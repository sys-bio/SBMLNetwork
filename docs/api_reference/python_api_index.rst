Python API Reference
====================

For many biologists, working with SBML models is familiar, but translating them into meaningful visual representations can be challenging. The **SBMLNetwork Python Package** provides an intuitive way to explore SBML-based visualized networks without requiring advanced programming knowledge. By abstracting away visualization complexities, this API allows users to focus on biological insights rather than rendering details.

The following sections dive into each core class of the SBMLNetwork, including `Network <./python_api_reference/network.html>`__, `Compartment <./python_api_reference/compartment.html>`__, `Species <./python_api_reference/species.html>`__, and `Reaction <./python_api_reference/reaction.html>`__, showing how they expose SBML data and the visual elements they own.

Network
-------

The `Network <./python_api_reference/network.html>`__ class is the central entry-point of the SBMLNetwork API. The fastest way to obtain a ``Network`` instance is the
:py:meth:`~sbmlnetwork.load` class method:

.. code-block:: python

   import sbmlnetwork as sn

   net = sn.load("my_model.xml")

   # Network Extents
   print(net.get_size())


A `Network <./python_api_reference/network.html>`__ object holds every visual element derived from an SBML model—
`Compartment <./python_api_reference/compartment.html>`__, `Species <./python_api_reference/species.html>`__, and `Reaction <./python_api_reference/reaction.html>`__ —so its structure mirrors the
hierarchy of the underlying file. The diagram below shows how these core components are organized and how they relate to each other in the visualized network.

.. graphviz::
   :align: center

   digraph sbml_network {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Network [
       label=< <font color="#3366cc">Network</font> >,
       URL="python_api_reference/network.html",
       tooltip="Click for more network details"
     ];

     Compartments [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Compartments</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/compartment.html",
       tooltip="Click for more compartment details"
     ];

     Species [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Species</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/species.html",
       tooltip="Click for more species details"
     ];

     Reactions [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Reactions</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/reaction.html",
       tooltip="Click for more reaction details"
     ];

     Network -> Compartments;
     Network -> Species;
     Network -> Reactions;
   }

For a full list of methods exposed by the `Network <./python_api_reference/network.html>`__ class, click the link to view the API reference.

Compartment
-----------

The `Compartment <./python_api_reference/compartment.html>`__ class represents a spatial or logical container within the SBMLNetwork model. It groups related biological species and reactions within a defined boundary—just as compartments do in SBML itself.

After loading a model you can:

* Get just the **IDs** (strings) with :py:meth:`~sbmlnetwork.SBMLNetwork.get_compartment_ids`.
* Retrieve **one** compartment by ID with :py:meth:`~sbmlnetwork.SBMLNetwork.get_compartment`.
* Get the **full list** of compartment objects via :py:meth:`~sbmlnetwork.SBMLNetwork.get_compartments_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get compartment ids
    compartment_ids = net.get_compartment_ids()

    # Single compartment
    compartment = net.get_compartment(compartment_ids[0])
    print(compartment.get_compartment_id())

    # All compartments
    for comp in net.get_compartments_list():
       print(comp.get_compartment_id())

In the visualization context, each Compartment includes its own `Shapes <./python_api_reference/shape.html>`__ and `Labels <./python_api_reference/label.html>`__, which define how the compartment is drawn and annotated in the rendered network diagram. The diagram below shows how a `Compartment <./python_api_reference/compartment.html>`__ connects to its `Shape <./python_api_reference/shape.html>`__ and `Label <./python_api_reference/label.html>`__ elements:

.. graphviz::
   :align: center

   digraph compartment_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Compartment [
       label=< <font color="#3366cc">Compartment</font> >,
       URL="python_api_reference/compartment.html",
       tooltip="Click for more about Compartment"
     ];

     Shapes [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Shapes</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/shape.html",
       tooltip="Click for more about Shapes"
     ];

     Labels [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Labels</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/label.html",
       tooltip="Click for more about Labels"
     ];

     Compartment -> Shapes;
     Compartment -> Labels;
   }

For a full list of methods exposed by the `Compartment <./python_api_reference/compartment.html>`__ class, click the link to view the API reference.

Species
-------

The `Species <./python_api_reference/species.html>`__ class represents individual biological entities within the SBMLNetwork model — for example, molecules, proteins, or genes. Each Species corresponds to a node in the network diagram and visually communicates its presence and role in the system.

After loading a model you can:

* Get just the **IDs** (strings) with :py:meth:`~sbmlnetwork.SBMLNetwork.get_species_ids`.
* Retrieve **one** species by ID with :py:meth:`~sbmlnetwork.SBMLNetwork.get_species`.
* Get the **full list** of species objects via :py:meth:`~sbmlnetwork.SBMLNetwork.get_species_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get Species ids
    species_ids = net.get_species_ids()

    # Single species
    species = net.get_species(species_ids[0])
    print(species.get_species_id())

    # All species
    for sp in net.get_species_list():
       print(sp.get_species_id())

