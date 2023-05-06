#include "libsbml_ne_render.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"
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

const unsigned int getNumGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation) {
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->size();

    return 0;
}

GlobalRenderInformation* getGlobalRenderInformation(SBMLDocument* document, unsigned int n) {
    return getGlobalRenderInformation(getListOfGlobalRenderInformation(document), n);
}

GlobalRenderInformation* getGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation, unsigned int n) {
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->get(n);

    return NULL;
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

const unsigned int getNumLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation) {
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->size();

    return 0;
}

LocalRenderInformation* getLocalRenderInformation(Layout* layout, unsigned int n) {
    return getLocalRenderInformation(getListOfLocalRenderInformation(layout), n);
}

LocalRenderInformation* getLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation, unsigned int n) {
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->get(n);

    return NULL;
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

bool isSetBackgroundColor(GlobalRenderInformation* globalRenderInformation) {
    if (globalRenderInformation)
        globalRenderInformation->isSetBackgroundColor();

    return false;
}

const std::string getBackgroundColor(GlobalRenderInformation* globalRenderInformation) {
    if (globalRenderInformation)
        return globalRenderInformation->getBackgroundColor();

    return "";
}

int setBackgroundColor(GlobalRenderInformation* globalRenderInformation, const std::string& backgroundColor) {
    if (globalRenderInformation) {
        globalRenderInformation->setBackgroundColor(backgroundColor);
        return 0;
    }

    return -1;
}

ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, const std::string& sid) {
    if (renderInformationBase)
        return renderInformationBase->getColorDefinition(sid);

    return NULL;
}

bool isSetValue(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetValue(getColorDefinition(renderInformationBase, sid));
}

bool isSetValue(ColorDefinition* colorDefinition) {
    if (colorDefinition)
        colorDefinition->isSetValue();

    return false;
}

const std::string getValue(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getValue(getColorDefinition(renderInformationBase, sid));
}

const std::string getValue(ColorDefinition* colorDefinition) {
    if (colorDefinition)
        return colorDefinition->getValue();

    return "";
}

int setValue(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& value) {
    return setValue(getColorDefinition(renderInformationBase, sid), value);
}

int setValue(ColorDefinition* colorDefinition, const std::string& value) {
    if (colorDefinition) {
        colorDefinition->setValue(value);
        return 0;
    }

    return -1;
}

GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, const std::string& sid) {
    if (renderInformationBase)
        return renderInformationBase->getGradientDefinition(sid);

    return NULL;
}

bool isLinearGradient(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isLinearGradient(getGradientDefinition(renderInformationBase, sid));
}

bool isLinearGradient(GradientBase* gradientBase) {
    if (gradientBase)
        return gradientBase->isLinearGradient();

    return false;
}

bool isRadialGradient(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isRadialGradient(getGradientDefinition(renderInformationBase, sid));
}

bool isRadialGradient(GradientBase* gradientBase) {
    if (gradientBase)
        return gradientBase->isRadialGradient();

    return false;
}

bool isSetSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetSpreadMethod(getGradientDefinition(renderInformationBase, sid));
}

bool isSetSpreadMethod(GradientBase* gradientBase) {
    if (gradientBase)
        gradientBase->isSetSpreadMethod();

    return false;
}

const std::string getSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getSpreadMethod(getGradientDefinition(renderInformationBase, sid));
}

const std::string getSpreadMethod(GradientBase* gradientBase) {
    if (gradientBase)
        return gradientBase->getSpreadMethodAsString();

    return "";
}

int setSpreadMethod(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& spreadMethod) {
    return setSpreadMethod(getGradientDefinition(renderInformationBase, sid), spreadMethod);
}

int setSpreadMethod(GradientBase* gradientBase, const std::string& spreadMethod) {
    if (gradientBase) {
        gradientBase->setSpreadMethod(spreadMethod);
        return 0;
    }

    return -1;
}

unsigned int getNumGradientStops(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getNumGradientStops(getGradientDefinition(renderInformationBase, sid));
}

unsigned int getNumGradientStops(GradientBase* gradientBase) {
    if (gradientBase)
        return gradientBase->getNumGradientStops();

    return 0;
}

GradientStop* getGradientStop(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n) {
    return getGradientStop(getGradientDefinition(renderInformationBase, sid), n);
}

GradientStop* getGradientStop(GradientBase* gradientBase, unsigned  int n) {
    if (gradientBase)
        return gradientBase->getGradientStop(n);

    return NULL;
}

bool isSetOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n) {
    return isSetOffset(getGradientDefinition(renderInformationBase, sid), n);
}

bool isSetOffset(GradientBase* gradientBase, unsigned  int n) {
    return isSetOffset(getGradientStop(gradientBase, n));
}

bool isSetOffset(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->isSetOffset();

    return false;
}

const RelAbsVector getOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n) {
    return getOffset(getGradientDefinition(renderInformationBase, sid), n);
}

const RelAbsVector getOffset(GradientBase* gradientBase, unsigned  int n) {
    return getOffset(getGradientStop(gradientBase, n));
}

const RelAbsVector getOffset(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->getOffset();

    return RelAbsVector();
}

int setOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n, const RelAbsVector& offset) {
    return setOffset(getGradientDefinition(renderInformationBase, sid), n, offset);
}

int setOffset(GradientBase* gradientBase, unsigned  int n, const RelAbsVector& offset) {
    return setOffset(getGradientStop(gradientBase, n), offset);
}

int setOffset(GradientStop* gradientStop, const RelAbsVector& offset) {
    if (gradientStop) {
        gradientStop->setOffset(offset);
        return 0;
    }

    return -1;
}

bool isSetStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n) {
    return isSetStopColor(getGradientDefinition(renderInformationBase, sid), n);
}

