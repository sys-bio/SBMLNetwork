from .network_element_base_list import NetworkElementBaseList
from .reaction_list import ReactionList


class SpeciesList(NetworkElementBaseList):

    def get_species_ids(self):
        species_ids = []
        for species in self:
            species_ids.append(species.get_species_id())

        return species_ids

    @property
    def species_ids(self):
        return self.get_species_ids()

    def get_compartment_ids(self):
        compartment_ids = []
        for species in self:
            compartment_ids.append(species.get_compartment_id())

        return compartment_ids

    @property
    def compartment_ids(self):
        return self.get_compartment_ids()

    def get_reactions_list(self):
        reactions = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for species in self:
            reactions.extend(species.get_reactions_list())
        return reactions

    def get_reactions(self):
        return self.get_reactions_list()

    @property
    def reactions(self):
        return self.get_reactions()

    def get_reaction_ids(self):
        reaction_ids = []
        for species in self:
            reaction_ids.append(species.get_reaction_ids())

        return reaction_ids

    @property
    def reaction_ids(self):
        return self.get_reaction_ids()

    def get_curves(self, reaction=None):
        from ..visual_elements.visual_element_lists.curve_element_lists.curve_list import CurveList

        curves = CurveList()
        for species in self:
            curves.extend(species.get_connected_curves(reaction))

        return curves

    def get_curves_list(self, reaction=None):
        return self.get_curves(reaction)

    @property
    def curves(self):
        return self.get_curves()

    def get_connected_curves(self, reaction=None):
        return self.get_curves(reaction)

    @property
    def connected_curves(self):
        return self.get_connected_curves()

    def get_curve_colors(self, reaction=None):
        curve_colors = []
        for species in self:
            curve_colors.append(species.get_curve_colors(reaction))

        return curve_colors

    def set_curve_colors(self, color, reaction=None):
        results = []
        for species in self:
            results.append(species.set_curve_colors(color, reaction))

        return results

    @property
    def curve_colors(self):
        return self.get_curve_colors()

    @curve_colors.setter
    def curve_colors(self, color):
        self.set_curve_colors(color)

    def get_curve_thicknesses(self, reaction=None):
        curve_thicknesses = []
        for species in self:
            curve_thicknesses.append(species.get_curve_thicknesses(reaction))

        return curve_thicknesses

    def set_curve_thicknesses(self, thickness, reaction=None):
        results = []
        for species in self:
            results.append(species.set_curve_thicknesses(thickness, reaction))

        return results

    @property
    def curve_thicknesses(self):
        return self.get_curve_thicknesses()

    @curve_thicknesses.setter
    def curve_thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    def get_arrow_heads(self):
        from ..visual_elements.visual_element_lists.curve_element_lists.arrow_head_list import ArrowHeadList

        arrow_heads = ArrowHeadList()
        for species in self:
            arrow_heads.extend(species.get_arrow_heads())

        return arrow_heads

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_shapes(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for species in self:
            shapes.extend(species.get_arrow_head_shapes())

        return shapes

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def set_arrow_head_shapes(self, shape):
        results = []
        for species in self:
            results.append(species.set_arrow_head_shapes(shape))

        return results

    @arrow_head_shapes.setter
    def arrow_head_shapes(self, shape):
        self.set_arrow_head_shapes(shape)

    def get_arrow_head_border_colors(self):
        border_colors = []
        for species in self:
            border_colors.append(species.get_arrow_head_border_colors())

        return border_colors

    def set_arrow_head_border_colors(self, color):
        results = []
        for species in self:
            results.append(species.set_arrow_head_border_colors(color))

        return results

    @property
    def arrow_head_border_colors(self):
        return self.get_arrow_head_border_colors()

    @arrow_head_border_colors.setter
    def arrow_head_border_colors(self, color):
        self.set_arrow_head_border_colors(color)

    def get_arrow_head_border_thicknesses(self):
        border_thicknesses = []
        for species in self:
            border_thicknesses.append(species.get_arrow_head_border_thicknesses())

        return border_thicknesses

    def set_arrow_head_border_thicknesses(self, thickness):
        results = []
        for species in self:
            results.append(species.set_arrow_head_border_thicknesses(thickness))

        return results

    @property
    def arrow_head_border_thicknesses(self):
        return self.get_arrow_head_border_thicknesses()

    @arrow_head_border_thicknesses.setter
    def arrow_head_border_thicknesses(self, thickness):
        self.set_arrow_head_border_thicknesses(thickness)

    def get_arrow_head_fill_colors(self):
        fill_colors = []
        for species in self:
            fill_colors.append(species.get_arrow_head_fill_colors())

        return fill_colors

    def set_arrow_head_fill_colors(self, color):
        results = []
        for species in self:
            results.append(species.set_arrow_head_fill_colors(color))

        return results

    @property
    def arrow_head_fill_colors(self):
        return self.get_arrow_head_fill_colors()

    @arrow_head_fill_colors.setter
    def arrow_head_fill_colors(self, color):
        self.set_arrow_head_fill_colors(color)

    def move_arrow_head_relative_positions_to(self, relative_position):
        results = []
        for species in self:
            results.append(species.move_arrow_head_relative_positions_to(relative_position))

        return results

    def move_arrow_head_relative_positions_by(self, relative_position):
        results = []
        for species in self:
            results.append(species.move_arrow_head_relative_positions_by(relative_position))

        return results

    def get_roles(self, reaction):
        roles = []
        for species in self:
            roles.append(species.get_role(reaction))

        return roles

    def are_empty_species(self):
        are_empty_species = []
        for species in self:
            are_empty_species.append(species.is_empty_species())

        return are_empty_species

    def create_alias(self, reaction):
        aliases = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for species in self:
            aliases.append(species.create_alias(reaction))

        return aliases

    def move_to(self, position, move_connected_curves=True):
        results = []
        for species in self:
            results.append(species.move_to(position, move_connected_curves))

        return results

    def move_by(self, position, move_connected_curves=True):
        results = []
        for species in self:
            results.append(species.move_by(position, move_connected_curves))

        return results

    def __str__(self):
        result = []
        for species in self:
            result.append(str(species))
        return "\n".join(result)

    def __repr__(self):
        return f"SpeciesList({[repr(species) for species in self]})"
