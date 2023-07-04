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

/// @brief Returns a pointer to the Layout with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the @c the nth Layout in the ListOfLayouts of the SBML document or NULL if no such Layout exists or the document is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN Layout* getLayout(SBMLDocument* document, unsigned int layoutIndex = 0);

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

/// @brief Returns the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return a pointer to the Dimensions object of the Layout object.
LIBSBML_NETWORKEDITOR_EXTERN Dimensions* getDimensions(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the value of the "width" attribute of the Dimensions object of the Layout object.
LIBSBML_NETWORKEDITOR_EXTERN double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Sets the value of the "width" attribute of the Dimensions object of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the first Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(SBMLDocument* document, const double& width);

/// @brief Sets the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width);

/// @brief Returns the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the value of the "height" attribute of the Dimensions object of the Layout object.
LIBSBML_NETWORKEDITOR_EXTERN double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Sets the value of the "height" attribute of the Dimensions object of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the first Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(SBMLDocument* document, const double& height);

/// @brief Sets the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height);

/// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of GraphicalObjects of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of GraphicalObjects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the number of GraphicalObject objects associated with it is going to be returned.
/// @return the number of GraphicalObject objects associated with the entered model entity id,
/// or @c 0 if the object is @c NULL or has no associated GraphicalObject objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGraphicalObjects(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the number of GraphicalObject objects associated with it is going to be returned.
/// @return the number of GraphicalObject objects associated with the entered model entity id,
/// or @c 0 if the object is @c NULL or has no associated GraphicalObject objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns a vector of GraphicalObject objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject objects of which are going to be returned.
/// @return a vector of GraphicalObject objects associated with the entered model entity id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, const std::string& id);

/// @brief Returns a vector of CompartmentGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject objects of which are going to be returned.
/// @return a vector of GraphicalObject objects associated with the entered model entity id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the GraphicalObject object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it is going to be returned.
/// @param graphicalObjectIndex the index number of the GraphicalObject object to return.
/// @return a pointer the nth GraphicalObject object associated with the entered model entity id.
LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the GraphicalObject object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it is going to be returned.
/// @param graphicalObjectIndexIndex the index number of the GraphicalObject object to return.
/// @return a pointer the nth GraphicalObject object associated with the entered model entity id.
LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of CompartmentGlyphs of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId);

/// @brief Returns the CompartmentGlyph object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph object associated with it is going to be returned.
/// @param compartmentGlyphIndex the index number of the CompartmentGlyph object to return.
/// @return a pointer the nth CompartmentGlyph object associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int compartmentGlyphIndex = 0);

/// @brief Returns the CompartmentGlyph object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentId the id of the compartment the CompartmentGlyph object associated with it is going to be returned.
/// @param compartmentGlyphIndex the index number of the CompartmentGlyph object to return.
/// @return a pointer the nth CompartmentGlyph object associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId, unsigned int compartmentGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the first Layout object of the SBML document is of type CompartmentGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCompartmentGlyph(SBMLDocument* document, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type CompartmentGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of SpeciesGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of SpeciesGlyphs of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
/// @return the number of SpeciesGlyph objects associated with the entered species id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId);

/// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
/// @return the number of SpeciesGlyph objects associated with the entered speices id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId);

/// @brief Returns a vector of SpeciesGlyph objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the SpeciesGlyph objects of which are going to be returned.
/// @return a vector of SpeciesGlyph objects associated with the entered species id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId);

/// @brief Returns a vector of SpeciesGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesId the id of the species the SpeciesGlyph objects of which are going to be returned.
/// @return a vector of SpeciesGlyph objects associated with the entered species id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId);

/// @brief Returns the SpeciesGlyph object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the SpeciesGlyph object associated with it is going to be returned.
/// @param speciesGlyphIndex the index number of the SpeciesGlyph object to return.
/// @return a pointer the nth SpeciesGlyph object associated with the entered species id.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex = 0);

/// @brief Returns the SpeciesGlyph object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesId the id of the species the SpeciesGlyph object associated with it is going to be returned.
/// @param speciesGlyphIndex the index number of the SpeciesGlyph object to return.
/// @return a pointer the nth SpeciesGlyph object associated with the entered species id.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the first Layout object of the SBML document is of type SpeciesGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesGlyph(SBMLDocument* document, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the number of ReactionGlyph of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of ReactionGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of ReactionGlyphs of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
/// @return the number of ReactionGlyph objects associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
/// @return the number of ReactionGlyph objects associated with the entered speices id,
/// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId);

/// @brief Returns a vector of ReactionGlyph objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph objects of which are going to be returned.
/// @return a vector of ReactionGlyph objects associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns a vector of ReactionGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the ReactionGlyph objects of which are going to be returned.
/// @return a vector of ReactionGlyph objects associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId);

