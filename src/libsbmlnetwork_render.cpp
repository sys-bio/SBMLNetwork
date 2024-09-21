#include "libsbmlnetwork_render.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_render_helpers.h"
#include "colors/libsbmlnetwork_colors.h"
#include "styles/libsbmlnetwork_styles.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

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
    if (listOfLocalRenderInformation) {
        if (renderIndex < listOfLocalRenderInformation->size())
            return listOfLocalRenderInformation->get(renderIndex);

        std::cerr << "error: renderIndex out of range" << std::endl;
    }

    return NULL;
}

bool isSetBackgroundColor(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        return renderInformationBase->isSetBackgroundColor();

    return false;
}

const std::string getBackgroundColor(RenderInformationBase* renderInformationBase) {
    if (renderInformationBase)
        return renderInformationBase->getBackgroundColor();

    return "";
}

int setBackgroundColor(RenderInformationBase* renderInformationBase, const std::string& backgroundColor) {
    if (renderInformationBase && isValidBackgroundColorValue(backgroundColor)) {
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
        return colorDefinition->isSetValue();

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
    if (colorDefinition && isValidColorValue(value)) {
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
    if (gradientBase && isValidSpreadMethodValue(spreadMethod)) {
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

    return RelAbsVector(NAN, NAN);
}

const double getOffsetAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex) {
    return getOffsetAsDouble(getGradientDefinition(renderInformationBase, sid), gradientStopIndex);
}

const double getOffsetAsDouble(GradientBase* gradientBase, unsigned int gradientStopIndex) {
    return getOffsetAsDouble(getGradientStop(gradientBase, gradientStopIndex));
}

const double getOffsetAsDouble(GradientStop* gradientStop) {
    if (gradientStop)
        return getRelativeValue(gradientStop->getOffset());

    return NAN;
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
    if (gradientStop && isValidOffsetValue(offset)) {
        gradientStop->setOffset(offset);
        return 0;
    }

    return -1;
}

int setOffsetAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& offset) {
    return setOffsetAsDouble(renderInformationBase, sid, 0, offset);
}

int setOffsetAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, unsigned int gradientStopIndex, const double& offset) {
    return setOffsetAsDouble(getGradientDefinition(renderInformationBase, sid), gradientStopIndex, offset);
}

int setOffsetAsDouble(GradientBase* gradientBase, const double& offset) {
    return setOffsetAsDouble(gradientBase, 0, offset);
}

int setOffsetAsDouble(GradientBase* gradientBase, unsigned int gradientStopIndex, const double& offset) {
    return setOffsetAsDouble(getGradientStop(gradientBase, gradientStopIndex), offset);
}

int setOffsetAsDouble(GradientStop* gradientStop, const double& offset) {
    if (gradientStop && isValidOffsetValue(offset)) {
        RelAbsVector offsetValue = gradientStop->getOffset().setRelativeValue(offset);
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
    if (gradientStop && isValidStopColorValue(stopColor)) {
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
        return ((LinearGradient*)gradientBase)->isSetX1();

    return false;
}

const RelAbsVector getLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientX1(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientX1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->getX1();

    return RelAbsVector(NAN, NAN);
}

const double getLinearGradientX1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientX1AsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getLinearGradientX1AsDouble(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return getRelativeValue(((LinearGradient*)gradientBase)->getX1());

    return NAN;
}

int setLinearGradientX1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x1) {
    return setLinearGradientX1(getGradientDefinition(renderInformationBase, sid), x1);
}

int setLinearGradientX1(GradientBase* gradientBase, const RelAbsVector& x1) {
    if (isLinearGradient(gradientBase) && isValidGradientX1Value(x1)) {
        ((LinearGradient *) gradientBase)->setX1(x1);
        return 0;
    }

    return -1;
}

int setLinearGradientX1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& x1) {
    return setLinearGradientX1AsDouble(getGradientDefinition(renderInformationBase, sid), x1);
}

int setLinearGradientX1AsDouble(GradientBase* gradientBase, const double& x1) {
    if (isLinearGradient(gradientBase) && isValidGradientX1Value(x1)) {
        ((LinearGradient *) gradientBase)->getX1().setRelativeValue(x1);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientX2(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientX2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->isSetX2();

    return false;
}

const RelAbsVector getLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientX2(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientX2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->getX2();

    return RelAbsVector(NAN, NAN);
}

const double getLinearGradientX2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientX2AsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getLinearGradientX2AsDouble(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return getRelativeValue(((LinearGradient*)gradientBase)->getX2());

    return NAN;
}

int setLinearGradientX2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& x2) {
    return setLinearGradientX2(getGradientDefinition(renderInformationBase, sid), x2);
}

int setLinearGradientX2(GradientBase* gradientBase, const RelAbsVector& x2) {
    if (isLinearGradient(gradientBase) && isValidGradientX2Value(x2)) {
        ((LinearGradient *) gradientBase)->setX2(x2);
        return 0;
    }

    return -1;
}

int setLinearGradientX2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& x2) {
    return setLinearGradientX2(getGradientDefinition(renderInformationBase, sid), x2);
}

int setLinearGradientX2AsDouble(GradientBase* gradientBase, const double& x2) {
    if (isLinearGradient(gradientBase) && isValidGradientX2Value(x2)) {
        ((LinearGradient *) gradientBase)->getX2().setRelativeValue(x2);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientY1(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientY1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->isSetY1();

    return false;
}

const RelAbsVector getLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientY1(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientY1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->getY1();

    return RelAbsVector(NAN, NAN);
}

const double getLinearGradientY1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientY1AsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getLinearGradientY1AsDouble(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return getRelativeValue(((LinearGradient*)gradientBase)->getY1());

    return NAN;
}

int setLinearGradientY1(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y1) {
    return setLinearGradientY1(getGradientDefinition(renderInformationBase, sid), y1);
}

int setLinearGradientY1(GradientBase* gradientBase, const RelAbsVector& y1) {
    if (isLinearGradient(gradientBase) && isValidGradientY1Value(y1)) {
        ((LinearGradient*) gradientBase)->setY1(y1);
        return 0;
    }

    return -1;
}

int setLinearGradientY1AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& y1) {
    return setLinearGradientY1(getGradientDefinition(renderInformationBase, sid), y1);
}

int setLinearGradientY1AsDouble(GradientBase* gradientBase, const double& y1) {
    if (isLinearGradient(gradientBase) && isValidGradientY1Value(y1)) {
        ((LinearGradient*) gradientBase)->getY1().setRelativeValue(y1);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetLinearGradientY2(getGradientDefinition(renderInformationBase, sid));
}

bool isSetLinearGradientY2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->isSetY2();

    return false;
}

const RelAbsVector getLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientY2(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getLinearGradientY2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return ((LinearGradient*)gradientBase)->getY2();

    return RelAbsVector(NAN, NAN);
}

const double getLinearGradientY2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLinearGradientY2AsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getLinearGradientY2AsDouble(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        return getRelativeValue(((LinearGradient*)gradientBase)->getY2());

    return NAN;
}

int setLinearGradientY2(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& y2) {
    return setLinearGradientY2(getGradientDefinition(renderInformationBase, sid), y2);
}

int setLinearGradientY2(GradientBase* gradientBase, const RelAbsVector& y2) {
    if (isLinearGradient(gradientBase) && isValidGradientY2Value(y2)) {
        ((LinearGradient*) gradientBase)->setY2(y2);
        return 0;
    }

    return -1;
}

int setLinearGradientY2AsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& y2) {
    return setLinearGradientY2(getGradientDefinition(renderInformationBase, sid), y2);
}

int setLinearGradientY2AsDouble(GradientBase* gradientBase, const double& y2) {
    if (isLinearGradient(gradientBase) && isValidGradientY2Value(y2)) {
        ((LinearGradient*) gradientBase)->getY2().setRelativeValue(y2);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientCx(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientCx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->isSetCx();

    return false;
}

const RelAbsVector getRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientCx(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientCx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->getCx();

    return RelAbsVector(NAN, NAN);
}

const double getRadialGradientCxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientCxAsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getRadialGradientCxAsDouble(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return getRelativeValue(((RadialGradient*)gradientBase)->getCx());

    return NAN;
}

int setRadialGradientCx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cx) {
    return setRadialGradientCx(getGradientDefinition(renderInformationBase, sid), cx);
}

int setRadialGradientCx(GradientBase* gradientBase, const RelAbsVector& cx) {
    if (isRadialGradient(gradientBase) && isValidGradientCxValue(cx)) {
        ((RadialGradient*) gradientBase)->setCx(cx);
        return 0;
    }

    return -1;
}

int setRadialGradientCxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& cx) {
    return setRadialGradientCx(getGradientDefinition(renderInformationBase, sid), cx);
}

int setRadialGradientCxAsDouble(GradientBase* gradientBase, const double& cx) {
    if (isRadialGradient(gradientBase) && isValidGradientCxValue(cx)) {
        ((RadialGradient*) gradientBase)->getCx().setRelativeValue(cx);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientCy(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientCy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->isSetCy();

    return false;
}

const RelAbsVector getRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientCy(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientCy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->getCy();

    return RelAbsVector(NAN, NAN);
}

const double getRadialGradientCyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientCyAsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getRadialGradientCyAsDouble(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return getRelativeValue(((RadialGradient*)gradientBase)->getCy());

    return NAN;
}

int setRadialGradientCy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& cy) {
    return setRadialGradientCy(getGradientDefinition(renderInformationBase, sid), cy);
}

int setRadialGradientCy(GradientBase* gradientBase, const RelAbsVector& cy) {
    if (isRadialGradient(gradientBase) && isValidGradientCyValue(cy)) {
        ((RadialGradient*)gradientBase)->setCy(cy);
        return 0;
    }

    return -1;
}

int setRadialGradientCyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& cy) {
    return setRadialGradientCy(getGradientDefinition(renderInformationBase, sid), cy);
}

int setRadialGradientCyAsDouble(GradientBase* gradientBase, const double& cy) {
    if (isRadialGradient(gradientBase) && isValidGradientCyValue(cy)) {
        ((RadialGradient*)gradientBase)->getCy().setRelativeValue(cy);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientFx(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientFx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->isSetFx();

    return false;
}

const RelAbsVector getRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientFx(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientFx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->getFx();

    return RelAbsVector(NAN, NAN);
}

const double getRadialGradientFxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientFxAsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getRadialGradientFxAsDouble(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return getRelativeValue(((RadialGradient*)gradientBase)->getFx());

    return NAN;
}

int setRadialGradientFx(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fx) {
    return setRadialGradientFx(getGradientDefinition(renderInformationBase, sid), fx);
}

int setRadialGradientFx(GradientBase* gradientBase, const RelAbsVector& fx) {
    if (isRadialGradient(gradientBase) && isValidGradientFxValue(fx)) {
        ((RadialGradient*)gradientBase)->setFx(fx);
        return 0;
    }

    return -1;
}

int setRadialGradientFxAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& fx) {
    return setRadialGradientFx(getGradientDefinition(renderInformationBase, sid), fx);
}

int setRadialGradientFxAsDouble(GradientBase* gradientBase, const double& fx) {
    if (isRadialGradient(gradientBase) && isValidGradientFxValue(fx)) {
        ((RadialGradient*)gradientBase)->getFx().setRelativeValue(fx);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientFy(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientFy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->isSetFy();

    return false;
}

const RelAbsVector getRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientFy(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientFy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->getFy();

    return RelAbsVector(NAN, NAN);
}

const double getRadialGradientFyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientFyAsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getRadialGradientFyAsDouble(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return getRelativeValue(((RadialGradient*)gradientBase)->getFy());

    return NAN;
}

int setRadialGradientFy(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& fy) {
    return setRadialGradientFy(getGradientDefinition(renderInformationBase, sid), fy);
}

int setRadialGradientFy(GradientBase* gradientBase, const RelAbsVector& fy) {
    if (isRadialGradient(gradientBase) && isValidGradientFyValue(fy)) {
        ((RadialGradient*)gradientBase)->setFy(fy);
        return 0;
    }

    return -1;
}

int setRadialGradientFyAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& fy) {
    return setRadialGradientFy(getGradientDefinition(renderInformationBase, sid), fy);
}

int setRadialGradientFyAsDouble(GradientBase* gradientBase, const double& fy) {
    if (isRadialGradient(gradientBase) && isValidGradientFyValue(fy)) {
        ((RadialGradient*)gradientBase)->getFy().setRelativeValue(fy);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return isSetRadialGradientR(getGradientDefinition(renderInformationBase, sid));
}

bool isSetRadialGradientR(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->isSetR();

    return false;
}

const RelAbsVector getRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientR(getGradientDefinition(renderInformationBase, sid));
}

const RelAbsVector getRadialGradientR(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return ((RadialGradient*)gradientBase)->getR();

    return RelAbsVector(NAN, NAN);
}

const double getRadialGradientRAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getRadialGradientRAsDouble(getGradientDefinition(renderInformationBase, sid));
}

const double getRadialGradientRAsDouble(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        return getAbsoluteValue(((RadialGradient*)gradientBase)->getR());

    return NAN;
}

int setRadialGradientR(RenderInformationBase* renderInformationBase, const std::string& sid, const RelAbsVector& r) {
    return setRadialGradientR(getGradientDefinition(renderInformationBase, sid), r);
}

int setRadialGradientR(GradientBase* gradientBase, const RelAbsVector& r) {
    if (isRadialGradient(gradientBase) && isValidGradientRValue(r)) {
        ((RadialGradient*)gradientBase)->setR(r);
        return 0;
    }

    return -1;
}

int setRadialGradientRAsDouble(RenderInformationBase* renderInformationBase, const std::string& sid, const double& r) {
    return setRadialGradientR(getGradientDefinition(renderInformationBase, sid), r);
}

int setRadialGradientRAsDouble(GradientBase* gradientBase, const double& r) {
    if (isRadialGradient(gradientBase) && isValidGradientRValue(r)) {
        ((RadialGradient*)gradientBase)->getR().setAbsoluteValue(r);
        ((RadialGradient*)gradientBase)->getR().setRelativeValue(0);
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
    if (lineEnding && isValidEnableRotationalMappingValue(enableRotationalMapping)) {
        lineEnding->setEnableRotationalMapping(enableRotationalMapping);
        return 0;
    }

    return -1;
}

BoundingBox* getLineEndingBoundingBox(RenderInformationBase* renderInformationBase, const std::string& sid) {
    return getLineEndingBoundingBox(getLineEnding(renderInformationBase, sid));
}

BoundingBox* getLineEndingBoundingBox(LineEnding* lineEnding) {
    if (lineEnding)
        return lineEnding->getBoundingBox();

    return NULL;
}

RenderGroup* getLineEndingRenderGroup(RenderInformationBase* renderInformationBase, const std::string& sid) {
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

bool isSetStrokeColor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeColor(getGeometricShape(renderGroup)))
        return isSetStrokeColor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetStroke();

    return false;
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

const std::string getStrokeColor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeColor(getGeometricShape(renderGroup)))
        return getStrokeColor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getStroke();

    return "";
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

int setStrokeColor(RenderGroup* renderGroup, const std::string& stroke) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeColor(getGeometricShape(renderGroup)))
        return setStrokeColor(getGeometricShape(renderGroup), stroke);

    if (isRenderGroup(renderGroup) && isValidStrokeColorValue(stroke)) {
        renderGroup->setStroke(stroke);
        return 0;
    }

    return -1;
}

