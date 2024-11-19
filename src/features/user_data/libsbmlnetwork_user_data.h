#ifndef __LIBSBMLNETWORK_USER_DATA_H
#define __LIBSBMLNETWORK_USER_DATA_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void freeUserData(Layout* layout);

std::vector<std::map<std::string, std::string>> ud_getUserData(Layout* layout);

void ud_setUserData(GraphicalObject* graphicalObject, const std::string& key, const std::string& value);

void ud_setPositionData(GraphicalObject* graphicalObject);

void ud_unsetPositionData(GraphicalObject* graphicalObject);

void ud_setPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph);

void ud_unsetPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph);

void ud_setGraphicalObjectUserData(GraphicalObject* graphicalObject, const std::vector<std::map<std::string, std::string>>& userData);

void ud_freeUserData(RenderInformationBase* renderInformation);

std::vector<std::map<std::string, std::string>> ud_getUserData(RenderInformationBase* renderInformationBase);

const std::string ud_getUserData(SBase* sbase, const std::string& key);

void ud_setUserData(SBase* sBase, const std::string& key, const std::string& value);

void ud_freeUserData(SBMLDocument* document);

void ud_freeUserData(SBase* sbase);

}

#endif
