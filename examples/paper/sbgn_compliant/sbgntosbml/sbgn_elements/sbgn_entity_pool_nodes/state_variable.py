from .sbgn_entity_pool_node_base import SBGNEntityPoolNodeBase
import math


class SBGNStateVariable(SBGNEntityPoolNodeBase):

    def __init__(self, node_id, x, y, width, height, border_color=None, fill_color=None,
                 text="", text_x=math.nan, text_y=math.nan, text_width=math.nan, text_height=math.nan,
                 font_size=11, font_color=None, text_vertical_alignment="middle", text_horizontal_alignment="middle", sub_elements=None):
        super(SBGNStateVariable, self).__init__(node_id, x, y, width, height, border_color, fill_color,
                                                text, text_x, text_y, text_width, text_height,
                                                     font_size, font_color, text_vertical_alignment, text_horizontal_alignment,
                                                     sub_elements)

    def get_type(self):
        return "state variable"

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        sbmlnetwork_object.libsbmlnetwork.addGeometricShape(parent_element.get_id(), "ellipse")
        geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumGeometricShapes(parent_element.get_id()) - 1
        geometric_shape_id = self.get_id()
        if parent_element.get_id() == self.get_id() and geometric_shape_index > 0:
            geometric_shape_id += "_" + str(geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeId(parent_element.get_id(), geometric_shape_id,
                                               geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeCenterX(parent_element.get_id(), self.get_relative_x(
            sbmlnetwork_object.libsbmlnetwork.getX(parent_element.get_id())) + 0.5 * self.get_relative_width(
            sbmlnetwork_object.libsbmlnetwork.getWidth(parent_element.get_id())), geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeCenterY(parent_element.get_id(), self.get_relative_y(
            sbmlnetwork_object.libsbmlnetwork.getY(parent_element.get_id())) + 0.5 * self.get_relative_height(
            sbmlnetwork_object.libsbmlnetwork.getHeight(parent_element.get_id())), geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeRadiusX(parent_element.get_id(), 0.5 * self.get_relative_width(
            sbmlnetwork_object.libsbmlnetwork.getWidth(parent_element.get_id())), geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeRadiusY(parent_element.get_id(), 0.5 * self.get_relative_height(
            sbmlnetwork_object.libsbmlnetwork.getHeight(parent_element.get_id())), geometric_shape_index=geometric_shape_index)

        # border width
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderWidth(parent_element.get_id(), self.get_border_width(), geometric_shape_index=geometric_shape_index)

        # border color
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderColor(parent_element.get_id(), self.border_color, geometric_shape_index=geometric_shape_index)

        # fill color
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeFillColor(parent_element.get_id(), self.fill_color, geometric_shape_index=geometric_shape_index)