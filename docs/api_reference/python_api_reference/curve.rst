Curve
-----

The **Curve** class represents the graphical connection between elements in a reaction,
typically used to draw the edges that link species to a reaction center and to each other.
A Curve holds one or more `Curve Segments <./curve_segment.html>`__, which define its actual path
(straight lines or Bezier curves), and an optional **Arrowhead** that indicates the
direction or type of connection.

Each `Reaction <./reaction.html>`__ can have **multiple Curves** — for example, to draw edges from reactants
to the reaction center and then to products.

After loading a model and retrieving a Reaction or Species, you can:

* Retrieve **all Curves** associated with a Reaction using
  :py:meth:`~Reaction.get_curves_list`.
* Retrieve **all Curves** connected to a Species using
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

A Curve contains all the details needed to draw its path and arrowhead.
The diagram below shows how a Curve contains multiple `Curve Segments <./curve_segment.html>`__
and may include an optional **Arrowhead**.

.. graphviz::
   :align: center

   digraph curve_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Curve [
       label=< <font color="#3366cc">Curve</font> >,
       URL="curve.html",
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
       URL="curve_segment.html",
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
       URL="arrow_head.html",
       tooltip="Optional arrowhead"
     ];

     Curve -> CurveSegments;
     Curve -> Arrowhead;
   }

Core Methods
************

Identification
==============

.. py:method:: get_reaction()

   Return the parent :class:`~sbmlnetwork.Reaction` object for this Curve.

   :rtype: Reaction

.. py:method:: get_species()

   Return the :class:`~sbmlnetwork.Species` this Curve connects to, or ``None``.

   :rtype: Species or None

.. py:method:: get_role()

   Return the role of the species reference (e.g., `"substrate"`, `"product"`, `"modifier"`).

   :rtype: str

Path Geometry
=============

.. py:method:: get_start()

   Return the absolute *(x, y)* coordinates of the Curve’s first segment start point.

   :rtype: tuple[float, float]

.. py:method:: set_start(start)

   Move the first segment start (and its first control point) to the given *(x, y)*.

   :param start: New start coordinates.

.. py:method:: get_end()

   Return the absolute *(x, y)* coordinates of the Curve’s last segment end point.

   :rtype: tuple[float, float]

.. py:method:: set_end(end)

   Move the last segment end (and its second control point) to the given *(x, y)*.

   :param end: New end coordinates.

.. py:method:: get_start_slope()

   Compute and return the angle (in radians) of the tangent at the start of the Curve.

   :rtype: float

.. py:method:: get_end_slope()

   Compute and return the angle (in radians) of the tangent at the end of the Curve.

   :rtype: float

Segments Management
===================

.. py:method:: add_segment(start, end, control_point_1=None, control_point_2=None)

   Append a cubic Bézier segment to the Curve with specified endpoints and optional control points.

   :param start: Segment start *(x, y)*.
   :param end: Segment end *(x, y)*.
   :param control_point_1: First control point *(x, y)* (defaults to start).
   :param control_point_2: Second control point *(x, y)* (defaults to end).

.. py:method:: remove_segment(segment)

   Remove a segment by index or :class:`~sbmlnetwork.CurveSegment` object.

   :param segment: Integer index or CurveSegment instance.

.. py:method:: get_segment(curve_segment_index=0)

   Return the segment at the given index.

   :param curve_segment_index: Zero-based index.
   :rtype: CurveSegment or None

.. py:method:: get_segments_list()

   Return a list of all :class:`~sbmlnetwork.CurveSegment` objects for this Curve.

   :rtype: CurveSegmentList

.. py:method:: get_segments()

   Alias for :py:meth:`get_segments_list`.

.. py:property:: segments

   Shorthand for :py:meth:`get_segments_list`.

Movement
========

.. py:method:: move_by(delta)

   Translate the entire Curve path by the given offset.

   :param delta: *(dx, dy)* in diagram units.

.. py:method:: move_start_to(position)

   Move the start of the Curve to an absolute position, adjusting control points.

   :param position: New start *(x, y)*.

.. py:method:: move_start_by(delta)

   Move the start of the Curve by the given offset.

   :param delta: *(dx, dy)*.

