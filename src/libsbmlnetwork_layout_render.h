#ifndef __LIBSBMLNETWORK_UTIL_LAYOUT_RENDER_H_
#define __LIBSBMLNETWORK_UTIL_LAYOUT_RENDER_H_

#include "libsbmlnetwork_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

/// @brief Get the List of local render Information of the Layout.
/// @param document a pointer to the Layout object.
/// @return a pointer to the ListOfGlobalInformationBase object of the SBML document.
LIBSBMLNETWORK_EXTERN ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout);

/// @brief Returns the number of items in the ListOfGlobalRenderInformation of this Layout object.
/// @param layout a pointer to the Layout object.
/// @return the number of items in the ListOfGlobalRenderInformation of this Layout object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumLocalRenderInformation(Layout* layout);

/// @brief Returns a pointer to the LocalRenderInformation object with the given index in the ListOfLocalRenderInformation of this layout object.
/// @param layout a pointer to the Layout object.
/// @param n the index number of the GlobalRenderInformation to return.
/// @return the @c the LocalRenderInformation with the given index in the ListOfLocalRenderInformation of this Layout object or NULL if
/// no such LocalRenderInformation exists or the object is @c NULL.
LIBSBMLNETWORK_EXTERN LocalRenderInformation* getLocalRenderInformation(Layout* layout, unsigned int renderIndex = 0);

/// @brief Add LocalRenderInformation to list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addLocalRenderInformation(Layout* layout, LocalRenderInformation* localRenderInformation);

/// @brief Create a LocalRenderInformation object and add it to list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @return a pointer to the created LocalRenderInformation object.
LIBSBMLNETWORK_EXTERN LocalRenderInformation* createLocalRenderInformation(Layout* layout);

/// @brief Remove all the local render information objects from the list of local renders of the Layout.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeAllLocalRenderInformation(Layout* layout);

/// @brief Set all the necessary features for the local render information object.
/// @param document a pointer to the SBMLDocument object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRenderInformation);

LIBSBMLNETWORK_EXTERN int setCompartmentStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN int setSpeciesStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN int setReactionStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN int setSpeciesReferenceStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN int setCompartmentStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setSpeciesStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setReactionStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setSpeciesReferenceStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setCompartmentFontColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontColor);

LIBSBMLNETWORK_EXTERN int setSpeciesFontColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontColor);

LIBSBMLNETWORK_EXTERN int setReactionFontColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontColor);

LIBSBMLNETWORK_EXTERN int setCompartmentFontFamily(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontFamily);

LIBSBMLNETWORK_EXTERN int setSpeciesFontFamily(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontFamily);

LIBSBMLNETWORK_EXTERN int setReactionFontFamily(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontFamily);

LIBSBMLNETWORK_EXTERN int setCompartmentFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize);

LIBSBMLNETWORK_EXTERN int setCompartmentFontSizeAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& fontSize);

LIBSBMLNETWORK_EXTERN int setSpeciesFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize);

LIBSBMLNETWORK_EXTERN int setSpeciesFontSizeAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& fontSize);

LIBSBMLNETWORK_EXTERN int setReactionFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize);

LIBSBMLNETWORK_EXTERN int setReactionFontSizeAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& fontSize);

LIBSBMLNETWORK_EXTERN int setCompartmentFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight);

LIBSBMLNETWORK_EXTERN int setSpeciesFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight);

LIBSBMLNETWORK_EXTERN int setReactionFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight);

LIBSBMLNETWORK_EXTERN int setCompartmentFontStyle(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontStyle);

LIBSBMLNETWORK_EXTERN int setSpeciesFontStyle(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontStyle);

LIBSBMLNETWORK_EXTERN int setReactionFontStyle(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontStyle);

LIBSBMLNETWORK_EXTERN int setCompartmentTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& textAnchor);

LIBSBMLNETWORK_EXTERN int setSpeciesTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& textAnchor);

LIBSBMLNETWORK_EXTERN int setReactionTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& textAnchor);

LIBSBMLNETWORK_EXTERN int setCompartmentVTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& vTextAnchor);

LIBSBMLNETWORK_EXTERN int setSpeciesVTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& vTextAnchor);

LIBSBMLNETWORK_EXTERN int setReactionVTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& vTextAnchor);

LIBSBMLNETWORK_EXTERN int setCompartmentFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor);

LIBSBMLNETWORK_EXTERN int setCompartmentFillColorAsGradient(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setSpeciesFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor);

LIBSBMLNETWORK_EXTERN int setSpeciesFillColorAsGradient(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setReactionFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor);

LIBSBMLNETWORK_EXTERN int setReactionFillColorAsGradient(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setCompartmentFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule);

LIBSBMLNETWORK_EXTERN int setSpeciesFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule);

LIBSBMLNETWORK_EXTERN int setReactionFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeType(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& shape);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeType(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& shape);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeType(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& shape);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& x);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& x);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& x);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& y);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& y);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& y);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeWidthAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeWidthAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeWidthAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeHeightAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& height);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeHeightAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& height);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeHeightAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& height);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementX);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementY);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1X);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1X);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1X);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1Y);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1Y);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1Y);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2X);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2X);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2X);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2Y);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2Y);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2Y);

LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href);

LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href);

LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href);

}

#endif
