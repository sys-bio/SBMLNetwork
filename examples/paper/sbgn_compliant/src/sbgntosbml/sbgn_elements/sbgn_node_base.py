from .sbgn_2d_element_base import SBGN2DElementBase
import math


class SBGNNodeBase(SBGN2DElementBase):

    def __init__(self, node_id, x, y, width, height, text="", text_x=math.nan, text_y=math.nan, text_width=math.nan,
                 text_height=math.nan,
                 font_size=14, text_vertical_alignment="middle", text_horizontal_alignment="middle", sub_elements=None):
        super(SBGNNodeBase, self).__init__(node_id, x, y, width, height, sub_elements)
        self.text = text
        self.text_x = text_x
        self.text_y = text_y
        self.text_width = text_width
        self.text_height = text_height
        self.font_size = font_size
        self.text_vertical_alignment = text_vertical_alignment
        self.text_horizontal_alignment = text_horizontal_alignment

    def get_text(self):
        return self.text

    def set_text(self, text):
        self.text = text

    def get_text_x(self):
        if math.isnan(self.text_x):
            return self.x

        return self.text_x

    def set_text_x(self, text_x):
        self.text_x = text_x

    def get_text_y(self):
        if math.isnan(self.text_y):
            return self.y

        return self.text_y

    def set_text_y(self, text_y):
        self.text_y = text_y

    def get_text_width(self):
        if math.isnan(self.text_width):
            return self.width

        return self.text_width

    def set_text_width(self, text_width):
        self.text_width = text_width

    def get_text_height(self):
        if math.isnan(self.text_height):
            return self.height

        return self.text_height

    def set_text_height(self, text_height):
        self.text_height = text_height

    def get_font_size(self):
        return self.font_size

    def set_font_size(self, font_size):
        self.font_size = font_size

    def get_text_vertical_alignment(self):
        return self.text_vertical_alignment

    def set_text_vertical_alignment(self, text_vertical_alignment):
        self.text_vertical_alignment = text_vertical_alignment

    def get_text_horizontal_alignment(self):
        return self.text_horizontal_alignment

    def set_text_horizontal_alignment(self, text_horizontal_alignment):
        self.text_horizontal_alignment = text_horizontal_alignment

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        if parent_element is None:
            parent_element = self
        self.initialize_sbml_info(sbmlnetwork_object, parent_element)
        self.add_geometric_shape(sbmlnetwork_object, parent_element)
        self.load_sbml_text_info(sbmlnetwork_object, parent_element)
        self.load_sbml_info_with_sub_elements(sbmlnetwork_object, parent_element)

    def initialize_sbml_info(self, sbmlnetwork_object, parent_element):
        if parent_element.get_id() == self.get_id():
            sbmlnetwork_object.libsbmlnetwork.setX(parent_element.get_id(), self.get_x(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setY(parent_element.get_id(), self.get_y(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setWidth(parent_element.get_id(), self.get_width(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setHeight(parent_element.get_id(), self.get_height(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.removeGeometricShape(self.get_id())
            sbmlnetwork_object.libsbmlnetwork.removeText(self.get_id())

    def load_sbml_text_info(self, sbmlnetwork_object, parent_element=None):
        if parent_element is None:
            parent_element = self
        if self.get_text() != "":
            sbmlnetwork_object.libsbmlnetwork.addText(parent_element.get_id(), self.get_text())
            text_glyph_index = sbmlnetwork_object.libsbmlnetwork.getNumTextGlyphs(parent_element.get_id()) - 1
            sbmlnetwork_object.libsbmlnetwork.setFontSize(parent_element.get_id(), self.get_font_size(), text_glyph_index=text_glyph_index)
            sbmlnetwork_object.libsbmlnetwork.setTextX(parent_element.get_id(), self.get_text_x(), text_glyph_index=text_glyph_index)
            sbmlnetwork_object.libsbmlnetwork.setTextY(parent_element.get_id(), self.get_text_y(), text_glyph_index=text_glyph_index)
            sbmlnetwork_object.libsbmlnetwork.setTextWidth(parent_element.get_id(), self.get_text_width(), text_glyph_index=text_glyph_index)
            sbmlnetwork_object.libsbmlnetwork.setTextHeight(parent_element.get_id(), self.get_text_height(), text_glyph_index=text_glyph_index)

    def __str__(self):
        return (super().__str__() +
                ", text: " + self.text + ", text_x: " + str(self.text_x) + ", text_y: " + str(self.text_y) + ", text_width: " + str(self.text_width) + ", text_height: " + str(self.text_height) +
                ", font_size: " + str(self.font_size) + ", text_vertical_alignment: " + self.text_vertical_alignment + ", text_horizontal_alignment: " +self.text_horizontal_alignment +
                ", sub_elements: " + str(self.sub_elements))