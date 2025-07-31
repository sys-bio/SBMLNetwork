from .sbgn_process_node_base import SBGNProcessNodeBase


class SBGNProcess(SBGNProcessNodeBase):

    def get_type(self):
        return "process"

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumGeometricShapes(parent_element.get_id()) - 1
        geometric_shape_id = self.get_id()
        if parent_element.get_id() == self.get_id() and geometric_shape_index > 0:
            geometric_shape_id += "_" + str(geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeId(parent_element.get_id(), geometric_shape_id,
                                               geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeX(parent_element.get_id(), self.get_relative_x(
            sbmlnetwork_object.libsbmlnetwork.getX(parent_element.get_id())),
                                              geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeY(parent_element.get_id(), self.get_relative_y(
            sbmlnetwork_object.libsbmlnetwork.getY(parent_element.get_id())),
                                              geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeWidth(parent_element.get_id(), self.get_relative_width(
            sbmlnetwork_object.libsbmlnetwork.getWidth(parent_element.get_id())), geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeHeight(parent_element.get_id(), self.get_relative_height(
            sbmlnetwork_object.libsbmlnetwork.getHeight(parent_element.get_id())), geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderRadiusX(parent_element.get_id(), 0.0,
                                                          geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderRadiusY(parent_element.get_id(), 0.0,
                                                          geometric_shape_index=geometric_shape_index)

        # set the style of the process node
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeFillColor(parent_element.get_id(), self.fill_color,
                                                          geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderColor(parent_element.get_id(), self.border_color,
                                                            geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderWidth(parent_element.get_id(), 2.0,
                                                            geometric_shape_index=geometric_shape_index)



