#ifndef __LIBSBML_NE_LAYOUT_H_
#define __LIBSBML_NE_LAYOUT_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

/// @brief Get the Layout of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the Layout object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfLayouts* getListOfLayouts(SBMLDocument* document);

/// @brief Returns the number of items in the ListOfLayouts of this SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of items in of this SBML document, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLayouts(SBMLDocument* document);

/// @brief Returns the number of items in this ListOfLayouts object.
/// @param listOfLayouts a pointer to the ListOfLayouts object.
/// @return the number of items in this ListOfLayouts object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts);

/// @brief Returns a pointer to the nth Layout in the ListOfLayouts of the SBML document.
/// @param n the index number of the Layout to return.
/// @return the @c the nth Layout in the ListOfLayouts of the SBML document or NULL if no such Layout exists or the document is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN Layout* getLayout(SBMLDocument* document, unsigned int n);

/// @brief Returns a pointer to the nth Layout in this ListOfLayouts.
/// @param n the index number of the Layout to return.
/// @return the @c the nth Layout in this ListOfLayouts or NULL if no such Layout exists or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN Layout* getLayout(ListOfLayouts* listOfLayouts, unsigned int n);

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

/// @brief Predicates returning @c true if the "id" attribute of this GraphicalObject is set.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "id" attribute of this GraphicalObject object is set, @c false if either the "id"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetId(GraphicalObject* graphicalObject);

/// Returns the value of the "id" attribute of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "id" attribute of the GraphicalObject object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getId(GraphicalObject* graphicalObject);

/// @brief Sets the value of the "id" attribute this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param sid a string value to be set as "id" attribute of the GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setId(GraphicalObject* graphicalObject, const std::string& sid);

/// @brief Predicates returning @c true if the "name" attribute of this GraphicalObject is set.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "name" attribute of this GraphicalObject object is set, @c false if either the "name"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetName(GraphicalObject* graphicalObject);

/// Returns the value of the "name" attribute of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "name" attribute of the GraphicalObject object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getName(GraphicalObject* graphicalObject);

/// @brief Sets the value of the "name" attribute this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param name a string value to be set as "name" attribute of the GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setName(GraphicalObject* graphicalObject, const std::string& name);

/// @brief Returns the GraphicalObject object with entered graphical object id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getGraphicalObject(Layout* layout, const std::string& id);

/// @brief Returns the number of CompartmentGlyphs of this Layout object.
/// @param Layout a pointer to the Layout object.
/// @return the number of CompartmentGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(Layout* layout);

/// @brief Returns a pointer to the CompartmentGlyph of this Layout object with the given id.
/// @param id the id of the CompartmentGlyph to return.
/// @return the @c CompartmentGlyph with the given id, or NULL if CompartmentGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN CompartmentGlyph* getCompartmentGlyph(Layout* layout, const std::string& id);

/// @brief Returns a pointer to the CompartmentGlyph of this Layout object with the given index.
/// @param index the index value of the CompartmentGlyph to return.
/// @return the @c CompartmentGlyph with the given index, or NULL if CompartmentGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN CompartmentGlyph* getCompartmentGlyph(Layout* layout, unsigned int index);

/// Returns the id of the compartment associated with the CompartmentGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the CompartmentGlyph.
/// @return the value of the "compartment" attribute of the CompartmentGlyph with the given id, or @c "" if
/// the CompartmentGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getCompartmentId(Layout* layout, const std::string& id);

/// @brief Returns the id of the compartment associated with the CompartmentGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the CompartmentGlyph.
/// @return the value of the "compartment" attribute of the CompartmentGlyph with the given index, or @c "" if
/// the CompartmentGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getCompartmentId(Layout* layout, unsigned int index);

/// Returns the id of the associated compartment.
/// @param compartmentGlyph a pointer to the GraphicalObject object.
/// @return the value of the "compartment" attribute, or @c "" if the object is not of type CompartmentGlyph or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getCompartmentId(GraphicalObject* compartmentGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id is of type CompartmentGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCompartmentGlyph(Layout* layout, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index is of type CompartmentGlyph.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCompartmentGlyph(Layout* layout, unsigned int index);

/// @brief Predicate returning true if this abstract GraphicalObject is of type CompartmentGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type CompartmentGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCompartmentGlyph(GraphicalObject* graphicalObject);

/// @brief Returns the number of SpeciesGlyphs of this Layout object.
/// @param Layout a pointer to the Layout object.
/// @return the number of SpeciesGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesGlyphs(Layout* layout);

