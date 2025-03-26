from .network_element_base_list import NetworkElementBaseList
from .species_list import SpeciesList
from .reaction_list import ReactionList


class CompartmentList(NetworkElementBaseList):

    def get_compartment_ids(self):
        compartment_ids = []
        for compartment in self:
            compartment_ids.append(compartment.get_compartment_id())

        return compartment_ids

    @property
    def compartment_ids(self):
        return self.get_compartment_ids()

    def get_species_list(self):
        species_list = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        for compartment in self:
            species_list.extend(compartment.get_species_list())
        return species_list

    def get_species(self):
        return self.get_species_list()

    @property
    def species(self):
        return self.get_species()

    def get_reactions_list(self):
        reactions_list = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        for compartment in self:
            reactions_list.extend(compartment.get_reactions_list())
        return reactions_list

    def get_reactions(self):
        return self.get_reactions_list()

    @property
    def reactions(self):
        return self.get_reactions()

    def __str__(self):
        result = []
        for compartment in self:
            result.append(str(compartment))
        return "\n".join(result)

    def __repr__(self):
        return f"CompartmentList({[repr(compartment) for compartment in self]})"
