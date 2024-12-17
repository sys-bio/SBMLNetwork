#ifndef __LIBSBMLNETWORK_LAYOUT_H_
#define __LIBSBMLNETWORK_LAYOUT_H_

#include "libsbmlnetwork_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

/// @brief Returns the number of items in this ListOfLayouts object.
/// @param listOfLayouts a pointer to the ListOfLayouts object.
/// @return the number of items in this ListOfLayouts object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts);

/// @brief Returns a pointer to the Layout object with the given index in this ListOfLayouts.
/// @param layoutIndex the index number of the Layout to return.
/// @return the Layout object with the given index in this ListOfLayouts, or NULL if no such Layout exists or the object is @c NULL.
LIBSBMLNETWORK_EXTERN Layout* getLayout(ListOfLayouts* listOfLayouts, unsigned int layoutIndex = 0);

/// @brief Returns the Dimensions object of the Layout object.
/// @param layout a pointer to the Layout object.
/// @return a pointer to the Dimensions object of the Layout object.
LIBSBMLNETWORK_EXTERN Dimensions* getDimensions(Layout* layout);

/// @brief Returns the value of the "width" attribute of the Dimensions object of the Layout object.
/// @param layout a pointer to the Layout object.
/// @return the value of the "width" attribute of the Dimensions object of the Layout object.
LIBSBMLNETWORK_EXTERN const double getDimensionWidth(Layout* layout);

/// @brief Sets the value of the "width" attribute of the Dimensions object of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param width a double value to use as the value of the "width" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(Layout* layout, const double& width);

/// @brief Returns the value of the "height" attribute of the Dimensions object of the Layout object.
/// @param layout a pointer to the Layout object.
/// @return the value of the "height" attribute of the Dimensions object of the Layout object.
LIBSBMLNETWORK_EXTERN const double getDimensionHeight(Layout* layout);

/// @brief Sets the value of the "height" attribute of the Dimensions object of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param height a double value to use as the value of the "height" attribute of the Dimensions object of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(Layout* layout, const double& height);

/// @brief Returns the number of GraphicalObject objects of the Layout object.
/// @param layout a pointer to the Layout object
/// @return the number of the GraphicalObject objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumGraphicalObjects(Layout* layout);

/// @brief Returns the number of GraphicalObject objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @return the number of the GraphicalObject objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumGraphicalObjects(Layout* layout, const std::string& id);

/// @brief Returns the GraphicalObject objects with the entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @return the GraphicalObject objects with the entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<GraphicalObject*> getGraphicalObjects(Layout* layout, const std::string& id);

/// @brief Returns the GraphicalObject object with the given index associated with entered id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param compartmentGlyphIndex the index of the CompartmentGlyph to return.
/// @return a pointer to the GraphicalObject object with the given index associated with the entered id, or NULL is GraphicalObject object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN GraphicalObject* getGraphicalObject(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex = 0);

