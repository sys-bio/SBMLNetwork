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

/// @brief Predicate returning true if the abstract GradientBase with the given identifier of all RenderInformationBase objects of SBML document is of type LinearGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isLinearGradient(SBMLDocument* document, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier of the RenderInformationBase object with the given index of the SBML document is of type LinearGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type LinearGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isLinearGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier of all RenderInformationBase objects of SBML document is of type RadialGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRadialGradient(SBMLDocument* document, const std::string& sid);

/// @brief Predicate returning true if the abstract GradientBase with the given identifier of the RenderInformationBase object with the given index of SBML document is of type RadialGradient.
/// @param document a pointer to the SBMLDocument object.
/// @param renderIndex the index number of the RenderInformationBase object.
/// @param sid a string representing the identifier of the GradientBase to retrieve.
/// @return @c true if this abstract GradientBase is of type RadialGradient, false otherwise
LIBSBML_NETWORKEDITOR_EXTERN bool isRadialGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid);

}

#endif