#ifndef __LIBSBMLNETWORK_SBMLDOCUMENT_LAYOUT_H_
#define __LIBSBMLNETWORK_SBMLDOCUMENT_LAYOUT_H_

#include "libsbmlnetwork_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

/// @brief Get the Layout of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the Layout object of the SBML document.
LIBSBMLNETWORK_EXTERN ListOfLayouts* getListOfLayouts(SBMLDocument* document);

/// @brief Returns the number of items in the ListOfLayouts of this SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of items in of this SBML document, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumLayouts(SBMLDocument* document);

/// @brief Returns a pointer to the Layout with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the @c the nth Layout in the ListOfLayouts of the SBML document or NULL if no such Layout exists or the document is @c NULL.
LIBSBMLNETWORK_EXTERN Layout* getLayout(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Add Layout to list of layouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addLayout(SBMLDocument* document, Layout* layout);

/// @brief Create a Layout object and add it to list of layouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the created Layout object.
LIBSBMLNETWORK_EXTERN Layout* createLayout(SBMLDocument* document);

/// @brief Remove all the layout objects from the list of layouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeAllLayouts(SBMLDocument* document);

/// @brief Set all the necessary features for the layout object.
/// @param document a pointer to the SBMLDocument object.
/// @param layout a pointer to the Layout object.
/// @param maxNumConnectedEdges the maximum number of connected edges before creating an alias SpeciesGlyph.
/// @param useNameAsTextLabel a variable that determines whether to use the name of the model entities as text labels in the autolayout algorithm.
/// @param resetLockedNodes a variable that determines whether to reset the locked nodes in the autolayout algorithm.
/// @param lockedNodesSet a set of ids of the model entities and the graphical objects indices that are going to be locked in the autolayout algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDefaultLayoutLocations(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true,
                                                          bool resetLockedNodes = false, const std::set<std::pair<std::string, std::vector<int>>> lockedNodesSet = {});

/// @brief Create a Layout object, add it to list of layouts of the SBML document, set all the necessary features for it, and apply autolayout algorithm.
/// @param document a pointer to the SBMLDocument object.
/// @param maxNumConnectedEdges the maximum number of connected edges before creating an alias SpeciesGlyph.
/// @param useNameAsTextLabel a variable that determines whether to use the name of the model entities as text labels in the autolayout algorithm.
/// @param resetLockedNodes a variable that determines whether to reset the locked nodes in the autolayout algorithm.
/// @param lockedNodeIds a set of ids of the model entities and their graphical objects indices that are going to be locked in the autolayout algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int createDefaultLayoutLocations(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true,
                                                     bool resetLockedNodes = false, const std::set<std::pair<std::string, std::vector<int>>> lockedNodesSet = {});

/// @brief Create a Layout object, add it to list of layouts of the SBML document, and set all the necessary features for it.
/// @param document a pointer to the SBMLDocument object.
/// @param maxNumConnectedEdges the maximum number of connected edges before creating an alias SpeciesGlyph.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int createDefaultLayoutFeatures(SBMLDocument* document, const int maxNumConnectedEdges = 3);

/// @brief lock all the species and reaction nodes in the layout and apply autolayout
/// @param document a pointer to the SBMLDocument object.
/// @param layout a pointer to the Layout object.
/// @param updatedGraphicalObject a set of the ids of the GraphicalObject objects the position of which has been updated recently.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int updateLayoutCurves(SBMLDocument* document, Layout* layout);

/// @brief Returns the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return a pointer to the Dimensions object of the Layout object.
LIBSBMLNETWORK_EXTERN Dimensions* getDimensions(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the value of the "width" attribute of the Dimensions object of the Layout object.
LIBSBMLNETWORK_EXTERN double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Sets the value of the "width" attribute of the Dimensions object of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the first Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(SBMLDocument* document, const double& width);

/// @brief Sets the value of the "width" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width);

/// @brief Returns the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the value of the "height" attribute of the Dimensions object of the Layout object.
LIBSBMLNETWORK_EXTERN double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Sets the value of the "height" attribute of the Dimensions object of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the first Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(SBMLDocument* document, const double& height);

/// @brief Sets the value of the "height" attribute of the Dimensions object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height);

/// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of GraphicalObjects of this Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of GraphicalObjects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the number of GraphicalObject objects associated with it is going to be returned.
/// @return the number of GraphicalObject objects associated with the entered model entity id,
/// or @c 0 if the object is @c NULL or has no associated GraphicalObject objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumGraphicalObjects(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of GraphicalObjects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the number of GraphicalObject objects associated with it is going to be returned.
/// @return the number of GraphicalObject objects associated with the entered model entity id,
/// or @c 0 if the object is @c NULL or has no associated GraphicalObject objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns a vector of GraphicalObject objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject objects of which are going to be returned.
/// @return a vector of GraphicalObject objects associated with the entered model entity id.
LIBSBMLNETWORK_EXTERN std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, const std::string& id);

