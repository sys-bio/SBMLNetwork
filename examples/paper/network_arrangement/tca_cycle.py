import sbmlnetwork
import tellurium as te


model = '''
J1: Pyr + NAD + CoA -> AcCoA + NADH + CO2;
J2: AcCoA + Oxalo + H2O -> Cit + CoA;
J3: Cit -> IsoCit;
J4: IsoCit + NAD -> aKG + CO2 + NADH;
J5: aKG + CoA + NAD -> SCoA + CO2 + NADH;
J6: SCoA + GDP + Pi -> Succ + CoA + GTP;
J7: Succ + FAD -> Fum + FADH2;
J8: Fum + H2O -> Mal;
J9: Mal + NAD -> Oxalo + NADH;

'''

r = te.loada(model)
net = sbmlnetwork.load(r.getSBML())

compartment = net.get_compartment()
compartment.set_fill_color("white")     # Warm medium brown background
compartment.set_border_color("white")    # Slightly deeper brown for the border
compartment.set_font_color("#8BC34A")      # Soft cream for text
compartment.set_border_thickness(30)
compartment.set_font_size(200)
compartment.move_text_by((0, 900))
compartment.get_label().set_size((compartment.get_label().get_size()[0], compartment.get_label().get_size()[1] - 900))
compartment.get_label().align_to_vertical_center()
compartment.set_text("TCA Cycle")
compartment.set_font("Helvetica")
compartment.set_text_bold(True)
compartment.get_shape().set_corner_radius((100, 100))
compartment.move_text_by((0, -100))
compartment.set_size((4400, 4900))

reaction = net.get_reaction("J2")
net.get_species("CoA").create_alias(reaction)
reaction = net.get_reaction("J4")
net.get_species("NAD").create_alias(reaction)
net.get_species("NADH").create_alias(reaction)
net.get_species("CO2").create_alias(reaction)
reaction = net.get_reaction(("J5"))
net.get_species("CoA").create_alias(reaction)
net.get_species("NAD").create_alias(reaction)
net.get_species("NADH").create_alias(reaction)
net.get_species("CO2").create_alias(reaction)
reaction = net.get_reaction("J6")
net.get_species("CoA").create_alias(reaction)
reaction = net.get_reaction("J8")
net.get_species("H2O").create_alias(reaction)
reaction = net.get_reaction("J9")
net.get_species("NAD").create_alias(reaction)
net.get_species("NADH").create_alias(reaction)

species = net.get_species_list()
main_cycle_species = net.get_species_list(["Oxalo", "Cit", "IsoCit", "aKG", "SCoA", "Succ", "Fum", "Mal"])
non_main_cycle_species = net.get_species_list(["Pyr", "AcCoA", "CoA", "H2O", "GDP", "GTP", "Pi", "NAD", "NADH", "FAD", "FADH2", "CO2"])
species.move_to((3000, 3000))
species.set_shapes("circle")
main_cycle_species.set_sizes((110, 110))
non_main_cycle_species.set_sizes((70, 70))
species.set_font_sizes(40)
species.set_fill_colors("#DCEDC8")        # Muted olive green fill
species.set_border_colors("#9CCC65")      # Deeper olive for border
species.set_border_thicknesses(6)
species.set_font_colors("#33691E")         # Soft cream for species font
net.get_species("aKG").set_text("αKG")

center = (2200, 2800)
radius = 1500
initial_arc = 105
arc_step = -45
arc_start = initial_arc
clockwise = True
net.get_reaction("J2").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["Oxalo", "AcCoA", "H2O"], products_order=["CoA", "Cit"])
arc_start += arc_step
arc_start = initial_arc + 2 * arc_step
net.get_reaction("J4").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["IsoCit", "NAD"], products_order=["CO2", "NADH", "aKG"])
arc_start = initial_arc + 4 * arc_step
net.get_reaction("J6").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["SCoA", "GDP", "Pi"], products_order=["CoA", "GTP", "Succ"])
arc_start = initial_arc + 5 * arc_step
net.get_reaction("J7").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["Succ", "FAD"], products_order=["FADH2", "Fum"])

arc_start = initial_arc + arc_step
net.get_reaction("J3").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["Cit"], products_order=["IsoCit"])
arc_start = initial_arc + 3 * arc_step
net.get_reaction("J5").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["aKG", "NAD", "CoA"], products_order=["CO2", "NADH", "SCoA"])
arc_start = initial_arc + 6 * arc_step
net.get_reaction("J8").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["Fum", "H2O"], products_order=["Mal"])
arc_start = initial_arc + 7 * arc_step
net.get_reaction("J9").align_circle(arc_start=arc_start, arc_end=arc_start + arc_step, center_at=center, radius=radius, clockwise=clockwise, reactants_order=["Mal", "NAD"], products_order=["NADH", "Oxalo"])


