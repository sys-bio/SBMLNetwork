from ...network_element_lists import *
from .curve_element_lists import *
from .shape_list import ShapeList


class ReactionCenterList(list):

    def __init__(self, reaction_center_list=None, libsbmlnetwork=None):
        super().__init__(reaction_center_list or [])
        self.libsbmlnetwork = libsbmlnetwork

    def get_reactions(self):
        reactions = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction_center in self:
            reactions.append(reaction_center.get_reaction())

        return reactions

    @property
    def reactions(self):
        return self.get_reactions()

    def switch_to_curves(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.switch_to_curve())

        return results

    def switch_to_shapes(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.switch_to_shapes())

        return results

    def are_curves(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.is_curve())

        return results

    def are_shapes(self):
        results = []
        for reaction_center in self:
            results.append(reaction_center.is_shapes())

        return results

    def get_curves(self):
        curve_list = CurveList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction_center in self:
            curve_list.append(reaction_center.get_curve())

        return curve_list

    @property
    def curves(self):
        return self.get_curves()

    def get_shapes_list(self):
        shapes_list = ShapeList()
        for reaction_center in self:
            shapes_list.append(reaction_center.get_shapes_list())

        return shapes_list

    def get_shapes(self):
        return self.get_shapes_list()

    @property
    def shapes(self):
        return self.get_shapes_list()

    def move(self, delta: tuple[float, float]):
        results = []
        for reaction_center in self:
            results.append(reaction_center.move_by(delta))

        return results

    def get_info(self):
        result = []
        for reaction_center in self:
            result.append(str(reaction_center))
        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        return f"ReactionCenterList({[repr(reaction_center) for reaction_center in self]})"
