#include "libsbmlnetwork_sbmldocument_helpers.h"
#include "libsbmlnetwork_common.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_render.h"
#include "libsbmlnetwork_render_helpers.h"
#include "libsbmlnetwork_layout_render.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

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