/// @brief Returns a vector of CompartmentGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject objects of which are going to be returned.
/// @return a vector of GraphicalObject objects associated with the entered model entity id.
LIBSBMLNETWORK_EXTERN std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the GraphicalObject object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it is going to be returned.
/// @param graphicalObjectIndex the index number of the GraphicalObject object to return.
/// @return a pointer the nth GraphicalObject object associated with the entered model entity id.
LIBSBMLNETWORK_EXTERN GraphicalObject* getGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the GraphicalObject object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it is going to be returned.
/// @param graphicalObjectIndexIndex the index number of the GraphicalObject object to return.
/// @return a pointer the nth GraphicalObject object associated with the entered model entity id.
LIBSBMLNETWORK_EXTERN GraphicalObject* getGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of CompartmentGlyphs of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns the number of CompartmentGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBMLNETWORK_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBMLNETWORK_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId);

/// @brief Returns the CompartmentGlyph object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph object associated with it is going to be returned.
/// @param compartmentGlyphIndex the index number of the CompartmentGlyph object to return.
/// @return a pointer the nth CompartmentGlyph object associated with the entered compartment id.
LIBSBMLNETWORK_EXTERN CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int compartmentGlyphIndex = 0);

/// @brief Returns the CompartmentGlyph object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentId the id of the compartment the CompartmentGlyph object associated with it is going to be returned.
/// @param compartmentGlyphIndex the index number of the CompartmentGlyph object to return.
/// @return a pointer to the nth CompartmentGlyph object associated with the entered compartment id.
LIBSBMLNETWORK_EXTERN CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId, unsigned int compartmentGlyphIndex = 0);

/// @brief Returns the CompartmentGlyph object with the given index in the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param compartmentGlyphIndex the index number of the CompartmentGlyph object to return.
/// @return a pointer to the CompartmentGlyph object with the given index in the ListOfCompartmentGlyphs of the Layout object.
LIBSBMLNETWORK_EXTERN  CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int compartmentGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the first Layout object of the SBML document is of type CompartmentGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isCompartmentGlyph(SBMLDocument* document, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type CompartmentGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// Returns the id of the compartment associated with the GraphicalObject with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the id of the compartment associated with the graphical object, or @c "" if the object does not have an associated compartment or is @c NULL
LIBSBMLNETWORK_EXTERN std::string getCompartmentId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// Returns the id of the compartment associated with the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the id of the compartment associated with the graphical object, or @c "" if the object does not have an associated compartment or is @c NULL
LIBSBMLNETWORK_EXTERN std::string getCompartmentId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// Returns the id of the compartment associated with the graphical object.
/// @param document a pointer to the SBMLDocument object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the id of the compartment associated with the graphical object, or @c "" if the object does not have an associated compartment or is @c NULL
LIBSBMLNETWORK_EXTERN std::string getCompartmentId(SBMLDocument* document, GraphicalObject* graphicalObject);

/// Returns a pointer to the compartment associated with the GraphicalObject with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return a pointer to the compartment associated with the graphical object, or @c NULL if the object does not have an associated compartment or is @c NULL
LIBSBMLNETWORK_EXTERN Compartment* getAssociatedCompartment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// Returns a pointer to the compartment associated with the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return a pointer to the compartment associated with the graphical object, or @c NULL if the object does not have an associated compartment or is @c NULL
LIBSBMLNETWORK_EXTERN Compartment* getAssociatedCompartment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// Returns a pointer to the compartment associated with the GraphicalObject object.
/// @param document a pointer to the SBMLDocument object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the compartment associated with the graphical object, or @c NULL if the object does not have an associated compartment or is @c NULL
LIBSBMLNETWORK_EXTERN Compartment* getAssociatedCompartment(SBMLDocument* document, GraphicalObject* graphicalObject);

/// @brief Returns the ids of the SpeciesGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the ids of the SpeciesGlyph objects of this Layout object
LIBSBMLNETWORK_EXTERN std::vector<std::string> getSpeciesGlyphsIds(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of SpeciesGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of SpeciesGlyphs of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
/// @return the number of SpeciesGlyph objects associated with the entered species id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId);

/// @brief Returns the number of SpeciesGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesId the id of the species the number of SpeciesGlyph objects associated with it is going to be returned.
/// @return the number of SpeciesGlyph objects associated with the entered speices id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesGlyph objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId);

/// @brief Returns a vector of SpeciesGlyph objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the SpeciesGlyph objects of which are going to be returned.
/// @return a vector of SpeciesGlyph objects associated with the entered species id.
LIBSBMLNETWORK_EXTERN std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId);

/// @brief Returns a vector of SpeciesGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesId the id of the species the SpeciesGlyph objects of which are going to be returned.
/// @return a vector of SpeciesGlyph objects associated with the entered species id.
LIBSBMLNETWORK_EXTERN std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId);

