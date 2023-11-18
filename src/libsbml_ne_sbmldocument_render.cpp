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
    if (!createDefaultGlobalRenderInformation(document) && !createDefaultLocalRenderInformation(document))
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
    else if (getStyle(getLocalRenderInformation(document), getGraphicalObject(document, attribute)))
        return getStyle(getLocalRenderInformation(document), getGraphicalObject(document, attribute));

    return getStyle(getGlobalRenderInformation(document), attribute);
}

Style* getStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    if (getStyle(getLocalRenderInformation(document, 0, renderIndex), attribute))
        return getStyle(getLocalRenderInformation(document, 0, renderIndex), attribute);
    else if (getStyle(getLocalRenderInformation(document, 0, renderIndex), getGraphicalObject(document, 0, attribute)))
        return getStyle(getLocalRenderInformation(document, 0, renderIndex), getGraphicalObject(document, 0, attribute));

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
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetStrokeColor(getGeometricShape(style));

    return isSetStrokeColor(style);
}

bool isSetStrokeColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetStrokeColor(getGeometricShape(style));

    return isSetStrokeColor(style);
}

const std::string getStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeColor(getGeometricShape(style));

    return getStrokeColor(style);
}

const std::string getStrokeColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeColor(getGeometricShape(style));

    return getStrokeColor(style);
}

int setStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& stroke) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeColor(getGeometricShape(style), stroke);

    return setStrokeColor(style, stroke);
}

int setStrokeColor(SBMLDocument* document, const std::string& attribute, const std::string& stroke) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeColor(getGeometricShape(style), stroke);

    return setStrokeColor(style, stroke);
}

bool isSetStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetStrokeWidth(getGeometricShape(style));

    return isSetStrokeWidth(style);
}

bool isSetStrokeWidth(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetStrokeWidth(getGeometricShape(style));

    return isSetStrokeWidth(style);
}

const double getStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeWidth(getGeometricShape(style));

    return getStrokeWidth(style);
}

const double getStrokeWidth(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeWidth(getGeometricShape(style));

    return getStrokeWidth(style);
}

int setStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const double& strokeWidth) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeWidth(getGeometricShape(style), strokeWidth);

    return setStrokeWidth(style, strokeWidth);
}

int setStrokeWidth(SBMLDocument* document, const std::string& attribute, const double& strokeWidth) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeWidth(getGeometricShape(style), strokeWidth);

    return setStrokeWidth(style, strokeWidth);
}

bool isSetStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetStrokeDashArray(getGeometricShape(style));

    return isSetStrokeDashArray(style);
}

bool isSetStrokeDashArray(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetStrokeDashArray(getGeometricShape(style));

    return isSetStrokeDashArray(style);
}

const std::vector<unsigned int> getStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeDashArray(getGeometricShape(style));

    return getStrokeDashArray(style);
}

const std::vector<unsigned int> getStrokeDashArray(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeDashArray(getGeometricShape(style));

    return getStrokeDashArray(style);
}

int setStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDashArray(getGeometricShape(style), strokeDashArray);

    return setStrokeDashArray(style, strokeDashArray);
}

int setStrokeDashArray(SBMLDocument* document, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDashArray(getGeometricShape(style), strokeDashArray);

    return setStrokeDashArray(style, strokeDashArray);
}

unsigned int getNumStrokeDashes(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getNumStrokeDashes(getGeometricShape(style));

    return getNumStrokeDashes(style);
}

unsigned int getNumStrokeDashes(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getNumStrokeDashes(getGeometricShape(style));

    return getNumStrokeDashes(style);
}

unsigned int getStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int strokeDashIndex) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeDash(getGeometricShape(style), strokeDashIndex);

    return getStrokeDash(style, strokeDashIndex);
}

unsigned int getStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int strokeDashIndex) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getStrokeDash(getGeometricShape(style), strokeDashIndex);

    return getStrokeDash(style, strokeDashIndex);
}

