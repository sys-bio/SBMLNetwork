from .. sbgn_node_base import SBGNNodeBase
import math


class SBGNContainerNodeBase(SBGNNodeBase):

    def __init__(self, node_id, x, y, width, height, text="", text_x=math.nan, text_y=math.nan, text_width=math.nan,
                    text_height=math.nan,
                    font_size=14, text_vertical_alignment="middle", text_horizontal_alignment="middle", sub_elements=None):
            super(SBGNContainerNodeBase, self).__init__(node_id, x, y, width, height, text, text_x, text_y, text_width,
                                                        text_height,
                                                        font_size, text_vertical_alignment, text_horizontal_alignment,
                                                        sub_elements)

    @staticmethod
    def get_super_type():
        return "container node"

