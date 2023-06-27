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

const unsigned int getNumColorDefinitions(SBMLDocument* document, unsigned int renderIndex) {
    if (getNumColorDefinitions(getGlobalRenderInformation(document, renderIndex)))
        return getNumColorDefinitions(getGlobalRenderInformation(document, renderIndex));

    return getNumColorDefinitions(getLocalRenderInformation(document, 0, renderIndex));
}

ColorDefinition* getColorDefinition(SBMLDocument* document, const std::string& sid) {
    for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
        if (getColorDefinition(getGlobalRenderInformation(document, i), sid))
            return getColorDefinition(getGlobalRenderInformation(document, i), sid);
    }
    for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
        if (getColorDefinition(getLocalRenderInformation(document, i), sid))
            return getColorDefinition(getLocalRenderInformation(document, i), sid);
    }

    return NULL;
}

ColorDefinition* getColorDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    if (getColorDefinition(getGlobalRenderInformation(document, renderIndex), sid))
        return getColorDefinition(getGlobalRenderInformation(document, renderIndex), sid);

    return getColorDefinition(getLocalRenderInformation(document, 0, renderIndex), sid);
}

ColorDefinition* getColorDefinition(SBMLDocument* document, unsigned int renderIndex, unsigned int colorIndex) {
    if (getColorDefinition(getGlobalRenderInformation(document, renderIndex), colorIndex))
        return getColorDefinition(getGlobalRenderInformation(document, renderIndex), colorIndex);

    return getColorDefinition(getLocalRenderInformation(document, 0, renderIndex), colorIndex);
}

bool isSetValue(SBMLDocument* document, const std::string& sid) {
    return isSetValue(getColorDefinition(document, sid));
}

bool isSetValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetValue(getColorDefinition(document, renderIndex, sid));
}

const std::string getValue(SBMLDocument* document, const std::string& sid) {
    return getValue(getColorDefinition(document, sid));
}

const std::string getValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getValue(getColorDefinition(document, renderIndex, sid));
}

int setValue(SBMLDocument* document, const std::string& sid, const std::string& value) {
    return setValue(getColorDefinition(document, sid), value);
}

int setValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& value) {
    return setValue(getColorDefinition(document, renderIndex, sid), value);
}

const unsigned int getNumGradientDefinitions(SBMLDocument* document, unsigned int renderIndex) {
    if (getNumGradientDefinitions(getGlobalRenderInformation(document, renderIndex)))
        return getNumGradientDefinitions(getGlobalRenderInformation(document, renderIndex));

    return getNumGradientDefinitions(getLocalRenderInformation(document, 0, renderIndex));
}

GradientBase* getGradientDefinition(SBMLDocument* document, const std::string& sid) {
    for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
        if (getGradientDefinition(getGlobalRenderInformation(document, i), sid))
            return getGradientDefinition(getGlobalRenderInformation(document, i), sid);
    }
    for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
        if (getGradientDefinition(getLocalRenderInformation(document, i), sid))
            return getGradientDefinition(getLocalRenderInformation(document, i), sid);
    }

    return NULL;
}

GradientBase* getGradientDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    if (getGradientDefinition(getGlobalRenderInformation(document, renderIndex), sid))
        return getGradientDefinition(getGlobalRenderInformation(document, renderIndex), sid);

    return getGradientDefinition(getLocalRenderInformation(document, 0, renderIndex), sid);
}

GradientBase* getGradientDefinition(SBMLDocument* document, unsigned int renderIndex, unsigned int gradientIndex) {
    if (getGradientDefinition(getGlobalRenderInformation(document, renderIndex), gradientIndex))
        return getGradientDefinition(getGlobalRenderInformation(document, renderIndex), gradientIndex);

    return getGradientDefinition(getLocalRenderInformation(document, 0, renderIndex), gradientIndex);
}

bool isLinearGradient(SBMLDocument* document, const std::string& sid) {
    return isLinearGradient(getGradientDefinition(document, sid));
}

bool isLinearGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isLinearGradient(getGradientDefinition(document, renderIndex, sid));
}

