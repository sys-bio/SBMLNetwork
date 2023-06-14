#include "libsbml_ne_render.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_render_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

const unsigned int getNumGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation) {
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->size();

    return 0;
}

GlobalRenderInformation* getGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation, unsigned int n) {
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->get(n);

    return NULL;
}

const unsigned int getNumLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation) {
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->size();

    return 0;
}

LocalRenderInformation* getLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation, unsigned int n) {
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->get(n);

    return NULL;
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

const unsigned int getNumColorDefinitions(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        return renderInformationBase->getNumColorDefinitions();

    return 0;
}

ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, const std::string& sid) {
    if (renderInformationBase)
        return renderInformationBase->getColorDefinition(sid);

    return NULL;
}

ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, unsigned int index) {
    if (renderInformationBase)
        return renderInformationBase->getColorDefinition(index);

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

const unsigned int getNumGradientDefinitions(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        return renderInformationBase->getNumGradientDefinitions();

    return 0;
}

GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, const std::string& sid) {
    if (renderInformationBase)
        return renderInformationBase->getGradientDefinition(sid);

    return NULL;
}

GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, unsigned int index) {
    if (renderInformationBase)
        return renderInformationBase->getGradientDefinition(index);

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

const unsigned int getNumLineEndings(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        return renderInformationBase->getNumLineEndings();

    return 0;
}

LineEnding* getLineEnding(RenderInformationBase* renderInformationBase, unsigned int index) {
    if (renderInformationBase)
        return renderInformationBase->getLineEnding(index);

    return NULL;
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
    if (graphicalObject)
        return getStyleById(renderInformationBase, graphicalObject->getId());

    return NULL;
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

const std::string getFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFillColor(getStyle(renderInformationBase, graphicalObject));
}

const std::string getFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFillColor(getStyle(renderInformationBase, attribute));
}

const std::string getFillColor(Style* style) {
    return getFillColor(getRenderGroup(style));
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

const std::string getEndHead(RenderInformationBase* renderInformationBase, const std::string& attribute) {
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

int addGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& shape) {
    return addGeometricShape(getStyle(renderInformationBase, graphicalObject), shape);
}

int addGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& shape) {
    return addGeometricShape(getStyle(renderInformationBase, attribute), shape);
}

int addGeometricShape(Style* style, const std::string& shape) {
    return addGeometricShape(getRenderGroup(style), shape);
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

Transformation2D* removeGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned  int n) {
    return removeGeometricShape(getStyle(renderInformationBase, graphicalObject), n);
}

Transformation2D* removeGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned  int n) {
    return removeGeometricShape(getStyle(renderInformationBase, attribute), n);
}

Transformation2D* removeGeometricShape(Style* style, unsigned  int n) {
    return removeGeometricShape(getRenderGroup(style), n);
}

