import unittest
import sys
import os
import math

sys.path.append('../src/sbmlnetwork/')
import sbmlnetwork


class TestSBMLNetwork(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.networks = []
        files = os.listdir(os.path.dirname(os.path.abspath(__file__)) + '/models')
        for file in files:
            if file.endswith('.xml'):
                cls.networks.append(sbmlnetwork.load(os.path.dirname(os.path.abspath(__file__)) + '/models/' + file))

    def test_layout_render_info(self):
        for network in self.networks:
            self.assertGreaterEqual(network.getNumLayouts(), 1)
            self.assertGreaterEqual(network.getNumGlobalRenderInformation() + network.getNumLocalRenderInformation(), 1)

    def test_compartments_list(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_compartment_ids = network.getListOfCompartmentIds()
                for compartment_id in list_of_compartment_ids:
                    self.assertEqual(True, bool(network.isCompartmentGlyph(compartment_id)))

    def test_species_list(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual(True, bool(network.isSpeciesGlyph(species_id)))

    def test_reactions_list(self):
        for network in self.networks:
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual(True, bool(network.isReactionGlyph(reaction_id)))

    def test_displayed_texts(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual(species_id, network.getText(species_id))

    def test_move_species(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                horizontal_displacement = 10.0
                vertical_displacement = 10.0
                for species_id in list_of_species_ids:
                    # x
                    position_x = network.getX(species_id)
                    network.setX(species_id, position_x + horizontal_displacement)
                    self.assertAlmostEqual(position_x + horizontal_displacement, network.getX(species_id), 1)

                    # y
                    position_y = network.getY(species_id)
                    network.setY(species_id, position_y + vertical_displacement)
                    self.assertAlmostEqual(position_y + vertical_displacement, network.getY(species_id), 1)

    def test_move_species_with_calling_position_functions(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                horizontal_displacement = 10.0
                vertical_displacement = 10.0
                for species_id in list_of_species_ids:
                    position = network.getPosition(species_id)
                    network.setPosition(species_id, position[0] + horizontal_displacement, position[1] + vertical_displacement)
                    self.assertAlmostEqual(position[0] + horizontal_displacement, network.getX(species_id), 1)
                    self.assertAlmostEqual(position[1] + vertical_displacement, network.getY(species_id), 1)

    def disabled_test_set_species_dimensions(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            width_extension = 10.0
            height_extension = 10.0
            for species_id in list_of_species_ids:
                # width
                width = network.getWidth(species_id)
                network.setWidth(species_id, width + width_extension)
                self.assertAlmostEqual(width + width_extension, network.getWidth(species_id), 1)

                # height
                height = network.getHeight(species_id)
                network.setHeight(species_id, height + height_extension)
                self.assertAlmostEqual(height + height_extension, network.getHeight(species_id), 1)

    def test_elements_are_bounded_by_compartment(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                for species_id in list_of_species_ids:
                    self._check_species_is_bounded_by_its_compartment(network, species_id)
                list_of_reaction_ids = network.getListOfReactionIds()
                for reaction_id in list_of_reaction_ids:
                    self._check_reaction_is_bounded_by_its_compartment(network, reaction_id)

    def test_align_left(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                x_min = self._get_min_position_x(network, list_of_species_ids)
                network.align(list_of_species_ids, 'left')
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(x_min, network.getX(species_id), 1)

    def test_align_right(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                x_max = self._get_max_position_x(network, list_of_species_ids)
                network.align(list_of_species_ids, 'right')
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(x_max, network.getX(species_id), 1)

    def test_align_center(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                x_min = self._get_min_position_x(network, list_of_species_ids)
                x_max = self._get_max_position_x(network, list_of_species_ids)
                center_x = 0.5 * (x_min + x_max)
                network.align(list_of_species_ids, 'center')
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(center_x, network.getX(species_id), 1)

    def test_align_top(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                y_min = self._get_min_position_y(network, list_of_species_ids)
                network.align(list_of_species_ids, 'top')
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(y_min, network.getY(species_id), 1)

    def test_align_bottom(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                y_max = self._get_max_position_y(network, list_of_species_ids)
                network.align(list_of_species_ids, 'bottom')
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(y_max, network.getY(species_id), 1)

    def test_align_middle(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                y_min = self._get_min_position_y(network, list_of_species_ids)
                y_max = self._get_max_position_y(network, list_of_species_ids)
                middle_y = 0.5 * (y_min + y_max)
                network.align(list_of_species_ids, 'middle')
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(middle_y, network.getY(species_id), 1)

    def test_align_circular(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_species_ids = network.getListOfSpeciesIds()
                network.align(list_of_species_ids, 'circular')
                radius = self._get_radius_of_positions(network, list_of_species_ids)
                center_x, center_y = self._get_center_of_positions(network, list_of_species_ids)
                self.assertAlmostEqual(radius, 50.0 * len(list_of_species_ids), 1)
                for species_id in list_of_species_ids:
                    self.assertAlmostEqual(self._distance(center_x, center_y, network.getX(species_id),
                                                          network.getY(species_id)), radius, 1)

    def test_curves_direction_towards_species_center(self):
        for network in self.networks:
            if network.layout_is_added:
                network.autolayout()
                list_of_reaction_ids = network.getListOfReactionIds()
                for reaction_id in list_of_reaction_ids:
                    self._check_curves_direction_towards_species_center(network, reaction_id)

    def test_set_background_color(self):
        for network in self.networks:
            if network.render_is_added:
                network.setBackgroundColor('white')
                self.assertEqual('white', network.getBackgroundColor())

    def disabled_test_list_of_colors(self):
        for network in self.networks:
            list_of_colors = network.getListOfColors()
            for color in list_of_colors:
                network.setBackgroundColor(color)
                self.assertEqual(color, network.getBackgroundColor())

    def test_set_border_color(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setBorderColor(species_id, 'blue')
                self.assertEqual('blue', network.getBorderColor(species_id))
            list_of_line_ending_ids = network.getListOfLineEndingIds()
            for line_ending_id in list_of_line_ending_ids:
                network.setLineEndingBorderColor(line_ending_id, 'blue')
                self.assertEqual('blue', network.getLineEndingBorderColor(line_ending_id))

    def test_set_border_colors(self):
        for network in self.networks:
            network.setSpeciesBorderColors('orange')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('orange', network.getBorderColor(species_id))

    def test_set_line_color(self):
        for network in self.networks:
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setLineColor(reaction_id, 'blue')
                self.assertEqual('blue', network.getLineColor(reaction_id))

    def test_set_line_colors(self):
        for network in self.networks:
            network.setReactionsLineColors('orange')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('orange', network.getLineColor(reaction_id))

    def test_set_border_width(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setBorderWidth(species_id, 4.0)
                self.assertEqual(4.0, network.getBorderWidth(species_id))
            list_of_line_ending_ids = network.getListOfLineEndingIds()
            for line_ending_id in list_of_line_ending_ids:
                network.setLineEndingBorderWidth(line_ending_id, 4.0)
                self.assertEqual(4.0, network.getLineEndingBorderWidth(line_ending_id))

    def test_set_border_widths(self):
        for network in self.networks:
            network.setSpeciesBorderWidths(4.0)
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual(4.0, network.getBorderWidth(species_id))

    def test_set_line_width(self):
        for network in self.networks:
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setLineWidth(reaction_id, 4.0)
                self.assertEqual(4.0, network.getLineWidth(reaction_id))

    def test_set_line_widths(self):
        for network in self.networks:
            network.setReactionsLineWidths(4.0)
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual(4.0, network.getLineWidth(reaction_id))

    def test_set_fill_color(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setFillColor(species_id, 'yellow')
                self.assertEqual('yellow', network.getFillColor(species_id))
            list_of_line_ending_ids = network.getListOfLineEndingIds()
            for line_ending_id in list_of_line_ending_ids:
                network.setLineEndingFillColor(line_ending_id, 'yellow')
                self.assertEqual('yellow', network.getLineEndingFillColor(line_ending_id))

    def test_set_fill_colors(self):
        for network in self.networks:
            network.setSpeciesFillColors('yellow')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('yellow', network.getFillColor(species_id))

    def test_set_font_color(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setFontColor(species_id, 'red')
                self.assertEqual('red', network.getFontColor(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setFontColor(reaction_id, 'red')
                self.assertEqual('red', network.getFontColor(reaction_id))

    def test_set_font_colors(self):
        for network in self.networks:
            network.setSpeciesFontColors('purple')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('purple', network.getFontColor(species_id))
            network.setReactionsFontColors('purple')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('purple', network.getFontColor(reaction_id))

    def test_set_font_size(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setFontSize(species_id, 9)
                self.assertEqual(9, network.getFontSize(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setFontSize(reaction_id, 9)
                self.assertEqual(9, network.getFontSize(reaction_id))

    def test_set_font_sizes(self):
        for network in self.networks:
            network.setSpeciesFontSizes(17)
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual(17, network.getFontSize(species_id))
            network.setReactionsFontSizes(17)
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual(17, network.getFontSize(reaction_id))

    def test_set_font_family(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setFontFamily(species_id, 'Arial')
                self.assertEqual('Arial', network.getFontFamily(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setFontFamily(reaction_id, 'Arial')
                self.assertEqual('Arial', network.getFontFamily(reaction_id))

    def test_set_font_families(self):
        for network in self.networks:
            network.setSpeciesFontFamilies('Times New Roman')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('Times New Roman', network.getFontFamily(species_id))
            network.setReactionsFontFamilies('Times New Roman')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('Times New Roman', network.getFontFamily(reaction_id))

    def test_set_font_style(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setFontStyle(species_id, 'italic')
                self.assertEqual('italic', network.getFontStyle(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setFontStyle(reaction_id, 'italic')
                self.assertEqual('italic', network.getFontStyle(reaction_id))

    def test_set_font_styles(self):
        for network in self.networks:
            network.setSpeciesFontStyles('normal')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('normal', network.getFontStyle(species_id))
            network.setReactionsFontStyles('normal')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('normal', network.getFontStyle(reaction_id))

    def test_set_font_weight(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setFontWeight(species_id, 'bold')
                self.assertEqual('bold', network.getFontWeight(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setFontWeight(reaction_id, 'bold')
                self.assertEqual('bold', network.getFontWeight(reaction_id))

    def test_set_font_weights(self):
        for network in self.networks:
            network.setSpeciesFontWeights('normal')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('normal', network.getFontWeight(species_id))
            network.setReactionsFontWeights('normal')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('normal', network.getFontWeight(reaction_id))

    def test_set_text_horizontal_alignment(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setTextHorizontalAlignment(species_id, 'start')
                print(network.getTextHorizontalAlignment(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setTextHorizontalAlignment(reaction_id, 'start')
                print(network.getTextHorizontalAlignment(reaction_id))

    def test_set_text_horizontal_alignments(self):
        for network in self.networks:
            network.setSpeciesTextHorizontalAlignments('end')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('end', network.getTextHorizontalAlignment(species_id))
            network.setReactionsTextHorizontalAlignments('end')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('end', network.getTextHorizontalAlignment(reaction_id))

    def test_set_text_vertical_alignment(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setTextVerticalAlignment(species_id, 'top')
                self.assertEqual('top', network.getTextVerticalAlignment(species_id))
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                network.setTextVerticalAlignment(reaction_id, 'top')
                self.assertEqual('top', network.getTextVerticalAlignment(reaction_id))

    def test_set_text_vertical_alignments(self):
        for network in self.networks:
            network.setSpeciesTextVerticalAlignments('bottom')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual('bottom', network.getTextVerticalAlignment(species_id))
            network.setReactionsTextVerticalAlignments('bottom')
            list_of_reaction_ids = network.getListOfReactionIds()
            for reaction_id in list_of_reaction_ids:
                self.assertEqual('bottom', network.getTextVerticalAlignment(reaction_id))

    def test_set_geometric_shape(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setGeometricShape(species_id, 'ellipse')
                self.assertEqual(True, bool(network.isEllipse(species_id)))

    def test_set_geometric_shapes(self):
        for network in self.networks:
            network.setSpeciesGeometricShapes('rectangle')
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertEqual(True, bool(network.isRectangle(species_id)))

    def test_move_rectangle_geometric_shape(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self._check_move_rectangle_geometric_shape(network, species_id)

    def test_move_rectangle_geometric_shapes(self):
        for network in self.networks:
            x = 10.0
            y = 15.0
            network.setSpeciesGeometricShapes('rectangle')
            network.setSpeciesGeometricShapeXs(x)
            network.setSpeciesGeometricShapeYs(y)
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertAlmostEqual(x, network.getGeometricShapeX(species_id), 0.1)
                self.assertAlmostEqual(y, network.getGeometricShapeY(species_id), 0.1)

    def test_set_dimensions_of_rectangle_geometric_shape(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self._check_set_dimensions_of_rectangle_geometric_shape(network, species_id)

    def test_set_dimensions_of_rectangle_geometric_shapes(self):
        for network in self.networks:
            width = 10.0
            height = 15.0
            network.setSpeciesGeometricShapes('rectangle')
            network.setSpeciesGeometricShapeWidths(width)
            network.setSpeciesGeometricShapeHeights(height)
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertAlmostEqual(width, network.getGeometricShapeWidth(species_id), 0.1)
                self.assertAlmostEqual(height, network.getGeometricShapeHeight(species_id), 0.1)

    def test_move_ellipse_geometric_shape(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setGeometricShape(species_id, 'ellipse')
                self._check_move_ellipse_geometric_shape(network, species_id)

    def test_move_ellipse_geometric_shapes(self):
        for network in self.networks:
            center_x = 5.0
            center_y = 7.5
            network.setSpeciesGeometricShapes('ellipse')
            network.setSpeciesGeometricShapeCenterXs(center_x)
            network.setSpeciesGeometricShapeCenterYs(center_y)
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertAlmostEqual(center_x, network.getGeometricShapeCenterX(species_id), 0.1)
                self.assertAlmostEqual(center_y, network.getGeometricShapeCenterY(species_id), 0.1)

    def test_set_dimensions_of_ellipse_geometric_shape(self):
        for network in self.networks:
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                network.setGeometricShape(species_id, 'ellipse')
                self._check_set_dimensions_of_ellipse_geometric_shape(network, species_id)

    def test_set_dimensions_of_ellipse_geometric_shapes(self):
        for network in self.networks:
            radius_x = 5.0
            radius_y = 7.5
            network.setSpeciesGeometricShapes('ellipse')
            network.setSpeciesGeometricShapeRadiusXs(radius_x)
            network.setSpeciesGeometricShapeRadiusYs(radius_y)
            list_of_species_ids = network.getListOfSpeciesIds()
            for species_id in list_of_species_ids:
                self.assertAlmostEqual(radius_x, network.getGeometricShapeRadiusX(species_id), 0.1)
                self.assertAlmostEqual(radius_y, network.getGeometricShapeRadiusY(species_id), 0.1)

    def _check_species_is_bounded_by_its_compartment(self, network, species_id):
        compartment_id = self._get_associated_compartment_id(network, species_id)
        self.assertGreater(network.getX(species_id), network.getX(compartment_id))
        self.assertLess(network.getX(species_id) + network.getWidth(species_id),
                        network.getX(compartment_id) + network.getWidth(
                            compartment_id))
        self.assertGreater(network.getY(species_id), network.getY(compartment_id))
        self.assertLess(network.getY(species_id) + network.getHeight(species_id),
                        network.getY(compartment_id) + network.getHeight(
                            compartment_id))

    def _check_reaction_is_bounded_by_its_compartment(self, network, reaction_id):
        compartment_id = self._get_associated_compartment_id(network, reaction_id)
        self.assertGreater(network.getCurveSegmentStartPointX(reaction_id),
                           network.getX(compartment_id))
        self.assertLess(network.getCurveSegmentStartPointX(reaction_id),
                        network.getX(compartment_id) + network.getWidth(
                            compartment_id))
        self.assertGreater(network.getCurveSegmentStartPointY(reaction_id),
                           network.getY(compartment_id))
        self.assertLess(network.getCurveSegmentStartPointY(reaction_id),
                        network.getY(compartment_id) + network.getHeight(
                            compartment_id))
        self.assertGreater(network.getCurveSegmentEndPointX(reaction_id),
                           network.getX(compartment_id))
        self.assertLess(network.getCurveSegmentEndPointX(reaction_id),
                        network.getX(compartment_id) + network.getWidth(
                            compartment_id))
        self.assertGreater(network.getCurveSegmentEndPointY(reaction_id),
                           network.getY(compartment_id))
        self.assertLess(network.getCurveSegmentEndPointY(reaction_id),
                        network.getY(compartment_id) + network.getHeight(
                            compartment_id))
        for species_reference_index in range(network.getNumSpeciesReferenceGlyphs(reaction_id)):
            self._check_species_reference_is_bounded_by_its_compartment(network, reaction_id, species_reference_index)

    def _check_species_reference_is_bounded_by_its_compartment(self, network,reaction_id, species_reference_index):
        compartment_id = self._get_associated_compartment_id(network, reaction_id)
        self.assertGreater(network.getSpeciesReferenceCurveSegmentStartPointX(reaction_id,
                                                                                   species_reference_glyph_index=species_reference_index),
                           network.getX(compartment_id))
        self.assertLess(network.getSpeciesReferenceCurveSegmentStartPointX(reaction_id,
                                                                                species_reference_glyph_index=species_reference_index),
                        network.getX(compartment_id) + network.getWidth(
                            compartment_id))
        self.assertGreater(network.getSpeciesReferenceCurveSegmentStartPointY(reaction_id,
                                                                                   species_reference_glyph_index=species_reference_index),
                           network.getY(compartment_id))
        self.assertLess(network.getSpeciesReferenceCurveSegmentStartPointY(reaction_id,
                                                                                species_reference_glyph_index=species_reference_index),
                        network.getY(compartment_id) + network.getHeight(
                            compartment_id))

    def _check_curves_direction_towards_species_center(self, network, reaction_id):
        for species_reference_index in range(network.getNumSpeciesReferenceGlyphs(reaction_id)):
            self._check_curve_direction_towards_species_center(network, reaction_id, species_reference_index)

    def _check_curve_direction_towards_species_center(self, network, reaction_id, species_reference_index):
        species_id = network.getSpeciesReferenceSpeciesId(reaction_id, species_reference_index)
        species_center_x = network.getX(species_id) + 0.5 * network.getWidth(species_id)
        species_center_y = network.getY(species_id) + 0.5 * network.getHeight(species_id)
        if network.getSpeciesReferenceRole(reaction_id, species_reference_index) in ['product', 'side product']:
            curve_control_point_x = network.getSpeciesReferenceCurveSegmentBasePoint2X(reaction_id,
                                                                                       species_reference_index)
            curve_control_point_y = network.getSpeciesReferenceCurveSegmentBasePoint2Y(reaction_id,
                                                                                       species_reference_index)
            curve_species_point_x = network.getSpeciesReferenceCurveSegmentEndPointX(reaction_id,
                                                                                     species_reference_index)
            curve_species_point_y = network.getSpeciesReferenceCurveSegmentEndPointY(reaction_id,
                                                                                     species_reference_index)
        else:
            curve_control_point_x = network.getSpeciesReferenceCurveSegmentBasePoint1X(reaction_id,
                                                                                       species_reference_index)
            curve_control_point_y = network.getSpeciesReferenceCurveSegmentBasePoint1Y(reaction_id,
                                                                                       species_reference_index)
            curve_species_point_x = network.getSpeciesReferenceCurveSegmentStartPointX(reaction_id,
                                                                                       species_reference_index)
            curve_species_point_y = network.getSpeciesReferenceCurveSegmentStartPointY(reaction_id,

                                                                                       species_reference_index)
        if abs(curve_species_point_x - curve_control_point_x) > 1e-6:
            slope1 = (curve_species_point_y - curve_control_point_y) / (curve_species_point_x - curve_control_point_x)
        else:
            slope1 = 0.0
        if abs(species_center_x - curve_species_point_x) > 1e-6:
            slope2 = (species_center_y - curve_species_point_y) / (species_center_x - curve_species_point_x)
        else:
            slope2 = 0.0
        self.assertAlmostEqual(slope1, slope2, 1)

    @staticmethod
    def _get_min_position_x(network, list_of_entity_ids):
        x_min = float('inf')
        for entity_id in list_of_entity_ids:
            x_min = min(x_min, network.getX(entity_id))
        return x_min

    @staticmethod
    def _get_min_position_y(network, list_of_entity_ids):
        y_min = float('inf')
        for entity_id in list_of_entity_ids:
            y_min = min(y_min, network.getY(entity_id))
        return y_min

    @staticmethod
    def _get_max_position_x(network, list_of_entity_ids):
        x_max = float('-inf')
        for entity_id in list_of_entity_ids:
            x_max = max(x_max, network.getX(entity_id))
        return x_max

    @staticmethod
    def _get_max_position_y(network, list_of_entity_ids):
        y_max = float('-inf')
        for entity_id in list_of_entity_ids:
            y_max = max(y_max, network.getY(entity_id))
        return y_max

    def _get_radius_of_positions(self, network, list_of_entity_ids):
        return 0.5 * max((self._get_max_position_x(network, list_of_entity_ids) - self._get_min_position_x(network, list_of_entity_ids)),
                         (self._get_max_position_y(network, list_of_entity_ids) - self._get_min_position_y(network, list_of_entity_ids)))

    def _get_center_of_positions(self, network, list_of_entity_ids):
        return 0.5 * (self._get_max_position_x(network, list_of_entity_ids) + self._get_min_position_x(network, list_of_entity_ids)), \
               0.5 * (self._get_max_position_y(network, list_of_entity_ids) + self._get_min_position_y(network, list_of_entity_ids))

    @staticmethod
    def _distance(x1, y1, x2, y2):
        return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

    def _check_move_rectangle_geometric_shape(self, network, entity_id):
        horizontal_displacement = 10.0
        vertical_displacement = 10.0
        network.setGeometricShape(entity_id, 'rectangle')
        # x
        geometric_shape_x = network.getGeometricShapeX(entity_id)
        network.setGeometricShapeX(entity_id, geometric_shape_x + horizontal_displacement)
        self.assertAlmostEqual(geometric_shape_x + horizontal_displacement, network.getGeometricShapeX(entity_id), 1)
        # y
        geometric_shape_y = network.getGeometricShapeY(entity_id)
        network.setGeometricShapeY(entity_id, geometric_shape_y + vertical_displacement)
        self.assertAlmostEqual(geometric_shape_y + vertical_displacement, network.getGeometricShapeY(entity_id), 1)

    def _check_move_ellipse_geometric_shape(self, network, entity_id):
        center_x_displacement = 5.0
        center_y_displacement = 5.0
        network.setGeometricShape(entity_id, 'ellipse')
        # center x
        geometric_shape_center_x = network.getGeometricShapeCenterX(entity_id)
        network.setGeometricShapeCenterX(entity_id, geometric_shape_center_x + center_x_displacement)
        self.assertAlmostEqual(geometric_shape_center_x + center_x_displacement, network.getGeometricShapeCenterX(entity_id), 1)
        # center y
        geometric_shape_center_y = network.getGeometricShapeCenterY(entity_id)
        network.setGeometricShapeCenterY(entity_id, geometric_shape_center_y + center_y_displacement)
        self.assertAlmostEqual(geometric_shape_center_y + center_y_displacement, network.getGeometricShapeCenterY(entity_id), 1)

    def _check_set_dimensions_of_rectangle_geometric_shape(self, network, entity_id):
        width_extension = 10.0
        height_extension = 10.0
        network.setGeometricShape(entity_id, 'rectangle')
        # width
        geometric_shape_width = network.getGeometricShapeWidth(entity_id)
        network.setGeometricShapeWidth(entity_id, geometric_shape_width + width_extension)
        self.assertAlmostEqual(network.getGeometricShapeWidth(entity_id), geometric_shape_width + width_extension, 1)
        # height
        geometric_shape_height = network.getGeometricShapeHeight(entity_id)
        network.setGeometricShapeHeight(entity_id, geometric_shape_height + height_extension)

    def _check_set_dimensions_of_ellipse_geometric_shape(self, network, entity_id):
        radius_x_extension = 5.0
        radius_y_extension = 5.0
        network.setGeometricShape(entity_id, 'ellipse')
        # radius x
        geometric_shape_radius_x = network.getGeometricShapeRadiusX(entity_id)
        network.setGeometricShapeRadiusX(entity_id, geometric_shape_radius_x + radius_x_extension)
        self.assertAlmostEqual(network.getGeometricShapeRadiusX(entity_id), geometric_shape_radius_x + radius_x_extension, 1)
        # radius y
        geometric_shape_radius_y = network.getGeometricShapeRadiusY(entity_id)
        network.setGeometricShapeRadiusY(entity_id, geometric_shape_radius_y + radius_y_extension)
        self.assertAlmostEqual(network.getGeometricShapeRadiusY(entity_id), geometric_shape_radius_y + radius_y_extension, 1)

    @staticmethod
    def _get_associated_compartment_id(network, element_id):
        compartment_id = network.getCompartmentId(element_id)
        if not compartment_id:
            list_of_compartment_ids = network.getListOfCompartmentIds()
            if len(list_of_compartment_ids) == 1:
                compartment_id = list_of_compartment_ids[0]
            else:
                raise ValueError('No compartment is associated in this model')

        return compartment_id


if __name__ == '__main__':
    unittest.main()