bool isRadialGradient(SBMLDocument* document, const std::string& sid) {
    return isRadialGradient(getGradientDefinition(document, sid));
}

bool isRadialGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isRadialGradient(getGradientDefinition(document, renderIndex, sid));
}

bool isSetSpreadMethod(SBMLDocument* document, const std::string& sid) {
    return isSetSpreadMethod(getGradientDefinition(document, sid));
}

bool isSetSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetSpreadMethod(getGradientDefinition(document, renderIndex, sid));
}

const std::string getSpreadMethod(SBMLDocument* document, const std::string& sid) {
    return getSpreadMethod(getGradientDefinition(document, sid));
}

const std::string getSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getSpreadMethod(getGradientDefinition(document, renderIndex, sid));
}

int setSpreadMethod(SBMLDocument* document, const std::string& sid, const std::string& spreadMethod) {
    return setSpreadMethod(getGradientDefinition(document, sid), spreadMethod);
}

int setSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& spreadMethod) {
    return setSpreadMethod(getGradientDefinition(document, renderIndex, sid), spreadMethod);
}

unsigned int getNumGradientStops(SBMLDocument* document, const std::string& sid) {
    return getNumGradientStops(getGradientDefinition(document, sid));
}

unsigned int getNumGradientStops(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getNumGradientStops(getGradientDefinition(document, renderIndex, sid));
}

GradientStop* getGradientStop(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex) {
    return getGradientStop(getGradientDefinition(document, sid), gradientStopIndex);
}

GradientStop* getGradientStop(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex) {
    return getGradientStop(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
}

bool isSetOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex) {
    return isSetOffset(getGradientDefinition(document, sid), gradientStopIndex);
}

bool isSetOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex) {
    return isSetOffset(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
}

const RelAbsVector getOffset(SBMLDocument* document, const std::string& sid , unsigned int gradientStopIndex) {
    return getOffset(getGradientDefinition(document, sid), gradientStopIndex);
}

const RelAbsVector getOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid , unsigned int gradientStopIndex) {
    return getOffset(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
}

int setOffset(SBMLDocument* document, const std::string& sid, const RelAbsVector& offset) {
    return setOffset(getGradientDefinition(document, sid), offset);
}

int setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& offset) {
    return setOffset(getGradientDefinition(document, renderIndex, sid), offset);
}

int setOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset) {
    return setOffset(getGradientDefinition(document, sid), gradientStopIndex, offset);
}

int setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset) {
    return setOffset(getGradientDefinition(document, renderIndex, sid), gradientStopIndex, offset);
}

bool isSetStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex) {
    return isSetStopColor(getGradientDefinition(document, sid), gradientStopIndex);
}

bool isSetStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex) {
    return isSetStopColor(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
}

const std::string getStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex) {
    return getStopColor(getGradientDefinition(document, sid), gradientStopIndex);
}

const std::string getStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex) {
    return getStopColor(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
}

int setStopColor(SBMLDocument* document, const std::string& sid, const std::string& stopColor) {
    return setStopColor(getGradientDefinition(document, sid), stopColor);
}

int setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& stopColor) {
    return setStopColor(getGradientDefinition(document, renderIndex, sid), stopColor);
}

int setStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor) {
    return setStopColor(getGradientDefinition(document, sid), gradientStopIndex, stopColor);
}

int setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor) {
    return setStopColor(getGradientDefinition(document, renderIndex, sid), gradientStopIndex, stopColor);
}

bool isSetLinearGradientX1(SBMLDocument* document, const std::string& sid) {
    return isSetLinearGradientX1(getGradientDefinition(document, sid));
}