Transformation2D* removeGeometricShape(RenderGroup* renderGroup, unsigned int n) {
    if (renderGroup)
        return renderGroup->removeElement(n);

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

bool isSetGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeX(Style* style, unsigned int n) {
    return isSetGeometricShapeX(getRenderGroup(style), n);
}

bool isSetGeometricShapeX(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeX(getGeometricShape(renderGroup, n));
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

const RelAbsVector getGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeX(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeX(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeX(Style* style, unsigned int n) {
    return getGeometricShapeX(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeX(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeX(getGeometricShape(renderGroup, n));
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

int setGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(renderInformationBase, graphicalObject), n, x);
}

int setGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(renderInformationBase, attribute), n, x);
}

int setGeometricShapeX(Style* style, unsigned int n, const RelAbsVector& x) {
    return setGeometricShapeX(getRenderGroup(style), n, x);
}

int setGeometricShapeX(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& x) {
    return setGeometricShapeX(getGeometricShape(renderGroup, n), x);
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

bool isSetGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeY(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeY(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeY(Style* style, unsigned int n) {
    return isSetGeometricShapeY(getRenderGroup(style), n);
}

bool isSetGeometricShapeY(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeY(getGeometricShape(renderGroup, n));
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

const RelAbsVector getGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeY(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeY(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeY(Style* style, unsigned int n) {
    return getGeometricShapeY(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeY(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeY(getGeometricShape(renderGroup, n));
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

int setGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(renderInformationBase, graphicalObject), n, y);
}

int setGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(renderInformationBase, attribute), n, y);
}

int setGeometricShapeY(Style* style, unsigned int n, const RelAbsVector& y) {
    return setGeometricShapeY(getRenderGroup(style), n, y);
}

int setGeometricShapeY(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& y) {
    return setGeometricShapeY(getGeometricShape(renderGroup, n), y);
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

bool isSetGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeWidth(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeWidth(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeWidth(Style* style, unsigned int n) {
    return isSetGeometricShapeWidth(getRenderGroup(style), n);
}

bool isSetGeometricShapeWidth(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeWidth(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeWidth(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetWidth();
    else if (isImage(shape))
        return ((Image*)shape)->isSetWidth();
    
    return false;
}

const RelAbsVector getGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeWidth(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeWidth(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeWidth(Style* style, unsigned int n) {
    return getGeometricShapeWidth(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeWidth(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeWidth(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeWidth(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getWidth();
    else if (isImage(shape))
        return ((Image*)shape)->getWidth();
    
    return RelAbsVector();
}

int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(renderInformationBase, graphicalObject), n, width);
}

int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(renderInformationBase, attribute), n, width);
}

int setGeometricShapeWidth(Style* style, unsigned int n, const RelAbsVector& width) {
    return setGeometricShapeWidth(getRenderGroup(style), n, width);
}

int setGeometricShapeWidth(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& width) {
    return setGeometricShapeWidth(getGeometricShape(renderGroup, n), width);
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

bool isSetGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeHeight(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeHeight(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeHeight(Style* style, unsigned int n) {
    return isSetGeometricShapeHeight(getRenderGroup(style), n);
}

bool isSetGeometricShapeHeight(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeHeight(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeHeight(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetHeight();
    else if (isImage(shape))
        return ((Image*)shape)->isSetHeight();

    return false;
}

const RelAbsVector getGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeHeight(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeHeight(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeHeight(Style* style, unsigned int n) {
    return getGeometricShapeHeight(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeHeight(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeHeight(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeHeight(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getHeight();
    else if (isImage(shape))
        return ((Image*)shape)->getHeight();

    return RelAbsVector();
}

int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(renderInformationBase, graphicalObject), n, height);
}

int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(renderInformationBase, attribute), n, height);
}

int setGeometricShapeHeight(Style* style, unsigned int n, const RelAbsVector& height) {
    return setGeometricShapeHeight(getRenderGroup(style), n, height);
}

int setGeometricShapeHeight(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& height) {
    return setGeometricShapeHeight(getGeometricShape(renderGroup, n), height);
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

bool isSetGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeRatio(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeRatio(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeRatio(Style* style, unsigned int n) {
    return isSetGeometricShapeRatio(getRenderGroup(style), n);
}

bool isSetGeometricShapeRatio(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeRatio(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeRatio(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRatio();
    else if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRatio();
    
    return false;
}

const double getGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeRatio(getStyle(renderInformationBase, graphicalObject), n);
}

const double getGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeRatio(getStyle(renderInformationBase, attribute), n);
}

const double getGeometricShapeRatio(Style* style, unsigned int n) {
    return getGeometricShapeRatio(getRenderGroup(style), n);
}

const double getGeometricShapeRatio(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeRatio(getGeometricShape(renderGroup, n));
}

const double getGeometricShapeRatio(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRatio();
    else if (isEllipse(shape))
        return ((Ellipse*)shape)->getRatio();
    
    return 0.0;
}

int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const double& ratio) {
    return setGeometricShapeRatio(getStyle(renderInformationBase, graphicalObject), n, ratio);
}

int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const double& ratio) {
    return setGeometricShapeRatio(getStyle(renderInformationBase, attribute), n, ratio);
}

int setGeometricShapeRatio(Style* style, unsigned int n, const double& ratio) {
    return setGeometricShapeRatio(getRenderGroup(style), n, ratio);
}

int setGeometricShapeRatio(RenderGroup* renderGroup, unsigned int n, const double& ratio) {
    return setGeometricShapeRatio(getGeometricShape(renderGroup, n), ratio);
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

bool isSetGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getRenderGroup(style), n);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRX();
    
    return false;
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusX(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRX();
    
    return RelAbsVector();
}

int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, graphicalObject), n, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, attribute), n, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getRenderGroup(style), n, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getGeometricShape(renderGroup, n), rx);
}

int setGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape, const RelAbsVector& rx) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getRenderGroup(style), n);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRY();
    
    return false;
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusY(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRY();
    
    return RelAbsVector();
}

int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, graphicalObject), n, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, attribute), n, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getRenderGroup(style), n, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getGeometricShape(renderGroup, n), ry);
}

int setGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape, const RelAbsVector& ry) {
    if (isRectangle(shape)) {
        return ((Rectangle*)shape)->setRY(ry);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeCenterX(Style* style, unsigned int n) {
    return isSetGeometricShapeX(getRenderGroup(style), n);
}

bool isSetGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeX(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeCenterX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetCX();
    
    return false;
}

const RelAbsVector getGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeCenterX(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeCenterX(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeCenterX(Style* style, unsigned int n) {
    return getGeometricShapeCenterX(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeCenterX(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeCenterX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getCX();
    
    return RelAbsVector();
}

int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(renderInformationBase, graphicalObject), n, cx);
}

int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(renderInformationBase, attribute), n, cx);
}

int setGeometricShapeCenterX(Style* style, unsigned int n, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getRenderGroup(style), n, cx);
}

int setGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getGeometricShape(renderGroup, n), cx);
}

int setGeometricShapeCenterX(Transformation2D* shape, const RelAbsVector& cx) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setCX(cx);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeCenterY(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeCenterY(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeCenterY(Style* style, unsigned int n) {
    return isSetGeometricShapeCenterY(getRenderGroup(style), n);
}

bool isSetGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeCenterY(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeCenterY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetCY();
    
    return false;
}

const RelAbsVector getGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeCenterY(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeCenterY(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeCenterY(Style* style, unsigned int n) {
    return getGeometricShapeCenterY(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeCenterY(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeCenterY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getCY();
    
    return RelAbsVector();
}

int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getStyle(renderInformationBase, graphicalObject), n, cy);
}

int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getStyle(renderInformationBase, attribute), n, cy);
}

int setGeometricShapeCenterY(Style* style, unsigned int n, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getRenderGroup(style), n, cy);
}

int setGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getGeometricShape(renderGroup, n), cy);
}

int setGeometricShapeCenterY(Transformation2D* shape, const RelAbsVector& cy) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setCY(cy);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeRadiusX(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeRadiusX(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeRadiusX(Style* style, unsigned int n) {
    return isSetGeometricShapeRadiusX(getRenderGroup(style), n);
}

bool isSetGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeRadiusX(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeRadiusX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRX();
    
    return false;
}

const RelAbsVector getGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeRadiusX(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeRadiusX(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeRadiusX(Style* style, unsigned int n) {
    return getGeometricShapeRadiusX(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeRadiusX(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeRadiusX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getRX();
    
    return RelAbsVector();
}

int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(renderInformationBase, graphicalObject), n, rx);
}

int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(renderInformationBase, attribute), n, rx);
}

int setGeometricShapeRadiusX(Style* style, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getRenderGroup(style), n, rx);
}

int setGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getGeometricShape(renderGroup, n), rx);
}

int setGeometricShapeRadiusX(Transformation2D* shape, const RelAbsVector& rx) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeRadiusY(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeRadiusY(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeRadiusY(Style* style, unsigned int n) {
    return isSetGeometricShapeRadiusY(getRenderGroup(style), n);
}

bool isSetGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeRadiusY(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeRadiusY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRY();
    
    return false;
}

const RelAbsVector getGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeRadiusY(getStyle(renderInformationBase, graphicalObject), n);
}

const RelAbsVector getGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeRadiusY(getStyle(renderInformationBase, attribute), n);
}

const RelAbsVector getGeometricShapeRadiusY(Style* style, unsigned int n) {
    return getGeometricShapeRadiusY(getRenderGroup(style), n);
}

const RelAbsVector getGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeRadiusY(getGeometricShape(renderGroup, n));
}

const RelAbsVector getGeometricShapeRadiusY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getRY();
    
    return RelAbsVector();
}

int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(renderInformationBase, graphicalObject), n, ry);
}

int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(renderInformationBase, attribute), n, ry);
}

int setGeometricShapeRadiusY(Style* style, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getRenderGroup(style), n, ry);
}

int setGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int n, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getGeometricShape(renderGroup, n), ry);
}

