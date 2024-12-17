#ifndef __LIBSBMLNETWORK_USER_DATA_H
#define __LIBSBMLNETWORK_USER_DATA_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int user_data_freeUserData(SBMLDocument* document);

int user_data_freeUserData(Layout* layout);

std::vector<std::map<std::string, std::string>> user_data_getUserData(const Layout* layout);

int user_data_setUserData(GraphicalObject* graphicalObject, const std::string& key, const std::string& value);

int user_data_setPositionData(GraphicalObject* graphicalObject);

int user_data_unsetPositionData(GraphicalObject* graphicalObject);

int user_data_setPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph);

int user_data_unsetPositionData(SpeciesReferenceGlyph* speciesReferenceGlyph);

int user_data_setGraphicalObjectUserData(GraphicalObject* graphicalObject, const std::vector<std::map<std::string, std::string>>& userData);

int user_data_freeUserData(RenderInformationBase* renderInformation);

std::vector<std::map<std::string, std::string>> user_data_getUserData(const RenderInformationBase* renderInformationBase);

const std::string user_data_getUserData(const SBase* sbase, const std::string& key);

int user_data_setUserData(SBase* sBase, const std::string& key, const std::string& value);

int user_data_freeUserData(SBMLDocument* document);

int user_data_freeUserData(SBase* sBase);

int user_data_passUserData(SBase* sBase1, SBase* sBase2);

}

#endif