bool isSetLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetLinearGradientX1(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getLinearGradientX1(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientX1(getGradientDefinition(document, sid));
}

const RelAbsVector getLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientX1(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientX1(SBMLDocument* document, const std::string& sid, const RelAbsVector& x1) {
    return setLinearGradientX1(getGradientDefinition(document, sid), x1);
}

int setLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x1) {
    return setLinearGradientX1(getGradientDefinition(document, renderIndex, sid), x1);
}

bool isSetLinearGradientX2(SBMLDocument* document, const std::string& sid) {
    return isSetLinearGradientX2(getGradientDefinition(document, sid));
}

bool isSetLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetLinearGradientX2(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getLinearGradientX2(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientX2(getGradientDefinition(document, sid));
}

const RelAbsVector getLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientX2(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientX2(SBMLDocument* document, const std::string& sid, const RelAbsVector& x2) {
    return setLinearGradientX2(getGradientDefinition(document, sid), x2);
}

int setLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x2) {
    return setLinearGradientX2(getGradientDefinition(document, renderIndex, sid), x2);
}

bool isSetLinearGradientY1(SBMLDocument* document, const std::string& sid) {
    return isSetLinearGradientY1(getGradientDefinition(document, sid));
}

bool isSetLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetLinearGradientY1(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getLinearGradientY1(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientY1(getGradientDefinition(document, sid));
}

const RelAbsVector getLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientY1(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientY1(SBMLDocument* document, const std::string& sid, const RelAbsVector& y1) {
    return setLinearGradientY1(getGradientDefinition(document, sid), y1);
}

int setLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y1) {
    return setLinearGradientY1(getGradientDefinition(document, renderIndex, sid), y1);
}

bool isSetLinearGradientY2(SBMLDocument* document, const std::string& sid) {
    return isSetLinearGradientY1(getGradientDefinition(document, sid));
}

bool isSetLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetLinearGradientY2(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getLinearGradientY2(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientY2(getGradientDefinition(document, sid));
}

const RelAbsVector getLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientY2(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientY2(SBMLDocument* document, const std::string& sid, const RelAbsVector& y2) {
    return setLinearGradientY2(getGradientDefinition(document, sid), y2);
}

int setLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y2) {
    return setLinearGradientY2(getGradientDefinition(document, renderIndex, sid), y2);
}

bool isSetRadialGradientCx(SBMLDocument* document, const std::string& sid) {
    return isSetRadialGradientCx(getGradientDefinition(document, sid));
}

bool isSetRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetRadialGradientCx(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getRadialGradientCx(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientCx(getGradientDefinition(document, sid));
}

const RelAbsVector getRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientCx(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientCx(SBMLDocument* document, const std::string& sid, const RelAbsVector& cx) {
    return setRadialGradientCx(getGradientDefinition(document, sid), cx);
}

int setRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cx) {
    return setRadialGradientCx(getGradientDefinition(document, renderIndex, sid), cx);
}

bool isSetRadialGradientCy(SBMLDocument* document, const std::string& sid) {
    return isSetRadialGradientCy(getGradientDefinition(document, sid));
}

bool isSetRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetRadialGradientCy(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getRadialGradientCy(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientCy(getGradientDefinition(document, sid));
}

const RelAbsVector getRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientCy(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientCy(SBMLDocument* document, const std::string& sid, const RelAbsVector& cy) {
    return setRadialGradientCy(getGradientDefinition(document, sid), cy);
}

int setRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cy) {
    return setRadialGradientCy(getGradientDefinition(document, renderIndex, sid), cy);
}

bool isSetRadialGradientFx(SBMLDocument* document, const std::string& sid) {
    return isSetRadialGradientFx(getGradientDefinition(document, sid));
}

bool isSetRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetRadialGradientFx(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getRadialGradientFx(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientFx(getGradientDefinition(document, sid));
}

const RelAbsVector getRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientFx(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientFx(SBMLDocument* document, const std::string& sid, const RelAbsVector& fx) {
    return setRadialGradientFx(getGradientDefinition(document, sid), fx);
}

int setRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fx) {
    return setRadialGradientFx(getGradientDefinition(document, renderIndex, sid), fx);
}

bool isSetRadialGradientFy(SBMLDocument* document, const std::string& sid) {
    return isSetRadialGradientFy(getGradientDefinition(document, sid));
}

bool isSetRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetRadialGradientFy(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getRadialGradientFy(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientFy(getGradientDefinition(document, sid));
}

const RelAbsVector getRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientFy(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientFy(SBMLDocument* document, const std::string& sid, const RelAbsVector& fy) {
    return setRadialGradientFy(getGradientDefinition(document, sid), fy);
}

int setRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fy) {
    return setRadialGradientFy(getGradientDefinition(document, renderIndex, sid), fy);
}

bool isSetRadialGradientR(SBMLDocument* document, const std::string& sid) {
    return isSetRadialGradientR(getGradientDefinition(document, sid));
}

bool isSetRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetRadialGradientR(getGradientDefinition(document, renderIndex, sid));
}

const RelAbsVector getRadialGradientR(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientR(getGradientDefinition(document, sid));
}

const RelAbsVector getRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientR(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientR(SBMLDocument* document, const std::string& sid, const RelAbsVector& r) {
    return setRadialGradientR(getGradientDefinition(document, sid), r);
}

int setRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& r) {
    return setRadialGradientR(getGradientDefinition(document, renderIndex, sid), r);
}

const unsigned int getNumLineEndings(SBMLDocument* document, unsigned int renderIndex) {
    if (getNumLineEndings(getGlobalRenderInformation(document, renderIndex)))
        return getNumLineEndings(getGlobalRenderInformation(document, renderIndex));

    return getNumLineEndings(getLocalRenderInformation(document, 0, renderIndex));
}

LineEnding* getLineEnding(SBMLDocument* document, const std::string& sid) {
    for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
        if (getLineEnding(getGlobalRenderInformation(document, i), sid))
            return getLineEnding(getGlobalRenderInformation(document, i), sid);
    }
    for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
        if (getLineEnding(getLocalRenderInformation(document, i), sid))
            return getLineEnding(getLocalRenderInformation(document, i), sid);
    }

    return NULL;
}

LineEnding* getLineEnding(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    if (getLineEnding(getGlobalRenderInformation(document, renderIndex), sid))
        return getLineEnding(getGlobalRenderInformation(document, renderIndex), sid);

    return getLineEnding(getLocalRenderInformation(document, 0, renderIndex), sid);
}

LineEnding* getLineEnding(SBMLDocument* document, unsigned int renderIndex, unsigned int lineEndingIndex) {
    if (getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex))
        return getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex);

    return getLineEnding(getLocalRenderInformation(document, 0, renderIndex), lineEndingIndex);
}

bool isSetEnableRotationalMapping(SBMLDocument* document, const std::string& sid) {
    return isSetEnableRotationalMapping(getLineEnding(document, sid));
}

bool isSetEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return isSetEnableRotationalMapping(getLineEnding(document, renderIndex, sid));
}

bool getEnableRotationalMapping(SBMLDocument* document, const std::string& sid) {
    return getEnableRotationalMapping(getLineEnding(document, sid));
}

bool getEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getEnableRotationalMapping(getLineEnding(document, renderIndex, sid));
}

int setEnableRotationalMapping(SBMLDocument* document, const std::string& sid, bool enableRotationalMapping) {
    return setEnableRotationalMapping(getLineEnding(document, sid), enableRotationalMapping);
}

int setEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, bool enableRotationalMapping) {
    return setEnableRotationalMapping(getLineEnding(document, renderIndex, sid), enableRotationalMapping);
}

