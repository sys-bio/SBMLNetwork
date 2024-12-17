#ifndef __LIBSBMLNETWORK_RENDER_H_
#define __LIBSBMLNETWORK_RENDER_H_

#include "libsbmlnetwork_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

/// @brief Returns the number of items in this ListOfGlobalRenderInformation object.
/// @param listOfGlobalRenderInformation a pointer to the ListOfGlobalRenderInformation object.
/// @return the number of items in this ListOfGlobalRenderInformation object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation);

/// @brief Returns a pointer to the the GlobalRenderInformation object with the given index in this ListOfGlobalRenderInformation.
/// @param renderIndex the index number of the GlobalRenderInformation to return.
/// @return the @c the GlobalRenderInformation with the given index in this ListOfGlobalRenderInformation or NULL if no such GlobalRenderInformation exists or the object is @c NULL.
LIBSBMLNETWORK_EXTERN GlobalRenderInformation* getGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation, unsigned int renderIndex = 0);

/// @brief Returns the number of items in this ListOfLocalRenderInformation object.
/// @param listOfLocalRenderInformation a pointer to the ListOfLocalRenderInformation object.
/// @return the number of items in this ListOfLocalRenderInformation object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation);

/// @brief Returns a pointer to the the LocalRenderInformation object with the given index in this ListOfLocalRenderInformation.
/// @param renderIndex the index number of the LocalRenderInformation to return.
/// @return the @c the LocalRenderInformation object with the given index in this ListOfLocalRenderInformation or NULL if no such LocalRenderInformation exists or the object is @c NULL.
LIBSBMLNETWORK_EXTERN LocalRenderInformation* getLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation, unsigned int renderIndex = 0);

/// @brief Predicates returning @c true if the "backgroundColor" attribute of this RenderInformationBase is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @return @c true if the "backgroundColor" attribute of this RenderInformationBase object is set, @c false if either the "backgroundColor"
/// attribute is not set or the object is @c NULL.
bool isSetBackgroundColor(RenderInformationBase* renderInformationBase);

/// @brief Returns the value of the "backgroundColor" attribute of this RenderInformationBase.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @return the "backgroundColor" attribute of the RenderInformationBase object, or @c "" if the object is @c NULL
const std::string getBackgroundColor(RenderInformationBase* renderInformationBase);

/// @brief Sets the value of the "backgroundColor" attribute of this RenderInformationBase object.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param backgroundColorId a string value to use as the value of the "backgroundColor" attribute of this RenderInformationBase object.
/// @param backgroundColorValue a string value showing the value of the backgroundColorId in the RenderInformationBase object.
/// @return integer value indicating success/failure of the function.
int setBackgroundColor(RenderInformationBase* renderInformationBase, const std::string& backgroundColorId, const std::string& backgroundColorValue);

/// @brief Returns the number of ColorDefinitions of this RenderInformationBase object.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @return the number of ColorDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumColorDefinitions(RenderInformationBase* renderInformationBase);

/// @brief Returns a ColorDefinition from the RenderInformationBase based on its identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the @c ColorDefinition in the ListOfColorDefinitions within this RenderInformationBase with the given sid or @c NULL if no such ColorDefinition exists.
LIBSBMLNETWORK_EXTERN ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns a pointer to the ColorDefinition of this RenderInformationBase object with the given index.
/// @param colorIndex the index value of the ColorDefinition to return.
/// @return the @c ColorDefinition with the given index, or NULL if ColorDefinition does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, unsigned int colorIndex = 0);

/// @brief Predicates returning @c true if the "value" attribute of the ColorDefinition with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetValue(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "value" attribute of this ColorDefinition is set.
/// @param colorDefinition a pointer to the ColorDefinition object.
/// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetValue(ColorDefinition* colorDefinition);

/// @brief Returns the value of the "value" attribute of the ColorDefinition with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getValue(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "value" attribute of this ColorDefinition.
/// @param colorDefinition a pointer to the ColorDefinition object.
/// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getValue(ColorDefinition* colorDefinition);

/// @brief Sets the value of the "value" attribute of the ColorDefinition with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setValue(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& value);

/// @brief Sets the value of the "value" attribute of this ColorDefinition object.
/// @param colorDefinition a pointer to the ColorDefinition object.
/// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setValue(ColorDefinition* colorDefinition, const std::string& value);

/// @brief Returns the number of GradientDefinitions of this RenderInformationBase object.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @return the number of GradientDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumGradientDefinitions(RenderInformationBase* renderInformationBase);

/// @brief Returns a GradientBase from the RenderInformationBase based on its identifier.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the @c GradientBase in the ListOfGradientDefinitions within this RenderInformationBase with the given sid or @c NULL if no such GradientBase exists.
LIBSBMLNETWORK_EXTERN GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns a pointer to the GradientBase of this RenderInformationBase object with the given index.
/// @param gradientIndex the index value of the GradientBase to return.
/// @return the @c GradientBase with the given index, or NULL if GradientBase does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, unsigned int gradientIndex = 0);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier is of type LinearGradient.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBMLNETWORK_EXTERN bool isLinearGradient(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicate returning true if this abstract GradientBase is of type LinearGradient.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBMLNETWORK_EXTERN bool isLinearGradient(GradientBase* gradientBase);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier is of type RadialGradient.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBMLNETWORK_EXTERN bool isRadialGradient(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicate returning true if this abstract GradientBase is of type RadialGradient.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBMLNETWORK_EXTERN bool isRadialGradient(GradientBase* gradientBase);

/// @brief Predicates returning @c true if the "spreadMethod" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "spreadMethod" attribute of this GradientBase object is set, @c false if either the "spreadMethod"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "spreadMethod" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "spreadMethod" attribute of this GradientBase object is set, @c false if either the "spreadMethod"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetSpreadMethod(GradientBase* gradientBase);

/// @brief Returns the value of the "spreadMethod" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "spreadMethod" attribute of the GradientBase object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "spreadMethod" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "spreadMethod" attribute of the GradientBase object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getSpreadMethod(GradientBase* gradientBase);

/// @brief Sets the value of the "spreadMethod" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& spreadMethod);

/// @brief Sets the value of the "spreadMethod" attribute of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpreadMethod(GradientBase* gradientBase, const std::string& spreadMethod);

/// @brief Returns Get the number of GradientStop objects in the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the number of GradientStop objects in this GradientBase, or 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumGradientStops(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns Get the number of GradientStop objects in this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the number of GradientStop objects in this GradientBase, or 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumGradientStops(GradientBase* gradientBase);

/// @brief Returns the GradientStop object with the given index of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop to retrieve.
/// @return the GradientStop at the given index of the GradientBase object, or NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN GradientStop* getGradientStop(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the GradientStop object with the given index of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop to retrieve.
/// @return the GradientStop at the given index of the GradientBase object, or NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN GradientStop* getGradientStop(GradientBase* gradientBase, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "offset" attribute of the GradientStop with the given index of this the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return @c true if the "offset" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if
/// either the "offset" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "offset" attribute of the GradientStop with the given index of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return @c true if the "offset" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if
/// either the "offset" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOffset(GradientBase* gradientBase, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "offset" attribute of this GradientStop is set.
/// @param gradientStop a pointer to the GradientStop object.
/// @return @c true if the "offset" attribute of this GradientStop object is set, @c false if either the "offset" attribute is not set
/// or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetOffset(GradientStop* gradientStop);

/// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "offset" attribute of the GradientStop with the given index of the GradientBase object, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getOffset(RenderInformationBase* renderInformationBase, const std::string& sid , unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "offset" attribute of the GradientStop with the given index of the GradientBase object, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getOffset(GradientBase* gradientBase , unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "offset" attribute of this GradientStop.
/// @param gradientStop a pointer to the GradientStop object.
/// @return the "offset" attribute of the GradientStop object, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getOffset(GradientStop* gradientStop);

/// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop to retrieve.
/// @return the "offset" attribute of the GradientStop with the given index of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getOffsetAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop to retrieve.
/// @return the "offset" attribute of the GradientStop with the given index of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getOffsetAsDouble(GradientBase* gradientBase, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "offset" attribute of this GradientStop as a double.
/// @param gradientStop a pointer to the GradientStop object.
/// @return the "offset" attribute of the GradientStop object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getOffsetAsDouble(GradientStop* gradientStop);

/// @brief Sets the value of the "offset" attribute of the first GradientStop of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the first GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffset(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the GradientStop with the given index of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the first GradientStop of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the first GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffset(GradientBase* gradientBase, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the GradientStop with the given index of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffset(GradientBase* gradientBase, unsigned int gradientStopIndex, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of this GradientStop object.
/// @param gradientStop a pointer to the GradientStop object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffset(GradientStop* gradientStop, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the first GradientStop of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param offset a double value to use as the value of the "offset" attribute of the first GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffsetAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& offset);

/// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a double value to use as the value of the "offset" attribute of the GradientStop with the given index of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffsetAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex, const double& offset);

/// @brief Sets the value of the "offset" attribute of the first GradientStop of this GradientBase object as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param offset a double value to use as the value of the "offset" attribute of the first GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffsetAsDouble(GradientBase* gradientBase, const double& offset);

/// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of this GradientBase object as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a double value to use as the value of the "offset" attribute of the GradientStop with the given index of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffsetAsDouble(GradientBase* gradientBase, unsigned int gradientStopIndex, const double& offset);

/// @brief Sets the value of the "offset" attribute of this GradientStop object as a double.
/// @param gradientStop a pointer to the GradientStop object.
/// @param offset a double value to use as the value of the "offset" attribute of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setOffsetAsDouble(GradientStop* gradientStop, const double& offset);

/// @brief Predicates returning @c true if the "stop-color" attribute of the GradientStop with the given index of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "stop-color" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "stop-color" attribute of the GradientStop with the given index of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "stop-color" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStopColor(GradientBase* gradientBase, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "stop-color" attribute of this GradientStop is set.
/// @param gradientStop a pointer to the GradientStop object.
/// @return @c true if the "stop-color" attribute of this GradientStop object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStopColor(GradientStop* gradientStop);

/// @brief Returns the value of the "stop-color" attribute of the GradientStop with the given index of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "stop-color" attribute of the GradientStop with the given index of this GradientStop object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "stop-color" attribute of the GradientStop with the given index of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "stop-color" attribute of the GradientStop with the given index of this GradientStop object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStopColor(GradientBase* gradientBase, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "stop-color" attribute of this GradientStop.
/// @param gradientStop a pointer to the GradientStop object.
/// @return the "stop-color" attribute of the GradientStop object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStopColor(GradientStop* gradientStop);

/// @brief Sets the value of the "stop-color" attribute of the first GradientStop of this the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param stopColorId a string value to use as the value of the "stop-color" attribute of the first GradientStop of this GradientBase object.
/// @param stopColorValue a string value showing the value of the stopColorId in the RenderInformationBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& stopColorId, const std::string& stopColorValue);

/// @brief Sets the value of the "stop-color" attribute of the GradientStop with the given index of this the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param stopColorId a string value to use as the value of the "stop-color" attribute of the GradientStop with the given index of this GradientBase object.
/// @param stopColorValue a string value showing the value of the stopColorId in the RenderInformationBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColorId, const std::string& stopColorValue);