int setStrokeColor(Transformation2D* transformation2D, const std::string& stroke) {
    if (isGraphicalPrimitive1D(transformation2D) && isValidStrokeColorValue(stroke)) {
        ((GraphicalPrimitive1D*)transformation2D)->setStroke(stroke);
        return 0;
    }

    return -1;
}

const std::string getCompartmentStrokeColor(GlobalRenderInformation* globalRenderInformation) {
    return getStrokeColor(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()));
}

int setCompartmentStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& stroke) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, stroke);
        return setStrokeColor(style, stroke);
    }

    return -1;
}

const std::string getSpeciesStrokeColor(GlobalRenderInformation* globalRenderInformation) {
    return getStrokeColor(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()));
}

int setSpeciesStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& stroke) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, stroke);
        return setStrokeColor(style, stroke);
    }

    return -1;
}

const std::string getReactionStrokeColor(GlobalRenderInformation* globalRenderInformation) {
    return getStrokeColor(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()));
}

int setReactionStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& stroke) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, stroke);
        return setStrokeColor(style, stroke);
    }

    return -1;
}

int setSpeciesReferenceStrokeColor(GlobalRenderInformation* globalRenderInformation, const std::string& stroke) {
    bool stokeColorIsSet = false;
    Style* style = getStyleByType(globalRenderInformation, getSpeciesReferenceGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, stroke);
        if (!setStrokeColor(style, stroke))
            stokeColorIsSet = true;
    }
    std::vector<std::pair<SpeciesReferenceRole_t, std::string>> styleRoles = getStyleRoles();
    for (unsigned int i = 0; i < styleRoles.size(); i++) {
        Style* style = getStyleByRole(globalRenderInformation, styleRoles[i].second);
        if (style) {
            addColor(globalRenderInformation, stroke);
            if (!setStrokeColor(style, stroke))
                stokeColorIsSet = true;
        }
    }

    return stokeColorIsSet ? 0 : -1;
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

bool isSetStrokeWidth(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeWidth(getGeometricShape(renderGroup)))
        return isSetStrokeWidth(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetStrokeWidth();

    return false;
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

const double getStrokeWidth(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeWidth(getGeometricShape(renderGroup)))
        return getStrokeWidth(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getStrokeWidth();

    return NAN;
}

const double getStrokeWidth(Transformation2D* transformation2D) {
    if (isGraphicalPrimitive1D(transformation2D))
        return ((GraphicalPrimitive1D*)transformation2D)->getStrokeWidth();

    return NAN;
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

int setStrokeWidth(RenderGroup* renderGroup, const double& strokeWidth) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeWidth(getGeometricShape(renderGroup)))
        return setStrokeWidth(getGeometricShape(renderGroup), strokeWidth);

    if (isRenderGroup(renderGroup) && isValidStrokeWidthValue(strokeWidth)) {
        renderGroup->setStrokeWidth(strokeWidth);
        return 0;
    }

    return -1;
}

int setStrokeWidth(Transformation2D* transformation2D, const double& strokeWidth) {
    if (isGraphicalPrimitive1D(transformation2D) && isValidStrokeWidthValue(strokeWidth)) {
        ((GraphicalPrimitive1D*)transformation2D)->setStrokeWidth(strokeWidth);
        return 0;
    }

    return -1;
}

const double getCompartmentStrokeWidth(GlobalRenderInformation* globalRenderInformation) {
    return getStrokeWidth(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()));
}

int setCompartmentStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth) {
    return setStrokeWidth(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()), strokeWidth);
}

const double getSpeciesStrokeWidth(GlobalRenderInformation* globalRenderInformation) {
    return getStrokeWidth(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()));
}

int setSpeciesStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth) {
    return setStrokeWidth(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()), strokeWidth);
}

const double getReactionStrokeWidth(GlobalRenderInformation* globalRenderInformation) {
    return getStrokeWidth(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()));
}

int setReactionStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth) {
    return setStrokeWidth(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()), strokeWidth);
}

int setSpeciesReferenceStrokeWidth(GlobalRenderInformation* globalRenderInformation, const double& strokeWidth) {
    bool stokeWidthIsSet = false;
    Style* style = getStyleByType(globalRenderInformation, getSpeciesReferenceGlyphStyleType());
    if (style) {
        if (!setStrokeWidth(style, strokeWidth))
            stokeWidthIsSet = true;
    }
    std::vector<std::pair<SpeciesReferenceRole_t, std::string>> styleRoles = getStyleRoles();
    for (unsigned int i = 0; i < styleRoles.size(); i++) {
        Style* style = getStyleByRole(globalRenderInformation, styleRoles[i].second);
        if (style) {
            if (!setStrokeWidth(style, strokeWidth))
                stokeWidthIsSet = true;
        }
    }

    return stokeWidthIsSet ? 0 : -1;
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

bool isSetStrokeDashArray(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeDashArray(getGeometricShape(renderGroup)))
        return isSetStrokeDashArray(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetStrokeDashArray();

    return false;
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

const std::vector<unsigned int> getStrokeDashArray(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeDashArray(getGeometricShape(renderGroup)))
        return getStrokeDashArray(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getStrokeDashArray();

    return std::vector<unsigned int>();
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
    if (getNumGeometricShapes(style) == 1)
        return setStrokeDashArray(getGeometricShape(style), strokeDashArray);

    return setStrokeDashArray(getRenderGroup(style), strokeDashArray);
}

int setStrokeDashArray(RenderGroup* renderGroup, const std::vector<unsigned int>& strokeDashArray) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeDashArray(getGeometricShape(renderGroup)))
        return setStrokeDashArray(getGeometricShape(renderGroup), strokeDashArray);

    if (isRenderGroup(renderGroup) && isValidStrokeDashArrayValue(strokeDashArray)) {
        renderGroup->setStrokeDashArray(strokeDashArray);
        return 0;
    }

    return -1;
}

int setStrokeDashArray(Transformation2D* transformation2D, const std::vector<unsigned int>& strokeDashArray) {
    if (isGraphicalPrimitive1D(transformation2D) && isValidStrokeDashArrayValue(strokeDashArray)) {
        ((GraphicalPrimitive1D*)transformation2D)->setStrokeDashArray(strokeDashArray);
        return 0;
    }

    return -1;
}

int setCompartmentStrokeDashArray(GlobalRenderInformation* globalRenderInformation, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()), strokeDashArray);
}

int setSpeciesStrokeDashArray(GlobalRenderInformation* globalRenderInformation, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()), strokeDashArray);
}

int setReactionStrokeDashArray(GlobalRenderInformation* globalRenderInformation, const std::vector<unsigned int>& strokeDashArray) {
    return setStrokeDashArray(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()), strokeDashArray);
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

unsigned int getNumStrokeDashes(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeDashArray(getGeometricShape(renderGroup)))
        return getNumStrokeDashes(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return getStrokeDashArray(renderGroup).size();

    return 0;
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
    return setStrokeDash(getRenderGroup(style), strokeDashIndex);
}

unsigned int getStrokeDash(RenderGroup* renderGroup, unsigned int strokeDashIndex) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeDashArray(getGeometricShape(renderGroup)))
        return getStrokeDash(getGeometricShape(renderGroup), strokeDashIndex);

    if (isRenderGroup(renderGroup))
        return renderGroup->getDashByIndex(strokeDashIndex);

    return NAN;
}

unsigned int getStrokeDash(Transformation2D* transformation2D, unsigned int strokeDashIndex) {
    if (isGraphicalPrimitive1D(transformation2D))
        ((GraphicalPrimitive1D*)transformation2D)->getDashByIndex(strokeDashIndex);

    return NAN;
}

int setStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int dash) {
    return setStrokeDash(renderInformationBase, graphicalObject, 0, dash);
}

int setStrokeDash(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getStyle(renderInformationBase, graphicalObject), strokeDashIndex, dash);
}

int setStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int dash) {
    return setStrokeDash(renderInformationBase, attribute, 0, dash);
}

int setStrokeDash(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getStyle(renderInformationBase, attribute), strokeDashIndex, dash);
}

int setStrokeDash(Style* style, unsigned int dash) {
    return setStrokeDash(style, 0, dash);
}

int setStrokeDash(Style* style, unsigned int strokeDashIndex, unsigned int dash) {
    return setStrokeDash(getRenderGroup(style), strokeDashIndex, dash);
}

int setStrokeDash(RenderGroup* renderGroup, unsigned int dash) {
    return setStrokeDash(renderGroup, 0, dash);
}

int setStrokeDash(RenderGroup* renderGroup, unsigned int strokeDashIndex, unsigned int dash) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStrokeDashArray(getGeometricShape(renderGroup)))
        return setStrokeDash(getGeometricShape(renderGroup), strokeDashIndex, dash);

    if (isRenderGroup(renderGroup) && isValidStrokeDashValue(dash)) {
        renderGroup->setDashByIndex(strokeDashIndex, dash);
        return 0;
    }

    return -1;
}

int setStrokeDash(Transformation2D* transformation2D, unsigned int dash) {
    return setStrokeDash(transformation2D, 0, dash);
}

int setStrokeDash(Transformation2D* transformation2D, unsigned int strokeDashIndex, unsigned int dash) {
    if (isGraphicalPrimitive1D(transformation2D) && isValidStrokeDashValue(dash)) {
        ((GraphicalPrimitive1D*)transformation2D)->setDashByIndex(strokeDashIndex, dash);
        return 0;
    }

    return -1;
}

int setCompartmentStrokeDash(GlobalRenderInformation* globalRenderInformation, unsigned int dash) {
    return setStrokeDash(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()), dash);
}

int setSpeciesStrokeDash(GlobalRenderInformation* globalRenderInformation, unsigned int dash) {
    return setStrokeDash(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()), dash);
}

int setReactionStrokeDash(GlobalRenderInformation* globalRenderInformation, unsigned int dash) {
    return setStrokeDash(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()), dash);
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

bool isSetFontColor(RenderGroup* renderGroup) {
    return isSetStrokeColor(renderGroup);
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

const std::string getFontColor(RenderGroup* renderGroup) {
    return getStrokeColor(renderGroup);
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

int setFontColor(RenderGroup* renderGroup, const std::string& fontColor) {
    return setStrokeColor(renderGroup, fontColor);
}

int setFontColor(Transformation2D* transformation2D, const std::string& fontColor) {
    if (isValidFontColorValue(fontColor))
        return setStrokeColor(transformation2D, fontColor);

    return -1;
}

const std::string getCompartmentFontColor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getFontColor(style);

    return "";
}

int setCompartmentFontColor(GlobalRenderInformation* globalRenderInformation, const std::string& fontColor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, fontColor);
        return setFontColor(style, fontColor);
    }

    return -1;
}

const std::string getSpeciesFontColor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getFontColor(style);

    return "";
}

int setSpeciesFontColor(GlobalRenderInformation* globalRenderInformation, const std::string& fontColor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, fontColor);
        return setFontColor(style, fontColor);
    }

    return -1;
}

const std::string getReactionFontColor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getFontColor(style);

    return "";
}

int setReactionFontColor(GlobalRenderInformation* globalRenderInformation, const std::string& fontColor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, fontColor);
        return setFontColor(style, fontColor);
    }

    return -1;
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

bool isSetFontFamily(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontFamily(getGeometricShape(renderGroup)))
        return isSetFontFamily(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetFontFamily();

    return false;
}