BoundingBox* getBoundingBoxOfLineEnding(SBMLDocument* document, const std::string& sid) {
    return getBoundingBoxOfLineEnding(getLineEnding(document, sid));
}

BoundingBox* getBoundingBoxOfLineEnding(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getBoundingBoxOfLineEnding(getLineEnding(document, renderIndex, sid));
}

RenderGroup* getRenderGroupOfLineEnding(SBMLDocument* document, const std::string& sid) {
    return getRenderGroup(getLineEnding(document, sid));
}

RenderGroup* getRenderGroupOfLineEnding(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRenderGroup(getLineEnding(document, renderIndex, sid));
}

Style* getStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
        if (getStyle(getLocalRenderInformation(document, i), graphicalObject))
            return getStyle(getLocalRenderInformation(document, i), graphicalObject);
    }
    for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
        if (getStyle(getGlobalRenderInformation(document, i), graphicalObject))
            return getStyle(getGlobalRenderInformation(document, i), graphicalObject);
    }

    return NULL;
}

Style* getStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    if (getStyle(getLocalRenderInformation(document, 0, renderIndex), graphicalObject))
        return getStyle(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);

    return getStyle(getGlobalRenderInformation(document, renderIndex), graphicalObject);
}

Style* getStyle(SBMLDocument* document, const std::string& attribute) {
    if (getStyle(getLocalRenderInformation(document), attribute))
        return getStyle(getLocalRenderInformation(document), attribute);

    return getStyle(getGlobalRenderInformation(document), attribute);
}

