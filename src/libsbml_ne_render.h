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

/// @brief Predicates returning @c true if the "stroke" attribute of this GraphicalPrimitive1D is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return @c true if the "stroke" attribute of this GraphicalPrimitive1D object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
bool isSetStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke" attribute of the GraphicalPrimitive1D object, or @c "" if the object is @c NULL
const std::string getStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke" attribute of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param stroke a string value to use as the value of the "stroke" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
int setStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& stroke);

/// @brief Predicates returning @c true if the "stroke-width" attribute of this GraphicalPrimitive1D is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return @c true if the "stroke-width" attribute of this GraphicalPrimitive1D object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
bool isSetStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke-width" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke-width" attribute of the GraphicalPrimitive1D object, or @c 0.0 if the object is @c NULL
const double getStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke-width" attribute of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param strokeWidth a double value to use as the value  of the "stroke-width" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
int setStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D, const double& strokeWidth);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of this GraphicalPrimitive1D is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return @c true if the "stroke-dasharray" attribute of this GraphicalPrimitive1D object is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
bool isSetStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the vector of the "stroke-dasharray" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or an empty vector if the object is @c NULL
const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke-dasharray" of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray);

/// @brief Returns the size of the "stroke-dasharray" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the size of "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or an 0 if the object is @c NULL
unsigned int getNumStrokeDashes(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the dash at the given index of the 'stroke-dasharray' attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param n an unsigned int representing the index of the dash to retrieve.
/// @return the dash at the given index of "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or an 0 if the object is @c NULL
unsigned int getDash(GraphicalPrimitive1D* graphicalPrimitive1D, unsigned  int n);

/// @brief Predicates returning @c true if the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
bool isSetFontColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "stroke" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const std::string getFontColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontColor a string value to use as the value of the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setFontColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontColor);

/// @brief Predicates returning @c true if the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-family"
/// attribute is not set or the object is @c NULL .
bool isSetFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-family" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const std::string getFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontFamily);

/// @brief Predicates returning @c true if the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-size"
/// attribute is not set or the object is @c NULL .
bool isSetFontSize(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-size" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const RelAbsVector getFontSize(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontFamily a string value to use as the value of the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setFontSize(GraphicalPrimitive1D* graphicalPrimitive1D, const RelAbsVector& fontSize);

/// @brief Predicates returning @c true if the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-weight"
/// attribute is not set or the object is @c NULL .
bool isSetFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-weight" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const std::string getFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontWeight);

/// @brief Predicates returning @c true if the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-style"
/// attribute is not set or the object is @c NULL .
bool isSetFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-style" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const std::string getFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontStyle);

/// @brief Predicates returning @c true if the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "text-anchor"
/// attribute is not set or the object is @c NULL .
bool isSetTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "text-anchor" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const std::string getTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& textAnchor);

/// @brief Predicates returning @c true if the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "vtext-anchor"
/// attribute is not set or the object is @c NULL .
bool isSetVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "vtext-anchor" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
const std::string getVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
int setVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& vtextAnchor);

/// @brief Predicates returning @c true if the "fill" attribute of this GraphicalPrimitive2D is set.
/// @param graphicalPrimitive2D a pointer to the GraphicalPrimitive2D object.
/// @return @c true if the "fill" attribute of this GraphicalPrimitive2D object is set, @c false if either the "fill"
/// attribute is not set or the object is @c NULL .
bool isSetFillColor(GraphicalPrimitive2D* graphicalPrimitive2D);

/// @brief Returns the value of the "fill" attribute of this GraphicalPrimitive2D.
/// @param graphicalPrimitive2D a pointer to the GraphicalPrimitive2D object.
/// @return the "fill" attribute of the GraphicalPrimitive2D object, or @c "" if the object is @c NULL
const std::string getFillColor(GraphicalPrimitive2D* graphicalPrimitive2D);

