#ifndef __LIBSBMLNETWORK_ERROR_LOG_H
#define __LIBSBMLNETWORK_ERROR_LOG_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

const std::string error_log_getErrorLog(const Layout *layout);

void error_log_clearErrorLog(Layout *layout);

const std::string error_log_getErrorLog(const GraphicalObject *graphicalObject);

void error_log_clearErrorLog(GraphicalObject *graphicalObject);

const std::string error_log_getErrorLog(const BoundingBox *boundingBox);

void error_log_clearErrorLog(BoundingBox *boundingBox);

const std::string error_log_getErrorLog(const Curve *curve);

void error_log_clearErrorLog(Curve *curve);

const std::string error_log_getErrorLog(const LineSegment *lineSegment);

void error_log_clearErrorLog(LineSegment *lineSegment);

const std::string error_log_getErrorLog(const RenderInformationBase* renderInformation);

void error_log_clearErrorLog(RenderInformationBase* renderInformation);

const std::string error_log_getErrorLog(const ColorDefinition* colorDefinition);

void error_log_clearErrorLog(ColorDefinition* colorDefinition);

const std::string error_log_getErrorLog(const GradientBase* gradientBase);

void error_log_clearErrorLog(GradientBase* gradientBase);

const std::string error_log_getErrorLog(const GradientStop* gradientStop);

void error_log_clearErrorLog(GradientStop* gradientStop);

const std::string error_log_getErrorLog(const LineEnding* lineEnding);

void error_log_clearErrorLog(LineEnding* lineEnding);

const std::string error_log_getErrorLog(const Style* style);

void error_log_clearErrorLog(Style* style);

const std::string error_log_getErrorLog(const RenderGroup* renderGroup);

void error_log_clearErrorLog(RenderGroup* renderGroup);

const std::string error_log_getErrorLog(const Transformation2D* transformation2D);

void error_log_clearErrorLog(Transformation2D* transformation2D);

const std::string error_log_getErrorLog(const SBase* sBase);

void error_log_clearErrorLog(SBase* sBase);

const std::string error_log_prepareErrorMessage(const std::string& errorMessage, const std::string& errorLog);

void error_log_addErrorToLog(SBase* sBase, const std::string& errorMessage);

const std::string error_log_createErrorMessage(const std::string& value, std::vector<std::string> validValues);

}

#endif