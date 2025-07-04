Shape
-----

The **Shape** class captures the geometric appearance of any network element
(`Compartment <./compartment.html>`__, `Species <./species.html>`__, or `Reaction <./reaction.html>`__).  A Shape contains the **type** of geometry
(e.g., rectangle, ellipse, polygon), its **position** and **dimensions** in the
diagram, and **styling** info such as border or fill colour.  Every visual
object that appears on the canvas can have mutliple Shapes associated with it.

After loading a model and retreiving a model element, you can

* Retrieve the first associated **Shape** with
  :py:meth:`~NetworkELementBase.get_shape`.
* Retrieve all the **Shape** objects associated with the network element
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

A Shape records the styling and geometry details needed to draw a network element.
The diagram below shows the inheritance structure: the abstract base ``Shape``
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
       URL="shape.html",
       tooltip="Base Shape class"
     ];

     // concrete subclasses
     Rectangle [
       label=< <font color="#3366cc">Rectangle</font> >,
       URL="rectangle.html",
       tooltip="Axis-aligned rectangle"
     ];

     Ellipse [
       label=< <font color="#3366cc">Ellipse</font> >,
       URL="ellipse.html",
       tooltip="Ellipse or circle"
     ];

     Polygon [
       label=< <font color="#3366cc">Polygon</font> >,
       URL="polygon.html",
       tooltip="Polygonal shape"
     ];

     // UML-style inheritance: open triangle at the base class
     Rectangle -> Shape [arrowhead="empty", arrowsize=1.1];
     Ellipse   -> Shape [arrowhead="empty", arrowsize=1.1];
     Polygon   -> Shape [arrowhead="empty", arrowsize=1.1];
   }

Core Methods
************

Identificaiton
==============

.. py:method:: get_type()

   Return the geometry type – ``"rectangle"``, ``"ellipse"``, ``"polygon"``,
   ``"curve"``, etc.

   :rtype: str

.. py:method:: get_element_id()

   Return the SBML identifier of the parent network element this Shape
   belongs to.

   :rtype: str

Styling
=======

.. py:method:: get_border_color()

   Current border colour of the Shape as a CSS *hex* string
   (``"#rrggbb"``) or a colour name supported by the renderer.

   :rtype: str

.. py:method:: set_border_color(border_color)

   Set the border colour.  Accepts a CSS *hex* string or a RGB **tuple** /
   **list** with values in the range 0‑255, e.g. ``(255, 0, 0)`` for red.

   :param border_color: New colour.
   :type border_color: str | tuple[int, int, int] | list[int]

.. py:method:: get_border_thickness()

   Border line width in **pixels**.

   :rtype: float

.. py:method:: set_border_thickness(thickness)

   Set the border line width.

   :param float thickness: New width in pixels.

.. py:method:: get_fill_color()

   Current interior (fill) colour.

   :rtype: str

.. py:method:: set_fill_color(fill_color)

   Set the interior colour.  Accepts the same value formats as
   :py:meth:`set_border_color`.

   :param fill_color: New fill colour.
   :type fill_color: str | tuple[int, int, int] | list[int]

Information
===========

.. py:property:: info

   Human-readable summary of glyph state for debugging.

   :rtype: str

.. py:method:: get_info()

   Generate the info string.

Example workflow
****************

The short script below demonstrates how to discover Shapes, change their
appearance, and render the diagram.

.. code-block:: python

    import sbmlnetwork as sn

    # Load the SBML file
    net = sn.load("my_model.xml")

    # Grab a Species glyph and its first Shape
    species = net.get_species_list()[0]
    shape = species.get_shapes_list()[0]

    # Inspect its current state
    print("Type :", shape.get_type())
    print("Border:", shape.get_border_color())
    print("Fill  :", shape.get_fill_color())

    # Make it visually stand‑out
    shape.set_fill_color("#cc6633")
    shape.set_border_color("#cc6633")
    shape.set_border_thickness(10)

    # Render the whole network to a PNG image
    net.draw("shape_demo.png")

    # Print a summary for the shapes info
    print(shape.get_info())