/// @brief Returns a pointer to the SpeciesGlyph of this Layout object with the given id.
/// @param id the id of the SpeciesGlyph to return.
/// @return the @c SpeciesGlyph with the given id, or NULL if SpeciesGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN SpeciesGlyph* getSpeciesGlyph(Layout* layout, const std::string& id);

/// @brief Returns a pointer to the SpeciesGlyph of this Layout object with the given index.
/// @param index the index value of the SpeciesGlyph to return.
/// @return the @c SpeciesGlyph with the given index, or NULL if SpeciesGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN SpeciesGlyph* getSpeciesGlyph(Layout* layout, unsigned int index);

/// Returns the id of the species associated with the SpeciesGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the SpeciesGlyph.
/// @return the value of the "species" attribute of the SpeciesGlyph with the given id, or @c "" if
/// the SpeciesGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesId(Layout* layout, const std::string& id);

/// @brief Returns the id of the species associated with the SpeciesGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the SpeciesGlyph.
/// @return the value of the "species" attribute of the SpeciesGlyph with the given index, or @c "" if
/// the SpeciesGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesId(Layout* layout, unsigned int index);

/// Returns the id of the associated species.
/// @param speciesGlyph a pointer to the GraphicalObject object.
/// @return the value of the "species" attribute, or @c "" if the object is not of type SpeciesGlyph or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesId(GraphicalObject* speciesGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id is of type SpeciesGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesGlyph(Layout* layout, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index is of type SpeciesGlyph.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesGlyph(Layout* layout, unsigned int index);

/// @brief Predicate returning true if this abstract GraphicalObject is of type SpeciesGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type SpeciesGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesGlyph(GraphicalObject* graphicalObject);

/// @brief Returns the number of ReactionGlyphs of this Layout object.
/// @param Layout a pointer to the Layout object.
/// @return the number of ReactionGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumReactionGlyphs(Layout* layout);

/// @brief Returns a pointer to the ReactionGlyph of this Layout object with the given id.
/// @param id the id of the ReactionGlyph to return.
/// @return the @c ReactionGlyph with the given id, or NULL if ReactionGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN ReactionGlyph* getReactionGlyph(Layout* layout, const std::string& id);

/// @brief Returns a pointer to the ReactionGlyph of this Layout object with the given index.
/// @param index the index value of the ReactionGlyph to return.
/// @return the @c ReactionGlyph with the given index, or NULL if ReactionGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN ReactionGlyph* getReactionGlyph(Layout* layout, unsigned int index);

/// Returns the id of the reaction associated with the ReactionGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the ReactionGlyph.
/// @return the value of the "reaction" attribute of the ReactionGlyph with the given id, or @c "" if
/// the ReactionGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getReactionId(Layout* layout, const std::string& id);

/// @brief Returns the id of the reaction associated with the ReactionGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the ReactionGlyph.
/// @return the value of the "reaction" attribute of the ReactionGlyph with the given index, or @c "" if
/// the ReactionGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getReactionId(Layout* layout, unsigned int index);

/// Returns the id of the associated reaction.
/// @param reactionGlyph a pointer to the GraphicalObject object.
/// @return the value of the "reaction" attribute, or @c "" if the object is not of type ReactionGlyph or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getReactionId(GraphicalObject* reactionGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id is of type ReactionGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isReactionGlyph(Layout* layout, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index is of type ReactionGlyph.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isReactionGlyph(Layout* layout, unsigned int index);

/// @brief Predicate returning true if this abstract GraphicalObject is of type ReactionGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type ReactionGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isReactionGlyph(GraphicalObject* graphicalObject);

/// @brief Returns the number of SpeciesReferenceGlyphs of this ReactionGlyph object.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @return the number of SpeciesReferenceGlyphs of this ReactionGlyph object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumSpeciesReferenceGlyphs(GraphicalObject* reactionGlyph);

/// @brief Returns a pointer to the SpeciesReferenceGlyphs of this ReactionGlyph object with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param index the index value of the SpeciesReferenceGlyphs to return.
/// @return the @c SpeciesReferenceGlyphs with the given index, or NULL if SpeciesReferenceGlyphs does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN SpeciesReferenceGlyph* getSpeciesReferenceGlyph(GraphicalObject* reactionGlyph, unsigned int index);

/// @brief Returns the id of the species reference associated with the SpeciesReferenceGlyph with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param index the index value of the SpeciesReferenceGlyph.
/// @return the value of the "species reference" attribute of the SpeciesReferenceGlyph with the given index, or @c "" if
/// the ReactionGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesReferenceId(GraphicalObject* reactionGlyph, unsigned int index);

