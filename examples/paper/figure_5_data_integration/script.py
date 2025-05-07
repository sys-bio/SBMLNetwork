import sbmlnetwork


net = sbmlnetwork.load("./glycolysis_pathway_map.xml")

simulation_time = 1
net.settings.hide_reaction_labels()
net.get_species_list().set_font_sizes(12.0)
net.show_fluxes(simulation_time)
net.get_color_bar().set_left_margin(75)
net.get_reactions_list().set_curve_thicknesses(5)
net.get_reactions_list().set_border_thicknesses(50)
net.get_reactions_list().set_arrow_head_border_thicknesses(3)
net.get_reactions_list().hide(apply_to_connected_elements=False)
net.draw("./figure_5_data_integration.pdf")
net.save("./figure_5_data_integration.xml")