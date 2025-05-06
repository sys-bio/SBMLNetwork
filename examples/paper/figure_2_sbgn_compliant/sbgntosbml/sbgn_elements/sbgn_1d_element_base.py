from .sbgn_element_base import SBGNElementBase


class SBGN1DElementBase(SBGNElementBase):

    def __init__(self, node_id, x, y, sub_elements=None):
        super(SBGN1DElementBase, self).__init__(node_id, sub_elements)
        self.x = x
        self.y = y

    def get_x(self):
        return self.x

    def set_x(self, x):
        self.x = x

    def get_y(self):
        return self.y

    def set_y(self, y):
        self.y = y

    def get_relative_x(self, absolute_x=0):
        return self.x - absolute_x

    def get_relative_y(self, absolute_y=0):
        return self.y - absolute_y

    def __str__(self):
        return super().__str__() + ", x: " + str(self.x) + ", y: " + str(self.y)