#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_layout_render.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_render.h"
#include "libsbmlnetwork_render_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

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
        globalRenderInformation->setId("libSBMLNetwork_Global_Render");
        globalRenderInformation->setBackgroundColor("white");
        addDefaultColors(globalRenderInformation);
        addDefaultLineEndings(globalRenderInformation);
        addGlobalStyles(globalRenderInformation);
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
        return setDefaultLocalRenderInformationFeatures(document, layout, localRenderInformation);
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
    addColor(getGlobalRenderInformation(document, renderIndex), backgroundColor);
    return setBackgroundColor(getGlobalRenderInformation(document, renderIndex), backgroundColor);
}

const unsigned int getNumGlobalColorDefinitions(SBMLDocument* document, unsigned int renderIndex) {
    return getNumColorDefinitions(getGlobalRenderInformation(document, renderIndex));
}

const std::string getNthGlobalColorDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int colorIndex) {
    ColorDefinition* colorDefinition = getColorDefinition(getGlobalRenderInformation(document, renderIndex), colorIndex);
    if (colorDefinition)
        return colorDefinition->getId();

    return "";
}

const unsigned int getNumLocalColorDefinitions(SBMLDocument* document, unsigned int renderIndex) {
    return getNumColorDefinitions(getLocalRenderInformation(document, 0, renderIndex));
}

const std::string getNthLocalColorDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int colorIndex) {
    ColorDefinition* colorDefinition = getColorDefinition(getLocalRenderInformation(document, 0, renderIndex), colorIndex);
    if (colorDefinition)
        return colorDefinition->getId();

    return "";
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

const unsigned int getNumGlobalGradientDefinitions(SBMLDocument* document, unsigned int renderIndex) {
    return getNumGradientDefinitions(getGlobalRenderInformation(document, renderIndex));
}

const unsigned int getNumLocalGradientDefinitions(SBMLDocument* document, unsigned int renderIndex) {
    return getNumGradientDefinitions(getLocalRenderInformation(document, 0, renderIndex));
}

const std::string getNthGlobalGradientDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int gradientIndex) {
    GradientBase* gradientDefinition = getGradientDefinition(getGlobalRenderInformation(document, renderIndex), gradientIndex);
    if (gradientDefinition)
        return gradientDefinition->getId();

    return "";
}

const std::string getNthLocalGradientDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int gradientIndex) {
    GradientBase* gradientDefinition = getGradientDefinition(getLocalRenderInformation(document, 0, renderIndex), gradientIndex);
    if (gradientDefinition)
        return gradientDefinition->getId();

    return "";
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

const RelAbsVector getOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex) {
    return getOffset(getGradientDefinition(document, sid), gradientStopIndex);
}

const RelAbsVector getOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex) {
    return getOffset(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
}

const double getOffsetAsDouble(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex) {
    return getOffsetAsDouble(getGradientDefinition(document, sid), gradientStopIndex);
}

const double getOffsetAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex) {
    return getOffsetAsDouble(getGradientDefinition(document, renderIndex, sid), gradientStopIndex);
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

int setOffsetAsDouble(SBMLDocument* document, const std::string& sid, const double& offset) {
    return setOffsetAsDouble(getGradientDefinition(document, sid), offset);
}

int setOffsetAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& offset) {
    return setOffsetAsDouble(getGradientDefinition(document, renderIndex, sid), offset);
}

int setOffsetAsDouble(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const double& offset) {
    return setOffsetAsDouble(getGradientDefinition(document, sid), gradientStopIndex, offset);
}

int setOffsetAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const double& offset) {
    return setOffsetAsDouble(getGradientDefinition(document, renderIndex, sid), gradientStopIndex, offset);
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

const double getLinearGradientX1AsDouble(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientX1AsDouble(getGradientDefinition(document, sid));
}

const double getLinearGradientX1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientX1AsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientX1(SBMLDocument* document, const std::string& sid, const RelAbsVector& x1) {
    return setLinearGradientX1(getGradientDefinition(document, sid), x1);
}

int setLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x1) {
    return setLinearGradientX1(getGradientDefinition(document, renderIndex, sid), x1);
}

int setLinearGradientX1AsDouble(SBMLDocument* document, const std::string& sid, const double& x1) {
    return setLinearGradientX1AsDouble(getGradientDefinition(document, sid), x1);
}

int setLinearGradientX1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& x1) {
    return setLinearGradientX1AsDouble(getGradientDefinition(document, renderIndex, sid), x1);
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

const double getLinearGradientX2AsDouble(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientX2AsDouble(getGradientDefinition(document, sid));
}

const double getLinearGradientX2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientX2AsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientX2(SBMLDocument* document, const std::string& sid, const RelAbsVector& x2) {
    return setLinearGradientX2(getGradientDefinition(document, sid), x2);
}

int setLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x2) {
    return setLinearGradientX2(getGradientDefinition(document, renderIndex, sid), x2);
}

int setLinearGradientX2AsDouble(SBMLDocument* document, const std::string& sid, const double& x2) {
    return setLinearGradientX2AsDouble(getGradientDefinition(document, sid), x2);
}

int setLinearGradientX2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& x2) {
    return setLinearGradientX2AsDouble(getGradientDefinition(document, renderIndex, sid), x2);
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

const double getLinearGradientY1AsDouble(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientY1AsDouble(getGradientDefinition(document, sid));
}

const double getLinearGradientY1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientY1AsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientY1(SBMLDocument* document, const std::string& sid, const RelAbsVector& y1) {
    return setLinearGradientY1(getGradientDefinition(document, sid), y1);
}

int setLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y1) {
    return setLinearGradientY1(getGradientDefinition(document, renderIndex, sid), y1);
}

int setLinearGradientY1AsDouble(SBMLDocument* document, const std::string& sid, const double& y1) {
    return setLinearGradientY1AsDouble(getGradientDefinition(document, sid), y1);
}

int setLinearGradientY1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& y1) {
    return setLinearGradientY1AsDouble(getGradientDefinition(document, renderIndex, sid), y1);
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

const double getLinearGradientY2AsDouble(SBMLDocument* document, const std::string& sid) {
    return getLinearGradientY2AsDouble(getGradientDefinition(document, sid));
}

const double getLinearGradientY2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLinearGradientY2AsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setLinearGradientY2(SBMLDocument* document, const std::string& sid, const RelAbsVector& y2) {
    return setLinearGradientY2(getGradientDefinition(document, sid), y2);
}

int setLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y2) {
    return setLinearGradientY2(getGradientDefinition(document, renderIndex, sid), y2);
}

int setLinearGradientY2AsDouble(SBMLDocument* document, const std::string& sid, const double& y2) {
    return setLinearGradientY2AsDouble(getGradientDefinition(document, sid), y2);
}

int setLinearGradientY2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& y2) {
    return setLinearGradientY2AsDouble(getGradientDefinition(document, renderIndex, sid), y2);
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

const double getRadialGradientCxAsDouble(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientCxAsDouble(getGradientDefinition(document, sid));
}

const double getRadialGradientCxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientCxAsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientCx(SBMLDocument* document, const std::string& sid, const RelAbsVector& cx) {
    return setRadialGradientCx(getGradientDefinition(document, sid), cx);
}

int setRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cx) {
    return setRadialGradientCx(getGradientDefinition(document, renderIndex, sid), cx);
}

int setRadialGradientCxAsDouble(SBMLDocument* document, const std::string& sid, const double& cx) {
    return setRadialGradientCxAsDouble(getGradientDefinition(document, sid), cx);
}

int setRadialGradientCxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& cx) {
    return setRadialGradientCxAsDouble(getGradientDefinition(document, renderIndex, sid), cx);
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

const double getRadialGradientCyAsDouble(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientCyAsDouble(getGradientDefinition(document, sid));
}

const double getRadialGradientCyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientCyAsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientCy(SBMLDocument* document, const std::string& sid, const RelAbsVector& cy) {
    return setRadialGradientCy(getGradientDefinition(document, sid), cy);
}

int setRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cy) {
    return setRadialGradientCy(getGradientDefinition(document, renderIndex, sid), cy);
}

int setRadialGradientCyAsDouble(SBMLDocument* document, const std::string& sid, const double& cy) {
    return setRadialGradientCy(getGradientDefinition(document, sid), cy);
}

int setRadialGradientCyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& cy) {
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

const double getRadialGradientFxAsDouble(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientFxAsDouble(getGradientDefinition(document, sid));
}

const double getRadialGradientFxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientFxAsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientFx(SBMLDocument* document, const std::string& sid, const RelAbsVector& fx) {
    return setRadialGradientFx(getGradientDefinition(document, sid), fx);
}

int setRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fx) {
    return setRadialGradientFx(getGradientDefinition(document, renderIndex, sid), fx);
}

int setRadialGradientFxAsDouble(SBMLDocument* document, const std::string& sid, const double& fx) {
    return setRadialGradientFxAsDouble(getGradientDefinition(document, sid), fx);
}

int setRadialGradientFxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& fx) {
    return setRadialGradientFxAsDouble(getGradientDefinition(document, renderIndex, sid), fx);
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

const double getRadialGradientFyAsDouble(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientFyAsDouble(getGradientDefinition(document, sid));
}

const double getRadialGradientFyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientFyAsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientFy(SBMLDocument* document, const std::string& sid, const RelAbsVector& fy) {
    return setRadialGradientFy(getGradientDefinition(document, sid), fy);
}

int setRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fy) {
    return setRadialGradientFy(getGradientDefinition(document, renderIndex, sid), fy);
}

int setRadialGradientFyAsDouble(SBMLDocument* document, const std::string& sid, const double& fy) {
    return setRadialGradientFyAsDouble(getGradientDefinition(document, sid), fy);
}

int setRadialGradientFyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& fy) {
    return setRadialGradientFyAsDouble(getGradientDefinition(document, renderIndex, sid), fy);
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

const double getRadialGradientRAsDouble(SBMLDocument* document, const std::string& sid) {
    return getRadialGradientRAsDouble(getGradientDefinition(document, sid));
}

const double getRadialGradientRAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRadialGradientRAsDouble(getGradientDefinition(document, renderIndex, sid));
}

int setRadialGradientR(SBMLDocument* document, const std::string& sid, const RelAbsVector& r) {
    return setRadialGradientR(getGradientDefinition(document, sid), r);
}

int setRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& r) {
    return setRadialGradientR(getGradientDefinition(document, renderIndex, sid), r);
}

int setRadialGradientRAsDouble(SBMLDocument* document, const std::string& sid, const double& r) {
    return setRadialGradientRAsDouble(getGradientDefinition(document, sid), r);
}

int setRadialGradientRAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& r) {
    return setRadialGradientRAsDouble(getGradientDefinition(document, renderIndex, sid), r);
}

const unsigned int getNumGlobalLineEndings(SBMLDocument* document, unsigned int renderIndex) {
    return getNumLineEndings(getGlobalRenderInformation(document, renderIndex));
}

const unsigned int getNumLocalLineEndings(SBMLDocument* document, unsigned int renderIndex) {
    return getNumLineEndings(getLocalRenderInformation(document, 0, renderIndex));
}

const std::string getNthGlobalLineEndingId(SBMLDocument* document, unsigned int renderIndex, unsigned int lineEndingIndex) {
    LineEnding* lineEnding = getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex);
    if (lineEnding)
        return lineEnding->getId();

    return "";
}

const std::string getNthLocalLineEndingId(SBMLDocument* document, unsigned int renderIndex, unsigned int lineEndingIndex) {
    LineEnding* lineEnding = getLineEnding(getLocalRenderInformation(document, 0, renderIndex), lineEndingIndex);
    if (lineEnding)
        return lineEnding->getId();

    return "";
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

BoundingBox* getLineEndingBoundingBox(SBMLDocument* document, const std::string& sid) {
    return getLineEndingBoundingBox(getLineEnding(document, sid));
}

BoundingBox* getLineEndingBoundingBox(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getLineEndingBoundingBox(getLineEnding(document, renderIndex, sid));
}

const double getLineEndingBoundingBoxX(SBMLDocument* document, const std::string& sid) {
    return getPositionX(getLineEndingBoundingBox(document, sid));
}

const double getLineEndingBoundingBoxX(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getPositionX(getLineEndingBoundingBox(document, renderIndex, sid));
}

int setLineEndingBoundingBoxX(SBMLDocument* document, const std::string& sid, double x) {
    return setPositionX(getLineEndingBoundingBox(document, sid), x);
}

int setLineEndingBoundingBoxX(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double x) {
    return setPositionX(getLineEndingBoundingBox(document, renderIndex, sid), x);
}

const double getLineEndingBoundingBoxY(SBMLDocument* document, const std::string& sid) {
    return getPositionY(getLineEndingBoundingBox(document, sid));
}

const double getLineEndingBoundingBoxY(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getPositionY(getLineEndingBoundingBox(document, renderIndex, sid));
}

int setLineEndingBoundingBoxY(SBMLDocument* document, const std::string& sid, double y) {
    return setPositionY(getLineEndingBoundingBox(document, sid), y);
}

int setLineEndingBoundingBoxY(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double y) {
    return setPositionY(getLineEndingBoundingBox(document, renderIndex, sid), y);
}

const double getLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& sid) {
    return getDimensionWidth(getLineEndingBoundingBox(document, sid));
}

const double getLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, sid));
}

int setLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& sid, double width) {
    return setDimensionWidth(getLineEndingBoundingBox(document, sid), width);
}

int setLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double width) {
    return setDimensionWidth(getLineEndingBoundingBox(document, renderIndex, sid), width);
}

const double getLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& sid) {
    return getDimensionHeight(getLineEndingBoundingBox(document, sid));
}

const double getLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, sid));
}

int setLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& sid, double height) {
    return setDimensionHeight(getLineEndingBoundingBox(document, sid), height);
}

int setLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double height) {
    return setDimensionHeight(getLineEndingBoundingBox(document, renderIndex, sid), height);
}

RenderGroup* getLineEndingRenderGroup(SBMLDocument* document, const std::string& sid) {
    return getRenderGroup(getLineEnding(document, sid));
}

RenderGroup* getLineEndingRenderGroup(SBMLDocument* document, unsigned int renderIndex, const std::string& sid) {
    return getRenderGroup(getLineEnding(document, renderIndex, sid));
}

bool isSetLineEndingStrokeColor(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && isSetStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, id))))
        return isSetStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return isSetStrokeColor(getLineEndingRenderGroup(document, id));
}

bool isSetLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && isSetStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))))
       return isSetStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return isSetStrokeColor(getLineEndingRenderGroup(document, renderIndex, id));
}

const std::string getLineEndingStrokeColor(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && !getStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, id))).empty())
        return getStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return getStrokeColor(getLineEndingRenderGroup(document, id));
}

const std::string getLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && !getStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))).empty())
        return getStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return getStrokeColor(getLineEndingRenderGroup(document, renderIndex, id));
}

int setLineEndingStrokeColor(SBMLDocument* document, const std::string& id, const std::string& strokeColor) {
    addColor(document, getLineEnding(document, id), strokeColor);
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, id)), strokeColor);

    return setStrokeColor(getLineEndingRenderGroup(document, id), strokeColor);
}

int setLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& strokeColor) {
    addColor(document, getLineEnding(document, renderIndex, id), strokeColor);
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setStrokeColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), strokeColor);

    return setStrokeColor(getLineEndingRenderGroup(document, renderIndex, id), strokeColor);
}

