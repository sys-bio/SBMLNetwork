Python API Reference
====================

Introduction
------------

For many biologists, working with SBML models is familiar, but translating them into meaningful visual representations can be challenging. The **SBMLNetwork Python Package** provides an intuitive way to explore SBML-based networks without requiring advanced programming knowledge. It offers structured access to **compartments**, **species**, and **reactions**, each represented with labels, shapes, and curves that reflect SBML concepts. By abstracting away visualization complexities, this API allows users to focus on biological insights rather than rendering details.

Conceptual Overview of the Network Structure
--------------------------------------------

SBMLNetwork visualizes biological networks in a way that mirrors the structure of SBML models. The network is composed of three key components:

- **Compartments**:
  Compartments act as containers for biological entities and processes. Each compartment is represented with its own label and shape, and provides direct access to the species and reactions it contains. This mirrors the idea of grouping related elements within a specific cellular or spatial context.

- **Species**:
  Species represent individual biological entities, such as molecules or genes, and are depicted as nodes. Each species comes with a label and a shape, and is connected to reactions via curves, visually demonstrating their role in various biological processes.

- **Reactions**:
  Reactions capture the interactions between species. Each reaction is labeled and features a central point, from which curves extend to illustrate the flow of interactions. These curves may consist of multiple segments and include arrowheads to indicate directionality. Reactions also provide access to the associated species, emphasizing the dynamic connectivity within the network.

This hierarchical structure is designed to align with the intuitive understanding of SBML models, allowing users to easily navigate and visualize the complex interplay between different biological elements.

Breakdown of Components
-----------------------


This diagram illustrates how the API components are structured, making it easier to understand their relationships and roles in the visualization of SBML-based networks.
The high-level API is organized into a clear, hierarchical structure. Below are the diagrams of the components and their relationships:

Network
^^^^^^^

.. graphviz::
   :caption: High-Level API Architecture

   digraph sbml_network {
    rankdir=TB;
    node [shape=record, style=rounded, fontname=Helvetica];

    Network [label="Network"];
    Compartments [
        label=<
            <table border="0" cellborder="0" cellpadding="5">
                <tr>
                    <td>Compartments</td>
                </tr>
                <tr>
                    <td><font point-size="10">- Shapes</font></td>
                </tr>
                <tr>
                    <td><font point-size="10">- Labels</font></td>
                </tr>
            </table>
        >,
        shape=record,
        style=rounded,
        URL="http://compartments-info.com",
        tooltip="Click for more compartment details"
    ];
    Species [
        label=<
            <table border="0" cellborder="0" cellpadding="5">
                <tr>
                    <td>Species</td>
                </tr>
                <tr>
                    <td><font point-size="10">- Shapes</font></td>
                </tr>
                <tr>
                    <td><font point-size="10">- Labels</font></td>
                </tr>
            </table>
        >,
        shape=record,
        style=rounded,
        URL="http://species-info.com",
        tooltip="Click for more species details"
    ];
    Reactions [
        label=<
            <table border="0" cellborder="0" cellpadding="5">
                <tr>
                    <td>Reactions</td>
                </tr>
                <tr>
                    <td><font point-size="10">- Center</font></td>
                </tr>
                <tr>
                    <td><font point-size="10">- Labels</font></td>
                </tr>
            </table>
        >,
        shape=record,
        style=rounded,
        URL="http://reactions-info.com",
        tooltip="Click for more reaction details"
    ];
    Curves [
        label=<
            <table border="0" cellborder="0" cellpadding="5">
                <tr>
                    <td>Curves</td>
                </tr>
                <tr>
                    <td><font point-size="10">- Segments</font></td>
                </tr>
                <tr>
                    <td><font point-size="10">- Arrowheads</font></td>
                </tr>
            </table>
        >,
        shape=record,
        style=rounded,
        URL="http://curves-info.com",
        tooltip="Click for more curve details"
    ];
    Labels [
        label=<
            <table border="0" cellborder="0" cellpadding="5">
                <tr>
                    <td>Labels</td>
                </tr>
                <tr>
                    <td><font point-size="10">- Text</font></td>
                </tr>
                <tr>
                    <td><font point-size="10">- Position</font></td>
                </tr>
            </table>
        >,
        shape=record,
        style=rounded,
        URL="http://labels-info.com",
        tooltip="Click for more label details"
    ];
    Shapes [
        label=<
            <table border="0" cellborder="0" cellpadding="5">
                <tr>
                    <td>Shapes</td>
                </tr>
                <tr>
                    <td><font point-size="10">- Type</font></td>
                </tr>
                <tr>
                    <td><font point-size="10">- Size</font></td>
                </tr>
            </table>
        >,
        shape=record,
        style=rounded,
        URL="http://shapes-info.com",
        tooltip="Click for more shape details"
    ];

    Network -> Compartments;
    Compartments -> Labels;
    Compartments -> Shapes;
    Network -> Species;
    Species -> Labels;
    Species -> Shapes;
    Network -> Reactions;
    Reactions -> Curves;



   }

