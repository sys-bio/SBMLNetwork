from .sbgn_port_base import SBGNPortBase

class SBGNPort(SBGNPortBase):

    def __init__(self, port_id, x, y, border_color=None, sub_elements=None):
        super(SBGNPortBase, self).__init__(port_id, x, y, border_color, sub_elements)

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        sbmlnetwork_object.libsbmlnetwork.addGeometricShape(parent_element.get_id(), "rendercurve")
        geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumGeometricShapes(parent_element.get_id()) - 1
        geometric_shape_id = self.get_id()
        if parent_element.get_id() == self.get_id() and geometric_shape_index > 0:
            geometric_shape_id += "_" + str(geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeId(parent_element.get_id(), geometric_shape_id,
                                               geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.getGeometricShapeId(parent_element.get_id(), geometric_shape_index)
        relative_start_point_x, relative_start_point_y = self.get_relative_start_point(sbmlnetwork_object, parent_element)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderColor(parent_element.get_id(), border_color=self.border_color,
                                                           geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderWidth(parent_element.get_id(), border_width=2.0,
                                                            geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(), relative_start_point_x, segment_index=0, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(), relative_start_point_y, segment_index=0, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     self.get_relative_x(sbmlnetwork_object.libsbmlnetwork.getX(parent_element.get_id())),
                                                     segment_index=1, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                        self.get_relative_y(sbmlnetwork_object.libsbmlnetwork.getY(parent_element.get_id())),
                                                        segment_index=1, geometric_shape_index=geometric_shape_index)

        # set the style of the process node
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderColor(parent_element.get_id(), self.border_color,
                                                           geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderWidth(parent_element.get_id(), 2.0,
                                                           geometric_shape_index=geometric_shape_index)