LIBSBMLNETWORK_EXTERN int removeGraphicalObject(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Predicates returning true if the id of the GraphicalObject with the given index inf the Layout object associated with the entered model entity id is set.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return @c true if the id of the GraphicalObject with the given index is set, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetId(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Returns the id of the GraphicalObject object with the given index associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the value of the "id" attribute of the GraphicalObject object with the given index associated with the entered id, or @c "" if
/// the GraphicalObject object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getId(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Sets the id of the GraphicalObject object with the given index associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param graphicalObjectId the id to set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setId(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex, const std::string& graphicalObjectId);

/// @brief Predicate returning true if the metaId of the GraphicalObject with the given index of the Layout object associated with the entered id is set.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return @c true if the metaId of the GraphicalObject with the given index is set, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetMetaId(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Returns the metaId of the GraphicalObject object with the given index associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the value of the "metaId" attribute of the GraphicalObject object with the given index associated with the entered id, or @c "" if
/// the GraphicalObject object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getMetaId(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Sets the metaId of the GraphicalObject object with the given index associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param graphicalObjectMetaId the metaId to set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setMetaId(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex, const std::string& graphicalObjectMetaId);

/// @brief Predicate returning true if the name of the GraphicalObject with the given index of the Layout object associated with the entered id is set.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return @c true if the name of the GraphicalObject with the given index is set, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetName(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Returns the name of the GraphicalObject object with the given index associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the value of the "name" attribute of the GraphicalObject object with the given index associated with the entered id, or @c "" if
/// the GraphicalObject object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getName(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex);

/// @brief Sets the name of the GraphicalObject object with the given index associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the the GraphicalObject objects of which to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param name the name to set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setName(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex, const std::string& name);

/// @brief Returns the number of CompartmentGlyph objects of the Layout object.
/// @param layout a pointer to the Layout object
/// @return the number of the CompartmentGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartmentGlyphs(Layout* layout);

/// @brief Returns the number of CompartmentGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the compartment the the CompartmentGlyph objects of which to be returned.
/// @return the number of the CompartmentGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartmentGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the CompartmentGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the compartment the the CompartmentGlyph objects of which to be returned.
/// @return the CompartmentGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the CompartmentGlyph object with the given index associated with entered id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the compartment the the CompartmentGlyph objects of which to be returned.
/// @param compartmentGlyphIndex the index of the CompartmentGlyph to return.
/// @return a pointer to the CompartmentGlyph object with the given index associated with the entered id, or NULL is CompartmentGlyph object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN CompartmentGlyph* getCompartmentGlyph(Layout* layout, const std::string& id, const unsigned int compartmentGlyphIndex = 0);

/// @brief Returns the CompartmentGlyph object with the given index associated of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param compartmentGlyphIndex the index of the CompartmentGlyph to return.
/// @return a pointer to the CompartmentGlyph object with the given index, or NULL is CompartmentGlyph object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN CompartmentGlyph* getCompartmentGlyph(Layout* layout, const unsigned int compartmentGlyphIndex = 0);

/// Returns the id of the compartment associated with the CompartmentGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the compartment the CompartmentGlyph objects of which to be returned.
/// @param compartmentGlyphIndex the index of the CompartmentGlyph to return.
/// @return the value of the "compartment" attribute of the CompartmentGlyph object with the given id, or @c "" if
/// the CompartmentGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getCompartmentId(Layout* layout, const std::string& id, const unsigned int compartmentGlyphIndex = 0);

/// @brief Returns the id of the compartment associated with the CompartmentGlyph object.
/// @param compartmentGlyph a pointer to the GraphicalObject object.
/// @return the value of the "compartment" attribute, or @c "" if the object is not of type CompartmentGlyph or is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getCompartmentId(GraphicalObject* compartmentGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id of the Layout object is of type CompartmentGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the compartment the the CompartmentGlyph objects of which to be returned.
/// @param compartmentGlyphIndex the index of the CompartmentGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isCompartmentGlyph(Layout* layout, const std::string& id, const unsigned int compartmentGlyphIndex = 0);

/// @brief Predicate returning true if this abstract GraphicalObject is of type CompartmentGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isCompartmentGlyph(GraphicalObject* graphicalObject);

/// @brief Returns the ids of the SpeciesGlyph objects of the Layout object
/// @param layout a pointer to the Layout object
/// @return the ids of the SpeciesGlyph objects of the Layout object
LIBSBMLNETWORK_EXTERN std::vector<std::string> getSpeciesGlyphsIds(Layout* layout);

/// @brief Returns the number of SpeciesGlyph objects of the Layout object.
/// @param layout a pointer to the Layout object
/// @return the number of the SpeciesGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesGlyphs(Layout* layout);

/// @brief Returns the number of SpeciesGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the species the the SpeciesGlyph objects of which to be returned.
/// @return the number of the SpeciesGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the SpeciesGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the species the the SpeciesGlyph objects of which to be returned.
/// @return the SpeciesGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<SpeciesGlyph*> getSpeciesGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the SpeciesGlyph object with the given index associated with entered id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the species the the SpeciesGlyph objects of which to be returned.
/// @param speciesGlyphIndex the index of the SpeciesGlyph to return.
/// @return a pointer to the SpeciesGlyph object with the given index associated with the entered id, or NULL is SpeciesGlyph object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN SpeciesGlyph* getSpeciesGlyph(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex = 0);

/// @brief Returns the SpeciesGlyph object with the given index associated of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param speciesGlyphIndex the index of the SpeciesGlyph to return.
/// @return a pointer to the SpeciesGlyph object with the given index, or NULL is SpeciesGlyph object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN SpeciesGlyph* getSpeciesGlyph(Layout* layout, const unsigned int speciesGlyphIndex = 0);

/// @brief Returns the index of the SpeciesGlyph object associated in the list of SpeciesGlyph objects among the list of SpeciesGlyph objects associated with the given species id that is associated with the given reaction id with the given index in the Layout object.
/// @param layout a pointer to the Layout object.
/// @param speciesId the id of the species the the SpeciesGlyph objects of which to be returned.
/// @param reactionId the id of the reaction the the SpeciesGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @return the index of the SpeciesGlyph object associated in the list of SpeciesGlyph objects among the list of SpeciesGlyph objects associated with the given species id that is associated with the given reaction id, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const int getSpeciesGlyphIndex(Layout* layout, const char* speciesId, const char* reactionId, unsigned int reactionGlyphIndex = 0);

/// Returns the id of the species associated with the SpeciesGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the species the the SpeciesGlyph objects of which to be returned.
/// @param speciesGlyphIndex the index of the SpeciesGlyph to return.
/// @return the value of the "species" attribute of the SpeciesGlyph object with the given id, or @c "" if
/// the SpeciesGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesId(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex = 0);

/// @brief Returns the id of the species associated with the SpeciesGlyph object.
/// @param speciesGlyph a pointer to the GraphicalObject object.
/// @return the value of the "species" attribute, or @c "" if the object is not of type SpeciesGlyph or is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesId(GraphicalObject* speciesGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id of the Layout object is of type SpeciesGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the GraphicalObject.
/// @param speciesGlyphIndex the index of the SpeciesGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesGlyph(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex = 0);

/// @brief Predicate returning true if this abstract GraphicalObject is of type SpeciesGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesGlyph(GraphicalObject* graphicalObject);

/// @brief Predicate returning true if the SpeciesGlyph object with the given id of the Layout object is an empty SpeciesGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the species the the SpeciesGlyph objects of which to be returned.
/// @param speciesGlyphIndex the index of the SpeciesGlyph to return.
/// @return @c true if this SpeciesGlyph object is an empty SpeciesGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isEmptySpeciesGlyph(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex = 0);

/// @brief Predicate returning true if this SpeciesGlyph object is an empty SpeciesGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this SpeciesGlyph object is an empty SpeciesGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isEmptySpeciesGlyph(GraphicalObject* graphicalObject);

/// @brief Returns the ids of the ReactionGlyph objects of the Layout object
/// @param layout a pointer to the Layout object
/// @return the ids of the ReactionGlyph objects of the Layout object
LIBSBMLNETWORK_EXTERN std::vector<std::string> getReactionGlyphsIds(Layout* layout);

/// @brief Returns the number of ReactionGlyph objects of the Layout object.
/// @param layout a pointer to the Layout object
/// @return the number of the ReactionGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactionGlyphs(Layout* layout);

/// @brief Returns the number of ReactionGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @return the number of the ReactionGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactionGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the ReactionGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @return the ReactionGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<ReactionGlyph*> getReactionGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the ReactionGlyph object with the given index associated with entered id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph to return.
/// @return a pointer to the ReactionGlyph object with the given index associated with the entered id, or NULL is ReactionGlyph object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN ReactionGlyph* getReactionGlyph(Layout* layout, const std::string& id, const unsigned int reactionGlyphIndex = 0);

/// @brief Returns the ReactionGlyph object with the given index associated of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param reactionGlyphIndex the index of the ReactionGlyph to return.
/// @return a pointer to the ReactionGlyph object with the given index, or NULL is ReactionGlyph object does not exist or the object is @c NULL.
LIBSBMLNETWORK_EXTERN ReactionGlyph* getReactionGlyph(Layout* layout, const unsigned int reactionGlyphIndex = 0);

/// Returns the id of the reaction associated with the ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph to return.
/// @return the value of the "reaction" attribute of the ReactionGlyph object with the given id, or @c "" if
/// the ReactionGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getReactionId(Layout* layout, const std::string& id, const unsigned int reactionGlyphIndex = 0);

/// @brief Returns the id of the reaction associated with the ReactionGlyph object.
/// @param reactionGlyph a pointer to the GraphicalObject object.
/// @return the value of the "reaction" attribute, or @c "" if the object is not of type ReactionGlyph or is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getReactionId(GraphicalObject* reactionGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id of the Layout object is of type ReactionGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isReactionGlyph(const Layout* layout, const std::string& id, const unsigned int reactionGlyphIndex = 0);

/// @brief Predicate returning true if this abstract GraphicalObject is of type ReactionGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isReactionGlyph(const GraphicalObject* graphicalObject);

/// @brief Returns the number of SpeciesReference objects of the ReactionGlyph with the given index associated with the reaction with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @return the number of SpeciesReference objects of this ReactionGlyph object, or @c 0 if ReactionGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferences(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the number of SpeciesReference objects of the ReactionGlyph object.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @return the number of SpeciesReference objects of the ReactionGlyph object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferences(GraphicalObject* reactionGlyph);

/// @brief Returns the SpeciesReferenceGlyph objects of the ReactionGlyph with the given index associated with the reaction with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @return the SpeciesReferenceGlyph objects of the ReactionGlyph object with the given id, or @c NULL if ReactionGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<SpeciesReferenceGlyph*> getSpeciesReferences(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0);

/// @brief Returns the SpeciesReferenceGlyph objects of the ReactionGlyph object.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @return the SpeciesReferenceGlyph objects of the ReactionGlyph object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<SpeciesReferenceGlyph*> getSpeciesReferences(GraphicalObject* reactionGlyph);

/// @brief Returns the SpeciesReference object with the given index of the ReactionGlyph with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @return the SpeciesReference object with the given index of the ReactionGlyph object with the given id, or @c NULL if ReactionGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN SpeciesReferenceGlyph* getSpeciesReference(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the SpeciesReference object with the given index of the ReactionGlyph object.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @return the SpeciesReference object with the given index of the ReactionGlyph object, or @c NULL if ReactionGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN SpeciesReferenceGlyph* getSpeciesReference(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species reference associated with the the SpeciesReference object with the given index of the ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceIndex the index of the SpeciesReference to return.
/// @return the value of the "species reference" attribute of the SpeciesReference object with the given index, or @c "" if
/// the ReactionGlyph does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species reference associated with the SpeciesReference object with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param speciesReferenceIndex the index value of the SpeciesReference.
/// @return the value of the "species reference" attribute of the SpeciesReference object with the given index, or @c "" if
/// the ReactionGlyph object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceId(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex);

/// Returns the id of the associated species reference.
/// @param speciesReferenceGlyph a pointer to the GraphicalObject object.
/// @return the value of the "speciesReference" attribute, or @c "" if the object is not of type SpeciesReferenceGlyph object or is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceId(GraphicalObject* speciesReferenceGlyph);

LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex);

/// @brief Returns the id of the species glyph associated with the the SpeciesReference object with the given index of the ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @return the value of the "speciesGlyph" attribute of the SpeciesReference object with the given index, or @c "" if
/// the SpeciesReference object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesGlyphId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the id of the species glyph associated with the SpeciesReference object with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param speciesReferenceIndex the index value of the SpeciesReference.
/// @return the value of the "speciesGlyph" attribute of the SpeciesReference object with the given index, or @c "" if
/// the SpeciesReference object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesGlyphId(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex);

/// Returns the id of the associated SpeciesGlyph.
/// @param speciesReference a pointer to the GraphicalObject object.
/// @return the value of the "speciesGlyph" attribute, or @c "" if the object is not of type SpeciesReferenceGlyph object or is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpeciesReferenceSpeciesGlyphId(GraphicalObject* speciesReferenceGlyph);

bool isSetEmptySpeciesGlyph(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex);

const std::string getEmptySpeciesGlyphId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given id of the Layout object is set.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @return @c true if the "role" attribute of the SpeciesReference object with the given index is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReference object with the given index is set.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param speciesReferenceIndex the index value of the SpeciesReference.
/// @return @c true if the "role" attribute of the SpeciesReference object with the given index is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex);

/// @brief Predicates returning @c true if the "role" attribute of the SpeciesReferenceGlyph object is set.
/// @param speciesReference a pointer to the GraphicalObject object.
/// @return @c true if the "role" attribute of the SpeciesReferenceGlyph object is set, @c false if either the "role"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetRole(GraphicalObject* speciesReferenceGlyph);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @return the value of the "role" attribute of the SpeciesReference object with the given index, or @c "" if
/// the SpeciesReference does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReference object with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param speciesReferenceIndex the index value of the SpeciesReference.
/// @return the value of the "role" attribute of the SpeciesReference object with the given index, or @c "" if
/// the SpeciesReference does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex);

/// @brief Returns the string representation of the "role" attribute of the SpeciesReferenceGlyph object.
/// @param speciesReference a pointer to the GraphicalObject object.
/// @return the value of the "role" attribute, or @c "" if the object is not of type SpeciesReferenceGlyph or is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getRole(GraphicalObject* speciesReferenceGlyph);

/// @brief Sets the value of the "role" attribute of the first SpeciesReference object of the first ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param role a string value to be set as "role" attribute of the SpeciesReference object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRole(Layout* layout, const std::string& id, const std::string& role);

/// @brief Sets the value of the "role" attribute of the first SpeciesReference object of the ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param role a string value to be set as "role" attribute of the SpeciesReference object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReference object with the given index of the ReactionGlyph object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the reaction the the ReactionGlyph objects of which to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @param role a string value to be set as "role" attribute of the SpeciesReference object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReference object with the given index.
/// @param reactionGlyph a pointer to the GraphicalObject object.
/// @param speciesReferenceIndex the index of the SpeciesReference.
/// @param role a string value to be set as "role" attribute of the SpeciesReference object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex, const std::string& role);

/// @brief Sets the value of the "role" attribute of the SpeciesReferenceGlyph object.
/// @param speciesReference a pointer to the GraphicalObject object.
/// @param role a string value to be set as "role" attribute of the SpeciesReferenceGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRole(GraphicalObject* speciesReferenceGlyph, const std::string& role);

/// @brief Returns the number of SpeciesReference objects of the ReactionGlyph with the given index associated with the entered species id in the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param speciesId the id of the species the SpeciesReference objects associated with it to be returned.
/// @param reactionId the id of the reaction the SpeciesReference objects associated with it to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @return the number of SpeciesReference objects of this ReactionGlyph object, or @c 0 if ReactionGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN const int getNumSpeciesReferencesAssociatedWithSpecies(Layout* layout, const std::string& speciesId, const std::string& reactionId, const unsigned int reactionGlyphIndex = 0);

/// @brief Returns the number of SpeciesReference objects of the ReactionGlyph with the given index associated with the entered species id in the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param speciesId the id of the species the SpeciesReference objects associated with it to be returned.
/// @param reactionId the id of the reaction the SpeciesReference objects associated with it to be returned.
/// @param reactionGlyphIndex the index of the ReactionGlyph.
/// @param n the number of SpeciesReference objects to be returned.
/// @return the number of SpeciesReference objects of this ReactionGlyph object, or @c 0 if ReactionGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN const int getSpeciesReferenceIndexAssociatedWithSpecies(Layout* layout, const std::string& speciesId, const std::string& reactionId, const unsigned int reactionGlyphIndex = 0, const unsigned int n = 0);

/// @brief Predicate returning true if this abstract GraphicalObject object is of type SpeciesReferenceGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject object is of type SpeciesReferenceGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isSpeciesReferenceGlyph(const GraphicalObject* graphicalObject);

/// @brief Returns the number of TextGlyph objects of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @return the number of TextGlyph objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumTextGlyphs(Layout* layout);

/// @brief Returns the number of TextGlyph objects associated with entered id of the Layout object.
/// @param layout a pointer to the Layout object
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the number of the TextGlyph objects associated with entered id of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumTextGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the number of TextGlyph objects associated with the GraphicalObject object.
/// @param layout a pointer to the Layout object
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the number of the GraphicalObject objects associated the GraphicalObject object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumTextGlyphs(Layout* layout, GraphicalObject* graphicalObject);

/// @brief Returns the TextGlyph objects associated with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @return the TextGlyph objects with the given id, or an empty vector if TextGlyph objects does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<TextGlyph*> getTextGlyphs(Layout* layout, const std::string& id);

/// @brief Returns the TextGlyph objects associated with the GraphicalObject object.
/// @param Layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the TextGlyph objects of the GraphicalObject object, or an empty vector if TextGlyph objects does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN std::vector<TextGlyph*> getTextGlyphs(Layout* layout, GraphicalObject* graphicalObject);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN TextGlyph* getTextGlyph(Layout* layout, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Returns a pointer to the TextGlyph object with the given index associated with the GraphicalObject object.
/// @param Layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the TextGlyph object with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN TextGlyph* getTextGlyph(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph object with the given index associated with the given id is set.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the "text" attribute of this TextGlyph is set.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetText(GraphicalObject* textGlyph);

/// @brief Returns the "text" attribute of the TextGlyph object with the given index associated with the given id is set.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getText(const Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the text associated with this TextGlyph object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set,
/// or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getText(const GraphicalObject* textGlyph);

/// @brief Sets the value of the "text" attribute of the first TextGlyph object associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Sets the value of the "text" attribute of TextGlyph object with the given index associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(Layout* layout, const std::string& id, unsigned int textGlyphIndex, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Sets the value of the "text" attribute this TextGlyph object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setText(GraphicalObject* textGlyph, const std::string& text);

/// @brief Adds a new TextGlyph object to the Layout object and associates it with the given GraphicalObject object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
LIBSBMLNETWORK_EXTERN int addText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text);

