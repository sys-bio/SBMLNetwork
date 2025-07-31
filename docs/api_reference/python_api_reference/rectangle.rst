Rectangle
---------


The **Rectangle** class is a concrete `Shape <./shape.html>`__
implementation that represents axis‑aligned rectangular shapes used to depict
compartments, species, reaction glyphs, or any additional box‑like graphics in
an SBMLNetwork diagram.

A Rectangle records its **top‑left corner** relative to the parent element,
its **size** (`width` × `height`), optional **corner radius** for
rounded boxes, and the usual **styling** attributes (border, fill, etc.)
inherited from Shape.

After loading a model and retreiving a model element, you can

* Retrieve the first associated **Shape** with
  :py:meth:`~NetworkELementBase.get_shape`.
* Retrieve all the **Shape** objects associated with the network element
  :py:meth:`~NetworkELementBase.get_shapes_list` helper.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Shape for a specific species
    shape = net.get_species_list()[0].get_shape()

    # Check if it's a Rectangle
    if shape.get_type() == "rectangle":
       print("Species shape is a rectangle.")

Core Methods
************

Identificaiton
==============

.. py:method:: get_type()

   Return the geometry type – ``"rectangle"``

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
   **list** with values in the range 0-255, e.g. ``(255, 0, 0)`` for red.

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

.. py:method:: get_relative_position()

   Get the rectangle’s relative position as an ``(x, y)`` tuple,
   in diagram coordinate units.

   :rtype: tuple[float, float]

.. py:method:: set_relative_position(relative_position)

   Set the rectangle’s relative position.

   :param relative_position: New coordinates as ``(x, y)``.
   :type relative_position: tuple[float, float]

.. py:method:: get_size()

   Get the width and height of the rectangle as a ``(width, height)`` tuple.

   :rtype: tuple[float, float]

.. py:method:: set_size(size)

   Set the rectangle’s dimensions.

   :param size: New dimensions as ``(width, height)``.
   :type size: tuple[float, float]

.. py:method:: get_corner_radius()

   Get the corner radii of the rectangle as an ``(rx, ry)`` tuple.

   :rtype: tuple[float, float]

.. py:method:: set_corner_radius(corner_radius)

   Set the corner radii of the rectangle.

   :param corner_radius: Radii as ``(rx, ry)``.
   :type corner_radius: tuple[float, float]

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
for a `Rectangle` shape:

.. code-block:: python

    import sbmlnetwork as sn

    # Load your SBML model
    net = sn.load("my_model.xml")

    # Access the first species in the network
    species = net.get_species_list()[0]

    # Set the shape to Rectangle
    species.set_shape("rectangle")

    # Grab the first Rectangle for a given element
    rect = species.get_shape()

    # Inspect current style & geometry
    print("Position       :", rect.get_relative_position())   # (x, y)
    print("Size           :", rect.get_size())                # (width, height)
    print("Corner radius  :", rect.get_corner_radius())       # (rx, ry)
    print("Border color   :", rect.get_border_color())
    print("Border thickness:", rect.get_border_thickness())
    print("Fill color     :", rect.get_fill_color())

    # Update styling
    rect.set_fill_color("#cc6633")
    rect.set_border_color((0, 51, 204))    # RGB tuple for a deep blue
    rect.set_border_thickness(5.0)

    # Update geometry
    rect.set_relative_position((150.0, 75.0))
    rect.set_size((120.0, 60.0))
    rect.set_corner_radius((8.0, 8.0))

    # Re-render and log
    net.draw("rectangle_styling_demo.png")
    print(rect.get_info())