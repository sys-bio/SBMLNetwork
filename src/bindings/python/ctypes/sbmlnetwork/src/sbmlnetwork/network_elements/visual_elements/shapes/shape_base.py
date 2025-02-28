class ShapeBase:

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index, geometric_shape_index, sub_element_index = None):
        self.libsbmlnetwork = libsbmlnetwork
        self.element_id = element_id
        self.graphical_object_index = graphical_object_index
        self.sub_element_index = sub_element_index
        self.geometric_shape_index = geometric_shape_index

    def get_element_id(self):
        return self.element_id

    def get_graphical_object_index(self):
        return self.graphical_object_index

    def get_geometric_shape_index(self):
        return self.geometric_shape_index

    def get_sub_element_index(self):
        return self.sub_element_index

    def get_type(self):
        shape = ""
        if self.sub_element_index is None:
            shape = self.libsbmlnetwork.getGeometricShapeType(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            shape = self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeType(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, index=self.geometric_shape_index)

        if shape == "rendercurve":
            return "curve"
        else:
            return shape

    @property
    def type(self):
        return self.get_type()

    def get_border_color(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeBorderColor(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingBorderColor(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index)

    def set_border_color(self, border_color: str):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeBorderColor(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, border_color=border_color) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingBorderColor(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, border_color=border_color) == 0:
                return True

        return False

    @property
    def border_color(self):
        return self.get_border_color()

    @border_color.setter
    def border_color(self, border_color: str):
        self.set_border_color(border_color)

    def get_border_thickness(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeBorderWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingBorderWidth(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index)

    def set_border_thickness(self, thickness: float):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeBorderWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, border_width=thickness) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingBorderWidth(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, border_width=thickness) == 0:
                return True

        return False

    @property
    def border_thickness(self):
        return self.get_border_thickness()

    @border_thickness.setter
    def border_thickness(self, thickness: float):
        self.set_border_thickness(thickness)

    def get_fill_color(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeFillColor(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingFillColor(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index)

    def set_fill_color(self, fill_color: str or tuple or list):
        if isinstance(fill_color, str):
            if self.sub_element_index is None:
                if self.libsbmlnetwork.setGeometricShapeFillColor(id=self.element_id,
                                                       graphical_object_index=self.graphical_object_index,
                                                       geometric_shape_index=self.geometric_shape_index,
                                                       fill_color=fill_color) == 0:
                    return True
            else:
                if self.libsbmlnetwork.setSpeciesReferenceLineEndingFillColor(reaction_id=self.element_id,
                                                                   reaction_glyph_index=self.graphical_object_index,
                                                                   species_reference_index=self.sub_element_index,
                                                                   fill_color=fill_color) == 0:
                    return True

        return False

    @property
    def fill_color(self):
        return self.get_fill_color()

    @fill_color.setter
    def fill_color(self, fill_color: str or tuple or list):
        self.set_fill_color(fill_color)

        # ToDo: Implement gradient fill color
        # elif isinstance(fill_color, (tuple, list)) and len(fill_color) == 3:
        #     stop_colors, stop_offsets, gradient_type = fill_color
        #     if isinstance(stop_colors, list) and isinstance(stop_offsets, list) and len(stop_colors) == len(
        #             stop_offsets):
        #         if self.sub_element_index is None:
        #             if self.libsbmlnetwork.setGeometricShapeFillColorAsGradient(id=self.element_id,
        #                                                graphical_object_index=self.graphical_object_index,
        #                                                geometric_shape_index=self.geometric_shape_index,
        #                                                stop_colors=stop_colors, stop_offsets=stop_offsets,
        #                                                gradient_type=gradient_type) == 0:
        #                 return True
        #         else:
        #             if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeFillColorAsGradient(reaction_id=self.element_id,
        #                                                reaction_glyph_index=self.graphical_object_index,
        #                                                species_reference_index=self.sub_element_index,
        #                                                stop_colors=stop_colors, stop_offsets=stop_offsets,
        #                                                gradient_type=gradient_type) == 0:
        #                 return True
        #
        # return False

    def get_info(self):
        return (
            f"type: {self.get_type()}\n"
            f"border_color: {self.get_border_color()}\n"
            f"border_thickness: {self.get_border_thickness()}\n"
            f"fill_color: {self.get_fill_color()}"
        )

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"{self.get_type()}"