bool isSetStopColor(GradientBase* gradientBase, unsigned  int n) {
    return isSetStopColor(getGradientStop(gradientBase, n));
}

bool isSetStopColor(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->isSetStopColor();

    return false;
}

const std::string getStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n) {
    return getStopColor(getGradientDefinition(renderInformationBase, sid), n);
}

const std::string getStopColor(GradientBase* gradientBase, unsigned  int n) {
    return getStopColor(getGradientStop(gradientBase, n));
}

const std::string getStopColor(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->getStopColor();

    return "";
}

int setStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned  int n, const std::string& stopColor) {
    return setStopColor(getGradientDefinition(renderInformationBase, sid), n, stopColor);
}

int setStopColor(GradientBase* gradientBase, unsigned  int n, const std::string& stopColor) {
    return setStopColor(getGradientStop(gradientBase, n), stopColor);
}

int setStopColor(GradientStop* gradientStop, const std::string& stopColor) {
    if (gradientStop) {
        gradientStop->setStopColor(stopColor);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientX1(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientX1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetX1();

    return false;
}

const RelAbsVector getLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientX1(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientX1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getX1();

    return RelAbsVector();
}

int setLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x1) {
    return setLinearGradientX1(getGradientDefinition(renderInformationBase, sid), x1);
}

int setLinearGradientX1(GradientBase* gradientBase, const RelAbsVector& x1) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient *) gradientBase)->setX1(x1);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientX2(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientX2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetX2();

    return false;
}

const RelAbsVector getLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientX2(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientX2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getX2();

    return RelAbsVector();
}

int setLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x2) {
    return setLinearGradientX2(getGradientDefinition(renderInformationBase, sid), x2);
}

int setLinearGradientX2(GradientBase* gradientBase, const RelAbsVector& x2) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient *) gradientBase)->setX2(x2);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientY1(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientY1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetY1();

    return false;
}

const RelAbsVector getLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientY1(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientY1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getY1();

    return RelAbsVector();
}

int setLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y1) {
    return setLinearGradientY1(getGradientDefinition(renderInformationBase, sid), y1);
}

int setLinearGradientY1(GradientBase* gradientBase, const RelAbsVector& y1) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient*) gradientBase)->setY1(y1);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientY2(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientY2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetY2();

    return false;
}

const RelAbsVector getLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientY2(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientY2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getY2();

    return RelAbsVector();
}

int setLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y2) {
    return setLinearGradientY2(getGradientDefinition(renderInformationBase, sid), y2);
}

int setLinearGradientY2(GradientBase* gradientBase, const RelAbsVector& y2) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient*) gradientBase)->setY2(y2);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientCx(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientCx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetCx();

    return false;
}

const RelAbsVector getRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientCx(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientCx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getCx();

    return RelAbsVector();
}

int setRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cx) {
    return setRadialGradientCx(getGradientDefinition(renderInformationBase, sid), cx);
}

int setRadialGradientCx(GradientBase* gradientBase, const RelAbsVector& cx) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*) gradientBase)->setCx(cx);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientCy(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientCy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetCy();

    return false;
}

const RelAbsVector getRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientCy(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientCy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getCy();

    return RelAbsVector();
}

int setRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cy) {
    return setRadialGradientCy(getGradientDefinition(renderInformationBase, sid), cy);
}

int setRadialGradientCy(GradientBase* gradientBase, const RelAbsVector& cy) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setCy(cy);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientFx(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientFx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetFx();

    return false;
}

const RelAbsVector getRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientFx(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientFx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getFx();

    return RelAbsVector();
}

int setRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fx) {
    return setRadialGradientFx(getGradientDefinition(renderInformationBase, sid), fx);
}

int setRadialGradientFx(GradientBase* gradientBase, const RelAbsVector& fx) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setFx(fx);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientFy(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientFy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetFy();

    return false;
}

const RelAbsVector getRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientFy(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientFy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getFy();

    return RelAbsVector();
}

int setRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fy) {
    return setRadialGradientFy(getGradientDefinition(renderInformationBase, sid), fy);
}

int setRadialGradientFy(GradientBase* gradientBase, const RelAbsVector& fy) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setFy(fy);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientR(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientR(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetR();

    return false;
}

const RelAbsVector getRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientR(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientR(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getR();

    return RelAbsVector();
}

int setRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& r) {
    return setRadialGradientR(getGradientDefinition(renderInformationBase, sid), r);
}

int setRadialGradientR(GradientBase* gradientBase, const RelAbsVector& r) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setR(r);
        return 0;
    }

    return -1;
}

LineEnding* getLineEnding(RenderInformationBase* renderInformationBase, const std::string& sid) {
    if (renderInformationBase)
        return renderInformationBase->getLineEnding(sid);

    return NULL;
}

bool isSetEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetEnableRotationalMapping(getLineEnding(renderInformationBase, sid));
}

bool isSetEnableRotationalMapping(LineEnding* lineEnding) {
    if (lineEnding) {
        lineEnding->isSetEnableRotationalMapping();
    }

    return false;
}

bool getEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getEnableRotationalMapping(getLineEnding(renderInformationBase, sid));
}

bool getEnableRotationalMapping(LineEnding* lineEnding) {
    if (lineEnding) {
        lineEnding->getEnableRotationalMapping();
    }

    return false;
}

int setEnableRotationalMapping(RenderInformationBase* renderInformationBase, const std::string& sid, bool enableRotationalMapping) {
    return setEnableRotationalMapping(getLineEnding(renderInformationBase, sid), enableRotationalMapping);
}

int setEnableRotationalMapping(LineEnding* lineEnding, bool enableRotationalMapping) {
    if (lineEnding) {
        lineEnding->setEnableRotationalMapping(enableRotationalMapping);
    }

    return false;
}

