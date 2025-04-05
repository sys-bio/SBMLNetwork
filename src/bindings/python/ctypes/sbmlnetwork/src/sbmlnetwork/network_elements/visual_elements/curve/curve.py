from typing import Union

from .curve_segment import CurveSegment
from ..visual_element_lists.curve_element_lists import *
from .arrow_head import ArrowHead
import math


class Curve:

    def __init__(self, libsbmlnetwork, reaction_id, reaction_glyph_index, species_reference_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.reaction_id = reaction_id
        self.reaction_glyph_index = reaction_glyph_index
        self.species_reference_index = species_reference_index

    def get_reaction(self):
        from ...reaction import Reaction

        return Reaction(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index)

    @property
    def reaction(self):
        return self.get_reaction()

    def get_species(self):
        if self.species_reference_index is not None:
            reaction = self.get_reaction()
            species_list = reaction.get_species_list()
            species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
            species_glyph_index = self.libsbmlnetwork.getSpeciesGlyphIndex(species_id=species_id, reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index)
            for species in species_list:
                if species.get_species_id() == species_id and species.get_graphical_object_index() == species_glyph_index:
                    return species
            if self.libsbmlnetwork.isSetSpeciesReferenceEmptySpeciesGlyph(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index):
                species_glyph_id = self.libsbmlnetwork.getSpeciesReferenceEmptySpeciesGlyphId(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
                for species in species_list:
                    if species.get_id() == species_glyph_id and species.get_graphical_object_index() == 0:
                        return species

        return None

    @property
    def species(self):
        return self.get_species()

    def get_role(self):
        if self.species_reference_index is not None:
            return self.libsbmlnetwork.getSpeciesReferenceRole(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)

        return None

    @property
    def role(self):
        return self.get_role()

    def get_role_options(self):
        return self.libsbmlnetwork.getListOfRoles()

    @property
    def roles_options(self):
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

    def get_color(self):
        if self.species_reference_index is not None:
            return self.libsbmlnetwork.getSpeciesReferenceLineColor(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
        else:
            return self.libsbmlnetwork.getLineColor(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index)

    def set_color(self, color: str):
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.setSpeciesReferenceLineColor(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, color=color) == 0:
                return True
        else:
            if self.libsbmlnetwork.setLineColor(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, line_color=color) == 0:
                return True

        return False

    @property
    def color(self):
        return self.get_color()

    @color.setter
    def color(self, color: str):
        self.set_color(color)

    def get_thickness(self):
        if self.species_reference_index is not None:
            return self.libsbmlnetwork.getSpeciesReferenceLineWidth(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
        else:
            return self.libsbmlnetwork.getLineWidth(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index)

    def set_thickness(self, thickness: float):
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.setSpeciesReferenceLineWidth(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, line_width=thickness) == 0:
                return True
        else:
            if self.libsbmlnetwork.setLineWidth(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, line_width=thickness) == 0:
                return True

        return False

    @property
    def thickness(self):
        return self.get_thickness()

    @thickness.setter
    def thickness(self, thickness: float):
        self.set_thickness(thickness)

    def get_start(self):
        first_segment = self.get_segment(0)
        if first_segment is not None:
            return first_segment.get_start()

        return None

    def set_start(self, start: tuple[float, float]):
        first_segment = self.get_segments_list()[0]
        if first_segment is not None:
            if first_segment.set_start(start) and first_segment.set_control_point_1(start):
                return True

        return False

    @property
    def start(self):
        return self.get_start()

    @start.setter
    def start(self, start: tuple[float, float]):
        self.set_start(start)

    def get_end(self):
        last_segment = self.get_segments_list()[-1]
        if last_segment is not None:
            return last_segment.get_end()

        return None

    def set_end(self, end: tuple[float, float]):
        last_segment = self.get_segments_list()[-1]
        if last_segment is not None:
            if last_segment.set_end(end) and last_segment.set_control_point_2(end):
                return True

        return False

    @property
    def end(self):
        return self.get_end()

    @end.setter
    def end(self, end: tuple[float, float]):
        self.set_end(end)

    def get_start_slope(self):
        first_segment = self.get_segments_list()[0]
        if first_segment is not None:
            first_point = first_segment.get_start()
            second_point = first_segment.get_control_point_1()
            if first_segment.get_start() == first_segment.get_control_point_1():
                second_point = first_segment.get_end()
            return math.atan2(second_point[1] - first_point[1], second_point[0] - first_point[0])

        return 0.0

    @property
    def start_slope(self):
        return self.get_start_slope()

    def get_end_slope(self):
        last_segment = self.get_segments_list()[-1]
        if last_segment is not None:
            first_point = last_segment.get_end()
            second_point = last_segment.get_control_point_2()
            if last_segment.get_end() == last_segment.get_control_point_2():
                second_point = last_segment.get_start()
            return math.atan2(second_point[1] - first_point[1], second_point[0] - first_point[0])

        return 0.0

    @property
    def end_slope(self):
        return self.get_end_slope()

    def add_segment(self, start: tuple[float, float], end: tuple[float, float], control_point_1: tuple[float, float] = None, control_point_2: tuple[float, float] = None):
        if control_point_1 is None:
            control_point_1 = start
        if control_point_2 is None:
            control_point_2 = end
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.addSpeciesReferenceCubicBezierCurveSegment(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) == 0:
                curve_segment_index = self.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) - 1
                if self.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, x=start[0]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, y=start[1]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, x=end[0]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, y=end[1]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, x=control_point_1[0]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, y=control_point_1[1]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, x=control_point_2[0]) == 0 and \
                        self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index, y=control_point_2[1]) == 0:
                    return True
        else:
            if self.libsbmlnetwork.addCubicBezierCurveSegment(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index) == 0:
                curve_segment_index = self.libsbmlnetwork.getNumCurveSegments(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index) - 1
                if self.libsbmlnetwork.setCurveSegmentStartPointX(id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, x=start[0]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentStartPointY(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, y=start[1]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentEndPointX(id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, x=end[0]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentEndPointY(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, y=end[1]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentBasePoint1X(id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, x=control_point_1[0]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentBasePoint1Y(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, y=control_point_1[1]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentBasePoint2X(id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, x=control_point_2[0]) == 0 and \
                        self.libsbmlnetwork.setCurveSegmentBasePoint2Y(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index, y=control_point_2[1]) == 0:
                    return True

        return False

    def remove_segment(self, segment: Union[int, CurveSegment]):
        if isinstance(segment, CurveSegment):
            curve_segment_index = segment.get_curve_segment_index()
        elif isinstance(segment, int):
            curve_segment_index = segment
        else:
            raise ValueError("segment must be an integer or a CurveSegment object")
        if self.species_reference_index is not None:
            if curve_segment_index < self.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index):
                if self.libsbmlnetwork.removeSpeciesReferenceCurveSegment(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=curve_segment_index) == 0:
                    return True
        else:
            if curve_segment_index < self.libsbmlnetwork.getNumCurveSegments(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index):
                if self.libsbmlnetwork.removeCurveSegment(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index, curve_segment_index=curve_segment_index) == 0:
                    return True

        return False

    def get_segment(self, curve_segment_index: int = 0):
        if self.species_reference_index is not None:
            if curve_segment_index < self.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index):
                return CurveSegment(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, self.species_reference_index, curve_segment_index)
        else:
            if curve_segment_index < self.libsbmlnetwork.getNumCurveSegments(id=self.reaction_id, graphical_object_index=self.reaction_glyph_index):
                return CurveSegment(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, None, curve_segment_index)

        return None

    def get_segments_list(self):
        segments = CurveSegmentList()
        if self.species_reference_index is not None:
            for curve_segment_index in range(self.libsbmlnetwork.getNumSpeciesReferenceCurveSegments(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)):
                segments.append(CurveSegment(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, self.species_reference_index, curve_segment_index))
        else:
            for curve_segment_index in range(self.libsbmlnetwork.getNumCurveSegments(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index)):
                segments.append(CurveSegment(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, None, curve_segment_index))

        return segments

    def get_segments(self):
        return self.get_segments_list()

    @property
    def segments(self):
        return self.get_segments_list()

    def get_arrow_head(self):
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.isSetSpeciesReferenceStartHead(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) or \
                    self.libsbmlnetwork.isSetSpeciesReferenceEndHead(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index):
                return ArrowHead(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, self.species_reference_index)
        else:
            if self.libsbmlnetwork.isSetSpeciesReferenceStartHead(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) or \
                    self.libsbmlnetwork.isSetSpeciesReferenceEndHead(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index):
                return ArrowHead(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, self.species_reference_index)

        return None

    @property
    def arrow_head(self):
        return self.get_arrow_head()

    def get_arrow_head_relative_position(self):
        return self.get_arrow_head().get_relative_position()

    def set_arrow_head_relative_position(self, relative_position: tuple[float, float]):
        return self.get_arrow_head().set_relative_position(relative_position)

    @property
    def arrow_head_relative_position(self):
        return self.get_arrow_head_relative_position()

    @arrow_head_relative_position.setter
    def arrow_head_relative_position(self, relative_position: tuple[float, float]):
        self.set_arrow_head_relative_position(relative_position)

    def get_arrow_head_size(self):
        return self.get_arrow_head().get_size()

    def set_arrow_head_size(self, size: tuple[float, float]):
        return self.get_arrow_head().set_size(size)

    @property
    def arrow_head_size(self):
        return self.get_arrow_head_size()

    @arrow_head_size.setter
    def arrow_head_size(self, size: tuple[float, float]):
        self.set_arrow_head_size(size)

    def get_arrow_head_shapes(self):
        return self.get_arrow_head().get_shape_type()

    @property
    def arrow_head_shapes(self):
        return self.get_arrow_head_shapes()

    def set_arrow_head_shapes(self, shape: str):
        return self.get_arrow_head().set_shape(shape)

    @arrow_head_shapes.setter
    def arrow_head_shapes(self, shape: str):
        self.set_arrow_head_shapes(shape)

    def get_arrow_head_border_color(self):
        return self.get_arrow_head().get_border_color()

    def set_arrow_head_border_color(self, border_color: str):
        return self.get_arrow_head().set_border_color(border_color)

    @property
    def arrow_head_border_color(self):
        return self.get_arrow_head_border_color()

    @arrow_head_border_color.setter
    def arrow_head_border_color(self, border_color: str):
        self.set_arrow_head_border_color(border_color)

    def get_arrow_head_border_thickness(self):
        return self.get_arrow_head().get_border_thickness()

    def set_arrow_head_border_thickness(self, thickness: float):
        return self.get_arrow_head().set_border_thickness(thickness)

    @property
    def arrow_head_border_thickness(self):
        return self.get_arrow_head_border_thickness()

    @arrow_head_border_thickness.setter
    def arrow_head_border_thickness(self, thickness: float):
        self.set_arrow_head_border_thickness(thickness)

    def get_arrow_head_fill_color(self):
        return self.get_arrow_head().get_fill_color()

    def set_arrow_head_fill_color(self, fill_color: str or tuple or list):
        return self.get_arrow_head().set_fill_color(fill_color)

    @property
    def arrow_head_fill_color(self):
        return self.get_arrow_head_fill_color()

    @arrow_head_fill_color.setter
    def arrow_head_fill_color(self, fill_color: str or tuple or list):
        self.set_arrow_head_fill_color(fill_color)

    def move_arrow_head_relative_position_to(self, relative_position: tuple[float, float]):
        return self.get_arrow_head().move_relative_position_to(relative_position)

    def move_arrow_head_relative_position_by(self, delta: tuple[float, float]):
        return self.get_arrow_head().move_relative_position_by(delta)

    def move_by(self, delta: tuple[float, float]):
        if all(self.get_segments_list().move_by(delta)):
            return True

        return False

    def move_start_to(self, position: tuple[float, float]):
        start = self.get_start()
        return self.move_start_by((position[0] - start[0], position[1] - start[1]))

    def move_start_by(self, delta: tuple[float, float]):
        first_segment = self.get_segments_list()[0]
        if first_segment is not None:
            return first_segment.move_start_by(delta)

        return False

    def move_end_to(self, position: tuple[float, float], adjust_end_point_for_uni_uni_reaction: bool = False):
        end = self.get_end()
        return self.move_end_by((position[0] - end[0], position[1] - end[1]), adjust_end_point_for_uni_uni_reaction)

    import math

    def move_end_by(self, delta: tuple[float, float], adjust_end_point_for_uni_uni_reaction: bool = False):
        last_segment = self.get_segments_list()[-1]
        if last_segment is not None:
            if not last_segment.move_end_by(delta):
                return False
            reaction = self.get_reaction()
            if len(reaction.get_species_list()) == 2 and len(reaction.get_curves_list()) == 2:
                species_list = reaction.get_species_list()
                first_species = self.get_species()
                first_curve = self
                first_species_center = (
                    first_species.get_position()[0] + 0.5 * first_species.get_size()[0],
                    first_species.get_position()[1] + 0.5 * first_species.get_size()[1]
                )
                second_species = [s for s in species_list if s.get_id() != first_species.get_id()][0]
                second_curve = reaction.get_curves_list(second_species)[0]
                second_species_center = (
                    second_species.get_position()[0] + 0.5 * second_species.get_size()[0],
                    second_species.get_position()[1] + 0.5 * second_species.get_size()[1]
                )
                reaction_center = (
                    0.5 * (first_species_center[0] + second_species_center[0]),
                    0.5 * (first_species_center[1] + second_species_center[1])
                )
                reaction.set_position(reaction_center)
                first_curve.get_segment().set_start(reaction_center)
                first_curve.get_segment().set_control_point_1(reaction_center)
                second_curve.get_segment().set_start(reaction_center)
                second_curve.get_segment().set_control_point_1(reaction_center)

                if adjust_end_point_for_uni_uni_reaction:
                    dx1 = reaction_center[0] - first_species_center[0]
                    dy1 = reaction_center[1] - first_species_center[1]
                    w1, h1 = first_species.get_size()
                    half_w1, half_h1 = w1 / 2, h1 / 2
                    t_x1 = half_w1 / abs(dx1) if dx1 != 0 else float('inf')
                    t_y1 = half_h1 / abs(dy1) if dy1 != 0 else float('inf')
                    t1 = min(t_x1, t_y1)
                    intersection1 = (
                        first_species_center[0] + t1 * dx1,
                        first_species_center[1] + t1 * dy1
                    )
                    length1 = math.hypot(dx1, dy1)
                    pad_dx1 = (dx1 / length1) * 10 if length1 else 0
                    pad_dy1 = (dy1 / length1) * 10 if length1 else 0
                    first_curve_end = (
                        intersection1[0] + pad_dx1,
                        intersection1[1] + pad_dy1
                    )
                    dx2 = reaction_center[0] - second_species_center[0]
                    dy2 = reaction_center[1] - second_species_center[1]
                    w2, h2 = second_species.get_size()
                    half_w2, half_h2 = w2 / 2, h2 / 2
                    t_x2 = half_w2 / abs(dx2) if dx2 != 0 else float('inf')
                    t_y2 = half_h2 / abs(dy2) if dy2 != 0 else float('inf')
                    t2 = min(t_x2, t_y2)
                    intersection2 = (
                        second_species_center[0] + t2 * dx2,
                        second_species_center[1] + t2 * dy2
                    )
                    length2 = math.hypot(dx2, dy2)
                    pad_dx2 = (dx2 / length2) * 5 if length2 else 0
                    pad_dy2 = (dy2 / length2) * 5 if length2 else 0
                    second_curve_end = (
                        intersection2[0] + pad_dx2,
                        intersection2[1] + pad_dy2
                    )
                    first_curve.get_segment().set_end(first_curve_end)
                    second_curve.get_segment().set_end(second_curve_end)
                first_curve.get_segment().set_control_point_2(first_curve.get_segment().get_end())
                second_curve.get_segment().set_control_point_2(second_curve.get_segment().get_end())
                return True
            else:
                return True

        return False

    def show(self):
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.makeSpeciesReferenceVisible(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) == 0:
                return True

        #ToDo: Implement show reaction curve

        return False

    def hide(self):
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.makeSpeciesReferenceInvisible(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) == 0:
                return True

        #ToDo: Implement hide reaction curve

        return False

    def is_hidden(self):
        if self.species_reference_index is not None:
            if self.libsbmlnetwork.isSpeciesReferenceVisible(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) == 0:
                return True

        #ToDo: Implement hide reaction curve

        return False

    #ToDo: implement set arrow head

    def get_info(self):
        result = []
        #ToDo: Add the reaction, species, and role information
        result.append(f"role: {self.get_role()}")
        result.append(f"color: {self.get_color()}")
        result.append(f"thickness: {self.get_thickness()}")

        segments = self.get_segments_list()
        result.append("segments:")
        for segment in segments:
            result.append("\n".join(["    " + line for line in str(segment).split("\n")]))
            if segment != segments[-1]:
                result.append("----")

        result.append("arrow_head:")
        if self.get_arrow_head() is not None:
            result.append("\n".join(["    " + line for line in str(self.get_arrow_head()).split("\n")]))
        else:
            result.append("    None")

        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"Curve(reaction_id={self.reaction_id}, reaction_glyph_index={self.reaction_glyph_index}, species_reference_index={self.species_reference_index})"
