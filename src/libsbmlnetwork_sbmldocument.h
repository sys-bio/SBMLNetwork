#ifndef __LIBSBMLNETWORK_SBML_DOCUMENT_H_
#define __LIBSBMLNETWORK_SBML_DOCUMENT_H_

#include "libsbmlnetwork_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/common/libsbml-namespace.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

#include "sbml/common/libsbml-namespace.h"

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

/// @brief Returns the version of the library.
/// @return the version of the library.
LIBSBMLNETWORK_EXTERN const std::string getVersion();

/// @brief Returns the current directory of the library.
/// @return the current directory of the library.
LIBSBMLNETWORK_EXTERN const std::string getCurrentDirectoryOfLibrary();

/// @brief Reads an SBML document from the given file name or the given text string
/// @param sbml either the name or full pathname of the file to be read or a string containing a full SBML model.
/// @return a pointer to the SBMLDocument structure created from the SBML content in the given file name or
/// from the SBML content in the given text string.
LIBSBMLNETWORK_EXTERN SBMLDocument* readSBML(const std::string &sbml);

/// @brief Writes the given SBML document to a filename.
/// @param document the SBML document to be written.
/// @param fileName the name or full pathname of the file where the SBML is to be written.
/// @return true on success and false if the filename could not be opened for writing.
LIBSBMLNETWORK_EXTERN bool writeSBML(SBMLDocument* document, const std::string &fileName);

/// @brief Writes the given SBML document to a string and returns it.
/// @param document the SBML document to be written.
/// @return the string on success and empty string if one of the underlying parser components fail.
LIBSBMLNETWORK_EXTERN const std::string writeSBML(SBMLDocument* document);

/// @brief Returns the SBML Level of the SBMLDocument object containing this object.
/// @param document a pointer to the SBMLDocument object.
/// @return the SBML Level of the SBMLDocument object containing this object.
LIBSBMLNETWORK_EXTERN const unsigned int getSBMLLevel(const SBMLDocument* document);

/// @brief Returns the Version within the SBML Level of the SBMLDocument object containing this object.
/// @param document a pointer to the SBMLDocument object.
/// @return the Version within the SBML Level of the SBMLDocument object containing this object.
LIBSBMLNETWORK_EXTERN const unsigned int getSBMLVersion(const SBMLDocument* document);

/// @brief Returns the Error log containing the errors and warnings that occurred while working with the SBMLDocument object.
/// @param document a pointer to the SBMLDocument object.
/// @return the Error log containing the errors and warnings that occurred while working with the SBMLDocument object.
LIBSBMLNETWORK_EXTERN const std::string getErrorLog(const SBMLDocument* document);

/// @brief Clears the Error log containing the errors and warnings that occurred while working with the SBMLDocument object.
/// @param document a pointer to the SBMLDocument object.
/// @return boolean value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN void clearErrorLog(SBMLDocument* document);

/// @brief Free the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return boolean value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN bool freeSBMLDocument(SBMLDocument* document);

/// @breif Free the user data of the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return boolean value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN bool freeUserData(SBMLDocument* document);

/// @brief Returns true if the Model object has been set, otherwise returns false.
/// @param document a pointer to the SBMLDocument object.
/// @return true if the Model object has been set, otherwise returns false.
LIBSBMLNETWORK_EXTERN bool isSetModel(SBMLDocument* document);

/// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
/// to the the SBML document, and set all the necessary features for them.
/// @param document a pointer to the SBMLDocument object.
/// @param maxNumConnectedEdges the maximum number of connected edges to a node in the autolayout algorithm..
/// @param resetFixedPositionElements a variable that determines whether to reset the fixed position elements in the autolayout algorithm.
/// @param fixedPositionNodesSet a set of fixed position nodes and their graphical object indices to be used in the autolayout algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int autolayout(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool resetFixedPositionElements = false, std::set<std::pair<std::string, int> > fixedPositionNodesSet = {});

/// @brief Create a Render object and add it to the the SBML document if it does not exist.
/// @param document a pointer to the SBMLDocument object.
/// @param maxNumConnectedEdges the maximum number of connected edges before creating an alias SpeciesGlyph.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int autorender(SBMLDocument* document, const int maxNumConnectedEdges = 3);

/// @brief Align the nodes position in the SBML document in the given alignment type.
/// @param document a pointer to the SBMLDocument object.
/// @param nodes a set of node ids and their graphical object indices to be aligned.
/// @param alignment determines how to align the nodes.
/// @param ignoreFixedPositionNodes a variable that determines whether to ignore the fixed position nodes in the alignment algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int align(SBMLDocument* document, std::set<std::pair<std::string, int> > nodesSet,  const std::string& alignment, const bool ignoreFixedPositionNodes = false);