/// @brief Returns the ReactionGlyph object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph object associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return a pointer the nth ReactionGlyph object associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the ReactionGlyph object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the ReactionGlyph object associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return a pointer the nth ReactionGlyph object associated with the entered reaction id.
LIBSBML_NETWORKEDITOR_EXTERN ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the first Layout object of the SBML document is of type ReactionGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isReactionGlyph(SBMLDocument* document, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type ReactionGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceIndex the index of the SpeciesReferenceGlyph.
/// @return the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceIndex the index of the SpeciesReferenceGlyph.
/// @return the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species reference associated with SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph to return.
/// @return the value of the "species reference" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the ReactionGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesReferenceId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @breif Returns the id of the species reference associated with SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph to return.
/// @return the value of the "species reference" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the ReactionGlyph object does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesReferenceId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "speciesGlyph" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "speciesGlyph" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the givne index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object of the first ReactionGlyph object id of
///  the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRole(SBMLDocument* document, const std::string& reactionId, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object of the first ReactionGlyph object id of
///  the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object of the ReactionGlyph object with the given id of
///  the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the first SpeciesReferenceGlyph object of the ReactionGlyph object with the given id of
/// the Layout object with the given index of the SBML document.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given id of
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given id of
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role);

/// @brief Returns the number of TextGlyph objects of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of TextGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of TextGlyph objects associated with entered id in the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumTextGlyphs(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of TextGlyph objects associated with entered id of the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the TextGlyph objects associated with the given id in the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the TextGlyph object with the given id, or an empty vector if TextGlyph objects does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, const std::string& id);

/// @brief Returns the TextGlyph objects associated with the given id of the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the TextGlyph object with the given id, or an empty vector if TextGlyph objects does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id of the Layout object in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN TextGlyph* getTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetText(SBMLDocument* document, const std::string& id);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getText(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Sets the value of the "text" attribute of the first TextGlyph object associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(SBMLDocument* document, const std::string& id, const std::string& text);

/// @brief Sets the value of the "text" attribute of the first TextGlyph object associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const std::string& text);

/// @brief Sets the value of the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, const std::string& text);

/// @brief Sets the value of the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex, const std::string& text);

/// @brief Predicates returning @c true if the origin of text of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the origin of text of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Sets id of the origin of text of the first TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(SBMLDocument* document, const std::string& id, const std::string& orig);

/// @brief Sets id of the origin of text of the first TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const std::string& orig);

/// @brief Sets id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, const std::string& orig);

/// @brief Sets id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex, const std::string& orig);

/// @brief Predicates returning @c true if id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the id of the associated graphical object of this TextGlyph object is not the empty string, @c false if either the id
/// of the associated graphical object is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the id of the associated graphical object of this TextGlyph object is not the empty string, @c false if either the id
/// of the associated graphical object is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the associated graphical object of the TextGlyph object with the given index associated with the given id
/// in the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Sets the id of the associated graphical object of the first TextGlyph object associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(SBMLDocument* document, const std::string& id, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the first TextGlyph object associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the TextGlyph object with the given index associated with the given id
/// in the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex, const std::string& graphicalObjectId);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index associated with the given id in
/// the first Layout object of the SBML document is of type TextGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is of type TextGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// Returns the BoundingBox object of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return a pointer to the BoundingBox object of the GraphicalObject object associated with the entered id, or @c NULL if
/// the GraphicalObject object does not exits or the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN BoundingBox* getBoundingBox(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex = 0);

/// Returns the bounding box for the GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the bounding box for the GraphicalObject object, or @c NULL if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN BoundingBox* getBoundingBox(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "x" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "x" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(BoundingBox* boundingBox);

/// @brief Sets the value of the "x" attribute of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(Layout* layout, const std::string& id, const double& x);

/// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the bounding box of this GraphicalObject object associated with the object with the given id of the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param x a double value to use as the value of the "x" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(BoundingBox* boundingBox, const double& x);

/// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "y" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "y" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "y" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(BoundingBox* boundingBox);

/// @brief Sets the value of the "y" attribute of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionY(Layout* layout, const std::string& id, const double& y);

/// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the bounding box this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionY(GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param y a double value to use as the value of the "y" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setPositionY(BoundingBox* boundingBox, const double& y);

/// @brief Returns the value of the "width" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "width" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "width" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "width" attribute of the bounding box of the BoundingBox object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(BoundingBox* boundingBox);

/// @brief Sets the value of the "width" attribute of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(Layout* layout, const std::string& id, const double& width);

/// @brief Sets the value of the "width" attribute of the bounding box the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& width);

/// @brief Sets the value of the "width" attribute of the bounding box this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(GraphicalObject* graphicalObject, const double& width);

/// @brief Sets the value of the "width" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "width" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(BoundingBox* boundingBox, const double& width);

/// @brief Returns the value of the "height" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "height" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
    LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(BoundingBox* boundingBox);

/// @brief Sets the value of the "height" attribute of the bounding box of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(Layout* layout, const std::string& id, const double& height);

/// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject object with the given index of associated with the object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& height);

/// @brief Sets the value of the "height" attribute of this GraphicalObject object associated with the object with the given id of the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "height" attribute of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(GraphicalObject* graphicalObject, const double& height);

/// @brief Sets the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "height" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(BoundingBox* boundingBox, const double& height);





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