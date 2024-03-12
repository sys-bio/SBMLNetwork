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

    def getVersion(self):
        """
        Returns the version of the libSBMLNetworkEditor

        :Returns:

            a string that determines the version of the libSBMLNetworkEditor
        """
        lib.c_api_getVersion.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getVersion()).value.decode()

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
        if not self.isSetModel():
            raise Exception("The SBML document could not be loaded")
        if not self._layout_is_specified() or not self._render_is_specified():
            self.autolayout()

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

        return lib.c_api_autolayout(self.sbml_object, ctypes.c_double(stiffness), ctypes.c_double(gravity), use_magnetism, use_boundary, use_grid, len(locked_nodes), locked_nodes_ptr)

    def getSBMLLevel(self):
        """
        Returns the SBML level of the given SBMLDocument

        :Returns:

            an integer that determines the SBML level of the given SBMLDocument
        """
        return lib.c_api_getSBMLLevel(self.sbml_object)

    def getSBMLVersion(self):
        """
        Returns the SBML version of the given SBMLDocument

        :Returns:

            an integer that determines the SBML version of the given SBMLDocument
        """
        return lib.c_api_getSBMLVersion(self.sbml_object)

    def isSetModel(self):
        """
        Returns whether the SBMLDocument has a Model object

        :Returns:

            true if the SBMLDocument has a Model object and false otherwise
        """
        return lib.c_api_isSetModel(self.sbml_object)

    def getNumCompartments(self):
        """
        Returns the number of Compartment objects in the given SBMLDocument

        :Returns:

            an integer that determines the number of Compartment objects in the given SBMLDocument
        """
        return lib.c_api_getNumCompartments(self.sbml_object)

    def getNthCompartmentId(self, index):
        """
        Returns the id of the Compartment object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the Compartment object in the given SBMLDocument

        :Returns:

            a string that determines the id of the Compartment object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthCompartmentId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthCompartmentId(self.sbml_object, index)).value.decode()

    def getNumSpecies(self):
        """
        Returns the number of Species objects in the given SBMLDocument

        :Returns:

            an integer that determines the number of Species objects in the given SBMLDocument
        """
        return lib.c_api_getNumSpecies(self.sbml_object)

    def getNthSpeciesId(self, index):
        """
        Returns the id of the Species object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the Species object in the given SBMLDocument

        :Returns:

            a string that determines the id of the Species object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthSpeciesId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthSpeciesId(self.sbml_object, index)).value.decode()

    def getNumReactions(self):
        """
        Returns the number of Reaction objects in the given SBMLDocument

        :Returns:

            an integer that determines the number of Reaction objects in the given SBMLDocument
        """
        return lib.c_api_getNumReactions(self.sbml_object)

    def getNthReactionId(self, index):
        """
        Returns the id of the Reaction object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the Reaction object in the given SBMLDocument

        :Returns:

            a string that determines the id of the Reaction object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthReactionId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthReactionId(self.sbml_object, index)).value.decode()

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

    def createDefaultLayout(self, stiffness=10, gravity=15, use_magnetism=False, use_boundary=False, use_grid=False, locked_nodes=[]):
        """
        Creates a default Layout object in the given SBMLDocument and sets all the necessary features for it

        :Parameters:

            - stiffness (float, optional): a float (default: 10.0) that determines the stiffness value used in the autolayout algorithm (can affect the canvas dimensions).
            - gravity (float, optional): a float (default: 15.0) that determines the gravity value used in the autolayout algorithm (can affect the how densely nodes are distributed).
            - use_magnetism (boolean, optional): a boolean (default: False) that determines whether to use magnetism in the autolayout algorithm.
            - use_boundary (boolean, optional): a boolean (default: False) that determines whether to use boundary restriction in the autolayout algorithm.
            - use_grid (boolean, optional): a boolean (default: False) that determines whether to use grid restriction in the autolayout algorithm.
            - locked_nodes (list, optional): a list (default: []) that determines the list of nodes that should not be moved during the autolayout algorithm.

        :Returns:

            true on success and false if the default Layout object could not be created
        """
        locked_nodes_ptr = None
        if locked_nodes is not None:
            locked_nodes_ptr = (ctypes.c_char_p * len(locked_nodes))()
            for i in range(len(locked_nodes)):
                locked_nodes_ptr[i] = ctypes.c_char_p(locked_nodes[i].encode())

        return lib.c_api_createDefaultLayout(self.sbml_object, ctypes.c_double(stiffness), ctypes.c_double(gravity), use_magnetism, use_boundary, use_grid, locked_nodes_ptr)

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

    def getNthGraphicalObjectId(self, id, index, layout_index=0):
        """
        Returns the id of the GraphicalObject with the given index associated with the given id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the GraphicalObject
            - index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the id of the GraphicalObject with the given index associated with the given id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGraphicalObjectId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthGraphicalObjectId(self.sbml_object, str(id).encode(), index, layout_index)).value.decode()

    def getNthGraphicalObjectMetaId(self, id, index, layout_index=0):
        """
        Returns the meta id of the GraphicalObject with the given index associated with the given id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the GraphicalObject
            - index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the meta id of the GraphicalObject with the given index associated with the given id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGraphicalObjectMetaId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthGraphicalObjectMetaId(self.sbml_object, str(id).encode(), index, layout_index)).value.decode()

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

    def getNthCompartmentGlyphId(self, compartment_id, index, layout_index=0):
        """
        Returns the id of the CompartmentGlyph with the given index associated with the given compartment_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - compartment_id (string): a string that determines the id of the Compartment
            - index (int): an integer that determines the index of the CompartmentGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the id of the CompartmentGlyph with the given index associated with the given compartment_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthCompartmentGlyphId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthCompartmentGlyphId(self.sbml_object, str(compartment_id).encode(), index, layout_index)).value.decode()

    def getNthCompartmentGlyphMetaId(self, compartment_id, index, layout_index=0):
        """
        Returns the meta id of the CompartmentGlyph with the given index associated with the given compartment_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - compartment_id (string): a string that determines the id of the Compartment
            - index (int): an integer that determines the index of the CompartmentGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the meta id of the CompartmentGlyph with the given index associated with the given compartment_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthCompartmentGlyphMetaId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthCompartmentGlyphMetaId(self.sbml_object, str(compartment_id).encode(), index, layout_index)).value.decode()

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

    def getCompartmentId(self, entity_id, graphical_object_id=0, layout_index=0):
        """
        Returns the id of the Compartment associated with the given entity_id and graphical_object_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - entity_id (string): a string that determines the id of the Entity
            - graphical_object_id (string): a string that determines the id of the GraphicalObject
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the id of the Compartment associated with the given entity_id and graphical_object_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getCompartmentId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getCompartmentId(self.sbml_object, str(entity_id).encode(), str(graphical_object_id).encode(), layout_index)).value.decode()

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

    def getNthSpeciesGlyphId(self, species_id, index, layout_index=0):
        """
        Returns the id of the SpeciesGlyph with the given index associated with the given species_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - species_id (string): a string that determines the id of the Species
            - index (int): an integer that determines the index of the SpeciesGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the id of the SpeciesGlyph with the given index associated with the given species_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthSpeciesGlyphId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthSpeciesGlyphId(self.sbml_object, str(species_id).encode(), index, layout_index)).value.decode()

    def getNthSpeciesGlyphMetaId(self, species_id, index, layout_index=0):
        """
        Returns the meta id of the SpeciesGlyph with the given index associated with the given species_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - species_id (string): a string that determines the id of the Species
            - index (int): an integer that determines the index of the SpeciesGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the meta id of the SpeciesGlyph with the given index associated with the given species_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthSpeciesGlyphMetaId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthSpeciesGlyphMetaId(self.sbml_object, str(species_id).encode(), index, layout_index)).value.decode()

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

    def getNthReactionGlyphId(self, reaction_id, index, layout_index=0):
        """
        Returns the id of the ReactionGlyph with the given index associated with the given reaction_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the id of the ReactionGlyph with the given index associated with the given reaction_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthReactionGlyphId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthReactionGlyphId(self.sbml_object, str(reaction_id).encode(), index, layout_index)).value.decode()

    def getNthReactionGlyphMetaId(self, reaction_id, index, layout_index=0):
        """
        Returns the meta id of the ReactionGlyph with the given index associated with the given reaction_id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the meta id of the ReactionGlyph with the given index associated with the given reaction_id in the Layout object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthReactionGlyphMetaId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthReactionGlyphMetaId(self.sbml_object, str(reaction_id).encode(), index, layout_index)).value.decode()

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

    def getSpeciesReferenceSpeciesId(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the species id of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the species id of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceSpeciesId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getSpeciesReferenceSpeciesId(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def getSpeciesReferenceSpeciesGlyphId(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the species glyph id of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the species glyph id of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceSpeciesGlyphId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getSpeciesReferenceSpeciesGlyphId(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def isSetSpeciesReferenceRole(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
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

        return lib.c_api_isSetSpeciesReferenceRole(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getSpeciesReferenceRole(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
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
        lib.c_api_getSpeciesReferenceRole.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getSpeciesReferenceRole(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def setSpeciesReferenceRole(self, reaction_id, role, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
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
        return lib.c_api_setSpeciesReferenceRole(self.sbml_object, str(reaction_id).encode(), str(role).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getNumSpeciesReferenceCurveSegments(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the number of CurveSegments associated with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of CurveSegments associated with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
            """
        return lib.c_api_getNumSpeciesReferenceCurveSegments(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def isSpeciesReferenceCurveSegmentCubicBezier(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns whether the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument is a CubicBezier

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument is a CubicBezier and false otherwise
        """
        return lib.c_api_isSpeciesReferenceCurveSegmentCubicBezier(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentStartPointX(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentStartPointX.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentStartPointX(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentStartPointX(self, reaction_id, x, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - x (float): a float that determines the x-coordinate of the start point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the start point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentStartPointX(self.sbml_object, str(reaction_id).encode(), x, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentStartPointY(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentStartPointY.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentStartPointY(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentStartPointY(self, reaction_id, y, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the start point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - y (float): a float that determines the y-coordinate of the start point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the start point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentStartPointY(self.sbml_object, str(reaction_id).encode(), y, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentEndPointX(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentEndPointX.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentEndPointX(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentEndPointX(self, reaction_id, x, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - x (float): a float that determines the x-coordinate of the end point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the end point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentEndPointX(self.sbml_object, str(reaction_id).encode(), x, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentEndPointY(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentEndPointY.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentEndPointY(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentEndPointY(self, reaction_id, y, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the end point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - y (float): a float that determines the y-coordinate of the end point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the end point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentEndPointY(self.sbml_object, str(reaction_id).encode(), y, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentBasePoint1X(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentBasePoint1X.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentBasePoint1X(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentBasePoint1X(self, reaction_id, x, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - x (float): a float that determines the x-coordinate of the first base point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the first base point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentBasePoint1X(self.sbml_object, str(reaction_id).encode(), x, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)


    def getSpeciesReferenceCurveSegmentBasePoint1Y(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """

        Returns the y-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentBasePoint1Y.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentBasePoint1Y(self, reaction_id, y, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the first base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - y (float): a float that determines the y-coordinate of the first base point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the first base point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(self.sbml_object, str(reaction_id).encode(), y, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentBasePoint2X(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the x-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentBasePoint2X.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentBasePoint2X(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentBasePoint2X(self, reaction_id, x, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the x-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - x (float): a float that determines the x-coordinate of the second base point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the second base point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentBasePoint2X(self.sbml_object, str(reaction_id).encode(), x, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def getSpeciesReferenceCurveSegmentBasePoint2Y(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns the y-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceCurveSegmentBasePoint2Y.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def setSpeciesReferenceCurveSegmentBasePoint2Y(self, reaction_id, y, reaction_glyph_index=0, species_reference_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Sets the y-coordinate of the second base point of the CurveSegment with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument

        :Parameters:

            - y (float): a float that determines the y-coordinate of the second base point of the CurveSegment
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the second base point of the CurveSegment could not be set
        """
        return lib.c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(self.sbml_object, str(reaction_id).encode(), y, reaction_glyph_index, species_reference_glyph_index, curve_segment_index, layout_index)

    def isSetSpeciesReferenceBorderColor(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns whether the border color of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the border color of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetSpeciesReferenceBorderColor(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getSpeciesReferenceBorderColor(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the border color of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the border color of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceBorderColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getSpeciesReferenceBorderColor(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def setSpeciesReferenceBorderColor(self, reaction_id, color, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Sets the border color of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - color (string): a string that determines the border color of the SpeciesReferenceGlyph
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the border color of the SpeciesReferenceGlyph could not be set
        """
        return lib.c_api_setSpeciesReferenceBorderColor(self.sbml_object, str(reaction_id).encode(), str(color).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def isSetSpeciesReferenceBorderWidth(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns whether the border width of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the border width of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetSpeciesReferenceBorderWidth(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getSpeciesReferenceBorderWidth(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the border width of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the border width of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceBorderWidth.restype = ctypes.c_double
        return lib.c_api_getSpeciesReferenceBorderWidth(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def setSpeciesReferenceBorderWidth(self, reaction_id, width, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Sets the border width of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - width (float): a float that determines the border width of the SpeciesReferenceGlyph
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the border width of the SpeciesReferenceGlyph could not be set
        """
        return lib.c_api_setSpeciesReferenceBorderWidth(self.sbml_object, str(reaction_id).encode(), width, reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getNumSpeciesReferenceBorderDashes(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the number of border dashes of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of border dashes of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        return lib.c_api_getNumSpeciesReferenceBorderDashes(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getSpeciesReferenceNthBorderDash(self, reaction_id, dash_index, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the dash at the given dash_index of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - dash_index (int): an integer that determines the index of the dash
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an int that determines the dash at the given dash_index of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        return lib.c_api_getSpeciesReferenceNthBorderDash(self.sbml_object, str(reaction_id).encode(), dash_index, reaction_glyph_index, species_reference_glyph_index, layout_index)

    def setSpeciesReferenceNthBorderDash(self, reaction_id, dash, dash_index, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Sets the dash at the given dash_index of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - dash (float): a float that determines the dash
            - dash_index (int): an integer that determines the index of the dash
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the dash at the given dash_index of the SpeciesReferenceGlyph could not be set
        """
        return lib.c_api_setSpeciesReferenceNthBorderDash(self.sbml_object, str(reaction_id).encode(), dash, dash_index, reaction_glyph_index, species_reference_glyph_index, layout_index)

    def isSetSpeciesReferenceStartHead(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns whether the start head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the start head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetSpeciesReferenceStartHead(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getSpeciesReferenceStartHead(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the start head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the start head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceStartHead.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getSpeciesReferenceStartHead(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def setSpeciesReferenceStartHead(self, reaction_id, head, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Sets the start head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - head (string): a string that determines the start head of the SpeciesReferenceGlyph
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the start head of the SpeciesReferenceGlyph could not be set
        """
        return lib.c_api_setSpeciesReferenceStartHead(self.sbml_object, str(reaction_id).encode(), str(head).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def isSetSpeciesReferenceEndHead(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns whether the end head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the end head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetSpeciesReferenceEndHead(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getSpeciesReferenceEndHead(self, reaction_id, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Returns the end head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the end head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getSpeciesReferenceEndHead.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getSpeciesReferenceEndHead(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)).value.decode()

    def setSpeciesReferenceEndHead(self, reaction_id, head, reaction_glyph_index=0, species_reference_glyph_index=0, layout_index=0):
        """
        Sets the end head of the SpeciesReferenceGlyph with the given reaction_id, reaction_glyph_index, species_reference_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - head (string): a string that determines the end head of the SpeciesReferenceGlyph
            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - species_reference_glyph_index (int): an integer that determines the index of the SpeciesReferenceGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the end head of the SpeciesReferenceGlyph could not be set
        """
        return lib.c_api_setSpeciesReferenceEndHead(self.sbml_object, str(reaction_id).encode(), str(head).encode(), reaction_glyph_index, species_reference_glyph_index, layout_index)

    def getNumAllTextGlyphs(self, layout_index=0):
        """
        Returns the number of TextGlyphs in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of TextGlyphs in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumAllTextGlyphs(self.sbml_object, layout_index)

    def getNumTextGlyphs(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the number of TextGlyphs associated with the given id in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of TextGlyphs associated with the given id in the Layout object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumTextGlyphs(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getText(self, id, graphical_object_index=0, text_glyph_index=0, layout_index=0):
        """
        Returns the text of the TextGlyph associated with the GraphicalObject associated with the given id, text_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - text_glyph_index (int): an integer that determines the index of the TextGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the text of the TextGlyph associated with the GraphicalObject associated with the given id, text_glyph_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getText.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getText(self.sbml_object, str(id).encode(), graphical_object_index, text_glyph_index, layout_index)).value.decode()

    def setText(self, id, text, graphical_object_index=0, text_glyph_index=0, layout_index=0):
        """
        Sets the text of the TextGlyph associated with the GraphicalObject associated with the given id, text_glyph_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text (string): a string that determines the text of the TextGlyph
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - text_glyph_index (int): an integer that determines the index of the TextGlyph in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the text of the TextGlyph could not be set
        """
        return lib.c_api_setText(self.sbml_object, str(id).encode(), str(text).encode(), graphical_object_index, text_glyph_index, layout_index)

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

    def isCurveSegmentCubicBezier(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
        """
        Returns whether the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument is a CubicBezier

        :Parameters:

            - reaction_id (string): a string that determines the id of the Reaction
            - reaction_glyph_index (int): an integer that determines the index of the ReactionGlyph in the given SBMLDocument
            - curve_segment_index (int): an integer that determines the index of the CurveSegment in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the CurveSegment with the given reaction_id, reaction_glyph_index, curve_segment_index, and layout_index in the given SBMLDocument is a CubicBezier and false otherwise
        """
        return lib.c_api_isCurveSegmentCubicBezier(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentStartPointX(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentStartPointX.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentStartPointX(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentStartPointX(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentStartPointX(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentStartPointY(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentStartPointY.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentStartPointY(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentStartPointY(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentStartPointY(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentEndPointX(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentEndPointX.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentEndPointX(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentEndPointX(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentEndPointX(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentEndPointY(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentEndPointY.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentEndPointY(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentEndPointY(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentEndPointY(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentBasePoint1X(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentBasePoint1X.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentBasePoint1X(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentBasePoint1X(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentBasePoint1X(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentBasePoint1Y(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentBasePoint1Y.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentBasePoint1Y(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentBasePoint1Y(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentBasePoint1Y(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentBasePoint2X(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentBasePoint2X.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentBasePoint2X(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentBasePoint2X(self, reaction_id, x, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentBasePoint2X(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(x), reaction_glyph_index, curve_segment_index, layout_index)

    def getCurveSegmentBasePoint2Y(self, reaction_id, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        lib.c_api_getCurveSegmentBasePoint2Y.restype = ctypes.c_double
        return lib.c_api_getCurveSegmentBasePoint2Y(self.sbml_object, str(reaction_id).encode(), reaction_glyph_index, curve_segment_index, layout_index)

    def setCurveSegmentBasePoint2Y(self, reaction_id, y, reaction_glyph_index=0, curve_segment_index=0, layout_index=0):
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
        return lib.c_api_setCurveSegmentBasePoint2Y(self.sbml_object, str(reaction_id).encode(), ctypes.c_double(y), reaction_glyph_index, curve_segment_index, layout_index)

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

    def createDefaultGlobalRenderInformation(self):
        """
        Creates a default GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the default GlobalRenderInformation object could not be created
        """
        return lib.c_api_createDefaultGlobalRenderInformation(self.sbml_object)

    def createDefaultLocalRenderInformation(self, layout_index=0):
        """
        Creates a default LocalRenderInformation object in the Layout object with the given index in the given SBMLDocument

        :Parameters:

            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the default LocalRenderInformation object could not be created
        """
        return lib.c_api_createDefaultLocalRenderInformation(self.sbml_object, layout_index)

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

    def getListOfColorIds(self, render_index=0):
        """
        Returns the list of ColorDefinition ids in the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a list of strings that determines the list of ColorDefinition ids in the RenderInformation object with the given index in the given SBMLDocument

        """
        lib.c_api_getNthGlobalColorId.restype = ctypes.c_char_p
        lib.c_api_getNthLocalColorId.restype = ctypes.c_char_p
        list_of_color_ids = []
        for n in range(lib.c_api_getNumGlobalColors(self.sbml_object, render_index)):
            list_of_color_ids.append(ctypes.c_char_p(lib.c_api_getNthGlobalColorId(self.sbml_object, n, render_index)).value.decode())
        for n in range(lib.c_api_getNumLocalColors(self.sbml_object, render_index)):
            list_of_color_ids.append(ctypes.c_char_p(lib.c_api_getNthLocalColorId(self.sbml_object, n, render_index)).value.decode())

        return list_of_color_ids

    def getNumColors(self, render_index=0):
        """
        Returns the number of ColorDefinition objects in the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of ColorDefinition objects in the RenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumColors(self.sbml_object, render_index)

    def getNumGlobalColors(self, render_index=0):
        """
        Returns the number of ColorDefinition objects in the GlobalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of ColorDefinition objects in the GlobalRenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumGlobalColors(self.sbml_object, render_index)

    def getNumLocalColors(self, render_index=0):
        """
        Returns the number of ColorDefinition objects in the LocalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the LocalRenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of ColorDefinition objects in the LocalRenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumLocalColors(self.sbml_object, render_index)

    def getNthGlobalColorId(self, index, render_index=0):
        """
        Returns the id of the ColorDefinition object with the given index in the GlobalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the ColorDefinition object in the GlobalRenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the id of the ColorDefinition object with the given index in the GlobalRenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGlobalColorId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthGlobalColorId(self.sbml_object, index, render_index)).value.decode()

    def getNthLocalColorId(self, index, render_index=0):
        """
        Returns the id of the ColorDefinition object with the given index in the LocalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the ColorDefinition object in the LocalRenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the LocalRenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the id of the ColorDefinition object with the given index in the LocalRenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthLocalColorId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthLocalColorId(self.sbml_object, index, render_index)).value.decode()

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

    def getListOfGradientIds(self, render_index=0):
        """
        Returns the list of GradientDefinition ids in the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a list of strings that determines the list of GradientDefinition ids in the RenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGlobalGradientId.restype = ctypes.c_char_p
        lib.c_api_getNthLocalGradientId.restype = ctypes.c_char_p
        list_of_gradient_ids = []
        for n in range(lib.c_api_getNumGlobalGradients(self.sbml_object, render_index)):
            list_of_gradient_ids.append(ctypes.c_char_p(lib.c_api_getNthGlobalGradientId(self.sbml_object, n, render_index)).value.decode())
        for n in range(lib.c_api_getNumLocalGradients(self.sbml_object, render_index)):
            list_of_gradient_ids.append(ctypes.c_char_p(lib.c_api_getNthLocalGradientId(self.sbml_object, n, render_index)).value.decode())

        return list_of_gradient_ids

    def getNumGradients(self, render_index=0):
        """
        Returns the number of GradientDefinition objects in the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GradientDefinition objects in the RenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumGradients(self.sbml_object, render_index)

    def getNumGlobalGradients(self, render_index=0):
        """
        Returns the number of GradientDefinition objects in the GlobalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GradientDefinition objects in the GlobalRenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumGlobalGradients(self.sbml_object, render_index)

    def getNumLocalGradients(self, render_index=0):
        """
        Returns the number of GradientDefinition objects in the LocalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the LocalRenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GradientDefinition objects in the LocalRenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumLocalGradients(self.sbml_object, render_index)

    def getNthGlobalGradientId(self, index, render_index=0):
        """
        Returns the id of the GradientDefinition object with the given index in the GlobalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the GradientDefinition object in the GlobalRenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the id of the GradientDefinition object with the given index in the GlobalRenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGlobalGradientId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthGlobalGradientId(self.sbml_object, index, render_index)).value.decode()

    def getNthLocalGradientId(self, index, render_index=0):
        """
        Returns the id of the GradientDefinition object with the given index in the LocalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the GradientDefinition object in the LocalRenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the LocalRenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the id of the GradientDefinition object with the given index in the LocalRenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthLocalGradientId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthLocalGradientId(self.sbml_object, index, render_index)).value.decode()

    def getListOfLineEndingIds(self, render_index=0):
        """
        Returns the list of LineEnding ids in the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a list of strings that determines the list of LineEnding ids in the RenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGlobalLineEndingId.restype = ctypes.c_char_p
        lib.c_api_getNthLocalLineEndingId.restype = ctypes.c_char_p
        list_of_line_ending_ids = []
        for n in range(lib.c_api_getNumGlobalLineEndings(self.sbml_object, render_index)):
            list_of_line_ending_ids.append(ctypes.c_char_p(lib.c_api_getNthGlobalLineEndingId(self.sbml_object, n, render_index)).value.decode())
        for n in range(lib.c_api_getNumLocalLineEndings(self.sbml_object, render_index)):
            list_of_line_ending_ids.append(ctypes.c_char_p(lib.c_api_getNthLocalLineEndingId(self.sbml_object, n, render_index)).value.decode())

        return list_of_line_ending_ids

    def getNumLineEndings(self, render_index=0):
        """
        Returns the number of LineEnding objects in the RenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of LineEnding objects in the RenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumLineEndings(self.sbml_object, render_index)

    def getNumGlobalLineEndings(self, render_index=0):
        """
        Returns the number of LineEnding objects in the GlobalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of LineEnding objects in the GlobalRenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumGlobalLineEndings(self.sbml_object, render_index)

    def getNumLocalLineEndings(self, render_index=0):
        """
        Returns the number of LineEnding objects in the LocalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - render_index (int, optional): an integer (default: 0) that determines the index of the LocalRenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of LineEnding objects in the LocalRenderInformation object with the given index in the given SBMLDocument
        """
        return lib.c_api_getNumLocalLineEndings(self.sbml_object, render_index)

    def getNthGlobalLineEndingId(self, index, render_index=0):
        """
        Returns the id of the LineEnding object with the given index in the GlobalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the LineEnding object in the GlobalRenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the GlobalRenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the id of the LineEnding object with the given index in the GlobalRenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthGlobalLineEndingId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthGlobalLineEndingId(self.sbml_object, index, render_index)).value.decode()

    def getNthLocalLineEndingId(self, index, render_index=0):
        """
        Returns the id of the LineEnding object with the given index in the LocalRenderInformation object with the given index in the given SBMLDocument

        :Parameters:

            - index (int): an integer that determines the index of the LineEnding object in the LocalRenderInformation object
            - render_index (int, optional): an integer (default: 0) that determines the index of the LocalRenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the id of the LineEnding object with the given index in the LocalRenderInformation object with the given index in the given SBMLDocument
        """
        lib.c_api_getNthLocalLineEndingId.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getNthLocalLineEndingId(self.sbml_object, index, render_index)).value.decode()

    def getLineEndingBoundingBoxX(self, line_ending_id, render_index=0):
        """
        Returns the x-coordinate of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingBoundingBoxX.restype = ctypes.c_double
        return lib.c_api_getLineEndingBoundingBoxX(self.sbml_object, str(line_ending_id).encode(), render_index)

    def setLineEndingBoundingBoxX(self, line_ending_id, x, render_index=0):
        """
        Sets the x-coordinate of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - x (float): a float that determines the x-coordinate of the bounding box of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the bounding box of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingBoundingBoxX(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(x), render_index)

    def getLineEndingBoundingBoxY(self, line_ending_id, render_index=0):
        """
        Returns the y-coordinate of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingBoundingBoxY.restype = ctypes.c_double
        return lib.c_api_getLineEndingBoundingBoxY(self.sbml_object, str(line_ending_id).encode(), render_index)

    def setLineEndingBoundingBoxY(self, line_ending_id, y, render_index=0):
        """
        Sets the y-coordinate of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - y (float): a float that determines the y-coordinate of the bounding box of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the bounding box of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingBoundingBoxY(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(y), render_index)

    def getLineEndingBoundingBoxWidth(self, line_ending_id, render_index=0):
        """
        Returns the width of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a float that determines the width of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingBoundingBoxWidth.restype = ctypes.c_double
        return lib.c_api_getLineEndingBoundingBoxWidth(self.sbml_object, str(line_ending_id).encode(), render_index)

    def setLineEndingBoundingBoxWidth(self, line_ending_id, width, render_index=0):
        """
        Sets the width of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - width (float): a float that determines the width of the bounding box of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the width of the bounding box of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingBoundingBoxWidth(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(width), render_index)

    def getLineEndingBoundingBoxHeight(self, line_ending_id, render_index=0):
        """
        Returns the height of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a float that determines the height of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingBoundingBoxHeight.restype = ctypes.c_double
        return lib.c_api_getLineEndingBoundingBoxHeight(self.sbml_object, str(line_ending_id).encode(), render_index)

    def setLineEndingBoundingBoxHeight(self, line_ending_id, height, render_index=0):
        """
        Sets the height of the bounding box of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - height (float): a float that determines the height of the bounding box of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the height of the bounding box of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingBoundingBoxHeight(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(height), render_index)

    def isSetLineEndingBorderColor(self, line_ending_id, render_index=0):
        """
        Returns whether the border color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true if the border color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingBorderColor(self.sbml_object, str(line_ending_id).encode(), render_index)

    def getLineEndingBorderColor(self, line_ending_id, render_index=0):
        """
        Returns the border color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the border color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingBorderColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getLineEndingBorderColor(self.sbml_object, str(line_ending_id).encode(), render_index)).value.decode()

    def setLineEndingBorderColor(self, line_ending_id, border_color, render_index=0):
        """
        Sets the border color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - border_color (string): a string that determines the border color of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the border color of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingBorderColor(self.sbml_object, str(line_ending_id).encode(), str(border_color).encode(), render_index)

    def isSetLineEndingBorderWidth(self, line_ending_id, render_index=0):
        """
        Returns whether the border width of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true if the border width of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingBorderWidth(self.sbml_object, str(line_ending_id).encode(), render_index)

    def getLineEndingBorderWidth(self, line_ending_id, render_index=0):
        """
        Returns the border width of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a float that determines the border width of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingBorderWidth.restype = ctypes.c_double
        return lib.c_api_getLineEndingBorderWidth(self.sbml_object, str(line_ending_id).encode(), render_index)

    def setLineEndingBorderWidth(self, line_ending_id, border_width, render_index=0):
        """
        Sets the border width of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - border_width (float): a float that determines the border width of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the border width of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingBorderWidth(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(border_width), render_index)

    def getNumLineEndingBorderDashes(self, line_ending_id, render_index=0):
        """
        Returns the number of border dashes of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of border dashes of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        return lib.c_api_getNumLineEndingBorderDashes(self.sbml_object, str(line_ending_id).encode(), render_index)

    def getLineEndingNthBorderDash(self, line_ending_id, index, render_index=0):
        """
        Returns the border dash with the given index of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - index (int): an integer that determines the index of the border dash in the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the border dash with the given index of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        """
        return lib.c_api_getLineEndingNthBorderDash(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingNthBorderDash(self, line_ending_id, index, border_dash, render_index=0):
        """
        Sets the border dash with the given index of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - index (int): an integer that determines the index of the border dash in the LineEnding object
            - border_dash (int): an integer that determines the border dash of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the border dash of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingNthBorderDash(self.sbml_object, str(line_ending_id).encode(), index, border_dash, render_index)

    def isSetLineEndingFillColor(self, line_ending_id, render_index=0):
        """
        Returns whether the fill color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true if the fill color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingFillColor(self.sbml_object, str(line_ending_id).encode(), render_index)

    def getLineEndingFillColor(self, line_ending_id, render_index=0):
        """
        Returns the fill color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the fill color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingFillColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getLineEndingFillColor(self.sbml_object, str(line_ending_id).encode(), render_index)).value.decode()

    def setLineEndingFillColor(self, line_ending_id, fill_color, render_index=0):
        """
        Sets the fill color of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - fill_color (string): a string that determines the fill color of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the fill color of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingFillColor(self.sbml_object, str(line_ending_id).encode(), str(fill_color).encode(), render_index)

    def isSetLineEndingFillRule(self, line_ending_id, render_index=0):
        """
        Returns whether the fill rule of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true if the fill rule of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingFillRule(self.sbml_object, str(line_ending_id).encode(), render_index)

    def getLineEndingFillRule(self, line_ending_id, render_index=0):
        """
        Returns the fill rule of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            a string that determines the fill rule of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingFillRule.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getLineEndingFillRule(self.sbml_object, str(line_ending_id).encode(), render_index)).value.decode()

    def setLineEndingFillRule(self, line_ending_id, fill_rule, render_index=0):
        """
        Sets the fill rule of the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - fill_rule (string): a string that determines the fill rule of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            true on success and false if the fill rule of the LineEnding object could not be set
        """
        return lib.c_api_setLineEndingFillRule(self.sbml_object, str(line_ending_id).encode(), str(fill_rule).encode(), render_index)

    def getNumLineEndingGeometricShapes(self, line_ending_id, render_index=0):
        """
        Returns the number of GeometricShape objects in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GeometricShape objects in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        return lib.c_api_getNumLineEndingGeometricShapes(self.sbml_object, str(line_ending_id).encode(), render_index)

    def isLineEndingRectangle(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a rectangle

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a rectangle and false otherwise
        """
        return lib.c_api_isLineEndingRectangle(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isLineEndingEllipse(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is an ellipse

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is an ellipse and false otherwise
        """
        return lib.c_api_isLineEndingEllipse(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isLineEndingPolygon(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a polygon

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a polygon and false otherwise
        """
        return lib.c_api_isLineEndingPolygon(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isLineEndingImage(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is an image

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is an image and false otherwise
        """
        return lib.c_api_isLineEndingImage(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isLineEndingRenderCurve(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a render curve

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a render curve and false otherwise
        """
        return lib.c_api_isLineEndingRenderCurve(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isLineEndingText(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is text

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is text and false otherwise
        """
        return lib.c_api_isLineEndingText(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isSetLineEndingGeometricShapeX(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the x-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the x-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeX(self, line_ending_id, index=0, render_index=0):
        """
        Returns the x-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the x-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeX.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeX(self, line_ending_id, x, index=0, render_index=0):
        """
        Sets the x-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - x (float): a float that determines the x-coordinate of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the x-coordinate of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeX(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(x), index, render_index)

    def isSetLineEndingGeometricShapeY(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the y-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the y-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeY(self, line_ending_id, index=0, render_index=0):
        """
        Returns the y-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the y-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeY.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeY(self, line_ending_id, y, index=0, render_index=0):
        """
        Sets the y-coordinate of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - y (float): a float that determines the y-coordinate of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the y-coordinate of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeY(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(y), index, render_index)

    def isSetLineEndingGeometricShapeWidth(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the width of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the width of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeWidth(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeWidth(self, line_ending_id, index=0, render_index=0):
        """
        Returns the width of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the width of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeWidth.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeWidth(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeWidth(self, line_ending_id, width, index=0, render_index=0):
        """
        Sets the width of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - width (float): a float that determines the width of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the width of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeWidth(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(width), index, render_index)

    def isSetLineEndingGeometricShapeHeight(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the height of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the height of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeHeight(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeHeight(self, line_ending_id, index=0, render_index=0):
        """
        Returns the height of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the height of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeHeight.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeHeight(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeHeight(self, line_ending_id, height, index=0, render_index=0):
        """
        Sets the height of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - height (float): a float that determines the height of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the height of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeHeight(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(height), index, render_index)

    def isSetLineEndingGeometricShapeRatio(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the ratio of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the ratio of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeRatio(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeRatio(self, line_ending_id, index=0, render_index=0):
        """
        Returns the ratio of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the ratio of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeRatio.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeRatio(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeRatio(self, line_ending_id, ratio, index=0, render_index=0):
        """
        Sets the ratio of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - ratio (float): a float that determines the ratio of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the ratio of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeRatio(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(ratio), index, render_index)

    def isSetLineEndingGeometricShapeBorderRadiusX(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the x-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the x-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeBorderRadiusX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeBorderRadiusX(self, line_ending_id, index=0, render_index=0):
        """
        Returns the x-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the x-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeBorderRadiusX.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeBorderRadiusX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeBorderRadiusX(self, line_ending_id, x_radius, index=0, render_index=0):
        """
        Sets the x-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - x_radius (float): a float that determines the x-radius of the border of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the x-radius of the border of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeBorderRadiusX(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(x_radius), index, render_index)

    def isSetLineEndingGeometricShapeBorderRadiusY(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the y-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the y-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeBorderRadiusY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeBorderRadiusY(self, line_ending_id, index=0, render_index=0):
        """
        Returns the y-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the y-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeBorderRadiusY.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeBorderRadiusY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeBorderRadiusY(self, line_ending_id, y_radius, index=0, render_index=0):
        """
        Sets the y-radius of the border of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - y_radius (float): a float that determines the y-radius of the border of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the y-radius of the border of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeBorderRadiusY(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(y_radius), index, render_index)

    def isSetLineEndingGeometricShapeCenterX(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the x-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the x-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeCenterX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeCenterX(self, line_ending_id, index=0, render_index=0):
        """
        Returns the x-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the x-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeCenterX.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeCenterX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeCenterX(self, line_ending_id, center_x, index=0, render_index=0):
        """
        Sets the x-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - center_x (float): a float that determines the x-coordinate of the center of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the x-coordinate of the center of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeCenterX(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(center_x), index, render_index)

    def isSetLineEndingGeometricShapeCenterY(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the y-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the y-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeCenterY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeCenterY(self, line_ending_id, index=0, render_index=0):
        """
        Returns the y-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the y-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeCenterY.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeCenterY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeCenterY(self, line_ending_id, center_y, index=0, render_index=0):
        """
        Sets the y-coordinate of the center of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - center_y (float): a float that determines the y-coordinate of the center of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the y-coordinate of the center of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeCenterY(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(center_y), render_index, index)

    def isSetLineEndingGeometricShapeRadiusX(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the x-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the x-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeRadiusX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeRadiusX(self, line_ending_id, index=0, render_index=0):
        """
        Returns the x-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the x-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeRadiusX.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeRadiusX(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeRadiusX(self, line_ending_id, radius_x, index=0, render_index=0):
        """
        Sets the x-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - radius_x (float): a float that determines the x-radius of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the x-radius of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeRadiusX(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(radius_x), index, render_index)

    def isSetLineEndingGeometricShapeRadiusY(self, line_ending_id, index=0, render_index=0):
        """
        Returns whether the y-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the y-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetLineEndingGeometricShapeRadiusY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def getLineEndingGeometricShapeRadiusY(self, line_ending_id, index=0, render_index=0):
        """
        Returns the y-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the y-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeRadiusY.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeRadiusY(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def setLineEndingGeometricShapeRadiusY(self, line_ending_id, radius_y, index=0, render_index=0):
        """
        Sets the y-radius of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - radius_y (float): a float that determines the y-radius of the GeometricShape object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the y-radius of the GeometricShape object could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeRadiusY(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(radius_y), render_index, index)

    def getLineEndingGeometricShapeNumSegments(self, line_ending_id, index=0, render_index=0):
        """
        Returns the number of segments of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            an integer that determines the number of segments of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        return lib.c_api_getLineEndingGeometricShapeNumSegments(self.sbml_object, str(line_ending_id).encode(), index, render_index)

    def isLineEndingGeometricShapeSegmentCubicBezier(self, line_ending_id, segment_index, index=0, render_index=0):
        """
        Returns whether the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a cubic bezier segment

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true if the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument is a cubic bezier segment and false otherwise
        """
        return lib.c_api_isLineEndingGeometricShapeSegmentCubicBezier(self.sbml_object, str(line_ending_id).encode(), segment_index, index, render_index)

    def getLineEndingGeometricShapeSegmentX(self, line_ending_id, segment_index, index=0, render_index=0):
        """
        Returns the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeSegmentX.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeSegmentX(self.sbml_object, str(line_ending_id).encode(), segment_index, index, render_index)

    def setLineEndingGeometricShapeSegmentX(self, line_ending_id, segment_index, x, index=0, render_index=0):
        """
        Sets the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - x (float): a float that determines the x-coordinate of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the x-coordinate of the segment could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeSegmentX(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(x), segment_index, index, render_index)

    def getLineEndingGeometricShapeSegmentY(self, line_ending_id, segment_index, index=0, render_index=0):
        """
        Returns the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeSegmentY.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeSegmentY(self.sbml_object, str(line_ending_id).encode(), segment_index, index, render_index)

    def setLineEndingGeometricShapeSegmentY(self, line_ending_id, y, segment_index, index=0, render_index=0):
        """
        Sets the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - y (float): a float that determines the y-coordinate of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the y-coordinate of the segment could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeSegmentY(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(y), segment_index, index, render_index)

    def getLineEndingGeometricShapeBasePoint1X(self, line_ending_id, segment_index, index=0, render_index=0):
        """
        Returns the x-coordinate of the first base point of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the x-coordinate of the first base point of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeBasePoint1X.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeBasePoint1X(self.sbml_object, str(line_ending_id).encode(), segment_index, index, render_index)

    def setLineEndingGeometricShapeBasePoint1X(self, line_ending_id, segment_index, x, index=0, render_index=0):
        """
        Sets the x-coordinate of the first base point of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - x (float): a float that determines the x-coordinate of the first base point of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the x-coordinate of the first base point of the segment could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeBasePoint1X(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(x), segment_index, index, render_index)

    def getLineEndingGeometricShapeBasePoint1Y(self, line_ending_id, segment_index, index=0, render_index=0):
        """
        Returns the y-coordinate of the first base point of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            a float that determines the y-coordinate of the first base point of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument
        """
        lib.c_api_getLineEndingGeometricShapeBasePoint1Y.restype = ctypes.c_double
        return lib.c_api_getLineEndingGeometricShapeBasePoint1Y(self.sbml_object, str(line_ending_id).encode(), segment_index, index, render_index)

    def setLineEndingGeometricShapeBasePoint1Y(self, line_ending_id, y, segment_index, index=0, render_index=0):
        """
        Sets the y-coordinate of the first base point of the segment with the given segment_index of the GeometricShape object with the given index in the LineEnding object with the given line_ending_id and render_index in the given SBMLDocument

        :Parameters:

            - line_ending_id (string): a string that determines the id of the LineEnding object
            - segment_index (int): an integer that determines the index of the segment
            - y (float): a float that determines the y-coordinate of the first base point of the segment
            - render_index (int, optional): an integer (default: 0) that determines the index of the RenderInformation object in the given SBMLDocument
            - index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object in the LineEnding object

        :Returns:

            true on success and false if the y-coordinate of the first base point of the segment could not be set
        """
        return lib.c_api_setLineEndingGeometricShapeBasePoint1Y(self.sbml_object, str(line_ending_id).encode(), ctypes.c_double(y), segment_index, index, render_index)

    def isSetBorderColor(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the border color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the border color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetBorderColor(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getBorderColor(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the border color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the border color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getBorderColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getBorderColor(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setBorderColor(self, id, border_color, graphical_object_index=0, layout_index=0):
        """
        Sets the border color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_color (string): a string that determines the border color of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the border color of the GraphicalObject could not be set
        """
        return lib.c_api_setBorderColor(self.sbml_object, str(id).encode(), str(border_color).encode(), graphical_object_index, layout_index)

    def isSetBorderWidth(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the border width of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the border width of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetBorderWidth(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getBorderWidth(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the border width of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the border width of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getBorderWidth.restype = ctypes.c_double
        return lib.c_api_getBorderWidth(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def setBorderWidth(self, id, border_width, graphical_object_index=0, layout_index=0):
        """
        Sets the border width of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_width (float): a float that determines the border width of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the border width of the GraphicalObject could not be set
        """
        return lib.c_api_setBorderWidth(self.sbml_object, str(id).encode(), ctypes.c_double(border_width), graphical_object_index, layout_index)

    def getNumBorderDashes(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the number of border dashes of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of border dashes of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        return lib.c_api_getNumBorderDashes(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getNthBorderDash(self, id, border_dash_index, graphical_object_index=0, layout_index=0):
        """
        Returns the border dash with the given border_dash_index of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_dash_index (int): an integer that determines the index of the border dash
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the border dash with the given border_dash_index of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        return lib.c_api_getNthBorderDash(self.sbml_object, str(id).encode(), border_dash_index, graphical_object_index, layout_index)

    def setNthBorderDash(self, id, dash, border_dash_index, graphical_object_index=0, layout_index=0):
        """
        Sets the border dash with the given border_dash_index of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - dash (int): an int that determines the border dash
            - border_dash_index (int): an integer that determines the index of the border dash
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the border dash could not be set
        """
        return lib.c_api_setNthBorderDash(self.sbml_object, str(id).encode(), dash, border_dash_index, graphical_object_index, layout_index)

    def isSetFillColor(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the fill color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the fill color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFillColor(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getFillColor(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the fill color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the fill color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFillColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFillColor(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setFillColor(self, id, fill_color, graphical_object_index=0, layout_index=0):
        """
        Sets the fill color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - fill_color (string): a string that determines the fill color of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the fill color of the GraphicalObject could not be set
        """
        return lib.c_api_setFillColor(self.sbml_object, str(id).encode(), str(fill_color).encode(), graphical_object_index, layout_index)

    def isSetFillRule(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the fill rule of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the fill rule of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFillRule(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getFillRule(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the fill rule of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the fill rule of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFillRule.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFillRule(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setFillRule(self, id, fill_rule, graphical_object_index=0, layout_index=0):
        """
        Sets the fill rule of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - fill_rule (string): a string that determines the fill rule of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the fill rule of the GraphicalObject could not be set
        """
        return lib.c_api_setFillRule(self.sbml_object, str(id).encode(), str(fill_rule).encode(), graphical_object_index, layout_index)

    def isSetFontColor(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the font color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the font color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontColor(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getFontColor(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the font color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the font color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFontColor.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontColor(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setFontColor(self, id, font_color, graphical_object_index=0, layout_index=0):
        """
        Sets the font color of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_color (string): a string that determines the font color of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the font color of the GraphicalObject could not be set
        """
        return lib.c_api_setFontColor(self.sbml_object, str(id).encode(), str(font_color).encode(), graphical_object_index, layout_index)

    def isSetFontFamily(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the font family of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the font family of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontFamily(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getFontFamily(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the font family of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the font family of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFontFamily.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontFamily(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setFontFamily(self, id, font_family, graphical_object_index=0, layout_index=0):
        """
        Sets the font family of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_family (string): a string that determines the font family of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the font family of the GraphicalObject could not be set
        """
        return lib.c_api_setFontFamily(self.sbml_object, str(id).encode(), str(font_family).encode(), graphical_object_index, layout_index)

    def isSetFontSize(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the font size of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the font size of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontSize(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getFontSize(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the font size of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the font size of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFontSize.restype = ctypes.c_double
        return lib.c_api_getFontSize(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def setFontSize(self, id, font_size, graphical_object_index=0, layout_index=0):
        """
        Sets the font size of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_size (float): a float that determines the font size of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the font size of the GraphicalObject could not be set
        """
        return lib.c_api_setFontSize(self.sbml_object, str(id).encode(), ctypes.c_double(font_size), graphical_object_index, layout_index)

    def isSetFontWeight(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the font weight of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the font weight of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontWeight(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getFontWeight(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the font weight of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the font weight of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFontWeight.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontWeight(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setFontWeight(self, id, font_weight, graphical_object_index=0, layout_index=0):
        """
        Sets the font weight of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_weight (string): a string that determines the font weight of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the font weight of the GraphicalObject could not be set
        """
        return lib.c_api_setFontWeight(self.sbml_object, str(id).encode(), str(font_weight).encode(), graphical_object_index, layout_index)

    def isSetFontStyle(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the font style of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the font style of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetFontStyle(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)


    def getFontStyle(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the font style of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the font style of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getFontStyle.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getFontStyle(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setFontStyle(self, id, font_style, graphical_object_index=0, layout_index=0):
        """
        Sets the font style of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - font_style (string): a string that determines the font style of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the font style of the GraphicalObject could not be set
        """
        return lib.c_api_setFontStyle(self.sbml_object, str(id).encode(), str(font_style).encode(), graphical_object_index, layout_index)

    def isSetTextHorizontalAlignment(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the text horizontal alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the text horizontal alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetTextHorizontalAlignment(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getTextHorizontalAlignment(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the text horizontal alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the text horizontal alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getTextHorizontalAlignment.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getTextHorizontalAlignment(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setTextHorizontalAlignment(self, id, text_horizontal_alignment, graphical_object_index=0, layout_index=0):
        """
        Sets the text horizontal alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text_horizontal_alignment (string): a string that determines the text horizontal alignment of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the text horizontal alignment of the GraphicalObject could not be set
        """
        return lib.c_api_setTextHorizontalAlignment(self.sbml_object, str(id).encode(), str(text_horizontal_alignment).encode(), graphical_object_index, layout_index)

    def isSetTextVerticalAlignment(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the text vertical alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the text vertical alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetTextVerticalAlignment(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getTextVerticalAlignment(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the text vertical alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the text vertical alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getTextVerticalAlignment.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getTextVerticalAlignment(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setTextVerticalAlignment(self, id, text_vertical_alignment, graphical_object_index=0, layout_index=0):
        """
        Sets the text vertical alignment of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - text_vertical_alignment (string): a string that determines the text vertical alignment of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the text vertical alignment of the GraphicalObject could not be set
        """
        return lib.c_api_setTextVerticalAlignment(self.sbml_object, str(id).encode(), str(text_vertical_alignment).encode(), graphical_object_index, layout_index)

    def isSetStartHead(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the start head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the start head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetStartHead(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getStartHead(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the start head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the start head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getStartHead.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getStartHead(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setStartHead(self, id, start_head, graphical_object_index=0, layout_index=0):
        """
        Sets the start head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - start_head (string): a string that determines the start head of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the start head of the GraphicalObject could not be set
        """
        return lib.c_api_setStartHead(self.sbml_object, str(id).encode(), str(start_head).encode(), graphical_object_index, layout_index)

    def isSetEndHead(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns whether the end head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the end head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetEndHead(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)

    def getEndHead(self, id, graphical_object_index=0, layout_index=0):
        """
        Returns the end head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the end head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument
        """
        lib.c_api_getEndHead.restype = ctypes.c_char_p
        return ctypes.c_char_p(lib.c_api_getEndHead(self.sbml_object, str(id).encode(), graphical_object_index, layout_index)).value.decode()

    def setEndHead(self, id, end_head, graphical_object_index=0, layout_index=0):
        """
        Sets the end head of the GraphicalObject associated with the model entity with the given id, graphical_object_index, and layout_index in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - end_head (string): a string that determines the end head of the GraphicalObject
            - graphical_object_index (int): an integer that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the end head of the GraphicalObject could not be set
        """
        return lib.c_api_setEndHead(self.sbml_object, str(id).encode(), str(end_head).encode(), graphical_object_index, layout_index)

    def getNumGeometricShapes(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the number of GeometricShape objects associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of GeometricShape objects associated with the model entity with the given id in the given SBMLDocument
        """
        return lib.c_api_getNumGeometricShapes(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isRectangle(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Rectangle object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Rectangle object and false otherwise
        """
        return lib.c_api_isRectangle(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isEllipse(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Ellipse object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Ellipse object and false otherwise
        """
        return lib.c_api_isEllipse(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isPolygon(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Polygon object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Polygon object and false otherwise
        """
        return lib.c_api_isPolygon(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isImage(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Image object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is an Image object and false otherwise
        """
        return lib.c_api_isImage(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isRenderCurve(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a RenderCurve object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a RenderCurve object and false otherwise
        """
        return lib.c_api_isRenderCurve(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isText(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Text object

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a Text object and false otherwise
        """
        return lib.c_api_isText(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeX(self, id, x, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeX(self.sbml_object, str(id).encode(), ctypes.c_double(x), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeY(self, id, y, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-coordinate of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeY(self.sbml_object, str(id).encode(), ctypes.c_double(y), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeWidth(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeWidth(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeWidth(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeWidth.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeWidth(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeWidth(self, id, width, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the width of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - width (float): a float that determines the width of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the width of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeWidth(self.sbml_object, str(id).encode(), ctypes.c_double(width), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeHeight(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeHeight(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeHeight(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeHeight.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeHeight(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeHeight(self, id, height, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the height of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - height (float): a float that determines the height of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the height of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeHeight(self.sbml_object, str(id).encode(), ctypes.c_double(height), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeRatio(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeRatio(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeRatio(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeRatio.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeRatio(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeRatio(self, id, ratio, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the ratio of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - ratio (float): a float that determines the ratio of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the ratio of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeRatio(self.sbml_object, str(id).encode(), ctypes.c_double(ratio), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeBorderRadiusX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeBorderRadiusX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeBorderRadiusX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeBorderRadiusX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeBorderRadiusX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeBorderRadiusX(self, id, border_radius_x, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_radius_x (float): a float that determines the x-radius of the border of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-radius of the border of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeBorderRadiusX(self.sbml_object, str(id).encode(), ctypes.c_double(border_radius_x), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeBorderRadiusY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeBorderRadiusY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeBorderRadiusY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeBorderRadiusY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeBorderRadiusY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeBorderRadiusY(self, id, border_radius_y, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-radius of the border of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - border_radius_y (float): a float that determines the y-radius of the border of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-radius of the border of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeBorderRadiusY(self.sbml_object, str(id).encode(), ctypes.c_double(border_radius_y), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeCenterX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeCenterX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeCenterX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeCenterX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeCenterX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeCenterX(self, id, center_x, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - center_x (float): a float that determines the x-coordinate of the center of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the center of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeCenterX(self.sbml_object, str(id).encode(), ctypes.c_double(center_x), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeCenterY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeCenterY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeCenterY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeCenterY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeCenterY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeCenterY(self, id, center_y, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-coordinate of the center of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - center_y (float): a float that determines the y-coordinate of the center of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the center of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeCenterY(self.sbml_object, str(id).encode(), ctypes.c_double(center_y), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeRadiusX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeRadiusX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeRadiusX(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeRadiusX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeRadiusX(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeRadiusX(self, id, radius_x, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - radius_x (float): a float that determines the x-radius of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-radius of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeRadiusX(self.sbml_object, str(id).encode(), ctypes.c_double(radius_x), geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeRadiusY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeRadiusY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeRadiusY(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeRadiusY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeRadiusY(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeRadiusY(self, id, radius_y, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-radius of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - radius_y (float): a float that determines the y-radius of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-radius of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeRadiusY(self.sbml_object, str(id).encode(), ctypes.c_double(radius_y), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeNumSegments(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the number of segments of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            an integer that determines the number of segments of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        return lib.c_api_getGeometricShapeNumSegments(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def isGeometricShapeSegmentCubicBezier(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a cubic bezier segment

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is a cubic bezier segment and false otherwise
        """
        return lib.c_api_isGeometricShapeSegmentCubicBezier(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeSegmentX(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentX.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentX(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeSegmentX(self, id, x, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the segment of the GeometricShape object
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentX(self.sbml_object, str(id).encode(), ctypes.c_double(x), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeSegmentY(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentY.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentY(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeSegmentY(self, id, y, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-coordinate of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the segment of the GeometricShape object
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentY(self.sbml_object, str(id).encode(), ctypes.c_double(y), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeSegmentBasePoint1X(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint1X.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint1X(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeSegmentBasePoint1X(self, id, x, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the base point 1 of the segment of the GeometricShape object
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the base point 1 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint1X(self.sbml_object, str(id).encode(), ctypes.c_double(x), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeSegmentBasePoint1Y(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint1Y.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint1Y(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeSegmentBasePoint1Y(self, id, y, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-coordinate of the base point 1 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the base point 1 of the segment of the GeometricShape object
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the base point 1 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint1Y(self.sbml_object, str(id).encode(), ctypes.c_double(y), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeSegmentBasePoint2X(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the x-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the x-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint2X.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint2X(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeSegmentBasePoint2X(self, id, x, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the x-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - x (float): a float that determines the x-coordinate of the base point 2 of the segment of the GeometricShape object
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the x-coordinate of the base point 2 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint2X(self.sbml_object, str(id).encode(), ctypes.c_double(x), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeSegmentBasePoint2Y(self, id, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the y-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a float that determines the y-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeSegmentBasePoint2Y.restype = ctypes.c_double
        return lib.c_api_getGeometricShapeSegmentBasePoint2Y(self.sbml_object, str(id).encode(), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def setGeometricShapeSegmentBasePoint2Y(self, id, y, segment_index=0, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the y-coordinate of the base point 2 of the segment with the given segment_index of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - y (float): a float that determines the y-coordinate of the base point 2 of the segment of the GeometricShape object
            - segment_index (int): an integer that determines the index of the segment of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the y-coordinate of the base point 2 of the segment of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeSegmentBasePoint2Y(self.sbml_object, str(id).encode(), ctypes.c_double(y), segment_index, geometric_shape_index, graphical_object_index, layout_index)

    def isSetGeometricShapeHref(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns whether the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true if the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument is set and false otherwise
        """
        return lib.c_api_isSetGeometricShapeHref(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def getGeometricShapeHref(self, id, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Returns the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            a string that determines the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument
        """
        lib.c_api_getGeometricShapeHref.restype = ctypes.c_char_p
        return lib.c_api_getGeometricShapeHref(self.sbml_object, str(id).encode(), geometric_shape_index, graphical_object_index, layout_index).decode()

    def setGeometricShapeHref(self, id, href, geometric_shape_index=0, graphical_object_index=0, layout_index=0):
        """
        Sets the href of the GeometricShape object with the given index associated with the model entity with the given id in the given SBMLDocument

        :Parameters:

            - id (string): a string that determines the id of the model entity
            - href (string): a string that determines the href of the GeometricShape object
            - geometric_shape_index (int, optional): an integer (default: 0) that determines the index of the GeometricShape object associated with the model entity with the given id in the given SBMLDocument
            - graphical_object_index (int, optional): an integer (default: 0) that determines the index of the GraphicalObject in the given SBMLDocument
            - layout_index (int, optional): an integer (default: 0) that determines the index of the Layout object in the given SBMLDocument

        :Returns:

            true on success and false if the href of the GeometricShape object could not be set
        """
        return lib.c_api_setGeometricShapeHref(self.sbml_object, str(id).encode(), str(href).encode(), geometric_shape_index, graphical_object_index, layout_index)

    def _layout_is_specified(self):
        if self.getNumLayouts():
            return True

        return False

    def _render_is_specified(self):
        if self.getNumGlobalRenderInformation() or self.getNumLocalRenderInformation():
            return True

        return False





