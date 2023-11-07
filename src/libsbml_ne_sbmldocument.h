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

/// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
/// to the the SBML document, and set all the necessary features for them.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultLayoutAndRenderFeatures(SBMLDocument* document, const double& stiffness = 10.0, const double& gravity = 15.0, const bool& useMagnetism = false, const bool& useBoundary = false, const bool& useGrid = false);

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

/// @brief Returns a pointer to the Compartment object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Compartment object
/// @return a pointer to the Compartment object with the given id, or @c "" if the object does not exists.
LIBSBML_NETWORKEDITOR_EXTERN Compartment* getCompartment(SBMLDocument* document, const std::string& id);

/// @brief Returns a pointer to the Species object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Species object.
/// @return a pointer to the Species object with the given id, or @c "" if the object does not exists.
LIBSBML_NETWORKEDITOR_EXTERN Species* getSpecies(SBMLDocument* document, const std::string& id);

/// @brief Returns a pointer to the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Reaction object.
/// @return a pointer to the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBML_NETWORKEDITOR_EXTERN Reaction* getReaction(SBMLDocument* document, const std::string& id);

/// @brief Returns a pointer to the SpeciesReference object associated with the given reactant/product species id in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param speciesId the id of the Species object.
/// @return a pointer to the SpeciesReference object, or @c NULL if the object does not exists or is not of type reactant/product.
LIBSBML_NETWORKEDITOR_EXTERN SpeciesReference* getSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId);

/// @brief Returns a pointer to the ModifierSpeciesReference object associated with the given modifier species id in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param speciesId the id of the Species object.
/// @return a pointer to the ModifierSpeciesReference object, or @c NULL if the object does not exists or is not of type modifier.
LIBSBML_NETWORKEDITOR_EXTERN ModifierSpeciesReference* getModifierSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId);

}

#endif