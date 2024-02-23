#ifndef __LIBSBML_NE_C_API_H_
#define __LIBSBML_NE_C_API_H_

#include "../libsbml_ne_sbmldocument.h"
#include "../libsbml_ne_sbmldocument_layout.h"
#include "../libsbml_ne_sbmldocument_render.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

    /// @brief Reads an SBML document from the given file name or the given text string
    /// @param sbml either the name or full pathname of the file to be read or a string containing a full SBML model.
    /// @return a pointer to the SBMLDocument structure created from the SBML content in the given file name or
    /// from the SBML content in the given text string.
    LIBSBML_NETWORKEDITOR_EXTERN SBMLDocument* c_api_readSBML(const char* sbml);

    /// @brief Writes the given SBML document to a filename.
    /// @param document the SBML document to be written.
    /// @param fileName the name or full pathname of the file where the SBML is to be written.
    /// @return true on success and false if the filename could not be opened for writing.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName);

    /// @brief Writes the given SBML document to a string and returns it.
    /// @param document the SBML document to be written.
    /// @return the string on success and empty string if one of the underlying parser components fail.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_writeSBMLToString(SBMLDocument* document);

    /// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
    /// to the the SBML document, and set all the necessary features for them.
    /// @param document a pointer to the SBMLDocument object.
    /// @param stiffness the stiffness value used in the autolayout algorithm.
    /// @param gravity the gravity value used in the autolayout algorithm.
    /// @param useMagnetism a variable that determines whether to use magnetism in the autolayout algorithm.
    /// @param useBoundary a variable that determines whether to use boundary restriction in the autolayout algorithm.
    /// @param useGrid a variable that determines whether to use grid restriction in the autolayout algorithm.
    /// @param lockedNodeIds an array of strings containing the ids of the nodes that should be locked in the autolayout algorithm.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_autolayout(SBMLDocument* document, const double stiffness = 10.0, const double gravity = 15.0,
                                                const bool useMagnetism = false, const bool useBoundary = false, const bool useGrid = false,
                                                const char** lockedNodeIds = NULL);

    /// @brief Returns the number of items in the ListOfLayouts of this SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of items in of this SBML document, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumLayouts(SBMLDocument* document);

    /// @brief Remove all the layout objects from the list of layouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_removeLayouts(SBMLDocument* document);

    /// @brief Returns the value of the "width" attribute of the Dimensions object of the Layout object
    /// with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "width" attribute of the Dimensions object of the Layout object.
    LIBSBML_NETWORKEDITOR_EXTERN double c_api_getCanvasWidth(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCanvasWidth(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "height" attribute of the Dimensions object of the Layout object.
    LIBSBML_NETWORKEDITOR_EXTERN double c_api_getCanvasHeight(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCanvasHeight(SBMLDocument* document, const double height, int layoutIndex = 0);

    /// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of GraphicalObjects of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllGraphicalObjects(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered model entity id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the number of GraphicalObject objects associated with it is going to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of GraphicalObject objects associated with the entered model entity id,
    /// or @c 0 if the object is @c NULL or has no associated GraphicalObject objects
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex = 0);

    /// @brief Returns the number of Compartment objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Compartment objects in the given SBML document.
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumCompartments(SBMLDocument* document);

    /// @brief Returns the id of the nth Compartment object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param index the index of the Compartment object.
    /// @return the id of the nth Compartment object in the given SBML document, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getNthCompartmentId(SBMLDocument* document, int index);

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns a list of the ids of the CompartmentGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return a list of the ids of the CompartmentGlyph objects of this Layout object, or an empty list if the object is @c NULL or contains
    /// no CompartmentGlyph objects
    LIBSBML_NETWORKEDITOR_EXTERN char** c_api_getListOfCompartmentGlyphIds(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered compartment id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
    /// @return the number of CompartmentGlyph objects associated with the entered compartment id,
    /// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type CompartmentGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0);

    /// @brief Returns the number of Species objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Species objects in the given SBML document.
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumSpecies(SBMLDocument* document);

    /// @brief Returns the id of the nth Species object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param index the index of the Species object.
    /// @return the id of the nth Species object in the given SBML document, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getNthSpeciesId(SBMLDocument* document, int index);

    /// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of SpeciesGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered species id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
    /// @return the number of SpeciesGlyph objects associated with the entered species id,
    /// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex = 0);

    /// @brief Returns the number of Reaction objects in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of Reaction objects in the given SBML document.
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumReactions(SBMLDocument* document);

    /// @brief Returns the id of the nth Reaction object in the given SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param index the index of the Reaction object.
    /// @return the id of the nth Reaction object in the given SBML document, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getNthReactionId(SBMLDocument* document, int index);

    /// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of ReactionGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllReactionsGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered reaction id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
    /// @return the number of ReactionGlyph objects associated with the entered reaction id,
    /// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex);

    /// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the GraphicalObject.
    /// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex = 0);

    /// @brief Returns the number of SpeciesReferences of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReference objects associated with it is going to be returned.
    /// @return the number of SpeciesReference objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumSpeciesReferences(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the number of Reactants of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of Reactant objects associated with it is going to be returned.
    /// @return the number of Reactant objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumReactants(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the number of Products of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of Product objects associated with it is going to be returned.
    /// @return the number of Product objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumProducts(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the number of Modifiers of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of Modifier objects associated with it is going to be returned.
    /// @return the number of Modifier objects of the Reaction object with the given id, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumModifiers(SBMLDocument* document, const char* reactionId);

    /// @brief Returns the id of nth Reactant of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the nth Reactant object associated with it is going to be returned.
    /// @param index the index of the Reactant object.
    /// @return the id of the nth Reactant object of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getNthReactantId(SBMLDocument* document, const char* reactionId, int index);

    /// @brief Returns the id of nth Product of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the nth Product object associated with it is going to be returned.
    /// @param index the index of the Product object.
    /// @return the id of the nth Product object of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getNthProductId(SBMLDocument* document, const char* reactionId, int index);

    /// @brief Returns the id of nth Modifier of the Reaction object with the given id in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the id of the nth Modifier object associated with it is going to be returned.
    /// @param index the index of the Modifier object.
    /// @return the id of the nth Modifier object of the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getNthModifierId(SBMLDocument* document, const char* reactionId, int index);

    /// @brief Returns the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
    /// or @c 0 if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "role"
    /// attribute is not set or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
    /// of the the Layout object with the givne index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
    /// the SpeciesReferenceGlyph does not exits or the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given id of
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
    /// @param reactionGlyphIndex the index of the ReactionGlyph.
    /// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
    /// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of TextGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of TextGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of TextGlyph objects associated with entered id of the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* id, int layoutIndex = 0);

    /// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id in
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
    /// , TextGlyph does not exits or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getText(SBMLDocument* document, const char* id, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Sets the "text" attribute of the TextGlyph object with the given index associated with the given id in
    /// the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
    /// @param text a string value to be set as "text" attribute of the TextGlyph object.
    /// @param textGlyphIndex the index of the TextGlyph to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setText(SBMLDocument* document, const char* id, const char* text, int textGlyphIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getX(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "width" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param width a double value to be set as "width" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject with the given index associated with
    /// the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param height a double value to be set as "height" attribute of the bounding box of the GraphicalObject object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Predicate returning true if the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document
    /// has a Curve object and the curve consists of one or more segments.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetCurve(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of curve segments of the curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
    /// or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumCurveSegments(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveStartPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the start point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveStartPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveStartPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the start point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveStartPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the end point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveEndPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the end point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveEndPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the end point of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveEndPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the end point of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveEndPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the base point 1 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveBasePoint1X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the base point 1 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveBasePoint1X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.

    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the base point 1 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveBasePoint1Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the base point 1 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveBasePoint1Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "x" attribute of the base point 2 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveBasePoint2X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param x a double value to be set as "x" attribute of the base point 2 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveBasePoint2X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the "y" attribute of the base point 2 of the the curve segment with the given index of the curve of this GraphicalObject object,
    /// or @c 0.0 if the object is @c NULL or does not have a curve
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getCurveBasePoint2Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Sets the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
    /// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
    /// @param y a double value to be set as "y" attribute of the base point 2 of the curve segment of the curve of the GraphicalObject object.
    /// @param graphicalObjectIndex the index of the GraphicalObject to return.
    /// @param curveSegmentIndex an int representing the index of the curve segment to retrieve.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setCurveBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0);

    /// @brief Returns the number of items in the ListOfGlobalRenderInformation of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return the number of items in the ListOfGlobalRenderInformation of the SBML document, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumGlobalRenderInformation(SBMLDocument* document);

    /// @brief Returns the number of items in the ListOfGlobalRenderInformation of the Layout object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout object.
    /// @return the number of items in the ListOfGlobalRenderInformation of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Remove all the global and local render information objects from the list of global renders of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_removeRenderInformation(SBMLDocument* document);

    /// @brief Remove all the global render information objects from the list of global renders of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_removeGlobalRenderInformation(SBMLDocument* document);

    /// @brief Remove all the local render information objects from the list of local renders of the Layout with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_removeLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Predicates returning @c true if the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return @c true if the "backgroundColor" attribute of this GlobalRenderInformation object is set, @c false if either the "backgroundColor"
    /// attribute is not set or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetBackgroundColor(SBMLDocument* document, int renderIndex = 0);

    /// @brief Returns the value of the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return the "backgroundColor" attribute of this RenderInformationBase object, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getBackgroundColor(SBMLDocument* document, int renderIndex = 0);

    /// @brief Sets the value of the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param backgroundColor a string value to use as the value of the "backgroundColor" attribute of this RenderInformationBase object.
    /// @param renderIndex the index number of the GlobalRenderInformation object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setBackgroundColor(SBMLDocument* document, const char* backgroundColor, int renderIndex = 0);

    /// @brief Returns the number of ColorDefinitions of the RenderInformationBase object with the given index of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the number of ColorDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumColors(SBMLDocument* document, int renderIndex = 0);

    /// @brief Predicates returning @c true if the "value" attribute of the ColorDefinition with the given identifier
    /// in the RenderInformationBase with the given index is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the ColorDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
    /// attribute is not set or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetColorValue(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Returns the value of the "value" attribute of the ColorDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the ColorDefinition to retrieve.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getColorValue(SBMLDocument* document, const char* id, int renderIndex = 0);

    /// @brief Sets the value of the "value" attribute of the ColorDefinition with the given identifier in the RenderInformationBase with the given index.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id a string representing the identifier of the ColorDefinition to retrieve.
    /// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
    /// @param renderIndex the index number of the RenderInformationBase object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setColorValue(SBMLDocument* document, const char* id, const char* value, int renderIndex);

    /// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is set.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetBorderColor(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getBorderColor(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setBorderColor(SBMLDocument* document, const char* id, const char* borderColor);

    /// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-width"
    /// attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetBorderWidth(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getBorderWidth(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param borderWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setBorderWidth(SBMLDocument* document, const char* id, const double borderWidth);

    /// @brief Predicates returning @c true if the "fill" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "fill" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill"
    /// attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFillColor(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "fill" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getFillColor(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFillColor(SBMLDocument* document, const char* id, const char* fillColor);

    /// @brief Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill-rule"
    /// attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFillRule(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getFillRule(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFillRule(SBMLDocument* document, const char* id, const char* fillRule);

    /// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
    /// attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFontColor(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getFontColor(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFontColor(SBMLDocument* document, const char* id, const char* fontColor);

/// @brief Predicates returning @c true if the "font-family" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-family"
    /// attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFontFamily(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getFontFamily(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFontFamily(SBMLDocument* document, const char* id, const char* fontFamily);

    /// @brief Predicates returning @c true if the "font-size" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-size"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFontSize(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getFontSize(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize);

    /// @brief Predicates returning @c true if the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-weight"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFontWeight(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getFontWeight(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFontWeight(SBMLDocument* document, const char* id, const char* fontWeight);

    /// @brief Predicates returning @c true if the "font-style" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-style"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetFontStyle(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getFontStyle(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setFontStyle(SBMLDocument* document, const char* id, const char* fontStyle);

    /// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "text-anchor"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetTextHorizontalAlignment(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getTextHorizontalAlignment(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param textHorizontalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setTextHorizontalAlignment(SBMLDocument* document, const char* id, const char* textHorizontalAlignment);

    /// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "text-anchor"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetTextVerticalAlignment(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getTextVerticalAlignment(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param textVerticalAlignment a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setTextVerticalAlignment(SBMLDocument* document, const char* id, const char* textVerticalAlignment);

    /// @brief Predicates returning @c true if the "startHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "startHead"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetStartHead(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "startHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getStartHead(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "startHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param startHead a string value to use as the value of the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setStartHead(SBMLDocument* document, const char* id, const char* startHead);

    /// @brief Predicates returning @c true if the "endHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return @c true if the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "endHead"
    /// attribute is not set
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetEndHead(SBMLDocument* document, const char* id);

    /// @brief Returns the value of the "endHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getEndHead(SBMLDocument* document, const char* id);

    /// @brief Sets the value of the "endHead" attribute of the RenderGroup of the Style that matches this id of model entity associated with the GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param endHead a string value to use as the value of the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setEndHead(SBMLDocument* document, const char* id, const char* endHead);

    /// @brief Returns number of Transformation2D objects in the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @return the number of Transformation2D objects in the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_getNumGeometricShapes(SBMLDocument* document, const char* id);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Rectangle.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Rectangle, @c false if
    /// it is not of type Rectangle or is or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Ellipse.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Ellipse, @c false if
    /// it is not of type Ellipse or is or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Polygon.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Polygon, @c false if
    /// it is not of type Polygon or is or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Image.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Image, @c false if
    /// it is not of type Image or is or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type RenderCurve.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCurve, @c false if
    /// it is not of type RenderCurve or is or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0);
    
    /// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject is of type Text.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Text, @c false if
    /// it is not of type Text or is or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
    /// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeRatio(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param borderRadiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param borderRadiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param centerX a double to use as the value of the "cx" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param centerY a double to use as the value of the "cy" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param radiusX a double to use as the value of the "rx" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @param radiusY a double to use as the value of the "ry" attribute of this Transformation2D object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the number of elements of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the number of elements of the Transformation2D object at the given index of the RenderGroup of this Style for this GraphicalObject, or @c 0 if
    /// either Transformation2D object does not exists, does not have any elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const unsigned int c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param x a double to use as the value of the "x" attribute of this element.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param y a double to use as the value of the "y" attribute of this element.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the base point 1 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param x a double to use as the value of the "x" attribute of base point 1 of this element.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the base point 1 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param y a double to use as the value of the "y" attribute of base point 1 of this element.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "x" attribute of the base point 2 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param x a double to use as the value of the "x" attribute of base point 2 of this element.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "y" attribute of the base point 2 of the nth element of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if
    /// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const double c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param segmentIndex an unsigned int representing the index of the element to retrieve.
    /// @param y a double to use as the value of the "y" attribute of base point 2 of this element.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, unsigned int segmentIndex = 0, unsigned int geometricShapeIndex = 0);

    /// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return @c true if the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
    /// @c false if either the "href" attribute is not set or the object is @c NULL .
    LIBSBML_NETWORKEDITOR_EXTERN bool c_api_isSetGeometricShapeHref(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Returns the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c NULL if
    /// either Transformation2D object does not exists, does not have "href" attribute, it is not set, or the object is @c NULL.
    LIBSBML_NETWORKEDITOR_EXTERN const char* c_api_getGeometricShapeHref(SBMLDocument* document, const char* id, unsigned int geometricShapeIndex = 0);

    /// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this id of model entity associated with GraphicalObject.
    /// @param document a pointer to the SBMLDocument object.
    /// @param id the id of a model entity.
    /// @param href a string to use as the value of the "href" attribute of this Transformation2D object.
    /// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, unsigned int geometricShapeIndex = 0);
}

#ifdef __cplusplus
}
#endif

#endif