bool isSetFontFamily(Transformation2D* transformation2D) {
    if (isText(transformation2D))
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

const std::string getFontFamily(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontFamily(getGeometricShape(renderGroup)))
        return getFontFamily(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getFontFamily();

    return "";
}

const std::string getFontFamily(Transformation2D* transformation2D) {
    if (isText(transformation2D))
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

int setFontFamily(RenderGroup* renderGroup, const std::string& fontFamily) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontFamily(getGeometricShape(renderGroup)))
        return setFontFamily(getGeometricShape(renderGroup), fontFamily);

    if (isRenderGroup(renderGroup) && isValidFontFamilyValue(fontFamily)) {
        renderGroup->setFontFamily(fontFamily);
        return 0;
    }

    return -1;
}

int setFontFamily(Transformation2D* transformation2D, const std::string& fontFamily) {
    if (isText(transformation2D) && isValidFontFamilyValue(fontFamily)) {
        ((Text*)transformation2D)->setFontFamily(fontFamily);
        return 0;
    }

    return -1;
}

const std::string getCompartmentFontFamily(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getFontFamily(style);

    return "";
}

int setCompartmentFontFamily(GlobalRenderInformation* globalRenderInformation, const std::string& fontFamily) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setFontFamily(style, fontFamily);

    return -1;
}

const std::string getSpeciesFontFamily(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getFontFamily(style);

    return "";
}

int setSpeciesFontFamily(GlobalRenderInformation* globalRenderInformation, const std::string& fontFamily) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setFontFamily(style, fontFamily);

    return -1;
}

const std::string getReactionFontFamily(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getFontFamily(style);

    return "";
}

int setReactionFontFamily(GlobalRenderInformation* globalRenderInformation, const std::string& fontFamily) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setFontFamily(style, fontFamily);

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

bool isSetFontSize(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontSize(getGeometricShape(renderGroup)))
        return isSetFontSize(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetFontSize();

    return false;
}

bool isSetFontSize(Transformation2D* transformation2D) {
    if (isText(transformation2D))
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

const RelAbsVector getFontSize(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontSize(getGeometricShape(renderGroup)))
        return getFontSize(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getFontSize();

    return RelAbsVector(NAN, NAN);
}

const RelAbsVector getFontSize(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->getFontSize();

    return RelAbsVector(NAN, NAN);
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

int setFontSize(RenderGroup* renderGroup, const RelAbsVector& fontSize) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontSize(getGeometricShape(renderGroup)))
        return setFontSize(getGeometricShape(renderGroup), fontSize);

    if (isRenderGroup(renderGroup) && isValidFontSizeValue(fontSize)) {
        renderGroup->setFontSize(fontSize);
        return 0;
    }

    return -1;
}

int setFontSize(Transformation2D* transformation2D, const RelAbsVector& fontSize) {
    if (isText(transformation2D) && isValidFontSizeValue(fontSize)) {
        ((Text*)transformation2D)->setFontSize(fontSize);
        return 0;
    }

    return -1;
}

int setFontSizeAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& fontSize) {
    return setFontSizeAsDouble(getStyle(renderInformationBase, graphicalObject), fontSize);
}

int setFontSizeAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& fontSize) {
    return setFontSizeAsDouble(getStyle(renderInformationBase, attribute), fontSize);
}

int setFontSizeAsDouble(Style* style, const double& fontSize) {
    return setFontSizeAsDouble(getRenderGroup(style), fontSize);
}

int setFontSizeAsDouble(RenderGroup* renderGroup, const double& fontSize) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontSize(getGeometricShape(renderGroup)))
        return setFontSizeAsDouble(getGeometricShape(renderGroup), fontSize);

    if (isRenderGroup(renderGroup)) {
        RelAbsVector fontSizeRelAbs;
        fontSizeRelAbs.setAbsoluteValue(fontSize);
        return setFontSize(renderGroup, fontSizeRelAbs);
    }

    return -1;
}

int setFontSizeAsDouble(Transformation2D* transformation2D, const double& fontSize) {
    RelAbsVector fontSizeRelAbs;
    fontSizeRelAbs.setAbsoluteValue(fontSize);
    return setFontSize(transformation2D, fontSizeRelAbs);
}

const RelAbsVector getCompartmentFontSize(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getFontSize(style);

    return RelAbsVector(NAN, NAN);
}

int setCompartmentFontSize(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& fontSize) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setFontSize(style, fontSize);

    return -1;
}

const double getCompartmentFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentFontSize(globalRenderInformation));
}

int setCompartmentFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation, const double& fontSize) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setFontSizeAsDouble(style, fontSize);

    return -1;
}

const RelAbsVector getSpeciesFontSize(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getFontSize(style);

    return RelAbsVector(NAN, NAN);
}

int setSpeciesFontSize(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& fontSize) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setFontSize(style, fontSize);

    return -1;
}

const double getSpeciesFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesFontSize(globalRenderInformation));
}

int setSpeciesFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation, const double& fontSize) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setFontSizeAsDouble(style, fontSize);

    return -1;
}

const RelAbsVector getReactionFontSize(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getFontSize(style);

    return RelAbsVector(NAN, NAN);
}

int setReactionFontSize(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& fontSize) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setFontSize(style, fontSize);

    return -1;
}

const double getReactionFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionFontSize(globalRenderInformation));
}

int setReactionFontSizeAsDouble(GlobalRenderInformation* globalRenderInformation, const double& fontSize) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setFontSizeAsDouble(style, fontSize);

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

bool isSetFontWeight(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontWeight(getGeometricShape(renderGroup)))
        return isSetFontWeight(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetFontWeight();

    return false;
}

bool isSetFontWeight(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->isSetFontWeight();

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

const std::string getFontWeight(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontWeight(getGeometricShape(renderGroup)))
        return getFontWeight(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getFontWeightAsString();

    return "";
}

const std::string getFontWeight(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->getFontWeightAsString();

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

int setFontWeight(RenderGroup* renderGroup, const std::string& fontWeight) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontWeight(getGeometricShape(renderGroup)))
        return setFontWeight(getGeometricShape(renderGroup), fontWeight);

    if (isRenderGroup(renderGroup) && isValidFontWeightValue(fontWeight)) {
        renderGroup->setFontWeight(fontWeight);
        return 0;
    }

    return -1;
}

int setFontWeight(Transformation2D* transformation2D, const std::string& fontWeight) {
    if (isText(transformation2D) && isValidFontWeightValue(fontWeight)) {
        ((Text*)transformation2D)->setFontWeight(fontWeight);
        return 0;
    }

    return -1;
}

const std::string getCompartmentFontWeight(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getFontWeight(style);

    return "";
}

int setCompartmentFontWeight(GlobalRenderInformation* globalRenderInformation, const std::string& fontWeight) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setFontWeight(style, fontWeight);

    return -1;
}

const std::string getSpeciesFontWeight(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getFontWeight(style);

    return "";
}

int setSpeciesFontWeight(GlobalRenderInformation* globalRenderInformation, const std::string& fontWeight) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setFontWeight(style, fontWeight);

    return -1;
}

const std::string getReactionFontWeight(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getFontWeight(style);

    return "";
}

int setReactionFontWeight(GlobalRenderInformation* globalRenderInformation, const std::string& fontWeight) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setFontWeight(style, fontWeight);

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

bool isSetFontStyle(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontStyle(getGeometricShape(renderGroup)))
        return isSetFontStyle(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetFontStyle();

    return false;
}

bool isSetFontStyle(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->isSetFontStyle();

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

const std::string getFontStyle(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontStyle(getGeometricShape(renderGroup)))
        return getFontStyle(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getFontStyleAsString();

    return "";
}

const std::string getFontStyle(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->getFontStyleAsString();

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

int setFontStyle(RenderGroup* renderGroup, const std::string& fontStyle) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFontStyle(getGeometricShape(renderGroup)))
        return setFontStyle(getGeometricShape(renderGroup), fontStyle);

    if (isRenderGroup(renderGroup) && isValidFontStyleValue(fontStyle)) {
        renderGroup->setFontStyle(fontStyle);
        return 0;
    }

    return -1;
}

int setFontStyle(Transformation2D* transformation2D, const std::string& fontStyle) {
    if (isText(transformation2D) && isValidFontStyleValue(fontStyle)) {
        ((Text*)transformation2D)->setFontStyle(fontStyle);
        return 0;
    }

    return -1;
}

const std::string getCompartmentFontStyle(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getFontStyle(style);

    return "";
}

int setCompartmentFontStyle(GlobalRenderInformation* globalRenderInformation, const std::string& fontStyle) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setFontStyle(style, fontStyle);

    return -1;
}

const std::string getSpeciesFontStyle(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getFontStyle(style);

    return "";
}

int setSpeciesFontStyle(GlobalRenderInformation* globalRenderInformation, const std::string& fontStyle) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setFontStyle(style, fontStyle);

    return -1;
}

const std::string getReactionFontStyle(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getFontStyle(style);

    return "";
}

int setReactionFontStyle(GlobalRenderInformation* globalRenderInformation, const std::string& fontStyle) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setFontStyle(style, fontStyle);

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

bool isSetTextAnchor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetTextAnchor(getGeometricShape(renderGroup)))
        return isSetTextAnchor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetTextAnchor();

    return false;
}

bool isSetTextAnchor(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->isSetTextAnchor();

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

const std::string getTextAnchor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetTextAnchor(getGeometricShape(renderGroup)))
        return getTextAnchor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getTextAnchorAsString();

    return "";
}

const std::string getTextAnchor(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->getTextAnchorAsString();

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

int setTextAnchor(RenderGroup* renderGroup, const std::string& textAnchor) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetTextAnchor(getGeometricShape(renderGroup)))
        return setTextAnchor(getGeometricShape(renderGroup), textAnchor);

    if (isRenderGroup(renderGroup) && isValidTextAnchorValue(textAnchor)) {
        renderGroup->setTextAnchor(textAnchor);
        return 0;
    }

    return -1;
}

int setTextAnchor(Transformation2D* transformation2D, const std::string& textAnchor) {
    if (isText(transformation2D) && isValidTextAnchorValue(textAnchor)) {
        ((Text*)transformation2D)->setTextAnchor(textAnchor);
        return 0;
    }

    return -1;
}

const std::string getCompartmentTextAnchor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getTextAnchor(style);

    return "";
}

int setCompartmentTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& textAnchor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setTextAnchor(style, textAnchor);

    return -1;
}

const std::string getSpeciesTextAnchor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getTextAnchor(style);

    return "";
}

int setSpeciesTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& textAnchor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setTextAnchor(style, textAnchor);

    return -1;
}

const std::string getReactionTextAnchor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getTextAnchor(style);

    return "";
}

int setReactionTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& textAnchor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setTextAnchor(style, textAnchor);

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

bool isSetVTextAnchor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetVTextAnchor(getGeometricShape(renderGroup)))
        return isSetVTextAnchor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetVTextAnchor();

    return false;
}

bool isSetVTextAnchor(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->isSetVTextAnchor();

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

const std::string getVTextAnchor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetVTextAnchor(getGeometricShape(renderGroup)))
        return getVTextAnchor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getVTextAnchorAsString();

    return "";
}

const std::string getVTextAnchor(Transformation2D* transformation2D) {
    if (isText(transformation2D))
        return ((Text*)transformation2D)->getVTextAnchorAsString();

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

int setVTextAnchor(RenderGroup* renderGroup, const std::string& vtextAnchor) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetVTextAnchor(getGeometricShape(renderGroup)))
        return setVTextAnchor(getGeometricShape(renderGroup), vtextAnchor);

    if (isRenderGroup(renderGroup) && isValidVTextAnchorValue(vtextAnchor)) {
        renderGroup->setVTextAnchor(vtextAnchor);
        return 0;
    }

    return -1;
}

int setVTextAnchor(Transformation2D* transformation2D, const std::string& vtextAnchor) {
    if (isText(transformation2D) && isValidVTextAnchorValue(vtextAnchor)) {
        ((Text*)transformation2D)->setVTextAnchor(vtextAnchor);
        return 0;
    }

    return -1;
}

const std::string getCompartmentVTextAnchor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return getVTextAnchor(style);

    return "";
}

int setCompartmentVTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& vtextAnchor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setVTextAnchor(style, vtextAnchor);

    return -1;
}

const std::string getSpeciesVTextAnchor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return getVTextAnchor(style);

    return "";
}

int setSpeciesVTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& vtextAnchor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setVTextAnchor(style, vtextAnchor);

    return -1;
}

const std::string getReactionVTextAnchor(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return getVTextAnchor(style);

    return "";
}

int setReactionVTextAnchor(GlobalRenderInformation* globalRenderInformation, const std::string& vtextAnchor) {
    Style* style = getStyleByType(globalRenderInformation, getTextGlyphStyleType());
    if (!style)
        style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setVTextAnchor(style, vtextAnchor);

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

bool isSetFillColor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillColor(getGeometricShape(renderGroup)))
        return isSetFillColor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetFill();

    return false;
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

const std::string getFillColor(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillColor(getGeometricShape(renderGroup)))
        return getFillColor(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getFill();

    return "";
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

int setFillColor(RenderGroup* renderGroup, const std::string& fillColor) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillColor(getGeometricShape(renderGroup)))
        return setFillColor(getGeometricShape(renderGroup), fillColor);

    if (isRenderGroup(renderGroup) && isValidFillColorValue(fillColor)) {
        renderGroup->setFill(fillColor);
        return 0;
    }

    return -1;
}

int setFillColor(Transformation2D* transformation2D, const std::string& fillColor) {
    if (isGraphicalPrimitive2D(transformation2D) && isValidFillColorValue(fillColor)) {
        ((GraphicalPrimitive2D*)transformation2D)->setFill(fillColor);
        return 0;
    }

    return -1;
}

