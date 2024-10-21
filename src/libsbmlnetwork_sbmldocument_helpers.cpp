#include "libsbmlnetwork_sbmldocument_helpers.h"
#include "libsbmlnetwork_common.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_render.h"
#include "libsbmlnetwork_render_helpers.h"
#include "libsbmlnetwork_layout_render.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

const std::string getErrorLog(SBase* sBase) {
    std::string errorLog = "";
    if (sBase)
        errorLog = prepareErrorMessage(getUserData(sBase, "error_log"), errorLog);

    return errorLog;

}

void clearErrorLog(SBase* sBase) {
    if (sBase)
        setUserData(sBase, "error_log", "");
}

void addErrorToLog(SBase* sbase, const std::string& errorMessage) {
    if (sbase && !errorMessage.empty()) {
        std::string errorLog = getUserData(sbase, "error_log");
        if (!errorLog.empty())
            errorLog += "\n";
        errorLog += errorMessage;
        setUserData(sbase, "error_log", errorLog);
    }
}

const std::string prepareErrorMessage(const std::string& errorMessage, const std::string& errorLog) {
    std::string preparedErrorMessage = "";
    if (!errorMessage.empty()) {
        if (!errorLog.empty())
            preparedErrorMessage += "\n";

        preparedErrorMessage += errorMessage;
    }

    return preparedErrorMessage;
}

const std::string getUserData(SBase* sBase, const std::string& key) {
    if (sBase->isSetUserData()) {
        auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
        if (userData->find(key) != userData->end())
            return (*userData)[key];
    }

    return "";
}


void setUserData(SBase* sBase, const std::string& key, const std::string& value) {
    if (!sBase->isSetUserData())
        sBase->setUserData(new std::map<std::string, std::string>());
    auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
    (*userData)[key] = value;
}

void freeUserData(SBMLDocument* document) {
    if (document) {
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        freeUserData(listOfLayouts);
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++)
            freeUserData(getLayout(document, i));
    }
}

void freeUserData(SBase* sBase) {
    if (sBase) {
        if (sBase->isSetUserData()) {
            auto userData = (std::map<std::string, std::string>*)sBase->getUserData();
            delete userData;
            sBase->unsetUserData();
        }
    }
}

}