unsigned int setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dash) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDash(getGeometricShape(style), dash);

    return setStrokeDash(style, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int strokeDashIndex, unsigned int dash) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDash(getGeometricShape(style), strokeDashIndex, dash);

    return setStrokeDash(style, strokeDashIndex, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dash) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDash(getGeometricShape(style), dash);

    return setStrokeDash(style, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int strokeDashIndex, unsigned int dash) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDash(getGeometricShape(style), strokeDashIndex, dash);

    return setStrokeDash(style, strokeDashIndex, dash);
}

bool isSetFontColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontColor(getGeometricShape(style));

    return isSetFontColor(style);
}

bool isSetFontColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontColor(getGeometricShape(style));

    return isSetFontColor(style);
}

const std::string getFontColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFontColor(getGeometricShape(style));

    return getFontColor(style);
}

const std::string getFontColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFontColor(getGeometricShape(style));

    return getFontColor(style);
}

int setFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontColor) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFontColor(getGeometricShape(style), fontColor);

    return setFontColor(style, fontColor);
}

int setFontColor(SBMLDocument* document, const std::string& attribute, const std::string& fontColor) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFontColor(getGeometricShape(style), fontColor);

    return setFontColor(style, fontColor);
}

bool isSetFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontFamily(getGeometricShape(style));

    return isSetFontFamily(style);
}

bool isSetFontFamily(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontFamily(getGeometricShape(style));

    return isSetFontFamily(style);
}

const std::string getFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFontFamily(getGeometricShape(style));

    return getFontFamily(style);
}

const std::string getFontFamily(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFontFamily(getGeometricShape(style));

    return getFontFamily(style);
}

int setFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontFamily) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFontFamily(getGeometricShape(style), fontFamily);

    return setFontFamily(style, fontFamily);
}

int setFontFamily(SBMLDocument* document, const std::string& attribute, const std::string& fontFamily) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFontFamily(getGeometricShape(style), fontFamily);

    return setFontFamily(style, fontFamily);
}

bool isSetFontSize(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontSize(getGeometricShape(style));

    return isSetFontSize(style);
}

bool isSetFontSize(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontSize(getGeometricShape(style));

    return isSetFontSize(style);
}

const RelAbsVector getFontSize(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFontSize(getGeometricShape(style));

    return getFontSize(style);
}

const RelAbsVector getFontSize(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFontSize(getGeometricShape(style));

    return getFontSize(style);
}

int setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& fontSize) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFontSize(getGeometricShape(style), fontSize);

    return setFontSize(style, fontSize);
}

int setFontSize(SBMLDocument* document, const std::string& attribute, const RelAbsVector& fontSize) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFontSize(getGeometricShape(style), fontSize);

    return setFontSize(style, fontSize);
}

bool isSetFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontWeight(getGeometricShape(style));

    return isSetFontWeight(style);
}

bool isSetFontWeight(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontWeight(getGeometricShape(style));

    return isSetFontWeight(style);
}

const std::string getFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFontWeight(getGeometricShape(style));

    return getFontWeight(style);
}

const std::string getFontWeight(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFontWeight(getGeometricShape(style));

    return getFontWeight(style);
}

int setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontWeight) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFontWeight(getGeometricShape(style), fontWeight);

    return setFontWeight(style, fontWeight);
}

int setFontWeight(SBMLDocument* document, const std::string& attribute, const std::string& fontWeight) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFontWeight(getGeometricShape(style), fontWeight);

    return setFontWeight(style, fontWeight);
}

bool isSetFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontStyle(getGeometricShape(style));

    return isSetFontStyle(style);
}

bool isSetFontStyle(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFontStyle(getGeometricShape(style));

    return isSetFontStyle(style);
}

const std::string getFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFontStyle(getGeometricShape(style));

    return getFontStyle(style);
}

const std::string getFontStyle(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFontStyle(getGeometricShape(style));

    return getFontStyle(style);
}

int setFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontStyle) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFontStyle(getGeometricShape(style), fontStyle);

    return setFontStyle(style, fontStyle);
}

int setFontStyle(SBMLDocument* document, const std::string& attribute, const std::string& fontStyle) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFontStyle(getGeometricShape(style), fontStyle);

    return setFontStyle(style, fontStyle);
}

bool isSetTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetTextAnchor(getGeometricShape(style));

    return isSetTextAnchor(style);
}

bool isSetTextAnchor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetTextAnchor(getGeometricShape(style));

    return isSetTextAnchor(style);
}

const std::string getTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getTextAnchor(getGeometricShape(style));

    return getTextAnchor(style);
}

const std::string getTextAnchor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getTextAnchor(getGeometricShape(style));

    return getTextAnchor(style);
}

int setTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& textAnchor) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setTextAnchor(getGeometricShape(style), textAnchor);

    return setTextAnchor(style, textAnchor);
}

int setTextAnchor(SBMLDocument* document, const std::string& attribute, const std::string& textAnchor) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setTextAnchor(getGeometricShape(style), textAnchor);

    return setTextAnchor(style, textAnchor);
}

bool isSetVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetVTextAnchor(getGeometricShape(style));

    return isSetVTextAnchor(style);
}

bool isSetVTextAnchor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetVTextAnchor(getGeometricShape(style));

    return isSetVTextAnchor(style);
}

const std::string getVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getVTextAnchor(getGeometricShape(style));

    return getVTextAnchor(style);
}

const std::string getVTextAnchor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getVTextAnchor(getGeometricShape(style));

    return getVTextAnchor(style);
}

int setVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& vtextAnchor) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setVTextAnchor(getGeometricShape(style), vtextAnchor);

    return setVTextAnchor(style, vtextAnchor);
}

int setVTextAnchor(SBMLDocument* document, const std::string& attribute, const std::string& vtextAnchor) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setVTextAnchor(getGeometricShape(style), vtextAnchor);

    return setVTextAnchor(style, vtextAnchor);
}

bool isSetFillColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFillColor(getGeometricShape(style));

    return isSetFillColor(style);
}

bool isSetFillColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFillColor(getGeometricShape(style));

    return isSetFillColor(style);
}

const std::string getFillColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFillColor(getGeometricShape(style));

    return getFillColor(style);
}

const std::string getFillColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFillColor(getGeometricShape(style));

    return getFillColor(style);
}

int setFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillColor) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFillColor(getGeometricShape(style), fillColor);

    return setFillColor(style, fillColor);
}

int setFillColor(SBMLDocument* document, const std::string& attribute, const std::string& fillColor) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFillColor(getGeometricShape(style), fillColor);

    return setFillColor(style, fillColor);
}

bool isSetFillRule(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetFillRule(getGeometricShape(style));

    return isSetFillRule(style);
}

bool isSetFillRule(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetFillRule(getGeometricShape(style));

    return isSetFillRule(style);
}

const std::string getFillRule(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getFillRule(getGeometricShape(style));

    return getFillRule(style);
}

const std::string getFillRule(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getFillRule(getGeometricShape(style));

    return getFillRule(style);
}

int setFillRule(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillRule) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setFillRule(getGeometricShape(style), fillRule);

    return setFillRule(style, fillRule);
}

int setFillRule(SBMLDocument* document, const std::string& attribute, const std::string& fillRule) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setFillRule(getGeometricShape(style), fillRule);

    return setFillRule(style, fillRule);
}

bool isSetStartHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetStartHead(getGeometricShape(style));

    return isSetStartHead(style);
}

bool isSetStartHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetStartHead(getGeometricShape(style));

    return isSetStartHead(style);
}

const std::string getStartHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getStartHead(getGeometricShape(style));

    return getStartHead(style);
}

const std::string getStartHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getStartHead(getGeometricShape(style));

    return getStartHead(style);
}

int setStartHead(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& startHead) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setStartHead(getGeometricShape(style), startHead);

    return setStartHead(style, startHead);
}

