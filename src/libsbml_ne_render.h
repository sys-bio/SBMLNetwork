#ifndef __LIBSBML_NE_RENDER_H_
#define __LIBSBML_NE_RENDER_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

/// @brief Get the List of global render Information of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the ListOfRenderInformationBase object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfGlobalRenderInformation* getListOfGlobalRenderInformation(SBMLDocument* document);

/// @brief Get the List of local render Information of the Layout.
/// @param document a pointer to the Layout object.
/// @return a pointer to the ListOfGlobalInformationBase object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout);

/// @brief Add GlobalRenderInformation to list of global renders of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param globalRednderInformation a pointer to the GlobalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addGlobalRender(SBMLDocument* document, GlobalRenderInformation* globalRednderInformation);

/// @brief Add LlobalRenderInformation to list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @param localRednderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addLocalRender(Layout* layout, LocalRenderInformation* localRednderInformation);

/// @brief Create a GlobalRenderInformation object and add it to list of global renders of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the created GlobalRenderInformation object.
LIBSBML_NETWORKEDITOR_EXTERN GlobalRenderInformation* createGlobalRender(SBMLDocument* document);

/// @brief Create a LocalRenderInformation object and add it to list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @return a pointer to the created LocalRenderInformation object.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* createLocalRender(Layout* layout);

/// @brief Remove all the global render information objects from the list of global renders of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeGlobalRenders(SBMLDocument* document);

/// @brief Remove all the local render information objects from the list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeLocalRenders(Layout* layout);

/// @brief Set all the necessary features for the global render information object.
/// @param document a pointer to the SBMLDocument object.
/// @param globalRednderInformation a pointer to the GlobalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultGlobalRenderFeatures(SBMLDocument* document, GlobalRenderInformation* globalRednderInformation);

/// @brief Set all the necessary features for the local render information object.
/// @param document a pointer to the SBMLDocument object.
/// @param localRednderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultLocalRenderFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRednderInformation);

/// @brief Searches among the styles of local render information information and returns one with the "id"
/// attribute of the GraphicalObject object in its "idlist" attribute list.
/// @param localRednderInformation  a pointer to the LocalRenderInformation object.
/// @param graphicalObject  a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* findStyle(LocalRenderInformation* localRednderInformation, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of global render information and returns one with either the "role"
/// attribute of the GraphicalObject object in its "rolelist" attribute list or "type"
/// in its "typelist" attribute list.
/// @param globalRednderInformation  a pointer to the GlobalRenderInformation object.
/// @param graphicalObject  a pointer to the GraphicalObject object.
/// @param objectType  a string indicating the type of the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* findStyle(GlobalRenderInformation* globalRednderInformation, GraphicalObject* graphicalObject, const std::string& objectType = "");

/// @brief Returns the value of the "stroke" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke" attribute of the GraphicalPrimitive1D object, or @c "" if the object is @c NULL
const std::string getStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke" attribute of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param stroke a string value to use as the value of the "stroke" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
int setStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& stroke);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @return the "stroke" attribute of the RenderGroup of the Style object, or @c "" if the object is @c NULL
const std::string getStrokeColor(Style* style);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param stroke a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
int setStrokeColor(Style* style, const std::string& stroke);

/// @brief Returns the value of the "stroke-width" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke-width" attribute of the GraphicalPrimitive1D object, or @c 0.0 if the object is @c NULL
const double getStrokeWidth(Style* style);

/// @brief Sets the value of the "stroke-width" attribute of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param strokeWidth a double value to use as the value  of the "stroke-width" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
int setStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D, const double& strokeWidth);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @return the "stroke-width" attribute of the RenderGroup of the Style object, or @c 0.0 if the object is @c NULL
const double getStrokeWidth(Style* style);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeWidth a double value to use as the value  of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
int setStrokeWidth(Style* style, const double& strokeWidth);

/// @brief Returns the vector of the "stroke-dasharray" attribute of this GraphicalPrimitive1D.
/// @param style a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or an empty vector if the object is @c NULL
const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke-dasharray" of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray);

/// @brief Returns the vector of the "stroke-dasharray" attribute of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @return the "stroke-dasharray" attribute of the RenderGroup of the Style object, or an empty vector if the object is @c NULL
const std::vector<unsigned int> getStrokeDashArray(Style* style);

/// @brief Sets the value of the "stroke-dasharray" of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
int setStrokeDashArray(Style* style, const std::vector<unsigned int>& strokeDashArray);

}

#endif

