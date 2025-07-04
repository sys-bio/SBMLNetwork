Reaction Center
---------------

The **Reaction Center** represents the visual anchor point of a Reaction in the network diagram.
It serves as the central location where `Curves <./curve.html>`__ connect reactants, products, and modifiers.

A Reaction Center can be represented in **two ways**:

* As a `Curve <./curve.html>`__ — for simple or implicit visual styles where the connection itself acts as the anchor.
* As a list of `Shapes <./shape.html>`__ — for explicit, node-like visual centers that mirror how Species or Compartments are drawn.

After loading a model and retrieving a Reaction, you can:

* Get the **Reaction Center** with
  :py:meth:`~Reaction.get_center`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get reaction id
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

Core Methods
************

Representation
==============

.. py:method:: is_curve()

   Return whether this Reaction Center is represented as a **Curve** (i.e., no shapes present).

   :rtype: bool

.. py:method:: is_shapes()

   Return whether this Reaction Center is represented as a **list of Shapes**.

   :rtype: bool


Switching Representations
==========================

.. py:method:: switch_to_curve()

   Convert this center to its **Curve** representation by removing all existing shapes.

   :returns: `True` on success, `False` if any shape could not be removed.

.. py:method:: switch_to_shapes()

   Convert this center to its **Shapes** representation. If no shapes exist, adds a default rectangle.

   :returns: `True` on success, `False` if the default shape could not be added.


Accessing Representations
=========================

.. py:method:: get_curve()

   If the center is a curve, return the associated :py:class:`~sbmlnetwork.Curve`; otherwise, return `None`.

   :rtype: Curve or None

.. py:attribute:: curve

   Alias for :py:meth:`get_curve`.

.. py:method:: get_shapes_list()

   Return a :py:class:`~sbmlnetwork.ShapeList` of all shapes representing the center.

   :rtype: ShapeList

.. py:attribute:: shapes

   Alias for :py:meth:`get_shapes_list`.


Mapping to Reaction
===================

.. py:method:: get_reaction()

   Return the parent :py:class:`~sbmlnetwork.Reaction` object this center belongs to.

   :rtype: Reaction

.. py:attribute:: reaction

   Alias for :py:meth:`get_reaction`.

Movement
========

.. py:method:: move(delta)

   Translate the center by the given *(dx, dy)* offset.

   - If it’s a curve, all segments are shifted by the offset.
   - If it’s shapes, returns `True` (shapes maintain relative layout).

   :param delta: Offset vector.
   :type delta: tuple[float, float]
   :returns: `True` on success, `False` on failure.


Information
===========

.. py:method:: get_info()

   Return a human-readable summary of each reaction center’s state (for debugging).

   :rtype: str

.. py:attribute:: info

   Alias for :py:meth:`get_info`.


Example Workflow
****************

.. code-block:: python

   import sbmlnetwork as sn

    # Load the SBML model
    net = sn.load("my_model.xml")

    # Fetch the Reaction Center for reaction "R1"
    center = net.get_reactions_list()[0].get_center()

    # Switch to Shapes representation if currently a curve
    if center.is_curve():
       center.switch_to_shapes()

    # Move the center downward by 40 diagram units
    center.move((0.0, -40.0))

    # Examine the shapes of the center
    for shape in center.get_shapes_list():
       print(shape.get_type(), "border color:", shape.get_border_color())