Style* getStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    if (getStyle(getLocalRenderInformation(document, 0, renderIndex), attribute))
        return getStyle(getLocalRenderInformation(document, 0, renderIndex), attribute);

    return getStyle(getGlobalRenderInformation(document, renderIndex), attribute);
}

Style* getStyleById(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getStyleById(getLocalRenderInformation(document), graphicalObject);
}

Style* getStyleById(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    return getStyleById(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);
}

Style* getStyleById(SBMLDocument* document, const std::string& id) {
    return getStyleById(getLocalRenderInformation(document), id);
}

Style* getStyleById(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    return getStyleById(getLocalRenderInformation(document, 0, renderIndex), id);
}

Style* getStyleByRole(SBMLDocument* document, GraphicalObject* graphicalObject) {
    if (getStyleByRole(getLocalRenderInformation(document), graphicalObject))
        return getStyleByRole(getLocalRenderInformation(document), graphicalObject);

    return getStyleByRole(getGlobalRenderInformation(document), graphicalObject);
}

Style* getStyleByRole(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    if (getStyleByRole(getLocalRenderInformation(document, 0, renderIndex), graphicalObject))
        return getStyleByRole(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);

    return getStyleByRole(getGlobalRenderInformation(document, renderIndex), graphicalObject);
}

Style* getStyleByRole(SBMLDocument* document, const std::string& role) {
    if (getStyleByRole(getLocalRenderInformation(document), role))
        return getStyleByRole(getLocalRenderInformation(document), role);

    return getStyleByRole(getGlobalRenderInformation(document), role);
}

Style* getStyleByRole(SBMLDocument* document, unsigned int renderIndex, const std::string& role) {
    if (getStyleByRole(getLocalRenderInformation(document, 0, renderIndex), role))
        return getStyleByRole(getLocalRenderInformation(document, 0, renderIndex), role);

    return getStyleByRole(getGlobalRenderInformation(document, renderIndex), role);
}

Style* getStyleByType(SBMLDocument* document, GraphicalObject* graphicalObject) {
    if (getStyleByType(getLocalRenderInformation(document), graphicalObject))
        return getStyleByType(getLocalRenderInformation(document), graphicalObject);

    return getStyleByType(getGlobalRenderInformation(document), graphicalObject);
}

Style* getStyleByType(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    if (getStyleByType(getLocalRenderInformation(document, 0, renderIndex), graphicalObject))
        return getStyleByType(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);

    return getStyleByType(getGlobalRenderInformation(document, renderIndex), graphicalObject);
}

Style* getStyleByType(SBMLDocument* document, const std::string& type) {
    if (getStyleByType(getLocalRenderInformation(document), type))
        return getStyleByType(getLocalRenderInformation(document), type);

    return getStyleByType(getGlobalRenderInformation(document), type);
}

Style* getStyleByType(SBMLDocument* document, unsigned int renderIndex, const std::string& type) {
    if (getStyleByType(getLocalRenderInformation(document, 0, renderIndex), type))
    return getStyleByType(getLocalRenderInformation(document, 0, renderIndex), type);

    return getStyleByType(getGlobalRenderInformation(document, renderIndex), type);
}

RenderGroup* getRenderGroup(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getRenderGroup(getStyle(document, graphicalObject));
}

RenderGroup* getRenderGroup(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    return getRenderGroup(getStyle(document, renderIndex, graphicalObject));
}

RenderGroup* getRenderGroup(SBMLDocument* document, const std::string& attribute) {
    return getRenderGroup(getStyle(document, attribute));
}