/// @brief Returns the SpeciesGlyph object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param speciesId the id of the species the SpeciesGlyph object associated with it is going to be returned.
/// @param speciesGlyphIndex the index number of the SpeciesGlyph object to return.
/// @return a pointer the nth SpeciesGlyph object associated with the entered species id.
LIBSBMLNETWORK_EXTERN SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex = 0);

/// @brief Returns the SpeciesGlyph object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered species id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesId the id of the species the SpeciesGlyph object associated with it is going to be returned.
/// @param speciesGlyphIndex the index number of the SpeciesGlyph object to return.
/// @return a pointer the nth SpeciesGlyph object associated with the entered species id.
LIBSBMLNETWORK_EXTERN SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex = 0);

/// @brief Returns the SpeciesGlyph object with the given index in the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param speciesGlyphIndex the index number of the SpeciesGlyph object to return.
/// @return a pointer to the nth SpeciesGlyph object with the given index in the ListOfSpeciesGlyphs of the Layout object.
LIBSBMLNETWORK_EXTERN  SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int speciesGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the first Layout object of the SBML document is of type SpeciesGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesGlyph(SBMLDocument* document, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type SpeciesGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the ids of the ReactionGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the ids of the ReactionGlyph objects of this Layout object
LIBSBMLNETWORK_EXTERN std::vector<std::string> getReactionGlyphsIds(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of ReactionGlyph of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of ReactionGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of ReactionGlyphs of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
/// @return the number of ReactionGlyph objects associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the number of ReactionGlyphs of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of ReactionGlyph objects associated with it is going to be returned.
/// @return the number of ReactionGlyph objects associated with the entered speices id,
/// or @c 0 if the object is @c NULL or has no associated ReactionGlyph objects
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId);

/// @brief Returns a vector of ReactionGlyph objects of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph objects of which are going to be returned.
/// @return a vector of ReactionGlyph objects associated with the entered reaction id.
LIBSBMLNETWORK_EXTERN std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns a vector of ReactionGlyph objects of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the ReactionGlyph objects of which are going to be returned.
/// @return a vector of ReactionGlyph objects associated with the entered reaction id.
LIBSBMLNETWORK_EXTERN std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId);

/// @brief Returns the ReactionGlyph object with the given index of the first Layout object in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the ReactionGlyph object associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return a pointer the nth ReactionGlyph object associated with the entered reaction id.
LIBSBMLNETWORK_EXTERN ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the ReactionGlyph object with the given index of the Layout object with the given index in the ListOfLayouts of the SBML document
/// associated with the entered reaction id.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the ReactionGlyph object associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return a pointer the nth ReactionGlyph object associated with the entered reaction id.
LIBSBMLNETWORK_EXTERN ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the ReactionGlyph object with the given index in the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return a pointer to the nth ReactionGlyph object with the given index in the ListOfReactionGlyphs of the Layout object.
LIBSBMLNETWORK_EXTERN  ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int reactionGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the first Layout object of the SBML document is of type ReactionGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isReactionGlyph(SBMLDocument* document, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id in the Layout object with the given index of the SBML document is of type ReactionGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the number of SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or @c 0 if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBMLNETWORK_EXTERN std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @return the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBMLNETWORK_EXTERN std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceIndex the index of the SpeciesReferenceGlyph.
/// @return the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBMLNETWORK_EXTERN SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceIndex the index of the SpeciesReferenceGlyph.
/// @return the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id,
/// or an empty vector if the object is @c NULL or has no associated SpeciesReferenceGlyph objects.
LIBSBMLNETWORK_EXTERN SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species reference associated with SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph to return.
/// @return the value of the "species reference" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the ReactionGlyph does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @breif Returns the id of the species reference associated with SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph to return.
/// @return the value of the "species reference" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the ReactionGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the id of the "species" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "speciesGlyph" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "speciesGlyph" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object with the given index is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index number of the ReactionGlyph object to return.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the the Layout object with the givne index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object of the first ReactionGlyph object id of
///  the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object of the first ReactionGlyph object id of
///  the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object of the ReactionGlyph object with the given id of
///  the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the first SpeciesReferenceGlyph object of the ReactionGlyph object with the given id of
/// the Layout object with the given index of the SBML document.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given id of
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given id of
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role);

