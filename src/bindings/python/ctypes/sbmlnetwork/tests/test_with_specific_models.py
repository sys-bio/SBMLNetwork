import unittest
import math

import tellurium as te
import sbmlnetwork


class TestSBMLNetwork(unittest.TestCase):
    def test_basic_autolayout(self):
        model = te.loada("""
            S1 -> S2;
            S2 -> S3;
        """)
        sbml = model.getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        self.assertNotEqual(network.getX("S1"), math.nan)
        self.assertNotEqual(network.getY("S1"), math.nan)
        self.assertNotEqual(network.getX("S2"), math.nan)
        self.assertNotEqual(network.getY("S2"), math.nan)
        self.assertNotEqual(network.getX("S3"), math.nan)
        self.assertNotEqual(network.getY("S3"), math.nan)

    def test_basic_positions(self):
        model = te.loada("""
            S1 -> S2;
        """)
        sbml = model.getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setPosition("S1", 52, 80)
        network.setX("S2", 86)
        network.setY("S2", 73)
        self.assertEqual(network.getX("S1"), 52)
        self.assertEqual(network.getY("S1"), 80)
        self.assertEqual(network.getX("S2"), 86)
        self.assertEqual(network.getY("S2"), 73)

    def test_basic_sizes(self):
        model = te.loada("""
            S1 -> S2;
        """)
        sbml = model.getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setWidth("S1", 52)
        network.setHeight("S1", 80)
        network.setWidth("S2", 86)
        network.setHeight("S2", 73)
        self.assertEqual(network.getWidth("S1"), 52)
        self.assertEqual(network.getHeight("S1"), 80)
        self.assertEqual(network.getWidth("S2"), 86)
        self.assertEqual(network.getHeight("S2"), 73)

    def test_max_edges(self):
        model = """
            S1 -> S2;
            S1 -> S3;
            S1 -> S4;
            S1 -> S5;
            S1 -> S6;
            S1 -> S7;
            S1 -> S8;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        # default max num connected edges
        self.assertEqual(network.getNumSpeciesGlyphs("S1"), 3)
        # max num connected edges = 7
        network.autolayout(max_num_connected_edges=7)
        self.assertEqual(network.getNumSpeciesGlyphs("S1"), 1)

    def test_use_name_as_text_label(self):
        model = """
            S1 -> S2;
            S1 is "Species 1";
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        # default use name as text label
        self.assertEqual(network.getText("S1"), "Species 1")
        # set use name as text label to False
        network.setUseNameAsTextLabel(False)
        self.assertEqual(network.getText("S1"), "S1")
        # set use name as text label to True
        network.setUseNameAsTextLabel(True)
        self.assertEqual(network.getText("S1"), "Species 1")

    def test_set_layout_style(self):
        model = """
            S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setStyle("power")
        self.assertEqual(network.getStyle(), "power")
        self.assertEqual(network.getBackgroundColor(), "white")
        self.assertEqual(network.getCompartmentsGeometricShapeType(), "rectangle")
        self.assertEqual(network.getCompartmentsBorderColor(), "mandy")
        self.assertEqual(network.getCompartmentsBorderWidth(), 3.0)
        self.assertEqual(network.getCompartmentsFillColor(), "pewter")
        self.assertEqual(network.getCompartmentsFontColor(), "gondola")
        self.assertEqual(network.getCompartmentsFontSize(), 10.0)
        self.assertEqual(network.getSpeciesGeometricShapeType(), "rectangle")
        self.assertEqual(network.getSpeciesFillColor(), "carnation")
        self.assertEqual(network.getSpeciesBorderColor(), "gondola")
        self.assertEqual(network.getSpeciesBorderWidth(), 3.0)
        self.assertEqual(network.getSpeciesFontColor(), "gondola")
        self.assertEqual(network.getSpeciesFontSize(), 24.0)
        self.assertEqual(network.getReactionsLineColor(), "gondola")
        self.assertEqual(network.getReactionsLineWidth(), 3.0)
        self.assertEqual(network.getReactionsFontColor(), "gondola")
        self.assertEqual(network.getReactionsFontSize(), 12.0)
        self.assertEqual(network.getLineEndingsBorderColor(0), "gondola")
        self.assertEqual(network.getLineEndingsBorderWidth(), 3.0)
        self.assertEqual(network.getLineEndingsFillColor(), "gondola")

    def test_layout_size(self):
        model = """
            S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setCanvasWidth(1234.0)
        network.setCanvasHeight(1432.0)
        self.assertEqual(network.getCanvasWidth(), 1234.0)
        self.assertEqual(network.getCanvasHeight(), 1432.0)
        network.autolayout()
        self.assertEqual(network.getCanvasWidth(), 1234.0)
        self.assertEqual(network.getCanvasHeight(), 1432.0)

    def test_align_top(self):
        model = """
            S1 -> S2;
            S2 -> S3;
            S3 -> S4;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        species_list = ["S1", "S2", "S3"]
        min_position_y = self._get_min_position_y(network, species_list)
        network.align(species_list, "top")
        self.assertAlmostEqual(network.getY("S1"), min_position_y, 1)
        self.assertAlmostEqual(network.getY("S2"), min_position_y, 1)
        self.assertAlmostEqual(network.getY("S3"), min_position_y, 1)

    def test_align_bottom(self):
        model = """
            S1 -> S2;
            S2 -> S3;
            S3 -> S4;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        species_list = ["S1", "S2", "S3"]
        max_position_y = self._get_max_position_y(network, species_list)
        network.align(species_list, "bottom")
        self.assertAlmostEqual(network.getY("S1"), max_position_y, 1)
        self.assertAlmostEqual(network.getY("S2"), max_position_y, 1)
        self.assertAlmostEqual(network.getY("S3"), max_position_y, 1)

    def test_align_left(self):
        model = """
            S1 -> S2;
            S2 -> S3;
            S3 -> S4;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        species_list = ["S1", "S2", "S3"]
        min_position_x = self._get_min_position_x(network, species_list)
        network.align(species_list, "left")
        self.assertAlmostEqual(network.getX("S1"), min_position_x, 1)
        self.assertAlmostEqual(network.getX("S2"), min_position_x, 1)
        self.assertAlmostEqual(network.getX("S3"), min_position_x, 1)

    def test_align_right(self):
        model = """
            S1 -> S2;
            S2 -> S3;
            S3 -> S4;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        species_list = ["S1", "S2", "S3"]
        max_position_x = self._get_max_position_x(network, species_list)
        network.align(species_list, "right")
        self.assertAlmostEqual(network.getX("S1"), max_position_x, 1)
        self.assertAlmostEqual(network.getX("S2"), max_position_x, 1)
        self.assertAlmostEqual(network.getX("S3"), max_position_x, 1)

    def test_align_vCenter(self):
        model = """
            S1 -> S2;
            S2 -> S3;
            S3 -> S4;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        species_list = ["S1", "S2", "S3"]
        min_position_y = self._get_min_position_y(network, species_list)
        max_position_y = self._get_max_position_y(network, species_list)
        network.align(species_list, "vCenter")
        self.assertAlmostEqual(network.getY("S1"), 0.5 * (min_position_y + max_position_y), 1)
        self.assertAlmostEqual(network.getY("S2"), 0.5 * (min_position_y + max_position_y), 1)
        self.assertAlmostEqual(network.getY("S3"), 0.5 * (min_position_y + max_position_y), 1)

    def test_align_hCenter(self):
        model = """
            S1 -> S2;
            S2 -> S3;
            S3 -> S4;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        species_list = ["S1", "S2", "S3"]
        min_position_x = self._get_min_position_x(network, species_list)
        max_position_x = self._get_max_position_x(network, species_list)
        network.align(species_list, "hCenter")
        self.assertAlmostEqual(network.getX("S1"), 0.5 * (min_position_x + max_position_x), 1)
        self.assertAlmostEqual(network.getX("S2"), 0.5 * (min_position_x + max_position_x), 1)
        self.assertAlmostEqual(network.getX("S3"), 0.5 * (min_position_x + max_position_x), 1)

    def test_whole_model_settings(self):
        model = """
            S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setBackgroundColor("orange")
        self.assertEqual(network.getBackgroundColor(), "orange")
        network.setCompartmentsFillColor("khaki")
        self.assertEqual(network.getCompartmentsFillColor(), "khaki")
        network.setSpeciesFillColor("khaki")
        self.assertEqual(network.getSpeciesFillColor(), "khaki")
        network.setReactionsFillColor("khaki")
        self.assertEqual(network.getReactionsFillColor(), "khaki")
        network.setCompartmentsBorderColor("azure")
        self.assertEqual(network.getCompartmentsBorderColor(), "azure")
        network.setSpeciesBorderColor("azure")
        self.assertEqual(network.getSpeciesBorderColor(), "azure")
        network.setReactionsLineColor("azure")
        self.assertEqual(network.getReactionsLineColor(), "azure")
        network.setCompartmentsFontColor("coral")
        self.assertEqual(network.getCompartmentsFontColor(), "coral")
        network.setSpeciesFontColor("coral")
        self.assertEqual(network.getSpeciesFontColor(), "coral")
        network.setReactionsFontColor("coral")
        self.assertEqual(network.getReactionsFontColor(), "coral")
        network.setCompartmentsBorderWidth(32.0)
        self.assertEqual(network.getCompartmentsBorderWidth(), 32.0)
        network.setSpeciesBorderWidth(32.0)
        self.assertEqual(network.getSpeciesBorderWidth(), 32.0)
        network.setReactionsLineWidth(32.0)
        self.assertEqual(network.getReactionsLineWidth(), 32.0)
        network.setCompartmentsFontFamily("monospace")
        self.assertEqual(network.getCompartmentsFontFamily(), "monospace")
        network.setSpeciesFontFamily("monospace")
        self.assertEqual(network.getSpeciesFontFamily(), "monospace")
        network.setReactionsFontFamily("monospace")
        self.assertEqual(network.getReactionsFontFamily(), "monospace")
        network.setCompartmentsFontSize(4.0)
        self.assertEqual(network.getCompartmentsFontSize(), 4.0)
        network.setSpeciesFontSize(4.0)
        self.assertEqual(network.getSpeciesFontSize(), 4.0)
        network.setReactionsFontSize(4.0)
        self.assertEqual(network.getReactionsFontSize(), 4.0)
        network.setCompartmentsFontStyle("italic")
        self.assertEqual(network.getCompartmentsFontStyle(), "italic")
        network.setSpeciesFontStyle("italic")
        self.assertEqual(network.getSpeciesFontStyle(), "italic")
        network.setReactionsFontStyle("italic")
        self.assertEqual(network.getReactionsFontStyle(), "italic")
        network.setCompartmentsFontWeight("normal")
        self.assertEqual(network.getCompartmentsFontWeight(), "normal")
        network.setSpeciesFontWeight("normal")
        self.assertEqual(network.getSpeciesFontWeight(), "normal")
        network.setReactionsFontWeight("normal")
        self.assertEqual(network.getReactionsFontWeight(), "normal")

    def test_compartment_settings(self):
        model = """
            species S1 in C, S2 in C;
            S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setWidth("C", 420.0)
        self.assertEqual(network.getWidth("C"), 420.0)
        network.setWidth("C", 420.0)
        self.assertEqual(network.getWidth("C"), 420.0)
        network.setHeight("C", 550.0)
        self.assertEqual(network.getHeight("C"), 550.0)
        network.setFillColor("C", "khaki")
        self.assertEqual(network.getFillColor("C"), "khaki")
        network.setBorderColor("C", "azure")
        self.assertEqual(network.getBorderColor("C"), "azure")
        network.setFontColor("C", "coral")
        self.assertEqual(network.getFontColor("C"), "coral")
        network.setBorderWidth("C", 32.0)
        self.assertEqual(network.getBorderWidth("C"), 32.0)
        network.setFontFamily("C", "monospace")
        self.assertEqual(network.getFontFamily("C"), "monospace")
        network.setFontSize("C", 4.0)
        self.assertEqual(network.getFontSize("C"), 4.0)
        network.setFontStyle("C", "italic")
        self.assertEqual(network.getFontStyle("C"), "italic")
        network.setFontWeight("C", "normal")
        self.assertEqual(network.getFontWeight("C"), "normal")

    def test_species_settings(self):
        model = """
            S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setWidth("S1", 42.0)
        self.assertEqual(network.getWidth("S1"), 42.0)
        network.setHeight("S1", 55.0)
        self.assertEqual(network.getHeight("S1"), 55.0)
        network.setWidth("S2", 42.0)
        self.assertEqual(network.getWidth("S2"), 42.0)
        network.setHeight("S2", 55.0)
        self.assertEqual(network.getHeight("S2"), 55.0)
        network.setFillColor("S1", "khaki")
        self.assertEqual(network.getFillColor("S1"), "khaki")
        network.setBorderColor("S1", "azure")
        self.assertEqual(network.getBorderColor("S1"), "azure")
        network.setFontColor("S1", "coral")
        self.assertEqual(network.getFontColor("S1"), "coral")
        network.setBorderWidth("S1", 32.0)
        self.assertEqual(network.getBorderWidth("S1"), 32.0)
        network.setFontFamily("S1", "monospace")
        self.assertEqual(network.getFontFamily("S1"), "monospace")
        network.setFontSize("S1", 4.0)
        self.assertEqual(network.getFontSize("S1"), 4.0)
        network.setFontStyle("S1", "italic")
        self.assertEqual(network.getFontStyle("S1"), "italic")
        network.setFontWeight("S1", "normal")
        self.assertEqual(network.getFontWeight("S1"), "normal")

    def test_reaction_settings(self):
        model = """
            J0: S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setWidth("J0", 420.0)
        self.assertEqual(network.getWidth("J0"), 420.0)
        network.setHeight("J0", 550.0)
        self.assertEqual(network.getHeight("J0"), 550.0)
        network.setFillColor("J0", "khaki")
        self.assertEqual(network.getFillColor("J0"), "khaki")
        network.setLineColor("J0", "azure")
        self.assertEqual(network.getLineColor("J0"), "azure")
        network.setFontColor("J0", "coral")
        self.assertEqual(network.getFontColor("J0"), "coral")
        network.setLineWidth("J0", 32.0)
        self.assertEqual(network.getLineWidth("J0"), 32.0)
        network.setFontFamily("J0", "monospace")
        self.assertEqual(network.getFontFamily("J0"), "monospace")
        network.setFontSize("J0", 4.0)
        self.assertEqual(network.getFontSize("J0"), 4.0)
        network.setFontStyle("J0", "italic")
        self.assertEqual(network.getFontStyle("J0"), "italic")
        network.setFontWeight("J0", "normal")
        self.assertEqual(network.getFontWeight("J0"), "normal")

    def test_locations_pos(self):
        model = """
            J0: S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setPosition("S1", 120.0, 250.0)
        self.assertEqual(network.getPosition("S1"), (120.0, 250.0))
        network.setPosition("S2", 420.0, 550.0)
        self.assertEqual(network.getPosition("S2"), (420.0, 550.0))
        network.setPosition("J0", 270.0, 400.0)
        self.assertEqual(network.getX("J0"), 270.0)
        self.assertEqual(network.getY("J0"), 400.0)

    def test_locations_xy(self):
        model = """
            J0: S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setX("S1", 120.0)
        self.assertEqual(network.getX("S1"), 120.0)
        network.setY("S1", 250.0)
        self.assertEqual(network.getY("S1"), 250.0)
        network.setX("S2", 420.0)
        self.assertEqual(network.getX("S2"), 420.0)
        network.setY("S2", 550.0)
        self.assertEqual(network.getY("S2"), 550.0)
        network.setX("J0", 270.0)
        self.assertEqual(network.getX("J0"), 270.0)
        network.setY("J0", 400.0)
        self.assertEqual(network.getY("J0"), 400.0)

    def test_control_points(self):
        model = """
            J0: S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setPosition("S1", 560.0, 0.0)
        network.setPosition("S2", 30.0, 37.5)
        network.setPosition("J0", 318.13, 29.25)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S1", reaction_id="J0")
        network.setSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index, x=318.13)
        network.setSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index, y=29.25)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index, x=364.9)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index, y=33.93)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index, x=350.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index, y=35.0)
        network.setSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index, x=550.02)
        network.setSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index, y=20.83)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S2", reaction_id="J0")
        network.setSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index, x=318.13)
        network.setSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index, y=29.25)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index, x=285.1)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index, y=39.57)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index, x=290.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index, y=40.0)
        network.setSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index, x=99.98)
        network.setSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index, y=52.67)
        self.assertEqual(network.getY("S1"), 0.0)
        self.assertEqual(network.getX("S2"), 30.0)
        self.assertEqual(network.getY("S2"), 37.5)
        self.assertEqual(network.getX("J0"), 318.13)
        self.assertEqual(network.getY("J0"), 29.25)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S1", reaction_id="J0")
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index), 318.13)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index), 29.25)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index), 364.9)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index), 33.93)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index), 350)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index), 35)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index), 550.02)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index), 20.83)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S2", reaction_id="J0")
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index), 318.13)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index), 29.25)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index), 285.1)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index), 39.57)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index), 290)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index), 40)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index), 99.98)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index), 52.67)

    def test_control_points_double_arcs(self):
        model = """
            J0: 2 S1 -> S2;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setPosition("S1", 560.0, 0.0)
        network.setPosition("S2", 30.0, 37.5)
        network.setPosition("J0", 318.13, 29.25)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S1", reaction_id="J0", n = 0)
        network.setSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index, x=318.13)
        network.setSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index, y=29.25)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index, x=364.9)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index, y=33.93)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index, x=350.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index, y=35.0)
        network.setSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index, x=550.02)
        network.setSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index, y=20.83)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S1", reaction_id="J0", n = 1)
        network.setSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index, x=318.13)
        network.setSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index, y=29.25)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index, x=342.95)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index, y=26.25)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index, x=490.02)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index, y=18.95)
        network.setSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index, x=550.01)
        network.setSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index, y=18.38)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S2", reaction_id="J0", n = 0)
        network.setSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index, x=318.13)
        network.setSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index, y=29.25)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index, x=285.1)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index, y=39.57)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index, x=290.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index, y=40.0)
        network.setSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index, x=99.98)
        network.setSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index, y=52.67)
        self.assertEqual(network.getY("S1"), 0.0)
        self.assertEqual(network.getX("S2"), 30.0)
        self.assertEqual(network.getY("S2"), 37.5)
        self.assertEqual(network.getX("J0"), 318.13)
        self.assertEqual(network.getY("J0"), 29.25)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S1", reaction_id="J0", n = 0)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index), 318.13)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index), 29.25)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index), 364.9)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index), 33.93)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index), 350)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index), 35)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index), 550.02)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index), 20.83)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S1", reaction_id="J0", n = 1)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index), 318.13)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index), 29.25)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index), 342.95)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index), 26.25)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index), 490.02)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index), 18.95)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index), 550.01)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index), 18.38)
        species_reference_index = network.getSpeciesReferenceIndexAssociatedWithSpecies(species_id="S2", reaction_id="J0", n = 0)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointX("J0", species_reference_index=species_reference_index), 318.13)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentStartPointY("J0", species_reference_index=species_reference_index), 29.25)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("J0", species_reference_index=species_reference_index), 285.1)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("J0", species_reference_index=species_reference_index), 39.57)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("J0", species_reference_index=species_reference_index), 290)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("J0", species_reference_index=species_reference_index), 40)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointX("J0", species_reference_index=species_reference_index), 99.98)
        self.assertEqual(network.getSpeciesReferenceCurveSegmentEndPointY("J0", species_reference_index=species_reference_index), 52.67)

    def test_all_line_ending_settings(self):
        model = '''
            S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setLineEndingsBorderColor("yellow")
        self.assertEqual(network.getLineEndingsBorderColor(), "yellow")
        network.setLineEndingsBorderWidth(10)
        self.assertEqual(network.getLineEndingsBorderWidth(), 10)
        network.setLineEndingsFillColor("blue")
        self.assertEqual(network.getLineEndingsFillColor(), "blue")

    def test_line_ending_in_a_reaction_settings(self):
        model = """
            J0: S1 -> S2 + S3;
            J1: S2 -> S4 + S5;
            J2: S3 -> S6 + S7;
        """
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        # set all features in a reaction
        reaction_id = "J0"
        network.setBorderColor(reaction_id, "blue")
        network.setBorderWidth(reaction_id, 8)
        network.setFillColor(reaction_id, "green")
        self.assertEqual(network.getBorderColor(reaction_id), "blue")
        self.assertEqual(network.getBorderWidth(reaction_id), 8)
        self.assertEqual(network.getFillColor(reaction_id), "green")
        # set the features of the line endings in a reaction
        reaction_id = "J1"
        network.setReactionLineEndingBorderColor(reaction_id, "yellow")
        network.setReactionLineEndingBorderWidth(reaction_id, 5)
        network.setReactionLineEndingFillColor(reaction_id, "red")
        for species_reference_index in range(network.getNumSpeciesReferences(reaction_id)):
            if network.getSpeciesReferenceLineEndingGeometricShapeType(reaction_id, species_reference_index=species_reference_index, index=0) != "":
                self.assertEqual(network.getSpeciesReferenceLineEndingBorderColor(reaction_id, species_reference_index=species_reference_index), "yellow")
                self.assertEqual(network.getSpeciesReferenceLineEndingBorderWidth(reaction_id, species_reference_index=species_reference_index), 5)
                self.assertEqual(network.getSpeciesReferenceLineEndingFillColor(reaction_id, species_reference_index=species_reference_index), "red")
        # set the features of the line endings of a species reference in a reaction
        reaction_id = "J2"
        graphical_object_index = 0
        species_reference_index = 1
        network.setSpeciesReferenceLineEndingBorderColor(reaction_id, "purple", graphical_object_index, species_reference_index)
        network.setSpeciesReferenceLineEndingBorderWidth(reaction_id, 3, graphical_object_index, species_reference_index)
        network.setSpeciesReferenceLineEndingFillColor(reaction_id, "orange", graphical_object_index, species_reference_index)
        self.assertEqual(network.getSpeciesReferenceLineEndingBorderColor(reaction_id, graphical_object_index, species_reference_index), "purple")
        self.assertEqual(network.getSpeciesReferenceLineEndingBorderWidth(reaction_id, graphical_object_index, species_reference_index), 3)
        self.assertEqual(network.getSpeciesReferenceLineEndingFillColor(reaction_id, graphical_object_index, species_reference_index), "orange")

    def test_graphical_object_id(self):
        model = '''
            J0: S1 + S2 -> S3;
            J1: S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.createAliasSpeciesGlyph("S1", "J1")
        network.setId("S1", "MyMostFavoriteSpeciesGlyph", graphical_object_index=0)
        network.setId("S1", "MyLeastFavoriteSpeciesGlyph", graphical_object_index=1)
        network.setText("MyMostFavoriteSpeciesGlyph", "Favorite")
        network.setText("MyLeastFavoriteSpeciesGlyph", "non-Favorite")
        self.assertEqual(network.getId("S1", graphical_object_index=0), "MyMostFavoriteSpeciesGlyph")
        self.assertEqual(network.getId("S1", graphical_object_index=1), "MyLeastFavoriteSpeciesGlyph")
        self.assertEqual(network.getText("MyMostFavoriteSpeciesGlyph"), "Favorite")
        self.assertEqual(network.getText("MyLeastFavoriteSpeciesGlyph"), "non-Favorite")

    def test_fill_color_as_gradient(self):
        model = '''
            S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        # linear gradient
        network.setFillColorAsGradient("S1", stop_colors=["#ff6600", "#ffff66"], stop_offsets=[0, 100], gradient_type="linear")
        gradient_id = network.getListOfGradientIds()[-1]
        network.setLinearGradientX1(gradient_id, 0)
        network.setLinearGradientY1(gradient_id, 50)
        network.setLinearGradientX2(gradient_id, 100)
        network.setLinearGradientY2(gradient_id, 50)
        self.assertEqual(network.getLinearGradientX1(gradient_id), 0)
        self.assertEqual(network.getLinearGradientY1(gradient_id), 50)
        self.assertEqual(network.getLinearGradientX2(gradient_id), 100)
        self.assertEqual(network.getLinearGradientY2(gradient_id), 50)
        # radial gradient
        network.setFillColorAsGradient("S2", stop_colors=["#FF0000", "#0000FF", "#FF0000"], stop_offsets=[0, 50, 100], gradient_type="radial")
        gradient_id = network.getListOfGradientIds()[-1]
        network.setRadialGradientCenterX(gradient_id, 50)
        network.setRadialGradientCenterY(gradient_id, 50)
        network.setRadialGradientFocalX(gradient_id, 50)
        network.setRadialGradientFocalY(gradient_id, 50)
        network.setRadialGradientRadius(gradient_id, 300)
        self.assertEqual(network.getRadialGradientCenterX(gradient_id), 50)
        self.assertEqual(network.getRadialGradientCenterY(gradient_id), 50)
        self.assertEqual(network.getRadialGradientFocalX(gradient_id), 50)
        self.assertEqual(network.getRadialGradientFocalY(gradient_id), 50)
        self.assertEqual(network.getRadialGradientRadius(gradient_id), 300)

    def test_compartment_extents(self):
        model = '''
        S1 in C1;
        S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        compartment_id = network.getListOfCompartmentIds()[0]
        network.setX(compartment_id, 200)
        network.setY(compartment_id, 250)
        network.setWidth(compartment_id, 1500)
        network.setHeight(compartment_id, 1000)
        network.autolayout(reset_fixed_position_elements=False)
        self.assertEqual(network.getX(compartment_id), 200)
        self.assertEqual(network.getY(compartment_id), 250)
        self.assertEqual(network.getWidth(compartment_id), 1500)
        self.assertEqual(network.getHeight(compartment_id), 1000)

    def test_graphical_objects_visibility(self):
        model = '''
            species S1 in C1, S2 in C1, S3 in C1, S4 in C1;
            J0: S1 + S2 -> S3;
            J1: S1 -> S4;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        # A specific compartment glyph
        network.makeInvisible("C1")
        self.assertFalse(network.isVisible("C1"))
        network.makeVisible("C1")
        self.assertTrue(network.isVisible("C1"))
        # A specific species glyph
        network.makeInvisible("S1")
        self.assertFalse(network.isVisible("S1"))
        network.makeVisible("S1")
        self.assertTrue(network.isVisible("S1"))
        # A specific reaction glyph
        network.makeInvisible("J0")
        self.assertFalse(network.isVisible("J0"))
        network.makeVisible("J0")
        # all compartment glyphs
        network.makeCompartmentsInvisible()
        self.assertFalse(all(network.isVisible(compartment) for compartment in network.getListOfCompartmentIds()))
        network.makeCompartmentsVisible()
        self.assertTrue(all(network.isVisible(compartment) for compartment in network.getListOfCompartmentIds()))
        # all species glyphs
        network.makeSpeciesInvisible()
        self.assertFalse(all(network.isVisible(species) for species in network.getListOfSpeciesIds()))
        network.makeSpeciesVisible()
        self.assertTrue(all(network.isVisible(species) for species in network.getListOfSpeciesIds()))
        # all reaction glyphs
        network.makeReactionsInvisible()
        self.assertFalse(all(network.isVisible(reaction) for reaction in network.getListOfReactionIds()))
        network.makeReactionsVisible()
        self.assertTrue(all(network.isVisible(reaction) for reaction in network.getListOfReactionIds()))
        # all glyphs
        all_graphical_objects = network.getListOfCompartmentIds() + network.getListOfSpeciesIds() + network.getListOfReactionIds()
        network.makeAllInvisible()
        self.assertFalse(all(network.isVisible(element) for element in all_graphical_objects))
        network.makeAllVisible()
        self.assertTrue(all(network.isVisible(element) for element in all_graphical_objects))

    def test_species_reference_curve_segment_points(self):
        model = '''
            S1 + S2 -> S3;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        initial_start_x = network.getSpeciesReferenceCurveSegmentStartPointX("_J0")
        initial_start_y = network.getSpeciesReferenceCurveSegmentStartPointY("_J0")
        initial_base_point1_x = network.getSpeciesReferenceCurveSegmentBasePoint1X("_J0")
        initial_base_point1_y = network.getSpeciesReferenceCurveSegmentBasePoint1Y("_J0")
        initial_base_point2_x = network.getSpeciesReferenceCurveSegmentBasePoint2X("_J0")
        initial_base_point2_y = network.getSpeciesReferenceCurveSegmentBasePoint2Y("_J0")
        initial_end_x = network.getSpeciesReferenceCurveSegmentEndPointX("_J0")
        initial_end_y = network.getSpeciesReferenceCurveSegmentEndPointY("_J0")
        network.setSpeciesReferenceCurveSegmentStartPointX("_J0", initial_start_x + 10.0)
        network.setSpeciesReferenceCurveSegmentStartPointY("_J0", initial_start_y + 20.0)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("_J0", initial_base_point1_x + 30.0)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("_J0", initial_base_point1_y + 40.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("_J0", initial_base_point2_x + 50.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("_J0", initial_base_point2_y + 60.0)
        network.setSpeciesReferenceCurveSegmentEndPointX("_J0", initial_end_x + 70.0)
        network.setSpeciesReferenceCurveSegmentEndPointY("_J0", initial_end_y + 80.0)
        network.autolayout(fixed_position_nodes=["S1", "S2", "S3", "_J0"])
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentStartPointX("_J0"), initial_start_x + 10.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentStartPointY("_J0"), initial_start_y + 20.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("_J0"), initial_base_point1_x + 30.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("_J0"), initial_base_point1_y + 40.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("_J0"), initial_base_point2_x + 50.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("_J0"), initial_base_point2_y + 60.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentEndPointX("_J0"), initial_end_x + 70.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentEndPointY("_J0"), initial_end_y + 80.0, 1)
        network.setSpeciesReferenceCurveSegmentStartPointX("_J0", initial_start_x + 11.0)
        network.setSpeciesReferenceCurveSegmentStartPointY("_J0", initial_start_y + 21.0)
        network.setSpeciesReferenceCurveSegmentBasePoint1X("_J0", initial_base_point1_x + 31.0)
        network.setSpeciesReferenceCurveSegmentBasePoint1Y("_J0", initial_base_point1_y + 41.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2X("_J0", initial_base_point2_x + 51.0)
        network.setSpeciesReferenceCurveSegmentBasePoint2Y("_J0", initial_base_point2_y + 61.0)
        network.setSpeciesReferenceCurveSegmentEndPointX("_J0", initial_end_x + 71.0)
        network.setSpeciesReferenceCurveSegmentEndPointY("_J0", initial_end_y + 81.0)
        network.autolayout(reset_fixed_position_elements=False)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentStartPointX("_J0"), initial_start_x + 11.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentStartPointY("_J0"), initial_start_y + 21.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint1X("_J0"), initial_base_point1_x + 31.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint1Y("_J0"), initial_base_point1_y + 41.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint2X("_J0"), initial_base_point2_x + 51.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentBasePoint2Y("_J0"), initial_base_point2_y + 61.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentEndPointX("_J0"), initial_end_x + 71.0, 1)
        self.assertAlmostEqual(network.getSpeciesReferenceCurveSegmentEndPointY("_J0"), initial_end_y + 81.0, 1)

    def test_index_of_species_glyph_in_reaction(self):
        model = '''
            J0: S1 + S2 -> S3;
            J1: S1 + S4 -> S5;
            J2: S1 + S6 -> S7;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.createAliasSpeciesGlyph("S1", "J1")
        network.createAliasSpeciesGlyph("S1", "J2")
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J0"), 0)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J1"), 1)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J2"), 2)

    def test_index_of_species_reference_in_reaction(self):
        model = '''
            J0: S1 ->S2 + S3 + S1 + S2 + S1 + S1;
            S3 -| J0;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S1", "J0", n=0), 0)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S1", "J0", n=1), 3)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S1", "J0", n=2), 5)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S1", "J0", n=3), 6)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S2", "J0", n=0), 1)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S2", "J0", n=1), 4)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S3", "J0", n=0), 2)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S3", "J0", n=1), 7)

    def test_border_color_vs_font_color(self):
        model = '''
            S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setSpeciesBorderColor("red")
        self.assertEqual(network.getSpeciesBorderColor(), "red")
        network.setSpeciesFontColor("brown")
        self.assertEqual(network.getSpeciesFontColor(), "brown")
        network.setReactionsLineColor("purple")
        self.assertEqual(network.getReactionsLineColor(), "purple")
        network.setReactionsFontColor("yellow")
        self.assertEqual(network.getReactionsFontColor(), "yellow")
        network.setBorderColor("S1", "pink")
        self.assertEqual(network.getBorderColor("S1"), "pink")
        network.setFontColor("S1", "grey")
        self.assertEqual(network.getFontColor("S1"), "grey")

    def test_swap_species_glyph_in_reaction(self):
        model = '''
            J0: S1 -> S2;
            J1: S1 + S4 + S5 -> S6;
            J2: S4 -> S1;
            J3: S1 + S2 -> S3;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J0"), 0)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J1"), 0)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J2"), 0)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J3"), 1)
        network.createAliasSpeciesGlyph("S1", "J1")
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J1"), 2)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J0"), 0)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J2"), 0)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J3"), 1)
        network.setSpeciesGlyphIndexInReactionGlyph("S1", "J2", 2)
        self.assertEqual(network.getSpeciesGlyphIndex("S1", "J1"), 2)

    def test_species_reference_index_associated_with_species(self):
        model = '''
            J0: S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S1", "J0"), 0)
        self.assertEqual(network.getSpeciesReferenceIndexAssociatedWithSpecies("S2", "J0"), 1)

    def test_set_stoichiometric_species_reference(self):
        model = '''
            J0: 100000 S1 -> 200000 S2;
        '''
        sbmlnetwork.settings.disable_stoichiometric_curves()
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        self.assertEqual(network.getNumSpeciesReferenceAssociatedWithSpecies("S1", "J0"), 1)

    def test_set_colors_of_a_group_of_graphical_objects(self):
        model = '''
            S1 -> S2;
        '''
        sbml = te.loada(model).getSBML()
        network = sbmlnetwork.load(sbml).libsbmlnetwork
        network.setCompartmentsBorderColor("#FF0000")
        network.setCompartmentsFontColor("#A52A2A")
        network.setSpeciesBorderColor("#00FF00")
        network.setSpeciesFontColor("#800080")
        network.setReactionsLineColor("#0000FF")
        network.setReactionsFontColor("#FFC0CB")
        network.setCompartmentsFillColor("#FFFF00")
        network.setSpeciesFillColor("#FFA500")
        network.setReactionsFillColor("#FF00FF")
        self.assertEqual(network.getCompartmentsBorderColor(), "red")
        self.assertEqual(network.getCompartmentsFontColor(), "brown")
        self.assertEqual(network.getSpeciesBorderColor(), "lime")
        self.assertEqual(network.getSpeciesFontColor(), "purple")
        self.assertEqual(network.getReactionsLineColor(), "blue")
        self.assertEqual(network.getReactionsFontColor(), "pink")
        self.assertEqual(network.getCompartmentsFillColor(), "yellow")
        self.assertEqual(network.getSpeciesFillColor(), "orange")
        self.assertEqual(network.getReactionsFillColor(), "fuchsia")

    def test_reaction_position_and_dimensions_after_autolayout(self):
        model = '''
        J0: S1 -> S2;
        '''
        r = te.loada(model)
        net = sbmlnetwork.load(r.getSBML())

        # Testing width
        self.assertEqual(net.libsbmlnetwork.getWidth("J0"), 0)
        net.libsbmlnetwork.setWidth("J0", 110)
        self.assertEqual(net.libsbmlnetwork.getWidth("J0"), 110)
        net.libsbmlnetwork.autolayout()
        self.assertEqual(net.libsbmlnetwork.getWidth("J0"), 110)

        # Testing height
        self.assertEqual(net.libsbmlnetwork.getHeight("J0"), 0)
        net.libsbmlnetwork.setHeight("J0", 25)
        self.assertEqual(net.libsbmlnetwork.getHeight("J0"), 25)
        net.libsbmlnetwork.autolayout()
        self.assertEqual(net.libsbmlnetwork.getHeight("J0"), 25)

        # Testing x position
        net.libsbmlnetwork.setX("J0", 410)
        self.assertEqual(net.libsbmlnetwork.getX("J0"), 410)
        net.libsbmlnetwork.autolayout()
        self.assertEqual(net.libsbmlnetwork.getX("J0"), 410)

        # Testing y position
        net.libsbmlnetwork.setY("J0", 420)
        self.assertEqual(net.libsbmlnetwork.getY("J0"), 420)
        net.libsbmlnetwork.autolayout()
        self.assertEqual(net.libsbmlnetwork.getY("J0"), 420)

    def test_empty_species_positiions_and_dimensions_after_autolayout(self):
        model = '''
        J0: -> S1;
        '''
        r = te.loada(model)
        net = sbmlnetwork.load(r.getSBML())
        empty_species_glyph_id = ""
        for sr_index in range(net.libsbmlnetwork.getNumSpeciesReferences(reaction_id="J0")):
            if net.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id="J0", species_reference_index=sr_index) != "":
                empty_species_glyph_id = net.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id="J0", species_reference_index=sr_index)
                break
        if empty_species_glyph_id != "":
            net.libsbmlnetwork.setX(id=empty_species_glyph_id, x=250)
            net.libsbmlnetwork.setY(id=empty_species_glyph_id, y=290)
            net.libsbmlnetwork.setWidth(id=empty_species_glyph_id, width=90)
            net.libsbmlnetwork.setHeight(id=empty_species_glyph_id, height=15)
            net.auto_layout()
            self.assertEqual(net.libsbmlnetwork.getX(id=empty_species_glyph_id), 250)
            self.assertEqual(net.libsbmlnetwork.getY(id=empty_species_glyph_id), 290)
            self.assertEqual(net.libsbmlnetwork.getWidth(id=empty_species_glyph_id), 90)
            self.assertEqual(net.libsbmlnetwork.getHeight(id=empty_species_glyph_id), 15)

    def test_setting_getting_empty_species_default_values(self):
        model = '''
        J0: -> S1;
        J1: S2 -> ;
        '''
        r = te.loada(model)
        net = sbmlnetwork.load(r.getSBML())

        # Test border color
        net.libsbmlnetwork.setEmptySpeciesBorderColor("blue")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesBorderColor(), "blue")

        # Test fill color
        net.libsbmlnetwork.setEmptySpeciesFillColor("yellow")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesFillColor(), "yellow")

        # Test font size
        net.libsbmlnetwork.setEmptySpeciesFontSize(10)
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesFontSize(), 10)

        # Test font family
        net.libsbmlnetwork.setEmptySpeciesFontFamily("Arial")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesFontFamily(), "Arial")

        # Test font style
        net.libsbmlnetwork.setEmptySpeciesFontStyle("italic")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesFontStyle(), "italic")

        # Test font weight
        net.libsbmlnetwork.setEmptySpeciesFontWeight("bold")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesFontWeight(), "bold")

        # Test font color
        net.libsbmlnetwork.setEmptySpeciesFontColor("green")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesFontColor(), "green")

        # Test geometric shape
        net.libsbmlnetwork.setEmptySpeciesGeometricShapeType("ellipse")
        self.assertEqual(net.libsbmlnetwork.getEmptySpeciesGeometricShapeType(), "ellipse")

    def test_empty_species_properties(self):
        model = '''
        J0: -> S1;
        '''
        r = te.loada(model)
        net = sbmlnetwork.load(r.getSBML())
        empty_species_glyph_id = ""
        for sr_index in range(net.libsbmlnetwork.getNumSpeciesReferences(reaction_id="J0")):
            if net.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id="J0", species_reference_index=sr_index) != "":
                empty_species_glyph_id = net.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id="J0", species_reference_index=sr_index)
                break
        if empty_species_glyph_id != "":
            net.libsbmlnetwork.setX(id=empty_species_glyph_id, x=250)
            net.libsbmlnetwork.setY(id=empty_species_glyph_id, y=290)
            net.libsbmlnetwork.setWidth(id=empty_species_glyph_id, width=90)
            net.libsbmlnetwork.setHeight(id=empty_species_glyph_id, height=15)
            net.auto_layout()
            self.assertEqual(net.libsbmlnetwork.getX(id=empty_species_glyph_id), 250)
            self.assertEqual(net.libsbmlnetwork.getY(id=empty_species_glyph_id), 290)
            self.assertEqual(net.libsbmlnetwork.getWidth(id=empty_species_glyph_id), 90)
            self.assertEqual(net.libsbmlnetwork.getHeight(id=empty_species_glyph_id), 15)

    def test_setting_geometric_shape_properties_for_species_glyph_with_more_than_one_geometric_shape(self):
        model = '''
        J0: -> S1;
        '''
        r = te.loada(model)
        net = sbmlnetwork.load(r.getSBML())
        empty_species_glyph_id = ""
        for sr_index in range(net.libsbmlnetwork.getNumSpeciesReferences(reaction_id="J0")):
            if net.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id="J0", species_reference_index=sr_index) != "":
                empty_species_glyph_id = net.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id="J0", species_reference_index=sr_index)
                break

        if empty_species_glyph_id != "":
            net.libsbmlnetwork.setBorderColor(id=empty_species_glyph_id, border_color="blue")
            self.assertEqual(net.libsbmlnetwork.getBorderColor(id=empty_species_glyph_id), "blue")
            net.libsbmlnetwork.setFillColor(id=empty_species_glyph_id, fill_color="yellow")
            self.assertEqual(net.libsbmlnetwork.getFillColor(id=empty_species_glyph_id), "yellow")

    @staticmethod
    def _get_max_position_y(network, species_list):
        max_position_y = -math.inf
        for species in species_list:
            y = network.getY(species)
            if y > max_position_y:
                max_position_y = y

        return max_position_y

    @staticmethod
    def _get_min_position_y(network, species_list):
        min_position_y = math.inf
        for species in species_list:
            y = network.getY(species)
            if y < min_position_y:
                min_position_y = y

        return min_position_y

    @staticmethod
    def _get_max_position_x(network, species_list):
        max_position_x = -math.inf
        for species in species_list:
            x = network.getX(species)
            if x > max_position_x:
                max_position_x = x

        return max_position_x

    @staticmethod
    def _get_min_position_x(network, species_list):
        min_position_x = math.inf
        for species in species_list:
            x = network.getX(species)
            if x < min_position_x:
                min_position_x = x

        return min_position_x


if __name__ == '__main__':
    unittest.main()