int setFillColorAsGradient(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, std::string& gradientId) {
    if (renderInformationBase && renderInformationBase->getGradientDefinition(gradientId)) {
        return setFillColor(getStyle(renderInformationBase, graphicalObject), gradientId);
    }

    return -1;
}

int setFillColorAsGradient(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& gradientId) {
    if (renderInformationBase && renderInformationBase->getGradientDefinition(gradientId)) {
        return setFillColor(getStyle(renderInformationBase, attribute), gradientId);
    }

    return -1;
}

int setFillColorAsGradient(Style* style, const std::string& gradientId) {
    return setFillColorAsGradient(getRenderGroup(style), gradientId);
}

int setFillColorAsGradient(RenderGroup* renderGroup, const std::string& gradientId) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillColor(getGeometricShape(renderGroup)))
        return setFillColorAsGradient(getGeometricShape(renderGroup), gradientId);

    if (isRenderGroup(renderGroup)) {
        renderGroup->setFill(gradientId);
        return 0;
    }

    return -1;
}

int setFillColorAsGradient(Transformation2D* transformation2D, const std::string& gradientId) {
    if (isGraphicalPrimitive2D(transformation2D)) {
        ((GraphicalPrimitive2D *) transformation2D)->setFill(gradientId);
        return 0;
    }

    return -1;
}

const std::string getCompartmentFillColor(GlobalRenderInformation* globalRenderInformation) {
    return getFillColor(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()));
}

int setCompartmentFillColor(GlobalRenderInformation* globalRenderInformation, const std::string& fillColor) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, fillColor);
        return setFillColor(style, fillColor);
    }

    return -1;
}

int setCompartmentFillColorAsGradient(GlobalRenderInformation* globalRenderInformation, const std::string& gradientId) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (globalRenderInformation->getGradientDefinition(gradientId)) {
            return setFillColorAsGradient(style, gradientId);
        }
    }

    return -1;
}

const std::string getSpeciesFillColor(GlobalRenderInformation* globalRenderInformation) {
    return getFillColor(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()));
}

int setSpeciesFillColor(GlobalRenderInformation* globalRenderInformation, const std::string& fillColor) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, fillColor);
        return setFillColor(style, fillColor);
    }

    return -1;
}

int setSpeciesFillColorAsGradient(GlobalRenderInformation* globalRenderInformation, const std::string& gradientId) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (globalRenderInformation->getGradientDefinition(gradientId)) {
            return setFillColorAsGradient(style, gradientId);
        }
    }

    return -1;
}

const std::string getReactionFillColor(GlobalRenderInformation* globalRenderInformation) {
    return getFillColor(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()));
}

int setReactionFillColor(GlobalRenderInformation* globalRenderInformation, const std::string& fillColor) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        addColor(globalRenderInformation, fillColor);
        return setFillColor(style, fillColor);
    }

    return -1;
}

int setReactionFillColorAsGradient(GlobalRenderInformation* globalRenderInformation, const std::string& gradientId) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (globalRenderInformation->getGradientDefinition(gradientId)) {
            return setFillColorAsGradient(style, gradientId);
        }
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

bool isSetFillRule(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillRule(getGeometricShape(renderGroup)))
        return isSetFillRule(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetFillRule();

    return false;
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

const std::string getFillRule(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillRule(getGeometricShape(renderGroup)))
        return getFillRule(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getFillRuleAsString();

    return "";
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

int setFillRule(RenderGroup* renderGroup, const std::string& fillRule) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetFillRule(getGeometricShape(renderGroup)))
        return setFillRule(getGeometricShape(renderGroup), fillRule);

    if (isRenderGroup(renderGroup) && isValidFillRuleValue(fillRule)) {
        renderGroup->setFillRule(fillRule);
        return 0;
    }

    return -1;
}

int setFillRule(Transformation2D* transformation2D, const std::string& fillRule) {
    if (isGraphicalPrimitive2D(transformation2D) && isValidFillRuleValue(fillRule)) {
        ((GraphicalPrimitive2D*)transformation2D)->setFillRule(fillRule);
        return 0;
    }

    return -1;
}

const std::string getCompartmentFillRule(GlobalRenderInformation* globalRenderInformation) {
    return getFillRule(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()));
}

int setCompartmentFillRule(GlobalRenderInformation* globalRenderInformation, const std::string& fillRule) {
    return setFillRule(getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType()), fillRule);
}

const std::string getSpeciesFillRule(GlobalRenderInformation* globalRenderInformation) {
    return getFillRule(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()));
}

int setSpeciesFillRule(GlobalRenderInformation* globalRenderInformation, const std::string& fillRule) {
    return setFillRule(getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType()), fillRule);
}

const std::string getReactionFillRule(GlobalRenderInformation* globalRenderInformation) {
    return getFillRule(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()));
}

int setReactionFillRule(GlobalRenderInformation* globalRenderInformation, const std::string& fillRule) {
    return setFillRule(getStyleByType(globalRenderInformation, getReactionGlyphStyleType()), fillRule);
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
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStartHead(getGeometricShape(renderGroup)))
        return isSetStartHead(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetStartHead();

    return false;
}

bool isSetStartHead(Transformation2D* transformation2D) {
    if (isRenderCurve(transformation2D))
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

const std::string getStartHead(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStartHead(getGeometricShape(renderGroup)))
        return getStartHead(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getStartHead();

    return "";
}

const std::string getStartHead(Transformation2D* transformation2D) {
    if (isRenderCurve(transformation2D))
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

int setStartHead(RenderGroup* renderGroup, const std::string& startHead) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetStartHead(getGeometricShape(renderGroup)))
        return setStartHead(getGeometricShape(renderGroup), startHead);

    if (isRenderGroup(renderGroup) && isValidStartHeadValue(startHead)) {
        renderGroup->setStartHead(startHead);
        return 0;
    }

    return -1;
}

int setStartHead(Transformation2D* transformation2D, const std::string startHead) {
    if (isRenderCurve(transformation2D) && isValidStartHeadValue(startHead)) {
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

bool isSetEndHead(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetEndHead(getGeometricShape(renderGroup)))
        return isSetEndHead(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->isSetEndHead();

    return false;
}

bool isSetEndHead(Transformation2D* transformation2D) {
    if (isRenderCurve(transformation2D))
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

const std::string getEndHead(RenderGroup* renderGroup) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetEndHead(getGeometricShape(renderGroup)))
        return getEndHead(getGeometricShape(renderGroup));

    if (isRenderGroup(renderGroup))
        return renderGroup->getEndHead();

    return "";
}

const std::string getEndHead(Transformation2D* transformation2D) {
    if (isRenderCurve(transformation2D))
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

int setEndHead(RenderGroup* renderGroup, const std::string& endHead) {
    if (getNumGeometricShapes(renderGroup) == 1 && isSetEndHead(getGeometricShape(renderGroup)))
        return setEndHead(getGeometricShape(renderGroup), endHead);

    if (isRenderGroup(renderGroup) && isValidEndHeadValue(endHead)) {
        renderGroup->setEndHead(endHead);
        return 0;
    }

    return -1;
}

int setEndHead(Transformation2D* transformation2D, const std::string endHead) {
    if (isRenderCurve(transformation2D) && isValidEndHeadValue(endHead)) {
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

    return -1;
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
        Transformation2D* shapeObject = NULL;
        if (stringCompare(shape, "square")) {
            shapeObject = renderGroup->createRectangle();
            setDefaultSquareShapeFeatures((Rectangle*)shapeObject);
        }
        else if (stringCompare(shape, "rectangle")) {
            shapeObject = renderGroup->createRectangle();
            setDefaultRectangleShapeFeatures((Rectangle*)shapeObject);
        }
        else if (stringCompare(shape, "circle")) {
            shapeObject = renderGroup->createEllipse();
            setDefaultCircleShapeFeatures((Ellipse*)shapeObject);
        }
        else if (stringCompare(shape, "ellipse")) {
            shapeObject = renderGroup->createEllipse();
            setDefaultEllipseShapeFeatures((Ellipse*)shapeObject);
        }
        else if (stringCompare(shape, "triangle")) {
            shapeObject = renderGroup->createPolygon();
            setDefaultTriangleShapeFeatures((Polygon*)shapeObject);
        }
        else if (stringCompare(shape, "diamond")) {
            shapeObject = renderGroup->createPolygon();
            setDefaultDiamondShapeFeatures((Polygon*)shapeObject);
        }
        else if (stringCompare(shape, "pentagon")) {
            shapeObject = renderGroup->createPolygon();
            setDefaultPentagonShapeFeatures((Polygon*)shapeObject);
        }
        else if (stringCompare(shape, "hexagon")) {
            shapeObject = renderGroup->createPolygon();
            setDefaultHexagonShapeFeatures((Polygon*)shapeObject);
        }
        else if (stringCompare(shape, "octagon")) {
            shapeObject = renderGroup->createPolygon();
            setDefaultOctagonShapeFeatures((Polygon*)shapeObject);
        }
        else if (stringCompare(shape, "rendercurve")) {
            shapeObject = renderGroup->createCurve();
            setDefaultRenderCurveShapeFeatures((RenderCurve*)shapeObject);
        }
        else if (stringCompare(shape, "image")) {
            shapeObject = renderGroup->createImage();
            setDefaultImageShapeFeatures((Image*)shapeObject);
        }

        if (shapeObject) {
            if (renderGroup->getNumElements() == 2)
                unifyGeometricShapeMutualFeatures(renderGroup);
            return 0;
        }
    }

    return -1;
}

int removeGeometricShape(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

int removeGeometricShape(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

int removeGeometricShape(Style* style, unsigned int geometricShapeIndex) {
    return removeGeometricShape(getRenderGroup(style), geometricShapeIndex);
}

int removeGeometricShape(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    if (renderGroup) {
        renderGroup->removeElement(geometricShapeIndex);
        return 0;
    }

    return -1;
}

const std::string getGeometricShapeType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeType(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const std::string getGeometricShapeType(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeType(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const std::string getGeometricShapeType(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeType(getRenderGroup(style), geometricShapeIndex);
}

const std::string getGeometricShapeType(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeType(getGeometricShape(renderGroup, geometricShapeIndex));
}

const std::string getGeometricShapeType(Transformation2D* shape) {
    if (isSquare(shape))
        return "square";
    else if (isRectangle(shape))
        return "rectangle";
    else if (isCircle(shape))
        return "circle";
    else if (isEllipse(shape))
        return "ellipse";
    else if (isTriangle(shape))
        return "triangle";
    else if (isDiamond(shape))
        return "diamond";
    else if (isPentagon(shape))
        return "pentagon";
    else if (isHexagon(shape))
        return "hexagon";
    else if (isOctagon(shape))
        return "octagon";
    else if (isPolygon(shape))
        return "polygon";
    else if (isRenderCurve(shape))
        return "rendercurve";
    else if (isImage(shape))
        return "image";

    return "";
}

int setGeometricShapeType(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& shape) {
    return setGeometricShapeType(getStyle(renderInformationBase, graphicalObject), shape);
}

int setGeometricShapeType(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& shape) {
    return setGeometricShapeType(getStyle(renderInformationBase, attribute), shape);
}

int setGeometricShapeType(Style* style, const std::string& shape) {
    return setGeometricShapeType(getRenderGroup(style), shape);
}

int setGeometricShapeType(RenderGroup* renderGroup, const std::string& shape) {
    if (getNumGeometricShapes(renderGroup) && isValidGeometricShapeName(shape)) {
        if (!addGeometricShape(renderGroup, shape)) {
            while (getNumGeometricShapes(renderGroup) > 1)
                removeGeometricShape(renderGroup, 0);

            return 0;
        }
    }

    return -1;
}

const std::string getCompartmentGeometricShapeType(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeType(getGeometricShape(style)).empty())
            return getGeometricShapeType(getGeometricShape(style));

        return getGeometricShapeType(style);
    }

    return "";
}

int setCompartmentGeometricShapeType(GlobalRenderInformation* globalRenderInformation, const std::string& shape) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeType(style, shape);

    return -1;
}

const std::string getSpeciesGeometricShapeType(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeType(getGeometricShape(style)).empty())
            return getGeometricShapeType(getGeometricShape(style));

        return getGeometricShapeType(style);
    }

    return "";
}

int setSpeciesGeometricShapeType(GlobalRenderInformation* globalRenderInformation, const std::string& shape) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeType(style, shape);

    return -1;
}

const std::string getReactionGeometricShapeType(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeType(getGeometricShape(style)).empty())
            return getGeometricShapeType(getGeometricShape(style));

        return getGeometricShapeType(style);
    }

    return "";
}

int setReactionGeometricShapeType(GlobalRenderInformation* globalRenderInformation, const std::string& shape) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeType(style, shape);

    return -1;
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