int setGeometricShapeRadiusY(Transformation2D* shape, const RelAbsVector& ry) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRY(ry);
        return 0;
    }
    
    return -1;
}

const unsigned int getGeometricShapeNumElements(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeNumElements(getStyle(renderInformationBase, graphicalObject), n);
}

const unsigned int getGeometricShapeNumElements(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeNumElements(getStyle(renderInformationBase, attribute), n);
}

const unsigned int getGeometricShapeNumElements(Style* style, unsigned int n) {
    return getGeometricShapeNumElements(getRenderGroup(style), n);
}

const unsigned int getGeometricShapeNumElements(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeNumElements(getGeometricShape(renderGroup, n));
}

const unsigned int getGeometricShapeNumElements(Transformation2D* shape) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->getNumElements();
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->getNumElements();

    return 0;
}

const RelAbsVector getGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return getGeometricShapeElementX(getStyle(renderInformationBase, graphicalObject), n, index);
}

const RelAbsVector getGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return getGeometricShapeElementX(getStyle(renderInformationBase, attribute), n, index);
}

const RelAbsVector getGeometricShapeElementX(Style* style, unsigned int n, unsigned int index) {
    return getGeometricShapeElementX(getRenderGroup(style), n, index);
}

const RelAbsVector getGeometricShapeElementX(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return getGeometricShapeElementX(getGeometricShape(renderGroup, n), index);
}

