Polygon
-------

The **Polygon** class is a concrete `Shape <./shape.html>`__
implementation that represents arbitrary multi-vertex graphical shapes defined
by an ordered list of points. Polygon shapes can be used to depict irregular
compartment boundaries, custom species glyphs, reaction arcs, or any additional
user-defined shapes in an SBMLNetwork diagram.

A Polygon records its **points**, given as a sequence of ``(x, y)`` tuples that
define the vertices in relative diagram coordinates. It inherits all standard
**styling** attributes—border color, fill color, border thickness, dash style,
etc.—from :class:`ShapeBase`.

After loading a model and retreiving a model element, you can

* Retrieve the first associated **Shape** with
  :py:meth:`~NetworkELementBase.get_shape`.
* Retrieve all the **Shape** objects associated with the network element
  :py:meth:`~NetworkELementBase.get_shapes_list` helper.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get the first species in the network
    species = net.get_species_list()[0]

    # Set the shape to a type of polygon
    species.set_shape("triangle")

    # Get the shape of the species
    shape = species.get_shape()

    # Check if it's a triangle
    if shape.get_type() == "triangle":
        print("The species shape is a triangle.")
        print("Vertices:", shape.get_points())

Core Methods
************

Identificaiton
==============

.. py:method:: get_type()

   Return the specific polygon “sub-type” as stored in the model.
   This indicates which line-ending or marker shape the Polygon represents.

   :rtype: str

   Possible return values include:

   * ``"triangle"`` – a standard triangular
   * ``"diamond"`` – a diamond-shaped marker
   * ``"pentagon"`` – a pentagon-shaped marker
   * ``"octagon"`` – an octagon-shaped marker

Styling
=======

.. py:method:: get_border_color()

   Current border colour of the Shape as a CSS *hex* string
   (``"#rrggbb"``) or a colour name supported by the renderer.

   :rtype: str

.. py:method:: set_border_color(border_color)

   Set the border colour.  Accepts a CSS *hex* string or a RGB **tuple** /
   **list** with values in the range 0–255, e.g. ``(255, 0, 0)`` for red.

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

.. py:method:: get_points()

   Get the polygon’s vertices as a list of ``(x, y)`` tuples,
   in diagram coordinate units.

   :rtype: list[tuple[float, float]]

.. py:method:: set_points(points)

   Set the polygon’s vertices.

   :param points: New vertex coordinates as a list of ``(x, y)`` tuples.
   :type points: list[tuple[float, float]]

Information
===========

.. py:property:: info

   Human-readable summary of glyph state for debugging.

   :rtype: str

.. py:method:: get_info()

   Generate the info string.

Example workflow
****************

This snippet walks through inspecting and updating both appearance and layout
for a `Polygon` shape:

.. code-block:: python

    import sbmlnetwork as sn

    # Load your SBML model
    net = sn.load("my_model.xml")

    # Access the first species in the network
    species = net.get_species_list()[0]

    # Set the shape to Polygon
    species.set_shape("hexagon")

    # Grab the first Polygon for a given element
    poly = species.get_shape()

    # Inspect current style & geometry
    print("Points           :", poly.get_points())         # [(x1, y1), (x2, y2), …]
    print("Border color     :", poly.get_border_color())
    print("Border thickness :", poly.get_border_thickness())
    print("Fill color       :", poly.get_fill_color())

    # Update styling
    poly.set_fill_color("#cc6633")
    poly.set_border_color((0, 51, 204))    # RGB tuple for a deep blue
    poly.set_border_thickness(5.0)

    # Update geometry (e.g., shift each vertex by (+10, +5))
    original = poly.get_points()
    shifted = [(x + 10.0, y + 5.0) for x, y in original]
    poly.set_points(shifted)

    # Re-render and log
    net.draw("polygon_styling_demo.png")
    print(poly.get_info())
