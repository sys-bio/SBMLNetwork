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
    # sbmlnetwork
    shutil.copy("../src/bindings/python/ctypes/sbmlnetwork/src/sbmlnetwork/sbmlnetwork.py", "./sbmlnetwork.py")

    version_file = "../VERSION.txt"
    version = read_version_from_file(version_file)
    # libsbmlnetwork
    input_file = "../src/bindings/python/ctypes/libsbmlnetwork.py.cmake"
    output_file = "./libsbmlnetwork.py"
    placeholder = "${LIBSBMLNETWORK_DOTTED_VERSION}"
    replace_placeholder_in_file(input_file, output_file, placeholder, version)

    # Doxyfile
    input_file = "Doxyfile.in"
    output_file = "Doxyfile"
    placeholder = "@LIBSBMLNETWORK_DOTTED_VERSION@"
    replace_placeholder_in_file(input_file, output_file, placeholder, version)

    # conf.py
    input_file = "conf.py.in"
    output_file = "conf.py"
    placeholder = "@LIBSBMLNETWORK_DOTTED_VERSION@"
    replace_placeholder_in_file(input_file, output_file, placeholder, version)

