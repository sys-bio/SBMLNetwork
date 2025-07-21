.. _building-from-source:

Building from source
====================

Here, we explain how to build **SBMLNetwork** from source for different environments:

* the native **C/C++ library** (with optional Python bindings), and
* the **JavaScript/WebAssembly** module for use in browsers.

Building C/C++ library (with optional Python bindings) from source
------------------------------------------------------------------

This section describes how to build the **SBMLNetwork native library** (C/C++) and, optionally, the associated **Python bindings**.

Prerequisites
~~~~~~~~~~~~~

* **CMake ≥ 3.16** plus a C++17‑capable compiler
* **libSBML (static)** binaries matching your platform – easiest is to download
  the archive from the
  `libroadrunner-deps release <https://github.com/sys-bio/libroadrunner-deps/releases>`_
* **Python 3.9–3.12** *(optional – required only if building the bindings)*

Build steps
~~~~~~~~~~~

1. Download or build the libSBML static binary files (preferably from `libroadrunner-deps release <https://github.com/sys-bio/libroadrunner-deps/releases>`_)
   and unpack them to a directory of your choice, e.g., `/path/to/libsbml-static`.
   This directory should contain the `include` and `lib` subdirectories with the
   headers and static libraries, respectively.

2. Clone the SBMLNetwork repository from GitHub:

   .. code-block:: bash

      git clone https://github.com/adelhpour/SBMLNetwork.git

3. Change into the repository:

   .. code-block:: bash

      cd SBMLNetwork

4. Create and enter the build directory:

   .. code-block:: bash

      mkdir build
      cd build

5. Configure the build:

   .. code-block:: bash

      cmake -DCMAKE_INSTALL_PREFIX=/path/to/install \
            -DCMAKE_BUILD_TYPE=Release \
            -DDEPENDENCIES_INSTALL_PREFIX=/path/to/libsbml-static \
            -DWITH_PYTHON=ON \
            -DPYTHON_INSTALL_WITH_SETUP=ON ..

6. Compile and install:

   .. code-block:: bash

      cmake --build build --target install

CMake options
~~~~~~~~~~~~~

``WITH_PYTHON``
    Build and install the ``sbmlnetwork`` and ``libsbmlnetwork`` Python packages alongside the native library.

``DEPENDENCIES_INSTALL_PREFIX``
    Path to the folder containing the unpacked *static* libSBML libraries and headers.

``CMAKE_OSX_ARCHITECTURES`` *(macOS only)*
    Override to build **arm64** or **x86_64**‑only binaries instead of a universal build.

For a complete, automated example of this build process across macOS, Linux, and Windows,
see the GitHub Actions workflow:

📄 `build.yml on GitHub <https://github.com/sys-bio/SBMLNetwork/blob/develop/.github/workflows/build.yml>`_


.. _building-webassembly:

Building JavaScript/WebAssembly module from source
--------------------------------------------------

This section describes how to build the **SBMLNetwork JavaScript/WebAssembly module**
for use in browsers or JavaScript environments like Node.js.

We use **Emscripten** to compile the C++ core of SBMLNetwork into a `.wasm` module
and generate a corresponding JavaScript interface (`.js`) that can be loaded in web applications.

Requirements
~~~~~~~~~~~~

Before starting, make sure you have:

* **Emscripten SDK ≥ 3.1.20** – install from https://emscripten.org
* **CMake ≥ 3.16**
* **GNU Make** (or Ninja)
* A Linux or macOS build environment (Windows builds are not currently supported)

You will also need to build **Expat** and **libSBML** with Emscripten first, before compiling SBMLNetwork.

Build steps
~~~~~~~~~~~

1. **Install and activate Emscripten**

   .. code-block:: bash

      git clone https://github.com/emscripten-core/emsdk.git
      cd emsdk
      ./emsdk install 3.1.20
      ./emsdk activate 3.1.20
      source ./emsdk_env.sh

