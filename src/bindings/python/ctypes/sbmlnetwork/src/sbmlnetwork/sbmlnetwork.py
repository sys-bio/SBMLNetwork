import libsbmlnetwork
import networkinfotranslator
from IPython.display import display
from .settings import Settings
from .network_elements import *
from typing import Union


class SBMLNetwork():

    def __init__(self):
        self.libsbmlnetwork = libsbmlnetwork.LibSBMLNetwork()
        self.settings = Settings(self.libsbmlnetwork)

    def load(self, sbml: str):
        self.libsbmlnetwork.load(sbml)
        self.populate_settings()
        if self.libsbmlnetwork.getNumLayouts() == 0:
            self.auto_layout()
        if self.libsbmlnetwork.getNumGlobalRenderInformation() == 0 and self.libsbmlnetwork.getNumLocalRenderInformation() == 0:
            self.auto_style()

        return self

    def save(self, file_name: str = None):
        return self.libsbmlnetwork.save(file_name)

    def draw(self, file_name: str = None):
        """
        Draws the network of the SBML model. Saves the figure to the file_directory if specified, otherwise displays the figure.

        :param file_directory:
        :param file_name:
        """
        if file_name:
            networkinfotranslator.import_sbml_export_figure(self.libsbmlnetwork, file_name,
                                                            self.settings.compartment_labels,
                                                            self.settings.species_labels,
                                                            self.settings.reaction_labels)
        else:
            display(networkinfotranslator.import_sbml_export_pil_image(self.libsbmlnetwork,
                                                                       self.settings.compartment_labels,
                                                                       self.settings.species_labels,
                                                                       self.settings.reaction_labels))

    def get_size(self):
        return self.libsbmlnetwork.getCanvasWidth(), self.libsbmlnetwork.getCanvasHeight()

    def set_size(self, size: tuple[int, int]):
        if self.libsbmlnetwork.setCanvasWidth(size[0]) == 0 and self.libsbmlnetwork.setCanvasHeight(size[1]) == 0:
            return True

        return False

    def get_compartment(self, compartment_id: str = None):
        if compartment_id is None and self.libsbmlnetwork.getNumAllCompartmentGlyphs() == 1:
            compartment_id = self.libsbmlnetwork.getListOfCompartmentIds()[0]
        if self.libsbmlnetwork.getNumCompartmentGlyphs(compartment_id=compartment_id) > 0:
            return Compartment(self.libsbmlnetwork, compartment_id, 0)

        return None

    def get_compartments_list(self, compartment_ids = None):
        compartments = CompartmentList(libsbmlnetwork=self.libsbmlnetwork)
        if compartment_ids is None:
            compartment_ids = self.libsbmlnetwork.getListOfCompartmentIds()
        elif isinstance(compartment_ids, str):
            compartment_ids = [compartment_ids]
        elif not isinstance(compartment_ids, list):
            raise ValueError("Compartment ids must be a string or a list of strings")
        for compartment_id in compartment_ids:
            for graphical_object_index in range(self.libsbmlnetwork.getNumCompartmentGlyphs(compartment_id=compartment_id)):
                compartments.append(Compartment(self.libsbmlnetwork, compartment_id, graphical_object_index))

        return compartments

    def get_compartment_ids(self):
        return self.libsbmlnetwork.getListOfCompartmentIds()

    def get_species(self, species_id: str):
        if self.libsbmlnetwork.getNumSpeciesGlyphs(species_id=species_id) > 0:
            return Species(self.libsbmlnetwork, species_id, 0)

        return None

    def get_species_list(self, species_ids = None):
        species = SpeciesList(libsbmlnetwork=self.libsbmlnetwork)
        if species_ids is None:
            species_ids = self.libsbmlnetwork.getListOfSpeciesIds()
        elif isinstance(species_ids, str):
            species_ids = [species_ids]
        elif not isinstance(species_ids, list):
            raise ValueError("Species ids must be a string or a list of strings")
        for species_id in species_ids:
            for graphical_object_index in range(self.libsbmlnetwork.getNumSpeciesGlyphs(species_id=species_id)):
                species.append(Species(self.libsbmlnetwork, species_id, graphical_object_index))

        return species

    def get_species_ids(self):
        return self.libsbmlnetwork.getListOfSpeciesIds()

    def get_reaction(self, reaction_id: str):
        if self.libsbmlnetwork.getNumReactionGlyphs(reaction_id=reaction_id) > 0:
            return Reaction(self.libsbmlnetwork, reaction_id, 0)

        return None

    def get_reactions_list(self, reaction_ids = None):
        reactions = ReactionList(libsbmlnetwork=self.libsbmlnetwork)
        if reaction_ids is None:
            reaction_ids = self.libsbmlnetwork.getListOfReactionIds()
        elif isinstance(reaction_ids, str):
            reaction_ids = [reaction_ids]
        elif not isinstance(reaction_ids, list):
            raise ValueError("Reaction ids must be a string or a list of strings")
        for reaction_id in reaction_ids:
            for graphical_object_index in range(self.libsbmlnetwork.getNumReactionGlyphs(reaction_id=reaction_id)):
                reactions.append(Reaction(self.libsbmlnetwork, reaction_id, graphical_object_index))

        return reactions

    def get_reaction_ids(self):
        return self.libsbmlnetwork.getListOfReactionIds()

    def get_additional_elements(self):
        additional_elements = NetworkElementList(libsbmlnetwork=self.libsbmlnetwork)
        for graphical_object_index in range(self.libsbmlnetwork.getNumAllAdditionalGraphicalObjects()):
            additional_elements.append(AdditionalElement(self.libsbmlnetwork, self.libsbmlnetwork.getAdditionalGraphicalObjectId(graphical_object_index)))

        return additional_elements

    def add_additional_element(self, element_id: str, element_type: str = "rectangle", position: tuple[float, float] = (0, 0), size: tuple[float, float] = (100, 100)):
        if element_id is None:
            raise ValueError("Element id cannot be None")
        valid_geometric_shapes = self.libsbmlnetwork.getListOfGeometricShapes()
        if element_type not in valid_geometric_shapes:
            raise ValueError(f"Element type must be one of {valid_geometric_shapes}")
        if self.libsbmlnetwork.addAdditionalGraphicalObject(id=element_id) == 0:
            if self.libsbmlnetwork.setGeometricShapeType(id=element_id, geometric_shape=element_type) == 0:
                if self.libsbmlnetwork.setX(id=element_id, x=position[0]) == 0 and \
                        self.libsbmlnetwork.setY(id=element_id, y=position[1]) == 0 and \
                        self.libsbmlnetwork.setWidth(id=element_id, width=size[0]) == 0 and \
                        self.libsbmlnetwork.setHeight(id=element_id, height=size[1]) == 0:
                    return AdditionalElement(self.libsbmlnetwork, element_id)
                else:
                    graphical_object_index = self.libsbmlnetwork.getNumAllAdditionalGraphicalObjects() - 1
                    self.libsbmlnetwork.removeAdditionalGraphicalObject(additional_graphical_object_index=graphical_object_index)

        return None

    def remove_additional_element(self, element: Union[str, AdditionalElement]):
        element_id = None
        if isinstance(element, str):
            element_id = element
        elif isinstance(element, AdditionalElement):
            element_id = element.get_id()
        if element_id is None:
            raise ValueError("Element id cannot be None")
        for i in range(self.libsbmlnetwork.getNumAllAdditionalGraphicalObjects()):
            if self.libsbmlnetwork.getAdditionalGraphicalObjectId(i) == element_id:
                if self.libsbmlnetwork.removeAdditionalGraphicalObject(additional_graphical_object_index=i) == 0:
                    return True

        return False

    # Todo: Implement get color options method

    def add_color_bar(self):
        color_bar_id = "sbmlnetwork_color_bar"
        self.remove_additional_element(color_bar_id)
        if self.libsbmlnetwork.addAdditionalGraphicalObject(id=color_bar_id) == 0:
            return ColorBar(self.libsbmlnetwork, color_bar_id)

        return None

    def get_color_bar(self):
        for i in range(self.libsbmlnetwork.getNumAllAdditionalGraphicalObjects()):
            if self.libsbmlnetwork.getAdditionalGraphicalObjectId(i) == "sbmlnetwork_color_bar":
                return ColorBar(self.libsbmlnetwork, self.libsbmlnetwork.getAdditionalGraphicalObjectId(i))

        return None

    def remove_color_bar(self):
        color_bar = self.get_color_bar()
        if color_bar:
            color_bar.clear_color_bar_space()

        return self.remove_additional_element("sbmlnetwork_color_bar")


    def get_background_color(self):
        return self.libsbmlnetwork.getBackgroundColor()

    def set_background_color(self, color: str):
        if self.libsbmlnetwork.setBackgroundColor(color) == 0:
            return True

        return False

    # Todo: Implement get_colors_list method to return all valid colors
    # def get_colors_list(self):
    #     return self.libsbmlnetwork.getListOfColorIds()

    def get_style(self):
        return self.libsbmlnetwork.getStyle()

    def set_style(self, style_name: str):
        valid_styles = self.libsbmlnetwork.getListOfStyles()
        if style_name not in valid_styles:
            raise ValueError(f"Style name must be one of {valid_styles}")
        if self.libsbmlnetwork.setStyle(style_name) == 0:
            return True

        return False

    def get_styles_options(self):
        return self.libsbmlnetwork.getListOfStyles()

        # ToDo: Implement the following functions on the list of elements
        # def show_compartment_labels(self):
        #     if self.libsbmlnetwork.enableDisplayCompartmentsTextLabel(True) == 0:
        #         return True
        #
        #     return False
        #
        # def hide_compartment_labels(self):
        #     if self.libsbmlnetwork.enableDisplayCompartmentsTextLabel(False) == 0:
        #         return True
        #
        #     return False
        #
        # def show_species_labels(self):
        #     if self.libsbmlnetwork.enableDisplaySpeciesTextLabel(True) == 0:
        #         return True
        #
        #     return False
        #
        # def hide_species_labels(self):
        #     if self.libsbmlnetwork.enableDisplaySpeciesTextLabel(False) == 0:
        #         return True
        #
        #     return False
        #
        # #ToDo: Check if it works properly
        # def show_reaction_labels(self):
        #     if self.libsbmlnetwork.enableDisplayReactionsTextLabel(True) == 0:
        #         return True
        #
        #     return False
        #
        # def hide_reaction_labels(self):
        #     if self.libsbmlnetwork.enableDisplayReactionsTextLabel(False) == 0:
        #         return True
        #
        #     return False
        #
        # def show_id_as_label(self):
        #     if self.libsbmlnetwork.setUseNameAsTextLabel(False) == 0:
        #         return True
        #
        #     return False
        #
        # def show_name_as_label(self):
        #     if self.libsbmlnetwork.setUseNameAsTextLabel(True) == 0:
        #         return True
        #
        #     return False

    def auto_layout(self, max_num_connected_edges: int = 3, reset_fixed_position_elements: bool = False, fixed_position_nodes: list = []):
        self.libsbmlnetwork.autolayout(max_num_connected_edges, reset_fixed_position_elements, fixed_position_nodes)

    def auto_style(self, max_num_connected_edges: int = 3):
        self.libsbmlnetwork.autorender(max_num_connected_edges)

    def update_reactions_curves(self):
        self.libsbmlnetwork.updateReactionCurves()

    def get_settings(self):
        return self.settings

    def populate_settings(self):
        self.libsbmlnetwork.enableDisplayCompartmentsTextLabel(self.settings.compartment_labels)
        self.libsbmlnetwork.enableDisplaySpeciesTextLabel(self.settings.species_labels)
        self.libsbmlnetwork.enableDisplayReactionsTextLabel(self.settings.reaction_labels)
        if self.settings.label == "name":
            self.libsbmlnetwork.setUseNameAsTextLabel(True)
        else:
            self.libsbmlnetwork.setUseNameAsTextLabel(False)
        self.libsbmlnetwork.setStoichiometricSpeciesReference(self.settings.stoichiometric_curves)

    #ToDo: Implement error_log method

    def get_version(self):
        return self.libsbmlnetwork.getVersion()

instance = SBMLNetwork()

def load(sbml: str):
    """
    Loads the SBML model.

    :param sbml: The SBML model.
    :return: an instance of the SBMLNetwork class.
    """
    instance.load(sbml)
    return instance

version = instance.get_version()
settings = instance.get_settings()
