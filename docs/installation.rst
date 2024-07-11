Installation
============

To install SBMLNetwork, you can use the following methods:

Installing Python packages
--------------------------

You can install SBMLNetwork using the `pip` package manager. To do this, run the following command:

.. code-block:: bash

   pip install sbmlnetwork

Also, you can install Python bindings of the backend library using the following command:

.. code-block:: bash

   pip install libsbmlnetwork

Installing C++ library
-----------------------

You can procure precompiled binary files for the libSBMLNetwork C++ library from the designated repository's releases page at `https://github.com/adelhpour/SBMLNetwork/releases <https://github.com/adelhpour/SBMLNetwork/releases>`_. After downloading the binary files, you can link the library to your project and include th following header files in your source code as follows:

Including C api:
^^^^^^^^^^^^^^^^

.. code-block:: c

   #include "c_api/libsbmlnetwork_c_api.h"

Including C++ api:
^^^^^^^^^^^^^^^^^^

.. code-block:: cpp

   #include "libsbmlnetwork_sbmldocument.h"
   #include "libsbmlnetwork_sbmldocument_layout.h"
   #include "libsbmlnetwork_sbmldocument_render.h"


Building from source
---------------------

To build the SBMLNetwork library from source, you can follow the instructions provided in the :doc:`Building from source </building>` section.
