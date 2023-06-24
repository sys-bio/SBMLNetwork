#ifndef __LIBSBML_NE_UTIL_RENDER_H_
#define __LIBSBML_NE_UTIL_RENDER_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

/// @brief Get the List of global render Information of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return a pointer to the ListOfRenderInformationBase object of the SBML document.
LIBSBML_NETWORKEDITOR_EXTERN ListOfGlobalRenderInformation* getListOfGlobalRenderInformation(SBMLDocument* document);

/// @brief Returns the number of items in the ListOfGlobalRenderInformation of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of items in the ListOfGlobalRenderInformation of the SBML document, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGlobalRenderInformation(SBMLDocument* document);

/// @brief Returns a pointer to the GlobalRenderInformation with the given index in the ListOfGlobalRenderInformation of the SBML document.
/// @param renderIndex the index number of the GlobalRenderInformation to return.
/// @return the @c the nth GlobalRenderInformation in the ListOfGlobalRenderInformation of the SBML document or NULL if
/// no such GlobalRenderInformation exists or the document is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN GlobalRenderInformation* getGlobalRenderInformation(SBMLDocument* document, unsigned int renderIndex = 0);

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

/// @brief Get the List of local render Information of the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @return a pointer to the ListOfGlobalInformationBase object of this Layout object.
LIBSBML_NETWORKEDITOR_EXTERN ListOfLocalRenderInformation* getListOfLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns the number of items in the ListOfGlobalRenderInformation of the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @return the number of items in the ListOfGlobalRenderInformation of this Layout object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Returns a pointer to the LocalRenderInformation object with the given index in the ListOfLocalRenderInformation of
/// the layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @param renderIndex the index number of the GlobalRenderInformation to return.
/// @return the @c the LocalRenderInformation with the given index in the ListOfLocalRenderInformation of this Layout object or NULL if
/// no such LocalRenderInformation exists or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* getLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int renderIndex = 0);

/// @brief Add LocalRenderInformation to the list of local renders of the first Layout of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addLocalRenderInformation(SBMLDocument* document, LocalRenderInformation* localRenderInformation);

/// @brief Add LocalRenderInformation to list of local renders of the Layout with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int addLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation);

/// @brief Create a LocalRenderInformation object and add it to list of local renders of the Layout with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @return a pointer to the created LocalRenderInformation object.
LIBSBML_NETWORKEDITOR_EXTERN LocalRenderInformation* createLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Remove all the local render information objects from the list of local renders of the Layout with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int removeAllLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0);

/// @brief Set all the necessary features for the local render information object in the first Layout object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, LocalRenderInformation* localRenderInformation);

/// @brief Set all the necessary features for the local render information object in the Layout object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param layoutIndex the index number of the Layout object.
/// @param localRenderInformation a pointer to the LocalRenderInformation object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation);

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

/// @brief Predicates returning @c true if the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the GlobalRenderInformation object.
/// @return @c true if the "backgroundColor" attribute of this GlobalRenderInformation object is set, @c false if either the "backgroundColor"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetBackgroundColor(SBMLDocument* document, unsigned int renderIndex = 0);

/// @brief Returns the value of the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the GlobalRenderInformation object.
/// @return the "backgroundColor" attribute of this RenderInformationBase object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getBackgroundColor(SBMLDocument* document, unsigned int renderIndex = 0);

/// @brief Sets the value of the "backgroundColor" attribute of the first GlobalRenderInformation object.
/// @param document a pointer to the SBMLDocument object.
/// @param backgroundColor a string value to use as the value of the "backgroundColor" attribute of this RenderInformationBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setBackgroundColor(SBMLDocument* document, const std::string& backgroundColor);

/// @brief Sets the value of the "backgroundColor" attribute of the GlobalRenderInformation object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the GlobalRenderInformation object.
/// @param backgroundColor a string value to use as the value of the "backgroundColor" attribute of this RenderInformationBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setBackgroundColor(SBMLDocument* document, unsigned int renderIndex, const std::string& backgroundColor);

/// @brief Returns the number of ColorDefinitions of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @return the number of ColorDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumColorDefinitions(SBMLDocument* document, unsigned int renderIndex = 0);

/// @brief Returns a ColorDefinition from all RenderInformationBase objects of the SBML document based on its identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the @c ColorDefinition in the ListOfColorDefinitions within this RenderInformationBase with the given sid or @c NULL if no such ColorDefinition exists.
LIBSBML_NETWORKEDITOR_EXTERN ColorDefinition* getColorDefinition(SBMLDocument* document, const std::string& sid);

