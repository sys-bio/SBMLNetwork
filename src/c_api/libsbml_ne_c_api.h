#ifndef __LIBSBML_NE_C_API_H_
#define __LIBSBML_NE_C_API_H_

#include "../libsbml_ne_sbmldocument.h"
#include "../libsbml_ne_sbmldocument_layout.h"

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
    LIBSBML_NETWORKEDITOR_EXTERN double c_api_getWidth(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setWidth(SBMLDocument* document, const double width, int layoutIndex = 0);

    /// @brief Returns the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the value of the "height" attribute of the Dimensions object of the Layout object.
    LIBSBML_NETWORKEDITOR_EXTERN double c_api_getHeight(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Sets the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
    /// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setHeight(SBMLDocument* document, const double height, int layoutIndex = 0);

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

    /// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex = 0);

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
    LIBSBML_NETWORKEDITOR_EXTERN int c_api_setRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, unsigned int layoutIndex = 0);

    /// @brief Returns the number of TextGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @return the number of TextGlyphs of this Layout object, or @c 0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex = 0);

    /// @brief Returns the number of TextGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
    /// associated with the entered graphical object id.
    /// @param document a pointer to the SBMLDocument object.
    /// @param layoutIndex the index number of the Layout to return.
    /// @param graphicalObjectId the id of the graphical object the number of TextGlyphs objects associated with it is going to be returned.
    /// @return the number of TextGlyphs objects associated with the entered graphical object id,
    /// or @c 0 if the object is @c NULL or has no associated TextGlyphs objects
    LIBSBML_NETWORKEDITOR_EXTERN const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* graphicalObjectId, int layoutIndex);



}

#ifdef __cplusplus
}
#endif

#endif