2. **Build Expat with Emscripten**

   .. code-block:: bash

      wget https://github.com/libexpat/libexpat/releases/download/R_2_2_10/expat-2.2.10.tar.bz2
      tar -xf expat-2.2.10.tar.bz2 && cd expat-2.2.10
      mkdir build && cd build
      emcmake cmake .. -DCMAKE_INSTALL_PREFIX=$PWD/../../install/expat
      emmake make && emmake make install

3. **Build libSBML with layout and render enabled**

   .. code-block:: bash

      wget https://github.com/sbmlteam/libsbml/archive/refs/tags/v5.20.0.zip
      unzip v5.20.0.zip && cd libsbml-5.20.0
      mkdir build && cd build
      emcmake cmake .. \
         -DCMAKE_INSTALL_PREFIX=$PWD/../../../install/sbml \
         -DCMAKE_BUILD_TYPE=Release \
         -DWITH_CPP_NAMESPACE=ON \
         -DWITH_EXPAT=ON \
         -DWITH_LIBXML=OFF \
         -DLIBSBML_SKIP_SHARED_LIBRARY=ON \
         -DENABLE_LAYOUT=ON \
         -DENABLE_RENDER=ON \
         -DWITH_STABLE_PACKAGES=ON \
         -DWITH_SWIG=OFF \
         -DEXPAT_INCLUDE_DIR=$PWD/../../../install/expat/include \
         -DEXPAT_LIBRARY=$PWD/../../../install/expat/lib/libexpat.a
      emmake make && emmake make install

4. **Build SBMLNetwork**

   .. code-block:: bash

      wget https://github.com/sys-bio/SBMLNetwork/archive/refs/tags/v0.4.5.zip
      unzip v0.4.5.zip && cd SBMLNetwork-0.4.5
      mkdir build && cd build
      emcmake cmake .. \
         -DCMAKE_INSTALL_PREFIX=$PWD/../../../install/sbmlnetwork \
         -DCMAKE_BUILD_TYPE=Release \
         -DEXPAT_INSTALL_PREFIX=$PWD/../../../install/expat \
         -DLIBEXPAT_LIBRARY=$PWD/../../../install/expat/lib/libexpat.a \
         -DLIBSBML_INSTALL_PREFIX=$PWD/../../../install/sbml \
         -DLIBSBML_LIBRARY=$PWD/../../../install/sbml/lib/libsbml-static.a \
         -DWITH_PYTHON=OFF
      emmake make && emmake make install

5. **Generate the final JavaScript and WASM files**

   .. code-block:: bash

      em++ -Iinstall/sbmlnetwork/include \
           -Iinstall/sbml/include \
           -Iinstall/expat/include \
           install/sbmlnetwork/lib/libsbmlnetwork.a \
           install/sbml/lib/libsbml-static.a \
           install/expat/lib/libexpat.a \
           -o libsbmlnetwork.js \
           -s WASM=1 \
           -s LINKABLE=1 \
           -s EXPORT_ALL=1 \
           -s MODULARIZE=1 \
           -s EXPORT_ES6=1 \
           -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "allocateUTF8", "UTF8ToString"]'

   This will generate two output files:
   * ``libsbmlnetwork.js`` – the JavaScript wrapper
   * ``libsbmlnetwork.wasm`` – the compiled WebAssembly module

Usage
~~~~~

Once built, the resulting files (`libsbmlnetwork.js` and `libsbmlnetwork.wasm`) can be used. See the :doc:`Installation <installation>` page for instructions on how to import and use the WebAssembly module in your application.

For a complete, working version of this WebAssembly build pipeline using Emscripten,
see the GitHub Actions workflow:

📄 `build-libsbmlnetworkjs.yml on GitHub <https://github.com/sys-bio/SBMLNetwork/blob/develop/.github/workflows/build-libsbmlnetworkjs.yml>`_
