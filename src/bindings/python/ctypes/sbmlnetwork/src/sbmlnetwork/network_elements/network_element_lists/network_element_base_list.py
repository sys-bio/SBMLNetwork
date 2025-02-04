from ..visual_elements import *
from ..visual_elements.visual_element_lists import *

class NetworkElementBaseList(list):

    def __init__(self, network_element_base_list=None, libsbmlnetwork=None):
        super().__init__(network_element_base_list or [])
        self.libsbmlnetwork = libsbmlnetwork

    def get_id(self):
        ids = []
        for element in self:
            ids.append(element.get_id())
            
        return ids

    def get_graphical_object_index(self):
        graphical_object_indices = []
        for element in self:
            graphical_object_indices.append(element.get_graphical_object_index())
            
        return graphical_object_indices

    def get_position(self):
        positions = []
        for element in self:
            positions.append(element.get_position())
            
        return positions

    def set_position(self, position: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.set_position(position))
            
        return results

    def get_size(self):
        sizes = []
        for element in self:
            sizes.append(element.get_size())
            
        return sizes

    def set_size(self, size: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.set_size(size))
            
        return results

    def move(self, delta: tuple[float, float]):
        results = []
        for element in self:
            results.append(element.move(delta))

        return results

    def add_label(self, text: str, relative_position: tuple[float, float] = (0.0, 0.0)):
        labels = LabelList()
        for element in self:
            labels.append(element.add_label(text, relative_position))
            
        return labels

    def remove_label(self, text: str):
        results = []
        for element in self:
            results.append(element.remove_label(text))
            
        return results

    def get_label(self):
        labels = LabelList()
        for element in self:
            labels.append(element.get_label())

        return labels

    def get_labels_list(self):
        labels = LabelList()
        for element in self:
            labels.extend(element.get_labels_list())

        return labels

    def add_shape(self, shape_type: str):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for element in self:
            shapes.append(element.add_shape(shape_type))

        return shapes

    def remove_shape(self, shape: ShapeBase):
        results = []
        for element in self:
            results.append(element.remove_shape(shape))

        return results

    def get_shape(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for element in self:
            shapes.append(element.get_shape())

        return shapes

    def set_shape(self, shape_type: str):
        results = []
        for element in self:
            results.append(element.set_shape(shape_type))

        return results

    def get_shapes_list(self):
        from ..visual_elements.visual_element_lists.shape_list import ShapeList

        shapes = ShapeList()
        for element in self:
            shapes.extend(element.get_shapes_list())

        return shapes

    def hide(self, apply_to_connected_elements=True):
        results = []
        for element in self:
            results.append(element.hide(apply_to_connected_elements))

        return results

    def show(self, apply_to_connected_elements=True):
        results = []
        for element in self:
            results.append(element.show(apply_to_connected_elements))

        return results

    def is_hidden(self):
        hidden_status = []
        for element in self:
            hidden_status.append(element.is_hidden())

        return hidden_status

    def add_meta_data(self, key: str, value: str):
        results = []
        for element in self:
            results.append(element.add_meta_data(key, value))

        return results

    def remove_meta_data(self, key: str):
        results = []
        for element in self:
            results.append(element.remove_meta_data(key))

        return results

    def get_meta_data(self, key: str):
        meta_data = []
        for element in self:
            meta_data.append(element.get_meta_data(key))

        return meta_data