/// Returns the id of the associated species reference.
/// @param speciesReferenceGlyph a pointer to the GraphicalObject object.
/// @return the value of the "speciesReference" attribute, or @c "" if the object is not of type SpeciesReferenceGlyph or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesReferenceId(GraphicalObject* speciesReferenceGlyph);

/// @brief Returns the id of the species glyph associated with the SpeciesReferenceGlyph with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param index the index value of the SpeciesReferenceGlyph.
/// @return the value of the "speciesglyph" attribute of the SpeciesReferenceGlyph with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesGlyphId(GraphicalObject* reactionGlyph, unsigned int index);

/// Returns the id of the associated SpeciesGlyph.
/// @param speciesReference a pointer to the GraphicalObject object.
/// @return the value of the "speciesglyph" attribute, or @c "" if the object is not of type SpeciesReferenceGlyph or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesGlyphId(GraphicalObject* speciesReferenceGlyph);

/// @brief Returns the string representation of the role the SpeciesReferenceGlyph with the given index.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @param index the index value of the SpeciesReferenceGlyph.
/// @return the value of the "role" attribute of the SpeciesReferenceGlyph with the given index, or @c "" if
/// the SpeciesReferenceGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getRole(GraphicalObject* reactionGlyph, unsigned int index);

/// Returns the string representation of the role.
/// @param speciesReference a pointer to the GraphicalObject object.
/// @return the value of the "role" attribute, or @c "" if the object is not of type SpeciesReferenceGlyph or is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getRole(GraphicalObject* speciesReferenceGlyph);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index is of type SpeciesReferenceGlyph.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type SpeciesReferenceGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesReferenceGlyph(Layout* layout, unsigned int index);

/// @brief Predicate returning true if this abstract GraphicalObject is of type SpeciesReferenceGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type SpeciesReferenceGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSpeciesReferenceGlyph(GraphicalObject* graphicalObject);

/// @brief Returns the number of TextGlyphs of this Layout object.
/// @param Layout a pointer to the Layout object.
/// @return the number of TextGlyphs of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumTextGlyphs(Layout* layout);

/// @brief Returns a pointer to the TextGlyphs of this Layout object with the given id.
/// @param id the id of the TextGlyph to return.
/// @return the @c TextGlyph with the given id, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN TextGlyph* getTextGlyph(Layout* layout, const std::string& id);

/// @brief Returns a pointer to the TextGlyph of this Layout object with the given index.
/// @param index the index value of the TextGlyph to return.
/// @return the @c TextGlyph with the given index, or NULL if TextGlyph does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN TextGlyph* getTextGlyph(Layout* layout, unsigned int index);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph with the given id is set.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetText(Layout* layout, const std::string& id);

/// @brief Predicates returning @c true if the "text" attribute of TextGlyph with the given index is set.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetText(Layout* layout, unsigned int index);

/// @brief Predicates returning @c true if the "text" attribute of this TextGlyph is set.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetText(GraphicalObject* textGlyph);

/// @brief Returns the text associated with the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getText(Layout* layout, const std::string& id);

/// @brief Returns the text associated with the TextGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getText(Layout* layout, unsigned int index);

/// @brief Returns the text associated with this TextGlyph object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return the "text" attribute of this TextGlyph object or @c empty string if either the "text" attribute is not set,
/// or the object is not of type TextGlyph or is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getText(GraphicalObject* textGlyph);

/// @brief Sets the value of the "text" attribute of the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(Layout* layout, const std::string& id, const std::string& text);

/// @brief Sets the value of the "text" attribute of the TextGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(Layout* layout, unsigned int index, const std::string& text);

/// @brief Sets the value of the "text" attribute this TextGlyph object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(GraphicalObject* textGlyph, const std::string& text);

/// @brief Predicates returning @c true if the origin of text of TextGlyph with the given id is not the empty string.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOriginOfTextId(Layout* layout, const std::string& id);

/// @brief Predicates returning @c true if the origin of text of TextGlyph with the given index is not the empty string.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOriginOfTextId(Layout* layout, unsigned int index);

/// @brief Predicates returning @c true if the id of the origin of text is not the empty string.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return @c true if the id of the origin of text of this TextGlyph object not the empty string, @c false
/// either the "originOfTextId" attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOriginOfTextId(GraphicalObject* textGlyph);

/// @brief Returns the id of the origin of text of the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @return the id of the origin of text of this TextGlyph or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getOriginOfTextId(Layout* layout, const std::string& id);

/// @brief Returns the id of the origin of text of the TextGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @return the id of the origin of text of this TextGlyph or @c empty string if either the "originOfTextId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getOriginOfTextId(Layout* layout, unsigned int index);

