from typing import Union

from .curve_segment import CurveSegment
from ..visual_element_lists.curve_element_lists import *
from .arrow_head import ArrowHead

class Curve:

    def __init__(self, libsbmlnetwork, reaction_id, reaction_glyph_index, species_reference_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.reaction_id = reaction_id
        self.reaction_glyph_index = reaction_glyph_index
        self.species_reference_index = species_reference_index

    def get_reaction(self):
        from ...reaction import Reaction

        return Reaction(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index)

    def get_species(self):
        if self.species_reference_index is not None:
            reaction = self.get_reaction()
            species_list = reaction.get_species_list()
            species_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesId(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
            species_glyph_id = self.libsbmlnetwork.getSpeciesReferenceSpeciesGlyphId(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
            for species in species_list:
                if species.get_species_id() == species_id and species.get_id() == species_glyph_id:
                    return species

        return None

    def get_role(self):
        if self.species_reference_index is not None:
            species = self.get_species()
            reaction = self.get_reaction()
            return species.get_role(reaction)

        return None

    def get_roles_options(self):
        return self.libsbmlnetwork.getListOfRoles()

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

    def get_start_slope(self):
        first_segment = self.get_segments_list()[0]
        if first_segment is not None:
            first_point = first_segment.get_start()
            second_point = first_segment.get_control_point_1()
            if first_segment.get_start() == first_segment.get_control_point_1():
                second_point = first_segment.get_end()
            return (second_point[1] - first_point[1]) / (second_point[0] - first_point[0])

        return 0.0

    def get_end_slope(self):
        last_segment = self.get_segments_list()[-1]
        if last_segment is not None:
            first_point = last_segment.get_end()
            second_point = last_segment.get_control_point_2()
            if last_segment.get_end() == last_segment.get_control_point_2():
                second_point = last_segment.get_start()
            return (second_point[1] - first_point[1]) / (second_point[0] - first_point[0])

        return 0.0

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

    def move(self, delta: tuple[float, float]):
        if all(self.get_segments_list().move(delta)):
            return True

        return False

    def move_start(self, delta: tuple[float, float]):
        first_segment = self.get_segments_list()[0]
        if first_segment is not None:
            return first_segment.move_start(delta)

        return False

    def move_end(self, delta: tuple[float, float]):
        last_segment = self.get_segments_list()[-1]
        if last_segment is not None:
            return last_segment.move_end(delta)

        return False

    #ToDo: implement set arrow head

    def __str__(self):
        result = []
        #ToDo: Add the reaction, species, and role information
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


    def __repr__(self):
        return f"Curve(reaction_id={self.reaction_id}, reaction_glyph_index={self.reaction_glyph_index}, species_reference_index={self.species_reference_index})"
