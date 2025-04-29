from .sbgn_1d_element_base import SBGN1DElementBase


class SBGN2DElementBase(SBGN1DElementBase):

    def __init__(self, node_id, x, y, width, height, sub_elements=None):
        super(SBGN2DElementBase, self).__init__(node_id, x, y, sub_elements)
        self.width = width
        self.height = height

    def get_width(self):
        return self.width

    def set_width(self, width):
        self.width = width

    def get_height(self):
        return self.height

    def set_height(self, height):
        self.height = height

    def get_relative_width(self, absolute_width=0):
        if self.width == 0:
            return absolute_width

        return self.width

    def get_relative_height(self, absolute_height=0):
        if self.height == 0:
            return absolute_height

        return self.height

    def __str__(self):
        return super().__str__() + ", width: " + str(self.width) + ", height: " + str(self.height)