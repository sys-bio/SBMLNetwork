#ifndef __LIBSBMLNETWORK_DEFAULTS_RENDER_H
#define __LIBSBMLNETWORK_DEFAULTS_RENDER_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    void defaults_addDefaultColors(GlobalRenderInformation* globalRenderInformation);

    void defaults_addColorsOfDefaultGeometricShapes(SBMLDocument* document, LineEnding* lineEnding);

    void defaults_addColorsOfDefaultGeometricShapes(SBMLDocument* document, Style* style);

    void defaults_addColorsOfDefaultGeometricShapes(GlobalRenderInformation* globalRenderInformation);

    void defaults_addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation);

    void defaults_setDefault1DShapeFeatures(GraphicalPrimitive1D* graphicalPrimitive1D);

    void defaults_setDefault2DShapeFeatures(GraphicalPrimitive2D* graphicalPrimitive2D);

    void defaults_setDefaultRectangleShapeFeatures(Rectangle* rectangle);

    void defaults_setDefaultSquareShapeFeatures(Rectangle* square);

    void defaults_setDefaultEllipseShapeFeatures(Ellipse* ellipse);

    void defaults_setDefaultCircleShapeFeatures(Ellipse* circle);

    void defaults_setDefaultTriangleShapeFeatures(Polygon* triangle);

    void defaults_setDefaultDiamondShapeFeatures(Polygon* diamond);

    void defaults_setDefaultPentagonShapeFeatures(Polygon* pentagon);

    void defaults_setDefaultHexagonShapeFeatures(Polygon* pentagon);

    void defaults_setDefaultOctagonShapeFeatures(Polygon* pentagon);

    void defaults_setDefaultRenderCurveShapeFeatures(RenderCurve* renderCurve);

    void defaults_setDefaultImageShapeFeatures(Image* image);

    void defaults_setDefaultDiagonalRenderCurveFeatures(RenderCurve* renderCurve);
}

#endif