In the visualization context, each Species includes its own `Shapes <./python_api_reference/shape.html>`__ and `Labels <./python_api_reference/label.html>`__, which define how the species is drawn and annotated within the network. The diagram below shows how a `Species <./python_api_reference/species.html>`__ connects to its `Shape <./python_api_reference/shape.html>`__ and `Label <./python_api_reference/label.html>`__ elements:


.. graphviz::
   :align: center

   digraph species_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Species [
       label=< <font color="#3366cc">Species</font> >,
       URL="python_api_reference/species.html",
       tooltip="Click for more about Species"
     ];

     Shapes [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Shapes</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/shape.html",
       tooltip="Click for more about Shapes"
     ];

     Labels [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Labels</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/label.html",
       tooltip="Click for more about Labels"
     ];

     Species -> Shapes;
     Species -> Labels;
   }

For a full list of methods exposed by the `Species <./python_api_reference/species.html>`__ class, click the link to view the API reference.

Reaction
--------

The `Reaction <./python_api_reference/reaction.html>`__ class represents an interaction or transformation within the SBMLNetwork model — for example, a biochemical reaction or regulatory event. Each `Reaction <./python_api_reference/reaction.html>`__ links `Species <./python_api_reference/species.html>`__ together and shows how entities are converted, produced, or modified as part of the network’s dynamic behavior.

After loading a model you can:

