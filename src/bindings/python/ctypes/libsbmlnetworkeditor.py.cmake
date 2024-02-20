import ctypes
import platform

current_platform = platform.system()
if current_platform == 'Windows':
    lib_path = "./libsbmlnetworkeditor.dll"
elif current_platform == 'Linux':
    lib_path = "./libsbmlnetworkeditor.so"
elif current_platform == 'Darwin':
    lib_path = "./libsbmlnetworkeditor." + "${LIBSBML_NETWORKEDITOR_DOTTED_VERSION}" + ".dylib"
else:
    raise Exception(f"Unsupported platform: {current_platform}")
    
class SBMLDocument(ctypes.Structure):
    pass

lib = ctypes.CDLL(lib_path)

class LibSBMLNetworkEditor:
    """
    A wrapper class to use libSBMLNetworkEditor, which is an API to work with the Layout and Render packages of libSBML
    """

    def __init__(self, sbml):
        """
        Initializes the LibSBMLNetworkEditor class by reading an SBML document from the given file name or the given text string

        :Parameters:

            - sbml: an SBML document in the form of either an SBML file (.xml) directory or an SBML string
        """
    
        self.sbml_object = None
        self.load(sbml)

    def load(self, sbml):
        """
        Reads an SBML document from the given file directory or the given text string

        :Parameters:

            - sbml (string): a string that determines either the name or full pathname of the SBML(.xml) file to be read or a string containing a full SBML model.

        :Returns:

            SBMLDocument: a pointer to the SBMLDocument structure created from the SBML content in the given file name or from the SBML content in the given text string
        """
        lib.c_api_readSBML.restype = ctypes.POINTER(SBMLDocument)
        self.sbml_object = lib.c_api_readSBML(str(sbml).encode())

    def export(self, file_name=""):
        """
        Writes the given SBML document to either the file_name or a string

        :Parameters:

            - file_name (string, optional): a string (default : "") that determines the name or full pathname of the file where the SBML is to be written

        :Returns:

            either success: true on success and false if the filename could not be opened for writing
            or text: the SBML text string on success and empty string if one of the underlying parser components fail.
        """
        
        if file_name:
            lib.c_api_writeSBMLToFile.restype = ctypes.c_int
            return lib.c_api_writeSBMLToFile(self.sbml_object, str(file_name).encode())
        else:
            lib.c_api_writeSBMLToString.restype = ctypes.c_char_p
            return ctypes.c_char_p(lib.c_api_writeSBMLToString(self.sbml_object)).value.decode()
        
    def autolayout(self, stiffness=10, gravity=15, use_magnetism=False, use_boundary=False, use_grid=False, locked_nodes=[]):
        """
        checks if a Layout object, a GlobalRenderInformation object, and LocalRenderInformation object does not exists in the SBMLDocument, then adds them to it, and set all the necessary features for them.

        :Parameters:

            - stiffness (float, optional): a float (default: 10.0) that determines the stiffness value used in the autolayout algorithm (can affect the canvas dimensions).
            - gravity (float, optional): a float (default: 15.0) that determines the gravity value used in the autolayout algorithm (can affect the how densely nodes are distributed).
            - use_magnetism (boolean, optional): a boolean (default: False) that determines whether to use magnetism in the autolayout algorithm.
            - use_boundary (boolean, optional): a boolean (default: False) that determines whether to use boundary restriction in the autolayout algorithm.
            - use_grid (boolean, optional): a boolean (default: False) that determines whether to use grid restriction in the autolayout algorithm.
            - locked_nodes (list, optional): a list (default: []) that determines the list of nodes that should not be moved during the autolayout algorithm.

        :Returns:

            true on success and false if autolayout algorithm was not applied successfully
        """

        locked_nodes_ptr = None
        if locked_nodes is not None:
            locked_nodes_ptr = (ctypes.c_char_p * len(locked_nodes))()
            for i in range(len(locked_nodes)):
                locked_nodes_ptr[i] = ctypes.c_char_p(locked_nodes[i].encode())

        return lib.c_api_autolayout(self.sbml_object, ctypes.c_double(stiffness), ctypes.c_double(gravity), use_magnetism, use_boundary, use_grid, locked_nodes_ptr)

    def getNumLayouts(self):
        """
        Returns the number of Layout objects in the given SBMLDocument

        :Returns:

            an integer that determines the number of Layout objects in the given SBMLDocument
        """
        return lib.c_api_getNumLayouts(self.sbml_object)

    def removeLayouts(self):
        """
        Removes all the Layout objects from the given SBMLDocument

        :Returns:

            true on success and false if the Layout objects could not be removed
        """
        return lib.c_api_removeAllLayouts(self.sbml_object)

    def getCanvasWidth(self, layout_index=0):
        """
        Returns the width of the canvas of the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the width of the canvas of the the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getCanvasWidth.restype = ctypes.c_double
        return lib.c_api_getCanvasWidth(self.sbml_object, layout_index)

    def setCanvasWidth(self, width, layout_index=0):
        """
        Sets the width of the canvas of the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - width (float): a float that determines the width of the canvas of the Layout object with the given index in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the width of the canvas could not be set
        """
        return lib.c_api_setCanvasWidth(self.sbml_object, ctypes.c_double(width), layout_index)

    def getCanvasHeight(self, layout_index=0):
        """
        Returns the height of the canvas of the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the height of the canvas of the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getCanvasHeight.restype = ctypes.c_double
        return lib.c_api_getCanvasHeight(self.sbml_object, layout_index)

    def setCanvasHeight(self, height, layout_index=0):
        """

        Sets the height of the canvas of the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - height (float): a float that determines the height of the canvas of the Layout object with the given index in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the height of the canvas could not be set
        """
        return lib.c_api_setCanvasHeight(self.sbml_object, ctypes.c_double(height), layout_index)

    def getNumAllGraphicalObjects(self, layout_index=0):
        """
        Returns the number of GraphicalObjects in the the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GraphicalObjects in the the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumAllGraphicalObjects(self.sbml_object, layout_index)

    def getNumGraphicalObjects(self, id, layout_index=0):
        """
        Returns the number of GraphicalObjects associated with the given id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the GraphicalObject
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GraphicalObjects associated with the given id in the Layout object with the given index in the given SBMLDocument
            """
        return lib.c_api_getNumGraphicalObjects(self.sbml_object, str(id).encode(), layout_index)

    def getNumAllCompartmentGlyphs(self, layout_index=0):
        """
        Returns the number of CompartmentGlyphs in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of CompartmentGlyphs in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumAllCompartmentGlyphs(self.sbml_object, layout_index)

    def getNumCompartmentGlyphs(self, compartment_id, layout_index=0):
        """
        Returns the number of CompartmentGlyphs associated with the given compartment_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - compartment_id (string): a string that determines the id of the Compartment
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

                an integer that determines the number of CompartmentGlyphs associated with the given compartment_id in the Layout object with the given index in the given SBMLDocument
            """
        return lib.c_api_getNumCompartmentGlyphs(self.sbml_object, str(compartment_id).encode(), layout_index)

    def isCompartmentGlyph(self, compartment_id, layout_index=0):
        """
        Returns whether the given compartment_id is associated with a CompartmentGlyph in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - compartment_id (string): a string that determines the id of the Compartment
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the given compartment_id is associated with a CompartmentGlyph in the Layout object with the given index in the given SBMLDocument and false otherwise
            """
        return lib.c_api_isCompartmentGlyph(self.sbml_object, str(compartment_id).encode(), layout_index)

    def getNumAllSpeciesGlyphs(self, layout_index=0):
        """
        Returns the number of SpeciesGlyphs in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of SpeciesGlyphs in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumAllSpeciesGlyphs(self.sbml_object, layout_index)

    def getNumSpeciesGlyphs(self, species_id, layout_index=0):
        """
        Returns the number of SpeciesGlyphs associated with the given species_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - species_id (string): a string that determines the id of the Species
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of SpeciesGlyphs associated with the given species_id in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumSpeciesGlyphs(self.sbml_object, str(species_id).encode(), layout_index)

    def isSpeciesGlyph(self, species_id, layout_index=0):
        """
        Returns whether the given species_id is associated with a SpeciesGlyph in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - species_id (string): a string that determines the id of the Species
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the given species_id is associated with a SpeciesGlyph in the Layout object with the given index in the given SBMLDocument and false otherwise
            """
        return lib.c_api_isSpeciesGlyph(self.sbml_object, str(species_id).encode(), layout_index)

    def getNumAllReactionGlyphs(self, layout_index=0):
        """
        Returns the number of ReactionGlyphs in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of ReactionGlyphs in the Layout object with the given index in the given SBMLDocument
            """
        return lib.c_api_getNumAllReactionGlyphs(self.sbml_object, layout_index)

    def getNumReactionGlyphs(self, reaction_id, layout_index=0):
        """
        Returns the number of ReactionGlyphs associated with the given reaction_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of ReactionGlyphs associated with the given reaction_id in the Layout object with the given index in the given SBMLDocument
            """

        return lib.c_api_getNumReactionGlyphs(self.sbml_object, str(reaction_id).encode(), layout_index)

    def isReactionGlyph(self, reaction_id, layout_index=0):
        """
        Returns whether the given reaction_id is associated with a ReactionGlyph in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the given reaction_id is associated with a ReactionGlyph in the Layout object with the given index in the given SBMLDocument and false otherwise
            """
        return lib.c_api_isReactionGlyph(self.sbml_object, str(reaction_id).encode(), layout_index)

    def getNumSpeciesReferenceGlyphs(self, reaction_id, reaction_glyph_index=0, layout_index=0):
        """
        Returns the number of SpeciesReferenceGlyphs associated with the given reaction_id and reaction_glyph_index in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of SpeciesReferenceGlyphs associated with the given reaction_id and reaction_glyph_index in the Layout object with the given index in the given SBMLDocument
            """
        return lib.c_api_getNumSpeciesReferenceGlyphs(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, layout_index)

    def isSetRole(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns whether the role of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the role of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set and false otherwise
            """

        return lib.c_api_isSetRole(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getRole(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the role of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the role of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getRole.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getRole(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def setRole(self, reaction_id, role, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Sets the role of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - role (string): a string that determines the role of the SpeciesReferenceGlyph
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the role of the SpeciesReferenceGlyph could not be set
            """
        return lib.c_api_setRole(self.sbml_object, str(reaction_id).encode(), str(role).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getNumAllTextGlyphs(self, layout_index=0):
        """
        Returns the number of TextGlyphs in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of TextGlyphs in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumAllTextGlyphs(self.sbml_object, layout_index)

    def getNumTextGlyphs(self, id, layout_index=0):
        """
        Returns the number of TextGlyphs associated with the given id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

                an integer that determines the number of TextGlyphs associated with the given id in the Layout object with the given index in the given SBMLDocument
            """
        return lib.c_api_getNumTextGlyphs(self.sbml_object, str(id).encode(), layout_index)

    def getText(self, id, text_glyph_index=0, layout_index=0):
        """

        Returns the text of the TextGlyph associated with the GraphicalObject associated with the given id, text_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text_glyph_index (int): an integer that determines the index of the TextGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the text of the TextGlyph associated with the GraphicalObject associated with the given id, text_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getText.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getText(self.sbml_object, str(id).encode(), text_glyph_index, layout_index)).value.decode()

    def setText(self, id, text, text_glyph_index=0, layout_index=0):
        """
        Sets the text of the TextGlyph associated with the GraphicalObject associated with the given id, text_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text (string): a string that determines the text of the TextGlyph
            - text_glyph_index (int): an integer that determines the index of the TextGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the text of the TextGlyph could not be set
        """
        return lib.c_api_setText(self.sbml_object, str(id).encode(), str(text).encode(), text_glyph_index, layout_index)

    def getX(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the x-coordinate of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getX.restype = ctypes.c_double
        return lib.c_api_getX(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def setX(self, id, x, graphical_object_index=0, layout_index=0):
        """
        Sets the x-coordinate of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the GraphicalObject could not be set
        """
        return lib.c_api_setX(self.sbml_object, str(id).encode(), ctypes.c_double(x), graphical_object_index, layout_index)

    def getY(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the y-coordinate of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getY.restype = ctypes.c_double
        return lib.c_api_getY(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def setY(self, id, y, graphical_object_index=0, layout_index=0):
        """
        Sets the y-coordinate of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the GraphicalObject could not be set
        """
        return lib.c_api_setY(self.sbml_object, str(id).encode(), ctypes.c_double(y), graphical_object_index, layout_index)

    def getWidth(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the width of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the width of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getWidth.restype = ctypes.c_double
        return lib.c_api_getWidth(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def setWidth(self, id, width, graphical_object_index=0, layout_index=0):
        """
        Sets the width of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - width (float): a float that determines the width of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the width of the GraphicalObject could not be set
        """
        return lib.c_api_setWidth(self.sbml_object, str(id).encode(), ctypes.c_double(width), graphical_object_index, layout_index)

    def getHeight(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the height of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the height of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getHeight.restype = ctypes.c_double
        return lib.c_api_getHeight(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def setHeight(self, id, height, graphical_object_index=0, layout_index=0):
        """
        Sets the height of the GraphicalObject associated with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - height (float): a float that determines the height of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the height of the GraphicalObject could not be set
        """
        return lib.c_api_setHeight(self.sbml_object, str(id).encode(), ctypes.c_double(height), graphical_object_index, layout_index)

    def isSetCurve(self, reaction_id, reaction_glyph_index=0, layout_index=0):
        """
        Returns whether the curve of the ReactionGlyph with the given reaction_id, reaction_glyph_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the curve of the ReactionGlyph with the given reaction_id, reaction_glyph_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetCurve(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, layout_index)

    def getNumCurveSegments(self, reaction_id, reaction_glyph_index=0, layout_index=0):
        """
        Returns the number of CurveSegments associated with the ReactionGlyph with the given reaction_id, reaction_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of CurveSegments associated with the ReactionGlyph with the given reaction_id, reaction_glyph_index, and layout_index in the given SBMLDocument
        """
        return lib.c_api_getNumCurveSegments(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, layout_index)

    def getCurveStartPointX(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveStartPointX.restype = ctypes.c_double
        return lib.c_api_getCurveStartPointX(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveStartPointX(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - x (float): a float that determines the x-coordinate of the start point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the start point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveStartPointX(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveStartPointY(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveStartPointY.restype = ctypes.c_double
        return lib.c_api_getCurveStartPointY(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveStartPointY(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - y (float): a float that determines the y-coordinate of the start point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the start point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveStartPointY(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveEndPointX(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveEndPointX.restype = ctypes.c_double
        return lib.c_api_getCurveEndPointX(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveEndPointX(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - x (float): a float that determines the x-coordinate of the end point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the end point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveEndPointX(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveEndPointY(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveEndPointY.restype = ctypes.c_double
        return lib.c_api_getCurveEndPointY(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveEndPointY(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - y (float): a float that determines the y-coordinate of the end point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the end point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveEndPointY(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveBasePoint1X(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveBasePoint1X.restype = ctypes.c_double
        return lib.c_api_getCurveBasePoint1X(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveBasePoint1X(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - x (float): a float that determines the x-coordinate of the first base point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the first base point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveBasePoint1X(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveBasePoint1Y(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveBasePoint1Y.restype = ctypes.c_double
        return lib.c_api_getCurveBasePoint1Y(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveBasePoint1Y(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - y (float): a float that determines the y-coordinate of the first base point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the first base point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveBasePoint1Y(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveBasePoint2X(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveBasePoint2X.restype = ctypes.c_double
        return lib.c_api_getCurveBasePoint2X(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveBasePoint2X(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - x (float): a float that determines the x-coordinate of the second base point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the second base point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveBasePoint2X(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveBasePoint2Y(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getCurveBasePoint2Y.restype = ctypes.c_double
        return lib.c_api_getCurveBasePoint2Y(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveBasePoint2Y(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - y (float): a float that determines the y-coordinate of the second base point of the CurveSegment
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:
            true on success and false if the y-coordinate of the second base point of the CurveSegment could not be set
        """
        return lib.c_api_setCurveBasePoint2Y(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)










