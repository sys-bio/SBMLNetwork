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

/// @brief Returns the number of items in the ListOfGlobalRenderInformation of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of items in the ListOfGlobalRenderInformation of the SBML document, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGlobalRenderInformation(SBMLDocument* document);

/// @brief Returns the number of items in this ListOfGlobalRenderInformation object.
/// @param listOfGlobalRenderInformation a pointer to the ListOfGlobalRenderInformation object.
/// @return the number of items in this ListOfGlobalRenderInformation object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation);

/// @brief Returns a pointer to the nth GlobalRenderInformation in the ListOfGlobalRenderInformation of the SBML document.
/// @param n the index number of the GlobalRenderInformation to return.
/// @return the @c the nth GlobalRenderInformation in the ListOfGlobalRenderInformation of the SBML document or NULL if
/// no such GlobalRenderInformation exists or the document is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN GlobalRenderInformation* getGlobalRenderInformation(SBMLDocument* document, unsigned int n);

/// @brief Returns a pointer to the nth GlobalRenderInformation in this ListOfGlobalRenderInformation.
/// @param n the index number of the GlobalRenderInformation to return.
/// @return the @c the nth GlobalRenderInformation in this ListOfGlobalRenderInformation or NULL if no such GlobalRenderInformation exists or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN GlobalRenderInformation* getGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation, unsigned int n);

/// @brief Add GlobalRenderInformation to list of global renders of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addGlobalRenderInformation(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation);

/// @brief Create a GlobalRenderInformation object and add it to list of global renders of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the created GlobalRenderInformation object.
LIBSBML_NETWORKEDITOR_EXTERN GlobalRenderInformation* createGlobalRenderInformation(SBMLDocument* document);

/// @brief Remove all the global render information objects from the list of global renders of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeAllGlobalRenderInformation(SBMLDocument* document);

/// @brief Set all the necessary features for the global render information object.
/// @param document a pointer to the SBMLDocument object.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultGlobalRenderInformationFeatures(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation);

/// @brief Get the List of local render Information of the Layout.
/// @param document a pointer to the Layout object.
/// @return a pointer to the ListOfGlobalInformationBase object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout);

/// @brief Returns the number of items in the ListOfGlobalRenderInformation of this Layout object.
/// @param layout a pointer to the Layout object.
/// @return the number of items in the ListOfGlobalRenderInformation of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLocalRenderInformation(Layout* layout);

/// @brief Returns the number of items in this ListOfLocalRenderInformation object.
/// @param listOfLocalRenderInformation a pointer to the ListOfLocalRenderInformation object.
/// @return the number of items in this ListOfLocalRenderInformation object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation);

/// @brief Returns a pointer to the nth LocalRenderInformation in the ListOfLocalRenderInformation of this layout object.
/// @param layout a pointer to the Layout object.
/// @param n the index number of the GlobalRenderInformation to return.
/// @return the @c the nth LocalRenderInformation in the ListOfLocalRenderInformation of this Layout object or NULL if
/// no such LocalRenderInformation exists or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* getLocalRenderInformation(Layout* layout, unsigned int n);

/// @brief Returns a pointer to the nth LocalRenderInformation in this ListOfLocalRenderInformation.
/// @param n the index number of the LocalRenderInformation to return.
/// @return the @c the nth LocalRenderInformation in this ListOfLocalRenderInformation or NULL if no such LocalRenderInformation exists or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* getLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation, unsigned int n);

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

/// @brief Predicates returning @c true if the "backgroundColor" attribute of this GlobalRenderInformation is set.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return @c true if the "backgroundColor" attribute of this GlobalRenderInformation object is set, @c false if either the "backgroundColor"
/// attribute is not set or the object is @c NULL.
bool isSetBackgroundColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Returns the value of the "backgroundColor" attribute of this GlobalRenderInformation.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @return the "backgroundColor" attribute of the GlobalRenderInformation object, or @c "" if the object is @c NULL
const std::string getBackgroundColor(GlobalRenderInformation* globalRenderInformation);

/// @brief Sets the value of the "backgroundColor" attribute of this GlobalRenderInformation object.
/// @param globalRenderInformation a pointer to the GlobalRenderInformation object.
/// @param backgroundColor a string value to use as the value of the "backgroundColor" attribute of this GlobalRenderInformation object.
/// @return integer value indicating success/failure of the function.
int setBackgroundColor(GlobalRenderInformation* globalRenderInformation, const std::string& backgroundColor);

