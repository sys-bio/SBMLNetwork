#include "libsbml_ne_sbmldocument_render.h"
#include "libsbml_ne_sbmldocument_layout.h"
#include "libsbml_ne_layout_render.h"
#include "libsbml_ne_render.h"
#include "libsbml_ne_render_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

ListOfGlobalRenderInformation* getListOfGlobalRenderInformation(SBMLDocument* document) {
    if (document) {
        SBasePlugin* renderBase = getRenderPlugin(document);
        if (renderBase) {
            RenderListOfLayoutsPlugin* renderListOfLayoutsPlugin = getRenderListOfLayoutsPlugin(renderBase);
            if (renderListOfLayoutsPlugin)
                return renderListOfLayoutsPlugin->getListOfGlobalRenderInformation();
        }
    }

    return NULL;
}

const unsigned int getNumGlobalRenderInformation(SBMLDocument* document) {
    return getNumGlobalRenderInformation(getListOfGlobalRenderInformation(document));
}

GlobalRenderInformation* getGlobalRenderInformation(SBMLDocument* document, unsigned int renderIndex) {
    return getGlobalRenderInformation(getListOfGlobalRenderInformation(document), renderIndex);
}

int addGlobalRenderInformation(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation) {
    if (globalRenderInformation) {
        ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
        if (listOfGlobalRenderInformation) {
            listOfGlobalRenderInformation->addGlobalRenderInformation(globalRenderInformation);
            return 0;
        }
    }

    return -1;
}

GlobalRenderInformation* createGlobalRenderInformation(SBMLDocument* document) {
    ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->createGlobalRenderInformation();

    return NULL;
}

int removeAllGlobalRenderInformation(SBMLDocument* document) {
    ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
    if (listOfGlobalRenderInformation) {
        while(listOfGlobalRenderInformation->size())
            listOfGlobalRenderInformation->remove(0);
        return 0;
    }

    return -1;
}

int setDefaultGlobalRenderInformationFeatures(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation) {
    if (document && globalRenderInformation) {
        LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(document->getLevel(), document->getVersion());
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(document->getLevel(), document->getVersion());
        globalRenderInformation->setId("libSBML_NetworkEditor_Global_Render");
        globalRenderInformation->setBackgroundColor("lightgray");
        addDefaultColors(globalRenderInformation, renderPkgNamespaces);
        addDefaultLineEndings(globalRenderInformation, layoutPkgNamespaces, renderPkgNamespaces);
        return 0;
    }

    return -1;
}

ListOfLocalRenderInformation* getListOfLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex) {
    return getListOfLocalRenderInformation(getLayout(document, layoutIndex));
}

const unsigned int getNumLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumLocalRenderInformation(getLayout(document, layoutIndex));
}

LocalRenderInformation* getLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex, unsigned int renderIndex) {
    return getLocalRenderInformation(getLayout(document, layoutIndex), renderIndex);
}

int addLocalRenderInformation(SBMLDocument* document, LocalRenderInformation* localRenderInformation) {
    return addLocalRenderInformation(getLayout(document), localRenderInformation);
}

int addLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation) {
    return addLocalRenderInformation(getLayout(document, layoutIndex), localRenderInformation);
}

LocalRenderInformation* createLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex) {
    return createLocalRenderInformation(getLayout(document, layoutIndex));
}

int removeAllLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex) {
    return removeAllLocalRenderInformation(getLayout(document, layoutIndex));
}

int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, LocalRenderInformation* localRenderInformation) {
    return setDefaultLocalRenderInformationFeatures(document, getLayout(document), localRenderInformation);
}

int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation) {
    return setDefaultLocalRenderInformationFeatures(document, getLayout(document, layoutIndex), localRenderInformation);
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

bool isSetBackgroundColor(SBMLDocument* document, unsigned int renderIndex) {
    return isSetBackgroundColor(getGlobalRenderInformation(document, renderIndex));
}

const std::string getBackgroundColor(SBMLDocument* document, unsigned int renderIndex) {
    return getBackgroundColor(getGlobalRenderInformation(document, renderIndex));
}

int setBackgroundColor(SBMLDocument* document, const std::string& backgroundColor) {
    return setBackgroundColor(document, 0, backgroundColor);
}

int setBackgroundColor(SBMLDocument* document, unsigned int renderIndex, const std::string& backgroundColor) {
    return setBackgroundColor(getGlobalRenderInformation(document, renderIndex), backgroundColor);
}

}
