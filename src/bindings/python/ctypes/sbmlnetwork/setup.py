from setuptools import setup
from setuptools import find_packages
import os

with open(os.path.dirname(os.path.abspath(__file__)) + "README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()
    
with open(os.path.dirname(os.path.abspath(__file__)) + "/VERSION.txt", "r") as f:
    version = f.read().rstrip()
    
with open(os.path.dirname(os.path.abspath(__file__)) +"/requirements.txt", "r") as f:
    requirements = f.readlines()
setup(
    name="sbmlnetwork",
    version=version,
    author="Adel Heydarabadipour",
    author_email="adelhp@uw.edu",
    description="A python api to work with libsbmlnetwork library",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/adelhpour/SBMLNetwork",
    project_urls={
        "Bug Tracker": "https://github.com/adelhpour/SBMLNetwork/issues",
    },
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    install_requires=requirements,
    package_dir={"": "src"},
    packages=find_packages(where="src"),
    python_requires=">=3.9"
)
