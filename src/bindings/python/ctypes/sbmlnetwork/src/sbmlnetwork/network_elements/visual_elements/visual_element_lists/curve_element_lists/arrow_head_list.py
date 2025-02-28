class ArrowHeadList(list):

    def __init__(self, arrow_head_list=None):
        super().__init__(arrow_head_list or [])

    def get_relative_positions(self):
        positions = []
        for arrow_head in self:
            positions.append(arrow_head.get_relative_position())

        return positions

    def set_relative_positions(self, relative_position: tuple[float, float]):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_relative_position(relative_position))

        return results

    @property
    def relative_positions(self):
        return self.get_relative_positions()

    @relative_positions.setter
    def relative_positions(self, relative_position: tuple[float, float]):
        self.set_relative_positions(relative_position)

    def get_sizes(self):
        sizes = []
        for arrow_head in self:
            sizes.append(arrow_head.get_size())

        return sizes

    def set_sizes(self, size: tuple[float, float]):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_size(size))

        return results

    @property
    def sizes(self):
        return self.get_sizes()

    @sizes.setter
    def sizes(self, size: tuple[float, float]):
        self.set_sizes(size)

    def get_shapes(self):
        from ...visual_element_lists import ShapeList

        shapes = ShapeList()
        for arrow_head in self:
            shapes.append(arrow_head.get_shape())

        return shapes

    def set_shapes(self, shape_type: str):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_shape(shape_type))

        return results

    @property
    def shapes(self):
        return self.get_shapes()

    @shapes.setter
    def shapes(self, shape_type: str):
        self.set_shapes(shape_type)

    def add_shapes(self, shape_type: str):
        from ..shape_list import ShapeList

        shapes = ShapeList()
        for arrow_head in self:
            shape = arrow_head.add_shape(shape_type)
            if shape:
                shapes.append(shape)
        return shapes

    def remove_shapes(self, shape):
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

    def get_shape_types(self):
        shape_types = []
        for arrow_head in self:
            shape_types.append(arrow_head.get_shape_type())

        return shape_types

    @property
    def shape_types(self):
        return self.get_shape_types()

    def get_border_colors(self):
        border_colors = []
        for arrow_head in self:
            border_colors.append(arrow_head.get_border_color())

        return border_colors

    def set_border_colors(self, border_color: str):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_border_color(border_color))

        return results

    @property
    def border_colors(self):
        border_colors = []
        for arrow_head in self:
            border_colors.append(arrow_head.get_border_color())

        return border_colors

    @border_colors.setter
    def border_colors(self, border_color: str):
        self.set_border_colors(border_color)

    def get_border_thicknesses(self):
        border_thicknesses = []
        for arrow_head in self:
            border_thicknesses.append(arrow_head.get_border_thickness())

        return border_thicknesses

    def set_border_thicknesses(self, thickness: float):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_border_thickness(thickness))

        return results

    @property
    def border_thicknesses(self):
        return self.get_border_thicknesses()

    @border_thicknesses.setter
    def border_thicknesses(self, thickness: float):
        self.set_border_thicknesses(thickness)

    def get_fill_colors(self):
        fill_colors = []
        for arrow_head in self:
            fill_colors.append(arrow_head.get_fill_color())

        return fill_colors

    def set_fill_colors(self, fill_color: str or tuple or list):
        results = []
        for arrow_head in self:
            results.append(arrow_head.set_fill_color(fill_color))

        return results

    @property
    def fill_colors(self):
        return self.get_fill_colors()

    @fill_colors.setter
    def fill_colors(self, fill_color: str or tuple or list):
        self.set_fill_colors(fill_color)

    def move_relative_positions_to(self, relative_position: tuple[float, float]):
        results = []
        for arrow_head in self:
            results.append(arrow_head.move_relative_position_to(relative_position))

        return results

    def move_relative_positions_by(self, delta: tuple[float, float]):
        results = []
        for arrow_head in self:
            results.append(arrow_head.move_relative_position_by(delta))

        return results

    def get_info(self):
        result = []
        for arrow_head in self:
            result.append(str(arrow_head))
        return "\n\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"ArrowHeadList({[repr(arrow_head) for arrow_head in self]})"
