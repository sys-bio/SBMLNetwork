import shutil

def read_version_from_file(version_file):
    with open(version_file, 'r') as f:
        version = f.read().strip()
    return version

def replace_placeholder_in_file(input_file, output_file, placeholder, replacement):
    with open(input_file, 'r') as fin:
        content = fin.read()

    content = content.replace(placeholder, replacement)

    with open(output_file, 'w') as fout:
        fout.write(content)

if __name__ == "__main__":
    version_file = "VERSION.txt"
    input_file = "docs/Doxyfile.in"
    output_file = "docs/Doxyfile"
    placeholder = "@LIBSBMLNETWORK_DOTTED_VERSION@"
    version = read_version_from_file(version_file)
    replace_placeholder_in_file(input_file, output_file, placeholder, version)
