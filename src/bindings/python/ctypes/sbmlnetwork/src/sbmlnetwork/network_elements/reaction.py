from .network_element_base import NetworkElementBase
from .visual_elements import *

class Reaction(NetworkElementBase):

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index):
        super().__init__(libsbmlnetwork, element_id, graphical_object_index)

    def get_reaction_id(self):
        return self.element_id

    def get_center(self):
        return ReactionCenter(self.libsbmlnetwork, self.element_id, self.graphical_object_index)

    def get_curves_list(self, species = None):
        from .species import Species

        curves = CurveList(libsbmlnetwork=self.libsbmlnetwork)
        species_id = None
        species_glyph_index = 0
        if species is not None:
            if isinstance(species, str):
                species_id = species
            elif isinstance(species, Species):
                species_id = species.get_species_id()
                species_glyph_index = species.get_graphical_object_index()
        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id,
                                                                              reaction_glyph_index=self.graphical_object_index)):
            species_reference_species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(
                reaction_id=self.element_id,
                reaction_glyph_index=self.graphical_object_index,
                species_reference_index=species_reference_index
            )
            species_glyph_index_in_reaction = self.libsbmlnetwork.getSpeciesGlyphIndex(
                species_id=species_id,
                reaction_id=self.element_id,
                reaction_glyph_index=self.graphical_object_index
            )
            if species_id is not None and (species_id != species_reference_species_id or species_glyph_index != species_glyph_index_in_reaction):
                continue
            curves.append(Curve(self.libsbmlnetwork, self.element_id, self.graphical_object_index, species_reference_index))

        return curves

    def get_species_list(self,  species_ids = None):
        from .species import Species
        from .network_element_lists import SpeciesList

        species = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
            species_index = self.libsbmlnetwork.getSpeciesGlyphIndex(species_id=species_id, reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)
            if species_id == "":
                if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index):
                    species_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
                    species_index = 0
                else:
                    continue
            if (species_ids is None or
                    (isinstance(species_ids, list) and species_id in species_ids) or
                    (isinstance(species_ids, str) and species_id == species_ids)):
                species.append(Species(self.libsbmlnetwork, species_id, species_index))

        return species

    def get_species_ids(self):
        species_ids = []
        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
            species_ids.append(species_id)

        return species_ids

    def get_empty_species(self):
        from .species import Species

        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index):
                species_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
                species_index = 0
                return Species(self.libsbmlnetwork, species_id, species_index)

        return None

    def get_compartment_id(self):
        return self.libsbmlnetwork.getGraphicalObjectCompartmentId(entity_id=self.element_id, graphical_object_index=self.graphical_object_index)

    def create_alias(self):
        if self.libsbmlnetwork.createAliasReactionGlyph(reaction_id=self.element_id) == 0:
            return Reaction(self.libsbmlnetwork, self.element_id, self.libsbmlnetwork.getNumReactionGlyphs(reaction_id=self.element_id) - 1)

    def assign_species(self, species):
        species_ids = self.get_species_ids()
        if species.get_species_id() in species_ids:
            if self.libsbmlnetwork.setSpeciesGlyphIndexInReactionGlyph(species_id=species.get_species_id(),
                                                            reaction_id=self.element_id,
                                                            reaction_glyph_index=self.graphical_object_index,
                                                            index=species.get_graphical_object_index()) == 0:
                return True

        return False

    def move(self, delta: tuple[float, float], move_connected_species: bool = False):
        is_moved = super().move(delta)
        if not is_moved:
            return False

        is_moved = self.get_curves_list().move(delta)
        if not all(is_moved):
            return False

        if move_connected_species:
            is_moved = self.get_species_list().move(delta, move_connected_curves=False)
            if not all(is_moved):
                return False

        #ToDo: add the option to move the species connected curves that are not connected to this reaction

        return True

    def __str__(self):
        result = []
        result.append(f"reaction id: {self.get_reaction_id()}")
        result.append(f"id: {self.get_id()}")
        result.append(f"compartment id: {self.get_compartment_id() or 'n/a'}")
        result.append(f"position: {self.get_position()}")
        result.append(f"size: {self.get_size()}")

        shapes = self.get_shapes_list()
        result.append("Shapes:")
        if shapes:
            for shape in shapes:
                result.append("\n".join(["    " + line for line in str(shape).split("\n")]))
                if shape != shapes[-1]:
                    result.append("----")
        else:
            result.append("    None")

        labels = self.get_labels_list()
        result.append("Labels:")
        for label in labels:
            result.append("\n".join(["    " + line for line in str(label).split("\n")]))
            if label != labels[-1]:
                result.append("----")

        curves = self.get_curves_list()
        result.append("Curves:")
        for curve in curves:
            result.append("\n".join(["    " + line for line in str(curve).split("\n")]))
            if curve != curves[-1]:
                result.append("----")

        return "\n".join(result)

    def __repr__(self):
        return f"Reaction(id={self.element_id}, index={self.graphical_object_index})"
