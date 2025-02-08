from ..shapes import *
from ..visual_element_lists import *

class ArrowHead:

    def __init__(self, libsbmlnetwork, reaction_id, reaction_glyph_index, species_reference_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.reaction_id = reaction_id
        self.reaction_glyph_index = reaction_glyph_index
        self.species_reference_index = species_reference_index

    def get_relative_position(self):
        return self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index), \
                self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)

    def set_relative_position(self, relative_position: tuple[float, float]):
        if self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, x=relative_position[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, y=relative_position[1]) == 0:
            return True

        return False

    def get_size(self):
        return self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxWidth(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index), \
                self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxHeight(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)

    def set_size(self, size: tuple[float, float]):
        if self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxWidth(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, width=size[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxHeight(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, height=size[1]) == 0:
            return True

        return False

    def add_shape(self, shape_type: str):
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if shape_type not in valid_geometric_shapes:
            raise ValueError(f"Shape type must be one of {valid_geometric_shapes}")
        num_geometric_shapes = self.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
        self.libsbmlnetwork.addSpeciesReferenceLineEndingGeometricShape(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, geometric_shape_type=shape_type)
        if self.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) > num_geometric_shapes:
            geometric_shape_index = self.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) - 1
            return create_shape(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, geometric_shape_index, self.species_reference_index)

        return None

    def remove_shape(self, shape: ShapeBase):
        if self.libsbmlnetwork.removeSpeciesReferenceLineEndingGeometricShape(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, index=shape.get_geometric_shape_index()) == 0:
            return True

        return False

    def get_shape(self):
        if self.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index) > 0:
            return create_shape(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, 0, self.species_reference_index)

        return None

    def set_shape(self, shape_type: str):
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if shape_type not in valid_geometric_shapes:
            raise ValueError(f"Shape type must be one of {valid_geometric_shapes}")
        if self.libsbmlnetwork.setSpeciesReferenceLineEndingGeometricShapeType(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, geometric_shape_type=shape_type) == 0:
            return True

        return False

    def get_shapes_list(self):
        shapes = ShapeList()
        for geometric_shape_index in range(self.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)):
            shape = create_shape(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, geometric_shape_index, self.species_reference_index)
            shapes.append(shape)

        return shapes

    def __str__(self):
        result = []
        result.append(f"relative_position: {self.get_relative_position()}")
        result.append(f"size: {self.get_size()}")

        shapes = self.get_shapes_list()
        result.append("Shapes:")
        for shape in shapes:
            result.append("\n".join(["    " + line for line in str(shape).split("\n")]))
            if shape != shapes[-1]:
                result.append("----")

        return "\n".join(result)

    def __repr__(self):
        return f"ArrowHead(reaction_id={self.reaction_id}, reaction_glyph_index={self.reaction_glyph_index}, species_reference_index={self.species_reference_index})"