RenderGroup* getRenderGroup(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    return getRenderGroup(getStyle(document, renderIndex, attribute));
}

bool isSetStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetStrokeColor(getStyle(document, graphicalObject));
}

bool isSetStrokeColor(SBMLDocument* document, const std::string& attribute) {
    return isSetStrokeColor(getStyle(document, attribute));
}

const std::string getStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getStrokeColor(getStyle(document, graphicalObject));
}

const std::string getStrokeColor(SBMLDocument* document, const std::string& attribute) {
    return getStrokeColor(getStyle(document, attribute));
}

int setStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& stroke) {
    return setStrokeColor(getStyle(document, graphicalObject), stroke);
}

int setStrokeColor(SBMLDocument* document, const std::string& attribute, std::string& stroke) {
    return setStrokeColor(getStyle(document, attribute), stroke);
}

bool isSetStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetStrokeWidth(getStyle(document, graphicalObject));
}

bool isSetStrokeWidth(SBMLDocument* document, const std::string& attribute) {
    return isSetStrokeWidth(getStyle(document, attribute));
}

const double getStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getStrokeWidth(getStyle(document, graphicalObject));
}

const double getStrokeWidth(SBMLDocument* document, const std::string& attribute) {
    return getStrokeWidth(getStyle(document, attribute));
}

int setStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const double& strokeWidth) {
    return setStrokeWidth(getStyle(document, graphicalObject), strokeWidth);
}

int setStrokeWidth(SBMLDocument* document, const std::string& attribute, const double& strokeWidth) {
    return setStrokeWidth(getStyle(document, attribute), strokeWidth);
}

bool isSetStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetStrokeDashArray(getStyle(document, graphicalObject));
}

bool isSetStrokeDashArray(SBMLDocument* document, const std::string& attribute) {
    return isSetStrokeDashArray(getStyle(document, attribute));
}

const std::vector<unsigned int> getStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getStrokeDashArray(getStyle(document, graphicalObject));
}

const std::vector<unsigned int> getStrokeDashArray(SBMLDocument* document, const std::string& attribute) {
    return getStrokeDashArray(getStyle(document, attribute));
}

int setStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyle(document, graphicalObject), strokeDashArray);
}

int setStrokeDashArray(SBMLDocument* document, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyle(document, attribute), strokeDashArray);
}

unsigned int getNumStrokeDashes(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getNumStrokeDashes(getStyle(document, graphicalObject));
}

unsigned int getNumStrokeDashes(SBMLDocument* document, const std::string& attribute) {
    return getNumStrokeDashes(getStyle(document, attribute));
}

unsigned int getStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int strokeDashIndex) {
    return getStrokeDash(getStyle(document, graphicalObject), strokeDashIndex);
}

unsigned int getStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int strokeDashIndex) {
    return getStrokeDash(getStyle(document, attribute), strokeDashIndex);
}

unsigned int setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dash) {
    return setStrokeDash(getStyle(document, graphicalObject), dash);
}

unsigned int setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getStyle(document, graphicalObject), strokeDashIndex, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dash) {
    return setStrokeDash(getStyle(document, attribute), dash);
}

unsigned int setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getStyle(document, attribute), strokeDashIndex, dash);
}

bool isSetFontColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFontColor(getStyle(document, graphicalObject));
}

bool isSetFontColor(SBMLDocument* document, const std::string& attribute) {
    return isSetFontColor(getStyle(document, attribute));
}

const std::string getFontColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFontColor(getStyle(document, graphicalObject));
}

const std::string getFontColor(SBMLDocument* document, const std::string& attribute) {
    return getFontColor(getStyle(document, attribute));
}

int setFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& fontColor) {
    return setFontColor(getStyle(document, graphicalObject), fontColor);
}

int setFontColor(SBMLDocument* document, const std::string& attribute, std::string& fontColor) {
    return setFontColor(getStyle(document, attribute), fontColor);
}

bool isSetFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFontFamily(getStyle(document, graphicalObject));
}

