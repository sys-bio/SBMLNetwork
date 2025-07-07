from .sbgn_connecting_arc_base import SBGNConnectingArcBase


class SBGNNecessaryStimulation(SBGNConnectingArcBase):

    def __init__(self, element_id, source_id, target_id, start_x, start_y, end_x, end_y,
                 control_point1_x=None, control_point1_y=None, control_point2_x=None, control_point2_y=None,
                 intermediate_points=None, border_color=None, fill_color=None, sub_elements=None):
        super(SBGNNecessaryStimulation, self).__init__(element_id, source_id, target_id, start_x, start_y, end_x, end_y,
                                                        control_point1_x, control_point1_y, control_point2_x, control_point2_y,
                                                        intermediate_points, border_color, fill_color, sub_elements)
        self.line_ending_horizontal_padding = -3.5

    @staticmethod
    def get_type():
        return "necessary stimulation"

    def set_geometric_shape_features(self, sbmlnetwork_object, reaction, species):
        super(SBGNNecessaryStimulation, self).set_geometric_shape_features(sbmlnetwork_object, reaction, species)
        species_reference_index = sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceIndexAssociatedWithSpecies(species.get_id(),
                                                                                                   reaction.get_id())
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeType(reaction.get_id(), "triangle",
                                                                           species_reference_index=species_reference_index)
        geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction.get_id(),
                                                                                                   species_reference_index=species_reference_index) - 1
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction.get_id(), x=0.0,
                                                                               segment_index=0,
                                                                               species_reference_index=species_reference_index,
                                                                               index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction.get_id(), y=0.0,
                                                                               segment_index=0, layout_index=0,
                                                                               species_reference_index=species_reference_index,
                                                                               index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction.get_id(), x=12.0,
                                                                               segment_index=1,
                                                                               species_reference_index=species_reference_index,
                                                                               index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction.get_id(), y=6.0,
                                                                               segment_index=1, layout_index=0,
                                                                               species_reference_index=species_reference_index,
                                                                               index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction.get_id(), x=0.0,
                                                                               segment_index=2,
                                                                               species_reference_index=species_reference_index,
                                                                               index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction.get_id(), y=12.0,
                                                                               segment_index=2, layout_index=0,
                                                                               species_reference_index=species_reference_index,
                                                                               index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBorderWidth(reaction.get_id(), border_width=2.0,
                                                                    species_reference_index=species_reference_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBorderColor(reaction.get_id(), border_color=self.border_color,
                                                                  species_reference_index=species_reference_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingFillColor(reaction.get_id(), fill_color=self.fill_color,
                                                                 species_reference_index=species_reference_index)

        sbmlnetwork_object.libsbmlnetwork.addSpeciesReferenceLineEndingGeometricShape(reaction.get_id(), "rendercurve", species_reference_index=species_reference_index)
        geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction.get_id(), species_reference_index=species_reference_index) - 1
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction.get_id(), x=-5.0, segment_index=0, species_reference_index=species_reference_index, index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction.get_id(), y=-2.0, segment_index=0, layout_index=0, species_reference_index=species_reference_index, index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction.get_id(), x=-5.0, segment_index=1, species_reference_index=species_reference_index, index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction.get_id(), y=14.0, segment_index=1, layout_index=0, species_reference_index=species_reference_index, index=geometric_shape_index)
