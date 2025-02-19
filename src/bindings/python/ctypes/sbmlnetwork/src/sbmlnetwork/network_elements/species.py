from .network_element_base import NetworkElementBase
from .reaction import Reaction
from .network_element_lists import ReactionList
from .visual_elements.visual_element_lists .curve_element_lists import CurveList


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

    def get_connected_curves_list(self):
        connected_curves = CurveList()
        reactions = self.get_reactions_list()
        for reaction in reactions:
            connected_curves.extend(reaction.get_curves_list(self))

        return connected_curves

    def get_connected_curves(self):
        return self.get_connected_curves_list()

    @property
    def connected_curves(self):
        return self.get_connected_curves()

    def get_curves_list(self, species = None):
        curves = CurveList()
        connected_curves = self.get_connected_curves_list()
        for curve in connected_curves:
            if species is None or curve.get_species() == species:
                curves.append(curve)

        return curves

    def get_curves(self):
        return self.get_curves_list()

    @property
    def curves(self):
        return self.get_curves()

    def get_curve_colors(self, species = None):
        return self.get_curves_list(species).get_color()

    def set_curve_colors(self, color, species = None):
        return self.get_curves_list(species).set_color(color)

    @property
    def curve_colors(self):
        return self.get_curve_colors()

    @curve_colors.setter
    def curve_colors(self, color):
        self.set_curve_colors(color)

    def get_curve_thicknesses(self, species = None):
        return self.get_curves_list(species).get_thickness()

    def set_curve_thicknesses(self, thickness, species = None):
        return self.get_curves_list(species).set_thickness(thickness)

    @property
    def curve_thicknesses(self):
        return self.get_curve_thicknesses()

    @curve_thicknesses.setter
    def curve_thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    def get_arrow_heads(self):
        return self.get_curves_list().get_arrow_head()

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_shapes(self):
        return self.get_arrow_heads().get_shapes_list()

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def get_arrow_head_shape_type(self):
        return self.get_arrow_heads().get_shape_type()

    @property
    def arrow_head_shape_type(self):
        return self.get_arrow_head_shape_type()

    def get_arrow_head_border_color(self):
        return self.get_arrow_heads().get_border_color()

    def set_arrow_head_border_color(self, border_color: str):
        return self.get_arrow_heads().set_border_color(border_color)

    @property
    def arrow_head_border_color(self):
        return self.get_arrow_head_border_color()

    @arrow_head_border_color.setter
    def arrow_head_border_color(self, border_color: str):
        self.set_arrow_head_border_color(border_color)

    def get_arrow_head_border_thickness(self):
        return self.get_arrow_heads().get_border_thickness()

    def set_arrow_head_border_thickness(self, thickness: float):
        return self.get_arrow_heads().set_border_thickness(thickness)

    @property
    def arrow_head_border_thickness(self):
        return self.get_arrow_head_border_thickness()

    @arrow_head_border_thickness.setter
    def arrow_head_border_thickness(self, thickness: float):
        self.set_arrow_head_border_thickness(thickness)

    def get_arrow_head_fill_color(self):
        return self.get_arrow_heads().get_fill_color()

    def set_arrow_head_fill_color(self, fill_color: str or tuple or list):
        return self.get_arrow_heads().set_fill_color(fill_color)

    @property
    def arrow_head_fill_color(self):
        return self.get_arrow_head_fill_color()

    @arrow_head_fill_color.setter
    def arrow_head_fill_color(self, fill_color: str or tuple or list):
        self.set_arrow_head_fill_color(fill_color)

    def get_role(self, reaction: Reaction):
        if reaction is not None:
            for species_reference_index in range(self.libsbmlnetwork.getNumSpeciesReferences(reaction_id=reaction.get_reaction_id(), reaction_glyph_index=reaction.graphical_object_index)):
                if self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=reaction.get_reaction_id(), reaction_glyph_index=reaction.graphical_object_index, species_reference_index=species_reference_index) == self.element_id:
                    return self.libsbmlnetwork.getSpeciesReferenceRole(reaction_id=reaction.get_reaction_id(), reaction_glyph_index=reaction.graphical_object_index, species_reference_index=species_reference_index)

        return None

    @property
    def role(self):
        return self.get_role()

    def get_role_options(self):
        return self.libsbmlnetwork.getListOfRoles()

    @property
    def role_options(self):
        return self.get_role_options()

    def get_modifier_role_options(self):
        roles = self.get_role_options()
        return [role for role in roles if role not in ["substrate", "sidesubstrate", "product", "sideproduct"]]

    @property
    def modifier_role_options(self):
        return self.get_modifier_role_options()

    def create_alias(self, reaction: Reaction):
        if self.libsbmlnetwork.createAliasSpeciesGlyph(species_id=self.element_id, reaction_id=reaction.get_reaction_id(), reaction_glyph_index=reaction.graphical_object_index) == 0:
            species_glyph_index = self.libsbmlnetwork.getSpeciesGlyphIndex(species_id=self.element_id, reaction_id=reaction.get_reaction_id(), reaction_glyph_index=reaction.graphical_object_index)
            return Species(self.libsbmlnetwork, self.element_id, species_glyph_index)

    def move(self, position: tuple[float, float], move_connected_curves: bool = False):
        is_moved = super().move(position)
        if not is_moved:
            return False

        if move_connected_curves:
            curves = self.get_connected_curves()
            for curve in curves:
                role = self.get_role(curve.get_reaction())
                if role in self.get_modifier_role_options():
                    if not curve.move_start(position):
                        return False
                else:
                    if not curve.move_end(position):
                        return False

        return True

    def __str__(self):
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

    def __repr__(self):
        return f"Species(id={self.element_id}, index={self.graphical_object_index})"
