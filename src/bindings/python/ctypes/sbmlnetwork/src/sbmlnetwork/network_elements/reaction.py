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
            return self.get_center_shapes_list().get_types()

        return None

    @property
    def shape_type(self):
        return self.get_shape_type()

    def get_border_color(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_border_colors()

        return None

    def set_border_color(self, border_color: str):
        if self.is_center_shapes():
            return self.get_center_shapes_list().set_border_colors(border_color)

        return False

    def set_border_colors(self, border_color: str):
        return self.set_border_color(border_color) and self.set_arrow_head_border_colors(border_color)

    def get_border_thicknesses(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_border_thicknesses()

        return None

    def set_border_thickness(self, thickness: float):
        if self.is_center_shapes():
            return self.get_center_shapes_list().set_border_thicknesses(thickness)

        return False

    def set_border_thicknesses(self, thickness: float):
        return self.set_border_thickness(thickness) and self.set_arrow_head_border_thicknesses()

    def get_fill_color(self):
        if self.is_center_shapes():
            return self.get_center_shapes_list().get_fill_colors()

        return None

    def set_fill_color(self, fill_color: str or tuple or list):
        if self.is_center_shapes():
            return self.get_center_shapes_list().set_fill_colors(fill_color)

        return False

    def set_fill_colors(self, fill_color: str or tuple or list):
        return self.set_fill_color(fill_color) and self.set_arrow_head_fill_colors(fill_color)

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
            if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index,
                                                                          species_reference_index=species_reference_index):
                species_reference_species_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.element_id,
                                                                                                          reaction_glyph_index=self.graphical_object_index,
                                                                                                          species_reference_index=species_reference_index)
                species_glyph_index_in_reaction = 0
            if species_id is not None and (species_id != species_reference_species_id or species_glyph_index != species_glyph_index_in_reaction):
                continue
            curves.append(Curve(self.libsbmlnetwork, self.element_id, self.graphical_object_index, species_reference_index))

        return curves

    def get_curves(self, species=None):
        return self.get_curves_list(species)

    @property
    def curves(self):
        return self.get_curves()

    def get_center_curve_color(self):
        if self.is_center_curve():
            return self.get_center_curve().get_color()

        return None

    def set_center_curve_color(self, color):
        if self.is_center_curve():
            return self.get_center_curve().set_color(color)

        return False

    @property
    def center_curve_color(self):
        return self.get_center_curve_color()

    @center_curve_color.setter
    def center_curve_color(self, color):
        self.set_center_curve_color(color)

    def get_curve_colors(self):
        return self.get_curves_list().get_colors()

    def set_curve_colors(self, color):
        return self.get_curves_list().set_colors(color)

    @property
    def curves_colors(self):
        return self.get_curve_colors()

    @curves_colors.setter
    def curves_colors(self, color):
        self.set_curve_colors(color)

    def set_colors(self, color):
        if self.is_center_curve():
            if not self.get_center_curve().set_color(color):
                return False
        else:
            if not self.set_border_color(color):
                return False
            if not self.set_fill_color(color):
                return False

        if not self.get_curves().set_colors(color):
            return False

        if len(self.get_arrow_heads()):
            if not self.set_arrow_head_fill_colors(color):
                return False
            if not self.set_arrow_head_border_colors(color):
                return False

        if not self.set_font_color(color):
            return False

        return True

    def get_center_curve_thickness(self):
        if self.is_center_curve():
            return self.get_center_curve().get_thickness()

        return None

    def set_center_curve_thickness(self, thickness):
        if self.is_center_curve():
            return self.get_center_curve().set_thickness(thickness)

        return False

    @property
    def center_curve_thickness(self):
        return self.get_center_curve_thickness()

    @center_curve_thickness.setter
    def center_curve_thickness(self, thickness):
        self.set_center_curve_thickness(thickness)

    def get_curve_thicknesses(self):
        return self.get_curves_list().get_thicknesses()

    def set_curve_thicknesses(self, thickness):
        return self.get_curves_list().set_thicknesses(thickness)

    @property
    def curve_thicknesses(self):
        return self.get_curve_thicknesses()

    @curve_thicknesses.setter
    def curve_thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    def set_thicknesses(self, thickness):
        if self.is_center_curve():
            if not self.get_center_curve().set_thickness(thickness):
                return False
        else:
            if not self.set_border_thickness(thickness):
                return False

        if not self.get_curves().set_thicknesses(thickness):
            return False

        if len(self.get_arrow_heads()):
            if not self.set_arrow_head_border_thicknesses(thickness):
                return False

        return True

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
        return self.get_arrow_heads().get_shape_type()

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def set_arrow_head_shapes(self, shape: str):
        return self.get_arrow_heads().set_shape(shape)

    @arrow_head_shapes.setter
    def arrow_head_shapes(self, shape: str):
        self.set_arrow_head_shapes(shape)

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
        return self.get_arrow_heads().get_border_thickneses()

    def set_arrow_head_border_thicknesses(self, thickness: float):
        return self.get_arrow_heads().set_border_thicknesses(thickness)

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

    def move_arrow_head_relative_positions_to(self, relative_position: float):
        return self.get_arrow_heads().move_relative_positions_to(relative_position)

    def move_arrow_head_relative_positions_by(self, delta: float):
        return self.get_arrow_heads().move_relative_positions_by(delta)

    def get_species_list(self,  species_ids=None):
        from .species import Species
        from .network_element_lists import SpeciesList

        species = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        species_set = {}
        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
            species_index = self.libsbmlnetwork.getSpeciesGlyphIndex(species_id=species_id, reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)
            if species_id == "":
                if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index):
                    species_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
                    species_index = 0
                else:
                    continue
            species_set_for_species_id = species_set.get(species_id, set())
            species_ids_is_valid = (species_ids is None or
                                    (isinstance(species_ids, list) and species_id in species_ids) or
                                    (isinstance(species_ids, str) and species_id == species_ids))

            if species_ids_is_valid and species_index not in species_set_for_species_id:
                species_set.setdefault(species_id, set()).add(species_index)
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

    def get_empty_species(self):
        from .species import Species

        for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index)):
            if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index):
                species_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=species_reference_index)
                species_index = 0
                return Species(self.libsbmlnetwork, species_id, species_index)

        return None

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
                                                                       species_glyph_index=species.get_graphical_object_index()) == 0:
                return True

        return False

    def move_to(self, position: tuple[float, float], move_connected_species: bool = True):
        return self.move_by((position[0] - self.get_position()[0], position[1] - self.get_position()[1]),
                            move_connected_species)

    def move_by(self, delta: tuple[float, float], move_connected_species: bool = True):
        if self._can_move_by(delta):
            is_moved = super().move_by(delta)
            if not is_moved:
                return False

            is_moved = self.get_curves_list().move_by(delta)
            if not all(is_moved):
                return False

            if move_connected_species:
                is_moved = self.get_species_list().move_by(delta, move_connected_curves=False)
                if not all(is_moved):
                    return False

            other_curves = self.get_species_list().get_connected_curves()
            for curve in other_curves:
                if curve.get_reaction().get_id() != self.get_id():
                    if curve.get_role() in curve.get_modifier_role_options():
                        curve.move_start_by(delta)
                    else:
                        curve.move_end_by(delta, adjust_end_point_for_uni_uni_reaction=True)

            return True

        raise ValueError(f"Reaction {self.get_reaction_id()} cannot be moved by {delta} because it would lead to negative coordinates.")

    def align_horizontal(self, center_at: tuple[float, float] = None, spread_width: float = None,
                         reactants_order: list = None, products_order: list = None, modifiers_order: list = None,
                         reactants_placement: str = "both", products_placement: str = "both", modifiers_placement: str = "both"):
        from ..features.align import HorizontalAlign

        horizontal_align = HorizontalAlign(self.libsbmlnetwork)
        return horizontal_align.align(self, center_at, spread_width,
                                      reactants_order, products_order, modifiers_order,
                                      reactants_placement, products_placement, modifiers_placement)

    def align_vertical(self, center_at: tuple[float, float] = None, spread_height: float = None,
                       reactants_order: list = None, products_order: list = None, modifiers_order: list = None,
                       reactants_placement: str = "both", products_placement: str = "both", modifiers_placement: str = "both"):
        from ..features.align import VerticalAlign

        vertical_align = VerticalAlign(self.libsbmlnetwork)
        return vertical_align.align(self, center_at, spread_height,
                                    reactants_order, products_order, modifiers_order,
                                    reactants_placement, products_placement, modifiers_placement)

    def align_circle(self, center_at: tuple[float, float] = None, radius: float = None, arc_start: float = -180,
                     arc_end: float = -90, clockwise: bool = False,
                     reactants_order: list = None, products_order: list = None, modifiers_order: list = None,
                     reactants_placement: str = "both", products_placement: str = "both", modifiers_placement: str = "both"):
        from ..features.align import CircleAlign

        circle_align = CircleAlign(self.libsbmlnetwork)
        return circle_align.align(self, center_at, radius, arc_start, arc_end, clockwise,
                                  reactants_order, products_order, modifiers_order,
                                  reactants_placement, products_placement, modifiers_placement)

    def show_reversibility(self, are_subsrate_directions_reversed: bool = False):
        if self.libsbmlnetwork.isReversible(reaction_id=self.get_reaction_id()):
            product_head_name = ""
            for curve in self.get_curves():
                if curve.get_role() in curve.get_product_role_options():
                    arrow_head = curve.get_arrow_head()
                    if arrow_head:
                        product_head_name = arrow_head.get_id()
                        break

            if product_head_name:
                for curve in self.get_curves():
                    if curve.get_role() in curve.get_substrate_role_options():
                        if are_subsrate_directions_reversed:
                            self.libsbmlnetwork.setSpeciesReferenceStartHead(reaction_id=self.get_reaction_id(), reaction_glyph_index=self.graphical_object_index, species_reference_index=curve.species_reference_index, head=product_head_name)
                        else:
                            self.libsbmlnetwork.setSpeciesReferenceEndHead(reaction_id=self.get_reaction_id(), reaction_glyph_index=self.graphical_object_index, species_reference_index=curve.species_reference_index, head=product_head_name)

        return False

    def get_info(self):
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

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"Reaction(id={self.element_id}, index={self.graphical_object_index})"
