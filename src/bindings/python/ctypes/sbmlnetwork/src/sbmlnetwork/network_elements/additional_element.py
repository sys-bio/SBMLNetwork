from .network_element_base import NetworkElementBase


class AdditionalElement(NetworkElementBase):

    def __init__(self, libsbmletwork, element_id):
        super().__init__(libsbmletwork, element_id, 0)

    # ToDo: fix the issue with adding label to it

    def get_info(self):
        result = []
        result.append(f"id: {self.get_id()}")
        result.append(f"position: {self.get_position()}")
        result.append(f"size: {self.get_size()}")

        shapes = self.get_shapes_list()
        result.append("Shapes:")
        for shape in shapes:
            result.append("\n".join(["    " + line for line in str(shape).split("\n")]))
            if shape != shapes[-1]:
                result.append("----")

        labels = self.get_labels_list()
        result.append("Labels:")
        for label in labels:
            result.append("\n".join(["    " + line for line in str(label).split("\n")]))
            if label != labels[-1]:
                result.append("----")

        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"AdditionalElement(id={self.element_id})"
