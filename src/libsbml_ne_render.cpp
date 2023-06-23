#include "libsbml_ne_render.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_render_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

const unsigned int getNumGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation) {
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->size();

    return 0;
}

GlobalRenderInformation* getGlobalRenderInformation(ListOfGlobalRenderInformation* listOfGlobalRenderInformation, unsigned int renderIndex) {
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->get(renderIndex);

    return NULL;
}

const unsigned int getNumLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation) {
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->size();

    return 0;
}

LocalRenderInformation* getLocalRenderInformation(ListOfLocalRenderInformation* listOfLocalRenderInformation, unsigned int renderIndex) {
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->get(renderIndex);

    return NULL;
}

bool isSetBackgroundColor(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        renderInformationBase->isSetBackgroundColor();

    return false;
}

const std::string getBackgroundColor(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        return renderInformationBase->getBackgroundColor();

    return "";
}

int setBackgroundColor(RenderInformationBase* renderInformationBase, const std::string& backgroundColor) {
    if (renderInformationBase) {
        renderInformationBase->setBackgroundColor(backgroundColor);
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

ColorDefinition* getColorDefinition(RenderInformationBase* renderInformationBase, unsigned int colorIndex) {
    if (renderInformationBase)
        return renderInformationBase->getColorDefinition(colorIndex);

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

GradientBase* getGradientDefinition(RenderInformationBase* renderInformationBase, unsigned int gradientIndex) {
    if (renderInformationBase)
        return renderInformationBase->getGradientDefinition(gradientIndex);

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

GradientStop* getGradientStop(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex) {
    return getGradientStop(getGradientDefinition(renderInformationBase, sid), gradientStopIndex);
}

GradientStop* getGradientStop(GradientBase* gradientBase, unsigned int gradientStopIndex) {
    if (gradientBase)
        return gradientBase->getGradientStop(gradientStopIndex);

    return NULL;
}

bool isSetOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex) {
    return isSetOffset(getGradientDefinition(renderInformationBase, sid), gradientStopIndex);
}

bool isSetOffset(GradientBase* gradientBase, unsigned int gradientStopIndex) {
    return isSetOffset(getGradientStop(gradientBase, gradientStopIndex));
}

bool isSetOffset(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->isSetOffset();

    return false;
}

const RelAbsVector getOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex) {
    return getOffset(getGradientDefinition(renderInformationBase, sid), gradientStopIndex);
}

const RelAbsVector getOffset(GradientBase* gradientBase, unsigned int gradientStopIndex) {
    return getOffset(getGradientStop(gradientBase, gradientStopIndex));
}

const RelAbsVector getOffset(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->getOffset();

    return RelAbsVector();
}

int setOffset(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& offset) {
    return setOffset(renderInformationBase, sid, 0, offset);
}

int setOffset(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset) {
    return setOffset(getGradientDefinition(renderInformationBase, sid), gradientStopIndex, offset);
}

int setOffset(GradientBase* gradientBase, const RelAbsVector& offset) {
    return setOffset(gradientBase, 0, offset);
}

int setOffset(GradientBase* gradientBase, unsigned int gradientStopIndex, const RelAbsVector& offset) {
    return setOffset(getGradientStop(gradientBase, gradientStopIndex), offset);
}

int setOffset(GradientStop* gradientStop, const RelAbsVector& offset) {
    if (gradientStop) {
        gradientStop->setOffset(offset);
        return 0;
    }

    return -1;
}

bool isSetStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex) {
    return isSetStopColor(getGradientDefinition(renderInformationBase, sid), gradientStopIndex);
}

bool isSetStopColor(GradientBase* gradientBase, unsigned int gradientStopIndex) {
    return isSetStopColor(getGradientStop(gradientBase, gradientStopIndex));
}

bool isSetStopColor(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->isSetStopColor();

    return false;
}

const std::string getStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex) {
    return getStopColor(getGradientDefinition(renderInformationBase, sid), gradientStopIndex);
}

const std::string getStopColor(GradientBase* gradientBase, unsigned int gradientStopIndex) {
    return getStopColor(getGradientStop(gradientBase, gradientStopIndex));
}

const std::string getStopColor(GradientStop* gradientStop) {
    if (gradientStop)
        return gradientStop->getStopColor();

    return "";
}

int setStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, const std::string& stopColor) {
    return setStopColor(renderInformationBase, sid, 0, stopColor);
}

int setStopColor(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor) {
    return setStopColor(getGradientDefinition(renderInformationBase, sid), gradientStopIndex, stopColor);
}

int setStopColor(GradientBase* gradientBase, const std::string& stopColor) {
    return setStopColor(gradientBase, 0, stopColor);
}

