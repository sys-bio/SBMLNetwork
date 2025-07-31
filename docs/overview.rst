.. _overview:

Overview
========

SBMLNetwork is a cross-platform library—built on a C++ core with native Python and WebAssembly bindings—that automatically generates and renders SBML Layout & Render info, transforming plain biochemical models into standards-compliant, publication-ready network diagrams with a single function call.

Key Capabilities
----------------

* **Standards fidelity** – full read/write support for SBML Layout & Render.

* **Reaction-aware autolayout** – Fruchterman–Reingold variant tuned for
  metabolic graphs.

* **Styling engine** – predefined templates like Escher to get you started,
  plus per-element overrides for colors, shapes, fonts, and stroke widths.

* **Data overlays** – map fluxes or concentrations to color gradients, line
  thickness, or node size with one call; automatic color-bar legend included.

* **Multi-format export** – render to PNG, SVG, PDF; high-quality drawing powered by Skia.

* **Multi-language API** – performance-oriented C++ core exposed to Python
  (PyPI) and JavaScript/WebAssembly for seamless embedding in desktop or web
  tools.

Who Is It For?
---------------

* **Modelers and computational biologists**
  Generate complete SBML Layout & Render info in one line, then fine-tune
  every glyph for publication-quality pathway figures or supplementary material.

* **Software developers and tool authors**
  Embed SBMLNetwork’s C API, Python package, or WebAssembly build to add
  standards-compliant visualization to desktop, CLI, or browser applications.

* **Educators and trainers**
  Use the high-level Python API in Jupyter notebooks to teach SBML Layout &
  Render concepts with immediate visual feedback.

.. _architecture_snapshot:

Architecture Snapshot
---------------------

.. figure:: _static/architecture.pdf
   :alt: Layered architecture of SBMLNetwork
   :width: 500px
   :align: center

   **Figure 1 – Layered design of SBMLNetwork.**
   A performance-oriented **C++ Core** is wrapped by a stable **C API**.
   Language-specific bindings build on that API to expose identical
   functionality in **Python** (PyPI package) and **JavaScript / WebAssembly**
   (browser). Thin user-facing layers—CLI helpers sit on top of the bindings.

Key design points
~~~~~~~~~~~~~~~~~

* **C++ Core** – Implements network data structures, SBML Layout & Render I/O,
  and a reaction-aware Fruchterman–Reingold autolayout algorithm.

* **C API** – A stable interface that exposes core functionality
  to other languages while insulating them from C++ implementation details.

* **Python binding** – Presents an intuitive, object-oriented hierarchy
  (``Network``, ``Species``, ``Reaction`` …) with concise methods,
  making visualization straightforward for modelers.

* **WebAssembly build** – Generated with *Emscripten* to provide the same
  high-level API in browsers, enabling interactive web tools and
  documentation demos.

Quick-Start
-----------

* **Install SBMLNetwork** – follow the step-by-step instructions in the
  :doc:`Installation <installation>` page.

* **Run your first example** – open the
  :doc:`Getting Started <getting_started>` guide fora quick walkthrough of using SBMLNetwork with simple examples.
