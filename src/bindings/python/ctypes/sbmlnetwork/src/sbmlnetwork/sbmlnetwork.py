import libsbmlnetwork
import networkinfotranslator
from IPython.display import display


class SBMLNetwork(libsbmlnetwork.LibSBMLNetwork):

    def __init__(self, sbml="", disable_autolayout=False):
        """
        Initializes the SBMLNetwork object.
        :param sbml:
        :param disable_autolayout:
        """
        super().__init__(sbml, disable_autolayout)

    def draw(self, file_name=""):
        """
        Draws the network of the SBML model. Saves the figure to the file_directory if specified, otherwise displays the figure.

        :param file_directory:
        :param file_name:
        """
        if file_name:
            networkinfotranslator.import_sbml_export_figure(self, file_name,
                                                            self.display_compartments_text_label,
                                                            self.display_species_text_label,
                                                            self.display_reactions_text_label)
        else:
            display(networkinfotranslator.import_sbml_export_pil_image(self,
                                                                       self.display_compartments_text_label,
                                                                       self.display_species_text_label,
                                                                       self.display_reactions_text_label))


def load(sbml, disable_autolayout=False):
    """
    Loads the SBML model.

    :param sbml: The SBML model.
    :param disable_autolayout: If True, the autolayout will not be applied.
    :return: SBMLNetwork
    """
    return SBMLNetwork(sbml, disable_autolayout)