/// @brief Sets the value of the "stop-color" attribute of the first GradientStop of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param stopColorId a string value to use as the value of the "stop-color" attribute of the first GradientStop of this GradientBase object.
/// @param stopColorValue a string value showing the value of the stopColorId in the GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStopColor(GradientBase* gradientBase, const std::string& stopColorId, const std::string& stopColorValue);

/// @brief Sets the value of the "stop-color" attribute of the GradientStop with the given index of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param stopColorId a string value to use as the value of the "stop-color" attribute of the GradientStop with the given index of this GradientBase object.
/// @param stopColorValue a string value showing the value of the stopColorId in the GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStopColor(GradientBase* gradientBase, unsigned int gradientStopIndex, const std::string& stopColorId, const std::string& stopColorValue);

/// @brief Sets the value of the "stop-color" attribute of this GradientStop object.
/// @param gradientStop a pointer to the GradientStop object.
/// @param stopColorId a string value to use as the value of the "stop-color" attribute of this GradientStop object.
/// @param stopColorValue a string value showing the value of the stopColorId in the GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStopColor(GradientStop* gradientStop, const std::string& stopColorId, const std::string& stopColorValue);

/// @brief Predicates returning @c true if the "x1" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "x1" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientX1(GradientBase* gradientBase);

/// @brief Returns the value of the "x1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "x1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "x1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientX1(GradientBase* gradientBase);

/// @brief Returns the value of the "x1" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x1" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientX1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "x1" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "x1" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientX1AsDouble(GradientBase* gradientBase);

/// @brief Returns the value of the "x1" attribute of this GradientStop as a double.
/// @param gradientStop a pointer to the GradientStop object.
/// @return the "x1" attribute of the GradientStop object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientX1AsDouble(GradientStop* gradientStop);

/// @brief Sets the value of the "x1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x1 a RelAbsVector to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x1);

/// @brief Sets the value of the "x1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param x1 a RelAbsVector to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX1(GradientBase* gradientBase, const RelAbsVector& x1);

/// @brief Sets the value of the "x1" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x1 a double value to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& x1);

/// @brief Sets the value of the "x1" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param x1 a double value to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX1AsDouble(GradientBase* gradientBase, const double& x1);

/// @brief Predicates returning @c true if the "x2" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x2" attribute of this GradientBase object is set, @c false if either the "x2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "x2" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "x2" attribute of this GradientBase object is set, @c false if either the "x2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientX2(GradientBase* gradientBase);

/// @brief Returns the value of the "x2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "x2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "x2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientX2(GradientBase* gradientBase);

/// @brief Returns the value of the "x2" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x2" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientX2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "x2" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "x2" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientX2AsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "x2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x2 a RelAbsVector to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x2);

/// @brief Sets the value of the "x2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param x2 a RelAbsVector to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX2(GradientBase* gradientBase, const RelAbsVector& x2);

/// @brief Sets the value of the "x2" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x2 a double value to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& x2);

/// @brief Sets the value of the "x2" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param x2 a double value to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientX2AsDouble(GradientBase* gradientBase, const double& x2);

/// @brief Predicates returning @c true if the "y1" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y1" attribute of this GradientBase object is set, @c false if either the "y1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "y1" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "y1" attribute of this GradientBase object is set, @c false if either the "y1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientY1(GradientBase* gradientBase);

/// @brief Returns the value of the "y1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "y1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "y1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientY1(GradientBase* gradientBase);

/// @brief Returns the value of the "y1" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y1" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientY1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "y1" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "y1" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientY1AsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "y1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y1 a RelAbsVector to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y1);

/// @brief Sets the value of the "y1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param y1 a RelAbsVector to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY1(GradientBase* gradientBase, const RelAbsVector& y1);

/// @brief Sets the value of the "y1" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y1 a double value to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& y1);

/// @brief Sets the value of the "y1" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param y1 a double value to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY1AsDouble(GradientBase* gradientBase, const double& y1);

/// @brief Predicates returning @c true if the "y2" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y2" attribute of this GradientBase object is set, @c false if either the "y2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "y2" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "y2" attribute of this GradientBase object is set, @c false if either the "y2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN bool isSetLinearGradientY2(GradientBase* gradientBase);

/// @brief Returns the value of the "y2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "y2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "y2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getLinearGradientY2(GradientBase* gradientBase);

/// @brief Returns the value of the "y2" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y2" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientY2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "y2" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "y2" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getLinearGradientY2AsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "y2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y2 a RelAbsVector to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y2);

/// @brief Sets the value of the "y2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param y2 a RelAbsVector to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY2(GradientBase* gradientBase, const RelAbsVector& y2);

/// @brief Sets the value of the "y2" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y2 a double value to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& y2);

/// @brief Sets the value of the "y2" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param y2 a double value to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setLinearGradientY2AsDouble(GradientBase* gradientBase, const double& y2);
/// @brief Predicates returning @c true if the "cx" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cx" attribute of this GradientBase object is set, @c false if either the "cx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "cx" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "cx" attribute of this GradientBase object is set, @c false if either the "cx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientCx(GradientBase* gradientBase);

/// @brief Returns the value of the "cx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "cx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "cx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientCx(GradientBase* gradientBase);

/// @brief Returns the value of the "cx" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cx" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientCxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "cx" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "cx" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientCxAsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "cx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCx(GradientBase* gradientBase, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cx a double value to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& cx);

/// @brief Sets the value of the "cx" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param cx a double value to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCxAsDouble(GradientBase* gradientBase, const double& cx);

/// @brief Predicates returning @c true if the "cy" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cy" attribute of this GradientBase object is set, @c false if either the "cy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "cy" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "cy" attribute of this GradientBase object is set, @c false if either the "cy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientCy(GradientBase* gradientBase);

/// @brief Returns the value of the "cy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "cy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "cy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientCy(GradientBase* gradientBase);

/// @brief Returns the value of the "cy" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cy" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientCyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "cy" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "cy" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientCyAsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "cy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCy(GradientBase* gradientBase, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cy a double value to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& cy);

/// @brief Sets the value of the "cy" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param cy a double value to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientCyAsDouble(GradientBase* gradientBase, const double& cy);

/// @brief Predicates returning @c true if the "fx" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fx" attribute of this GradientBase object is set, @c false if either the "fx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "fx" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "fx" attribute of this GradientBase object is set, @c false if either the "fx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientFx(GradientBase* gradientBase);

/// @brief Returns the value of the "fx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "fx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "fx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientFx(GradientBase* gradientBase);

/// @brief Returns the value of the "fx" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fx" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientFxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "fx" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "fx" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientFxAsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "fx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fx a RelAbsVector to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fx);

/// @brief Sets the value of the "fx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param fx a RelAbsVector to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFx(GradientBase* gradientBase, const RelAbsVector& fx);

/// @brief Sets the value of the "fx" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fx a double value to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& fx);

/// @brief Sets the value of the "fx" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param fx a double value to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFxAsDouble(GradientBase* gradientBase, const double& fx);

/// @brief Predicates returning @c true if the "fy" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fy" attribute of this GradientBase object is set, @c false if either the "fy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "fy" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "fy" attribute of this GradientBase object is set, @c false if either the "fy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientFy(GradientBase* gradientBase);

/// @brief Returns the value of the "fy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "fy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "fy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientFy(GradientBase* gradientBase);

/// @brief Returns the value of the "fy" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fy" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientFyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "fy" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "fy" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientFyAsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "fy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fy a RelAbsVector to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fy);

/// @brief Sets the value of the "fy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param fy a RelAbsVector to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFy(GradientBase* gradientBase, const RelAbsVector& fy);

/// @brief Sets the value of the "fy" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fy a double value to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& fy);

/// @brief Sets the value of the "fy" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param fy a double value to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientFyAsDouble(GradientBase* gradientBase, const double& fy);

/// @brief Predicates returning @c true if the "r" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "r" attribute of this GradientBase object is set, @c false if either the "r" attribute is not set
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "r" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "r" attribute of this GradientBase object is set, @c false if either the "r" attribute is not set
LIBSBMLNETWORK_EXTERN bool isSetRadialGradientR(GradientBase* gradientBase);

/// @brief Returns the value of the "r" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "r" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "r" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "r" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBMLNETWORK_EXTERN const RelAbsVector getRadialGradientR(GradientBase* gradientBase);

/// @brief Returns the value of the "r" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "r" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientRAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "r" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "r" attribute of the GradientBase object as a double, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getRadialGradientRAsDouble(GradientBase* gradientBase);

/// @brief Sets the value of the "r" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param r a RelAbsVector to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& r);

/// @brief Sets the value of the "r" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param r a RelAbsVector to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientR(GradientBase* gradientBase, const RelAbsVector& r);

/// @brief Sets the value of the "r" attribute of the GradientBase with the given identifier as a double.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param r a double value to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientRAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& r);

/// @brief Sets the value of the "r" attribute of this GradientBase as a double.
/// @param gradientBase a pointer to the GradientBase object.
/// @param r a double value to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRadialGradientRAsDouble(GradientBase* gradientBase, const double& r);

/// @brief Returns the number of LineEndings of this RenderInformationBase object.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @return the number of LineEndings of this RenderInformationBase object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const unsigned int getNumLineEndings(RenderInformationBase* renderInformationBase);

