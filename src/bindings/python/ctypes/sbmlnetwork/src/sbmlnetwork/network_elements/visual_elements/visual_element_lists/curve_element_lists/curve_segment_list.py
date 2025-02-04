class CurveSegmentList(list):

    def __init__(self, segment_list=None):
        super().__init__(segment_list or [])

    def get_start(self):
        results = []
        for segment in self:
            results.append(segment.get_start())

        return results

    def set_start(self, start: tuple[float, float]):
        start_points = []
        for segment in self:
            start_points.append(segment.set_start(start))

        return start_points

    def get_end(self):
        segment_list = CurveSegmentList()
        for segment in self:
            segment_list.append(segment.get_end())

        return segment_list

    def set_end(self, end: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.set_end(end))

        return results

    def get_control_point_1(self):
        control_points = []
        for segment in self:
            control_points.append(segment.get_control_point_1())

        return control_points

    def set_control_point_1(self, control_point_1: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.set_control_point_1(control_point_1))

        return results

    def get_control_point_2(self):
        control_points = []
        for segment in self:
            control_points.append(segment.get_control_point_2())

        return control_points

    def set_control_point_2(self, control_point_2: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.set_control_point_2(control_point_2))

        return results

    def move(self, delta: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.move(delta))

        return results

    def move_start(self, delta: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.move_start(delta))

        return results

    def move_end(self, delta: tuple[float, float]):
        results = []
        for segment in self:
            results.append(segment.move_end(delta))

        return results

    def __str__(self):
        result = []
        for segment in self:
            result.append(str(segment))
        return "\n\n".join(result)

    def __repr__(self):
        return f"CurveSegmentList({[repr(segment) for segment in self]})"
