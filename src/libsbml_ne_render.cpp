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

bool isSetStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStrokeDashArray();

    return false;
}

const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeDashArray();
    
    return std::vector<unsigned int>();
}

int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeDashArray(strokeDashArray);
        return 0;
    }
    
    return -1;
}

unsigned int getNumStrokeDashes(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return getStrokeDashArray(graphicalPrimitive1D).size();
}

unsigned int getDash(GraphicalPrimitive1D* graphicalPrimitive1D, unsigned  int n) {
    if (graphicalPrimitive1D)
        graphicalPrimitive1D->getDashByIndex(n);

    return 0;
}

bool isSetFontColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return isSetStrokeColor(graphicalPrimitive1D);
}

const std::string getFontColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return getStrokeColor(graphicalPrimitive1D);
}

int setFontColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontColor) {
    return setStrokeColor(graphicalPrimitive1D, fontColor);
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

bool isSetFontSize(GraphicalPrimitive1D* graphicalPrimitive1D) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup)
        return renderGroup->isSetFontSize();
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text)
        return text->isSetFontSize();

    return false;
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

int setFillColor(GraphicalPrimitive2D* graphicalPrimitive2D, const std::string& fill) {
    if (graphicalPrimitive2D) {
        graphicalPrimitive2D->setFill(fill);
        return 0;
    }
    
    return -1;
}

unsigned int getNumGeometricShapes(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getNumElements();

    return 0;
}

Transformation2D* getGeometricShape(RenderGroup* renderGroup, unsigned  int n) {
    if (renderGroup)
        return renderGroup->getElement(n);

    return NULL;
}

bool isRectangle(Transformation2D* shape) {
    if (shape)
        return shape->isRectangle();

    return false;
}

bool isEllipse(Transformation2D* shape) {
    if (shape)
        return shape->isEllipse();

    return false;
}

bool isPolygon(Transformation2D* shape) {
    if (shape)
        return shape->isPolygon();

    return false;
}

bool isRenderCurve(Transformation2D* shape) {
    if (shape)
        return shape->isRenderCurve();

    return false;
}

bool isImage(Transformation2D* shape) {
    if (shape)
        return shape->isImage();

    return false;
}

bool isText(Transformation2D* shape) {
    if (shape)
        return shape->isText();

    return false;
}

bool isSetRectangleShapeX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetX();
    
    return false;
}

const RelAbsVector getRectangleShapeX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getX();
    
    return RelAbsVector();
}

int setRectangleShapeX(Rectangle* rectangle, const RelAbsVector& x) {
    if (rectangle) {
        rectangle->setX(x);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetY();
    
    return false;
}

const RelAbsVector getRectangleShapeY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getY();
    
    return RelAbsVector();
}

