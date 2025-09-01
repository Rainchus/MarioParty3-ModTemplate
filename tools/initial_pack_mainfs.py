import subprocess
import os
import shutil
import sys
import argparse

# Define paths (update as needed)
rom_path = "rom/mp3.z64"
temp_rom_path = "rom/mp3-mainFS-repack.z64"
destination_dir = "assets/"
source_dir = "assets_new/" 
tool_path = "tools/mpromtool.exe"


def batch_decompile_strings(input_dir="assets_new/messdata_eng", 
                            output_dir="assets_new/new_messdata_eng",
                            decompiler_script="tools/mp3_message_decompiler.py"):
    """
    Run mp3_message_decompiler.py on all .bin files in input_dir
    and output .txt files with the same base filename to output_dir.
    Only prints when a file is actually decompiled.
    """
    os.makedirs(output_dir, exist_ok=True)

    for filename in os.listdir(input_dir):
        if not filename.endswith(".bin"):
            continue

        input_path = os.path.join(input_dir, filename)
        output_filename = os.path.splitext(filename)[0] + ".txt"
        output_path = os.path.join(output_dir, output_filename)

        # Skip if output file already exists
        if os.path.exists(output_path):
            continue

        try:
            subprocess.run(["python", decompiler_script, input_path, output_path], check=True)
            print(f"📝 Decompiled: {input_path} -> {output_path}")
        except subprocess.CalledProcessError as e:
            print(f"❌ Failed to decompile {filename}: exit code {e.returncode}")
        except FileNotFoundError:
            print(f"❌ Decompiler script not found: {decompiler_script}")
            break



def batch_compile_strings(input_dir="assets_new/new_messdata_eng",
                          output_dir="assets_new/messdata_eng",
                          compiler_script="tools/mp3_message_compiler.py"):
    """
    Compile all .txt message files in input_dir to .bin files in output_dir
    using mp3_message_compiler.py. Always recompiles, even if .bin exists.
    Added debugging output.
    """
    if not os.path.exists(input_dir):
        print(f"⚠️ Input directory does not exist: {input_dir}")
        return

    files = [f for f in os.listdir(input_dir) if f.endswith(".txt")]
    if not files:
        print(f"⚠️ No .txt files found in {input_dir}")
        return

    os.makedirs(output_dir, exist_ok=True)

    for filename in files:
        input_path = os.path.join(input_dir, filename)
        output_filename = os.path.splitext(filename)[0] + ".bin"
        output_path = os.path.join(output_dir, output_filename)

        print(f"🔧 Compiling: {input_path} -> {output_path}")
        try:
            result = subprocess.run(
                ["python", compiler_script, input_path, output_path],
                check=True,
                capture_output=True,
                text=True
            )
            print(f"📦 Compiled: {input_path} -> {output_path}")
            if result.stdout:
                print(f"stdout: {result.stdout.strip()}")
            if result.stderr:
                print(f"stderr: {result.stderr.strip()}")
        except subprocess.CalledProcessError as e:
            print(f"❌ Failed to compile {filename}: exit code {e.returncode}")
            if e.stdout:
                print(f"stdout: {e.stdout.strip()}")
            if e.stderr:
                print(f"stderr: {e.stderr.strip()}")
        except FileNotFoundError:
            print(f"❌ Compiler script not found: {compiler_script}")
            break



def run_command(command, description):
    """Run a subprocess command with error checking."""
    try:
        subprocess.run(command, check=True)
        print(f"✅ {description} succeeded")
    except subprocess.CalledProcessError as e:
        print(f"❌ {description} failed with exit code {e.returncode}")
        sys.exit(1)
    except FileNotFoundError:
        print(f"❌ Command not found: {command[0]}")
        sys.exit(1)


def newFunc(clean=False):
    # Check required files first
    if not os.path.isfile(tool_path):
        print(f"❌ Tool not found: {tool_path}")
        sys.exit(1)

    if not os.path.isfile(rom_path):
        print(f"❌ ROM file not found: {rom_path}")
        sys.exit(1)

    # Step 1: Extract (only if --clean OR assets/ doesn't exist)
    if clean and os.path.exists(destination_dir):
        print("🧹 --clean specified, removing old assets/")
        shutil.rmtree(destination_dir)

    if not os.path.exists(destination_dir):
        run_command([tool_path, "-a", rom_path, destination_dir], "ROM extraction")
    else:
        print("⏩ Skipping extraction (assets/ already exists, use --clean to force re-extract)")

    # Step 2: Copy missing files from assets/ → assets_new/
    os.makedirs(source_dir, exist_ok=True)

    copied_count = 0
    for root, _, files in os.walk(destination_dir):
        for file in files:
            src_path = os.path.join(root, file)
            rel_path = os.path.relpath(src_path, destination_dir)
            dest_path = os.path.join(source_dir, rel_path)
            os.makedirs(os.path.dirname(dest_path), exist_ok=True)

            if not os.path.exists(dest_path):
                shutil.copy2(src_path, dest_path)
                copied_count += 1

    if copied_count > 0:
        print(f"✅ Asset copy complete: {copied_count} new files copied")
    else:
        print("⏩ Asset copy skipped (no new files)")

    # Step 2b: Extract strings and recompile new strings if they exist into binary
    batch_decompile_strings()
    batch_compile_strings()

    # batch_decompile_strings("assets_new/messdata", "assets_new/new_messdata", "tools/mp3_message_decompiler.py")
    # batch_compile_strings("assets_new/new_messdata", "assets_new/messdata", "tools/mp3_message_decompiler.py")

    # Step 3: Repack
    print(f"{tool_path}, \"-b\", \"-a\", {rom_path}, {source_dir}, {temp_rom_path}")
    run_command([tool_path, "-b", "-a", rom_path, source_dir, temp_rom_path], "ROM repack")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Extract, sync assets, and repack ROM.")
    parser.add_argument("--clean", action="store_true", help="Force re-dump of assets/")
    args = parser.parse_args()

    newFunc(clean=args.clean)
