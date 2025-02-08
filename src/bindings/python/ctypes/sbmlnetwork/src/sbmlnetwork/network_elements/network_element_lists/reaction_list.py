from .network_element_base_list import NetworkElementBaseList


class ReactionList(NetworkElementBaseList):

    def get_reaction_id(self):
        reaction_ids = []
        for reaction in self:
            reaction_ids.append(reaction.get_reaction_id())

        return reaction_ids

    def get_compartment_id(self):
        compartment_ids = []
        for reaction in self:
            compartment_ids.append(reaction.get_compartment_id())

        return compartment_ids

    def get_curves_list(self, species=None):
        from ..visual_elements.visual_element_lists.curve_element_lists.curve_list import CurveList

        curves = CurveList()
        for reaction in self:
            curves.extend(reaction.get_curves_list(species))
        return curves

    def get_species_list(self):
        from .species_list import SpeciesList

        species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            species_list.extend(reaction.get_species_list())
        return species_list

    def get_species_ids(self):
        species_ids = []
        for reaction in self:
            species_ids.extend(reaction.get_species_ids())
        return species_ids

    def get_empty_species(self):
        from .species_list import SpeciesList

        empty_species = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            empty_species.append(reaction.get_empty_species())
        return empty_species

    def create_alias(self):
        aliases = ReactionList()
        for reaction in self:
            alias = reaction.create_alias()
            if alias:
                aliases.append(alias)
        return aliases

    def assign_species(self, species):
        from .species_list import SpeciesList

        successful_assignments = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            if reaction.assign_species(species):
                successful_assignments.extend(reaction)
        return successful_assignments

    def get_center(self):
        from ..visual_elements.visual_element_lists.reaction_center_list import ReactionCenterList

        reaction_center_list = ReactionCenterList(libsbmlnetwork=self.libsbmlnetwork)
        for reaction in self:
            reaction_center_list.append(reaction.get_center())

        return reaction_center_list

    def move(self, delta: tuple[float, float], move_connected_species: bool = False):
        results = []
        for reaction in self:
            results.append(reaction.move(delta, move_connected_species=move_connected_species))

        return results

    def __str__(self):
        result = []
        for reaction in self:
            result.append(str(reaction))
        return "\n".join(result)

    def __repr__(self):
        return f"ReactionList({[repr(reaction) for reaction in self]})"
