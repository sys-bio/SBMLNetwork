Network
-------

The **Network** class is the central entry-point of the SBMLNetwork API.
The fastest way to obtain a ``Network`` instance is the :py:meth:`~sbmlnetwork.load`
convenience constructor:

.. code-block:: python

   import sbmlnetwork as sn

   net = sn.load("my_model.xml")

   # Network Extents
   print(net.get_size())

A ``Network`` object holds every visual element derived from an SBML model—
`Compartments <./compartment.html>`__, `Species <./species.html>`__, and `Reactions <./reaction.html>`__ —so its structure mirrors the
hierarchy of the underlying file.  The diagram below shows how these core
components are organized and how they relate to each other in the visualized
network.

.. graphviz::
   :align: center

   digraph sbml_network {
     rankdir=TB;
     node [shape=record, style=rounded, fontname=Helvetica];

     Network [
       label=< <font color="#3366cc">Network</font> >,
       URL="http://network-info.com",
       tooltip="Click for more network details"
     ];

     Compartments [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Compartments</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="http://compartments-info.com",
       tooltip="Click for more compartment details"
     ];

     Species [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Species</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="http://species-info.com",
       tooltip="Click for more species details"
     ];

     Reactions [
       label=<
         <table border="0" cellborder="0" cellpadding="5">
           <tr><td><font color="#3366cc">Reactions</font></td></tr>
         </table>
       >,
       shape=record,
       style=rounded,
       URL="http://reactions-info.com",
       tooltip="Click for more reaction details"
     ];

     Network -> Compartments;
     Network -> Species;
     Network -> Reactions;
   }

Core Methods
************

Loading and Saving
==================

.. py:method:: load(sbml)

   Load an SBML model into the network. Accepts file paths, XML strings, or Antimony strings.

   :param str sbml: SBML file path, XML content, or Antimony model string
   :returns: The Network instance (for method chaining)
   :rtype: Network

.. py:method:: save(file_name=None, update_network_extents=False)

   Save the network to an SBML file.

   :param str file_name: Output file path (optional)
   :param bool update_network_extents: Whether to recalculate canvas size before saving
   :returns: Success status
   :rtype: bool

.. py:method:: draw(file_name=None, update_network_extents=False)

   Render and display (or save) the network visualization.

   :param str file_name: Save figure to this file (optional)
   :param bool update_network_extents: Whether to recalculate canvas size before drawing

Example
~~~~~~~

.. code-block:: python

   import sbmlnetwork as sn

   # Load a model from file
   net = sn.SBMLNetwork().load("my_model.xml")

   # Save to a new file, updating extents
   net.save("output.xml", update_network_extents=True)

   # Render and save visualization
   net.draw("network.png", update_network_extents=True)

Canvas and Background
=====================

.. py:method:: get_size()

   Return the current canvas dimensions as a tuple (width, height).

   :rtype: tuple[int, int]

.. py:method:: set_size(width, height)

   Set the canvas dimensions to the specified width and height.

   :param int width: Canvas width in pixels
   :param int height: Canvas height in pixels

.. py:method:: get_background_color()

   Return the current background color of the network canvas.

   :rtype: str

.. py:method:: set_background_color(color)

   Set the background color of the network canvas.

   :param str color: Color string (e.g., "#f0f0f0")

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Initialize and draw default canvas
    net = sn.load("my_model.xml")

    # Inspect and modify canvas size
    width, height = net.get_size()
    print(f"Default size: {width}x{height}")
    net.set_size((800, 600))

    # Inspect and modify background
    current_bg = net.get_background_color()
    print(f"Default background: {current_bg}")
    net.set_background_color("#f0f0f0")
    net.draw()

Accessing Network Elements
==========================

.. py:method:: get_compartments_list()

   Return a list-like wrapper over all compartments in the network.

   :rtype: CompartmentList

.. py:method:: get_compartment(id)

   Fetch a single compartment by its SBML identifier.

   :param str id: The SBML id of the compartment
   :returns: The matching Compartment object