bool isSetFontFamily(SBMLDocument* document, const std::string& attribute) {
    return isSetFontFamily(getStyle(document, attribute));
}

const std::string getFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFontFamily(getStyle(document, graphicalObject));
}

const std::string getFontFamily(SBMLDocument* document, const std::string& attribute) {
    return getFontFamily(getStyle(document, attribute));
}

int setFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& fontFamily) {
    return setFontFamily(getStyle(document, graphicalObject), fontFamily);
}

int setFontFamily(SBMLDocument* document, const std::string& attribute, std::string& fontFamily) {
    return setFontFamily(getStyle(document, attribute), fontFamily);
}

bool isSetFontSize(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFontSize(getStyle(document, graphicalObject));
}

bool isSetFontSize(SBMLDocument* document, const std::string& attribute) {
    return isSetFontSize(getStyle(document, attribute));
}

const RelAbsVector getFontSize(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFontSize(getStyle(document, graphicalObject));
}

const RelAbsVector getFontSize(SBMLDocument* document, const std::string& attribute) {
    return getFontSize(getStyle(document, attribute));
}

int setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& fontSize) {
    return setFontSize(getStyle(document, graphicalObject) , fontSize);
}

int setFontSize(SBMLDocument* document, const std::string& attribute, const RelAbsVector& fontSize) {
    return setFontSize(getStyle(document, attribute) , fontSize);
}

bool isSetFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFontWeight(getStyle(document, graphicalObject));
}

bool isSetFontWeight(SBMLDocument* document, const std::string& attribute) {
    return isSetFontWeight(getStyle(document, attribute));
}

const std::string getFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFontWeight(getStyle(document, graphicalObject));
}

const std::string getFontWeight(SBMLDocument* document, const std::string& attribute) {
    return getFontWeight(getStyle(document, attribute));
}

int setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& fontWeight) {
    return setFontWeight(getStyle(document, graphicalObject), fontWeight);
}

int setFontWeight(SBMLDocument* document, const std::string& attribute, std::string& fontWeight) {
    return setFontWeight(getStyle(document, attribute), fontWeight);
}

bool isSetFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFontStyle(getStyle(document, graphicalObject));
}

bool isSetFontStyle(SBMLDocument* document, const std::string& attribute) {
    return isSetFontStyle(getStyle(document, attribute));
}

const std::string getFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFontStyle(getStyle(document, graphicalObject));
}

const std::string getFontStyle(SBMLDocument* document, const std::string& attribute) {
    return getFontStyle(getStyle(document, attribute));
}

int setFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& fontStyle) {
    return setFontStyle(getStyle(document, graphicalObject), fontStyle);
}

int setFontStyle(SBMLDocument* document, const std::string& attribute, std::string& fontStyle) {
    return setFontStyle(getStyle(document, attribute), fontStyle);
}

bool isSetTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetTextAnchor(getStyle(document, graphicalObject));
}

bool isSetTextAnchor(SBMLDocument* document, const std::string& attribute) {
    return isSetTextAnchor(getStyle(document, attribute));
}

const std::string getTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getTextAnchor(getStyle(document, graphicalObject));
}

const std::string getTextAnchor(SBMLDocument* document, const std::string& attribute) {
    return getTextAnchor(getStyle(document, attribute));
}

int setTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& textAnchor) {
    return setTextAnchor(getStyle(document, graphicalObject), textAnchor);
}

int setTextAnchor(SBMLDocument* document, const std::string& attribute, std::string& textAnchor) {
    return setTextAnchor(getStyle(document, attribute), textAnchor);
}

bool isSetVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetVTextAnchor(getStyle(document, graphicalObject));
}

bool isSetVTextAnchor(SBMLDocument* document, const std::string& attribute) {
    return isSetVTextAnchor(getStyle(document, attribute));
}

const std::string getVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getVTextAnchor(getStyle(document, graphicalObject));
}

const std::string getVTextAnchor(SBMLDocument* document, const std::string& attribute) {
    return getVTextAnchor(getStyle(document, attribute));
}

int setVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& vtextAnchor) {
    return setVTextAnchor(getStyle(document, graphicalObject), vtextAnchor);
}