/// @brief Returns the id of the origin of text.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if either
/// the "originOfTextId" attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getOriginOfTextId(GraphicalObject* textGlyph);

/// @brief Sets id of the origin of text of the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(Layout* layout, const std::string& id, const std::string& orig);

/// @brief Sets id of the origin of text of the TextGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(Layout* layout, unsigned int index, const std::string& orig);

/// @brief Sets the id of the origin of text.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @param orig a string value to be set as the if the origin of text attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(GraphicalObject* textGlyph, const std::string& orig);

/// @brief Predicates returning @c true if id of the associated graphical object of TextGlyph with the given id is not the empty string.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @return @c true if the id of the associated graphical object of this TextGlyph object is not the empty string, @c false if either the id
/// of the associated graphical object is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetGraphicalObjectId(Layout* layout, const std::string& id);

/// @brief Predicates returning @c true if the origin of text of TextGlyph with the given index is not the empty string.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @return @c true if the origin of text of this TextGlyph object is not the empty string, @c false if either the origin of text
/// is empty, or TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetGraphicalObjectId(Layout* layout, unsigned int index);

/// @brief Predicates returning @c true if the id of the associated graphical object is not the empty string.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return @c true if the id of the associated graphical object of this TextGlyph object not the empty string, @c false if either
/// the "graphicalObjectId" attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetGraphicalObjectId(GraphicalObject* textGlyph);

/// @brief Returns the id of the associated graphical object of the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getGraphicalObjectId(Layout* layout, const std::string& id);

/// @brief Returns the id of the associated graphical object of the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param index the index of the TextGlyph.
/// @return the id of associated graphical object of this TextGlyph or @c empty string if either the "graphicalObjectId" attribute is not set
/// , TextGlyph does not exits or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getGraphicalObjectId(Layout* layout, unsigned int index);

/// @brief Returns the id of the associated graphical object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @return the id of the associated graphical object of this TextGlyph object or @c empty string if either the "graphicalObjectId"
/// attribute is not set, or the object is not of type TextGlyph or is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getGraphicalObjectId(GraphicalObject* textGlyph);

/// @brief Sets the id of the associated graphical object of the TextGlyph with the given id.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the TextGlyph.
/// @param id a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(Layout* layout, const std::string& id, const std::string& orig);

/// @brief Sets the id of the associated graphical object of the TextGlyph with the given index.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the TextGlyph.
/// @param id a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(Layout* layout, unsigned int index, const std::string& orig);

/// @brief Sets the id of the associated graphical object.
/// @param textGlyph a pointer to the GraphicalObject object.
/// @param id a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(GraphicalObject* textGlyph, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given id is of type TextGlyph.
/// @param Layout a pointer to the Layout object.
/// @param id the id of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isText(Layout* layout, const std::string& id);

/// @brief Predicate returning true if the abstract GraphicalObject with the given index is of type TextGlyph.
/// @param Layout a pointer to the Layout object.
/// @param index the index value of the GraphicalObject.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isText(Layout* layout, unsigned int index);

/// @brief Predicate returning true if this abstract GraphicalObject is of type TextGlyph.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if this abstract GraphicalObject is of type TextGlyph, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isText(GraphicalObject* graphicalObject);

/// @brief Returns the bounding box for the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @return the bounding box for the GraphicalObject object, or @c NULL if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN BoundingBox* getBoundingBox(Layout* layout, const std::string& id);

/// Returns the bounding box for the GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the bounding box for the GraphicalObject object, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN BoundingBox* getBoundingBox(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of the bounding box of the GraphicalObject with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(Layout* layout, const std::string& id);

/// @brief Returns the value of the "x" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "x" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(BoundingBox* boundingBox);

/// @brief Sets the value of the "x" attribute of the bounding box of the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(Layout* layout, const std::string& id, const double& x);

/// @brief Sets the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param x a double value to use as the value of the "x" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPositionX(BoundingBox* boundingBox, const double& x);

/// @brief Returns the value of the "y" attribute of the bounding box of the GraphicalObject with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(Layout* layout, const std::string& id);

/// @brief Returns the value of the "y" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "y" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "y" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(BoundingBox* boundingBox);

/// @brief Sets the value of the "y" attribute of the bounding box of the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPositionY(Layout* layout, const std::string& id, const double& y);

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

/// @brief Returns the value of the "width" attribute of the bounding box of the GraphicalObject with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(Layout* layout, const std::string& id);

/// @brief Returns the value of the "width" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "width" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "width" attribute of the bounding box of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(BoundingBox* boundingBox);

