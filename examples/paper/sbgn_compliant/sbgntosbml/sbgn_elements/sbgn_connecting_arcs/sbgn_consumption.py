from .sbgn_connecting_arc_base import SBGNConnectingArcBase


class SBGNConsumption(SBGNConnectingArcBase):

    @staticmethod
    def get_type():
        return "consumption"