/// @brief Returns a ColorDefinition from the RenderInformationBase object with the given index of the SBML document based on its identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the @c ColorDefinition in the ListOfColorDefinitions within this RenderInformationBase with the given sid or @c NULL if no such ColorDefinition exists.
LIBSBML_NETWORKEDITOR_EXTERN ColorDefinition* getColorDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns a pointer to the ColorDefinition with the given index of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param colorIndex the index value of the ColorDefinition to return.
/// @return the @c ColorDefinition with the given index, or NULL if ColorDefinition does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN ColorDefinition* getColorDefinition(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int colorIndex = 0);

/// @brief Predicates returning @c true if the "value" attribute of the ColorDefinition with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetValue(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "value" attribute of the ColorDefinition with the given identifier
/// in the RenderInformationBase with the given index is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return @c true if the "value" attribute of this ColorDefinition object is set, @c false if either the "value"
/// attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "value" attribute of the ColorDefinition with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getValue(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "value" attribute of the ColorDefinition with the given identifier in the RenderInformationBase with the given index.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @return the "value" attribute of the ColorDefinition object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "value" attribute of the ColorDefinition with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setValue(SBMLDocument* document, const std::string& sid, const std::string& value);

/// @brief Sets the value of the "value" attribute of the ColorDefinition with the given identifier in the RenderInformationBase with the given index.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the ColorDefinition to retrieve.
/// @param value a string value to use as the value of the "value" attribute of this ColorDefinition object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& value);

/// @brief Returns the number of GradientDefinitions of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @return the number of GradientDefinitions of this RenderInformationBase object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumGradientDefinitions(SBMLDocument* document, unsigned int renderIndex = 0);

/// @brief Returns a GradientBase from all the RenderInformationBase objects of the SBML document based on its identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the @c GradientBase in the ListOfGradientDefinitions within all RenderInformationBase objects with the given sid or @c NULL if no such GradientBase exists.
LIBSBML_NETWORKEDITOR_EXTERN GradientBase* getGradientDefinition(SBMLDocument* document, const std::string& sid);

/// @brief Returns a GradientBase from the RenderInformationBase object with the given index of the SBML document based on its identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the @c GradientBase in the ListOfGradientDefinitions within this RenderInformationBase with the given sid or @c NULL if no such GradientBase exists.
LIBSBML_NETWORKEDITOR_EXTERN GradientBase* getGradientDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns a pointer to the GradientBase with the given index of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param gradientIndex the index value of the GradientBase to return.
/// @return the @c GradientBase with the given index, or NULL if GradientBase does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN GradientBase* getGradientDefinition(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int gradientIndex = 0);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier in all RenderInformationBase objects of SBML document is of type LinearGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isLinearGradient(SBMLDocument* document, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier in the RenderInformationBase object with the given index of the SBML document is of type LinearGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isLinearGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier in all RenderInformationBase objects of SBML document with the given identifier is of type RadialGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRadialGradient(SBMLDocument* document, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier in the RenderInformationBase object with the given index of SBML document is of type RadialGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRadialGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Predicates returning @c true if the "spreadMethod" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "spreadMethod" attribute of this GradientBase object is set, @c false if either the "spreadMethod"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetSpreadMethod(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "spreadMethod" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "spreadMethod" attribute of this GradientBase object is set, @c false if either the "spreadMethod"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "spreadMethod" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "spreadMethod" attribute of the GradientBase object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpreadMethod(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "spreadMethod" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "spreadMethod" attribute of the GradientBase object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "spreadMethod" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setSpreadMethod(SBMLDocument* document, const std::string& sid, const std::string& spreadMethod);

/// @brief Sets the value of the "spreadMethod" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param spreadMethod a string value to use as the value of the "spreadMethod" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& spreadMethod);

/// @brief Returns Get the number of GradientStop objects in the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the number of GradientStop objects in this GradientBase, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumGradientStops(SBMLDocument* document, const std::string& sid);

/// @brief Returns Get the number of GradientStop objects in the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the number of GradientStop objects in this GradientBase, or 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN unsigned int getNumGradientStops(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the GradientStop object with the given index of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop to retrieve.
/// @return the GradientStop at the given index of the GradientBase object, or NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN GradientStop* getGradientStop(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the GradientStop object with the given index of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop to retrieve.
/// @return the GradientStop at the given index of the GradientBase object, or NULL if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN GradientStop* getGradientStop(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "offset" attribute of the GradientStop with the given index of this the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return @c true if the "offset" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if
/// either the "offset" attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "offset" attribute of the GradientStop with the given index of this the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return @c true if the "offset" attribute of the GradientStop with the given index of this GradientBase object is set, @c false if
/// either the "offset" attribute is not set or the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "offset" attribute of the GradientStop with the given index of the GradientBase object, or @c RelAbsVector() if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getOffset(SBMLDocument* document, const std::string& sid , unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "offset" attribute of the GradientStop with the given index of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "offset" attribute of the GradientStop with the given index of the GradientBase object, or @c RelAbsVector() if the object is @c NULL.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid , unsigned int gradientStopIndex = 0);