BoundingBox* getBoundingBox(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getBoundingBox(getLineEnding(renderInformationBase, sid));
}

BoundingBox* getBoundingBox(LineEnding* lineEnding) {
    if (lineEnding)
        return lineEnding->getBoundingBox();

    return NULL;
}

RenderGroup* getRenderGroupOfLineEnding(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRenderGroup(getLineEnding(renderInformationBase, sid));
}

RenderGroup* getRenderGroup(LineEnding* lineEnding) {
    if (lineEnding)
        return lineEnding->getGroup();

    return NULL;
}

Style* getStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    Style* style = NULL;
    style = getStyleById(renderInformationBase, graphicalObject);
    if (style)
        return style;
    style = getStyleByRole(renderInformationBase, graphicalObject);
    if (style)
        return style;
    style = getStyleByType(renderInformationBase, graphicalObject);
    if (style)
        return style;

    return NULL;
}

Style* getStyle(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    Style* style = NULL;
    style = getStyleById(renderInformationBase, attribute);
    if (style)
        return style;
    style = getStyleByRole(renderInformationBase, attribute);
    if (style)
        return style;
    style = getStyleByType(renderInformationBase, attribute);
    if (style)
        return style;

    return NULL;
}

Style* getStyleById(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStyleById(renderInformationBase, getId(graphicalObject));
}

Style* getStyleById(RenderInformationBase* renderInformationBase, const std::string& id) {
    if (renderInformationBase)
        return findStyleByIdList(renderInformationBase, id);

    return NULL;
}

Style* getStyleByRole(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStyleByRole(renderInformationBase, getObjectRole(graphicalObject));
}

Style* getStyleByRole(RenderInformationBase* renderInformationBase, const std::string& role) {
    if (renderInformationBase)
        return findStyleByRoleList(renderInformationBase, role);

    return NULL;
}

Style* getStyleByType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStyleByType(renderInformationBase, getStyleType(graphicalObject));
}

Style* getStyleByType(RenderInformationBase* renderInformationBase, const std::string& type) {
    if (renderInformationBase)
        return findStyleByTypeList(renderInformationBase, type);

    return NULL;
}

RenderGroup* getRenderGroup(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getRenderGroup(getStyle(renderInformationBase, graphicalObject));
}

RenderGroup* getRenderGroup(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getRenderGroup(getStyle(renderInformationBase, attribute));
}

RenderGroup* getRenderGroup(Style* style) {
    if (style)
        return style->getGroup();

    return NULL;
}

bool isSetStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetStrokeColor(getStyle(renderInformationBase, graphicalObject));
}

bool isSetStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetStrokeColor(getStyle(renderInformationBase, attribute));
}

bool isSetStrokeColor(Style* style) {
    return isSetStrokeColor(getRenderGroup(style));
}

bool isSetStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStroke();

    return false;
}

const std::string getStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStrokeColor(getStyle(renderInformationBase, graphicalObject));
}

const std::string getStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getStrokeColor(getStyle(renderInformationBase, attribute));
}

const std::string getStrokeColor(Style* style) {
    return getStrokeColor(getRenderGroup(style));
}

const std::string getStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStroke();
    
    return "";
}

int setStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& stroke) {
    return setStrokeColor(getStyle(renderInformationBase, graphicalObject), stroke);
}

int setStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& stroke) {
    return setStrokeColor(getStyle(renderInformationBase, attribute), stroke);
}

int setStrokeColor(Style* style, const std::string& stroke) {
    return setStrokeColor(getRenderGroup(style), stroke);
}

int setStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& stroke) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStroke(stroke);
        return 0;
    }
    
    return -1;
}

bool isSetStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetStrokeWidth(getStyle(renderInformationBase, graphicalObject));
}

bool isSetStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetStrokeWidth(getStyle(renderInformationBase, attribute));
}

bool isSetStrokeWidth(Style* style) {
    return isSetStrokeWidth(getRenderGroup(style));
}

bool isSetStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStrokeWidth();

    return false;
}

const double getStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStrokeWidth(getStyle(renderInformationBase, graphicalObject));
}

const double getStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getStrokeWidth(getStyle(renderInformationBase, attribute));
}

const double getStrokeWidth(Style* style) {
    return getStrokeWidth(getRenderGroup(style));
}

const double getStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeWidth();
    
    return 0.0;
}

int setStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D, const double& strokeWidth) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeWidth(strokeWidth);
        return 0;
    }
    
    return -1;
}

int setStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& strokeWidth) {
    return setStrokeWidth(getStyle(renderInformationBase, graphicalObject), strokeWidth);
}

int setStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& strokeWidth) {
    return setStrokeWidth(getStyle(renderInformationBase, attribute), strokeWidth);
}

int setStrokeWidth(Style* style, const double& strokeWidth) {
    return setStrokeWidth(getRenderGroup(style), strokeWidth);
}

bool isSetStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetStrokeDashArray(getStyle(renderInformationBase, graphicalObject));
}

bool isSetStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetStrokeDashArray(getStyle(renderInformationBase, attribute));
}

bool isSetStrokeDashArray(Style* style) {
    return isSetStrokeDashArray(getRenderGroup(style));
}

bool isSetStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStrokeDashArray();

    return false;
}

const std::vector<unsigned int> getStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStrokeDashArray(getStyle(renderInformationBase, graphicalObject));
}

const std::vector<unsigned int> getStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getStrokeDashArray(getStyle(renderInformationBase, attribute));
}

const std::vector<unsigned int> getStrokeDashArray(Style* style) {
    return getStrokeDashArray(getRenderGroup(style));
}

const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeDashArray();
    
    return std::vector<unsigned int>();
}

