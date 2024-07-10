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
