from ..sbgn_node_base import SBGNNodeBase
import math


class SBGNEntityPoolNodeBase(SBGNNodeBase):

    def __init__(self, node_id, x, y, width, height, border_color=None, fill_color=None,
                 text="", text_x=math.nan, text_y=math.nan, text_width=math.nan, text_height=math.nan,
                 font_size=14, font_color=None, text_vertical_alignment="middle", text_horizontal_alignment="middle", sub_elements=None):
        super(SBGNEntityPoolNodeBase, self).__init__(node_id, x, y, width, height, border_color, fill_color, text, text_x, text_y, text_width, text_height,
                                                     font_size, font_color, text_vertical_alignment, text_horizontal_alignment,
                                                     sub_elements)

    @staticmethod
    def get_super_type():
        return "entity pool node"

    @staticmethod
    def get_border_width():
        return 4.0

    def get_connected_species_reference_index(self, sbmlnetwork_object, reaction_id):
        return sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceIndexAssociatedWithSpecies(self.get_id(), reaction_id)


