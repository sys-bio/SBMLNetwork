CurveSegment
------------

The **CurveSegment** class represents an individual segment of a `Curve <./curve.html>`__ path—
a straight line or cubic Bézier curve defined by a start point, an end point,
and two control handles.

After loading a model and retrieving a `Curve <./curve.html>`__, you can:

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

Core Methods
************

Identification
==============

.. py:method:: get_curve_segment_index()

   Return the zero-based index of this segment within its parent Curve.

   :rtype: int

Endpoints
=========

.. py:method:: get_start()

   Return the starting point *(x, y)* of the segment.

   :rtype: tuple[float, float]

.. py:method:: set_start(start)

   Move the start point to the given *(x, y)* coordinates.

   :param start: New start coordinates.

.. py:method:: get_end()

   Return the end point *(x, y)* of the segment.

   :rtype: tuple[float, float]

.. py:method:: set_end(end)

   Move the end point to the given *(x, y)* coordinates.

   :param end: New end coordinates.

Control Points
==============

.. py:method:: get_control_point_1()

   Return the first Bézier control handle *(x, y)*.

   :rtype: tuple[float, float]

.. py:method:: set_control_point_1(control_point_1)

   Set the first control handle to the given coordinates.

   :param control_point_1: New control point *(x, y)*.

.. py:method:: get_control_point_2()

   Return the second Bézier control handle *(x, y)*.

   :rtype: tuple[float, float]

.. py:method:: set_control_point_2(control_point_2)

   Set the second control handle to the given coordinates.

   :param control_point_2: New control point *(x, y)*.

Movement
========

.. py:method:: move_by(delta)

   Translate this segment by the given offset, moving start, end, and control points.

   :param delta: Offset *(dx, dy)*.

.. py:method:: move_start_to(position)

   Move the start point to absolute coordinates, adjusting the first control point.

   :param position: New start *(x, y)*.

.. py:method:: move_start_by(delta)

   Move the start point and first control point by *(dx, dy)*.

   :param delta: Offset *(dx, dy)*.

.. py:method:: move_end_to(position)

   Move the end point to absolute coordinates, adjusting the second control point.

   :param position: New end *(x, y)*.

.. py:method:: move_end_by(delta)

   Move the end point and second control point by *(dx, dy)*.

   :param delta: Offset *(dx, dy)*.

Information
===========

.. py:property:: info

   Human-readable summary of glyph state for debugging.

   :rtype: str

.. py:method:: get_info()

   Generate the info string.

Example workflow
****************

.. code-block:: python

    import sbmlnetwork as sn

    # Load the SBML network and retrieve a reaction segment
    net = sn.load("my_model.xml")

    segment = net.get_reactions_list()[0].get_curves_list()[0].get_segment(0)

    # Inspect endpoints and handles
    print("Start            :", segment.start)
    print("Control point 1  :", segment.control_point_1)
    print("Control point 2  :", segment.control_point_2)
    print("End              :", segment.end)

    # Move the entire segment
    segment.move_by((5, -10))

    # Debug summary
    print(segment.info)