/// @brief Adds a new TextGlyph object to the Layout object and associates it with the given GraphicalObject object.
/// @param Layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
int addText(Layout* layout, GraphicalObject* graphicalObject, const std::string& text);

/// @brief Removes the TextGlyph object with the given index associated with the given GraphicalObject object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to remove.
/// @return integer value indicating success/failure of the function.
int removeText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex);

/// @brief Removes the TextGlyph object from the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return integer value indicating success/failure of the function.
int removeText(Layout* layout, GraphicalObject* textGlyph);

/// @brief Predicates returning @c true if the origin of text of the TextGlyph object with the given index associated with the given id is not the empty string.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the id of the origin of text of the TextGlyph object is not the empty string.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return @c true if the id of the origin of text of this TextGlyph object not the empty string, @c false
/// either the "originOfTextId" attribute of this TextGlyph object is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOriginOfTextId(GraphicalObject* textGlyph);

/// @brief Returns the id of the origin of text of the TextGlyph object with the given index associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the origin of text of the TextGlyph object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either
/// the "originOfTextId" attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getOriginOfTextId(GraphicalObject* textGlyph);

/// @brief Sets id of the origin of text of the first TextGlyph object with the given index associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig);

/// @brief Sets id of the origin of text of the TextGlyph object with the given index associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(Layout* layout, const std::string& id, unsigned int textGlyphIndex, unsigned int graphicalObjectIndex, const std::string& orig);

