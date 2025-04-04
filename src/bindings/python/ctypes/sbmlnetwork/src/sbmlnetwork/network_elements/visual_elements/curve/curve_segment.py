class CurveSegment:

    def __init__(self, libsbmlnetwork, reaction_id, reaction_glyph_index, species_reference_index, curve_segment_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.reaction_id = reaction_id
        self.reaction_glyph_index = reaction_glyph_index
        self.species_reference_index = species_reference_index
        self.curve_segment_index = curve_segment_index

    def get_curve_segment_index(self):
        return self.curve_segment_index

    def get_start(self):
        if self.species_reference_index is None:
            return (self.libsbmlnetwork.getCurveSegmentStartPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getCurveSegmentStartPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index))
        else:
            return (self.libsbmlnetwork.getSpeciesReferenceCurveSegmentStartPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getSpeciesReferenceCurveSegmentStartPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index))

    def set_start(self, start: tuple[float, float]):
        if self.species_reference_index is None:
            if self.libsbmlnetwork.setCurveSegmentStartPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, x=start[0]) == 0 and \
                self.libsbmlnetwork.setCurveSegmentStartPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, y=start[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, x=start[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceCurveSegmentStartPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, y=start[1]) == 0:
                return True

        return False

    @property
    def start(self):
        return self.get_start()

    @start.setter
    def start(self, start: tuple[float, float]):
        self.set_start(start)

    def get_end(self):
        if self.species_reference_index is None:
            return (self.libsbmlnetwork.getCurveSegmentEndPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getCurveSegmentEndPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index))
        else:
            return (self.libsbmlnetwork.getSpeciesReferenceCurveSegmentEndPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getSpeciesReferenceCurveSegmentEndPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index))

    def set_end(self, end: tuple[float, float]):
        if self.species_reference_index is None:
            if self.libsbmlnetwork.setCurveSegmentEndPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, x=end[0]) == 0 and \
                self.libsbmlnetwork.setCurveSegmentEndPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, y=end[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, x=end[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceCurveSegmentEndPointY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, y=end[1]) == 0:
                return True

        return False

    @property
    def end(self):
        return self.get_end()

    @end.setter
    def end(self, end: tuple[float, float]):
        self.set_end(end)

    def get_control_point_1(self):
        if self.species_reference_index is None:
            return (self.libsbmlnetwork.getCurveSegmentBasePoint1X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getCurveSegmentBasePoint1Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index))
        else:
            return (self.libsbmlnetwork.getSpeciesReferenceCurveSegmentBasePoint1X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getSpeciesReferenceCurveSegmentBasePoint1Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index))

    def set_control_point_1(self, control_point_1: tuple[float, float]):
        if self.species_reference_index is None:
            if self.libsbmlnetwork.setCurveSegmentBasePoint1X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, x=control_point_1[0]) == 0 and \
                self.libsbmlnetwork.setCurveSegmentBasePoint1Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, y=control_point_1[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, x=control_point_1[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint1Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, y=control_point_1[1]) == 0:
                return True

        return False

    @property
    def control_point_1(self):
        return self.get_control_point_1()

    @control_point_1.setter
    def control_point_1(self, control_point_1: tuple[float, float]):
        self.set_control_point_1(control_point_1)

    def get_control_point_2(self):
        if self.species_reference_index is None:
            return (self.libsbmlnetwork.getCurveSegmentBasePoint2X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getCurveSegmentBasePoint2Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index))
        else:
            return (self.libsbmlnetwork.getSpeciesReferenceCurveSegmentBasePoint2X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index),
                self.libsbmlnetwork.getSpeciesReferenceCurveSegmentBasePoint2Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index))

    def set_control_point_2(self, control_point_2: tuple[float, float]):
        if self.species_reference_index is None:
            if self.libsbmlnetwork.setCurveSegmentBasePoint2X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, x=control_point_2[0]) == 0 and \
                self.libsbmlnetwork.setCurveSegmentBasePoint2Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, curve_segment_index=self.curve_segment_index, y=control_point_2[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2X(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, x=control_point_2[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceCurveSegmentBasePoint2Y(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, curve_segment_index=self.curve_segment_index, y=control_point_2[1]) == 0:
                return True

        return False

    @property
    def control_point_2(self):
        return self.get_control_point_2()

    @control_point_2.setter
    def control_point_2(self, control_point_2: tuple[float, float]):
        self.set_control_point_2(control_point_2)

    def move_by(self, delta: tuple[float, float]):
        current_start = self.get_start()
        new_start = (current_start[0] + delta[0], current_start[1] + delta[1])
        if not self.set_start(new_start):
            return False

        current_end = self.get_end()
        new_end = (current_end[0] + delta[0], current_end[1] + delta[1])
        if not self.set_end(new_end):
            return False

        current_control_point_1 = self.get_control_point_1()
        new_control_point_1 = (current_control_point_1[0] + delta[0], current_control_point_1[1] + delta[1])
        if not self.set_control_point_1(new_control_point_1):
            return False

        current_control_point_2 = self.get_control_point_2()
        new_control_point_2 = (current_control_point_2[0] + delta[0], current_control_point_2[1] + delta[1])
        if not self.set_control_point_2(new_control_point_2):
            return False

        return True

    def move_start_to(self, position: tuple[float, float]):
        start = self.get_start()
        return self.move_by((position[0] - start[0], position[1] - start[1]))

    def move_start_by(self, delta: tuple[float, float]):
        current_start = self.get_start()
        new_start = (current_start[0] + delta[0], current_start[1] + delta[1])
        if not self.set_start(new_start):
            return False

        current_control_point_1 = self.get_control_point_1()
        new_control_point_1 = (current_control_point_1[0] + delta[0], current_control_point_1[1] + delta[1])
        if not self.set_control_point_1(new_control_point_1):
            return False

        return True

    def move_end_to(self, position: tuple[float, float]):
        end = self.get_end()
        return self.move_by((position[0] - end[0], position[1] - end[1]))

    def move_end_by(self, delta: tuple[float, float]):
        current_end = self.get_end()
        new_end = (current_end[0] + delta[0], current_end[1] + delta[1])
        if not self.set_end(new_end):
            return False

        current_control_point_2 = self.get_control_point_2()
        new_control_point_2 = (current_control_point_2[0] + delta[0], current_control_point_2[1] + delta[1])
        if not self.set_control_point_2(new_control_point_2):
            return False

        return True

    def get_info(self):
        return(
            f"start: {self.get_start()}\n"
            f"end: {self.get_end()}\n"
            f"control_point_1: {self.get_control_point_1()}\n"
            f"control_point_2: {self.get_control_point_2()}"
        )

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"CurveSegment(reaction_id={self.reaction_id}, reaction_glyph_index={self.reaction_glyph_index}, species_reference_index={self.species_reference_index}, curve_segment_index={self.curve_segment_index})"
