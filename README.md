# SBMLNetwork

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.15360020.svg)](https://doi.org/10.5281/zenodo.15360020)
[![Paper DOI](https://img.shields.io/badge/DOI-10.1101%2F2025.05.09.653024-blue)](https://doi.org/10.1101/2025.05.09.653024)

SBMLNetwork is a cross-platform library—built on a C++ core with native Python and WebAssembly bindings—that automatically generates and renders SBML Layout & Render info, transforming plain biochemical models into standards-compliant, publication-ready network diagrams with a single function call.

**Note**: This repository is a continuation of the original [adelhpour/SBMLNetwork](https://github.com/adelhpour/SBMLNetwork) project. As of [v0.3.1](https://github.com/adelhpour/SBMLNetwork/releases/tag/v0.3.1), active development and maintenance have moved to the [UW Sauro Lab](https://github.com/sys-bio/SBMLNetwork), where ongoing enhancements and new features are being implemented.

## Features

- **Standards fidelity** – full read/write support for SBML Layout & Render.

- **Reaction-aware autolayout** – Fruchterman–Reingold variant tuned for
  metabolic graphs.

- **Styling engine** – predefined templates like Escher to get you started,
  plus per-element overrides for colors, shapes, fonts, and stroke widths.

- **Data overlays** – map fluxes or concentrations to color gradients, line
  thickness, or node size with one call; automatic color-bar legend included.

- **Multi-format export** – render to PNG, SVG, PDF; high-quality drawing powered by Skia.

- **Multi-language API** – performance-oriented C++ core exposed to Python
  (PyPI) and JavaScript/WebAssembly for seamless embedding in desktop or web
  tools.

## Installation

SBMLNetwork is distributed both as a Python package and as a shared library.

### Python Package

To install the Python package, run the following command:

```pip install sbmlnetwork```

This will install the latest version of SBMLNetwork from PyPI, along with its dependencies. If you also want Tellurium for simulation:

```pip install "sbmlnetwork[tellurium]"```

which will install the latest version of Tellurium as well to be used as the simulation engine for the SBML models. This is in particular useful for using data integration features of SBMLNetwork when the data is not directly passed and instead is expected to be fetched from the model.

### Shared Library

SBMLNetwork provides native libraries for both **C/C++** and **JavaScript/WebAssembly** environments.

To get started:

- **C/C++ users** can link against the precompiled static libraries available on the [releases page](https://github.com/sys-bio/SBMLNetwork/releases), or build from source for full control.
- **JavaScript/WebAssembly users** can include the `libsbmlnetwork.js` and `libsbmlnetwork.wasm` bundles in their web applications for in-browser SBML support.

📚 **Detailed installation and usage instructions** for all supported environments are available in the [documentation](https://sbmlnetwork.readthedocs.io/en/latest/installation.html).

## Usage

SBMLNetwork provides a concise, high-level Python interface for loading, styling, analyzing, and exporting SBML models with full Layout and Render support.

### Basic Visualization

Load a model, apply automatic layout and styling if needed, render the image, and save the updated SBML.

```python
import sbmlnetwork as sb

# Load SBML; auto‑layout and auto‑style will run if the file lacks them
net = sb.load("my_model.xml")

# Render the network and save a PNG
net.draw("network.png")

# Save SBML back to disk with Layout/Render information embedded
net.save("network.xml")
```

📚 More examples (including styling and theming, flux mapping, concentration overlays, and reaction grouping) are available in the [Getting Started guide](https://sbmlnetwork.readthedocs.io/en/latest/getting_started.html).


## Documentation

For more information on how to use SBMLNetwork, please refer to the [documentation](https://sbmlnetwork.readthedocs.io/en/latest/).

## License

SBMLNetwork is distributed under the [MIT License](https://github.com/adelhpour/SBMLNetwork/blob/develop/LICENSE).

## Contributing

If you would like to contribute to SBMLNetwork, please create a pull request with your changes. We welcome contributions from the community and are happy to review and merge your changes.

## Citation

If you use SBMLNetwork in your work, please cite the following preprint:

> Heydarabadipour A, Smith L, Hellerstein JL, Sauro HM.  
> *SBMLNetwork: Standards-based layout, styling, and visualization of biochemical models across platforms.*  
> bioRxiv 2025. [https://doi.org/10.1101/2025.05.09.653024](https://doi.org/10.1101/2025.05.09.653024)

📄 [View on bioRxiv](https://www.biorxiv.org/content/10.1101/2025.05.09.653024v1)


## Acknowledgements

This project is developed by the [UW Sauro Lab](https://www.sys-bio.org) at the Department of Bioengineering, University of Washington, Seattle.  We acknowledge the support of the **Center for Reproducible Biomedical Modeling**, funded by NIH award [P41EB023912](https://reporter.nih.gov/project-details/10094520).  We also gratefully acknowledge funding from NIH award [U24EB028887](https://reporter.nih.gov/project-details/10126363), which supported much of the early work.