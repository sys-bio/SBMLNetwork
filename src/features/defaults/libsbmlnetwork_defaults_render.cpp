#include "libsbmlnetwork_defaults_render.h"
#include "../../libsbmlnetwork_render_helpers.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {
    
    void defaults_addDefaultColors(GlobalRenderInformation* globalRenderInformation) {
        addColor(globalRenderInformation, "white");
        addColor(globalRenderInformation, "black");
        addColor(globalRenderInformation, "orange");
        addColor(globalRenderInformation, "navy");
        addColor(globalRenderInformation, "orangered");
        addColor(globalRenderInformation, "darkslategray");
    }

    void defaults_addColorsOfDefaultGeometricShapes(SBMLDocument* document, LineEnding* lineEnding) {
        addColor(document, lineEnding, "white");
        addColor(document, lineEnding, "black");
    }

    void defaults_addColorsOfDefaultGeometricShapes(SBMLDocument* document, Style* style) {
        addColor(document, style, "white");
        addColor(document, style, "black");
    }

    void defaults_addColorsOfDefaultGeometricShapes(GlobalRenderInformation* globalRenderInformation) {
        addColor(globalRenderInformation, "white");
        addColor(globalRenderInformation, "black");
    }

    void defaults_addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation) {
        addProductHeadLineEnding(globalRenderInformation);
        addModifierHeadLineEnding(globalRenderInformation);
        addActivatorHeadLineEnding(globalRenderInformation);
        addInhibitorHeadLineEnding(globalRenderInformation);
    }

    void defaults_setDefault1DShapeFeatures(GraphicalPrimitive1D* graphicalPrimitive1D) {
        graphicalPrimitive1D->setStroke("black");
        graphicalPrimitive1D->setStrokeWidth(2.0);
    }

    void defaults_setDefault2DShapeFeatures(GraphicalPrimitive2D* graphicalPrimitive2D) {
        defaults_setDefault1DShapeFeatures(graphicalPrimitive2D);
        graphicalPrimitive2D->setFill("white");
    }

    void defaults_setDefaultRectangleShapeFeatures(Rectangle* rectangle) {
        defaults_setDefault2DShapeFeatures(rectangle);
        rectangle->setX(RelAbsVector(0.0, 0.0));
        rectangle->setY(RelAbsVector(0.0, 0.0));
        rectangle->setWidth(RelAbsVector(0.0, 100.0));
        rectangle->setHeight(RelAbsVector(0.0, 100.0));
        rectangle->setRX(RelAbsVector(0.0, 10.0));
        rectangle->setRY(RelAbsVector(0.0, 10.0));
    }

    void defaults_setDefaultSquareShapeFeatures(Rectangle* square) {
        defaults_setDefault2DShapeFeatures(square);
        square->setX(RelAbsVector(0.0, 0.0));
        square->setY(RelAbsVector(0.0, 0.0));
        square->setWidth(RelAbsVector(0.0, 100.0));
        square->setRatio(1.0);
        square->setRX(RelAbsVector(0.0, 0.0));
        square->setRY(RelAbsVector(0.0, 0.0));
    }

    void defaults_setDefaultEllipseShapeFeatures(Ellipse* ellipse) {
        defaults_setDefault2DShapeFeatures(ellipse);
        ellipse->setCX(RelAbsVector(0.0, 50.0));
        ellipse->setCY(RelAbsVector(0.0, 50.0));
        ellipse->setRX(RelAbsVector(0.0, 50.0));
        ellipse->setRY(RelAbsVector(0.0, 50.0));
        ellipse->setStroke("black");
        ellipse->setStrokeWidth(2.0);
    }

    void defaults_setDefaultCircleShapeFeatures(Ellipse* circle) {
        defaults_setDefault2DShapeFeatures(circle);
        circle->setCX(RelAbsVector(0.0, 50.0));
        circle->setCY(RelAbsVector(0.0, 50.0));
        circle->setRX(RelAbsVector(0.0, 50.0));
        circle->setRY(RelAbsVector(0.0, 50.0));
        circle->setRatio(1.0);
        circle->setStroke("black");
        circle->setStrokeWidth(2.0);
    }

    void defaults_setDefaultTriangleShapeFeatures(Polygon* triangle) {
        defaults_setDefault2DShapeFeatures(triangle);
        RenderPoint* point = NULL;
        point = triangle->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 0.0));
        point = triangle->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 0.0));
        point = triangle->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 100.0));
    }

    void defaults_setDefaultDiamondShapeFeatures(Polygon* diamond) {
        defaults_setDefault2DShapeFeatures(diamond);
        RenderPoint* point = NULL;
        point = diamond->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 50.0));
        point = diamond->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 0.0));
        point = diamond->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 50.0));
        point = diamond->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 100.0));

    }

    void defaults_setDefaultPentagonShapeFeatures(Polygon* pentagon) {
        defaults_setDefault2DShapeFeatures(pentagon);
        RenderPoint* point = NULL;
        point = pentagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 - std::sin(0.4 * M_PI))));
        point->setY(RelAbsVector(0.0, 50. * (1 - std::cos(0.4 * M_PI))));
        point = pentagon->createPoint();
        point->setX(RelAbsVector(0.0, 50.));
        point->setY(RelAbsVector(0.0, 0.));
        point = pentagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 + std::sin(0.4 * M_PI))));
        point->setY(RelAbsVector(0.0, 50. * (1 - std::cos(0.4 * M_PI))));
        point = pentagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 + std::sin(0.2 * M_PI))));
        point->setY(RelAbsVector(0.0, 50. * (1 + std::cos(0.2 * M_PI))));
        point = pentagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 - std::sin(0.2 * M_PI))));
        point->setY(RelAbsVector(0.0, 50. * (1 + std::cos(0.2 * M_PI))));
    }

    void defaults_setDefaultHexagonShapeFeatures(Polygon* hexagon) {
        defaults_setDefault2DShapeFeatures(hexagon);
        RenderPoint* point = NULL;
        point = hexagon->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 25.0));
        point = hexagon->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 0.0));
        point = hexagon->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 25.0));
        point = hexagon->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 75.0));
        point = hexagon->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 100.0));
        point = hexagon->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 75.0));
    }

    void defaults_setDefaultOctagonShapeFeatures(Polygon* octagon) {
        defaults_setDefault2DShapeFeatures(octagon);
        const double pi = 3.14159265;
        RenderPoint* point = NULL;
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 50.0));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 - std::cos(M_PI / 4.0))));
        point->setY(RelAbsVector(0.0, 50. * (1 - std::sin(M_PI / 4.0))));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 0.0));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 + std::cos(M_PI / 4.0))));
        point->setY(RelAbsVector(0.0, 50. * (1 - std::sin(M_PI / 4.0))));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 50.0));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 + std::cos(M_PI / 4.0))));
        point->setY(RelAbsVector(0.0, 50. * (1 + std::sin(M_PI / 4.0))));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 50.0));
        point->setY(RelAbsVector(0.0, 100.0));
        point = octagon->createPoint();
        point->setX(RelAbsVector(0.0, 50. * (1 - std::cos(M_PI / 4.0))));
        point->setY(RelAbsVector(0.0, 50. * (1 + std::sin(M_PI / 4.0))));
    }

    void defaults_setDefaultRenderCurveShapeFeatures(RenderCurve* renderCurve) {
        defaults_setDefault1DShapeFeatures(renderCurve);
        RenderPoint* point = NULL;
        point = renderCurve->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 50.0));
        point = renderCurve->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 50.0));
    }

    void defaults_setDefaultImageShapeFeatures(Image* image) {
        image->setX(RelAbsVector(0.0, 0.0));
        image->setY(RelAbsVector(0.0, 0.0));
        image->setWidth(RelAbsVector(0.0, 100.0));
        image->setHeight(RelAbsVector(0.0, 100.0));
    }

    void defaults_setDefaultDiagonalRenderCurveFeatures(RenderCurve* renderCurve) {
        defaults_setDefault1DShapeFeatures(renderCurve);
        RenderPoint* point = NULL;
        point = renderCurve->createPoint();
        point->setX(RelAbsVector(0.0, 100.0));
        point->setY(RelAbsVector(0.0, 0.0));
        point = renderCurve->createPoint();
        point->setX(RelAbsVector(0.0, 0.0));
        point->setY(RelAbsVector(0.0, 100.0));
    }

}
