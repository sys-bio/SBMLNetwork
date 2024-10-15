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
LIBSBMLNETWORK_EXTERN const unsigned int getSBMLLevel(SBMLDocument* document);

/// @brief Returns the Version within the SBML Level of the SBMLDocument object containing this object.
/// @param document a pointer to the SBMLDocument object.
/// @return the Version within the SBML Level of the SBMLDocument object containing this object.
LIBSBMLNETWORK_EXTERN const unsigned int getSBMLVersion(SBMLDocument* document);

/// @brief Free the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return boolean value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN bool freeSBMLDocument(SBMLDocument* document);

/// @brief Returns true if the Model object has been set, otherwise returns false.
/// @param document a pointer to the SBMLDocument object.
/// @return true if the Model object has been set, otherwise returns false.
LIBSBMLNETWORK_EXTERN bool isSetModel(SBMLDocument* document);

/// @brief Create a Layout object, a GlobalRenderInformation object, and LocalRenderInformation resume object, add them
/// to the the SBML document, and set all the necessary features for them.
/// @param document a pointer to the SBMLDocument object.
/// @param maxNumConnectedEdges the maximum number of connected edges to a node in the autolayout algorithm.
/// @param useNameAsTextLabel a variable that determines whether to use the name of the species/reaction as the text label in the autolayout algorithm.
/// @param resetLockedElements a variable that determines whether to reset the locked elements in the autolayout algorithm.
/// @param lockedNodesSet a set of locked nodes and their graphical object indices to be used in the autolayout algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int autolayout(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true, bool resetLockedElements = false, std::set<std::pair<std::string, int> > lockedNodesSet = {});

/// @brief Create a Render object and add it to the the SBML document if it does not exist.
/// @param document a pointer to the SBMLDocument object.
/// @param maxNumConnectedEdges the maximum number of connected edges before creating an alias SpeciesGlyph.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int autorender(SBMLDocument* document, const int maxNumConnectedEdges = 3);

/// @brief Align the nodes position in the SBML document in the given alignment type.
/// @param document a pointer to the SBMLDocument object.
/// @param nodes a set of node ids and their graphical object indices to be aligned.
/// @param alignment determines how to align the nodes.
/// @param ignoreLockedNodes a variable that determines whether to ignore the locked nodes in the alignment algorithm.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int align(SBMLDocument* document, std::set<std::pair<std::string, int> > nodesSet,  const std::string& alignment, const bool ignoreLockedNodes = false);

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

/// @brief Predicates returning @c true if the "id" attribute of this SBML object is set.
/// @param object a pointer to the SBML object.
/// @return @c true if the "id" attribute of this SBML object is set, @c false if either the "id"
/// attribute is not set or the object is @c NULL.
LIBSBMLNETWORK_EXTERN bool isSetId(SBase* object);

/// Returns the value of the "id" attribute of this SBML object.
/// @param object a pointer to the SBML object.
/// @return the "id" attribute of the SBML object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getId(SBase* object);

/// @brief Sets the value of the "id" attribute this SBML object.
/// @param object a pointer to the SBML object.
/// @param sid a string value to be set as "id" attribute of the SBML object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setId(SBase* object, const std::string& sid);

/// @brief Predicates returning @c true if the "name" attribute of this SBML object is set.
/// @param object a pointer to the SBML object.
/// @return @c true if the "name" attribute of this SBML object is set, @c false if either the "name"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetName(SBase* object);

/// Returns the value of the "name" attribute of this SBML object.
/// @param object a pointer to the SBML object.
/// @return the "name" attribute of the SBML object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getName(SBase* object);

/// @brief Sets the value of the "name" attribute this SBML object.
/// @param object a pointer to the SBML object.
/// @param name a string value to be set as "name" attribute of the SBML object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setName(SBase* object, const std::string& name);

/// @brief Predicates returning @c true if the "metaid" attribute of this SBML object is set.
/// @param object a pointer to the SBML object.
/// @return @c true if the "metaid" attribute of this SBML object is set, @c false if either the "metaid"
/// attribute is not set or the object is @c NULL .
LIBSBMLNETWORK_EXTERN bool isSetMetaId(SBase* object);

/// Returns the value of the "metaid" attribute of this SBML object.
/// @param object a pointer to the SBML object.
/// @return the "metaid" attribute of the SBML object, or @c "" if the object is @c NULL
LIBSBMLNETWORK_EXTERN const std::string getMetaId(SBase* object);

/// @brief Sets the value of the "metaid" attribute this SBML object.
/// @param object a pointer to the SBML object.
/// @param metaid a string value to be set as "metaid" attribute of the SBML object.
/// @return integer value indicating success/failure of the function.
LIBSBMLNETWORK_EXTERN int setMetaId(SBase* object, const std::string& metaid);

/// @brief Returns the number of Compartment objects in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of Compartment objects in the given SBML document.
LIBSBMLNETWORK_EXTERN const unsigned int getNumCompartments(SBMLDocument* document);

/// @brief Returns the id of the nth Compartment object in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param index the index of the Compartment object.
/// @return the id of the nth Compartment object in the given SBML document, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getNthCompartmentId(SBMLDocument* document, unsigned int index);

/// @brief Returns a pointer to the Compartment object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Compartment object
/// @return a pointer to the Compartment object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN Compartment* getCompartment(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of Species objects in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of Species objects in the given SBML document.
LIBSBMLNETWORK_EXTERN const unsigned int getNumSpecies(SBMLDocument* document);

/// @brief Returns the id of the nth Species object in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param index the index of the Species object.
/// @return the id of the nth Species object in the given SBML document, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getNthSpeciesId(SBMLDocument* document, unsigned int index);

/// @brief Returns a pointer to the Species object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the Species object.
/// @return a pointer to the Species object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN Species* getSpecies(SBMLDocument* document, const std::string& id);

/// @brief Returns the number of Reaction objects in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @return the number of Reaction objects in the given SBML document.
LIBSBMLNETWORK_EXTERN const unsigned int getNumReactions(SBMLDocument* document);

/// @brief Returns the id of the nth Reaction object in the given SBML document.
/// @param document a pointer to the SBMLDocument object.
/// @param index the index of the Reaction object.
/// @return the id of the nth Reaction object in the given SBML document, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getNthReactionId(SBMLDocument* document, unsigned int index);

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

/// @brief Returns the id of the nth reactant species in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param index the index of the reactant species.
/// @return the id of the nth reactant species in the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getNthReactantId(SBMLDocument* document, const std::string& reactionId, unsigned int index);

/// @brief Returns the id of the nth product species in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param index the index of the product species.
/// @return the id of the nth product species in the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getNthProductId(SBMLDocument* document, const std::string& reactionId, unsigned int index);

/// @brief Returns the id of the nth modifier species in the Reaction object with the given id.
/// @param document a pointer to the SBMLDocument object.
/// @param reactionId the id of the Reaction object.
/// @param index the index of the modifier species.
/// @return the id of the nth modifier species in the Reaction object with the given id, or @c "" if the object does not exists.
LIBSBMLNETWORK_EXTERN const std::string getNthModifierId(SBMLDocument* document, const std::string& reactionId, unsigned int index);

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

}

#endif