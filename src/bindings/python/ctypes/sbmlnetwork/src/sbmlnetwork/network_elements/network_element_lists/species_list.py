from .network_element_base_list import NetworkElementBaseList
from .reaction_list import ReactionList

class SpeciesList(NetworkElementBaseList):

    def get_species_id(self):
        species_ids = []
        for species in self:
            species_ids.append(species.get_species_id())

        return species_ids

    def get_compartment_id(self):
        compartment_ids = []
        for species in self:
            compartment_ids.append(species.get_compartment_id())

        return compartment_ids

    def get_reactions_list(self):
        reactions = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for species in self:
            reactions.extend(species.get_reactions_list())
        return reactions

    def get_reaction_ids(self):
        reaction_ids = []
        for species in self:
            reaction_ids.append(species.get_reaction_ids())

        return reaction_ids

    def get_connected_curves(self):
        from ..visual_elements.visual_element_lists.curve_element_lists.curve_list import CurveList

        connected_curves = CurveList()
        for species in self:
            connected_curves.extend(species.get_connected_curves())

        return connected_curves

    def get_role(self, reaction):
        roles = []
        for species in self:
            roles.append(species.get_role(reaction))

        return roles

    def create_alias(self, reaction):
        aliases = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for species in self:
            aliases.append(species.create_alias(reaction))

        return aliases

    def align_to_top(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "top") == 0:
            return True

        return False

    def align_to_bottom(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "bottom") == 0:
            return True

        return False

    def align_to_vertical_center(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "vCenter") == 0:
            return True

        return False

    def align_to_left(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "left") == 0:
            return True

        return False

    def align_to_right(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "right") == 0:
            return True

        return False

    def align_to_horizontal_center(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "hCenter") == 0:
            return True

        return False

    def align_to_circle(self):
        species_info = []
        for species in self:
            species_info.append([species.get_species_id(), species.get_graphical_object_index()])
        if self.libsbmlnetwork.align(species_info, "circular") == 0:
            return True

        return False

    # Todo: Implement distribute method
    # ToDo: Implement get_distribute_options method

    def move(self, position: tuple[float, float], move_connected_curves: bool = False):
        results = []
        for species in self:
            results.append(species.move(position, move_connected_curves))

        return results

    def __str__(self):
        result = []
        for species in self:
            result.append(str(species))
        return "\n".join(result)

    def __repr__(self):
        return f"SpeciesList({[repr(species) for species in self]})"
