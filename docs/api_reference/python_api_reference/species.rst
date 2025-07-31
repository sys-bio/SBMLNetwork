Species
-------

The **Species** class represents individual biological entities within the SBMLNetwork model — for example, molecules, proteins, or genes. Each Species corresponds to a node in the network diagram and visually communicates its presence and role in the system.

After loading a model you can:

* Get just the **IDs** (strings) with :py:meth:`~sbmlnetwork.SBMLNetwork.get_species_ids`.
* Retrieve **one** species by ID with :py:meth:`~sbmlnetwork.SBMLNetwork.get_species`.
* Get the **full list** of species objects via :py:meth:`~sbmlnetwork.SBMLNetwork.get_species_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get Species ids
    species_ids = net.get_species_ids()

    # Single species
    species = net.get_species(species_ids[0])
    print(species.get_species_id())

    # All species
    for sp in net.get_species_list():
       print(sp.get_species_id())

In the visualization context, each Species includes its own `Shapes <./shape.html>`__ and `Labels <./label.html>`__, which define how the species is drawn and annotated within the network. The diagram below shows how a Species connects to its Shape and Label elements:


.. graphviz::
   :align: center

   digraph species_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Species [
       label=< <font color="#3366cc">Species</font> >,
       URL="species.html",
       tooltip="Click for more about Species"
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

     Species -> Shapes;
     Species -> Labels;
   }

Core Methods
************

Identification
==============

.. py:method:: get_id()

   Return the unique glyph identifier (the `SpeciesGlyph` element) as defined in the SBML Layout package.

   :rtype: str

.. py:method:: get_species_id()

   Return the SBML object identifier of the underlying species in the model.

   :rtype: str

.. py:method:: get_compartment_id()

   Return the SBML compartment identifier in which this species resides.

   :rtype: str

Model Connections
=================

.. py:method:: get_reaction_ids()

   Return a set of SBML reaction identifiers connected to this species.

   :rtype: Set[str]

.. py:method:: get_reactions_list()

   Return a list-like wrapper over all :py:class:`~sbmlnetwork.Reaction` objects connected to this species.

   :rtype: ReactionList

.. py:method:: get_reactions(id_list=None)

   Fetch one or many connected reactions.

   :param id_list: ``None`` for all reactions, a single ID, or an iterable of IDs
   :type  id_list: str | Iterable[str] | None
   :returns: A single :py:class:`~sbmlnetwork.Reaction` or a sub-list

Visual Connections
==================

.. py:method:: get_curves_list(reaction=None)

   Return all connecting curve glyphs (from substrate/product mapping) optionally scoped to a reaction.

   :param reaction: an optional :py:class:`~sbmlnetwork.Reaction` or SBML ID
   :type  reaction: Reaction | str | None
   :rtype: CurveList

.. py:method:: get_curves(reaction=None)

   Synonym for :py:meth:`get_curves_list`.

   :rtype: CurveList

.. py:method:: create_alias(reaction)

   Clone this species glyph for a given reaction, producing an alias glyph when species participate in multiple reactions.

   :param reaction: Reaction object or SBML reaction ID
   :returns: A new :py:class:`~sbmlnetwork.Species` alias or ``None``

Geometry & Positioning
======================

.. py:method:: get_position()

   Get the current (``x, y``) position of the glyph’s center on the canvas.

   :returns: ``(x, y)`` in canvas units

.. py:method:: set_position(position)

   Move the glyph to a new canvas position.

   :param tuple position: (x, y) coordinates

.. py:method:: get_size()

   Get the glyph’s width and height.

   :returns: ``(width, height)``

.. py:method:: set_size(size)

   Resize the glyph.

   :param tuple size: (width, height)

.. py:method:: move_to(position, move_connected_curves=True)

   Move glyph and optionally reposition connected curves.

.. py:method:: move_by(delta, move_connected_curves=True)

   Translate glyph by a delta vector.

Appearance
==========

.. py:method:: add_shape(shape_type, **options)

   Attach a geometric shape (rectangle, ellipse, etc.) as the glyph’s outline.

   :param str shape_type: one of the SBML geometric shape names

.. py:method:: set_shape(shape_type)

   Change the existing shape type.

.. py:method:: get_shape()

   Return the primary shape glyph.

.. py:method:: get_shapes_list()

   Return all shape glyphs.

.. py:method:: get_border_color()

   Get outline color.

.. py:method:: set_border_color(color)

   Set outline color.

.. py:method:: get_fill_color()

   Get interior fill color.

.. py:method:: set_fill_color(color)

   Set interior fill color.

Labels
======

.. py:method:: add_label(text, **options)

   Attach a text label relative to the glyph.

   :param str text: Label text

.. py:method:: get_labels_list()

   Return all attached label glyphs.

.. py:method:: get_text()

   Return the label text (single or list).

Geometry Utilities
=================

.. py:method:: set_font_size(font_size, adjust_size=False)

   Uniformly adjust font size of all labels.

   :param float font_size: New font size

Visibility
==========

.. py:method:: show()

   Make the glyph (and nested elements) visible.

.. py:method:: hide()

   Hide the glyph.

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

    net = sn.load("my_model.xml")
    species = net.get_species(net.get_species_ids()[0])

    # Inspect identifiers
    print(species.get_id(), species.get_species_id(), species.get_compartment_id())

    # List connected reactions
    for rid in species.get_reaction_ids():
       print(rid)

    # Move and style the glyph
    species.move_to((200, 150))
    species.set_fill_color("#ffeecc")
    species.set_border_color("#cc6633")

    # Add a custom text label
    species.add_label("ATP Molecule", relative_position=(10, 10))

    # Highlight its connecting curves which are of type product
    for curve in species.get_curves_list():
       if species.get_role(curve.get_reaction()) == "product":
           curve.set_border_color("#3366cc")

    # Finally, render the network diagram
    net.draw("species_demo.png")

