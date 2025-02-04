from ....network_element_lists import *

class CurveList(list):

    def __init__(self, curve_list=None, libsbmlnetwork=None):
        super().__init__(curve_list or [])
        self.libsbmlnetwork = libsbmlnetwork

    def get_reaction(self):
        reaction_list = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for curve in self:
            reaction_list.append(curve.get_reaction())

        return reaction_list

    def get_species(self):
        species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for curve in self:
            species_list.append(curve.get_species())

        return species_list

    def get_color(self):
        colors = []
        for curve in self:
            colors.append(curve.get_color())

        return colors

    def set_color(self, color: str):
        results = []
        for curve in self:
            results.append(curve.set_color(color))

        return results

    def get_thickness(self):
        thicknesses = []
        for curve in self:
            thicknesses.append(curve.get_thickness())

        return thicknesses

    def set_thickness(self, thickness: float):
        results = []
        for curve in self:
            results.append(curve.set_thickness(thickness))

        return results

    def get_start(self):
        start_points = []
        for curve in self:
            start_points.append(curve.get_start())

        return start_points

    def set_start(self, start: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.set_start(start))

        return results

    def get_end(self):
        end_points = []
        for curve in self:
            end_points.append(curve.get_end())

        return end_points

    def set_end(self, end: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.set_end(end))

        return results

    def get_start_slope(self):
        start_slopes = []
        for curve in self:
            start_slopes.append(curve.get_start_slope())

        return start_slopes

    def get_end_slope(self):
        end_slopes = []
        for curve in self:
            end_slopes.append(curve.get_end_slope())

        return end_slopes

    def add_segment(self, start: tuple[float, float], end: tuple[float, float], control_point_1: tuple[float, float] = None, control_point_2: tuple[float, float] = None):
        results = []
        for curve in self:
            results.append(curve.add_segment(start, end, control_point_1, control_point_2))

        return results

    def remove_segment(self, curve_segment_index: int):
        results = []
        for curve in self:
            results.append(curve.remove_segment(curve_segment_index))

        return results

    def get_segment(self, curve_segment_index: int = 0):
        from .curve_segment_list import CurveSegmentList

        curve_segment_list = CurveSegmentList()
        for curve in self:
            curve_segment_list.append(curve.get_segment(curve_segment_index))

        return curve_segment_list

    def get_segments_list(self):
        from .curve_segment_list import CurveSegmentList

        curve_segment_list = CurveSegmentList()
        for curve in self:
            curve_segment_list.extend(curve.get_segments_list())

        return curve_segment_list

    def get_arrow_head(self):
        from .arrow_head_list import ArrowHeadList

        arrow_heads = ArrowHeadList()
        for curve in self:
            arrow_head = curve.get_arrow_head()
            if arrow_head:
                arrow_heads.append(arrow_head)

        return arrow_heads

    def move(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move(delta))

        return results

    def move_start(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_start(delta))

        return results

    def move_end(self, delta: tuple[float, float]):
        results = []
        for curve in self:
            results.append(curve.move_end(delta))

        return results

    def __str__(self):
        result = []
        for curve in self:
            result.append(str(curve))
        return "\n".join(result)

    def __repr__(self):
        return f"CurveList({[repr(curve) for curve in self]})"
