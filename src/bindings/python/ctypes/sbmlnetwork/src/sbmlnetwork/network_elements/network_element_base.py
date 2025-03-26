from .visual_elements import *


class NetworkElementBase:

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.element_id = element_id
        self.graphical_object_index = graphical_object_index
        self.meta_data = {}

    def get_id(self):
        return self.libsbmlnetwork.getId(id=self.element_id, graphical_object_index=self.graphical_object_index)

    @property
    def id(self):
        return self.get_id()

    def get_graphical_object_index(self):
        return self.graphical_object_index

    def get_position(self):
        return (self.libsbmlnetwork.getX(id=self.element_id, graphical_object_index=self.graphical_object_index),
                self.libsbmlnetwork.getY(id=self.element_id, graphical_object_index=self.graphical_object_index))

    def set_position(self, position: tuple[float, float]):
        if self._can_move_to(position):
            if self.libsbmlnetwork.setX(id=self.element_id, graphical_object_index=self.graphical_object_index, x=position[0], update_curves=False) == 0 and \
                    self.libsbmlnetwork.setY(id=self.element_id, graphical_object_index=self.graphical_object_index, y=position[1], update_curves=False) == 0:
                return True

            return False

        raise ValueError(f"The network element {self.get_id()} cannot be moved to {position} because it would lead to negative coordinates.")

    @property
    def position(self):
        return self.get_position()

    @position.setter
    def position(self, position: tuple[float, float]):
        self.set_position(position)

    def get_size(self):
        return (self.libsbmlnetwork.getWidth(id=self.element_id, graphical_object_index=self.graphical_object_index),
                self.libsbmlnetwork.getHeight(id=self.element_id, graphical_object_index=self.graphical_object_index))

    def set_size(self, size: tuple[float, float]):
        if self.libsbmlnetwork.setWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, width=size[0], update_curves=False) == 0 and \
                self.libsbmlnetwork.setHeight(id=self.element_id, graphical_object_index=self.graphical_object_index, height=size[1], update_curves=False) == 0:
            return True

        return False

    @property
    def size(self):
        return self.get_size()

    @size.setter
    def size(self, size: tuple[float, float]):
        self.set_size(size)

    def add_label(self, text: str, relative_position: tuple[float, float] = (0.0, 0.0)):
        if self.libsbmlnetwork.addText(id=self.element_id, graphical_object_index=self.graphical_object_index, text=text) == 0:
            absolute_x = self.libsbmlnetwork.getX(id=self.element_id, graphical_object_index=self.graphical_object_index) + relative_position[0]
            absolute_y = self.libsbmlnetwork.getY(id=self.element_id, graphical_object_index=self.graphical_object_index) + relative_position[1]
            text_glyph_index = self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index) - 1
            if self.libsbmlnetwork.setTextX(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index, x=absolute_x) == 0 and \
                    self.libsbmlnetwork.setTextY(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index, y=absolute_y) == 0:
                return Label(self.libsbmlnetwork, self.element_id, self.graphical_object_index, text_glyph_index)

        return None

    def remove_label(self, text: str):
        removed = False
        for text_glyph_index in range(self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index)):
            if self.libsbmlnetwork.getText(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index) == text:
                if self.libsbmlnetwork.removeText(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index) == 0:
                    removed = True

        return removed

    def remove_all_labels(self):
        could_not_remove = False
        while self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index) > 0:
            if self.libsbmlnetwork.removeText(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=0) == 0:
                continue
            else:
                could_not_remove = True

        return not could_not_remove

    def get_label(self):
        if self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index) > 0:
            return Label(self.libsbmlnetwork, self.element_id, self.graphical_object_index, 0)

        return None

    def get_labels_list(self):
        labels = LabelList()
        for text_glyph_index in range(self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index)):
            labels.append(Label(self.libsbmlnetwork, self.element_id, self.graphical_object_index, text_glyph_index))

        return labels

    def get_labels(self):
        return self.get_labels_list()

    @property
    def labels(self):
        return self.get_labels_list()

    def get_text(self):
        texts = self.get_labels_list().get_texts()
        if len(texts) == 1:
            return texts[0]

        return texts

    def set_text(self, text: str):
        return self.get_labels_list().set_texts(text)

    @property
    def text(self):
        return self.get_text()

    @text.setter
    def text(self, text: str):
        self.set_text(text)

    def get_font_color(self):
        font_colors = self.get_labels_list().get_font_colors()
        if len(font_colors) == 1:
            return font_colors[0]

        return font_colors

    def set_font_color(self, font_color: str):
        return self.get_labels_list().set_font_colors(font_color)

    @property
    def font_color(self):
        return self.get_font_color()

    @font_color.setter
    def font_color(self, font_color: str):
        self.set_font_color(font_color)

    def get_font(self):
        fonts = self.get_labels_list().get_fonts()
        if len(fonts) == 1:
            return fonts[0]

        return fonts

    def set_font(self, font):
        return self.get_labels_list().set_fonts(font)

    @property
    def font(self):
        return self.get_font()

    @font.setter
    def font(self, font):
        self.set_font(font)

    def get_font_size(self):
        font_sizes = self.get_labels_list().get_font_sizes()
        if len(font_sizes) == 1:
            return font_sizes[0]

        return font_sizes

    def set_font_size(self, font_size: float):
        return self.get_labels_list().set_font_sizes(font_size)

    @property
    def font_size(self):
        return self.get_font_size()

    @font_size.setter
    def font_size(self, font_size: float):
        self.set_font_size(font_size)

    def set_text_bold(self, bold: bool):
        return self.get_labels_list().set_bold(bold)

    def is_text_bold(self):
        is_bold = self.get_labels_list().are_bold()
        if len(is_bold) == 1:
            return is_bold[0]

        return is_bold

    @property
    def text_bold(self):
        return self.is_text_bold()

    @text_bold.setter
    def text_bold(self, bold: bool):
        self.set_text_bold(bold)

    def set_text_italic(self, italic: bool):
        return self.get_labels_list().set_italic(italic)

    def is_text_italic(self):
        is_italic = self.get_labels_list().are_italic()
        if len(is_italic) == 1:
            return is_italic[0]

        return is_italic

    @property
    def text_italic(self):
        return self.is_text_italic()

    @text_italic.setter
    def text_italic(self, italic: bool):
        self.set_text_italic(italic)

    def set_text_relative_position(self, relative_position: tuple[float, float]):
        position = self.get_position()
        return self.get_labels_list().set_positions((position[0] + relative_position[0], position[1] + relative_position[1]))

    def get_text_relative_position(self):
        labels_positions = self.get_labels_list().get_positions()
        position = self.get_position()
        relative_positions = []
        for label_position in labels_positions:
            relative_positions.append((label_position[0] - position[0], label_position[1] - position[1]))

        if len(relative_positions) == 1:
            return relative_positions[0]

        return relative_positions

    @property
    def text_relative_position(self):
        return self.get_text_relative_position()

    @text_relative_position.setter
    def text_relative_position(self, relative_position: tuple[float, float]):
        self.set_text_relative_position(relative_position)

    def move_text_by(self, delta: tuple[float, float]):
        return self.get_labels_list().move_by(delta)

    def move_text_to(self, position: tuple[float, float]):
        return self.get_labels_list().move_to(position)

    def add_shape(self, shape_type: str):
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if shape_type not in valid_geometric_shapes:
            raise ValueError(f"Shape type must be one of {valid_geometric_shapes}")
        num_geometric_shapes = self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index)
        if num_geometric_shapes > 0:
            self.libsbmlnetwork.addGeometricShape(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_type=shape_type)
        else:
            self.libsbmlnetwork.setGeometricShapeType(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape=shape_type)
        if self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) > num_geometric_shapes:
            geometric_shape_index = self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) - 1
            return create_shape(self.libsbmlnetwork, self.element_id, self.graphical_object_index, geometric_shape_index)

        return None

    def remove_shape(self, shape: ShapeBase):
        if shape is not None:
            if self.libsbmlnetwork.removeGeometricShape(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=shape.get_geometric_shape_index()) == 0:
                return True

        return False

    def remove_all_shapes(self):
        could_not_remove = False
        while self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) > 0:
            if self.libsbmlnetwork.removeGeometricShape(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=0) == 0:
                continue
            else:
                could_not_remove = True

        return not could_not_remove

    def get_shape(self):
        if self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) > 0:
            return create_shape(self.libsbmlnetwork, self.element_id, self.graphical_object_index, 0)

        return None

    def set_shape(self, shape_type: str):
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if shape_type not in valid_geometric_shapes:
            raise ValueError(f"Shape type must be one of {valid_geometric_shapes}")
        if self.libsbmlnetwork.setGeometricShapeType(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape=shape_type) == 0:
            return True

        return False

    @property
    def shape(self):
        return self.get_shape()

    @shape.setter
    def shape(self, shape_type: str):
        self.set_shape(shape_type)

    def get_shapes_list(self):
        shapes = ShapeList()
        for geometric_shape_index in range(
                self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index)):
            shape = create_shape(self.libsbmlnetwork, self.element_id, self.graphical_object_index, geometric_shape_index)
            if shape is not None:
                shapes.append(shape)

        return shapes

    def get_shapes(self):
        return self.get_shapes_list()

    @property
    def shapes(self):
        return self.get_shapes_list()

    def get_shape_options(self):
        return self.libsbmlnetwork.getListOfGeometricShapes()

    @property
    def shape_options(self):
        return self.get_shape_options()

    def get_shape_type(self):
        return self.get_shapes_list().get_types()

    @property
    def shape_type(self):
        return self.get_shape_type()

    def get_border_color(self):
        return self.get_shapes_list().get_border_colors()

    def set_border_color(self, border_color: str):
        return self.get_shapes_list().set_border_colors(border_color)

    @property
    def border_color(self):
        return self.get_border_color()

    @border_color.setter
    def border_color(self, border_color: str):
        self.set_border_color(border_color)

    def get_border_thickness(self):
        return self.get_shapes_list().get_border_thicknesses()

    def set_border_thickness(self, thickness: float):
        return self.get_shapes_list().set_border_thicknesses(thickness)

    @property
    def border_thickness(self):
        return self.get_border_thickness()

    @border_thickness.setter
    def border_thickness(self, thickness: float):
        self.set_border_thickness(thickness)

    def get_fill_color(self):
        return self.get_shapes_list().get_fill_colors()

    def set_fill_color(self, fill_color: str or tuple or list):
        return self.get_shapes_list().set_fill_colors(fill_color)

    @property
    def fill_color(self):
        return self.get_fill_color()

    @fill_color.setter
    def fill_color(self, fill_color: str or tuple or list):
        self.set_fill_color(fill_color)

    def hide(self, apply_to_connected_elements=True):
        if self.libsbmlnetwork.makeInvisible(id=self.element_id, graphical_object_index=self.graphical_object_index, apply_to_connected_elements=apply_to_connected_elements) == 0:
            return True

        return False

    def show(self, apply_to_connected_elements=True):
        if self.libsbmlnetwork.makeVisible(id=self.element_id, graphical_object_index=self.graphical_object_index, apply_to_connected_elements=apply_to_connected_elements) == 0:
            return True

        return False

    def is_hidden(self):
        if self.libsbmlnetwork.isVisible(id=self.element_id, graphical_object_index=self.graphical_object_index) == 0:
            return True

        return False

    def move_to(self, position: tuple[float, float]):
        return self.move_by((position[0] - self.get_position()[0], position[1] - self.get_position()[1]))

    def move_by(self, delta: tuple[float, float]):
        if self._can_move_by(delta):
            current_position = self.get_position()
            new_position = (current_position[0] + delta[0], current_position[1] + delta[1])
            return self.set_position(new_position)

        raise ValueError(f"The network element {self.get_id()} cannot be moved by {delta} because it would lead to negative coordinates.")

    @staticmethod
    def _can_move_to(position: tuple[float, float]):
        if position[0] < 0 or position[1] < 0:
            return False

        return True

    def _can_move_by(self, delta: tuple[float, float]):
        current_position = self.get_position()
        new_position = (current_position[0] + delta[0], current_position[1] + delta[1])
        if new_position[0] < 0 or new_position[1] < 0:
            return False

        return True