* Get just the **IDs** (strings) with :py:meth:`~sbmlnetwork.SBMLNetwork.get_reaction_ids`.
* Retrieve **one** reaction by ID with :py:meth:`~sbmlnetwork.SBMLNetwork.get_reaction`.
* Get the **full list** of reaction objects via :py:meth:`~sbmlnetwork.SBMLNetwork.get_reactions_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get reaction ids
    reaction_ids = net.get_reaction_ids()

    # Single reaction
    rxn = net.get_reaction(reaction_ids[0])
    print(rxn.get_reaction_id())

    # All reactions
    for r in net.get_reactions_list():
       print(r.get_reaction_id())

Visually, each `Reaction <./python_api_reference/reaction.html>`__ includes its own `Reaction Center <./python_api_reference/reaction_center.html>`__, `Labels <./python_api_reference/label.html>`__, `Curves <./python_api_reference/curve.html>`__, which define how the reaction is drawn, annotated, and connected to other components in the diagram.

The diagram below shows how a `Reaction <./python_api_reference/reaction.html>`__ connects to its `Curves <./python_api_reference/curve.html>`__, `Reaction Center <./python_api_reference/reaction_center.html>`__, and `Labels <./python_api_reference/label.html>`__ elements:


.. graphviz::
   :align: center

   digraph reaction_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Reaction [
       label=< <font color="#3366cc">Reaction</font> >,
       URL="python_api_reference/reaction.html",
       tooltip="Click for more about Reaction"
     ];

     Curves [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Curves</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/curve.html",
       tooltip="Click for more about Curves"
     ];

     ReactionCenter [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Reaction Center</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/reaction_center.html",
       tooltip="Click for more about Reaction Center"
     ];

     Labels [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Labels</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/label.html",
       tooltip="Click for more about Labels"
     ];

     Reaction -> Curves;
     Reaction -> ReactionCenter;
     Reaction -> Labels;
   }

For a full list of methods exposed by the `Reaction <./python_api_reference/reaction.html>`__ class, click the link to view the API reference.

Shape
-----

The `Shape <./python_api_reference/shape.html>`__ class captures the geometric appearance of any network element
(`Compartment <./python_api_reference/compartment.html>`__, `Species <./python_api_reference/species.html>`__, or `Reaction <./python_api_reference/reaction.html>`__).  A `Shape <./python_api_reference/shape.html>`__ contains the **type** of geometry
(e.g., rectangle, ellipse, polygon), its **position** and **dimensions** in the
diagram, and **styling** info such as border or fill colour.  Every visual
object that appears on the canvas can have mutliple Shapes associated with it.

After loading a model and retreiving a model element, you can

* Retrieve the first associated `Shape <./python_api_reference/shape.html>`__ with
  :py:meth:`~NetworkELementBase.get_shape`.
* Retrieve all the `Shape <./python_api_reference/shape.html>`__ objects associated with the network element
  :py:meth:`~NetworkELementBase.get_shapes_list` helper.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get species ids
    species_ids = net.get_species_ids()

    # Shape for a specific species
    species_shape = net.get_species(species_ids[0]).get_shape()
    print(species_shape.get_type())

    # Add a new shape to the species
    net.get_species(species_ids[0]).add_shape("ellipse")

    # All shapes for a species
    for sh in net.get_species(species_ids[0]).get_shapes_list():
        print(sh.get_type())

A `Shape <./python_api_reference/shape.html>`__ records the styling and geometry details needed to draw a network element.
The diagram below shows the inheritance structure: the abstract base `Shape <./python_api_reference/shape.html>`__
class is extended by concrete shapes like Rectangle, Ellipse, and Polygon.

.. graphviz::
   :align: center

   digraph shape_hierarchy {
     rankdir=BT;                      // bottom-to-top layout
     node [shape=record, style=rounded, fontname=Helvetica];

     // abstract base
     Shape [
       label=<
         <table border="0" cellborder="0" cellpadding="4">
           <tr><td><font color="#3366cc">Shape</font></td></tr>
           <tr><td><font point-size="10"><i>abstract</i></font></td></tr>
         </table>
       >,
       URL="python_api_reference/shape.html",
       tooltip="Base Shape class"
     ];

     // concrete subclasses
     Rectangle [
       label=< <font color="#3366cc">Rectangle</font> >,
       URL="python_api_reference/rectangle.html",
       tooltip="Axis-aligned rectangle"
     ];

     Ellipse [
       label=< <font color="#3366cc">Ellipse</font> >,
       URL="python_api_reference/ellipse.html",
       tooltip="Ellipse or circle"
     ];

     Polygon [
       label=< <font color="#3366cc">Polygon</font> >,
       URL="python_api_reference/polygon.html",
       tooltip="Polygonal shape"
     ];

     // UML-style inheritance: open triangle at the base class
     Rectangle -> Shape [arrowhead="empty", arrowsize=1.1];
     Ellipse   -> Shape [arrowhead="empty", arrowsize=1.1];
     Polygon   -> Shape [arrowhead="empty", arrowsize=1.1];
   }

For a full list of methods exposed by the `Shape <./python_api_reference/shape.html>`__ abstract class and its concrete subclasses, click the link to view the API reference.

Label
-----

The `Label <./python_api_reference/label.html>`__ class defines the textual annotations attached to a network element
(such as a `Compartment <./python_api_reference/compartment.html>`__, `Species <./python_api_reference/species.html>`__, or `Reaction <./python_api_reference/reaction.html>`__). A `Label <./python_api_reference/label.html>`__ stores the displayed
**text**, its **position**, and optional **styling** like font size, colour, or alignment.
Every visual object on the canvas can have multiple `Labels <./python_api_reference/label.html>`__ to describe different
features or details.

After loading a model and retrieving a network element, you can:

* Get the first `Label <./python_api_reference/label.html>`__ for that element with
  :py:meth:`~NetworkElementBase.get_label`.
* Retrieve **all Label** objects attached to the element with
  :py:meth:`~NetworkElementBase.get_labels_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get Species ids
    species_ids = net.get_species_ids()

    # First label for a specific species
    species_label = net.get_species(species_ids[0]).get_label()
    print(species_label.get_text(), species_label.get_position())

    # Add a new label to the first species
    new_label = net.get_species(species_ids[0]).add_label("New Label", relative_position=(10, 10))

    # All labels for the same species
    for label in net.get_species(species_ids[0]).get_labels_list():
        print(label.get_text(), label.get_position())

