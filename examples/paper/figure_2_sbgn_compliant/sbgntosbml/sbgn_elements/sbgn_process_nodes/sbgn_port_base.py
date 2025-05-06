from ..sbgn_1d_element_base import SBGN1DElementBase
import math


class SBGNPortBase(SBGN1DElementBase):

    def __init__(self, port_id, x, y, sub_elements=None):
        super(SBGNPortBase, self).__init__(port_id, x, y, sub_elements)

    def get_type(self):
        return "port"

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        if parent_element is None:
            parent_element = self
        self.add_geometric_shape(sbmlnetwork_object, parent_element)
        self.load_sbml_info_with_sub_elements(sbmlnetwork_object, parent_element)

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        pass

    def get_relative_start_point(self, sbmlnetwork_object, parent_element):
        closest_point_x, closest_point_y = self.closest_point_on_bounding_box(self.get_x(), self.get_y(),
                                                           sbmlnetwork_object.libsbmlnetwork.getX(parent_element.get_id()),
                                                           sbmlnetwork_object.libsbmlnetwork.getY(parent_element.get_id()),
                                                           sbmlnetwork_object.libsbmlnetwork.getWidth(parent_element.get_id()),
                                                           sbmlnetwork_object.libsbmlnetwork.getHeight(parent_element.get_id()))
        return closest_point_x - sbmlnetwork_object.libsbmlnetwork.getX(parent_element.get_id()), closest_point_y - sbmlnetwork_object.libsbmlnetwork.getY(parent_element.get_id())


    def closest_point_on_bounding_box(self, x, y, bb_x, bb_y, bb_width, bb_height):
        top_left = (bb_x, bb_y)
        top_right = (bb_x + bb_width, bb_y)
        bottom_left = (bb_x, bb_y + bb_height)
        bottom_right = (bb_x + bb_width, bb_y + bb_height)

        edges = [
            (top_left, top_right),  # Top edge
            (top_right, bottom_right),  # Right edge
            (bottom_right, bottom_left),  # Bottom edge
            (bottom_left, top_left)  # Left edge
        ]

        min_closest_x, min_closest_y = None, None
        min_distance = float('inf')

        for (x1, y1), (x2, y2) in edges:
            closest_x, closest_y = self.closest_point_on_line(x1, y1, x2, y2, x, y)
            distance = self.point_to_point_distance(x, y, closest_x, closest_y)

            if distance < min_distance:
                min_distance = distance
                min_closest_x = closest_x
                min_closest_y = closest_y

        return min_closest_x, min_closest_y

    @staticmethod
    def closest_point_on_line(x1, y1, x2, y2, px, py):
        if x1 == x2:
            closest_x = x1
            closest_y = max(min(py, max(y1, y2)), min(y1, y2))
        elif y1 == y2:
            closest_x = max(min(px, max(x1, x2)), min(x1, x2))
            closest_y = y1
        else:
            t = ((px - x1) * (x2 - x1) + (py - y1) * (y2 - y1)) / ((x2 - x1) ** 2 + (y2 - y1) ** 2)
            t = max(0, min(1, t))
            closest_x = x1 + t * (x2 - x1)
            closest_y = y1 + t * (y2 - y1)

        return closest_x, closest_y

    @staticmethod
    def point_to_point_distance(x1, y1, x2, y2):
            return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

    def __str__(self):
        return super().__str__() + str(self.sub_elements)