.. py:method:: get_species_list()

   Return a list-like wrapper over all species in the network.

   :rtype: SpeciesList

.. py:method:: get_species(id)

   Fetch a single species by its SBML identifier.

   :param str id: The SBML id of the species
   :returns: The matching Species object

.. py:method:: get_reactions_list()

   Return a list-like wrapper over all reactions in the network.

   :rtype: ReactionList

.. py:method:: get_reaction(id)

   Fetch a single reaction by its SBML identifier.

   :param str id: The SBML id of the reaction
   :returns: The matching Reaction object

.. py:method:: add_additional_element(element_id, element_type="rectangle", position=(0, 0), size=(100, 100))

   Add a custom graphical element to the network canvas.

   :param str element_id: Unique identifier for the element
   :param str element_type: Shape type (e.g., "rectangle", "ellipse")
   :param tuple position: (x, y) coordinates
   :param tuple size: (width, height) dimensions
   :returns: The created AdditionalElement object

.. py:method:: remove_additional_element(element)

   Remove a custom graphical element from the network.

   :param element: Element ID or AdditionalElement instance to remove

.. py:method:: add_independent_label(text, x, y, width, height)

   Add a free-floating text label to the network canvas.

   :param str text: Label text content
   :param float x: X coordinate
   :param float y: Y coordinate
   :param float width: Label width
   :param float height: Label height
   :returns: The created Label object

.. py:method:: remove_independent_label(label)

   Remove an independent text label from the canvas.

   :param str label: Label ID or text content to remove

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Load network
    net = sn.load("my_model.xml")

    # List all compartments
    for comp in net.get_compartments_list():
       print(comp.id)

    # Fetch and inspect one species
    species = net.get_species_list()[0]
    print(species.id)

    # List and fetch reactions
    for rxn in net.get_reactions_list():
       print(rxn.id)

    r1 = net.get_reactions_list()[0]
    print({r1.id})

    # Add a custom element and label
    elem = net.add_additional_element("box1", "rectangle", position=(50,50), size=(100,30))
    label = net.add_independent_label("Custom Box", 50, 50, 100, 30)


Layout and Positioning
======================

.. py:method:: auto_layout(max_num_connected_edges=3, reset_fixed_position_elements=False, fixed_position_nodes=None, iterations=-1)

   Arrange network elements automatically using a force-directed algorithm.

   :param int max_num_connected_edges: Maximum edges per node for layout decisions
   :param bool reset_fixed_position_elements: If True, clear existing fixed positions before layout
   :param list fixed_position_nodes: List of element IDs to keep fixed (default: None)
   :param int iterations: Number of layout iterations (-1 for automatic convergence)

.. py:method:: auto_style(max_num_connected_edges=3)

   Apply automatic styling heuristics based on network connectivity.

   :param int max_num_connected_edges: Maximum edges per node for styling logic

.. py:method:: update_network_extents()

   Recalculate and update the canvas size to fit all elements after layout or styling changes.

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Load and prepare network
    net = sn.load("my_model.xml")

    # Perform auto-layout with default settings
    net.auto_layout()

    # Optionally fix a key node in place
    net.auto_layout(fixed_position_nodes=[net.get_species_ids()[0]], reset_fixed_position_elements=True)

    # Apply auto-styling to adjust line widths and colors
    net.auto_style()

    # Ensure the canvas encompasses all nodes
    net.update_network_extents()

    # Render the final layout
    net.draw("laid_out_network.png")

Styling
=======

.. py:method:: get_style()

   Return the active visual-style theme.

.. py:method:: set_style(style_name)

   Apply a predefined style.

.. py:method:: get_styles_options()

   List all available style names.

.. py:method:: get_font_color()

   Return the current text color for all network labels.

.. py:method:: set_font_color(color)

   Set the text color for all network labels.

.. py:method:: get_font_size()

   Return the current font size for all network text.

.. py:method:: set_font_size(size)

   Set the font size for all network text.