bool isSquare(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSquare(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSquare(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSquare(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSquare(Style* style, unsigned int geometricShapeIndex) {
    return isSquare(getRenderGroup(style), geometricShapeIndex);
}

bool isSquare(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSquare(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSquare(Transformation2D* shape) {
    if (shape)
        return isRectangle(shape) && ((Rectangle*)shape)->getRatio() == 1.0;

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

bool isCircle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isCircle(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isCircle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isCircle(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isCircle(Style* style, unsigned int geometricShapeIndex) {
    return isCircle(getRenderGroup(style), geometricShapeIndex);
}

bool isCircle(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isCircle(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isCircle(Transformation2D* shape) {
    if (shape)
        return isEllipse(shape) && ((Ellipse*)shape)->getRatio() == 1.0;

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

bool isTriangle(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isTriangle(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isTriangle(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isTriangle(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isTriangle(Style* style, unsigned int geometricShapeIndex) {
    return isTriangle(getRenderGroup(style), geometricShapeIndex);
}

bool isTriangle(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isTriangle(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isTriangle(Transformation2D* shape) {
    if (shape)
        return isPolygon(shape) && getGeometricShapeNumElements(shape) == 3;

    return false;
}

bool isDiamond(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isDiamond(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isDiamond(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isDiamond(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isDiamond(Style* style, unsigned int geometricShapeIndex) {
    return isDiamond(getRenderGroup(style), geometricShapeIndex);
}

bool isDiamond(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isDiamond(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isDiamond(Transformation2D* shape) {
    if (shape)
        return isPolygon(shape) && getGeometricShapeNumElements(shape) == 4;

    return false;
}

bool isPentagon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isPentagon(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isPentagon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isPentagon(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isPentagon(Style* style, unsigned int geometricShapeIndex) {
    return isPentagon(getRenderGroup(style), geometricShapeIndex);
}

bool isPentagon(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isPentagon(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isPentagon(Transformation2D* shape) {
    if (shape)
        return isPolygon(shape) && getGeometricShapeNumElements(shape) == 5;

    return false;
}

bool isHexagon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isHexagon(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isHexagon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isHexagon(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isHexagon(Style* style, unsigned int geometricShapeIndex) {
    return isHexagon(getRenderGroup(style), geometricShapeIndex);
}

bool isHexagon(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isHexagon(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isHexagon(Transformation2D* shape) {
    if (shape)
        return isPolygon(shape) && getGeometricShapeNumElements(shape) == 6;

    return false;
}

bool isOctagon(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isOctagon(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isOctagon(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isOctagon(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isOctagon(Style* style, unsigned int geometricShapeIndex) {
    return isOctagon(getRenderGroup(style), geometricShapeIndex);
}

bool isOctagon(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isOctagon(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isOctagon(Transformation2D* shape) {
    if (shape)
        return isPolygon(shape) && getGeometricShapeNumElements(shape) == 8;

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

bool isSetGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeColor(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeColor(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeStrokeColor(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeColor(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeStrokeColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeColor(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeStrokeColor(Transformation2D* shape) {
    if (isGraphicalPrimitive1D(shape))
        return ((GraphicalPrimitive1D*)shape)->isSetStroke();

    return false;
}

const std::string getGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeColor(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const std::string getGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeColor(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const std::string getGeometricShapeStrokeColor(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeColor(getRenderGroup(style), geometricShapeIndex);
}

const std::string getGeometricShapeStrokeColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeColor(getGeometricShape(renderGroup, geometricShapeIndex));
}

const std::string getGeometricShapeStrokeColor(Transformation2D* shape) {
    if (isGraphicalPrimitive1D(shape))
        return ((GraphicalPrimitive1D*)shape)->getStroke();

    return "";
}

int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(renderInformationBase, graphicalObject, 0, strokeColor);
}

int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, strokeColor);
}

int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(renderInformationBase, attribute, 0, strokeColor);
}

int setGeometricShapeStrokeColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(getStyle(renderInformationBase, attribute), geometricShapeIndex, strokeColor);
}

int setGeometricShapeStrokeColor(Style* style, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(style, 0, strokeColor);
}

int setGeometricShapeStrokeColor(Style* style, unsigned int geometricShapeIndex, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(getRenderGroup(style), geometricShapeIndex, strokeColor);
}

int setGeometricShapeStrokeColor(RenderGroup* renderGroup, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(renderGroup, 0, strokeColor);
}

int setGeometricShapeStrokeColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& strokeColor) {
    return setGeometricShapeStrokeColor(getGeometricShape(renderGroup, geometricShapeIndex), strokeColor);
}

int setGeometricShapeStrokeColor(Transformation2D* shape, const std::string& strokeColor) {
    if (isValidColorValue(strokeColor)) {
        if (isGraphicalPrimitive1D(shape)) {
            ((GraphicalPrimitive1D*)shape)->setStroke(strokeColor);
            return 0;
        }
    }

    return -1;
}

bool isSetGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeWidth(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeWidth(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeStrokeWidth(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeWidth(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeStrokeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeStrokeWidth(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeStrokeWidth(Transformation2D* shape) {
    if (isGraphicalPrimitive1D(shape))
        return ((GraphicalPrimitive1D*)shape)->isSetStrokeWidth();

    return false;
}

const double getGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeWidth(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const double getGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeWidth(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const double getGeometricShapeStrokeWidth(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeWidth(getRenderGroup(style), geometricShapeIndex);
}

const double getGeometricShapeStrokeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeStrokeWidth(getGeometricShape(renderGroup, geometricShapeIndex));
}

const double getGeometricShapeStrokeWidth(Transformation2D* shape) {
    if (isGraphicalPrimitive1D(shape))
        return ((GraphicalPrimitive1D*)shape)->getStrokeWidth();

    return -1;
}

int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(renderInformationBase, graphicalObject, 0, strokeWidth);
}

int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, strokeWidth);
}

int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(renderInformationBase, attribute, 0, strokeWidth);
}

int setGeometricShapeStrokeWidth(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(getStyle(renderInformationBase, attribute), geometricShapeIndex, strokeWidth);
}

int setGeometricShapeStrokeWidth(Style* style, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(style, 0, strokeWidth);
}

int setGeometricShapeStrokeWidth(Style* style, unsigned int geometricShapeIndex, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(getRenderGroup(style), geometricShapeIndex, strokeWidth);
}

int setGeometricShapeStrokeWidth(RenderGroup* renderGroup, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(renderGroup, 0, strokeWidth);
}

int setGeometricShapeStrokeWidth(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& strokeWidth) {
    return setGeometricShapeStrokeWidth(getGeometricShape(renderGroup, geometricShapeIndex), strokeWidth);
}

int setGeometricShapeStrokeWidth(Transformation2D* shape, const double& strokeWidth) {
    if (isGraphicalPrimitive1D(shape)) {
        ((GraphicalPrimitive1D*)shape)->setStrokeWidth(strokeWidth);
        return 0;
    }

    return -1;
}

bool isSetGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeFillColor(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeFillColor(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeFillColor(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeFillColor(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeFillColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeFillColor(getGeometricShape(renderGroup, geometricShapeIndex));
}

bool isSetGeometricShapeFillColor(Transformation2D* shape) {
    if (isGraphicalPrimitive2D(shape))
        return ((GraphicalPrimitive2D*)shape)->isSetFillColor();

    return false;
}

const std::string getGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return getGeometricShapeFillColor(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

const std::string getGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return getGeometricShapeFillColor(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

const std::string getGeometricShapeFillColor(Style* style, unsigned int geometricShapeIndex) {
    return getGeometricShapeFillColor(getRenderGroup(style), geometricShapeIndex);
}

const std::string getGeometricShapeFillColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return getGeometricShapeFillColor(getGeometricShape(renderGroup, geometricShapeIndex));
}

const std::string getGeometricShapeFillColor(Transformation2D* shape) {
    if (isGraphicalPrimitive2D(shape))
        return ((GraphicalPrimitive2D*)shape)->getFillColor();

    return "";
}

int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& fillColor) {
    return setGeometricShapeFillColor(renderInformationBase, graphicalObject, 0, fillColor);
}

int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& fillColor) {
    return setGeometricShapeFillColor(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, fillColor);
}

int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& fillColor) {
    return setGeometricShapeFillColor(renderInformationBase, attribute, 0, fillColor);
}

int setGeometricShapeFillColor(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& fillColor) {
    return setGeometricShapeFillColor(getStyle(renderInformationBase, attribute), geometricShapeIndex, fillColor);
}

int setGeometricShapeFillColor(Style* style, const std::string& fillColor) {
    return setGeometricShapeFillColor(style, 0, fillColor);
}

int setGeometricShapeFillColor(Style* style, unsigned int geometricShapeIndex, const std::string& fillColor) {
    return setGeometricShapeFillColor(getRenderGroup(style), geometricShapeIndex, fillColor);
}

int setGeometricShapeFillColor(RenderGroup* renderGroup, const std::string& fillColor) {
    return setGeometricShapeFillColor(renderGroup, 0, fillColor);
}

int setGeometricShapeFillColor(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& fillColor) {
    return setGeometricShapeFillColor(getGeometricShape(renderGroup, geometricShapeIndex), fillColor);
}

int setGeometricShapeFillColor(Transformation2D* shape, const std::string& fillColor) {
    if (isValidColorValue(fillColor)) {
        if (isGraphicalPrimitive2D(shape)) {
            ((GraphicalPrimitive2D*)shape)->setFillColor(fillColor);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(renderInformationBase, graphicalObject, 0, gradientId);
}

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, gradientId);
}

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, const std::string& attribute, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(renderInformationBase, attribute, 0, gradientId);
}

int setGeometricShapeFillColorAsGradient(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(getStyle(renderInformationBase, attribute), geometricShapeIndex, gradientId);
}

int setGeometricShapeFillColorAsGradient(Style* style, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(style, 0, gradientId);
}

int setGeometricShapeFillColorAsGradient(Style* style, unsigned int geometricShapeIndex, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(getRenderGroup(style), geometricShapeIndex, gradientId);
}

int setGeometricShapeFillColorAsGradient(RenderGroup* renderGroup, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(renderGroup, 0, gradientId);
}

int setGeometricShapeFillColorAsGradient(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const std::string& gradientId) {
    return setGeometricShapeFillColorAsGradient(getGeometricShape(renderGroup, geometricShapeIndex), gradientId);
}

int setGeometricShapeFillColorAsGradient(Transformation2D* shape, const std::string& gradientId) {
    if (isGraphicalPrimitive2D(shape)) {
        ((GraphicalPrimitive2D*)shape)->setFillColor(gradientId);
        return 0;
    }

    return -1;
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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeXValue(x)) {
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
    }

    return -1;
}

int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x) {
    return setGeometricShapeXAsDouble(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeXAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, x);
}

int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x) {
    return setGeometricShapeXAsDouble(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeXAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, x);
}

int setGeometricShapeXAsDouble(Style* style, const double& x) {
    return setGeometricShapeXAsDouble(style, 0, x);
}

int setGeometricShapeXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeXAsDouble(getRenderGroup(style), geometricShapeIndex, x);
}

int setGeometricShapeXAsDouble(RenderGroup* renderGroup, const double& x) {
    return setGeometricShapeXAsDouble(renderGroup, 0, x);
}

int setGeometricShapeXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeXAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), x);
}

int setGeometricShapeXAsDouble(Transformation2D* shape, const double& x) {
    RelAbsVector xRelAbs;
    xRelAbs.setAbsoluteValue(x);
    return setGeometricShapeX(shape, xRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeX(getGeometricShape(style)).empty())
            return getGeometricShapeX(getGeometricShape(style));

        return getGeometricShapeX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeX(style, x);

    return -1;
}

const double getCompartmentGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeX(globalRenderInformation));
}

int setCompartmentGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeXAsDouble(style, x);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeX(getGeometricShape(style)).empty())
            return getGeometricShapeX(getGeometricShape(style));

        return getGeometricShapeX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeX(style, x);

    return -1;
}

const double getSpeciesGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeX(globalRenderInformation));
}

int setSpeciesGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeXAsDouble(style, x);

    return -1;
}

const RelAbsVector getReactionGeometricShapeX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeX(getGeometricShape(style)).empty())
            return getGeometricShapeX(getGeometricShape(style));

        return getGeometricShapeX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeX(style, x);

    return -1;
}

const double getReactionGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeX(globalRenderInformation));
}

int setReactionGeometricShapeXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeXAsDouble(style, x);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeYValue(y)) {
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
    }

    return -1;
}

int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y) {
    return setGeometricShapeYAsDouble(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeYAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, y);
}

int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y) {
    return setGeometricShapeYAsDouble(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeYAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, y);
}

int setGeometricShapeYAsDouble(Style* style, const double& y) {
    return setGeometricShapeYAsDouble(style, 0, y);
}

int setGeometricShapeYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeYAsDouble(getRenderGroup(style), geometricShapeIndex, y);
}

int setGeometricShapeYAsDouble(RenderGroup* renderGroup, const double& y) {
    return setGeometricShapeYAsDouble(renderGroup, 0, y);
}

int setGeometricShapeYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeYAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), y);
}

int setGeometricShapeYAsDouble(Transformation2D* shape, const double& y) {
    RelAbsVector yRelAbs;
    yRelAbs.setAbsoluteValue(y);
    return setGeometricShapeY(shape, yRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeY(getGeometricShape(style)).empty())
            return getGeometricShapeY(getGeometricShape(style));

        return getGeometricShapeY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeY(style, y);

    return -1;
}

const double getCompartmentGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeY(globalRenderInformation));
}

int setCompartmentGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeYAsDouble(style, y);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeY(getGeometricShape(style)).empty())
            return getGeometricShapeY(getGeometricShape(style));

        return getGeometricShapeY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeY(style, y);

    return -1;
}

const double getSpeciesGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeY(globalRenderInformation));
}

int setSpeciesGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeYAsDouble(style, y);

    return -1;
}

const RelAbsVector getReactionGeometricShapeY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeY(getGeometricShape(style)).empty())
            return getGeometricShapeY(getGeometricShape(style));

        return getGeometricShapeY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeY(style, y);

    return -1;
}

const double getReactionGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeY(globalRenderInformation));
}

int setReactionGeometricShapeYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeYAsDouble(style, y);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeWidthValue(width)) {
        if (isRectangle(shape)) {
            ((Rectangle*)shape)->setWidth(width);
            return 0;
        }
        else if (isImage(shape)) {
            ((Image*)shape)->setWidth(width);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& width) {
    return setGeometricShapeWidthAsDouble(renderInformationBase, graphicalObject, 0, width);
}

int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& width) {
    return setGeometricShapeWidthAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, width);
}

int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& width) {
    return setGeometricShapeWidthAsDouble(renderInformationBase, attribute, 0, width);
}

int setGeometricShapeWidthAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& width) {
    return setGeometricShapeWidthAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, width);
}

