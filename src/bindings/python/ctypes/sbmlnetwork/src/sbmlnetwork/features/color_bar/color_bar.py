from ...network_elements.additional_element import AdditionalElement

class ColorBar(AdditionalElement):

    def __init__(self, libsbmlnetwork, element_id):
        super().__init__(libsbmlnetwork, element_id)
        self.default_width = 20
        self._initialize()

    def _initialize(self):
        left_margin = self.get_left_margin()
        right_margin = self.get_right_margin()
        border_color = self.get_border_color()
        border_thickness = self.get_border_thickness()
        corner_radius = self.get_corner_radius()
        gradient_colors = self.get_gradient_colors()
        number_of_tick_marks = self.get_number_of_tick_marks()
        tick_mark_size = self.get_tick_mark_size()
        tick_mark_thickness = self.get_tick_mark_thickness()
        tick_mark_color = self.get_tick_mark_color()
        super().set_position((self._get_max_compartments_position_x() + left_margin, 0.125 * self.libsbmlnetwork.getCanvasHeight()))
        super().set_size((self.default_width, 0.75 * self.libsbmlnetwork.getCanvasHeight()))
        self.libsbmlnetwork.setCanvasWidth(
            self._get_max_compartments_position_x() + left_margin + self.default_width + right_margin)
        while self.libsbmlnetwork.getNumGeometricShapes(self.element_id) > 0:
            self.libsbmlnetwork.removeGeometricShape(self.element_id, 0)
        self.libsbmlnetwork.addGeometricShape(self.element_id, geometric_shape_type="rectangle")
        self.get_shape().set_border_color(border_color)
        self.get_shape().set_border_thickness(border_thickness)
        self.get_shape().set_corner_radius((corner_radius, corner_radius))
        self.libsbmlnetwork.setGeometricShapeFillColorAsGradient(id=self.element_id, geometric_shape_index=0,
                                                                 stop_colors=gradient_colors,
                                                                 stop_offsets=[i * 100 / (len(gradient_colors) - 1) for i in
                                                                               range(len(gradient_colors))],
                                                                 gradient_type="linear")
        self._update_tick_marks(number_of_tick_marks, tick_mark_size, tick_mark_thickness, tick_mark_color)

    def _update_tick_marks(self, number_of_tick_marks: int, tick_mark_size: float = None, tick_mark_thickness: float = None, tick_mark_color: str = None):
        max_value = self.get_max_value()
        min_value = self.get_min_value()
        if tick_mark_size is None:
            tick_mark_size = self.get_tick_mark_size()
        if tick_mark_thickness is None:
            tick_mark_thickness = self.get_tick_mark_thickness()
        if tick_mark_color is None:
            tick_mark_color = self.get_tick_mark_color()
        while self.libsbmlnetwork.getNumGeometricShapes(self.element_id) > 1:
            self.libsbmlnetwork.removeGeometricShape(self.element_id, 1)
        for i in range(number_of_tick_marks):
            curve = self.add_shape("curve")
            points = [(self.get_size()[0] + tick_mark_size, self.get_size()[1] * i / (number_of_tick_marks - 1)),
                      (self.get_size()[0], self.get_size()[1] * i / (number_of_tick_marks - 1))]
            curve.set_points(points)
            curve.set_border_thickness(tick_mark_thickness)
            curve.set_border_color(tick_mark_color)

        return self._update_labels()

    def _update_labels(self):
        font_size = self.get_tick_mark_label_font_size()
        max_value = self.get_max_value()
        min_value = self.get_min_value()
        number_of_tick_marks = self.get_number_of_tick_marks()
        tick_mark_size = self.get_tick_mark_size()
        size = self.get_size()
        while self.libsbmlnetwork.getNumTextGlyphs(self.element_id) > 0:
            self.libsbmlnetwork.removeText(self.element_id, 0)
        labels = [str(round(i * (max_value - min_value) / (number_of_tick_marks - 1) + min_value, 2))
                  for i in range(number_of_tick_marks)]
        for i in range(len(labels)):
            y_position = (i / (number_of_tick_marks - 1) - 0.5) * size[
                1]
            label = self.add_label(labels[len(labels) - 1 - i], (size[0] + tick_mark_size, y_position + size[1] / 2))
            if not label.set_size((1.5 * label.get_size()[0], 1.5 * label.get_size()[0])):
                return False
            else:
                label.move_by((0.0, - label.get_size()[1] / 2))

        if not self._add_legend_label():
            return False

        return self.get_labels_list().set_font_sizes(font_size)

    def get_max_value(self):
        if self.get_labels_list() and len(self.get_labels_list()) > 0:
            return float(self.get_labels_list()[0].get_text())

        return 1.0

    def set_max_value(self, max_value: float):
        if max_value < self.get_min_value():
            raise ValueError("Max value must be greater than min value")
        if self.get_labels_list() and len(self.get_labels_list()) > 0:
            self.get_labels_list()[0].set_text(str(max_value))

        return self._update_labels()

    def get_min_value(self):
        if self.get_labels_list() and len(self.get_labels_list()) > 0:
            return float(self.get_labels_list()[-2].get_text())

        return 0.0

    def set_min_value(self, min_value: float):
        if min_value > self.get_max_value():
            raise ValueError("Min value must be less than max value")
        if self.get_labels_list() and len(self.get_labels_list()) > 0:
            self.get_labels_list()[-2].set_text(str(min_value))

        return self._update_labels()

    def get_number_of_tick_marks(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return len(self.get_shapes_list()) - 1

        return 5

    def set_number_of_tick_marks(self, number_of_tick_marks: int):
        if number_of_tick_marks < 2:
            raise ValueError("Number of tick marks must be greater at least 2")
        self._update_tick_marks(number_of_tick_marks)

    def get_tick_mark_size(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.get_shapes_list()[1].get_points()[0][0] - self.get_size()[0]

        return 6

    def set_tick_mark_size(self, tick_mark_size: float):
        if tick_mark_size < 0:
            raise ValueError("Tick mark size must be greater than 0")
        tick_mark_size_diff = tick_mark_size - self.get_tick_mark_size()
        for i, shape in enumerate(self.get_shapes_list()):
            if i > 0:
                points = shape.get_points()
                points[0] = (points[0][0] + tick_mark_size_diff, points[0][1])
                if shape.set_points(points) == False:
                    return False
        self._update_labels()

    def get_left_margin(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            max_compartments_position_x_max = self._get_max_compartments_position_x()
            return self.get_position()[0] - max_compartments_position_x_max

        return 1.5 * self.default_width

    def set_left_margin(self, left_margin: float):
        if left_margin < 0:
            raise ValueError("Left margin must be greater than 0")
        left_margin_diff = left_margin - self.get_left_margin()
        super().set_position((self.get_position()[0] + left_margin_diff, self.get_position()[1]))
        self.libsbmlnetwork.setCanvasWidth(self.libsbmlnetwork.getCanvasWidth() + left_margin_diff)

    def _get_max_compartments_position_x(self):
        max_compartments_position_x_max = 0
        for i in range(self.libsbmlnetwork.getNumCompartments()):
            compartment_id = self.libsbmlnetwork.getCompartmentId(i)
            compartment_position_x_max = self.libsbmlnetwork.getX(id=compartment_id) + self.libsbmlnetwork.getWidth(
                id=compartment_id)
            if compartment_position_x_max > max_compartments_position_x_max:
                max_compartments_position_x_max = compartment_position_x_max
        return max_compartments_position_x_max

    def get_right_margin(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.libsbmlnetwork.getCanvasWidth() - self.get_position()[0] - self.get_size()[0]

        return 2 * self.default_width

    def set_right_margin(self, right_margin: float):
        if right_margin < 0:
            raise ValueError("Right margin must be greater than 0")
        right_margin_diff = right_margin - self.get_right_margin()
        self.libsbmlnetwork.setCanvasWidth(self.libsbmlnetwork.getCanvasWidth() + right_margin_diff)

    def get_border_color(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.get_shapes_list()[0].get_border_color()

        return "#2C3E50"

    def set_border_color(self, border_color: str):
        return self.get_shapes_list()[0].set_border_color(border_color)

    def get_border_thickness(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.get_shapes_list()[0].get_border_thickness()

        return 3

    def set_border_thickness(self, border_thickness: float):
        if border_thickness < 0:
            raise ValueError("Border thickness must be greater than 0")

        return self.get_shapes_list()[0].set_border_thickness(border_thickness)

    def get_corner_radius(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.get_shapes_list()[0].get_corner_radius()[0]

        return 1

    def set_corner_radius(self, corner_radius: float):
        if corner_radius < 0:
            raise ValueError("Corner radius must be greater than 0")

        return self.get_shapes_list()[0].set_corner_radius((corner_radius, corner_radius))

    def get_gradient_colors(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            fill_color = self.get_shapes_list()[0].get_fill_color()
            for i in range(self.libsbmlnetwork.getNumLocalGradients()):
                gradient_id = self.libsbmlnetwork.getLocalGradientId(i)
                if gradient_id == fill_color:
                    gradient_colors = []
                    for j in range(self.libsbmlnetwork.getNumGradientStops(gradient_id)):
                        gradient_colors.append(self.libsbmlnetwork.getStopColor(gradient_id=gradient_id, gradient_stop_index=j))
                    return gradient_colors

        return ['#D32F2F', '#FF7F32', '#A8D400', '#00B4B4', '#1E3A5F']

    def set_gradient_colors(self, gradient_colors: list[str]):
        if self.libsbmlnetwork.setGeometricShapeFillColorAsGradient(id=self.element_id, geometric_shape_index=0,
                                                                    stop_colors=gradient_colors,
                                                                    stop_offsets=[i * 100 / (len(gradient_colors) - 1) for i in range(len(gradient_colors))],
                                                                    gradient_type="linear") == 0:
            return True

        return False

    def get_tick_mark_thickness(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.get_shapes_list()[1].get_border_thickness()

        return 1

    def set_tick_mark_thickness(self, tick_mark_thickness: float):
        if tick_mark_thickness < 0:
            raise ValueError("Tick mark thickness must be greater than 0")
        for i, shape in enumerate(self.get_shapes_list()):
            if i > 0:
                if not shape.set_border_thickness(tick_mark_thickness):
                    return False

        return True

    def get_tick_mark_color(self):
        if self.get_shapes_list() and len(self.get_shapes_list()) > 1:
            return self.get_shapes_list()[1].get_border_color()

        return "#2C3E50"

    def set_tick_mark_color(self, tick_mark_color: str):
        for i, shape in enumerate(self.get_shapes_list()):
            if i > 0:
                if not shape.set_border_color(tick_mark_color):
                    return False

        return True

    def get_tick_mark_label_font_size(self):
        if self.get_label() and self.get_label().get_font_size() > 0:
            return self.get_label().get_font_size()

        return 10

    def set_tick_mark_label_font_size(self, tick_mark_label_font_size: int):
        if tick_mark_label_font_size < 0:
            raise ValueError("Tick mark label font size must be greater than 0")
        for label in self.get_labels_list():
            if not label.set_font_size(tick_mark_label_font_size):
                return False

        return True

    def _get_color_bar_id(self):
        return self.element_id

    def get_horizontal_extent(self):
        return self.get_size()[0] + self.get_left_margin() + self.get_right_margin()

    def get_vertical_extent(self):
        return self.get_size()[1]

    def _add_legend_label(self):
        label_text = "Conc."
        if "flux" in self.get_id().lower():
            label_text = "Flux"
        label = self.add_label(label_text, (0, self.get_size()[1]))
        label.set_size((2 * label.get_size()[0], 2 * label.get_size()[0]))
        label.align_to_left()
        return True

    def get_info(self):
        return (
                f"left_margin: {self.get_left_margin()}\n" +
                f"right_margin: {self.get_right_margin()}\n" +
                f"border_color: {self.get_border_color()}\n" +
                f"border_thickness: {self.get_border_thickness()}\n" +
                f"corner_radius: {self.get_corner_radius()}\n" +
                f"gradient_colors: {self.get_gradient_colors()}\n" +
                f"tick_mark_thickness: {self.get_tick_mark_thickness()}\n" +
                f"tick_mark_color: {self.get_tick_mark_color()}\n" +
                f"tick_mark_label_font_size: {self.get_tick_mark_label_font_size()}\n" +
                f"max_value: {self.get_max_value()}\n" +
                f"min_value: {self.get_min_value()}\n" +
                f"number_of_tick_marks: {self.get_number_of_tick_marks()}\n" +
                f"tick_mark_size: {self.get_tick_mark_size()} \n" +
                f"position: {self.get_position()}\n" +
                f"size: {self.get_size()} \n" +
                f"legend_label: {self.get_labels_list()[-1].get_text()}"
        )

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"ColorBar(id={self.element_id})"
