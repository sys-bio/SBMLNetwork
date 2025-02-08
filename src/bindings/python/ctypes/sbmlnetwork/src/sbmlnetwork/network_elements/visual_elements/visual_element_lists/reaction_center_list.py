from ...network_element_lists import *
from .curve_element_lists import *
from .shape_list import ShapeList


class ReactionCenterList(list):

    def __init__(self, reaction_center_list=None, libsbmlnetwork=None):
        super().__init__(reaction_center_list or [])
        self.libsbmlnetwork = libsbmlnetwork

    def get_reaction(self):
        reactions = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction_center in self:
            reactions.append(reaction_center.get_reaction())

        return reactions

    def switch_to_curve(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.switch_to_curve())

        return results

    def switch_to_shapes(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.switch_to_shapes())

        return results

    def is_curve(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.is_curve())

        return results

    def is_shapes(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.is_shapes())

        return results

    def get_curve(self):
        curve_list = CurveList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction_center in self:
            curve_list.append(reaction_center.get_curve())

        return curve_list

    def get_shapes_list(self):
        shapes_list = ShapeList()
        for reaction_center in self:
            shapes_list.append(reaction_center.get_shapes_list())

        return shapes_list

    def move(self, delta: tuple[float, float]):
        results = []
        for reaction_center in self:
            results.append(reaction_center.move(delta))

        return results

    def __str__(self):
        result = []
        for reaction_center in self:
            result.append(str(reaction_center))
        return "\n".join(result)

    def __repr__(self):
        return f"ReactionCenterList({[repr(reaction_center) for reaction_center in self]})"
