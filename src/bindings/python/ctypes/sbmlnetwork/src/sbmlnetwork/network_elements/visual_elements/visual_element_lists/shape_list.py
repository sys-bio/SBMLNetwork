class ShapeList(list):

    def __init__(self, shape_list=None):
        super().__init__(shape_list or [])

    def get_types(self):
        types = []
        for shape in self:
            types.append(shape.get_type())

        return types

    @property
    def types(self):
        return self.get_types()

    def set_border_colors(self, border_color: str):
        results = []
        for shape in self:
            results.append(shape.set_border_color(border_color))

        return results

    def get_border_colors(self):
        colors = []
        for shape in self:
            colors.append(shape.get_border_color())

        return colors

    @property
    def border_colors(self):
        return self.get_border_colors()

    @border_colors.setter
    def border_colors(self, border_color: str):
        self.set_border_colors(border_color)

    def set_border_thicknesses(self, thickness: float):
        results = []
        for shape in self:
            results.append(shape.set_border_thickness(thickness))

        return results

    def get_border_thicknesses(self):
        thicknesses = []
        for shape in self:
            thicknesses.append(shape.get_border_thickness())

        return thicknesses

    @property
    def border_thicknesses(self):
        return self.get_border_thicknesses()

    @border_thicknesses.setter
    def border_thicknesses(self, thickness: float):
        self.set_border_thicknesses(thickness)

    def set_fill_colors(self, fill_color: str or tuple or list):
        results = []
        for shape in self:
            results.append(shape.set_fill_color(fill_color))

        return results

    def get_fill_colors(self):
        colors = []
        for shape in self:
            colors.append(shape.get_fill_color())

        return colors

    @property
    def fill_colors(self):
        return self.get_fill_colors()

    @fill_colors.setter
    def fill_colors(self, fill_color: str or tuple or list):
        self.set_fill_colors(fill_color)

    def get_info(self):
        result = []
        for shape in self:
            result.append(str(shape))
        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"ShapeList({[repr(shape) for shape in self]})"
