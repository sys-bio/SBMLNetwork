from .sbgn_connecting_arc_base import SBGNConnectingArcBase


class SBGNCatalysis(SBGNConnectingArcBase):

    def __init__(self, element_id, source_id, target_id, start_x, start_y, end_x, end_y,
                 control_point1_x=None, control_point1_y=None, control_point2_x=None, control_point2_y=None,
                 intermediate_points=None, border_color=None, fill_color=None, sub_elements=None):
        super(SBGNCatalysis, self).__init__(element_id, source_id, target_id, start_x, start_y, end_x, end_y,
                                            control_point1_x, control_point1_y, control_point2_x, control_point2_y,
                                            intermediate_points, border_color, fill_color, sub_elements)
        self.line_ending_horizontal_padding = -3.5

    @staticmethod
    def get_type():
        return "catalysis"

    def set_geometric_shape_features(self, sbmlnetwork_object, reaction, species):
        super(SBGNCatalysis, self).set_geometric_shape_features(sbmlnetwork_object, reaction, species)
        species_reference_index = sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceIndexAssociatedWithSpecies(species.get_id(),
                                                                                                   reaction.get_id())
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBorderColor(reaction.get_id(), border_color=self.border_color,
                                                                    species_reference_index=species_reference_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingBorderWidth(reaction.get_id(), border_width=2.0,
                                                                    species_reference_index=species_reference_index)
        sbmlnetwork_object.libsbmlnetwork.setSpeciesReferenceLineEndingFillColor(reaction.get_id(), fill_color=self.fill_color,
                                                                 species_reference_index=species_reference_index)