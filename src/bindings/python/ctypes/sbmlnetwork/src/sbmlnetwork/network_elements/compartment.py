from .network_element_base import NetworkElementBase
from .species import Species
from .reaction import Reaction
from .network_element_lists import *


class Compartment(NetworkElementBase):

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index):
        super().__init__(libsbmlnetwork, element_id, graphical_object_index)

    def get_compartment_id(self):
        return self.element_id

    def get_species_list(self):
        species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        species_ids = self.libsbmlnetwork.getListOfSpeciesIds()
        for species_id in species_ids:
            num_species_glyphs = self.libsbmlnetwork.getNumSpeciesGlyphs(species_id=species_id)
            for species_glyph_index in range(num_species_glyphs):
                if self.libsbmlnetwork.getGraphicalObjectCompartmentId(entity_id=species_id, graphical_object_index=self.graphical_object_index) == self.element_id:
                    species_list.append(Species(self.libsbmlnetwork, species_id, species_glyph_index))

        return species_list

    def get_reactions_list(self):
        reactions_list = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        reaction_ids = self.libsbmlnetwork.getListOfReactionIds()
        for reaction_id in reaction_ids:
            num_reaction_glyphs = self.libsbmlnetwork.getNumReactionGlyphs(reaction_id=reaction_id)
            for reaction_glyph_index in range(num_reaction_glyphs):
                if self.libsbmlnetwork.getGraphicalObjectCompartmentId(entity_id=reaction_id,
                                                            graphical_object_index=self.graphical_object_index) == self.element_id:
                    reactions_list.append(Reaction(self.libsbmlnetwork, reaction_id, reaction_glyph_index))

        return reactions_list

    def __str__(self):
        result = []
        result.append(f"compartment id: {self.get_compartment_id()}")
        result.append(f"id: {self.get_id()}")
        species_list = self.get_species_list()
        species_ids = [species.get_species_id() for species in species_list]
        result.append(f"species: {', '.join(species_ids)}")

        reactions_list = self.get_reactions_list()
        reaction_ids = [reaction.get_reaction_id() for reaction in reactions_list]
        result.append(f"reactions: {', '.join(reaction_ids)}")

        result.append(f"position: {self.get_position()}")
        result.append(f"size: {self.get_size()}")

        shapes = self.get_shapes_list()
        result.append("Shapes:")
        for shape in shapes:
            result.append("\n".join(["    " + line for line in str(shape).split("\n")]))
            if shape != shapes[-1]:
                result.append("----")

        labels = self.get_labels_list()
        result.append("Labels:")
        for label in labels:
            result.append("\n".join(["    " + line for line in str(label).split("\n")]))
            if label != labels[-1]:
                result.append("----")


        return "\n".join(result)

    def __repr__(self):
        return f"Compartment(id={self.element_id}, index={self.graphical_object_index})"