For a full list of methods exposed by the `Label <./python_api_reference/label.html>`__ class, click the link to view the API reference.


Curve
-----

The `Curve <./python_api_reference/curve.html>`__ class represents the graphical connection between elements in a reaction,
typically used to draw the edges that link species to a reaction center and to each other.
A `Curve <./python_api_reference/curve.html>`__ holds one or more **Curve Segments**, which define its actual path
(straight lines or Bezier curves), and an optional **Arrowhead** that indicates the
direction or type of connection.

Each `Reaction <./python_api_reference/reaction.html>`__ can have multiple `Curve <./python_api_reference/curve.html>`__ — for example, to draw edges from reactants
to the reaction center and then to products.

After loading a model and retrieving a `Reaction <./python_api_reference/reaction.html>`__ or `Species <./python_api_reference/species.html>`__, you can:

* Retrieve all `Curves <./python_api_reference/curve.html>`__ associated with a `Reaction <./python_api_reference/reaction.html>`__ using
  :py:meth:`~Reaction.get_curves_list`.
* Retrieve all `Curves <./python_api_reference/curve.html>`__ connected to a `Species <./python_api_reference/species.html>`__ using
  :py:meth:`~Species.get_curves_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get species and reaction ids
    species_id = net.get_species_ids()[0]
    reaction_id = net.get_reaction_ids()[0]

    # All Curves for a Reaction
    for curve in net.get_reaction(reaction_id).get_curves_list():
       print(len(curve.get_segments()))

    # All Curves in a Reaction that connect to a specific Species
    for curve in net.get_reaction(reaction_id).get_curves_list(species_id):
       print(len(curve.get_segments()))

    # All Curves connected to a Species
    for curve in net.get_species(species_id).get_curves_list():
       print(len(curve.get_segments()))

    # All Curves connected to a Species, filtered by Reaction
    for curve in net.get_species(species_id).get_curves_list(reaction_id):
       print(len(curve.get_segments()))

A `Curve <./python_api_reference/curve.html>`__ contains all the details needed to draw its path and arrowhead.
The diagram below shows how a `Curve <./python_api_reference/curve.html>`__ contains multiple **Curve Segments**
and may include an optional **Arrowhead**.

.. graphviz::
   :align: center

   digraph curve_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Curve [
       label=< <font color="#3366cc">Curve</font> >,
       URL="python_api_reference/curve.html",
       tooltip="Base Curve class"
     ];

     CurveSegments [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Curve Segments</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/curve_segment.html",
       tooltip="Line or Bezier segments"
     ];

     Arrowhead [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Arrowhead</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="python_api_reference/arrow_head.html",
       tooltip="Optional arrowhead"
     ];

     Curve -> CurveSegments;
     Curve -> Arrowhead;
   }

For a full list of methods exposed by the `Curve <./python_api_reference/curve.html>`__ class, click the link to view the API reference.

Reaction Center
---------------

The `Reaction Center <./python_api_reference/reaction_center.html>`__ represents the visual anchor point of a `Reaction <./python_api_reference/reaction.html>`__ in the network diagram.
It serves as the central location where `Curves <./python_api_reference/curve.html>`__ connect reactants, products, and modifiers.

A `Reaction Center <./python_api_reference/reaction_center.html>`__ can be represented in **two ways**:

* As a `Curve <./python_api_reference/curve.html>`__ — for simple or implicit visual styles where the connection itself acts as the anchor.
* As a list of `Shapes <./python_api_reference/shape.html>`__ — for explicit, node-like visual centers that mirror how Species or Compartments are drawn.

After loading a model and retrieving a `Reaction <./python_api_reference/reaction.html>`__, you can:

* Get the `Reaction Center <./python_api_reference/reaction_center.html>`__ with
  :py:meth:`~Reaction.get_center`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    reaction_id = net.get_reaction_ids()[0]

    # Get the Reaction Center
    center = net.get_reaction(reaction_id).get_center()

    # If the center is a list of Shapes
    if center.is_shapes():
       for shape in center.get_shapes_list():
           print(shape.get_type())

    # Switch to curve
    center.switch_to_curve()

    # If the center is a Curve
    if center.is_curve():
       print(len(center.get_curve().get_segments()))

For a full list of methods exposed by the `Reaction Center <./python_api_reference/reaction_center.html>`__ class, click the link to view the API reference.

CurveSegment
------------

The **CurveSegment** class represents an individual segment of a `Curve <./python_api_reference/curve.html>`__ path—
a straight line or cubic Bézier curve defined by a start point, an end point,
and two control handles.

After loading a model and retrieving a `Curve <./python_api_reference/curve.html>`__, you can:

* Get a specific segment by index with
  :py:meth:`~sbmlnetwork.Curve.get_segment`.
* Iterate all segments via
  :py:meth:`~sbmlnetwork.Curve.get_segments_list` or the ``segments`` property.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get reaction id
    reaction_id = net.get_reaction_ids()[0]

    # Get curve segment coordinates
    curve = net.get_reaction(reaction_id).get_curves_list()[0]
    seg = curve.get_segment(0)
    print(seg.get_start(), seg.get_end())

For a full list of methods exposed by the `CurveSegment <./python_api_reference/curve_segment.html>`__ class, click the link to view the API reference.

ArrowHead
---------

The **ArrowHead** class encapsulates the arrow head at the end of a `Curve <./python_api_reference/curve.html>`__ in a `Reaction <./python_api_reference/reaction.html>`__. It provides methods to retrieve and modify the arrow head’s identifier, bounding box position and size, and any underlying geometric shapes and styling.

After loading a model and retrieving a `Curve <./python_api_reference/curve.html>`__ in a `Reaction <./python_api_reference/reaction.html>`__, you can:

* Obtain the **ArrowHead** instance via :py:meth:`Curve.get_arrow_head`.
* Inspect or update its position, size, shapes, and styling.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    # Load the SBML model
    net = sn.load("my_model.xml")

    # Get reaction id
    reaction_id = net.get_reaction_ids()[0]

    arrow_head = None

    # Find the first species that is a product of the reaction
    for species in net.get_species_list():
        if species.get_role(reaction_id) == "product":
            arrow_head = species.get_arrow_heads()[0]
            break

    # Inspect identifier and position
    print("ID:", arrow_head.get_id())
    print("Position:", arrow_head.get_relative_position())

For a full list of methods exposed by the `ArrowHead <./python_api_reference/arrow_head.html>`__ class, click the link to view the API reference.

Detailed API Reference Index
----------------------------

This section provides direct links to the detailed API reference pages for each SBMLNetwork class. Use the list below to navigate to the full method and attribute documentation.

.. toctree::
   :maxdepth: 1

   python_api_reference/network
   python_api_reference/compartment
   python_api_reference/species
   python_api_reference/reaction
   python_api_reference/shape
   python_api_reference/rectangle
   python_api_reference/ellipse
   python_api_reference/polygon
   python_api_reference/label
   python_api_reference/curve
   python_api_reference/reaction_center
   python_api_reference/curve_segment
   python_api_reference/arrow_head

