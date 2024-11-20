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

std::vector<std::map<std::string, std::string>> user_data_getUserData(Layout* layout);

void user_data_setUserData(GraphicalObject* graphicalObject, const std::string& key, const std::string& value);

void user_data_setPositionData(GraphicalObject* graphicalObject);

void user_data_unsetPositionData(GraphicalObject* graphicalObject);

void user_data_setPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph);

void user_data_unsetPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph);

void user_data_setGraphicalObjectUserData(GraphicalObject* graphicalObject, const std::vector<std::map<std::string, std::string>>& userData);

void user_data_freeUserData(RenderInformationBase* renderInformation);

std::vector<std::map<std::string, std::string>> user_data_getUserData(RenderInformationBase* renderInformationBase);

const std::string user_data_getUserData(SBase* sbase, const std::string& key);

void user_data_setUserData(SBase* sBase, const std::string& key, const std::string& value);

void user_data_freeUserData(SBMLDocument* document);

void user_data_freeUserData(SBase* sbase);

}

#endif