/// @brief Distribute the nodes position in the SBML document in the given distribution direction.
/// @param document a pointer to the SBMLDocument object.
/// @param nodes a set of node ids and their graphical object indices to be distributed.
/// @param direction determines how to distribute the nodes.
/// @param spacing the spacing between the distributed nodes.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int distribute(SBMLDocument* document, std::set<std::pair<std::string, int> > nodesSet, const std::string& direction, const double spacing = -1);

/// @brief Returns the first child element found that has the given id in the model-wide SId namespace, or NULL if no such object is found.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the object to be found.
/// @return a pointer to the first element found with the given identifier.
SBase* getSBMLObject(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of Compartment objects in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of Compartment objects in the given SBML document.
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartments(const SBMLDocument* document);

/// @brief Returns the id of the Compartment object with the given index in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param index the index of the Compartment object.
/// @return the id of the Compartment object with the given index in the given SBML document, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getCompartmentId(SBMLDocument* document, unsigned int index);

/// @brief Returns a pointer to the Compartment object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Compartment object
/// @return a pointer to the Compartment object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN Compartment* getCompartment(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of Species objects in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of Species objects in the given SBML document.
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpecies(const SBMLDocument* document);

/// @brief Returns the id of the Species object with the given index in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param index the index of the Species object.
/// @return the id of the Species object with the given index in the given SBML document, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getSpeciesId(SBMLDocument* document, unsigned int index);

/// @brief Returns a pointer to the Species object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Species object.
/// @return a pointer to the Species object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN Species* getSpecies(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of Reaction objects in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of Reaction objects in the given SBML document.
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactions(const SBMLDocument* document);

/// @brief Returns the id of the Reaction object with the given index in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param index the index of the Reaction object.
/// @return the id of the Reaction object with the given index in the given SBML document, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getReactionId(SBMLDocument* document, unsigned int index);

/// @brief Returns a pointer to the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Reaction object.
/// @return a pointer to the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN Reaction* getReaction(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of SpeciesReference objects in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @return the number of SpeciesReference objects in the Reaction object with the given id.
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpeciesReferences(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the number of Reactant objects in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @return the number of Reactant objects in the Reaction object with the given id.
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactants(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the number of Product objects in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @return the number of Product objects in the Reaction object with the given id.
LIBSBMLNETWORK_EXTERN const unsigned int getNumProducts(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the number of Modifier objects in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @return the number of Modifier objects in the Reaction object with the given id.
LIBSBMLNETWORK_EXTERN const unsigned int getNumModifiers(SBMLDocument* document, const std::string& reactionId);

/// @brief Returns the id of the reactant species with the given index in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param index the index of the reactant species.
/// @return the id of the reactant species with the given index in the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getReactantId(SBMLDocument* document, const std::string& reactionId, unsigned int index);

/// @brief Returns the id of the product species with the given index in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param index the index of the product species.
/// @return the id of the product species with the given index in the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getProductId(SBMLDocument* document, const std::string& reactionId, unsigned int index);

/// @brief Returns the id of the modifier species with the given index in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param index the index of the modifier species.
/// @return the id of the modifier species with the given index in the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getModifierId(SBMLDocument* document, const std::string& reactionId, unsigned int index);

/// @brief Returns a pointer to the SpeciesReference object associated with the given reactant/product species id in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param speciesId the id of the Species object.
/// @return a pointer to the SpeciesReference object, or @c NULL if the object does not exists or is not of type reactant/product.
LIBSBMLNETWORK_EXTERN SpeciesReference* getSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId);

/// @brief Returns a pointer to the ModifierSpeciesReference object associated with the given modifier species id in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param speciesId the id of the Species object.
/// @return a pointer to the ModifierSpeciesReference object, or @c NULL if the object does not exists or is not of type modifier.
LIBSBMLNETWORK_EXTERN ModifierSpeciesReference* getModifierSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId);

/// @brief Returns the value of the option to generate stoichiometric species reference in the autolayout algorithm.
/// @param document a pointer to the SBMLDocument object.
/// @return the value of the option to generate stoichiometric species reference in the autolayout algorithm.
LIBSBMLNETWORK_EXTERN bool getStoichiometricSpeciesReference(SBMLDocument* document);

/// @brief Sets the value of the option to generate stoichiometric species reference in the autolayout algorithm.
/// @param document a pointer to the SBMLDocument object.q
/// @param stoichiometricSpeciesReference the value of the option to generate stoichiometric species reference in the autolayout algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setStoichiometricSpeciesReference(SBMLDocument* document, bool stoichiometricSpeciesReference);

}

#endif