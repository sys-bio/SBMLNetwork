#ifndef __LIBSBML_NE_UTIL_H_
#define __LIBSBML_NE_UTIL_H_

#include "libsbml_ne_common.h"

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

/// @brief Reads an SBML document from the given file name or the given text string
/// @param sbml either the name or full pathname of the file to be read or a string containing a full SBML model.
/// @return a pointer to the SBMLDocument structure created from the SBML content in the given file name or
/// from the SBML content in the given text string.
LIBSBML_NETWORKEDITOR_EXTERN SBMLDocument* readSBML(const std::string &sbml);

/// @brief Writes the given SBML document to a filename.
/// @param document the SBML document to be written.
/// @param fileName the name or full pathname of the file where the SBML is to be written.
/// @return true on success and false if the filename could not be opened for writing.
LIBSBML_NETWORKEDITOR_EXTERN bool writeSBML(SBMLDocument* document, const std::string &fileName);

/// @brief Writes the given SBML document to a string and returns it.
/// @param document the SBML document to be written.
/// @return the string on success and empty string if one of the underlying parser components fail.
LIBSBML_NETWORKEDITOR_EXTERN const std::string writeSBML(SBMLDocument* document);

/// @brief Create a Layout object, add it to list of layouts of the SBML document, and
/// set all the necessary features for it
/// @param document a pointer to the SBMLDocument object.
/// @return integer value indicating success/failure of the function.
LIBSBML_NETWORKEDITOR_EXTERN int createDefaultLayout(SBMLDocument* document);

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

/// @brief Returns a list of GraphicalObject objects associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity to the GraphicalObject objects of which are going to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
LIBSBML_NETWORKEDITOR_EXTERN ListOfGraphicalObjects getListOfAssociatedGraphicalObjects(SBMLDocument* document, const std::string& id);

/// @brief Returns a list of GraphicalObject objects associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity to the GraphicalObject objects of which are going to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
LIBSBML_NETWORKEDITOR_EXTERN ListOfGraphicalObjects getListOfAssociatedCompartmentGlyphs(SBMLDocument* document, const std::string& id);

/// @brief Returns a list of GraphicalObject objects associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity to the GraphicalObject objects of which are going to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
LIBSBML_NETWORKEDITOR_EXTERN ListOfGraphicalObjects getListOfAssociatedSpeciesGlyphs(SBMLDocument* document, const std::string& id);

/// @brief Returns a list of GraphicalObject objects associated with the entered model entity id.
/// @param document a pointer to the SBMLDocument object.
/// @param id the id of the model entity to the GraphicalObject objects of which are going to be returned.
/// @return a pointer to the GraphicalObject object with the same graphical object id.
LIBSBML_NETWORKEDITOR_EXTERN ListOfGraphicalObjects getListOfAssociatedReactionGlyphs(SBMLDocument* document, const std::string& id);

LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getAssociatedGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int index);

LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getAssociatedCompartmentGlyph(SBMLDocument* document, const std::string& id, unsigned int index);

LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getAssociatedSpeciesGlyph(SBMLDocument* document, const std::string& id, unsigned int index);

LIBSBML_NETWORKEDITOR_EXTERN GraphicalObject* getAssociatedReactionGlyph(SBMLDocument* document, const std::string& id, unsigned int index);

}

#endif