/// @brief Sets the id of the origin of text of the TextGlyph object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOriginOfTextId(GraphicalObject* textGlyph, const std::string& orig);

/// @brief Predicates returning @c true if id of the associated graphical object of the TextGlyph object with the given index associated with the given id is not the empty string.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if the id of the associated graphical object of this TextGlyph object is not the empty string, @c false if either the id
/// of the associated graphical object is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Predicates returning @c true if the id of the associated graphical object is not the empty string.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return @c true if the id of the associated graphical object of this TextGlyph object not the empty string, @c false if either
/// the "graphicalObjectId" attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGraphicalObjectId(GraphicalObject* textGlyph);

/// @brief Returns the id of the associated graphical object of the TextGlyph object with the given index associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0);

/// @brief Returns the id of the associated graphical object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return the id of the associated graphical object of this TextGlyph object or @c empty string if either the "graphicalObjectId"
/// attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGraphicalObjectId(GraphicalObject* textGlyph);

/// @brief Sets the id of the associated graphical object of the first TextGlyph object associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object of the TextGlyph object with the given index associated with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId);

/// @brief Sets the id of the associated graphical object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @param graphicalObjectId a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGraphicalObjectId(GraphicalObject* textGlyph, const std::string& graphicalObjectId);

/// @brief Returns a pointer to the GraphicalObject the id of which is set to "graphicalObjectId" attribute.
/// @param Layout a pointer to the Layout object.
/// @return A pointer to the associated graphical object of this TextGlyph object or @c NULL if either the "graphicalObjectId"
/// attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBMLNETWORK_EXTERN GraphicalObject* getGraphicalObject(Layout* layout, GraphicalObject* textGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index associated with the given id is of type TextGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the TextGlyph objects associated with it to be returned.
/// @param textGlyphIndex the index of the TextGlyph to return.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isTextGlyph(const Layout* layout, const std::string& id, unsigned int textGlyphIndex = 0);

