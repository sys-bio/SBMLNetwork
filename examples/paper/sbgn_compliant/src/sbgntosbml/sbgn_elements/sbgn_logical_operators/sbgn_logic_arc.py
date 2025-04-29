from ..sbgn_connecting_arcs.sbgn_connecting_arc_base import SBGNConnectingArcBase
from ..utils import find_element, find_parent_element


class SBGNLogicArc(SBGNConnectingArcBase):

    def __init__(self, element_id, source_id, target_id, start_x, start_y, end_x, end_y, intermediate_points=None, sub_elements=None):
        super(SBGNLogicArc, self).__init__(element_id, source_id, target_id, start_x, start_y, end_x, end_y, intermediate_points, sub_elements)

    @staticmethod
    def get_type():
        return "logic arc"