int setStrokeDashArray(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyle(renderInformationBase, graphicalObject), strokeDashArray);
}

int setStrokeDashArray(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyle(renderInformationBase, attribute), strokeDashArray);
}

int setStrokeDashArray(Style* style, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getRenderGroup(style), strokeDashArray);
}

int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeDashArray(strokeDashArray);
        return 0;
    }
    
    return -1;
}

unsigned int getNumStrokeDashes(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getNumStrokeDashes(getStyle(renderInformationBase, graphicalObject));
}

unsigned int getNumStrokeDashes(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getNumStrokeDashes(getStyle(renderInformationBase, attribute));
}

unsigned int getNumStrokeDashes(Style* style) {
    return getNumStrokeDashes(getRenderGroup(style));
}

unsigned int getNumStrokeDashes(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return getStrokeDashArray(graphicalPrimitive1D).size();
}

unsigned int getDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return getDash(getStyle(renderInformationBase, graphicalObject), n);
}

unsigned int getDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return getDash(getStyle(renderInformationBase, attribute), n);
}

unsigned int getDash(Style* style, unsigned  int n) {
    return getDash(getRenderGroup(style), n);
}

unsigned int getDash(GraphicalPrimitive1D* graphicalPrimitive1D, unsigned  int n) {
    if (graphicalPrimitive1D)
        graphicalPrimitive1D->getDashByIndex(n);

    return 0;
}

bool isSetFontColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFontColor(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFontColor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFontColor(getStyle(renderInformationBase, attribute));
}

bool isSetFontColor(Style* style) {
    return isSetFontColor(getRenderGroup(style));
}

bool isSetFontColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return isSetStrokeColor(graphicalPrimitive1D);
}

const std::string getFontColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFontColor(getStyle(renderInformationBase, graphicalObject));
}

const std::string getFontColor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFontColor(getStyle(renderInformationBase, attribute));
}

const std::string getFontColor(Style* style) {
    return getFontColor(getRenderGroup(style));
}

const std::string getFontColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return getStrokeColor(graphicalPrimitive1D);
}

int setFontColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontColor) {
    return setFontColor(getStyle(renderInformationBase, graphicalObject), fontColor);
}

int setFontColor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontColor) {
    return setFontColor(getStyle(renderInformationBase, attribute), fontColor);
}

int setFontColor(Style* style, const std::string& fontColor) {
    return setFontColor(getRenderGroup(style), fontColor);
}

int setFontColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontColor) {
    return setStrokeColor(graphicalPrimitive1D, fontColor);
}

bool isSetFontFamily(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFontFamily(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFontFamily(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFontFamily(getStyle(renderInformationBase, attribute));
}

bool isSetFontFamily(Style* style) {
    return isSetFontFamily(getRenderGroup(style));
}

bool isSetFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetFontFamily();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetFontFamily();
    }

    return false;
}

const std::string getFontFamily(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFontFamily(getStyle(renderInformationBase, graphicalObject));
}

const std::string getFontFamily(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFontFamily(getStyle(renderInformationBase, attribute));
}

const std::string getFontFamily(Style* style) {
    return getFontFamily(getRenderGroup(style));
}

const std::string getFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getFontFamily();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getFontFamily();
    }

    return "";
}

int setFontFamily(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontFamily) {
    return setFontFamily(getStyle(renderInformationBase, graphicalObject), fontFamily);
}

int setFontFamily(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontFamily) {
    return setFontFamily(getStyle(renderInformationBase, attribute), fontFamily);
}

int setFontFamily(Style* style, const std::string& fontFamily) {
    return setFontFamily(getRenderGroup(style), fontFamily);
}

int setFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontFamily) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setFontFamily(fontFamily);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setFontFamily(fontFamily);
            return 0;
        }
    }

    return -1;
}

bool isSetFontSize(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFontSize(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFontSize(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFontSize(getStyle(renderInformationBase, attribute));
}

bool isSetFontSize(Style* style) {
    return isSetFontSize(getRenderGroup(style));
}

bool isSetFontSize(GraphicalPrimitive1D* graphicalPrimitive1D) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup)
        return renderGroup->isSetFontSize();
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text)
        return text->isSetFontSize();

    return false;
}

const RelAbsVector getFontSize(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFontSize(getStyle(renderInformationBase, graphicalObject));
}

const RelAbsVector getFontSize(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFontSize(getStyle(renderInformationBase, attribute));
}

const RelAbsVector getFontSize(Style* style) {
    return getFontSize(getRenderGroup(style));
}

const RelAbsVector getFontSize(GraphicalPrimitive1D* graphicalPrimitive1D) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup)
        return renderGroup->getFontSize();
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text)
        return text->getFontSize();

    return RelAbsVector();
}

int setFontSize(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& fontSize) {
    return setFontSize(getStyle(renderInformationBase, graphicalObject), fontSize);
}

int setFontSize(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& fontSize) {
    return setFontSize(getStyle(renderInformationBase, attribute), fontSize);
}

int setFontSize(Style* style, const RelAbsVector& fontSize) {
    return setFontSize(getRenderGroup(style), fontSize);
}

int setFontSize(GraphicalPrimitive1D* graphicalPrimitive1D, const RelAbsVector& fontSize) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup) {
        renderGroup->setFontSize(fontSize);
        return 0;
    }
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text) {
        text->setFontSize(fontSize);
        return 0;
    }

    return -1;
}

bool isSetFontWeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFontWeight(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFontWeight(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFontWeight(getStyle(renderInformationBase, attribute));
}

bool isSetFontWeight(Style* style) {
    return isSetFontWeight(getRenderGroup(style));
}

bool isSetFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetFontWeight();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetFontWeight();
    }

    return false;
}

