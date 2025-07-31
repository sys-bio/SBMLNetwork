from .sbgn_entity_pool_node_base import SBGNEntityPoolNodeBase


class SBGNComplex(SBGNEntityPoolNodeBase):

    def get_type(self):
        return "complex"

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        sbmlnetwork_object.libsbmlnetwork.addGeometricShape(parent_element.get_id(), "octagon")
        geometric_shape_index = sbmlnetwork_object.libsbmlnetwork.getNumGeometricShapes(parent_element.get_id()) - 1
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeId(parent_element.get_id(), self.get_id(),
                                               geometric_shape_index=geometric_shape_index)
        horizontal_edge_ratio = 0.05
        vertical_edge_ratio = 0.05
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     horizontal_edge_ratio * sbmlnetwork_object.libsbmlnetwork.getWidth(
                                                         parent_element.get_id()), segment_index=0,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(), 0.0, segment_index=0,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     (1 - horizontal_edge_ratio) * sbmlnetwork_object.libsbmlnetwork.getWidth(
                                                         parent_element.get_id()), segment_index=1,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(), 0.0, segment_index=1,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     sbmlnetwork_object.libsbmlnetwork.getWidth(parent_element.get_id()),
                                                     segment_index=2, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                     vertical_edge_ratio * sbmlnetwork_object.libsbmlnetwork.getHeight(
                                                         parent_element.get_id()), segment_index=2,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     sbmlnetwork_object.libsbmlnetwork.getWidth(parent_element.get_id()),
                                                     segment_index=3, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                     (1 - vertical_edge_ratio) * sbmlnetwork_object.libsbmlnetwork.getHeight(
                                                         parent_element.get_id()), segment_index=3,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     (1 - horizontal_edge_ratio) * sbmlnetwork_object.libsbmlnetwork.getWidth(
                                                         parent_element.get_id()), segment_index=4,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                     sbmlnetwork_object.libsbmlnetwork.getHeight(parent_element.get_id()),
                                                     segment_index=4, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(),
                                                     horizontal_edge_ratio * sbmlnetwork_object.libsbmlnetwork.getWidth(
                                                         parent_element.get_id()), segment_index=5,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                     sbmlnetwork_object.libsbmlnetwork.getHeight(parent_element.get_id()),
                                                     segment_index=5, geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(), 0.0, segment_index=6,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                     (1 - vertical_edge_ratio) * sbmlnetwork_object.libsbmlnetwork.getHeight(
                                                         parent_element.get_id()), segment_index=6,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentX(parent_element.get_id(), 0.0, segment_index=7,
                                                     geometric_shape_index=geometric_shape_index)
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeSegmentY(parent_element.get_id(),
                                                     vertical_edge_ratio * sbmlnetwork_object.libsbmlnetwork.getHeight(
                                                         parent_element.get_id()), segment_index=7,
                                                     geometric_shape_index=geometric_shape_index)

        # border width
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderWidth(parent_element.get_id(), self.get_border_width(), geometric_shape_index=geometric_shape_index)

        # border color
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeBorderColor(parent_element.get_id(), self.border_color, geometric_shape_index=geometric_shape_index)

        # fill color
        sbmlnetwork_object.libsbmlnetwork.setGeometricShapeFillColor(parent_element.get_id(), self.fill_color, geometric_shape_index=geometric_shape_index)



