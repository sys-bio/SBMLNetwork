.. _installation:

============
Installation
============

SBMLNetwork ships in three flavours—**Python package**, **native C/C++ library**,
and **JavaScript/WebAssembly bundle**—so you can pick the distribution that best
fits your workflow.  The table below gives a quick overview; detailed,
step-by-step instructions follow.

-------------------------------------------------
Install the Python package (recommended for most)
-------------------------------------------------

1. **Install the core library**

   .. code-block:: console

      pip install sbmlnetwork

2. **Optional – add Tellurium for simulation-based features**

   .. code-block:: console

      pip install sbmlnetwork[tellurium]

   The ``[tellurium]`` extra pulls in the latest version of **Tellurium** to act
   as the simulation engine. Choose this variant if you plan to use
   SBMLNetwork’s data-integration helpers that fetch fluxes or concentration
   trajectories directly from the model rather than supplying data arrays
   yourself.

3. **Next steps**

   * Continue with :doc:`Getting Started <getting_started>` to render your first
     network.
   * See the :doc:`Python API reference <api_reference/python_api_index>` for full Python-level details.

----------------------------------------
Install the native C/C++ static library
----------------------------------------

To use and link against **C API** or the native **C++ backend**, download the
*pre-built static binaries* distributed in the
`libroadrunner-deps <https://github.com/sys-bio/libroadrunner-deps/releases>`_
archives. These archives bundle **SBMLNetwork**, **static libSBML**, and required
third-party libraries (Expat, Zlib, etc.) under a common directory tree so you
can link everything from a single location. Then, follow the steps below to

#. **Write *main.cpp***

   .. code-block:: cpp
      :caption: *main.cpp*

      #include "sbmlnetwork/c_api/libsbmlnetwork_c_api.h"
      #include <iostream>

      using namespace LIBSBMLNETWORK_CPP_NAMESPACE;

      int main()
      {
          const char* path = "path/to/your/model.xml";

          SBMLDocument* doc = c_api_readSBML(path);
          if (!doc) {
              std::cerr << "Error: could not load SBML file '" << path << "'.\n";
              return 1;
          }

          c_api_autolayout(doc);

          std::cout << "Canvas width  : " << c_api_getCanvasWidth(doc)  << "\n";
          std::cout << "Canvas height : " << c_api_getCanvasHeight(doc) << "\n";

          c_api_freeSBMLDocument(doc);
          return 0;
      }

#. **Create *CMakeLists.txt***

   Put the following file next to your ``main.cpp``.  It looks for static
   versions of libSBML and SBMLNetwork **only** and links in Expat & Zlib as
   separate objects (required by static libSBML).

   .. code-block:: cmake
      :caption: *CMakeLists.txt*

      cmake_minimum_required(VERSION 3.10)
      project(TestLibSBMLNetwork)

      # -- User-configurable root for all dependencies -------------------------
      set(DEPENDENCIES_ROOT "" CACHE PATH
          "Path containing libSBML, SBMLNetwork, Expat, Zlib, …")

      add_executable(TestLibSBMLNetwork main.cpp)

      # ---- SBMLNetwork -------------------------------------------------------
      find_library(SBMLNETWORK_LIBRARY
          NAMES libsbmlnetwork-static sbmlnetwork-static
          PATHS ${DEPENDENCIES_ROOT}/lib )

      find_path(SBMLNETWORK_INCLUDE_DIR
          NAMES sbmlnetwork/c_api/libsbmlnetwork_c_api.h
          PATHS ${DEPENDENCIES_ROOT}/include )

      # ---- libSBML (static only) --------------------------------------------
      find_path(LIBSBML_INCLUDE_DIR
          NAMES sbml/SBMLTypes.h
          PATHS ${DEPENDENCIES_ROOT}/include )

      find_library(LIBSBML_LIBRARY
          NAMES libsbml-static sbml-static
          PATHS ${DEPENDENCIES_ROOT}/lib ${DEPENDENCIES_ROOT}/lib64 )

      # ---- Expat & Zlib ------------------------------------------------------
      find_library(EXPAT_LIBRARY
          NAMES expat libexpat
          PATHS ${DEPENDENCIES_ROOT}/lib )

      find_library(LIBZ_LIBRARY
          NAMES z
          PATHS ${DEPENDENCIES_ROOT}/lib )

      # ---- Sanity checks -----------------------------------------------------
      foreach(var SBMLNETWORK_LIBRARY SBMLNETWORK_INCLUDE_DIR
                  LIBSBML_LIBRARY     LIBSBML_INCLUDE_DIR
                  EXPAT_LIBRARY       LIBZ_LIBRARY)
        if(NOT ${var})
          message(FATAL_ERROR "Missing `${var}` – check DEPENDENCIES_ROOT")
        endif()
      endforeach()

      # ---- Include & link ----------------------------------------------------
      target_include_directories(TestLibSBMLNetwork PRIVATE
          ${SBMLNETWORK_INCLUDE_DIR} ${LIBSBML_INCLUDE_DIR} )

      target_link_libraries(TestLibSBMLNetwork PRIVATE
          ${SBMLNETWORK_LIBRARY} ${LIBSBML_LIBRARY}
          ${EXPAT_LIBRARY} ${LIBZ_LIBRARY} ${CMAKE_DL_LIBS} )

