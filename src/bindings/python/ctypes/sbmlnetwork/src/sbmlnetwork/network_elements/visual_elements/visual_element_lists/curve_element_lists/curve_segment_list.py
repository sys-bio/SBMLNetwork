class CurveSegmentList(list):

    def __init__(self, segment_list=None):
        super().__init__(segment_list or [])

    def get_starts(self):
        results = []
        for segment in self:
            results.append(segment.get_start())

        return results

    def set_starts(self, start: tuple[float, float]):
        start_points = []
        for segment in self:
            start_points.append(segment.set_start(start))

        return start_points

    @property
    def starts(self):
        return self.get_starts()

    @starts.setter
    def starts(self, start: tuple[float, float]):
        self.set_starts(start)

    def get_ends(self):
        segment_list = CurveSegmentList()
        for segment in self:
            segment_list.append(segment.get_end())

        return segment_list

    def set_ends(self, end: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.set_end(end))

        return results

    @property
    def ends(self):
        return self.get_ends()

    @ends.setter
    def ends(self, end: tuple[float, float]):
        self.set_ends(end)

    def get_control_point_1s(self):
        control_points = []
        for segment in self:
            control_points.append(segment.get_control_point_1())

        return control_points

    def set_control_point_1s(self, control_point_1: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.set_control_point_1(control_point_1))

        return results

    @property
    def control_point_1s(self):
        return self.get_control_point_1s()

    @control_point_1s.setter
    def control_point_1s(self, control_point_1: tuple[float, float]):
        self.set_control_point_1s(control_point_1)

    def get_control_point_2s(self):
        control_points = []
        for segment in self:
            control_points.append(segment.get_control_point_2())

        return control_points

    def set_control_point_2s(self, control_point_2: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.set_control_point_2(control_point_2))

        return results

    @property
    def control_point_2s(self):
        return self.get_control_point_2s()

    @control_point_2s.setter
    def control_point_2s(self, control_point_2: tuple[float, float]):
        self.set_control_point_2s(control_point_2)

    def move_by(self, delta: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.move_by(delta))

        return results

    def move_starts_to(self, start: tuple[float, float]):
        return self.set_starts(start)

    def move_starts_by(self, delta: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.move_start_by(delta))

        return results

    def move_ends_to(self, end: tuple[float, float]):
        return self.set_ends(end)

    def move_ends_by(self, delta: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.move_end_by(delta))

        return results

    def get_info(self):
        result = []
        for segment in self:
            result.append(str(segment))
        return "\n\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"CurveSegmentList({[repr(segment) for segment in self]})"
