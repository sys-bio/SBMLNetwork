#include "libsbml_ne_layout_render.h"
#include "libsbml_ne_render.h"
#include "libsbml_ne_render_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout) {
    if (layout) {
        SBasePlugin* renderBase = getRenderPlugin(layout);
        if (renderBase) {
            RenderLayoutPlugin* renderLayoutPlugin = getRenderLayoutPlugin(renderBase);
            if (renderLayoutPlugin)
                return renderLayoutPlugin->getListOfLocalRenderInformation();
        }
    }

    return NULL;
}

const unsigned int getNumLocalRenderInformation(Layout* layout) {
    return getNumLocalRenderInformation(getListOfLocalRenderInformation(layout));
}

LocalRenderInformation* getLocalRenderInformation(Layout* layout, unsigned int renderIndex) {
    return getLocalRenderInformation(getListOfLocalRenderInformation(layout), renderIndex);
}

int addLocalRenderInformation(Layout* layout, LocalRenderInformation* localRenderInformation) {
    if (localRenderInformation) {
        ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
        if (listOfLocalRenderInformation) {
            listOfLocalRenderInformation->addLocalRenderInformation(localRenderInformation);
            return 0;
        }
    }

    return -1;
}

LocalRenderInformation* createLocalRenderInformation(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->createLocalRenderInformation();

    return NULL;
}

int removeAllLocalRenderInformation(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation) {
        while(listOfLocalRenderInformation->size())
            listOfLocalRenderInformation->remove(0);
        return 0;
    }

    return -1;
}

int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRenderInformation) {
    if (document && localRenderInformation) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(document->getLevel(), document->getVersion());
        localRenderInformation->setId("libSBML_NetworkEditor_Local_Render");
        localRenderInformation->setReferenceRenderInformation("libSBML_NetworkEditor_Global_Render");
        if (layout) {
            addStyles(layout, localRenderInformation, renderPkgNamespaces);
            return 0;
        }
    }

    return -1;
}

}