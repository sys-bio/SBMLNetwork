from .sbgn_entity_pool_node_base import SBGNEntityPoolNodeBase
import math


class SBGNEmptySet(SBGNEntityPoolNodeBase):

    def __init__(self, node_id, reaction_id, x, y, width, height, text="", sub_elements=None):
        super(SBGNEmptySet, self).__init__(node_id, x, y, width, height, sub_elements)
        self.reaction_id = reaction_id

    def get_type(self):
        return "empty set"

    def get_reaction_id(self):
        return self.reaction_id

    def set_reaction_id(self, reaction_id):
        self.reaction_id = reaction_id

    def get_connected_species_reference_index(self, sbmlnetwork_object, reaction_id):
        for species_reference_index in range(sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferences(reaction_id)):
            if sbmlnetwork_object.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(self.reaction_id,
                                                                         species_reference_index=species_reference_index):
                return species_reference_index

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        if parent_element is None:
            parent_element = self
        self.initialize_sbml_info(sbmlnetwork_object, parent_element)
        self.add_geometric_shape(sbmlnetwork_object, parent_element)
        self.load_sbml_info_with_sub_elements(sbmlnetwork_object, parent_element)

    def initialize_sbml_info(self, sbmlnetwork_object, parent_element):
        if parent_element.get_id() == self.get_id():
            empty_species_glyph_id = ""
            for species_reference_index in range(sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferences(self.reaction_id)):
                if sbmlnetwork_object.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(self.reaction_id,
                                                                             species_reference_index=species_reference_index):
                    empty_species_glyph_id = sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(self.reaction_id,
                                                                                      species_reference_index=species_reference_index)
            if empty_species_glyph_id != "":
                sbmlnetwork_object.libsbmlnetwork.setX(empty_species_glyph_id, self.get_x())
                sbmlnetwork_object.libsbmlnetwork.setY(empty_species_glyph_id, self.get_y())
                sbmlnetwork_object.libsbmlnetwork.setWidth(empty_species_glyph_id, self.get_width())
                sbmlnetwork_object.libsbmlnetwork.setHeight(empty_species_glyph_id, self.get_height())
                sbmlnetwork_object.libsbmlnetwork.removeText(empty_species_glyph_id)
            else:
                raise ValueError("Empty set node must be associated with an empty species glyph.")