/// @brief Predicate returning @c true if the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the the ListOfLayouts of the SBML document has a Curve object and the curve consists of one or more segments.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return @c true if the SpeciesReferenceGlyph object has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Predicate returning @c true if the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document has a Curve object and the curve consists of one or more segments.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return @c true if the SpeciesReferenceGlyph object has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return a pointer to the Curve object of the SpeciesReferenceGlyph object with the given index, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN Curve* getSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return a pointer to the Curve object of the SpeciesReferenceGlyph object with the given index, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN Curve* getSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the number of curve segments of the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the number of curve segments of the Curve object of the SpeciesReferenceGlyph object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the number of curve segments of the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return the number of curve segments of the Curve object of the SpeciesReferenceGlyph object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferenceCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns a pointer to the curve segment with the given index of the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return a pointer to the LineSegment object with the given index, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN LineSegment* getSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns a pointer to the curve segment with the given index of the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the number of SpeciesReferenceGlyph objects of its ReactionGlyph object with the given index associated with it is going to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return a pointer to the LineSegment object with the given index, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN LineSegment* getSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Creates a new LineSegment and adds it to the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return a pointer to the newly created LineSegment object, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN LineSegment* createSpeciesReferenceLineCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Creates a new LineSegment and adds it to the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return a pointer to the newly created LineSegment object, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN LineSegment* createSpeciesReferenceLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Creates a new CubicBezier object and adds it to the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return a pointer to the newly created CubicBezier object, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN CubicBezier* createSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Creates a new CubicBezier object and adds it to the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @return a pointer to the newly created CubicBezier object, or @c NULL if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN CubicBezier* createSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Removes the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Removes the Curve object of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Predicate returning true if the curve segment with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts is of type CubicBezier.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return @c true if the curve segment with the given index is of type CubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Predicate returning true if the curve segment with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts is of type CubicBezier.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return @c true if the curve segment with the given index is of type CubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the start point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the start point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @breif Returns the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Returns the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @breif Returns the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Returns the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the end point of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the end point of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @breif Returns the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Returns the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 1 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @breif Returns the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Returns the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param x the value to be set as "x" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x);

/// @breif Returns the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @breif Returns the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @return the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index, or @c 0 if
/// the SpeciesReferenceGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN double getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the first Layout object in the first ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the first ReactionGlyph object of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the first Layout object in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the CubicBezier object with the given index of the Curve of the SpeciesReferenceGlyph object with the given index of the ReactionGlyph object with the given index associated with the entered reaction id
/// of the Layout object with the given index in the ListOfLayouts of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param reactionId the id of the reaction the SpeciesReferenceGlyph object of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceGlyphIndex the index of the SpeciesReferenceGlyph.
/// @param curveSegmentIndex the index of the CurveSegment.
/// @param y the value to be set as "y" attribute of the base point 2 of the CubicBezier object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the number of TextGlyph objects of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @return the number of TextGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of TextGlyph objects associated with entered id in the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumTextGlyphs(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the number of TextGlyph objects associated with entered id of the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the TextGlyph objects associated with the given id in the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the TextGlyph object with the given id, or an empty vector if TextGlyph objects does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, const std::string& id);

/// @brief Returns the TextGlyph objects associated with the given id of the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the TextGlyph object with the given id, or an empty vector if TextGlyph objects does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id of the Layout object in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN TextGlyph* getTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id of the Layout object in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN TextGlyph* getTextGlyph(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetText(SBMLDocument* document, const std::string& id);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id);

/// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets the value of the "text" attribute of the first TextGlyph object associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Sets the value of the "text" attribute of the first TextGlyph object associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Sets the value of the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text);

/// @brief Sets the value of the "text" attribute of TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text);

/// @brief Adds a new TextGlyph object to the first Layout object of the SBML document and associates it with the given GraphicalObject object.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Adds a new TextGlyph object to the Layout object with the given index of the SBML document and associates it with the given GraphicalObject object.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Removes the TextGlyph object with the given index associated with the given id in the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex);

/// @brief Removes the TextGlyph object with the given index associated with the given id in the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex);

/// @brief Predicates returning @c true if the origin of text of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the origin of text of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets id of the origin of text of the first TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig);

/// @brief Sets id of the origin of text of the first TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig);

/// @brief Sets id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig);

/// @brief Sets id of the origin of text of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig);

/// @brief Predicates returning @c true if id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the id of the associated graphical object of this TextGlyph object is not the empty string, @c false if either the id
/// of the associated graphical object is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is not the empty string.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the id of the associated graphical object of this TextGlyph object is not the empty string, @c false if either the id
/// of the associated graphical object is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the associated graphical object of the TextGlyph object with the given index associated with the given id
/// in the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets the id of the associated graphical object of the first TextGlyph object associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the first TextGlyph object associated with the given id in
/// the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the TextGlyph object with the given index associated with the given id in
/// the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the TextGlyph object with the given index associated with the given id
/// in the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index associated with the given id in
/// the first Layout object of the SBML document is of type TextGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index associated with the given id in
/// the Layout object with the given index of the SBML document is of type TextGlyph.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0);