/// @brief Sets the value of the "fill" attribute of this GraphicalPrimitive2D object.
/// @param graphicalPrimitive2D a pointer to the GraphicalPrimitive2D object.
/// @param fill a string value to use as the value of the "fill" attribute of this GraphicalPrimitive2D object.
/// @return integer value indicating success/failure of the function.
int setFillColor(GraphicalPrimitive2D* graphicalPrimitive2D, const std::string& fill);

/// @brief Predicates returning @c true if the "x" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "x" attribute of this Rectangle object is set, @c false if either the "x" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeX(Rectangle* rectangle);

/// @brief Returns the value of the "x" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "x" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getRectangleShapeX(Rectangle* rectangle);

/// @brief Sets the value of the "x" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeX(Rectangle* rectangle, const RelAbsVector& x);

/// @brief Predicates returning @c true if the "y" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "y" attribute of this Rectangle object is set, @c false if either the "y" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeY(Rectangle* rectangle);

/// @brief Returns the value of the "y" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "y" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getRectangleShapeY(Rectangle* rectangle);

/// @brief Sets the value of the "y" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeY(Rectangle* rectangle, const RelAbsVector& y);

/// @brief Predicates returning @c true if the "width" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "width" attribute of this Rectangle object is set, @c false if either the "width" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeWidth(Rectangle* rectangle);

/// @brief Returns the value of the "width" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "width" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getRectangleShapeWidth(Rectangle* rectangle);

/// @brief Sets the value of the "width" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeWidth(Rectangle* rectangle, const RelAbsVector& width);

/// @brief Predicates returning @c true if the "height" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "height" attribute of this Rectangle object is set, @c false if either the "height" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeHeight(Rectangle* rectangle);

/// @brief Returns the value of the "height" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "height" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getRectangleShapeHeight(Rectangle* rectangle);

/// @brief Sets the value of the "height" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeHeight(Rectangle* rectangle, const RelAbsVector& height);

/// @brief Predicates returning @c true if the "ratio" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "ratio" attribute of this Rectangle object is set, @c false if either the "ratio" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeRatio(Rectangle* rectangle);

/// @brief Returns the value of the "ratio" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "ratio" attribute of the Rectangle object, or @c "0.0" if the object is @c NULL
const double getRectangleShapeRatio(Rectangle* rectangle);

/// @brief Sets the value of the "ratio" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param ratio a double value to use as the value of the "ratio" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeRatio(Rectangle* rectangle, const double& ratio);

/// @brief Predicates returning @c true if the "rx" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "rx" attribute of this Rectangle object is set, @c false if either the "rx" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeRX(Rectangle* rectangle);

/// @brief Returns the value of the "rx" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "rx" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getRectangleShapeRX(Rectangle* rectangle);

/// @brief Sets the value of the "rx" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeRX(Rectangle* rectangle, const RelAbsVector& rx);

/// @brief Predicates returning @c true if the "ry" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "ry" attribute of this Rectangle object is set, @c false if either the "ry" attribute is not set or the object is @c NULL .
bool isSetRectangleShapeRY(Rectangle* rectangle);

/// @brief Returns the value of the "ry" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "ry" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getRectangleShapeRY(Rectangle* rectangle);

/// @brief Sets the value of the "ry" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
int setRectangleShapeRY(Rectangle* rectangle, const RelAbsVector& ry);

/// @brief Predicates returning @c true if the "cx" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "cx" attribute of this Ellipse object is set, @c false if either the "cx" attribute is not set or the object is @c NULL .
bool isSetEllipseShapeCX(Ellipse* ellipse);

/// @brief Returns the value of the "cx" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "cx" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getEllipseShapeCX(Ellipse* ellipse);

/// @brief Sets the value of the "cx" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
int setEllipseShapeCX(Ellipse* ellipse, const RelAbsVector& cx);

