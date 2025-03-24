from .rectangle import Rectangle
from .ellipse import Ellipse
from .polygon import Polygon
from .curve import Curve

def create_shape(libsbmlnetwork, entity_id, graphical_object_index, geometric_shape_index, sub_element_index=None):
    if sub_element_index is None:
        shape_type = libsbmlnetwork.getGeometricShapeType(id=entity_id, graphical_object_index=graphical_object_index, geometric_shape_index=geometric_shape_index)
    else:
        shape_type = libsbmlnetwork.getSpeciesReferenceLineEndingGeometricShapeType(reaction_id=entity_id, reaction_glyph_index=graphical_object_index, species_reference_index=sub_element_index, index=geometric_shape_index)
    if shape_type == "rectangle":
        return Rectangle(libsbmlnetwork, entity_id, graphical_object_index, geometric_shape_index, sub_element_index)
    elif shape_type in ["ellipse", "circle"]:
        return Ellipse(libsbmlnetwork, entity_id, graphical_object_index, geometric_shape_index, sub_element_index)
    elif shape_type in ["polygon", "triangle", "diamond", "pentagon", "hexagon", "octagon"]:
        return Polygon(libsbmlnetwork, entity_id, graphical_object_index, geometric_shape_index, sub_element_index)
    elif shape_type in ["curve", "rendercurve"]:
        return Curve(libsbmlnetwork, entity_id, graphical_object_index, geometric_shape_index, sub_element_index)
