#!/usr/bin/env python3
"""
Mario Party 3 Message File Decompiler
...
"""

import struct
import sys
import os
import re

def escape_text_for_output(text):
    """Escape special characters for output in the message format."""
    result = text
    
    # Removed escaping of backslashes so \x## stays intact
    # result = result.replace('\\', '\\\\')
    
    # Escape quotes
    result = result.replace('"', '\\"')
    
    # Handle common escape sequences
    result = result.replace('\n', '\\n')
    result = result.replace('\t', '\\t')
    result = result.replace('\r', '\\r')
    
    return result

def read_mario_party_messages(filename):
    """Read and parse a Mario Party 3 binary message file."""
    try:
        print(f"Opening file: {filename}")
        with open(filename, 'rb') as f:
            file_size = os.path.getsize(filename)
            print(f"File size: {file_size} bytes")
            
            num_messages_bytes = f.read(4)
            if len(num_messages_bytes) < 4:
                print("Error: File too small to contain valid header")
                return None
            
            num_messages = struct.unpack('>I', num_messages_bytes)[0]
            print(f"Number of messages: {num_messages}")
            
            if num_messages == 0:
                return []
            
            offsets = []
            for i in range(num_messages):
                offset_bytes = f.read(4)
                if len(offset_bytes) < 4:
                    print(f"Error: Incomplete offset table at message {i}")
                    return None
                offset = struct.unpack('>I', offset_bytes)[0]
                offsets.append(offset)
            
            header_size = 4 + (num_messages * 4)
            for i, offset in enumerate(offsets):
                if offset < header_size or offset >= file_size:
                    print(f"Error: Invalid offset for message {i}: 0x{offset:08X}")
                    return None
            
            messages = []
            for i, offset in enumerate(offsets):
                f.seek(offset)
                length_bytes = f.read(2)
                if len(length_bytes) < 2:
                    return None
                stored_length = struct.unpack('>H', length_bytes)[0]
                message_length = stored_length - 2
                
                message_bytes = f.read(message_length)
                null_terminator = f.read(1)
                
                message_text = ""
                for byte_val in message_bytes:
                    if 32 <= byte_val <= 126:  # Printable ASCII
                        message_text += chr(byte_val)
                    else:
                        # Write as literal \x## (not \\x##)
                        message_text += "\\x%02X" % byte_val
                
                messages.append({
                    'id': f"{i:02X}",
                    'text': message_text,
                    'length': message_length
                })
            
            return messages
    
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found")
        return None
    except Exception as e:
        print(f"Error reading file '{filename}': {e}")
        return None

def write_message_file(messages, output_filename):
    """Write messages to the structured text format."""
    try:
        with open(output_filename, 'w', encoding='utf-8') as f:
            f.write("# Mario Party 3 Messages\n")
            f.write("# Decompiled from binary format\n")
            f.write("# Edit this file and recompile with mp3_message_compiler.py\n\n")
            
            for message in messages:
                message_id = message['id']
                message_text = message['text']
                
                escaped_text = escape_text_for_output(message_text)
                
                if '\n' in escaped_text or len(escaped_text) > 60:
                    f.write(f'#message:{message_id} {{\n')
                    f.write(f'"{escaped_text}"\n')
                    f.write('};\n\n')
                else:
                    f.write(f'#message:{message_id} {{"{escaped_text}"}};\n\n')
        
        print(f"Successfully wrote {len(messages)} messages to '{output_filename}'")
        return True
    except Exception as e:
        print(f"Error writing to '{output_filename}': {e}")
        return False

def analyze_binary_file(filename):
    try:
        with open(filename, 'rb') as f:
            file_size = os.path.getsize(filename)
            print(f"\n=== Binary File Analysis ===")
            print(f"File: {filename}")
            print(f"Size: {file_size} bytes")
            
            num_messages = struct.unpack('>I', f.read(4))[0]
            header_size = 4 + (num_messages * 4)
            
            print(f"Message count: {num_messages}")
            print(f"Header size: {header_size} bytes")
            print(f"Data section: {file_size - header_size} bytes")
            
            offsets = []
            for i in range(num_messages):
                offset = struct.unpack('>I', f.read(4))[0]
                offsets.append(offset)
            
            print(f"\nMessage breakdown:")
            for i, offset in enumerate(offsets):
                f.seek(offset)
                stored_length = struct.unpack('>H', f.read(2))[0]
                message_length = stored_length - 2
                total_size = stored_length + 1
                print(f"  Message {i:02X}: offset=0x{offset:08X}, stored_length={stored_length}, "
                      f"message_length={message_length}, total_size={total_size}")
            
            print(f"=== End Analysis ===\n")
    except Exception as e:
        print(f"Error analyzing file: {e}")

def main():
    if len(sys.argv) < 3:
        print("Usage: python mp3_message_decompiler.py <input_binary_file> <output_text_file>")
        print("       python mp3_message_decompiler.py --analyze <binary_file>")
        return
    
    if sys.argv[1] == "--analyze":
        analyze_binary_file(sys.argv[2])
        return
    
    input_filename = sys.argv[1]
    output_filename = sys.argv[2]
    
    analyze_binary_file(input_filename)
    
    messages = read_mario_party_messages(input_filename)
    if messages is None or len(messages) == 0:
        return
    
    write_message_file(messages, output_filename)

if __name__ == "__main__":
    main()