/// @brief Predicates returning @c true if the "cy" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "cy" attribute of this Ellipse object is set, @c false if either the "cy" attribute is not set or the object is @c NULL .
bool isSetEllipseShapeCY(Ellipse* ellipse);

/// @brief Returns the value of the "cy" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "cy" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getEllipseShapeCY(Ellipse* ellipse);

/// @brief Sets the value of the "cy" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
int setEllipseShapeCY(Ellipse* ellipse, const RelAbsVector& cy);

/// @brief Predicates returning @c true if the "rx" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "rx" attribute of this Ellipse object is set, @c false if either the "rx" attribute is not set or the object is @c NULL .
bool isSetEllipseShapeRX(Ellipse* ellipse);

/// @brief Returns the value of the "rx" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "rx" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getEllipseShapeRX(Ellipse* ellipse);

/// @brief Sets the value of the "rx" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
int setEllipseShapeRX(Ellipse* ellipse, const RelAbsVector& rx);

/// @brief Predicates returning @c true if the "ry" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "ry" attribute of this Ellipse object is set, @c false if either the "ry" attribute is not set or the object is @c NULL .
bool isSetEllipseShapeRY(Ellipse* ellipse);

/// @brief Returns the value of the "ry" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "ry" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getEllipseShapeRY(Ellipse* ellipse);

/// @brief Sets the value of the "ry" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
int setEllipseShapeRY(Ellipse* ellipse, const RelAbsVector& ry);

/// @brief Predicates returning @c true if the "ratio" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "ratio" attribute of this Ellipse object is set, @c false if either the "ratio" attribute is not set or the object is @c NULL .
bool isSetEllipseShapeRatio(Ellipse* ellipse);

/// @brief Returns the value of the "ratio" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "ratio" attribute of the Ellipse object, or @c "0.0" if the object is @c NULL
const double getEllipseShapeRatio(Ellipse* ellipse);

/// @brief Sets the value of the "ratio" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param ratio a double value to use as the value of the "ratio" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
int setEllipseShapeRatio(Ellipse* ellipse, const double& ratio);

/// @brief Returns the value of the "x" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeElementX(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "x" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeElementX(Polygon* polygon, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeElementY(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeElementY(Polygon* polygon, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 1 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 1 of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 2 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 2 of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeElementX(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeElementX(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeElementY(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeElementY(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 2 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getPolygonShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setPolygonShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 2 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
const RelAbsVector getRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
int setRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Predicates returning @c true if the "x" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "x" attribute of this Image object is set, @c false if either the "x" attribute is not set or the object is @c NULL .
bool isSetImageShapeX(Image* image);

/// @brief Returns the value of the "x" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "x" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getImageShapeX(Image* image);

/// @brief Sets the value of the "x" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
int setImageShapeX(Image* image, const RelAbsVector& x);

/// @brief Predicates returning @c true if the "y" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "y" attribute of this Image object is set, @c false if either the "y" attribute is not set or the object is @c NULL .
bool isSetImageShapeY(Image* image);

/// @brief Returns the value of the "y" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "y" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getImageShapeY(Image* image);

/// @brief Sets the value of the "y" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
int setImageShapeY(Image* image, const RelAbsVector& y);

/// @brief Predicates returning @c true if the "width" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "width" attribute of this Image object is set, @c false if either the "width" attribute is not set or the object is @c NULL .
bool isSetImageShapeWidth(Image* image);

/// @brief Returns the value of the "width" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "width" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getImageShapeWidth(Image* image);

/// @brief Sets the value of the "width" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
int setImageShapeWidth(Image* image, const RelAbsVector& width);

/// @brief Predicates returning @c true if the "height" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "height" attribute of this Image object is set, @c false if either the "height" attribute is not set or the object is @c NULL .
bool isSetImageShapeHeight(Image* image);

/// @brief Returns the value of the "height" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "height" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
const RelAbsVector getImageShapeHeight(Image* image);

