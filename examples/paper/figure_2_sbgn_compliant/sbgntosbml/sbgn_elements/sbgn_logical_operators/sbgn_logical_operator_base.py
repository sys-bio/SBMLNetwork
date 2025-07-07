from ..sbgn_2d_element_base import SBGN2DElementBase
from ..utils import find_element, find_parent_element

class SBGNLogicalOperatorBase(SBGN2DElementBase):

    def __init__(self, node_id, x, y, width, height, border_color=None, fill_color=None, sub_elements=None, sbgn_elements=None):
        super(SBGNLogicalOperatorBase, self).__init__(node_id, x, y, width, height, border_color, fill_color, sub_elements)
        self.sbgn_elements = sbgn_elements
        self.line_ending_horizontal_padding = -3.5

    @staticmethod
    def get_super_type():
        return "logical operator"

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        if parent_element is None:
            parent_element = self
        self.initialize_sbml_info(sbmlnetwork_object, parent_element)
        self.add_geometric_shape(sbmlnetwork_object)
        self.set_curves(sbmlnetwork_object)
        self.load_sbml_info_with_sub_elements(sbmlnetwork_object, parent_element)

    def initialize_sbml_info(self, sbmlnetwork_object, parent_element):
        if parent_element.get_id() == self.get_id():
            sbmlnetwork_object.libsbmlnetwork.setGeometricShapeType(parent_element.get_id(), "ellipse")
            sbmlnetwork_object.libsbmlnetwork.setX(parent_element.get_id(), self.get_x(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setY(parent_element.get_id(), self.get_y(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setWidth(parent_element.get_id(), self.get_width(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setHeight(parent_element.get_id(), self.get_height(), update_curves=False)

    def add_geometric_shape(self, sbmlnetwork_object, parent_element=None):
        sbmlnetwork_object.libsbmlnetwork.addAdditionalGraphicalObject(self.get_id())
        sbmlnetwork_object.libsbmlnetwork.setX(self.get_id(), self.get_x(), update_curves=False)
        sbmlnetwork_object.libsbmlnetwork.setY(self.get_id(), self.get_y(), update_curves=False)
        sbmlnetwork_object.libsbmlnetwork.setWidth(self.get_id(), self.get_width(), update_curves=False)
        sbmlnetwork_object.libsbmlnetwork.setHeight(self.get_id(), self.get_height(), update_curves=False)
        geometric_shape_id = self.get_id() + "_geometric_shape"
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeId(self.get_id(), geometric_shape_id)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeType(self.get_id(), "ellipse")
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeCenterX(self.get_id(), self.get_relative_x(
            sbmlnetwork_object.libsbmlnetwork.getX(self.get_id())) + 0.5 * self.get_relative_width(
            sbmlnetwork_object.libsbmlnetwork.getWidth(self.get_id())))
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeCenterY(self.get_id(), self.get_relative_y(
            sbmlnetwork_object.libsbmlnetwork.getY(self.get_id())) + 0.5 * self.get_relative_height(
            sbmlnetwork_object.libsbmlnetwork.getHeight(self.get_id())))
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeRadiusX(self.get_id(), 0.5 * self.get_relative_width(
            sbmlnetwork_object.libsbmlnetwork.getWidth(self.get_id())))
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeRadiusY(self.get_id(), 0.5 * self.get_relative_height(
            sbmlnetwork_object.libsbmlnetwork.getHeight(self.get_id())))

    def set_curves(self, sbmlnetwork_object):
        target_element = self.get_target_element()
        source_elements = self.get_source_elements()
        if len(source_elements) == 2:
            self.set_curve(sbmlnetwork_object, source_elements[0], target_element)
            self.set_curve(sbmlnetwork_object, source_elements[1], target_element)

    def set_curve(self, sbmlnetwork_object, source_element, target_element):
        species = find_parent_element(source_element.get_source_id(), self.sbgn_elements)
        species_reference_index = species.get_connected_species_reference_index(sbmlnetwork_object, target_element.get_target_id())
        self.set_curve_source_segment(sbmlnetwork_object, source_element, target_element, species_reference_index)
        self.set_curve_ports_segments(sbmlnetwork_object, target_element, species_reference_index)
        self.set_curve_target_segment(sbmlnetwork_object, target_element, species_reference_index)
        self.set_curve_line_ending(sbmlnetwork_object, target_element, species_reference_index)

    @staticmethod
    def set_curve_source_segment(sbmlnetwork_object, source_element, target_element, species_reference_index):
        while sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(target_element.get_target_id(), species_reference_index=species_reference_index) > 0:
            sbmlnetwork_object.libsbmlnetwork.removeSpeciesReferenceCurveSegment(target_element.get_target_id(), species_reference_index=species_reference_index, curve_segment_index=0)
        sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceCubicBezierCurveSegment(target_element.get_target_id(), species_reference_index=species_reference_index)
        curve_segment_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(target_element.get_target_id(), species_reference_index=species_reference_index) - 1
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(target_element.get_target_id(), source_element.get_start_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(target_element.get_target_id(), source_element.get_start_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(target_element.get_target_id(), source_element.get_start_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(target_element.get_target_id(), source_element.get_start_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(target_element.get_target_id(), source_element.get_end_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(target_element.get_target_id(), source_element.get_end_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(target_element.get_target_id(), source_element.get_end_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(target_element.get_target_id(), source_element.get_end_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)

    def set_curve_ports_segments(self, sbmlnetwork_object, target_element, species_reference_index):
        sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceCubicBezierCurveSegment(target_element.get_target_id(),
                                                                      species_reference_index=species_reference_index)
        for sub_element_index, sub_element in enumerate(self.sub_elements):
            if sub_element.get_type() == "logic port":
                curve_segment_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(target_element.get_target_id(),
                                                                                             species_reference_index=species_reference_index) - 1
                if sub_element_index == 0:
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(target_element.get_target_id(), sub_element.get_x(),
                                                                                  species_reference_index=species_reference_index,
                                                                                  curve_segment_index=curve_segment_index)
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(target_element.get_target_id(), sub_element.get_y(),
                                                                                  species_reference_index=species_reference_index,
                                                                                  curve_segment_index=curve_segment_index)
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(target_element.get_target_id(), sub_element.get_x(),
                                                                                  species_reference_index=species_reference_index,
                                                                                  curve_segment_index=curve_segment_index)
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(target_element.get_target_id(), sub_element.get_y(),
                                                                                  species_reference_index=species_reference_index,
                                                                                  curve_segment_index=curve_segment_index)
                else:
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(target_element.get_target_id(), sub_element.get_x(),
                                                                                species_reference_index=species_reference_index,
                                                                                curve_segment_index=curve_segment_index)
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(target_element.get_target_id(), sub_element.get_y(),
                                                                                species_reference_index=species_reference_index,
                                                                                curve_segment_index=curve_segment_index)
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(target_element.get_target_id(), sub_element.get_x(),
                                                                                  species_reference_index=species_reference_index,
                                                                                  curve_segment_index=curve_segment_index)
                    sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(target_element.get_target_id(), sub_element.get_y(),
                                                                                  species_reference_index=species_reference_index,
                                                                                  curve_segment_index=curve_segment_index)

    def set_curve_target_segment(self, sbmlnetwork_object, target_element, species_reference_index):
        sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceCubicBezierCurveSegment(target_element.get_target_id(),
                                                                      species_reference_index=species_reference_index)
        curve_segment_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(target_element.get_target_id(),
                                                                                     species_reference_index=species_reference_index) - 1
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(target_element.get_target_id(), target_element.get_start_x(),
                                                                      species_reference_index=species_reference_index,
                                                                      curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(target_element.get_target_id(), target_element.get_start_y(),
                                                                      species_reference_index=species_reference_index,
                                                                      curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(target_element.get_target_id(), target_element.get_start_x(),
                                                                      species_reference_index=species_reference_index,
                                                                      curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(target_element.get_target_id(), target_element.get_start_y(),
                                                                      species_reference_index=species_reference_index,
                                                                      curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(target_element.get_target_id(), target_element.get_end_x(),
                                                                    species_reference_index=species_reference_index,
                                                                    curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(target_element.get_target_id(), target_element.get_end_y(),
                                                                    species_reference_index=species_reference_index,
                                                                    curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(target_element.get_target_id(), target_element.get_end_x(),
                                                                      species_reference_index=species_reference_index,
                                                                      curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(target_element.get_target_id(), target_element.get_end_y(),
                                                                      species_reference_index=species_reference_index,
                                                                      curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineWidth(target_element.get_target_id(), species_reference_index=species_reference_index, line_width=2.0)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineColor(target_element.get_target_id(), color=self.border_color,
                                                                      species_reference_index=species_reference_index)
        
    def set_curve_line_ending(self, sbmlnetwork_object, target_element, species_reference_index):
        if target_element.get_type() == "necessary stimulation":
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxX(target_element.get_target_id(),
                                                                         sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxX(
                                                                             target_element.get_target_id(),
                                                                             species_reference_index=species_reference_index) +
                                                                         self.line_ending_horizontal_padding,
                                                                         species_reference_index=species_reference_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeType(target_element.get_target_id(), "triangle",
                                                                               species_reference_index=species_reference_index)
            geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(target_element.get_target_id(),
                                                                                                       species_reference_index=species_reference_index) - 1
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(target_element.get_target_id(), x=0.0,
                                                                                   segment_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(target_element.get_target_id(), y=0.0,
                                                                                   segment_index=0, layout_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(target_element.get_target_id(), x=12.0,
                                                                                   segment_index=1,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(target_element.get_target_id(), y=6.0,
                                                                                   segment_index=1, layout_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(target_element.get_target_id(), x=0.0,
                                                                                   segment_index=2,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(target_element.get_target_id(), y=12.0,
                                                                                   segment_index=2, layout_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBorderColor(target_element.get_target_id(), border_color=self.border_color,
                                                                        species_reference_index=species_reference_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBorderWidth(target_element.get_target_id(),
                                                                                       border_width=2.0,
                                                                                       species_reference_index=species_reference_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingFillColor(target_element.get_target_id(), fill_color=self.fill_color,
                                                                      species_reference_index=species_reference_index)

            sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceLineEndingGeometricShape(target_element.get_target_id(), "rendercurve",
                                                                           species_reference_index=species_reference_index)
            geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(target_element.get_target_id(),
                                                                                                       species_reference_index=species_reference_index) - 1
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(target_element.get_target_id(), x=-5.0,
                                                                                   segment_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(target_element.get_target_id(), y=-2.0,
                                                                                   segment_index=0, layout_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(target_element.get_target_id(), x=-5.0,
                                                                                   segment_index=1,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)
            sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(target_element.get_target_id(), y=14.0,
                                                                                   segment_index=1, layout_index=0,
                                                                                   species_reference_index=species_reference_index,
                                                                                   index=geometric_shape_index)

    def get_source_elements(self):
        source_elements = []
        logic_port_ids = self.get_logic_port_ids()
        for sub_element in self.sub_elements:
            if sub_element.get_type() == "logic port":
                logic_port_ids.append(sub_element.get_id())
        for sbgn_element in self.sbgn_elements:
            if sbgn_element.get_type() == "logic arc" and sbgn_element.get_target_id() in logic_port_ids:
                source_elements.append(sbgn_element)

        return source_elements

    def get_target_element(self):
        target_element = None
        logic_port_ids = self.get_logic_port_ids()
        for sbgn_element in self.sbgn_elements:
            if sbgn_element.get_super_type() == "connecting arc" and sbgn_element.get_source_id() in logic_port_ids:
                target_element = sbgn_element
                break

        return target_element

    def get_logic_port_ids(self):
        logic_port_ids = []
        for sub_element in self.sub_elements:
            if sub_element.get_type() == "logic port":
                logic_port_ids.append(sub_element.get_id())

        return logic_port_ids

    def set_text_style(self, sbmlnetwork_object):
        sbmlnetwork_object.libsbmlnetwork.setFontSize(self.get_id(), 14)
        sbmlnetwork_object.libsbmlnetwork.setFontWeight(self.get_id(), "bold")

    def __str__(self):
        return super().__str__() + ", sub_elements: " + str(self.sub_elements)
