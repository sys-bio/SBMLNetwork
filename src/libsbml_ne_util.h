#ifndef __LIBSBML_NE_UTIL_H_
#define __LIBSBML_NE_UTIL_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

/// @brief Reads an SBML document from the given file name or the given text string
/// @param sbml either the name or full pathname of the file to be read or a string containing a full SBML model.
/// @return a pointer to the SBMLDocument structure created from the SBML content in the given file name or
/// from the SBML content in the given text string.
LIBSBML_NETWORKEDITOR_EXTERN SBMLDocument* readSBML(const std::string &sbml);

/// @brief Writes the given SBML document to a filename.
/// @param document the SBML document to be written.
/// @param fileName the name or full pathname of the file where the SBML is to be written.
/// @return true on success and false if the filename could not be opened for writing.
LIBSBML_NETWORKEDITOR_EXTERN bool writeSBML(SBMLDocument* document, const std::string &fileName);

/// @brief Writes the given SBML document to a string and returns it.
/// @param document the SBML document to be written.
/// @return the string on success and empty string if one of the underlying parser components fail.
LIBSBML_NETWORKEDITOR_EXTERN const std::string writeSBML(SBMLDocument* document);

/// @brief Create a Layout object, add it to list of layouts of the SBML document, and
/// set all the necessary features for it
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultLayout(SBMLDocument* document);

/// @brief Create a GlobalRenderInformation object and add it to list of global renders of the SBML document, and
/// Create a LocalRenderInformation object, add it to list of local renders of the Layout of the SBML document, and
/// set all the necessary features for them.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultRenderInformation(SBMLDocument* document);

/// @brief Create a GlobalRenderInformation object, add it to list of global renders of the SBML document, and
/// set all the necessary features for it.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultGlobalRenderInformation(SBMLDocument* document);

/// @brief Create a LocalRenderInformation object, add it to list of local renders of the Layout of the SBML document, and
/// set all the necessary features for it.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultLocalRenderInformation(SBMLDocument* document);

/// @brief Predicates returning @c true if the "id" attribute of this SBML object is set.
/// @param object a pointer to the SBML object.
/// @return @c true if the "id" attribute of this SBML object is set, @c false if either the "id"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetId(SBase* object);

/// Returns the value of the "id" attribute of this SBML object.
/// @param object a pointer to the SBML object.
/// @return the "id" attribute of the SBML object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getId(SBase* object);

/// @brief Sets the value of the "id" attribute this SBML object.
/// @param object a pointer to the SBML object.
/// @param sid a string value to be set as "id" attribute of the SBML object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setId(SBase* object, const std::string& sid);

/// @brief Predicates returning @c true if the "name" attribute of this SBML object is set.
/// @param object a pointer to the SBML object.
/// @return @c true if the "name" attribute of this SBML object is set, @c false if either the "name"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetName(SBase* object);

/// Returns the value of the "name" attribute of this SBML object.
/// @param object a pointer to the SBML object.
/// @return the "name" attribute of the SBML object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getName(SBase* object);

/// @brief Sets the value of the "name" attribute this SBML object.
/// @param object a pointer to the SBML object.
/// @param name a string value to be set as "name" attribute of the SBML object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setName(SBase* object, const std::string& name);

/// @brief Predicates returning @c true if the "metaid" attribute of this SBML object is set.
/// @param object a pointer to the SBML object.
/// @return @c true if the "metaid" attribute of this SBML object is set, @c false if either the "metaid"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetMetaId(SBase* object);

/// Returns the value of the "metaid" attribute of this SBML object.
/// @param object a pointer to the SBML object.
/// @return the "metaid" attribute of the SBML object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getMetaId(SBase* object);

/// @brief Sets the value of the "metaid" attribute this SBML object.
/// @param object a pointer to the SBML object.
/// @param metaid a string value to be set as "metaid" attribute of the SBML object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setMetaId(SBase* object, const std::string& metaid);

/// @brief Returns the number of CompartmentGlyph objects associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the number of CompartmentGlyph objects associated with it is going to be returned.
/// @return the number of CompartmentGlyph objects associated with the entered compartment id,
/// or @c 0 if the object is @c NULL or has no associated CompartmentGlyph objects
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

/// @brief Returns a vector of CompartmentGlyph objects associated with the entered compartment id.
/// @param document a pointer to the SBMLDocument object.
/// @param compartmentId the id of the compartment the CompartmentGlyph objects of which are going to be returned.
/// @return a vector of CompartmentGlyph objects associated with the entered compartment id.
LIBSBML_NETWORKEDITOR_EXTERN std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId);

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