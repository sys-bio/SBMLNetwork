from setuptools import setup
from setuptools import find_packages
from setuptools.dist import Distribution
import platform


class BinaryDistribution(Distribution):

    def has_ext_modules(foo):
        return True

deps = []
if platform.system() == "Windows":
    deps = ['*.dll', '*.pyd', './resources/*']
elif platform.system() == "Darwin" or platform.system() == "Linux":
    deps = ['*.so', '*.dylib', './resources/*']

setup(
    name = "libsbmlnetwork",
    version = "${LIBSBMLNETWORK_DOTTED_VERSION}",
    author = "Adel Heydarabadipour",
    author_email = "adelhp@uw.edu",
    description = "LibSBML Network Python API",
    long_description_content_type = "text/x-rst",
    long_description = ("LibSBML Network is a portable library for systems/synthetic biologist to work with the Layout and Render extensions of SBML models. It enables the users to straightforwardly read, manipulate, and write and also automatically generate the information about the Layout and Render extensions of an SBML model."),
    url = "https://github.com/adelhpour/libsmlNetwork",
    license = "MIT License",
    platforms = ["Windows", "MacOS", "Unix"],
    classifiers = [
        "Intended Audience :: Science/Research",
        "Programming Language :: C++",
        "License :: OSI Approved :: MIT License",
        "Operating System :: Microsoft :: Windows",
        "Operating System :: MacOS :: MacOS X",
        "Operating System :: Unix"
    ],
    keywords= ["SBML", "Layout", "Render"],
    package_dir={"": "."},
    packages=find_packages(),
    package_data={"": deps},
    include_package_data = True,
    python_requires=">=3.8",
    distclass=BinaryDistribution
)
