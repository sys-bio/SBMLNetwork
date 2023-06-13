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

}

#endif