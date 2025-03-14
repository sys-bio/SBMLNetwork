from ..visual_elements import *
from ..visual_elements.visual_element_lists import *

class NetworkElementBaseList(list):

    def __init__(self, network_element_base_list=None, libsbmlnetwork=None):
        super().__init__(network_element_base_list or [])
        self.libsbmlnetwork = libsbmlnetwork

    def get_ids(self):
        ids = []
        for element in self:
            ids.append(element.get_id())
            
        return ids

    @property
    def ids(self):
        return self.get_ids()

    def get_graphical_object_indices(self):
        graphical_object_indices = []
        for element in self:
            graphical_object_indices.append(element.get_graphical_object_index())
            
        return graphical_object_indices

    def get_positions(self):
        positions = []
        for element in self:
            positions.append(element.get_position())
            
        return positions

    def set_positions(self, position: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.set_position(position))
            
        return results

    @property
    def positions(self):
        return self.get_positions()

    def get_sizes(self):
        sizes = []
        for element in self:
            sizes.append(element.get_size())
            
        return sizes

    def set_sizes(self, size: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.set_size(size))
            
        return results

    @property
    def sizes(self):
        return self.get_sizes()

    def move_to(self, position: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.move_to(position))

        return results

    def move_by(self, delta: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.move_by(delta))

        return results

    def add_labels(self, text: str, relative_position: tuple[float, float] = (0.0, 0.0)):
        labels = LabelList()
        for element in self:
            labels.append(element.add_label(text, relative_position))
            
        return labels

    def remove_labels(self, text: str):
        results = []
        for element in self:
            results.append(element.remove_label(text))
            
        return results

    def remove_all_labels(self):
        results = []
        for element in self:
            results.append(element.remove_all_labels())

        return results

    def get_labels(self):
        labels = LabelList()
        for element in self:
            labels.append(element.get_label())

        return labels

    def get_labels_list(self):
        labels = LabelList()
        for element in self:
            labels.extend(element.get_labels_list())

        return labels

    def get_labels(self):
        return self.get_labels_list()

    @property
    def labels(self):
        return self.get_labels()

    def get_texts(self):
        texts = []
        for element in self:
            texts.append(element.get_text())

        return texts

    def set_texts(self, text: str):
        results = []
        for element in self:
            results.append(element.set_text(text))

        return results

    @property
    def texts(self):
        return self.get_texts()

    @texts.setter
    def texts(self, text: str):
        self.set_texts(text)

    def get_font_colors(self):
        font_colors = []
        for element in self:
            font_colors.append(element.get_font_color())

        return font_colors

    def set_font_colors(self, font_color: str):
        results = []
        for element in self:
            results.append(element.set_font_color(font_color))

        return results

    @property
    def font_colors(self):
        return self.get_font_colors()

    @font_colors.setter
    def font_colors(self, font_color: str):
        self.set_font_colors(font_color)

    def get_fonts(self):
        fonts = []
        for element in self:
            fonts.append(element.get_font())

        return fonts

    def set_fonts(self, font: str):
        results = []
        for element in self:
            results.append(element.set_font(font))

        return results

    @property
    def fonts(self):
        return self.get_fonts()

    @fonts.setter
    def fonts(self, font: str):
        self.set_fonts(font)

    def get_font_sizes(self):
        font_sizes = []
        for element in self:
            font_sizes.append(element.get_font_size())

        return font_sizes

    def set_font_sizes(self, font_size: float):
        results = []
        for element in self:
            results.append(element.set_font_size(font_size))

        return results

    @property
    def font_sizes(self):
        return self.get_font_sizes()

    @font_sizes.setter
    def font_sizes(self, font_size: float):
        self.set_font_sizes(font_size)

    def set_texts_bold(self, bold: bool):
        results = []
        for element in self:
            results.append(element.set_text_bold(bold))

        return results

    def are_texts_bold(self):
        is_bold = []
        for element in self:
            is_bold.append(element.is_text_bold())

        return is_bold

    @property
    def texts_bold(self):
        return self.are_texts_bold()

    @texts_bold.setter
    def texts_bold(self, bold: bool):
        self.set_texts_bold(bold)

    def set_texts_italic(self, italic: bool):
        results = []
        for element in self:
            results.append(element.set_text_italic(italic))

        return results

    def are_texts_italic(self):
        is_italic = []
        for element in self:
            is_italic.append(element.is_text_italic())

        return is_italic

    @property
    def texts_italic(self):
        return self.are_texts_italic()

    @texts_italic.setter
    def texts_italic(self, italic: bool):
        self.set_texts_italic(italic)

    def set_text_relative_positions(self, relative_position: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.set_text_relative_position(relative_position))

        return results

    def get_text_relative_positions(self):
        relative_positions = []
        for element in self:
            relative_positions.append(element.get_text_relative_position())

        return relative_positions

    @property
    def text_relative_positions(self):
        return self.get_text_relative_positions()

    @text_relative_positions.setter
    def text_relative_positions(self, relative_position: tuple[float, float]):
        self.set_text_relative_positions(relative_position)

    def move_texts_by(self, delta: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.move_text_by(delta))

        return results

    def move_texts_to(self, position: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.move_text_to(position))

        return results

    def add_shapes(self, shape_type: str):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for element in self:
            shapes.append(element.add_shape(shape_type))

        return shapes

    def remove_shapes(self, shape: ShapeBase):
        results = []
        for element in self:
            results.append(element.remove_shape(shape))

        return results

    def remove_all_shapes(self):
        results = []
        for element in self:
            results.append(element.remove_all_shapes())

        return results

    def get_shapes(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for element in self:
            shapes.append(element.get_shape())

        return shapes

    def set_shapes(self, shape_type: str):
        results = []
        for element in self:
            results.append(element.set_shape(shape_type))

        return results

    def get_shapes_list(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for element in self:
            shapes.extend(element.get_shapes_list())

        return shapes

    def get_shapes(self):
        return self.get_shapes_list()

    @property
    def shapes(self):
        return self.get_shapes()

    @shapes.setter
    def shapes(self, shape_type: str):
        self.set_shapes(shape_type)

    @property
    def shapes(self):
        return self.get_shapes()

    def get_shape_types(self):
        shape_types = []
        for element in self:
            shape_types.append(element.get_type())

        return shape_types

    @property
    def shape_types(self):
        return self.get_shape_types()

    def set_border_colors(self, border_color: str):
        results = []
        for element in self:
            results.append(element.set_border_color(border_color))

        return results

    def get_border_colors(self):
        border_colors = []
        for element in self:
            border_colors.append(element.get_border_color())

        return border_colors

    @property
    def border_colors(self):
        return self.get_border_colors()

    @border_colors.setter
    def border_colors(self, border_color: str):
        self.set_border_colors(border_color)

    def set_border_thicknesses(self, thickness: float):
        results = []
        for element in self:
            results.append(element.set_border_thickness(thickness))

        return results

    def get_border_thicknesses(self):
        thicknesses = []
        for element in self:
            thicknesses.append(element.get_border_thickness())

        return thicknesses

    @property
    def border_thicknesses(self):
        return self.get_border_thicknesses()

    @border_thicknesses.setter
    def border_thicknesses(self, thickness: float):
        self.set_border_thicknesses(thickness)

    def set_fill_colors(self, fill_color: str or tuple or list):
        results = []
        for element in self:
            results.append(element.set_fill_color(fill_color))

        return results

    def get_fill_colors(self):
        fill_colors = []
        for element in self:
            fill_colors.append(element.get_fill_color())

        return fill_colors

    @property
    def fill_colors(self):
        return self.get_fill_colors()

    @fill_colors.setter
    def fill_colors(self, fill_color: str or tuple or list):
        self.set_fill_colors(fill_color)

    def hide(self, apply_to_connected_elements=True):
        results = []
        for element in self:
            results.append(element.hide(apply_to_connected_elements))

        return results

    def show(self, apply_to_connected_elements=True):
        results = []
        for element in self:
            results.append(element.show(apply_to_connected_elements))

        return results

    def are_hidden(self):
        hidden_status = []
        for element in self:
            hidden_status.append(element.is_hidden())

        return hidden_status
