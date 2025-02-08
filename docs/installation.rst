Installation
============

To install SBMLNetwork, you can choose from the following installation methods. These methods enable the integration of SBMLNetwork into your workflows and systems based on the components you need.

Install via Python Package
--------------------------

For users who wish to utilize the **Python Package with User-Friendly API**, which simplifies interactions with SBML models and provides graphical representations, you can install SBMLNetwork via the `pip` package manager. This is suitable for users with minimal experience in software development.

Run the following command to install the core package:

.. code-block:: bash

   pip install sbmlnetwork

.. note::

   **Quick Start**: Check out the :doc:`Use Case Examples </use-case-examples>` page for detailed example workflows to quickly get up to speed with using SBMLNetwork in your Python projects.

To install the Python bindings for the backend library (useful for integrating with the **Python API** for advanced programmatic interaction), use this command:

.. code-block:: bash

   pip install libsbmlnetwork

Install C++ Library
-------------------

If you need to access the **C API** or **C++ Backend** components directly, you can install the C++ library.

Precompiled binary files for the libSBMLNetwork C++ library are available on the releases page of the repository at `https://github.com/sys-bio/SBMLNetwork/releases <https://github.com/sys-bio/SBMLNetwork/releases>`_. After downloading the appropriate binaries, link the library to your project and include the necessary header files in your source code:

- **C API** (if you want to use the **C API** for compatibility with various programming languages):
    .. code-block:: c

    #include "c_api/libsbmlnetwork_c_api.h"

- **C++ API** (if you want to directly utilize the **C++ Backend** for high-performance processing of SBML models):
    .. code-block:: cpp

     #include "libsbmlnetwork_sbmldocument.h"
     #include "libsbmlnetwork_sbmldocument_layout.h"
     #include "libsbmlnetwork_sbmldocument_render.h"

Building from Source
--------------------

For users who need to customize SBMLNetwork or build it from scratch (e.g., to modify the **C++ Backend** for performance optimization), follow the instructions provided in the :doc:`Building from source </building>` section.