int setRectangleShapeY(Rectangle* rectangle, const RelAbsVector& y) {
    if (rectangle) {
        rectangle->setX(y);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeWidth(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetWidth();
    
    return false;
}

const RelAbsVector getRectangleShapeWidth(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getWidth();
    
    return RelAbsVector();
}

int setRectangleShapeWidth(Rectangle* rectangle, const RelAbsVector& width) {
    if (rectangle) {
        rectangle->setWidth(width);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeHeight(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetHeight();
    
    return false;
}

const RelAbsVector getRectangleShapeHeight(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getHeight();
    
    return RelAbsVector();
}

int setRectangleShapeHeight(Rectangle* rectangle, const RelAbsVector& height) {
    if (rectangle) {
        rectangle->setHeight(height);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeRatio(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetRatio();
    
    return false;
}

const double getRectangleShapeRatio(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getRatio();
    
    return 0.0;
}

int setRectangleShapeRatio(Rectangle* rectangle, const double& ratio) {
    if (rectangle) {
        rectangle->setRatio(ratio);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeRX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetRX();
    
    return false;
}

const RelAbsVector getRectangleShapeRX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getRX();
    
    return RelAbsVector();
}

int setRectangleShapeRX(Rectangle* rectangle, const RelAbsVector& rx) {
    if (rectangle) {
        rectangle->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeRY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetRY();
    
    return false;
}

const RelAbsVector getRectangleShapeRY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getRY();
    
    return RelAbsVector();
}

int setRectangleShapeRY(Rectangle* rectangle, const RelAbsVector& ry) {
    if (rectangle) {
        rectangle->setRY(ry);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeCX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetCX();
    
    return false;
}

const RelAbsVector getEllipseShapeCX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getCX();
    
    return RelAbsVector();
}

int setEllipseShapeCX(Ellipse* ellipse, const RelAbsVector& cx) {
    if (ellipse) {
        ellipse->setCX(cx);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeCY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetCY();
    
    return false;
}

const RelAbsVector getEllipseShapeCY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getCY();
    
    return RelAbsVector();
}

int setEllipseShapeCY(Ellipse* ellipse, const RelAbsVector& cy) {
    if (ellipse) {
        ellipse->setCY(cy);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeRX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetRX();
    
    return false;
}

const RelAbsVector getEllipseShapeRX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getRX();
    
    return RelAbsVector();
}

int setEllipseShapeRX(Ellipse* ellipse, const RelAbsVector& rx) {
    if (ellipse) {
        ellipse->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeRY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetRY();
    
    return false;
}

const RelAbsVector getEllipseShapeRY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getRY();
    
    return RelAbsVector();
}

int setEllipseShapeRY(Ellipse* ellipse, const RelAbsVector& ry) {
    if (ellipse) {
        ellipse->setRY(ry);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeRatio(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetRatio();
    
    return false;
}

const double getEllipseShapeRatio(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getRatio();
    
    return 0.0;
}

int setEllipseShapeRatio(Ellipse* ellipse, const double& ratio) {
    if (ellipse) {
        ellipse->setRatio(ratio);
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

bool isSetImageShapeX(Image* image) {
    if (image)
        return image->isSetX();

    return false;
}

const RelAbsVector getImageShapeX(Image* image) {
    if (image)
        return image->getX();

    return RelAbsVector();
}

int setImageShapeX(Image* image, const RelAbsVector& x) {
    if (image) {
        image->setX(x);
        return 0;
    }

    return -1;
}

bool isSetImageShapeY(Image* image) {
    if (image)
        return image->isSetY();

    return false;
}

const RelAbsVector getImageShapeY(Image* image) {
    if (image)
        return image->getY();

    return RelAbsVector();
}

int setImageShapeY(Image* image, const RelAbsVector& y) {
    if (image) {
        image->setY(y);
        return 0;
    }

    return -1;
}

bool isSetImageShapeWidth(Image* image) {
    if (image)
        return image->isSetWidth();

    return false;
}

const RelAbsVector getImageShapeWidth(Image* image) {
    if (image)
        return image->getWidth();

    return RelAbsVector();
}

int setImageShapeWidth(Image* image, const RelAbsVector& width) {
    if (image) {
        image->setWidth(width);
        return 0;
    }

    return -1;
}

bool isSetImageShapeHeight(Image* image) {
    if (image)
        return image->isSetHeight();

    return false;
}

const RelAbsVector getImageShapeHeight(Image* image) {
    if (image)
        return image->getHeight();

    return RelAbsVector();
}

int setImageShapeHeight(Image* image, const RelAbsVector& height) {
    if (image) {
        image->setHeight(height);
        return 0;
    }

    return -1;
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

bool isSetTextShapeX(Text* text) {
    if (text)
        return text->isSetX();

    return false;
}

const RelAbsVector getTextShapeX(Text* text) {
    if (text)
        return text->getX();

    return RelAbsVector();
}

int setTextShapeX(Text* text, const RelAbsVector& x) {
    if (text) {
        text->setX(x);
        return 0;
    }

    return -1;
}

bool isSetTextShapeY(Text* text) {
    if (text)
        return text->isSetY();

    return false;
}

const RelAbsVector getTextShapeY(Text* text) {
    if (text)
        return text->getY();

    return RelAbsVector();
}

int setTextShapeY(Text* text, const RelAbsVector& y) {
    if (text) {
        text->setY(y);
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

bool isSetStartHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->isSetStartHead();

    return false;
}

const std::string getStartHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getStartHead();

    return "";
}

int setStartHead(RenderGroup* renderGroup, const std::string startHead) {
    if (renderGroup) {
        renderGroup->setStartHead(startHead);
        return 0;
    }

    return -1;
}

bool isSetEndHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->isSetEndHead();

    return false;
}

const std::string getEndHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getEndHead();

    return "";
}

int setEndHead(RenderGroup* renderGroup, const std::string endHead) {
    if (renderGroup) {
        renderGroup->setEndHead(endHead);
        return 0;
    }

    return -1;
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

