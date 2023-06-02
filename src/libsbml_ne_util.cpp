#include "libsbml_ne_util.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_render.h"

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

int addDefaultLayout(SBMLDocument* document) {
    if (!getNumLayouts(document)) {
        Layout* layout = createLayout(document);
        setDefaultLayoutFeatures(document, layout);
        return addLayout(document, layout);
    }

    return -1;
}

int addDefaultGlobalRenderInformation(SBMLDocument* document) {
    if (!getNumGlobalRenderInformation(document)) {
        GlobalRenderInformation* globalRenderInformation = createGlobalRenderInformation(document);
        setDefaultGlobalRenderInformationFeatures(document, globalRenderInformation);
        return addGlobalRenderInformation(document, globalRenderInformation);
    }

    return -1;
}

int addDefaultLocalRenderInformation(SBMLDocument* document) {
    Layout* layout = getLayout(document);
    if (!getNumLocalRenderInformation(layout)) {
        LocalRenderInformation* localRenderInformation = createLocalRenderInformation(layout);
        setDefaultLocalRenderInformationFeatures(document,layout, localRenderInformation);
        return addLocalRenderInformation(layout, localRenderInformation);
    }

    return -1;
}

}