#. **Configure & build**

   Set ``DEPENDENCIES_ROOT`` to the **top of the unpacked libroadrunner-deps archive**
   that contains ``include`` and ``lib`` inside).

   .. code-block:: bash

      mkdir build && cd build
      cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release \
               -DDEPENDENCIES_ROOT="path/to/libroadrunner-deps"
      cmake --build .

   The resulting executable ``TestLibSBMLNetwork`` links everything **statically**
   and runs without external DLLs/so-files (aside from the system C runtime).

#. **Next steps**

   * See the :doc:`C API reference <api_reference/c_api_index>` and :doc:`C++ API reference <api_reference/cpp_api_index>` for full C/C++-level details.

-----------------------------------------
Use SBMLNetwork in JavaScript/WebAssembly
-----------------------------------------

SBMLNetwork’s core compiles to **WebAssembly**, allowing in-browser or Node.js
workflows.

#. **Download the WASM bundle**

   Obtain the WebAssembly distribution from the
   `SBMLNetwork releases page <https://github.com/sys-bio/SBMLNetwork/releases>`_.
   Each release includes the pair ``libsbmlnetwork.js`` and ``libsbmlnetwork.wasm`` inside
   the assets section. Download both files and place them in your web project.

#. **Load and initialize**

   Example ES‑module page (save as ``index.html`` next to ``libsbmlnetwork.js``,
   ``libsbmlnetwork.wasm`` and a test ``model.xml``):

   .. code-block:: html
      :caption: *index.html*

      <!DOCTYPE html>
      <html>
      <head>
        <meta charset="utf-8">
        <title>SBML Autolayout and Get Compartment Layout Info</title>
      </head>
      <body>
        <script type="module">
          import libsbmlnetwork from './libsbmlnetwork.js';

          libsbmlnetwork().then(Module => {
            console.log("WASM module initialized");

            const sbmlStr = `<?xml version="1.0" encoding="UTF-8"?>
      <sbml xmlns="http://www.sbml.org/sbml/level3/version2/core" level="3" version="2">
        <model metaid="__main" id="__main">
          <listOfCompartments>
            <compartment sboTerm="SBO:0000410" id="default_compartment" spatialDimensions="3" size="1" constant="true"/>
          </listOfCompartments>
          <listOfSpecies>
            <species id="S1" compartment="default_compartment" hasOnlySubstanceUnits="false" boundaryCondition="false" constant="false"/>
            <species id="S2" compartment="default_compartment" hasOnlySubstanceUnits="false" boundaryCondition="false" constant="false"/>
          </listOfSpecies>
          <listOfReactions>
            <reaction id="J0" reversible="true">
              <listOfReactants>
                <speciesReference species="S1" stoichiometry="1" constant="true"/>
              </listOfReactants>
              <listOfProducts>
                <speciesReference species="S2" stoichiometry="1" constant="true"/>
              </listOfProducts>
            </reaction>
          </listOfReactions>
        </model>
      </sbml>`;

            const sbmlPtr = Module.allocateUTF8(sbmlStr);
            const docPtr = Module._c_api_readSBML(sbmlPtr);

            Module._free(sbmlPtr);

            const numLayouts = Module._c_api_getNumLayouts(docPtr);
            console.log("Number of existing layouts:", numLayouts);

            if (numLayouts === 0) {
              Module._c_api_autolayout(docPtr);
              console.log("Autolayout applied because no layouts existed");
            } else {
              console.log("Layout already exists, skipping autolayout");
            }

            const w = Module._c_api_getCanvasWidth(docPtr);
            const h = Module._c_api_getCanvasHeight(docPtr);
            console.log(`Canvas: ${w} x ${h}`);

          });
        </script>
      </body>
      </html>


#. **Serve the files**

   Modern browsers block non-trivial WASM loading from ``file://`` URLs.  Use a
   local dev server (e.g. ``python -m http.server``) during development.

#. **Next steps**

   * See the :doc:`C API reference <api_reference/c_api_index>` for full C-level details. Note the WASM build exposes the same C API as the native library, except for each function being prefixed with underscore (e.g. ``_c_api_readSBMLFromString`` instead of ``c_api_readSBMLFromString``).


Building from Source
--------------------

For users who need to build SBMLNetwork from source (e.g., to modify the **C++ Backend**), follow the instructions provided in the :doc:`Building from source </building>` section.

