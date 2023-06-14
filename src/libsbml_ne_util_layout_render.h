#ifndef __LIBSBML_NE_UTIL_LAYOUT_RENDER_H_
#define __LIBSBML_NE_UTIL_LAYOUT_RENDER_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

/// @brief Get the List of local render Information of the Layout.
/// @param document a pointer to the Layout object.
/// @return a pointer to the ListOfGlobalInformationBase object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout);

/// @brief Returns the number of items in the ListOfGlobalRenderInformation of this Layout object.
/// @param layout a pointer to the Layout object.
/// @return the number of items in the ListOfGlobalRenderInformation of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLocalRenderInformation(Layout* layout);

/// @brief Returns a pointer to the nth LocalRenderInformation in the ListOfLocalRenderInformation of this layout object.
/// @param layout a pointer to the Layout object.
/// @param n the index number of the GlobalRenderInformation to return.
/// @return the @c the nth LocalRenderInformation in the ListOfLocalRenderInformation of this Layout object or NULL if
/// no such LocalRenderInformation exists or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* getLocalRenderInformation(Layout* layout, unsigned int n = 0);

/// @brief Add LocalRenderInformation to list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addLocalRenderInformation(Layout* layout, LocalRenderInformation* localRenderInformation);

/// @brief Create a LocalRenderInformation object and add it to list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @return a pointer to the created LocalRenderInformation object.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* createLocalRenderInformation(Layout* layout);

/// @brief Remove all the local render information objects from the list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeAllLocalRenderInformation(Layout* layout);

/// @brief Set all the necessary features for the local render information object.
/// @param document a pointer to the SBMLDocument object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRenderInformation);

}

#endif
