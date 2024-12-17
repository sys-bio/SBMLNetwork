#ifndef __LIBSBMLNETWORK_C_API_H_
#define __LIBSBMLNETWORK_C_API_H_

#include "../libsbmlnetwork_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#endif

using namespace libsbml;

#ifdef __cplusplus
extern "C" {
#endif

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    /// @brief Returns the version of the library.
    /// @return the version of the library.
    LIBSBMLNETWORK_EXTERN const char* c_api_getVersion();

    /// @brief Returns the directory of the library.
    /// @return the directory of the library.
    LIBSBMLNETWORK_EXTERN const char* c_api_getCurrentDirectoryOfLibrary();

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

    /// @breif Returns the error log.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the error log.
    LIBSBMLNETWORK_EXTERN const char* c_api_getErrorLog(SBMLDocument* document);

    /// @brief Clears the error log.
    /// @param document a pointer to the SBMLDocument object.
    /// @return boolean value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN void c_api_clearErrorLog(SBMLDocument* document);

    /// @brief Returns true if the Model object has been set, otherwise returns false.
    /// @param document a pointer to the SBMLDocument object.
    /// @return true if the Model object has been set, otherwise returns false.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetModel(SBMLDocument* document);

    /// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
    /// to the the SBML document, and set all the necessary features for them.
    /// @param document a pointer to the SBMLDocument object.
    /// @param maxNumConnectedEdges the maximum number of connected edges to a species glyph.
    /// @param resetFixedPositionElements a variable that determines whether to reset the fixed position elements in the autolayout algorithm.
    /// @param fixedPositionNodeIds an array of strings containing the ids of the nodes and the indices of their associated graphical objects that must have fixed position in the autolayout algorithm.
    /// @param fixedPositionNodesSize the size of fixedPositionNodeIds
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_autolayout(SBMLDocument* document, const int maxNumConnectedEdges = 3,
                                                bool resetFixedPositionElements = false, const char ***fixedPositionNodes = NULL, const int fixedPositionNodesSize = 0);

    /// @brief Create a Render object, add it to the the SBML document, and set all the necessary features for it.
    /// @param document a pointer to the SBMLDocument object.
    /// @param maxNumConnectedEdges the maximum number of connected edges to a species glyph.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_autorender(SBMLDocument *document, const int maxNumConnectedEdges = 3);

    /// @brief Updates the curves of the centroid node position of the ReactionGlyphs and the curve of their SpeciesReferenceGlyphs in the Layout object with the given index in the given SBMLDocument.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_updateReactionCurves(SBMLDocument* document, const int layoutIndex = 0);

    /// @brief Align the nodes position in the SBML document in the given alignment type.
    /// @param document a pointer to the SBMLDocument object.
    /// @param nodes an array of strings containing the ids of the nodes and their associated graphical objects that should be aligned.
    /// @param nodesSize the size of nodeIds
    /// @param alignment determines how to align the nodes.
    /// @param ignoreFixedPositionNodes a variable that determines whether to ignore the fixed position nodes in the autolayout algorithm.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_align(SBMLDocument* document, const char ***nodes, const int nodesSize,  const char* alignment, bool ignoreFixedPositionNodes = false);

    /// @brief Distribute the nodes position in the SBML document in the given direction.
    /// @param document a pointer to the SBMLDocument object.
    /// @param nodes an array of strings containing the ids of the nodes and their associated graphical objects that should be distributed.
    /// @param nodesSize the size of nodeIds
    /// @param direction determines how to distribute the nodes.
    /// @param spacing the spacing between the distributed nodes.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_distribute(SBMLDocument* document, const char ***nodes, const int nodesSize, const char* direction, const double spacing = -1.0);

    /// @brief Make all the elements in the Layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeAllVisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the elements in the Layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeAllInvisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the compartments in the Layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeCompartmentsVisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the compartments in the Layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeCompartmentsInvisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the species in the Layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeSpeciesVisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the species in the Layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeSpeciesInvisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the reactions in the Layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeReactionsVisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the reactions in the Layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeReactionsInvisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the species references in the Layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeSpeciesReferencesVisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the species references in the Layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeSpeciesReferencesInvisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the line endings in the Layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeLineEndingsVisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Make all the line endings in the Layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeLineEndingsInvisible(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the graphical object with the given index associated with the entered model in the layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the graphical object to check visibility.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @true if the graphical object with the given index associated with the entered model in the layout object with the given index of the SBML document visible, @false otherwise.
    LIBSBMLNETWORK_EXTERN bool c_api_isVisible(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Make the graphical object with the given index associated with the entered model in the layout object with the given index of the SBML document visible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the graphical object to make visible.
    /// @param applyToConnectedElements a variable that determines whether to apply the visibility change to the connected elements.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeVisible(SBMLDocument* document, const char* id, bool applyToConnectedElements = true, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Make the graphical object with the given index associated with the entered model in the layout object with the given index of the SBML document invisible.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the graphical object to make invisible.
    /// @param applyToConnectedElements a variable that determines whether to apply the visibility change to the connected elements.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_makeInvisible(SBMLDocument* document, const char* id, bool applyToConnectedElements = true, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of items in the ListOfLayouts of this SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of items in of this SBML document, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLayouts(SBMLDocument* document);

    /// @brief Remove all the layout objects from the list of layouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeLayouts(SBMLDocument* document);

    /// @brief Create a Layout object, add it to list of layouts of the SBML document, and set all the necessary features for it.
    /// @param document a pointer to the SBMLDocument object.
    /// @param maxNumConnectedEdges the maximum number of connected edges to a species glyph.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createDefaultLayoutFeatures(SBMLDocument* document, const int maxNumConnectedEdges = 3);

    /// @brief Create a Layout object, add it to list of layouts of the SBML document, and set all the necessary features for it, and set the positions of the nodes in the layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param maxNumConnectedEdges the maximum number of connected edges to a species glyph.
    /// @param useMagnetism a variable that determines whether to use magnetism in the autolayout algorithm.
    /// @param useGrid a variable that determines whether to use grid restriction in the autolayout algorithm.
    /// @param resetFixedPositionElements a variable that determines whether to reset the fixed position elements in the autolayout algorithm.
    /// @param fixedPositionNodesSize the size of fixedPositionNodeIds
    /// @param fixedPositionNodeIds an array of strings containing the ids of the nodes that must have fixed position in the autolayout algorithm.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createDefaultLayoutLocations(SBMLDocument* document, const int maxNumConnectedEdges = 3,
                                                               bool resetFixedPositionElements = false, const char*** fixedPositionNodeIds = NULL, const int fixedPositionNodesSize = 0);

    /// @brief Returns the value of the option to generate stoichiometric species reference in the autolayout algorithm.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the value of the option to generate stoichiometric species reference in the autolayout algorithm.
    LIBSBMLNETWORK_EXTERN bool c_api_getStoichiometricSpeciesReference(SBMLDocument* document);

    /// @brief Sets the value of the option to generate stoichiometric species reference in the autolayout algorithm.
    /// @param document a pointer to the SBMLDocument object.
    /// @param stoichiometricSpeciesReference the value of the option to generate stoichiometric species reference in the autolayout algorithm.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setStoichiometricSpeciesReference(SBMLDocument* document, bool stoichiometricSpeciesReference);

    /// @brief Returns the option to use the name of the model entity as the text label of the GraphicalObject associated with the model entities in the Layout object with the given index in the ListOfLayouts of the SBMLDocument.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the option to use the name of the model entity as the text label of the GraphicalObject associated with the model entities.
    LIBSBMLNETWORK_EXTERN bool c_api_getUseNameAsTextLabel(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the option to use the name of the model entity as the text label of the GraphicalObject associated with the model entities in the Layout object with the given index in the ListOfLayouts of the SBMLDocument.
    /// @param document a pointer to the SBMLDocument object.
    /// @param useNameAsTextLabel the option to use the name of the model entity as the text label of the GraphicalObject associated with the model entities.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setUseNameAsTextLabel(SBMLDocument* document, bool useNameAsTextLabel, int layoutIndex = 0);

    /// @brief Create an alias SpeciesGlyph object for Species with the given id and connect all the SpeciesReferences in the ReactionGlyph object with the given id and index that contain Species as a participant to the alias SpeciesGlyph in the Layout object with the given index in the ListOfLayouts of the SBMLDocument.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species to create an alias SpeciesGlyph for.
    /// @param reactionId the id of the reaction to create an alias SpeciesGlyph for.
    /// @param reactionGlyphIndex the index of the ReactionGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createAliasSpeciesGlyph(SBMLDocument* document, const char* speciesId, const char* reactionId, int reactionGlyphIndex, int layoutIndex);

    /// @brief Create an alias ReactionGlyph object for Reaction with the given id
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction to create an alias ReactionGlyph for.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_createAliasReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex);

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

    LIBSBMLNETWORK_EXTERN int c_api_removeGraphicalObject(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex);

    /// @brief Predicate returning true if the id of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the id of the GraphicalObject is set, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSetId(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the id of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the GraphicalObject, or @c "" if the id is not set or the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getId(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Sets the id of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectId the id of the GraphicalObject.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setId(SBMLDocument* document, const char* entityId, const char* graphicalObjectId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Predicate returning true if the meta id of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the meta id of the GraphicalObject is set, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSetMetaId(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the meta id of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the meta id of the GraphicalObject, or @c "" if the meta id is not set or the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getMetaId(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Sets the meta id of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param metaId the meta id of the GraphicalObject.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setMetaId(SBMLDocument* document, const char* entityId, const char* metaId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Predicate returning true if the name of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the name of the GraphicalObject is set, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSetName(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the name of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the name of the GraphicalObject, or @c "" if the name is not set or the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getName(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex);

    /// @brief Sets the name of the GraphicalObject with the given id in the Layout object with the given index of the SBML document associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param entityId the id of the model entity.
    /// @param name the name of the GraphicalObject.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setName(SBMLDocument* document, const char* entityId, const char* name, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the number of Compartment objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Compartment objects in the given SBML document.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumCompartments(SBMLDocument* document);

    /// @brief Returns the id of the Compartment object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param compartmentIndex the index of the Compartment object.
    /// @return the id of the Compartment object with the given index in the given SBML document, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentId(SBMLDocument* document, int compartmentIndex);

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered compartment id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
    /// @return the number of CompartmentGlyph objects associated with the entered compartment id,
    /// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
    LIBSBMLNETWORK_EXTERN const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0);

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
    LIBSBMLNETWORK_EXTERN const char* c_api_getGraphicalObjectCompartmentId(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of Species objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Species objects in the given SBML document.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpecies(SBMLDocument* document);

    /// @brief Returns the id of the Species object wtih the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesIndex the index of the Species object.
    /// @return the id of the Species object wtih the given index in the given SBML document, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesId(SBMLDocument* document, int speciesIndex);

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

    /// @brief Sets which SpeciesGlyph of Species with the given id  to be assigned to the ReactionGlyph with the given id and index in the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species the SpeciesGlyph object associated with it is going to be set.
    /// @param reactionId the id of the reaction the SpeciesGlyph object is going to be associated with.
    /// @param index the index of the SpeciesGlyph object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    LIBSBMLNETWORK_EXTERN const int c_api_setSpeciesGlyphIndexInReactionGlyph(SBMLDocument* document, const char* speciesId, const char* reactionId, int index, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the index of the SpeciesGlyph object among the list of SpeciesGlyph objects associated with the given species id that is associated with the given reaction id with the given index in the ListOfLayouts of the SBML document.
    /// @param a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species the index of the SpeciesGlyph object associated with it is going to be returned.
    /// @param reactionId the id of the reaction the SpeciesGlyph object is associated with.
    /// @param reactionGlyphIndex the index of the ReactionGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the index of the SpeciesGlyph object among the list of SpeciesGlyph objects associated with the given species id that is associated with the given reaction id,
    LIBSBMLNETWORK_EXTERN const int c_api_getSpeciesGlyphIndex(SBMLDocument* document, const char* speciesId, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the id of the Reaction object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionIndex the index of the Reaction object.
    /// @return the id of the Reaction object with the given index in the given SBML document, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionId(SBMLDocument* document, int reactionIndex);

    /// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of ReactionGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllReactionGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered reaction id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
    /// @return the number of ReactionGlyph objects associated with the entered reaction id,
    /// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
    LIBSBMLNETWORK_EXTERN const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex = 0);

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

    /// @brief Returns the id of Reactant object with the given index of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the Reactant object with the given index associated with it is going to be returned.
    /// @param reactantIndex the index of the Reactant object.
    /// @return the id of the Reactant object with the given index of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactantId(SBMLDocument* document, const char* reactionId, int reactantIndex);

    /// @brief Returns the id of Product object with the given index of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the Product object with the givne index associated with it is going to be returned.
    /// @param productIndex the index of the Product object.
    /// @return the id of the Product object with the given index of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getProductId(SBMLDocument* document, const char* reactionId, int productIndex);

    /// @brief Returns the id of Modifier object with the given index of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the Modifier object with the given index associated with it is going to be returned.
    /// @param modifierIndex the index of the Modifier object.
    /// @return the id of the Modifier object with the given index of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getModifierId(SBMLDocument* document, const char* reactionId, int modifierIndex);

    /// @brief Returns the number of SpeciesReference objects of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of SpeciesReference objects of the ReactionGlyph object with the given index associated with the entered reaction id,
    /// or @c 0 if the object is @c NULL or has no associated SpeciesReference objects.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferences(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the id of the SpeciesReference with the given index associated with the given reaction id of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the SpeciesReference object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the SpeciesReference with the givne index associated with the given reaction id, or @c "" if the object does not exists.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);
    
    /// @brief Returns the id of the species glyph associated with the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the "species" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceSpeciesId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the id of the species glyph associated with the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "speciesGlyph" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Predicate returning true if the SpeciesGlyph associated with the SpeciesReferenceGlyph with the given index in the given ReactionGlyph object with the given index associated with the entered reaction id is an empty SpeciesGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the SpeciesGlyph associated with the SpeciesReferenceGlyph with the given index is an empty SpeciesGlyph, @c false otherwise.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceEmptySpeciesGlyph(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int layoutIndex);

    /// @brief Returns the id of the empty species glyph associated with the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the empty SpeciesGlyph associated with the SpeciesReference object with the given index, or @c "" if the SpeciesGlyph is not empty or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceEmptySpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int layoutIndex);

    /// @brief Predicates returning @c true if the "role" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "role" attribute of the SpeciesReference object with the given index is set, @c false if either the "role"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the string representation of the "role" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the givne index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "role" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "role" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given id of
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param role a string value to be set as "role" attribute of the SpeciesReference object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of SpeciesReference objects of the ReactionGlyph with the given index associated with the entered species id in the of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of SpeciesReference objects of the ReactionGlyph object with the given index associated with the entered species id,
    /// or @c 0 if the object is @c NULL or has no associated SpeciesReference objects.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceAssociatedWithSpecies(SBMLDocument* document, const char* speciesId, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the index of the SpeciesReference object with the given index associated with the given species id in the ReactionGlyph object with the given index associated with the entered reaction id in the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param speciesId the id of the species the index of the SpeciesReference object associated with it is going to be returned.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param n the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the index of the SpeciesReference object with the given index associated with the given species id, or @c -1 if the object does not exists.
    LIBSBMLNETWORK_EXTERN const int c_api_getSpeciesReferenceIndexAssociatedWithSpecies(SBMLDocument* document, const char* speciesId, const char* reactionId, int reactionGlyphIndex = 0, int n = 0, int layoutIndex = 0);

    /// @brief Returns the number of curve segments of the Curve object of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of curve segments of the Curve object of the SpeciesReference object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Adds a LineSegment to the Curve object of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addSpeciesReferenceLineCurveSegment(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Adds a CubicBezier to the Curve object of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Removes the curve segment with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeSpeciesReferenceCurveSegment(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @breif Predicate returning true if the curve segment with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts is of type CubicBezier.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the curve segment with the given index is of type CubicBezier, @c false otherwise
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the start point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the start point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the end point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the end point of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the base point 1 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the base point 1 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param x the value to be set as "x" attribute of the base point 2 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
    /// the SpeciesReference object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param curveSegmentIndex the index of the CurveSegment.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param y the value to be set as "y" attribute of the base point 2 of the CubicBezier object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke" attribute of the SpeciesReference object with the given index is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "stroke" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param lineColor a string value to be set as "stroke" attribute of the SpeciesReference object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineColor(SBMLDocument* document, const char* reactionId, const char* lineColor, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "stroke-width" attribute of the SpeciesReference object with the given index is set, @c false if either the "stroke-width"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "stroke-width" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param lineWidth a double value to be set as "stroke-width" attribute of the SpeciesReference object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineWidth(SBMLDocument* document, const char* reactionId, const double lineWidth, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getNumSpeciesReferenceLineDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the dash at the given index of the "stroke-dasharray" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document at the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param lineDashIndex the index of the "stroke-dasharray" attribute of the SpeciesReference object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "stroke-dasharray" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getSpeciesReferenceLineDash(SBMLDocument* document, const char* reactionId, int lineDashIndex, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the "stroke-dasharray" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document at the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param lineDash a string value to be set as "stroke-dasharray" attribute of the SpeciesReference object.
    /// @param lineDashIndex the index of the "stroke-dasharray" attribute of the SpeciesReference object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineDash(SBMLDocument* document, const char* reactionId, const int lineDash, int lineDashIndex, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "startHead" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "startHead" attribute of the SpeciesReference object with the given index is set, @c false if either the "startHead"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "startHead" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "startHead" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "startHead" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param startHead a string value to be set as "startHead" attribute of the SpeciesReference object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, const char* startHead, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "endHead" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "endHead" attribute of the SpeciesReference object with the given index is set, @c false if either the "endHead"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "endHead" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "endHead" attribute of the SpeciesReference object with the given index, or @c "" if
    /// the SpeciesReference does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "endHead" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the SpeciesReference object of which to be returned.
    /// @param endHead a string value to be set as "endHead" attribute of the SpeciesReference object.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceIndex the index of the SpeciesReference.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, const char* endHead, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

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
    /// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
    /// , TextGlyph does not exits or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getText(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Adds a new TextGlyph object associated with the graphical object with the given index of the model entity with the given id in the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object to be added.
    /// @param text a string value to be set as "text" attribute of the TextGlyph object.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addText(SBMLDocument* document, const char* id, const char* text, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Removes the TextGlyph object with the given index associated with the graphical object with the given index of the model entity with the given id in the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph object to be removed.
    /// @param graphicalObjectIndex the index number of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeText(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of additional graphical objects of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of additional graphical objects of this Layout object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumAllAdditionalGraphicalObjects(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the id of the additional graphical object with the given index of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param additionalGraphicalObjectIndex the index of the additional graphical object to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the additional graphical object with the given index, or @c NULL if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getAdditionalGraphicalObjectId(SBMLDocument* document, int additionalGraphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Adds a new additional graphical object to the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the additional graphical object to be added.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addAdditionalGraphicalObject(SBMLDocument* document, const char* id, int layoutIndex = 0);

    /// @brief Removes the additional graphical object with the given index of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param additionalGraphicalObjectIndex the index of the additional graphical object to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeAdditionalGraphicalObject(SBMLDocument* document, int additionalGraphicalObjectIndex, int layoutIndex = 0);

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
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool updateCurves = true);

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
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Sets the values of the "x" and "y" attributes of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the bounding box of the GraphicalObject object.
    /// @param y a double value to be set as "y" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool updateCurves = true);

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
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Sets the values of the "width" attribute of the bounding box of all the Compartments of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double value to be set as "width" attribute of the bounding box of the Compartments object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsWidth(SBMLDocument* document, const double width, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Returns the default value of the "width" attribute of the bounding box of the SpeciesGlyph objects.
    /// @return the default value of the "width" attribute of the bounding box of the SpeciesGlyph objects.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesWidth();

    /// @brief Sets the values of the "width" attribute of the bounding box of all the Species of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double value to be set as "width" attribute of the bounding box of the Species object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesWidth(SBMLDocument* document, const double width, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Returns the default value of the "width" attribute of the bounding box of the ReactionGlyph objects.
    /// @return the default value of the "width" attribute of the bounding box of the ReactionGlyph objects.
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsWidth();

    /// @brief Sets the values of the "width" attribute of the bounding box of all the Reactions of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double value to be set as "width" attribute of the bounding box of the Reactions object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsWidth(SBMLDocument* document, const double width, int layoutIndex = 0, bool updateCurves = true);

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
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Sets the values of the "height" attribute of the bounding box of all the Compartments of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double value to be set as "height" attribute of the bounding box of the Compartments object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsHeight(SBMLDocument* document, const double height, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Returns the default value of the "height" attribute of the bounding box of the SpeciesGlyph objects.
    /// @return the default value of the "height" attribute of the bounding box of the SpeciesGlyph objects.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesHeight();

    /// @brief Sets the values of the "height" attribute of the bounding box of all the Species of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double value to be set as "height" attribute of the bounding box of the Species object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesHeight(SBMLDocument* document, const double height, int layoutIndex = 0, bool updateCurves = true);

    /// @brief Returns the default value of the "height" attribute of the bounding box of the ReactionGlyph objects.
    /// @return the default value of the "height" attribute of the bounding box of the ReactionGlyph objects.
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsHeight();

    /// @brief Sets the values of the "height" attribute of the bounding box of all the Reactions of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double value to be set as "height" attribute of the bounding box of the Reactions object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param updateCurves a boolean value to indicate whether the function should update the curves after setting the value.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsHeight(SBMLDocument* document, const double height, int layoutIndex = 0, bool updateCurves = true);

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

    /// @brief Adds a LineSemgent to the Curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addLineCurveSegment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Adds a CubicBezier to the Curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addCubicBezierCurveSegment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Removes the curve segment with the given index of the Curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to remove.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeCurveSegment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

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
    LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the id of the Global ColorDefinition object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param colorIndex the index of the ColorDefinition to return.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the id of the ColorDefinition object with the given index, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getGlobalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0);

    /// @brief Returns the id of the Local ColorDefinition object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param colorIndex the index of the ColorDefinition to return.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the id of the ColorDefinition object with the given index, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLocalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0);

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

    /// @brief Returns the id of the GradientDefinition object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientIndex the index of the GradientDefinition to return.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the id of the GradientDefinition object with the given index, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getGlobalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0);

    /// @brief Returns the id of the GradientDefinition object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientIndex the index of the GradientDefinition to return.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the id of the GradientDefinition object with the given index, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLocalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0);

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

    /// @brief Returns the id of the LineEnding object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineEndingIndex the index of the LineEnding to return.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the id of the LineEnding object with the given index, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getGlobalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex = 0);

    /// @brief Returns the id of the LineEnding object with the given index in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineEndingIndex the index of the LineEnding to return.
    /// @param renderIndex the index number of the LocalRenderInformation object.
    /// @return the id of the LineEnding object with the given index, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getLocalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex = 0);

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

    /// @brief Returns the value of the "y" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "y" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the bounding box of the all LineEnding objects associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the value of the "y" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "y" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the bounding box of the all LineEnding objects associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the value of the "width" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "width" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param width a double value to be set as "width" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the bounding box of all LineEnding objects associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param width a double value to be set as "width" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the value of the "height" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "height" attribute of the bounding box of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the bounding box of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param height a double value to be set as "height" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the bounding box of all LineEnding objects associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param height a double value to be set as "height" attribute of the bounding box of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return @c true if the "stroke" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "stroke" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "stroke" attribute of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return @c true if the "stroke-width" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "stroke-width" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "stroke-width" attribute of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param renderIndex the index number of the RenderInformationBase object.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLineEndingBorderDashes(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param renderIndex the index number of the RenderInformationBase object.
    LIBSBMLNETWORK_EXTERN const int c_api_getLineEndingBorderDash(SBMLDocument* document, const char* id, int borderDashIndex, int renderIndex = 0);

    /// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderDashes a double array to use as the value of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object.
    /// @param numBorderDashes the number of elements in the borderDashes array.
    /// @param renderIndex the index number of the RenderInformationBase object.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex, int renderIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceLineEndingBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the dash at the given index of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderDashIndex the index of the border dash.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the value of the dash at the given index of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const int c_api_getSpeciesReferenceLineEndingBorderDash(SBMLDocument* document, const char* reactionId, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param dash the value of the dash to set.
    /// @param borderDashIndex the index of the border dash.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingBorderDash(SBMLDocument* document, const char* reactionId, const int dash, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the "stroke-dasharray" attribute of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param dash the value of the dash to set.
    /// @param borderDashIndex the index of the border dash.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingBorderDash(SBMLDocument* document, const char* reactionId, const int dash, int borderDashIndex, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document in the form of a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param gradientType the type of the gradient.
    /// @param stopColors an array of strings representing the colors of the gradient stops.
    /// @param stopOffsets an array of doubles representing the offsets of the gradient stops.
    /// @param stopsSize the size of the stopColors and stopOffsets arrays.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingFillColorAsGradient(SBMLDocument* document, const char* id, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "fill" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return @c true if the "fill" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "fill" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "fill" attribute of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, const char* fillColor, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document in the form of a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param gradientType the type of the gradient.
    /// @param stopColors an array of strings representing the colors of the gradient stops.
    /// @param stopOffsets an array of doubles representing the offsets of the gradient stops.
    /// @param stopsSize the size of the stopColors and stopOffsets arrays.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingFillColorAsGradient(SBMLDocument* document, const char* reactionId, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingFillColor(SBMLDocument* document, const char* reactionId, const char* fillColor, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document in the form of a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param gradientType the type of the gradient.
    /// @param stopColors an array of strings representing the colors of the gradient stops.
    /// @param stopOffsets an array of doubles representing the offsets of the gradient stops.
    /// @param stopsSize the size of the stopColors and stopOffsets arrays.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingFillColorAsGradient(SBMLDocument* document, const char* reactionId, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int reactionGlyphIndex = 0, int layoutIndex = 0);

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

    /// @brief Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return @c true if the "fill-rule" attribute of the RenderGroup of the LineEnding object is set, @c false if either the "fill-rule" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the "fill-rule" attribute of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, const char* fillRule, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingFillRule(SBMLDocument* document, const char* reactionId, const char* fillRule, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns number of Transformation2D objects in the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of Transformation2D objects in the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const int c_api_getNumLineEndingGeometricShapes(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns number of Transformation2D objects in the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    //// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the number of Transformation2D objects in the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceLineEndingGeometricShapes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Adds a Transformation2D object to the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param shape a string value to use as the value of the "shape" attribute of the Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to add.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addLineEndingGeometricShape(SBMLDocument* document, const char* id, const char* shape, int renderIndex = 0);

    /// @brief Adds a Transformation2D object to the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param shape a string value to use as the value of the "shape" attribute of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_addSpeciesReferenceLineEndingGeometricShape(SBMLDocument* document, const char* reactionId, const char* shape, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Removes the Transformation2D object at the given index from the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object to remove.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeLineEndingGeometricShape(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Removes the Transformation2D object at the given index from the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param geometricShapeIndex the index of the Transformation2D object to remove.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_removeSpeciesReferenceLineEndingGeometricShape(SBMLDocument* document, const char* reactionId, int geometricShapeIndex = 0, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the type of the Transformation2D object at the given index from the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the type of the Transformation2D object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingGeometricShapeType(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the type of the Transformation2D object at the given index from the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the type of the Transformation2D object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingGeometricShapeType(SBMLDocument* document, const char* reactionId, int geometricShapeIndex = 0, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Sets the type of the Transformation2D object at the given index in the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param shape a string value to use as the type of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeType(SBMLDocument* document, const char* id, const char* shape, int renderIndex = 0);

    /// @brief Sets the type of the Transformation2D object at the given index in the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param shape a string value to use as the type of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeType(SBMLDocument* document, const char* reactionId, const char* shape, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0);

    /// @brief Returns the id of the Transformation2D object at the given index from the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the id of the Transformation2D object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingGeometricShapeId(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the id of the Transformation2D object at the given index from the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return the id of the Transformation2D object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingGeometricShapeId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the id of the Transformation2D object at the given index in the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param shapeId a string value to use as the id of the Transformation2D object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeId(SBMLDocument* document, const char* id, const char* shapeId, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the id of the Transformation2D object at the given index in the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param id a string value to use as the id of the Transformation2D object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeId(SBMLDocument* document, const char* reactionId, const char* id, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Rectangle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Rectangle, @c false if either the Transformation2D
    /// object is not of type Rectangle or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is of type Rectangle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Rectangle, @c false if either the Transformation2D object is not of type Rectangle or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingRectangle(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Ellipse.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Ellipse, @c false if either the Transformation2D
    /// object is not of type Ellipse or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is of type Ellipse.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Ellipse, @c false if either the Transformation2D object is not of type Ellipse or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingEllipse(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Polygon.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Polygon, @c false if either the Transformation2D
    /// object is not of type Polygon or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is of type Polygon.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Polygon, @c false if either the Transformation2D object is not of type Polygon or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingPolygon(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Image.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Image, @c false if either the Transformation2D
    /// object is not of type Image or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is of type Image.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Image, @c false if either the Transformation2D object is not of type Image or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingImage(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type RenderCurve.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type RenderCurve, @c false if either the Transformation2D
    /// object is not of type RenderCurve or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is of type RenderCurve.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type RenderCurve, @c false if either the Transformation2D object is not of type RenderCurve or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingRenderCurve(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is of type Text.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Text, @c false if either the Transformation2D
    /// object is not of type Text or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is of type Text.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the LineEnding object is of type Text, @c false if either the Transformation2D object is not of type Text or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingText(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "stroke" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingGeometricShapeBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the Transformation2D object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "stroke-width" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "stroke-width" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0 , int renderIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "fill" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetLineEndingGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "fill" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingGeometricShapeFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the Transformation2D object.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeFillColor(SBMLDocument* document, const char* id, const char* fillColor, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the Transformation2D object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeFillColor(SBMLDocument* document, const char* reactionId, const char* fillColor, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document as a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param gradientType the type of the gradient.
    /// @param stopColors an array of strings representing the colors of the gradient stops.
    /// @param stopOffsets an array of doubles representing the offsets of the gradient stops.
    /// @param stopsSize the size of the stopColors and stopOffsets arrays.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex the index of the Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeFillColorAsGradient(SBMLDocument* document, const char* reactionId, const char* gradientType, const char** stopColors, const double* stopOffsets, const int stopsSize, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "x" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "y" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "width" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param width a double value to be set as "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param width a double value to be set as "width" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "height" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param height a double value to be set as "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param height a double value to be set as "height" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "ratio" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param ratio a double value to be set as "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, const double ratio, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param ratio a double value to be set as "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, const double ratio, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "rx" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param rx a double value to be set as "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param rx a double value to be set as "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "ry" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param ry a double value to be set as "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param ry a double value to be set as "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "cx" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param cx a double value to be set as "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, const double cx, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param cx a double value to be set as "cx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, const double cx, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "cy" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param cy a double value to be set as "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, const double cy, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param cy a double value to be set as "cy" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, const double cy, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "rx" attribute is not set or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param rx a double value to be set as "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param rx a double value to be set as "rx" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object
    /// @param reactionId the id of the reaction
    /// @param reactionGlyphIndex the index of the reaction glyph
    /// @param speciesReferenceIndex the index of the species reference glyph
    /// @param layoutIndex the index of the layout
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve
    /// @return @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false if either the "ry" attribute is not set or the object is @c NULL
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param ry a double value to be set as "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param ry a double value to be set as "ry" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the number of elements of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of elements of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN int c_api_getLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the number of segments of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the number of segments of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN int c_api_getSpeciesReferenceLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the "type" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document is set to "cubicBezier".
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "type" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set to "cubicBezier", @c false otherwise.
    LIBSBMLNETWORK_EXTERN bool c_api_isLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "type" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set to "cubicBezier".
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "type" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set to "cubicBezier", @c false otherwise.
    LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the base point 1 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the base point 1 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "x" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param x a double value to be set as "x" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param x a double value to be set as "x" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "y" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the LineEnding object.
    /// @param y a double value to be set as "y" attribute of the base point 2 of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param segmentIndex an int representing the index of the Transformation2D to retrieve.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param y a double value to be set as "y" attribute of the base point 2 of the segment at the given index of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param segmentIndex the index of the segment.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0);

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
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int renderIndex = 0);

   /// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object is set, @c false otherwise.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object, or @c NULL if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given species reference glyph of the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param href a string to be set as the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param speciesReferenceIndex the index of the species reference glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, const char* href, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object associated with the given reaction glyph of the given layout of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction.
    /// @param href a string to be set as the "href" attribute of the Transformation2D at the given index of the RenderGroup of the LineEnding object.
    /// @param reactionGlyphIndex the index of the reaction glyph.
    /// @param layoutIndex the index of the layout.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, const char* href, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0);

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

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsBorderColor(SBMLDocument* document);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesBorderColor(SBMLDocument* document);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsLineColor(SBMLDocument* document);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsLineColor(SBMLDocument* document, const char* lineColor, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object if they share the same color.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object, or @c "" if the object is @c NULL or the LineEndings objects do not share the same color.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingsBorderColor(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineColors(SBMLDocument* document, const char* lineColor, int layoutIndex = 0);

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

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object, or @c 0.0 if the object is @c NULL.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsBorderWidth(SBMLDocument* document);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesBorderWidth(SBMLDocument* document);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsLineWidth(SBMLDocument* document);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsLineWidth(SBMLDocument* document, const double lineWidth, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object if they share the same width.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object, or @c nan if the object is @c NULL or the LineEndings objects do not share the same width.
    LIBSBMLNETWORK_EXTERN const double c_api_getLineEndingsBorderWidth(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param lineWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineWidths(SBMLDocument* document, const double lineWidth, int layoutIndex = 0);

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
    LIBSBMLNETWORK_EXTERN const int c_api_getBorderDash(SBMLDocument* document, const char* id, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param dash a int value to use as the dash at the given index of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
    /// @param borderDashIndex an int representing the index of the stroke dash to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object, or @c 0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN int c_api_getNumLineDashes(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the stroke dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param lineDashIndex an int representing the index of the stroke dash to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    LIBSBMLNETWORK_EXTERN const int c_api_getLineDash(SBMLDocument* document, const char* id, int lineDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param dash a int value to use as the dash at the given index of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
    /// @param lineDashIndex an int representing the index of the stroke dash to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineDash(SBMLDocument* document, const char* id, const int dash, int lineDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

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
    LIBSBMLNETWORK_EXTERN int c_api_setFillColorAsGradient(SBMLDocument* document, const char* id, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "fill" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsFillColor(SBMLDocument* document);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object as a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientType a string value representing the type of gradient (e.g., "linear").
    /// @param stopColors an array of string values representing the colors at each stop of the gradient.
    /// @param stopOffsets an array of double values representing the offset at each stop of the gradient.
    /// @param stopsSize an int representing the number of stops in the gradient.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "fill" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesFillColor(SBMLDocument* document);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object as a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientType a string value representing the type of gradient (e.g., "linear").
    /// @param stopColors an array of string values representing the colors at each stop of the gradient.
    /// @param stopOffsets an array of double values representing the offset at each stop of the gradient.
    /// @param stopsSize an int representing the number of stops in the gradient.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "fill" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    /// @return the "fill" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsFillColor(SBMLDocument* document);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object as a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientType a string value representing the type of gradient (e.g., "linear").
    /// @param stopColors an array of string values representing the colors at each stop of the gradient.
    /// @param stopOffsets an array of double values representing the offset at each stop of the gradient.
    /// @param stopsSize an int representing the number of stops in the gradient.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object if they share the same color.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "fill" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object, or @c "" if the object is @c NULL or the LineEndings objects do not share the same color.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingsFillColor(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object as a gradient.
    /// @param document a pointer to the SBMLDocument object.
    /// @param gradientType a string value representing the type of gradient (e.g., "linear").
    /// @param stopColors an array of string values representing the colors at each stop of the gradient.
    /// @param stopOffsets an array of double values representing the offset at each stop of the gradient.
    /// @param stopsSize an int representing the number of stops in the gradient.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFillColorsAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0);

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

    /// @brief Returns the default value of the "fill-rule" attribute of the RenderGroup of the Global Style of CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "fill-rule" attribute of the RenderGroup of the Style for the global CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsFillRule(SBMLDocument* document);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "fill-rule" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesFillRule(SBMLDocument* document);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style of all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "fill-rule" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsFillRule(SBMLDocument* document);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object if they share the same fill rule.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "fill-rule" attribute of the RenderGroup of the Style of all LineEndings objects in this Layout object, or @c "" if the object is @c NULL or the LineEndings objects do not share the same fill rule.
    LIBSBMLNETWORK_EXTERN const char* c_api_getLineEndingsFillRule(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of all LineEndings objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setLineEndingsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0);

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

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsFontColor(SBMLDocument* document);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesFontColor(SBMLDocument* document);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "stroke" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsFontColor(SBMLDocument* document);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex = 0);

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

    /// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-family" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsFontFamily(SBMLDocument* document);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style of all CompartmentGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

    /// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-family" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesFontFamily(SBMLDocument* document);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

    /// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-family" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsFontFamily(SBMLDocument* document);

    /// @breif Sets the value of the "font-family" attribute of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0);

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
    /// @return @c true if the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-size" attribute is not set
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

    /// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsFontSize(SBMLDocument* document);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontSize(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesFontSize(SBMLDocument* document);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontSize(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsFontSize(SBMLDocument* document);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontSize(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all GraphicalObject objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-weight" attribute is not set
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

    /// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-weight" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsFontWeight(SBMLDocument* document);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-weight" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesFontWeight(SBMLDocument* document);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-weight" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsFontWeight(SBMLDocument* document);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all GraphicalObject objects in this Layout object.
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

    /// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-style" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsFontStyle(SBMLDocument* document);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

    /// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-style" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesFontStyle(SBMLDocument* document);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

    /// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "font-style" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsFontStyle(SBMLDocument* document);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0);

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

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsTextHorizontalAlignment(SBMLDocument* document);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesTextHorizontalAlignment(SBMLDocument* document);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsTextHorizontalAlignment(SBMLDocument* document);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0);

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

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsTextVerticalAlignment(SBMLDocument* document);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesTextVerticalAlignment(SBMLDocument* document);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style of the TextGlyph objects associated with all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsTextVerticalAlignment(SBMLDocument* document);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the the Style of the TextGlyph objects associated with of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for these GraphicalObject objects.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0);

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

    /// @breif Returns the type of the geometric shape of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the type of the geometric shape of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getGeometricShapeType(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeType(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the id of the geometric shape of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the id of the geometric shape of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getGeometricShapesId(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the id of the geometric shape of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeId a string value indicating the id of the geometric shape to be set.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapesId(SBMLDocument* document, const char* id, const char* geometricShapeId, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the type of the geometric shape of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the type of the geometric shape of the RenderGroup of the Style for all CompartmentGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsGeometricShapeType(SBMLDocument* document);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Returns the type of the geometric shape of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the type of the geometric shape of the RenderGroup of the Style for all SpeciesGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesGeometricShapeType(SBMLDocument* document);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Returns the type of the geometric shape of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the type of the geometric shape of the RenderGroup of the Style for all ReactionGlyph objects, or @c "" if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsGeometricShapeType(SBMLDocument* document);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style of all GraphicalObjects objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param shape a string value indicating the shape of the geometric shape to be set.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapesType(SBMLDocument* document, const char* shape, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Rectangle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Rectangle, @c false if
    /// it is not of type Rectangle or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Square.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Square, @c false if
    /// it is not of type Square or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isSquare(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Ellipse.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Ellipse, @c false if
    /// it is not of type Ellipse or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Circle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Circle, @c false if
    /// it is not of type Circle or is or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool c_api_isCircle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);
    
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

    /// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "stroke" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "stroke" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "stroke-width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "stroke-width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const double c_api_getGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return @c true if the "fill" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set.
    LIBSBMLNETWORK_EXTERN bool c_api_isSetGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Returns the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return the "fill" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL.
    LIBSBMLNETWORK_EXTERN const char* c_api_getGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    /// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the Transformation2D object.
    /// @param geometricShapeIndex an int representing the index of the Transformation2D to retrieve.
    /// @param graphicalObjectIndex an int representing the index of the GraphicalObject to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeFillColor(SBMLDocument* document, const char* id, const char* fillColor, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex);

    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeFillColorAsGradient(SBMLDocument* document, const char* id, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeX(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeX(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeX(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex = 0);

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

    /// @brief Returns the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeY(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeY(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeY(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex = 0);

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

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "width" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeWidth(SBMLDocument* document);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "width" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeWidth(SBMLDocument* document);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "width" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeWidth(SBMLDocument* document);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex = 0);

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

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "height" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeHeight(SBMLDocument* document);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "height" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeHeight(SBMLDocument* document);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "height" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeHeight(SBMLDocument* document);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex = 0);

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

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ratio" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeRatio(SBMLDocument* document);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex = 0);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ratio" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeRatio(SBMLDocument* document);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex = 0);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ratio" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeRatio(SBMLDocument* document);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex = 0);

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

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "rx" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeBorderRadiusX(SBMLDocument* document);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "rx" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeBorderRadiusX(SBMLDocument* document);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "rx" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeBorderRadiusX(SBMLDocument* document);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0);

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

   /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ry" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeBorderRadiusY(SBMLDocument* document);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ry" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeBorderRadiusY(SBMLDocument* document);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ry" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeBorderRadiusY(SBMLDocument* document);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0);

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

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "cx" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeCenterX(SBMLDocument* document);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "cx" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeCenterX(SBMLDocument* document);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "cx" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeCenterX(SBMLDocument* document);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex = 0);

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

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "cy" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeCenterY(SBMLDocument* document);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "cy" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeCenterY(SBMLDocument* document);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "cy" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeCenterY(SBMLDocument* document);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex = 0);

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

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "rx" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeRadiusX(SBMLDocument* document);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "rx" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeRadiusX(SBMLDocument* document);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "rx" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeRadiusX(SBMLDocument* document);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex = 0);

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

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ry" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeRadiusY(SBMLDocument* document);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ry" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeRadiusY(SBMLDocument* document);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "ry" attribute of the Transformation2D object for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeRadiusY(SBMLDocument* document);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex = 0);

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
    /// @return the "x" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
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

    /// @brief Returns the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of the element for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeSegmentX(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of the element for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeSegmentX(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of the element for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeSegmentX(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

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
    /// @return the "y" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
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

    /// @brief Returns the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of the element for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeSegmentY(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of the element for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeSegmentY(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of the element for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeSegmentY(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

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
    /// @return the "x" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
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

    /// @brief Returns the value of the "x" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of base point 1 of the element for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeSegmentBasePoint1X(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of base point 1 of the element for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeSegmentBasePoint1X(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of base point 1 of the element for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeSegmentBasePoint1X(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

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
    /// @return the "y" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
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

   /// @brief Returns the value of the "y" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of base point 1 of the element for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of base point 1 of the element for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeSegmentBasePoint1Y(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of base point 1 of the element for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

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
    /// @return the "x" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
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

    /// @brief Returns the value of the "x" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of base point 2 of the element for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeSegmentBasePoint2X(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of base point 2 of the element for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeSegmentBasePoint2X(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "x" attribute of base point 2 of the element for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeSegmentBasePoint2X(SBMLDocument* document);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0);

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
    /// @return the "y" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
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

    /// @brief Returns the value of the "y" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of base point 2 of the element for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getCompartmentsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of base point 2 of the element for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesGeometricShapeSegmentBasePoint2Y(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "y" attribute of base point 2 of the element for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const double c_api_getReactionsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param segmentIndex an int representing the index of the element to retrieve.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0);

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

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "href" attribute of the Transformation2D object for all CompartmentGlyph objects, or @c NULL if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentsGeometricShapeHref(SBMLDocument* document);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all CompartmentGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setCompartmentsGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "href" attribute of the Transformation2D object for all SpeciesGlyph objects, or @c NULL if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesGeometricShapeHref(SBMLDocument* document);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all SpeciesGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setSpeciesGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph objects in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the "href" attribute of the Transformation2D object for all ReactionGlyph objects, or @c NULL if the object is @c NULL
    LIBSBMLNETWORK_EXTERN const char* c_api_getReactionsGeometricShapeHref(SBMLDocument* document);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all ReactionGlyph object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setReactionsGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style of all GraphicalObject object in this Layout object.
    /// @param document a pointer to the SBMLDocument object.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param layoutIndex an int representing the index of the Layout to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0);

    /// @brief Returns the name of the predefined style that is used for the render features.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex an int representing the index of the Render object to retrieve.
    /// @return the name of the predefined style that is used for the render features, or @c "" if the object is @c NULL or no predefined style is used.
    LIBSBMLNETWORK_EXTERN const char* c_api_getStyle(SBMLDocument* document, int renderIndex = 0);

    /// @brief Sets the render features using the predefined style with the given name.
    /// @param document a pointer to the SBMLDocument object.
    /// @param styleName a string representing the name of the predefined style to use.
    /// @param renderIndex an int representing the index of the Render object to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int c_api_setStyle(SBMLDocument* document, const char* styleName, int renderIndex = 0);

    /// @brief Sets the render features using the predefined style with the given name for all CompartmentGlyph object in this Layout object.
    /// @param styleName a string representing the name of the predefined style to use.
    /// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN bool c_api_whetherDisplayReactionTextLabel(const char* styleName);

    /// @brief Returns the number of predefined styles that can be used in for c_api_setStyle function.
    /// @return the number of predefined styles.
    LIBSBMLNETWORK_EXTERN int c_api_getNumPredefinedStyles();

    /// @brief Returns the predefined style name with the given index that can be used in for c_api_setStyle function.
    /// @param index an int representing the index of the predefined style name to retrieve.
    /// @return the predefined style name with the given index.
    LIBSBMLNETWORK_EXTERN const char* c_api_getPredefinedStyleName(int index);

    /// @brief Returns the number of valid values for the "role" attribute that can be used in for c_api_SetSpeciesReferenceRole function.
    /// @return the number of valid values for the "role" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidRoleValues();

    /// @brief Returns the valid value with the given index for the "role" attribute that can be used in for c_api_SetSpeciesReferenceRole function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidRoleValue(int index);

    /// @brief Returns the number of valid values for the "alignment" attribute that can be used in for c_api_align function.
    /// @return the number of valid values for the "alignment" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidAlignmentValues();

    /// @brief Returns the valid value with the given index for the "alignment" attribute that can be used in for c_api_align function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidAlignmentValue(int index);

    /// @brief Returns the number of valid values for the "distribution" direction attribute that can be used in for c_api_setDistribution function
    /// @return the number of valid values for the "distribution" direction attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidDistributionDirectionValues();

    /// @brief Returns the valid value with the given index for the "distribution" direction attribute that can be used in for c_api_setDistribution function
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidDistributionDirectionValue(int index);

    /// @brief Returns the number of valid values for the "spread-method" attribute that can be used in for c_api_setGradientSpreadMethod function.
    /// @return the number of valid values for the "spread-method" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidSpreadMethodValues();

    /// @brief Returns the valid value with the given index for the "spread-method" attribute that can be used in for c_api_setGradientSpreadMethod function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidSpreadMethodValue(int index);

    /// @brief Returns the number of valid values for the "font-weight" attribute that can be used in for all set font weight functions.
    /// @return the number of valid values for the "font-weight" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidFontWeightValues();

    /// @brief Returns the valid value with the given index for the "font-weight" attribute that can be used in for all set font weight functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidFontWeightValue(int index);

    /// @brief Returns the number of valid values for the "font-style" attribute that can be used in for all set font style functions.
    /// @return the number of valid values for the "font-style" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidFontStyleValues();

    /// @brief Returns the valid value with the given index for the "font-style" attribute that can be used in for all set font style functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidFontStyleValue(int index);

    /// @brief Returns the number of valid values for the "text-anchor" attribute that can be used in for all set text anchor functions.
    /// @return the number of valid values for the "text-anchor" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidHorizontalTextAlignmentValues();

    /// @brief Returns the valid value with the given index for the "text-anchor" attribute that can be used in for all set text anchor functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidHorizontalTextAlignmentValue(int index);

    /// @brief Returns the number of valid values for the "vtext-anchor" attribute that can be used in for all set vertical text alignment functions.
    /// @return the number of valid values for the "vtext-anchor" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidVerticalTextAlignmentValues();

    /// @brief Returns the valid value with the given index for the "vtext-anchor" attribute that can be used in for all set vertical text alignment functions.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidVerticalTextAlignmentValue(int index);

    /// @brief Returns the number of valid values for the "fill-rule" attribute that can be used in for c_api_setFillRule function.
    /// @return the number of valid values for the "fill-rule" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidFillRuleValues();

    /// @brief Returns the valid value with the given index for the "fill-rule" attribute that can be used in for c_api_setFillRule function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidFillRuleValue(int index);

    /// @brief Returns the number of valid values for the "shape" attribute that can be sued in for c_api_setGeometricShape function.
    /// @return the number of valid values for the "shape" attribute.
    LIBSBMLNETWORK_EXTERN int c_api_getNumValidGeometricShapeValues();

    /// @brief Returns the valid value with the given index for the "shape" attribute that can be used in for c_api_setGeometricShape function.
    /// @param index an int representing the index of the valid value to retrieve.
    LIBSBMLNETWORK_EXTERN const char* c_api_getValidGeometricShapeValue(int index);
}

#ifdef __cplusplus
}
#endif

#endif