const std::string getFontWeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFontWeight(getStyle(renderInformationBase, graphicalObject));
}

const std::string getFontWeight(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFontWeight(getStyle(renderInformationBase, attribute));
}

const std::string getFontWeight(Style* style) {
    return getFontWeight(getRenderGroup(style));
}

const std::string getFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getFontWeightAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getFontWeightAsString();
    }

    return "";
}

int setFontWeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontWeight) {
    return setFontWeight(getStyle(renderInformationBase, graphicalObject), fontWeight);
}

int setFontWeight(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontWeight) {
    return setFontWeight(getStyle(renderInformationBase, attribute), fontWeight);
}

int setFontWeight(Style* style, const std::string& fontWeight) {
    return setFontWeight(getRenderGroup(style), fontWeight);
}

int setFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontWeight) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setFontWeight(fontWeight);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setFontWeight(fontWeight);
            return 0;
        }
    }

    return -1;
}

bool isSetFontStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFontStyle(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFontStyle(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFontStyle(getStyle(renderInformationBase, attribute));
}

bool isSetFontStyle(Style* style) {
    return isSetFontStyle(getRenderGroup(style));
}

bool isSetFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetFontStyle();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetFontStyle();
    }

    return false;
}

const std::string getFontStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFontStyle(getStyle(renderInformationBase, graphicalObject));
}

const std::string getFontStyle(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFontStyle(getStyle(renderInformationBase, attribute));
}

const std::string getFontStyle(Style* style) {
    return getFontStyle(getRenderGroup(style));
}

const std::string getFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getFontStyleAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getFontStyleAsString();
    }

    return "";
}

int setFontStyle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fontStyle) {
    return setFontStyle(getStyle(renderInformationBase, graphicalObject), fontStyle);
}

int setFontStyle(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fontStyle) {
    return setFontStyle(getStyle(renderInformationBase, attribute), fontStyle);
}

int setFontStyle(Style* style, const std::string& fontStyle) {
    return setFontStyle(getRenderGroup(style), fontStyle);
}

int setFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontStyle) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setFontStyle(fontStyle);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setFontStyle(fontStyle);
            return 0;
        }
    }

    return -1;
}

bool isSetTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetTextAnchor(getStyle(renderInformationBase, graphicalObject));
}

bool isSetTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetTextAnchor(getStyle(renderInformationBase, attribute));
}

bool isSetTextAnchor(Style* style) {
    return isSetTextAnchor(getRenderGroup(style));
}

bool isSetTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetTextAnchor();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetTextAnchor();
    }

    return false;
}

const std::string getTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getTextAnchor(getStyle(renderInformationBase, graphicalObject));
}

const std::string getTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getTextAnchor(getStyle(renderInformationBase, attribute));
}

const std::string getTextAnchor(Style* style) {
    return getTextAnchor(getRenderGroup(style));
}

const std::string getTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getTextAnchorAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getTextAnchorAsString();
    }

    return "";
}

int setTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& textAnchor) {
    return setTextAnchor(getStyle(renderInformationBase, graphicalObject), textAnchor);
}

int setTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& textAnchor) {
    return setTextAnchor(getStyle(renderInformationBase, attribute), textAnchor);
}

int setTextAnchor(Style* style, const std::string& textAnchor) {
    return setTextAnchor(getRenderGroup(style), textAnchor);
}

int setTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& textAnchor) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setTextAnchor(textAnchor);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setTextAnchor(textAnchor);
            return 0;
        }
    }

    return -1;
}

bool isSetVTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetVTextAnchor(getStyle(renderInformationBase, graphicalObject));
}

bool isSetVTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetVTextAnchor(getStyle(renderInformationBase, attribute));
}

bool isSetVTextAnchor(Style* style) {
    return isSetVTextAnchor(getRenderGroup(style));
}

bool isSetVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetVTextAnchor();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetVTextAnchor();
    }

    return false;
}

const std::string getVTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getVTextAnchor(getStyle(renderInformationBase, graphicalObject));
}

const std::string getVTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getVTextAnchor(getStyle(renderInformationBase, attribute));
}

const std::string getVTextAnchor(Style* style) {
    return getVTextAnchor(getRenderGroup(style));
}

const std::string getVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getVTextAnchorAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getVTextAnchorAsString();
    }

    return "";
}

int setVTextAnchor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& vtextAnchor) {
    return setVTextAnchor(getStyle(renderInformationBase, graphicalObject), vtextAnchor);
}

int setVTextAnchor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& vtextAnchor) {
    return setVTextAnchor(getStyle(renderInformationBase, attribute), vtextAnchor);
}

int setVTextAnchor(Style* style, const std::string& vtextAnchor) {
    return setVTextAnchor(getRenderGroup(style), vtextAnchor);
}

int setVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& vtextAnchor) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setVTextAnchor(vtextAnchor);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setVTextAnchor(vtextAnchor);
            return 0;
        }
    }

    return -1;
}

bool isSetFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFillColor(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFillColor(getStyle(renderInformationBase, attribute));
}

bool isSetFillColor(Style* style) {
    return isSetFillColor(getRenderGroup(style));
}

bool isSetFillColor(GraphicalPrimitive2D* graphicalPrimitive2D) {
    if (graphicalPrimitive2D)
        return graphicalPrimitive2D->isSetFill();

    return false;
}

const std::string getFillColor(GraphicalPrimitive2D* graphicalPrimitive2D) {
    if (graphicalPrimitive2D)
        return graphicalPrimitive2D->getFill();
    
    return "";
}

int setFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fillColor) {
    return setFillColor(getStyle(renderInformationBase, graphicalObject), fillColor);
}

int setFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fillColor) {
    return setFillColor(getStyle(renderInformationBase, attribute), fillColor);
}

