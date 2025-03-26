from ..shapes import *
from ..visual_element_lists import *

class ArrowHead:

    def __init__(self, libsbmlnetwork, reaction_id, reaction_glyph_index, species_reference_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.reaction_id = reaction_id
        self.reaction_glyph_index = reaction_glyph_index
        self.species_reference_index = species_reference_index

    def get_id(self):
        start_head_id = self.libsbmlnetwork.getSpeciesReferenceStartHead(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
        if start_head_id:
            return start_head_id
        end_head_id = self.libsbmlnetwork.getSpeciesReferenceEndHead(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)
        if end_head_id:
            return end_head_id

        return None

    def get_relative_position(self):
        return self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index), \
            self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)

    def set_relative_position(self, relative_position: tuple[float, float]):
        if self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxX(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, x=relative_position[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxY(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, y=relative_position[1]) == 0:
            return True

        return False

    @property
    def relative_position(self):
        return self.get_relative_position()

    @relative_position.setter
    def relative_position(self, relative_position: tuple[float, float]):
        self.set_relative_position(relative_position)

    def get_size(self):
        return self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxWidth(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index), \
            self.libsbmlnetwork.getSpeciesReferenceLineEndingBoundingBoxHeight(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)

    def set_size(self, size: tuple[float, float]):
        if self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxWidth(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, width=size[0]) == 0 and \
                self.libsbmlnetwork.setSpeciesReferenceLineEndingBoundingBoxHeight(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index, height=size[1]) == 0:
            return True

        return False

    @property
    def size(self):
        return self.get_size()

    @size.setter
    def size(self, size: tuple[float, float]):
        self.set_size(size)

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

    @property
    def shape(self):
        return self.get_shape()

    @shape.setter
    def shape(self, shape_type: str):
        self.set_shape(shape_type)

    def get_shapes_list(self):
        shapes = ShapeList()
        for geometric_shape_index in range(self.libsbmlnetwork.getNumSpeciesReferenceLineEndingGeometricShapes(reaction_id=self.reaction_id, reaction_glyph_index=self.reaction_glyph_index, species_reference_index=self.species_reference_index)):
            shape = create_shape(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, geometric_shape_index, self.species_reference_index)
            shapes.append(shape)

        return shapes

    def get_shapes(self):
        return self.get_shapes_list()

    @property
    def shapes(self):
        return self.get_shapes_list()

    def get_shape_type(self):
        return self.get_shapes_list().get_types()

    @property
    def shape_type(self):
        return self.get_shape_type()

    def get_border_color(self):
        return self.get_shapes_list().get_border_colors()

    def set_border_color(self, border_color: str):
        return self.get_shapes_list().set_border_colors(border_color)

    @property
    def border_color(self):
        return self.get_border_color()

    @border_color.setter
    def border_color(self, border_color: str):
        self.set_border_color(border_color)

    def get_border_thickness(self):
        return self.get_shapes_list().get_border_thicknesses()

    def set_border_thickness(self, thickness: float):
        return self.get_shapes_list().set_border_thicknesses(thickness)

    @property
    def border_thickness(self):
        return self.get_border_thickness()

    @border_thickness.setter
    def border_thickness(self, thickness: float):
        self.set_border_thickness(thickness)

    def get_fill_color(self):
        return self.get_shapes_list().get_fill_colors()

    def set_fill_color(self, fill_color: str or tuple or list):
        return self.get_shapes_list().set_fill_colors(fill_color)

    @property
    def fill_color(self):
        return self.get_fill_color()

    @fill_color.setter
    def fill_color(self, fill_color: str or tuple or list):
        self.set_fill_color(fill_color)

    def move_relative_position_to(self, relative_position: tuple[float, float]):
        return self.set_relative_position(relative_position)

    def move_relative_position_by(self, delta: tuple[float, float]):
        current_position = self.get_relative_position()
        new_position = (current_position[0] + delta[0], current_position[1] + delta[1])
        return self.set_relative_position(new_position)

    def get_info(self):
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

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return (f"ArrowHead(shapes={repr(self.get_shapes_list())},"
                f"reaction_id={self.reaction_id}, reaction_glyph_index={self.reaction_glyph_index},species_reference_index={self.species_reference_index})")