/// @brief Returns a ColorDefinition from the RenderInformationBase based on its identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the @c ColorDefinition in the ListOfColorDefinitions within this RenderInformationBase with the given sid or @c NULL if no such ColorDefinition exists.
LIBSBML_NETWORKEDITOR_EXTERN ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "value" attribute of the ColorDefinition with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetValue(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "value" attribute of this ColorDefinition is set.
/// @param colorDefinition a pointer to the ColorDefinition object.
/// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetValue(ColorDefinition* colorDefinition);

/// @brief Returns the value of the "value" attribute of the ColorDefinition with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getValue(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "value" attribute of this ColorDefinition.
/// @param colorDefinition a pointer to the ColorDefinition object.
/// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getValue(ColorDefinition* colorDefinition);

/// @brief Sets the value of the "value" attribute of the ColorDefinition with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setValue(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& value);

/// @brief Sets the value of the "value" attribute of this ColorDefinition object.
/// @param colorDefinition a pointer to the ColorDefinition object.
/// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setValue(ColorDefinition* colorDefinition, const std::string& value);

/// @brief Returns a GradientBase from the RenderInformationBase based on its identifier.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the @c GradientBase in the ListOfGradientDefinitions within this RenderInformationBase with the given sid or @c NULL if no such GradientBase exists.
LIBSBML_NETWORKEDITOR_EXTERN GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier is of type LinearGradient.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isLinearGradient(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicate returning true if this abstract GradientBase is of type LinearGradient.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isLinearGradient(GradientBase* gradientBase);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier is of type RadialGradient.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRadialGradient(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicate returning true if this abstract GradientBase is of type RadialGradient.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRadialGradient(GradientBase* gradientBase);

/// @brief Predicates returning @c true if the "spreadMethod" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "spreadMethod" attribute of this GradientBase object is set, @c false if either the "spreadMethod"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "spreadMethod" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "spreadMethod" attribute of this GradientBase object is set, @c false if either the "spreadMethod"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetSpreadMethod(GradientBase* gradientBase);

/// @brief Returns the value of the "spreadMethod" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "spreadMethod" attribute of the GradientBase object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "spreadMethod" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "spreadMethod" attribute of the GradientBase object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpreadMethod(GradientBase* gradientBase);

/// @brief Sets the value of the "spreadMethod" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& spreadMethod);

/// @brief Sets the value of the "spreadMethod" attribute of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setSpreadMethod(GradientBase* gradientBase, const std::string& spreadMethod);

/// @brief Returns Get the number of GradientStop objects in the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the number of GradientStop objects in this GradientBase, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumGradientStops(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns Get the number of GradientStop objects in this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the number of GradientStop objects in this GradientBase, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumGradientStops(GradientBase* gradientBase);

/// @brief Returns the nth GradientStop of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param n an unsigned int representing the index of the GradientStop to retrieve.
/// @return the GradientStop at the given index of the GradientBase object, or NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN GradientStop* getGradientStop(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n);

/// @brief Returns the nth GradientStop of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param n an unsigned int representing the index of the GradientStop to retrieve.
/// @return the GradientStop at the given index of the GradientBase object, or NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN GradientStop* getGradientStop(GradientBase* gradientBase, unsigned  int n);

/// @brief Predicates returning @c true if the "offset" attribute of the nth GradientStop of this the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return @c true if the "offset" attribute of the nth GradientStop of this GradientBase object is set, @c false if
/// either the "offset" attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n);

/// @brief Predicates returning @c true if the "offset" attribute of the nth GradientStop of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return @c true if the "offset" attribute of the nth GradientStop of this GradientBase object is set, @c false if
/// either the "offset" attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOffset(GradientBase* gradientBase, unsigned  int n);

/// @brief Predicates returning @c true if the "offset" attribute of this GradientStop is set.
/// @param gradientStop a pointer to the GradientStop object.
/// @return @c true if the "offset" attribute of this GradientStop object is set, @c false if either the "offset" attribute is not set
/// or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOffset(GradientStop* gradientStop);

/// @brief Returns the value of the "offset" attribute of the nth GradientStop of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "offset" attribute of the nth GradientStop of the GradientBase object, or @c RelAbsVector() if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getOffset(RenderInformationBase* renderInformationBase, const std::string& sid , unsigned  int n);

/// @brief Returns the value of the "offset" attribute of the nth GradientStop of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "offset" attribute of the nth GradientStop of the GradientBase object, or @c RelAbsVector() if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getOffset(GradientBase* gradientBase , unsigned  int n);

/// @brief Returns the value of the "offset" attribute of this GradientBase.
/// @param gradientStop a pointer to the GradientStop object.
/// @return the "offset" attribute of the GradientStop object, or @c RelAbsVector() if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getOffset(GradientStop* gradientStop);

/// @brief Sets the value of the "offset" attribute of the nth GradientStop of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the nth GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the nth GradientStop of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the nth GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(GradientBase* gradientBase, unsigned  int n, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of this GradientStop object.
/// @param gradientStop a pointer to the GradientStop object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(GradientStop* gradientStop, const RelAbsVector& offset);

/// @brief Predicates returning @c true if the "stop-color" attribute of the nth GradientStop of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "stop-color" attribute of nth GradientStop of this GradientBase object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int n);

/// @brief Predicates returning @c true if the "stop-color" attribute of the nth GradientStop of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "stop-color" attribute of nth GradientStop of this GradientBase object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStopColor(GradientBase* gradientBase, unsigned int n);

/// @brief Predicates returning @c true if the "stop-color" attribute of this GradientStop is set.
/// @param gradientStop a pointer to the GradientStop object.
/// @return @c true if the "stop-color" attribute of this GradientStop object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStopColor(GradientStop* gradientStop);

/// @brief Returns the value of the "stop-color" attribute of the nth GradientStop of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "stop-color" attribute of the nth GradientStop of this GradientStop object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int n);

/// @brief Returns the value of the "stop-color" attribute of the nth GradientStop of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "stop-color" attribute of the nth GradientStop of this GradientStop object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStopColor(GradientBase* gradientBase, unsigned int n);

/// @brief Returns the value of the "stop-color" attribute of this GradientStop.
/// @param gradientStop a pointer to the GradientStop object.
/// @return the "stop-color" attribute of the GradientStop object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStopColor(GradientStop* gradientStop);

/// @brief Sets the value of the "stop-color" attribute of the nth GradientStop of this the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of the nth GradientStop of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int n, const std::string& stopColor);

/// @brief Sets the value of the "stop-color" attribute of the nth GradientStop of this GradientBase object.
/// @param gradientBase a pointer to the GradientBase object.
/// @param n an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of the nth GradientStop of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(GradientBase* gradientBase, unsigned int n, const std::string& stopColor);

/// @brief Sets the value of the "stop-color" attribute of this GradientStop object.
/// @param gradientStop a pointer to the GradientStop object.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(GradientStop* gradientStop, const std::string& stopColor);

/// @brief Predicates returning @c true if the "x1" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "x1" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX1(GradientBase* gradientBase);

/// @brief Returns the value of the "x1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "x1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "x1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX1(GradientBase* gradientBase);

/// @brief Sets the value of the "x1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x1 a RelAbsVector to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x1);

/// @brief Sets the value of the "x1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param x1 a RelAbsVector to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX1(GradientBase* gradientBase, const RelAbsVector& x1);

/// @brief Predicates returning @c true if the "x2" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x2" attribute of this GradientBase object is set, @c false if either the "x2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "x2" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "x2" attribute of this GradientBase object is set, @c false if either the "x2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX2(GradientBase* gradientBase);

/// @brief Returns the value of the "x2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "x2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "x2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX2(GradientBase* gradientBase);

/// @brief Sets the value of the "x2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x2 a RelAbsVector to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x2);

/// @brief Sets the value of the "x2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param x2 a RelAbsVector to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX2(GradientBase* gradientBase, const RelAbsVector& x2);

/// @brief Predicates returning @c true if the "y1" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y1" attribute of this GradientBase object is set, @c false if either the "y1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "y1" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "y1" attribute of this GradientBase object is set, @c false if either the "y1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY1(GradientBase* gradientBase);

/// @brief Returns the value of the "y1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "y1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "y1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY1(GradientBase* gradientBase);

/// @brief Sets the value of the "y1" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y1 a RelAbsVector to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y1);

/// @brief Sets the value of the "y1" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param y1 a RelAbsVector to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY1(GradientBase* gradientBase, const RelAbsVector& y1);

/// @brief Predicates returning @c true if the "y2" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y2" attribute of this GradientBase object is set, @c false if either the "y2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "y2" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "y2" attribute of this GradientBase object is set, @c false if either the "y2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY2(GradientBase* gradientBase);

/// @brief Returns the value of the "y2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "y2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "y2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY2(GradientBase* gradientBase);

/// @brief Sets the value of the "y2" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y2 a RelAbsVector to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y2);

/// @brief Sets the value of the "y2" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param y2 a RelAbsVector to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY2(GradientBase* gradientBase, const RelAbsVector& y2);

/// @brief Predicates returning @c true if the "cx" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cx" attribute of this GradientBase object is set, @c false if either the "cx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "cx" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "cx" attribute of this GradientBase object is set, @c false if either the "cx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCx(GradientBase* gradientBase);

/// @brief Returns the value of the "cx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "cx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "cx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCx(GradientBase* gradientBase);

/// @brief Sets the value of the "cx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCx(GradientBase* gradientBase, const RelAbsVector& cx);

/// @brief Predicates returning @c true if the "cy" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cy" attribute of this GradientBase object is set, @c false if either the "cy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "cy" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "cy" attribute of this GradientBase object is set, @c false if either the "cy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCy(GradientBase* gradientBase);

/// @brief Returns the value of the "cy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "cy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "cy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCy(GradientBase* gradientBase);

/// @brief Sets the value of the "cy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCy(GradientBase* gradientBase, const RelAbsVector& cy);

/// @brief Predicates returning @c true if the "fx" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fx" attribute of this GradientBase object is set, @c false if either the "fx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "fx" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "fx" attribute of this GradientBase object is set, @c false if either the "fx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFx(GradientBase* gradientBase);

/// @brief Returns the value of the "fx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "fx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "fx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFx(GradientBase* gradientBase);

/// @brief Sets the value of the "fx" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fx a RelAbsVector to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fx);

/// @brief Sets the value of the "fx" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param fx a RelAbsVector to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFx(GradientBase* gradientBase, const RelAbsVector& fx);

/// @brief Predicates returning @c true if the "fy" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fy" attribute of this GradientBase object is set, @c false if either the "fy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "fy" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "fy" attribute of this GradientBase object is set, @c false if either the "fy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFy(GradientBase* gradientBase);

/// @brief Returns the value of the "fy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "fy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "fy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFy(GradientBase* gradientBase);

/// @brief Sets the value of the "fy" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fy a RelAbsVector to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fy);

/// @brief Sets the value of the "fy" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param fy a RelAbsVector to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFy(GradientBase* gradientBase, const RelAbsVector& fy);

/// @brief Predicates returning @c true if the "r" attribute of the GradientBase with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "r" attribute of this GradientBase object is set, @c false if either the "r" attribute is not set
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "r" attribute of this GradientBase is set.
/// @param gradientBase a pointer to the GradientBase object.
/// @return @c true if the "r" attribute of this GradientBase object is set, @c false if either the "r" attribute is not set
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientR(GradientBase* gradientBase);

/// @brief Returns the value of the "r" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "r" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "r" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @return the "r" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientR(GradientBase* gradientBase);

/// @brief Sets the value of the "r" attribute of the GradientBase with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param r a RelAbsVector to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& r);

/// @brief Sets the value of the "r" attribute of this GradientBase.
/// @param gradientBase a pointer to the GradientBase object.
/// @param r a RelAbsVector to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientR(GradientBase* gradientBase, const RelAbsVector& r);

/// @brief Returns a LineEnding from the RenderInformationBase based on its identifier.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the @c LineEnding in the ListOfLineEndings within this RenderInformationBase with the given sid or @c NULL if no such LineEnding exists.
LIBSBML_NETWORKEDITOR_EXTERN LineEnding* getLineEnding(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of the LineEnding with the given identifier is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of this LineEnding is set.
/// @param lineEnding a pointer to the LineEnding object.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEnableRotationalMapping(LineEnding* lineEnding);

/// @brief Returns the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN bool getEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid);

/// @brief Returns the value of the "enableRotationalMapping" attribute of this LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN bool getEnableRotationalMapping(LineEnding* lineEnding);

/// @brief Sets the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid, bool enableRotationalMapping);

/// @brief Sets the value of the "enableRotationalMapping" attribute of this LineEnding .
/// @param lineEnding a pointer to the LineEnding object.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEnableRotationalMapping(LineEnding* lineEnding, bool enableRotationalMapping);

/// Returns the bounding box for the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the bounding box for the LineEnding object, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN BoundingBox* getBoundingBox(RenderInformationBase* renderInformationBase, const std::string& sid);

/// Returns the bounding box for the LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the bounding box for the LineEnding object, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN BoundingBox* getBoundingBox(LineEnding* lineEnding);

/// Returns the value of the "group" element of the LineEnding with the given identifier.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the value of the "group" element of this LineEnding as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN RenderGroup* getRenderGroupOfLineEnding(RenderInformationBase* renderInformationBase, const std::string& sid);

/// Returns the value of the "group" element of this LineEnding.
/// @param lineEnding a pointer to the LineEnding object.
/// @return the value of the "group" element of this LineEnding as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN RenderGroup* getRenderGroup(LineEnding* lineEnding);

/// @brief Searches among the styles of the render information base and returns one that matches this GraphicalObject attributes
/// @param renderInformationBase  a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one that matches this attribute (id, role, type) of a GraphicalObject
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyle(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Searches among the styles of the render information base and returns one contains the "id" in its idlist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyleById(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "id" in its idlist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param id the id attribute of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyleById(RenderInformationBase* renderInformationBase, const std::string& id);

/// @brief Searches among the styles of the render information base and returns one contains the "role" in its rolelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyleByRole(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "role" in its rolelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param role the role attribute of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyleByRole(RenderInformationBase* renderInformationBase, const std::string& role);

/// @brief Searches among the styles of the render information base and returns one contains the "type" in its typelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyleByType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Searches among the styles of the render information base and returns one contains the "type" in its typelist.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param type the type attribute of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN Style* getStyleByType(RenderInformationBase* renderInformationBase, const std::string& type);

/// Returns the value of the "group" element of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the value of the "group" element of the Style for this GraphicalObjet as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN RenderGroup* getRenderGroup(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// Returns the value of the "group" element of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return a pointer to the found Style object.
LIBSBML_NETWORKEDITOR_EXTERN RenderGroup* getRenderGroup(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// Returns the value of the "group" element of this Style.
/// @param style a pointer to the Style object.
/// @return the value of the "group" element of this Style as a RenderGroup, or @c NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN RenderGroup* getRenderGroup(Style* style);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeColor(Style* style);

/// @brief Predicates returning @c true if the "stroke" attribute of this GraphicalPrimitive1D is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return @c true if the "stroke" attribute of this GraphicalPrimitive1D object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke" attribute of the RenderGroup of this Style object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStrokeColor(Style* style);

/// @brief Returns the value of the "stroke" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke" attribute of the GraphicalPrimitive1D object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param stroke a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& stroke);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param stroke a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& stroke);

/// @brief Sets the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param stroke a string value to use as the value of the "stroke" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeColor(Style* style, const std::string& stroke);

/// @brief Sets the value of the "stroke" attribute of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param stroke a string value to use as the value of the "stroke" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& stroke);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke-width" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke-width" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeWidth(Style* style);

/// @brief Predicates returning @c true if the "stroke-width" attribute of this GraphicalPrimitive1D is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return @c true if the "stroke-width" attribute of this GraphicalPrimitive1D object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke-width" attribute of the RenderGroup of this Style object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getStrokeWidth(Style* style);

/// @brief Returns the value of the "stroke-width" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke-width" attribute of the GraphicalPrimitive1D object, or @c 0.0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeWidth(Style* style, const double& strokeWidth);

/// @brief Sets the value of the "stroke-width" attribute of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param strokeWidth a double value to use as the value of the "stroke-width" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D, const double& strokeWidth);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject is set.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return @c true if the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of the RenderGroup of this Style object is set.
/// @param style a pointer to the Style object.
/// @return @c true if the "stroke-dasharray" attribute of the RenderGroup of this Style object is set, @c false if either the "stroke-width"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeDashArray(Style* style);

/// @brief Predicates returning @c true if the "stroke-dasharray" attribute of this GraphicalPrimitive1D is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return @c true if the "stroke-dasharray" attribute of this GraphicalPrimitive1D object is set, @c false if either the "stroke-dasharray"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or an empty vector if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::vector<unsigned int> getStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the value of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject, or an empty vector if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::vector<unsigned int> getStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the value of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the "stroke-dasharray" attribute of the RenderGroup of this Style object, or an empty vector if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::vector<unsigned int> getStrokeDashArray(Style* style);

/// @brief Returns the vector of the "stroke-dasharray" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or an empty vector if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeDashArray(Style* style, const std::vector<unsigned int>& strokeDashArray);

/// @brief Sets the value of the "stroke-dasharray" of this GraphicalPrimitive1D object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param strokeDashArray a vector to use as the value  of the "stroke-dasharray" attribute of this GraphicalPrimitive1D object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray);

/// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param graphicalObject a pointer to the GraphicalObject object.
/// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumStrokeDashes(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject);

/// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject.
/// @param renderInformationBase a pointer to the RenderInformationBase object.
/// @param attribute the attribute (id, role, type) of a GraphicalObject.
/// @return the size of the "stroke-dasharray" attribute of the RenderGroup of the Style for this GraphicalObject, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumStrokeDashes(RenderInformationBase* renderInformationBase, const std::string& attribute);

/// @brief Returns the size of the "stroke-dasharray" attribute of the RenderGroup of this Style object.
/// @param style a pointer to the Style object.
/// @return the size of the "stroke-dasharray" attribute of the RenderGroup of this Style object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumStrokeDashes(Style* style);

/// @brief Returns the size of the "stroke-dasharray" attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @return the size of "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumStrokeDashes(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the dash at the given index of the 'stroke-dasharray' attribute of this GraphicalPrimitive1D.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D object.
/// @param n an unsigned int representing the index of the dash to retrieve.
/// @return the dash at the given index of "stroke-dasharray" attribute of the GraphicalPrimitive1D object, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getDash(GraphicalPrimitive1D* graphicalPrimitive1D, unsigned  int n);

/// @brief Predicates returning @c true if the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "stroke"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetFontColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "stroke" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getFontColor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontColor a string value to use as the value of the "stroke" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setFontColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontColor);

/// @brief Predicates returning @c true if the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-family"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-family" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontFamily a string value to use as the value of the "font-family" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontFamily);

/// @brief Predicates returning @c true if the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-size"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetFontSize(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-size" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getFontSize(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontFamily a string value to use as the value of the "font-size" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setFontSize(GraphicalPrimitive1D* graphicalPrimitive1D, const RelAbsVector& fontSize);

/// @brief Predicates returning @c true if the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-weight"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-weight" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "font-weight" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontWeight);

/// @brief Predicates returning @c true if the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "font-style"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "font-style" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "font-style" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontStyle);

/// @brief Predicates returning @c true if the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "text-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "text-anchor" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param fontWeight a string value to use as the value of the "text-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& textAnchor);

/// @brief Predicates returning @c true if the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) is set.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return @c true if the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object is set, @c false if either the "vtext-anchor"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Returns the value of the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup).
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return the "vtext-anchor" attribute of the GraphicalPrimitive1D (Text or RenderGroup) object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D);

/// @brief Sets the value of the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param graphicalPrimitive1D a pointer to the GraphicalPrimitive1D (Text or RenderGroup) object.
/// @param vtextAnchor a string value to use as the value of the "vtext-anchor" attribute of this GraphicalPrimitive1D (Text or RenderGroup) object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& vtextAnchor);

/// @brief Predicates returning @c true if the "fill" attribute of this GraphicalPrimitive2D is set.
/// @param graphicalPrimitive2D a pointer to the GraphicalPrimitive2D object.
/// @return @c true if the "fill" attribute of this GraphicalPrimitive2D object is set, @c false if either the "fill"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetFillColor(GraphicalPrimitive2D* graphicalPrimitive2D);

/// @brief Returns the value of the "fill" attribute of this GraphicalPrimitive2D.
/// @param graphicalPrimitive2D a pointer to the GraphicalPrimitive2D object.
/// @return the "fill" attribute of the GraphicalPrimitive2D object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getFillColor(GraphicalPrimitive2D* graphicalPrimitive2D);

/// @brief Sets the value of the "fill" attribute of this GraphicalPrimitive2D object.
/// @param graphicalPrimitive2D a pointer to the GraphicalPrimitive2D object.
/// @param fill a string value to use as the value of the "fill" attribute of this GraphicalPrimitive2D object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setFillColor(GraphicalPrimitive2D* graphicalPrimitive2D, const std::string& fill);

/// @brief Returns Get the number of Transformation2D objects in this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the number of Transformation2D objects in this RenderGroup, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumGeometricShapes(RenderGroup* renderGroup);

/// @brief Returns the Transformation2D at the given index of the this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param n an unsigned int representing the index of the Transformation2D to retrieve.
/// @return the Transformation2D at the given index of the RenderGroup object, or NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN Transformation2D* getGeometricShape(RenderGroup* renderGroup, unsigned  int n);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Rectangle.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Rectangle, @c false if either it is not of type Rectangle or is or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isRectangle(Transformation2D* shape);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Ellipse.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Ellipse, @c false if either it is not of type Ellipse or is or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isEllipse(Transformation2D* shape);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Polygon.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Polygon, @c false if either it is not of type Polygon or is or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isPolygon(Transformation2D* shape);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type RenderCurve.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type RenderCurve, @c false if either it is not of type RenderCurve or is or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isRenderCurve(Transformation2D* shape);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Image.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Image, @c false if either it is not of type Image or is or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isImage(Transformation2D* shape);

/// @brief Predicates returning @c true if this abstract Transformation2D is of type Text.
/// @param shape a pointer to the Transformation2D object.
/// @return @c true if this abstract Transformation2D is of type Text, @c false if either it is not of type Text or is or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isText(Transformation2D* shape);

/// @brief Predicates returning @c true if the "x" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "x" attribute of this Rectangle object is set, @c false if either the "x" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeX(Rectangle* rectangle);

/// @brief Returns the value of the "x" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "x" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRectangleShapeX(Rectangle* rectangle);

/// @brief Sets the value of the "x" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeX(Rectangle* rectangle, const RelAbsVector& x);

/// @brief Predicates returning @c true if the "y" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "y" attribute of this Rectangle object is set, @c false if either the "y" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeY(Rectangle* rectangle);

/// @brief Returns the value of the "y" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "y" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRectangleShapeY(Rectangle* rectangle);

/// @brief Sets the value of the "y" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeY(Rectangle* rectangle, const RelAbsVector& y);

/// @brief Predicates returning @c true if the "width" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "width" attribute of this Rectangle object is set, @c false if either the "width" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeWidth(Rectangle* rectangle);

/// @brief Returns the value of the "width" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "width" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRectangleShapeWidth(Rectangle* rectangle);

/// @brief Sets the value of the "width" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeWidth(Rectangle* rectangle, const RelAbsVector& width);

/// @brief Predicates returning @c true if the "height" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "height" attribute of this Rectangle object is set, @c false if either the "height" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeHeight(Rectangle* rectangle);

/// @brief Returns the value of the "height" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "height" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRectangleShapeHeight(Rectangle* rectangle);

/// @brief Sets the value of the "height" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeHeight(Rectangle* rectangle, const RelAbsVector& height);

/// @brief Predicates returning @c true if the "ratio" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "ratio" attribute of this Rectangle object is set, @c false if either the "ratio" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeRatio(Rectangle* rectangle);

/// @brief Returns the value of the "ratio" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "ratio" attribute of the Rectangle object, or @c "0.0" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getRectangleShapeRatio(Rectangle* rectangle);

/// @brief Sets the value of the "ratio" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param ratio a double value to use as the value of the "ratio" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeRatio(Rectangle* rectangle, const double& ratio);

/// @brief Predicates returning @c true if the "rx" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "rx" attribute of this Rectangle object is set, @c false if either the "rx" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeRX(Rectangle* rectangle);

/// @brief Returns the value of the "rx" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "rx" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRectangleShapeRX(Rectangle* rectangle);

/// @brief Sets the value of the "rx" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeRX(Rectangle* rectangle, const RelAbsVector& rx);

/// @brief Predicates returning @c true if the "ry" attribute of this Rectangle is set.
/// @param rectangle a pointer to the Rectangle object.
/// @return @c true if the "ry" attribute of this Rectangle object is set, @c false if either the "ry" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRectangleShapeRY(Rectangle* rectangle);

/// @brief Returns the value of the "ry" attribute of this Rectangle.
/// @param rectangle a pointer to the Rectangle object.
/// @return the "ry" attribute of the Rectangle object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRectangleShapeRY(Rectangle* rectangle);

/// @brief Sets the value of the "ry" attribute of this Rectangle object.
/// @param rectangle a pointer to the Rectangle object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Rectangle object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRectangleShapeRY(Rectangle* rectangle, const RelAbsVector& ry);

/// @brief Predicates returning @c true if the "cx" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "cx" attribute of this Ellipse object is set, @c false if either the "cx" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEllipseShapeCX(Ellipse* ellipse);

/// @brief Returns the value of the "cx" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "cx" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getEllipseShapeCX(Ellipse* ellipse);

/// @brief Sets the value of the "cx" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEllipseShapeCX(Ellipse* ellipse, const RelAbsVector& cx);

/// @brief Predicates returning @c true if the "cy" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "cy" attribute of this Ellipse object is set, @c false if either the "cy" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEllipseShapeCY(Ellipse* ellipse);

/// @brief Returns the value of the "cy" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "cy" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getEllipseShapeCY(Ellipse* ellipse);

/// @brief Sets the value of the "cy" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEllipseShapeCY(Ellipse* ellipse, const RelAbsVector& cy);

/// @brief Predicates returning @c true if the "rx" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "rx" attribute of this Ellipse object is set, @c false if either the "rx" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEllipseShapeRX(Ellipse* ellipse);

/// @brief Returns the value of the "rx" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "rx" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getEllipseShapeRX(Ellipse* ellipse);

/// @brief Sets the value of the "rx" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param rx a RelAbsVector to use as the value of the "rx" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEllipseShapeRX(Ellipse* ellipse, const RelAbsVector& rx);

/// @brief Predicates returning @c true if the "ry" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "ry" attribute of this Ellipse object is set, @c false if either the "ry" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEllipseShapeRY(Ellipse* ellipse);

/// @brief Returns the value of the "ry" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "ry" attribute of the Ellipse object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getEllipseShapeRY(Ellipse* ellipse);

/// @brief Sets the value of the "ry" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param ry a RelAbsVector to use as the value of the "ry" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEllipseShapeRY(Ellipse* ellipse, const RelAbsVector& ry);

/// @brief Predicates returning @c true if the "ratio" attribute of this Ellipse is set.
/// @param ellipse a pointer to the Ellipse object.
/// @return @c true if the "ratio" attribute of this Ellipse object is set, @c false if either the "ratio" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEllipseShapeRatio(Ellipse* ellipse);

/// @brief Returns the value of the "ratio" attribute of this Ellipse.
/// @param ellipse a pointer to the Ellipse object.
/// @return the "ratio" attribute of the Ellipse object, or @c "0.0" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const double getEllipseShapeRatio(Ellipse* ellipse);

/// @brief Sets the value of the "ratio" attribute of this Ellipse object.
/// @param ellipse a pointer to the Ellipse object.
/// @param ratio a double value to use as the value of the "ratio" attribute of this Ellipse object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEllipseShapeRatio(Ellipse* ellipse, const double& ratio);

/// @brief Returns the number of elements of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @return the number of elements of the Polygon object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getPolygonShapeNumElements(Polygon* polygon);

/// @brief Returns the value of the "x" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeElementX(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "x" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeElementX(Polygon* polygon, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeElementY(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeElementY(Polygon* polygon, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 1 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 1 of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 2 of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth element of this Polygon.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 2 of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeElementX(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeElementX(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the nth element of Polygon object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeElementY(Polygon* polygon, unsigned  int n);

/// @brief Sets the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of nth element of this Polygon.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeElementY(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of the nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 2 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of the nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of the nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of he base point 2 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getPolygonShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setPolygonShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Predicate returning true if the nth element of this Polygon is of type RenderCubicBezier.
/// @param polygon a pointer to the Polygon object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return @c true if the nth element of this Polygon is of type RenderCubicBezier, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRenderCubicBezier(Polygon* polygon, unsigned  int n);

/// @brief Returns the number of elements of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @return the number of elements of the RenderCurve object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getRenderCurveShapeNumElements(RenderCurve* renderCurve);

/// @brief Returns the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 1 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 1 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Returns the value of the "x" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "x" attribute of the base point 1 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "x" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "x" attribute of the base point 2 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x);

/// @brief Returns the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return the "y" attribute of the base point 2 of the nth element of RenderCurve object, or @c RelAbsVector() if the
/// object is @c NULL or it has less than n elements
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n);

/// @brief Sets the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @param x a RelAbsVector to use as the value of the "y" attribute of the base point 2 of nth element of this RenderCurve.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y);

/// @brief Predicate returning true if the nth element of this RenderCurve is of type RenderCubicBezier.
/// @param renderCurve a pointer to the RenderCurve object.
/// @param n an unsigned int representing the index of the element to retrieve.
/// @return @c true if the nth element of this RenderCurve is of type RenderCubicBezier, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRenderCubicBezier(RenderCurve* renderCurve, unsigned  int n);

/// @brief Predicate returning true if this RenderCurve is of type RenderCubicBezier.
/// @param renderPoint a pointer to the RenderPoint object.
/// @return @c true if this RenderPoint is of type RenderCubicBezier, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRenderCubicBezier(RenderPoint* renderPoint);

/// @brief Predicates returning @c true if the "x" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "x" attribute of this Image object is set, @c false if either the "x" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetImageShapeX(Image* image);

/// @brief Returns the value of the "x" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "x" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getImageShapeX(Image* image);

/// @brief Sets the value of the "x" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setImageShapeX(Image* image, const RelAbsVector& x);

/// @brief Predicates returning @c true if the "y" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "y" attribute of this Image object is set, @c false if either the "y" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetImageShapeY(Image* image);

/// @brief Returns the value of the "y" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "y" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getImageShapeY(Image* image);

/// @brief Sets the value of the "y" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setImageShapeY(Image* image, const RelAbsVector& y);

/// @brief Predicates returning @c true if the "width" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "width" attribute of this Image object is set, @c false if either the "width" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetImageShapeWidth(Image* image);

/// @brief Returns the value of the "width" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "width" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getImageShapeWidth(Image* image);

/// @brief Sets the value of the "width" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param width a RelAbsVector to use as the value of the "width" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setImageShapeWidth(Image* image, const RelAbsVector& width);

/// @brief Predicates returning @c true if the "height" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "height" attribute of this Image object is set, @c false if either the "height" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetImageShapeHeight(Image* image);

/// @brief Returns the value of the "height" attribute of this Image.
/// @param image a pointer to the Image object.
/// @return the "height" attribute of the Image object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getImageShapeHeight(Image* image);

/// @brief Sets the value of the "height" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param height a RelAbsVector to use as the value of the "height" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setImageShapeHeight(Image* image, const RelAbsVector& height);

/// @brief Predicates returning @c true if the "href" attribute of this Image is set.
/// @param image a pointer to the Image object.
/// @return @c true if the "href" attribute of this Image object is set, @c false if either the "href" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetImageShapeHref(Image* image);

/// @brief Returns the value of the "href" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @return the "href" attribute of the Image object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getImageShapeHref(Image* image);

/// @brief Sets the value of the "href" attribute of this Image object.
/// @param image a pointer to the Image object.
/// @param stroke a string value to use as the value of the "image" attribute of this Image object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setImageShapeHref(Image* image, const std::string& href);

/// @brief Predicates returning @c true if the "x" attribute of this Text is set.
/// @param text a pointer to the Text object.
/// @return @c true if the "x" attribute of this Text object is set, @c false if either the "x" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetTextShapeX(Text* text);

/// @brief Returns the value of the "x" attribute of this Text.
/// @param text a pointer to the Text object.
/// @return the "x" attribute of the Text object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getTextShapeX(Text* text);

/// @brief Sets the value of the "x" attribute of this Text object.
/// @param text a pointer to the Text object.
/// @param x a RelAbsVector to use as the value of the "x" attribute of this Text object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setTextShapeX(Text* text, const RelAbsVector& x);

/// @brief Predicates returning @c true if the "y" attribute of this Text is set.
/// @param text a pointer to the Text object.
/// @return @c true if the "y" attribute of this Text object is set, @c false if either the "y" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetTextShapeY(Text* text);

/// @brief Returns the value of the "y" attribute of this Text.
/// @param text a pointer to the Text object.
/// @return the "y" attribute of the Text object, or @c RelAbsVector() if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getTextShapeY(Text* text);

/// @brief Sets the value of the "y" attribute of this Text object.
/// @param text a pointer to the Text object.
/// @param y a RelAbsVector to use as the value of the "y" attribute of this Text object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setTextShapeY(Text* text, const RelAbsVector& y);

/// @brief Add a geometric shape to this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param shape a string value indicating the shape of the geometric shape to be added.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addGeometricShape(RenderGroup* renderGroup, const std::string& shape);

/// @brief Remove a geometric shape from this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param n an unsigned int representing the index of the Transformation2D to remove.
/// @return a pointer to the nth Transformation2D in this RenderGroup.
LIBSBML_NETWORKEDITOR_EXTERN int addGeometricShape(RenderGroup* renderGroup, const std::string& shape);

/// @brief Add a render point to this Transformation2d (Polygon or RenderCurve).
/// @param shape a pointer to the Transformation2d object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addRenderPointToShape(Transformation2D* shape);

/// @brief Add a render cubic bezier to this Transformation2d (Polygon or RenderCurve).
/// @param shape a pointer to the Transformation2d object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addRenderCubicBezierToShape(Transformation2D* shape);

/// @brief Remove an element from this Transformation2d (Polygon or RenderCurve).
/// @param shape a pointer to the Transformation2d object.
/// @param n an unsigned int representing the index of the RenderPoint to remove.
/// @return a pointer to the nth RenderPoint in this Transformation2d.
LIBSBML_NETWORKEDITOR_EXTERN RenderPoint * removeElementFromShape(Transformation2D* shape, unsigned int n);

/// @brief Predicates returning @c true if the "startHead" attribute of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return @c true if the "startHead" attribute of this RenderGroup object is set, @c false if either the "startHead" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStartHead(RenderGroup* renderGroup);

/// @brief Returns the value of the "startHead" attribute of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "startHead" attribute of the RenderGroup object, or empty string if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStartHead(RenderGroup* renderGroup);

/// @brief Sets the value of the "startHead" attribute of this RenderGroup object.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param startHead a boolean to use as the value of the "startHead" attribute of this RenderGroup object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStartHead(RenderGroup* renderGroup, const std::string startHead);

/// @brief Predicates returning @c true if the "endHead" attribute of this RenderGroup is set.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return @c true if the "endHead" attribute of this RenderGroup object is set, @c false if either the "endHead" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEndHead(RenderGroup* renderGroup);

/// @brief Returns the value of the "endHead" attribute of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "endHead" attribute of the RenderGroup object, or empty string if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getEndHead(RenderGroup* renderGroup);

/// @brief Sets the value of the "endHead" attribute of this RenderGroup object.
/// @param renderGroup a pointer to the RenderGroup object.
/// @param endHead a boolean to use as the value of the "endHead" attribute of this RenderGroup object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEndHead(RenderGroup* renderGroup, const std::string endHead);

/// @brief Returns the value of the "endHead" attribute of this RenderGroup.
/// @param renderGroup a pointer to the RenderGroup object.
/// @return the "objetRole" attribute of the GraphicalObject object, or @c false if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getObjectRole(GraphicalObject* graphicalObject);

}

#endif