/// @brief Sets the value of the "offset" attribute of the first GradientStop of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the first GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(SBMLDocument* document, const std::string& sid, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the first GradientStop of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the first GradientStop of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the GradientStop with the given index of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset);

/// @brief Sets the value of the "offset" attribute of the GradientStop with the given index of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param offset a RelAbsVector to use as the value of the "offset" attribute of the GradientStop with the given index of this GradientStop object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset);

/// @brief Predicates returning @c true if the "stop-color" attribute of the GradientStop with the given index of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "stop-color" attribute of nth GradientStop of this GradientBase object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Predicates returning @c true if the "stop-color" attribute of the GradientStop with the given index of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "stop-color" attribute of nth GradientStop of this GradientBase object is set, @c false if either the "stop-color"
/// attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "stop-color" attribute of the GradientStop with the given index of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "stop-color" attribute of the GradientStop with the given index of this GradientStop object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Returns the value of the "stop-color" attribute of the GradientStop with the given index of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @return the "stop-color" attribute of the GradientStop with the given index of this GradientStop object, or @c "" if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const std::string getStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0);

/// @brief Sets the value of the "stop-color" attribute of the first GradientStop of this the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of the first GradientStop of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(SBMLDocument* document, const std::string& sid, const std::string& stopColor);

/// @brief Sets the value of the "stop-color" attribute of the first GradientStop of this the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of the first GradientStop of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& stopColor);

/// @brief Sets the value of the "stop-color" attribute of the GradientStop with the given index of this the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of the GradientStop with the given index of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor);

/// @brief Sets the value of the "stop-color" attribute of the GradientStop with the given index of this the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param gradientStopIndex an unsigned int representing the index of the GradientStop of this GradientBase object.
/// @param stopColor a string value to use as the value of the "stop-color" attribute of the GradientStop with the given index of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor);

/// @brief Predicates returning @c true if the "x1" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX1(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "x1" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x1" attribute of this GradientBase object is set, @c false if either the "x1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "x1" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX1(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "x1" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "x1" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x1 a RelAbsVector to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX1(SBMLDocument* document, const std::string& sid, const RelAbsVector& x1);

/// @brief Sets the value of the "x1" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x1 a RelAbsVector to use as the value of the "x1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x1);

/// @brief Predicates returning @c true if the "x2" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x2" attribute of this GradientBase object is set, @c false if either the "x2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX2(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "x2" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "x2" attribute of this GradientBase object is set, @c false if either the "x2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "x2" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX2(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "x2" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "x2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "x2" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x2 a RelAbsVector to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX2(SBMLDocument* document, const std::string& sid, const RelAbsVector& x2);

/// @brief Sets the value of the "x2" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param x2 a RelAbsVector to use as the value of the "x2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x2);

/// @brief Predicates returning @c true if the "y1" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y1" attribute of this GradientBase object is set, @c false if either the "y1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY1(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "y1" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y1" attribute of this GradientBase object is set, @c false if either the "y1" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "y1" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY1(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "y1" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y1" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "y1" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y1 a RelAbsVector to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY1(SBMLDocument* document, const std::string& sid, const RelAbsVector& y1);

/// @brief Sets the value of the "y1" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y1 a RelAbsVector to use as the value of the "y1" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y1);

/// @brief Predicates returning @c true if the "y2" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y2" attribute of this GradientBase object is set, @c false if either the "y2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY2(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "y2" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "y2" attribute of this GradientBase object is set, @c false if either the "y2" attribute is not set
/// , the object is @c NULL, or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "y2" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY2(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "y2" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "y2" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type LinearGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "y2" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y2 a RelAbsVector to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY2(SBMLDocument* document, const std::string& sid, const RelAbsVector& y2);

/// @brief Sets the value of the "y2" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param y2 a RelAbsVector to use as the value of the "y2" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y2);

/// @brief Predicates returning @c true if the "cx" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cx" attribute of this GradientBase object is set, @c false if either the "cx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCx(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "cx" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cx" attribute of this GradientBase object is set, @c false if either the "cx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "cx" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCx(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "cx" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "cx" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCx(SBMLDocument* document, const std::string& sid, const RelAbsVector& cx);

/// @brief Sets the value of the "cx" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cx a RelAbsVector to use as the value of the "cx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cx);

/// @brief Predicates returning @c true if the "cy" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cy" attribute of this GradientBase object is set, @c false if either the "cy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCy(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "cy" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "cy" attribute of this GradientBase object is set, @c false if either the "cy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "cy" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCy(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "cy" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "cy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "cy" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCy(SBMLDocument* document, const std::string& sid, const RelAbsVector& cy);

