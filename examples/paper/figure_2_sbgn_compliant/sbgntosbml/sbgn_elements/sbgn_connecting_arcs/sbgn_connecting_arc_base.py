from ..sbgn_element_base import SBGNElementBase
from ..utils import find_element, find_parent_element


class SBGNConnectingArcBase(SBGNElementBase):

    def __init__(self, element_id, source_id, target_id, start_x, start_y, end_x, end_y, intermediate_points=None, sub_elements=None):
        super(SBGNConnectingArcBase, self).__init__(element_id, sub_elements)
        self.source_id = source_id
        self.target_id = target_id
        self.start_x = start_x
        self.start_y = start_y
        self.end_x = end_x
        self.end_y = end_y
        self.intermediate_points = None
        if isinstance(intermediate_points, list):
            if all(isinstance(point, tuple) and len(point) == 2 for point in intermediate_points):
                self.intermediate_points = intermediate_points
        self.line_ending_horizontal_padding = 0.0

    @staticmethod
    def get_super_type():
        return "connecting arc"

    def get_source_id(self):
        return self.source_id

    def set_source_id(self, source_id):
        self.source_id = source_id

    def get_target_id(self):
        return self.target_id

    def set_target_id(self, target_id):
        self.target_id = target_id

    def get_start_x(self):
        return self.start_x

    def set_start_x(self, start_x):
        self.start_x = start_x

    def get_start_y(self):
        return self.start_y

    def set_start_y(self, start_y):
        self.start_y = start_y

    def get_end_x(self):
        return self.end_x

    def set_end_x(self, end_x):
        self.end_x = end_x

    def get_end_y(self):
        return self.end_y

    def set_end_y(self, end_y):
        self.end_y = end_y

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        source = find_parent_element(self.get_source_id(), sbgn_elements)
        target = find_parent_element(self.get_target_id(), sbgn_elements)
        if source is not None and target is not None:
            if source.get_super_type() == "entity pool node" and target.get_super_type() == "process node":
                self.set_geometric_shape_features(sbmlnetwork_object, target, source)
            elif source.get_super_type() == "process node" and target.get_super_type() == "entity pool node":
                self.set_geometric_shape_features(sbmlnetwork_object, source, target)

    def set_geometric_shape_features(self, sbmlnetwork_object, reaction, species):
        species_reference_index = species.get_connected_species_reference_index(sbmlnetwork_object, reaction.get_id())

        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineWidth(reaction.get_id(), species_reference_index=species_reference_index, line_width=2.0)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineColor(reaction.get_id(), species_reference_index=species_reference_index, color="black")

        # curve points
        while sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction.get_id(), species_reference_index=species_reference_index) > 0:
            sbmlnetwork_object.libsbmlnetwork.removeSpeciesReferenceCurveSegment(reaction.get_id(), species_reference_index=species_reference_index, curve_segment_index=0)
        sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceCubicBezierCurveSegment(reaction.get_id(), species_reference_index=species_reference_index)
        curve_segment_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction.get_id(), species_reference_index=species_reference_index) - 1
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(reaction.get_id(), self.get_start_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(reaction.get_id(), self.get_start_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(reaction.get_id(), self.get_start_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(reaction.get_id(), self.get_start_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        if self.intermediate_points is not None:
            for i, point in enumerate(self.intermediate_points):
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(reaction.get_id(), point[0], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(reaction.get_id(), point[1], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(reaction.get_id(), point[0], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(reaction.get_id(), point[1], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceCubicBezierCurveSegment(reaction.get_id(), species_reference_index=species_reference_index)
                curve_segment_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction.get_id(), species_reference_index=species_reference_index) - 1
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(reaction.get_id(), point[0], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(reaction.get_id(), point[1], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(reaction.get_id(), point[0], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
                sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(reaction.get_id(), point[1], species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(reaction.get_id(), self.get_end_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(reaction.get_id(), self.get_end_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(reaction.get_id(), self.get_end_x(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(reaction.get_id(), self.get_end_y(), species_reference_index=species_reference_index, curve_segment_index=curve_segment_index)

        # line ending
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxX(reaction.get_id(),
                                                                     sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxX(reaction.get_id(),
                                                                                                                                  species_reference_index=species_reference_index) +
                                                                     self.line_ending_horizontal_padding,
                                                                     species_reference_index=species_reference_index)