.. py:method:: get_font_family()

   Return the font family currently in use.

.. py:method:: set_font_family(family)

   Set the font family for all network text.

.. py:method:: is_text_bold()

   Check whether all network text is rendered in bold.

.. py:method:: set_text_bold(flag=True)

   Enable or disable bold formatting for all network text.

.. py:method:: is_text_italic()

   Check whether all network text is rendered in italic.

.. py:method:: set_text_italic(flag=True)

   Enable or disable italic formatting for all network text.

.. py:method:: get_border_color()

   Return the border color used for network elements.

.. py:method:: set_border_color(color)

   Set the border color for all network elements.

.. py:method:: get_border_thickness()

   Return the current border thickness for network elements.

.. py:method:: set_border_thickness(thickness)

   Set the border thickness for all network elements.

.. py:method:: get_fill_color()

   Return the fill color used for network elements.

.. py:method:: set_fill_color(color)

   Set the fill color for all network elements.

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Load and prepare network
    net = sn.load("my_model.xml")

    # Theme and style
    available = net.get_styles_options()
    print("Styles:", available)
    net.set_style("escher")

    # Typography adjustments
    net.set_font("Helvetica")
    net.set_font_size(14)
    net.set_font_color("#333333")
    net.set_text_bold(True)
    net.set_text_italic(False)

    # Element appearance
    net.set_border_color("#666666")
    net.set_border_thickness(5)
    net.set_fill_color("#ffffff")

    # Render updated network
    net.draw("styled_network.png")

.. _data-visualization:

Data Visualization
==================


.. py:method:: show_fluxes(data, log_scale=False, min_threshold=None, skip_hidden_elements=True)

   Color reactions by numeric flux values.

   :param data: Either:

                1. A single float representing a **simulation time** (in time units of your model).
                   In this mode, SBMLNetwork will invoke the simulation engine (i.e., Tellurium) to compute reaction fluxes at that time point and then color reactions accordingly.
                   **Example:**

                   .. code-block:: python

                      # Simulate the model for 5.0 time units, then color by flux
                      net.show_fluxes(5.0)

                2. A dict mapping individual reaction IDs to their flux values (floats).
                   - **Keys**: SBML Reaction Ids.
                   - **Values**: Flux magnitudes (floats).
                     - Positive → forward flux
                     - Negative → reverse flux

                   **Example:**

                   .. code-block:: python

                      flux_map = {
                          'HEX1': 0.85,     # forward 0.85 units
                          'PGI_rev': -0.30  # reverse 0.30 units
                      }
                      net.show_fluxes(flux_map, log_scale=True, min_threshold=0.05)
   :type data: float | dict[str, float]
   :param bool log_scale:
      If ``True``, apply a logarithmic color scale to flux magnitudes (default: ``False``).
   :param float min_threshold:
      Minimum absolute flux value to display. Reactions with |flux| below this threshold are omitted (default: ``None``).
   :param bool skip_hidden_elements:
      If ``True``, skip reactions marked as hidden in the current layout (default: ``True``).
   :raises KeyError:
      If a dict-mode key does not match any reaction ID in the model.
   :returns: ``None``

.. py:method:: hide_fluxes()

   Remove any flux-based coloring from reactions.

