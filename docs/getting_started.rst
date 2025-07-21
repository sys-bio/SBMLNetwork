.. _getting-started:

====================
Getting Started
====================

SBMLNetwork provides a concise, high‑level Python interface for loading,
styling, analyzing, and exporting SBML models with full *Layout* and *Render*
support.

Installation
============
For complete installation options, see :ref:`installation`.

Example use‑cases
=================
Basic visualization
-------------------

Load a model, let *SBMLNetwork* auto‑layout/style it if necessary, then render
and save both the figure and the updated SBML.

.. code-block:: python
   :name: example-basic-visualisation

   import sbmlnetwork as sb

   # Load SBML; auto‑layout and auto‑style will run if the file lacks them
   net = sb.load("my_model.xml")

   # Render the network and save a PNG
   net.draw("network.png")

   # Save SBML back to disk with Layout/Render information embedded
   net.save("network.xml")

Styling and theming
-------------------

Apply a built‑in theme before drawing to instantly switch color palette and typography.

.. code-block:: python
   :name: example-styling

   import sbmlnetwork as sb

   # Load the model
   net = sb.load("my_model.xml")

   # Apply one of the built‑in themes (e.g. “escher”)
   net.set_style("escher")

   # Render with the new look
   net.draw("styled_network.png")


Mapping reaction fluxes
-----------------------

Colour‑code reactions by experimental or simulated flux values to highlight
bottlenecks or high‑throughput steps.

.. code-block:: python
   :name: example-fluxes

   import sbmlnetwork as sb

   # Define an Antimony model
   antimony_str = """
       J0: S1 -> S2 ; k1*S1
       J1: S2 -> S3 ; k2*S2
       k1 = 1;  k2 = 0.5;
       S1 = 10; S2 = 0; S3 = 0;
   """

   # Load the model from the Antimony string
   net = sb.load(antimony_str)

   # Flux values for each reaction
   fluxes = {
       "J0": 12.3,
       "J1": 6.8,
   }

   # Map flux magnitude to reaction colours (log‑scaled) and add a colour bar
   net.show_fluxes(fluxes, log_scale=True)

   # Render the flux‑mapped network
   net.draw("flux_map.png")

Mapping species concentrations
------------------------------

Encode absolute or log‑scaled species abundances as node colour or size to
visualise high‑ and low‑concentration pools at a glance.

.. code-block:: python
   :name: example-concentrations

   import sbmlnetwork as sb

   # Define an Antimony model
   antimony_str = """
       J0: S1 -> S2 ; k1*S1
       J1: S2 -> S3 ; k2*S2
       k1 = 1;  k2 = 0.5;
       S1 = 10; S2 = 0; S3 = 0;
   """

   # Load the model from the Antimony string
   net = sb.load(antimony_str)

   # Measured or simulated concentrations
   conc = {
       "S1": 2.5,
       "S2": 0.8,
       "S3": 5.1,
   }

   # Map concentrations to node size (log‑scaled)
   net.show_concentrations(conc,
                           show_by="size",
                           log_scale=True,
                           min_size=20,
                           max_size=80)

   # Render the concentration‑mapped network
   net.draw("concentration_map.png")

Grouping reactions
------------------

Highlight a pathway or functional module by assigning its reactions to a shared
group and giving them a distinct colour.

.. code-block:: python
   :name: example-grouping

   import sbmlnetwork as sb

   # Antimony model with three reactions
   antimony_str = """
       J0: S1 -> S2 ; k1*S1
       J1: S2 -> S3 ; k2*S2
       J2: S2 -> S4 ; k3*S2
       k1 = 1; k2 = 0.5; k3 = 0.2;
       S1 = 10; S2 = 0; S3 = 0; S4 = 0;
   """

   # Load the model
   net = sb.load(antimony_str)

   # Group two reactions (J0 and J1) and colour them red
   net.group_reactions(["J0", "J1"], color="red")

   # Render the grouped network
   net.draw("grouped_pathway.png")

Next steps
==========
* Explore the full **Python API reference** reference in :doc:`Python API reference <api_reference/python_api_index>`.
* See the :doc:`Gallery <gallery>` for real‑world, fully‑annotated examples.