/// @brief Predicate returning true if this abstract GraphicalObject object is of type TextGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBMLNETWORK_EXTERN bool isTextGlyph(const GraphicalObject* graphicalObject);

/// @brief Returns the number of additional GraphicalObject objects of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @return the number of additional GraphicalObject objects of the Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumAdditionalGraphicalObjects(Layout* layout);

/// @brief Returns a pointer to the additional GraphicalObject object with the given index of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param additionalGraphicalObjectIndex the index of the additional GraphicalObject to return.
/// @return a pointer to the additional GraphicalObject object with the given index, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN GraphicalObject* getAdditionalGraphicalObject(Layout* layout, const unsigned int additionalGraphicalObjectIndex = 0);

/// @brief Returns the id of the additional GraphicalObject object with the given index of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param additionalGraphicalObjectIndex the index of the additional GraphicalObject to return.
/// @return the id of the additional GraphicalObject object with the given index, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getAdditionalGraphicalObjectId(Layout* layout, const unsigned int additionalGraphicalObjectIndex = 0);

/// @brief Adds a new GraphicalObject object to the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id a string value to be set as the id of the GraphicalObject object.
/// @return a pointer to the newly created GraphicalObject object, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN GraphicalObject* addAdditionalGraphicalObject(Layout* layout, const std::string& id);