const RelAbsVector getGeometricShapeElementX(Transformation2D* shape, unsigned int index) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (element)
        return element->getX();

    return RelAbsVector();
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(renderInformationBase, graphicalObject), n, index, x);
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(renderInformationBase, attribute), n, index, x);
}

int setGeometricShapeElementX(Style* style, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeElementX(getRenderGroup(style), n, index, x);
}

int setGeometricShapeElementX(RenderGroup* renderGroup, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeElementX(getGeometricShape(renderGroup, n), index, x);
}

int setGeometricShapeElementX(Transformation2D* shape, unsigned int index, const RelAbsVector& x) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (element) {
        element->setX(x);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return getGeometricShapeElementY(getStyle(renderInformationBase, graphicalObject), n, index);
}

const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return getGeometricShapeElementX(getStyle(renderInformationBase, attribute), n, index);
}

const RelAbsVector getGeometricShapeElementY(Style* style, unsigned int n, unsigned int index) {
    return getGeometricShapeElementX(getRenderGroup(style), n, index);
}

const RelAbsVector getGeometricShapeElementY(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return getGeometricShapeElementY(getGeometricShape(renderGroup, n), index);
}

const RelAbsVector getGeometricShapeElementY(Transformation2D* shape, unsigned int index) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (element)
        return element->getY();

    return RelAbsVector();
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(renderInformationBase, graphicalObject), n, index, y);
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(renderInformationBase, attribute), n, index, y);
}

int setGeometricShapeElementY(Style* style, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeElementY(getRenderGroup(style), n, index, y);
}

int setGeometricShapeElementY(RenderGroup* renderGroup, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeElementY(getGeometricShape(renderGroup, n), index, y);
}

int setGeometricShapeElementY(Transformation2D* shape, unsigned  int index, const RelAbsVector& y) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (element) {
        element->setY(y);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1X(getStyle(renderInformationBase, graphicalObject), n, index);
}

const RelAbsVector getGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1X(getStyle(renderInformationBase, attribute), n, index);
}

const RelAbsVector getGeometricShapeBasePoint1X(Style* style, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1X(getRenderGroup(style), n, index);
}

const RelAbsVector getGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1X(getGeometricShape(renderGroup, n), index);
}

const RelAbsVector getGeometricShapeBasePoint1X(Transformation2D* shape, unsigned int index) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint1_x();

    return RelAbsVector();
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(renderInformationBase, graphicalObject), n, index, x);
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(renderInformationBase, attribute), n, index, x);
}

int setGeometricShapeBasePoint1X(Style* style, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getRenderGroup(style), n, index, x);
}

int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getGeometricShape(renderGroup, n), index, x);
}

int setGeometricShapeBasePoint1X(Transformation2D* shape, unsigned  int index, const RelAbsVector& x) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint1_x(x);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1Y(getStyle(renderInformationBase, graphicalObject), n, index);
}

const RelAbsVector getGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1Y(getStyle(renderInformationBase, attribute), n, index);
}

