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
LIBSBML_NETWORKEDITOR_EXTERN int removeLayouts(SBMLDocument* document);

/// @brief Set all the necessary features for the layout object.
/// @param document a pointer to the SBMLDocument object.
/// @param layout a pointer to the Layout object.
/// @return integer value indicating success/failure of the function.
int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout);

/// @brief Returns the GraphicalObject object with entered graphical object id.
/// @param layout a pointer to the Layout object.
/// @param graphicalObjectId the id of the graphical object to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
GraphicalObject* getGraphicalObject(Layout* layout, const std::string& graphicalObjectId);

/// @brief Returns the value of the "x" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
const double getPositionX(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "x" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
const double getPositionX(BoundingBox* boundingBox);

/// @brief Sets the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double value to use as the value of the "x" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setPositionX(GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param x a double value to use as the value of the "x" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
int setPositionX(BoundingBox* boundingBox, const double& x);

/// @brief Returns the value of the "y" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
const double getPositionY(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "y" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "y" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
const double getPositionY(BoundingBox* boundingBox);

/// @brief Sets the value of the "y" attribute of the bounding box this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double value to use as the value of the "y" attribute of the bounding box of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setPositionY(GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param y a double value to use as the value of the "y" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
int setPositionY(BoundingBox* boundingBox, const double& y);

/// @brief Returns the value of the "width" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
const double getDimensionWidth(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "width" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "width" attribute of the bounding box of the BoundingBox object, or @c 0.0 if the object is @c NULL
const double getDimensionWidth(BoundingBox* boundingBox);

/// @brief Sets the value of the "width" attribute of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "width" attribute of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setDimensionWidth(GraphicalObject* graphicalObject, const double& width);

/// @brief Sets the value of the "width" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "width" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
int setDimensionWidth(BoundingBox* boundingBox, const double& width);

/// @brief Returns the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
const double getDimensionHeight(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "height" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
const double getDimensionHeight(BoundingBox* boundingBox);

/// @brief Sets the value of the "height" attribute of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double value to use as the value of the "height" attribute of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setDimensionHeight(GraphicalObject* graphicalObject, const double& height);

/// @brief Sets the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @param width a double value to use as the value of the "height" attribute of this BoundingBox object.
/// @return integer value indicating success/failure of the function.
int setDimensionHeight(BoundingBox* boundingBox, const double& height);

}

#endif

