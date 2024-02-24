import ctypes
import os
import platform

lib_path = os.path.dirname(os.path.abspath(__file__))
shared_lib = lib_path
current_platform = platform.system()
if current_platform == 'Windows':
    shared_lib = os.path.join(lib_path, "libsbmlnetworkeditor.dll")
elif current_platform == 'Linux':
    shared_lib = os.path.join(lib_path, "libsbmlnetworkeditor.so")
elif current_platform == 'Darwin':
    shared_lib = os.path.join(lib_path, "libsbmlnetworkeditor." + "${LIBSBML_NETWORKEDITOR_DOTTED_VERSION}" + ".dylib")
else:
    raise Exception(f"Unsupported platform: {current_platform}")
    
class SBMLDocument(ctypes.Structure):
    pass

lib = ctypes.CDLL(shared_lib)

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

    def getListOfCompartmentIds(self):
        """
        Returns the list of CompartmentGlyph ids in the Layout object with the given index in the given SBMLDocument

        :Returns:

            a list of strings that determines the list of Compartment ids in the given SBMLDocument
        """
        lib.c_api_getNthCompartmentId.restype = ctypes.c_char_p
        list_of_compartment_ids = []
        for n in range(lib.c_api_getNumCompartments(self.sbml_object)):
            list_of_compartment_ids.append(ctypes.c_char_p(lib.c_api_getNthCompartmentId(self.sbml_object, n)).value.decode())

        return list_of_compartment_ids


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

    def getListOfSpeciesIds(self):
        """
        Returns the list of SpeciesGlyph ids in the Layout object with the given index in the given SBMLDocument

        :Returns:

            a list of strings that determines the list of Species ids in the given SBMLDocument
        """
        lib.c_api_getNthSpeciesId.restype = ctypes.c_char_p
        list_of_species_ids = []
        for n in range(lib.c_api_getNumSpecies(self.sbml_object)):
            list_of_species_ids.append(ctypes.c_char_p(lib.c_api_getNthSpeciesId(self.sbml_object, n)).value.decode())

        return list_of_species_ids

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

    def getListOfReactionIds(self):
        """
        Returns the list of ReactionGlyph ids in the Layout object with the given index in the given SBMLDocument

        :Returns:

            a list of strings that determines the list of Reaction ids in the given SBMLDocument
        """
        lib.c_api_getNthReactionId.restype = ctypes.c_char_p
        list_of_reaction_ids = []
        for n in range(lib.c_api_getNumReactions(self.sbml_object)):
            list_of_reaction_ids.append(ctypes.c_char_p(lib.c_api_getNthReactionId(self.sbml_object, n)).value.decode())

        return list_of_reaction_ids

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

    def getNumGlobalRenderInformation(self):
        """
        Returns the number of GlobalRenderInformation objects in the given SBMLDocument

        :Returns:

            an integer that determines the number of GlobalRenderInformation objects in the given SBMLDocument
        """
        return lib.c_api_getNumGlobalRenderInformation(self.sbml_object)

    def getNumLocalRenderInformation(self, layout_index=0):
        """
        Returns the number of LocalRenderInformation objects in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of LocalRenderInformation objects in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumLocalRenderInformation(self.sbml_object, layout_index)

    def removeRenderInformation(self):
        """
        Removes all the RenderInformation objects from the given SBMLDocument

        :Returns:

            true on success and false if the RenderInformation objects could not be removed
        """
        return lib.c_api_removeRenderInformation(self.sbml_object)

    def removeGlobalRenderInformation(self):
        """
        Removes all the GlobalRenderInformation object from the given SBMLDocument

        :Returns:

            true on success and false if the GlobalRenderInformation object could not be removed
        """
        return lib.c_api_removeGlobalRenderInformation(self.sbml_object)

    def removeLocalRenderInformation(self, layout_index=0):
        """
        Removes all the LocalRenderInformation objects from the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the LocalRenderInformation objects could not be removed
        """
        return lib.c_api_removeLocalRenderInformation(self.sbml_object, layout_index)

    def isSetBackgroundColor(self, render_index=0):
        """
        Returns whether the background color of the RenderInformation object with the given index in the given SBMLDocument is set

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true if the background color of the RenderInformation object with the given index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetBackgroundColor(self.sbml_object, render_index)

    def getBackgroundColor(self, render_index=0):
        """
        Returns the background color of the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the background color of the RenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getBackgroundColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getBackgroundColor(self.sbml_object, render_index)).value.decode()

    def setBackgroundColor(self, color, render_index=0):
        """
        Sets the background color of the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - color (string): a string that determines the background color of the RenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the background color of the RenderInformation object could not be set
        """
        return lib.c_api_setBackgroundColor(self.sbml_object, str(color).encode(), render_index)

    def isSetColorValue(self, color_id, render_index=0):
        """
        Returns whether the color value of the ColorDefinition object with the given color_id and render_index in the given SBMLDocument is set

        :Parameters:

            - color_id (string): a string that determines the id of the ColorDefinition object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true if the color value of the ColorDefinition object with the given color_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetColorValue(self.sbml_object, str(color_id).encode(), render_index)

    def getColorValue(self, color_id, render_index=0):
        """
        Returns the color value of the ColorDefinition object with the given color_id and render_index in the given SBMLDocument

        :Parameters:

            - color_id (string): a string that determines the id of the ColorDefinition object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the color value of the ColorDefinition object with the given color_id and render_index in the given SBMLDocument
        """
        lib.c_api_getColorValue.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getColorValue(self.sbml_object, str(color_id).encode(), render_index)).value.decode()

    def setColorValue(self, color_id, color, render_index=0):
        """
        Sets the color value of the ColorDefinition object with the given color_id and render_index in the given SBMLDocument

        :Parameters:

            - color_id (string): a string that determines the id of the ColorDefinition object
            - color (string): a string that determines the color value of the ColorDefinition object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the color value of the ColorDefinition object could not be set
        """
        return lib.c_api_setColorValue(self.sbml_object, str(color_id).encode(), str(color).encode(), render_index)

    def isSetBorderColor(self, id):
        """
        Returns whether the border color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the border color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetBorderColor(self.sbml_object, str(id).encode())

    def getBorderColor(self, id):
        """
        Returns the border color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the border color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getBorderColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getBorderColor(self.sbml_object, str(id).encode())).value.decode()

    def setBorderColor(self, id, border_color):
        """
        Sets the border color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_color (string): a string that determines the border color of the GraphicalObject

        :Returns:

            true on success and false if the border color of the GraphicalObject could not be set
        """
        return lib.c_api_setBorderColor(self.sbml_object, str(id).encode(), str(border_color).encode())

    def isSetBorderWidth(self, id):
        """
        Returns whether the border width of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the border width of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetBorderWidth(self.sbml_object, str(id).encode())

    def getBorderWidth(self, id):
        """
        Returns the border width of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

                a float that determines the border width of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
            """
        lib.c_api_getBorderWidth.restype = ctypes.c_double
        return lib.c_api_getBorderWidth(self.sbml_object, str(id).encode())

    def setBorderWidth(self, id, border_width):
        """
        Sets the border width of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_width (float): a float that determines the border width of the GraphicalObject

        :Returns:

            true on success and false if the border width of the GraphicalObject could not be set
        """
        return lib.c_api_setBorderWidth(self.sbml_object, str(id).encode(), ctypes.c_double(border_width))

    def isSetFillColor(self, id):
        """
        Returns whether the fill color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the fill color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFillColor(self.sbml_object, str(id).encode())

    def getFillColor(self, id):
        """
        Returns the fill color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the fill color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFillColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFillColor(self.sbml_object, str(id).encode())).value.decode()

    def setFillColor(self, id, fill_color):
        """

        Sets the fill color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - fill_color (string): a string that determines the fill color of the GraphicalObject

        :Returns:

            true on success and false if the fill color of the GraphicalObject could not be set
        """
        return lib.c_api_setFillColor(self.sbml_object, str(id).encode(), str(fill_color).encode())

    def isSetFillRule(self, id):
        """
        Returns whether the fill rule of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the fill rule of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFillRule(self.sbml_object, str(id).encode())

    def getFillRule(self, id):
        """
        Returns the fill rule of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the fill rule of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFillRule.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFillRule(self.sbml_object, str(id).encode())).value.decode()

    def setFillRule(self, id, fill_rule):
        """
        Sets the fill rule of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - fill_rule (string): a string that determines the fill rule of the GraphicalObject

        :Returns:

            true on success and false if the fill rule of the GraphicalObject could not be set
        """
        return lib.c_api_setFillRule(self.sbml_object, str(id).encode(), str(fill_rule).encode())

    def isSetFontColor(self, id):
        """
        Returns whether the font color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the font color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontColor(self.sbml_object, str(id).encode())

    def getFontColor(self, id):
        """
        Returns the font color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the font color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFontColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontColor(self.sbml_object, str(id).encode())).value.decode()

    def setFontColor(self, id, font_color):
        """

        Sets the font color of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_color (string): a string that determines the font color of the GraphicalObject

        :Returns:

            true on success and false if the font color of the GraphicalObject could not be set
        """
        return lib.c_api_setFontColor(self.sbml_object, str(id).encode(), str(font_color).encode())

    def isSetFontFamily(self, id):
        """
        Returns whether the font family of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the font family of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontFamily(self.sbml_object, str(id).encode())

    def getFontFamily(self, id):
        """
        Returns the font family of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the font family of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFontFamily.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontFamily(self.sbml_object, str(id).encode())).value.decode()

    def setFontFamily(self, id, font_family):
        """

        Sets the font family of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_family (string): a string that determines the font family of the GraphicalObject

        :Returns:

            true on success and false if the font family of the GraphicalObject could not be set
        """
        return lib.c_api_setFontFamily(self.sbml_object, str(id).encode(), str(font_family).encode())

    def isSetFontSize(self, id):
        """
        Returns whether the font size of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the font size of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontSize(self.sbml_object, str(id).encode())

    def getFontSize(self, id):
        """

        Returns the font size of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a float that determines the font size of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFontSize.restype = ctypes.c_double
        return lib.c_api_getFontSize(self.sbml_object, str(id).encode())

    def setFontSize(self, id, font_size):
        """
        Sets the font size of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_size (float): a float that determines the font size of the GraphicalObject

        :Returns:

            true on success and false if the font size of the GraphicalObject could not be set
        """
        return lib.c_api_setFontSize(self.sbml_object, str(id).encode(), ctypes.c_double(font_size))

    def isSetFontWeight(self, id):
        """
        Returns whether the font weight of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the font weight of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontWeight(self.sbml_object, str(id).encode())

    def getFontWeight(self, id):
        """
        Returns the font weight of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the font weight of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFontWeight.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontWeight(self.sbml_object, str(id).encode())).value.decode()

    def setFontWeight(self, id, font_weight):
        """
        Sets the font weight of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_weight (string): a string that determines the font weight of the GraphicalObject

        :Returns:

            true on success and false if the font weight of the GraphicalObject could not be set
        """
        return lib.c_api_setFontWeight(self.sbml_object, str(id).encode(), str(font_weight).encode())

    def isSetFontStyle(self, id):
        """
        Returns whether the font style of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the font style of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontStyle(self.sbml_object, str(id).encode())


    def getFontStyle(self, id):
        """
        Returns the font style of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the font style of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getFontStyle.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontStyle(self.sbml_object, str(id).encode())).value.decode()

    def setFontStyle(self, id, font_style):
        """
        Sets the font style of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_style (string): a string that determines the font style of the GraphicalObject

        :Returns:

            true on success and false if the font style of the GraphicalObject could not be set
        """
        return lib.c_api_setFontStyle(self.sbml_object, str(id).encode(), str(font_style).encode())

    def isSetTextHorizontalAlignment(self, id):
        """
        Returns whether the text horizontal alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the text horizontal alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetTextHorizontalAlignment(self.sbml_object, str(id).encode())

    def getTextHorizontalAlignment(self, id):
        """
        Returns the text horizontal alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the text horizontal alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getTextHorizontalAlignment.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getTextHorizontalAlignment(self.sbml_object, str(id).encode())).value.decode()

    def setTextHorizontalAlignment(self, id, text_horizontal_alignment):
        """
        Sets the text horizontal alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text_horizontal_alignment (string): a string that determines the text horizontal alignment of the GraphicalObject

        :Returns:

            true on success and false if the text horizontal alignment of the GraphicalObject could not be set
        """
        return lib.c_api_setTextHorizontalAlignment(self.sbml_object, str(id).encode(), str(text_horizontal_alignment).encode())

    def isSetTextVerticalAlignment(self, id):
        """
        Returns whether the text vertical alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the text vertical alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetTextVerticalAlignment(self.sbml_object, str(id).encode())

    def getTextVerticalAlignment(self, id):
        """
        Returns the text vertical alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the text vertical alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getTextVerticalAlignment.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getTextVerticalAlignment(self.sbml_object, str(id).encode())).value.decode()

    def setTextVerticalAlignment(self, id, text_vertical_alignment):
        """
        Sets the text vertical alignment of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text_vertical_alignment (string): a string that determines the text vertical alignment of the GraphicalObject

        :Returns:

            true on success and false if the text vertical alignment of the GraphicalObject could not be set
        """
        return lib.c_api_setTextVerticalAlignment(self.sbml_object, str(id).encode(), str(text_vertical_alignment).encode())

    def isSetStartHead(self, id):
        """
        Returns whether the start head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the start head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetStartHead(self.sbml_object, str(id).encode())

    def getStartHead(self, id):
        """
        Returns the start head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the start head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getStartHead.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getStartHead(self.sbml_object, str(id).encode())).value.decode()

    def setStartHead(self, id, start_head):
        """
        Sets the start head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - start_head (string): a string that determines the start head of the GraphicalObject

        :Returns:

            true on success and false if the start head of the GraphicalObject could not be set
        """
        return lib.c_api_setStartHead(self.sbml_object, str(id).encode(), str(start_head).encode())

    def isSetEndHead(self, id):
        """
        Returns whether the end head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            true if the end head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetEndHead(self.sbml_object, str(id).encode())

    def getEndHead(self, id):
        """
        Returns the end head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            a string that determines the end head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getEndHead.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getEndHead(self.sbml_object, str(id).encode())).value.decode()

    def setEndHead(self, id, end_head):
        """
        Sets the end head of the GraphicalObject associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - end_head (string): a string that determines the end head of the GraphicalObject

        :Returns:

            true on success and false if the end head of the GraphicalObject could not be set
        """
        return lib.c_api_setEndHead(self.sbml_object, str(id).encode(), str(end_head).encode())

    def getNumGeometricShapes(self, id):
        """
        Returns the number of GeometricShape objects associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity

        :Returns:

            an integer that determines the number of GeometricShape objects associated with the model entity with the given id in the given SBMLDocument
        """
        return lib.c_api_getNumGeometricShapes(self.sbml_object, str(id).encode())

    def isRectangle(self, id, index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Rectangle object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Rectangle object and false otherwise
        """
        return lib.c_api_isRectangle(self.sbml_object, str(id).encode(),  index)

    def isEllipse(self, id, index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Ellipse object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Ellipse object and false otherwise
        """
        return lib.c_api_isEllipse(self.sbml_object, str(id).encode(), index)

    def isPolygon(self, id, index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Polygon object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Polygon object and false otherwise
        """
        return lib.c_api_isPolygon(self.sbml_object, str(id).encode(), index)

    def isImage(self, id, index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Image object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Image object and false otherwise
        """
        return lib.c_api_isImage(self.sbml_object, str(id).encode(), index)

    def isRenderCurve(self, id, index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a RenderCurve object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a RenderCurve object and false otherwise
        """
        return lib.c_api_isRenderCurve(self.sbml_object, str(id).encode(), index)

    def isText(self, id, index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Text object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Text object and false otherwise
        """
        return lib.c_api_isText(self.sbml_object, str(id).encode(), index)

    def getGeometricShapeX(self, id, index=0):
        """
        Returns the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeX(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeX(self, id, x, index=0):
        """
        Sets the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeX(self.sbml_object, str(id).encode(), ctypes.c_double(x), index)

    def getGeometricShapeY(self, id, index=0):
        """
        Returns the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeY(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeY(self, id, y, index=0):
        """
        Sets the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeY(self.sbml_object, str(id).encode(), ctypes.c_double(y), index)

    def getGeometricShapeWidth(self, id, index=0):
        """
        Returns the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeWidth.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeWidth(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeWidth(self, id, width, index=0):
        """
        Sets the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - width (float): a float that determines the width of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the width of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeWidth(self.sbml_object, str(id).encode(), ctypes.c_double(width), index)

    def getGeometricShapeHeight(self, id, index=0):
        """
        Returns the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeHeight.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeHeight(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeHeight(self, id, height, index=0):
        """
        Sets the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - height (float): a float that determines the height of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the height of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeHeight(self.sbml_object, str(id).encode(), ctypes.c_double(height), index)

    def getGeometricShapeRatio(self, id, index=0):
        """
        Returns the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeRatio.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeRatio(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeRatio(self, id, ratio, index=0):
        """
        Sets the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - ratio (float): a float that determines the ratio of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the ratio of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeRatio(self.sbml_object, str(id).encode(), ctypes.c_double(ratio), index)

    def getGeometricShapeBorderRadiusX(self, id, index=0):
        """
        Returns the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeBorderRadiusX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeBorderRadiusX(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeBorderRadiusX(self, id, border_radius_x, index=0):
        """
        Sets the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_radius_x (float): a float that determines the x-radius of the border of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the x-radius of the border of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeBorderRadiusX(self.sbml_object, str(id).encode(), ctypes.c_double(border_radius_x), index)

    def getGeometricShapeBorderRadiusY(self, id, index=0):
        """
        Returns the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeBorderRadiusY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeBorderRadiusY(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeBorderRadiusY(self, id, border_radius_y, index=0):
        """
        Sets the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_radius_y (float): a float that determines the y-radius of the border of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the y-radius of the border of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeBorderRadiusY(self.sbml_object, str(id).encode(), ctypes.c_double(border_radius_y), index)

    def getGeometricShapeCenterX(self, id, index=0):
        """
        Returns the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeCenterX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeCenterX(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeCenterX(self, id, center_x, index=0):
        """
        Sets the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - center_x (float): a float that determines the x-coordinate of the center of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the center of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeCenterX(self.sbml_object, str(id).encode(), ctypes.c_double(center_x), index)

    def getGeometricShapeCenterY(self, id, index=0):
        """
        Returns the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeCenterY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeCenterY(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeCenterY(self, id, center_y, index=0):
        """
        Sets the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - center_y (float): a float that determines the y-coordinate of the center of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the center of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeCenterY(self.sbml_object, str(id).encode(), ctypes.c_double(center_y), index)

    def getGeometricShapeRadiusX(self, id, index=0):
        """
        Returns the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeRadiusX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeRadiusX(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeRadiusX(self, id, radius_x, index=0):
        """
        Sets the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - radius_x (float): a float that determines the x-radius of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the x-radius of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeRadiusX(self.sbml_object, str(id).encode(), ctypes.c_double(radius_x), index)

    def getGeometricShapeRadiusY(self, id, index=0):
        """
        Returns the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a float that determines the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeRadiusY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeRadiusY(self.sbml_object, str(id).encode(), index)

    def setGeometricShapeRadiusY(self, id, radius_y, index=0):
        """
        Sets the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - radius_y (float): a float that determines the y-radius of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the y-radius of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeRadiusY(self.sbml_object, str(id).encode(), ctypes.c_double(radius_y), index)


    def getGeometricShapeNumSegments(self, id, index=0):
        """
        Returns the number of segments of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            an integer that determines the number of segments of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        return lib.c_api_getGeometricShapeNumSegments(self.sbml_object, str(id).encode(), index)

    def getGeometricShapeSegmentX(self, id, index=0, segment_index=0):
        """
        Returns the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            a float that determines the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentX(self.sbml_object, str(id).encode(), index, segment_index)

    def setGeometricShapeSegmentX(self, id, x, index=0, segment_index=0):
        """
        Sets the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the segment of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            true on success and false if the x-coordinate of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentX(self.sbml_object, str(id).encode(), ctypes.c_double(x), index, segment_index)

    def getGeometricShapeSegmentY(self, id, index=0, segment_index=0):
        """
        Returns the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            a float that determines the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentY(self.sbml_object, str(id).encode(), index, segment_index)

    def setGeometricShapeSegmentY(self, id, y, index=0, segment_index=0):
        """
        Sets the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the segment of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            true on success and false if the y-coordinate of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentY(self.sbml_object, str(id).encode(), ctypes.c_double(y), index, segment_index)

    def getGeometricShapeSegmentBasePoint1X(self, id, index=0, segment_index=0):
        """
        Returns the x-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            a float that determines the x-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint1X.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint1X(self.sbml_object, str(id).encode(), index, segment_index)

    def setGeometricShapeSegmentBasePoint1X(self, id, x, index=0, segment_index=0):
        """
        Sets the x-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the base point 1 of the segment of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            true on success and false if the x-coordinate of the base point 1 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint1X(self.sbml_object, str(id).encode(), ctypes.c_double(x), index, segment_index)

    def getGeometricShapeSegmentBasePoint1Y(self, id, index=0, segment_index=0):
        """
        Returns the y-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            a float that determines the y-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint1Y.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint1Y(self.sbml_object, str(id).encode(), index, segment_index)

    def setGeometricShapeSegmentBasePoint1Y(self, id, y, index=0, segment_index=0):
        """
        Sets the y-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the base point 1 of the segment of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            true on success and false if the y-coordinate of the base point 1 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint1Y(self.sbml_object, str(id).encode(), ctypes.c_double(y), index, segment_index)

    def getGeometricShapeSegmentBasePoint2X(self, id, index=0, segment_index=0):
        """
        Returns the x-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            a float that determines the x-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint2X.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint2X(self.sbml_object, str(id).encode(), index, segment_index)

    def setGeometricShapeSegmentBasePoint2X(self, id, x, index=0, segment_index=0):
        """
        Sets the x-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the base point 2 of the segment of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            true on success and false if the x-coordinate of the base point 2 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint2X(self.sbml_object, str(id).encode(), ctypes.c_double(x), index, segment_index)

    def getGeometricShapeSegmentBasePoint2Y(self, id, index=0, segment_index=0):
        """

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            a float that determines the y-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint2Y.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint2Y(self.sbml_object, str(id).encode(), index, segment_index)

    def setGeometricShapeSegmentBasePoint2Y(self, id, y, index=0, segment_index=0):
        """
        Sets the y-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the base point 2 of the segment of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object

        :Returns:

            true on success and false if the y-coordinate of the base point 2 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint2Y(self.sbml_object, str(id).encode(), ctypes.c_double(y), index, segment_index)

    def isSetGeometricShapeHref(self, id, index=0):
        """
        Returns whether the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true if the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeHref(self.sbml_object, str(id).encode(), index)

    def getGeometricShapeHref(self, id, index=0):
        """
        Returns the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            a string that determines the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeHref.restype = ctypes.c_char_p
        return lib.c_api_getGeometricShapeHref(self.sbml_object, str(id).encode(), index).decode('utf-8')

    def setGeometricShapeHref(self, id, href, index=0):
        """
        Sets the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - href (string): a string that determines the href of the GeometricShape object
            - index (int): an integer that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument

        :Returns:

            true on success and false if the href of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeHref(self.sbml_object, str(id).encode(), str(href).encode(), index)