int setGeometricShapeWidthAsDouble(Style* style, const double& width) {
    return setGeometricShapeWidthAsDouble(style, 0, width);
}

int setGeometricShapeWidthAsDouble(Style* style, unsigned int geometricShapeIndex, const double& width) {
    return setGeometricShapeWidthAsDouble(getRenderGroup(style), geometricShapeIndex, width);
}

int setGeometricShapeWidthAsDouble(RenderGroup* renderGroup, const double& width) {
    return setGeometricShapeWidthAsDouble(renderGroup, 0, width);
}

int setGeometricShapeWidthAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& width) {
    return setGeometricShapeWidthAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), width);
}

int setGeometricShapeWidthAsDouble(Transformation2D* shape, const double& width) {
    RelAbsVector widthRelAbs;
    widthRelAbs.setAbsoluteValue(width);
    return setGeometricShapeWidth(shape, widthRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeWidth(getGeometricShape(style)).empty())
            return getGeometricShapeWidth(getGeometricShape(style));

        return getGeometricShapeWidth(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& width) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeWidth(style, width);

    return -1;
}

const double getCompartmentGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeWidth(globalRenderInformation));
}

int setCompartmentGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation, const double& width) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeWidthAsDouble(style, width);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeWidth(getGeometricShape(style)).empty())
            return getGeometricShapeWidth(getGeometricShape(style));

        return getGeometricShapeWidth(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& width) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeWidth(style, width);

    return -1;
}

const double getSpeciesGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeWidth(globalRenderInformation));
}

int setSpeciesGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation, const double& width) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeWidthAsDouble(style, width);

    return -1;
}

const RelAbsVector getReactionGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeWidth(getGeometricShape(style)).empty())
            return getGeometricShapeWidth(getGeometricShape(style));

        return getGeometricShapeWidth(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeWidth(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& width) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeWidth(style, width);

    return -1;
}

const double getReactionGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeWidth(globalRenderInformation));
}

int setReactionGeometricShapeWidthAsDouble(GlobalRenderInformation* globalRenderInformation, const double& width) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeWidthAsDouble(style, width);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeHeightValue(height)) {
        if (isRectangle(shape)) {
            ((Rectangle*)shape)->setHeight(height);
            return 0;
        }
        else if (isImage(shape)) {
            ((Image*)shape)->setHeight(height);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& height) {
    return setGeometricShapeHeightAsDouble(renderInformationBase, graphicalObject, 0, height);
}

int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& height) {
    return setGeometricShapeHeightAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, height);
}

int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& height) {
    return setGeometricShapeHeightAsDouble(renderInformationBase, attribute, 0, height);
}

int setGeometricShapeHeightAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& height) {
    return setGeometricShapeHeightAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, height);
}

int setGeometricShapeHeightAsDouble(Style* style, const double& height) {
    return setGeometricShapeHeightAsDouble(style, 0, height);
}

int setGeometricShapeHeightAsDouble(Style* style, unsigned int geometricShapeIndex, const double& height) {
    return setGeometricShapeHeightAsDouble(getRenderGroup(style), geometricShapeIndex, height);
}

int setGeometricShapeHeightAsDouble(RenderGroup* renderGroup, const double& height) {
    return setGeometricShapeHeightAsDouble(renderGroup, 0, height);
}

int setGeometricShapeHeightAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& height) {
    return setGeometricShapeHeightAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), height);
}

int setGeometricShapeHeightAsDouble(Transformation2D* shape, const double& height) {
    RelAbsVector heightRelAbs;
    heightRelAbs.setAbsoluteValue(height);
    return setGeometricShapeHeight(shape, heightRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeHeight(getGeometricShape(style)).empty())
            return getGeometricShapeHeight(getGeometricShape(style));

        return getGeometricShapeHeight(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& height) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeHeight(style, height);

    return -1;
}

const double getCompartmentGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeHeight(globalRenderInformation));
}

int setCompartmentGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation, const double& height) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeHeightAsDouble(style, height);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeHeight(getGeometricShape(style)).empty())
            return getGeometricShapeHeight(getGeometricShape(style));

        return getGeometricShapeHeight(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& height) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeHeight(style, height);

    return -1;
}

const double getSpeciesGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeHeight(globalRenderInformation));
}

int setSpeciesGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation, const double& height) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeHeightAsDouble(style, height);

    return -1;
}

const RelAbsVector getReactionGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeHeight(getGeometricShape(style)).empty())
            return getGeometricShapeHeight(getGeometricShape(style));

        return getGeometricShapeHeight(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeHeight(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& height) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeHeight(style, height);

    return -1;
}

const double getReactionGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeHeight(globalRenderInformation));
}

int setReactionGeometricShapeHeightAsDouble(GlobalRenderInformation* globalRenderInformation, const double& height) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeHeightAsDouble(style, height);

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

    return NAN;
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
    if (isValidGeometricShapeRatioValue(ratio)) {
        if (isRectangle(shape)) {
            ((Rectangle*)shape)->setRatio(ratio);
            return 0;
        }
        else if (isEllipse(shape)) {
            ((Ellipse*)shape)->setRatio(ratio);
            return 0;
        }
    }

    return -1;
}

const double getCompartmentGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && getGeometricShapeRatio(getGeometricShape(style)) > 0.00)
            return getGeometricShapeRatio(getGeometricShape(style));

        return getGeometricShapeRatio(style);
    }

    return NAN;
}

int setCompartmentGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation, const double& ratio) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeRatio(style, ratio);

    return -1;
}

const double getSpeciesGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && getGeometricShapeRatio(getGeometricShape(style)) > 0.00)
            return getGeometricShapeRatio(getGeometricShape(style));

        return getGeometricShapeRatio(style);
    }

    return NAN;
}

int setSpeciesGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation, const double& ratio) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeRatio(style, ratio);

    return -1;
}

const double getReactionGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && getGeometricShapeRatio(getGeometricShape(style)) > 0.00)
            return getGeometricShapeRatio(getGeometricShape(style));

        return getGeometricShapeRatio(style);
    }

    return NAN;
}

int setReactionGeometricShapeRatio(GlobalRenderInformation* globalRenderInformation, const double& ratio) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeRatio(style, ratio);

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

    return RelAbsVector(NAN, NAN);
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
    if (isRectangle(shape) && isValidGeometricShapeCornerCurvatureRadiusX(rx)) {
        ((Rectangle*)shape)->setRX(rx);
        return 0;
    }

    return -1;
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(renderInformationBase, graphicalObject, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(renderInformationBase, attribute, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(Style* style, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(getRenderGroup(style), geometricShapeIndex, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderGroup* renderGroup, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(renderGroup, 0, rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeCornerCurvatureRadiusXAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), rx);
}

int setGeometricShapeCornerCurvatureRadiusXAsDouble(Transformation2D* shape, const double& rx) {
    RelAbsVector rxRelAbs;
    rxRelAbs.setAbsoluteValue(rx);
    return setGeometricShapeCornerCurvatureRadiusX(shape, rxRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(style)).empty())
            return getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(style));

        return getGeometricShapeCornerCurvatureRadiusX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusX(style, rx);

    return -1;
}

const double getCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeCornerCurvatureRadiusX(globalRenderInformation));
}

int setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, rx);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(style)).empty())
            return getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(style));

        return getGeometricShapeCornerCurvatureRadiusX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusX(style, rx);

    return -1;
}

const double getSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeCornerCurvatureRadiusX(globalRenderInformation));
}

int setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, rx);

    return -1;
}

const RelAbsVector getReactionGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(style)).empty())
            return getGeometricShapeCornerCurvatureRadiusX(getGeometricShape(style));

        return getGeometricShapeCornerCurvatureRadiusX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeCornerCurvatureRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusX(style, rx);

    return -1;
}

const double getReactionGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeCornerCurvatureRadiusX(globalRenderInformation));
}

int setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusXAsDouble(style, rx);

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

    return RelAbsVector(NAN, NAN);
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
    if (isRectangle(shape) && isValidGeometricShapeCornerCurvatureRadiusY(ry)) {
        return ((Rectangle*)shape)->setRY(ry);
        return 0;
    }

    return -1;
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(renderInformationBase, graphicalObject, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(renderInformationBase, attribute, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(Style* style, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(getRenderGroup(style), geometricShapeIndex, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderGroup* renderGroup, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(renderGroup, 0, ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeCornerCurvatureRadiusYAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), ry);
}

int setGeometricShapeCornerCurvatureRadiusYAsDouble(Transformation2D* shape, const double& ry) {
    RelAbsVector ryRelAbs;
    ryRelAbs.setAbsoluteValue(ry);
    return setGeometricShapeCornerCurvatureRadiusY(shape, ryRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(style)).empty())
            return getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(style));

        return getGeometricShapeCornerCurvatureRadiusY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusY(style, ry);

    return -1;
}

const double getCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeCornerCurvatureRadiusY(globalRenderInformation));
}

int setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, ry);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(style)).empty())
            return getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(style));

        return getGeometricShapeCornerCurvatureRadiusY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusY(style, ry);

    return -1;
}

const double getSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeCornerCurvatureRadiusY(globalRenderInformation));
}

int setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, ry);

    return -1;
}

const RelAbsVector getReactionGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(style)).empty())
            return getGeometricShapeCornerCurvatureRadiusY(getGeometricShape(style));

        return getGeometricShapeCornerCurvatureRadiusY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeCornerCurvatureRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusY(style, ry);

    return -1;
}

const double getReactionGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeCornerCurvatureRadiusY(globalRenderInformation));
}

int setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCornerCurvatureRadiusYAsDouble(style, ry);

    return -1;
}

bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getStyle(renderInformationBase, attribute), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(Style* style, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getRenderGroup(style), geometricShapeIndex);
}

bool isSetGeometricShapeCenterX(RenderGroup* renderGroup, unsigned int geometricShapeIndex) {
    return isSetGeometricShapeCenterX(getGeometricShape(renderGroup, geometricShapeIndex));
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

    return RelAbsVector(NAN, NAN);
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
    return setGeometricShapeCenterX(style, 0, cx);
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
    if (isEllipse(shape) && isValidGeometricShapeCenterX(cx)) {
        ((Ellipse*)shape)->setCX(cx);
        return 0;
    }

    return -1;
}

int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& cx) {
    return setGeometricShapeCenterXAsDouble(renderInformationBase, graphicalObject, 0, cx);
}

int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cx) {
    return setGeometricShapeCenterXAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, cx);
}

int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& cx) {
    return setGeometricShapeCenterXAsDouble(renderInformationBase, attribute, 0, cx);
}

int setGeometricShapeCenterXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& cx) {
    return setGeometricShapeCenterXAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, cx);
}

int setGeometricShapeCenterXAsDouble(Style* style, const double& cx) {
    return setGeometricShapeCenterXAsDouble(style, 0, cx);
}

int setGeometricShapeCenterXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& cx) {
    return setGeometricShapeCenterXAsDouble(getRenderGroup(style), geometricShapeIndex, cx);
}

int setGeometricShapeCenterXAsDouble(RenderGroup* renderGroup, const double& cx) {
    return setGeometricShapeCenterXAsDouble(renderGroup, 0, cx);
}

int setGeometricShapeCenterXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& cx) {
    return setGeometricShapeCenterXAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), cx);
}

int setGeometricShapeCenterXAsDouble(Transformation2D* shape, const double& cx) {
    RelAbsVector cxRelAbs;
    cxRelAbs.setAbsoluteValue(cx);
    return setGeometricShapeCenterX(shape, cxRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCenterX(getGeometricShape(style)).empty())
            return getGeometricShapeCenterX(getGeometricShape(style));

        return getGeometricShapeCenterX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cx) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCenterX(style, cx);

    return -1;
}

const double getCompartmentGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeCenterX(globalRenderInformation));
}

int setCompartmentGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cx) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCenterXAsDouble(style, cx);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCenterX(getGeometricShape(style)).empty())
            return getGeometricShapeCenterX(getGeometricShape(style));

        return getGeometricShapeCenterX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cx) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCenterX(style, cx);

    return -1;
}

const double getSpeciesGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeCenterX(globalRenderInformation));
}

int setSpeciesGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cx) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCenterXAsDouble(style, cx);

    return -1;
}

const RelAbsVector getReactionGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCenterX(getGeometricShape(style)).empty())
            return getGeometricShapeCenterX(getGeometricShape(style));

        return getGeometricShapeCenterX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeCenterX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cx) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCenterX(style, cx);

    return -1;
}

const double getReactionGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeCenterX(globalRenderInformation));
}

int setReactionGeometricShapeCenterXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cx) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCenterXAsDouble(style, cx);

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

    return RelAbsVector(NAN, NAN);
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
    if (isEllipse(shape) && isValidGeometricShapeCenterY(cy)) {
        ((Ellipse*)shape)->setCY(cy);
        return 0;
    }

    return -1;
}

int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& cy) {
    return setGeometricShapeCenterYAsDouble(renderInformationBase, graphicalObject, 0, cy);
}

int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cy) {
    return setGeometricShapeCenterYAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, cy);
}

int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& cy) {
    return setGeometricShapeCenterYAsDouble(renderInformationBase, attribute, 0, cy);
}

int setGeometricShapeCenterYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& cy) {
    return setGeometricShapeCenterYAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, cy);
}

