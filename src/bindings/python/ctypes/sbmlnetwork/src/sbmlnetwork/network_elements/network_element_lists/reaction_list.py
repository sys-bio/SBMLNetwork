from .network_element_base_list import NetworkElementBaseList


class ReactionList(NetworkElementBaseList):

    def get_reaction_ids(self):
        reaction_ids = []
        for reaction in self:
            reaction_ids.append(reaction.get_reaction_id())

        return reaction_ids

    @property
    def reaction_ids(self):
        return self.get_reaction_ids()

    def get_compartment_ids(self):
        compartment_ids = []
        for reaction in self:
            compartment_ids.append(reaction.get_compartment_id())

        return compartment_ids

    @property
    def compartment_ids(self):
        return self.get_compartment_ids()

    def get_centers(self):
        from ..visual_elements.visual_element_lists.reaction_center_list import ReactionCenterList

        reaction_center_list = ReactionCenterList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            reaction_center_list.append(reaction.get_center())

        return reaction_center_list

    @property
    def centers(self):
        return self.get_centers()

    def switch_to_curve(self):
        results = []
        for reaction in self:
            results.append(reaction.switch_to_curve())

        return results

    def switch_centers_to_curve(self):
        results = []
        for reaction in self:
            results.append(reaction.switch_center_to_curve())

        return results

    def switch_to_shapes(self):
        results = []
        for reaction in self:
            results.append(reaction.switch_to_shapes())

        return results

    def switch_centers_to_shapes(self):
        results = []
        for reaction in self:
            results.append(reaction.switch_center_to_shapes())

        return results

    def are_curves(self):
        are_curves = []
        for reaction in self:
            are_curves.append(reaction.is_curve())

        return are_curves

    def are_centers_curve(self):
        are_curves = []
        for reaction in self:
            are_curves.append(reaction.is_center_curve())

        return are_curves

    def are_shapes(self):
        are_shapes = []
        for reaction in self:
            are_shapes.append(reaction.is_shapes())

        return are_shapes

    def are_centers_shapes(self):
        are_shapes = []
        for reaction in self:
            are_shapes.append(reaction.is_center_shapes())

        return are_shapes

    def get_center_curves(self):
        from ..visual_elements.visual_element_lists.curve_element_lists.curve_list import CurveList

        curves = CurveList()
        for reaction in self:
            curves.append(reaction.get_center_curve())
        return curves

    @property
    def center_curves(self):
        return self.get_center_curves()

    def get_shapes_list(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for reaction in self:
            shapes.extend(reaction.get_shapes())

        return shapes

    def get_center_shapes_list(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for reaction in self:
            shapes.extend(reaction.get_center_shapes())

        return shapes

    def get_center_shapes(self):
        return self.get_center_shapes_list()

    @property
    def center_shapes(self):
        return self.get_center_shapes()

    def get_shape_types(self):
        types = []
        for reaction in self:
            types.append(reaction.get_shape_type())

        return types

    @property
    def shape_types(self):
        return self.get_shape_types()

    def get_border_colors(self):
        border_colors = []
        for reaction in self:
            border_colors.append(reaction.get_border_color())

        return border_colors

    def set_border_colors(self, border_color: str):
        results = []
        for reaction in self:
            results.append(reaction.set_border_color(border_color))

        return results

    def get_border_thicknesses(self):
        thicknesses = []
        for reaction in self:
            thicknesses.append(reaction.get_border_thickness())

        return thicknesses

    def set_border_thicknesses(self, thickness: float):
        results = []
        for reaction in self:
            results.append(reaction.set_border_thickness(thickness))

        return results

    def get_fill_colors(self):
        fill_colors = []
        for reaction in self:
            fill_colors.append(reaction.get_fill_color())

        return fill_colors

    def set_fill_colors(self, fill_color: str or tuple or list):
        results = []
        for reaction in self:
            results.append(reaction.set_fill_color(fill_color))

        return results

    def get_curves_list(self, species=None):
        from ..visual_elements.visual_element_lists.curve_element_lists.curve_list import CurveList

        curves = CurveList()
        for reaction in self:
            curves.extend(reaction.get_curves_list(species))
        return curves

    def get_curves(self, species=None):
        return self.get_curves_list(species)

    @property
    def curves(self):
        return self.get_curves()

    def get_center_curve_colors(self):
        colors = []
        for reaction in self:
            colors.append(reaction.get_center_curve_color())

        return colors

    def set_center_curve_colors(self, color):
        results = []
        for reaction in self:
            results.append(reaction.set_center_curve_color(color))

        return results

    @property
    def center_curve_colors(self):
        return self.get_center_curve_colors()

    @center_curve_colors.setter
    def center_curve_colors(self, color):
        self.set_center_curve_colors(color)

    def get_curve_colors(self):
        curve_colors = []
        for reaction in self:
            curve_colors.extend(reaction.get_curve_colors())

        return curve_colors

    def set_curve_colors(self, color):
        results = []
        for reaction in self:
            results.append(reaction.set_curve_colors(color))

        return results

    @property
    def curve_colors(self):
        return self.get_curve_colors()

    @curve_colors.setter
    def curve_colors(self, color):
        self.set_curve_colors(color)

    def set_colors(self, color):
        results = []
        for reaction in self:
            results.append(reaction.set_colors(color))

        return results

    def get_center_curve_thicknesses(self):
        thicknesses = []
        for reaction in self:
            thicknesses.append(reaction.get_center_curve_thickness())

        return thicknesses

    def set_center_curve_thicknesses(self, thickness):
        results = []
        for reaction in self:
            results.append(reaction.set_center_curve_thickness(thickness))

        return results

    @property
    def center_curve_thicknesses(self):
        return self.get_center_curve_thicknesses()

    @center_curve_thicknesses.setter
    def center_curve_thicknesses(self, thickness):
        self.set_center_curve_thicknesses(thickness)

    def get_curve_thicknesses(self):
        curve_thicknesses = []
        for reaction in self:
            curve_thicknesses.extend(reaction.get_curve_thicknesses())

        return curve_thicknesses

    def set_curve_thicknesses(self, thickness):
        results = []
        for reaction in self:
            results.append(reaction.set_curve_thicknesses(thickness))

        return results

    @property
    def curve_thicknesses(self):
        return self.get_curve_thicknesses()

    @curve_thicknesses.setter
    def curve_thicknesses(self, thickness):
        self.set_curve_thicknesses(thickness)

    def set_thicknesses(self, thickness):
        results = []
        for reaction in self:
            results.append(reaction.set_thicknesses(thickness))

        return results

    def get_arrow_heads(self):
        from ..visual_elements.visual_element_lists.curve_element_lists.arrow_head_list import ArrowHeadList

        arrow_heads = ArrowHeadList()
        for reaction in self:
            arrow_heads.extend(reaction.get_arrow_heads())
        return arrow_heads

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_relative_positions(self):
        relative_positions = []
        for reaction in self:
            relative_positions.append(reaction.get_arrow_head_relative_positions())
        return relative_positions

    def set_arrow_head_relative_positions(self, relative_position: tuple[float, float]):
        results = []
        for reaction in self:
            results.append(reaction.set_arrow_head_relative_positions(relative_position))
        return results

    @property
    def arrow_head_relative_positions(self):
        return self.get_arrow_head_relative_positions()

    @arrow_head_relative_positions.setter
    def arrow_head_relative_positions(self, relative_position: tuple[float, float]):
        self.set_arrow_head_relative_positions(relative_position)

    def get_arrow_head_sizes(self):
        sizes = []
        for reaction in self:
            sizes.append(reaction.get_arrow_head_sizes())
        return sizes

    def set_arrow_head_sizes(self, size: tuple[float, float]):
        results = []
        for reaction in self:
            results.append(reaction.set_arrow_head_sizes(size))
        return results

    @property
    def arrow_head_sizes(self):
        return self.get_arrow_head_sizes()

    @arrow_head_sizes.setter
    def arrow_head_sizes(self, size: tuple[float, float]):
        self.set_arrow_head_sizes(size)

    def get_arrow_head_shapes(self):
        shapes = []
        for reaction in self:
            shapes.append(reaction.get_arrow_head_shapes())

        return shapes

    def set_arrow_head_shapes(self, shape):
        results = []
        for reaction in self:
            results.append(reaction.set_arrow_head_shapes(shape))

        return results

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    @arrow_head_shapes.setter
    def arrow_head_shapes(self, shape):
        self.set_arrow_head_shapes(shape)

    def get_arrow_head_border_color(self):
        border_colors = []
        for reaction in self:
            border_colors.append(reaction.get_arrow_head_border_colors())
        return border_colors

    def set_arrow_head_border_colors(self, border_color: str):
        results = []
        for reaction in self:
            results.append(reaction.set_arrow_head_border_colors(border_color))
        return results

    @property
    def arrow_head_border_colors(self):
        return self.get_arrow_head_border_color()

    @arrow_head_border_colors.setter
    def arrow_head_border_colors(self, border_color: str):
        self.set_arrow_head_border_colors(border_color)

    def get_arrow_head_border_thicknesses(self):
        border_thicknesses = []
        for reaction in self:
            border_thicknesses.append(reaction.get_arrow_head_border_thicknesses())
        return border_thicknesses

    def set_arrow_head_border_thicknesses(self, thickness: float):
        results = []
        for reaction in self:
            results.append(reaction.set_arrow_head_border_thicknesses(thickness))
        return results

    @property
    def arrow_head_border_thicknesses(self):
        return self.get_arrow_head_border_thicknesses()

    @arrow_head_border_thicknesses.setter
    def arrow_head_border_thicknesses(self, thickness: float):
        self.set_arrow_head_border_thicknesses(thickness)

    def get_arrow_head_fill_colors(self):
        fill_colors = []
        for reaction in self:
            fill_colors.append(reaction.get_arrow_head_fill_colors())
        return fill_colors

    def set_arrow_head_fill_colors(self, fill_color: str or tuple or list):
        results = []
        for reaction in self:
            results.append(reaction.set_arrow_head_fill_colors(fill_color))
        return results

    @property
    def arrow_head_fill_colors(self):
        return self.get_arrow_head_fill_colors()

    @arrow_head_fill_colors.setter
    def arrow_head_fill_colors(self, fill_color: str or tuple or list):
        self.set_arrow_head_fill_colors(fill_color)

    def move_arrow_head_relative_positions_to(self, relative_position: tuple[float, float]):
        results = []
        for reaction in self:
            results.append(reaction.move_arrow_head_relative_positions_to(relative_position))

        return results

    def move_arrow_head_relative_positions_by(self, delta: tuple[float, float]):
        results = []
        for reaction in self:
            results.append(reaction.move_arrow_head_relative_positions_by(delta))

        return results

    def get_species_list(self):
        from .species_list import SpeciesList

        species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            species_list.extend(reaction.get_species_list())
        return species_list

    def get_species(self):
        return self.get_species_list()

    @property
    def species(self):
        return self.get_species()

    def get_species_ids(self):
        species_ids = []
        for reaction in self:
            species_ids.extend(reaction.get_species_ids())
        return species_ids

    @property
    def species_ids(self):
        return self.get_species_ids()

    def get_empty_species_list(self):
        from .species_list import SpeciesList

        empty_species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            empty_species_list.append(reaction.get_empty_species())
        return empty_species_list

    def get_empty_species(self):
        return self.get_empty_species_list()

    @property
    def empty_species(self):
        return self.get_empty_species()

    def create_alias(self):
        aliases = ReactionList()
        for reaction in self:
            alias = reaction.create_alias()
            if alias:
                aliases.append(alias)
        return aliases

    def assign_species(self, species):
        from .species_list import SpeciesList

        successful_assignments = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            if reaction.assign_species(species):
                successful_assignments.extend(reaction)
        return successful_assignments

    def move(self, delta: tuple[float, float], move_connected_species: bool = True):
        results = []
        for reaction in self:
            results.append(reaction.move_by(delta, move_connected_species=move_connected_species))

        return results

    def __str__(self):
        result = []
        for reaction in self:
            result.append(str(reaction))
        return "\n".join(result)

    def __repr__(self):
        return f"ReactionList({[repr(reaction) for reaction in self]})"