int setStopColor(GradientBase* gradientBase, unsigned int gradientStopIndex, const std::string& stopColor) {
    return setStopColor(getGradientStop(gradientBase, gradientStopIndex), stopColor);
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

LineEnding* getLineEnding(RenderInformationBase* renderInformationBase, unsigned int linEndingIndex) {
    if (renderInformationBase)
        return renderInformationBase->getLineEnding(linEndingIndex);

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

const bool isGraphicalPrimitive1D(Transformation2D* transformation2D) {
    if (transformation2D && dynamic_cast<GraphicalPrimitive1D*>(transformation2D))
        return true;

    return false;
}

const bool isGraphicalPrimitive2D(Transformation2D* transformation2D) {
    if (transformation2D && dynamic_cast<GraphicalPrimitive2D*>(transformation2D))
        return true;

    return false;
}

const bool isRenderGroup(Transformation2D* transformation2D) {
    if (transformation2D && dynamic_cast<RenderGroup*>(transformation2D))
        return true;

    return false;
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

bool isSetStrokeColor(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->isSetStroke();

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

const std::string getStrokeColor(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->getStroke();

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

int setStrokeColor(Transformation2D* transformation2D, const std::string& stroke) {
    if (isGraphicalPrimitive1D(transformation2D)) {
        ((GraphicalPrimitive1D*)transformation2D)->setStroke(stroke);
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

bool isSetStrokeWidth(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->isSetStrokeWidth();

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

const double getStrokeWidth(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->getStrokeWidth();

    return 0.0;
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

int setStrokeWidth(Transformation2D* transformation2D, const double& strokeWidth) {
    if (isGraphicalPrimitive1D(transformation2D)) {
        ((GraphicalPrimitive1D*)transformation2D)->setStrokeWidth(strokeWidth);
        return 0;
    }

    return -1;
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

bool isSetStrokeDashArray(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->isSetStrokeDashArray();

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

const std::vector<unsigned int> getStrokeDashArray(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->getStrokeDashArray();

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

int setStrokeDashArray(Transformation2D* transformation2D, const std::vector<unsigned int>& strokeDashArray) {
    if (isGraphicalPrimitive1D(transformation2D)) {
        ((GraphicalPrimitive1D*)transformation2D)->setStrokeDashArray(strokeDashArray);
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

unsigned int getNumStrokeDashes(Transformation2D* transformation2D) {
    return getStrokeDashArray(transformation2D).size();
}

unsigned int getStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int strokeDashIndex) {
    return getStrokeDash(getStyle(renderInformationBase, graphicalObject), strokeDashIndex);
}

unsigned int getStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int strokeDashIndex) {
    return getStrokeDash(getStyle(renderInformationBase, attribute), strokeDashIndex);
}

unsigned int getStrokeDash(Style* style, unsigned int strokeDashIndex) {
    return getStrokeDash(getRenderGroup(style), strokeDashIndex);
}

unsigned int getStrokeDash(Transformation2D* transformation2D, unsigned int strokeDashIndex) {
    if (isGraphicalPrimitive1D(transformation2D))
        ((GraphicalPrimitive1D*)transformation2D)->getDashByIndex(strokeDashIndex);

    return 0;
}

unsigned int setStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int dash) {
    return setStrokeDash(renderInformationBase, graphicalObject, 0, dash);
}

unsigned int setStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getStyle(renderInformationBase, graphicalObject), strokeDashIndex, dash);
}

unsigned int setStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int dash) {
    return setStrokeDash(renderInformationBase, attribute, 0, dash);
}

unsigned int setStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getStyle(renderInformationBase, attribute), strokeDashIndex, dash);
}

unsigned int setStrokeDash(Style* style, unsigned int dash) {
    return setStrokeDash(style, 0, dash);
}

unsigned int setStrokeDash(Style* style, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getRenderGroup(style), strokeDashIndex, dash);
}

unsigned int setStrokeDash(Transformation2D* transformation2D, unsigned int dash) {
    return setStrokeDash(transformation2D, 0, dash);
}

unsigned int setStrokeDash(Transformation2D* transformation2D, unsigned int strokeDashIndex, unsigned int dash) {
    if (isGraphicalPrimitive1D(transformation2D)) {
        ((GraphicalPrimitive1D*)transformation2D)->setDashByIndex(strokeDashIndex, dash);
        return 0;
    }

    return -1;
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

bool isSetFontColor(Transformation2D* transformation2D) {
    return isSetStrokeColor(transformation2D);
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

const std::string getFontColor(Transformation2D* transformation2D) {
    return getStrokeColor(transformation2D);
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

int setFontColor(Transformation2D* transformation2D, const std::string& fontColor) {
    return setStrokeColor(transformation2D, fontColor);
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

bool isSetFontFamily(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontFamily();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontFamily();

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

const std::string getFontFamily(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontFamily();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontFamily();

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

int setFontFamily(Transformation2D* transformation2D, const std::string& fontFamily) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setFontFamily(fontFamily);
        return 0;
    }
    else if (isText(transformation2D)) {
        ((Text*)transformation2D)->setFontFamily(fontFamily);
        return 0;
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

bool isSetFontSize(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontSize();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontSize();

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

const RelAbsVector getFontSize(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontSize();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontSize();
    
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

int setFontSize(Transformation2D* transformation2D, const RelAbsVector& fontSize) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setFontSize(fontSize);
        return 0;
    }
    else if (isText(transformation2D)) {
        ((Text*)transformation2D)->setFontSize(fontSize);
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

bool isSetFontWeight(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontWeight();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontWeight();

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

const std::string getFontWeight(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontWeightAsString();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontWeightAsString();

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

int setFontWeight(Transformation2D* transformation2D, const std::string& fontWeight) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setFontWeight(fontWeight);
        return 0;
    }
    else if (isText(transformation2D)) {
        ((Text*)transformation2D)->setFontWeight(fontWeight);
        return 0;
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

bool isSetFontStyle(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontStyle();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetFontStyle();

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

const std::string getFontStyle(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontStyleAsString();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->getFontStyleAsString();

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

int setFontStyle(Transformation2D* transformation2D, const std::string& fontStyle) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setFontStyle(fontStyle);
        return 0;
    }
    else if (isText(transformation2D)) {
        ((Text*)transformation2D)->setFontStyle(fontStyle);
        return 0;
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

bool isSetTextAnchor(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetTextAnchor();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetTextAnchor();

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

const std::string getTextAnchor(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getTextAnchorAsString();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->getTextAnchorAsString();

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

int setTextAnchor(Transformation2D* transformation2D, const std::string& textAnchor) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setTextAnchor(textAnchor);
        return 0;
    }
    else if (isText(transformation2D)) {
        ((Text*)transformation2D)->setTextAnchor(textAnchor);
        return 0;
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

bool isSetVTextAnchor(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetVTextAnchor();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetVTextAnchor();

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

const std::string getVTextAnchor(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getVTextAnchorAsString();
    else if (isText(transformation2D))
        return ((RenderGroup*)transformation2D)->getVTextAnchorAsString();

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

int setVTextAnchor(Transformation2D* transformation2D, const std::string& vtextAnchor) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setVTextAnchor(vtextAnchor);
        return 0;
    }
    else if (isText(transformation2D)) {
        ((Text*)transformation2D)->setVTextAnchor(vtextAnchor);
        return 0;
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

bool isSetFillColor(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive2D(transformation2D))
        return ((GraphicalPrimitive2D*)transformation2D)->isSetFill();

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

const std::string getFillColor(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive2D(transformation2D))
        return ((GraphicalPrimitive2D*)transformation2D)->getFill();

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

int setFillColor(Transformation2D* transformation2D, const std::string& fillColor) {
    if (isGraphicalPrimitive2D(transformation2D)) {
        ((GraphicalPrimitive2D*)transformation2D)->setFill(fillColor);
        return 0;
    }

    return -1;
}

bool isSetFillRule(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return isSetFillRule(getStyle(renderInformationBase, graphicalObject));
}

bool isSetFillRule(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return isSetFillRule(getStyle(renderInformationBase, attribute));
}

bool isSetFillRule(Style* style) {
    return isSetFillRule(getRenderGroup(style));
}

bool isSetFillRule(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive2D(transformation2D))
        return ((GraphicalPrimitive2D*)transformation2D)->isSetFillRule();

    return false;
}

const std::string getFillRule(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject) {
    return getFillRule(getStyle(renderInformationBase, graphicalObject));
}

const std::string getFillRule(RenderInformationBase* renderInformationBase, const std::string& attribute) {
    return getFillRule(getStyle(renderInformationBase, attribute));
}

const std::string getFillRule(Style* style) {
    return getFillRule(getRenderGroup(style));
}

const std::string getFillRule(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive2D(transformation2D))
        return ((GraphicalPrimitive2D*)transformation2D)->getFillRuleAsString();

    return "";
}

int setFillRule(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& fillRule) {
    return setFillRule(getStyle(renderInformationBase, graphicalObject), fillRule);
}

int setFillRule(RenderInformationBase* renderInformationBase, const std::string& attribute, std::string& fillRule) {
    return setFillRule(getStyle(renderInformationBase, attribute), fillRule);
}

int setFillRule(Style* style, const std::string& fillRule) {
    return setFillRule(getRenderGroup(style), fillRule);
}

int setFillRule(Transformation2D* transformation2D, const std::string& fillRule) {
    if (isGraphicalPrimitive2D(transformation2D)) {
        ((GraphicalPrimitive2D*)transformation2D)->setFillRule(fillRule);
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

bool isSetStartHead(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetStartHead();
    else if (isRenderCurve(transformation2D))
        return ((RenderCurve*)transformation2D)->isSetStartHead();

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

const std::string getStartHead(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getStartHead();
    else if (isRenderCurve(transformation2D))
        return ((RenderCurve*)transformation2D)->getStartHead();

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

int setStartHead(Transformation2D* transformation2D, const std::string startHead) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setStartHead(startHead);
        return 0;
    }
    else if (isRenderCurve(transformation2D)) {
        ((RenderCurve*)transformation2D)->setStartHead(startHead);
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

bool isSetEndHead(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->isSetEndHead();
    else if (isRenderCurve(transformation2D))
        return ((RenderCurve*)transformation2D)->isSetEndHead();

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

const std::string getEndHead(Transformation2D* transformation2D) {
    if (isRenderGroup(transformation2D))
        return ((RenderGroup*)transformation2D)->getEndHead();
    else if (isRenderCurve(transformation2D))
        return ((RenderCurve*)transformation2D)->getEndHead();

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

int setEndHead(Transformation2D* transformation2D, const std::string endHead) {
    if (isRenderGroup(transformation2D)) {
        ((RenderGroup*)transformation2D)->setEndHead(endHead);
        return 0;
    }
    else if (isRenderCurve(transformation2D)) {
        ((RenderCurve*)transformation2D)->setEndHead(endHead);
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

Transformation2D* getGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShape(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

Transformation2D* getGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShape(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

Transformation2D* getGeometricShape(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShape(getRenderGroup(style), geometricShapeIndex);
}

Transformation2D* getGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    if (renderGroup)
        return renderGroup->getElement(geometricShapeIndex);

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

Transformation2D* removeGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

Transformation2D* removeGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

Transformation2D* removeGeometricShape(Style* style, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getRenderGroup(style), geometricShapeIndex);
}

Transformation2D* removeGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    if (renderGroup)
        return renderGroup->removeElement(geometricShapeIndex);

    return NULL;
}

bool isRectangle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isRectangle(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isRectangle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isRectangle(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isRectangle(Style* style, unsigned int geometricShapeIndex) {
    return isRectangle(getRenderGroup(style), geometricShapeIndex);
}

bool isRectangle(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isRectangle(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isRectangle(Transformation2D* shape) {
    if (shape)
        return shape->isRectangle();

    return false;
}

bool isEllipse(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isEllipse(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isEllipse(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isEllipse(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isEllipse(Style* style, unsigned int geometricShapeIndex) {
    return isEllipse(getRenderGroup(style), geometricShapeIndex);
}

bool isEllipse(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isEllipse(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isEllipse(Transformation2D* shape) {
    if (shape)
        return shape->isEllipse();

    return false;
}

bool isPolygon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isPolygon(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isPolygon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isPolygon(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isPolygon(Style* style, unsigned int geometricShapeIndex) {
    return isPolygon(getRenderGroup(style), geometricShapeIndex);
}

bool isPolygon(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isPolygon(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isPolygon(Transformation2D* shape) {
    if (shape)
        return shape->isPolygon();

    return false;
}

bool isRenderCurve(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isRenderCurve(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isRenderCurve(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isRenderCurve(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isRenderCurve(Style* style, unsigned int geometricShapeIndex) {
    return isRenderCurve(getRenderGroup(style), geometricShapeIndex);
}

bool isRenderCurve(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isRenderCurve(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isRenderCurve(Transformation2D* shape) {
    if (shape)
        return shape->isRenderCurve();

    return false;
}

bool isImage(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isImage(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isImage(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isImage(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isImage(Style* style, unsigned int geometricShapeIndex) {
    return isImage(getRenderGroup(style), geometricShapeIndex);
}

bool isImage(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isImage(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isImage(Transformation2D* shape) {
    if (shape)
        return shape->isImage();

    return false;
}

bool isText(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isText(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isText(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isText(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isText(Style* style, unsigned int geometricShapeIndex) {
    return isText(getRenderGroup(style), geometricShapeIndex);
}

bool isText(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isText(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isText(Transformation2D* shape) {
    if (shape)
        return shape->isText();

    return false;
}

bool isSetGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeX(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getGeometricShape(renderGroup, geometricShapeIndex));
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

const RelAbsVector getGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeX(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeX(getGeometricShape(renderGroup, geometricShapeIndex));
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

int setGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeX(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, x);
}

int setGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeX(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getStyle(renderInformationBase, attribute), geometricShapeIndex, x);
}

int setGeometricShapeX(Style* style, const RelAbsVector& x) {
    return setGeometricShapeX(style, 0, x);
}

int setGeometricShapeX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getRenderGroup(style), geometricShapeIndex, x);
}

int setGeometricShapeX(RenderGroup* renderGroup, const RelAbsVector& x) {
    return setGeometricShapeX(renderGroup, 0, x);
}

int setGeometricShapeX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& x) {
    return setGeometricShapeX(getGeometricShape(renderGroup, geometricShapeIndex), x);
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

bool isSetGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeY(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeY(getGeometricShape(renderGroup, geometricShapeIndex));
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

const RelAbsVector getGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeY(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeY(getGeometricShape(renderGroup, geometricShapeIndex));
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

int setGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeY(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, y);
}

int setGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeY(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getStyle(renderInformationBase, attribute), geometricShapeIndex, y);
}

int setGeometricShapeY(Style* style, const RelAbsVector& y) {
    return setGeometricShapeY(style, 0, y);
}

int setGeometricShapeY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getRenderGroup(style), geometricShapeIndex, y);
}

int setGeometricShapeY(RenderGroup* renderGroup, const RelAbsVector& y) {
    return setGeometricShapeY(renderGroup, 0, y);
}

int setGeometricShapeY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& y) {
    return setGeometricShapeY(getGeometricShape(renderGroup, geometricShapeIndex), y);
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

bool isSetGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeWidth(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeWidth(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeWidth(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetWidth();
    else if (isImage(shape))
        return ((Image*)shape)->isSetWidth();

    return false;
}

const RelAbsVector getGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeWidth(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeWidth(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeWidth(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getWidth();
    else if (isImage(shape))
        return ((Image*)shape)->getWidth();

    return RelAbsVector();
}

int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& width) {
    return setGeometricShapeWidth(renderInformationBase, graphicalObject, 0, width);
}

int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, width);
}

int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& width) {
    return setGeometricShapeWidth(renderInformationBase, attribute, 0, width);
}

int setGeometricShapeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getStyle(renderInformationBase, attribute), geometricShapeIndex, width);
}

int setGeometricShapeWidth(Style* style, const RelAbsVector& width) {
    return setGeometricShapeWidth(style, 0, width);
}

int setGeometricShapeWidth(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getRenderGroup(style), geometricShapeIndex, width);
}

int setGeometricShapeWidth(RenderGroup* renderGroup, const RelAbsVector& width) {
    return setGeometricShapeWidth(renderGroup, 0, width);
}

int setGeometricShapeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& width) {
    return setGeometricShapeWidth(getGeometricShape(renderGroup, geometricShapeIndex), width);
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

bool isSetGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeHeight(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeHeight(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHeight(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeHeight(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetHeight();
    else if (isImage(shape))
        return ((Image*)shape)->isSetHeight();

    return false;
}

const RelAbsVector getGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeHeight(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeHeight(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeHeight(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeHeight(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getHeight();
    else if (isImage(shape))
        return ((Image*)shape)->getHeight();

    return RelAbsVector();
}

int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& height) {
    return setGeometricShapeHeight(renderInformationBase, graphicalObject, 0, height);
}

int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, height);
}

int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& height) {
    return setGeometricShapeHeight(renderInformationBase, attribute, 0, height);
}

int setGeometricShapeHeight(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getStyle(renderInformationBase, attribute), geometricShapeIndex, height);
}

int setGeometricShapeHeight(Style* style, const RelAbsVector& height) {
    return setGeometricShapeHeight(style, 0, height);
}

int setGeometricShapeHeight(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getRenderGroup(style), geometricShapeIndex, height);
}

int setGeometricShapeHeight(RenderGroup* renderGroup, const RelAbsVector& height) {
    return setGeometricShapeHeight(renderGroup, height);
}

int setGeometricShapeHeight(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& height) {
    return setGeometricShapeHeight(getGeometricShape(renderGroup, geometricShapeIndex), height);
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

bool isSetGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeRatio(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeRatio(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRatio(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeRatio(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRatio();
    else if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRatio();

    return false;
}

const double getGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const double getGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const double getGeometricShapeRatio(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getRenderGroup(style), geometricShapeIndex);
}

const double getGeometricShapeRatio(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeRatio(getGeometricShape(renderGroup, geometricShapeIndex));
}

const double getGeometricShapeRatio(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRatio();
    else if (isEllipse(shape))
        return ((Ellipse*)shape)->getRatio();

    return 0.0;
}

int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& ratio) {
    return setGeometricShapeRatio(renderInformationBase, graphicalObject, 0, ratio);
}

int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ratio) {
    return setGeometricShapeRatio(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, ratio);
}

int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& ratio) {
    return setGeometricShapeRatio(renderInformationBase, attribute, 0, ratio);
}

int setGeometricShapeRatio(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& ratio) {
    return setGeometricShapeRatio(getStyle(renderInformationBase, attribute), geometricShapeIndex, ratio);
}

int setGeometricShapeRatio(Style* style, const double& ratio) {
    return setGeometricShapeRatio(style, 0, ratio);
}

int setGeometricShapeRatio(Style* style, unsigned int geometricShapeIndex, const double& ratio) {
    return setGeometricShapeRatio(getRenderGroup(style), geometricShapeIndex, ratio);
}

int setGeometricShapeRatio(RenderGroup* renderGroup, const double& ratio) {
    return setGeometricShapeRatio(renderGroup, 0, ratio);
}

int setGeometricShapeRatio(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& ratio) {
    return setGeometricShapeRatio(getGeometricShape(renderGroup, geometricShapeIndex), ratio);
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

bool isSetGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusX(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRX();

    return false;
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRX();

    return RelAbsVector();
}

int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(renderInformationBase, graphicalObject, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(renderInformationBase, attribute, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getStyle(renderInformationBase, attribute), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(Style* style, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(style, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getRenderGroup(style), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(renderGroup, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeCornerCurvatureRadiusX(getGeometricShape(renderGroup, geometricShapeIndex), rx);
}

int setGeometricShapeCornerCurvatureRadiusX(Transformation2D* shape, const RelAbsVector& rx) {
    if (isRectangle(shape)) {
        ((Rectangle*)shape)->setRX(rx);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCornerCurvatureRadiusY(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->isSetRY();

    return false;
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape) {
    if (isRectangle(shape))
        return ((Rectangle*)shape)->getRY();

    return RelAbsVector();
}

int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(renderInformationBase, graphicalObject, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(renderInformationBase, attribute, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getStyle(renderInformationBase, attribute), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(Style* style, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(style, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getRenderGroup(style), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(renderGroup, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeCornerCurvatureRadiusY(getGeometricShape(renderGroup, geometricShapeIndex), ry);
}

int setGeometricShapeCornerCurvatureRadiusY(Transformation2D* shape, const RelAbsVector& ry) {
    if (isRectangle(shape)) {
        return ((Rectangle*)shape)->setRY(ry);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeX(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeCenterX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetCX();

    return false;
}

const RelAbsVector getGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterX(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeCenterX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getCX();

    return RelAbsVector();
}

int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(renderInformationBase, graphicalObject, 0, cx);
}

int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, cx);
}

int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(renderInformationBase, attribute, 0, cx);
}

int setGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getStyle(renderInformationBase, attribute), geometricShapeIndex, cx);
}

int setGeometricShapeCenterX(Style* style, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(style, cx);
}

int setGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getRenderGroup(style), geometricShapeIndex, cx);
}

int setGeometricShapeCenterX(RenderGroup* renderGroup, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(renderGroup, 0, cx);
}

int setGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& cx) {
    return setGeometricShapeCenterX(getGeometricShape(renderGroup, geometricShapeIndex), cx);
}

int setGeometricShapeCenterX(Transformation2D* shape, const RelAbsVector& cx) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setCX(cx);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeCenterY(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterY(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeCenterY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetCY();

    return false;
}

const RelAbsVector getGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterY(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeCenterY(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeCenterY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getCY();

    return RelAbsVector();
}

int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(renderInformationBase, graphicalObject, 0, cy);
}

int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, cy);
}

int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(renderInformationBase, attribute, 0, cy);
}

int setGeometricShapeCenterY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getStyle(renderInformationBase, attribute), geometricShapeIndex, cy);
}

int setGeometricShapeCenterY(Style* style, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(style, 0, cy);
}

int setGeometricShapeCenterY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getRenderGroup(style), geometricShapeIndex, cy);
}

int setGeometricShapeCenterY(RenderGroup* renderGroup, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(renderGroup, 0, cy);
}

int setGeometricShapeCenterY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& cy) {
    return setGeometricShapeCenterY(getGeometricShape(renderGroup, geometricShapeIndex), cy);
}

int setGeometricShapeCenterY(Transformation2D* shape, const RelAbsVector& cy) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setCY(cy);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusX(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusX(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeRadiusX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRX();

    return false;
}

const RelAbsVector getGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusX(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusX(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeRadiusX(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getRX();

    return RelAbsVector();
}

int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(renderInformationBase, graphicalObject, 0, rx);
}

int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(renderInformationBase, attribute, 0, rx);
}

int setGeometricShapeRadiusX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getStyle(renderInformationBase, attribute), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusX(Style* style, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(style, 0, rx);
}

int setGeometricShapeRadiusX(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getRenderGroup(style), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusX(RenderGroup* renderGroup, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(renderGroup, 0, rx);
}

int setGeometricShapeRadiusX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& rx) {
    return setGeometricShapeRadiusX(getGeometricShape(renderGroup, geometricShapeIndex), rx);
}

int setGeometricShapeRadiusX(Transformation2D* shape, const RelAbsVector& rx) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRX(rx);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusY(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeRadiusY(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeRadiusY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->isSetRY();

    return false;
}

const RelAbsVector getGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusY(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getRenderGroup(style), geometricShapeIndex);
}

const RelAbsVector getGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeRadiusY(getGeometricShape(renderGroup, geometricShapeIndex));
}

const RelAbsVector getGeometricShapeRadiusY(Transformation2D* shape) {
    if (isEllipse(shape))
        return ((Ellipse*)shape)->getRY();

    return RelAbsVector();
}

int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(renderInformationBase, graphicalObject, 0, ry);
}

int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(renderInformationBase, attribute, 0, ry);
}

int setGeometricShapeRadiusY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getStyle(renderInformationBase, attribute), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusY(Style* style, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(style, 0, ry);
}

int setGeometricShapeRadiusY(Style* style, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getRenderGroup(style), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusY(RenderGroup* renderGroup, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(renderGroup, 0, ry);
}

int setGeometricShapeRadiusY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const RelAbsVector& ry) {
    return setGeometricShapeRadiusY(getGeometricShape(renderGroup, geometricShapeIndex), ry);
}

int setGeometricShapeRadiusY(Transformation2D* shape, const RelAbsVector& ry) {
    if (isEllipse(shape)) {
        ((Ellipse*)shape)->setRY(ry);
        return 0;
    }

    return -1;
}

const unsigned int getGeometricShapeNumElements(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const unsigned int getGeometricShapeNumElements(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const unsigned int getGeometricShapeNumElements(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getRenderGroup(style), geometricShapeIndex);
}

const unsigned int getGeometricShapeNumElements(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeNumElements(getGeometricShape(renderGroup, geometricShapeIndex));
}

const unsigned int getGeometricShapeNumElements(Transformation2D* shape) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->getNumElements();
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->getNumElements();

    return 0;
}

const RelAbsVector getGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementX(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

const RelAbsVector getGeometricShapeElementX(Transformation2D* shape, unsigned int elementIndex) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (element)
        return element->getX();

    return RelAbsVector();
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeElementX(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(renderInformationBase, graphicalObject, 0, elementIndex, x);
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeElementX(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(renderInformationBase, attribute, 0, elementIndex, x);
}

int setGeometricShapeElementX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementX(Style* style, const RelAbsVector& x) {
    return setGeometricShapeElementX(style, 0, x);
}

int setGeometricShapeElementX(Style* style, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(style, 0, elementIndex, x);
}

int setGeometricShapeElementX(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getRenderGroup(style), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementX(RenderGroup* renderGroup, const RelAbsVector& x) {
    return setGeometricShapeElementX(renderGroup, 0, x);
}

int setGeometricShapeElementX(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(renderGroup, 0, elementIndex, x);
}

int setGeometricShapeElementX(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, x);
}

int setGeometricShapeElementX(Transformation2D* shape, const RelAbsVector& x) {
    return setGeometricShapeElementX(shape, 0, x);
}

int setGeometricShapeElementX(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& x) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (element) {
        element->setX(x);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementX(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

const RelAbsVector getGeometricShapeElementY(Transformation2D* shape, unsigned int elementIndex) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (element)
        return element->getY();

    return RelAbsVector();
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeElementY(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(renderInformationBase, graphicalObject, 0, elementIndex, y);
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeElementY(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(renderInformationBase, attribute, 0, elementIndex, y);
}

int setGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementY(Style* style, const RelAbsVector& y) {
    return setGeometricShapeElementY(style, 0, y);
}

int setGeometricShapeElementY(Style* style, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(style, 0, elementIndex, y);
}

int setGeometricShapeElementY(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getRenderGroup(style), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementY(RenderGroup* renderGroup, const RelAbsVector& y) {
    return setGeometricShapeElementY(renderGroup, 0, y);
}

int setGeometricShapeElementY(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(renderGroup, 0, elementIndex, y);
}

int setGeometricShapeElementY(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeElementY(Transformation2D* shape, const RelAbsVector& y) {
    return setGeometricShapeElementY(shape, 0, y);
}

int setGeometricShapeElementY(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& y) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (element) {
        element->setY(y);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1X(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1X(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1X(Transformation2D* shape, unsigned int elementIndex) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint1_x();

    return RelAbsVector();
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(renderInformationBase, graphicalObject, 0, elementIndex, x);
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(renderInformationBase, attribute, 0, elementIndex, x);
}

int setGeometricShapeBasePoint1X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1X(Style* style, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(style, 0, x);
}

int setGeometricShapeBasePoint1X(Style* style, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(style, 0, elementIndex, x);
}

int setGeometricShapeBasePoint1X(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getRenderGroup(style), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(renderGroup, 0, x);
}

int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(renderGroup, 0, elementIndex, x);
}

int setGeometricShapeBasePoint1X(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, x);
}

int setGeometricShapeBasePoint1X(Transformation2D* shape, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(shape, 0, x);
}

int setGeometricShapeBasePoint1X(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& x) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint1_x(x);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1Y(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint1Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint1Y(Transformation2D* shape, unsigned int elementIndex) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint1_y();

    return RelAbsVector();
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(renderInformationBase, graphicalObject, 0, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(renderInformationBase, attribute, 0, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(Style* style, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(style, 0, y);
}

int setGeometricShapeBasePoint1Y(Style* style, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(style, 0, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getRenderGroup(style), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(renderGroup, 0, y);
}

int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(renderGroup, 0, elementIndex, y);
}

int setGeometricShapeBasePoint1Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeBasePoint1Y(Transformation2D* shape, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(shape, 0, y);
}

int setGeometricShapeBasePoint1Y(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& y) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint1_y(y);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2X(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2X(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2X(Transformation2D* shape, unsigned int elementIndex) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint2_x();

    return RelAbsVector();
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(renderInformationBase, graphicalObject, 0, elementIndex, x);
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(renderInformationBase, attribute, 0, elementIndex, x);
}

int setGeometricShapeBasePoint2X(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2X(Style* style, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(style, 0, x);
}

int setGeometricShapeBasePoint2X(Style* style, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(style, 0, elementIndex, x);
}

int setGeometricShapeBasePoint2X(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getRenderGroup(style), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(renderGroup, 0, x);
}

int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(renderGroup, 0, elementIndex, x);
}

int setGeometricShapeBasePoint2X(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, x);
}

int setGeometricShapeBasePoint2X(Transformation2D* shape, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2X(shape, 0, x);
}

int setGeometricShapeBasePoint2X(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& x) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint2_x(x);
        return 0;
    }

    return -1;
}

const RelAbsVector getGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2Y(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeBasePoint2Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

const RelAbsVector getGeometricShapeBasePoint2Y(Transformation2D* shape, unsigned int elementIndex) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element))
        return ((RenderCubicBezier*)element)->getBasePoint2_y();

    return RelAbsVector();
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(renderInformationBase, graphicalObject, 0, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(renderInformationBase, attribute, 0, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(Style* style, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(style, 0, y);
}

int setGeometricShapeBasePoint2Y(Style* style, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(style, 0, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getRenderGroup(style), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(renderGroup, 0, y);
}

int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(renderGroup, 0, elementIndex, y);
}

int setGeometricShapeBasePoint2Y(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeBasePoint2Y(Transformation2D* shape, const RelAbsVector& y) {
    return setGeometricShapeBasePoint2Y(shape, 0, y);
}

int setGeometricShapeBasePoint2Y(Transformation2D* shape, unsigned int elementIndex, const RelAbsVector& y) {
    RenderPoint* element = NULL;
    if (isPolygon(shape))
        element = ((Polygon*)shape)->getElement(elementIndex);
    else if (isRenderCurve(shape))
        element = ((RenderCurve*)shape)->getElement(elementIndex);

    if (isRenderCubicBezier(element)) {
        ((RenderCubicBezier*)element)->setBasePoint2_y(y);
        return 0;
    }

    return -1;
}

int addRenderPointToGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return addRenderPointToGeometricShape(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

int addRenderPointToGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return addRenderPointToGeometricShape(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

int addRenderPointToGeometricShape(Style* style, unsigned int geometricShapeIndex) {
    return addRenderPointToGeometricShape(getRenderGroup(style), geometricShapeIndex);
}

int addRenderPointToGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return addRenderPointToGeometricShape(getGeometricShape(renderGroup, geometricShapeIndex));
}

int addRenderPointToGeometricShape(Transformation2D* shape) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->addElement(new RenderPoint(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->addElement(new RenderPoint(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));

    return -1;
}

int addRenderCubicBezierToGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return addRenderCubicBezierToGeometricShape(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return addRenderCubicBezierToGeometricShape(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(Style* style, unsigned int geometricShapeIndex) {
    return addRenderCubicBezierToGeometricShape(getRenderGroup(style), geometricShapeIndex);
}

int addRenderCubicBezierToGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return addRenderCubicBezierToGeometricShape(getGeometricShape(renderGroup, geometricShapeIndex));
}

int addRenderCubicBezierToGeometricShape(Transformation2D* shape) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->addElement(new RenderCubicBezier(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->addElement(new RenderCubicBezier(new RenderPkgNamespaces(shape->getLevel(), shape->getVersion())));

    return -1;
}

RenderPoint* removeElementFromGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return removeElementFromGeometricShape(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

RenderPoint* removeElementFromGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return removeElementFromGeometricShape(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

RenderPoint* removeElementFromGeometricShape(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return removeElementFromGeometricShape(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

RenderPoint* removeElementFromGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return removeElementFromGeometricShape(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

RenderPoint* removeElementFromGeometricShape(Transformation2D* shape, unsigned int elementIndex) {
    if (isPolygon(shape))
        return ((Polygon*)shape)->removeElement(elementIndex);
    else if (isRenderCurve(shape))
        return ((RenderCurve*)shape)->removeElement(elementIndex);

    return NULL;
}

bool isRenderCubicBezier(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

bool isRenderCubicBezier(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

bool isRenderCubicBezier(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getRenderGroup(style), geometricShapeIndex, elementIndex);
}

bool isRenderCubicBezier(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return isRenderCubicBezier(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex);
}

bool isRenderCubicBezier(Transformation2D* shape, unsigned int elementIndex) {
    if (isPolygon(shape))
        return isRenderCubicBezier(((Polygon*)shape)->getElement(elementIndex));
    else if (isRenderCurve(shape))
        return isRenderCubicBezier(((RenderCurve*)shape)->getElement(elementIndex));

    return false;
}

bool isRenderCubicBezier(RenderPoint* renderPoint) {
    if (renderPoint)
        return renderPoint->isRenderCubicBezier();

    return false;
}

bool isSetGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeHref(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeHref(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeHref(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeHref(Transformation2D* shape) {
    if (isImage(shape))
        return ((Image*)shape)->isSetHref();

    return false;
}

const std::string getGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const std::string getGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const std::string getGeometricShapeHref(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getRenderGroup(style), geometricShapeIndex);
}

const std::string getGeometricShapeHref(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeHref(getGeometricShape(renderGroup, geometricShapeIndex));
}

const std::string getGeometricShapeHref(Transformation2D* shape) {
    if (isImage(shape))
        return ((Image*)shape)->getHref();

    return "";
}

int setGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& href) {
    return setGeometricShapeHref(renderInformationBase, graphicalObject, 0, href);
}

int setGeometricShapeHref(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, href);
}

int setGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& href) {
    return setGeometricShapeHref(renderInformationBase, attribute, 0, href);
}

int setGeometricShapeHref(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getStyle(renderInformationBase, attribute), geometricShapeIndex, href);
}

int setGeometricShapeHref(Style* style, const std::string& href) {
    return setGeometricShapeHref(style, 0, href);
}

int setGeometricShapeHref(Style* style, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getRenderGroup(style), geometricShapeIndex, href);
}

int setGeometricShapeHref(RenderGroup* renderGroup, const std::string& href) {
    return setGeometricShapeHref(renderGroup, 0, href);
}

int setGeometricShapeHref(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& href) {
    return setGeometricShapeHref(getGeometricShape(renderGroup, geometricShapeIndex), href);
}

int setGeometricShapeHref(Transformation2D* shape, const std::string& href) {
    if (isImage(shape)) {
        ((Image*)shape)->setHref(href);
        return 0;
    }

    return -1;
}

const double getAbsoluteValue(const RelAbsVector& relAbsVector) {
    return relAbsVector.getAbsoluteValue();
}

int setAbsoluteValue(RelAbsVector relAbsVector, const double& abs) {
    return relAbsVector.setAbsoluteValue(abs);
}

const double getRelativeValue(const RelAbsVector& relAbsVector) {
    return relAbsVector.getRelativeValue();
}

int setRelativeValue(RelAbsVector relAbsVector, const double& rel) {
    return relAbsVector.setRelativeValue(rel);
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