/// @brief Sets the value of the "width" attribute of the bounding box of the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @param width a double value to use as the value of the "width" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(Layout* layout, const std::string& id, const double& width);

/// @brief Sets the value of the "width" attribute of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "width" attribute of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(GraphicalObject* graphicalObject, const double& width);

/// @brief Sets the value of the "width" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "width" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionWidth(BoundingBox* boundingBox, const double& width);

/// @brief Returns the value of the "height" attribute of the bounding box of the GraphicalObject with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(Layout* layout, const std::string& id);

/// @brief Returns the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "height" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(BoundingBox* boundingBox);

/// @brief Sets the value of the "height" attribute of the bounding box of the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @param height a double value to use as the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(Layout* layout, const std::string& id, const double& height);

/// @brief Sets the value of the "height" attribute of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "height" attribute of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(GraphicalObject* graphicalObject, const double& height);

/// @brief Sets the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "height" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDimensionHeight(BoundingBox* boundingBox, const double& height);

/// @brief Predicate returning true if this GraphicalObject object has a Curve object and the curve consists of one or more segments
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the GraphicalObject has a Curve object and the curve consists of one or more segments, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isSetCurve(GraphicalObject* graphicalObject);

/// @brief Returns the Curve object of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the Curve object of the GraphicalObject object, or @c NULL if the object is @c NULL or does not have
/// a Curve object
LIBSBML_NETWORKEDITOR_EXTERN Curve* getCurve(GraphicalObject* graphicalObject);

/// @brief Returns the number of curve segments of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCurveSegments(GraphicalObject* graphicalObject);

/// @brief Returns the number of curve segments of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the number of curve segments of the Curve object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCurveSegments(Curve* curve);

/// @brief Returns a pointer to the curve segment of this GraphicalObject object with the given index.
/// @param index the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this GraphicalObject object.
LIBSBML_NETWORKEDITOR_EXTERN LineSegment* getCurveSegment(GraphicalObject* graphicalObject, unsigned int index);

/// @brief Returns a pointer to the curve segment of this Curve object with the given index.
/// @param index the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this Curve object.
LIBSBML_NETWORKEDITOR_EXTERN LineSegment* getCurveSegment(Curve* curve, unsigned int index);

/// @brief Creates a new LineSegment and adds it to the end of the list of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the created @c LineSegment, or NULL if the line segment could not be created.
LIBSBML_NETWORKEDITOR_EXTERN LineSegment* createLineCurveSegment(GraphicalObject* graphicalObject);

/// @brief Creates a new LineSegment and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the created @c LineSegment, or NULL if the line segment could not be created.
LIBSBML_NETWORKEDITOR_EXTERN LineSegment* createLineCurveSegment(Curve* curve);

/// @brief Creates a new CubicBezier and adds it to the end of the list of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
LIBSBML_NETWORKEDITOR_EXTERN CubicBezier* createCubicBezierCurveSegment(GraphicalObject* graphicalObject);

/// @brief Creates a new CubicBezier and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
LIBSBML_NETWORKEDITOR_EXTERN CubicBezier* createCubicBezierCurveSegment(Curve* curve);

/// @brief Removes and deletes a curve segment from the list of the Curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeCurveSegment(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Removes and deletes a curve segment from the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeCurveSegment(Curve* curve, unsigned int n);

/// @brief Predicate returning true if the nth curve segment of the Curve of this GraphicalObject object is of type CubicBezier.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCubicBezier(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Predicate returning true if the nth curve segment of this Curve object is of type CubicBezier.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment.
/// @return @c true if this curve segment is of type CubicBezier, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCubicBezier(Curve* curve, unsigned int n);

/// @brief Predicate returning true if this abstract LineSegment is of type CubicBezier.
/// @param lineSegment a pointer to the LineSegment object.
/// @return @c true if this abstract LineSegment is of type CubicBezier, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isCubicBezier(LineSegment* lineSegment);

/// @brief Returns the value of the "x" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the start point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentStartPointX(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentStartPointX(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the start point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentStartPointY(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentStartPointY(Curve* curve, unsigned int n, const double& y);

/// @brief Returns the value of the "x" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the end point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentEndPointX(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentEndPointX(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the end point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentEndPointY(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentEndPointY(Curve* curve, unsigned int n, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint1X(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint1X(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint1Y(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint1Y(Curve* curve, unsigned int n, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint2X(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint2X(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
LIBSBML_NETWORKEDITOR_EXTERN const double getCurveSegmentBasePoint2Y(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setCurveSegmentBasePoint2Y(Curve* curve, unsigned int n, const double& y);

}

#endif

