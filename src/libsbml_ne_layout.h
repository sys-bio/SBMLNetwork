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

/// @brief Returns the Curve object of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the Curve object of the GraphicalObject object, or @c NULL if the object is @c NULL or does not have
/// a Curve object
Curve* getCurve(GraphicalObject* graphicalObject);

/// @brief Returns the number of curve segments of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the number of curve segments of the curve of the GraphicalObject object, or @c 0 if the object is @c NULL
/// or does not have a curve
const unsigned int getNumCurveSegments(GraphicalObject* graphicalObject);

/// @brief Returns the number of curve segments of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the number of curve segments of the Curve object, or @c 0 if the object is @c NULL
const unsigned int getNumCurveSegments(Curve* curve);

/// @brief Returns a pointer to the curve segment of this GraphicalObject object with the given index.
/// @param index the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this GraphicalObject object.
LineSegment* getCurveSegment(GraphicalObject* graphicalObject, unsigned int index);

/// @brief Returns a pointer to the curve segment of this Curve object with the given index.
/// @param index the index value of the curve segment to return.
/// @return the @c LineSegment representing the child "curveSegment" with the appropriate index, or NULL if no such LineSegment exists for
/// this Curve object.
LineSegment* getCurveSegment(Curve* curve, unsigned int index);

/// @brief Creates a new LineSegment and adds it to the end of the list of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the created @c LineSegment, or NULL if the line segment could not be created.
LineSegment* createLineCurveSegment(GraphicalObject* graphicalObject);

/// @brief Creates a new LineSegment and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the created @c LineSegment, or NULL if the line segment could not be created.
LineSegment* createLineCurveSegment(Curve* curve);

/// @brief Creates a new CubicBezier and adds it to the end of the list of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
CubicBezier* createCubicBezierCurveSegment(GraphicalObject* graphicalObject);

/// @brief Removes and deletes a curve segment from the list of the Curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
int removeCurveSegment(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Removes and deletes a curve segment from the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to remove.
/// @return integer value indicating success/failure of the function.
int removeCurveSegment(Curve* curve, unsigned int n);

/// @brief Creates a new CubicBezier and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
CubicBezier* createCubicBezierCurveSegment(Curve* curve);

/// @brief Predicate returning true if this abstract LineSegment is of type CubicBezier.
/// @param lineSegment a pointer to the LineSegment object.
/// @return @c true if this abstract LineSegment is of type CubicBezier, false otherwise
bool isCubicBezier(LineSegment* lineSegment);

/// @brief Returns the value of the "x" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the start point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the start point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentStartPointX(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the start point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the start point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentStartPointX(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the start point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the start point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentStartPointY(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the start point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the start point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentStartPointY(Curve* curve, unsigned int n, const double& y);

/// @brief Returns the value of the "x" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the end point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the end point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentEndPointX(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the end point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the end point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentEndPointX(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the end point of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the end point of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentEndPointY(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the end point of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the end point of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentEndPointY(Curve* curve, unsigned int n, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 1 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentBasePoint1X(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 1 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint1X(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 1 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentBasePoint1Y(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 1 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint1Y(Curve* curve, unsigned int n, const double& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "x" attribute of the base point 2 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentBasePoint2X(Curve* curve, unsigned int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param x a double value to use as the value of the "x" attribute of the base point 2 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint2X(Curve* curve, unsigned int n, const double& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the nth curve segment of the curve of this GraphicalObject object, or @c 0.0 if the object is @c NULL
/// or does not have a curve
const double getCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @return the "y" attribute of the base point 2 of the nth curve segment of the Curve object, or @c 0.0 if the object is @c NULL or does not
/// have a curve
const double getCurveSegmentBasePoint2Y(Curve* curve, unsigned int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of nth curve segment of the curve of this GraphicalObject object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth curve segment of this Curve object.
/// @param curve a pointer to the Curve object.
/// @param n an unsigned int representing the index of the curve segment to retrieve.
/// @param y a double value to use as the value of the "y" attribute of the base point 2 of nth curve segment of this Curve object.
/// @return integer value indicating success/failure of the function.
int setCurveSegmentBasePoint2Y(Curve* curve, unsigned int n, const double& y);

}

#endif

