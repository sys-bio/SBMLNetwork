ArrowHead
---------

The **ArrowHead** class encapsulates the arrow head at the end of a `Curve <./curve.html>`__ in a `Reaction <./reaction.html>`__. It provides methods to retrieve and modify the arrow head’s identifier, bounding box position and size, and any underlying geometric shapes and styling.

After loading a model and retrieving a `Curve <./curve.html>`__ in a `Reaction <./reaction.html>`__, you can:

* Obtain the **ArrowHead** instance via :py:meth:`Curve.get_arrow_head`.
* Inspect or update its position, size, shapes, and styling.

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

Core Methods
************

Identification
==============

.. py:method:: get_id()

    Return the unique identifier of the arrow head (start or end), or None if not defined.

   :rtype: str or None

Position
========

.. py:method:: get_relative_position()

    Get the (x, y) coordinates of the arrow head’s bounding box.

   :returns: A 2-tuple of floats representing (x, y).
   :rtype: tuple[float, float]

.. py:method:: set_relative_position(relative_position)

    Set the (x, y) coordinates of the arrow head’s bounding box.

   :param relative_position: A 2-tuple of floats representing the new (x, y).
   :type relative_position: tuple[float, float]
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

Size
====

.. py:method:: get_size()

    Get the (width, height) of the arrow head’s bounding box.

   :returns: A 2-tuple of floats representing (width, height).
   :rtype: tuple[float, float]

.. py:method:: set_size(size)

    Set the (width, height) of the arrow head’s bounding box.

   :param size: A 2-tuple of floats representing the new (width, height).
   :type size: tuple[float, float]
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

Shapes
======

.. py:method:: add_shape(shape_type)

    Add a new geometric shape of the given type to this arrow head.

   :param shape_type: One of the valid geometric shape type names.
   :type shape_type: str
   :returns: The newly created :py:class:`ShapeBase` instance, or None if creation failed.
   :rtype: ShapeBase or None

.. py:method:: remove_shape(shape)

    Remove the specified shape from this arrow head.

   :param shape: The :py:class:`ShapeBase` to remove.
   :type shape: ShapeBase
   :returns: True if removal succeeded, False otherwise.
   :rtype: bool

.. py:method:: get_shape()

    Retrieve the first geometric shape attached to this arrow head.

   :returns: A :py:class:`ShapeBase` or None if no shapes are present.
   :rtype: ShapeBase or None

.. py:method:: get_shapes_list()

    Return a list of all geometric shapes attached to this arrow head.

   :returns: A :py:class:`ShapeList` containing all shapes.
   :rtype: ShapeList

.. py:method:: get_shape_type()

    Get the types of all attached geometric shapes.

   :returns: A list of shape type names.
   :rtype: list[str]

Styling
=======

.. py:method:: get_border_color()

    Get the border color(s) of all attached shapes.

   :returns: A list of color values.
   :rtype: list[str]

.. py:method:: set_border_color(border_color)

    Set the border color for all attached shapes.

   :param border_color: A color string (e.g., “#RRGGBB”).
   :type border_color: str
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

.. py:method:: get_border_thickness()

    Get the border thickness(es) of all attached shapes.

   :returns: A list of floats.
   :rtype: list[float]

.. py:method:: set_border_thickness(thickness)

    Set the border thickness for all attached shapes.

   :param thickness: The new border thickness.
   :type thickness: float
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

.. py:method:: get_fill_color()

    Get the fill color(s) of all attached shapes.

   :returns: A list of color values.
   :rtype: list[str]

.. py:method:: set_fill_color(fill_color)

    Set the fill color for all attached shapes.

   :param fill_color: A color string or RGB tuple/list.
   :type fill_color: str or tuple or list
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

Movement
========

.. py:method:: move_relative_position_to(relative_position)

    Alias for :py:meth:`set_relative_position`.

   :param relative_position: A 2-tuple of floats representing the new (x, y).
   :type relative_position: tuple[float, float]
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

.. py:method:: move_relative_position_by(delta)

    Move the arrow head by the specified (dx, dy) offset.

   :param delta: A 2-tuple of floats representing (dx, dy).
   :type delta: tuple[float, float]
   :returns: True if the operation succeeded, False otherwise.
   :rtype: bool

Informational
=============

.. py:method:: get_info()

    Return a formatted summary string of the arrow head’s current state, including position, size, and attached shapes.

   :returns: A multi-line string summarizing internal state.
   :rtype: str

.. py:attribute:: info
   Alias for :py:meth:`get_info`.

Example workflow
****************

.. code-block:: python

    import sbmlnetwork as sn

    # Load the SBML model
    net = sn.load("my_model.xml")

    # Get an arrow head from the first reaction
    curves = net.get_reactions_list()[0].get_curves_list()
    arrow_head = None
    for curve in curves:
     if curve.get_arrow_head() is not None:
         arrow_head = curve.get_arrow_head()
         break

    # Inspect identifier and position
    print("ID:", arrow_head.get_id())
    print("Position:", arrow_head.get_relative_position())

    # Resize and restyle
    arrow_head.set_size((10.0, 8.0))
    arrow_head.set_fill_color("#333333")
    arrow_head.set_border_color("#000000")
