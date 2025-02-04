class ArrowHeadList(list):

    def __init__(self, arrow_head_list=None):
        super().__init__(arrow_head_list or [])

    def get_relative_position(self):
        positions = []
        for arrow_head in self:
            positions.append(arrow_head.get_relative_position())

        return positions

    def set_relative_position(self, relative_position: tuple[float, float]):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_relative_position(relative_position))

        return results

    def get_size(self):
        sizes = []
        for arrow_head in self:
            sizes.append(arrow_head.get_size())

        return sizes

    def set_size(self, size: tuple[float, float]):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_size(size))

        return results

    def get_shape(self):
        from ...visual_element_lists import ShapeList

        shapes = ShapeList()
        for arrow_head in self:
            shapes.append(arrow_head.get_shape())

        return shapes

    def set_shape(self, shape_type: str):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_shape(shape_type))

        return results

    def add_shape(self, shape_type: str):
        from ..shape_list import ShapeList

        shapes = ShapeList()
        for arrow_head in self:
            shape = arrow_head.add_shape(shape_type)
            if shape:
                shapes.append(shape)
        return shapes

    def remove_shape(self, shape):
        results = []
        for arrow_head in self:
            results.append(arrow_head.remove_shape(shape))

        return results

    def get_shapes_list(self):
        from ...visual_element_lists import ShapeList

        shapes = ShapeList()
        for arrow_head in self:
            shapes.extend(arrow_head.get_shapes_list())

        return shapes

    def __str__(self):
        result = []
        for arrow_head in self:
            result.append(str(arrow_head))
        return "\n\n".join(result)

    def __repr__(self):
        return f"ArrowHeadList({[repr(arrow_head) for arrow_head in self]})"
