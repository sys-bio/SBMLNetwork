#ifndef __LIBSBML_NE_UTIL_RENDER_H_
#define __LIBSBML_NE_UTIL_RENDER_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

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

}

#endif