from ..sbgn_process_nodes.sbgn_port_base import SBGNPortBase

class SBGNLogicPort(SBGNPortBase):

    def __init__(self, port_id, x, y, sub_elements=None):
        super(SBGNLogicPort, self).__init__(port_id, x, y, sub_elements)

    def get_type(self):
        return "logic port"

    def __str__(self):
        return super().__str__() + str(self.sub_elements)

