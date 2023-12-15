#ifndef __LIBSBML_NE_UTIL_H_
#define __LIBSBML_NE_UTIL_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

/// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
/// to the the SBML document, and set all the necessary features for them.
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int autolayoutWithDefaultParameters(SBMLDocument* document);

/// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
/// to the the SBML document, and set all the necessary features for them.
/// @param document a pointer to the SBMLDocument object.
/// @param stiffness the stiffness value used in the autolayout algorithm.
/// @param gravity the gravity value used in the autolayout algorithm.
/// @param useMagnetism a variable that determines whether to use magnetism in the autolayout algorithm.
/// @param useBoundary a variable that determines whether to use boundary restriction in the autolayout algorithm.
/// @param useGrid a variable that determines whether to use grid restriction in the autolayout algorithm.
/// @return integer value indicating success/failure of the function.
    LIBSBML_NETWORKEDITOR_EXTERN int
    autolayout(SBMLDocument* document, const double stiffness = 10.0, const double gravity = 15.0, const bool useMagnetism = false,
               const bool useBoundary = false, const bool useGrid = false);

/// @brief Returns a pointer to the Compartment object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Compartment object
/// @return a pointer to the Compartment object with the given id, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN Compartment *getCompartment(SBMLDocument *document, const char* id);

/// @brief Returns a pointer to the Species object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Species object.
/// @return a pointer to the Species object with the given id, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN Species *getSpecies(SBMLDocument *document, const char* id);

/// @brief Returns a pointer to the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Reaction object.
/// @return a pointer to the Reaction object with the given id, or @c "" if the object does not exists.
    LIBSBML_NETWORKEDITOR_EXTERN Reaction *getReaction(SBMLDocument *document, const char* id);

/// @brief Returns a pointer to the SpeciesReference object associated with the given reactant/product species id in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param speciesId the id of the Species object.
/// @return a pointer to the SpeciesReference object, or @c NULL if the object does not exists or is not of type reactant/product.
    LIBSBML_NETWORKEDITOR_EXTERN SpeciesReference *
    getSpeciesReference(SBMLDocument *document, const char* reactionId, const char* speciesId);

/// @brief Returns a pointer to the ModifierSpeciesReference object associated with the given modifier species id in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param speciesId the id of the Species object.
/// @return a pointer to the ModifierSpeciesReference object, or @c NULL if the object does not exists or is not of type modifier.
    LIBSBML_NETWORKEDITOR_EXTERN ModifierSpeciesReference *
    getModifierSpeciesReference(SBMLDocument *document, const char* reactionId, const char* speciesId);

#ifdef __cplusplus
}
#endif

}

#endif