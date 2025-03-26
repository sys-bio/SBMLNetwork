class LabelList(list):

    def __init__(self, label_list=None):
        super().__init__(label_list or [])

    def get_texts(self):
        texts = []
        for label in self:
            texts.append(label.get_text())

        return texts

    def set_texts(self, text: str):
        results = []
        for label in self:
            results.append(label.set_text(text))

        return results

    @property
    def texts(self):
        return self.get_texts()

    def get_positions(self):
        positions = []
        for label in self:
            positions.append(label.get_position())

        return positions

    def set_positions(self, position: tuple[float, float]):
        results = []
        for label in self:
            results.append(label.set_position(position))

        return results

    @property
    def positions(self):
        return self.get_positions()

    @positions.setter
    def positions(self, position: tuple[float, float]):
        self.set_positions(position)

    def get_sizes(self):
        sizes = []
        for label in self:
            sizes.append(label.get_size())

        return sizes

    def set_sizes(self, size: tuple[float, float]):
        results = []
        for label in self:
            results.append(label.set_size(size))

        return results

    @property
    def sizes(self):
        return self.get_sizes()

    @sizes.setter
    def sizes(self, size: tuple[float, float]):
        self.set_sizes(size)

    def align_to_top(self):
        results = []
        for label in self:
            results.append(label.align_to_top())

        return results

    def align_to_vertical_center(self):
        results = []
        for label in self:
            results.append(label.align_to_vertical_center())

        return results

    def align_to_baseline(self):
        results = []
        for label in self:
            results.append(label.align_to_baseline())

        return results

    def align_to_bottom(self):
        results = []
        for label in self:
            results.append(label.align_to_bottom())

        return results

    def align_to_left(self):
        results = []
        for label in self:
            results.append(label.align_to_left())

        return results

    def align_to_horizontal_center(self):
        results = []
        for label in self:
            results.append(label.align_to_horizontal_center())

        return results

    def align_to_right(self):
        results = []
        for label in self:
            results.append(label.align_to_right())

        return results

    def get_font_colors(self):
        font_colors = []
        for label in self:
            font_colors.append(label.get_font_color())

        return font_colors

    def set_font_colors(self, font_color: str):
        results = []
        for label in self:
            results.append(label.set_font_color(font_color))

        return results

    @property
    def font_colors(self):
        return self.get_font_colors()

    def get_fonts(self):
        fonts = []
        for label in self:
            fonts.append(label.get_font())

        return fonts

    def set_fonts(self, font: str):
        results = []
        for label in self:
            results.append(label.set_font(font))

        return results

    @property
    def fonts(self):
        return self.get_fonts()

    @fonts.setter
    def fonts(self, font: str):
        self.set_fonts(font)

    def get_font_sizes(self):
        font_sizes = []
        for label in self:
            font_sizes.append(label.get_font_size())

        return font_sizes

    def set_font_sizes(self, font_size: float):
        results = []
        for label in self:
            results.append(label.set_font_size(font_size))

        return results

    @property
    def font_sizes(self):
        return self.get_font_sizes()

    @font_sizes.setter
    def font_sizes(self, font_size: float):
        self.set_font_sizes(font_size)

    def set_bold(self, bold: bool):
        results = []
        for label in self:
            results.append(label.set_bold(bold))

        return results

    def are_bold(self):
        is_bold = []
        for label in self:
            is_bold.append(label.is_bold())

        return is_bold

    def set_italic(self, italic: bool):
        results = []
        for label in self:
            results.append(label.set_italic(italic))

        return results

    def are_italic(self):
        is_italic = []
        for label in self:
            is_italic.append(label.is_italic())

        return is_italic

    def move_to(self, position: tuple[float, float]):
        results = []
        for label in self:
            results.append(label.move_to(position))

        return results

    def move_by(self, offset: tuple[float, float]):
        results = []
        for label in self:
            results.append(label.move_by(offset))

        return results

    def get_info(self):
        result = []
        for label in self:
            result.append(str(label))
        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"LabelList({[repr(label) for label in self]})"
