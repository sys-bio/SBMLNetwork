import tellurium as te
import sys
import unittest
import math


sys.path.append('../src/sbmlnetwork/')
import sbmlnetwork

class TestSBMLModel(unittest.TestCase):
    def setUp(self):
        """ Set up the model for the test """
        self.model = '''
        J0: S1 -> S2;
        J1: S2 -> S3 + S4;
        J3: S2 -> S5;
        '''
        self.r = te.loada(self.model)

    def test_network_size(self):
        """ Test if the network size can be set and retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        size = network.get_size()
        network.set_size((size[0] + 100, size[1] + 100))
        new_size = network.get_size()
        self.assertEqual((size[0] + 100, size[1] + 100), new_size)

    def test_network_compartment(self):
        """ Test if the network compartment can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_ids = network.get_compartment_ids()
        compartment1 = network.get_compartment()
        compartment2 = network.get_compartment(compartment_id=compartment_ids[0])
        compartment3 = network.get_compartments_list()[0]
        self.assertEqual(compartment1.get_id(), compartment2.get_id())
        self.assertEqual(compartment1.get_graphical_object_index(), compartment2.get_graphical_object_index())
        self.assertEqual(compartment1.get_id(), compartment3.get_id())
        self.assertEqual(compartment1.get_graphical_object_index(), compartment3.get_graphical_object_index())

    def test_network_species(self):
        """ Test if the network species can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        species_ids = network.get_species_ids()
        species1 = network.get_species(species_id=species_ids[0])
        species2 = network.get_species_list(species_ids=species_ids[0])[0]
        self.assertEqual(species1.get_id(), species2.get_id())
        self.assertEqual(species1.get_graphical_object_index(), species2.get_graphical_object_index())

    def test_network_reaction(self):
        """ Test if the network reaction can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_ids = network.get_reaction_ids()
        reaction1 = network.get_reaction(reaction_id=reaction_ids[0])
        reaction2 = network.get_reactions_list(reaction_ids=reaction_ids[0])[0]
        self.assertEqual(reaction1.get_id(), reaction2.get_id())
        self.assertEqual(reaction1.get_graphical_object_index(), reaction2.get_graphical_object_index())

    def test_network_additional_elements(self):
        """ Test if the network additional elements can be added and removed"""
        network = sbmlnetwork.load(self.r.getSBML())
        elements = network.get_additional_elements()
        self.assertEqual(len(elements), 0)
        network.add_additional_element("test_additional_element", "rectangle", (100, 100), (50, 50))
        elements = network.get_additional_elements()
        self.assertEqual(len(elements), 1)
        self.assertEqual(elements[0].get_id(), "test_additional_element")
        self.assertEqual(elements[0].get_position(), (100, 100))
        self.assertEqual(elements[0].get_size(), (50, 50))
        self.assertEqual(elements[0].get_shape().get_type(), "rectangle")
        network.remove_additional_element(elements[0])
        elements = network.get_additional_elements()
        self.assertEqual(len(elements), 0)

    def test_color_bar(self):
        """ Test if the color bar can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        original_canvas_width = network.get_size()[0]
        color_bar = network.add_color_bar()
        self.assertAlmostEqual(color_bar.get_position()[0], original_canvas_width + color_bar.get_left_margin(), delta=0.1)
        self.assertAlmostEqual(network.get_size()[0], original_canvas_width + color_bar.get_left_margin() + color_bar.get_size()[0] + color_bar.get_right_margin(), delta=0.1)
        color_bar.set_number_of_tick_marks(10)
        self.assertEqual(color_bar.get_number_of_tick_marks(), 10)
        color_bar.set_max_value(100)
        self.assertAlmostEqual(color_bar.get_max_value(), 100, delta=0.1)
        color_bar.set_min_value(20)
        self.assertAlmostEqual(color_bar.get_min_value(), 20, delta=0.1)
        color_bar.set_tick_mark_size(50)
        self.assertAlmostEqual(color_bar.get_tick_mark_size(), 50, delta=0.1)
        color_bar.set_left_margin(100)
        self.assertAlmostEqual(color_bar.get_left_margin(), 100, delta=0.1)
        self.assertAlmostEqual(color_bar.get_position()[0], original_canvas_width + color_bar.get_left_margin(), delta=0.1)
        self.assertAlmostEqual(network.get_size()[0], original_canvas_width + color_bar.get_left_margin() + color_bar.get_size()[0] + color_bar.get_right_margin(), delta=0.1)
        color_bar.set_right_margin(200)
        self.assertAlmostEqual(color_bar.get_right_margin(), 200, delta=0.1)
        self.assertAlmostEqual(color_bar.get_position()[0], original_canvas_width + color_bar.get_left_margin(), delta=0.1)
        self.assertAlmostEqual(network.get_size()[0], original_canvas_width + color_bar.get_left_margin() + color_bar.get_size()[0] + color_bar.get_right_margin(), delta=0.1)
        color_bar.set_border_color("blue")
        self.assertEqual(color_bar.get_border_color(), "blue")
        color_bar.set_border_thickness(20)
        self.assertAlmostEqual(color_bar.get_border_thickness(), 20, delta=0.1)
        color_bar.set_corner_radius(50)
        self.assertEqual(color_bar.get_corner_radius(), 50)
        color_bar.set_tick_mark_thickness(5)
        self.assertAlmostEqual(color_bar.get_tick_mark_thickness(), 5, delta=0.1)
        color_bar.set_tick_mark_color("green")
        self.assertEqual(color_bar.get_tick_mark_color(), "green")
        color_bar.set_tick_mark_label_font_size(15)
        self.assertAlmostEqual(color_bar.get_tick_mark_label_font_size(), 15, delta=0.1)
        color_bar = network.get_color_bar()
        self.assertEqual(color_bar.get_number_of_tick_marks(), 10)
        self.assertAlmostEqual(color_bar.get_max_value(), 100, delta=0.1)
        self.assertAlmostEqual(color_bar.get_min_value(), 20, delta=0.1)
        self.assertAlmostEqual(color_bar.get_tick_mark_size(), 50, delta=0.1)
        self.assertAlmostEqual(color_bar.get_left_margin(), 100, delta=0.1)
        self.assertAlmostEqual(color_bar.get_position()[0], original_canvas_width + color_bar.get_left_margin(), delta=0.1)
        self.assertAlmostEqual(network.get_size()[0], original_canvas_width + color_bar.get_left_margin() + color_bar.get_size()[0] + color_bar.get_right_margin(), delta=0.1)
        self.assertEqual(color_bar.get_border_color(), "blue")
        self.assertAlmostEqual(color_bar.get_border_thickness(), 20, delta=0.1)
        self.assertAlmostEqual(color_bar.get_corner_radius(), 50, delta=0.1)
        self.assertAlmostEqual(color_bar.get_tick_mark_thickness(), 5, delta=0.1)
        self.assertEqual(color_bar.get_tick_mark_color(), "green")
        self.assertAlmostEqual(color_bar.get_tick_mark_label_font_size(), 15, delta=0.1)
        network.remove_color_bar()
        self.assertEqual(network.get_size()[0], original_canvas_width)

    def test_network__background_color(self):
        """ Test if the network background color can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        network.set_background_color("blue")
        self.assertEqual(network.get_background_color(), "blue")

    def test_network_style(self):
        """ Test if the network style can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        style_options = network.get_styles_options()
        network.set_style(style_options[-1])
        self.assertEqual(network.get_style(), style_options[-1])

    def test_network_element_position(self):
        """ Test if the network element position can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        position = species.get_position()
        species.set_position((position[0] + 100, position[1] + 100))
        new_position = species.get_position()
        self.assertAlmostEqual(position[0] + 100, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 100, new_position[1], delta=0.1)

    def test_network_element_size(self):
        """ Test if the network element size can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        size = species.get_size()
        species.set_size((size[0] + 100, size[1] + 100))
        new_size = species.get_size()
        self.assertAlmostEqual(size[0] + 100, new_size[0], delta=0.1)
        self.assertAlmostEqual(size[1] + 100, new_size[1], delta=0.1)

    def test_network_element_label(self):
        """ Test if the network element label can be added and removed """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        species.add_label("test_label")
        label = species.get_labels_list()[-1]
        self.assertEqual(label.get_text(), "test_label")
        species.remove_label("test_label")
        label = species.get_label()
        self.assertEqual(label.get_text(), species.get_species_id())
        self.assertEqual(len(species.get_labels_list()), 1)

    def test_network_element_shapes(self):
        """ Test if the network element shapes can be added and removed """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        species.add_shape("ellipse")
        shape = species.get_shapes_list()[-1]
        self.assertEqual(shape.get_type(), "ellipse")
        species.remove_shape(shape)
        self.assertEqual(len(species.get_shapes_list()), 1)
        shape_options = species.get_shapes_options()
        species.set_shape(shape_options[-1])
        shape = species.get_shapes_list()[-1]
        self.assertEqual(shape.get_type(), shape_options[-1])

    def test_network_element_hide_show(self):
        """ Test if the network element can be hidden and shown """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        species.hide()
        self.assertTrue(species.is_hidden())
        species.show()
        self.assertFalse(species.is_hidden())

    def test_network_element_meta_data(self):
        """ Test if the network element meta data can be added and removed """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        species.add_meta_data("test_key", "test_value")
        self.assertEqual(species.get_meta_data("test_key"), "test_value")
        species.remove_meta_data("test_key")
        self.assertEqual(species.get_meta_data("test_key"), None)

    def test_compartment_species_list(self):
        """ Test if the species list in compartment can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment = network.get_compartment()
        species_list = compartment.get_species_list()
        for species in species_list:
            self.assertEqual(species.get_compartment_id(), compartment.get_compartment_id())

    def test_compartment_reaction_list(self):
        """ Test if the reaction list in compartment can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment = network.get_compartment()
        reaction_list = compartment.get_reactions_list()
        for reaction in reaction_list:
            self.assertEqual(reaction.get_compartment_id(), compartment.get_compartment_id())

    def test_species_reaction_list(self):
        """ Test if the reaction list in species can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        for species in species_list:
            reaction_list = species.get_reactions_list()
            for reaction in reaction_list:
                reaction_species_ids = reaction.get_species_ids()
                self.assertTrue(species.get_species_id() in reaction_species_ids)

    def test_species_connected_curves(self):
        """ Test if the connected curves in species can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        for species in species_list:
            connected_curves = species.get_connected_curves()
            for curve in connected_curves:
                self.assertEqual(curve.get_species().get_species_id(), species.get_species_id())

    def test_species_roles(self):
        """ Test if the roles in species can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        for species in species_list:
            reaction_list = species.get_reactions_list()
            for reaction in reaction_list:
                self.assertTrue(species.get_role(reaction) in species.get_roles_options())

    def test_species_alias(self):
        """ Test if the alias in species can be created """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        for species in species_list:
            reaction_list = species.get_reactions_list()
            for reaction in reaction_list:
                alias_species = species.create_alias(reaction)
                if alias_species:
                    self.assertEqual(alias_species.get_species_id(), species.get_species_id())
                    self.assertEqual(alias_species.get_graphical_object_index(), len(network.get_species_list(species.get_species_id())) - 1)

    def test_species_move(self):
        """ Test if the species can be moved """
        self.model1 = '''
            J0: S1 -> S2;
            S3 -| J0;
        '''
        self.r1 = te.loada(self.model1)
        network = sbmlnetwork.load(self.r1.getSBML())
        species = network.get_species("S1")
        position = species.get_position()
        connected_curve = species.get_connected_curves()[0]
        connected_curve_end = connected_curve.get_end()
        species.move((50, 50), move_connected_curves=True)
        new_position = species.get_position()
        new_connected_curve_end = connected_curve.get_end()
        self.assertAlmostEqual(position[0] + 50, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 50, new_position[1], delta=0.1)
        self.assertAlmostEqual(connected_curve_end[0] + 50, new_connected_curve_end[0], delta=0.1)
        self.assertAlmostEqual(connected_curve_end[1] + 50, new_connected_curve_end[1], delta=0.1)
        position = species.get_position()
        connected_curve_end = connected_curve.get_end()
        species.move((50, 50), move_connected_curves=False)
        new_position = species.get_position()
        new_connected_curve_end = connected_curve.get_end()
        self.assertAlmostEqual(position[0] + 50, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 50, new_position[1], delta=0.1)
        self.assertAlmostEqual(connected_curve_end[0], new_connected_curve_end[0], delta=0.1)
        self.assertAlmostEqual(connected_curve_end[1], new_connected_curve_end[1], delta=0.1)
        species = network.get_species("S3")
        position = species.get_position()
        connected_curve = species.get_connected_curves()[0]
        connected_curve_start = connected_curve.get_start()
        species.move((50, 50), move_connected_curves=True)
        new_position = species.get_position()
        new_connected_curve_start = connected_curve.get_start()
        self.assertAlmostEqual(position[0] + 50, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 50, new_position[1], delta=0.1)
        self.assertAlmostEqual(connected_curve_start[0] + 50, new_connected_curve_start[0], delta=0.1)
        self.assertAlmostEqual(connected_curve_start[1] + 50, new_connected_curve_start[1], delta=0.1)
        position = species.get_position()
        connected_curve_start = connected_curve.get_start()
        species.move((50, 50), move_connected_curves=False)
        new_position = species.get_position()
        new_connected_curve_start = connected_curve.get_start()
        self.assertAlmostEqual(position[0] + 50, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 50, new_position[1], delta=0.1)
        self.assertAlmostEqual(connected_curve_start[0], new_connected_curve_start[0], delta=0.1)
        self.assertAlmostEqual(connected_curve_start[1], new_connected_curve_start[1], delta=0.1)

    def test_reaction_center(self):
        """ Test if the center of the reaction can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            center = reaction.get_center()
            self.assertTrue(center.get_reaction().get_reaction_id() == reaction.get_reaction_id())

    def test_reaction_curves_list(self):
        """ Test if the curves list in reaction can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                self.assertEqual(curve.get_reaction().get_reaction_id(), reaction.get_reaction_id())

    def test_reaction_species_list(self):
        """ Test if the species list in reaction can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            species_list = reaction.get_species_list()
            for species in species_list:
                species_reaction_ids = species.get_reaction_ids()
                self.assertTrue(reaction.get_reaction_id() in species_reaction_ids)

    def test_reaction_empty_species(self):
        """ Test if the empty species in reaction can be retrieved """
        self.model1 = '''
                J0: S1 -> S2;
                J1: -> S2;
                '''
        self.r1 = te.loada(self.model1)
        network = sbmlnetwork.load(self.r1.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            empty_species = reaction.get_empty_species()
            if empty_species:
                last_underscore_index = empty_species.get_species_id().rfind('_')
                reaction_id =  empty_species.get_species_id()[:last_underscore_index]
                self.assertEqual(reaction_id, reaction.get_id())
                self.assertTrue(empty_species.get_graphical_object_index() == 0)

    def test_reaction_alias(self):
        """ Test if the alias in reaction can be created """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            alias_reaction = reaction.create_alias()
            if alias_reaction:
                self.assertEqual(alias_reaction.get_reaction_id(), reaction.get_reaction_id())
                self.assertEqual(alias_reaction.get_graphical_object_index(), len(network.get_reactions_list(reaction.get_reaction_id())) - 1)
                alias_species_list = alias_reaction.get_species_list()
                species_list = reaction.get_species_list()
                for i in range(len(alias_species_list)):
                    self.assertEqual(alias_species_list[i].get_species_id(), species_list[i].get_species_id())
                    self.assertEqual(alias_species_list[i].get_graphical_object_index(),
                                     network.get_species_list(species_list[i].get_species_id())[-1].get_graphical_object_index())

    def test_reaction_assign_species(self):
        """ Test if the species can be assigned to the reaction """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        for species in species_list:
            reaction_list = species.get_reactions_list()
            if len(reaction_list) > 1:
                for i in range(1, len(reaction_list)):
                    reaction = reaction_list[i]
                    alias_species = species.create_alias(reaction)
                    species_in_reaction = reaction.get_species_list(species.get_species_id())[0]
                    self.assertEqual(species_in_reaction.get_species_id(), alias_species.get_species_id())
                    self.assertEqual(species_in_reaction.get_graphical_object_index(), alias_species.get_graphical_object_index())
                    reaction.assign_species(species)
                    species_in_reaction = reaction.get_species_list(species.get_species_id())[0]
                    self.assertEqual(species_in_reaction.get_species_id(), species.get_species_id())
                    self.assertEqual(species_in_reaction.get_graphical_object_index(), species.get_graphical_object_index())

    def test_label_position(self):
        """ Test if the label position can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        label = species.get_labels_list()[-1]
        position = label.get_position()
        label.set_position((position[0] + 100, position[1] + 100))
        new_position = label.get_position()
        self.assertAlmostEqual(position[0] + 100, new_position[0], delta=0.1)

    def test_label_size(self):
        """ Test if the label size can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        label = species.get_labels_list()[-1]
        size = label.get_size()
        label.set_size((size[0] + 100, size[1] + 100))
        new_size = label.get_size()
        self.assertEqual((size[0] + 100, size[1] + 100), new_size)

    def test_label_align(self):
        """ Test if the label can be aligned """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        label = species.get_labels_list()[-1]
        label.align_to_top()
        self.assertEqual(label.get_vertical_alignment(), "top")
        label.align_to_vertical_center()
        self.assertEqual(label.get_vertical_alignment(), "vertical_center")
        label.align_to_bottom()
        self.assertEqual(label.get_vertical_alignment(), "bottom")
        label.align_to_baseline()
        self.assertEqual(label.get_vertical_alignment(), "baseline")
        label.align_to_left()
        self.assertEqual(label.get_horizontal_alignment(), "left")
        label.align_to_horizontal_center()
        self.assertEqual(label.get_horizontal_alignment(), "horizontal_center")
        label.align_to_right()
        self.assertEqual(label.get_horizontal_alignment(), "right")

    def test_label_text(self):
        """ Test if the label text can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        label = species.get_labels_list()[-1]
        label.set_text("test_label")
        self.assertEqual(label.get_text(), "test_label")

    def test_label_font(self):
        """ Test if the label font can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        species = network.get_species_list()[0]
        label = species.get_labels_list()[-1]
        label.set_font("Arial")
        self.assertEqual(label.get_font(), "Arial")
        label.set_font_size(20)
        self.assertEqual(label.get_font_size(), 20)
        label.set_font_color("red")
        self.assertEqual(label.get_font_color(), "red")
        self.assertEqual(label.is_bold(), False)
        label.set_bold(True)
        self.assertEqual(label.is_bold(), True)
        self.assertEqual(label.is_italic(), False)
        label.set_italic(True)
        self.assertEqual(label.is_italic(), True)

    def test_reaction_center_reaction(self):
        """ Test if the reaction center can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            center = reaction.get_center()
            self.assertTrue(center.get_reaction().get_reaction_id() == reaction.get_reaction_id())

    def test_reaction_center_switch(self):
        """ Test if the reaction center can be switched """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            center = reaction.get_center()
            self.assertTrue(center.is_curve())
            center.switch_to_shapes()
            self.assertTrue(center.is_shapes())
            center.switch_to_curve()
            self.assertTrue(center.is_curve())

    def test_reaction_center_curve(self):
        """ Test if the reaction center curve can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            center = reaction.get_center()
            center.switch_to_curve()
            curve = center.get_curve()
            self.assertTrue(curve.get_reaction().get_reaction_id() == reaction.get_reaction_id())

    def test_reaction_center_shapes(self):
        """ Test if the reaction center shapes can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            center = reaction.get_center()
            center.switch_to_shapes()
            shapes_list = center.get_shapes_list()
            for shape in shapes_list:
                self.assertEqual(shape.get_element_id(), reaction.get_reaction_id())
                self.assertEqual(shape.get_graphical_object_index(), reaction.get_graphical_object_index())

    def test_reaction_move(self):
        """ Test if the reaction can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction = network.get_reactions_list()[0]
        position = reaction.get_position()
        connected_species_positions = reaction.get_species_list().get_position()
        connected_curves_start = reaction.get_curves_list().get_start()
        connected_curves_end = reaction.get_curves_list().get_end()
        reaction.move((50, 50), move_connected_species=True)
        new_position = reaction.get_position()
        new_connected_species_positions = reaction.get_species_list().get_position()
        new_connected_curves_start = reaction.get_curves_list().get_start()
        new_connected_curves_end = reaction.get_curves_list().get_end()
        self.assertAlmostEqual(position[0] + 50, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 50, new_position[1], delta=0.1)
        for i in range(len(connected_species_positions)):
            self.assertAlmostEqual(connected_species_positions[i][0] + 50, new_connected_species_positions[i][0], delta=0.1)
            self.assertAlmostEqual(connected_species_positions[i][1] + 50, new_connected_species_positions[i][1], delta=0.1)
        for i in range(len(connected_curves_start)):
            self.assertAlmostEqual(connected_curves_start[i][0] + 50, new_connected_curves_start[i][0], delta=0.1)
            self.assertAlmostEqual(connected_curves_start[i][1] + 50, new_connected_curves_start[i][1], delta=0.1)
        for i in range(len(connected_curves_end)):
            self.assertAlmostEqual(connected_curves_end[i][0] + 50, new_connected_curves_end[i][0], delta=0.1)
            self.assertAlmostEqual(connected_curves_end[i][1] + 50, new_connected_curves_end[i][1], delta=0.1)
        position = reaction.get_position()
        connected_species_positions = reaction.get_species_list().get_position()
        connected_curves_start = reaction.get_curves_list().get_start()
        connected_curves_end = reaction.get_curves_list().get_end()
        reaction.move((50, 50), move_connected_species=False)
        new_position = reaction.get_position()
        new_connected_species_positions = reaction.get_species_list().get_position()
        new_connected_curves_start = reaction.get_curves_list().get_start()
        new_connected_curves_end = reaction.get_curves_list().get_end()
        self.assertAlmostEqual(position[0] + 50, new_position[0], delta=0.1)
        self.assertAlmostEqual(position[1] + 50, new_position[1], delta=0.1)
        for i in range(len(connected_species_positions)):
            self.assertAlmostEqual(connected_species_positions[i][0], new_connected_species_positions[i][0], delta=0.1)
            self.assertAlmostEqual(connected_species_positions[i][1], new_connected_species_positions[i][1], delta=0.1)
        for i in range(len(connected_curves_start)):
            self.assertAlmostEqual(connected_curves_start[i][0] + 50, new_connected_curves_start[i][0], delta=0.1)
            self.assertAlmostEqual(connected_curves_start[i][1] + 50, new_connected_curves_start[i][1], delta=0.1)
        for i in range(len(connected_curves_end)):
            self.assertAlmostEqual(connected_curves_end[i][0] + 50, new_connected_curves_end[i][0], delta=0.1)
            self.assertAlmostEqual(connected_curves_end[i][1] + 50, new_connected_curves_end[i][1], delta=0.1)

    def test_curve_reaction(self):
        """ Test if the curve reaction can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                self.assertEqual(curve.get_reaction().get_reaction_id(), reaction.get_reaction_id())

    def test_curve_species(self):
        """ Test if the curve species can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            species_ids = reaction.get_species_ids()
            for curve in curves_list:
                self.assertTrue(curve.get_species().get_species_id() in species_ids)

    def test_curve_role(self):
        """ Test if the curve role can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                self.assertTrue(curve.get_role() in curve.get_roles_options())

    def test_curve_color(self):
        """ Test if the curve color can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                curve.set_color("red")
                self.assertEqual(curve.get_color(), "red")

    def test_curve_thickness(self):
        """ Test if the curve thickness can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                curve.set_thickness(10)
                self.assertEqual(curve.get_thickness(), 10)

    def test_curve_start_end(self):
        """ Test if the curve start and end can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                curve.set_start((100, 100))
                self.assertEqual(curve.get_start(), (100, 100))
                curve.set_end((200, 200))
                self.assertEqual(curve.get_end(), (200, 200))

    def test_curve_segment(self):
        """ Test if the curve segment can be added and removed """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                self.assertEqual(len(curve.get_segments_list()), 1)
                curve.add_segment((100, 100), (200, 200), (150, 150), (250, 250))
                self.assertEqual(len(curve.get_segments_list()), 2)
                curve.remove_segment(curve.get_segments_list()[0])
                self.assertEqual(len(curve.get_segments_list()), 1)
                self.assertEqual(curve.get_segment().get_start(), (100, 100))
                self.assertEqual(curve.get_segment().get_end(), (200, 200))
                self.assertEqual(curve.get_start_slope(), (150 - 100) / (150 - 100))
                self.assertEqual(curve.get_end_slope(), (250 - 200) / (250 - 200))

    def test_curve_move(self):
        """ Test if the curve can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction = network.get_reactions_list()[0]
        curve = reaction.get_curves_list()[0]
        start_position = curve.get_start()
        end_position = curve.get_end()
        curve.move((50, 50))
        new_start_position = curve.get_start()
        new_end_position = curve.get_end()
        self.assertAlmostEqual(start_position[0] + 50, new_start_position[0], delta=0.1)
        self.assertAlmostEqual(start_position[1] + 50, new_start_position[1], delta=0.1)
        self.assertAlmostEqual(end_position[0] + 50, new_end_position[0], delta=0.1)
        self.assertAlmostEqual(end_position[1] + 50, new_end_position[1], delta=0.1)
        start_position = curve.get_start()
        end_position = curve.get_end()
        curve.move_start((50, 50))
        new_start_position = curve.get_start()
        new_end_position = curve.get_end()
        self.assertAlmostEqual(start_position[0] + 50, new_start_position[0], delta=0.1)
        self.assertAlmostEqual(start_position[1] + 50, new_start_position[1], delta=0.1)
        self.assertAlmostEqual(end_position[0], new_end_position[0], delta=0.1)
        self.assertAlmostEqual(end_position[1], new_end_position[1], delta=0.1)
        start_position = curve.get_start()
        end_position = curve.get_end()
        curve.move_end((50, 50))
        new_start_position = curve.get_start()
        new_end_position = curve.get_end()
        self.assertAlmostEqual(start_position[0], new_start_position[0], delta=0.1)
        self.assertAlmostEqual(start_position[1], new_start_position[1], delta=0.1)
        self.assertAlmostEqual(end_position[0] + 50, new_end_position[0], delta=0.1)
        self.assertAlmostEqual(end_position[1] + 50, new_end_position[1], delta=0.1)
        curve.add_segment((100, 100), (200, 200), (150, 150), (250, 250))
        first_segment_start_position = curve.get_segments_list()[0].get_start()
        first_segment_end_position = curve.get_segments_list()[0].get_end()
        first_segment_control_point_1_position = curve.get_segments_list()[0].get_control_point_1()
        first_segment_control_point_2_position = curve.get_segments_list()[0].get_control_point_2()
        first_segment_end_position = curve.get_segments_list()[0].get_end()
        second_segment_start_position = curve.get_segments_list()[1].get_start()
        second_segment_end_position = curve.get_segments_list()[1].get_end()
        second_segment_control_point_1_position = curve.get_segments_list()[1].get_control_point_1()
        second_segment_control_point_2_position = curve.get_segments_list()[1].get_control_point_2()
        curve.move((50, 50))
        new_first_segment_start_position = curve.get_segments_list()[0].get_start()
        new_first_segment_end_position = curve.get_segments_list()[0].get_end()
        new_first_segment_control_point_1_position = curve.get_segments_list()[0].get_control_point_1()
        new_first_segment_control_point_2_position = curve.get_segments_list()[0].get_control_point_2()
        new_second_segment_start_position = curve.get_segments_list()[1].get_start()
        new_second_segment_end_position = curve.get_segments_list()[1].get_end()
        new_second_segment_control_point_1_position = curve.get_segments_list()[1].get_control_point_1()
        new_second_segment_control_point_2_position = curve.get_segments_list()[1].get_control_point_2()
        self.assertAlmostEqual(first_segment_start_position[0] + 50, new_first_segment_start_position[0], delta=0.1)
        self.assertAlmostEqual(first_segment_start_position[1] + 50, new_first_segment_start_position[1], delta=0.1)
        self.assertAlmostEqual(first_segment_end_position[0] + 50, new_first_segment_end_position[0], delta=0.1)
        self.assertAlmostEqual(first_segment_end_position[1] + 50, new_first_segment_end_position[1], delta=0.1)
        self.assertAlmostEqual(first_segment_control_point_1_position[0] + 50, new_first_segment_control_point_1_position[0], delta=0.1)
        self.assertAlmostEqual(first_segment_control_point_1_position[1] + 50, new_first_segment_control_point_1_position[1], delta=0.1)
        self.assertAlmostEqual(first_segment_control_point_2_position[0] + 50, new_first_segment_control_point_2_position[0], delta=0.1)
        self.assertAlmostEqual(first_segment_control_point_2_position[1] + 50, new_first_segment_control_point_2_position[1], delta=0.1)
        self.assertAlmostEqual(second_segment_start_position[0] + 50, new_second_segment_start_position[0], delta=0.1)
        self.assertAlmostEqual(second_segment_start_position[1] + 50, new_second_segment_start_position[1], delta=0.1)
        self.assertAlmostEqual(second_segment_end_position[0] + 50, new_second_segment_end_position[0], delta=0.1)
        self.assertAlmostEqual(second_segment_end_position[1] + 50, new_second_segment_end_position[1], delta=0.1)
        self.assertAlmostEqual(second_segment_control_point_1_position[0] + 50, new_second_segment_control_point_1_position[0], delta=0.1)
        self.assertAlmostEqual(second_segment_control_point_1_position[1] + 50, new_second_segment_control_point_1_position[1], delta=0.1)
        self.assertAlmostEqual(second_segment_control_point_2_position[0] + 50, new_second_segment_control_point_2_position[0], delta=0.1)
        self.assertAlmostEqual(second_segment_control_point_2_position[1] + 50, new_second_segment_control_point_2_position[1], delta=0.1)

    def test_curve_hide_show(self):
        """ Test if the curve can be hidden and shown """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction = network.get_reactions_list()[0]
        curve = reaction.get_curves_list()[0]
        curve.hide()
        self.assertTrue(curve.is_hidden())
        curve.show()
        self.assertFalse(curve.is_hidden())

    def test_curve_segment_points(self):
        """ Test if the curve segment start and end can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                for segment in curve.get_segments_list():
                    segment.set_start((100, 100))
                    self.assertEqual(segment.get_start(), (100, 100))
                    segment.set_end((200, 200))
                    self.assertEqual(segment.get_end(), (200, 200))
                    segment.set_control_point_1((150, 150))
                    self.assertEqual(segment.get_control_point_1(), (150, 150))
                    segment.set_control_point_2((250, 250))
                    self.assertEqual(segment.get_control_point_2(), (250, 250))

    def test_curve_segment_move(self):
        """ Test if the curve segment can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction = network.get_reactions_list()[0]
        curve = reaction.get_curves_list()[0]
        segment = curve.get_segments_list()[0]
        start_position = segment.get_start()
        end_position = segment.get_end()
        control_point_1_position = segment.get_control_point_1()
        control_point_2_position = segment.get_control_point_2()
        segment.move((50, 50))
        new_start_position = segment.get_start()
        new_end_position = segment.get_end()
        new_control_point_1_position = segment.get_control_point_1()
        new_control_point_2_position = segment.get_control_point_2()
        self.assertAlmostEqual(start_position[0] + 50, new_start_position[0], delta=0.1)
        self.assertAlmostEqual(start_position[1] + 50, new_start_position[1], delta=0.1)
        self.assertAlmostEqual(end_position[0] + 50, new_end_position[0], delta=0.1)
        self.assertAlmostEqual(end_position[1] + 50, new_end_position[1], delta=0.1)
        self.assertAlmostEqual(control_point_1_position[0] + 50, new_control_point_1_position[0], delta=0.1)
        self.assertAlmostEqual(control_point_1_position[1] + 50, new_control_point_1_position[1], delta=0.1)
        self.assertAlmostEqual(control_point_2_position[0] + 50, new_control_point_2_position[0], delta=0.1)
        self.assertAlmostEqual(control_point_2_position[1] + 50, new_control_point_2_position[1], delta=0.1)
        start_position = segment.get_start()
        end_position = segment.get_end()
        control_point_1_position = segment.get_control_point_1()
        control_point_2_position = segment.get_control_point_2()
        segment.move_start((50, 50))
        new_start_position = segment.get_start()
        new_end_position = segment.get_end()
        new_control_point_1_position = segment.get_control_point_1()
        new_control_point_2_position = segment.get_control_point_2()
        self.assertAlmostEqual(start_position[0] + 50, new_start_position[0], delta=0.1)
        self.assertAlmostEqual(start_position[1] + 50, new_start_position[1], delta=0.1)
        self.assertAlmostEqual(end_position[0], new_end_position[0], delta=0.1)
        self.assertAlmostEqual(end_position[1], new_end_position[1], delta=0.1)
        self.assertAlmostEqual(control_point_1_position[0] + 50, new_control_point_1_position[0], delta=0.1)
        self.assertAlmostEqual(control_point_1_position[1] + 50, new_control_point_1_position[1], delta=0.1)
        self.assertAlmostEqual(control_point_2_position[0], new_control_point_2_position[0], delta=0.1)
        self.assertAlmostEqual(control_point_2_position[1], new_control_point_2_position[1], delta=0.1)
        start_position = segment.get_start()
        end_position = segment.get_end()
        control_point_1_position = segment.get_control_point_1()
        control_point_2_position = segment.get_control_point_2()
        segment.move_end((50, 50))
        new_start_position = segment.get_start()
        new_end_position = segment.get_end()
        new_control_point_1_position = segment.get_control_point_1()
        new_control_point_2_position = segment.get_control_point_2()
        self.assertAlmostEqual(start_position[0], new_start_position[0], delta=0.1)
        self.assertAlmostEqual(start_position[1], new_start_position[1], delta=0.1)
        self.assertAlmostEqual(end_position[0] + 50, new_end_position[0], delta=0.1)
        self.assertAlmostEqual(end_position[1] + 50, new_end_position[1], delta=0.1)
        self.assertAlmostEqual(control_point_1_position[0], new_control_point_1_position[0], delta=0.1)
        self.assertAlmostEqual(control_point_1_position[1], new_control_point_1_position[1], delta=0.1)
        self.assertAlmostEqual(control_point_2_position[0] + 50, new_control_point_2_position[0], delta=0.1)
        self.assertAlmostEqual(control_point_2_position[1] + 50, new_control_point_2_position[1], delta=0.1)

    def test_arrow_head_relative_position(self):
        """ Test if the arrow head relative position can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                arrow_head = curve.get_arrow_head()
                if arrow_head:
                    position = arrow_head.get_relative_position()
                    arrow_head.set_relative_position((position[0] + 100, position[1] + 100))
                    new_position = arrow_head.get_relative_position()
                    self.assertAlmostEqual(position[0] + 100, new_position[0], delta=0.1)
                    self.assertAlmostEqual(position[1] + 100, new_position[1], delta=0.1)

    def test_arrow_head_size(self):
        """ Test if the arrow head size can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve in curves_list:
                arrow_head = curve.get_arrow_head()
                if arrow_head:
                    size = arrow_head.get_size()
                    arrow_head.set_size((size[0] + 100, size[1] + 100))
                    new_size = arrow_head.get_size()
                    self.assertEqual((size[0] + 100, size[1] + 100), new_size)

    def test_arrow_head_shape(self):
        """ Test if the arrow head shape can be set """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curves_list = reaction.get_curves_list()
            for curve_index, curve in enumerate(curves_list):
                arrow_head = curve.get_arrow_head()
                if arrow_head:
                    arrow_head.set_shape("rectangle")
                    arrow_head.add_shape("hexagon")
                    shapes_list = arrow_head.get_shapes_list()
                    self.assertEqual(len(shapes_list), 2)
                    for shape_index, shape in enumerate(shapes_list):
                        self.assertEqual(shape.get_element_id(), reaction.get_reaction_id())
                        self.assertEqual(shape.get_graphical_object_index(), reaction.get_graphical_object_index())
                        self.assertEqual(shape.get_sub_element_index(), curve_index)
                        self.assertEqual(shape.get_geometric_shape_index(), shape_index)
                    arrow_head.remove_shape(shapes_list[0])
                    self.assertEqual(len(arrow_head.get_shapes_list()), 1)
                    self.assertEqual(arrow_head.get_shape().get_type(), "hexagon")

    def test_network_element_list_id(self):
        """ Test if the ids can be retrieved from the network element list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        compartment_ids1 = [compartment.get_id() for compartment in compartment_list]
        compartment_ids2 = compartment_list.get_id()
        self.assertEqual(compartment_ids1, compartment_ids2)
        species_list = network.get_species_list()
        speices_ids1 = [species.get_id() for species in species_list]
        speices_ids2 = species_list.get_id()
        self.assertEqual(speices_ids1, speices_ids2)
        reaction_list = network.get_reactions_list()
        reaction_ids1 = [reaction.get_id() for reaction in reaction_list]
        reaction_ids2 = reaction_list.get_id()
        self.assertEqual(reaction_ids1, reaction_ids2)

    def test_network_element_list_graphical_object_index(self):
        """ Test if the graphical object index can be retrieved from the network element list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        compartment_graphical_object_index1 = [compartment.get_graphical_object_index() for compartment in compartment_list]
        compartment_graphical_object_index2 = compartment_list.get_graphical_object_index()
        self.assertEqual(compartment_graphical_object_index1, compartment_graphical_object_index2)
        species_list = network.get_species_list()
        species_graphical_object_index1 = [species.get_graphical_object_index() for species in species_list]
        species_graphical_object_index2 = species_list.get_graphical_object_index()
        self.assertEqual(species_graphical_object_index1, species_graphical_object_index2)
        reaction_list = network.get_reactions_list()
        reaction_graphical_object_index1 = [reaction.get_graphical_object_index() for reaction in reaction_list]
        reaction_graphical_object_index2 = reaction_list.get_graphical_object_index()
        self.assertEqual(reaction_graphical_object_index1, reaction_graphical_object_index2)

    def test_network_element_list_position(self):
        """ Test if the position can be retrieved from the network element list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        compartment_position1 = [compartment.get_position() for compartment in compartment_list]
        compartment_position2 = compartment_list.get_position()
        self.assertEqual(compartment_position1, compartment_position2)
        compartment_list.set_position((100, 100))
        for compartment in compartment_list:
            self.assertEqual(compartment.get_position(), (100, 100))
        species_list = network.get_species_list()
        species_position1 = [species.get_position() for species in species_list]
        species_position2 = species_list.get_position()
        self.assertEqual(species_position1, species_position2)
        species_list.set_position((100, 100))
        for species in species_list:
            self.assertEqual(species.get_position(), (100, 100))
        reaction_list = network.get_reactions_list()
        reaction_position1 = [reaction.get_position() for reaction in reaction_list]
        reaction_position2 = reaction_list.get_position()
        self.assertEqual(reaction_position1, reaction_position2)
        reaction_list.set_position((100, 100))
        for reaction in reaction_list:
            self.assertEqual(reaction.get_position(), (100, 100))

    def test_network_element_list_size(self):
        """ Test if the size can be retrieved from the network element list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        compartment_size1 = [compartment.get_size() for compartment in compartment_list]
        compartment_size2 = compartment_list.get_size()
        self.assertEqual(compartment_size1, compartment_size2)
        compartment_list.set_size((100, 100))
        for compartment in compartment_list:
            self.assertEqual(compartment.get_size(), (100, 100))
        species_list = network.get_species_list()
        species_size1 = [species.get_size() for species in species_list]
        species_size2 = species_list.get_size()
        self.assertEqual(species_size1, species_size2)
        species_list.set_size((100, 100))
        for species in species_list:
            self.assertEqual(species.get_size(), (100, 100))
        reaction_list = network.get_reactions_list()
        reaction_size1 = [reaction.get_size() for reaction in reaction_list]
        reaction_size2 = reaction_list.get_size()
        self.assertEqual(reaction_size1, reaction_size2)
        reaction_list.set_size((100, 100))
        for reaction in reaction_list:
            self.assertEqual(reaction.get_size(), (100, 100))

    def test_network_element_list_label(self):
        """ Test if the label can be added and removed from the network element list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        label = compartment_list.add_label("test_label")
        for compartment in compartment_list:
            self.assertEqual(compartment.get_labels_list()[-1].get_text(), "test_label")
        compartment_list.remove_label("test_label")
        for compartment in compartment_list:
            self.assertEqual(compartment.get_labels_list()[-1].get_text(), compartment.get_compartment_id())
            self.assertEqual(len(compartment.get_labels_list()), 1)
        species_list = network.get_species_list()
        species_list.add_label("test_label")
        for species in species_list:
            self.assertEqual(species.get_labels_list()[-1].get_text(), "test_label")
        species_list.remove_label("test_label")
        for species in species_list:
            self.assertEqual(species.get_label().get_text(), species.get_species_id())
            self.assertEqual(len(species.get_labels_list()), 1)
        reaction_list = network.get_reactions_list()
        reaction_list.add_label("test_label")
        for reaction in reaction_list:
            self.assertEqual(reaction.get_labels_list()[-1].get_text(), "test_label")
        reaction_list.remove_label("test_label")
        for reaction in reaction_list:
            self.assertEqual(reaction.get_label().get_text(), reaction.get_reaction_id())
            self.assertEqual(len(reaction.get_labels_list()), 1)

    def test_network_element_list_shape(self):
        """ Test if the shape can be added and removed from the network element list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        compartment_list.add_shape("ellipse")
        for compartment in compartment_list:
            self.assertEqual(compartment.get_shapes_list()[-1].get_type(), "ellipse")
        compartment_list.remove_shape(compartment_list.get_shapes_list()[-1])
        for compartment in compartment_list:
            self.assertEqual(compartment.get_shapes_list()[-1].get_type(), "rectangle")
            self.assertEqual(len(compartment.get_shapes_list()), 1)
        species_list = network.get_species_list()
        species_list.add_shape("ellipse")
        for species in species_list:
            self.assertEqual(species.get_shapes_list()[-1].get_type(), "ellipse")
        species_list.remove_shape(species_list.get_shapes_list()[-1])
        for species in species_list:
            self.assertEqual(species.get_shape().get_type(), "rectangle")
            self.assertEqual(len(species.get_shapes_list()), 1)

    def test_compartment_list_compartment_id(self):
        """ Test if the compartment ids can be retrieved from the compartment list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        compartment_ids1 = [compartment.get_compartment_id() for compartment in compartment_list]
        compartment_ids2 = compartment_list.get_compartment_id()
        self.assertEqual(compartment_ids1, compartment_ids2)

    def test_compartment_list_species_list(self):
        """ Test if the species list can be retrieved from the compartment list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        species_list1 = []
        for compartment in compartment_list:
            species_list1.extend(compartment.get_species_list())
        species_list2 = compartment_list.get_species_list()
        self.assertEqual(len(species_list1), len(species_list2))
        for i in range(len(species_list1)):
            self.assertEqual(species_list1[i].get_species_id(), species_list2[i].get_species_id())
            self.assertEqual(species_list1[i].get_graphical_object_index(), species_list2[i].get_graphical_object_index())

    def test_compartment_list_reaction_list(self):
        """ Test if the reaction list can be retrieved from the compartment list """
        network = sbmlnetwork.load(self.r.getSBML())
        compartment_list = network.get_compartments_list()
        reaction_list1 = []
        for compartment in compartment_list:
            reaction_list1.extend(compartment.get_reactions_list())
        reaction_list2 = compartment_list.get_reactions_list()
        self.assertEqual(len(reaction_list1), len(reaction_list2))
        for i in range(len(reaction_list1)):
            self.assertEqual(reaction_list1[i].get_reaction_id(), reaction_list2[i].get_reaction_id())
            self.assertEqual(reaction_list1[i].get_graphical_object_index(), reaction_list2[i].get_graphical_object_index())

    def test_species_list_species_id(self):
        """ Test if the species ids can be retrieved from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        species_ids1 = [species.get_species_id() for species in species_list]
        species_ids2 = species_list.get_species_id()
        self.assertEqual(species_ids1, species_ids2)

    def test_species_list_compartment_id(self):
        """ Test if the compartment ids can be retrieved from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        compartment_ids1 = [species.get_compartment_id() for species in species_list]
        compartment_ids2 = species_list.get_compartment_id()
        self.assertEqual(compartment_ids1, compartment_ids2)

    def test_species_list_reaction_list(self):
        """ Test if the reaction list can be retrieved from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        reaction_list1 = []
        for species in species_list:
            reaction_list1.extend(species.get_reactions_list())
        reaction_list2 = species_list.get_reactions_list()
        self.assertEqual(len(reaction_list1), len(reaction_list2))
        for i in range(len(reaction_list1)):
            self.assertEqual(reaction_list1[i].get_reaction_id(), reaction_list2[i].get_reaction_id())
            self.assertEqual(reaction_list1[i].get_graphical_object_index(), reaction_list2[i].get_graphical_object_index())

    def test_species_list_reaction_ids(self):
        """ Test if the reaction ids can be retrieved from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        reaction_ids1 = [species.get_reaction_ids() for species in species_list]
        reaction_ids2 = species_list.get_reaction_ids()
        self.assertEqual(reaction_ids1, reaction_ids2)

    def test_species_list_connected_curves(self):
        """ Test if the connected curves can be retrieved from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        connected_curves1 = []
        for species in species_list:
            connected_curves1.extend(species.get_connected_curves())
        connected_curves2 = species_list.get_connected_curves()
        self.assertEqual(len(connected_curves1), len(connected_curves2))
        for i in range(len(connected_curves1)):
            self.assertEqual(connected_curves1[i].get_species().get_species_id(), connected_curves2[i].get_species().get_species_id())

    def test_species_list_role(self):
        """ Test if the roles can be retrieved from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        roles1 = []
        for species in species_list:
            roles1.append(species.get_role(network.get_reactions_list()[0]))
        roles2 = species_list.get_role(network.get_reactions_list()[0])
        self.assertEqual(roles1, roles2)

    def test_species_list_create_alias(self):
        """ Test if the alias can be created from the species list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        aliases1 = []
        for species in species_list:
            aliases1.append(species.create_alias(network.get_reactions_list()[1]))
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        aliases2 = species_list.create_alias(network.get_reactions_list()[1])
        self.assertEqual(len(aliases1), len(aliases2))
        for i in range(len(aliases1)):
            if aliases1[i] is not None or aliases2[i] is not None:
                self.assertEqual(aliases1[i].get_species_id(), aliases2[i].get_species_id())
                self.assertEqual(aliases1[i].get_graphical_object_index(), aliases2[i].get_graphical_object_index())

    def test_species_list_alignment(self):
        """ Test if the species list can be aligned """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        min_y = min([pos[1] for pos in species_list.get_position()])
        species_list.align_to_top()
        self.assertTrue(all([math.isclose(pos[1], min_y, abs_tol=1) for pos in species_list.get_position()]))
        network.auto_layout(reset_fixed_position_elements=True)
        max_y = max([pos[1] for pos in species_list.get_position()])
        species_list.align_to_bottom()
        self.assertTrue(all([math.isclose(pos[1], max_y, abs_tol=1) for pos in species_list.get_position()]))
        network.auto_layout(reset_fixed_position_elements=True)
        min_y = min([pos[1] for pos in species_list.get_position()])
        max_y = max([pos[1] for pos in species_list.get_position()])
        center_y = (min_y + max_y) / 2
        species_list.align_to_vertical_center()
        self.assertTrue(all([math.isclose(pos[1], center_y, abs_tol=1) for pos in species_list.get_position()]))
        network.auto_layout(reset_fixed_position_elements=True)
        min_x = min([pos[0] for pos in species_list.get_position()])
        species_list.align_to_left()
        self.assertTrue(all([math.isclose(pos[0], min_x, abs_tol=1) for pos in species_list.get_position()]))
        network.auto_layout(reset_fixed_position_elements=True)
        max_x = max([pos[0] for pos in species_list.get_position()])
        species_list.align_to_right()
        self.assertTrue(all([math.isclose(pos[0], max_x, abs_tol=1) for pos in species_list.get_position()]))
        network.auto_layout(reset_fixed_position_elements=True)
        min_x = min([pos[0] for pos in species_list.get_position()])
        max_x = max([pos[0] for pos in species_list.get_position()])
        center_x = (min_x + max_x) / 2
        species_list.align_to_horizontal_center()
        self.assertTrue(all([math.isclose(pos[0], center_x, abs_tol=1) for pos in species_list.get_position()]))
        network.auto_layout(reset_fixed_position_elements=True)
        min_x = min([pos[0] for pos in species_list.get_position()])
        max_x = max([pos[0] for pos in species_list.get_position()])
        min_y = min([pos[1] for pos in species_list.get_position()])
        max_y = max([pos[1] for pos in species_list.get_position()])
        center_x = (min_x + max_x) / 2
        center_y = (min_y + max_y) / 2
        radius = len(species_list) * 50 # this is the radius of the circle in sbmlnetwork main code
        species_list.align_to_circle()
        num_species = len(species_list)
        for i in range(num_species):
            angle = 2 * math.pi * i / num_species
            x = center_x + radius * math.cos(angle)
            y = center_y + radius * math.sin(angle)
            self.assertAlmostEqual(species_list[i].get_position()[0], x, delta=1)
            self.assertAlmostEqual(species_list[i].get_position()[1], y, delta=1)

    def test_species_list_move(self):
        """ Test if the species list can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        positions = species_list.get_position()
        connected_curves_ends = species_list.get_connected_curves().get_end()
        species_list.move((100, 100), move_connected_curves=True)
        for i in range(len(species_list)):
            self.assertAlmostEqual(species_list[i].get_position()[0], positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(species_list[i].get_position()[1], positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(species_list.get_connected_curves()[i].get_end()[0], connected_curves_ends[i][0] + 100, delta=1)
            self.assertAlmostEqual(species_list.get_connected_curves()[i].get_end()[1], connected_curves_ends[i][1] + 100, delta=1)
        positions = species_list.get_position()
        connected_curves_ends = species_list.get_connected_curves().get_end()
        species_list.move((100, 100), move_connected_curves=False)
        for i in range(len(species_list)):
            self.assertAlmostEqual(species_list[i].get_position()[0], positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(species_list[i].get_position()[1], positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(species_list.get_connected_curves()[i].get_end()[0], connected_curves_ends[i][0], delta=1)
            self.assertAlmostEqual(species_list.get_connected_curves()[i].get_end()[1], connected_curves_ends[i][1], delta=1)

    def test_reaction_list_reaction_id(self):
        """ Test if the reaction ids can be retrieved from the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        reaction_ids1 = [reaction.get_reaction_id() for reaction in reaction_list]
        reaction_ids2 = reaction_list.get_reaction_id()
        self.assertEqual(reaction_ids1, reaction_ids2)

    def test_reaction_list_compartment_id(self):
        """ Test if the compartment ids can be retrieved from the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        compartment_ids1 = [reaction.get_compartment_id() for reaction in reaction_list]
        compartment_ids2 = reaction_list.get_compartment_id()
        self.assertEqual(compartment_ids1, compartment_ids2)

    def test_reaction_list_species_list(self):
        """ Test if the species list can be retrieved from the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        species_list1 = []
        for reaction in reaction_list:
            species_list1.extend(reaction.get_species_list())
        species_list2 = reaction_list.get_species_list()
        self.assertEqual(len(species_list1), len(species_list2))
        for i in range(len(species_list1)):
            self.assertEqual(species_list1[i].get_species_id(), species_list2[i].get_species_id())
            self.assertEqual(species_list1[i].get_graphical_object_index(), species_list2[i].get_graphical_object_index())

    def test_reaction_list_species_ids(self):
        """ Test if the species ids can be retrieved from the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        species_ids1 = []
        for reaction in reaction_list:
            species_ids1.extend(reaction.get_species_ids())
        species_ids2 = reaction_list.get_species_ids()
        self.assertEqual(species_ids1, species_ids2)

    def test_reaction_list_curve_list(self):
        """ Test if the curve list can be retrieved from the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        curve_list1 = []
        for reaction in reaction_list:
            curve_list1.extend(reaction.get_curves_list())
        curve_list2 = reaction_list.get_curves_list()
        self.assertEqual(len(curve_list1), len(curve_list2))
        for i in range(len(curve_list1)):
            self.assertEqual(curve_list1[i].get_reaction().get_reaction_id(), curve_list2[i].get_reaction().get_reaction_id())

    def test_reaction_list_empty_species(self):
        """ Test if the empty species can be retrieved from the reaction list """
        self.model1 = '''
                J0: S1 -> S2;
                J1: -> S2;
                '''
        self.r1 = te.loada(self.model1)
        network = sbmlnetwork.load(self.r1.getSBML())
        reaction_list = network.get_reactions_list()
        empty_species_list1 = [reaction.get_empty_species() for reaction in reaction_list]
        empty_species_list2 = reaction_list.get_empty_species()
        self.assertEqual(len(empty_species_list1), len(empty_species_list2))
        for i in range(len(empty_species_list1)):
            if empty_species_list1[i] is not None or empty_species_list2[i] is not None:
                last_underscore_index = empty_species_list1[i].get_species_id().rfind('_')
                reaction_id = empty_species_list1[i].get_species_id()[:last_underscore_index]
                self.assertEqual(reaction_id, reaction_list[i].get_id())
                self.assertTrue(empty_species_list1[i].get_graphical_object_index() == 0)

    def test_reaction_list_create_alias(self):
        """ Test if the alias can be created from the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        aliases1 = []
        for reaction in reaction_list:
            aliases1.append(reaction.create_alias())
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        aliases2 = reaction_list.create_alias()
        self.assertEqual(len(aliases1), len(aliases2))
        for i in range(len(aliases1)):
            if aliases1[i] is not None or aliases2[i] is not None:
                self.assertEqual(aliases1[i].get_reaction_id(), aliases2[i].get_reaction_id())
                self.assertEqual(aliases1[i].get_graphical_object_index(), aliases2[i].get_graphical_object_index())

    def test_reaction_list_assign_species(self):
        """ Test if the species can be assigned to the reaction list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        species_list = network.get_species_list()
        for species in species_list:
            reaction_list.assign_species(species)
            for reaction in reaction_list:
                if species.get_species_id() in reaction.get_species_ids():
                    species_in_reaction = reaction.get_species_list(species.get_species_id())[0]
                    self.assertEqual(species_in_reaction.get_species_id(), species.get_species_id())
                    self.assertEqual(species_in_reaction.get_graphical_object_index(), species.get_graphical_object_index())

    def test_reaction_list_center(self):
        """ Test if the center of the reaction list can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        centers1 = [reaction.get_center() for reaction in reaction_list]
        centers2 = reaction_list.get_center()
        for i in range(len(centers1)):
            self.assertTrue(centers1[i].get_reaction().get_reaction_id() == reaction_list[i].get_reaction_id())

    def test_reaction_list_move(self):
        """ Test if the reaction list can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        positions = reaction_list.get_position()
        reaction_list.move((100, 100))
        for i in range(len(reaction_list)):
            self.assertAlmostEqual(reaction_list[i].get_position()[0], positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(reaction_list[i].get_position()[1], positions[i][1] + 100, delta=1)

    def test_label_list_text(self):
        """ Test if the text can be set for the label list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        species = species_list[0]
        species.add_label("test_label1")
        species.add_label("test_label2")
        label_list = species.get_labels_list()
        label_list.set_text("test_label")
        for label in label_list:
            self.assertEqual(label.get_text(), "test_label")

        species_list.add_label("test_label1")
        species_list.get_labels_list().set_text("test_label2")
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_text(), "test_label2")

    def test_label_list_position(self):
        """ Test if the position can be set for the label list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        species = species_list[0]
        species.add_label("test_label1")
        species.add_label("test_label2")
        label_list = species.get_labels_list()
        label_list.set_position((100, 50))
        for label in label_list:
            self.assertEqual(label.get_position(), (100, 50))

        species_list.add_label("test_label1")
        species_list.get_labels_list().set_position((200, 100))
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_position(), (200, 100))

    def test_label_list_size(self):
        """ Test if the size can be set for the label list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        species = species_list[0]
        species.add_label("test_label1")
        species.add_label("test_label2")
        label_list = species.get_labels_list()
        label_list.set_size((100, 50))
        for label in label_list:
            self.assertEqual(label.get_size(), (100, 50))

        species_list.add_label("test_label1")
        species_list.get_labels_list().set_size((200, 100))
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_size(), (200, 100))

    def test_label_list_align(self):
        """ Test if the label list can be aligned """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        species = species_list[0]
        species.add_label("test_label1")
        species.add_label("test_label2")
        label_list = species.get_labels_list()
        label_list.align_to_top()
        for label in label_list:
            self.assertEqual(label.get_vertical_alignment(), "top")
        label_list.align_to_vertical_center()
        for label in label_list:
            self.assertEqual(label.get_vertical_alignment(), "vertical_center")
        label_list.align_to_bottom()
        for label in label_list:
            self.assertEqual(label.get_vertical_alignment(), "bottom")
        label_list.align_to_baseline()
        for label in label_list:
            self.assertEqual(label.get_vertical_alignment(), "baseline")
        label_list.align_to_left()
        for label in label_list:
            self.assertEqual(label.get_horizontal_alignment(), "left")
        label_list.align_to_horizontal_center()
        for label in label_list:
            self.assertEqual(label.get_horizontal_alignment(), "horizontal_center")
        label_list.align_to_right()
        for label in label_list:
            self.assertEqual(label.get_horizontal_alignment(), "right")

        species_list.add_label("test_label1")
        species_list.get_labels_list().align_to_top()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_vertical_alignment(), "top")
        species_list.get_labels_list().align_to_vertical_center()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_vertical_alignment(), "vertical_center")
        species_list.get_labels_list().align_to_bottom()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_vertical_alignment(), "bottom")
        species_list.get_labels_list().align_to_baseline()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_vertical_alignment(), "baseline")
        species_list.get_labels_list().align_to_left()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_horizontal_alignment(), "left")
        species_list.get_labels_list().align_to_horizontal_center()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_horizontal_alignment(), "horizontal_center")
        species_list.get_labels_list().align_to_right()
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_horizontal_alignment(), "right")

    def test_label_list_font(self):
        """ Test if the font can be set for the label list """
        network = sbmlnetwork.load(self.r.getSBML())
        species_list = network.get_species_list()
        species = species_list[0]
        species.add_label("test_label1")
        species.add_label("test_label2")
        label_list = species.get_labels_list()
        label_list.set_font("Arial")
        for label in label_list:
            self.assertEqual(label.get_font(), "Arial")
        label_list.set_font_size(20)
        for label in label_list:
            self.assertEqual(label.get_font_size(), 20)
        label_list.set_font_color("red")
        for label in label_list:
            self.assertEqual(label.get_font_color(), "red")
        for label in label_list:
            self.assertEqual(label.is_bold(), False)
        label_list.set_bold(True)
        for label in label_list:
            self.assertEqual(label.is_bold(), True)
        for label in label_list:
            self.assertEqual(label.is_italic(), False)
        label_list.set_italic(True)
        for label in label_list:
            self.assertEqual(label.is_italic(), True)

        species_list.add_label("test_label1")
        species_list.get_labels_list().set_font("Arial")
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_font(), "Arial")
        species_list.get_labels_list().set_font_size(20)
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_font_size(), 20)
        species_list.get_labels_list().set_font_color("red")
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.get_font_color(), "red")
        species_list.get_labels_list().set_bold(True)
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.is_bold(), True)
        species_list.get_labels_list().set_italic(True)
        for species in species_list:
            for label in species.get_labels_list():
                self.assertEqual(label.is_italic(), True)

    def test_reaction_center_list(self):
        """ Test if the reaction center list can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        center_reaction_list_1 = reaction_list.get_center().get_reaction()
        center_reaction_list_2 = [reaction.get_center().get_reaction() for reaction in reaction_list]
        self.assertEqual(len(center_reaction_list_1), len(center_reaction_list_2))
        for i in range(len(center_reaction_list_1)):
            self.assertEqual(center_reaction_list_1[i].get_reaction_id(), center_reaction_list_2[i].get_reaction_id())
            self.assertEqual(center_reaction_list_1[i].get_graphical_object_index(), center_reaction_list_2[i].get_graphical_object_index())

    def test_reaction_center_list_switch(self):
        """ Test if the reaction center list can be switched """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        reaction_list.get_center().switch_to_shapes()
        is_curve1 = reaction_list.get_center().is_curve()
        is_curve2 = [reaction.get_center().is_curve() for reaction in reaction_list]
        self.assertEqual(is_curve1, is_curve2)
        is_shapes1 = reaction_list.get_center().is_shapes()
        is_shapes2 = [reaction.get_center().is_shapes() for reaction in reaction_list]
        self.assertEqual(is_shapes1, is_shapes2)
        reaction_list.get_center().switch_to_curve()
        is_curve1 = reaction_list.get_center().is_curve()
        is_curve2 = [reaction.get_center().is_curve() for reaction in reaction_list]
        self.assertEqual(is_curve1, is_curve2)
        is_shapes1 = reaction_list.get_center().is_shapes()
        is_shapes2 = [reaction.get_center().is_shapes() for reaction in reaction_list]
        self.assertEqual(is_shapes1, is_shapes2)

    def test_reaction_center_list_curve(self):
        """ Test if the reaction center curve list can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        reaction_list.get_center().switch_to_curve()
        curve_list = reaction_list.get_center().get_curve()
        for i in range(len(curve_list)):
            self.assertEqual(curve_list[i].get_reaction().get_reaction_id(), reaction_list[i].get_reaction_id())

    def test_reaction_center_list_shapes(self):
        """ Test if the reaction center shapes list can be retrieved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        reaction_list.get_center().switch_to_shapes()
        shapes_list1 = reaction_list.get_center().get_shapes_list()
        shapes_list2 = []
        for reaction in reaction_list:
            shapes_list2.append(reaction.get_center().get_shapes_list())
        self.assertEqual(len(shapes_list1), len(shapes_list2))
        for i in range(len(shapes_list1)):
            self.assertEqual(len(shapes_list1[i]), len(shapes_list2[i]))
            for j in range(len(shapes_list1[i])):
                self.assertEqual(shapes_list1[i][j].get_element_id(), shapes_list2[i][j].get_element_id())
                self.assertEqual(shapes_list1[i][j].get_graphical_object_index(), shapes_list2[i][j].get_graphical_object_index())

    def test_curve_list_reaction(self):
        """ Test if the reaction can be retrieved from the curve list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            reaction_list = curve_list.get_reaction()
            for i in range(len(reaction_list)):
                self.assertEqual(reaction_list[i].get_reaction_id(), reaction.get_reaction_id())
                self.assertEqual(reaction_list[i].get_graphical_object_index(), reaction.get_graphical_object_index())

    def test_curve_list_species(self):
        """ Test if the species can be retrieved from the curve list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            species_list = curve_list.get_species()
            species_ids = reaction.get_species_ids()
            for i in range(len(species_list)):
                self.assertEqual(species_list[i].get_species_id(), species_ids[i])

    def test_curve_list_color(self):
        """ Test if the color can be set for the curve list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            curve_list.set_color("red")
            for curve in curve_list:
                self.assertEqual(curve.get_color(), "red")

    def test_curve_list_thickness(self):
        """ Test if the thickness can be set for the curve list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            curve_list.set_thickness(5)
            for curve in curve_list:
                self.assertEqual(curve.get_thickness(), 5)

    def test_curve_list_start_end(self):
        """ Test if the start and end can be set for the curve list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            curve_list.set_start((100, 100))
            curve_list.set_end((200, 200))
            for curve in curve_list:
                self.assertEqual(curve.get_start(), (100, 100))
                self.assertEqual(curve.get_end(), (200, 200))

    def test_curve_list_segment(self):
        """ Test if the segment can be set for the curve list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            self.assertEqual(len(curve_list.get_segment()), len(curve_list))
            curve_list.add_segment((100, 100), (200, 200), (150, 150), (250, 250))
            self.assertEqual(len(curve_list.get_segment()), len(curve_list))
            curve_list.remove_segment(0)
            self.assertEqual(len(curve_list.get_segment()), len(curve_list))
            start_points = curve_list.get_start()
            for start_point in start_points:
                self.assertEqual(start_point, (100, 100))
            end_points = curve_list.get_segment().get_end()
            for end_point in end_points:
                self.assertEqual(end_point, (200, 200))
            start_slopes = curve_list.get_start_slope()
            for start_slope in start_slopes:
                self.assertEqual(start_slope, (150 - 100) / (150 - 100))
            end_slopes = curve_list.get_end_slope()
            for end_slope in end_slopes:
                self.assertEqual(end_slope, (250 - 200) / (250 - 200))

    def test_curve_list_move(self):
        """ Test if the curve list can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        curve_list = reaction_list[0].get_curves_list()
        start_positions = curve_list.get_start()
        end_positions = curve_list.get_end()
        curve_list.move((100, 100))
        for i in range(len(curve_list)):
            self.assertAlmostEqual(curve_list[i].get_start()[0], start_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(curve_list[i].get_start()[1], start_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(curve_list[i].get_end()[0], end_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(curve_list[i].get_end()[1], end_positions[i][1] + 100, delta=1)
        start_positions = curve_list.get_start()
        end_positions = curve_list.get_end()
        curve_list.move_start((100, 100))
        for i in range(len(curve_list)):
            self.assertAlmostEqual(curve_list[i].get_start()[0], start_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(curve_list[i].get_start()[1], start_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(curve_list[i].get_end()[0], end_positions[i][0], delta=1)
            self.assertAlmostEqual(curve_list[i].get_end()[1], end_positions[i][1], delta=1)
        start_positions = curve_list.get_start()
        end_positions = curve_list.get_end()
        curve_list.move_end((100, 100))
        for i in range(len(curve_list)):
            self.assertAlmostEqual(curve_list[i].get_start()[0], start_positions[i][0], delta=1)
            self.assertAlmostEqual(curve_list[i].get_start()[1], start_positions[i][1], delta=1)
            self.assertAlmostEqual(curve_list[i].get_end()[0], end_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(curve_list[i].get_end()[1], end_positions[i][1] + 100, delta=1)

    def test_curve_list_hide_show(self):
        """ Test if the curve can be hidden and shown """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        curve_list = reaction_list[0].get_curves_list()
        curve_list.hide()
        for curve in curve_list:
            self.assertTrue(curve.is_hidden())
        curve_list.show()
        for curve in curve_list:
            self.assertFalse(curve.is_hidden())

    def test_curve_segment_list_points(self):
        """ Test if the points can be set for the curve segment list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            curve_list = reaction.get_curves_list()
            curve_list.add_segment((100, 100), (200, 200), (150, 150), (250, 250))
            curve_list.add_segment((200, 200), (300, 300), (250, 250), (350, 350))
            for curve in curve_list:
                segment_list = curve.get_segments_list()
                segment_list.set_start((300, 300))
                segment_list.set_end((400, 400))
                segment_list.set_control_point_1((350, 350))
                segment_list.set_control_point_2((450, 450))
                start_points = segment_list.get_start()
                for start_point in start_points:
                    self.assertEqual(start_point, (300, 300))
                end_points = segment_list.get_end()
                for end_point in end_points:
                    self.assertEqual(end_point, (400, 400))
                control_points_1 = segment_list.get_control_point_1()
                for control_point_1 in control_points_1:
                    self.assertEqual(control_point_1, (350, 350))
                control_points_2 = segment_list.get_control_point_2()
                for control_point_2 in control_points_2:
                    self.assertEqual(control_point_2, (450, 450))

    def test_curve_segment_list_move(self):
        """ Test if the curve segment list can be moved """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        curve = reaction_list[0].get_curves_list()[0]
        segment_list = curve.get_segments_list()
        start_positions = segment_list.get_start()
        end_positions = segment_list.get_end()
        control_point_1_positions = segment_list.get_control_point_1()
        control_point_2_positions = segment_list.get_control_point_2()
        segment_list.move((100, 100))
        for i in range(len(segment_list)):
            self.assertAlmostEqual(segment_list[i].get_start()[0], start_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_start()[1], start_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_end()[0], end_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_end()[1], end_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_1()[0], control_point_1_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_1()[1], control_point_1_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_2()[0], control_point_2_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_2()[1], control_point_2_positions[i][1] + 100, delta=1)
        start_positions = segment_list.get_start()
        end_positions = segment_list.get_end()
        control_point_1_positions = segment_list.get_control_point_1()
        control_point_2_positions = segment_list.get_control_point_2()
        segment_list.move_start((100, 100))
        for i in range(len(segment_list)):
            self.assertAlmostEqual(segment_list[i].get_start()[0], start_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_start()[1], start_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_end()[0], end_positions[i][0], delta=1)
            self.assertAlmostEqual(segment_list[i].get_end()[1], end_positions[i][1], delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_1()[0], control_point_1_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_1()[1], control_point_1_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_2()[0], control_point_2_positions[i][0], delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_2()[1], control_point_2_positions[i][1], delta=1)
        start_positions = segment_list.get_start()
        end_positions = segment_list.get_end()
        control_point_1_positions = segment_list.get_control_point_1()
        control_point_2_positions = segment_list.get_control_point_2()
        segment_list.move_end((100, 100))
        for i in range(len(segment_list)):
            self.assertAlmostEqual(segment_list[i].get_start()[0], start_positions[i][0], delta=1)
            self.assertAlmostEqual(segment_list[i].get_start()[1], start_positions[i][1], delta=1)
            self.assertAlmostEqual(segment_list[i].get_end()[0], end_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_end()[1], end_positions[i][1] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_1()[0], control_point_1_positions[i][0], delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_1()[1], control_point_1_positions[i][1], delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_2()[0], control_point_2_positions[i][0] + 100, delta=1)
            self.assertAlmostEqual(segment_list[i].get_control_point_2()[1], control_point_2_positions[i][1] + 100, delta=1)

    def test_arrow_head_list_relative_position(self):
        """ Test if the relative position can be set for the arrow head list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            arrow_head_list = reaction.get_curves_list().get_arrow_head()
            arrow_head_list.set_relative_position((0.5, 0.5))
            for arrow_head in arrow_head_list:
                self.assertEqual(arrow_head.get_relative_position(), (0.5, 0.5))

    def test_arrow_head_list_size(self):
        """ Test if the size can be set for the arrow head list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            arrow_head_list = reaction.get_curves_list().get_arrow_head()
            arrow_head_list.set_size((10, 10))
            for arrow_head in arrow_head_list:
                self.assertEqual(arrow_head.get_size(), (10, 10))

    def test_arrow_head_list_shape(self):
        """ Test if the shape can be set for the arrow head list """
        network = sbmlnetwork.load(self.r.getSBML())
        reaction_list = network.get_reactions_list()
        for reaction in reaction_list:
            arrow_head_list = reaction.get_curves_list().get_arrow_head()
            arrow_head_list.set_shape("rectangle")
            arrow_head_list.add_shape("hexagon")
            for arrow_head in arrow_head_list:
                shapes_list = arrow_head.get_shapes_list()
                self.assertEqual(len(shapes_list), 2)
                for shape in shapes_list:
                    self.assertEqual(shape.get_element_id(), reaction.get_reaction_id())
                    self.assertEqual(shape.get_graphical_object_index(), reaction.get_graphical_object_index())
                arrow_head.remove_shape(shapes_list[0])
                self.assertEqual(len(arrow_head.get_shapes_list()), 1)
                self.assertEqual(arrow_head.get_shape().get_type(), "hexagon")


if __name__ == '__main__':
    unittest.main()
