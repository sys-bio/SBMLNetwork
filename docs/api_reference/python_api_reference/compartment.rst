Compartment
-----------

The **Compartment** class represents a spatial or logical container within the SBMLNetwork model. It groups related biological species and reactions within a defined boundary—just as compartments do in SBML itself.

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

In the visualization context, each Compartment includes its own `Shapes <./shape.html>`__ and `Labels <./label.html>`__, which define how the compartment is drawn and annotated in the rendered network diagram. The diagram below shows how a Compartment connects to its Shape and Label elements:

.. graphviz::
   :align: center

   digraph compartment_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Compartment [
       label=< <font color="#3366cc">Compartment</font> >,
       URL="compartment.html",
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
       URL="shape.html",
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
       URL="label.html",
       tooltip="Click for more about Labels"
     ];

     Compartment -> Shapes;
     Compartment -> Labels;
   }

Core Methods
************

Identification
==============

.. py:method:: get_id()

   Return the unique identifier of the drawing glyph for this compartment (the `CompartmentGlyph` element), as defined in the SBML Layout package.

   :rtype: str

.. py:method:: get_compartment_id()

   Return the SBML object identifier of the underlying compartment in the model.

   :rtype: str

Contents
========

.. py:method:: get_species_list()

   Return a list‑like wrapper over all species that reside in this compartment.

   :rtype: SpeciesList

.. py:method:: get_species(id)

   Fetch a single species (of type :py:class:`~sbmlnetwork.Species`) by its SBML identifier.

   :param str id: The SBML id of the desired species
   :returns: The matching Species object

.. py:method:: get_reactions_list()

   Return a list‑like wrapper over all reactions whose *products* or *reactants* appear in this compartment.

   :rtype: ReactionList

.. py:method:: get_reactions(id_list=None)

   Fetch one or many reactions scoped to the compartment.

   :param id_list: ``None`` for all reactions, a single id, or an iterable of ids
   :type  id_list: str | Iterable[str] | None
   :returns: A single Reaction object or a sub‑list depending on *id_list*

Geometry & Positioning
======================

.. py:method:: get_position()

   Get the current (``x, y``) position—upper‑left corner by convention—of the compartment on the canvas.

   :returns: ``(x, y)`` tuple in *canvas units* (typically pixels)

.. py:method:: set_position(x, y)

   Move the compartment to a new position on the canvas.

   :param float x: X‑coordinate of the upper‑left corner
   :param float y: Y‑coordinate of the upper‑left corner

.. py:method:: get_size()

   Get the current width and height of the compartment in canvas units.

   :returns: ``(width, height)``

.. py:method:: set_size(width, height)

   Resize the compartment.

   :param float width: New width
   :param float height: New height

Appearance
==========

.. py:method:: add_shape(shape_type='rectangle', **options)

   Add a new geometric shape that defines the compartment boundary.

   :param str shape_type: ``'rectangle'``, ``'ellipse'``, etc.
   :param options: Shape‑specific keyword arguments (border thickness, corner radius, …)

.. py:method:: get_shape()

   Return the primary :py:class:`~sbmlnetwork.Shape` object that outlines the compartment.

.. py:method:: set_shape(shape)

   Replace the existing shape with *shape*.

.. py:method:: get_border_color()

   Get the current border color (hex string ``'#rrggbb'``).

.. py:method:: set_border_color(color)

   Set the border color.

   :param str color: Hex or named color string

.. py:method:: get_fill_color()

   Get the interior fill color.

.. py:method:: set_fill_color(color)

   Change the fill color.

Labels
======

.. py:method:: add_label(text, **options)

   Attach a textual label to the compartment.

   :param str text: Label text
   :param options: Keyword arguments forwarded to the underlying :py:class:`~sbmlnetwork.Label` constructor

.. py:method:: get_labels_list()

   Return a list of all labels attached to the compartment.

   :rtype: LabelList


Visibility
==========

.. py:method:: show()

   Make the compartment (and all nested shapes & labels) visible on the canvas.

.. py:method:: hide()

   Hide the compartment without deleting it from the model.

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

    # Load the network from an SBML file
    net = sn.load('my_model.xml')

    # Get the default compartment
    compartment = net.get_compartment()

    # Move and resize
    compartment.set_position((50, 80))
    compartment.set_size((800, 600))

    # Change shape to ellipse
    compartment.set_shape('ellipse')

    # Style tweaks
    compartment.set_border_color('#3366cc')
    compartment.set_fill_color('#f0f4ff')

    # Add a label
    compartment.add_label('Cytosol', (0, -20))

    # Inspect species
    for s in compartment.get_species_list():
       print(s.get_id(), s.get_position())

    # Finally, draw the full network
    net.draw('my_network.png')