int setFillColor(Style* style, const std::string& fillColor) {
    return setFillColor(getRenderGroup(style), fillColor);
}

int setFillColor(GraphicalPrimitive2D* graphicalPrimitive2D, const std::string& fillColor) {
    if (graphicalPrimitive2D) {
        graphicalPrimitive2D->setFill(fillColor);
        return 0;
    }
    
    return -1;
}

bool isSetStartHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetStartHead(getStyle(renderInformationBase, graphicalObject));
}

bool isSetStartHead(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetStartHead(getStyle(renderInformationBase, attribute));
}

bool isSetStartHead(Style* style) {
    return isSetStartHead(getRenderGroup(style));
}

bool isSetStartHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->isSetStartHead();

    return false;
}

const std::string getStartHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getStartHead(getStyle(renderInformationBase, graphicalObject));
}

const std::string getStartHead(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getStartHead(getStyle(renderInformationBase, attribute));
}

const std::string getStartHead(Style* style) {
    return getStartHead(getRenderGroup(style));
}

const std::string getStartHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getStartHead();

    return "";
}

int setStartHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& startHead) {
    return setStartHead(getStyle(renderInformationBase, graphicalObject), startHead);
}

int setStartHead(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& startHead) {
    return setStartHead(getStyle(renderInformationBase, attribute), startHead);
}

int setStartHead(Style* style, const std::string& startHead) {
    return setStartHead(getRenderGroup(style), startHead);
}

int setStartHead(RenderGroup* renderGroup, const std::string startHead) {
    if (renderGroup) {
        renderGroup->setStartHead(startHead);
        return 0;
    }

    return -1;
}

bool isSetEndHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetEndHead(getStyle(renderInformationBase, graphicalObject));
}

bool isSetEndHead(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetEndHead(getStyle(renderInformationBase, attribute));
}

bool isSetEndHead(Style* style) {
    return isSetEndHead(getRenderGroup(style));
}

bool isSetEndHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->isSetEndHead();

    return false;
}

const std::string getEndHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getEndHead(getStyle(renderInformationBase, graphicalObject));
}

const std::string getStgetEndHeadartHead(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getEndHead(getStyle(renderInformationBase, attribute));
}

const std::string getEndHead(Style* style) {
    return getEndHead(getRenderGroup(style));
}

const std::string getEndHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getEndHead();

    return "";
}

int setEndHead(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& endHead) {
    return setEndHead(getStyle(renderInformationBase, graphicalObject), endHead);
}

int setEndHead(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& endHead) {
    return setEndHead(getStyle(renderInformationBase, attribute), endHead);
}

int setEndHead(Style* style, const std::string& endHead) {
    return setEndHead(getRenderGroup(style), endHead);
}

int setEndHead(RenderGroup* renderGroup, const std::string endHead) {
    if (renderGroup) {
        renderGroup->setEndHead(endHead);
        return 0;
    }

    return -1;
}

unsigned int getNumGeometricShapes(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getNumGeometricShapes(getStyle(renderInformationBase, graphicalObject));
}

unsigned int getNumGeometricShapes(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getNumGeometricShapes(getStyle(renderInformationBase, attribute));
}

unsigned int getNumGeometricShapes(Style* style) {
    return getNumGeometricShapes(getRenderGroup(style));
}

unsigned int getNumGeometricShapes(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getNumElements();

    return 0;
}

Transformation2D* getGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return getGeometricShape(getStyle(renderInformationBase, graphicalObject), n);
}

Transformation2D* getGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return getGeometricShape(getStyle(renderInformationBase, attribute), n);
}

Transformation2D* getGeometricShape(Style* style, unsigned  int n) {
    return getGeometricShape(getRenderGroup(style), n);
}

Transformation2D* getGeometricShape(RenderGroup* renderGroup, unsigned  int n) {
    if (renderGroup)
        return renderGroup->getElement(n);

    return NULL;
}

bool isRectangle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return isRectangle(getStyle(renderInformationBase, graphicalObject), n);
}

bool isRectangle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return isRectangle(getStyle(renderInformationBase, attribute), n);
}

bool isRectangle(Style* style, unsigned  int n) {
    return isRectangle(getRenderGroup(style), n);
}

bool isRectangle(RenderGroup* renderGroup, unsigned  int n) {
    return isRectangle(getGeometricShape(renderGroup, n));
}

bool isRectangle(Transformation2D* shape) {
    if (shape)
        return shape->isRectangle();

    return false;
}

bool isEllipse(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return isEllipse(getStyle(renderInformationBase, graphicalObject), n);
}

bool isEllipse(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return isEllipse(getStyle(renderInformationBase, attribute), n);
}

bool isEllipse(Style* style, unsigned  int n) {
    return isEllipse(getRenderGroup(style), n);
}

bool isEllipse(RenderGroup* renderGroup, unsigned  int n) {
    return isEllipse(getGeometricShape(renderGroup, n));
}

bool isEllipse(Transformation2D* shape) {
    if (shape)
        return shape->isEllipse();

    return false;
}

bool isPolygon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return isPolygon(getStyle(renderInformationBase, graphicalObject), n);
}

bool isPolygon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return isPolygon(getStyle(renderInformationBase, attribute), n);
}

bool isPolygon(Style* style, unsigned  int n) {
    return isPolygon(getRenderGroup(style), n);
}

bool isPolygon(RenderGroup* renderGroup, unsigned  int n) {
    return isPolygon(getGeometricShape(renderGroup, n));
}

bool isPolygon(Transformation2D* shape) {
    if (shape)
        return shape->isPolygon();

    return false;
}

bool isRenderCurve(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return isRenderCurve(getStyle(renderInformationBase, graphicalObject), n);
}

bool isRenderCurve(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return isRenderCurve(getStyle(renderInformationBase, attribute), n);
}