/// @brief Sets the value of the "cy" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param cy a RelAbsVector to use as the value of the "cy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cy);

/// @brief Predicates returning @c true if the "fx" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fx" attribute of this GradientBase object is set, @c false if either the "fx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFx(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "fx" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fx" attribute of this GradientBase object is set, @c false if either the "fx" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "fx" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFx(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "fx" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fx" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "fx" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fx a RelAbsVector to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFx(SBMLDocument* document, const std::string& sid, const RelAbsVector& fx);

/// @brief Sets the value of the "fx" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fx a RelAbsVector to use as the value of the "fx" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fx);

/// @brief Predicates returning @c true if the "fy" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fy" attribute of this GradientBase object is set, @c false if either the "fy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFy(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "fy" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "fy" attribute of this GradientBase object is set, @c false if either the "fy" attribute is not set
/// , the object is @c NULL, or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "fy" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFy(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "fy" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "fy" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "fy" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fy a RelAbsVector to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFy(SBMLDocument* document, const std::string& sid, const RelAbsVector& fy);

/// @brief Sets the value of the "fy" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param fy a RelAbsVector to use as the value of the "fy" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fy);

/// @brief Predicates returning @c true if the "r" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "r" attribute of this GradientBase object is set, @c false if either the "r" attribute is not set
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientR(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "r" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if the "r" attribute of this GradientBase object is set, @c false if either the "r" attribute is not set
LIBSBML_NETWORKEDITOR_EXTERN bool isSetRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "r" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "r" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientR(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "r" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return the "r" attribute of the GradientBase object, or @c RelAbsVector() if the object is @c NULL or not of type RadialGradient.
LIBSBML_NETWORKEDITOR_EXTERN const RelAbsVector getRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "r" attribute of the GradientBase in all RenderInformationBase objects of SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param r a RelAbsVector to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientR(SBMLDocument* document, const std::string& sid, const RelAbsVector& r);

/// @brief Sets the value of the "r" attribute of the GradientBase in the RenderInformationBase with the given index of the SBML document with the given identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @param r a RelAbsVector to use as the value of the "r" attribute of this GradientBase object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& r);

/// @brief Returns the number of LineEndings of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @return the number of LineEndings of this RenderInformationBase object, or @c 0 if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN const unsigned int getNumLineEndings(SBMLDocument* document, unsigned int renderIndex = 0);

/// @brief Returns a LineEnding from all the RenderInformationBase objects of the SBML document based on its identifier.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the @c LineEnding in the ListOfLineEndings within this RenderInformationBase with the given sid or @c NULL if no such LineEnding exists.
LIBSBML_NETWORKEDITOR_EXTERN LineEnding* getLineEnding(SBMLDocument* document, const std::string& sid);

/// @brief Returns a LineEnding from the RenderInformationBase object with the given index of the SBML document based on its identifier.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the @c LineEnding in the ListOfLineEndings within this RenderInformationBase with the given sid or @c NULL if no such LineEnding exists.
LIBSBML_NETWORKEDITOR_EXTERN LineEnding* getLineEnding(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns a pointer to the LineEnding with the given index of the RenderInformationBase object with given index of the SBML document the given index.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param lineEndingIndex the index value of the LineEnding to return.
/// @return the @c LineEnding with the given index, or NULL if LineEnding does not exist or the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN LineEnding* getLineEnding(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int lineEndingIndex = 0);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of the LineEnding with the given identifier
/// of the first RenderInformationBase object of the SBML document is set.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEnableRotationalMapping(SBMLDocument* document, const std::string& sid);

/// @brief Predicates returning @c true if the "enableRotationalMapping" attribute of the LineEnding with the given identifier
/// of the RenderInformationBase object with the given index of the SBML document is set.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return @c true if the "enableRotationalMapping" attribute of this LineEnding object is set, @c false if either the "enableRotationalMapping" attribute is not set or the object is @c NULL .
LIBSBML_NETWORKEDITOR_EXTERN bool isSetEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Returns the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier
/// of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN bool getEnableRotationalMapping(SBMLDocument* document, const std::string& sid);

/// @brief Returns the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier
/// of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @return the "enableRotationalMapping" attribute of the LineEnding object, or @c false if the object is @c NULL
LIBSBML_NETWORKEDITOR_EXTERN bool getEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Sets the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier
/// of the first RenderInformationBase object of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEnableRotationalMapping(SBMLDocument* document, const std::string& sid, bool enableRotationalMapping);

/// @brief Sets the value of the "enableRotationalMapping" attribute of the LineEnding with the given identifier
/// of the RenderInformationBase object with the given index of the SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the LineEnding to retrieve.
/// @param enableRotationalMapping a boolean to use as the value of the "enableRotationalMapping" attribute of this LineEnding object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int setEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, bool enableRotationalMapping);


}

#endif