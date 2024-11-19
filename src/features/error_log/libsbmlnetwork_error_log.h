#ifndef __LIBSBMLNETWORK_ERROR_LOG_H
#define __LIBSBMLNETWORK_ERROR_LOG_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

const std::string el_getErrorLog(Layout *layout);

void el_clearErrorLog(Layout *layout);

const std::string el_getErrorLog(GraphicalObject *graphicalObject);

void el_clearErrorLog(GraphicalObject *graphicalObject);

const std::string el_getErrorLog(BoundingBox *boundingBox);

void el_clearErrorLog(BoundingBox *boundingBox);

const std::string el_getErrorLog(Curve *curve);

void el_clearErrorLog(Curve *curve);

const std::string el_getErrorLog(LineSegment *lineSegment);

void el_clearErrorLog(LineSegment *lineSegment);

const std::string el_getErrorLog(RenderInformationBase* renderInformation);

void el_clearErrorLog(RenderInformationBase* renderInformation);

const std::string el_getErrorLog(ColorDefinition* colorDefinition);

void el_clearErrorLog(ColorDefinition* colorDefinition);

const std::string el_getErrorLog(GradientBase* gradientBase);

void el_clearErrorLog(GradientBase* gradientBase);

const std::string el_getErrorLog(GradientStop* gradientStop);

void el_clearErrorLog(GradientStop* gradientStop);

const std::string el_getErrorLog(LineEnding* lineEnding);

void el_clearErrorLog(LineEnding* lineEnding);

const std::string el_getErrorLog(Style* style);

void el_clearErrorLog(Style* style);

const std::string el_getErrorLog(RenderGroup* renderGroup);

void el_clearErrorLog(RenderGroup* renderGroup);

const std::string el_getErrorLog(Transformation2D* transformation2D);

void el_clearErrorLog(Transformation2D* transformation2D);

const std::string el_getErrorLog(SBase* sBase);

void el_clearErrorLog(SBase* sBase);

const std::string el_prepareErrorMessage(const std::string& errorMessage, const std::string& errorLog);

void el_addErrorToLog(SBase* sBase, const std::string& errorMessage);

}

#endif