bool isSetLineEndingStrokeWidth(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && isSetStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, id))))
        return isSetStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return isSetStrokeWidth(getLineEndingRenderGroup(document, id));
}

bool isSetLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && isSetStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))))
        return isSetStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return isSetStrokeWidth(getLineEndingRenderGroup(document, renderIndex, id));
}

const double getLineEndingStrokeWidth(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && getStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, id))) > 0.01)
        return getStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return getStrokeWidth(getLineEndingRenderGroup(document, id));
}

const double getLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && getStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))) > 0.01)
        return getStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return getStrokeWidth(getLineEndingRenderGroup(document, renderIndex, id));
}

int setLineEndingStrokeWidth(SBMLDocument* document, const std::string& id, double strokeWidth) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, id)), strokeWidth);

    return setStrokeWidth(getLineEndingRenderGroup(document, id), strokeWidth);
}

int setLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, double strokeWidth) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setStrokeWidth(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), strokeWidth);

    return setStrokeWidth(getLineEndingRenderGroup(document, renderIndex, id), strokeWidth);
}

bool isSetLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && isSetStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, id))))
        return isSetStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return isSetStrokeDashArray(getLineEndingRenderGroup(document, id));
}

bool isSetLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && isSetStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))))
        return isSetStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return isSetStrokeDashArray(getLineEndingRenderGroup(document, renderIndex, id));
}

const std::vector<unsigned int> getLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && !getStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, id))).empty())
        return getStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return getStrokeDashArray(getLineEndingRenderGroup(document, id));
}

const std::vector<unsigned int> getLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && !getStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))).empty())
        return getStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return getStrokeDashArray(getLineEndingRenderGroup(document, renderIndex, id));
}

int setLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id, const std::vector<unsigned int>& strokeDashArray) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, id)), strokeDashArray);

    return setStrokeDashArray(getLineEndingRenderGroup(document, id), strokeDashArray);
}

int setLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::vector<unsigned int>& strokeDashArray) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setStrokeDashArray(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), strokeDashArray);

    return setStrokeDashArray(getLineEndingRenderGroup(document, renderIndex, id), strokeDashArray);
}

unsigned int getNumLineEndingStrokeDashes(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return getNumStrokeDashes(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return getNumStrokeDashes(getLineEndingRenderGroup(document, id));
}

unsigned int getNumLineEndingStrokeDashes(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return getNumStrokeDashes(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return getNumStrokeDashes(getLineEndingRenderGroup(document, renderIndex, id));
}

unsigned int getLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dashIndex) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return getStrokeDash(getGeometricShape(getLineEndingRenderGroup(document, id)), dashIndex);

    return getStrokeDash(getLineEndingRenderGroup(document, id), dashIndex);
}

unsigned int getLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dashIndex) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return getStrokeDash(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), dashIndex);

    return getStrokeDash(getLineEndingRenderGroup(document, renderIndex, id), dashIndex);
}

int setLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dash) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setStrokeDash(getGeometricShape(getLineEndingRenderGroup(document, id)), dash);

    return setStrokeDash(getLineEndingRenderGroup(document, id), dash);
}

int setLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dash) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setStrokeDash(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), dash);

    return setStrokeDash(getLineEndingRenderGroup(document, renderIndex, id), dash);
}


int setLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dashIndex, unsigned int dash) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setStrokeDash(getGeometricShape(getLineEndingRenderGroup(document, id)), dashIndex, dash);

    return setStrokeDash(getLineEndingRenderGroup(document, id), dashIndex, dash);
}

int setLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dashIndex, unsigned int dash) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setStrokeDash(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), dashIndex, dash);

    return setStrokeDash(getLineEndingRenderGroup(document, renderIndex, id), dashIndex, dash);
}

bool isSetLineEndingFillColor(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && isSetFillColor(getGeometricShape(getLineEndingRenderGroup(document, id))))
        return isSetFillColor(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return isSetFillColor(getLineEndingRenderGroup(document, id));
}

bool isSetLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && isSetFillColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))))
        return isSetFillColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return isSetFillColor(getLineEndingRenderGroup(document, renderIndex, id));
}

const std::string getLineEndingFillColor(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && !getFillColor(getGeometricShape(getLineEndingRenderGroup(document, id))).empty())
        return getFillColor(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return getFillColor(getLineEndingRenderGroup(document, id));
}

const std::string getLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && !getFillColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))).empty())
        return getFillColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return getFillColor(getLineEndingRenderGroup(document, renderIndex, id));
}

int setLineEndingFillColor(SBMLDocument* document, const std::string& id, const std::string& fillColor) {
    addColor(document, getLineEnding(document, id), fillColor);
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setFillColor(getGeometricShape(getLineEndingRenderGroup(document, id)), fillColor);

    return setFillColor(getLineEndingRenderGroup(document, id), fillColor);
}

int setLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& fillColor) {
    addColor(document, getLineEnding(document, renderIndex, id), fillColor);
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setFillColor(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), fillColor);

    return setFillColor(getLineEndingRenderGroup(document, renderIndex, id), fillColor);
}

bool isSetLineEndingFillRule(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && isSetFillRule(getGeometricShape(getLineEndingRenderGroup(document, id))))
        return isSetFillRule(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return isSetFillRule(getLineEndingRenderGroup(document, id));
}

bool isSetLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && isSetFillRule(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))))
        return isSetFillRule(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return isSetFillRule(getLineEndingRenderGroup(document, renderIndex, id));
}

const std::string getLineEndingFillRule(SBMLDocument* document, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1 && !getFillRule(getGeometricShape(getLineEndingRenderGroup(document, id))).empty())
        return getFillRule(getGeometricShape(getLineEndingRenderGroup(document, id)));

    return getFillRule(getLineEndingRenderGroup(document, id));
}

const std::string getLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1 && !getFillRule(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id))).empty())
        return getFillRule(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)));

    return getFillRule(getLineEndingRenderGroup(document, renderIndex, id));
}

int setLineEndingFillRule(SBMLDocument* document, const std::string& id, const std::string& fillRule) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, id)) == 1)
        return setFillRule(getGeometricShape(getLineEndingRenderGroup(document, id)), fillRule);

    return setFillRule(getLineEndingRenderGroup(document, id), fillRule);
}

int setLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& fillRule) {
    if (getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id)) == 1)
        return setFillRule(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id)), fillRule);

    return setFillRule(getLineEndingRenderGroup(document, renderIndex, id), fillRule);
}

unsigned int getNumLineEndingGeometricShapes(SBMLDocument* document, const std::string& id) {
    return getNumGeometricShapes(getLineEndingRenderGroup(document, id));
}

unsigned int getNumLineEndingGeometricShapes(SBMLDocument* document, unsigned int renderIndex, const std::string& id) {
    return getNumGeometricShapes(getLineEndingRenderGroup(document, renderIndex, id));
}

bool isLineEndingRectangle(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isRectangle(getGeometricShape(getLineEndingRenderGroup(document, id), geometricShapeIndex));
}

bool isLineEndingRectangle(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isRectangle(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex));
}

bool isLineEndingEllipse(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isEllipse(getGeometricShape(getLineEndingRenderGroup(document, id), geometricShapeIndex));
}

bool isLineEndingEllipse(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isEllipse(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex));
}

bool isLineEndingPolygon(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isPolygon(getGeometricShape(getLineEndingRenderGroup(document, id), geometricShapeIndex));
}

bool isLineEndingPolygon(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isPolygon(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex));
}

bool isLineEndingImage(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isImage(getGeometricShape(getLineEndingRenderGroup(document, id), geometricShapeIndex));
}

bool isLineEndingImage(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isImage(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex));
}

bool isLineEndingRenderCurve(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isRenderCurve(getGeometricShape(getLineEndingRenderGroup(document, id), geometricShapeIndex));
}

bool isLineEndingRenderCurve(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isRenderCurve(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex));
}

bool isLineEndingText(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isText(getGeometricShape(getLineEndingRenderGroup(document, id), geometricShapeIndex));
}

bool isLineEndingText(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isText(getGeometricShape(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex));
}

bool isSetLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector xVector = getLineEndingGeometricShapeX(document, id, geometricShapeIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * xVector.getRelativeValue();
}

const double getLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector xVector = getLineEndingGeometricShapeX(document, renderIndex, id, geometricShapeIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * xVector.getRelativeValue();
}

int setLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getLineEndingRenderGroup(document, id), geometricShapeIndex, x);
}

int setLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, x);
}

int setLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeXAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, x);
}

int setLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeXAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, x);
}

bool isSetLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector yVector = getLineEndingGeometricShapeY(document, id, geometricShapeIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * yVector.getRelativeValue();
}

const double getLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector yVector = getLineEndingGeometricShapeY(document, renderIndex, id, geometricShapeIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * yVector.getRelativeValue();
}

int setLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getLineEndingRenderGroup(document, id), geometricShapeIndex, y);
}

int setLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, y);
}

int setLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeYAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, y);
}

int setLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeYAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, y);
}

bool isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector widthVector = getLineEndingGeometricShapeWidth(document, id, geometricShapeIndex);
    return widthVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * widthVector.getRelativeValue();
}

const double getLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector widthVector = getLineEndingGeometricShapeWidth(document, renderIndex, id, geometricShapeIndex);
    return widthVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * widthVector.getRelativeValue();
}

int setLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getLineEndingRenderGroup(document, id), geometricShapeIndex, width);
}

int setLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, width);
}

int setLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& width) {
    return setGeometricShapeWidthAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, width);
}

int setLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& width) {
    return setGeometricShapeWidthAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, width);
}

bool isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector heightVector = getLineEndingGeometricShapeHeight(document, id, geometricShapeIndex);
    return heightVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * heightVector.getRelativeValue();
}

const double getLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector heightVector = getLineEndingGeometricShapeHeight(document, renderIndex, id, geometricShapeIndex);
    return heightVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * heightVector.getRelativeValue();
}

int setLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getLineEndingRenderGroup(document, id), geometricShapeIndex, height);
}

int setLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, height);
}

int setLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& height) {
    return setGeometricShapeHeightAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, height);
}

int setLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& height) {
    return setGeometricShapeHeightAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, height);
}

bool isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

int setLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, double ratio) {
    return setGeometricShapeRatio(getLineEndingRenderGroup(document, id), geometricShapeIndex, ratio);
}

int setLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, double ratio) {
    return setGeometricShapeRatio(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, ratio);
}

bool isSetLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector cornerCurvatureRadiusXVector = getLineEndingGeometricShapeCornerCurvatureRadiusX(document, id, geometricShapeIndex);
    return cornerCurvatureRadiusXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * cornerCurvatureRadiusXVector.getRelativeValue();
}

const double getLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector cornerCurvatureRadiusXVector = getLineEndingGeometricShapeCornerCurvatureRadiusX(document, renderIndex, id, geometricShapeIndex);
    return cornerCurvatureRadiusXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * cornerCurvatureRadiusXVector.getRelativeValue();
}

int setLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& cornerCurvatureRadiusX) {
    return setGeometricShapeCornerCurvatureRadiusX(getLineEndingRenderGroup(document, id), geometricShapeIndex, cornerCurvatureRadiusX);
}

int setLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& cornerCurvatureRadiusX) {
    return setGeometricShapeCornerCurvatureRadiusX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, cornerCurvatureRadiusX);
}

int setLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& cornerCurvatureRadiusX) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, cornerCurvatureRadiusX);
}

int setLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& cornerCurvatureRadiusX) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, cornerCurvatureRadiusX);
}

bool isSetLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector cornerCurvatureRadiusYVector = getLineEndingGeometricShapeCornerCurvatureRadiusY(document, id, geometricShapeIndex);
    return cornerCurvatureRadiusYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * cornerCurvatureRadiusYVector.getRelativeValue();
}

const double getLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector cornerCurvatureRadiusYVector = getLineEndingGeometricShapeCornerCurvatureRadiusY(document, renderIndex, id, geometricShapeIndex);
    return cornerCurvatureRadiusYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * cornerCurvatureRadiusYVector.getRelativeValue();
}

int setLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& cornerCurvatureRadiusY) {
    return setGeometricShapeCornerCurvatureRadiusY(getLineEndingRenderGroup(document, id), geometricShapeIndex, cornerCurvatureRadiusY);
}

int setLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& cornerCurvatureRadiusY) {
    return setGeometricShapeCornerCurvatureRadiusY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, cornerCurvatureRadiusY);
}

int setLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& cornerCurvatureRadiusY) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, cornerCurvatureRadiusY);
}

int setLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& cornerCurvatureRadiusY) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, cornerCurvatureRadiusY);
}

bool isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector cXVector = getLineEndingGeometricShapeCenterX(document, id, geometricShapeIndex);
    return cXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * cXVector.getRelativeValue();
}

const double getLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
   RelAbsVector xVector = getLineEndingGeometricShapeCenterX(document, renderIndex, id, geometricShapeIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * xVector.getRelativeValue();
}

int setLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerX) {
    return setGeometricShapeCenterX(getLineEndingRenderGroup(document, id), geometricShapeIndex, centerX);
}

int setLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerX) {
    return setGeometricShapeCenterX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, centerX);
}

int setLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& centerX) {
    return setGeometricShapeCenterXAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, centerX);
}

int setLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& centerX) {
    return setGeometricShapeCenterXAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, centerX);
}

bool isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector cYVector = getLineEndingGeometricShapeCenterY(document, id, geometricShapeIndex);
    return cYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * cYVector.getRelativeValue();
}

const double getLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector yVector = getLineEndingGeometricShapeCenterY(document, renderIndex, id, geometricShapeIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * yVector.getRelativeValue();
}

int setLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerY) {
    return setGeometricShapeCenterY(getLineEndingRenderGroup(document, id), geometricShapeIndex, centerY);
}

int setLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerY) {
    return setGeometricShapeCenterY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, centerY);
}

int setLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& centerY) {
    return setGeometricShapeCenterYAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, centerY);
}

int setLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& centerY) {
    return setGeometricShapeCenterYAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, centerY);
}

bool isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector rXVector = getLineEndingGeometricShapeRadiusX(document, id, geometricShapeIndex);
    return rXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * rXVector.getRelativeValue();
}

const double getLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector rXVector = getLineEndingGeometricShapeRadiusX(document, renderIndex, id, geometricShapeIndex);
    return rXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * rXVector.getRelativeValue();
}

int setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusX) {
    return setGeometricShapeRadiusX(getLineEndingRenderGroup(document, id), geometricShapeIndex, radiusX);
}

int setLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusX) {
    return setGeometricShapeRadiusX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, radiusX);
}

int setLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& radiusX) {
    return setGeometricShapeRadiusXAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, radiusX);
}

int setLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& radiusX) {
    return setGeometricShapeRadiusXAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, radiusX);
}

bool isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector rYVector = getLineEndingGeometricShapeRadiusY(document, id, geometricShapeIndex);
    return rYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * rYVector.getRelativeValue();
}

const double getLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    RelAbsVector rYVector = getLineEndingGeometricShapeRadiusY(document, renderIndex, id, geometricShapeIndex);
    return rYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * rYVector.getRelativeValue();
}

int setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusY) {
    return setGeometricShapeRadiusY(getLineEndingRenderGroup(document, id), geometricShapeIndex, radiusY);
}

int setLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusY) {
    return setGeometricShapeRadiusY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, radiusY);
}

int setLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& radiusY) {
    return setGeometricShapeRadiusYAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, radiusY);
}

int setLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& radiusY) {
    return setGeometricShapeRadiusYAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, radiusY);
}

const unsigned int getLineEndingGeometricShapeNumElements(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const unsigned int getLineEndingGeometricShapeNumElements(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

bool isLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex);
}

bool isLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex);
}

const RelAbsVector getLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex);
}

const RelAbsVector getLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex);
}

const double getLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector elementXVector = getLineEndingGeometricShapeElementX(document, id, geometricShapeIndex, elementIndex);
    return elementXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * elementXVector.getRelativeValue();
}

const double getLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector elementXVector = getLineEndingGeometricShapeElementX(document, renderIndex, id, geometricShapeIndex, elementIndex);
    return elementXVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * elementXVector.getRelativeValue();
}

int setLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, x);
}

int setLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, x);
}

int setLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    return setGeometricShapeElementXAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, x);
}

int setLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    return setGeometricShapeElementXAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, x);
}

const RelAbsVector getLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex);
}

const RelAbsVector getLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex);
}

const double getLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector elementYVector = getLineEndingGeometricShapeElementY(document, id, geometricShapeIndex, elementIndex);
    return elementYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * elementYVector.getRelativeValue();
}

const double getLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector elementYVector = getLineEndingGeometricShapeElementY(document, renderIndex, id, geometricShapeIndex, elementIndex);
    return elementYVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * elementYVector.getRelativeValue();
}

int setLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, y);
}

int setLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, y);
}

int setLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    return setGeometricShapeElementYAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, y);
}

int setLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    return setGeometricShapeElementYAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, y);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint1XVector = getLineEndingGeometricShapeBasePoint1X(document, id, geometricShapeIndex);
    return basePoint1XVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * basePoint1XVector.getRelativeValue();
}

const double getLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint1XVector = getLineEndingGeometricShapeBasePoint1X(document, renderIndex, id, geometricShapeIndex);
    return basePoint1XVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * basePoint1XVector.getRelativeValue();
}

int setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X) {
    return setGeometricShapeBasePoint1X(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint1X);
}

int setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X) {
    return setGeometricShapeBasePoint1X(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint1X);
}

int setLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X) {
    return setGeometricShapeBasePoint1XAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint1X);
}

int setLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X) {
    return setGeometricShapeBasePoint1XAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint1X);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint1YVector = getLineEndingGeometricShapeBasePoint1Y(document, id, geometricShapeIndex);
    return basePoint1YVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * basePoint1YVector.getRelativeValue();
}

const double getLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint1YVector = getLineEndingGeometricShapeBasePoint1Y(document, renderIndex, id, geometricShapeIndex);
    return basePoint1YVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * basePoint1YVector.getRelativeValue();
}

int setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y) {
    return setGeometricShapeBasePoint1Y(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint1Y);
}

int setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y) {
    return setGeometricShapeBasePoint1Y(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint1Y);
}

int setLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1Y) {
    return setGeometricShapeBasePoint1YAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint1Y);
}

int setLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1Y) {
    return setGeometricShapeBasePoint1YAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint1Y);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint2XVector = getLineEndingGeometricShapeBasePoint2X(document, id, geometricShapeIndex);
    return basePoint2XVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, id)) * basePoint2XVector.getRelativeValue();
}

const double getLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint2XVector = getLineEndingGeometricShapeBasePoint2X(document, renderIndex, id, geometricShapeIndex);
    return basePoint2XVector.getAbsoluteValue() + 0.01 * getDimensionWidth(getLineEndingBoundingBox(document, renderIndex, id)) * basePoint2XVector.getRelativeValue();
}

int setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X) {
    return setGeometricShapeBasePoint2X(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint2X);
}

int setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X) {
    return setGeometricShapeBasePoint2X(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint2X);
}

int setLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X) {
    return setGeometricShapeBasePoint2XAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint2X);
}

int setLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X) {
    return setGeometricShapeBasePoint2XAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint2X);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const RelAbsVector getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const double getLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint2YVector = getLineEndingGeometricShapeBasePoint2Y(document, id, geometricShapeIndex);
    return basePoint2YVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, id)) * basePoint2YVector.getRelativeValue();
}

const double getLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint2YVector = getLineEndingGeometricShapeBasePoint2Y(document, renderIndex, id, geometricShapeIndex);
    return basePoint2YVector.getAbsoluteValue() + 0.01 * getDimensionHeight(getLineEndingBoundingBox(document, renderIndex, id)) * basePoint2YVector.getRelativeValue();
}

int setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y) {
    return setGeometricShapeBasePoint2Y(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint2Y);
}

int setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y) {
    return setGeometricShapeBasePoint2Y(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint2Y);
}

int setLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y) {
    return setGeometricShapeBasePoint2YAsDouble(getLineEndingRenderGroup(document, id), geometricShapeIndex, elementIndex, basePoint2Y);
}

int setLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y) {
    return setGeometricShapeBasePoint2YAsDouble(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, elementIndex, basePoint2Y);
}

bool isSetLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

bool isSetLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

const std::string getLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getLineEndingRenderGroup(document, id), geometricShapeIndex);
}

const std::string getLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex);
}

int setLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getLineEndingRenderGroup(document, id), geometricShapeIndex, href);
}

int setLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getLineEndingRenderGroup(document, renderIndex, id), geometricShapeIndex, href);
}

Style* getStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = getGlobalStyle(document, graphicalObject);

    return style;
}

Style* getLocalStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
        Style* style = getStyle(getLocalRenderInformation(document, i), graphicalObject);
        if (style)
            return style;
    }

    return NULL;
}

Style* getGlobalStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
        Style* style = getStyle(getGlobalRenderInformation(document, i), graphicalObject);
        if (style)
            return style;
    }

    return NULL;
}

Style* createLocalStyle(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* globalStyle = getGlobalStyle(document, graphicalObject);
    return createLocalStyle(getLocalRenderInformation(document), globalStyle, graphicalObject);
}

Style* createLocalStyle(SBMLDocument* document, TextGlyph* textGlyph, GraphicalObject* graphicalObject) {
    Style* globalStyle = getGlobalStyle(document, graphicalObject);
    return createLocalStyle(getLocalRenderInformation(document), globalStyle, textGlyph);
}

Style* getStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    Style* style = getLocalStyle(document, renderIndex, graphicalObject);
    if (!style)
        style = getGlobalStyle(document, renderIndex, graphicalObject);

    return style;
}

Style* getLocalStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    return getStyle(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);
}

Style* getGlobalStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    return getStyle(getGlobalRenderInformation(document, renderIndex), graphicalObject);
}

Style* createLocalStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    Style* globalStyle = getGlobalStyle(document, renderIndex, graphicalObject);
    return createLocalStyle(getLocalRenderInformation(document, renderIndex), globalStyle, graphicalObject);
}

Style* getStyle(SBMLDocument* document, const std::string& attribute) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = getGlobalStyle(document, attribute);

    return style;
}

Style* getLocalStyle(SBMLDocument* document, const std::string& attribute) {
    for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
        Style* style = getStyle(getLocalRenderInformation(document, i), attribute);
        if (style)
            return style;
    }

    return getLocalStyle(document, getGraphicalObject(document, attribute));
}

Style* getGlobalStyle(SBMLDocument* document, const std::string& attribute) {
    for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
        Style* style = getStyle(getGlobalRenderInformation(document, i), attribute);
        if (style)
            return style;
    }

    return getGlobalStyle(document, getGraphicalObject(document, attribute));
}

Style* createLocalStyle(SBMLDocument* document, const std::string& attribute) {
    Style* globalStyle = getGlobalStyle(document, attribute);
    return createLocalStyle(getLocalRenderInformation(document), globalStyle, getGraphicalObject(document, attribute));
}

Style* getStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    Style* style = getLocalStyle(document, renderIndex, attribute);
    if (!style)
        style = getGlobalStyle(document, renderIndex, attribute);

    return style;
}

Style* getLocalStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    Style* style = getStyle(getLocalRenderInformation(document, 0, renderIndex), attribute);
    if (!style)
        style = getStyle(getLocalRenderInformation(document, 0, renderIndex), getGraphicalObject(document, 0, attribute));

    return style;
}

Style* getGlobalStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    return getStyle(getGlobalRenderInformation(document, renderIndex), attribute);
}

Style* createLocalStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute) {
    Style* globalStyle = getGlobalStyle(document, renderIndex, attribute);
    return createLocalStyle(getLocalRenderInformation(document, 0, renderIndex), globalStyle, getGraphicalObject(document, 0, attribute));
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
    Style* style = getStyleByRole(getLocalRenderInformation(document), graphicalObject);
    if (style)
        return style;

    return getStyleByRole(getGlobalRenderInformation(document), graphicalObject);
}

Style* getStyleByRole(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    Style* style = getStyleByRole(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);
    if (style)
        return style;

    return getStyleByRole(getGlobalRenderInformation(document, renderIndex), graphicalObject);
}

Style* getStyleByRole(SBMLDocument* document, const std::string& role) {
    Style* style = getStyleByRole(getLocalRenderInformation(document), role);
    if (style)
        return style;

    return getStyleByRole(getGlobalRenderInformation(document), role);
}

Style* getStyleByRole(SBMLDocument* document, unsigned int renderIndex, const std::string& role) {
    Style* style = getStyleByRole(getLocalRenderInformation(document, 0, renderIndex), role);
    if (style)
        return style;

    return getStyleByRole(getGlobalRenderInformation(document, renderIndex), role);
}

Style* getStyleByType(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyleByType(getLocalRenderInformation(document), graphicalObject);
    if (style)
        return style;

    return getStyleByType(getGlobalRenderInformation(document), graphicalObject);
}

Style* getStyleByType(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject) {
    Style* style = getStyleByType(getLocalRenderInformation(document, 0, renderIndex), graphicalObject);
    if (style)
        return style;

    return getStyleByType(getGlobalRenderInformation(document, renderIndex), graphicalObject);
}

Style* getStyleByType(SBMLDocument* document, const std::string& type) {
    Style* style = getStyleByType(getLocalRenderInformation(document), type);
    if (style)
        return style;

    return getStyleByType(getGlobalRenderInformation(document), type);
}

Style* getStyleByType(SBMLDocument* document, unsigned int renderIndex, const std::string& type) {
    Style* style = getStyleByType(getLocalRenderInformation(document, 0, renderIndex), type);
    if (style)
        return style;

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
    if (getNumGeometricShapes(style) == 1 && isSetStrokeColor(getGeometricShape(style)))
        return isSetStrokeColor(getGeometricShape(style));

    return isSetStrokeColor(style);
}

bool isSetStrokeColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isSetStrokeColor(getGeometricShape(style)))
        return isSetStrokeColor(getGeometricShape(style));

    return isSetStrokeColor(style);
}

const std::string getStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && !getStrokeColor(getGeometricShape(style)).empty())
        return getStrokeColor(getGeometricShape(style));

    return getStrokeColor(style);
}

const std::string getStrokeColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && !getStrokeColor(getGeometricShape(style)).empty())
        return getStrokeColor(getGeometricShape(style));

    return getStrokeColor(style);
}

int setStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& stroke) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    addColor(document, style, stroke);
    return setStrokeColor(style, stroke);
}

int setStrokeColor(SBMLDocument* document, const std::string& attribute, const std::string& stroke) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    addColor(document, style, stroke);
    return setStrokeColor(style, stroke);
}

int setCompartmentStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke) {
    if (!setCompartmentStrokeColor(getGlobalRenderInformation(document), stroke) && !setCompartmentStrokeColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), stroke))
        return 0;

    return -1;
}

int setSpeciesStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke) {
    if (!setSpeciesStrokeColor(getGlobalRenderInformation(document), stroke) && !setSpeciesStrokeColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), stroke))
        return 0;

    return -1;
}

int setReactionStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke, bool setSpeciesReferenceGlyphs) {
    if (!setReactionStrokeColor(getGlobalRenderInformation(document), stroke) && !setReactionStrokeColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), stroke)) {
        if (setSpeciesReferenceGlyphs) {
            if (!setSpeciesReferenceStrokeColor(getGlobalRenderInformation(document), stroke) && !setSpeciesReferenceStrokeColor(
                    getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), stroke))
                return 0;

            return -1;
        }

        return 0;
    }

    return -1;
}

int setLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke) {
    for (unsigned int renderIndex = 0; renderIndex < getNumLocalRenderInformation(document, layoutIndex); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getLocalRenderInformation(document, lineEndingIndex, renderIndex)); lineEndingIndex++) {
            if (setLineEndingStrokeColor(document, renderIndex, getLineEnding(getLocalRenderInformation(document, layoutIndex, renderIndex), lineEndingIndex)->getId(), stroke))
                return -1;
        }
    }
    for (unsigned int renderIndex = 0; renderIndex < getNumGlobalRenderInformation(document); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getGlobalRenderInformation(document, renderIndex)); lineEndingIndex++) {
            if (setLineEndingStrokeColor(document, renderIndex, getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex)->getId(), stroke))
                return -1;
        }
    }

    return 0;
}

int setStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke) {
    if (setCompartmentStrokeColor(document, layoutIndex, stroke))
        return -1;
    if (setSpeciesStrokeColor(document, layoutIndex, stroke))
        return -1;

    return 0;
}

bool isSetStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isSetStrokeWidth(getGeometricShape(style)))
        return isSetStrokeWidth(getGeometricShape(style));

    return isSetStrokeWidth(style);
}

bool isSetStrokeWidth(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isSetStrokeWidth(getGeometricShape(style)))
        return isSetStrokeWidth(getGeometricShape(style));

    return isSetStrokeWidth(style);
}

const double getStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && getStrokeWidth(getGeometricShape(style)) > 0.01)
        return getStrokeWidth(getGeometricShape(style));

    return getStrokeWidth(style);
}

const double getStrokeWidth(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && getStrokeWidth(getGeometricShape(style)) > 0.01)
        return getStrokeWidth(getGeometricShape(style));

    return getStrokeWidth(style);
}

int setStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const double& strokeWidth) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setStrokeWidth(style, strokeWidth);
}

int setStrokeWidth(SBMLDocument* document, const std::string& attribute, const double& strokeWidth) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setStrokeWidth(style, strokeWidth);
}

int setCompartmentStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth) {
    if (!setCompartmentStrokeWidth(getGlobalRenderInformation(document), strokeWidth) && !setCompartmentStrokeWidth(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), strokeWidth))
        return 0;

    return -1;
}

int setSpeciesStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth) {
    if (!setSpeciesStrokeWidth(getGlobalRenderInformation(document), strokeWidth) && !setSpeciesStrokeWidth(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), strokeWidth))
        return 0;

    return -1;
}

int setReactionStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth, bool setSpeciesReferenceGlyphs) {
    if (!setReactionStrokeWidth(getGlobalRenderInformation(document), strokeWidth) && !setReactionStrokeWidth(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), strokeWidth)) {
        if (setSpeciesReferenceGlyphs) {
            if (!setSpeciesReferenceStrokeWidth(getGlobalRenderInformation(document), strokeWidth) && !setSpeciesReferenceStrokeWidth(
                    getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), strokeWidth))
                return 0;

            return -1;
        }

        return 0;
    }

    return -1;
}

int setLineEndingStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth) {
    for (unsigned int renderIndex = 0; renderIndex < getNumLocalRenderInformation(document, layoutIndex); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getLocalRenderInformation(document, lineEndingIndex, renderIndex)); lineEndingIndex++) {
            if (setLineEndingStrokeWidth(document, renderIndex, getLineEnding(getLocalRenderInformation(document, layoutIndex, renderIndex), lineEndingIndex)->getId(), strokeWidth))
                return -1;
        }
    }
    for (unsigned int renderIndex = 0; renderIndex < getNumGlobalRenderInformation(document); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getGlobalRenderInformation(document, renderIndex)); lineEndingIndex++) {
            if (setLineEndingStrokeWidth(document, renderIndex, getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex)->getId(), strokeWidth))
                return -1;
        }
    }

    return 0;
}

int setStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth) {
    if (setCompartmentStrokeWidth(document, layoutIndex, strokeWidth))
        return -1;
    if (setSpeciesStrokeWidth(document, layoutIndex, strokeWidth))
        return -1;
    if (setReactionStrokeWidth(document, layoutIndex, strokeWidth))
        return -1;

    return 0;
}

bool isSetStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isSetStrokeDashArray(getGeometricShape(style)))
        return isSetStrokeDashArray(getGeometricShape(style));

    return isSetStrokeDashArray(style);
}

bool isSetStrokeDashArray(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isSetStrokeDashArray(getGeometricShape(style)))
        return isSetStrokeDashArray(getGeometricShape(style));

    return isSetStrokeDashArray(style);
}

const std::vector<unsigned int> getStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && getStrokeDashArray(getGeometricShape(style)).size())
        return getStrokeDashArray(getGeometricShape(style));

    return getStrokeDashArray(style);
}

const std::vector<unsigned int> getStrokeDashArray(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && getStrokeDashArray(getGeometricShape(style)).size())
        return getStrokeDashArray(getGeometricShape(style));

    return getStrokeDashArray(style);
}

int setStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setStrokeDashArray(style, strokeDashArray);
}

int setStrokeDashArray(SBMLDocument* document, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setStrokeDashArray(style, strokeDashArray);
}

unsigned int getNumStrokeDashes(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && getNumStrokeDashes(getGeometricShape(style)))
        return getNumStrokeDashes(getGeometricShape(style));

    return getNumStrokeDashes(style);
}

unsigned int getNumStrokeDashes(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && getNumStrokeDashes(getGeometricShape(style)))
        return getNumStrokeDashes(getGeometricShape(style));

    return getNumStrokeDashes(style);
}

unsigned int getStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dashIndex) {
    Style* style = getStyle(document, graphicalObject);

    return getStrokeDash(style, dashIndex);
}

unsigned int getStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dashIndex) {
    return getStrokeDash(getStyle(document, attribute), dashIndex);
}

unsigned int setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dash) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setStrokeDash(style, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dashIndex, unsigned int dash) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setStrokeDash(style, dashIndex, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dash) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setStrokeDash(style, dash);
}

unsigned int setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dashIndex, unsigned int dash) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setStrokeDash(style, dashIndex, dash);
}

bool isSetFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontColor(getGeometricShape(style));

    return isSetFontColor(style);
}

bool isSetFontColor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontColor(getGeometricShape(style));

    return isSetFontColor(style);
}

const std::string getFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontColor(getGeometricShape(style));

    return getFontColor(style);
}

const std::string getFontColor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontColor(getGeometricShape(style));

    return getFontColor(style);
}

int setFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontColor) {
    return setFontColor(document, graphicalObject, 0, fontColor);
}

int setFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontColor) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    addColor(document, style, fontColor);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontColor(getGeometricShape(style), fontColor);

    return setFontColor(style, fontColor);
}

int setFontColor(SBMLDocument* document, const std::string& attribute, const std::string& fontColor) {
    return setFontColor(document, attribute, 0, fontColor);
}

int setFontColor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontColor) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    addColor(document, style, fontColor);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontColor(getGeometricShape(style), fontColor);

    return setFontColor(style, fontColor);
}

int setCompartmentFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor) {
    if (!setCompartmentFontColor(getGlobalRenderInformation(document), fontColor) && !setCompartmentFontColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontColor))
        return 0;

    return -1;
}

int setSpeciesFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor) {
    if (!setSpeciesFontColor(getGlobalRenderInformation(document), fontColor) && !setSpeciesFontColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontColor))
        return 0;

    return -1;
}

int setReactionFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor) {
    if (!setReactionFontColor(getGlobalRenderInformation(document), fontColor) && !setReactionFontColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontColor))
        return 0;

    return -1;
}

int setFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor) {
    if (setCompartmentFontColor(document, layoutIndex, fontColor))
        return -1;
    if (setSpeciesFontColor(document, layoutIndex, fontColor))
        return -1;
    if (setReactionFontColor(document, layoutIndex, fontColor))
        return -1;

    return 0;
}

bool isSetFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontFamily(getGeometricShape(style));

    return isSetFontFamily(style);
}

bool isSetFontFamily(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontFamily(getGeometricShape(style));

    return isSetFontFamily(style);
}

const std::string getFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontFamily(getGeometricShape(style));

    return getFontFamily(style);
}

const std::string getFontFamily(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontFamily(getGeometricShape(style));

    return getFontFamily(style);
}

int setFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontFamily) {
    return setFontFamily(document, graphicalObject, 0, fontFamily);
}

int setFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontFamily) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontFamily(getGeometricShape(style), fontFamily);

    return setFontFamily(style, fontFamily);
}

int setFontFamily(SBMLDocument* document, const std::string& attribute, const std::string& fontFamily) {
    return setFontFamily(document, attribute, 0, fontFamily);
}

int setFontFamily(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontFamily) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontFamily(getGeometricShape(style), fontFamily);

    return setFontFamily(style, fontFamily);
}

int setCompartmentFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily) {
    if (!setCompartmentFontFamily(getGlobalRenderInformation(document), fontFamily) && !setCompartmentFontFamily(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontFamily))
        return 0;

    return -1;
}

int setSpeciesFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily) {
    if (!setSpeciesFontFamily(getGlobalRenderInformation(document), fontFamily) && !setSpeciesFontFamily(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontFamily))
        return 0;

    return -1;
}

int setReactionFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily) {
    if (!setReactionFontFamily(getGlobalRenderInformation(document), fontFamily) && !setReactionFontFamily(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontFamily))
        return 0;

    return -1;
}

int setFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily) {
    if (setCompartmentFontFamily(document, layoutIndex, fontFamily))
        return -1;
    if (setSpeciesFontFamily(document, layoutIndex, fontFamily))
        return -1;
    if (setReactionFontFamily(document, layoutIndex, fontFamily))
        return -1;

    return 0;
}

bool isSetFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontSize(getGeometricShape(style));

    return isSetFontSize(style);
}

bool isSetFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontSize(getGeometricShape(style));

    return isSetFontSize(style);
}

const RelAbsVector getFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontSize(getGeometricShape(style));

    return getFontSize(style);
}

const RelAbsVector getFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontSize(getGeometricShape(style));

    return getFontSize(style);
}

const double getFontSizeAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    RelAbsVector fontSizeVector = getFontSize(document, graphicalObject, textGlyphIndex);
    return fontSizeVector.getAbsoluteValue() + 0.5 * (getTextDimensionWidth(getLayout(document), graphicalObject, textGlyphIndex) + getTextDimensionHeight(getLayout(document), graphicalObject, textGlyphIndex)) * fontSizeVector.getRelativeValue();
}

const double getFontSizeAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    RelAbsVector fontSizeVector = getFontSize(document, attribute, textGlyphIndex);
    return fontSizeVector.getAbsoluteValue() + 0.5 * (getTextDimensionWidth(document, attribute, 0, textGlyphIndex) + getTextDimensionWidth(document, attribute, 0, textGlyphIndex)) * fontSizeVector.getRelativeValue();
}

int setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& fontSize) {
    return setFontSize(document, graphicalObject, 0, fontSize);
}

int setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const RelAbsVector& fontSize) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontSize(getGeometricShape(style), fontSize);

    return setFontSize(style, fontSize);
}

int setFontSize(SBMLDocument* document, const std::string& attribute, const RelAbsVector& fontSize) {
    return setFontSize(document, attribute, 0, fontSize);
}

int setFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const RelAbsVector& fontSize) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontSize(getGeometricShape(style), fontSize);

    return setFontSize(style, fontSize);
}

int setFontSizeAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& fontSize) {
    return setFontSizeAsDouble(document, graphicalObject, 0, fontSize);
}

int setFontSizeAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& fontSize) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontSizeAsDouble(getGeometricShape(style), fontSize);

    return setFontSizeAsDouble(style, fontSize);
}

int setFontSizeAsDouble(SBMLDocument* document, const std::string& attribute, const double& fontSize) {
    return setFontSizeAsDouble(document, attribute, 0, fontSize);
}

int setFontSizeAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const double& fontSize) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontSizeAsDouble(getGeometricShape(style), fontSize);

    return setFontSizeAsDouble(style, fontSize);
}

int setCompartmentFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize) {
    if (!setCompartmentFontSize(getGlobalRenderInformation(document), fontSize) && !setCompartmentFontSize(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontSize))
        return 0;

    return -1;
}

int setCompartmentFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize) {
    if (!setCompartmentFontSizeAsDouble(getGlobalRenderInformation(document), fontSize) && !setCompartmentFontSizeAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontSize))
        return 0;

    return -1;
}

int setSpeciesFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize) {
    if (!setSpeciesFontSize(getGlobalRenderInformation(document), fontSize) && !setSpeciesFontSize(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontSize))
        return 0;

    return -1;
}

int setSpeciesFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize) {
    if (!setSpeciesFontSizeAsDouble(getGlobalRenderInformation(document), fontSize) && !setSpeciesFontSizeAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontSize))
        return 0;

    return -1;
}

int setReactionFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize) {
    if (!setReactionFontSize(getGlobalRenderInformation(document), fontSize) && !setReactionFontSize(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontSize))
        return 0;

    return -1;
}

int setReactionFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize) {
    if (!setReactionFontSizeAsDouble(getGlobalRenderInformation(document), fontSize) && !setReactionFontSizeAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontSize))
        return 0;

    return -1;
}

int setFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize) {
    if (setSpeciesFontSize(document, layoutIndex, fontSize))
        return -1;
    if (setCompartmentFontSize(document, layoutIndex, fontSize))
        return -1;
    if (setReactionFontSize(document, layoutIndex, fontSize))
        return -1;

    return 0;
}

int setFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize) {
    if (setSpeciesFontSizeAsDouble(document, layoutIndex, fontSize))
        return -1;
    if (setCompartmentFontSizeAsDouble(document, layoutIndex, fontSize))
        return -1;
    if (setReactionFontSizeAsDouble(document, layoutIndex, fontSize))
        return -1;

    return 0;
}

bool isSetFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontWeight(getGeometricShape(style));

    return isSetFontWeight(style);
}

bool isSetFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontWeight(getGeometricShape(style));

    return isSetFontWeight(style);
}

const std::string getFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontWeight(getGeometricShape(style));

    return getFontWeight(style);
}

const std::string getFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontWeight(getGeometricShape(style));

    return getFontWeight(style);
}

int setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontWeight) {
    return setFontWeight(document, graphicalObject, 0, fontWeight);
}

int setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontWeight) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontWeight(getGeometricShape(style), fontWeight);

    return setFontWeight(style, fontWeight);
}

int setFontWeight(SBMLDocument* document, const std::string& attribute, const std::string& fontWeight) {
    return setFontWeight(document, attribute, 0, fontWeight);
}

int setFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontWeight) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontWeight(getGeometricShape(style), fontWeight);

    return setFontWeight(style, fontWeight);
}

int setCompartmentFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight) {
    if (!setCompartmentFontWeight(getGlobalRenderInformation(document), fontWeight) && !setCompartmentFontWeight(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontWeight))
        return 0;

    return -1;
}

int setSpeciesFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight) {
    if (!setSpeciesFontWeight(getGlobalRenderInformation(document), fontWeight) && !setSpeciesFontWeight(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontWeight))
        return 0;

    return -1;
}

int setReactionFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight) {
    if (!setReactionFontWeight(getGlobalRenderInformation(document), fontWeight) && !setReactionFontWeight(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontWeight))
        return 0;

    return -1;
}

int setFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight) {
    if (setCompartmentFontWeight(document, layoutIndex, fontWeight))
        return -1;
    if (setSpeciesFontWeight(document, layoutIndex, fontWeight))
        return -1;
    if (setReactionFontWeight(document, layoutIndex, fontWeight))
        return -1;

    return 0;
}

bool isSetFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontStyle(getGeometricShape(style));

    return isSetFontStyle(style);
}

bool isSetFontStyle(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetFontStyle(getGeometricShape(style));

    return isSetFontStyle(style);
}

const std::string getFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontStyle(getGeometricShape(style));

    return getFontStyle(style);
}

const std::string getFontStyle(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getFontStyle(getGeometricShape(style));

    return getFontStyle(style);
}

int setFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontStyle) {
    return setFontStyle(document, graphicalObject, 0, fontStyle);
}

int setFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontStyle) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontStyle(getGeometricShape(style), fontStyle);

    return setFontStyle(style, fontStyle);
}

int setFontStyle(SBMLDocument* document, const std::string& attribute, const std::string& fontStyle) {
    return setFontStyle(document, attribute, 0, fontStyle);
}

int setFontStyle(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontStyle) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setFontStyle(getGeometricShape(style), fontStyle);

    return setFontStyle(style, fontStyle);
}

int setCompartmentFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle) {
    if (!setCompartmentFontStyle(getGlobalRenderInformation(document), fontStyle) && !setCompartmentFontStyle(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontStyle))
        return 0;

    return -1;
}

int setSpeciesFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle) {
    if (!setSpeciesFontStyle(getGlobalRenderInformation(document), fontStyle) && !setSpeciesFontStyle(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontStyle))
        return 0;

    return -1;
}

int setReactionFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle) {
    if (!setReactionFontStyle(getGlobalRenderInformation(document), fontStyle) && !setReactionFontStyle(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fontStyle))
        return 0;

    return -1;
}

int setFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle) {
    if (setCompartmentFontStyle(document, layoutIndex, fontStyle))
        return -1;
    if (setSpeciesFontStyle(document, layoutIndex, fontStyle))
        return -1;
    if (setReactionFontStyle(document, layoutIndex, fontStyle))
        return -1;

    return 0;
}

bool isSetTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetTextAnchor(getGeometricShape(style));

    return isSetTextAnchor(style);
}

bool isSetTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetTextAnchor(getGeometricShape(style));

    return isSetTextAnchor(style);
}

const std::string getTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getTextAnchor(getGeometricShape(style));

    return getTextAnchor(style);
}

const std::string getTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getTextAnchor(getGeometricShape(style));

    return getTextAnchor(style);
}

int setTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& textAnchor) {
    return setTextAnchor(document, graphicalObject, 0, textAnchor);
}

int setTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& textAnchor) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setTextAnchor(getGeometricShape(style), textAnchor);

    return setTextAnchor(style, textAnchor);
}

int setTextAnchor(SBMLDocument* document, const std::string& attribute, const std::string& textAnchor) {
    return setTextAnchor(document, attribute, 0, textAnchor);
}

int setTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& textAnchor) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setTextAnchor(getGeometricShape(style), textAnchor);

    return setTextAnchor(style, textAnchor);
}

int setCompartmentTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor) {
    if (!setCompartmentTextAnchor(getGlobalRenderInformation(document), textAnchor) && !setCompartmentTextAnchor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), textAnchor))
        return 0;

    return -1;
}

int setSpeciesTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor) {
    if (!setSpeciesTextAnchor(getGlobalRenderInformation(document), textAnchor) && !setSpeciesTextAnchor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), textAnchor))
        return 0;

    return -1;
}

int setReactionTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor) {
    if (!setReactionTextAnchor(getGlobalRenderInformation(document), textAnchor) && !setReactionTextAnchor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), textAnchor))
        return 0;

    return -1;
}

int setTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor) {
    if (setCompartmentTextAnchor(document, layoutIndex, textAnchor))
        return -1;
    if (setSpeciesTextAnchor(document, layoutIndex, textAnchor))
        return -1;
    if (setReactionTextAnchor(document, layoutIndex, textAnchor))
        return -1;

    return 0;
}

bool isSetVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetVTextAnchor(getGeometricShape(style));

    return isSetVTextAnchor(style);
}

bool isSetVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return isSetVTextAnchor(getGeometricShape(style));

    return isSetVTextAnchor(style);
}

const std::string getVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getVTextAnchor(getGeometricShape(style));

    return getVTextAnchor(style);
}

const std::string getVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex) {
    Style* style = getStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return getVTextAnchor(getGeometricShape(style));

    return getVTextAnchor(style);
}

int setVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& vtextAnchor) {
    return setVTextAnchor(document, graphicalObject, 0, vtextAnchor);
}

int setVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& vtextAnchor) {
    Style* style = getLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, graphicalObject, textGlyphIndex), graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setVTextAnchor(getGeometricShape(style), vtextAnchor);

    return setVTextAnchor(style, vtextAnchor);
}

int setVTextAnchor(SBMLDocument* document, const std::string& attribute, const std::string& vtextAnchor) {
    return setVTextAnchor(document, attribute, 0, vtextAnchor);
}

int setVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& vtextAnchor) {
    Style* style = getLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex));
    if (!style)
        style = createLocalStyle(document, getTextGlyph(document, attribute, textGlyphIndex), getGraphicalObject(document, attribute));
    if (getNumGeometricShapes(style) == 1 && isText(getGeometricShape(style)))
        return setVTextAnchor(getGeometricShape(style), vtextAnchor);

    return setVTextAnchor(style, vtextAnchor);
}

int setCompartmentVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor) {
    if (!setCompartmentVTextAnchor(getGlobalRenderInformation(document), vtextAnchor) && !setCompartmentVTextAnchor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), vtextAnchor))
        return 0;

    return -1;
}

int setSpeciesVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor) {
    if (!setSpeciesVTextAnchor(getGlobalRenderInformation(document), vtextAnchor) && !setSpeciesVTextAnchor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), vtextAnchor))
        return 0;

    return -1;
}

int setReactionVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor) {
    if (!setReactionVTextAnchor(getGlobalRenderInformation(document), vtextAnchor) && !setReactionVTextAnchor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), vtextAnchor))
        return 0;

    return -1;
}

int setVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor) {
    if (setCompartmentVTextAnchor(document, layoutIndex, vtextAnchor))
        return -1;
    if (setSpeciesVTextAnchor(document, layoutIndex, vtextAnchor))
        return -1;
    if (setReactionVTextAnchor(document, layoutIndex, vtextAnchor))
        return -1;

    return 0;
}

bool isSetFillColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isSetFillColor(getGeometricShape(style)))
        return isSetFillColor(getGeometricShape(style));

    return isSetFillColor(style);
}

bool isSetFillColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isSetFillColor(getGeometricShape(style)))
        return isSetFillColor(getGeometricShape(style));

    return isSetFillColor(style);
}

const std::string getFillColor(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && !getFillColor(getGeometricShape(style)).empty())
        return getFillColor(getGeometricShape(style));

    return getFillColor(style);
}

const std::string getFillColor(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && !getFillColor(getGeometricShape(style)).empty())
        return getFillColor(getGeometricShape(style));

    return getFillColor(style);
}

int setFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillColor) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    addColor(document, style, fillColor);
    return setFillColor(style, fillColor);
}

int setFillColor(SBMLDocument* document, const std::string& attribute, const std::string& fillColor) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    addColor(document, style, fillColor);
    return setFillColor(style, fillColor);
}

int setCompartmentFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor) {
    if (!setCompartmentFillColor(getGlobalRenderInformation(document), fillColor) && !setCompartmentFillColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fillColor))
        return 0;

    return -1;
}

int setSpeciesFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor) {
    if (!setSpeciesFillColor(getGlobalRenderInformation(document), fillColor) && !setSpeciesFillColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fillColor))
        return 0;

    return -1;
}

int setReactionFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor) {
    if (!setReactionFillColor(getGlobalRenderInformation(document), fillColor) && !setReactionFillColor(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fillColor))
        return 0;

    return -1;
}

int setLineEndingFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor) {
    for (unsigned int renderIndex = 0; renderIndex < getNumLocalRenderInformation(document, layoutIndex); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getLocalRenderInformation(document, lineEndingIndex, renderIndex)); lineEndingIndex++) {
            if (setLineEndingFillColor(document, renderIndex, getLineEnding(getLocalRenderInformation(document, layoutIndex, renderIndex), lineEndingIndex)->getId(), fillColor))
                return -1;
        }
    }
    for (unsigned int renderIndex = 0; renderIndex < getNumGlobalRenderInformation(document); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getGlobalRenderInformation(document, renderIndex)); lineEndingIndex++) {
            if (setLineEndingFillColor(document, renderIndex, getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex)->getId(), fillColor))
                return -1;
        }
    }

    return 0;
}

int setFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor) {
    if (setCompartmentFillColor(document, layoutIndex, fillColor))
        return -1;
    if (setSpeciesFillColor(document, layoutIndex, fillColor))
        return -1;
    if (setReactionFillColor(document, layoutIndex, fillColor))
        return -1;

    return 0;
}

bool isSetFillRule(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isPolygon(getGeometricShape(style)))
        return isSetFillRule(getGeometricShape(style));

    return isSetFillRule(style);
}

bool isSetFillRule(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isPolygon(getGeometricShape(style)))
        return isSetFillRule(getGeometricShape(style));

    return isSetFillRule(style);
}

const std::string getFillRule(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isPolygon(getGeometricShape(style)))
        return getFillRule(getGeometricShape(style));

    return getFillRule(style);
}

const std::string getFillRule(SBMLDocument* document, const std::string& attribute) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isPolygon(getGeometricShape(style)))
        return getFillRule(getGeometricShape(style));

    return getFillRule(style);
}

int setFillRule(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillRule) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isPolygon(getGeometricShape(style)))
        return setFillRule(getGeometricShape(style), fillRule);

    return setFillRule(style, fillRule);
}

int setFillRule(SBMLDocument* document, const std::string& attribute, const std::string& fillRule) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isPolygon(getGeometricShape(style)))
        return setFillRule(getGeometricShape(style), fillRule);

    return setFillRule(style, fillRule);
}

int setCompartmentFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule) {
    if (!setCompartmentFillRule(getGlobalRenderInformation(document), fillRule) && !setCompartmentFillRule(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fillRule))
        return 0;

    return -1;
}

int setSpeciesFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule) {
    if (!setSpeciesFillRule(getGlobalRenderInformation(document), fillRule) && !setSpeciesFillRule(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fillRule))
        return 0;

    return -1;
}

int setReactionFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule) {
    if (!setReactionFillRule(getGlobalRenderInformation(document), fillRule) && !setReactionFillRule(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), fillRule))
        return 0;

    return -1;
}

int setLineEndingFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule) {
    for (unsigned int renderIndex = 0; renderIndex < getNumLocalRenderInformation(document, layoutIndex); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getLocalRenderInformation(document, lineEndingIndex, renderIndex)); lineEndingIndex++) {
            if (setLineEndingFillRule(document, renderIndex, getLineEnding(getLocalRenderInformation(document, layoutIndex, renderIndex), lineEndingIndex)->getId(), fillRule))
                return -1;
        }
    }
    for (unsigned int renderIndex = 0; renderIndex < getNumGlobalRenderInformation(document); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getGlobalRenderInformation(document, renderIndex)); lineEndingIndex++) {
            if (setLineEndingFillRule(document, renderIndex, getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex)->getId(), fillRule))
                return -1;
        }
    }

    return 0;
}

int setFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule) {
    if (setCompartmentFillRule(document, layoutIndex, fillRule))
        return -1;
    if (setSpeciesFillRule(document, layoutIndex, fillRule))
        return -1;
    if (setReactionFillRule(document, layoutIndex, fillRule))
        return -1;

    return 0;
}

bool isSetStartHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return isSetStartHead(getGeometricShape(style));

    return isSetStartHead(style);
}

bool isSetStartHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return isSetStartHead(getGeometricShape(style));

    return isSetStartHead(style);
}

const std::string getStartHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return getStartHead(getGeometricShape(style));

    return getStartHead(style);
}

const std::string getStartHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return getStartHead(getGeometricShape(style));

    return getStartHead(style);
}

int setStartHead(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& startHead) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return setStartHead(getGeometricShape(style), startHead);

    return setStartHead(style, startHead);
}

int setStartHead(SBMLDocument* document, const std::string& attribute, const std::string& startHead) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return setStartHead(getGeometricShape(style), startHead);

    return setStartHead(style, startHead);
}

bool isSetEndHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return isSetEndHead(getGeometricShape(style));

    return isSetEndHead(style);
}

bool isSetEndHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return isSetEndHead(getGeometricShape(style));

    return isSetEndHead(style);
}

const std::string getEndHead(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Style* style = getStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return getEndHead(getGeometricShape(style));

    return getEndHead(style);
}

const std::string getEndHead(SBMLDocument* document, const std::string& attribute) {
    Style* style = getStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return getEndHead(getGeometricShape(style));

    return getEndHead(style);
}

int setEndHead(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& endHead) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
        return setEndHead(getGeometricShape(style), endHead);

    return setEndHead(style, endHead);
}

int setEndHead(SBMLDocument* document, const std::string& attribute, const std::string& endHead) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    if (getNumGeometricShapes(style) == 1 && isRenderCurve(getGeometricShape(style)))
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
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return addGeometricShape(style, shape);
}

int addGeometricShape(SBMLDocument* document, const std::string& attribute, const std::string& shape) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return addGeometricShape(style, shape);
}

Transformation2D* removeGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return removeGeometricShape(style, geometricShapeIndex);
}

Transformation2D* removeGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return removeGeometricShape(style, geometricShapeIndex);
}

const std::string getGeometricShapeType(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeType(getStyle(document, graphicalObject), geometricShapeIndex);
}

const std::string getGeometricShapeType(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeType(getStyle(document, attribute), geometricShapeIndex);
}

int setGeometricShapeType(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& shape) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    if (!setGeometricShapeType(style, shape)) {
        if (getGlobalRenderInformation(document))
            addColorsOfDefaultGeometricShapes(getGlobalRenderInformation(document));
        else
            addColorsOfDefaultGeometricShapes(document, style);
        removeCurve(graphicalObject);
        return 0;
    }

    return -1;
}

int setGeometricShapeType(SBMLDocument* document, const std::string& attribute, const std::string& shape) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    if (setGeometricShapeType(style, shape)) {
        if (getGlobalRenderInformation(document))
            addColorsOfDefaultGeometricShapes(getGlobalRenderInformation(document));
        else
            addColorsOfDefaultGeometricShapes(document, style);
        removeCurve(getGraphicalObject(document, attribute));
        return 0;
    }

    return -1;
}

int setCompartmentGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape) {
    if (!setCompartmentGeometricShapeType(getGlobalRenderInformation(document), shape) && !setCompartmentGeometricShapeType(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), shape))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape) {
    if (!setSpeciesGeometricShapeType(getGlobalRenderInformation(document), shape) && !setSpeciesGeometricShapeType(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), shape))
        return 0;

    return -1;
}

int setReactionGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape) {
    if (!setReactionGeometricShapeType(getGlobalRenderInformation(document), shape) && !setReactionGeometricShapeType(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), shape))
        return 0;

    return -1;
}

int setGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape) {
    if (setCompartmentGeometricShapeType(document, layoutIndex, shape))
        return -1;
    if (setSpeciesGeometricShapeType(document, layoutIndex, shape))
        return -1;
    if (setReactionGeometricShapeType(document, layoutIndex, shape))
        return -1;

    return 0;
}

bool isRectangle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isRectangle(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isRectangle(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isRectangle(getStyle(document, attribute), geometricShapeIndex);
}

bool isSquare(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSquare(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isSquare(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSquare(getStyle(document, attribute), geometricShapeIndex);
}

bool isEllipse(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isEllipse(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isEllipse(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isEllipse(getStyle(document, attribute), geometricShapeIndex);
}

bool isCircle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isCircle(getStyle(document, graphicalObject), geometricShapeIndex);
}

bool isCircle(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isCircle(getStyle(document, attribute), geometricShapeIndex);
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

const double getGeometricShapeXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector xVector = getGeometricShapeX(document, graphicalObject, geometricShapeIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * xVector.getRelativeValue();
}

const double getGeometricShapeXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex ) {
    RelAbsVector xVector = getGeometricShapeX(document, attribute, geometricShapeIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * xVector.getRelativeValue();
}

int setGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeX(style, 0, x);
}

int setGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeX(style, geometricShapeIndex, x);
}

int setGeometricShapeX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeX(style, 0, x);
}

int setGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeX(style, geometricShapeIndex, x);
}

int setGeometricShapeXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeXAsDouble(style, 0, x);
}

int setGeometricShapeXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeXAsDouble(style, geometricShapeIndex, x);
}

int setGeometricShapeXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeXAsDouble(style, 0, x);
}

int setGeometricShapeXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeXAsDouble(style, geometricShapeIndex, x);
}

int setCompartmentGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x) {
    if (!setCompartmentGeometricShapeX(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x) {
    if (!setCompartmentGeometricShapeXAsDouble(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x) {
    if (!setSpeciesGeometricShapeX(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x) {
    if (!setSpeciesGeometricShapeXAsDouble(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x) {
    if (!setReactionGeometricShapeX(getGlobalRenderInformation(document), x) && !setReactionGeometricShapeX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x) {
    if (!setReactionGeometricShapeXAsDouble(getGlobalRenderInformation(document), x) && !setReactionGeometricShapeXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x) {
    if (setCompartmentGeometricShapeX(document, layoutIndex, x))
        return -1;
    if (setSpeciesGeometricShapeX(document, layoutIndex, x))
        return -1;
    if (setReactionGeometricShapeX(document, layoutIndex, x))
        return -1;

    return 0;
}

int setGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x) {
    if (setCompartmentGeometricShapeXAsDouble(document, layoutIndex, x))
        return -1;
    if (setSpeciesGeometricShapeXAsDouble(document, layoutIndex, x))
        return -1;
    if (setReactionGeometricShapeXAsDouble(document, layoutIndex, x))
        return -1;

    return 0;
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

const double getGeometricShapeYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector yVector = getGeometricShapeY(document, graphicalObject, geometricShapeIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * yVector.getRelativeValue();
}

const double getGeometricShapeYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector yVector = getGeometricShapeY(document, attribute, geometricShapeIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * yVector.getRelativeValue();
}

int setGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeY(style, 0, y);
}

int setGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeY(style, geometricShapeIndex, y);
}

int setGeometricShapeY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeY(style, 0, y);
}

int setGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeY(style, geometricShapeIndex, y);
}

int setGeometricShapeYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeYAsDouble(style, 0, y);
}

int setGeometricShapeYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeYAsDouble(style, geometricShapeIndex, y);
}

int setGeometricShapeYAsDouble(SBMLDocument* document, const std::string& attribute, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeYAsDouble(style, 0, y);
}

int setGeometricShapeYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeYAsDouble(style, geometricShapeIndex, y);
}

int setCompartmentGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y) {
    if (!setCompartmentGeometricShapeY(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y) {
    if (!setCompartmentGeometricShapeYAsDouble(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y) {
    if (!setSpeciesGeometricShapeY(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y) {
    if (!setSpeciesGeometricShapeYAsDouble(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y) {
    if (!setReactionGeometricShapeY(getGlobalRenderInformation(document), y) && !setReactionGeometricShapeY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y) {
    if (!setReactionGeometricShapeYAsDouble(getGlobalRenderInformation(document), y) && !setReactionGeometricShapeYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y) {
    if (setCompartmentGeometricShapeY(document, layoutIndex, y))
        return -1;
    if (setSpeciesGeometricShapeY(document, layoutIndex, y))
        return -1;
    if (setReactionGeometricShapeY(document, layoutIndex, y))
        return -1;

    return 0;
}

int setGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y) {
    if (setCompartmentGeometricShapeYAsDouble(document, layoutIndex, y))
        return -1;
    if (setSpeciesGeometricShapeYAsDouble(document, layoutIndex, y))
        return -1;
    if (setReactionGeometricShapeYAsDouble(document, layoutIndex, y))
        return -1;

    return 0;
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

const double getGeometricShapeWidthAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector widthVector = getGeometricShapeWidth(document, graphicalObject, geometricShapeIndex);
    return widthVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * widthVector.getRelativeValue();
}

const double getGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector widthVector = getGeometricShapeWidth(document, attribute, geometricShapeIndex);
    return widthVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * widthVector.getRelativeValue();
}

int setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& width) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeWidth(style, 0, width);
}

int setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeWidth(style, geometricShapeIndex, width);
}

int setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, const RelAbsVector& width) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeWidth(style, 0, width);
}

int setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeWidth(style, geometricShapeIndex, width);
}

int setGeometricShapeWidthAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& width) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeWidthAsDouble(style, 0, width);
}

int setGeometricShapeWidthAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& width) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeWidthAsDouble(style, geometricShapeIndex, width);
}

int setGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& attribute, const double& width) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeWidthAsDouble(style, 0, width);
}

int setGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& width) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeWidthAsDouble(style, geometricShapeIndex, width);
}

int setCompartmentGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width) {
    if (!setCompartmentGeometricShapeWidth(getGlobalRenderInformation(document), width) && !setCompartmentGeometricShapeWidth(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), width))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    if (!setCompartmentGeometricShapeWidthAsDouble(getGlobalRenderInformation(document), width) && !setCompartmentGeometricShapeWidthAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), width))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width) {
    if (!setSpeciesGeometricShapeWidth(getGlobalRenderInformation(document), width) && !setSpeciesGeometricShapeWidth(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), width))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    if (!setSpeciesGeometricShapeWidthAsDouble(getGlobalRenderInformation(document), width) && !setSpeciesGeometricShapeWidthAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), width))
        return 0;

    return -1;
}

int setReactionGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width) {
    if (!setReactionGeometricShapeWidth(getGlobalRenderInformation(document), width) && !setReactionGeometricShapeWidth(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), width))
        return 0;

    return -1;
}

int setReactionGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    if (!setReactionGeometricShapeWidthAsDouble(getGlobalRenderInformation(document), width) && !setReactionGeometricShapeWidthAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), width))
        return 0;

    return -1;
}

int setGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width) {
    if (setCompartmentGeometricShapeWidth(document, layoutIndex, width))
        return -1;
    if (setSpeciesGeometricShapeWidth(document, layoutIndex, width))
        return -1;
    if (setReactionGeometricShapeWidth(document, layoutIndex, width))
        return -1;

    return 0;
}

int setGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    if (setCompartmentGeometricShapeWidthAsDouble(document, layoutIndex, width))
        return -1;
    if (setSpeciesGeometricShapeWidthAsDouble(document, layoutIndex, width))
        return -1;
    if (setReactionGeometricShapeWidthAsDouble(document, layoutIndex, width))
        return -1;

    return 0;
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

const double getGeometricShapeHeightAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector heightVector = getGeometricShapeHeight(document, graphicalObject, geometricShapeIndex);
    return heightVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * heightVector.getRelativeValue();
}

const double getGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector heightVector = getGeometricShapeHeight(document, attribute, geometricShapeIndex);
    return heightVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * heightVector.getRelativeValue();
}

int setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& height) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeHeight(style, 0, height);
}

int setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeHeight(style, geometricShapeIndex, height);
}

int setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, const RelAbsVector& height) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeHeight(style, 0, height);
}

int setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeHeight(style, geometricShapeIndex, height);
}

int setGeometricShapeHeightAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& height) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeHeightAsDouble(style, 0, height);
}

int setGeometricShapeHeightAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& height) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeHeightAsDouble(style, geometricShapeIndex, height);
}

int setGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& attribute, const double& height) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeHeightAsDouble(style, 0, height);
}

int setGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& height) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeHeightAsDouble(style, geometricShapeIndex, height);
}

int setCompartmentGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height) {
    if (!setCompartmentGeometricShapeHeight(getGlobalRenderInformation(document), height) && !setCompartmentGeometricShapeHeight(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), height))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    if (!setCompartmentGeometricShapeHeightAsDouble(getGlobalRenderInformation(document), height) && !setCompartmentGeometricShapeHeightAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), height))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height) {
    if (!setSpeciesGeometricShapeHeight(getGlobalRenderInformation(document), height) && !setSpeciesGeometricShapeHeight(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), height))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    if (!setSpeciesGeometricShapeHeightAsDouble(getGlobalRenderInformation(document), height) && !setSpeciesGeometricShapeHeightAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), height))
        return 0;

    return -1;
}

int setReactionGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height) {
    if (!setReactionGeometricShapeHeight(getGlobalRenderInformation(document), height) && !setReactionGeometricShapeHeight(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), height))
        return 0;

    return -1;
}

int setReactionGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    if (!setReactionGeometricShapeHeightAsDouble(getGlobalRenderInformation(document), height) && !setReactionGeometricShapeHeightAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), height))
        return 0;

    return -1;
}

int setGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height) {
    if (setCompartmentGeometricShapeHeight(document, layoutIndex, height))
        return -1;
    if (setSpeciesGeometricShapeHeight(document, layoutIndex, height))
        return -1;
    if (setReactionGeometricShapeHeight(document, layoutIndex, height))
        return -1;

    return 0;
}

int setGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    if (setCompartmentGeometricShapeHeightAsDouble(document, layoutIndex, height))
        return -1;
    if (setSpeciesGeometricShapeHeightAsDouble(document, layoutIndex, height))
        return -1;
    if (setReactionGeometricShapeHeightAsDouble(document, layoutIndex, height))
        return -1;

    return 0;
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
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRatio(style, ratio);
}

int setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ratio) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRatio(style, geometricShapeIndex, ratio);
}

int setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, const double& ratio) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRatio(style, ratio);
}

int setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ratio) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRatio(style, geometricShapeIndex, ratio);
}

int setCompartmentGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio) {
    if (!setCompartmentGeometricShapeRatio(getGlobalRenderInformation(document), ratio) && !setCompartmentGeometricShapeRatio(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ratio))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio) {
    if (!setSpeciesGeometricShapeRatio(getGlobalRenderInformation(document), ratio) && !setSpeciesGeometricShapeRatio(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ratio))
        return 0;

    return -1;
}

int setReactionGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio) {
    if (!setReactionGeometricShapeRatio(getGlobalRenderInformation(document), ratio) && !setReactionGeometricShapeRatio(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ratio))
        return 0;

    return -1;
}

int setGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio) {
    if (setCompartmentGeometricShapeRatio(document, layoutIndex, ratio))
        return -1;
    if (setSpeciesGeometricShapeRatio(document, layoutIndex, ratio))
        return -1;
    if (setReactionGeometricShapeRatio(document, layoutIndex, ratio))
        return -1;

    return 0;
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

const double getGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector rxVector = getGeometricShapeCornerCurvatureRadiusX(document, graphicalObject, geometricShapeIndex);
    return rxVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * rxVector.getRelativeValue();
}

const double getGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector rxVector = getGeometricShapeCornerCurvatureRadiusX(document, attribute, geometricShapeIndex);
    return rxVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * rxVector.getRelativeValue();
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusX(style, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusX(style, geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusX(style, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusX(style, geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, const double& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, geometricShapeIndex, rx);
}

int setCompartmentGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (!setCompartmentGeometricShapeCornerCurvatureRadiusX(getGlobalRenderInformation(document), rx) && !setCompartmentGeometricShapeCornerCurvatureRadiusX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (!setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(getGlobalRenderInformation(document), rx) && !setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (!setSpeciesGeometricShapeCornerCurvatureRadiusX(getGlobalRenderInformation(document), rx) && !setSpeciesGeometricShapeCornerCurvatureRadiusX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (!setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(getGlobalRenderInformation(document), rx) && !setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setReactionGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (!setReactionGeometricShapeCornerCurvatureRadiusX(getGlobalRenderInformation(document), rx) && !setReactionGeometricShapeCornerCurvatureRadiusX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (!setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(getGlobalRenderInformation(document), rx) && !setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (setCompartmentGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, rx))
        return -1;
    if (setSpeciesGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, rx))
        return -1;
    if (setReactionGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, rx))
        return -1;

    return 0;
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, rx))
        return -1;
    if (setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, rx))
        return -1;
    if (setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, rx))
        return -1;

    return 0;
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

const double getGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector ryVector = getGeometricShapeCornerCurvatureRadiusY(document, graphicalObject, geometricShapeIndex);
    return ryVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * ryVector.getRelativeValue();
}

const double getGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector ryVector = getGeometricShapeCornerCurvatureRadiusY(document, attribute, geometricShapeIndex);
    return ryVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * ryVector.getRelativeValue();
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusY(style, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusY(style, geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusY(style, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusY(style, geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, const double& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, geometricShapeIndex, ry);
}

int setCompartmentGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (!setCompartmentGeometricShapeCornerCurvatureRadiusY(getGlobalRenderInformation(document), ry) && !setCompartmentGeometricShapeCornerCurvatureRadiusY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (!setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(getGlobalRenderInformation(document), ry) && !setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (!setSpeciesGeometricShapeCornerCurvatureRadiusY(getGlobalRenderInformation(document), ry) && !setSpeciesGeometricShapeCornerCurvatureRadiusY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (!setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(getGlobalRenderInformation(document), ry) && !setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setReactionGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (!setReactionGeometricShapeCornerCurvatureRadiusY(getGlobalRenderInformation(document), ry) && !setReactionGeometricShapeCornerCurvatureRadiusY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (!setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(getGlobalRenderInformation(document), ry) && !setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (setCompartmentGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, ry))
        return -1;
    if (setSpeciesGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, ry))
        return -1;
    if (setReactionGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, ry))
        return -1;

    return 0;
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, ry))
        return -1;
    if (setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, ry))
        return -1;
    if (setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, ry))
        return -1;

    return 0;
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

const double getGeometricShapeCenterXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector cxVector = getGeometricShapeCenterX(document, graphicalObject, geometricShapeIndex);
    return cxVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * cxVector.getRelativeValue();
}

const double getGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector cxVector = getGeometricShapeCenterX(document, attribute, geometricShapeIndex);
    return cxVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * cxVector.getRelativeValue();
}

int setGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& cx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterX(style, cx);
}

int setGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterX(style, geometricShapeIndex, cx);
}

int setGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterX(style, cx);
}

int setGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterX(style, geometricShapeIndex, cx);
}

int setGeometricShapeCenterXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& cx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterXAsDouble(style, cx);
}

int setGeometricShapeCenterXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterXAsDouble(style, geometricShapeIndex, cx);
}

int setGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& attribute, const double& cx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterXAsDouble(style, cx);
}

int setGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& cx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterXAsDouble(style, geometricShapeIndex, cx);
}

int setCompartmentGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx) {
    if (!setCompartmentGeometricShapeCenterX(getGlobalRenderInformation(document), cx) && !setCompartmentGeometricShapeCenterX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cx))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx) {
    if (!setCompartmentGeometricShapeCenterXAsDouble(getGlobalRenderInformation(document), cx) && !setCompartmentGeometricShapeCenterXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cx))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx) {
    if (!setSpeciesGeometricShapeCenterX(getGlobalRenderInformation(document), cx) && !setSpeciesGeometricShapeCenterX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cx))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx) {
    if (!setSpeciesGeometricShapeCenterXAsDouble(getGlobalRenderInformation(document), cx) && !setSpeciesGeometricShapeCenterXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cx))
        return 0;

    return -1;
}

int setReactionGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx) {
    if (!setReactionGeometricShapeCenterX(getGlobalRenderInformation(document), cx) && !setReactionGeometricShapeCenterX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cx))
        return 0;

    return -1;
}

int setReactionGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx) {
    if (!setReactionGeometricShapeCenterXAsDouble(getGlobalRenderInformation(document), cx) && !setReactionGeometricShapeCenterXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cx))
        return 0;

    return -1;
}

int setGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx) {
    if (setCompartmentGeometricShapeCenterX(document, layoutIndex, cx))
        return -1;
    if (setSpeciesGeometricShapeCenterX(document, layoutIndex, cx))
        return -1;
    if (setReactionGeometricShapeCenterX(document, layoutIndex, cx))
        return -1;

    return 0;
}

int setGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx) {
    if (setCompartmentGeometricShapeCenterXAsDouble(document, layoutIndex, cx))
        return -1;
    if (setSpeciesGeometricShapeCenterXAsDouble(document, layoutIndex, cx))
        return -1;
    if (setReactionGeometricShapeCenterXAsDouble(document, layoutIndex, cx))
        return -1;

    return 0;
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

const double getGeometricShapeCenterYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector cyVector = getGeometricShapeCenterY(document, graphicalObject, geometricShapeIndex);
    return cyVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * cyVector.getRelativeValue();
}

const double getGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector cyVector = getGeometricShapeCenterY(document, attribute, geometricShapeIndex);
    return cyVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * cyVector.getRelativeValue();
}

int setGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& cy) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterY(style, cy);
}

int setGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterY(style, geometricShapeIndex, cy);
}

int setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cy) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterY(style, cy);
}

int setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterY(style, geometricShapeIndex, cy);
}

int setGeometricShapeCenterYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& cy) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterYAsDouble(style, cy);
}

int setGeometricShapeCenterYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cy) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeCenterYAsDouble(style, geometricShapeIndex, cy);
}

int setGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& attribute, const double& cy) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterYAsDouble(style, cy);
}

int setGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& cy) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeCenterYAsDouble(style, geometricShapeIndex, cy);
}

int setCompartmentGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy) {
    if (!setCompartmentGeometricShapeCenterY(getGlobalRenderInformation(document), cy) && !setCompartmentGeometricShapeCenterY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cy))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy) {
    if (!setCompartmentGeometricShapeCenterYAsDouble(getGlobalRenderInformation(document), cy) &&
        !setCompartmentGeometricShapeCenterYAsDouble(
                getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cy))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy) {
    if (!setSpeciesGeometricShapeCenterY(getGlobalRenderInformation(document), cy) && !setSpeciesGeometricShapeCenterY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cy))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy) {
    if (!setSpeciesGeometricShapeCenterYAsDouble(getGlobalRenderInformation(document), cy) && !setSpeciesGeometricShapeCenterYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cy))
        return 0;

    return -1;
}

int setReactionGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy) {
    if (!setReactionGeometricShapeCenterY(getGlobalRenderInformation(document), cy) && !setReactionGeometricShapeCenterY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cy))
        return 0;

    return -1;
}

int setReactionGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy) {
    if (!setReactionGeometricShapeCenterYAsDouble(getGlobalRenderInformation(document), cy) && !setReactionGeometricShapeCenterYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), cy))
        return 0;

    return -1;
}

int setGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy) {
    if (setCompartmentGeometricShapeCenterY(document, layoutIndex, cy))
        return -1;
    if (setSpeciesGeometricShapeCenterY(document, layoutIndex, cy))
        return -1;
    if (setReactionGeometricShapeCenterY(document, layoutIndex, cy))
        return -1;

    return 0;
}

int setGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy) {
    if (setCompartmentGeometricShapeCenterYAsDouble(document, layoutIndex, cy))
        return -1;
    if (setSpeciesGeometricShapeCenterYAsDouble(document, layoutIndex, cy))
        return -1;
    if (setReactionGeometricShapeCenterYAsDouble(document, layoutIndex, cy))
        return -1;

    return 0;
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

const double getGeometricShapeRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector rxVector = getGeometricShapeRadiusX(document, graphicalObject, geometricShapeIndex);
    return rxVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * rxVector.getRelativeValue();
}

const double getGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector rxVector = getGeometricShapeRadiusX(document, attribute, geometricShapeIndex);
    return rxVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * rxVector.getRelativeValue();
}

int setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusX(style, rx);
}

int setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusX(style, geometricShapeIndex, rx);
}

int setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusX(style, rx);
}

int setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusX(style, geometricShapeIndex, rx);
}

int setGeometricShapeRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusXAsDouble(style, rx);
}

int setGeometricShapeRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusXAsDouble(style, geometricShapeIndex, rx);
}

int setGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, const double& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusXAsDouble(style, rx);
}

int setGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusXAsDouble(style, geometricShapeIndex, rx);
}

int setCompartmentGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (!setCompartmentGeometricShapeRadiusX(getGlobalRenderInformation(document), rx) && !setCompartmentGeometricShapeRadiusX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (!setCompartmentGeometricShapeRadiusXAsDouble(getGlobalRenderInformation(document), rx) && !setCompartmentGeometricShapeRadiusXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (!setSpeciesGeometricShapeRadiusX(getGlobalRenderInformation(document), rx) && !setSpeciesGeometricShapeRadiusX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (!setSpeciesGeometricShapeRadiusXAsDouble(getGlobalRenderInformation(document), rx) && !setSpeciesGeometricShapeRadiusXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setReactionGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (!setReactionGeometricShapeRadiusX(getGlobalRenderInformation(document), rx) && !setReactionGeometricShapeRadiusX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setReactionGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (!setReactionGeometricShapeRadiusXAsDouble(getGlobalRenderInformation(document), rx) && !setReactionGeometricShapeRadiusXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), rx))
        return 0;

    return -1;
}

int setGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx) {
    if (setCompartmentGeometricShapeRadiusX(document, layoutIndex, rx))
        return -1;
    if (setSpeciesGeometricShapeRadiusX(document, layoutIndex, rx))
        return -1;
    if (setReactionGeometricShapeRadiusX(document, layoutIndex, rx))
        return -1;

    return 0;
}

int setGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx) {
    if (setCompartmentGeometricShapeRadiusXAsDouble(document, layoutIndex, rx))
        return -1;
    if (setSpeciesGeometricShapeRadiusXAsDouble(document, layoutIndex, rx))
        return -1;
    if (setReactionGeometricShapeRadiusXAsDouble(document, layoutIndex, rx))
        return -1;

    return 0;
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

const double getGeometricShapeRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    RelAbsVector ryVector = getGeometricShapeRadiusY(document, graphicalObject, geometricShapeIndex);
    return ryVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * ryVector.getRelativeValue();
}

const double getGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    RelAbsVector ryVector = getGeometricShapeRadiusY(document, attribute, geometricShapeIndex);
    return ryVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * ryVector.getRelativeValue();
}

int setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusY(style, ry);
}

int setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusY(style, geometricShapeIndex, ry);
}

int setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusY(style, ry);
}

int setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusY(style, geometricShapeIndex, ry);
}

int setGeometricShapeRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusYAsDouble(style, ry);
}

int setGeometricShapeRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeRadiusYAsDouble(style, geometricShapeIndex, ry);
}

int setGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, const double& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusYAsDouble(style, ry);
}

int setGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeRadiusYAsDouble(style, geometricShapeIndex, ry);
}

int setCompartmentGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (!setCompartmentGeometricShapeRadiusY(getGlobalRenderInformation(document), ry) && !setCompartmentGeometricShapeRadiusY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (!setCompartmentGeometricShapeRadiusYAsDouble(getGlobalRenderInformation(document), ry) && !setCompartmentGeometricShapeRadiusYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (!setSpeciesGeometricShapeRadiusY(getGlobalRenderInformation(document), ry) && !setSpeciesGeometricShapeRadiusY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (!setSpeciesGeometricShapeRadiusYAsDouble(getGlobalRenderInformation(document), ry) && !setSpeciesGeometricShapeRadiusYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setReactionGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
    if (!setReactionGeometricShapeRadiusY(getGlobalRenderInformation(document), ry) && !setReactionGeometricShapeRadiusY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

int setReactionGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
    if (!setReactionGeometricShapeRadiusYAsDouble(getGlobalRenderInformation(document), ry) &&
        !setReactionGeometricShapeRadiusYAsDouble(
                getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), ry))
        return 0;

    return -1;
}

 int setGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry) {
     if (setCompartmentGeometricShapeRadiusY(document, layoutIndex, ry))
         return -1;
     if (setSpeciesGeometricShapeRadiusY(document, layoutIndex, ry))
         return -1;
     if (setReactionGeometricShapeRadiusY(document, layoutIndex, ry))
         return -1;

     return 0;
 }

 int setGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry) {
     if (setCompartmentGeometricShapeRadiusYAsDouble(document, layoutIndex, ry))
         return -1;
     if (setSpeciesGeometricShapeRadiusYAsDouble(document, layoutIndex, ry))
         return -1;
     if (setReactionGeometricShapeRadiusYAsDouble(document, layoutIndex, ry))
         return -1;

     return 0;
 }

const unsigned int getGeometricShapeNumElements(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getStyle(document, graphicalObject), geometricShapeIndex);
}

const unsigned int getGeometricShapeNumElements(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getStyle(document, attribute), geometricShapeIndex);
}

bool isGeometricShapeElementCubicBezier(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

bool isGeometricShapeElementCubicBezier(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const double getGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector xVector = getGeometricShapeElementX(document, graphicalObject, geometricShapeIndex, elementIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * xVector.getRelativeValue();
}

const double getGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector xVector = getGeometricShapeElementX(document, attribute, geometricShapeIndex, elementIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * xVector.getRelativeValue();
}

int setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementX(style, x);
}

int setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementX(style, elementIndex, x);
}

int setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementX(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementX(style, x);
}

int setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementX(style, elementIndex, x);
}

int setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementX(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementXAsDouble(style, x);
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementXAsDouble(style, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementXAsDouble(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementXAsDouble(style, x);
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementXAsDouble(style, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementXAsDouble(style, geometricShapeIndex, elementIndex, x);
}

int setCompartmentGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setCompartmentGeometricShapeElementX(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeElementX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setCompartmentGeometricShapeElementXAsDouble(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeElementXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setSpeciesGeometricShapeElementX(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeElementX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setSpeciesGeometricShapeElementXAsDouble(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeElementXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setReactionGeometricShapeElementX(getGlobalRenderInformation(document), x) && !setReactionGeometricShapeElementX(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setReactionGeometricShapeElementXAsDouble(getGlobalRenderInformation(document), x) && !setReactionGeometricShapeElementXAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (setCompartmentGeometricShapeElementX(document, layoutIndex, elementIndex, x))
        return -1;
    if (setSpeciesGeometricShapeElementX(document, layoutIndex, elementIndex, x))
        return -1;
    if (setReactionGeometricShapeElementX(document, layoutIndex, elementIndex, x))
        return -1;

    return 0;
}

int setGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (setCompartmentGeometricShapeElementXAsDouble(document, layoutIndex, elementIndex, x))
        return -1;
    if (setSpeciesGeometricShapeElementXAsDouble(document, layoutIndex, elementIndex, x))
        return -1;
    if (setReactionGeometricShapeElementXAsDouble(document, layoutIndex, elementIndex, x))
        return -1;

    return 0;
}

const RelAbsVector getGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const double getGeometricShapeElementYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector yVector = getGeometricShapeElementY(document, graphicalObject, geometricShapeIndex, elementIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * yVector.getRelativeValue();
}

const double getGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector yVector = getGeometricShapeElementY(document, attribute, geometricShapeIndex, elementIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * yVector.getRelativeValue();
}

int setGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementY(style, y);
}

int setGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementY(style, elementIndex, y);
}

int setGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementY(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementY(style, y);
}

int setGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementY(style, elementIndex, y);
}

int setGeometricShapeElementY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementY(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementYAsDouble(style, y);
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementYAsDouble(style, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeElementYAsDouble(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& attribute, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementYAsDouble(style, y);
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementYAsDouble(style, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeElementYAsDouble(style, geometricShapeIndex, elementIndex, y);
}

int setCompartmentGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setCompartmentGeometricShapeElementY(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeElementY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setCompartmentGeometricShapeElementYAsDouble(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeElementYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setSpeciesGeometricShapeElementY(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeElementY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setSpeciesGeometricShapeElementYAsDouble(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeElementYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setReactionGeometricShapeElementY(getGlobalRenderInformation(document), y) && !setReactionGeometricShapeElementY(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setReactionGeometricShapeElementYAsDouble(getGlobalRenderInformation(document), y) && !setReactionGeometricShapeElementYAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (setCompartmentGeometricShapeElementY(document, layoutIndex, elementIndex, y))
        return -1;
    if (setSpeciesGeometricShapeElementY(document, layoutIndex, elementIndex, y))
        return -1;
    if (setReactionGeometricShapeElementY(document, layoutIndex, elementIndex, y))
        return -1;

    return 0;
}

int setGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (setCompartmentGeometricShapeElementYAsDouble(document, layoutIndex, elementIndex, y))
        return -1;
    if (setSpeciesGeometricShapeElementYAsDouble(document, layoutIndex, elementIndex, y))
        return -1;
    if (setReactionGeometricShapeElementYAsDouble(document, layoutIndex, elementIndex, y))
        return -1;

    return 0;
}

const RelAbsVector getGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const double getGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector xVector = getGeometricShapeBasePoint1X(document, graphicalObject, geometricShapeIndex, elementIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * xVector.getRelativeValue();
}

const double getGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector xVector = getGeometricShapeBasePoint1X(document, attribute, geometricShapeIndex, elementIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * xVector.getRelativeValue();
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1X(style, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1X(style, elementIndex, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1X(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1X(style, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1X(style, elementIndex, x);
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1X(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1XAsDouble(style, x);
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1XAsDouble(style, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1XAsDouble(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1XAsDouble(style, x);
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1XAsDouble(style, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1XAsDouble(style, geometricShapeIndex, elementIndex, x);
}

int setCompartmentGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setCompartmentGeometricShapeBasePoint1X(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeBasePoint1X(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setCompartmentGeometricShapeBasePoint1XAsDouble(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeBasePoint1XAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setSpeciesGeometricShapeBasePoint1X(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeBasePoint1X(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setSpeciesGeometricShapeBasePoint1XAsDouble(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeBasePoint1XAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setReactionGeometricShapeBasePoint1X(getGlobalRenderInformation(document), x) && !setReactionGeometricShapeBasePoint1X(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setReactionGeometricShapeBasePoint1XAsDouble(getGlobalRenderInformation(document), x) &&
        !setReactionGeometricShapeBasePoint1XAsDouble(
                getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (setCompartmentGeometricShapeBasePoint1X(document, layoutIndex, elementIndex, x))
        return -1;
    if (setSpeciesGeometricShapeBasePoint1X(document, layoutIndex, elementIndex, x))
        return -1;
    if (setReactionGeometricShapeBasePoint1X(document, layoutIndex, elementIndex, x))
        return -1;

    return 0;
}

int setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (setCompartmentGeometricShapeBasePoint1XAsDouble(document, layoutIndex, elementIndex, x))
        return -1;
    if (setSpeciesGeometricShapeBasePoint1XAsDouble(document, layoutIndex, elementIndex, x))
        return -1;
    if (setReactionGeometricShapeBasePoint1XAsDouble(document, layoutIndex, elementIndex, x))
        return -1;

    return 0;
}

const RelAbsVector getGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex ) {
    return getGeometricShapeBasePoint1Y(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const double getGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector yVector = getGeometricShapeBasePoint1Y(document, graphicalObject, geometricShapeIndex, elementIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(graphicalObject) * yVector.getRelativeValue();
}

const double getGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector yVector = getGeometricShapeBasePoint1Y(document, attribute, geometricShapeIndex, elementIndex);
    return yVector.getAbsoluteValue() + 0.01 * getDimensionHeight(document, attribute) * yVector.getRelativeValue();
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1Y(style, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1Y(style, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1Y(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1Y(style, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1Y(style, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1Y(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1YAsDouble(style, y);
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1YAsDouble(style, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint1YAsDouble(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1YAsDouble(style, y);
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1YAsDouble(style, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint1YAsDouble(style, geometricShapeIndex, elementIndex, y);
}

int setCompartmentGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setCompartmentGeometricShapeBasePoint1Y(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeBasePoint1Y(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setCompartmentGeometricShapeBasePoint1YAsDouble(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeBasePoint1YAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setSpeciesGeometricShapeBasePoint1Y(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeBasePoint1Y(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setSpeciesGeometricShapeBasePoint1YAsDouble(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeBasePoint1YAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setReactionGeometricShapeBasePoint1Y(getGlobalRenderInformation(document), y) && !setReactionGeometricShapeBasePoint1Y(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setReactionGeometricShapeBasePoint1YAsDouble(getGlobalRenderInformation(document), y) &&
        !setReactionGeometricShapeBasePoint1YAsDouble(
                getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (setCompartmentGeometricShapeBasePoint1Y(document, layoutIndex, elementIndex, y))
        return -1;
    if (setSpeciesGeometricShapeBasePoint1Y(document, layoutIndex, elementIndex, y))
        return -1;
    if (setReactionGeometricShapeBasePoint1Y(document, layoutIndex, elementIndex, y))
        return -1;

    return 0;
}

int setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (setCompartmentGeometricShapeBasePoint1YAsDouble(document, layoutIndex, elementIndex, y))
        return -1;
    if (setSpeciesGeometricShapeBasePoint1YAsDouble(document, layoutIndex, elementIndex, y))
        return -1;
    if (setReactionGeometricShapeBasePoint1YAsDouble(document, layoutIndex, elementIndex, y))
        return -1;

    return 0;
}

const RelAbsVector getGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const double getGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector xVector = getGeometricShapeBasePoint2X(document, graphicalObject, geometricShapeIndex, elementIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * xVector.getRelativeValue();
}

const double getGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector xVector = getGeometricShapeBasePoint2X(document, attribute, geometricShapeIndex, elementIndex);
    return xVector.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * xVector.getRelativeValue();
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2X(style, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2X(style, elementIndex, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2X(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2X(style, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2X(style, elementIndex, x);
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2X(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2XAsDouble(style, x);
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2XAsDouble(style, elementIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2XAsDouble(style, geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2XAsDouble(style, x);
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2XAsDouble(style, elementIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2XAsDouble(style, geometricShapeIndex, elementIndex, x);
}

int setCompartmentGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setCompartmentGeometricShapeBasePoint2X(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeBasePoint2X(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setCompartmentGeometricShapeBasePoint2XAsDouble(getGlobalRenderInformation(document), x) && !setCompartmentGeometricShapeBasePoint2XAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setSpeciesGeometricShapeBasePoint2X(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeBasePoint2X(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setSpeciesGeometricShapeBasePoint2XAsDouble(getGlobalRenderInformation(document), x) && !setSpeciesGeometricShapeBasePoint2XAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (!setReactionGeometricShapeBasePoint2X(getGlobalRenderInformation(document), x) && !setReactionGeometricShapeBasePoint2X(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (!setReactionGeometricShapeBasePoint2XAsDouble(getGlobalRenderInformation(document), x) &&
        !setReactionGeometricShapeBasePoint2XAsDouble(
                getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), x))
        return 0;

    return -1;
}

int setGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x) {
    if (setCompartmentGeometricShapeBasePoint2X(document, layoutIndex, elementIndex, x))
        return -1;
    if (setSpeciesGeometricShapeBasePoint2X(document, layoutIndex, elementIndex, x))
        return -1;
    if (setReactionGeometricShapeBasePoint2X(document, layoutIndex, elementIndex, x))
        return -1;

    return 0;
}

int setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x) {
    if (setCompartmentGeometricShapeBasePoint2XAsDouble(document, layoutIndex, elementIndex, x))
        return -1;
    if (setSpeciesGeometricShapeBasePoint2XAsDouble(document, layoutIndex, elementIndex, x))
        return -1;
    if (setReactionGeometricShapeBasePoint2XAsDouble(document, layoutIndex, elementIndex, x))
        return -1;

    return 0;
}

const RelAbsVector getGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getStyle(document, attribute), geometricShapeIndex, elementIndex);
}

const double getGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint2Y = getGeometricShapeBasePoint2Y(getStyle(document, graphicalObject), geometricShapeIndex, elementIndex);
    return basePoint2Y.getAbsoluteValue() + 0.01 * getDimensionWidth(graphicalObject) * basePoint2Y.getRelativeValue();
}

const double getGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    RelAbsVector basePoint2Y = getGeometricShapeBasePoint2Y(getStyle(document, attribute), geometricShapeIndex, elementIndex);
    return basePoint2Y.getAbsoluteValue() + 0.01 * getDimensionWidth(document, attribute) * basePoint2Y.getRelativeValue();
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2Y(style, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2Y(style, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2Y(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2Y(style, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2Y(style, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2Y(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2YAsDouble(style, y);
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2YAsDouble(style, elementIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeBasePoint2YAsDouble(style, geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2YAsDouble(style, y);
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2YAsDouble(style, elementIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeBasePoint2YAsDouble(style, geometricShapeIndex, elementIndex, y);
}

int setCompartmentGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setCompartmentGeometricShapeBasePoint2Y(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeBasePoint2Y(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setCompartmentGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setCompartmentGeometricShapeBasePoint2YAsDouble(getGlobalRenderInformation(document), y) && !setCompartmentGeometricShapeBasePoint2YAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setSpeciesGeometricShapeBasePoint2Y(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeBasePoint2Y(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setSpeciesGeometricShapeBasePoint2YAsDouble(getGlobalRenderInformation(document), y) && !setSpeciesGeometricShapeBasePoint2YAsDouble(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (!setReactionGeometricShapeBasePoint2Y(getGlobalRenderInformation(document), y) && !setReactionGeometricShapeBasePoint2Y(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setReactionGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (!setReactionGeometricShapeBasePoint2YAsDouble(getGlobalRenderInformation(document), y) &&
        !setReactionGeometricShapeBasePoint2YAsDouble(
                getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), y))
        return 0;

    return -1;
}

int setGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y) {
    if (setCompartmentGeometricShapeBasePoint2Y(document, layoutIndex, elementIndex, y))
        return -1;
    if (setSpeciesGeometricShapeBasePoint2Y(document, layoutIndex, elementIndex, y))
        return -1;
    if (setReactionGeometricShapeBasePoint2Y(document, layoutIndex, elementIndex, y))
        return -1;

    return 0;
}

int setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y) {
    if (setCompartmentGeometricShapeBasePoint2YAsDouble(document, layoutIndex, elementIndex, y))
        return -1;
    if (setSpeciesGeometricShapeBasePoint2YAsDouble(document, layoutIndex, elementIndex, y))
        return -1;
    if (setReactionGeometricShapeBasePoint2YAsDouble(document, layoutIndex, elementIndex, y))
        return -1;

    return 0;
}

int addRenderPointToGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return addRenderPointToGeometricShape(style, geometricShapeIndex);
}

int addRenderPointToGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return addRenderPointToGeometricShape(style, geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return addRenderCubicBezierToGeometricShape(style, geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return addRenderCubicBezierToGeometricShape(style, geometricShapeIndex);
}

RenderPoint* removeElementFromGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return removeElementFromGeometricShape(style, geometricShapeIndex, elementIndex);
}

RenderPoint* removeElementFromGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return removeElementFromGeometricShape(style, geometricShapeIndex, elementIndex);
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
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeHref(style, href);
}

int setGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& href) {
    Style* style = getLocalStyle(document, graphicalObject);
    if (!style)
        style = createLocalStyle(document, graphicalObject);
    return setGeometricShapeHref(style, geometricShapeIndex, href);
}

int setGeometricShapeHref(SBMLDocument* document, const std::string& attribute, const std::string& href) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeHref(style, href);
}

int setGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& href) {
    Style* style = getLocalStyle(document, attribute);
    if (!style)
        style = createLocalStyle(document, attribute);
    return setGeometricShapeHref(style, geometricShapeIndex, href);
}

int setCompartmentGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href) {
    if (!setCompartmentGeometricShapeHref(getGlobalRenderInformation(document), href) && !setCompartmentGeometricShapeHref(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), href))
        return 0;

    return -1;
}

int setSpeciesGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href) {
    if (!setSpeciesGeometricShapeHref(getGlobalRenderInformation(document), href) && !setSpeciesGeometricShapeHref(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), href))
        return 0;

    return -1;
}

int setReactionGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href) {
    if (!setReactionGeometricShapeHref(getGlobalRenderInformation(document), href) && !setReactionGeometricShapeHref(
            getLayout(document, layoutIndex), getLocalRenderInformation(document, layoutIndex), href))
        return 0;

    return -1;
}

int setGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href) {
    if (setCompartmentGeometricShapeHref(document, layoutIndex, href))
        return -1;
    if (setSpeciesGeometricShapeHref(document, layoutIndex, href))
        return -1;
    if (setReactionGeometricShapeHref(document, layoutIndex, href))
        return -1;

    return 0;
}

int setStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& styleName) {
    std::map<std::string, std::string> styleFeatures = getPredefinedStyleFeatures(styleName);
    if (styleFeatures.find("background-color") != styleFeatures.end())
        setBackgroundColor(document, layoutIndex, styleFeatures.find("background-color")->second);
    if (styleFeatures.find("compartment-geometric-shape") != styleFeatures.end())
        setCompartmentGeometricShapeType(document, layoutIndex, styleFeatures.find("compartment-geometric-shape")->second);
    if (styleFeatures.find("compartment-geometric-shape-ratio") != styleFeatures.end())
        setCompartmentGeometricShapeRatio(document, layoutIndex, std::stod(styleFeatures.find("compartment-geometric-shape-ratio")->second));
    if (styleFeatures.find("compartment-border-color") != styleFeatures.end())
        setCompartmentStrokeColor(document, layoutIndex, styleFeatures.find("compartment-border-color")->second);
    if (styleFeatures.find("compartment-border-width") != styleFeatures.end())
        setCompartmentStrokeWidth(document, layoutIndex, std::stod(styleFeatures.find("compartment-border-width")->second));
    if (styleFeatures.find("compartment-fill-color") != styleFeatures.end())
        setCompartmentFillColor(document, layoutIndex, styleFeatures.find("compartment-fill-color")->second);
    if (styleFeatures.find("compartment-font-color") != styleFeatures.end())
        setCompartmentFontColor(document, layoutIndex, styleFeatures.find("compartment-font-color")->second);
    if (styleFeatures.find("compartment-font-size") != styleFeatures.end())
        setCompartmentFontSize(document, layoutIndex, styleFeatures.find("compartment-font-size")->second);
    if (styleFeatures.find("compartment-font-style") != styleFeatures.end())
        setCompartmentFontStyle(document, layoutIndex, styleFeatures.find("compartment-font-style")->second);
    if (styleFeatures.find("compartment-font-weight") != styleFeatures.end())
        setCompartmentFontWeight(document, layoutIndex, styleFeatures.find("compartment-font-weight")->second);
    if (styleFeatures.find("species-geometric-shape") != styleFeatures.end())
        setSpeciesGeometricShapeType(document, layoutIndex, styleFeatures.find("species-geometric-shape")->second);
    if (styleFeatures.find("species-geometric-shape-ratio") != styleFeatures.end())
        setSpeciesGeometricShapeRatio(document, layoutIndex, std::stod(styleFeatures.find("species-geometric-shape-ratio")->second));
    if (styleFeatures.find("species-border-color") != styleFeatures.end())
        setSpeciesStrokeColor(document, layoutIndex, styleFeatures.find("species-border-color")->second);
    if (styleFeatures.find("species-border-width") != styleFeatures.end())
        setSpeciesStrokeWidth(document, layoutIndex, std::stod(styleFeatures.find("species-border-width")->second));
    if (styleFeatures.find("species-fill-color") != styleFeatures.end())
        setSpeciesFillColor(document, layoutIndex, styleFeatures.find("species-fill-color")->second);
    if (styleFeatures.find("species-font-color") != styleFeatures.end())
        setSpeciesFontColor(document, layoutIndex, styleFeatures.find("species-font-color")->second);
    if (styleFeatures.find("species-font-size") != styleFeatures.end())
        setSpeciesFontSize(document, layoutIndex, styleFeatures.find("species-font-size")->second);
    if (styleFeatures.find("species-font-style") != styleFeatures.end())
        setSpeciesFontStyle(document, layoutIndex, styleFeatures.find("species-font-style")->second);
    if (styleFeatures.find("species-font-weight") != styleFeatures.end())
        setSpeciesFontWeight(document, layoutIndex, styleFeatures.find("species-font-weight")->second);
    if (styleFeatures.find("reaction-geometric-shape") != styleFeatures.end())
        setReactionGeometricShapeType(document, layoutIndex, styleFeatures.find("reaction-geometric-shape")->second);
    if (styleFeatures.find("reaction-geometric-shape-ratio") != styleFeatures.end())
        setReactionGeometricShapeRatio(document, layoutIndex, std::stod(styleFeatures.find("reaction-geometric-shape-ratio")->second));
    if (styleFeatures.find("reaction-geometric-shape-center-x") != styleFeatures.end())
        setReactionGeometricShapeCenterX(document, layoutIndex, styleFeatures.find("reaction-geometric-shape-center-x")->second);
    if (styleFeatures.find("reaction-geometric-shape-center-y") != styleFeatures.end())
        setReactionGeometricShapeCenterY(document, layoutIndex, styleFeatures.find("reaction-geometric-shape-center-y")->second);
    if (styleFeatures.find("reaction-geometric-shape-radius-x") != styleFeatures.end())
        setReactionGeometricShapeRadiusX(document, layoutIndex, styleFeatures.find("reaction-geometric-shape-radius-x")->second);
    if (styleFeatures.find("reaction-geometric-shape-radius-y") != styleFeatures.end())
        setReactionGeometricShapeRadiusY(document, layoutIndex, styleFeatures.find("reaction-geometric-shape-radius-y")->second);
    if (styleFeatures.find("reaction-line-color") != styleFeatures.end())
        setReactionStrokeColor(document, layoutIndex, styleFeatures.find("reaction-line-color")->second);
    if (styleFeatures.find("reaction-line-width") != styleFeatures.end())
        setReactionStrokeWidth(document, layoutIndex, std::stod(styleFeatures.find("reaction-line-width")->second));
    if (styleFeatures.find("reaction-fill-color") != styleFeatures.end())
        setReactionFillColor(document, layoutIndex, styleFeatures.find("reaction-fill-color")->second);
    if (styleFeatures.find("reaction-font-color") != styleFeatures.end())
        setReactionFontColor(document, layoutIndex, styleFeatures.find("reaction-font-color")->second);
    if (styleFeatures.find("reaction-font-size") != styleFeatures.end())
        setReactionFontSize(document, layoutIndex, styleFeatures.find("reaction-font-size")->second);
    if (styleFeatures.find("reaction-font-style") != styleFeatures.end())
        setReactionFontStyle(document, layoutIndex, styleFeatures.find("reaction-font-style")->second);
    if (styleFeatures.find("reaction-font-weight") != styleFeatures.end())
        setReactionFontWeight(document, layoutIndex, styleFeatures.find("reaction-font-weight")->second);
    if (styleFeatures.find("line-ending-border-color") != styleFeatures.end())
        setLineEndingStrokeColor(document, layoutIndex, styleFeatures.find("line-ending-border-color")->second);
    if (styleFeatures.find("line-ending-border-width") != styleFeatures.end())
        setLineEndingStrokeWidth(document, layoutIndex, std::stod(styleFeatures.find("line-ending-border-width")->second));
    if (styleFeatures.find("line-ending-fill-color") != styleFeatures.end())
        setLineEndingFillColor(document, layoutIndex, styleFeatures.find("line-ending-fill-color")->second);

    return 0;
}

bool whetherDisplayReactionTextLabel(const std::string& styleName) {
    std::map<std::string, std::string> styleFeatures = getPredefinedStyleFeatures(styleName);
    if (styleFeatures.find("display-reaction-text-label") != styleFeatures.end())
        return styleFeatures.find("display-reaction-text-label")->second == "true";

    return false;
}

}
