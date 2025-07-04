Reaction
--------

The **Reaction** class represents an interaction or transformation within the SBMLNetwork model — for example, a biochemical reaction or regulatory event. Each Reaction links Species together and shows how entities are converted, produced, or modified as part of the network’s dynamic behavior.

After loading a model you can:

* Get just the **IDs** (strings) with :py:meth:`~sbmlnetwork.SBMLNetwork.get_reaction_ids`.
* Retrieve **one** reaction by ID with :py:meth:`~sbmlnetwork.SBMLNetwork.get_reaction`.
* Get the **full list** of reaction objects via :py:meth:`~sbmlnetwork.SBMLNetwork.get_reactions_list`.

Example:

.. code-block:: python

    import sbmlnetwork as sn

    net = sn.load("my_model.xml")

    # Get reaction ids
    reaction_ids = net.get_reaction_ids()

    # Single reaction
    rxn = net.get_reaction(reaction_ids[0])
    print(rxn.get_reaction_id())

    # All reactions
    for r in net.get_reactions_list():
       print(r.get_reaction_id())

Visually, each Reaction includes its own `Reaction Center <./reaction_center.html>`__, `Labels <./label.html>`__, `Curves <./curve.html>`__, which define how the reaction is drawn, annotated, and connected to other components in the diagram.

The diagram below shows how a Reaction connects to its `Curves <./curve.html>`__, `Reaction Center <./reaction_center.html>`__, and `Labels <./label.html>`_ elements:


.. graphviz::
   :align: center

   digraph reaction_hierarchy {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Reaction [
       label=< <font color="#3366cc">Reaction</font> >,
       URL="reaction.html",
       tooltip="Click for more about Reaction"
     ];

     Curves [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Curves</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="curve.html",
       tooltip="Click for more about Curves"
     ];

     ReactionCenter [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Reaction Center</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="reaction_center.html",
       tooltip="Click for more about Reaction Center"
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

     Reaction -> Curves;
     Reaction -> ReactionCenter;
     Reaction -> Labels;
   }

Core Methods
************

Identification
==============

.. py:method:: get_id()

   Return the unique glyph identifier (the `ReactionGlyph` element) as defined in the SBML Layout package.

   :rtype: str

.. py:method:: get_reaction_id()

   Return the SBML object identifier of the underlying reaction in the model.

   :rtype: str

.. py:method:: get_compartment_id()

   Return the SBML compartment identifier in which this reaction glyph resides.

   :rtype: str

Participants
============

.. py:method:: get_species_ids()

   Return a list of SBML species identifiers connected to this reaction.

   :rtype: list[str]

.. py:method:: get_species_list()

   Return a list-like wrapper over the species glyphs connected to this reaction.

   :rtype: SpeciesList

.. py:method:: assign_species(species)

   Attach an existing species glyph to this reaction.

   :param species: species glyph to attach
   :type species: Species
   :returns: True if successfully attached


Geometry & Positioning
======================

.. py:method:: get_position()

   Get the (``x, y``) position of the reaction centre glyph on the canvas.

   :returns: ``(x, y)`` in canvas units

.. py:method:: move_to(position, move_connected_species=True)

   Translate the entire reaction (centre **and** all curves) so that the centre sits at *position*.

   :param tuple position: New ``(x, y)`` location
   :param bool move_connected_species: If ``True`` the connected species glyphs are also shifted to keep arrow lengths unchanged.

.. py:method:: move_by(delta, move_connected_species=True)

   Move the reaction by the specified ``(dx, dy)`` offset.

Centre representation
=====================

.. py:method:: get_center()

   Return the :pyclass:`ReactionCenter` wrapper that represents the centre glyph (curve **or** shape list).

   :rtype: ReactionCenter

.. py:method:: is_center_curve()

   Return ``True`` if the centre is currently represented by a Curve object.

.. py:method:: is_center_shapes()

   Return ``True`` if the centre is represented by one or more Shape glyphs.

.. py:method:: switch_center_to_curve()

   Convert the centre representation to a single curve.

.. py:method:: switch_center_to_shapes()

   Convert the centre representation to one or more explicit shapes (defaults to a circle).

Curves & Arrow‑heads
====================

.. py:method:: get_curves_list()

   Return a list-like wrapper over the curves connected to this reaction.

   :rtype: CurveList

.. py:method:: set_curve_colors(color)

   Uniformly set the border colour of all curves.

   :param str color: Hex string (``"#RRGGBB"``) or CSS colour name

.. py:method:: set_arrow_head_shapes(shape_type)

   Change the arrow‑head geometry for all curves (e.g. ``"triangle"``, ``"bar"``).

.. py:method:: set_arrow_head_fill_colors(color)

   Set the fill colour of the arrow‑head shapes.

Styling
=======

The methods below operate on the *centre* shapes if present; when the centre is a curve they have no effect.

.. py:method:: set_fill_color(color)

   Fill the centre shapes with *color*.

.. py:method:: set_border_color(color)

   Set the stroke colour of the centre shapes.

.. py:method:: set_border_thickness(thickness)

   Set the border width (in canvas units) of the centre shapes.

Layout helpers
==============

.. py:method:: align_horizontal(center_at: tuple[float, float] = None,
                                 spread: float = None,
                                 reactants_order: list = None,
                                 products_order: list = None,
                                 modifiers_order: list = None,
                                 reactants_placement: str = "both",
                                 products_placement: str = "both",
                                 modifiers_placement: str = "both")

   Arrange substrates, products, and modifiers in a horizontal layout around the reaction centre.

   By default, substrates appear on the left, products on the right, and modifiers above and/or below the centre depending on placement settings.

   :param center_at: Optional new centre position `(x, y)` to anchor the layout. If omitted, the current centre position is used.
   :type center_at: tuple[float, float]

   :param spread: Total horizontal distance between the outermost reactants and products.
   :type spread: float

   :param reactants_order: Custom ordering of reactant species IDs for left-to-right placement.
   :type reactants_order: list[str]

   :param products_order: Custom ordering of product species IDs for left-to-right placement.
   :type products_order: list[str]

   :param modifiers_order: Custom ordering of modifier species IDs.
   :type modifiers_order: list[str]

   :param reactants_placement: Placement of reactants: "top", "bottom", or "both".
   :type reactants_placement: str

   :param products_placement: Placement of products: "top", "bottom", or "both".
   :type products_placement: str

   :param modifiers_placement: Placement of modifiers: "top", "bottom", or "both".
   :type modifiers_placement: str

   :returns: True if the alignment was applied successfully.

.. py:method:: align_vertical(center_at: tuple[float, float] = None,
                               spread: float = None,
                               reactants_order: list = None,
                               products_order: list = None,
                               modifiers_order: list = None,
                               reactants_placement: str = "both",
                               products_placement: str = "both",
                               modifiers_placement: str = "both")

   Stack substrates, products, and modifiers in a vertical layout around the reaction centre.

   By default, substrates are positioned above, products below, and modifiers to the sides according to placement settings.

   :param center_at: Optional new centre position `(x, y)` to anchor the layout. If omitted, the current centre position is used.
   :type center_at: tuple[float, float]

   :param spread: Total vertical distance between the outermost reactants and products.
   :type spread: float

   :param reactants_order: Custom ordering of reactant species IDs for top-to-bottom placement.
   :type reactants_order: list[str]

   :param products_order: Custom ordering of product species IDs for top-to-bottom placement.
   :type products_order: list[str]

   :param modifiers_order: Custom ordering of modifier species IDs.
   :type modifiers_order: list[str]

   :param reactants_placement: Placement of reactants: "left", "right", or "both".
   :type reactants_placement: str

   :param products_placement: Placement of products: "left", "right", or "both".
   :type products_placement: str

   :param modifiers_placement: Placement of modifiers: "left", "right", or "both".
   :type modifiers_placement: str

   :returns: True if the alignment was applied successfully.

.. py:method:: align_circle(center_at: tuple[float, float] = None,
                            radius: float = None,
                            arc_start: float = -180,
                            arc_end: float = -90,
                            clockwise: bool = True,
                            reactants_order: list = None,
                            products_order: list = None,
                            modifiers_order: list = None,
                            reactants_placement: str = "both",
                            products_placement: str = "both",
                            modifiers_placement: str = "both")

   Distribute substrates, products, and modifiers evenly along a circular arc around the reaction centre.

   :param center_at: Optional centre position `(x, y)` of the circle. Defaults to the current centre.
   :type center_at: tuple[float, float]

   :param radius: Radius of the circle along which species are placed. If omitted, calculated from current layout bounds.
   :type radius: float

   :param arc_start: Starting angle of the arc (degrees).
   :type arc_start: float

   :param arc_end: Ending angle of the arc (degrees).
   :type arc_end: float

   :param clockwise: Direction to traverse the arc: `True` for clockwise, `False` for counter-clockwise.
   :type clockwise: bool

   :param reactants_order: Order of reactant species along the arc.
   :type reactants_order: list[str]

   :param products_order: Order of product species along the arc.
   :type products_order: list[str]

   :param modifiers_order: Order of modifier species along the arc.
   :type modifiers_order: list[str]

   :param reactants_placement: Placement of reactants off the arc: "inside", "outside", or "both".
   :type reactants_placement: str

   :param products_placement: Placement of products off the arc: "inside", "outside", or "both".
   :type products_placement: str

   :param modifiers_placement: Placement of modifiers off the arc: "inside", "outside", or "both".
   :type modifiers_placement: str

   :returns: True if the alignment was applied successfully.

Reversibility
=============

.. py:method:: show_reversibility(are_subsrate_directions_reversed=False)

   Display a second arrow‑head to indicate a reversible reaction.

.. py:method:: hide_reversibility()

   Remove the reversibility arrow‑head.

Visibility
==========

.. py:method:: show()

   Make the reaction glyphs visible.

.. py:method:: hide()

   Hide the reaction from the rendered diagram.

Example workflow
****************

The script below demonstrates how to fetch a reaction, switch its centre to an explicit shape, recolour it, rearrange its participants, and save the resulting diagram:

.. code-block:: python

    import sbmlnetwork as sn

    # Load a simple metabolic model
    net = sn.load("my_model.xml")

    # Fetch the first reaction
    rxn = net.get_reactions_list()[0]

    # Inspect participants
    print("Participants:", rxn.get_species_ids())

    # Represent the centre as a filled orange circle
    if rxn.is_center_curve():
       rxn.switch_center_to_shapes()

    rxn.set_fill_color("#ffd699")      # pastel orange
    rxn.set_border_color("#cc7a00")
    rxn.set_border_thickness(2.0)

    # Colour substrate vs product curves differently
    substrate_colour = "#3366cc"   # blue
    product_colour   = "#2ca02c"   # green

    for curve in rxn.get_curves_list():
       species = curve.get_species()
       role = curve.get_role()
       curve.set_color(product_colour if role == "product" else substrate_colour)

    # Arrange substrates on the left, products on the right, and place modifiers above
    rxn.align_horizontal(
        center_at=(200.0, 150.0),
        spread=120.0,
        reactants_order=["GLC", "ATP"],
        products_order=["G6P", "ADP"],
        modifiers_order=["Inhibitor"],
        reactants_placement="both",
        products_placement="both",
        modifiers_placement="top"
    )

    # Save to file
    net.draw("reaction_demo.png")