int setGeometricShapeCenterYAsDouble(Style* style, const double& cy) {
    return setGeometricShapeCenterYAsDouble(style, 0, cy);
}

int setGeometricShapeCenterYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& cy) {
    return setGeometricShapeCenterYAsDouble(getRenderGroup(style), geometricShapeIndex, cy);
}

int setGeometricShapeCenterYAsDouble(RenderGroup* renderGroup, const double& cy) {
    return setGeometricShapeCenterYAsDouble(renderGroup, 0, cy);
}

int setGeometricShapeCenterYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& cy) {
    return setGeometricShapeCenterYAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), cy);
}

int setGeometricShapeCenterYAsDouble(Transformation2D* shape, const double& cy) {
    RelAbsVector cyRelAbs;
    cyRelAbs.setAbsoluteValue(cy);
    return setGeometricShapeCenterY(shape, cyRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCenterY(getGeometricShape(style)).empty())
            return getGeometricShapeCenterY(getGeometricShape(style));

        return getGeometricShapeCenterY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cy) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCenterY(style, cy);

    return -1;
}

const double getCompartmentGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeCenterY(globalRenderInformation));
}

int setCompartmentGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cy) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeCenterYAsDouble(style, cy);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCenterY(getGeometricShape(style)).empty())
            return getGeometricShapeCenterY(getGeometricShape(style));

        return getGeometricShapeCenterY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cy) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCenterY(style, cy);

    return -1;
}

const double getSpeciesGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeCenterY(globalRenderInformation));
}

int setSpeciesGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cy) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeCenterYAsDouble(style, cy);

    return -1;
}

const RelAbsVector getReactionGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeCenterY(getGeometricShape(style)).empty())
            return getGeometricShapeCenterY(getGeometricShape(style));

        return getGeometricShapeCenterY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeCenterY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& cy) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCenterY(style, cy);

    return -1;
}

const double getReactionGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeCenterY(globalRenderInformation));
}

int setReactionGeometricShapeCenterYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& cy) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeCenterYAsDouble(style, cy);

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

    return RelAbsVector(NAN, NAN);
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
    if (isEllipse(shape) && isValidGeometricShapeRadiusX(rx)) {
        ((Ellipse*)shape)->setRX(rx);
        return 0;
    }

    return -1;
}

int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(renderInformationBase, graphicalObject, 0, rx);
}

int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(renderInformationBase, attribute, 0, rx);
}

int setGeometricShapeRadiusXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusXAsDouble(Style* style, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(style, 0, rx);
}

int setGeometricShapeRadiusXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(getRenderGroup(style), geometricShapeIndex, rx);
}

int setGeometricShapeRadiusXAsDouble(RenderGroup* renderGroup, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(renderGroup, 0, rx);
}

int setGeometricShapeRadiusXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& rx) {
    return setGeometricShapeRadiusXAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), rx);
}

int setGeometricShapeRadiusXAsDouble(Transformation2D* shape, const double& rx) {
    RelAbsVector rxRelAbs;
    rxRelAbs.setAbsoluteValue(rx);
    return setGeometricShapeRadiusX(shape, rxRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeRadiusX(getGeometricShape(style)).empty())
            return getGeometricShapeRadiusX(getGeometricShape(style));

        return getGeometricShapeRadiusX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusX(style, rx);

    return -1;
}

const double getCompartmentGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeRadiusX(globalRenderInformation));
}

int setCompartmentGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusXAsDouble(style, rx);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeRadiusX(getGeometricShape(style)).empty())
            return getGeometricShapeRadiusX(getGeometricShape(style));

        return getGeometricShapeRadiusX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusX(style, rx);

    return -1;
}

const double getSpeciesGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeRadiusX(globalRenderInformation));
}

int setSpeciesGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusXAsDouble(style, rx);

    return -1;
}

const RelAbsVector getReactionGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeRadiusX(getGeometricShape(style)).empty())
            return getGeometricShapeRadiusX(getGeometricShape(style));

        return getGeometricShapeRadiusX(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeRadiusX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& rx) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusX(style, rx);

    return -1;
}

const double getReactionGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeRadiusX(globalRenderInformation));
}

int setReactionGeometricShapeRadiusXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& rx) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusXAsDouble(style, rx);

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

    return RelAbsVector(NAN, NAN);
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
    if (isEllipse(shape) && isValidGeometricShapeRadiusY(ry)) {
        ((Ellipse*)shape)->setRY(ry);
        return 0;
    }

    return -1;
}

int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(renderInformationBase, graphicalObject, 0, ry);
}

int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(renderInformationBase, attribute, 0, ry);
}

int setGeometricShapeRadiusYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusYAsDouble(Style* style, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(style, 0, ry);
}

int setGeometricShapeRadiusYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(getRenderGroup(style), geometricShapeIndex, ry);
}

int setGeometricShapeRadiusYAsDouble(RenderGroup* renderGroup, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(renderGroup, 0, ry);
}

int setGeometricShapeRadiusYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& ry) {
    return setGeometricShapeRadiusYAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), ry);
}

int setGeometricShapeRadiusYAsDouble(Transformation2D* shape, const double& ry) {
    RelAbsVector ryRelAbs;
    ryRelAbs.setAbsoluteValue(ry);
    return setGeometricShapeRadiusY(shape, ryRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeRadiusY(getGeometricShape(style)).empty())
            return getGeometricShapeRadiusY(getGeometricShape(style));

        return getGeometricShapeRadiusY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusY(style, ry);

    return -1;
}

const double getCompartmentGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeRadiusY(globalRenderInformation));
}

int setCompartmentGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusYAsDouble(style, ry);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeRadiusY(getGeometricShape(style)).empty())
            return getGeometricShapeRadiusY(getGeometricShape(style));

        return getGeometricShapeRadiusY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusY(style, ry);

    return -1;
}

const double getSpeciesGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeRadiusY(globalRenderInformation));
}

int setSpeciesGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusYAsDouble(style, ry);

    return -1;
}

const RelAbsVector getReactionGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeRadiusY(getGeometricShape(style)).empty())
            return getGeometricShapeRadiusY(getGeometricShape(style));

        return getGeometricShapeRadiusY(style);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeRadiusY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& ry) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusY(style, ry);

    return -1;
}

const double getReactionGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeRadiusY(globalRenderInformation));
}

int setReactionGeometricShapeRadiusYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& ry) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeRadiusYAsDouble(style, ry);

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

    return -1;
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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeElementX(x)) {
        RenderPoint* element = NULL;
        if (isPolygon(shape))
            element = ((Polygon*)shape)->getElement(elementIndex);
        else if (isRenderCurve(shape))
            element = ((RenderCurve*)shape)->getElement(elementIndex);

        if (element) {
            element->setX(x);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x) {
    return setGeometricShapeElementXAsDouble(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeElementXAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, x);
}

int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x) {
    return setGeometricShapeElementXAsDouble(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeElementXAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, x);
}

int setGeometricShapeElementXAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementXAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(Style* style, const double& x) {
    return setGeometricShapeElementXAsDouble(style, 0, x);
}

int setGeometricShapeElementXAsDouble(Style* style, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeElementXAsDouble(getRenderGroup(style), geometricShapeIndex, x);
}

int setGeometricShapeElementXAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementXAsDouble(getRenderGroup(style), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeElementXAsDouble(RenderGroup* renderGroup, const double& x) {
    return setGeometricShapeElementXAsDouble(renderGroup, 0, x);
}

int setGeometricShapeElementXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeElementXAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), x);
}

int setGeometricShapeElementXAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeElementX(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, x);
}

int setGeometricShapeElementXAsDouble(Transformation2D* shape, const double& x) {
    RelAbsVector xRelAbs;
    xRelAbs.setAbsoluteValue(x);
    return setGeometricShapeElementX(shape, xRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeElementX(getGeometricShape(style), 0).empty())
            return getGeometricShapeElementX(getGeometricShape(style), 0);

        return getGeometricShapeElementX(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeElementX(style, x);

    return -1;
}

const double getCompartmentGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeElementX(globalRenderInformation));
}

int setCompartmentGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeElementXAsDouble(style, x);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeElementX(getGeometricShape(style), 0).empty())
            return getGeometricShapeElementX(getGeometricShape(style), 0);

        return getGeometricShapeElementX(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeElementX(style, x);

    return -1;
}

const double getSpeciesGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeElementX(globalRenderInformation));
}

int setSpeciesGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeElementXAsDouble(style, x);

    return -1;
}

const RelAbsVector getReactionGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeElementX(getGeometricShape(style), 0).empty())
            return getGeometricShapeElementX(getGeometricShape(style), 0);

        return getGeometricShapeElementX(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeElementX(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeElementX(style, x);

    return -1;
}

const double getReactionGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeElementX(globalRenderInformation));
}

int setReactionGeometricShapeElementXAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeElementXAsDouble(style, x);

    return -1;
}

const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex);
}

const RelAbsVector getGeometricShapeElementY(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex) {
    return getGeometricShapeElementY(getRenderGroup(style), geometricShapeIndex, elementIndex);
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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeElementY(y)) {
        RenderPoint* element = NULL;
        if (isPolygon(shape))
            element = ((Polygon*)shape)->getElement(elementIndex);
        else if (isRenderCurve(shape))
            element = ((RenderCurve*)shape)->getElement(elementIndex);

        if (element) {
            element->setY(y);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y) {
    return setGeometricShapeElementYAsDouble(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeElementYAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, y);
}

int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y) {
    return setGeometricShapeElementYAsDouble(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeElementYAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, y);
}

int setGeometricShapeElementYAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(Style* style, const double& y) {
    return setGeometricShapeElementYAsDouble(style, 0, y);
}

int setGeometricShapeElementYAsDouble(Style* style, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeElementYAsDouble(getRenderGroup(style), geometricShapeIndex, y);
}

int setGeometricShapeElementYAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementYAsDouble(getRenderGroup(style), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeElementYAsDouble(RenderGroup* renderGroup, const double& y) {
    return setGeometricShapeElementYAsDouble(renderGroup, 0, y);
}

int setGeometricShapeElementYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeElementYAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), y);
}

int setGeometricShapeElementYAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeElementY(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeElementYAsDouble(Transformation2D* shape, const double& y) {
    RelAbsVector yRelAbs;
    yRelAbs.setAbsoluteValue(y);
    return setGeometricShapeElementY(shape, yRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeElementY(getGeometricShape(style), 0).empty())
            return getGeometricShapeElementY(getGeometricShape(style), 0);

        return getGeometricShapeElementY(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeElementY(style, y);

    return -1;
}

const double getCompartmentGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeElementY(globalRenderInformation));
}

int setCompartmentGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeElementYAsDouble(style, y);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeElementY(getGeometricShape(style), 0).empty())
            return getGeometricShapeElementY(getGeometricShape(style), 0);

        return getGeometricShapeElementY(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeElementY(style, y);

    return -1;
}

const double getSpeciesGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeElementY(globalRenderInformation));
}

int setSpeciesGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeElementYAsDouble(style, y);

    return -1;
}

const RelAbsVector getReactionGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeElementY(getGeometricShape(style), 0).empty())
            return getGeometricShapeElementY(getGeometricShape(style), 0);

        return getGeometricShapeElementY(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeElementY(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeElementY(style, y);

    return -1;
}

const double getReactionGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeElementY(globalRenderInformation));
}

int setReactionGeometricShapeElementYAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeElementYAsDouble(style, y);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeBasePoint1X(x)) {
        RenderPoint* element = NULL;
        if (isPolygon(shape))
            element = ((Polygon*)shape)->getElement(elementIndex);
        else if (isRenderCurve(shape))
            element = ((RenderCurve*)shape)->getElement(elementIndex);

        if (isRenderCubicBezier(element)) {
            ((RenderCubicBezier*)element)->setBasePoint1_x(x);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(Style* style, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(style, 0, x);
}

int setGeometricShapeBasePoint1XAsDouble(Style* style, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(getRenderGroup(style), geometricShapeIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1XAsDouble(getRenderGroup(style), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderGroup* renderGroup, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(renderGroup, 0, x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint1XAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), x);
}

int setGeometricShapeBasePoint1XAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint1X(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, x);
}

int setGeometricShapeBasePoint1XAsDouble(Transformation2D* shape, const double& x) {
    RelAbsVector xRelAbs;
    xRelAbs.setAbsoluteValue(x);
    return setGeometricShapeBasePoint1X(shape, xRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint1X(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint1X(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint1X(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1X(style, x);

    return -1;
}

const double getCompartmentGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeBasePoint1X(globalRenderInformation));
}

int setCompartmentGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1XAsDouble(style, x);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint1X(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint1X(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint1X(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1X(style, x);

    return -1;
}

const double getSpeciesGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeBasePoint1X(globalRenderInformation));
}

int setSpeciesGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1XAsDouble(style, x);

    return -1;
}

const RelAbsVector getReactionGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint1X(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint1X(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint1X(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeBasePoint1X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1X(style, x);

    return -1;
}

const double getReactionGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeBasePoint1X(globalRenderInformation));
}

int setReactionGeometricShapeBasePoint1XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1XAsDouble(style, x);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeBasePoint1Y(y)) {
        RenderPoint* element = NULL;
        if (isPolygon(shape))
            element = ((Polygon*)shape)->getElement(elementIndex);
        else if (isRenderCurve(shape))
            element = ((RenderCurve*)shape)->getElement(elementIndex);

        if (isRenderCubicBezier(element)) {
            ((RenderCubicBezier*)element)->setBasePoint1_y(y);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(Style* style, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(style, 0, y);
}

int setGeometricShapeBasePoint1YAsDouble(Style* style, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(getRenderGroup(style), geometricShapeIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1YAsDouble(getRenderGroup(style), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderGroup* renderGroup, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(renderGroup, 0, y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint1YAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), y);
}

int setGeometricShapeBasePoint1YAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeBasePoint1YAsDouble(Transformation2D* shape, const double& y) {
    RelAbsVector yRelAbs;
    yRelAbs.setAbsoluteValue(y);
    return setGeometricShapeBasePoint1Y(shape, yRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint1Y(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint1Y(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint1Y(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1Y(style, y);

    return -1;
}

const double getCompartmentGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeBasePoint1Y(globalRenderInformation));
}

int setCompartmentGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1YAsDouble(style, y);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint1Y(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint1Y(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint1Y(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1Y(style, y);

    return -1;
}

const double getSpeciesGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeBasePoint1Y(globalRenderInformation));
}

int setSpeciesGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1YAsDouble(style, y);

    return -1;
}

const RelAbsVector getReactionGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint1Y(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint1Y(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint1Y(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeBasePoint1Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1Y(style, y);

    return -1;
}

const double getReactionGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeBasePoint1Y(globalRenderInformation));
}

int setReactionGeometricShapeBasePoint1YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint1YAsDouble(style, y);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeBasePoint2X(x)) {
        RenderPoint* element = NULL;
        if (isPolygon(shape))
            element = ((Polygon*)shape)->getElement(elementIndex);
        else if (isRenderCurve(shape))
            element = ((RenderCurve*)shape)->getElement(elementIndex);

        if (isRenderCubicBezier(element)) {
            ((RenderCubicBezier*)element)->setBasePoint2_x(x);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(renderInformationBase, graphicalObject, 0, x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(renderInformationBase, attribute, 0, x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getStyle(renderInformationBase, attribute), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2XAsDouble(Style* style, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(style, 0, x);
}

int setGeometricShapeBasePoint2XAsDouble(Style* style, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(getRenderGroup(style), geometricShapeIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x) {
    return setGeometricShapeBasePoint2XAsDouble(getRenderGroup(style), geometricShapeIndex, elementIndex, x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderGroup* renderGroup, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(renderGroup, 0, x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& x) {
    return setGeometricShapeBasePoint2XAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), x);
}

int setGeometricShapeBasePoint2XAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y) {
    return setGeometricShapeBasePoint1Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeBasePoint2XAsDouble(Transformation2D* shape, const double& x) {
    RelAbsVector xRelAbs;
    xRelAbs.setAbsoluteValue(x);
    return setGeometricShapeBasePoint2X(shape, xRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint2X(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint2X(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint2X(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2X(style, x);

    return -1;
}

const double getCompartmentGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeBasePoint2X(globalRenderInformation));
}

int setCompartmentGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2XAsDouble(style, x);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint2X(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint2X(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint2X(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2X(style, x);

    return -1;
}

const double getSpeciesGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeBasePoint2X(globalRenderInformation));
}

int setSpeciesGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2XAsDouble(style, x);

    return -1;
}

const RelAbsVector getReactionGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint2X(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint2X(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint2X(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeBasePoint2X(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2X(style, x);

    return -1;
}

const double getReactionGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeBasePoint2X(globalRenderInformation));
}

int setReactionGeometricShapeBasePoint2XAsDouble(GlobalRenderInformation* globalRenderInformation, const double& x) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2XAsDouble(style, x);

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

    return RelAbsVector(NAN, NAN);
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
    if (isValidGeometricShapeBasePoint2Y(y)) {
        RenderPoint* element = NULL;
        if (isPolygon(shape))
            element = ((Polygon*)shape)->getElement(elementIndex);
        else if (isRenderCurve(shape))
            element = ((RenderCurve*)shape)->getElement(elementIndex);

        if (isRenderCubicBezier(element)) {
            ((RenderCubicBezier*)element)->setBasePoint2_y(y);
            return 0;
        }
    }

    return -1;
}

int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(renderInformationBase, graphicalObject, 0, y);
}

int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(getStyle(renderInformationBase, graphicalObject), geometricShapeIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(renderInformationBase, attribute, 0, y);
}

int setGeometricShapeBasePoint2YAsDouble(RenderInformationBase* renderInformationBase, const std::string& attribute, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(getStyle(renderInformationBase, attribute), geometricShapeIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(Style* style, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(style, 0, y);
}

int setGeometricShapeBasePoint2YAsDouble(Style* style, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(getRenderGroup(style), geometricShapeIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(Style* style, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(getRenderGroup(style), geometricShapeIndex, elementIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(RenderGroup* renderGroup, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(renderGroup, 0, y);
}

int setGeometricShapeBasePoint2YAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, const double& y) {
    return setGeometricShapeBasePoint2YAsDouble(getGeometricShape(renderGroup, geometricShapeIndex), y);
}

int setGeometricShapeBasePoint2YAsDouble(RenderGroup* renderGroup, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y) {
    return setGeometricShapeBasePoint2Y(getGeometricShape(renderGroup, geometricShapeIndex), elementIndex, y);
}

int setGeometricShapeBasePoint2YAsDouble(Transformation2D* shape, const double& y) {
    RelAbsVector yRelAbs;
    yRelAbs.setAbsoluteValue(y);
    return setGeometricShapeBasePoint2Y(shape, yRelAbs);
}

const RelAbsVector getCompartmentGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint2Y(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint2Y(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint2Y(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setCompartmentGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2Y(style, y);

    return -1;
}

const double getCompartmentGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getCompartmentGeometricShapeBasePoint2Y(globalRenderInformation));
}

int setCompartmentGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2YAsDouble(style, y);

    return -1;
}

const RelAbsVector getSpeciesGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint2Y(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint2Y(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint2Y(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setSpeciesGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2Y(style, y);

    return -1;
}

const double getSpeciesGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getSpeciesGeometricShapeBasePoint2Y(globalRenderInformation));
}

int setSpeciesGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2YAsDouble(style, y);

    return -1;
}

const RelAbsVector getReactionGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeBasePoint2Y(getGeometricShape(style), 0).empty())
            return getGeometricShapeBasePoint2Y(getGeometricShape(style), 0);

        return getGeometricShapeBasePoint2Y(style, 0, 0);
    }

    return RelAbsVector(NAN, NAN);
}

int setReactionGeometricShapeBasePoint2Y(GlobalRenderInformation* globalRenderInformation, const RelAbsVector& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2Y(style, y);

    return -1;
}

const double getReactionGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation) {
    return getAbsoluteValue(getReactionGeometricShapeBasePoint2Y(globalRenderInformation));
}

int setReactionGeometricShapeBasePoint2YAsDouble(GlobalRenderInformation* globalRenderInformation, const double& y) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeBasePoint2YAsDouble(style, y);

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
    if (isImage(shape) && isValidGeometricShapeHref(href)) {
        ((Image*)shape)->setHref(href);
        return 0;
    }

    return -1;
}

const std::string getCompartmentGeometricShapeHref(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeHref(getGeometricShape(style)).empty())
            return getGeometricShapeHref(getGeometricShape(style));

        return getGeometricShapeHref(style);
    }

    return "";
}

int setCompartmentGeometricShapeHref(GlobalRenderInformation* globalRenderInformation, const std::string& href) {
    Style* style = getStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
    if (style)
        return setGeometricShapeHref(style, href);

    return -1;
}

const std::string getSpeciesGeometricShapeHref(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeHref(getGeometricShape(style)).empty())
            return getGeometricShapeHref(getGeometricShape(style));

        return getGeometricShapeHref(style);
    }

    return "";
}

int setSpeciesGeometricShapeHref(GlobalRenderInformation* globalRenderInformation, const std::string& href) {
    Style* style = getStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
    if (style)
        return setGeometricShapeHref(style, href);

    return -1;
}

const std::string getReactionGeometricShapeHref(GlobalRenderInformation* globalRenderInformation) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style) {
        if (getNumGeometricShapes(style) == 1 && !getGeometricShapeHref(getGeometricShape(style)).empty())
            return getGeometricShapeHref(getGeometricShape(style));

        return getGeometricShapeHref(style);
    }

    return "";
}

int setReactionGeometricShapeHref(GlobalRenderInformation* globalRenderInformation, const std::string& href) {
    Style* style = getStyleByType(globalRenderInformation, getReactionGlyphStyleType());
    if (style)
        return setGeometricShapeHref(style, href);

    return -1;
}

const std::string getStyle(GlobalRenderInformation* globalRenderInformation) {
    std::map<std::string, std::string> renderFeatures = {
            {"background-color", getBackgroundColor(globalRenderInformation)},
            {"compartment-border-color", getCompartmentStrokeColor(globalRenderInformation)},
            {"compartment-border-width", std::to_string(getCompartmentStrokeWidth(globalRenderInformation))},
            {"compartment-fill-color", getCompartmentFillColor(globalRenderInformation)},
            {"compartment-font-color", getCompartmentFontColor(globalRenderInformation)},
            {"compartment-font-size", std::to_string(getCompartmentFontSizeAsDouble(globalRenderInformation))},
            {"compartment-font-family", getCompartmentFontFamily(globalRenderInformation)},
            {"compartment-font-style", getCompartmentFontStyle(globalRenderInformation)},
            {"compartment-font-weight", getCompartmentFontWeight(globalRenderInformation)},
            {"compartment-horizontal-alignment", getCompartmentTextAnchor(globalRenderInformation)},
            {"compartment-vertical-alignment", getCompartmentVTextAnchor(globalRenderInformation)},
            {"compartment-geometric-shape", getCompartmentGeometricShapeType(globalRenderInformation)},
            {"compartment-geometric-shape-ratio", std::to_string(getCompartmentGeometricShapeRatio(globalRenderInformation))},
            {"compartment-geometric-shape-corner-curvature-radius-x", std::to_string(getCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(globalRenderInformation))},
            {"compartment-geometric-shape-corner-curvature-radius-y", std::to_string(getCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(globalRenderInformation))},
            {"species-border-color", getSpeciesStrokeColor(globalRenderInformation)},
            {"species-border-width", std::to_string(getSpeciesStrokeWidth(globalRenderInformation))},
            {"species-fill-color", getSpeciesFillColor(globalRenderInformation)},
            {"species-font-color", getSpeciesFontColor(globalRenderInformation)},
            {"species-font-size", std::to_string(getSpeciesFontSizeAsDouble(globalRenderInformation))},
            {"species-font-family", getSpeciesFontFamily(globalRenderInformation)},
            {"species-font-style", getSpeciesFontStyle(globalRenderInformation)},
            {"species-font-weight", getSpeciesFontWeight(globalRenderInformation)},
            {"species-horizontal-alignment", getSpeciesTextAnchor(globalRenderInformation)},
            {"species-vertical-alignment", getSpeciesVTextAnchor(globalRenderInformation)},
            {"species-geometric-shape", getSpeciesGeometricShapeType(globalRenderInformation)},
            {"species-geometric-shape-ratio", std::to_string(getSpeciesGeometricShapeRatio(globalRenderInformation))},
            {"species-geometric-shape-corner-curvature-radius-x", std::to_string(getSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(globalRenderInformation))},
            {"species-geometric-shape-corner-curvature-radius-y", std::to_string(getSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(globalRenderInformation))},
            {"reaction-line-color", getReactionStrokeColor(globalRenderInformation)},
            {"reaction-line-width", std::to_string(getReactionStrokeWidth(globalRenderInformation))},
            {"reaction-fill-color", getReactionFillColor(globalRenderInformation)},
            {"reaction-font-color", getReactionFontColor(globalRenderInformation)},
            {"reaction-font-size", std::to_string(getReactionFontSizeAsDouble(globalRenderInformation))},
            {"reaction-font-family", getReactionFontFamily(globalRenderInformation)},
            {"reaction-font-style", getReactionFontStyle(globalRenderInformation)},
            {"reaction-font-weight", getReactionFontWeight(globalRenderInformation)},
            {"reaction-horizontal-alignment", getReactionTextAnchor(globalRenderInformation)},
            {"reaction-vertical-alignment", getReactionVTextAnchor(globalRenderInformation)},
            {"reaction-geometric-shape", getReactionGeometricShapeType(globalRenderInformation)},
            {"reaction-geometric-shape-ratio", std::to_string(getReactionGeometricShapeRatio(globalRenderInformation))},
            {"reaction-geometric-shape-corner-curvature-radius-x", std::to_string(getReactionGeometricShapeCornerCurvatureRadiusXAsDouble(globalRenderInformation))},
            {"reaction-geometric-shape-corner-curvature-radius-y", std::to_string(getReactionGeometricShapeCornerCurvatureRadiusYAsDouble(globalRenderInformation))},
            {"reaction-geometric-shape-center-x", std::to_string(getReactionGeometricShapeCenterXAsDouble(globalRenderInformation))},
            {"reaction-geometric-shape-center-y", std::to_string(getReactionGeometricShapeCenterYAsDouble(globalRenderInformation))},
            {"reaction-geometric-shape-radius-x", std::to_string(getReactionGeometricShapeRadiusXAsDouble(globalRenderInformation))},
            {"reaction-geometric-shape-radius-y", std::to_string(getReactionGeometricShapeRadiusYAsDouble(globalRenderInformation))}
    };

    return findStyle(renderFeatures);
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
    if (isSpeciesReferenceGlyph(graphicalObject)) {
        SpeciesReferenceGlyph* speciesReferenceGlyph = (SpeciesReferenceGlyph*)graphicalObject;
        return speciesReferenceGlyph->getRoleString();

    }

    return "";
}

}