/// @brief Removes the additional GraphicalObject object with the given index from the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param additionalGraphicalObjectIndex the index of the additional GraphicalObject to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeAdditionalGraphicalObject(Layout* layout, const unsigned int additionalGraphicalObjectIndex = 0);

/// Returns the value of the "id" attribute of the SBML object associated with the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param graphicalObjectId the id of the GraphicalObject object.
/// @return the "id" attribute of the SBML object associated with the GraphicalObject object with given id, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSBMLObjectId(Layout* layout, const std::string& graphicalObjectId);

/// Returns the value of the "id" attribute of the SBML object associated with this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "id" attribute of the SBML object associated with this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSBMLObjectId(GraphicalObject* graphicalObject);

/// Returns the BoundingBox object of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return a pointer to the BoundingBox object of the GraphicalObject object associated with the entered id, or @c NULL if
/// the GraphicalObject object does not exits or the object is @c NULL
LIBSBMLNETWORK_EXTERN BoundingBox* getBoundingBox(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex = 0);

/// Returns the bounding box for the GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the bounding box for the GraphicalObject object, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN BoundingBox* getBoundingBox(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionX(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "x" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionX(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "x" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionX(BoundingBox* boundingBox);

/// @brief Returns the x value of the middle point of the Curve object.
/// @param curve a pointer to the Curve object.
/// @return the x value of the middle point of the Curve object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionX(Curve* curve);

/// @brief Sets the value of the "x" attribute of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(Layout* layout, const std::string& id, const double& x);

/// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the bounding box of this GraphicalObject object associated with the object with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(Layout* layout, GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param x a double value to use as the value of the "x" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(BoundingBox* boundingBox, const double& x);

/// @brief Sets the x value of the middle point of the Curve object.
/// @param curve a pointer to the Curve object.
/// @param x a double value to use as the x value of the middle point of the Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionX(Curve* curve, const double& x);

/// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "y" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionY(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "y" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "y" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionY(BoundingBox* boundingBox);