/// Returns the BoundingBox object of the GraphicalObject with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @return a pointer to the BoundingBox object of the GraphicalObject object associated with the entered id, or @c NULL if
/// the GraphicalObject object does not exits or the object is @c NULL
    LIBSBMLNETWORK_EXTERN BoundingBox* getBoundingBox(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// Returns the BoundingBox object of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return a pointer to the BoundingBox object of the GraphicalObject object associated with the entered id, or @c NULL if
/// the GraphicalObject object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN BoundingBox* getBoundingBox(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with
/// the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with
/// the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Sets the value of the "x" attribute of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(SBMLDocument* document, const std::string& id, const double& x, bool updateCurves = true);

/// @brief Sets the value of the "x" attribute of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, bool updateCurves = true);

/// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, bool updateCurves = true);

/// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, bool updateCurves = true);

/// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Sets the value of the "y" attribute of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(SBMLDocument* document, const std::string& id, const double& y, bool updateCurves = true);

/// @brief Sets the value of the "y" attribute of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y, bool updateCurves = true);

/// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y, bool updateCurves = true);

/// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y, bool updateCurves = true);

/// @breif Sets th value of the "x" and "y" attributes of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y, bool updateCurves = true);

/// @breif Sets th value of the "x" and "y" attributes of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y, bool updateCurves = true);

/// @breif Sets th value of the "x" and "y" attributes of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y, bool updateCurves = true);

/// @breif Sets th value of the "x" and "y" attributes of the bounding box of the GraphicalObject with the given index associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y, bool updateCurves = true);

/// @brief Returns the value of the "width" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with
/// the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "width" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with
/// the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Sets the value of the "width" attribute of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(SBMLDocument* document, const std::string& id, const double& width, bool updateCurves = true);

/// @brief Sets the value of the "width" attribute of the bounding box of the first GraphicalObject associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width, bool updateCurves = true);

/// @brief Sets the value of the "width" attribute of the bounding box the GraphicalObject with the given index associated with the model entity with
/// the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width, bool updateCurves = true);

/// @brief Sets the value of the "width" attribute of the bounding box the GraphicalObject with the given index associated with the model entity with
/// the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width, bool updateCurves = true);

/// @brief Sets the value of the "width" attribute the bounding box of all the CompartmentGlyph objects in the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of all the CompartmentGlyph objects.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves = true);

/// @brief Returns the default value of the "width" attribute of the bounding box of the SpeciesGlyph objects.
/// @return the default "width" attribute of the bounding box of the SpeciesGlyph objects.
LIBSBMLNETWORK_EXTERN const double getSpeciesDimensionWidth();

/// @brief Sets the value of the "width" attribute the bounding box of all the SpeciesGlyph objects in the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of all the SpeciesGlyph objects.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves = true);

/// @brief Returns the default value of the "width" attribute of the bounding box of the ReactionGlyph objects.
/// @return the default "width" attribute of the bounding box of the ReactionGlyph objects.
LIBSBMLNETWORK_EXTERN const double getReactionDimensionWidth();

/// @brief Sets the value of the "width" attribute the bounding box of all the ReactionGlyph objects in the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of all the ReactionGlyph objects.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves = true);

/// @brief Returns the value of the "height" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with
/// the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "height" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with
/// the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Sets the value of the "height" attribute of the bounding box of the bounding box of the first GraphicalObject associated with
/// the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(SBMLDocument* document, const std::string& id, const double& height, bool updateCurves = true);

/// @brief Sets the value of the "height" attribute of the bounding box of the bounding box of the first GraphicalObject associated with
/// the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height, bool updateCurves = true);

/// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject object with the given index of associated with
/// the object with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height, bool updateCurves = true);

/// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject object with the given index of associated with
/// the object with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height, bool updateCurves = true);

/// @brief Sets the value of the "height" attribute of the bounding box of all the CompartmentGlyph objects in the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of all the CompartmentGlyph objects.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves = true);

/// @brief Returns the default value of the "height" attribute of the bounding box of the SpeciesGlyph objects.
/// @return the default "height" attribute of the bounding box of the SpeciesGlyph objects.
LIBSBMLNETWORK_EXTERN const double getSpeciesDimensionHeight();

/// @brief Sets the value of the "height" attribute of the bounding box of all the SpeciesGlyph objects in the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of all the SpeciesGlyph objects.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves = true);

/// @brief Returns the default value of the "height" attribute of the bounding box of the ReactionGlyph objects.
/// @return the default "height" attribute of the bounding box of the ReactionGlyph objects.
LIBSBMLNETWORK_EXTERN const double getReactionDimensionHeight();

/// @brief Sets the value of the "height" attribute of the bounding box of all the ReactionGlyph objects in the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of all the ReactionGlyph objects.
/// @param updateCurves a boolean value, indicating whether the rest of the layout curves (with locked nodes) should be adjusted.  Default 'true'.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves = true);

/// @brief Retrieves the "x" position of a TextGlyph object within a specific layout.
/// This function fetches the "x" coordinate of the bounding box of a TextGlyph object, identified by its associated model entity ID and within a specified layout of the SBML document. The layout is determined by its index. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object or the layout does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The "x" position of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Retrieves the "x" position of a TextGlyph object within a specific layout.
/// This function fetches the "x" coordinate of the bounding box of a TextGlyph object, identified by its index and associated with a model entity identified by its ID, within a specified layout of the SBML document. The layout is determined by its index. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object or the layout does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document from which to retrieve the TextGlyph object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The "x" position of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets the "x" position of a TextGlyph object within the first layout of the SBML document.
/// This function assigns a new "x" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionX(SBMLDocument* document, const std::string& id, const double& x);

/// @brief Sets the "x" position of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns a new "x" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID and within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x);

/// @brief Sets the "x" position of a TextGlyph object, identified by graphical object index, within the first layout of the SBML document.
/// This function assigns a new "x" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x);

/// @brief Sets the "x" position of a TextGlyph object, identified by graphical object index, within a specific layout of the SBML document.
/// This function assigns a new "x" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x);

/// @brief Sets the "x" position of a TextGlyph object, identified by both graphical and text glyph indices, within the first layout of the SBML document.
/// This function assigns a new "x" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x);

/// @brief Sets the "x" position of a TextGlyph object, identified by both graphical and text glyph indices, within a specific layout of the SBML document.
/// This function assigns a new "x" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x);

/// @brief Retrieves the "y" position of a TextGlyph object within the first layout of the SBML document.
/// This function fetches the "y" coordinate of the bounding box of a TextGlyph object, identified by its index and associated with a model entity identified by its ID, within the first layout of the SBML document. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The "y" position of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Retrieves the "y" position of a TextGlyph object within a specific layout of the SBML document.
/// This function fetches the "y" coordinate of the bounding box of a TextGlyph object, identified by its index and associated with a model entity identified by its ID, within a specified layout of the SBML document. The layout is determined by its index. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object or the layout does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document from which to retrieve the TextGlyph object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The "y" position of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets the "y" position of a TextGlyph object within the first layout of the SBML document.
/// This function assigns a new "y" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionY(SBMLDocument* document, const std::string& id, const double& y);

/// @brief Sets the "y" position of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns a new "y" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID and within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y);

/// @brief Sets the "y" position of a TextGlyph object, identified by graphical object index, within the first layout of the SBML document.
/// This function assigns a new "y" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y);

/// @brief Sets the "y" position of a TextGlyph object, identified by graphical object index, within a specific layout of the SBML document.
/// This function assigns a new "y" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y);

/// @brief Sets the "y" position of a TextGlyph object, identified by both graphical and text glyph indices, within the first layout of the SBML document.
/// This function assigns a new "y" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y);

/// @brief Sets the "y" position of a TextGlyph object, identified by both graphical and text glyph indices, within a specific layout of the SBML document.
/// This function assigns a new "y" coordinate to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y);

/// @brief Sets both the "x" and "y" positions of a TextGlyph object within the first layout of the SBML document.
/// This function assigns new "x" and "y" coordinates to the bounding box of a TextGlyph object, identified by its associated model entity ID. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y);

/// @brief Sets both the "x" and "y" positions of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns new "x" and "y" coordinates to the bounding box of a TextGlyph object, identified by its associated model entity ID and within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y);

/// @brief Sets both the "x" and "y" positions of a TextGlyph object, identified by graphical object index, within the first layout of the SBML document.
/// This function assigns new "x" and "y" coordinates to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y);

/// @brief Sets both the "x" and "y" positions of a TextGlyph object, identified by graphical object index, within a specific layout of the SBML document.
/// This function assigns new "x" and "y" coordinates to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y);

/// @brief Sets both the "x" and "y" positions of a TextGlyph object within the first layout of the SBML document.
/// This function assigns new "x" and "y" coordinates to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y);

/// @brief Sets both the "x" and "y" positions of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns new "x" and "y" coordinates to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param x The new "x" position to set for the bounding box of the TextGlyph object.
/// @param y The new "y" position to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y);

/// @brief Retrieves the width of the bounding box of a TextGlyph object within the first layout of the SBML document.
/// This function fetches the width of the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within the first layout of the SBML document. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The width of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Retrieves the width of the bounding box of a TextGlyph object within a specific layout of the SBML document.
/// This function fetches the width of the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object or the layout does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document from which to retrieve the TextGlyph object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The width of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets the width of the bounding box of a TextGlyph object within the first layout of the SBML document.
/// This function assigns a new width to the bounding box of a TextGlyph object, identified by its associated model entity ID. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param width The new width to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(SBMLDocument* document, const std::string& id, const double& width);

/// @brief Sets the width of the bounding box of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns a new width to the bounding box of a TextGlyph object, identified by its associated model entity ID and within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param width The new width to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width);

/// @brief Sets the width of the bounding box of a TextGlyph object, identified by graphical object index, within the first layout of the SBML document.
/// This function assigns a new width to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param width The new width to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width);

/// @brief Sets the width of the bounding box of a TextGlyph object, identified by graphical object index, within a specific layout of the SBML document.
/// This function assigns a new width to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param width The new width to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width);

/// @brief Sets the width of the bounding box of a TextGlyph object, identified by both graphical and text glyph indices, within the first layout of the SBML document.
/// This function assigns a new width to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param width The new width to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width);

/// @brief Sets the width of the bounding box of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns a new width to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param width The new width to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width);

/// @brief Retrieves the height of the bounding box of a TextGlyph object within the first layout of the SBML document.
/// This function fetches the height of the bounding box of a TextGlyph object, identified by its index and associated with a model entity identified by its ID, within the first layout of the SBML document. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The height of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Retrieves the height of the bounding box of a TextGlyph object within a specific layout of the SBML document.
/// This function fetches the height of the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index. Defaults for graphicalObjectIndex and textGlyphIndex are 0. If the TextGlyph object or the layout does not exist, the function returns 0.0.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document from which to retrieve the TextGlyph object.
/// @param id The ID of the model entity associated with the TextGlyph object to be retrieved.
/// @param graphicalObjectIndex (Optional) The index of the GraphicalObject within the layout. Defaults to 0.
/// @param textGlyphIndex (Optional) The index of the TextGlyph within the graphical object. Defaults to 0.
/// @return The height of the bounding box of the specified TextGlyph object, or 0.0 if the object is NULL.
LIBSBMLNETWORK_EXTERN const double getTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Sets the height of the bounding box of a TextGlyph object within the first layout of the SBML document.
/// This function assigns a new height to the bounding box of a TextGlyph object, identified by its associated model entity ID. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param height The new height to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(SBMLDocument* document, const std::string& id, const double& height);

/// @brief Sets the height of the bounding box of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns a new height to the bounding box of a TextGlyph object, identified by its associated model entity ID and within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param height The new height to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height);

/// @brief Sets the height of the bounding box of a TextGlyph object, identified by graphical object index, within the first layout of the SBML document.
/// This function assigns a new height to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param height The new height to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height);

/// @brief Sets the height of the bounding box of a TextGlyph object, identified by graphical object index, within a specific layout of the SBML document.
/// This function assigns a new height to the bounding box of a TextGlyph object, identified by its associated model entity ID and graphical object index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param height The new height to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height);

/// @brief Sets the height of the bounding box of a TextGlyph object within the first layout of the SBML document.
/// This function assigns a new height to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index. This operation is performed within the first layout of the SBML document.
/// @param document A pointer to the SBMLDocument object.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param height The new height to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height);

/// @brief Sets the height of the bounding box of a TextGlyph object within a specific layout of the SBML document.
/// This function assigns a new height to the bounding box of a TextGlyph object, identified by its associated model entity ID, graphical object index, and text glyph index, within a specified layout of the SBML document. The layout is determined by its index.
/// @param document A pointer to the SBMLDocument object.
/// @param layoutIndex The index of the layout within the SBML document in which the TextGlyph object is located.
/// @param id The ID of the model entity associated with the TextGlyph object to be modified.
/// @param graphicalObjectIndex The index of the GraphicalObject within the layout.
/// @param textGlyphIndex The index of the TextGlyph within the graphical object.
/// @param height The new height to set for the bounding box of the TextGlyph object.
/// @return An integer value indicating success (non-zero) or failure (zero).
LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height);