bool isRenderCurve(Style* style, unsigned  int n) {
    return isRenderCurve(getRenderGroup(style), n);
}

bool isRenderCurve(RenderGroup* renderGroup, unsigned  int n) {
    return isRenderCurve(getGeometricShape(renderGroup, n));
}

bool isRenderCurve(Transformation2D* shape) {
    if (shape)
        return shape->isRenderCurve();

    return false;
}

bool isImage(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return isImage(getStyle(renderInformationBase, graphicalObject), n);
}

bool isImage(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return isImage(getStyle(renderInformationBase, attribute), n);
}

bool isImage(Style* style, unsigned  int n) {
    return isImage(getRenderGroup(style), n);
}

bool isImage(RenderGroup* renderGroup, unsigned  int n) {
    return isImage(getGeometricShape(renderGroup, n));
}

bool isImage(Transformation2D* shape) {
    if (shape)
        return shape->isImage();

    return false;
}

bool isText(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return isText(getStyle(renderInformationBase, graphicalObject), n);
}

bool isText(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return isText(getStyle(renderInformationBase, attribute), n);
}

bool isText(Style* style, unsigned  int n) {
    return isText(getRenderGroup(style), n);
}

bool isText(RenderGroup* renderGroup, unsigned  int n) {
    return isText(getGeometricShape(renderGroup, n));
}

bool isText(Transformation2D* shape) {
    if (shape)
        return shape->isText();

    return false;
}

bool isSetGeometricShapeX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetX();
    else if (isImage(shape))
        return ((Image*)shape)->isSetX();
    else if (isText(shape))
        return ((Text*)shape)->isSetX();
    
    return false;
}

const RelAbsVector getGeometricShapeX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getX();
    else if (isImage(shape))
        return ((Image*)shape)->getX();
    else if (isText(shape))
        return ((Text*)shape)->getX();
    
    return RelAbsVector();
}

int setGeometricShapeX(Transformation2D* shape, const RelAbsVector& x) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setX(x);
        return 0;
    }
    else if (isImage(shape)) {
        ((Image*)shape)->setX(x);
        return 0;
    }
    else if (isText(shape)) {
        ((Text*)shape)->setX(x);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetY();
    else if (isImage(shape))
        return ((Image*)shape)->isSetY();
    else if (isText(shape))
        return ((Text*)shape)->isSetY();

    return false;
}

const RelAbsVector getGeometricShapeY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getY();
    else if (isImage(shape))
        return ((Image*)shape)->getY();
    else if (isText(shape))
        return ((Text*)shape)->getY();

    return RelAbsVector();
}

int setGeometricShapeY(Transformation2D* shape, const RelAbsVector& y) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setY(y);
        return 0;
    }
    else if (isImage(shape)) {
        ((Image*)shape)->setY(y);
        return 0;
    }
    else if (isText(shape)) {
        ((Text*)shape)->setY(y);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeWidth(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetWidth();
    else if (isRectangle(shape))
        return ((Image*)shape)->isSetWidth();
    
    return false;
}

const RelAbsVector getGeometricShapeWidth(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getWidth();
    else if (isRectangle(shape))
        return ((Image*)shape)->getWidth();
    
    return RelAbsVector();
}

int setGeometricShapeWidth(Transformation2D* shape, const RelAbsVector& width) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setWidth(width);
        return 0;
    }
    else if (isImage(shape)) {
        ((Image*)shape)->setWidth(width);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeHeight(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetHeight();
    else if (isRectangle(shape))
        return ((Image*)shape)->isSetHeight();

    return false;
}

const RelAbsVector getGeometricShapeHeight(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getHeight();
    else if (isRectangle(shape))
        return ((Image*)shape)->getHeight();

    return RelAbsVector();
}

int setGeometricShapeHeight(Transformation2D* shape, const RelAbsVector& height) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setHeight(height);
        return 0;
    }
    else if (isImage(shape)) {
        ((Image*)shape)->setHeight(height);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeRatio(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRatio();
    else if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRatio();
    
    return false;
}

const double getGeometricShapeRatio(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRatio();
    else if (isEllipse(shape))
        return ((Ellipse*)shape)->getRatio();
    
    return 0.0;
}

int setGeometricShapeRatio(Transformation2D* shape, const double& ratio) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setRatio(ratio);
        return 0;
    }
    else if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRatio(ratio);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRX();
    
    return false;
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRX();
    
    return RelAbsVector();
}

int setGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape, const RelAbsVector& rx) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRY();
    
    return false;
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRY();
    
    return RelAbsVector();
}

int setGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape, const RelAbsVector& ry) {
    if (isRectangle(shape)) {
        return ((Rectangle*)shape)->setRY(ry);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCenterX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetCX();
    
    return false;
}

const RelAbsVector getGeometricShapeCenterX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getCX();
    
    return RelAbsVector();
}

int setGeometricShapeCenterX(Transformation2D* shape, const RelAbsVector& cx) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setCX(cx);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCenterY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetCY();
    
    return false;
}

const RelAbsVector getGeometricShapeCenterY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getCY();
    
    return RelAbsVector();
}

int setGeometricShapeCenterY(Transformation2D* shape, const RelAbsVector& cy) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setCY(cy);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeRadiusX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRX();
    
    return false;
}

const RelAbsVector getGeometricShapeRadiusX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getRX();
    
    return RelAbsVector();
}

int setGeometricShapeRadiusX(Transformation2D* shape, const RelAbsVector& rx) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeRadiusY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRY();
    
    return false;
}

const RelAbsVector getGeometricShapeRadiusY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getRY();
    
    return RelAbsVector();
}

int setGeometricShapeRadiusY(Transformation2D* shape, const RelAbsVector& ry) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRY(ry);
        return 0;
    }
    
    return -1;
}

