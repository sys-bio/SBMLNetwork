#include "libsbml_ne_autolayout.h"
#include "../libsbml_ne_layout_helpers.h"
#include "libsbml_ne_fruchterman_reingold_algorithm.h"

#include <cstdlib>
#include <cmath>

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

void locateGlyphs(Model *model, Layout *layout) {
    randomizeGlyphLocations(model, layout);
    applyAutolayout(model, layout);
}

void randomizeGlyphLocations(Model *model, Layout *layout) {
    double canvasWidth = 400.0;
    double canvasHeight = 400.0;
    double padding = 30.0;
    randomizeSpeciesGlyphsLocations(model, layout, canvasWidth, canvasHeight, padding);
    randomizeReactionGlyphsLocations(model, layout, canvasWidth, canvasHeight, padding);
}

void
randomizeSpeciesGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth, const double &canvasHeight,
                                const double &padding) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        randomizeBoundingBoxValues(layout->getSpeciesGlyph(i)->getBoundingBox(), canvasWidth, canvasHeight);
        Compartment *compartment = findSpeciesGlyphCompartment(model, layout->getSpeciesGlyph(i));
        if (compartment && getCompartmentGlyph(layout, compartment)) {
            if (i == 0)
                initializeCompartmentGlyphExtents(getCompartmentGlyph(layout, compartment)->getBoundingBox(),
                                                  layout->getSpeciesGlyph(i)->getBoundingBox(), padding);
            updateCompartmentExtents(getCompartmentGlyph(layout, compartment)->getBoundingBox(),
                                     layout->getSpeciesGlyph(i)->getBoundingBox(), padding);
        }
    }
}

void randomizeReactionGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth,
                                      const double &canvasHeight, const double &padding) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        randomizeCurveCenterPoint(layout->getReactionGlyph(i)->getCurve(), canvasWidth, canvasHeight);
        Compartment *compartment = findReactionGlyphCompartment(model, layout->getReactionGlyph(i));
        if (compartment && getCompartmentGlyph(layout, compartment))
            updateCompartmentExtents(getCompartmentGlyph(layout, compartment)->getBoundingBox(),
                                     layout->getReactionGlyph(i)->getCurve(), padding);
    }
}

void
initializeCompartmentGlyphExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox,
                                  const double &padding) {
    compartmentGlyphBoundingBox->setX(speciesGlyphBoundingBox->x() - padding);
    compartmentGlyphBoundingBox->setY(speciesGlyphBoundingBox->y() - padding);
    compartmentGlyphBoundingBox->setWidth(speciesGlyphBoundingBox->width() + 2 * padding);
    compartmentGlyphBoundingBox->setHeight(speciesGlyphBoundingBox->height() + 2 * padding);
}

void updateCompartmentExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox,
                              const double &padding) {
    if (speciesGlyphBoundingBox->x() - padding < compartmentGlyphBoundingBox->x()) {
        compartmentGlyphBoundingBox->setWidth(compartmentGlyphBoundingBox->width() +
                                              (compartmentGlyphBoundingBox->x() -
                                               (speciesGlyphBoundingBox->x() - padding)));
        compartmentGlyphBoundingBox->setX(speciesGlyphBoundingBox->x() - padding);
    }
    if (speciesGlyphBoundingBox->y() - padding < compartmentGlyphBoundingBox->y()) {
        compartmentGlyphBoundingBox->setHeight(compartmentGlyphBoundingBox->height() +
                                               (compartmentGlyphBoundingBox->y() -
                                                (speciesGlyphBoundingBox->y() - padding)));
        compartmentGlyphBoundingBox->setY(speciesGlyphBoundingBox->y() - padding);
    }
    if (speciesGlyphBoundingBox->x() + speciesGlyphBoundingBox->width() + padding >
        compartmentGlyphBoundingBox->x() + compartmentGlyphBoundingBox->width()) {
        compartmentGlyphBoundingBox->setWidth(compartmentGlyphBoundingBox->width()
                                              + (speciesGlyphBoundingBox->x() + speciesGlyphBoundingBox->width() +
                                                 padding)
                                              - (compartmentGlyphBoundingBox->x() +
                                                 compartmentGlyphBoundingBox->width()));
    }
    if (speciesGlyphBoundingBox->y() + speciesGlyphBoundingBox->height() + padding >
        compartmentGlyphBoundingBox->y() + compartmentGlyphBoundingBox->height()) {
        compartmentGlyphBoundingBox->setHeight(compartmentGlyphBoundingBox->height()
                                               +
                                               (speciesGlyphBoundingBox->y() + speciesGlyphBoundingBox->height() +
                                                padding)
                                               - (compartmentGlyphBoundingBox->y() +
                                                  compartmentGlyphBoundingBox->height()));
    }
}