.. py:method:: move_end_to(position, adjust_end_point_for_uni_uni_reaction=False)

   Move the end of the Curve to an absolute position; for simple uni–uni reactions,
   optionally adjust both curves symmetrically.

   :param position: New end *(x, y)*.
   :param adjust_end_point_for_uni_uni_reaction: ``True`` to auto-adjust paired curve.

.. py:method:: move_end_by(delta, adjust_end_point_for_uni_uni_reaction=False)

   Move the end of the Curve by the given offset; see :py:meth:`move_end_to`.

   :param delta: *(dx, dy)*.
   :param adjust_end_point_for_uni_uni_reaction: See :py:meth:`move_end_to`.

Styling
========

.. py:method:: get_color()

   Return the curve line colour as a hex string or RGB tuple.

   :rtype: str or tuple[int, int, int]

.. py:method:: set_color(color)

   Set the curve line colour.

   :param color: Hex string (e.g. `"#rrggbb"`) or RGB tuple `(r, g, b)`.

.. py:method:: get_thickness()

   Return the line width of the Curve.

   :rtype: float

.. py:method:: set_thickness(thickness)

   Set the line width of the Curve.

   :param thickness: Line width in diagram units.

Arrowhead
=========

.. py:method:: get_arrow_head()

   Return the attached :class:`~sbmlnetwork.ArrowHead` object, or ``None``.

   :rtype: ArrowHead or None

.. py:method:: get_arrow_head_relative_position()

   Return the arrowhead position relative to the Curve.

   :rtype: tuple[float, float]

.. py:method:: set_arrow_head_relative_position(relative_position)

   Move the arrowhead to the given relative *(dx, dy)*.

   :param relative_position: Offset from Curve path.

.. py:method:: get_arrow_head_size()

   Return the width and height of the arrowhead.

   :rtype: tuple[float, float]

.. py:method:: set_arrow_head_size(size)

   Set the arrowhead dimensions.

   :param size: *(width, height)* in diagram units.

.. py:method:: get_arrow_head_shapes()

   Return the shape type(s) of the arrowhead.

   :rtype: str

.. py:method:: set_arrow_head_shapes(shape)

   Set the arrowhead shape (e.g., `"triangle"`, `"diamond"`).

   :param shape: Shape name.

.. py:method:: get_arrow_head_border_color()

   Return the arrowhead border colour.

   :rtype: str or tuple[int, int, int]

.. py:method:: set_arrow_head_border_color(border_color)

   Set the arrowhead border colour.

   :param border_color: Hex string or RGB tuple.

.. py:method:: get_arrow_head_border_thickness()

   Return the arrowhead border width.

   :rtype: float

.. py:method:: set_arrow_head_border_thickness(thickness)

   Set the arrowhead border width.

   :param thickness: Line width in diagram units.

.. py:method:: get_arrow_head_fill_color()

   Return the arrowhead fill colour.

   :rtype: str or tuple[int, int, int]

.. py:method:: set_arrow_head_fill_color(fill_color)

   Set the arrowhead fill colour.

   :param fill_color: Hex string, RGB tuple, or list.

Visibility
==========

.. py:method:: show()

   Make this Curve visible in the diagram.

.. py:method:: hide()

   Make this Curve invisible in the diagram.

.. py:method:: is_hidden()

   Return whether this Curve is currently hidden.

   :rtype: bool

Information
===========

.. py:property:: info

   Human-readable summary of the Curve’s state for debugging.

   :rtype: str

.. py:method:: get_info()

   Generate the info string used by :py:attr:`info`.

Example workflow
****************

Below is a script demonstrating how to discover, inspect, and modify Curves:

.. code-block:: python

   import sbmlnetwork as sn

    # Load the SBML model
    net = sn.load("my_model.xml")

    # Select a reaction and its first curve
    rxn = net.get_reactions_list()[0]
    curve = rxn.get_curves_list()[0]

    # Inspect basic properties
    print("Role      :", curve.role)
    print("Color     :", curve.get_color())
    print("Thickness :", curve.thickness)
    print("Start     :", curve.start, "Slope:", curve.start_slope)

    # Change styling
    curve.set_color("#cc6633")
    curve.set_thickness(3.0)

    # Add a new Bézier segment
    curve.add_segment((50, 50), (100, 100), (60, 60), (90, 90))

    # Move the curve
    curve.move_by((10, -20))

    # Toggle visibility
    curve.hide()
    curve.show()

    # Debug summary
    print(curve.info)