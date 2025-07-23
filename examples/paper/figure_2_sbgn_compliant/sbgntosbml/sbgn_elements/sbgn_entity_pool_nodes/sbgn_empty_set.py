from .sbgn_entity_pool_node_base import SBGNEntityPoolNodeBase
import math


class SBGNEmptySet(SBGNEntityPoolNodeBase):

    def __init__(self, node_id, reaction_id, x, y, width, height, border_color=None, fill_color=None, text="", sub_elements=None):
        super(SBGNEmptySet, self).__init__(node_id, x, y, width, height, border_color, fill_color, text, sub_elements)
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
        self.load_sbml_info_with_sub_elements(sbmlnetwork_object, parent_element)
        sbmlnetwork_object.libsbmlnetwork.setId(self.get_id_in_model(sbmlnetwork_object), self.get_id())
        self.add_geometric_shape(sbmlnetwork_object, parent_element)

    def initialize_sbml_info(self, sbmlnetwork_object, parent_element):
        if parent_element.get_id() == self.get_id():
            empty_species_glyph_id = ""
            for species_reference_index in range(sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferences(self.reaction_id)):
                if sbmlnetwork_object.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(self.reaction_id,
                                                                             species_reference_index=species_reference_index):
                    empty_species_glyph_id = sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(self.reaction_id,
                                                                                      species_reference_index=species_reference_index)
            if empty_species_glyph_id != "":
                sbmlnetwork_object.libsbmlnetwork.setX(empty_species_glyph_id, self.get_x(), update_curves=False)
                sbmlnetwork_object.libsbmlnetwork.setY(empty_species_glyph_id, self.get_y(), update_curves=False)
                sbmlnetwork_object.libsbmlnetwork.setWidth(empty_species_glyph_id, self.get_width(), update_curves=False)
                sbmlnetwork_object.libsbmlnetwork.setHeight(empty_species_glyph_id, self.get_height(), update_curves=False)
                sbmlnetwork_object.libsbmlnetwork.removeText(empty_species_glyph_id)
            else:
                raise ValueError("Empty set node must be associated with an empty species glyph.")

    def get_id_in_model(self, sbmlnetwork_object):
        model_id = ""
        for reaction_glyph_index in range(
                sbmlnetwork_object.libsbmlnetwork.getNumReactionGlyphs(self.get_reaction_id())):
            for species_reference_index in range(
                    sbmlnetwork_object.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.get_reaction_id(),
                                                                              reaction_glyph_index=reaction_glyph_index)):
                if sbmlnetwork_object.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(
                        reaction_id=self.get_reaction_id(), reaction_glyph_index=reaction_glyph_index,
                        species_reference_index=species_reference_index):
                    model_id = sbmlnetwork_object.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(
                        reaction_id=self.get_reaction_id(), reaction_glyph_index=reaction_glyph_index,
                        species_reference_index=species_reference_index)
                    break
        return model_id

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        # border color
        sbmlnetwork_object.libsbmlnetwork.setBorderColor(parent_element.get_id(), self.border_color)
        # border width
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderWidth(parent_element.get_id(), geometric_shape_index=0,
                                                                       border_width=4.0)
        # fill color
        sbmlnetwork_object.libsbmlnetwork.setFillColor(parent_element.get_id(), self.fill_color)
