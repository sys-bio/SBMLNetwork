#include "libsbml_ne_util_core.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_render.h"
#include "libsbml_ne_util_layout.h"
#include "libsbml_ne_util_helpers.h"
#include "libsbml_ne_layout_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

SBMLDocument* readSBML(const std::string& sbml) {
    SBMLDocument* document = readSBMLFromFile(sbml.c_str());
    if (document)
        return document;
    document = readSBMLFromString(sbml.c_str());
    if (document)
        return document;

    return NULL;
}

bool writeSBML(SBMLDocument* document, const std::string &fileName) {
    return writeSBMLToFile(document, fileName.c_str());
}

const std::string writeSBML(SBMLDocument* document) {
    return writeSBMLToString(document);
}

int createDefaultLayout(SBMLDocument* document) {
    if (!getNumLayouts(document)) {
        Layout* layout = createLayout(document);
        return setDefaultLayoutFeatures(document, layout);
    }

    return -1;
}

int createDefaultRenderInformation(SBMLDocument* document) {
    if (!createDefaultLocalRenderInformation(document) && !createDefaultGlobalRenderInformation(document))
        return 0;

    return -1;
}

int createDefaultGlobalRenderInformation(SBMLDocument* document) {
    if (!getNumGlobalRenderInformation(document)) {
        GlobalRenderInformation* globalRenderInformation = createGlobalRenderInformation(document);
        return setDefaultGlobalRenderInformationFeatures(document, globalRenderInformation);
    }

    return -1;
}

int createDefaultLocalRenderInformation(SBMLDocument* document) {
    Layout* layout = getLayout(document);
    if (!getNumLocalRenderInformation(layout)) {
        LocalRenderInformation* localRenderInformation = createLocalRenderInformation(layout);
        return setDefaultLocalRenderInformationFeatures(document,layout, localRenderInformation);
    }

    return -1;
}

bool isSetId(SBase* object) {
    if (object)
        return object->isSetId();

    return false;
}

const std::string getId(SBase* object) {
    if (object)
        return object->getId();

    return "";
}

int setId(SBase* object, const std::string& sid) {
    if (object) {
        object->setId(sid);
        return 0;
    }

    return -1;
}

bool isSetName(SBase* object) {
    if (object)
        object->isSetName();

    return false;
}

const std::string getName(SBase* object) {
    if (object)
        return object->getName();

    return "";
}

int setName(SBase* object, const std::string& name) {
    if (object) {
        object->setName(name);
        return 0;
    }

    return -1;
}

bool isSetMetaId(SBase* object) {
    if (object)
        return object->isSetMetaId();

    return false;
}

const std::string getMetaId(SBase* object) {
    if (object)
        return object->getMetaId();

    return "";
}

int setMetaId(SBase* object, const std::string& metaid) {
    if (object) {
        object->setMetaId(metaid);
        return 0;
    }

    return -1;
}

}
