# SBMLNetwork

SBMLNetwork is a library designed to enable software developers and systems biologists to interact with the graphical representation of SBML (Systems Biology Markup Language) models. It makes use of SBML Layout and Render extensions and provides the following features: (i) a built-in high-performance autolayout algorithm that automatically generates and adds graphical representation data to SBML models that don’t have them (ii) a robust API that provides the users and developers with seamless access to the graphical representation attributes of SBML models (iii) a drawing tool to render an image of the graphical representation of SBML models using their Layout and Render data.

## Features

- **Autolayout**: SBMLNetwork provides a high-performance autolayout algorithm that automatically generates and adds graphical representation data to SBML models that don’t have them. The autolayout algorithm is based on the force-directed layout algorithm which is customized to accommodate the intricate structures often present in the graphical representation of biological networks.

- **API**: SBMLNetwork provides a robust API that allows users and developers to interact with the graphical representation attributes of SBML models. The API is designed to be intuitive and easy to use, providing seamless access to the graphical representation data of SBML models.

- **Drawing Tool**: SBMLNetwork provides a drawing tool that allows users to render an image of the graphical representation of SBML models using their Layout and Render data.

## Installation

SBMLNetwork is distributed both as a Python package and as a shared library.

### Python Package

To install the Python package, run the following command:

```pip install sbmlnetwork```

### Shared Library

To install the shared library, download the latest release from the [releases page](https://github.com/adelhpour/SBMLNetwork/releases) and link it to your project.

## Usage

Here are simple examples of how to use SBMLNetwork python package and C library:

### Python

```python
import sbmlnetwork

# Load an SBML model
network = sbmlnetwork.load('path/to/model.xml')

# set the fill color of the species
network.setSpeciesFillColors('Orange')

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

## License

SBMLNetwork is distributed under the [MIT License](https://github.com/adelhpour/SBMLNetwork/blob/develop/LICENSE).

## Contributing

If you would like to contribute to SBMLNetwork, please create a pull request with your changes. We welcome contributions from the community and are happy to review and merge your changes.

## Acknowledgements

This project is developed by the [UW Sauro Lab](https://www.sys-bio.org) at the Department of Bioengineering, University of Washington, Seattle.

