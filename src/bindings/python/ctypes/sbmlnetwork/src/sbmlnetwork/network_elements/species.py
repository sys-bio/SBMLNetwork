from .network_element_base import NetworkElementBase
from .reaction import Reaction
from .network_element_lists import ReactionList
from .visual_elements.visual_element_lists .curve_element_lists import CurveList
from typing import Union


class Species(NetworkElementBase):

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index):
        super().__init__(libsbmlnetwork, element_id, graphical_object_index)

    def get_species_id(self):
        return self.element_id

    @property
    def species_id(self):
        return self.get_species_id()

    def get_compartment_id(self):
        return self.libsbmlnetwork.getGraphicalObjectCompartmentId(entity_id=self.element_id, graphical_object_index=self.graphical_object_index)

    @property
    def compartment_id(self):
        return self.get_compartment_id()

    def get_reactions_list(self):
        reactions_list = ReactionList()
        reaction_ids = self.libsbmlnetwork.getListOfReactionIds()
        for reaction_id in reaction_ids:
            num_reaction_glyphs = self.libsbmlnetwork.getNumReactionGlyphs(reaction_id=reaction_id)
            for reaction_glyph_index in range(num_reaction_glyphs):
                if self.libsbmlnetwork.getSpeciesGlyphIndex(species_id=self.element_id, reaction_id=reaction_id, reaction_glyph_index=reaction_glyph_index) != -1:
                    reactions_list.append(Reaction(self.libsbmlnetwork, reaction_id, reaction_glyph_index))

        return reactions_list

    def get_reactions(self):
        return self.get_reactions_list()

    @property
    def reactions(self):
        return self.get_reactions()

    def get_reaction_ids(self):
        reaction_ids = set()
        reactions = self.get_reactions_list()
        for reaction in reactions:
            reaction_ids.add(reaction.get_reaction_id())

        return reaction_ids

    @property
    def reaction_ids(self):
        return self.get_reaction_ids()

    def get_curves_list(self, reaction: Union[Reaction, str] = None):
        curves = CurveList()
        reactions = self.get_reactions_list()
        for reaction_item in reactions:
            if reaction is None or isinstance(reaction, str) and reaction == reaction_item.get_reaction_id() or isinstance(
                    reaction, Reaction) and reaction == reaction_item:
                curves.extend(reaction_item.get_curves_list(self))

        return curves

    def get_curves(self, reaction: Union[Reaction, str] = None):
        return self.get_curves_list(reaction)

    @property
    def curves(self):
        return self.get_curves()

    def get_connected_curves_list(self, reaction: Union[Reaction, str] = None):
        return self.get_curves_list(reaction)

    def get_connected_curves(self, reaction: Union[Reaction, str] = None):
        return self.get_connected_curves_list(reaction)

    @property
    def connected_curves(self):
        return self.get_connected_curves()

    def get_curve_colors(self, reaction: Union[Reaction, str] = None):
        return self.get_curves_list(reaction).get_colors()

    def set_curve_colors(self, color, reaction: Union[Reaction, str] = None):
        return self.get_curves_list(reaction).set_colors(color)

    @property
    def curve_colors(self):
        return self.get_curve_colors()

    @curve_colors.setter
    def curve_colors(self, color):
        self.set_curve_colors(color)

    def get_curve_thicknesses(self, reaction: Union[Reaction, str] = None):
        return self.get_curves_list(reaction).get_thicknesses()

    def set_curve_thicknesses(self, thickness, reaction: Union[Reaction, str] = None):
        return self.get_curves_list(reaction).set_thicknesses(thickness)

    @property
    def curve_thicknesses(self):
        return self.get_curve_thicknesses()

    @curve_thicknesses.setter
    def curve_thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    def get_arrow_heads(self):
        return self.get_curves_list().get_arrow_heads()

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_shapes(self):
        return self.get_arrow_heads().get_shape_type()

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def set_arrow_head_shapes(self, shape: str):
        return self.get_arrow_heads().set_shapes(shape)

    @arrow_head_shapes.setter
    def arrow_head_shapes(self, shape: str):
        self.set_arrow_head_shapes(shape)

    def get_arrow_head_border_colors(self):
        return self.get_arrow_heads().get_border_color()

    def set_arrow_head_border_colors(self, border_color: str):
        return self.get_arrow_heads().set_border_color(border_color)

    @property
    def arrow_head_border_colors(self):
        return self.get_arrow_head_border_colors()

    @arrow_head_border_colors.setter
    def arrow_head_border_colors(self, border_color: str):
        self.set_arrow_head_border_colors(border_color)

    def get_arrow_head_border_thicknesses(self):
        return self.get_arrow_heads().get_border_thicknesses()

    def set_arrow_head_border_thicknesses(self, thickness: float):
        return self.get_arrow_heads().set_border_thicknesses(thickness)

    @property
    def arrow_head_border_thicknesses(self):
        return self.get_arrow_head_border_thicknesses()

    @arrow_head_border_thicknesses.setter
    def arrow_head_border_thicknesses(self, thickness: float):
        self.set_arrow_head_border_thicknesses(thickness)

    def get_arrow_head_fill_colors(self):
        return self.get_arrow_heads().get_fill_color()

    def set_arrow_head_fill_colors(self, fill_color: str or tuple or list):
        return self.get_arrow_heads().set_fill_color(fill_color)

    @property
    def arrow_head_fill_colors(self):
        return self.get_arrow_head_fill_colors()

    @arrow_head_fill_colors.setter
    def arrow_head_fill_colors(self, fill_color: str or tuple or list):
        self.set_arrow_head_fill_colors(fill_color)

    def move_arrow_head_relative_positions_to(self, relative_position: tuple[float, float]):
        return self.get_arrow_heads().move_relative_positions_to(relative_position)

    def move_arrow_head_relative_positions_by(self, relative_position: tuple[float, float]):
        return self.get_arrow_heads().move_relative_positions_by(relative_position)

    def get_role(self, reaction: Union[Reaction, str]):
        reaction_id = None
        reaction_glyph_index = None
        if isinstance(reaction, Reaction):
            reaction_id = reaction.get_reaction_id()
            reaction_glyph_index = reaction.graphical_object_index
        elif isinstance(reaction, str):
            reaction_id = reaction
            reaction_glyph_index = 0
        if reaction_id is not None and reaction_glyph_index is not None:
            for species_reference_index in range(
                    self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=reaction_id,
                                                                reaction_glyph_index=reaction_glyph_index)):
                if self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=reaction_id,
                                                                    reaction_glyph_index=reaction_glyph_index,
                                                                    species_reference_index=species_reference_index) == self.element_id \
                        or self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=reaction_id,
                                                                                      reaction_glyph_index=reaction_glyph_index,
                                                                                      species_reference_index=species_reference_index) == self.id:
                    return self.libsbmlnetwork.getSpeciesReferenceRole(reaction_id=reaction_id,
                                                                       reaction_glyph_index=reaction_glyph_index,
                                                                       species_reference_index=species_reference_index)

        return None

    def get_role_options(self):
        return self.libsbmlnetwork.getListOfRoles()

    @property
    def role_options(self):
        return self.get_role_options()

    def get_substrate_role_options(self):
        roles = self.get_role_options()
        return [role for role in roles if role in ["substrate", "sidesubstrate", "side substrate", "reactant", "sidereactant", "side reactant"]]

    @property
    def substrate_role_options(self):
        return self.get_substrate_role_options()

    def get_product_role_options(self):
        roles = self.get_role_options()
        return [role for role in roles if role in ["product", "sideproduct", "side product"]]

    @property
    def product_role_options(self):
        return self.get_product_role_options()

    def get_modifier_role_options(self):
        roles = self.get_role_options()
        return [role for role in roles if role not in self.get_substrate_role_options() + self.get_product_role_options()]

    @property
    def modifier_role_options(self):
        return self.get_modifier_role_options()

    def is_empty_species(self):
        reactions = self.get_reactions_list()
        if len(reactions) == 1:
            reaction = reactions[0]
            for species_reference_index in range(
                    self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=reaction.get_reaction_id(),
                                                                reaction_glyph_index=reaction.graphical_object_index)):
                if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=reaction.get_reaction_id(),
                                                                              reaction_glyph_index=reaction.graphical_object_index,
                                                                              species_reference_index=species_reference_index):
                    if self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=reaction.get_reaction_id(),
                                                                                  reaction_glyph_index=reaction.graphical_object_index,
                                                                                  species_reference_index=species_reference_index) == self.element_id:
                        return True

        return False

    def create_alias(self, reaction: Union[Reaction, str]):
        if isinstance(reaction, Reaction):
            reaction_id = reaction.get_reaction_id()
            reaction_glyph_index = reaction.graphical_object_index
        elif isinstance(reaction, str):
            reaction_id = reaction
            reaction_glyph_index = 0
        else:
            raise ValueError("Reaction must be a Reaction object or a string")

        if self.libsbmlnetwork.createAliasSpeciesGlyph(species_id=self.element_id, reaction_id=reaction_id, reaction_glyph_index=reaction_glyph_index) == 0:
            species_glyph_index = self.libsbmlnetwork.getSpeciesGlyphIndex(species_id=self.element_id, reaction_id=reaction_id, reaction_glyph_index=reaction_glyph_index)
            return Species(self.libsbmlnetwork, self.element_id, species_glyph_index)

        return None

    def move_to(self, position: tuple[float, float], move_connected_curves: bool = True):
        return self.move_by((position[0] - self.get_position()[0], position[1] - self.get_position()[1]),
                            move_connected_curves)

    def move_by(self, position: tuple[float, float], move_connected_curves: bool = True):
        if self._can_move_by(position):
            is_moved = super().move_by(position)
            if not is_moved:
                return False

            if move_connected_curves:
                curves = self.get_connected_curves()
                for curve in curves:
                    role = self.get_role(curve.get_reaction())
                    if role in self.get_modifier_role_options():
                        if not curve.move_start_by(position):
                            return False
                    else:
                        if not curve.move_end_by(position, adjust_end_point_for_uni_uni_reaction=True):
                            return False

            return True

        raise ValueError(f"Species {self.get_species_id()} cannot be moved by {position} because it would lead to negative coordinates.")

    def set_size(self, size: tuple[float, float], adjust_font_size: bool = True):
        current_size = self.get_size()
        current_position = self.get_position()
        delta_width = size[0] - current_size[0]
        delta_height = size[1] - current_size[1]
        new_position = (
            current_position[0] - 0.5 * delta_width,
            current_position[1] - 0.5 * delta_height,
        )
        super().set_size(size)
        self.set_position(new_position)
        labels = self.get_labels_list()
        for label in labels:
            label.set_font_size(label.get_font_size() * size[0] / current_size[0])
        center = (new_position[0] + size[0] / 2, new_position[1] + size[1] / 2)
        half_width, half_height = size[0] / 2, size[1] / 2
        for curve in self.get_connected_curves():
            if curve.get_role() in self.get_modifier_role_options():
                cp = curve.get_start()
            else:
                cp = curve.get_end()
            dx = cp[0] - center[0]
            dy = cp[1] - center[1]
            if dx == 0 and dy == 0:
                continue
            scale_x = half_width / abs(dx) if dx != 0 else float('inf')
            scale_y = half_height / abs(dy) if dy != 0 else float('inf')
            scale = min(scale_x, scale_y)
            new_cp = (center[0] + dx * scale, center[1] + dy * scale)
            import math
            length = math.hypot(dx, dy)
            if length != 0:
                pad_dx = (dx / length) * 10
                pad_dy = (dy / length) * 10
                new_cp = (new_cp[0] + pad_dx, new_cp[1] + pad_dy)
            move_vector = (new_cp[0] - cp[0], new_cp[1] - cp[1])
            if curve.get_role() in self.get_modifier_role_options():
                curve.move_start_by(move_vector)
            else:
                curve.move_end_by(move_vector, adjust_end_point_for_uni_uni_reaction=True)

        return True

    def set_font_size(self, font_size: float, adjust_size: bool = True):
        labels = self.get_labels_list()
        for label in labels:
            label.set_font_size(font_size)

        if adjust_size:
            width_factor = 0.6
            height_factor = 1.2
            max_text_width = 0
            max_text_height = 0

            for label in labels:
                text = label.get_text()
                text_width = len(text) * font_size * width_factor
                text_height = font_size * height_factor

                max_text_width = max(max_text_width, text_width)
                max_text_height = max(max_text_height, text_height)

            padding = 10
            required_width = max_text_width + padding
            required_height = max_text_height + padding
            current_width, current_height = self.get_size()
            scale_w = required_width / current_width
            scale_h = required_height / current_height
            scale = max(scale_w, scale_h)
            if scale > 1:
                new_width = current_width * scale
                new_height = current_height * scale
                self.set_size((new_width, new_height), adjust_font_size=False)

        return True


    def get_info(self):
        result = []
        result.append(f"species id: {self.get_species_id()}")
        result.append(f"id: {self.get_id()}")
        result.append(f"compartment id : {self.get_compartment_id()}")
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

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"Species(id={self.element_id}, index={self.graphical_object_index})"
