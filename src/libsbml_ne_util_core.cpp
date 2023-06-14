#include "libsbml_ne_util_core.h"

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
