Label
-----

The **Label** class defines the textual annotations attached to a network element
(such as a `Compartment <./compartment.html>`__, `Species <./species.html>`__, or `Reaction <./reaction.html>`__). A Label stores the displayed
**text**, its **position**, and optional **styling** like font size, colour, or alignment.
Every visual object on the canvas can have multiple Labels to describe different
features or details.

After loading a model and retrieving a network element, you can:

* Get the **first Label** for that element with
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

Core Methods
************

Identificaiton
==============

.. py:method:: get_element_id()

   Return the SBML identifier of the parent network element this Label belongs to.

   :rtype: str

.. py:method:: get_text()

   Return the text content of this Label.

   :rtype: str

.. py:method:: set_text(text)

   Set the text content of this Label.

   :param text: New text for the label.
   :type text: str


Size & Placement
================

.. py:method:: get_position()

   Return the absolute diagram coordinates *(x, y)* of this Label’s origin.

   :rtype: tuple[float, float]

.. py:method:: set_position(position)

   Set the Label’s absolute position to the given *(x, y)* coordinates.

   :param position: New position in diagram units.
   :type position: tuple[float, float]

.. py:method:: get_relative_position()

   Return the Label’s position relative to its parent element’s origin.

   :rtype: tuple[float, float]

.. py:method:: set_relative_position(relative_position)

   Set the Label’s position relative to its parent element’s origin.

   :param relative_position: Offset *(dx, dy)* from the parent element.
   :type relative_position: tuple[float, float]

.. py:method:: get_size()

   Return the width and height of the Label’s bounding box.

   :rtype: tuple[float, float]

.. py:method:: set_size(size)

   Set the width and height of the Label’s bounding box.

   :param size: New (width, height) in diagram units.
   :type size: tuple[float, float]


Alignment Helpers
=================

.. py:method:: align_to_left()

   Align the text to the left edge of its bounding box.

.. py:method:: align_to_horizontal_center()

   Center the text horizontally within its bounding box.

.. py:method:: align_to_right()

   Align the text to the right edge of its bounding box.

.. py:method:: get_horizontal_alignment()

   Return the current horizontal alignment as one of "left", "center", or "right".

.. py:method:: align_to_top()

   Align the text to the top edge of its bounding box.

.. py:method:: align_to_vertical_center()

   Center the text vertically within its bounding box.

.. py:method:: align_to_baseline()

   Align the text to its font baseline within the bounding box.

.. py:method:: align_to_bottom()

   Align the text to the bottom edge of its bounding box.

.. py:method:: get_vertical_alignment()

   Return the current vertical alignment as one of "top", "center", "baseline", or "bottom".

Styling
========

.. py:method:: get_font()

   Return the font family used by this Label.

   :rtype: str

.. py:method:: set_font(font_family)

   Set the font family for this Label.

   :param font_family: Name of an installed font (e.g. `"Helvetica"`).
   :type font_family: str

.. py:method:: get_font_size()

   Return the font size in diagram units (or points).

   :rtype: float

.. py:method:: set_font_size(font_size)

   Set the font size for this Label.

   :param font_size: Size in diagram units (or points).
   :type font_size: float

.. py:method:: get_font_color()

   Return the font colour as a hex string or RGB tuple.

   :rtype: str or tuple[int, int, int]

.. py:method:: set_font_color(font_color)

   Set the font colour.

   :param font_color: Hex string (e.g. `"#rrggbb"`) or RGB tuple `(r, g, b)`.
   :type font_color: str or tuple[int, int, int]

.. py:method:: set_bold(bold=True)

   Enable or disable **bold** text.

   :param bold: `True` to set weight to `"bold"`, `False` for `"normal"`.

.. py:method:: is_bold()

   Return whether the text weight is currently **bold**.

   :rtype: bool

.. py:method:: set_italic(italic=True)

   Enable or disable *italic* text.

   :param italic: `True` to set style to `"italic"`, `False` for `"normal"`.

.. py:method:: is_italic()

   Return whether the text style is currently *italic*.

   :rtype: bool

Information
===========

.. py:property:: info

   Human-readable summary of glyph state for debugging.

   :rtype: str

.. py:method:: get_info()

   Generate the info string.

Example workflow
****************

The script below demonstrates how to discover Labels, inspect and update their content, styling, and placement, then re-render the diagram.

.. code-block:: python

    import sbmlnetwork as sn

    # Load the SBML model
    net = sn.load("my_model.xml")

    # Get the first Label for a species
    species = net.get_species_list()[0]
    label = species.get_label()

    # Inspect current state
    print("Text     :", label.get_text())
    print("Position :", label.get_position())
    print("Size     :", label.get_size())

    # Modify text content
    label.set_text("ATP")

    # Update styling
    label.set_font("Arial")
    label.set_font_size(12)
    label.set_font_color("#cc6633")
    label.set_bold(True)
    label.set_italic(False)

    # Update placement and alignment
    label.set_position((150.0, 80.0))
    label.align_to_horizontal_center()
    label.align_to_vertical_center()

    # Re-render to file
    net.draw("updated_diagram.png")

