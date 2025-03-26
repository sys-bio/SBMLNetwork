from .shape_base import ShapeBase

class Ellipse(ShapeBase):

    def get_relative_center(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeCenterX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index), \
                self.libsbmlnetwork.getGeometricShapeCenterY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeCenterX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index), \
                self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeCenterY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index)

    def set_relative_center(self, center: tuple[float, float]):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeCenterX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, center_x=center[0]) == 0 and \
                    self.libsbmlnetwork.setGeometricShapeCenterY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, center_y=center[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeCenterX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, center_x=center[0]) == 0 and \
                    self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeCenterY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, center_y=center[1]) == 0:
                return True

        return False

    def get_radii(self):
        if self.sub_element_index is None:
            return self.libsbmlnetwork.getGeometricShapeRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index), \
                self.libsbmlnetwork.getGeometricShapeRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)
        else:
            return self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index), \
                self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index)

    def set_radii(self, radii: tuple[float, float]):
        if self.sub_element_index is None:
            if self.libsbmlnetwork.setGeometricShapeRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, radius_x=radii[0]) == 0 and \
                    self.libsbmlnetwork.setGeometricShapeRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, radius_y=radii[1]) == 0:
                return True
        else:
            if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeRadiusX(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, radius_x=radii[0]) == 0 and \
                    self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeRadiusY(id=self.element_id, graphical_object_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, radius_y=radii[1]) == 0:
                return True

        return False

    def get_info(self):
        base_str = super().__str__()
        return (
                base_str + "\n" +
                f"relative_center: {self.get_relative_center()}\n"
                f"radii: {self.get_radii()}"
        )
