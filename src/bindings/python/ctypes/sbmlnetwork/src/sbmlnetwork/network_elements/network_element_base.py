from .visual_elements import *


class NetworkElementBase:

    def __init__(self, libsbmlnetwork, element_id, graphical_object_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.element_id = element_id
        self.graphical_object_index = graphical_object_index
        self.meta_data = {}

    def get_id(self):
        return self.libsbmlnetwork.getId(id=self.element_id, graphical_object_index=self.graphical_object_index)

    def get_graphical_object_index(self):
        return self.graphical_object_index

    def get_position(self):
        return (self.libsbmlnetwork.getX(id=self.element_id, graphical_object_index=self.graphical_object_index),
                self.libsbmlnetwork.getY(id=self.element_id, graphical_object_index=self.graphical_object_index))

    def set_position(self, position: tuple[float, float]):
        if self.libsbmlnetwork.setX(id=self.element_id, graphical_object_index=self.graphical_object_index, x=position[0], update_curves=False) == 0 and \
                self.libsbmlnetwork.setY(id=self.element_id, graphical_object_index=self.graphical_object_index, y=position[1], update_curves=False) == 0:
            return True

        return False

    def get_size(self):
        return (self.libsbmlnetwork.getWidth(id=self.element_id, graphical_object_index=self.graphical_object_index),
                self.libsbmlnetwork.getHeight(id=self.element_id, graphical_object_index=self.graphical_object_index))

    def set_size(self, size: tuple[float, float]):
        if self.libsbmlnetwork.setWidth(id=self.element_id, graphical_object_index=self.graphical_object_index, width=size[0], update_curves=False) == 0 and \
                self.libsbmlnetwork.setHeight(id=self.element_id, graphical_object_index=self.graphical_object_index, height=size[1], update_curves=False) == 0:
            return True

        return False

    def add_label(self, text: str, relative_position: tuple[float, float] = (0.0, 0.0)):
        if self.libsbmlnetwork.addText(id=self.element_id, graphical_object_index=self.graphical_object_index, text=text) == 0:
            absolute_x = self.libsbmlnetwork.getX(id=self.element_id, graphical_object_index=self.graphical_object_index) + relative_position[0]
            absolute_y = self.libsbmlnetwork.getY(id=self.element_id, graphical_object_index=self.graphical_object_index) + relative_position[1]
            text_glyph_index = self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index) - 1
            if self.libsbmlnetwork.setTextX(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index, x=absolute_x) == 0 and \
                    self.libsbmlnetwork.setTextY(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index, y=absolute_y) == 0:
                return Label(self.libsbmlnetwork, self.element_id, self.graphical_object_index, text_glyph_index)

        return None

    def remove_label(self, text: str):
        removed = False
        for text_glyph_index in range(self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index)):
            if self.libsbmlnetwork.getText(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index) == text:
                if self.libsbmlnetwork.removeText(id=self.element_id, graphical_object_index=self.graphical_object_index, text_glyph_index=text_glyph_index) == 0:
                    removed = True

        return removed

    def get_label(self):
        if self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index) > 0:
            return Label(self.libsbmlnetwork, self.element_id, self.graphical_object_index, 0)

        return None

    def get_labels_list(self):
        labels = LabelList()
        for text_glyph_index in range(self.libsbmlnetwork.getNumTextGlyphs(id=self.element_id, graphical_object_index=self.graphical_object_index)):
            labels.append(Label(self.libsbmlnetwork, self.element_id, self.graphical_object_index, text_glyph_index))

        return labels

    def add_shape(self, shape_type: str):
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if shape_type not in valid_geometric_shapes:
            raise ValueError(f"Shape type must be one of {valid_geometric_shapes}")
        num_geometric_shapes = self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index)
        if num_geometric_shapes > 0:
            self.libsbmlnetwork.addGeometricShape(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_type=shape_type)
        else:
            self.libsbmlnetwork.setGeometricShapeType(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape=shape_type)
        if self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) > num_geometric_shapes:
            geometric_shape_index = self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) - 1
            return create_shape(self.libsbmlnetwork, self.element_id, self.graphical_object_index, geometric_shape_index)

        return None

    def remove_shape(self, shape: ShapeBase):
        if shape is not None:
            if self.libsbmlnetwork.removeGeometricShape(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape_index=shape.get_geometric_shape_index()) == 0:
                return True

        return False

    def get_shape(self):
        if self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index) > 0:
            return create_shape(self.libsbmlnetwork, self.element_id, self.graphical_object_index, 0)

        return None

    def set_shape(self, shape_type: str):
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if shape_type not in valid_geometric_shapes:
            raise ValueError(f"Shape type must be one of {valid_geometric_shapes}")
        if self.libsbmlnetwork.setGeometricShapeType(id=self.element_id, graphical_object_index=self.graphical_object_index, geometric_shape=shape_type) == 0:
            return True

        return False

    def get_shapes_list(self):
        shapes = ShapeList()
        for geometric_shape_index in range(
                self.libsbmlnetwork.getNumGeometricShapes(id=self.element_id, graphical_object_index=self.graphical_object_index)):
            shape = create_shape(self.libsbmlnetwork, self.element_id, self.graphical_object_index, geometric_shape_index)
            if shape is not None:
                shapes.append(shape)

        return shapes

    def get_shapes_options(self):
        return self.libsbmlnetwork.getListOfGeometricShapes()

    def hide(self, apply_to_connected_elements=True):
        if self.libsbmlnetwork.makeInvisible(id=self.element_id, graphical_object_index=self.graphical_object_index, apply_to_connected_elements=apply_to_connected_elements) == 0:
            return True

        return False

    def show(self, apply_to_connected_elements=True):
        if self.libsbmlnetwork.makeVisible(id=self.element_id, graphical_object_index=self.graphical_object_index, apply_to_connected_elements=apply_to_connected_elements) == 0:
            return True

        return False

    def is_hidden(self):
        if self.libsbmlnetwork.isVisible(id=self.element_id, graphical_object_index=self.graphical_object_index) == 0:
            return True

        return False

    def move(self, delta: tuple[float, float]):
        current_position = self.get_position()
        new_position = (current_position[0] + delta[0], current_position[1] + delta[1])
        return self.set_position(new_position)

    def add_meta_data(self, key: str, value: str):
        self.meta_data[key] = value

    def remove_meta_data(self, key: str):
        if key in self.meta_data:
            del self.meta_data[key]

    def get_meta_data(self, key: str):
        return self.meta_data.get(key, None)

    def get_meta_data_keys(self):
        return self.meta_data.keys()

    def get_meta_data_values(self):
        return self.meta_data.values()
