from ....network_element_lists import *


class CurveList(list):

    def __init__(self, curve_list=None, libsbmlnetwork=None):
        super().__init__(curve_list or [])
        self.libsbmlnetwork = libsbmlnetwork

    def get_reactions(self):
        reaction_list = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for curve in self:
            reaction_list.append(curve.get_reaction())

        return reaction_list

    @property
    def reactions(self):
        return self.get_reactions()

    def get_species(self):
        species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for curve in self:
            species_list.append(curve.get_species())

        return species_list

    @property
    def species(self):
        return self.get_species()

    def get_roles(self):
        roles = []
        for curve in self:
            roles.append(curve.get_role())

        return roles

    @property
    def roles(self):
        return self.get_roles()

    def get_colors(self):
        colors = []
        for curve in self:
            colors.append(curve.get_color())

        return colors

    def set_colors(self, color: str):
        results = []
        for curve in self:
            results.append(curve.set_color(color))

        return results

    @property
    def colors(self):
        return self.get_colors()

    @colors.setter
    def colors(self, color: str):
        self.set_colors(color)

    def get_thicknesses(self):
        thicknesses = []
        for curve in self:
            thicknesses.append(curve.get_thickness())

        return thicknesses

    def set_thicknesses(self, thickness: float):
        results = []
        for curve in self:
            results.append(curve.set_thickness(thickness))

        return results

    @property
    def thicknesses(self):
        return self.get_thicknesses()

    @thicknesses.setter
    def thicknesses(self, thickness: float):
        self.set_thicknesses(thickness)

    def get_starts(self):
        start_points = []
        for curve in self:
            start_points.append(curve.get_start())

        return start_points

    def set_starts(self, start: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.set_start(start))

        return results

    @property
    def starts(self):
        return self.get_starts()

    @starts.setter
    def starts(self, start: tuple[float, float]):
        self.set_starts(start)

    def get_ends(self):
        end_points = []
        for curve in self:
            end_points.append(curve.get_end())

        return end_points

    def set_ends(self, end: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.set_end(end))

        return results

    @property
    def ends(self):
        return self.get_ends()

    @ends.setter
    def ends(self, end: tuple[float, float]):
        self.set_ends(end)

    def get_start_slopes(self):
        start_slopes = []
        for curve in self:
            start_slopes.append(curve.get_start_slope())

        return start_slopes

    @property
    def start_slopes(self):
        return self.get_start_slopes()

    def get_end_slopes(self):
        end_slopes = []
        for curve in self:
            end_slopes.append(curve.get_end_slope())

        return end_slopes

    @property
    def end_slopes(self):
        return self.get_end_slopes()

    def add_segments(self, start: tuple[float, float], end: tuple[float, float], control_point_1: tuple[float, float] = None, control_point_2: tuple[float, float] = None):
        results = []
        for curve in self:
            results.append(curve.add_segment(start, end, control_point_1, control_point_2))

        return results

    def remove_segments(self, curve_segment_index: int):
        results = []
        for curve in self:
            results.append(curve.remove_segment(curve_segment_index))

        return results

    def get_first_segments(self, curve_segment_index: int = 0):
        from .curve_segment_list import CurveSegmentList

        curve_segment_list = CurveSegmentList()
        for curve in self:
            curve_segment_list.append(curve.get_segment(curve_segment_index))

        return curve_segment_list

    @property
    def first_segments(self):
        return self.get_first_segments()

    def get_segments_list(self):
        from .curve_segment_list import CurveSegmentList

        curve_segment_list = CurveSegmentList()
        for curve in self:
            curve_segment_list.extend(curve.get_segments_list())

        return curve_segment_list

    def get_segments(self, curve_segment_index: int = 0):
        return self.get_segments(curve_segment_index)

    @property
    def segments(self):
        return self.get_segments_list()

    def get_arrow_heads(self):
        from .arrow_head_list import ArrowHeadList

        arrow_heads = ArrowHeadList()
        for curve in self:
            arrow_head = curve.get_arrow_head()
            if arrow_head:
                arrow_heads.append(arrow_head)

        return arrow_heads

    @property
    def arrow_heads(self):
        return self.get_arrow_heads()

    def get_arrow_head_relative_positions(self):
        relative_positions = []
        for curve in self:
            relative_positions.append(curve.get_arrow_head_relative_position())

        return relative_positions

    def set_arrow_head_relative_positions(self, relative_position: float):
        results = []
        for curve in self:
            results.append(curve.set_arrow_head_relative_position(relative_position))

        return results

    @property
    def arrow_head_relative_positions(self):
        return self.get_arrow_head_relative_positions()

    @arrow_head_relative_positions.setter
    def arrow_head_relative_positions(self, relative_position: float):
        self.set_arrow_head_relative_positions(relative_position)

    def get_arrow_head_sizes(self):
        sizes = []
        for curve in self:
            sizes.append(curve.get_arrow_head_size())

        return sizes

    def set_arrow_head_sizes(self, size: float):
        results = []
        for curve in self:
            results.append(curve.set_arrow_head_size(size))

        return results

    @property
    def arrow_head_sizes(self):
        return self.get_arrow_head_sizes()

    @arrow_head_sizes.setter
    def arrow_head_sizes(self, size: float):
        self.set_arrow_head_sizes(size)

    def get_arrow_head_shapes(self):
        from ..shape_list import ShapeList

        arrow_head_shapes = ShapeList()
        for curve in self:
            arrow_head = curve.get_arrow_head()
            if arrow_head:
                arrow_head_shapes.append(arrow_head.get_shape())

        return arrow_head_shapes

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def get_arrow_head_shape_types(self):
        shape_types = []
        for curve in self:
            shape_types.append(curve.get_arrow_head_shape_type())

        return shape_types

    @property
    def arrow_head_shape_types(self):
        return self.get_arrow_head_shape_types()

    def get_arrow_head_border_colors(self):
        border_colors = []
        for curve in self:
            border_colors.append(curve.get_arrow_head_border_color())

        return border_colors

    def set_arrow_head_border_colors(self, border_color: str):
        results = []
        for curve in self:
            results.append(curve.set_arrow_head_border_color(border_color))

        return results

    @property
    def arrow_head_border_colors(self):
        return self.get_arrow_head_border_colors()

    @arrow_head_border_colors.setter
    def arrow_head_border_colors(self, border_color: str):
        self.set_arrow_head_border_colors(border_color)

    def get_arrow_head_border_thicknesses(self):
        thicknesses = []
        for curve in self:
            thicknesses.append(curve.get_arrow_head_border_thickness())

        return thicknesses

    def set_arrow_head_border_thicknesses(self, thickness: float):
        results = []
        for curve in self:
            results.append(curve.set_arrow_head_border_thickness(thickness))

        return results

    @property
    def arrow_head_border_thicknesses(self):
        return self.get_arrow_head_border_thicknesses()

    @arrow_head_border_thicknesses.setter
    def arrow_head_border_thicknesses(self, thickness: float):
        self.set_arrow_head_border_thicknesses(thickness)

    def get_arrow_head_fill_colors(self):
        fill_colors = []
        for curve in self:
            fill_colors.append(curve.get_arrow_head_fill_color())

        return fill_colors

    def set_arrow_head_fill_colors(self, fill_color: str or tuple or list):
        results = []
        for curve in self:
            results.append(curve.set_arrow_head_fill_color(fill_color))

        return results

    @property
    def arrow_head_fill_colors(self):
        return self.get_arrow_head_fill_colors()

    @arrow_head_fill_colors.setter
    def arrow_head_fill_colors(self, fill_color: str or tuple or list):
        self.set_arrow_head_fill_colors(fill_color)

    def move_arrow_head_relative_positions_to(self, relative_position: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_arrow_head_relative_position_to(relative_position))

        return results

    def move_arrow_head_relative_positions_by(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_arrow_head_relative_position_by(delta))

        return results

    def move_by(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_by(delta))

        return results

    def move_to(self, position: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_to(position))

        return results

    def move_start_by(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_start_by(delta))

        return results

    def move_end_to(self, position: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_end_to(position))

        return results

    def move_end_by(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_end_by(delta))

        return results

    def show(self):
        results = []
        for curve in self:
            results.append(curve.show())

        return results

    def hide(self):
        results = []
        for curve in self:
            results.append(curve.hide())

        return results

    def are_hidden(self):
        hidden = []
        for curve in self:
            hidden.append(curve.is_hidden())

        return hidden

    def get_info(self):
        result = []
        for curve in self:
            result.append(str(curve))
        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"CurveList({[repr(curve) for curve in self]})"