/// @brief Predicate returning true if the GraphicalObject with the given index associated with the model entity with the given id of
/// the first Layout object in the SBML document has a Curve object and the curve consists of one or more segments.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Predicate returning true if the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document
/// has a Curve object and the curve consists of one or more segments.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the Curve object of the GraphicalObject with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the Curve object of the GraphicalObject object, or @c NULL if the object is @c NULL or does not have a Curve object
LIBSBMLNETWORK_EXTERN Curve* getCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the Curve object of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the Curve object of the GraphicalObject object, or @c NULL if the object is @c NULL or does not have a Curve object
LIBSBMLNETWORK_EXTERN Curve* getCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the number of curve segments of the curve of the GraphicalObject with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const unsigned int getNumCurveSegments(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the number of curve segments of the curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const unsigned int getNumCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns a pointer to the curve segment with the given index of the GraphicalObject with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this GraphicalObject object.
LIBSBMLNETWORK_EXTERN LineSegment* getCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns a pointer to the curve segment with the given index of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this GraphicalObject object.
LIBSBMLNETWORK_EXTERN LineSegment* getCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Creates a new LineSegment and adds it to the end of the list of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the created @c LineSegment, or NULL if the line segment could not be created.
LIBSBMLNETWORK_EXTERN LineSegment* createLineCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Creates a new LineSegment and adds it to the end of the list of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the created @c LineSegment, or NULL if the line segment could not be created.
LIBSBMLNETWORK_EXTERN LineSegment* createLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Creates a new CubicBezier and adds it to the end of the list of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
LIBSBMLNETWORK_EXTERN CubicBezier* createCubicBezierCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Creates a new CubicBezier and adds it to the end of the list of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
LIBSBMLNETWORK_EXTERN CubicBezier* createCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Removes and deletes the curve segment with the given index from the list of the Curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeCurveSegment(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex = 0);

/// @brief Removes and deletes the curve segment with the given index from the list of the Curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex = 0);

/// @brief Predicate returning true if the curve segment with the given index of the Curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document is of type CubicBezier.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBMLNETWORK_EXTERN bool isCubicBezier(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Predicate returning true if the curve segment with the given index of the Curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document is of type CubicBezier.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBMLNETWORK_EXTERN bool isCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
/// or @c 0.0 if the object is @c NULL or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
/// or @c 0.0 if the object is @c NULL or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of the curve the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of the curve the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of the of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of the of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of the of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of the of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve.
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve.
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the first Layout object in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object with the given index in the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout to return.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

}

#endif