class LabelList(list):

    def __init__(self, label_list=None):
        super().__init__(label_list or [])

    def get_text(self):
        texts = []
        for label in self:
            texts.append(label.get_text())

        return texts

    def set_text(self, text: str):
        results = []
        for label in self:
            results.append(label.set_text(text))

        return results

    def get_position(self):
        positions = []
        for label in self:
            positions.append(label.get_position())

        return positions

    def set_position(self, position: tuple[float, float]):
        results = []
        for label in self:
            results.append(label.set_position(position))

        return results

    def get_size(self):
        sizes = []
        for label in self:
            sizes.append(label.get_size())

        return sizes

    def set_size(self, size: tuple[float, float]):
        results = []
        for label in self:
            results.append(label.set_size(size))

        return results

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

    def get_font_color(self):
        font_colors = []
        for label in self:
            font_colors.append(label.get_font_color())

        return font_colors

    def set_font_color(self, font_color: str):
        results = []
        for label in self:
            results.append(label.set_font_color(font_color))

        return results

    def get_font(self):
        fonts = []
        for label in self:
            fonts.append(label.get_font())

        return fonts

    def set_font(self, font: str):
        results = []
        for label in self:
            results.append(label.set_font(font))

        return results

    def get_font_size(self):
        font_sizes = []
        for label in self:
            font_sizes.append(label.get_font_size())

        return font_sizes

    def set_font_size(self, font_size: float):
        results = []
        for label in self:
            results.append(label.set_font_size(font_size))

        return results

    def set_bold(self, bold: bool):
        results = []
        for label in self:
            results.append(label.set_bold(bold))

        return results

    def is_bold(self):
        is_bold = []
        for label in self:
            is_bold.append(label.is_bold())

        return is_bold

    def set_italic(self, italic: bool):
        results = []
        for label in self:
            results.append(label.set_italic(italic))

        return results

    def is_italic(self):
        is_italic = []
        for label in self:
            is_italic.append(label.is_italic())

        return is_italic

    def __str__(self):
        result = []
        for label in self:
            result.append(str(label))
        return "\n".join(result)

    def __repr__(self):
        return f"LabelList({[repr(label) for label in self]})"