/// @brief Returns the y value of the middle point of the Curve object.
/// @param curve a pointer to the Curve object.
/// @return the y value of the middle point of the Curve object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getPositionY(Curve* curve);

/// @brief Sets the value of the "y" attribute of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(Layout* layout, const std::string& id, const double& y);

/// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the bounding box this GraphicalObject object.
/// @param layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(Layout* layout, GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param y a double value to use as the value of the "y" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(BoundingBox* boundingBox, const double& y);

/// @brief Sets the y value of the middle point of the Curve object.
/// @param curve a pointer to the Curve object.
/// @pram y a double value to use as the y value of the middle point of the Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPositionY(Curve* curve, const double& y);

/// @brief Sets the value of "x" and "y" attributes of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(Layout* layout, const std::string& id, const double& x, const double& y);

/// @brief Sets the value of "x" and "y" attributes of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y);

/// @brief Sets the value of "x" and "y" attributes of the bounding box this GraphicalObject object.
/// @param layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(Layout* layout, GraphicalObject* graphicalObject, const double& x, const double& y);

/// @brief Sets the value of "x" and "y" attributes of the bounding box this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this BoundingBox object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(BoundingBox* boundingBox, const double& x, const double& y);

/// @brief Sets the x and y values of the middle point of the Curve object.
/// @param curve a pointer to the Curve object.
/// @param x a double value to use as the x value of the middle point of the Curve object.
/// @param y a double value to use as the y value of the middle point of the Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setPosition(Curve* curve, const double& x, const double& y);

/// @brief Returns the value of the "width" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "width" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionWidth(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "width" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "width" attribute of the bounding box of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionWidth(BoundingBox* boundingBox);

/// @brief Sets the value of the "width" attribute of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(Layout* layout, const std::string& id, const double& width);

/// @brief Sets the value of the "width" attribute of the bounding box the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& width);

/// @brief Sets the value of the "width" attribute of the bounding box this GraphicalObject object.
/// @param layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, const double& width);

/// @brief Sets the value of the "width" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "width" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionWidth(BoundingBox* boundingBox, const double& width);

LIBSBMLNETWORK_EXTERN int setCompartmentDimensionWidth(Layout* layout, const double& width);

LIBSBMLNETWORK_EXTERN int setSpeciesDimensionWidth(Layout* layout, const double& width);

LIBSBMLNETWORK_EXTERN int setReactionDimensionWidth(Layout* layout, const double& width);

/// @brief Returns the value of the "height" attribute of the bounding box of the bounding box of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionHeight(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "height" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getDimensionHeight(BoundingBox* boundingBox);

/// @brief Sets the value of the "height" attribute of the bounding box of the bounding box of the first GraphicalObject associated with the model entity with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(Layout* layout, const std::string& id, const double& height);

/// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject object with the given index of associated with the object with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& height);

/// @brief Sets the value of the "height" attribute of this GraphicalObject object associated with the object with the given id of the Layout object.
/// @param layout a pointer to the Layout object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "height" attribute of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, const double& height);

/// @brief Sets the value of the "height" attribute of this BoundingBox object.
/// @param layout a pointer to the Layout object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "height" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDimensionHeight(BoundingBox* boundingBox, const double& height);

LIBSBMLNETWORK_EXTERN int setCompartmentDimensionHeight(Layout* layout, const double& height);

LIBSBMLNETWORK_EXTERN int setSpeciesDimensionHeight(Layout* layout, const double& height);

LIBSBMLNETWORK_EXTERN int setReactionDimensionHeight(Layout* layout, const double& height);

LIBSBMLNETWORK_EXTERN const double getTextPositionX(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

LIBSBMLNETWORK_EXTERN int setTextPositionX(Layout* layout, GraphicalObject* graphicalObject, const double& x);

LIBSBMLNETWORK_EXTERN int setTextPositionX(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& x);

LIBSBMLNETWORK_EXTERN const double getTextPositionY(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

LIBSBMLNETWORK_EXTERN int setTextPositionY(Layout* layout, GraphicalObject* graphicalObject, const double& y);

LIBSBMLNETWORK_EXTERN int setTextPositionY(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& y);

LIBSBMLNETWORK_EXTERN int setTextPosition(Layout* layout, GraphicalObject* graphicalObject, const double& x, const double& y);

LIBSBMLNETWORK_EXTERN int setTextPosition(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& x, const double& y);

LIBSBMLNETWORK_EXTERN const double getTextDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, const double& width);

LIBSBMLNETWORK_EXTERN int setTextDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& width);

LIBSBMLNETWORK_EXTERN const double getTextDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0);

LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, const double& height);

LIBSBMLNETWORK_EXTERN int setTextDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& height);

/// @brief Predicate returning true if the GraphicalObject with the given index associated with the model entity with the given id of the Layout object
/// has a Curve object and the curve consists of one or more segments.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetCurve(const Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Predicate returning true if this GraphicalObject object has a Curve object and the curve consists of one or more segments
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBMLNETWORK_EXTERN bool isSetCurve(const GraphicalObject* graphicalObject);

