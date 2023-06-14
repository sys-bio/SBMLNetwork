#ifndef __LIBSBML_NE_UTIL_LAYOUT_H_
#define __LIBSBML_NE_UTIL_LAYOUT_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

/// @brief Get the Layout of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the Layout object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfLayouts* getListOfLayouts(SBMLDocument* document);

/// @brief Returns the number of items in the ListOfLayouts of this SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of items in of this SBML document, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLayouts(SBMLDocument* document);

/// @brief Returns a pointer to the nth Layout in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @return the @c the nth Layout in the ListOfLayouts of the SBML document or NULL if no such Layout exists or the document is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN Layout* getLayout(SBMLDocument* document, unsigned int n = 0);

/// @brief Add Layout to list of layouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addLayout(SBMLDocument* document, Layout* layout);

/// @brief Create a Layout object and add it to list of layouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the created Layout object.
LIBSBML_NETWORKEDITOR_EXTERN Layout* createLayout(SBMLDocument* document);

/// @brief Remove all the layout objects from the list of layouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeAllLayouts(SBMLDocument* document);

/// @brief Set all the necessary features for the layout object.
/// @param document a pointer to the SBMLDocument object.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout);

/// @brief Create a Layout object, add it to list of layouts of the SBML document, and
/// set all the necessary features for it
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultLayout(SBMLDocument* document);

/// @brief Returns the Dimensions object of the nth Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @return a pointer to the Dimensions object of the Layout object.
LIBSBML_NETWORKEDITOR_EXTERN Dimensions* getDimensions(SBMLDocument* document, unsigned int n = 0);

/// @brief Returns the value of the "width" attribute of the Dimensions object of the nth Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @return the value of the "width" attribute of the Dimensions object of the Layout object.
LIBSBML_NETWORKEDITOR_EXTERN double getDimensionWidth(SBMLDocument* document, unsigned int n = 0);

/// @brief Sets the value of the "width" attribute of the Dimensions object of the nth Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(SBMLDocument* document, unsigned int n, const double& width);

/// @brief Returns the value of the "height" attribute of the Dimensions object of the nth Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @return the value of the "height" attribute of the Dimensions object of the Layout object.
LIBSBML_NETWORKEDITOR_EXTERN double getDimensionHeight(SBMLDocument* document, unsigned int n = 0);

/// @brief Sets the value of the "height" attribute of the Dimensions object of the nth Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(SBMLDocument* document, unsigned int n, const double& height);

/// @brief Returns the number of CompartmentGlyphs of all Layout objects in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of CompartmentGlyphs of all Layout objects, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document);

/// @brief Returns the number of CompartmentGlyphs of the nth Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int n);

/// @brief Returns the number of CompartmentGlyphs of all Layout objects in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns the number of CompartmentGlyphs of the nth Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int n, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects of all Layout objects in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects of the nth Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param n the index number of the Layout to return.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, unsigned int n, const std::string& compartmentId);

/// @brief Returns the nth CompartmentGlyph object associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph object assoicated with it is going to be returned.
/// @param n the index number of the CompartmentGlyph object to return.
/// @return a pointer the nth CompartmentGlyph object associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int n = 0);

/// @brief Returns the number of SpeciesGlyph objects associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
/// @return the number of SpeciesGlyph objects associated with the entered species id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId);

/// @brief Returns a vector of SpeciesGlyph objects associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the SpeciesGlyph objects of which are going to be returned.
/// @return a vector of SpeciesGlyph objects associated with the entered species id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId);

/// @brief Returns the nth SpeciesGlyph object associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the SpeciesGlyph object associated with it is going to be returned.
/// @param n the index number of the SpeciesGlyph object to return.
/// @return a pointer the nth SpeciesGlyph object associated with the entered species id.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int n = 0);

/// @brief Returns the number of ReactionGlyph objects associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
/// @return the number of ReactionGlyph objects associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns a vector ReactionGlyph objects associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph objects of which are going to be returned.
/// @return a vector of ReactionGlyph objects associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the nth ReactionGlyph object associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph object associated with it is going to be returned.
/// @param n the index number of the ReactionGlyph object to return.
/// @return a pointer the nth ReactionGlyph object associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int n = 0);

/// @brief Returns the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph object associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index number of the SpeciesReferenceGlyph object to return.
/// @return a pointer to the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceGlyphIndex = 0);

/// Returns the id of the compartment associated with the graphical object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the id of the compartment associated with the graphical object, or @c "" if the object does not have an associated compartment or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN std::string getCompartmentId(SBMLDocument* document, GraphicalObject* graphicalObject);

/// Returns a pointer to the compartment associated with the graphical object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the compartment associated with the graphical object, or @c NULL if the object does not have an associated compartment or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN Compartment* getCompartment(SBMLDocument* document, GraphicalObject* graphicalObject);

}

#endif