spread = 800
mutual_species = net.get_species("AcCoA")
center = (mutual_species.get_position()[0] + mutual_species.get_size()[0] / 2,
          mutual_species.get_position()[1] + mutual_species.get_size()[1] / 2 - 0.5 * spread)
net.get_reaction("J1").align_vertical(center_at=center, spread_height=spread, reactants_order=["Pyr", "NAD", "CoA"], products_order=["CO2", "NADH", "AcCoA"])

reactions = net.get_reactions_list()
reactions.move_texts_by((15, 15))
reactions.set_font_sizes(20)
reactions.set_curve_thicknesses(22)
reactions.set_arrow_head_border_thicknesses(22)
reactions.set_arrow_head_sizes((18, 18))
reactions.move_arrow_head_relative_positions_by((-6, -3))
reactions.set_colors("#43A047")         # Vivid orange-red for maximum contrast
reactions.set_font_colors("#1B5E20")
reactions.move_texts_by((15, 10))# Soft cream for reaction texts

# Acetyl-CoA (Gold)
net.get_species_list("AcCoA").set_fill_colors("#FFD700")  # Gold
net.get_species_list("AcCoA").set_border_colors("#B8860B")  # Darker Gold
net.get_species_list("AcCoA").set_font_colors("#000000")  # Black (Good contrast)

# Water (Cyan)
net.get_species_list("H2O").set_fill_colors("#00BFFF")  # Cyan
net.get_species_list("H2O").set_border_colors("#0077A3")  # Darker Cyan
net.get_species_list("H2O").set_font_colors("#000000")  # Black (Good contrast)

# GDP & GTP (Bright Orange)
net.get_species_list("GDP").set_fill_colors("#FFA500")  # Bright Orange
net.get_species_list("GDP").set_border_colors("#CC8400")  # Darker Orange
net.get_species_list("GDP").set_font_colors("#000000")  # Black (Good contrast)

net.get_species_list("GTP").set_fill_colors("#FFA500")  # Bright Orange (same as GDP)
net.get_species_list("GTP").set_border_colors("#CC8400")  # Darker Orange (same as GDP)
net.get_species_list("GTP").set_font_colors("#000000")  # Black

# Inorganic Phosphate (Pi - Dark Orange)
net.get_species_list("Pi").set_fill_colors("#FF8C00")  # Dark Orange
net.get_species_list("Pi").set_border_colors("#B5651D")  # Brownish Orange
net.get_species_list("Pi").set_font_colors("#000000")  # Black

# NAD and NADH with representative colors
net.get_species_list("NAD").set_fill_colors("#FF7043")  # Soft Coral (Red-Orange for Oxidized NAD)
net.get_species_list("NAD").set_border_colors("#D84315")  # Dark Coral for Border
net.get_species_list("NAD").set_font_colors("#FFFFFF")  # White (Best contrast)

net.get_species_list("NADH").set_fill_colors("#64B5F6")  # Light Blue for Reduced NADH
net.get_species_list("NADH").set_border_colors("#1976D2")  # Dark Blue for Border
net.get_species_list("NADH").set_font_colors("#FFFFFF")  # White

# FAD & FADH2 (Royal Blue)
net.get_species_list("FAD").set_fill_colors("#4169E1")  # Royal Blue
net.get_species_list("FAD").set_border_colors("#1E3A8A")  # Darker Blue
net.get_species_list("FAD").set_font_colors("#FFFFFF")  # White

net.get_species_list("FADH2").set_fill_colors("#4169E1")  # Royal Blue (same as FAD)
net.get_species_list("FADH2").set_border_colors("#1E3A8A")  # Darker Blue
net.get_species_list("FADH2").set_font_colors("#FFFFFF")  # White

# Coenzyme A (Teal)
net.get_species_list("CoA").set_fill_colors("#008080")  # Teal
net.get_species_list("CoA").set_border_colors("#005F5F")  # Darker Teal
net.get_species_list("CoA").set_font_colors("#FFFFFF")  # White

# Carbon Dioxide (Gray)
net.get_species_list("CO2").set_fill_colors("#A9A9A9")  # Gray
net.get_species_list("CO2").set_border_colors("#696969")  # Darker Gray
net.get_species_list("CO2").set_font_colors("#000000")  # Black

# Set the fill color for main cycle species (Light Yellow)
cycle_fill_color = "#FFEB3B"  # Light Yellow
cycle_border_color = "#FBC02D"  # Golden Yellow (Border)
cycle_font_color = "#000000"  # Black (For Readability)


main_cycle_species.set_fill_colors(cycle_fill_color)
main_cycle_species.set_border_colors(cycle_border_color)
main_cycle_species.set_font_colors(cycle_font_color)




net.draw("test1.pdf")