/// @brief Returns the Curve object of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the Curve object of the GraphicalObject object, or @c NULL if the object is @c NULL or does not have a Curve object
LIBSBMLNETWORK_EXTERN Curve* getCurve(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the Curve object of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the Curve object of the GraphicalObject object, or @c NULL if the object is @c NULL or does not have a Curve object
LIBSBMLNETWORK_EXTERN Curve* getCurve(GraphicalObject* graphicalObject);

/// @brief Removes the Curve object of this GraphicalObject object.
LIBSBMLNETWORK_EXTERN int removeCurve(GraphicalObject* graphicalObject);

/// @brief Returns the number of curve segments of the curve of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const unsigned int getNumCurveSegments(const Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Returns the number of curve segments of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const unsigned int getNumCurveSegments(const GraphicalObject* graphicalObject);

/// @brief Returns the number of curve segments of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the number of curve segments of the Curve object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumCurveSegments(const Curve* curve);

/// @brief Returns a pointer to the curve segment with the given index of the GraphicalObject with the given index associated with the model entity with the given id of the Layout object.
///// @param Layout a pointer to the Layout object.
///// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this GraphicalObject object.
LIBSBMLNETWORK_EXTERN LineSegment* getCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns a pointer to the curve segment of this GraphicalObject object with the given index.
/// @param curveSegmentIndex the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this GraphicalObject object.
LIBSBMLNETWORK_EXTERN LineSegment* getCurveSegment(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns a pointer to the curve segment of this Curve object with the given index.
/// @param curveSegmentIndex the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this Curve object.
LIBSBMLNETWORK_EXTERN LineSegment* getCurveSegment(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Creates a new LineSegment and adds it to the end of the list of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addLineCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Creates a new LineSegment and adds it to the end of the list of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addLineCurveSegment(GraphicalObject* graphicalObject);

/// @brief Creates a new LineSegment and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addLineCurveSegment(Curve* curve);

/// @brief Creates a new CubicBezier and adds it to the end of the list of the curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addCubicBezierCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0);

/// @brief Creates a new CubicBezier and adds it to the end of the list of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addCubicBezierCurveSegment(GraphicalObject* graphicalObject);

/// @brief Creates a new CubicBezier and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addCubicBezierCurveSegment(Curve* curve);

/// @brief Removes and deletes the curve segment with the given index from the list of the Curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Removes and deletes the curve segment with the given index from the list of the Curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeCurveSegment(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Removes and deletes the curve segment with the given index from the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeCurveSegment(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Predicate returning true if the curve segment with the given index of the Curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object is of type CubicBezier.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBMLNETWORK_EXTERN bool isCubicBezier(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Predicate returning true if the curve segment with the given index of the Curve of this GraphicalObject object is of type CubicBezier.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBMLNETWORK_EXTERN bool isCubicBezier(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Predicate returning true if the curve segment with the given index of this Curve object is of type CubicBezier.
/// @param curve a pointer to the Curve object.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBMLNETWORK_EXTERN bool isCubicBezier(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Predicate returning true if this abstract LineSegment is of type CubicBezier.
/// @param lineSegment a pointer to the LineSegment object.
/// @return @c true if this abstract LineSegment is of type CubicBezier, false otherwise
LIBSBMLNETWORK_EXTERN bool isCubicBezier(LineSegment* lineSegment);

/// @brief Returns the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object,
/// or @c 0.0 if the object is @c NULL or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the start point of the the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the start point of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the curve segment with the given index of the Curve object,
/// or @c 0.0 if the object is @c NULL or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointX(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param curveSegmentIndex an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointX(Curve* curve, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of the curve the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the start point of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentStartPointY(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentStartPointY(Curve* curve, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the end point of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointX(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointX(Curve* curve, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the end point of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentEndPointY(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentEndPointY(Curve* curve, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of the the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 1 of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1X(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of the of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of the of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1X(Curve* curve, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of the GraphicalObject
///// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 1 of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint1Y(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint1Y(Curve* curve, unsigned int curveSegmentIndex, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 2 of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2X(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2X(Curve* curve, unsigned int curveSegmentIndex, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the curve segment with the given index of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 2 of the curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the curve segment with the given index of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBMLNETWORK_EXTERN const double getCurveSegmentBasePoint2Y(Curve* curve, unsigned int curveSegmentIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of the first GraphicalObject
/// associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of the GraphicalObject
/// with the given index associated with the model entity with the given id of the Layout object.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the model entity the GraphicalObject object associated with it to be returned.
/// @param graphicalObjectIndex the index of the GraphicalObject to return.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of curve segment with the given index of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of curve segment with the given index of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCurveSegmentBasePoint2Y(Curve* curve, unsigned int curveSegmentIndex, const double& y);

}

#endif

