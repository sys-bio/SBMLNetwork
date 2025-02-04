class ShapeList(list):

    def __init__(self, shape_list=None):
        super().__init__(shape_list or [])

    def get_type(self):
        types = []
        for shape in self:
            types.append(shape.get_type())

        return types

    def set_border_color(self, border_color: str):
        results = []
        for shape in self:
            results.append(shape.set_border_color(border_color))

        return results

    def get_border_color(self):
        colors = []
        for shape in self:
            colors.append(shape.get_border_color())

        return colors

    def set_border_thickness(self, thickness: float):
        results = []
        for shape in self:
            results.append(shape.set_border_thickness(thickness))

        return results

    def get_border_thickness(self):
        thicknesses = []
        for shape in self:
            thicknesses.append(shape.get_border_thickness())

        return thicknesses

    def set_fill_color(self, fill_color: str or tuple or list):
        results = []
        for shape in self:
            results.append(shape.set_fill_color(fill_color))

        return results

    def get_fill_color(self):
        colors = []
        for shape in self:
            colors.append(shape.get_fill_color())

        return colors

    def __str__(self):
        result = []
        for shape in self:
            result.append(str(shape))
        return "\n".join(result)

    def __repr__(self):
        return f"ShapeList({[repr(shape) for shape in self]})"
