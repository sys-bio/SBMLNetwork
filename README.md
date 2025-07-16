# SBMLNetwork

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.15360020.svg)](https://doi.org/10.5281/zenodo.15360020)

SBMLNetwork is a library designed to enable software developers and systems biologists to interact with the graphical representation of SBML (Systems Biology Markup Language) models. It makes use of SBML Layout and Render extensions and provides the following features: (i) a built-in high-performance autolayout algorithm that automatically generates and adds graphical representation data to SBML models that don’t have them (ii) a robust API that provides the users and developers with seamless access to the graphical representation attributes of SBML models (iii) a drawing tool to render an image of the graphical representation of SBML models using their Layout and Render data.

**Important Note**: As of tag [v0.3.1](https://github.com/adelhpour/SBMLNetwork/releases/tag/v0.3.1) this repository has been forked and is now under active development and maintenance at the [UW Sauro Lab](https://github.com/sys-bio/SBMLNetwork) GitHub account, where further enhancements and updates are being implemented.

## Features

- **Autolayout**: SBMLNetwork provides a high-performance autolayout algorithm that automatically generates and adds graphical representation data to SBML models that don’t have them. The autolayout algorithm is based on the force-directed layout algorithm which is customized to accommodate the intricate structures often present in the graphical representation of biological networks.

- **API**: SBMLNetwork provides a robust API that allows users and developers to interact with the graphical representation attributes of SBML models. The API is designed to be intuitive and easy to use, providing seamless access to the graphical representation data of SBML models.

- **Drawing Tool**: SBMLNetwork provides a drawing tool that allows users to render an image of the graphical representation of SBML models using their Layout and Render data.

## Installation

SBMLNetwork is distributed both as a Python package and as a shared library.

### Python Package

To install the Python package, run the following command:

```pip install sbmlnetwork```

This will install the latest version of SBMLNetwork from PyPI, along with its dependencies. If you also want Tellurium for simulation:

```pip install sbmlnetwork[tellurium]```

which will install the latest version of Tellurium as well to be used as the simulation engine for the SBML models. This is in particular useful for using data integration features of SBMLNetwork when the data is not directly passed and instead is expected to be fetched from the model.

### Shared Library

To install the shared library, download the latest release from the [releases page](https://github.com/sys-bio/SBMLNetwork/releases) and link it to your project.

#### Pre-built binaries

Download an archive for your OS from the [releases page](https://github.com/adelhpour/SBMLNetwork/releases) and link it in your build system.

#### Build from source

The steps below reproduce our CI workflow so you can compile the C/C++ core and the Python bindings locally on macOS, Linux, or Windows.

#####  Clone the repo
```bash
git clone https://github.com/sys-bio/SBMLNetwork.git
cd SBMLNetwork
```

#####  Download binary dependencies (libroadrunner-deps)
```bash
curl -L -O <matching-archive>.zip          # pick the archive for your OS/arch/build-type
unzip <matching-archive>.zip -d $HOME/rr_deps
export DEPENDENCIES_INSTALL_PREFIX=$HOME/rr_deps   # Windows PowerShell:  setx DEPENDENCIES_INSTALL_PREFIX C:\rr_deps
```

#####  Configure
```bash
mkdir build && cd build
cmake .. -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DDEPENDENCIES_INSTALL_PREFIX=$DEPENDENCIES_INSTALL_PREFIX \
  -DWITH_PYTHON=ON \
  -DPYTHON_INSTALL_WITH_SETUP=ON \
  -DCMAKE_INSTALL_PREFIX=$PWD/../install
#  (macOS Apple-silicon: add -DCMAKE_OSX_ARCHITECTURES=arm64)
#  (Windows: run from a “x64 Native Tools VS 2022” prompt)
```

#####  Build & install
```bash
cmake --build . --target install
```

## Usage

Here are simple examples of how to use SBMLNetwork python package and C library:

### Python

```python
import sbmlnetwork

# Load an SBML model
network = sbmlnetwork.load('path/to/model.xml')

# set the fill color of the species
network.setSpeciesFillColor('Orange')

# draw an image of the graphical representation of the model
network.draw()

# export the image
network.draw('path/to/image.png')

# save the model with the graphical representation data
network.save('path/to/model_with_graphical_representation.xml')
```

To use the C APIs, you need to link to both libsbml and libsbmlnetowk libraries and include the appropriate headers. The following is an example of how to use the C APIs:

### C

```c
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "c_api/libsbmlnetwork_c_api.h"

// Load an SBML model
SBMLDocument* document = c_api_readSBML('path/to/model.xml');

// add graphical representation data to the model
c_api_applyAutolayout(document); 

// Save the model with the graphical representation data
c_api_writeSBMLToFile(document, 'path/to/model_with_graphical_representation.xml');

// Free the memory
c_api_freeSBMLDocument(document);
```

## Documentation

For more information on how to use SBMLNetwork, please refer to the [documentation](https://sbmlnetwork.readthedocs.io/en/latest/).

## License

SBMLNetwork is distributed under the [MIT License](https://github.com/adelhpour/SBMLNetwork/blob/develop/LICENSE).

## Contributing

If you would like to contribute to SBMLNetwork, please create a pull request with your changes. We welcome contributions from the community and are happy to review and merge your changes.

## Acknowledgements

This project is developed by the [UW Sauro Lab](https://www.sys-bio.org) at the Department of Bioengineering, University of Washington, Seattle.

