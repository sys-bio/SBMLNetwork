#ifndef __LIBSBMLNETWORK_SBMLDOCUMENT_HELPERS_H_
#define __LIBSBMLNETWORK_SBMLDOCUMENT_HELPERS_H_

#include "libsbmlnetwork_sbmldocument.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

const std::string getErrorLog(SBase* sBase);

void clearErrorLog(SBase* sBase);

void addErrorToLog(SBase* sbase, const std::string& errorMessage);

const std::string prepareErrorMessage(const std::string& errorMessage, const std::string& errorLog);

const std::string getUserData(SBase* sbase, const std::string& key);

void setUserData(SBase* sBase, const std::string& key, const std::string& value);

void freeUserData(SBMLDocument* document);

void freeUserData(SBase* sbase);

}

#endif