const RelAbsVector getGeometricShapeBasePoint1Y(Style* style, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1Y(getRenderGroup(style), n, index);
}

const RelAbsVector getGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint1Y(getGeometricShape(renderGroup, n), index);
}

const RelAbsVector getGeometricShapeBasePoint1Y(Transformation2D* shape, unsigned  int index) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint1_y();

    return RelAbsVector();
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, graphicalObject), n, index, y);
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, attribute), n, index, y);
}

int setGeometricShapeBasePoint1Y(Style* style, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getRenderGroup(style), n, index, y);
}

int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getGeometricShape(renderGroup, n), index, y);
}

int setGeometricShapeBasePoint1Y(Transformation2D* shape, unsigned  int index, const RelAbsVector& y) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint1_y(y);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2X(getStyle(renderInformationBase, graphicalObject), n, index);
}

const RelAbsVector getGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2X(getStyle(renderInformationBase, attribute), n, index);
}

const RelAbsVector getGeometricShapeBasePoint2X(Style* style, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2X(getRenderGroup(style), n, index);
}

const RelAbsVector getGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2X(getGeometricShape(renderGroup, n), index);
}

const RelAbsVector getGeometricShapeBasePoint2X(Transformation2D* shape, unsigned int index) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint2_x();

    return RelAbsVector();
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(renderInformationBase, graphicalObject), n, index, x);
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(renderInformationBase, attribute), n, index, x);
}

int setGeometricShapeBasePoint2X(Style* style, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getRenderGroup(style), n, index, x);
}

int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int n, unsigned int index, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getGeometricShape(renderGroup, n), index, x);
}

int setGeometricShapeBasePoint2X(Transformation2D* shape, unsigned int index, const RelAbsVector& x) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint2_x(x);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2Y(getStyle(renderInformationBase, graphicalObject), n, index);
}

const RelAbsVector getGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2Y(getStyle(renderInformationBase, attribute), n, index);
}

const RelAbsVector getGeometricShapeBasePoint2Y(Style* style, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2Y(getRenderGroup(style), n, index);
}

const RelAbsVector getGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return getGeometricShapeBasePoint2Y(getGeometricShape(renderGroup, n), index);
}

const RelAbsVector getGeometricShapeBasePoint2Y(Transformation2D* shape, unsigned int index) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint2_y();

    return RelAbsVector();
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(renderInformationBase, graphicalObject), n, index, y);
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(renderInformationBase, attribute), n, index, y);
}

int setGeometricShapeBasePoint2Y(Style* style, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getRenderGroup(style), n, index, y);
}

int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int n, unsigned int index, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getGeometricShape(renderGroup, n), index, y);
}

int setGeometricShapeBasePoint2Y(Transformation2D* shape, unsigned int index, const RelAbsVector& y) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(index);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(index);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint2_y(y);
        return 0;
    }

    return -1;
}

int addRenderPointToGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return addRenderPointToGeometricShape(getStyle(renderInformationBase, graphicalObject), n);
}

int addRenderPointToGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return addRenderPointToGeometricShape(getStyle(renderInformationBase, attribute), n);
}

int addRenderPointToGeometricShape(Style* style, unsigned int n) {
    return addRenderPointToGeometricShape(getRenderGroup(style), n);
}

int addRenderPointToGeometricShape(RenderGroup* renderGroup, unsigned int n) {
    return addRenderPointToGeometricShape(getGeometricShape(renderGroup, n));
}

int addRenderPointToGeometricShape(Transformation2D* shape) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->addElement(new RenderPoint(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->addElement(new RenderPoint(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));

    return -1;
}

int addRenderCubicBezierToGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return addRenderCubicBezierToGeometricShape(getStyle(renderInformationBase, graphicalObject), n);
}

int addRenderCubicBezierToGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return addRenderCubicBezierToGeometricShape(getStyle(renderInformationBase, attribute), n);
}

int addRenderCubicBezierToGeometricShape(Style* style, unsigned int n) {
    return addRenderCubicBezierToGeometricShape(getRenderGroup(style), n);
}

int addRenderCubicBezierToGeometricShape(RenderGroup* renderGroup, unsigned int n) {
    return addRenderCubicBezierToGeometricShape(getGeometricShape(renderGroup, n));
}

