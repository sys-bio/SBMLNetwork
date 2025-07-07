from ..sbgn_2d_element_base import SBGN2DElementBase


class SBGNProcessNodeBase(SBGN2DElementBase):

    def __init__(self, node_id, x, y, width, height, border_color=None, fill_color=None, sub_elements=None):
            super(SBGNProcessNodeBase, self).__init__(node_id, x, y, width, height, border_color, fill_color, sub_elements)

    @staticmethod
    def get_super_type():
        return "process node"

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        if parent_element is None:
            parent_element = self
        self.initialize_sbml_info(sbmlnetwork_object, parent_element)
        self.add_geometric_shape(sbmlnetwork_object, parent_element)
        self.load_sbml_info_with_sub_elements(sbmlnetwork_object, parent_element)

    def initialize_sbml_info(self, sbmlnetwork_object, parent_element):
        if parent_element.get_id() == self.get_id():
            sbmlnetwork_object.libsbmlnetwork.setGeometricShapeType(parent_element.get_id(), "rectangle")
            sbmlnetwork_object.libsbmlnetwork.setX(parent_element.get_id(), self.get_x(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setY(parent_element.get_id(), self.get_y(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setWidth(parent_element.get_id(), self.get_width(), update_curves=False)
            sbmlnetwork_object.libsbmlnetwork.setHeight(parent_element.get_id(), self.get_height(), update_curves=False)

    def __str__(self):
        return super().__str__() + ", sub_elements: " + str(self.sub_elements)