/// @brief Returns a LineEnding from the RenderInformationBase based on its identifier.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the @c LineEnding in the ListOfLineEndings within this RenderInformationBase with the given sid or @c NULL if no such LineEnding exists.
LIBSBMLNETWORK_EXTERN LineEnding* getLineEnding(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns a pointer to the LineEnding of this RenderInformationBase object with the given index.
/// @param lineEndingIndex the index value of the LineEnding to return.
/// @return the @c LineEnding with the given index, or NULL if LineEnding does not exist or the object is @c NULL
LIBSBMLNETWORK_EXTERN LineEnding* getLineEnding(RenderInformationBase* renderInformationBase, unsigned int lineEndingIndex);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of the LineEnding with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of this LineEnding is set.
/// @param lineEnding a pointer to the LineEnding object.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetEnableRotationalMapping(LineEnding* lineEnding);

/// @brief Returns the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
LIBSBMLNETWORK_EXTERN bool getEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "enableRotationalMapping" attribute of this LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
LIBSBMLNETWORK_EXTERN bool getEnableRotationalMapping(LineEnding* lineEnding);

/// @brief Sets the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid, bool enableRotationalMapping);

/// @brief Sets the value of the "enableRotationalMapping" attribute of this LineEnding .
/// @param lineEnding a pointer to the LineEnding object.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setEnableRotationalMapping(LineEnding* lineEnding, bool enableRotationalMapping);

/// Returns the bounding box for the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the bounding box for the LineEnding object, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN BoundingBox* getLineEndingBoundingBox(RenderInformationBase* renderInformationBase, const std::string& sid);

/// Returns the bounding box for the LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the bounding box for the LineEnding object, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN BoundingBox* getLineEndingBoundingBox(LineEnding* lineEnding);

/// Returns the value of the "group" element of the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the value of the "group" element of this LineEnding as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN RenderGroup* getLineEndingRenderGroup(RenderInformationBase* renderInformationBase, const std::string& sid);

/// Returns the value of the "group" element of this LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the value of the "group" element of this LineEnding as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN RenderGroup* getRenderGroup(LineEnding* lineEnding);

/// @brief Searches among the styles of the render information base and returns one that matches this GraphicalObject attributes
/// @param renderInformationBase  a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one that matches this attribute (id, role, type) of a GraphicalObject
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyle(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Searches among the styles of the render information base and returns one that matches with the TextGlyph associated whit this GraphicalObject
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getTextGlyphStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "id" in its idlist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyleById(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "id" in its idlist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param id the id attribute of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyleById(RenderInformationBase* renderInformationBase, const std::string& id);

/// @brief Searches among the styles of the render information base and returns one contains the "role" in its rolelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyleByRole(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "role" in its rolelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param role the role attribute of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyleByRole(RenderInformationBase* renderInformationBase, const std::string& role);

/// @brief Searches among the styles of the render information base and returns one contains the "type" in its typelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyleByType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "type" in its typelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param type the type attribute of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN Style* getStyleByType(RenderInformationBase* renderInformationBase, const std::string& type);

/// Returns the value of the "group" element of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the value of the "group" element of the Style for this GraphicalObjet as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN RenderGroup* getRenderGroup(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// Returns the value of the "group" element of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBMLNETWORK_EXTERN RenderGroup* getRenderGroup(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// Returns the value of the "group" element of this Style.
/// @param style a pointer to the Style object.
/// @return the value of the "group" element of this Style as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN RenderGroup* getRenderGroup(Style* style);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type GraphicalPrimitive1D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type GraphicalPrimitive1D, @c false if either it is not of type GraphicalPrimitive1D or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const bool isGraphicalPrimitive1D(Transformation2D* Transformation2D);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type GraphicalPrimitive2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type GraphicalPrimitive2D, @c false if either it is not of type GraphicalPrimitive2D or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const bool isGraphicalPrimitive2D(Transformation2D* Transformation2D);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type RenderGroup.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type RenderGroup, @c false if either it is not of type RenderGroup or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const bool isRenderGroup(Transformation2D* Transformation2D);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeColor(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetStrokeColor(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "stroke" attribute of this Transformation2D is set.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if the "stroke" attribute of this Transformation2D object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeColor(Transformation2D* transformation2D);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStrokeColor(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getStrokeColor(RenderGroup* renderGroup);

/// @brief Returns the value of the "stroke" attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the "stroke" attribute of the Transformation2D object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStrokeColor(Transformation2D* transformation2D);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeColorId a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param strokeColorValue a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& strokeColorId, const std::string& strokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeColorId a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param strokeColorValue a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& strokeColorId, const std::string& strokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeColorId a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param strokeColorValue a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeColor(Style* style, const std::string& strokeColorId, const std::string& strokeColorValue);

LIBSBMLNETWORK_EXTERN int setStrokeColor(RenderGroup* renderGroup, const std::string& strokeColorId, const std::string& strokeColorValue);

LIBSBMLNETWORK_EXTERN int setStrokeColor(Transformation2D* transformation2D, const std::string& strokeColorId, const std::string& strokeColorValue);

LIBSBMLNETWORK_EXTERN const std::string getCompartmentStrokeColor(GlobalRenderInformation* globalRenderInformation);

LIBSBMLNETWORK_EXTERN int setCompartmentStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN const std::string getSpeciesStrokeColor(GlobalRenderInformation* globalRenderInformation);

LIBSBMLNETWORK_EXTERN int setSpeciesStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN const std::string getReactionStrokeColor(GlobalRenderInformation* globalRenderInformation);

LIBSBMLNETWORK_EXTERN int setReactionStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& strokeColor);

LIBSBMLNETWORK_EXTERN int setSpeciesReferenceStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& strokeColor);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke-width" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeWidth(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetStrokeWidth(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "stroke-width" attribute of this Transformation2D is set.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if the "stroke-width" attribute of this Transformation2D object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeWidth(Transformation2D* transformation2D);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke-width" attribute of the RenderGroup of this Style object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getStrokeWidth(Style* style);

LIBSBMLNETWORK_EXTERN const double getStrokeWidth(RenderGroup* renderGroup);

/// @brief Returns the value of the "stroke-width" attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the "stroke-width" attribute of the Transformation2D object, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getStrokeWidth(Transformation2D* transformation2D);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeWidth(Style* style, const double& strokeWidth);

LIBSBMLNETWORK_EXTERN int setStrokeWidth(RenderGroup* renderGroup, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of this Transformation2D object.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeWidth(Transformation2D* transformation2D, const double& strokeWidth);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentStrokeWidth(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL.
const double getSpeciesStrokeWidth(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL.
const double getReactionStrokeWidth(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style for all SpeciesReferenceGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of the Style for all SpeciesReferenceGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesReferenceStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke-dasharray" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeDashArray(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetStrokeDashArray(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of this Transformation2D is set.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if the "stroke-dasharray" attribute of this Transformation2D object is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStrokeDashArray(Transformation2D* transformation2D);

/// @brief Returns the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or an empty vector if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::vector<unsigned int> getStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject, or an empty vector if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::vector<unsigned int> getStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke-dasharray" attribute of the RenderGroup of this Style object, or an empty vector if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::vector<unsigned int> getStrokeDashArray(Style* style);

LIBSBMLNETWORK_EXTERN const std::vector<unsigned int> getStrokeDashArray(RenderGroup* renderGroup);

/// @brief Returns the vector of the "stroke-dasharray" attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the "stroke-dasharray" attribute of the Transformation2D object, or an empty vector if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::vector<unsigned int> getStrokeDashArray(Transformation2D* transformation2D);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDashArray(Style* style, const std::vector<unsigned int>& strokeDashArray);

LIBSBMLNETWORK_EXTERN int setStrokeDashArray(RenderGroup* renderGroup, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" of this GraphicalPrimitive1D object.
/// @param shape a pointer to the Transformation2D object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDashArray(Transformation2D* transformation2D, const std::vector<unsigned int>& strokeDashArray);

/// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumStrokeDashes(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumStrokeDashes(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the size of the "stroke-dasharray" attribute of the RenderGroup of this Style object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumStrokeDashes(Style* style);

LIBSBMLNETWORK_EXTERN unsigned int getNumStrokeDashes(RenderGroup* renderGroup);

/// @brief Returns the size of the "stroke-dasharray" attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the size of "stroke-dasharray" attribute of the Transformation2D object, or 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumStrokeDashes(Transformation2D* transformation2D);

/// @brief Returns the stroke dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeDashIndex an unsigned int representing the index of the stroke dash to retrieve.
/// @return the stroke dash at the given index of "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int strokeDashIndex = 0);

/// @brief Returns the stroke dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeDashIndex an unsigned int representing the index of the stroke dash to retrieve.
/// @return the stroke dash at the given index of "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int strokeDashIndex = 0);

/// @brief Returns the stroke dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeDashIndex an unsigned int representing the index of the dash to retrieve.
/// @return the stroke dash at the given index of "stroke-dasharray" attribute of the RenderGroup of this Style object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getStrokeDash(Style* style, unsigned int strokeDashIndex = 0);

LIBSBMLNETWORK_EXTERN unsigned int getStrokeDash(RenderGroup* renderGroup, unsigned int strokeDashIndex = 0);

/// @brief Returns the stroke dash at the given index of the 'stroke-dasharray' attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param strokeDashIndex an unsigned int representing the index of the dash to retrieve.
/// @return the stroke dash at the given index of "stroke-dasharray" attribute of the Transformation2D object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getStrokeDash(Transformation2D* transformation2D, unsigned int strokeDashIndex = 0);

/// @brief Sets the first dash of the 'stroke-dasharray' attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param dash a unsigned int value to use as the first dash of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int dash);

/// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeDashIndex an unsigned int representing the index of the stroke dash to retrieve.
/// @param dash a unsigned int value to use as the dash at the given index of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int strokeDashIndex, unsigned int dash);

/// @brief Sets the first dash of the 'stroke-dasharray' attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param dash a unsigned int value to use as the first dash of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int dash);

/// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeDashIndex an unsigned int representing the index of the stroke dash to retrieve.
/// @param dash a unsigned int value to use as the dash at the given index of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int strokeDashIndex, unsigned int dash);

/// @brief Sets the first dash of the 'stroke-dasharray' attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeDashIndex an unsigned int representing the index of the dash to retrieve.
/// @param dash a unsigned int value to use as the first dash of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(Style* style, unsigned int dash);

/// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeDashIndex an unsigned int representing the index of the dash to retrieve.
/// @param dash a unsigned int value to use as the dash at the given index of the 'stroke-dasharray' attribute of of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(Style* style, unsigned int strokeDashIndex, unsigned int dash);

LIBSBMLNETWORK_EXTERN int setStrokeDash(RenderGroup* renderGroup, unsigned int dash);

/// @brief Sets the first dash of the 'stroke-dasharray' attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param dash a unsigned int value to use as the fist dash of the 'stroke-dasharray' attribute of this Transformation2D.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(Transformation2D* transformation2D, unsigned int dash);

/// @brief Sets the dash at the given index of the 'stroke-dasharray' attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param strokeDashIndex an unsigned int representing the index of the dash to set.
/// @param dash a unsigned int value to use as the dash at the given index of the 'stroke-dasharray' attribute of this Transformation2D.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStrokeDash(Transformation2D* transformation2D, unsigned int strokeDashIndex, unsigned int dash);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeDashArray a vector to use as the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentStrokeDash(GlobalRenderInformation* globalRenderInformation, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeDashArray a vector to use as the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesStrokeDash(GlobalRenderInformation* globalRenderInformation, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param strokeDashArray a vector to use as the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionStrokeDash(GlobalRenderInformation* globalRenderInformation, const std::vector<unsigned int>& strokeDashArray);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontColor(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFontColor(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "stroke" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "stroke" attribute of this Transformation2D (Text or RenderGroup) object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontColor(Transformation2D* transformation2D);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontColor(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getFontColor(RenderGroup* renderGroup);

/// @brief Returns the value of the "stroke" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "stroke" attribute of the Transformation2D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontColor(Transformation2D* transformation2D);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fontColorId a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param fontColorValue a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& fontColorId, const std::string& fontColorValue);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fontColorId a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param fontColorValue a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& fontColorId, const std::string& fontColorValue);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fontColorId a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param fontColorValue a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontColor(Style* style, const std::string& fontColorId, const std::string& fontColorValue);

LIBSBMLNETWORK_EXTERN int setFontColor(RenderGroup* renderGroup, const std::string& fontColorId, const std::string& fontColorValue);

/// @brief Sets the value of the "stroke" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param fontColorId a string value to use as the value of the "stroke" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param fontColorValue a string value to use as the value of the "stroke" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontColor(Transformation2D* transformation2D, const std::string& fontColorId, const std::string& fontColorValue);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "stroke" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentFontColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFontColor(GlobalRenderInformation* globalRenderInformation, const std::string& fontColor);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "stroke" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesFontColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFontColor(GlobalRenderInformation* globalRenderInformation, const std::string& fontColor);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "stroke" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionFontColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontColor a string value to use as the value of the "stroke" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFontColor(GlobalRenderInformation* globalRenderInformation, const std::string& fontColor);

/// @brief Predicates returning @c true if the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-family"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontFamily(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "font-family" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-family"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontFamily(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "font-family" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "font-family" attribute of the RenderGroup of this Style object is set, @c false if either the "font-family"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontFamily(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFontFamily(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "font-family" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "font-family" attribute of this Transformation2D (Text or RenderGroup) object is set, @c false if either the "font-family"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontFamily(Transformation2D* transformation2D);

/// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontFamily(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontFamily(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "font-family" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "font-family" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontFamily(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getFontFamily(RenderGroup* renderGroup);

/// @brief Returns the value of the "font-family" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "font-family" attribute of the Transformation2D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontFamily(Transformation2D* transformation2D);

/// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontFamily(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontFamily);

/// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontFamily(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontFamily);

/// @brief Sets the value of the "font-family" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontFamily(Style* style, const std::string& fontFamily);

LIBSBMLNETWORK_EXTERN int setFontFamily(RenderGroup* renderGroup, const std::string& fontFamily);

/// @brief Sets the value of the "font-family" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontFamily(Transformation2D* transformation2D, const std::string& fontFamily);

/// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-family" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentFontFamily(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFontFamily(GlobalRenderInformation* globalRenderInformation, const std::string& fontFamily);

/// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-family" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesFontFamily(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFontFamily(GlobalRenderInformation* globalRenderInformation, const std::string& fontFamily);

/// @brief Returns the value of the "font-family" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-family" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionFontFamily(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-family" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFontFamily(GlobalRenderInformation* globalRenderInformation, const std::string& fontFamily);

/// @brief Predicates returning @c true if the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-size"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontSize(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "font-size" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-size"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontSize(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "font-size" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "font-size" attribute of the RenderGroup of this Style object is set, @c false if either the "font-size"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontSize(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFontSize(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "font-size" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "font-size" attribute of this Transformation2D (Text or RenderGroup) object is set, @c false if either the "font-size"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontSize(Transformation2D* transformation2D);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getFontSize(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getFontSize(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "font-size" attribute of the RenderGroup of this Style object, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getFontSize(Style* style);

LIBSBMLNETWORK_EXTERN const RelAbsVector getFontSize(RenderGroup* renderGroup);

/// @brief Returns the value of the "font-size" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "font-size" attribute of the Transformation2D (Text or RenderGroup) object, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getFontSize(Transformation2D* transformation2D);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fontSize a RelAbsVector value to use as the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSize(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& fontSize);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fontSize a RelAbsVector to use as the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSize(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& fontSize);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fontSize a RelAbsVector to use as the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSize(Style* style, const RelAbsVector& fontSize);

LIBSBMLNETWORK_EXTERN int setFontSize(RenderGroup* renderGroup, const RelAbsVector& fontSize);

/// @brief Sets the value of the "font-size" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param fontSize a RelAbsVector to use as the value of the "font-size" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSize(Transformation2D* transformation2D, const RelAbsVector& fontSize);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSizeAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& fontSize);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSizeAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& fontSize);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSizeAsDouble(Style* style, const double& fontSize);

LIBSBMLNETWORK_EXTERN int setFontSizeAsDouble(RenderGroup* renderGroup, const double& fontSize);

/// @brief Sets the value of the "font-size" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param fontSize a double value to use as the value of the "font-size" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontSizeAsDouble(Transformation2D* transformation2D, const double& fontSize);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentFontSize(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontSize a RelAbsVector value to use as the value of the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFontSize(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& fontSize);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getCompartmentFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation, const double& fontSize);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesFontSize(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontSize a RelAbsVector value to use as the value of the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFontSize(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& fontSize);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getSpeciesFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation, const double& fontSize);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionFontSize(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontSize a RelAbsVector value to use as the value of the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFontSize(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& fontSize);

/// @brief Returns the value of the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c 0.0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN const double getReactionFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontSize a double value to use as the value of the "font-size" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation, const double& fontSize);

/// @brief Predicates returning @c true if the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-weight"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontWeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "font-weight" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-weight"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontWeight(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "font-weight" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "font-weight" attribute of the RenderGroup of this Style object is set, @c false if either the "font-weight"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontWeight(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFontWeight(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "font-weight" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "font-weight" attribute of this Transformation2D (Text or RenderGroup) object is set, @c false if either the "font-weight"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontWeight(Transformation2D* transformation2D);

/// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontWeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontWeight(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "font-weight" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "font-weight" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontWeight(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getFontWeight(RenderGroup* renderGroup);

/// @brief Returns the value of the "font-weight" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "font-weight" attribute of the Transformation2D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontWeight(Transformation2D* transformation2D);

/// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontWeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontWeight);

/// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontWeight(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontWeight);

/// @brief Sets the value of the "font-weight" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontWeight(Style* style, const std::string& fontWeight);

LIBSBMLNETWORK_EXTERN int setFontWeight(RenderGroup* renderGroup, const std::string& fontWeight);

/// @brief Sets the value of the "font-weight" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontWeight(Transformation2D* transformation2D, const std::string& fontWeight);

/// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-weight" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentFontWeight(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFontWeight(GlobalRenderInformation* globalRenderInformation, const std::string& fontWeight);

/// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-weight" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesFontWeight(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFontWeight(GlobalRenderInformation* globalRenderInformation, const std::string& fontWeight);

/// @brief Returns the value of the "font-weight" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-weight" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionFontWeight(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-weight" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFontWeight(GlobalRenderInformation* globalRenderInformation, const std::string& fontWeight);

/// @brief Predicates returning @c true if the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-style"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "font-style" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "font-style"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontStyle(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "font-style" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "font-style" attribute of the RenderGroup of this Style object is set, @c false if either the "font-style"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontStyle(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFontStyle(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "font-style" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-style"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFontStyle(Transformation2D* transformation2D);

/// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontStyle(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "font-style" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "font-style" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontStyle(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getFontStyle(RenderGroup* renderGroup);

/// @brief Returns the value of the "font-style" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "font-style" attribute of the Transformation2D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFontStyle(Transformation2D* transformation2D);

/// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontStyle);

/// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontStyle(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontStyle);

/// @brief Sets the value of the "font-style" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontStyle(Style* style, const std::string& fontStyle);

LIBSBMLNETWORK_EXTERN int setFontStyle(RenderGroup* renderGroup, const std::string& fontStyle);

/// @brief Sets the value of the "font-style" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "font-style" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFontStyle(Transformation2D* transformation2D, const std::string& fontStyle);

/// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-style" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentFontStyle(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFontStyle(GlobalRenderInformation* globalRenderInformation, const std::string& fontStyle);

/// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-style" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesFontStyle(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFontStyle(GlobalRenderInformation* globalRenderInformation, const std::string& fontStyle);

/// @brief Returns the value of the "font-style" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "font-style" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionFontStyle(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "font-style" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fontStyle a string value to use as the value of the "font-style" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFontStyle(GlobalRenderInformation* globalRenderInformation, const std::string& fontStyle);

/// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "text-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "text-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "text-anchor" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "text-anchor" attribute of the RenderGroup of this Style object is set, @c false if either the "text-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetTextAnchor(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetTextAnchor(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "text-anchor" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "text-anchor" attribute of this Transformation2D (Text or RenderGroup) object is set, @c false if either the "text-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetTextAnchor(Transformation2D* transformation2D);

/// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "text-anchor" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getTextAnchor(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getTextAnchor(RenderGroup* renderGroup);

/// @brief Returns the value of the "text-anchor" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "text-anchor" attribute of the Transformation2D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getTextAnchor(Transformation2D* transformation2D);

/// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& textAnchor);

/// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& textAnchor);

/// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setTextAnchor(Style* style, const std::string& textAnchor);

LIBSBMLNETWORK_EXTERN int setTextAnchor(RenderGroup* renderGroup, const std::string& textAnchor);

/// @brief Sets the value of the "text-anchor" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setTextAnchor(Transformation2D* transformation2D, const std::string& textAnchor);

/// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "text-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentTextAnchor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& textAnchor);

/// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "text-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesTextAnchor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& textAnchor);

/// @brief Returns the value of the "text-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "text-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionTextAnchor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "text-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param textAnchor a string value to use as the value of the "text-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& textAnchor);

/// @brief Predicates returning @c true if the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "vtext-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetVTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "vtext-anchor" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "vtext-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetVTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "vtext-anchor" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "vtext-anchor" attribute of the RenderGroup of this Style object is set, @c false if either the "vtext-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetVTextAnchor(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetVTextAnchor(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "vtext-anchor" attribute of this Transformation2D (Text or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return @c true if the "vtext-anchor" attribute of this Transformation2D (Text or RenderGroup) object is set, @c false if either the "vtext-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetVTextAnchor(Transformation2D* transformation2D);

/// @brief Returns the value of the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getVTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "vtext-anchor" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getVTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "vtext-anchor" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "vtext-anchor" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getVTextAnchor(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getVTextAnchor(RenderGroup* renderGroup);

/// @brief Returns the value of the "vtext-anchor" attribute of this Transformation2D (Text or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @return the "vtext-anchor" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getVTextAnchor(Transformation2D* transformation2D);

/// @brief Sets the value of the "vtext-anchor" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setVTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& vtextAnchor);

/// @brief Sets the value of the "vtext-anchor" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setVTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& vtextAnchor);

/// @brief Sets the value of the "vtext-anchor" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setVTextAnchor(Style* style, const std::string& vtextAnchor);

LIBSBMLNETWORK_EXTERN int setVTextAnchor(RenderGroup* renderGroup, const std::string& vtextAnchor);

/// @brief Sets the value of the "vtext-anchor" attribute of this Transformation2D (Text or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D (Text or RenderGroup) object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of this Transformation2D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setVTextAnchor(Transformation2D* transformation2D, const std::string& vtextAnchor);

/// @brief Returns the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "vtext-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentVTextAnchor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentVTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& vtextAnchor);

/// @brief Returns the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "vtext-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesVTextAnchor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesVTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& vtextAnchor);

/// @brief Returns the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "vtext-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionVTextAnchor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionVTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& vtextAnchor);

/// @brief Predicates returning @c true if the "fill" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "fill" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "fill" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "fill" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "fill" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "fill" attribute of the RenderGroup of this Style object is set, @c false if either the "fill"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillColor(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFillColor(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "fill" attribute of this Transformation2D is set.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if the "fill" attribute of this Transformation2D object is set, @c false if either the "fill"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillColor(Transformation2D* transformation2D);

/// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "fill" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "fill" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "fill" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "fill" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillColor(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getFillColor(RenderGroup* renderGroup);

/// @brief Returns the value of the "fill" attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the "fill" attribute of the Transformation2D object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillColor(Transformation2D* transformation2D);

/// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the RenderGroup of this Style object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the RenderGroup of this Style object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the RenderGroup of this Style object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillColor(Style* style, const std::string& fillColorId, const std::string& fillColorValue);

LIBSBMLNETWORK_EXTERN int setFillColor(RenderGroup* renderGroup, const std::string& fillColorId, const std::string& fillColorValue);

LIBSBMLNETWORK_EXTERN int setFillColor(Transformation2D* transformation2D, const std::string& fillColorId, const std::string& fillColorValue);

LIBSBMLNETWORK_EXTERN int setFillColorAsGradient(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setFillColorAsGradient(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setFillColorAsGradient(Style* style, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setFillColorAsGradient(RenderGroup* renderGroup, const std::string& gradientId);

LIBSBMLNETWORK_EXTERN int setFillColorAsGradient(Transformation2D* transformation2D, const std::string& gradientId);

/// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "fill" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentFillColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFillColor(GlobalRenderInformation* globalRenderInformation, const std::string& fillColor);

LIBSBMLNETWORK_EXTERN int setCompartmentFillColorAsGradient(GlobalRenderInformation* globalRenderInformation, const std::string& gradientId);

/// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "fill" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesFillColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFillColor(GlobalRenderInformation* globalRenderInformation, const std::string& fillColor);

LIBSBMLNETWORK_EXTERN int setSpeciesFillColorAsGradient(GlobalRenderInformation* globalRenderInformation, const std::string& gradientId);

/// @brief Returns the value of the "fill" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "fill" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionFillColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "fill" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fillColor a string value to use as the value of the "fill" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFillColor(GlobalRenderInformation* globalRenderInformation, const std::string& fillColor);

LIBSBMLNETWORK_EXTERN int setReactionFillColorAsGradient(GlobalRenderInformation* globalRenderInformation, const std::string& gradientId);

/// @brief Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill-rule"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillRule(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "fill-rule"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillRule(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "fill-rule" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "fill-rule" attribute of the RenderGroup of this Style object is set, @c false if either the "fill-rule"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillRule(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetFillRule(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "fill-rule" attribute of this Transformation2D is set.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return @c true if the "fill-rule" attribute of this Transformation2D object is set, @c false if either the "fill-rule"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetFillRule(Transformation2D* transformation2D);

/// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillRule(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillRule(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "fill-rule" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillRule(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getFillRule(RenderGroup* renderGroup);

/// @brief Returns the value of the "fill-rule" attribute of this Transformation2D.
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the "fill-rule" attribute of the Transformation2D object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getFillRule(Transformation2D* transformation2D);

/// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillRule(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fillRule);

/// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillRule(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fillRule);

/// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillRule(Style* style, const std::string& fillRule);

LIBSBMLNETWORK_EXTERN int setFillRule(RenderGroup* renderGroup, const std::string& fillRule);

/// @brief Sets the value of the "fill-rule" attribute of this Transformation2D object.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setFillRule(Transformation2D* transformation2D, const std::string& fillRule);

/// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "fill-rule" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentFillRule(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentFillRule(GlobalRenderInformation* globalRenderInformation, const std::string& fillRule);

/// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "fill-rule" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesFillRule(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesFillRule(GlobalRenderInformation* globalRenderInformation, const std::string& fillRule);

/// @brief Returns the value of the "fill-rule" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "fill-rule" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionFillRule(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "fill-rule" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param fillRule a string value to use as the value of the "fill-rule" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionFillRule(GlobalRenderInformation* globalRenderInformation, const std::string& fillRule);

/// @brief Predicates returning @c true if the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "startHead"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStartHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "startHead" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "startHead"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStartHead(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "startHead" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "startHead" attribute of the RenderGroup of this Style object is set, @c false if either the "startHead"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStartHead(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetStartHead(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "startHead" attribute of this Transformation2D (RenderCurve or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (RenderCurve or RenderGroup) object.
/// @return @c true if the "startHead" attribute of this Transformation2D (RenderCurve or RenderGroup) object is set, @c false if either the "startHead" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetStartHead(Transformation2D* transformation2D);

/// @brief Returns the value of the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStartHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "startHead" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStartHead(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "startHead" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "startHead" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStartHead(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getStartHead(RenderGroup* renderGroup);

/// @brief Returns the value of the "startHead" attribute of this Transformation2D (RenderCurve or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D (RenderCurve or RenderGroup) object.
/// @return the "startHead" attribute of the Transformation2D (RenderCurve or RenderGroup) object, or empty string if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getStartHead(Transformation2D* transformation2D);

/// @brief Sets the value of the "startHead" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param startHead a string value to use as the value of the "startHead" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStartHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& startHead);

/// @brief Sets the value of the "startHead" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param startHead a string value to use as the value of the "startHead" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStartHead(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& startHead);

/// @brief Sets the value of the "startHead" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param startHead a string value to use as the value of the "startHead" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStartHead(Style* style, const std::string& startHead);

LIBSBMLNETWORK_EXTERN int setStartHead(RenderGroup* renderGroup, const std::string& startHead);

/// @brief Sets the value of the "startHead" attribute of this Transformation2D (RenderCurve or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param startHead a boolean to use as the value of the "startHead" attribute of this Transformation2D (RenderCurve or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStartHead(Transformation2D* transformation2D, const std::string startHead);

/// @brief Predicates returning @c true if the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "endHead"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetEndHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "endHead" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "endHead"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetEndHead(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "endHead" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "endHead" attribute of the RenderGroup of this Style object is set, @c false if either the "endHead"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetEndHead(Style* style);

LIBSBMLNETWORK_EXTERN bool isSetEndHead(RenderGroup* renderGroup);

/// @brief Predicates returning @c true if the "endHead" attribute of this Transformation2D (RenderCurve or RenderGroup) is set.
/// @param transformation2D a pointer to the Transformation2D (RenderCurve or RenderGroup) object.
/// @return @c true if the "endHead" attribute of this Transformation2D (RenderCurve or RenderGroup) object is set, @c false if either the "endHead" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetEndHead(Transformation2D* transformation2D);

/// @brief Returns the value of the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getEndHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "endHead" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getEndHead(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "endHead" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "endHead" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getEndHead(Style* style);

LIBSBMLNETWORK_EXTERN const std::string getEndHead(RenderGroup* renderGroup);

/// @brief Returns the value of the "endHead" attribute of this Transformation2D (RenderCurve or RenderGroup).
/// @param transformation2D a pointer to the Transformation2D object.
/// @return the "endHead" attribute of the Transformation2D (RenderCurve or RenderGroup) object, or empty string if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getEndHead(Transformation2D* transformation2D);

/// @brief Sets the value of the "endHead" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param endHead a string value to use as the value of the "endHead" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setEndHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& endHead);

/// @brief Sets the value of the "endHead" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param endHead a string value to use as the value of the "startHead" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setEndHead(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& endHead);

/// @brief Sets the value of the "endHead" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param endHead a string value to use as the value of the "endHead" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setEndHead(Style* style, const std::string& endHead);

LIBSBMLNETWORK_EXTERN int setEndHead(RenderGroup* renderGroup, const std::string& endHead);

/// @brief Sets the value of the "endHead" attribute of this Transformation2D (RenderCurve or RenderGroup) object.
/// @param transformation2D a pointer to the Transformation2D object.
/// @param endHead a boolean to use as the value of the "endHead" attribute of this Transformation2D (RenderCurve or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setEndHead(Transformation2D* transformation2D, const std::string endHead);

/// @brief Returns number of Transformation2D objects in the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the number of Transformation2D objects in the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumGeometricShapes(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns number of Transformation2D objects in the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the number of Transformation2D objects in the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumGeometricShapes(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns number of Transformation2D objects in the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the number of Transformation2D objects in the RenderGroup of this Style object, or @c 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumGeometricShapes(Style* style);

/// @brief Returns Get the number of Transformation2D objects in this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the number of Transformation2D objects in this RenderGroup, or 0 if the object is @c NULL
LIBSBMLNETWORK_EXTERN unsigned int getNumGeometricShapes(RenderGroup* renderGroup);

/// @brief Returns the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the Transformation2D at the given index the RenderGroup of the Style for this GraphicalObject object, @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN Transformation2D* getGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN Transformation2D* getGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the Transformation2D at the given index of the RenderGroup of this Style object, or @c NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN Transformation2D* getGeometricShape(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the Transformation2D at the given index of the this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the Transformation2D at the given index of the RenderGroup object, or NULL if the object is @c NULL
LIBSBMLNETWORK_EXTERN Transformation2D* getGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Add a geometric shape to the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& shape);

/// @brief Add a geometric shape to the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param shape a string value indicating the shape of the geometric shape to be added.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& shape);

/// @brief Add a geometric shape to the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param shape a string value indicating the shape of the geometric shape to be added.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addGeometricShape(Style* style, const std::string& shape);

/// @brief Add a geometric shape to this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param shape a string value indicating the shape of the geometric shape to be added.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addGeometricShape(RenderGroup* renderGroup, const std::string& shape);

/// @brief Remove a geometric shape from the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Remove a geometric shape from the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Remove a geometric shape from the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeGeometricShape(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Remove a geometric shape from this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to remove.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int removeGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Sets the geometric shape as the single geometric shape of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& shape);

LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeId(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeId(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeId(Style* style, unsigned int geometricShapeIndex = 0);

LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeId(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeId(Transformation2D* shape);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(Style* style, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(Style* style, unsigned int geometricShapeIndex, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(RenderGroup* renderGroup, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& id);

LIBSBMLNETWORK_EXTERN int setGeometricShapeId(Transformation2D* shape, const std::string& id);

/// @brief Returns the geometric shape as a string based on the RenderInformationBase and GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an optional unsigned int representing the index of the Transformation2D to retrieve.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the geometric shape as a string based on the RenderInformationBase and a specific attribute.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an optional unsigned int representing the index of the Transformation2D to retrieve.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeType(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the geometric shape as a string for a specific Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an optional unsigned int representing the index of the Transformation2D to retrieve.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeType(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the geometric shape as a string for a specific RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an optional unsigned int representing the index of the Transformation2D to retrieve.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeType(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the geometric shape as a string for a specific Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeType(Transformation2D* shape);

/// @brief Sets the geometric shape for a GraphicalObject based on RenderInformationBase.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& shape);

/// @brief Sets the geometric shape for a GraphicalObject based on its attribute.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeType(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& shape);

/// @brief Sets the geometric shape for a specific Style.
/// @param style a pointer to the Style object.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int setGeometricShapeType(Style* style, const std::string& shape);

/// @brief Sets the geometric shape for a specific RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeType(RenderGroup* renderGroup, const std::string& shape);

/// @brief Returns the geometric shape as a string for a specific CompartmentGlyph.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentGeometricShapeType(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the geometric shape for a specific CompartmentGlyph.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeType(GlobalRenderInformation* globalRenderInformation, const std::string& shape);

/// @brief Returns the geometric shape as a string for a specific SpeciesGlyph.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesGeometricShapeType(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the geometric shape for a specific SpeciesGlyph.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeType(GlobalRenderInformation* globalRenderInformation, const std::string& shape);

/// @brief Returns the geometric shape as a string for a specific ReactionGlyph.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return A string representing the geometric shape, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionGeometricShapeType(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the geometric shape for a specific ReactionGlyph.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param shape a string value indicating the shape of the geometric shape to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeType(GlobalRenderInformation* globalRenderInformation, const std::string& shape);

/// @brief Checks if the Transformation2D at the given index of the RenderGroup of the Style for a GraphicalObject is of type Rectangle.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Rectangle, @c false if
/// it is not of type Rectangle or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRectangle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Rectangle.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Rectangle, @c false if
/// it is not of type Rectangle or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRectangle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Rectangle.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Rectangle, @c false if
/// it is not of type Rectangle or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRectangle(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Rectangle.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Rectangle, @c false if
/// it is not of type Rectangle or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRectangle(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Rectangle.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Rectangle, @c false if either it is not of type Rectangle or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRectangle(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Square.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Square, @c false if
/// it is not of type Square or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSquare(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Square.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Square, @c false if
/// it is not of type Square or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSquare(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Square.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Square, @c false if
/// it is not of type Square or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSquare(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Square.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Square, @c false if
/// it is not of type Square or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSquare(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Square.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Square, @c false if either it is not of type Square or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSquare(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Ellipse.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Ellipse, @c false if
/// it is not of type Ellipse or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isEllipse(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Ellipse.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Ellipse, @c false if
/// it is not of type Ellipse or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isEllipse(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Ellipse.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Ellipse, @c false if
/// it is not of type Ellipse or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isEllipse(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Ellipse.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Ellipse, @c false if
/// it is not of type Ellipse or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isEllipse(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Ellipse.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Ellipse, @c false if either it is not of type Ellipse or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isEllipse(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Circle.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Circle, @c false if
/// it is not of type Circle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isCircle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Circle.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Circle, @c false if
/// it is not of type Circle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isCircle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Circle.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Circle, @c false if
/// it is not of type Circle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isCircle(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Circle.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Circle, @c false if
/// it is not of type Circle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isCircle(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Circle.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Circle, @c false if either it is not of type Circle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isCircle(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Polygon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Polygon, @c false if
/// it is not of type Polygon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPolygon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Polygon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Polygon, @c false if
/// it is not of type Polygon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPolygon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Polygon.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Polygon, @c false if
/// it is not of type Polygon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPolygon(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Polygon.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Polygon, @c false if
/// it is not of type Polygon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPolygon(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Polygon.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Polygon, @c false if either it is not of type Polygon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPolygon(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Triangle.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Triangle, @c false if
/// it is not of type Triangle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isTriangle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Triangle.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Triangle, @c false if
/// it is not of type Triangle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isTriangle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Triangle.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Triangle, @c false if
/// it is not of type Triangle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isTriangle(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Triangle.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Triangle, @c false if
/// it is not of type Triangle or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isTriangle(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Triangle.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Triangle, @c false if either it is not of type Triangle or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isTriangle(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Diamond.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Diamond, @c false if
/// it is not of type Diamond or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isDiamond(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Diamond.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Diamond, @c false if
/// it is not of type Diamond or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isDiamond(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Diamond.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Diamond, @c false if
/// it is not of type Diamond or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isDiamond(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Diamond.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Diamond, @c false if
/// it is not of type Diamond or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isDiamond(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Diamond.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Diamond, @c false if either it is not of type Diamond or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isDiamond(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Pentagon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Pentagon, @c false if
/// it is not of type Pentagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPentagon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Pentagon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Pentagon, @c false if
/// it is not of type Pentagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPentagon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Pentagon.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Pentagon, @c false if
/// it is not of type Pentagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPentagon(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Pentagon.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Pentagon, @c false if
/// it is not of type Pentagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPentagon(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Pentagon.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Pentagon, @c false if either it is not of type Pentagon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isPentagon(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Hexagon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Hexagon, @c false if
/// it is not of type Hexagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isHexagon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Hexagon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Hexagon, @c false if
/// it is not of type Hexagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isHexagon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Hexagon.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Hexagon, @c false if
/// it is not of type Hexagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isHexagon(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Hexagon.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Hexagon, @c false if
/// it is not of type Hexagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isHexagon(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Hexagon.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Hexagon, @c false if either it is not of type Hexagon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isHexagon(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Octagon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Octagon, @c false if
/// it is not of type Octagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isOctagon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Octagon.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Octagon, @c false if
/// it is not of type Octagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isOctagon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Octagon.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Octagon, @c false if
/// it is not of type Octagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isOctagon(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Octagon.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Octagon, @c false if
/// it is not of type Octagon or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isOctagon(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Octagon.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Octagon, @c false if either it is not of type Octagon or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isOctagon(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCurve.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCurve, @c false if
/// it is not of type RenderCurve or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRenderCurve(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type RenderCurve.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCurve, @c false if
/// it is not of type RenderCurve or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRenderCurve(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type RenderCurve.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type RenderCurve, @c false if
/// it is not of type RenderCurve or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRenderCurve(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type RenderCurve.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type RenderCurve, @c false if
/// it is not of type RenderCurve or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRenderCurve(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type RenderCurve.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type RenderCurve, @c false if either it is not of type RenderCurve or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isRenderCurve(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Image.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Image, @c false if
/// it is not of type Image or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isImage(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Image.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Image, @c false if
/// it is not of type Image or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isImage(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Image.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Image, @c false if
/// it is not of type Image or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isImage(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Image.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Image, @c false if
/// it is not of type Image or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isImage(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Image.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Image, @c false if either it is not of type Image or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isImage(Transformation2D* shape);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Text.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Text, @c false if
/// it is not of type Text or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isText(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type Text.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type Text, @c false if
/// it is not of type Text or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isText(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Text.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type Text, @c false if
/// it is not of type Text or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isText(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type Text.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the Transformation2D at the given index of this RenderGroup is of type Text, @c false if
/// it is not of type Text or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isText(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Text.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Text, @c false if either it is not of type Text or is or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isText(Transformation2D* shape);

/// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set, @c false if
/// it is not set or is or the object is @c NULL.
bool isSetGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of this Style is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of this Style is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeColor(Style* style, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke" attribute of the Transformation2D at the given index of this RenderGroup is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke" attribute of this abstract Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "stroke" attribute of this abstract Transformation2D is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeColor(Transformation2D* shape);

/// @brief Retrieves the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
const std::string getGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
const std::string getGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
const std::string getGeometricShapeStrokeColor(Style* style, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "stroke" attribute of the Transformation2D at the given index of this RenderGroup.
const std::string getGeometricShapeStrokeColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke" attribute of this abstract Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return a string value representing the "stroke" attribute of this abstract Transformation2D.
const std::string getGeometricShapeStrokeColor(Transformation2D* shape);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param StrokeColor a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(Style* style, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(Style* style, unsigned int geometricShapeIndex, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(RenderGroup* renderGroup, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Sets the value of the "stroke" attribute of this abstract Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param StrokeColorId a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @param StrokeColorValue a string value to use as the value of the "stroke" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeColor(Transformation2D* shape, const std::string& StrokeColorId, const std::string& StrokeColorValue);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of this Style is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of this Style is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeWidth(Style* style, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "stroke-width" attribute of the Transformation2D at the given index of this RenderGroup is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "stroke-width" attribute of this abstract Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "stroke-width" attribute of this abstract Transformation2D is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeStrokeWidth(Transformation2D* shape);

/// @brief Retrieves the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a double value representing the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
const double getGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a double value representing the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
const double getGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a double value representing the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
const double getGeometricShapeStrokeWidth(Style* style, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke-width" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a double value representing the "stroke-width" attribute of the Transformation2D at the given index of this RenderGroup.
const double getGeometricShapeStrokeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "stroke-width" attribute of this abstract Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return a double value representing the "stroke-width" attribute of this abstract Transformation2D.
const double getGeometricShapeStrokeWidth(Transformation2D* shape);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(Style* style, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(Style* style, unsigned int geometricShapeIndex, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(RenderGroup* renderGroup, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the Transformation2D at the given index of the RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of this abstract Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeStrokeWidth(Transformation2D* shape, const double& strokeWidth);

/// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of this Style is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "fill" attribute of the Transformation2D at the given index of the RenderGroup of this Style is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeFillColor(Style* style, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "fill" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "fill" attribute of the Transformation2D at the given index of this RenderGroup is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeFillColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex);

/// @brief Predicates returning @c true if the "fill" attribute of this abstract Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "fill" attribute of this abstract Transformation2D is set, @c false if it is not set or the object is @c NULL.
bool isSetGeometricShapeFillColor(Transformation2D* shape);

/// @brief Retrieves the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
const std::string getGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
const std::string getGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "fill" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
const std::string getGeometricShapeFillColor(Style* style, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "fill" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return a string value representing the "fill" attribute of the Transformation2D at the given index of this RenderGroup.
const std::string getGeometricShapeFillColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex);

/// @brief Retrieves the value of the "fill" attribute of this abstract Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return a string value representing the "fill" attribute of this abstract Transformation2D.
const std::string getGeometricShapeFillColor(Transformation2D* shape);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(Style* style, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup of this Style.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(Style* style, unsigned int geometricShapeIndex, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(RenderGroup* renderGroup, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of the Transformation2D at the given index of the RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& fillColorId, const std::string& fillColorValue);

/// @brief Sets the value of the "fill" attribute of this abstract Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param fillColorId a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @param fillColorValue a string value to use as the value of the "fill" attribute of the Transformation2D object.
/// @return integer value indicating success/failure of the function.
int setGeometricShapeFillColor(Transformation2D* shape, const std::string& fillColorId, const std::string& fillColorValue);

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(Style* style, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(Style* style, unsigned int geometricShapeIndex, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(RenderGroup* renderGroup, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& gradientId);

int setGeometricShapeFillColorAsGradient(Transformation2D* shape, const std::string& gradientId);

/// @brief Predicates returning @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "x" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "x" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "x" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "x" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "x" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "x" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "x" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "x" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "x" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeX(Transformation2D* shape);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "x" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "x" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "x" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "x" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "x" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "x" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "x" attribute of this Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "x" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeX(Transformation2D* shape);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param style a pointer to the Style object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(Style* style, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(RenderGroup* renderGroup, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeX(Transformation2D* shape, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x);

/// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param style a pointer to the Style object.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(Style* style, const double& x);

/// @brief Sets the value of the "x" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(RenderGroup* renderGroup, const double& x);

/// @brief Sets the value of the "x" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& x);

/// @brief Sets the value of the "x" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param x a double to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeXAsDouble(Transformation2D* shape, const double& x);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Predicates returning @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "y" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "y" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "y" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "y" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "y" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "y" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "y" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
    LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "y" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "y" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "y" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeY(Transformation2D* shape);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "y" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "y" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "y" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "y" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "y" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "y" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "y" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "y" attribute of this Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "y" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeY(Transformation2D* shape);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(Style* style, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(RenderGroup* renderGroup, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeY(Transformation2D* shape, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y);

/// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param style a pointer to the Style object.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(Style* style, const double& y);

/// @brief Sets the value of the "y" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(RenderGroup* renderGroup, const double& y);

/// @brief Sets the value of the "y" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& y);

/// @brief Sets the value of the "y" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param y a double to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeYAsDouble(Transformation2D* shape, const double& y);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Predicates returning @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "width" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "width" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "width" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "width" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "width" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeWidth(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "width" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "width" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "width" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "width" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeWidth(Transformation2D* shape);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "width" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "width" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "width" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeWidth(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "width" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "width" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "width" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "width" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "width" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeWidth(Transformation2D* shape);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(Style* style, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(RenderGroup* renderGroup, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidth(Transformation2D* shape, const RelAbsVector& width);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& width);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& width);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param style a pointer to the Style object.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(Style* style, const double& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(Style* style, unsigned int geometricShapeIndex, const double& width);

/// @brief Sets the value of the "width" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(RenderGroup* renderGroup, const double& width);

/// @brief Sets the value of the "width" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& width);

/// @brief Sets the value of the "width" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param width a double to use as the value of the "width" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeWidthAsDouble(Transformation2D* shape, const double& width);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& width);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param width a double to use as the value of the "width" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation, const double& width);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& width);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param width a double to use as the value of the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation, const double& width);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& width);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param width a double to use as the value of the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation, const double& width);

/// @brief Predicates returning @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "height" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "height" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "height" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "height" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "height" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHeight(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "height" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "height" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHeight(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "height" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "height" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHeight(Transformation2D* shape);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "height" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "height" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "height" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeHeight(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "height" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "height" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeHeight(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "height" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "height" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "height" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeHeight(Transformation2D* shape);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(Style* style, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(RenderGroup* renderGroup, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param width a RelAbsVector to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeight(Transformation2D* shape, const RelAbsVector& height);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& height);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& height);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(Style* style, const double& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(Style* style, unsigned int geometricShapeIndex, const double& height);

/// @brief Sets the value of the "height" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(RenderGroup* renderGroup, const double& height);

/// @brief Sets the value of the "height" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& height);

/// @brief Sets the value of the "height" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param height a double to use as the value of the "height" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHeightAsDouble(Transformation2D* shape, const double& height);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& height);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param height a double to use as the value of the "height" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation, const double& height);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "width" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& height);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param height a double to use as the value of the "height" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation, const double& height);

/// @brief Returns the value of the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "width" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& height);

/// @brief Returns the value of the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param height a double to use as the value of the "height" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation, const double& height);

/// @brief Predicates returning @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "ratio" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "ratio" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ratio" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "ratio" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRatio(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ratio" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ratio" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRatio(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ratio" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "ratio" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRatio(Transformation2D* shape);

/// @brief Returns the value of the "ratio" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ratio" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ratio" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ratio" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getGeometricShapeRatio(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ratio" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "ratio" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getGeometricShapeRatio(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ratio" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "ratio" attribute of the Transformation2D object, or @c "0.0" if
///// either the Transformation2D object does not have "ratio" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getGeometricShapeRatio(Transformation2D* shape);

/// @brief Sets the value of the "ratio" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& ratio);

/// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ratio);

/// @brief Sets the value of the "ratio" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& ratio);

/// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& ratio);

/// @brief Sets the value of the "ratio" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(Style* style, const double& ratio);

/// @brief Sets the value of the "ratio" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(Style* style, unsigned int geometricShapeIndex, const double& ratio);

/// @brief Sets the value of the "ratio" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(RenderGroup* renderGroup, const double& ratio);

/// @brief Sets the value of the "ratio" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ratio a double to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& ratio);

/// @brief Sets the value of the "height" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param ratio a double value to use as the value of the "ratio" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRatio(Transformation2D* shape, const double& ratio);

/// @brief Returns the value of the "ratio" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ratio" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ratio" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ratio a double to use as the value of the "ratio" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation, const double& ratio);

/// @brief Returns the value of the "ratio" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ratio" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ratio" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ratio a double to use as the value of the "ratio" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation, const double& ratio);

/// @brief Returns the value of the "ratio" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ratio" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ratio" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ratio a double to use as the value of the "ratio" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation, const double& ratio);

/// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "rx" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "rx" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "rx" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "rx" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "rx" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "rx" attribute of the Rectangle object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(Style* style, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(Style* style, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderGroup* renderGroup, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusXAsDouble(Transformation2D* shape, const double& rx);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a double to use as the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a double to use as the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a double to use as the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx);

/// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "ry" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "ry" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "ry" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "ry" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "ry" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "ry" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(Style* style, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(Style* style, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderGroup* renderGroup, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCornerCurvatureRadiusYAsDouble(Transformation2D* shape, const double& ry);

/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a double to use as the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry);

/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a double to use as the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry);

/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a double to use as the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry);

/// @brief Predicates returning @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "cx" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "cx" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cx" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "cx" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cx" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cx" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cx" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "cx" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterX(Transformation2D* shape);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "cx" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cx" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "cx" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cx" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "cx" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "cx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterX(Transformation2D* shape);

/// @brief Sets the value of the "cx" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(Style* style, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(RenderGroup* renderGroup, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterX(Transformation2D* shape, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& cx);

/// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cx);

/// @brief Sets the value of the "cx" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& cx);

/// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& cx);

/// @brief Sets the value of the "cx" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(Style* style, const double& cx);

/// @brief Sets the value of the "cx" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& cx);

/// @brief Sets the value of the "cx" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(RenderGroup* renderGroup, const double& cx);

/// @brief Sets the value of the "cx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& cx);

/// @brief Sets the value of the "cx" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param cx a double to use as the value of the "cx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterXAsDouble(Transformation2D* shape, const double& cx);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cx);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cx a double to use as the value of the "cx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cx);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cx);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cx a double to use as the value of the "cx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cx);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cx);

/// @brief Returns the value of the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cx a double to use as the value of the "cx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cx);

/// @brief Predicates returning @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "cy" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "cy" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cy" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "cy" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cy" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "cy" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "cy" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "cy" attribute of this Transformation2D object is set, @c false
/// either the Transformation2D object does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeCenterY(Transformation2D* shape);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "cy" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cy" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "cy" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cy" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "cy" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeCenterY(Transformation2D* shape);

/// @brief Sets the value of the "cy" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(Style* style, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(RenderGroup* renderGroup, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterY(Transformation2D* shape, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& cy);

/// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cy);

/// @brief Sets the value of the "cy" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& cy);

/// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& cy);

/// @brief Sets the value of the "cy" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(Style* style, const double& cy);

/// @brief Sets the value of the "cy" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& cy);

/// @brief Sets the value of the "cy" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(RenderGroup* renderGroup, const double& cy);

/// @brief Sets the value of the "cy" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& cy);

/// @brief Sets the value of the "cy" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param cy a double to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeCenterYAsDouble(Transformation2D* shape, const double& cy);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cy);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cy a double to use as the value of the "cy" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cy);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cy);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cy a double to use as the value of the "cy" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cy);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cy);

/// @brief Returns the value of the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param cy a double to use as the value of the "cy" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cy);

/// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "rx" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "rx" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "rx" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "rx" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "rx" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "rx" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusX(Transformation2D* shape);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "rx" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusX(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "cy" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "cy" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "rx" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "rx" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "rx" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusX(Transformation2D* shape);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(Style* style, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param rx a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(RenderGroup* renderGroup, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a RelAbsVector to use as the value of the "cy" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusX(Transformation2D* shape, const RelAbsVector& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(Style* style, const double& rx);

/// @brief Sets the value of the "rx" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(RenderGroup* renderGroup, const double& rx);

/// @brief Sets the value of the "rx" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& rx);

/// @brief Sets the value of the "rx" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param rx a double to use as the value of the "rx" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusXAsDouble(Transformation2D* shape, const double& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a double to use as the value of the "rx" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a double to use as the value of the "rx" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx);

/// @brief Returns the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param rx a double to use as the value of the "rx" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx);

/// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "ry" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "ry" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "ry" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "ry" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "ry" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "ry" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeRadiusY(Transformation2D* shape);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "ry" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusY(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "ry" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "ry" attribute of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the "ry" attribute of the Transformation2D object, or @c RelAbsVector() if
/// either the Transformation2D object does not have "ry" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeRadiusY(Transformation2D* shape);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(Style* style, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(RenderGroup* renderGroup, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusY(Transformation2D* shape, const RelAbsVector& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(Style* style, const double& ry);

/// @brief Sets the value of the "ry" attribute the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(RenderGroup* renderGroup, const double& ry);

/// @brief Sets the value of the "ry" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& ry);

/// @brief Sets the value of the "ry" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param ry a double to use as the value of the "ry" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeRadiusYAsDouble(Transformation2D* shape, const double& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a double to use as the value of the "ry" attribute of the RenderGroup of the Style for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a double to use as the value of the "ry" attribute of the RenderGroup of the Style for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry);

/// @brief Returns the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param ry a double to use as the value of the "ry" attribute of the RenderGroup of the Style for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry);

/// @brief Returns the number of elements of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the number of elements of the Transformation2D object at the given index of the RenderGroup of this Style for this GraphicalObject, or @c 0 if
/// either Transformation2D object does not exists, does not have any elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const unsigned int getGeometricShapeNumElements(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the number of elements of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the number of elements of the Transformation2D object at the given index of the RenderGroup of this Style for this GraphicalObject, or @c 0 if
/// either Transformation2D object does not exists, does not have any elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const unsigned int getGeometricShapeNumElements(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the number of elements of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the number of elements of the Transformation2D object at the given index of the RenderGroup of this Style, or @c 0 if
/// either Transformation2D object does not exists, does not have any elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const unsigned int getGeometricShapeNumElements(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the number of elements of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the number of elements of the Transformation2D object at the given index of this RenderGroup, or @c 0 if
/// either Transformation2D object does not exists, does not have any elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const unsigned int getGeometricShapeNumElements(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the number of elements of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @return the number of elements of the Transformation2D object, or @c 0 if
/// either the Transformation2D object does not have any elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const unsigned int getGeometricShapeNumElements(Transformation2D* shape);

/// @brief Returns the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementX(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of element at the given index of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the element with the given index of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementX(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the element with the given index of Transformation2D object, or @c RelAbsVector() if
/// the Transformation2D object does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementX(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(Style* style, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(Style* style, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderGroup* renderGroup, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of element with the given index of this Transformation2D.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(Transformation2D* shape, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of element with the given index of this Transformation2D.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementX(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double to use as the value of the "x" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a double to use as the value of the "x" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param x a double to use as the value of the "x" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(Style* style, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(Style* style, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of the first Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a double to use as the value of the "x" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderGroup* renderGroup, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderGroup* renderGroup, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a double to use as the value of the "x" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementXAsDouble(Transformation2D* shape, const double& x);

/// @brief Returns the value of the "x" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the geometric shape element for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the geometric shape element for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the geometric shape element for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the geometric shape element for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the geometric shape element for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the geometric shape element for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the element with the given index of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementY(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of element at the given index of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the element with the given index of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementY(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the element with the given index of Transformation2D object, or @c RelAbsVector() if
/// the Transformation2D object does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeElementY(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(Style* style, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(Style* style, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderGroup* renderGroup, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a RelAbsVector to use as the value of the "y" attribute of element with the given index of this Transformation2D.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(Transformation2D* shape, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of element with the given index of this Transformation2D.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementY(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a double to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a double to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(Style* style, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(Style* style, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a double to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderGroup* renderGroup, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderGroup* renderGroup, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param y a double to use as the value of the "y" attribute of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeElementYAsDouble(Transformation2D* shape, const double& y);

/// @brief Returns the value of the "y" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the geometric shape element for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the geometric shape element for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the geometric shape element for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the geometric shape element for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the geometric shape element for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the geometric shape element for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1X(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of base point 1 of element at the given index of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the element with the given index of Transformation2D object, or @c RelAbsVector() if
/// the Transformation2D object does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1X(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(Style* style, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(Style* style, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(Transformation2D* shape, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1X(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(Style* style, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(Style* style, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderGroup* renderGroup, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderGroup* renderGroup, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1XAsDouble(Transformation2D* shape, const double& x);

/// @brief Returns the value of the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1Y(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of base point 1 of element at the given index of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 1 of the element with the given index of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 1 of the element with the given index of Transformation2D object, or @c RelAbsVector() if
/// the Transformation2D object does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint1Y(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(Style* style, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(Style* style, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(Transformation2D* shape, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1Y(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(Style* style, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(Style* style, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderGroup* renderGroup, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderGroup* renderGroup, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 1 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint1YAsDouble(Transformation2D* shape, const double& y);

/// @brief Returns the value of the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the base point 1 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2X(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of base point 2 of element at the given index of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the element with the given index of Transformation2D object, or @c RelAbsVector() if
/// the Transformation2D object does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2X(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(Style* style, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(Style* style, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
    LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(Transformation2D* shape, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2X(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(Style* style, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(Style* style, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderGroup* renderGroup, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderGroup* renderGroup, unsigned int elementIndex, const double& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x);

/// @brief Sets the value of the "x" attribute of the base point 2 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2XAsDouble(Transformation2D* shape, const double& x);

/// @brief Returns the value of the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x);

/// @brief Returns the value of the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param x a double to use as the value of the "x" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x);

/// @brief Returns the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2Y(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of base point 2 of element at the given index of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 2 of the element with the given index of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Returns the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 2 of the element with the given index of Transformation2D object, or @c RelAbsVector() if
/// the Transformation2D object does not have any elements, it has less than n elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getGeometricShapeBasePoint2Y(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(Style* style, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(Style* style, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(Transformation2D* shape, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2Y(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(Style* style, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at at the given index of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(Style* style, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at at the given index of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderGroup* renderGroup, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderGroup* renderGroup, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the element at the given index of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the element at the given index of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y);

/// @brief Sets the value of the "y" attribute of the base point 2 of the first element of this Transformation2D.
/// @param shape a pointer to the Transformation2D object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the first element of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeBasePoint2YAsDouble(Transformation2D* shape, const double& y);

/// @brief Returns the value of the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getCompartmentGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getCompartmentGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getSpeciesGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getSpeciesGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Returns the value of the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects, or @c RelAbsVector() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const RelAbsVector getReactionGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y);

/// @brief Returns the value of the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects, or @c double() if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const double getReactionGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param y a double to use as the value of the "y" attribute of the base point 2 of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y);

/// @brief Add a render point to the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderPointToGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Add a render point to the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderPointToGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Add a render point to the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderPointToGeometricShape(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Add a render point to the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderPointToGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Add a render point to this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderPointToGeometricShape(Transformation2D* shape);

/// @brief Add a render cubic bezier to the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderCubicBezierToGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Add a render cubic bezier to the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderCubicBezierToGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Add a render cubic bezier to the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderCubicBezierToGeometricShape(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Add a render cubic bezier to the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderCubicBezierToGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Add a render cubic bezier to this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int addRenderCubicBezierToGeometricShape(Transformation2D* shape);

/// @brief Remove an element from the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param index an unsigned int representing the index of the element to be removed.
/// @return a pointer to the RenderPoint at the given index of this Transformation2D object, or @c NULL if
/////// either Transformation2D object does not exists, does not have any elements, it has less than index elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN RenderPoint* removeElementFromGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Remove an element from the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param index an unsigned int representing the index of the element to be removed.
/// @return a pointer to the RenderPoint at the given index of this Transformation2D object, or @c NULL if
/////// either Transformation2D object does not exists, does not have any elements, it has less than index elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN RenderPoint* removeElementFromGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Remove an element from the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param index an unsigned int representing the index of the element to be removed.
/// @return a pointer to the RenderPoint at the given index of this Transformation2D object, or @c NULL if
/////// either Transformation2D object does not exists, does not have any elements, it has less than index elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN RenderPoint* removeElementFromGeometricShape(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Remove an element from the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param index an unsigned int representing the index of the element to be removed.
/// @return a pointer to the RenderPoint at the given index of this Transformation2D object, or @c NULL if
/////// either Transformation2D object does not exists, does not have any elements, it has less than index elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN RenderPoint* removeElementFromGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Remove an element from this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param index an unsigned int representing the index of the element to be removed.
/// @return a pointer to the RenderPoint at the given index of this Transformation2D object, or @c NULL if
///// either Transformation2D object does not exists, does not have any elements, it has less than index elements, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN RenderPoint* removeElementFromGeometricShape(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCubicBezier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return @c true if the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isRenderCubicBezier(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is of type RenderCubicBezier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return @c true if the element at the given index of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is of type RenderCubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isRenderCubicBezier(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of the RenderGroup of this Style is of type RenderCubicBezier.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return @c true if the element at the given index of the Transformation2D at the given index of the RenderGroup of this Style is of type RenderCubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isRenderCubicBezier(Style* style, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Predicates returning @c true if the Transformation2D at the given index of this RenderGroup is of type RenderCubicBezier.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return @c true if the element at the given index of the Transformation2D at the given index of this RenderGroup is of type RenderCubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isRenderCubicBezier(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0);

/// @brief Predicate returning true if the element at the given index of this Transformation2D is of type RenderCubicBezier.
/// @param shape a pointer to the Transformation2D object.
/// @param elementIndex an unsigned int representing the index of the element to retrieve.
/// @return @c true if the element at the given index of this Transformation2D is of type RenderCubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isRenderCubicBezier(Transformation2D* shape, unsigned int elementIndex = 0);

/// @brief Predicate returning true if this RenderCurve is of type RenderCubicBezier.
/// @param renderPoint a pointer to the RenderPoint object.
/// @return @c true if this RenderPoint is of type RenderCubicBezier, @c false otherwise
LIBSBMLNETWORK_EXTERN bool isRenderCubicBezier(RenderPoint* renderPoint);

/// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "href" attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject = 0, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject is set,
/// @c false if either the "href" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "href" attribute the Transformation2D at the given index of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "href" attribute of the Transformation2D object at the given index of the RenderGroup of this Style object is set,
/// @c false if either the "href" attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHref(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "href" attribute of the Transformation2D at the given index of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return @c true if the "href" attribute of the Transformation2D object at the given index of this RenderGroup is set, @c false if
/// either Transformation2D object does not exists, does not have "href" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHref(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Predicates returning @c true if the "href" attribute of this Transformation2D is set.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if the "href" attribute of this Transformation2D object is set, @c false if
/// either the Transformation2D object does not have "href" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetGeometricShapeHref(Transformation2D* shape);

/// @brief Returns the value of the "href" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "href" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "href" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "href" attribute of the Transformation2D object at the given index of the RenderGroup of the Style for this GraphicalObject, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "href" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "href" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the "href" attribute of the Transformation2D object at the given index of the RenderGroup of this Style, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "href" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeHref(Style* style, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "href" attribute of the Transformation2D object at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "href" attribute of the Transformation2D object at the given index of this RenderGroup, or @c RelAbsVector() if
/// either Transformation2D object does not exists, does not have "cy" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeHref(RenderGroup* renderGroup, unsigned int geometricShapeIndex = 0);

/// @brief Returns the value of the "href" attribute of this Transformation2D object.
/// @param shape a pointer to the Image object.
/// @return the "href" attribute of the Transformation2D object, or @c "" if the object is @c NULL if
/// either the Transformation2D object does not have "href" attribute, it is not set, or the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getGeometricShapeHref(Transformation2D* shape);

/// @brief Sets the value of the "href" attribute of the first Transformation2D of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& href);

/// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& href);

/// @brief Sets the value of the "href" attribute of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& href);

/// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& href);

/// @brief Sets the value of the "href" attribute of the first Transformation2D of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(Style* style, const std::string& href);

/// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(Style* style, unsigned int geometricShapeIndex, const std::string& href);

/// @brief Sets the value of the "href" attribute of the first Transformation2D of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(RenderGroup* renderGroup, const std::string& href);

/// @brief Sets the value of the "href" attribute of the Transformation2D at the given index of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param geometricShapeIndex an unsigned int representing the index of the Transformation2D to retrieve.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& href);

/// @brief Sets the value of the "href" attribute of this Transformation2D object.
/// @param shape a pointer to the Transformation2D object.
/// @param href a string value to use as the value of the "href" attribute of this Transformation2D object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setGeometricShapeHref(Transformation2D* shape, const std::string& href);

/// @brief Returns the value of the "href" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "href" attribute of the geometric shape element for all CompartmentGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentGeometricShapeHref(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the "href" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param href a string value to use as the value of the "href" attribute of the geometric shape element for all CompartmentGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setCompartmentGeometricShapeHref(GlobalRenderInformation* globalRenderInformation, const std::string& href);

/// @brief Returns the value of the "href" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "href" attribute of the geometric shape element for all SpeciesGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesGeometricShapeHref(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the "href" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param href a string value to use as the value of the "href" attribute of the geometric shape element for all SpeciesGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setSpeciesGeometricShapeHref(GlobalRenderInformation* globalRenderInformation, const std::string& href);

/// @brief Returns the value of the "href" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "href" attribute of the geometric shape element for all ReactionGlyph objects, or an empty string if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getReactionGeometricShapeHref(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the "href" attribute of the geometric shape element for all ReactionGlyph objects.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param href a string value to use as the value of the "href" attribute of the geometric shape element for all ReactionGlyph objects.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setReactionGeometricShapeHref(GlobalRenderInformation* globalRenderInformation, const std::string& href);

LIBSBMLNETWORK_EXTERN const std::string getStyle(GlobalRenderInformation* globalRenderInformation);

/// @brief Returns the absolute coordinate value of this RelAbsVector.
/// @param relAbsVector a RelAbsVector.
/// @return the absolute coordinate value of this RelAbsVector
LIBSBMLNETWORK_EXTERN const double getAbsoluteValue(const RelAbsVector& relAbsVector);

/// @brief Returns the relative coordinate value of this RelAbsVector.
/// @param relAbsVector a RelAbsVector.
/// @return the relative coordinate value of this RelAbsVector
LIBSBMLNETWORK_EXTERN const double getRelativeValue(const RelAbsVector& relAbsVector);

/// @brief Sets the absolute coordinate value of this RelAbsVector.
/// @param relAbsVector a RelAbsVector.
/// @param abs double value of the "abs" attribute to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setAbsoluteValue(RelAbsVector relAbsVector, const double& abs);

/// @brief Sets the relative coordinate value of this RelAbsVector.
/// @param relAbsVector a RelAbsVector.
/// @param rel double value of the "rel" attribute to be set.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setRelativeValue(RelAbsVector relAbsVector, const double& rel);

/// @brief Returns the object role string for the GraphicalObject object with the given id.
/// @param layout a pointer to the Layout object.
/// @param id the id of the graphical object.
/// @return the object role string the for this GraphicalObject object, or @c NULL if the object is @c NULL.
LIBSBMLNETWORK_EXTERN const std::string getObjectRole(Layout* layout, const std::string& id);

/// @brief Returns the object role string for this GraphicalObject.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the object role string for the GraphicalObject object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getObjectRole(GraphicalObject* graphicalObject);

}

#endif

