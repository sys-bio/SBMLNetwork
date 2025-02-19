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

    def get_connected_curves(self):
        from ..visual_elements.visual_element_lists.curve_element_lists.curve_list import CurveList

        connected_curves = CurveList()
        for species in self:
            connected_curves.extend(species.get_connected_curves())

        return connected_curves

    @property
    def connected_curves(self):
        return self.get_connected_curves()

    def get_curves(self, species=None):
        return self.get_connected_curves()

    def get_curves_list(self, species=None):
        return self.get_curves(species)

    @property
    def curves(self):
        return self.get_curves()

    def get_curve_colors(self, species=None):
        curve_colors = []
        for species in self:
            curve_colors.append(species.get_curve_colors())

        return curve_colors

    def set_curve_colors(self, color, species=None):
        results = []
        for species in self:
            results.append(species.set_curve_colors(color))

        return results

    @property
    def curve_colors(self):
        return self.get_curve_colors()

    @curve_colors.setter
    def curve_colors(self, color):
        self.set_curve_colors(color)

    def get_curve_thicknesses(self, species=None):
        curve_thicknesses = []
        for species in self:
            curve_thicknesses.append(species.get_curve_thicknesses())

        return curve_thicknesses

    def set_curve_thicknesses(self, thickness, species=None):
        results = []
        for species in self:
            results.append(species.set_curve_thicknesses(thickness))

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
            arrow_heads.append(species.get_arrow_heads())

        return arrow_heads

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_shapes(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for species in self:
            shapes.append(species.get_arrow_head_shapes())

        return shapes

    def get_arrow_head_shape_types(self):
        shape_types = []
        for species in self:
            shape_types.append(species.get_arrow_head_shape_type())

        return shape_types

    @property
    def arrow_head_shape_types(self):
        return self.arrow_head_shape_types()

    def get_arrow_head_border_colors(self):
        border_colors = []
        for species in self:
            border_colors.append(species.get_arrow_head_border_color())

        return border_colors

    def set_arrow_head_border_colors(self, color):
        results = []
        for species in self:
            results.append(species.set_arrow_head_border_color(color))

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
            border_thicknesses.append(species.get_arrow_head_border_thickness())

        return border_thicknesses

    def set_arrow_head_border_thicknesses(self, thickness):
        results = []
        for species in self:
            results.append(species.set_arrow_head_border_thickness(thickness))

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
            fill_colors.append(species.get_arrow_head_fill_color())

        return fill_colors

    def set_arrow_head_fill_colors(self, color):
        results = []
        for species in self:
            results.append(species.set_arrow_head_fill_color(color))

        return results

    @property
    def arrow_head_fill_colors(self):
        return self.get_arrow_head_fill_colors()

    @arrow_head_fill_colors.setter
    def arrow_head_fill_colors(self, color):
        self.set_arrow_head_fill_colors(color)

    def get_roles(self, reaction):
        roles = []
        for species in self:
            roles.append(species.get_role(reaction))

        return roles

    def create_alias(self, reaction):
        aliases = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for species in self:
            aliases.append(species.create_alias(reaction))

        return aliases

    def align_to_top(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "top") == 0:
            return True

        return False

    def align_to_bottom(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "bottom") == 0:
            return True

        return False

    def align_to_vertical_center(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "vCenter") == 0:
            return True

        return False

    def align_to_left(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "left") == 0:
            return True

        return False

    def align_to_right(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "right") == 0:
            return True

        return False

    def align_to_horizontal_center(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "hCenter") == 0:
            return True

        return False

    def align_to_circle(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "circular") == 0:
            return True

        return False

    # Todo: Implement distribute method
    # ToDo: Implement get_distribute_options method

    def move(self, position: tuple[float, float], move_connected_curves: bool = False):
        results = []
        for species in self:
            results.append(species.move(position, move_connected_curves))

        return results

    def __str__(self):
        result = []
        for species in self:
            result.append(str(species))
        return "\n".join(result)

    def __repr__(self):
        return f"SpeciesList({[repr(species) for species in self]})"