int setVTextAnchor(SBMLDocument* document, const std::string& attribute, std::string& vtextAnchor) {
    return setVTextAnchor(getStyle(document, attribute), vtextAnchor);
}

bool isSetFillColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFillColor(getStyle(document, graphicalObject));
}

bool isSetFillColor(SBMLDocument* document, const std::string& attribute) {
    return isSetFillColor(getStyle(document, attribute));
}

const std::string getFillColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFillColor(getStyle(document, graphicalObject));
}

const std::string getFillColor(SBMLDocument* document, const std::string& attribute) {
    return getFillColor(getStyle(document, attribute));
}

int setFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& fillColor) {
    return setFillColor(getStyle(document, graphicalObject), fillColor);
}

int setFillColor(SBMLDocument* document, const std::string& attribute, std::string& fillColor) {
    return setFillColor(getStyle(document, attribute), fillColor);
}

bool isSetFillRule(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetFillRule(getStyle(document, graphicalObject));
}

bool isSetFillRule(SBMLDocument* document, const std::string& attribute) {
    return isSetFillRule(getStyle(document, attribute));
}

const std::string getFillRule(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getFillRule(getStyle(document, graphicalObject));
}

const std::string getFillRule(SBMLDocument* document, const std::string& attribute) {
    return getFillRule(getStyle(document, attribute));
}

int setFillRule(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& fillColor) {
    return setFillRule(getStyle(document, graphicalObject), fillColor);
}

int setFillRule(SBMLDocument* document, const std::string& attribute, std::string& fillColor) {
    return setFillRule(getStyle(document, attribute), fillColor);
}

bool isSetStartHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetStartHead(getStyle(document, graphicalObject));
}

bool isSetStartHead(SBMLDocument* document, const std::string& attribute) {
    return isSetStartHead(getStyle(document, attribute));
}

const std::string getStartHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getStartHead(getStyle(document, graphicalObject));
}

const std::string getStartHead(SBMLDocument* document, const std::string& attribute) {
    return getStartHead(getStyle(document, attribute));
}

int setStartHead(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& startHead) {
    return setStartHead(getStyle(document, graphicalObject), startHead);
}

int setStartHead(SBMLDocument* document, const std::string& attribute, std::string& startHead) {
    return setStartHead(getStyle(document, attribute), startHead);
}

bool isSetEndHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return isSetEndHead(getStyle(document, graphicalObject));
}

bool isSetEndHead(SBMLDocument* document, const std::string& attribute) {
    return isSetEndHead(getStyle(document, attribute));
}

const std::string getEndHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getEndHead(getStyle(document, graphicalObject));
}

const std::string getEndHead(SBMLDocument* document, const std::string& attribute) {
    return getEndHead(getStyle(document, attribute));
}

int setEndHead(SBMLDocument* document, GraphicalObject* graphicalObject, std::string& endHead) {
    return setEndHead(getStyle(document, graphicalObject), endHead);
}

int setEndHead(SBMLDocument* document, const std::string& attribute, std::string& endHead) {
    return setEndHead(getStyle(document, attribute), endHead);
}

unsigned int getNumGeometricShapes(SBMLDocument* document, GraphicalObject* graphicalObject) {
    return getNumGeometricShapes(getStyle(document, graphicalObject));
}

unsigned int getNumGeometricShapes(SBMLDocument* document, const std::string& attribute) {
    return getNumGeometricShapes(getStyle(document, attribute));
}

Transformation2D* getGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShape(getStyle(document, graphicalObject), geometricShapeIndex);
}

Transformation2D* getGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShape(getStyle(document, attribute), geometricShapeIndex);
}

int addGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& shape) {
    return addGeometricShape(getStyle(document, graphicalObject), shape);
}

int addGeometricShape(SBMLDocument* document, const std::string& attribute, const std::string& shape) {
    return addGeometricShape(getStyle(document, attribute), shape);
}

Transformation2D* removeGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getStyle(document, graphicalObject), geometricShapeIndex);
}

Transformation2D* removeGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getStyle(document, attribute), geometricShapeIndex);
}


}
