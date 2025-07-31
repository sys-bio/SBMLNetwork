Ellipse
-------

The **Ellipse** class is a concrete `Shape <./shape.html>`__
implementation that represents axis‑aligned elliptical shapes used to depict
compartments, species, reaction glyphs, or any additional oval‑like graphics in
an SBMLNetwork diagram.

An Ellipse records its **relative center** within the parent element,
its **radii** (`rx` × `ry`), and the usual **styling** attributes (border, fill, etc.)
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

    # Get the first species in the network
    species = net.get_species_list()[0]

    # Set the shape to ellipse
    species.set_shape("ellipse")

    # Get the shape of the species
    shape = species.get_shape()

    # Check if it's an ellipse
    if shape.get_type() == "ellipse":
        print("The species shape is an ellipse.")

Core Methods
************

Identificaiton
==============

.. py:method:: get_type()

   Return the geometry type – ``"ellipse"``

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

.. py:method:: get_relative_center()

   Get the ellipse’s relative center as an ``(x, y)`` tuple,
   in diagram coordinate units.

   :rtype: tuple[float, float]

.. py:method:: set_relative_center(center)

   Set the ellipse’s relative center.

   :param center: New center coordinates as ``(x, y)``.
   :type center: tuple[float, float]

.. py:method:: get_radii()

   Get the ellipse’s radii as an ``(rx, ry)`` tuple.

   :rtype: tuple[float, float]

.. py:method:: set_radii(radii)

   Set the ellipse’s radii.

   :param radii: New radii as ``(rx, ry)``.
   :type radii: tuple[float, float]

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
for a `Ellipse` shape:

.. code-block:: python

    import sbmlnetwork as sn

    # Load your SBML model
    net = sn.load("my_model.xml")

    # Get the first species
    species = net.get_species_list()[0]

    # Set the shape to Ellipse
    species.set_shape("ellipse")

    # Grab the first Ellipse for a given element
    ellipse = species.get_shape()

    # Inspect current style & geometry
    print("Center         :", ellipse.get_relative_center())   # (x, y)
    print("Radii          :", ellipse.get_radii())             # (rx, ry)
    print("Border color   :", ellipse.get_border_color())
    print("Border thickness:", ellipse.get_border_thickness())
    print("Fill color     :", ellipse.get_fill_color())

    # Update styling
    ellipse.set_fill_color("#cc6633")
    ellipse.set_border_color((0, 51, 204))    # RGB tuple for a deep blue
    ellipse.set_border_thickness(5.0)

    # Update geometry
    ellipse.set_relative_center((150.0, 75.0))
    ellipse.set_radii((60.0, 30.0))

    # Re-render and log
    net.draw("ellipse_styling_demo.png")
    print(ellipse.get_info())
