from .shape_base import ShapeBase

class Curve(ShapeBase):

    def get_points(self):
        points = []
        if self.sub_element_index is None:
            for segment_index in range(self.libsbmlnetwork.getGeometricShapeNumSegments(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)):
                points.append((
                    self.libsbmlnetwork.getGeometricShapeSegmentX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index),
                    self.libsbmlnetwork.getGeometricShapeSegmentY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index)))
        else:
            for segment_index in range(self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeNumSegments(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, index=self.geometric_shape_index)):
                points.append((
                    self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, index=self.geometric_shape_index, segment_index=segment_index),
                    self.libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, index=self.geometric_shape_index, segment_index=segment_index)))

        return points

    def set_points(self, points: list[tuple[float, float]]):
        #ToDo: remove all geometric shapes segments
        # for segment_index in range(self.libsbmlnetwork.getGeometricShapeNumSegments(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index)):
        #     if self.libsbmlnetwork.removeGeometricShapeSegment(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index) != 0:
        #         return False

        if self.sub_element_index is None:
            for segment_index, point in enumerate(points):
                #ToDo add a geometric shapes segment
                if self.libsbmlnetwork.setGeometricShapeSegmentX(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index, x=point[0]) != 0 or \
                        self.libsbmlnetwork.setGeometricShapeSegmentY(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index, y=point[1]) != 0:
                    return False
        else:
            for segment_index, point in enumerate(points):
                #ToDo add a geometric shapes segment
                if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentX(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index, x=point[0]) != 0 or \
                        self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeSegmentY(reaction_id=self.element_id, reaction_glyph_index=self.graphical_object_index, species_reference_index=self.sub_element_index, geometric_shape_index=self.geometric_shape_index, segment_index=segment_index, y=point[1]) != 0:
                    return False

        return True

    def get_info(self):
        base_str = super().__str__()
        return (
                base_str + "\n" +
                f"points: {self.get_points()}"
        )