/// @brief Sets the value of the "height" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
int setImageShapeHeight(Image* image, const RelAbsVector& height);

/// @brief Predicates returning @c true if the "href" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "href" attribute of this Image object is set, @c false if either the "href" attribute is not set or the object is @c NULL .
bool isSetImageShapeHref(Image* image);

/// @brief Returns the value of the "href" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @return the "href" attribute of the Image object, or @c "" if the object is @c NULL
const std::string getImageShapeHref(Image* image);

/// @brief Sets the value of the "href" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param stroke a string value to use as the value of the "image" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
int setImageShapeHref(Image* image, const std::string& href);

/// @brief Add a geometric shape to this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param shape a string value indicating the shape of the geometric shape to be added.
/// @return integer value indicating success/failure of the function.
int addGeometricShape(RenderGroup* renderGroup, const std::string& shape);

/// @brief Remove a geometric shape from this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param n an unsigned int representing the index of the Transformation2D to remove.
/// @return a pointer to the nth Transformation2D in this RenderGroup.
int addGeometricShape(RenderGroup* renderGroup, const std::string& shape);

/// @brief Add a render point to this Transformation2d (Polygon or RenderCurve).
/// @param shape a pointer to the Transformation2d object.
/// @return integer value indicating success/failure of the function.
int addRenderPointToShape(Transformation2D* shape);

/// @brief Add a render cubic bezier to this Transformation2d (Polygon or RenderCurve).
/// @param shape a pointer to the Transformation2d object.
/// @return integer value indicating success/failure of the function.
int addRenderCubicBezierToShape(Transformation2D* shape);

/// @brief Remove an element from this Transformation2d (Polygon or RenderCurve).
/// @param shape a pointer to the Transformation2d object.
/// @param n an unsigned int representing the index of the RenderPoint to remove.
/// @return a pointer to the nth RenderPoint in this Transformation2d.
RenderPoint * removeElementFromShape(Transformation2D* shape, unsigned int n);

/// @brief Predicates returning @c true if the "startHead" attribute of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return @c true if the "startHead" attribute of this RenderGroup object is set, @c false if either the "startHead" attribute is not set or the object is @c NULL .
bool isSetStartHead(RenderGroup* renderGroup);

/// @brief Returns the value of the "startHead" attribute of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "startHead" attribute of the RenderGroup object, or @c false if the object is @c NULL
const std::string getStartHead(RenderGroup* renderGroup);

/// @brief Sets the value of the "startHead" attribute of this RenderGroup object.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param startHead a boolean to use as the value of the "startHead" attribute of this RenderGroup object.
/// @return integer value indicating success/failure of the function.
int setStartHead(RenderGroup* renderGroup, const std::string startHead);

/// @brief Predicates returning @c true if the "endHead" attribute of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return @c true if the "endHead" attribute of this RenderGroup object is set, @c false if either the "endHead" attribute is not set or the object is @c NULL .
bool isSetEndHead(RenderGroup* renderGroup);

/// @brief Returns the value of the "endHead" attribute of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "endHead" attribute of the RenderGroup object, or @c false if the object is @c NULL
const std::string getEndHead(RenderGroup* renderGroup);

/// @brief Sets the value of the "endHead" attribute of this RenderGroup object.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param endHead a boolean to use as the value of the "endHead" attribute of this RenderGroup object.
/// @return integer value indicating success/failure of the function.
int setEndHead(RenderGroup* renderGroup, const std::string endHead);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of this LineEnding is set.
/// @param lineEnding a pointer to the LineEnding object.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
bool isSetEnableRotationalMapping(LineEnding* lineEnding);

/// @brief Returns the value of the "enableRotationalMapping" attribute of this LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
bool getEnableRotationalMapping(LineEnding* lineEnding);

/// @brief Sets the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @param lineEnding a pointer to the LineEnding object.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
int setEnableRotationalMapping(LineEnding* lineEnding, bool enableRotationalMapping);

}

#endif

