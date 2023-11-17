import _libsbmlnetworkeditor as ne

class SBMLNetworkEditor:

    """
    A wrapper class to use libSBMLNetworkEditor, which is an API to work with the Layout and Render packages of libSBML

    """
    def __init__(self, sbml):

        """
        Initializes the SBMLNetworkEditor class by reading an SBML document from the given file name or the given text string

        :Parameters:

            - sbml: an SBML document in the form of either an SBML string or an SBML file (.xml) directory
        """

        self.sbml_object = None
        self.read_sbml(sbml)

    def read_sbml(self, sbml):

        """
        Reads an SBML document from the given file name or the given text string

        :Parameters:

            - sbml (string): a string that determines either the name or full pathname of the SBML(.xml) file to be read
                or a string containing a full SBML model.

        :Returns:

            SBMLDocument: a pointer to the SBMLDocument structure created from the SBML content in the given file name or
                from the SBML content in the given text string
        """

        self.sbml_object = ne.readSBML(sbml)
        return self.sbml_object

    def write_sbml(self, file_name=""):
        """
        Writes the given SBML document to either the file_name or a string

        :Parameters:

            - file_name (string, optional): a string (default : "") that determines the name or full pathname of the file where the SBML is to be written

        :Returns:

            either success: true on success and false if the filename could not be opened for writing
            or text: the SBML text string on success and empty string if one of the underlying parser components fail.
        """

        if file_name:
            return ne.writeSBML(self.sbml_object, file_name)
        else:
            return ne.writeSBML(self.sbml_object)

    def get_sbml(self):
        """
        Writes the given SBML document to a string a returns it

        :Returns:

            text: the SBML text string on success and empty string if one of the underlying parser components fail.
        """

        return self.write_sbml()

    def autolayout(self, stiffness=10.0, gravity=15.0, use_magnetism=False, use_boundary=False, use_grid=False):
        """
        checks if a Layout object, a GlobalRenderInformation object, and LocalRenderInformation object does not exists in the SBMLDocument,
            then adds them to it, and set all the necessary features for them.

        :Parameters:

            - stiffness (float, optional): a float (default: 10.0) that determines the stiffness value used in the autolayout algorithm (can affect the canvas dimensions).
            - gravity (float, optional): a float (default: 15.0) that determines the gravity value used in the autolayout algorithm (can affect the how densely nodes are distributed).
            - use_magnetism (boolean, optional): a boolean (default: False) that determines whether to use magnetism in the autolayout algorithm.
            - useBoundary (boolean, optional): a boolean (default: False) that determines whether to use boundary restriction in the autolayout algorithm.
            - use_grid (boolean, optional): a boolean (default: False) that determines whether to use grid restriction in the autolayout algorithm.

        :Returns:

            either success: true on success and false if the filename could not be opened for writing
            or text: the SBML text string on success and empty string if one of the underlying parser components fail.
        """

        return ne.autolayout(self.sbml_object, stiffness, gravity, use_magnetism, use_boundary, use_grid)



