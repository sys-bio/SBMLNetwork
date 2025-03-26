class Label:

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index, text_glyph_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.element_id = element_id
        self.graphical_object_index = graphical_object_index
        self.text_glyph_index = text_glyph_index

    def get_position(self):
        return (self.libsbmlnetwork.getTextX(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                  text_glyph_index=self.text_glyph_index),
                self.libsbmlnetwork.getTextY(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                  text_glyph_index=self.text_glyph_index))

    def set_position(self, position: tuple[float, float]):
        if self.libsbmlnetwork.setTextX(id=self.element_id, graphical_object_index=self.graphical_object_index,
                             text_glyph_index=self.text_glyph_index, x=position[0]) == 0 and \
                self.libsbmlnetwork.setTextY(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                  text_glyph_index=self.text_glyph_index, y=position[1]) == 0:
            return True

        return False

    @property
    def position(self):
        return self.get_position()

    @position.setter
    def position(self, position: tuple[float, float]):
        self.set_position(position)

    def get_relative_position(self):
        element_position = (self.libsbmlnetwork.getX(id=self.element_id, graphical_object_index=self.graphical_object_index),
                            self.libsbmlnetwork.getY(id=self.element_id, graphical_object_index=self.graphical_object_index))
        text_position = self.get_position()
        return (text_position[0] - element_position[0], text_position[1] - element_position[1])

    def set_relative_position(self, relative_position: tuple[float, float]):
        element_position = (self.libsbmlnetwork.getX(id=self.element_id, graphical_object_index=self.graphical_object_index),
                            self.libsbmlnetwork.getY(id=self.element_id, graphical_object_index=self.graphical_object_index))
        text_position = (element_position[0] + relative_position[0], element_position[1] + relative_position[1])
        return self.set_position(text_position)

    @property
    def relative_position(self):
        return self.get_relative_position()

    @relative_position.setter
    def relative_position(self, relative_position: tuple[float, float]):
        self.set_relative_position(relative_position)

    def get_size(self):
        return (self.libsbmlnetwork.getTextWidth(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                     text_glyph_index=self.text_glyph_index),
            self.libsbmlnetwork.getTextHeight(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                   text_glyph_index=self.text_glyph_index))

    def set_size(self, size: tuple[float, float]):
        if self.libsbmlnetwork.setTextWidth(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                 text_glyph_index=self.text_glyph_index, width=size[0]) == 0 and \
                self.libsbmlnetwork.setTextHeight(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                       text_glyph_index=self.text_glyph_index, height=size[1]) == 0:
            return True

        return False

    @property
    def size(self):
        return self.get_size()

    @size.setter
    def size(self, size: tuple[float, float]):
        self.set_size(size)

    def align_to_top(self):
        if self.libsbmlnetwork.setTextVerticalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_vertical_alignment="top"):
            return True

        return False

    def align_to_vertical_center(self):
        if self.libsbmlnetwork.setTextVerticalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_vertical_alignment="middle"):
            return True

        return False

    def align_to_baseline(self):
        if self.libsbmlnetwork.setTextVerticalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_vertical_alignment="baseline"):
            return True

        return False

    def align_to_bottom(self):
        if self.libsbmlnetwork.setTextVerticalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_vertical_alignment="bottom"):
            return True

        return False

    def get_vertical_alignment(self):
        alignment = self.libsbmlnetwork.getTextVerticalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                    text_glyph_index=self.text_glyph_index)
        if alignment == "top":
            return "top"
        elif alignment == "middle":
            return "vertical_center"
        elif alignment == "baseline":
            return "baseline"
        elif alignment == "bottom":
            return "bottom"

        return None

    @property
    def vertical_alignment(self):
        return self.get_vertical_alignment()

    def align_to_left(self):
        if self.libsbmlnetwork.setTextHorizontalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_horizontal_alignment="start"):
            return True

        return False

    def align_to_horizontal_center(self):
        if self.libsbmlnetwork.setTextHorizontalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_horizontal_alignment="middle"):
            return True

        return False

    def align_to_right(self):
        if self.libsbmlnetwork.setTextHorizontalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                 text_glyph_index=self.text_glyph_index, text_horizontal_alignment="end"):
            return True

        return False

    def get_horizontal_alignment(self):
        alignment = self.libsbmlnetwork.getTextHorizontalAlignment(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                                    text_glyph_index=self.text_glyph_index)
        if alignment == "start":
            return "left"
        elif alignment == "middle":
            return "horizontal_center"
        elif alignment == "end":
            return "right"

        return None

    @property
    def horizontal_alignment(self):
        return self.get_horizontal_alignment

    def get_text(self):
        return self.libsbmlnetwork.getText(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                text_glyph_index=self.text_glyph_index)

    def set_text(self, text: str):
        if self.libsbmlnetwork.setText(id=self.element_id, graphical_object_index=self.graphical_object_index,
                            text_glyph_index=self.text_glyph_index, text=text) == 0:
            return True

        return False

    @property
    def text(self):
        return self.get_text()

    @text.setter
    def text(self, text: str):
        self.set_text(text)

    def get_font_color(self):
        return self.libsbmlnetwork.getFontColor(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                     text_glyph_index=self.text_glyph_index)

    def set_font_color(self, font_color: str):
        if self.libsbmlnetwork.setFontColor(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                 text_glyph_index=self.text_glyph_index, font_color=font_color) == 0:
            return True

        return False

    @property
    def font_color(self):
        return self.get_font_color()

    @font_color.setter
    def font_color(self, font_color: str):
        self.set_font_color(font_color)

    def get_font(self):
        return self.libsbmlnetwork.getFontFamily(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                      text_glyph_index=self.text_glyph_index)

    def set_font(self, font):
        if self.libsbmlnetwork.setFontFamily(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                  text_glyph_index=self.text_glyph_index, font_family=font) == 0:
            return True

        return False

    @property
    def font(self):
        return self.get_font()

    @font.setter
    def font(self, font):
        self.set_font(font)

    def get_font_size(self):
        return self.libsbmlnetwork.getFontSize(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                    text_glyph_index=self.text_glyph_index)

    def set_font_size(self, font_size: float):
        if self.libsbmlnetwork.setFontSize(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                text_glyph_index=self.text_glyph_index, font_size=font_size) == 0:
            return True

        return False

    @property
    def font_size(self):
        return self.get_font_size()

    @font_size.setter
    def font_size(self, font_size: float):
        self.set_font_size(font_size)

    def set_bold(self, bold: bool):
        if bold:
            return self.libsbmlnetwork.setFontWeight(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                          text_glyph_index=self.text_glyph_index, font_weight="bold") == 0
        else:
            return self.libsbmlnetwork.setFontWeight(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                          text_glyph_index=self.text_glyph_index, font_weight="normal") == 0

    def is_bold(self):
        if self.libsbmlnetwork.getFontWeight(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                  text_glyph_index=self.text_glyph_index) == "bold":
            return True
        else:
            return False

    def set_italic(self, italic: bool):
        if italic:
            return self.libsbmlnetwork.setFontStyle(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                         text_glyph_index=self.text_glyph_index, font_style="italic") == 0
        else:
            return self.libsbmlnetwork.setFontStyle(id=self.element_id, graphical_object_index=self.graphical_object_index,
                                         text_glyph_index=self.text_glyph_index, font_style="normal") == 0

    def is_italic(self):
        if self.libsbmlnetwork.getFontStyle(self.element_id, self.graphical_object_index, self.text_glyph_index) == "italic":
            return True

        return False

    #ToDo hide/show label

    def move_to(self, position: tuple[float, float]):
        if self.set_position(position):
            return True

        return False

    def move_by(self, position: tuple[float, float]):
        current_position = self.get_position()
        new_position = (current_position[0] + position[0], current_position[1] + position[1])
        if self.set_position(new_position):
            return True

        return False

    def get_info(self):
        return (
            f"text: {self.get_text()}\n"
            f"position: {self.get_position()}\n"
            f"size: {self.get_size()}\n"
            f"font: {self.get_font()}\n"
            f"font_size: {self.get_font_size()}\n"
            f"font_color: {self.get_font_color()}\n"
            f"bold: {self.is_bold()}\n"
            f"italic: {self.is_italic()}\n"
            f"vertical_alignment: {self.get_vertical_alignment()}\n"
            f"horizontal_alignment: {self.get_horizontal_alignment()}"
        )

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"{self.get_text()}"
