import shutil
import os
import subprocess
import argparse

def log(msg):
    print(f"[DEBUG] {msg}")

# Get the directory where this script is located
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
MPROMTOOL = os.path.join(SCRIPT_DIR, "tools/mpromtool.exe")
MPN64SPRTOOL = os.path.join(SCRIPT_DIR, "tools/mpn64sprtool.exe")

def process_anm_to_xml():
    input_dir = "mp3_extract"
    output_dir = "original_assets"
    os.makedirs(output_dir, exist_ok=True)
    log(f"Ensured output directory exists: {output_dir}")

    for root, _, files in os.walk(input_dir):
        for file in files:
            if file.endswith(".anm"):
                input_file = os.path.join(root, file)
                relative_path = os.path.relpath(input_file, input_dir)
                output_file = os.path.join(output_dir, os.path.splitext(relative_path)[0] + ".xml")
                os.makedirs(os.path.dirname(output_file), exist_ok=True)
                log(f"Dumping: {input_file} -> {output_file}")

                try:
                    subprocess.run([MPN64SPRTOOL, "dump", input_file, output_file], check=True)
                    log(f"Successfully dumped {input_file}")
                except subprocess.CalledProcessError as e:
                    log(f"❌ Failed dumping {input_file}: exit code {e.returncode}")
                except FileNotFoundError:
                    log(f"❌ mpn64sprtool not found")

def process_files():
    new_assets_dir = "new_assets"
    new_converted_assets_dir = "new_converted_assets"
    os.makedirs(new_converted_assets_dir, exist_ok=True)
    log(f"Ensured output directory exists: {new_converted_assets_dir}")

    filedata_dir = os.path.join(new_converted_assets_dir, "filedata")
    if os.path.exists(filedata_dir) and os.path.isdir(filedata_dir):
        shutil.rmtree(filedata_dir)
        log(f"Deleted the folder: {filedata_dir}")

    for root, _, files in os.walk(new_assets_dir):
        for file in files:
            if file.endswith(".xml"):
                input_file = os.path.join(root, file)
                relative_path = os.path.relpath(input_file, new_assets_dir)
                output_file = os.path.join(new_converted_assets_dir, os.path.splitext(relative_path)[0] + ".anm")
                os.makedirs(os.path.dirname(output_file), exist_ok=True)
                log(f"Building: {input_file} -> {output_file}")

                try:
                    subprocess.run([MPN64SPRTOOL, "build", input_file, output_file], check=True)
                    log(f"Successfully built {output_file}")
                except subprocess.CalledProcessError as e:
                    log(f"❌ Failed building {input_file}: exit code {e.returncode}")
                except FileNotFoundError:
                    log(f"❌ mpn64sprtool not found")

def compile_txt_to_bin():
    input_dir = "new_assets"
    output_dir = "new_converted_assets"
    compiler_script = os.path.join(SCRIPT_DIR, "tools", "mp3_message_compiler.py")
    os.makedirs(output_dir, exist_ok=True)
    log(f"Ensured output directory exists: {output_dir}")

    for root, _, files in os.walk(input_dir):
        for file in files:
            if not file.endswith(".txt"):
                continue

            input_file = os.path.join(root, file)
            relative_path = os.path.relpath(input_file, input_dir)
            output_file = os.path.join(output_dir, os.path.splitext(relative_path)[0] + ".bin")
            os.makedirs(os.path.dirname(output_file), exist_ok=True)
            log(f"Compiling: {input_file} -> {output_file}")

            try:
                subprocess.run(["python", compiler_script, input_file, output_file], check=True)
                log(f"Successfully compiled {input_file}")
            except subprocess.CalledProcessError as e:
                log(f"❌ Failed to compile {input_file}: exit code {e.returncode}")
            except FileNotFoundError:
                log(f"❌ Compiler script not found: {compiler_script}")
                return

def main():
    parser = argparse.ArgumentParser(description="Process and rebuild the ROM.")
    parser.add_argument("-dump", action="store_true", help="Force re-extraction of rom/mp3.z64 into mp3_extract.")
    args = parser.parse_args()

    if not os.path.exists("mp3_extract") or args.dump:
        if args.dump:
            log("Forced dump requested via -dump flag.")
        else:
            log("mp3_extract directory does not exist. Dumping...")

        try:
            subprocess.run([MPROMTOOL, "-a", "rom/mp3.z64", "mp3_extract"], check=True)
            log("Successfully extracted ROM to mp3_extract")
        except subprocess.CalledProcessError as e:
            log(f"❌ mpromtool failed: exit code {e.returncode}")
            return
        except FileNotFoundError:
            log(f"❌ mpromtool not found at {MPROMTOOL}")
            return

        process_anm_to_xml()
    else:
        log("Skipping extraction as 'mp3_extract' already exists. Use -dump to force extraction.")

    if not os.path.exists("new_converted_assets"):
        os.makedirs("new_converted_assets")
        log("Created new_converted_assets directory")

        romdata_src = "mp3_extract/romdata.xml"
        romdata_dest = "new_converted_assets/romdata.xml"
        if os.path.exists(romdata_src):
            shutil.copy(romdata_src, romdata_dest)
            log(f"Copied {romdata_src} to {romdata_dest}.")

    process_files()
    compile_txt_to_bin()

    log("Copying new_converted_assets back to mp3_extract...")
    shutil.copytree("new_converted_assets", "mp3_extract", dirs_exist_ok=True)

    log("Building ROM...")
    try:
        subprocess.run([MPROMTOOL, "-b", "-a", "rom/mp3.z64", "mp3_extract", "rom/mp3-mainFS-repack.z64"], check=True)
        log("Successfully built mp3-mainFS-repack.z64")
    except subprocess.CalledProcessError as e:
        log(f"❌ mpromtool build failed: exit code {e.returncode}")
    except FileNotFoundError:
        log(f"❌ mpromtool not found at {MPROMTOOL}")

if __name__ == "__main__":
    main()
