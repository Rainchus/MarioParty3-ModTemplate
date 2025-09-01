#!/usr/bin/env python3
"""
Mario Party 3 Message File Compiler

This script compiles text messages into the binary format used by Mario Party 3.

Binary format (big-endian):
- First 4 bytes: Number of message entries (uint32)
- Next N*4 bytes: Array of offsets to each message (uint32 each)
- Message data: For each message:
  - 2 bytes: Message length in bytes (uint16, not including null terminator)
  - N bytes: Message text
  - 1 byte: Null terminator (0x00)

Text file format:
#message:ID {"Message text"};
or
#message:ID {
"Multi-line message
with line breaks"
};

Where ID is a hexadecimal identifier (00, 01, FF, etc.)
Escape sequences supported: \n (newline), \t (tab), \\ (backslash), \" (quote)
"""

import struct
import sys
import os
import re

def parse_message_file(filename):
    """Parse the structured message file format."""
    messages = []  # List to maintain order
    seen_ids = set()  # Set to track duplicate IDs
    
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Regular expression to match the message format
        # Matches: #message:ID {"content"}; or #message:ID {\n"content"\n};
        pattern = r'#message:([0-9A-Fa-f]+)\s*\{\s*"((?:[^"\\]|\\.)*)"\s*\}\s*;'
        
        matches = re.findall(pattern, content, re.DOTALL)
        
        for match in matches:
            msg_id, msg_text = match
            msg_id_upper = msg_id.upper()
            
            # Check for duplicate IDs
            if msg_id_upper in seen_ids:
                print(f"ERROR: Duplicate message ID found: {msg_id_upper}")
                print("Each message must have a unique ID.")
                return None
            
            seen_ids.add(msg_id_upper)
            
            # Process escape sequences
            msg_text = process_escape_sequences(msg_text)
            
            # Add to messages list in the order they appear in the file
            messages.append({
                'id': msg_id_upper,
                'text': msg_text
            })
            
            #print(f"Parsed message {msg_id_upper} (position {len(messages)}): '{repr(msg_text)}'")
        
        if not messages:
            print("No messages found in the specified format.")
            print("Expected format:")
            print('#message:00 {"Hello world!"};')
            print('or')
            print('#message:01 {\n"Multi-line\\nmessage"\n};')
            return None
        
        print(f"\nParsed {len(messages)} messages from '{filename}' in user-defined order")
        return messages
    
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return None
    except Exception as e:
        print(f"Error reading file '{filename}': {e}")
        return None

def process_escape_sequences(text):
    """Process escape sequences in the message text."""
    result = text
    
    # First handle hex escape sequences (\x00 to \xFF)
    import re
    hex_pattern = r'\\x([0-9A-Fa-f]{2})'
    def hex_replacer(match):
        hex_value = int(match.group(1), 16)
        return chr(hex_value)
    
    result = re.sub(hex_pattern, hex_replacer, result)
    
    # Then handle common escape sequences
    escape_map = {
        '\\n': '\n',
        '\\t': '\t',
        '\\r': '\r',
        '\\"': '"',
        '\\\\': '\\'
    }
    
    for escape_seq, replacement in escape_map.items():
        result = result.replace(escape_seq, replacement)
    
    return result

def compile_messages_to_binary(messages, output_filename):
    """Compile messages into Mario Party 3 binary format with 2-byte alignment."""

    num_messages = len(messages)
    header_size = 4 + (num_messages * 4)

    encoded_messages = []
    message_offsets = []
    current_offset = header_size

    for i, message_data in enumerate(messages):
        message_text = message_data['text']
        message_id = message_data['id']

        # Convert to raw bytes (1:1 mapping from characters)
        message_bytes = bytes(ord(c) for c in message_text)
        message_length = len(message_bytes)

        # Length = 2 (for length field itself) + message length
        stored_length = message_length + 2

        # Build message block
        binary_message = struct.pack('>H', stored_length) + message_bytes + b'\x00'

        # Pad to 2-byte alignment
        if len(binary_message) % 2 != 0:
            binary_message += b'\x00'

        message_offsets.append(current_offset)
        encoded_messages.append(binary_message)
        current_offset += len(binary_message)

        print(
            f"Message {message_id} (index {i}): "
            f"message_bytes={message_length}, stored_length={stored_length}, "
            f"block_size={len(binary_message)}, offset=0x{message_offsets[i]:08X}"
        )

    # Write binary file
    try:
        with open(output_filename, 'wb') as f:
            # Header
            f.write(struct.pack('>I', num_messages))
            for offset in message_offsets:
                f.write(struct.pack('>I', offset))

            # Message data
            for message_data in encoded_messages:
                f.write(message_data)

        print(f"\nSuccessfully compiled {num_messages} messages to '{output_filename}'")
        print(f"File size: {os.path.getsize(output_filename)} bytes")
        return True

    except Exception as e:
        print(f"Error writing to '{output_filename}': {e}")
        return False


