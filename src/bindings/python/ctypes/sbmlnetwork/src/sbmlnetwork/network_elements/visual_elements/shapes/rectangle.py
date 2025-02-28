from .shape_base import ShapeBase

class Rectangle(ShapeBase):

    def get_relative_position(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index), \
                    self.libsbmlnetwork.getGeometricShapeY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index), \
                    self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index)

    def set_relative_position(self, relative_position: tuple[float, float]):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, x=relative_position[0]) == 0 and \
                    self.libsbmlnetwork.setGeometricShapeY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, y=relative_position[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeXPosition(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, x=relative_position[0]) == 0 and \
                    self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeYPosition(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, y=relative_position[1]) == 0:
                return True

        return False

    @property
    def relative_position(self):
        return self.get_relative_position()

    @relative_position.setter
    def relative_position(self, relative_position: tuple[float, float]):
        self.set_relative_position(relative_position)

    def get_size(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index), \
                    self.libsbmlnetwork.getGeometricShapeHeight(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return (self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index),
                    self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeHeight(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index))

    def set_size(self, size: tuple[float, float]):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, width=size[0]) == 0 and \
                    self.libsbmlnetwork.setGeometricShapeHeight(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, height=size[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, width=size[0]) == 0 and \
                    self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeHeight(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, height=size[1]) == 0:
                return True

        return False

    @property
    def size(self):
        return self.get_size()

    @size.setter
    def size(self, size: tuple[float, float]):
        self.set_size(size)

    def get_corner_radius(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeBorderRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index), \
                    self.libsbmlnetwork.getGeometricShapeBorderRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index), \
                    self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index)

    def set_corner_radius(self, corner_radius: tuple[float, float]):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeBorderRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, border_radius_x=corner_radius[0]) == 0 and \
                    self.libsbmlnetwork.setGeometricShapeBorderRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, border_radius_y=corner_radius[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, x=corner_radius[0]) == 0 and \
                    self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, y=corner_radius[1]) == 0:
                return True

        return False

    @property
    def corner_radius(self):
        return self.get_corner_radius()

    @corner_radius.setter
    def corner_radius(self, corner_radius: tuple[float, float]):
        self.set_corner_radius(corner_radius)

    def get_info(self):
        base_str = super().__str__()
        return (
                base_str + "\n" +
                f"relative_position: {self.get_relative_position()}\n"
                f"size: {self.get_size()} \n"
                f"corner_radius: {self.get_corner_radius()}"
        )