int addRenderCubicBezierToGeometricShape(Transformation2D* shape) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->addElement(new RenderCubicBezier(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->addElement(new RenderCubicBezier(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));

    return -1;
}

RenderPoint* removeElementFromGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return removeElementFromGeometricShape(getStyle(renderInformationBase, graphicalObject), n, index);
}

RenderPoint* removeElementFromGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return removeElementFromGeometricShape(getStyle(renderInformationBase, attribute), n, index);
}

RenderPoint* removeElementFromGeometricShape(Style* style, unsigned int n, unsigned int index) {
    return removeElementFromGeometricShape(getRenderGroup(style), n, index);
}

RenderPoint* removeElementFromGeometricShape(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return removeElementFromGeometricShape(getGeometricShape(renderGroup, n), index);
}

RenderPoint* removeElementFromGeometricShape(Transformation2D* shape, unsigned int index) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->removeElement(index);
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->removeElement(index);

    return NULL;
}

bool isRenderCubicBezier(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, unsigned int index) {
    return isRenderCubicBezier(getStyle(renderInformationBase, graphicalObject), n, index);
}

bool isRenderCubicBezier(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, unsigned int index) {
    return isRenderCubicBezier(getStyle(renderInformationBase, attribute), n, index);
}

bool isRenderCubicBezier(Style* style, unsigned int n, unsigned int index) {
    return isRenderCubicBezier(getRenderGroup(style), n, index);
}

bool isRenderCubicBezier(RenderGroup* renderGroup, unsigned int n, unsigned int index) {
    return isRenderCubicBezier(getGeometricShape(renderGroup, n), index);
}

bool isRenderCubicBezier(Transformation2D* shape, unsigned int index) {
    if (isPolygon(shape))
        return isRenderCubicBezier(((Polygon*)shape)->getElement(index));
    else if (isRenderCurve(shape))
        return isRenderCubicBezier(((RenderCurve*)shape)->getElement(index));

    return false;
}

bool isRenderCubicBezier(RenderPoint* renderPoint) {
    if (renderPoint)
        return renderPoint->isRenderCubicBezier();

    return false;
}

bool isSetGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return isSetGeometricShapeHref(getStyle(renderInformationBase, graphicalObject), n);
}

bool isSetGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return isSetGeometricShapeHref(getStyle(renderInformationBase, attribute), n);
}

bool isSetGeometricShapeHref(Style* style, unsigned int n) {
    return isSetGeometricShapeHref(getRenderGroup(style), n);
}

bool isSetGeometricShapeHref(RenderGroup* renderGroup, unsigned int n) {
    return isSetGeometricShapeHref(getGeometricShape(renderGroup, n));
}

bool isSetGeometricShapeHref(Transformation2D* shape) {
    if (isImage(shape))
        return ((Image*)shape)->isSetHref();

    return false;
}

const std::string getGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n) {
    return getGeometricShapeHref(getStyle(renderInformationBase, graphicalObject), n);
}

const std::string getGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n) {
    return getGeometricShapeHref(getStyle(renderInformationBase, attribute), n);
}

const std::string getGeometricShapeHref(Style* style, unsigned int n) {
    return getGeometricShapeHref(getRenderGroup(style), n);
}

const std::string getGeometricShapeHref(RenderGroup* renderGroup, unsigned int n) {
    return getGeometricShapeHref(getGeometricShape(renderGroup, n));
}

const std::string getGeometricShapeHref(Transformation2D* shape) {
    if (isImage(shape))
        return ((Image*)shape)->getHref();

    return "";
}

int setGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int n, const std::string& href) {
    return setGeometricShapeHref(getStyle(renderInformationBase, graphicalObject), n, href);
}

int setGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int n, const std::string& href) {
    return setGeometricShapeHref(getStyle(renderInformationBase, attribute), n, href);
}

int setGeometricShapeHref(Style* style, unsigned int n, const std::string& href) {
    return setGeometricShapeHref(getRenderGroup(style), n, href);
}

int setGeometricShapeHref(RenderGroup* renderGroup, unsigned int n, const std::string& href) {
    return setGeometricShapeHref(getGeometricShape(renderGroup, n), href);
}

int setGeometricShapeHref(Transformation2D* shape, const std::string& href) {
    if (isImage(shape)) {
        ((Image*)shape)->setHref(href);
        return 0;
    }

    return -1;
}

const std::string getObjectRole(Layout* layout, const std::string& id) {
    return getObjectRole(getGraphicalObject(layout, id));
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