void
updateCompartmentExtents(BoundingBox *compartmentGlyphBoundingBox, Curve *reactionCurve, const double &padding) {
    Point reactionCenter = Point(0.5 * (reactionCurve->getCurveSegment(0)->getStart()->x() +
                                        reactionCurve->getCurveSegment(0)->getEnd()->x()),
                                 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->y() +
                                        reactionCurve->getCurveSegment(0)->getEnd()->y()));
    if (reactionCenter.x() - padding < compartmentGlyphBoundingBox->x()) {
        compartmentGlyphBoundingBox->setWidth(compartmentGlyphBoundingBox->width() +
                                              (compartmentGlyphBoundingBox->x() - (reactionCenter.x() - padding)));
        compartmentGlyphBoundingBox->setX(reactionCenter.x() - padding);
    }
    if (reactionCenter.y() - padding < compartmentGlyphBoundingBox->y()) {
        compartmentGlyphBoundingBox->setWidth(compartmentGlyphBoundingBox->height() +
                                              (compartmentGlyphBoundingBox->y() - (reactionCenter.y() - padding)));
        compartmentGlyphBoundingBox->setY(reactionCenter.y() - padding);
    }
}

void randomizeBoundingBoxValues(BoundingBox *boundingBox, const double &canvasWidth, const double &canvasHeight) {
    double offset = 30.0;
    double defaultBoundingBoxWidth = 60.0;
    double defaultBoundingBoxHeight = 36.0;
    boundingBox->setX(offset + (std::rand() % int(canvasWidth - offset)));
    boundingBox->setY(offset + (std::rand() % int(canvasHeight - offset)));
    boundingBox->setWidth(defaultBoundingBoxWidth);
    boundingBox->setHeight(defaultBoundingBoxHeight);
}

void randomizeCurveCenterPoint(Curve *curve, const double &canvasWidth, const double &canvasHeight) {
    double offset = 30.0;
    double randomPointX = offset + (std::rand() % int(canvasWidth - offset));
    double randomPointY = offset + (std::rand() % int(canvasHeight - offset));
    CubicBezier *cubicBezier = ((CubicBezier *) curve->getCurveSegment(0));
    cubicBezier->getStart()->setX(randomPointX);
    cubicBezier->getStart()->setY(randomPointY);
    cubicBezier->getEnd()->setX(randomPointX);
    cubicBezier->getEnd()->setY(randomPointY);
    cubicBezier->getBasePoint1()->setX(randomPointX);
    cubicBezier->getBasePoint1()->setY(randomPointY);
    cubicBezier->getBasePoint2()->setX(randomPointX);
    cubicBezier->getBasePoint2()->setY(randomPointY);
}

void applyAutolayout(Model *model, Layout *layout) {
    FruthtermanReingoldAlgorithm * fruthtermanReingoldAlgorithm = new FruthtermanReingoldAlgorithm();
    fruthtermanReingoldAlgorithm->setElements(model, layout);
    fruthtermanReingoldAlgorithm->setStiffness(30.0);
    fruthtermanReingoldAlgorithm->setGravity(15.0);
    fruthtermanReingoldAlgorithm->setUseMagnetism(false);
    fruthtermanReingoldAlgorithm->setUseBoundary(false);
    fruthtermanReingoldAlgorithm->setUseGrid(false);
    fruthtermanReingoldAlgorithm->apply();
}

}