def verify_binary_file(filename, original_messages):
    """Verify the generated binary file by reading it back."""
    try:
        with open(filename, 'rb') as f:
            # Read number of messages
            num_messages = struct.unpack('>I', f.read(4))[0]
            print(f"\nVerification - Number of messages: {num_messages}")
            
            # Read offsets
            offsets = []
            for i in range(num_messages):
                offset = struct.unpack('>I', f.read(4))[0]
                offsets.append(offset)
                print(f"Offset {i+1}: 0x{offset:08X}")
            
            # Read messages
            for i, offset in enumerate(offsets):
                f.seek(offset)
                stored_length = struct.unpack('>H', f.read(2))[0]
                # Length includes the 2-byte length field itself, so message data is stored_length - 2
                message_length = stored_length - 2
                message_bytes = f.read(message_length)
                null_terminator = f.read(1)
                
                message_text = message_bytes.decode('utf-8')
                original_id = original_messages[i]['id']
                print(f"Message {original_id} (index {i}, stored_length={stored_length}, message_length={message_length}): {repr(message_text)}")
                
                if null_terminator != b'\x00':
                    print(f"Warning: Message {original_id} missing null terminator")
    
    except Exception as e:
        print(f"Error verifying file: {e}")

def create_example_file(filename):
    """Create an example message file."""
    example_content = '''#message:00 {"Welcome to Mario Party 3!"};

#message:01 {
"Press START to continue.\\n\\nGood luck!"
};

#message:02 {"Player 1 wins the game!"};

#message:03 {
"This message has hex escape: \\x0B and \\xFF\\n
Multi-line with \\"quotes\\" too!"
};

# Note: Messages will appear in the binary file in the same order as defined here
# In this case: index 0=00, index 1=01, index 2=02, index 3=03
# So Mario Party 3 can reference message at index 2 to get "Player 1 wins the game!"
# 
# Supported escape sequences:
# \\n (newline), \\t (tab), \\r (carriage return), \\" (quote), \\\\ (backslash)
# \\x## (hex byte, where ## is 00-FF, like \\x0B for byte 0x0B)
'''
    
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(example_content)
    
    print(f"Created example file: {filename}")
    print("Messages will be compiled in the exact order they appear in the file.")
    print("Hex escapes like \\x0B are now supported!")

def main():
    if len(sys.argv) < 3:
        print("Usage: python mp3_message_compiler.py <input_text_file> <output_binary_file>")
        print("       python mp3_message_compiler.py --example <example_file>")
        print("\nExamples:")
        print("  python mp3_message_compiler.py messages.txt messages.bin")
        print("  python mp3_message_compiler.py --example example_messages.txt")
        print("\nMessage file format:")
        print('  #message:00 {"Hello world!"};')
        print('  #message:01 {')
        print('  "Multi-line\\nmessage with\\nline breaks"')
        print('  };')
        print("\nSupported escape sequences: \\n \\t \\r \\\" \\\\ \\x##")
        print("  \\x## = hex byte (00-FF), e.g. \\x0B for byte 0x0B")
        return
    
    if sys.argv[1] == "--example":
        create_example_file(sys.argv[2])
        return
    
    input_filename = sys.argv[1]
    output_filename = sys.argv[2]
    
    print("Mario Party 3 Message Compiler")
    print("=" * 40)
    
    # Parse messages from input file
    messages = parse_message_file(input_filename)
    if messages is None:
        return
    
    if len(messages) == 0:
        print("No messages found in input file.")
        return
    
    # Compile to binary format
    if compile_messages_to_binary(messages, output_filename):
        # Verify the output
        verify_binary_file(output_filename, messages)
        print(f"\nDone! Binary file '{output_filename}' created successfully.")
    else:
        print("Failed to create binary file.")

if __name__ == "__main__":
    main()