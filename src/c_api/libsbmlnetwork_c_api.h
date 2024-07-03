#ifndef __LIBSBMLNETWORK_C_API_H_
#define __LIBSBMLNETWORK_C_API_H_

#include "../libsbmlnetwork_sbmldocument.h"
#include "../libsbmlnetwork_sbmldocument_layout.h"
#include "../libsbmlnetwork_sbmldocument_render.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    /// @brief Returns the version of the library.
    /// @return the version of the library.
    LIBSBMLNETWORK_EXTERN const char* c_api_getVersion();

    /// @brief Reads an SBML document from the given file name or the given text string
    /// @param sbml either the name or full pathname of the file to be read or a string containing a full SBML model.
    /// @return a pointer to the SBMLDocument structure created from the SBML content in the given file name or
    /// from the SBML content in the given text string.
    LIBSBMLNETWORK_EXTERN SBMLDocument* c_api_readSBML(const char* sbml);

    /// @brief Writes the given SBML document to a filename.
    /// @param document the SBML document to be written.
    /// @param fileName the name or full pathname of the file where the SBML is to be written.
    /// @return true on success and false if the filename could not be opened for writing.
    LIBSBMLNETWORK_EXTERN bool c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName);

    /// @brief Writes the given SBML document to a string and returns it.
    /// @param document the SBML document to be written.
    /// @return the string on success and empty string if one of the underlying parser components fail.
    LIBSBMLNETWORK_EXTERN const char* c_api_writeSBMLToString(SBMLDocument* document);

    /// @brief Returns the SBML Level of the SBMLDocument object containing this object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the SBML Level of the SBMLDocument object containing this object.
    LIBSBMLNETWORK_EXTERN int c_api_getSBMLLevel(SBMLDocument* document);

    /// @brief Returns the Version within the SBML Level of the SBMLDocument object containing this object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the Version within the SBML Level of the SBMLDocument object containing this object.
    LIBSBMLNETWORK_EXTERN int c_api_getSBMLVersion(SBMLDocument* document);

    /// @brief Free the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return boolean value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN bool c_api_freeSBMLDocument(SBMLDocument* document);

    /// @brief Returns true if the Model object has been set, otherwise returns false.
    /// @param document a pointer to the SBMLDocument object.
    /// @return true if the Model object has been set, otherwise returns false.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetModel(SBMLDocument* document);

    /// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
    /// to the the SBML document, and set all the necessary features for them.
    /// @param document a pointer to the SBMLDocument object.
    /// @param stiffness the stiffness value used in the autolayout algorithm.
    /// @param gravity the gravity value used in the autolayout algorithm.
    /// @param useMagnetism a variable that determines whether to use magnetism in the autolayout algorithm.
    /// @param useBoundary a variable that determines whether to use boundary restriction in the autolayout algorithm.
    /// @param useGrid a variable that determines whether to use grid restriction in the autolayout algorithm.
    /// @param useNameAsTextLabel a variable that determines whether to use the name of the nodes as text labels in the autolayout algorithm.
    /// @param lockedNodeIds an array of strings containing the ids of the nodes that should be locked in the autolayout algorithm.
    /// @param lockedNodesSize the size of lockedNodeIds
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_autolayout(SBMLDocument* document, const double stiffness = 10.0, const double gravity = 15.0,
                                                bool useMagnetism = false, bool useBoundary = false, bool useGrid = false,
                                                bool useNameAsTextLabel = true, const char** lockedNodeIds = NULL, const int lockedNodesSize = 0);

    /// @brief Align the nodes position in the SBML document in the given alignment type.
    /// @param document a pointer to the SBMLDocument object.
    /// @param nodeIds an array of strings containing the ids of the nodes that should be aligned.
    /// @param nodesSize the size of nodeIds
    /// @param alignment determines how to align the nodes.
    /// @param isLayoutAdded a variable that determines whether layout info is added after sbml document is loaded.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_align(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* alignment, bool isLayoutAdded = true);

    /// @brief Distribute the nodes position in the SBML document in the given direction.
    /// @param document a pointer to the SBMLDocument object.
    /// @param nodeIds an array of strings containing the ids of the nodes that should be distributed.
    /// @param nodesSize the size of nodeIds
    /// @param direction determines how to distribute the nodes.
    /// @param spacing the spacing between the distributed nodes.
    /// @param isLayoutAdded a variable that determines whether layout info is added after sbml document is loaded.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_distribute(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* direction, const double spacing = -1.0, bool isLayoutAdded = true);

    /// @brief Returns the number of items in the ListOfLayouts of this SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of items in of this SBML document, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLayouts(SBMLDocument* document);

    /// @brief Remove all the layout objects from the list of layouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeLayouts(SBMLDocument* document);

    /// @brief Create a Layout object, add it to list of layouts of the SBML document, and
    /// set all the necessary features for it
    /// @param document a pointer to the SBMLDocument object.
    /// @param stiffness the stiffness value used in the autolayout algorithm.
    /// @param gravity the gravity value used in the autolayout algorithm.
    /// @param useMagnetism a variable that determines whether to use magnetism in the autolayout algorithm.
    /// @param useBoundary a variable that determines whether to use boundary restriction in the autolayout algorithm.
    /// @param useGrid a variable that determines whether to use grid restriction in the autolayout algorithm.
    /// @param useNameAsTextLabel a variable that determines whether to use the name of the nodes as text labels in the autolayout algorithm.
    /// @param lockedNodesSize the size of lockedNodeIds
    /// @param lockedNodeIds an array of strings containing the ids of the nodes that should be locked in the autolayout algorithm.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createDefaultLayout(SBMLDocument* document, const double stiffness = 10.0, const double gravity = 15.0,
                                                               bool useMagnetism = false, bool useBoundary = false, bool useGrid = false,
                                                               bool useNameAsTextLabel= true, const char** lockedNodeIds = NULL, const int lockedNodesSize = 0);

    /// @brief Returns the value of the "width" attribute of the Dimensions object of the Layout object
    /// with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "width" attribute of the Dimensions object of the Layout object.
    LIBSBMLNETWORK_EXTERN double c_api_getCanvasWidth(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCanvasWidth(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "height" attribute of the Dimensions object of the Layout object.
    LIBSBMLNETWORK_EXTERN double c_api_getCanvasHeight(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCanvasHeight(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of GraphicalObjects of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllGraphicalObjects(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the number of GraphicalObject objects associated with it is going to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of GraphicalObject objects associated with the entered model entity id,
    /// or @c 0 if the object is @c NULL or has no associated GraphicalObject objects
    LIBSBMLNETWORK_EXTERN const int c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex = 0);

    /// @brief Returns the id of the nth GraphicalObject associated with the given model entity id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the id of the GraphicalObject associated with it is going to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the nth GraphicalObject associated with the given model entity id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthGraphicalObjectId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex = 0);

    /// @brief Returns the meta id of the nth GraphicalObject associated with the given model entity id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the id of the GraphicalObject associated with it is going to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the meta id of the nth GraphicalObject associated with the given model entity id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthGraphicalObjectMetaId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex = 0);

    /// @brief Returns the number of Compartment objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Compartment objects in the given SBML document.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumCompartments(SBMLDocument* document);

    /// @brief Returns the id of the nth Compartment object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param compartmentIndex the index of the Compartment object.
    /// @return the id of the nth Compartment object in the given SBML document, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthCompartmentId(SBMLDocument* document, int compartmentIndex);

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns a list of the ids of the CompartmentGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return a list of the ids of the CompartmentGlyph objects of this Layout object, or an empty list if the object is @c NULL or contains
    /// no CompartmentGlyph objects
    LIBSBMLNETWORK_EXTERN char** c_api_getListOfCompartmentGlyphIds(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered compartment id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
    /// @return the number of CompartmentGlyph objects associated with the entered compartment id,
    /// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
    LIBSBMLNETWORK_EXTERN const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0);

    /// @brief Returns the id of the nth CompartmentGlyph associated with the given compartment id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param compartmentId the id of the compartment the id of the CompartmentGlyph object associated with it is going to be returned.
    /// @param compartmentGlyphIndex the index of the CompartmentGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the nth CompartmentGlyph associated with the given compartment id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthCompartmentGlyphId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex = 0);

    /// @brief Returns the meta id of the nth CompartmentGlyph associated with the given compartment id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param compartmentId the id of the compartment the id of the CompartmentGlyph object associated with it is going to be returned.
    /// @param compartmentGlyphIndex the index of the CompartmentGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the meta id of the nth CompartmentGlyph associated with the given compartment id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthCompartmentGlyphMetaId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex = 0);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type CompartmentGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0);

    /// @breif Returns the id of the compartment associated with the given GraphicalObject with the given id in the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the GraphicalObject.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the compartment associated with the given GraphicalObject, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentId(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of Species objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Species objects in the given SBML document.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpecies(SBMLDocument* document);

    /// @brief Returns the id of the nth Species object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesIndex the index of the Species object.
    /// @return the id of the nth Species object in the given SBML document, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthSpeciesId(SBMLDocument* document, int speciesIndex);

    /// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of SpeciesGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered species id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
    /// @return the number of SpeciesGlyph objects associated with the entered species id,
    /// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex);

    /// @brief Returns the id of the nth SpeciesGlyph object associated with the given species id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species the id of the SpeciesGlyph object associated with it is going to be returned.
    /// @param speciesGlyphIndex the index of the SpeciesGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the nth SpeciesGlyph associated with the given species id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthSpeciesGlyphId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex = 0);

    /// @brief Returns the meta id of the nth SpeciesGlyph object associated with the given species id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species the id of the SpeciesGlyph object associated with it is going to be returned.
    /// @param speciesGlyphIndex the index of the SpeciesGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the meta id of the nth SpeciesGlyph associated with the given species id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthSpeciesGlyphMetaId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex = 0);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex = 0);

    /// @brief Returns the number of Reaction objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Reaction objects in the given SBML document.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumReactions(SBMLDocument* document);

    /// @brief Returns the id of the nth Reaction object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionIndex the index of the Reaction object.
    /// @return the id of the nth Reaction object in the given SBML document, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactionId(SBMLDocument* document, int reactionIndex);

    /// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of ReactionGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllReactionsGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered reaction id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
    /// @return the number of ReactionGlyph objects associated with the entered reaction id,
    /// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
    LIBSBMLNETWORK_EXTERN const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex);

    /// @brief Returns the id of the nth ReactionGlyph object associated with the given reaction id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the ReactionGlyph object associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the nth ReactionGlyph associated with the given reaction id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactionGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex = 0);

    /// @brief Returns the meta id of the nth ReactionGlyph object associated with the given reaction id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the ReactionGlyph object associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the meta id of the nth ReactionGlyph associated with the given reaction id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactionGlyphMetaId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex = 0);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex = 0);

    /// @brief Returns the number of SpeciesReferences of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects associated with it is going to be returned.
    /// @return the number of SpeciesReference objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferences(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the number of Reactants of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of Reactant objects associated with it is going to be returned.
    /// @return the number of Reactant objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumReactants(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the number of Products of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of Product objects associated with it is going to be returned.
    /// @return the number of Product objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumProducts(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the number of Modifiers of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of Modifier objects associated with it is going to be returned.
    /// @return the number of Modifier objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumModifiers(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the id of nth Reactant of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the nth Reactant object associated with it is going to be returned.
    /// @param reactantIndex the index of the Reactant object.
    /// @return the id of the nth Reactant object of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactantId(SBMLDocument* document, const char* reactionId, int reactantIndex);

    /// @brief Returns the id of nth Product of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the nth Product object associated with it is going to be returned.
    /// @param productIndex the index of the Product object.
    /// @return the id of the nth Product object of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthProductId(SBMLDocument* document, const char* reactionId, int productIndex);

    /// @brief Returns the id of nth Modifier of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the nth Modifier object associated with it is going to be returned.
    /// @param modifierIndex the index of the Modifier object.
    /// @return the id of the nth Modifier object of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthModifierId(SBMLDocument* document, const char* reactionId, int modifierIndex);

    /// @brief Returns the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
    /// or @c 0 if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the "species" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceSpeciesId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "speciesGlyph" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "role"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the givne index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given id of
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of curve segments of the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of curve segments of the Curve object of the SpeciesReferenceGlyph object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @breif Predicate returning true if the curve segment with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts is of type CubicBezier.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the curve segment with the given index is of type CubicBezier, @c false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the start point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the start point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the end point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the end point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the base point 1 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the base point 1 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the base point 2 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the base point 2 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "stroke" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param stroke a string value to be set as "stroke" attribute of the SpeciesReferenceGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, const char* stroke, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke-width" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "stroke-width"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "stroke-width" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param strokeWidth a string value to be set as "stroke-width" attribute of the SpeciesReferenceGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, const double strokeWidth, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getNumSpeciesReferenceBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the dash at the given index of the "stroke-dasharray" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document at the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param index the index of the "stroke-dasharray" attribute of the SpeciesReferenceGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "stroke-dasharray" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the "stroke-dasharray" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document at the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param borderDash a string value to be set as "stroke-dasharray" attribute of the SpeciesReferenceGlyph object.
    /// @param index the index of the "stroke-dasharray" attribute of the SpeciesReferenceGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, const int borderDash, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "startHead" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "startHead" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "startHead"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "startHead" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "startHead" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "startHead" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param startHead a string value to be set as "startHead" attribute of the SpeciesReferenceGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, const char* startHead, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "endHead" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "endHead" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "endHead"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "endHead" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "endHead" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "endHead" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
    /// @param endHead a string value to be set as "endHead" attribute of the SpeciesReferenceGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, const char* endHead, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of TextGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of TextGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of TextGlyph objects associated with entered id of the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id in
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @package checkForName a boolean value to indicate whether the function should check for the "name" attribute of the TextGlyph object.
    /// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
    /// , TextGlyph does not exits or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getText(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0, bool checkForName = true);

    /// @brief Sets the "text" attribute of the TextGlyph object with the given index associated with the given id in
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
    /// @param text a string value to be set as "text" attribute of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setText(SBMLDocument* document, const char* id, const char* text, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getX(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @isLayoutAdded a boolean value
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true);

    /// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param isLayoutAdded a variable that determines whether layout info is added after sbml document is loaded.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true);

    /// @brief Sets the values of the "x" and "y" attributes of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the bounding box of the GraphicalObject object.
    /// @param y a double value to be set as "y" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param isLayoutAdded a variable that determines whether layout info is added after sbml document is loaded.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true);

    /// @brief Returns the value of the "width" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param width a double value to be set as "width" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param isLayoutAdded a variable that determines whether layout info is added after sbml document is loaded.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true);

    /// @brief Returns the value of the "height" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param height a double value to be set as "height" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param isLayoutAdded a variable that determines whether layout info is added after sbml document is loaded.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true);

    /// @brief Returns the value of the "x" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the bounding box of the TextGlyph object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getTextX(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Sets the value of the "x" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the bounding box of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Returns the value of the "y" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the bounding box of the TextGlyph object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getTextY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Sets the value of the "y" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the bounding box of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// brief Sets the value of "x" and "y" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the bounding box of the TextGlyph object.
    /// @param y a double value to be set as "y" attribute of the bounding box of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Returns the value of the "width" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "width" attribute of the bounding box of the TextGlyph object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getTextWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Sets the value of the "width" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param width a double value to be set as "width" attribute of the bounding box of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Returns the value of the "height" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "height" attribute of the bounding box of the TextGlyph object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getTextHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Sets the value of the "height" attribute of the bounding box of the TextGlyph object with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object associated with it to be returned.
    /// @param height a double value to be set as "height" attribute of the bounding box of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex);

    /// @brief Predicate returning true if the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document
    /// has a Curve object and the curve consists of one or more segments.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSetCurve(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of curve segments of the curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
    /// or does not have a curve
    LIBSBMLNETWORK_EXTERN const int c_api_getNumCurveSegments(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicate returning true if the curve segment with the given index of the Curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document is of type CubicBezier.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if this curve segment is of type CubicBezier, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isCurveSegmentCubicBezier(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentStartPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the start point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentStartPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentStartPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the start point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentStartPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the end point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentEndPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the end point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentEndPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the end point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentEndPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the end point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentEndPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the base point 1 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the base point 1 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.

    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the base point 1 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the base point 1 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the base point 2 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the base point 2 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the base point 2 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the base point 2 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSegmentCurveBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of items in the ListOfGlobalRenderInformation of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of items in the ListOfGlobalRenderInformation of the SBML document, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumGlobalRenderInformation(SBMLDocument* document);

    /// @brief Returns the number of items in the ListOfGlobalRenderInformation of the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout object.
    /// @return the number of items in the ListOfGlobalRenderInformation of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Remove all the global and local render information objects from the list of global renders of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeRenderInformation(SBMLDocument* document);

    /// @brief Remove all the global render information objects from the list of global renders of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeGlobalRenderInformation(SBMLDocument* document);

    /// @brief Remove all the local render information objects from the list of local renders of the Layout with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Create a GlobalRenderInformation object, add it to list of global renders of the SBML document, and
    /// set all the necessary features for it.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createDefaultGlobalRenderInformation(SBMLDocument* document);

    /// @brief Create a LocalRenderInformation object, add it to list of local renders of the Layout of the SBML document, and
    /// set all the necessary features for it.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createDefaultLocalRenderInformation(SBMLDocument* document);

    /// @brief Predicates returning @c true if the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return @c true if the "backgroundColor" attribute of this GlobalRenderInformation object is set, @c false if either the "backgroundColor"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetBackgroundColor(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the value of the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the "backgroundColor" attribute of this RenderInformationBase object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getBackgroundColor(SBMLDocument* document, int renderIndex = 0);

    /// @brief Sets the value of the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param backgroundColor a string value to use as the value of the "backgroundColor" attribute of this RenderInformationBase object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBackgroundColor(SBMLDocument* document, const char* backgroundColor, int renderIndex = 0);

    /// @brief Returns the number of ColorDefinitions of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of ColorDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumColors(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the number of ColorDefinitions of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the number of ColorDefinitions of this GlobalRenderInformation object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumGlobalColors(SBMLDocument* document, int renderIndex);

    /// @brief Returns the number of ColorDefinitions of the LocalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the number of ColorDefinitions of this LocalRenderInformation object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLocalColors(SBMLDocument* document, int renderIndex);

    /// @brief Returns the id of the nth Global ColorDefinition object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param colorIndex the index of the ColorDefinition to return.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the id of the nth ColorDefinition object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthGlobalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0);

    /// @brief Returns the id of the nth Local ColorDefinition object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param colorIndex the index of the ColorDefinition to return.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the id of the nth ColorDefinition object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthLocalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "value" attribute of the ColorDefinition with the given identifier
    /// in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the ColorDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetColorValue(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "value" attribute of the ColorDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the ColorDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getColorValue(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "value" attribute of the ColorDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the ColorDefinition to retrieve.
    /// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setColorValue(SBMLDocument* document, const char* id, const char* value, int renderIndex);

    /// @brief Returns the number of GradientDefinitions of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of GradientDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumGradients(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the number of GradientDefinitions of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the number of GradientDefinitions of this GlobalRenderInformation object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumGlobalGradients(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the number of GradientDefinitions of the LocalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the number of GradientDefinitions of this LocalRenderInformation object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLocalGradients(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the id of the nth GradientDefinition object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientIndex the index of the GradientDefinition to return.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the id of the nth GradientDefinition object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthGlobalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0);

    /// @brief Returns the id of the nth GradientDefinition object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientIndex the index of the GradientDefinition to return.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the id of the nth GradientDefinition object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthLocalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0);

    /// @brief Predicate returning true if the GradientDefinition with the given identifier in the RenderInformationBase with the given index is of type LinearGradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @return @c true if this GradientBase is of type LinearGradient, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isLinearGradient(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Predicate returning true if the GradientDefinition with the given identifier in the RenderInformationBase with the given index is of type RadialGradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @return @c true if this GradientBase is of type RadialGradient, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isRadialGradient(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "spreadMethod" attribute of the GradientDefinition with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "spreadMethod" attribute of this GradientDefinition object is set, @c false if either the "spreadMethod"
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpreadMethod(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "spreadMethod" attribute of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "spreadMethod" attribute of the GradientDefinition object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpreadMethod(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "spreadMethod" attribute of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientDefinition object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpreadMethod(SBMLDocument* document, const char* id, const char* spreadMethod, int renderIndex = 0);

    /// @breif Returns the number of GradientStop objects of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of GradientStop objects of this GradientDefinition object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getNumGradientStops(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "offset" attribute of the GradientStop with the given index of the GradientDefinition with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "offset" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if
    /// either the "offset" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetOffset(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "offset" attribute of the GradientStop object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getOffset(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param offset a double value (between 0 to 100) to be set as "offset" attribute of the GradientStop object.
    /// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setOffset(SBMLDocument* document, const char* id, const double offset, int gradientStopIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "stop-color" attribute of the GradientStop with the given index of the GradientDefinition with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "stop-color" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if
    /// either the "stop-color" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetStopColor(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "stop-color" attribute of the GradientStop with the given index of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "stop-color" attribute of the GradientStop object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getStopColor(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "stop-color" attribute of the GradientStop with the given index of the GradientDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param stopColor a string value to use as the value of the "stop-color" attribute of the GradientStop object.
    /// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setStopColor(SBMLDocument* document, const char* id, const char* stopColor, int gradientStopIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "x1" attribute of the GradientDefinition with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the GradientDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
    /// , the object is @c NULL, or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "x1" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x1" attribute of the LinearGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "x1" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param x1 a double value to be set as "x1" attribute of the LinearGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientX1(SBMLDocument* document, const char* id, const double x1, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "y1" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "y1" attribute of this LinearGradient object is set, @c false if either the "y1" attribute is not set
    /// , the object is @c NULL, or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "y1" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y1" attribute of the LinearGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "y1" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param y1 a double value to be set as "y1" attribute of the LinearGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientY1(SBMLDocument* document, const char* id, const double y1, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "x2" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "x2" attribute of this LinearGradient object is set, @c false if either the "x2" attribute is not set
    /// , the object is @c NULL, or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "x2" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x2" attribute of the LinearGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "x2" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param x2 a double value to be set as "x2" attribute of the LinearGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientX2(SBMLDocument* document, const char* id, const double x2, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "y2" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "y2" attribute of this LinearGradient object is set, @c false if either the "y2" attribute is not set
    /// , the object is @c NULL, or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "y2" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y2" attribute of the LinearGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type LinearGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "y2" attribute of the LinearGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the LinearGradient to retrieve.
    /// @param y2 a double value to be set as "y2" attribute of the LinearGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientY2(SBMLDocument* document, const char* id, const double y2, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "cx" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "cx" attribute of this RadialGradient object is set, @c false if either the "cx" attribute is not set
    /// , the object is @c NULL, or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "cx" attribute of the RadialGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param cx a double value to be set as "cx" attribute of the RadialGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientCenterX(SBMLDocument* document, const char* id, const double cx, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "cy" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "cy" attribute of this RadialGradient object is set, @c false if either the "cy" attribute is not set
    /// , the object is @c NULL, or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "cy" attribute of the RadialGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param cy a double value to be set as "cy" attribute of the RadialGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientCenterY(SBMLDocument* document, const char* id, const double cy, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "fx" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "fx" attribute of this RadialGradient object is set, @c false if either the "fx" attribute is not set
    /// , the object is @c NULL, or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "fx" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "fx" attribute of the RadialGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "fx" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param fx a double value to be set as "fx" attribute of the RadialGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientFocalX(SBMLDocument* document, const char* id, const double fx, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "fy" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "fy" attribute of this RadialGradient object is set, @c false if either the "fy" attribute is not set
    /// , the object is @c NULL, or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "fy" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "fy" attribute of the RadialGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "fy" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param fy a double value to be set as "fy" attribute of the RadialGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientFocalY(SBMLDocument* document, const char* id, const double fy, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "r" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "r" attribute of this RadialGradient object is set, @c false if either the "r" attribute is not set
    /// , the object is @c NULL, or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "r" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "r" attribute of the RadialGradient object, or @c 0.0 if the object is @c NULL
    /// or not of type RadialGradient.
    LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "r" attribute of the RadialGradient with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the RadialGradient to retrieve.
    /// @param r a double value to be set as "r" attribute of the RadialGradient object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientRadius(SBMLDocument* document, const char* id, const double r, int renderIndex = 0);

    /// @brief Returns the number of LineEnding objects of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of LineEnding objects of this RenderInformationBase object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLineEndings(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the number of LineEnding objects of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the number of LineEnding objects of this GlobalRenderInformation object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumGlobalLineEndings(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the number of LineEnding objects of the LocalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the number of LineEnding objects of this LocalRenderInformation object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLocalLineEndings(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the id of the nth LineEnding object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineEndingIndex the index of the LineEnding to return.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the id of the nth LineEnding object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthGlobalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex = 0);

    /// @brief Returns the id of the nth LineEnding object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineEndingIndex the index of the LineEnding to return.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the id of the nth LineEnding object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthLocalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the bounding box of the LineEnding object  of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingBoundingBoxX(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the bounding box of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBoundingBoxX(SBMLDocument* document, const char* id, const double x, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingBoundingBoxY(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the bounding box of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBoundingBoxY(SBMLDocument* document, const char* id, const double y, int renderIndex = 0);

    /// @brief Returns the value of the "width" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "width" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "width" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param width a double value to be set as "width" attribute of the bounding box of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, const double width, int renderIndex = 0);

    /// @brief Returns the value of the "height" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "height" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "height" attribute of the bounding box of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param height a double value to be set as "height" attribute of the bounding box of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, const double height, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "stroke" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "stroke" attribute of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "stroke-width" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "stroke-width"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "stroke-width" attribute of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int renderIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param renderIndex the index number of the RenderInformationBase object.
    LIBSBMLNETWORK_EXTERN int c_api_getNumLineEndingBorderDashes(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param renderIndex the index number of the RenderInformationBase object.
    LIBSBMLNETWORK_EXTERN const int c_api_getLineEndingNthBorderDash(SBMLDocument* document, const char* id, int borderDashIndex, int renderIndex = 0);

    /// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderDashes a double array to use as the value of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object.
    /// @param numBorderDashes the number of elements in the borderDashes array.
    /// @param renderIndex the index number of the RenderInformationBase object.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingNthBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex, int renderIndex = 0);

    /// @breif Predicates returning @c true if the "fill" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "fill" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "fill"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "fill" attribute of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingFillColor(SBMLDocument* document, const char* id, const char* fillColor, int renderIndex = 0);

    /// @breif Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "fill-rule" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "fill-rule"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "fill-rule" attribute of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingFillRule(SBMLDocument* document, const char* id, const char* fillRule, int renderIndex = 0);

    /// @brief Returns number of Transformation2D objects in the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of Transformation2D objects in the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLineEndingGeometricShapes(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Rectangle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Rectangle, @c false if either the Transformation2D
    /// object is not of type Rectangle or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Ellipse.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Ellipse, @c false if either the Transformation2D
    /// object is not of type Ellipse or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Polygon.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Polygon, @c false if either the Transformation2D
    /// object is not of type Polygon or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Image.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Image, @c false if either the Transformation2D
    /// object is not of type Image or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type RenderCurve.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type RenderCurve, @c false if either the Transformation2D
    /// object is not of type RenderCurve or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Text.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Text, @c false if either the Transformation2D
    /// object is not of type Text or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "x"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "y"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "width"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param width a double value to be set as "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "height"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param height a double value to be set as "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "ratio"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param ratio a double value to be set as "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "rx"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param rx a double value to be set as "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double rx, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "ry"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param ry a double value to be set as "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double ry, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "cx"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param cx a double value to be set as "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, const double cx, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "cy"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param cy a double value to be set as "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, const double cy, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "rx"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object
    /// @param id the id of the LineEnding object
    /// @param rx a double value to be set as "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object
    /// @return integer value indicating success/failure of the function
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double rx, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object
    /// @param id the id of the LineEnding object
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object
    /// @return @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "ry"
    /// attribute is not set or the object is @c NULL
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document
    /// @param document a pointer to the SBMLDocument object
    /// @param id the id of the LineEnding object
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object
    /// @return the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document
    /// @param document a pointer to the SBMLDocument object
    /// @param id the id of the LineEnding object
    /// @param ry a double value to be set as "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object
    /// @return integer value indicating success/failure of the function
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double ry, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the number of elements of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of elements of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "type" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set to "cubicBezier".
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "href"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param href a string value to be set as "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeSegmentHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject (ReactionGlyph).
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject (ReactionGlyph).
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL or not a ReactoinGlyph.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject (ReactionGlyph).
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param lineColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineColor(SBMLDocument* document, const char* id, const char* lineColor, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsLineColors(SBMLDocument* document, const char* lineColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-width"
    /// attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject (ReactionGlyph).
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL or not a ReactionGlyph.
    LIBSBMLNETWORK_EXTERN const double c_api_getLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject (ReactionGlyph).
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param lineWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
    LIBSBMLNETWORK_EXTERN int c_api_setLineWidth(SBMLDocument* document, const char* id, const double lineWidth, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsLineWidths(SBMLDocument* document, const double lineWidth, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getNumBorderDashes(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the stroke dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderDashIndex an int representing the index of the stroke dash to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the stroke dash at the given index of "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNthBorderDash(SBMLDocument* document, const char* id, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param dash a int value to use as the dash at the given index of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
    /// @param borderDashIndex an int representing the index of the stroke dash to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setNthBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "fill" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "fill" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill"
    /// attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "fill" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFillColor(SBMLDocument* document, const char* id, const char* fillColor, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill-rule"
    /// attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFillRule(SBMLDocument* document, const char* id, const char* fillRule, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that belongs to the the TextGlyph
    /// with the given index associated with the GraphicalObject with the given index associated with the model entity with this id is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.  
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontColor(SBMLDocument* document, const char* id, const char* fontColor, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "font-family" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-family"
    /// attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontFamily(SBMLDocument* document, const char* id, const char* fontFamily, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

    /// @breif Sets the value of the "font-family" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "font-size" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-size"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-weight"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontWeight(SBMLDocument* document, const char* id, const char* fontWeight, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "font-style" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @return @c true if the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-style"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontStyle(SBMLDocument* document, const char* id, const char* fontStyle, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "text-anchor"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextHorizontalAlignment(SBMLDocument* document, const char* id, const char* textHorizontalAlignment, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "text-anchor"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextVerticalAlignment(SBMLDocument* document, const char* id, const char* textVerticalAlignment, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "startHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "startHead"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetStartHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "startHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getStartHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "startHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param startHead a string value to use as the value of the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setStartHead(SBMLDocument* document, const char* id, const char* startHead, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "endHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "endHead"
    /// attribute is not set
    LIBSBMLNETWORK_EXTERN bool c_api_isSetEndHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "endHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getEndHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "endHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param endHead a string value to use as the value of the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setEndHead(SBMLDocument* document, const char* id, const char* endHead, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns number of Transformation2D objects in the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of Transformation2D objects in the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getNumGeometricShapes(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Add a geometric shape to the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param shape a string value indicating the shape of the geometric shape to be added.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addGeometricShape(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Remove a geometric shape from the RenderGroup of the that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeGeometricShape(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShape(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex = 0, int layoutIndex = 0);


    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Rectangle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Rectangle, @c false if
    /// it is not of type Rectangle or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Ellipse.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Ellipse, @c false if
    /// it is not of type Ellipse or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Polygon.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Polygon, @c false if
    /// it is not of type Polygon or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Image.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Image, @c false if
    /// it is not of type Image or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type RenderCurve.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCurve, @c false if
    /// it is not of type RenderCurve or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Text.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Text, @c false if
    /// it is not of type Text or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "x" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
    /// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "y" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "width" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @breif Predicates returning @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "height" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "ratio" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "rx" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "ry" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "cx" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "cy" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "rx" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "ry" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0,  int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

    /// @brief Returns the number of elements of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the number of elements of the Transformation2D object at the given index of the RenderGroup of this Style for this GraphicalObject, or @c 0 if
    /// either Transformation2D object does not exists, does not have any elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const int c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type RenderCubicBezier.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCubicBezier,
    LIBSBMLNETWORK_EXTERN bool c_api_isGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "x" attribute of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "y" attribute of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "x" attribute of the base point 1 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "y" attribute of the base point 1 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "x" attribute of the base point 2 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "y" attribute of the base point 2 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "href" attribute is not set or the object is @c NULL .
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c NULL if
    /// either Transformation2D object does not exists, does not have "href" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Returns the number of valid values for the "role" attribute that can be used in for c_api_SetSpeciesReferenceRole function.
    /// @return the number of valid values for the "role" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidRoleValues();

    /// @brief Returns the nth valid value for the "role" attribute that can be used in for c_api_SetSpeciesReferenceRole function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidRoleValue(int index);

    /// @brief Returns the number of valid values for the "alignment" attribute that can be used in for c_api_align function.
    /// @return the number of valid values for the "alignment" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidAlignmentValues();

    /// @brief Returns the nth valid value for the "alignment" attribute that can be used in for c_api_align function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidAlignmentValue(int index);

    /// @brief Returns the number of valid values for the "distribution" direction attribute that can be used in for c_api_setDistribution function
    /// @return the number of valid values for the "distribution" direction attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidDistributionDirectionValues();

    /// @brief Returns the nth valid value for the "distribution" direction attribute that can be used in for c_api_setDistribution function
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidDistributionDirectionValue(int index);

    /// @brief Returns the number of valid values for the "color" name attribute that can be used in for all set color value functions.
    /// @return the number of valid values for the "color" name attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidColorNameValues();

    /// @brief Returns the nth valid value for the "color" name attribute that can be used in for all set color value functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidColorNameValue(int index);

    /// @brief Returns the number of valid values for the hex "color" attribute that can be used in for all set color value functions.
    /// @return the number of valid values for the hex "color" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidHexColorCodeValues();

    /// @brief Returns the nth valid value for the hex "color" attribute that can be used in for all set color value functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidHexColorCodeValue(int index);

    /// @brief Returns the number of valid values for the "spread-method" attribute that can be used in for c_api_setGradientSpreadMethod function.
    /// @return the number of valid values for the "spread-method" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidSpreadMethodValues();

    /// @brief Returns the nth valid value for the "spread-method" attribute that can be used in for c_api_setGradientSpreadMethod function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidSpreadMethodValue(int index);

    /// @brief Returns the number of valid values for the "font-weight" attribute that can be used in for all set font weight functions.
    /// @return the number of valid values for the "font-weight" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidFontWeightValues();

    /// @brief Returns the nth valid value for the "font-weight" attribute that can be used in for all set font weight functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidFontWeightValue(int index);

    /// @brief Returns the number of valid values for the "font-style" attribute that can be used in for all set font style functions.
    /// @return the number of valid values for the "font-style" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidFontStyleValues();

    /// @brief Returns the nth valid value for the "font-style" attribute that can be used in for all set font style functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidFontStyleValue(int index);

    /// @brief Returns the number of valid values for the "text-anchor" attribute that can be used in for all set text anchor functions.
    /// @return the number of valid values for the "text-anchor" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidHorizontalTextAlignmentValues();

    /// @brief Returns the nth valid value for the "text-anchor" attribute that can be used in for all set text anchor functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidHorizontalTextAlignmentValue(int index);

    /// @brief Returns the number of valid values for the "vtext-anchor" attribute that can be used in for all set vertical text alignment functions.
    /// @return the number of valid values for the "vtext-anchor" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidVerticalTextAlignmentValues();

    /// @brief Returns the nth valid value for the "vtext-anchor" attribute that can be used in for all set vertical text alignment functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidVerticalTextAlignmentValue(int index);

    /// @brief Returns the number of valid values for the "fill-rule" attribute that can be used in for c_api_setFillRule function.
    /// @return the number of valid values for the "fill-rule" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidFillRuleValues();

    /// @brief Returns the nth valid value for the "fill-rule" attribute that can be used in for c_api_setFillRule function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidFillRuleValue(int index);

    /// @brief Returns the number of valid values for the "shape" attribute that can be sued in for c_api_setGeometricShape function.
    /// @return the number of valid values for the "shape" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidGeometricShapeValues();

    /// @brief Returns the nth valid value for the "shape" attribute that can be used in for c_api_setGeometricShape function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getNthValidGeometricShapeValue(int index);
}

#ifdef __cplusplus
}
#endif

#endif