const unsigned int getPolygonShapeNumElements(Polygon* polygon) {
    if (polygon)
        return polygon->getNumElements();

    return 0;
}

const RelAbsVector getPolygonShapeElementX(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element)
            return element->getX();
    }

    return RelAbsVector();
}

int setPolygonShapeElementX(Polygon* polygon, unsigned  int n, const RelAbsVector& x) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element) {
            element->setX(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeElementY(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element)
            return element->getY();
    }

    return RelAbsVector();
}

int setPolygonShapeElementY(Polygon* polygon, unsigned  int n, const RelAbsVector& y) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element) {
            element->setY(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_x();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n, const RelAbsVector& x) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_y();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_y(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_x();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n, const RelAbsVector& x) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_y();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_y(y);
            return 0;
        }
    }

    return -1;
}

bool isRenderCubicBezier(Polygon* polygon, unsigned  int n) {
    if (polygon)
        return isRenderCubicBezier(polygon->getElement(n));

    return false;
}

const unsigned int getRenderCurveShapeNumElements(RenderCurve* renderCurve) {
    if (renderCurve)
        return  renderCurve->getNumElements();

    return 0;
}

const RelAbsVector getRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element)
            return element->getX();
    }

    return RelAbsVector();
}

int setRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element) {
            element->setX(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element)
            return element->getY();
    }

    return RelAbsVector();
}

int setRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element) {
            element->setY(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_x();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_y();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_y(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_x();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_y();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_y(y);
            return 0;
        }
    }

    return -1;
}

bool isRenderCubicBezier(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve)
        return isRenderCubicBezier(renderCurve->getElement(n));

    return false;
}

bool isRenderCubicBezier(RenderPoint* renderPoint) {
    if (renderPoint)
        return renderPoint->isRenderCubicBezier();

    return false;
}

bool isSetImageShapeHref(Image* image) {
    if (image)
        return image->isSetHref();

    return false;
}

const std::string getImageShapeHref(Image* image) {
    if (image)
        return image->getHref();

    return "";
}

int setImageShapeHref(Image* image, const std::string& href) {
    if (image) {
        image->setHref(href);
        return 0;
    }

    return -1;
}

int addGeometricShape(RenderGroup* renderGroup, const std::string& shape) {
    if (renderGroup) {
        if (stringCompare(shape, "rectangle")) {
            Rectangle* rectangle = renderGroup->createRectangle();
            setDefaultRectangleShapeFeatures(rectangle);
            return 0;
        }
        else if (stringCompare(shape, "ellipse")) {
            Ellipse* ellipse = renderGroup->createEllipse();
            setDefaultEllipseShapeFeatures(ellipse);
            return 0;
        }
        else if (stringCompare(shape, "triangle")) {
            Polygon* triangle = renderGroup->createPolygon();
            setDefaultTriangleShapeFeatures(triangle);
            return 0;
        }
        else if (stringCompare(shape, "diamond")) {
            Polygon* diamond = renderGroup->createPolygon();
            setDefaultDiamondShapeFeatures(diamond);
            return 0;
        }
        else if (stringCompare(shape, "pentagon")) {
            Polygon* pentagon = renderGroup->createPolygon();
            setDefaultPentagonShapeFeatures(pentagon);
            return 0;
        }
        else if (stringCompare(shape, "hexagon")) {
            Polygon* hexagon = renderGroup->createPolygon();
            setDefaultHexagonShapeFeatures(hexagon);
            return 0;
        }
        else if (stringCompare(shape, "octagon")) {
            Polygon* octagon = renderGroup->createPolygon();
            setDefaultOctagonShapeFeatures(octagon);
            return 0;
        }
        else if (stringCompare(shape, "rendercurve")) {
            RenderCurve* renderCurve = renderGroup->createCurve();
            setDefaultRenderCurveShapeFeatures(renderCurve);
            return 0;
        }
        else if (stringCompare(shape, "image")) {
            Image* image = renderGroup->createImage();
            setDefaultImageShapeFeatures(image);
            return 0;
        }
    }

    return -1;
}

Transformation2D * removeGeometricShape(RenderGroup* renderGroup, unsigned int n) {
    if (renderGroup)
        return renderGroup->removeElement(n);

    return NULL;
}

int addRenderPointToShape(Transformation2D* shape) {
    if (shape) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(shape->getLevel(), shape->getVersion());
        if (shape->isPolygon())
            return ((Polygon*)shape)->addElement(new RenderPoint(renderPkgNamespaces));
        else if (shape->isRenderCurve())
            return ((RenderCurve*)shape)->addElement(new RenderPoint(renderPkgNamespaces));
    }

    return -1;
}

int addRenderCubicBezierToShape(Transformation2D* shape) {
    if (shape) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(shape->getLevel(), shape->getVersion());
        if (shape->isPolygon())
            return ((Polygon*)shape)->addElement(new RenderCubicBezier(renderPkgNamespaces));
        else if (shape->isRenderCurve())
            return ((RenderCurve*)shape)->addElement(new RenderCubicBezier(renderPkgNamespaces));
    }

    return -1;
}

RenderPoint * removeElementFromShape(Transformation2D* shape, unsigned int n) {
    if (shape) {
        if (shape->isPolygon())
            return ((Polygon*)shape)->removeElement(n);
        else if (shape->isRenderCurve())
            return ((RenderCurve*)shape)->removeElement(n);
    }

    return NULL;
}

const std::string getObjectRole(GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        RenderGraphicalObjectPlugin* renderGraphicalObjectPlugin = dynamic_cast<RenderGraphicalObjectPlugin*>(graphicalObject->getPlugin("render"));
        if (renderGraphicalObjectPlugin)
            return renderGraphicalObjectPlugin->getObjectRole();
    }

    return "";
}

}

