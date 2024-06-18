import libsbmlnetwork
import networkinfotranslator
from IPython.display import display


class SBMLNetwork(libsbmlnetwork.LibSBMLNetwork):

    def __init__(self, sbml=""):
        super().__init__(sbml)

    def draw(self, file_name=""):
        """
        Draws the network of the SBML model. Saves the figure to the file_directory if specified, otherwise displays the figure.

        :param file_directory:
        :param file_name:
        """
        if file_name:
            networkinfotranslator.import_sbml_export_figure(self.save(), file_name, self.use_name_as_text_label, self.display_reactions_text_label)
        else:
            display(networkinfotranslator.import_sbml_export_pil_image(self.save(), self.use_name_as_text_label, self.display_reactions_text_label))


def load(sbml):
    """
    Loads the SBML model.

    :param sbml: The SBML model.
    :return: SBMLNetwork
    """
    return SBMLNetwork(sbml)