.. py:method:: show_concentrations(data, log_scale=False, min_threshold=None, show_by="color", skip_hidden_elements=True, min_size=10, max_size=100)

   Visualize species concentrations by coloring or resizing glyphs.

   :param data: Either:

                1. A single float representing a **simulation time** (in your model’s time units).
                   SBMLNetwork will invoke the simulation engine (i.e., Tellurium) to compute species concentrations at that time point, then visualize accordingly.

                   **Example:**

                   .. code-block:: python

                      # Simulate for 10.0 time units, then color by concentration
                      net.show_concentrations(10.0, show_by="color")

                2. A dict mapping individual species IDs to their concentration values (floats).
                   - **Keys**: SBML Species Ids.
                   - **Values**: Concentration magnitudes (floats).

                   **Example:**

                   .. code-block:: python

                      conc_map = {
                          'A': 5.2,    # concentration 5.2 units for species “A”
                          'B': 0.75    # concentration 0.75 units for species “B”
                      }
                      net.show_concentrations(
                          conc_map,
                          log_scale=True,
                          min_threshold=0.1,
                          show_by="size",
                          min_size=5,
                          max_size=50
                      )
   :type data: float | dict[str, float]
   :param bool log_scale:
      If ``True``, apply a logarithmic scale to concentration values (default: ``False``).
   :param float min_threshold:
      Minimum concentration to display. Species with values below this threshold are omitted (default: ``None``).
   :param str show_by:
      Choose how to visualize values:
      - ``"color"`` – color glyphs by concentration (default)
      - ``"size"``  – resize glyphs between ``min_size`` and ``max_size`` based on concentration
   :param bool skip_hidden_elements:
      If ``True``, skip any species marked as hidden in the current layout (default: ``True``).
   :param float min_size:
      Minimum glyph size when ``show_by="size"`` (default: ``10``).
   :param float max_size:
      Maximum glyph size when ``show_by="size"`` (default: ``100``).
   :raises KeyError:
      If a dict-mode key does not match any species ID in the model.
   :returns: ``None``

.. py:method:: hide_concentrations()

   Remove any concentration-based coloring or sizing from species.

Example
=======

.. code-block:: python

    import sbmlnetwork as sn

    # Load network
    net = sn.load("my_model.xml")

    reaction_ids = net.get_reaction_ids()

    flux_data = {}
    initial_flux = 1.0
    for reaction_id in reaction_ids:
        flux_data[reaction_id] = initial_flux
        initial_flux += 0.5

    # Visualize fluxes on reactions
    net.show_fluxes(flux_data, log_scale=True, min_threshold=0.5)
    net.draw("flux_network.png")

    # Remove flux visualization
    net.hide_fluxes()

    species_ids = net.get_species_ids()

    conc_data = {}
    initial_conc = 1.0
    for species_id in species_ids:
        conc_data[species_id] = initial_conc
        initial_conc += 0.2

    # Visualize concentrations on species by color
    net.show_concentrations(conc_data, show_by="color")
    net.draw("concentration_network_color.png")

    # Remove concentration visualization
    net.hide_concentrations()

    # Visualize concentrations on species by size
    net.show_concentrations(conc_data, show_by="size", min_size=20, max_size=80)
    net.draw("concentration_network_size.png")

    # Clear concentration visualization
    net.hide_concentrations()

Grouping
========

.. py:method:: group_reactions(reactions, color=None)

   Visually group related reactions into a single composite object.

   :param reactions: List of reaction IDs or Reaction objects
   :type  reactions: list[str | Reaction]
   :param str color: Optional fill color for the group
   :returns: A ReactionGroup instance

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Load network
    net = sn.load("my_model.xml")

    # Define a group of reactions
    reaction_ids = net.get_reaction_ids()[:-1]

    # Group the reactions with a specific color
    group = net.group_reactions(reaction_ids, color="lightgreen")

    # Draw the network with grouped reactions highlighted
    net.update_network_extents()
    net.draw("grouped_network.png")

Visibility Controls
===================

.. py:method:: show()

   Make all network elements visible on the canvas.

   :returns: None

.. py:method:: hide()

   Hide all network elements from view.

   :returns: None

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Load network
    net = sn.load("my_model.xml")

    # Hide every element before rendering
    net.hide()
    net.draw("hidden_network.png")

    # Reveal all elements and render again
    net.show()
    net.draw("full_network.png")

Library Information
===================

.. py:method:: get_version()

   Return the version string of the underlying SBMLNetwork library.

   :rtype: str

Example
~~~~~~~

.. code-block:: python

    import sbmlnetwork as sn

    # Load network (or simply instantiate)
    net = sn.load("my_model.xml")

    # Print library version
    print(f"SBMLNetwork version: {net.get_version()}")