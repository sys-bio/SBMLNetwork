from .network_element_base import NetworkElementBase
from .visual_elements import *

class Reaction(NetworkElementBase):

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index):
        super().__init__(libsbmlnetwork, element_id, graphical_object_index)

    def get_reaction_id(self):
        return self.element_id

    @property
    def reaction_id(self):
        return self.get_reaction_id()

    def get_center(self):
        return ReactionCenter(self.libsbmlnetwork, self.element_id, self.graphical_object_index)

    @property
    def center(self):
        return self.get_center()

    def switch_to_curve(self):
        return self.get_center().switch_to_curve()

    def switch_center_to_curve(self):
        return self.get_center().switch_to_curve()

    def switch_to_shapes(self):
        return self.get_center().switch_to_shapes()

    def switch_center_to_shapes(self):
        return self.get_center().switch_to_shapes()

    def is_curve(self):
        return self.get_center().is_curve()

    def is_center_curve(self):
        return self.get_center().is_curve()

    def is_shapes(self):
        return self.get_center().is_shapes()

    def is_center_shapes(self):
        return self.get_center().is_shapes()

    def get_center_curve(self):
        return self.get_center().get_curve()

    @property
    def center_curve(self):
        return self.get_center_curve()

    def get_center_shapes_list(self):
        return self.get_center().get_shapes_list()

    def get_center_shapes(self):
        return self.get_center_shapes_list()

    @property
    def center_shapes(self):
        return self.get_center_shapes()

    def get_shape_type(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_type()

        return None

    @property
    def shape_type(self):
        return self.get_shape_type()

    def get_border_color(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_border_color()

        return None

    def set_border_color(self, border_color: str):
        if self.is_center_shapes():
            return self.get_center_shapes_list().set_border_color(border_color)

        return False

    def set_border_colors(self, border_color: str):
        return self.set_border_color(border_color) and self.set_arrow_head_border_colors()

    def get_border_thickness(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_border_thickness()

        return None

    def set_border_thickness(self, thickness: float):
        if self.is_center_shapes():
            return self.get_center_shapes_list().set_border_thickness(thickness)

        return False

    def set_border_thicknesses(self, thickness: float):
        return self.set_border_thickness(thickness) and self.set_arrow_head_border_thicknesses()

    def get_fill_color(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_fill_color()

        return None

    def set_fill_color(self, fill_color: str or tuple or list):
        if self.is_center_shapes():
            return self.get_center_shapes_list().set_fill_color(fill_color)

        return False

    def set_fill_colors(self, fill_color: str or tuple or list):
        return self.set_fill_color(fill_color) and self.set_arrow_head_fill_colors()

    def get_curves_list(self, species=None):
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

    def get_curves(self, species=None):
        return self.get_curves_list(species)

    @property
    def curves(self):
        return self.get_curves()

    def get_curve_colors(self, species=None):
        if self.is_center_curve():
            return self.get_center_curve().get_color()

        return None

    def get_colors(self, species=None):
        return self.get_curve_colors(species)

    def set_curve_colors(self, color, species=None):
        if self.is_center_curve():
            return self.get_center_curve().set_color(color)

        return False

    def set_colors(self, color, species=None):
        return self.set_curve_colors(color, species)

    @property
    def curves_colors(self):
        return self.get_curve_colors()

    @property
    def colors(self):
        return self.get_curve_colors()

    @curves_colors.setter
    def curves_colors(self, color):
        self.set_curve_colors(color)

    @colors.setter
    def colors(self, color):
        self.set_curve_colors(color)

    def get_curve_thicknesses(self, species=None):
        if self.is_center_curve():
            return self.get_center_curve().get_thickness()

        return None

    def get_thicknesses(self, species=None):
        return self.get_curve_thicknesses(species)

    def set_curve_thicknesses(self, thickness, species=None):
        if self.is_center_curve():
            return self.get_center_curve().set_thickness(thickness)

        return False

    def set_thicknesses(self, thickness, species=None):
        return self.set_curve_thicknesses(thickness, species)

    @property
    def curves_thicknesses(self):
        return self.get_curve_thicknesses()

    @property
    def thicknesses(self):
        return self.get_curve_thicknesses()

    @curves_thicknesses.setter
    def curves_thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    @thicknesses.setter
    def thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    def get_arrow_heads(self):
        return self.get_curves_list().get_arrow_heads()

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_relative_positions(self):
        return self.get_arrow_heads().get_relative_positions()

    def set_arrow_head_relative_positions(self, relative_position: float):
        return self.get_arrow_heads().set_relative_positions(relative_position)

    @property
    def arrow_head_relative_positions(self):
        return self.get_arrow_head_relative_positions()

    @arrow_head_relative_positions.setter
    def arrow_head_relative_positions(self, relative_position: float):
        self.set_arrow_head_relative_positions(relative_position)

    def get_arrow_head_sizes(self):
        return self.get_arrow_heads().get_sizes()

    def set_arrow_head_sizes(self, size: tuple[float, float]):
        return self.get_arrow_heads().set_sizes(size)

    @property
    def arrow_head_sizes(self):
        return self.get_arrow_head_sizes()

    @arrow_head_sizes.setter
    def arrow_head_sizes(self, size: tuple[float, float]):
        self.set_arrow_head_sizes(size)

    def get_arrow_head_shapes(self):
        return self.get_arrow_heads().get_shapes_list()

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def get_arrow_head_shape_types(self):
        return self.get_arrow_heads().get_shape_type()

    @property
    def arrow_head_shape_types(self):
        return self.get_arrow_head_shape_types()

    def get_arrow_head_border_colors(self):
        return self.get_arrow_heads().get_border_colors()

    def set_arrow_head_border_colors(self, border_color: str):
        return self.get_arrow_heads().set_border_colors(border_color)

    @property
    def arrow_head_border_colors(self):
        return self.get_arrow_head_border_colors()

    @arrow_head_border_colors.setter
    def arrow_head_border_colors(self, border_color: str):
        self.set_arrow_head_border_colors(border_color)

    def get_arrow_head_border_thicknesses(self):
        return self.get_arrow_heads().get_border_thickness()

    def set_arrow_head_border_thicknesses(self, thickness: float):
        return self.get_arrow_heads().set_border_thickness(thickness)

    @property
    def arrow_head_border_thicknesses(self):
        return self.get_arrow_head_border_thicknesses()

    @arrow_head_border_thicknesses.setter
    def arrow_head_border_thicknesses(self, thickness: float):
        self.set_arrow_head_border_thicknesses(thickness)

    def get_arrow_head_fill_colors(self):
        return self.get_arrow_heads().get_fill_colors()

    def set_arrow_head_fill_colors(self, fill_color: str or tuple or list):
        return self.get_arrow_heads().set_fill_colors(fill_color)

    @property
    def arrow_head_fill_colors(self):
        return self.get_arrow_head_fill_colors()

    @arrow_head_fill_colors.setter
    def arrow_head_fill_colors(self, fill_color: str or tuple or list):
        self.set_arrow_head_fill_colors(fill_color)

    def get_species_list(self,  species_ids=None):
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

    def get_species(self, species_ids=None):
        return self.get_species_list(species_ids)

    @property
    def species(self):
        return self.get_species()

    def get_species_ids(self):
        species_ids = []
        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
            species_ids.append(species_id)

        return species_ids

    @property
    def species_ids(self):
        return self.get_species_ids()

    def get_empty_species_list(self):
        from .species import Species

        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index):
                species_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
                species_index = 0
                return Species(self.libsbmlnetwork, species_id, species_index)

        return None

    def get_empty_species(self):
        return self.get_empty_species_list()

    @property
    def empty_species(self):
        return self.get_empty_species()

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

    def move(self, delta: tuple[float, float], move_connected_species: bool = True):
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

        other_curves = self.get_species_list().get_connected_curves()
        for curve in other_curves:
            if curve.get_reaction().get_id() != self.get_id():
                if curve.get_role() in curve.get_modifier_role_options():
                    curve.get_start().move(delta)
                else:
                    curve.move_end(delta)

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
