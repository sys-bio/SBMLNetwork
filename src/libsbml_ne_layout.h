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

/// @brief Returns the number of items in this ListOfLayouts object.
/// @param listOfLayouts a pointer to the ListOfLayouts object.
/// @return the number of items in this ListOfLayouts object, or @c 0 if the object is @c NULL
/// or does not have a curve
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts);

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

/// Returns the id of the associated compartment.
/// @param compartmentGlyph a pointer to the CompartmentGlyph object.
/// @return the value of the "compartment" attribute, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getCompartmentId(CompartmentGlyph* compartmentGlyph);

/// Returns the id of the associated species.
/// @param speciesGlyph a pointer to the SpeciesGlyph object.
/// @return the value of the "species" attribute, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesId(SpeciesGlyph* speciesGlyph);

/// Returns the id of the associated reaction.
/// @param reactionGlyph a pointer to the ReactionGlyph object.
/// @return the value of the "reaction" attribute, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getReactionId(ReactionGlyph* reactionGlyph);

/// Returns the id of the associated species reference.
/// @param speciesReference a pointer to the SpeciesReference object.
/// @return the value of the "speciesReference" attribute, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesReferenceId(SpeciesReferenceGlyph* speciesReferenceGlyph);

/// Returns the id of the associated SpeciesGlyph.
/// @param speciesReference a pointer to the SpeciesReference object.
/// @return the value of the "speciesglyph" attribute, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpeciesGlyphId(SpeciesReferenceGlyph* speciesReferenceGlyph);

/// Returns a string representation of the role.
/// @param speciesReference a pointer to the SpeciesReference object.
/// @return the value of the "speciesglyph" attribute, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getRole(SpeciesReferenceGlyph* speciesReferenceGlyph);

/// @brief Returns the GraphicalObject object with entered graphical object id.
/// @param layout a pointer to the Layout object.
/// @param graphicalObjectId the id of the graphical object to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getGraphicalObject(Layout* layout, const std::string& graphicalObjectId);

/// Returns the bounding box for the GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the bounding box for the GraphicalObject object, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN BoundingBox * getBoundingBox(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "x" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "x" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "x" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionX(BoundingBox* boundingBox);

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

/// @brief Returns the value of the "y" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "y" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "y" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "y" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getPositionY(BoundingBox* boundingBox);

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

/// @brief Returns the value of the "width" attribute of the bounding box of this GraphicalObject.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "width" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "width" attribute of this BoundingBox.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "width" attribute of the bounding box of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionWidth(BoundingBox* boundingBox);

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

/// @brief Returns the value of the "height" attribute of the bounding box of this GraphicalObject object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "height" attribute of the bounding box of the GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(GraphicalObject* graphicalObject);

/// @brief Returns the value of the "height" attribute of this BoundingBox object.
/// @param boundingBox a pointer to the BoundingBox object.
/// @return the "height" attribute of the BoundingBox object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getDimensionHeight(BoundingBox* boundingBox);

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

/// @brief Creates a new CubicBezier and adds it to the end of the list of this Curve object.
/// @param curve a pointer to the Curve object.
/// @return the created @c CubicBezier, or NULL if the line segment could not be created.
LIBSBML_NETWORKEDITOR_EXTERN CubicBezier* createCubicBezierCurveSegment(Curve* curve);

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

/// @brief Predicates returning @c true if the "text" attribute of this TextGlyph is set.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return @c true if the "text" attribute of this TextGlyph object is set, @c false if either the "text"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetText(TextGlyph* textGlyph);

/// @brief Returns the text associated with this TextGlyph object.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return the "text" attribute of this TextGlyph object
/// or @c empty string if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getText(TextGlyph* textGlyph);

/// @brief Sets the value of the "text" attribute this TextGlyph object.
/// @param textGlyph a pointer to the TextGlyph object.
/// @param text a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setText(TextGlyph* textGlyph, const std::string& text);

/// @brief Predicates returning @c true if the id of the origin of text is not the empty string.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return @c true if the id of the origin of text of this TextGlyph object not the empty string, @c false either
/// the id attribute is empty string or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOriginOfTextId(TextGlyph* textGlyph);

/// @brief Returns the id of the origin of text.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return the id of the origin of text of this TextGlyph object or @c empty string if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getOriginOfTextId(TextGlyph* textGlyph);

/// @brief Sets the id of the origin of text.
/// @param textGlyph a pointer to the TextGlyph object.
/// @param orig a string value to be set as "text" attribute of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOriginOfTextId(TextGlyph* textGlyph, const std::string& orig);

/// @brief Predicates returning @c true if the id of id of the associated graphical object is not the empty string.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return @c true if the id of the associated graphical object of this TextGlyph object not the empty string, @c false either
/// the id attribute is empty string or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetGraphicalObjectId(TextGlyph* textGlyph);

/// @brief Returns the id of the associated graphical object.
/// @param textGlyph a pointer to the TextGlyph object.
/// @return the id of the associated graphical object of this TextGlyph object or @c empty string if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const std::string getGraphicalObjectId(TextGlyph* textGlyph);

/// @brief Sets the id of the associated graphical object.
/// @param textGlyph a pointer to the TextGlyph object.
/// @param id a string value to be set as id of the associated graphical object of the TextGlyph object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setGraphicalObjectId(TextGlyph* textGlyph, const std::string& id);

}

#endif