int setStartHead(SBMLDocument* document, const std::string& attribute, const std::string& startHead) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setStartHead(getGeometricShape(style), startHead);

    return setStartHead(style, startHead);
}

bool isSetEndHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return isSetEndHead(getGeometricShape(style));

    return isSetEndHead(style);
}

bool isSetEndHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return isSetEndHead(getGeometricShape(style));

    return isSetEndHead(style);
}

const std::string getEndHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return getEndHead(getGeometricShape(style));

    return getEndHead(style);
}

const std::string getEndHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return getEndHead(getGeometricShape(style));

    return getEndHead(style);
}

int setEndHead(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& endHead) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1)
        return setEndHead(getGeometricShape(style), endHead);

    return setEndHead(style, endHead);
}

int setEndHead(SBMLDocument* document, const std::string& attribute, const std::string& endHead) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1)
        return setEndHead(getGeometricShape(style), endHead);

    return setEndHead(style, endHead);
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

bool isRectangle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isRectangle(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isRectangle(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isRectangle(getStyle(document, attribute), geometricShapeIndex);
}

bool isEllipse(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isEllipse(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isEllipse(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isEllipse(getStyle(document, attribute), geometricShapeIndex);
}

bool isPolygon(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isPolygon(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isPolygon(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isPolygon(getStyle(document, attribute), geometricShapeIndex);
}

bool isRenderCurve(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isRenderCurve(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isRenderCurve(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isRenderCurve(getStyle(document, attribute), geometricShapeIndex);
}

bool isImage(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isImage(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isImage(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isImage(getStyle(document, attribute), geometricShapeIndex);
}

bool isText(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isText(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isText(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isText(getStyle(document, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex ) {
    return isSetGeometricShapeX(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex ) {
    return getGeometricShapeX(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(document, graphicalObject), 0, x);
}

int setGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(document, graphicalObject), geometricShapeIndex, x);
}

int setGeometricShapeX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(document, attribute), 0, x);
}

int setGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(document, attribute), geometricShapeIndex, x);
}

bool isSetGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(document, graphicalObject), 0, y);
}

int setGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(document, graphicalObject), geometricShapeIndex, y);
}

int setGeometricShapeY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(document, attribute), 0, y);
}

int setGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(document, attribute), geometricShapeIndex, y);
}

bool isSetGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(document, graphicalObject), 0, width);
}

int setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(document, graphicalObject), geometricShapeIndex, width);
}

int setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(document, attribute), 0, width);
}

int setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(document, attribute), geometricShapeIndex, width);
}

bool isSetGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(document, graphicalObject), 0, height);
}

int setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(document, graphicalObject), geometricShapeIndex, height);
}

int setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(document, attribute), 0, height);
}

int setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(document, attribute), geometricShapeIndex, height);
}

bool isSetGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getStyle(document, attribute), geometricShapeIndex);
}

const double getGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getStyle(document, graphicalObject), geometricShapeIndex);
}

const double getGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ratio) {
    return setGeometricShapeRatio(getStyle(document, graphicalObject), ratio);
}

int setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ratio) {
    return setGeometricShapeRatio(getStyle(document, graphicalObject), geometricShapeIndex, ratio);
}

int setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, const double& ratio) {
    return setGeometricShapeRatio(getStyle(document, attribute), ratio);
}

int setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ratio) {
    return setGeometricShapeRatio(getStyle(document, attribute), geometricShapeIndex, ratio);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(document, graphicalObject), rx);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(document, graphicalObject), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(document, attribute), rx);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(document, attribute), geometricShapeIndex, rx);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(document, graphicalObject), ry);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(document, graphicalObject), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(document, attribute), ry);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(document, attribute), geometricShapeIndex, ry);
}

bool isSetGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(document, graphicalObject), cx);
}

int setGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(document, graphicalObject), geometricShapeIndex, cx);
}

int setGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(document, attribute), cx);
}

int setGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(document, attribute), geometricShapeIndex, cx);
}

bool isSetGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& cy) {
    return setGeometricShapeCenterX(getStyle(document, graphicalObject), cy);
}

int setGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    return setGeometricShapeCenterX(getStyle(document, graphicalObject), geometricShapeIndex, cy);
}

int setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cy) {
    return setGeometricShapeCenterX(getStyle(document, attribute), cy);
}

int setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    return setGeometricShapeCenterX(getStyle(document, attribute), geometricShapeIndex, cy);
}

bool isSetGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(document, graphicalObject), rx);
}

int setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(document, graphicalObject), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(document, attribute), rx);
}

int setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(document, attribute), geometricShapeIndex, rx);
}

bool isSetGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getStyle(document, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(document, graphicalObject), ry);
}

int setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(document, graphicalObject), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(document, attribute), ry);
}

int setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(document, attribute), geometricShapeIndex, ry);
}

const unsigned int getGeometricShapeNumElements(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getStyle(document, graphicalObject), geometricShapeIndex);
}

const unsigned int getGeometricShapeNumElements(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getStyle(document, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

int setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(document, graphicalObject), x);
}

int setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(document, graphicalObject), elementIndex, x);
}

int setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(document, attribute), x);
}

int setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(document, attribute), elementIndex, x);
}

int setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(document, attribute), geometricShapeIndex, elementIndex, x);
}

const RelAbsVector getGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

int setGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(document, graphicalObject), y);
}

int setGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(document, graphicalObject), elementIndex, y);
}

int setGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(document, attribute), y);
}

int setGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(document, attribute), elementIndex, y);
}

int setGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(document, attribute), geometricShapeIndex, elementIndex, y);
}

const RelAbsVector getGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(document, graphicalObject), x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(document, graphicalObject), elementIndex, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(document, attribute), x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(document, attribute), elementIndex, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(document, attribute), geometricShapeIndex, elementIndex, x);
}

const RelAbsVector getGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex ) {
    return getGeometricShapeBasePoint1Y(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(document, graphicalObject), y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(document, graphicalObject), elementIndex, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(document, attribute), y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(document, attribute), elementIndex, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(document, attribute), geometricShapeIndex, elementIndex, y);
}

const RelAbsVector getGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(document, graphicalObject), x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(document, graphicalObject), elementIndex, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(document, attribute), x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(document, attribute), elementIndex, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(document, attribute), geometricShapeIndex, elementIndex, x);
}

const RelAbsVector getGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(document, graphicalObject), y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(document, graphicalObject), elementIndex, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(document, attribute), y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(document, attribute), elementIndex, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(document, attribute), geometricShapeIndex, elementIndex, y);
}

int addRenderPointToGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return addRenderPointToGeometricShape(getStyle(document, graphicalObject), geometricShapeIndex);
}

int addRenderPointToGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return addRenderPointToGeometricShape(getStyle(document, attribute), geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return addRenderCubicBezierToGeometricShape(getStyle(document, graphicalObject), geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return addRenderCubicBezierToGeometricShape(getStyle(document, attribute), geometricShapeIndex);
}

RenderPoint* removeElementFromGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return removeElementFromGeometricShape(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

RenderPoint* removeElementFromGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return removeElementFromGeometricShape(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

bool isRenderCubicBezier(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

bool isRenderCubicBezier(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

bool isSetGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getStyle(document, attribute), geometricShapeIndex);
}

const std::string getGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getStyle(document, graphicalObject), geometricShapeIndex);
}

const std::string getGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& href) {
    return setGeometricShapeHref(getStyle(document, graphicalObject), href);
}

int setGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getStyle(document, graphicalObject), geometricShapeIndex, href);
}

int setGeometricShapeHref(SBMLDocument* document, const std::string& attribute, const std::string& href) {
    return setGeometricShapeHref(getStyle(document, attribute), href);
}

int setGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getStyle(document, attribute), geometricShapeIndex, href);
}

}
