# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'SBMLNetwork'
copyright = '2024, Adel Heydarabadipour'
author = 'Adel Heydarabadipour'
release = '0.0.23'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["breathe", "sphinx.ext.autosectionlabel"]
breathe_projects = {'SBMLNetwork': "doxygen/xml"}
breathe_default_project = "SBMLNetwork"

templates_path = ['_templates']
exclude_patterns = []

language = 'C++, Python'

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']



# configure the Doxyfile
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
    version_file = "../VERSION.txt"
    input_file = "Doxyfile.in"
    output_file = "Doxyfile"
    placeholder = "@LIBSBMLNETWORK_DOTTED_VERSION@"
    version = read_version_from_file(version_file)
    replace_placeholder_in_file(input_file, output_file, placeholder, version)
