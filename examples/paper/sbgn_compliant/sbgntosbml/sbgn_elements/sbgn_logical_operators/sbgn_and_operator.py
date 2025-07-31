from .sbgn_logical_operator_base import SBGNLogicalOperatorBase


class SBGNAndOperator(SBGNLogicalOperatorBase):

    def __init__(self, node_id, x, y, width, height, border_color=None, fill_color=None, sub_elements=None, sbgn_elements=None):
        super(SBGNAndOperator, self).__init__(node_id, x, y, width, height, border_color, fill_color, sub_elements, sbgn_elements)

    @staticmethod
    def get_type():
        return "and operator"

    def add_geometric_shape(self, sbmlnetwork_object, parent=None):
        super(SBGNAndOperator, self).add_geometric_shape(sbmlnetwork_object)
        sbmlnetwork_object.libsbmlnetwork.addText(self.get_id(), "AND")
        self.set_text_style(sbmlnetwork_object)