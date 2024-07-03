#include "libsbmlnetwork_autolayout.h"
#include "../libsbmlnetwork_layout_helpers.h"
#include "libsbmlnetwork_fruchterman_reingold_algorithm.h"

#include <cstdlib>
#include <cmath>
#include <climits>

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void locateGlyphs(Model *model, Layout *layout, const double &stiffness, const double &gravity,
                  const bool &useMagnetism, const bool &useBoundary, const bool &useGrid,
                  const bool& useNameAsTextLabel, const std::vector <std::string> &lockedNodeIds) {
    double padding = 30.0;
    std::srand(time(0));
    randomizeGlyphsLocations(model, layout, padding, lockedNodeIds);
    applyAutolayout(model, layout, stiffness, gravity, useMagnetism, useBoundary, useGrid, useNameAsTextLabel, lockedNodeIds, padding);
    updateCompartmentExtents(model, layout, padding);
    updateLayoutDimensions(layout, padding);
}

void randomizeGlyphsLocations(Model *model, Layout *layout, const double &padding,
                              const std::vector <std::string> &lockedNodeIds) {
    double canvasWidth = layout->getDimensions()->width();
    double canvasHeight = layout->getDimensions()->height();
    randomizeSpeciesGlyphsLocations(model, layout, canvasWidth, canvasHeight, padding, lockedNodeIds);
    randomizeReactionGlyphsLocations(model, layout, canvasWidth, canvasHeight, padding, lockedNodeIds);
}

void randomizeSpeciesGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth, const double &canvasHeight,
                                const double &padding, const std::vector <std::string> &lockedNodeIds) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        if (!whetherGraphicalObjectIsLocked(layout, layout->getSpeciesGlyph(i), lockedNodeIds))
            randomizeBoundingBoxesPosition(layout->getSpeciesGlyph(i)->getBoundingBox(), canvasWidth, canvasHeight);
    }
}

void randomizeReactionGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth,
                                      const double &canvasHeight, const double &padding,
                                      const std::vector <std::string> &lockedNodeIds) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (!whetherGraphicalObjectIsLocked(layout, layout->getReactionGlyph(i), lockedNodeIds))
            randomizeCurveCenterPoint(layout->getReactionGlyph(i)->getCurve(), canvasWidth, canvasHeight);
    }
}

void randomizeBoundingBoxesPosition(BoundingBox *boundingBox, const double &canvasWidth, const double &canvasHeight) {
    double offset = 30.0;
    boundingBox->setX(offset + (std::rand() % int(canvasWidth - offset)));
    boundingBox->setY(offset + (std::rand() % int(canvasHeight - offset)));
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

void applyAutolayout(Model *model, Layout *layout, const double &stiffness, const double &gravity,
                     const bool &useMagnetism, const bool &useBoundary, const bool &useGrid,
                     const bool& useNameAsTextLabel, const std::vector <std::string> &lockedNodeIds, const double &padding) {
    FruchtermanReingoldAlgorithm* fruchtermanReingoldAlgorithm = new FruchtermanReingoldAlgorithm();
    fruchtermanReingoldAlgorithm->setElements(model, layout, useNameAsTextLabel);
    fruchtermanReingoldAlgorithm->setStiffness(stiffness);
    fruchtermanReingoldAlgorithm->setGravity(gravity);
    fruchtermanReingoldAlgorithm->setUseMagnetism(useMagnetism);
    fruchtermanReingoldAlgorithm->setUseBoundary(useBoundary);
    fruchtermanReingoldAlgorithm->setUseGrid(useGrid);
    fruchtermanReingoldAlgorithm->setNodesLockedStatus(layout, lockedNodeIds);
    fruchtermanReingoldAlgorithm->setPadding(padding);
    fruchtermanReingoldAlgorithm->apply();
}

void initializeCompartmentGlyphExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox,
                                  const double &padding) {
    compartmentGlyphBoundingBox->setX(speciesGlyphBoundingBox->x() - padding);
    compartmentGlyphBoundingBox->setY(speciesGlyphBoundingBox->y() - padding);
    compartmentGlyphBoundingBox->setWidth(speciesGlyphBoundingBox->width() + 2 * padding);
    compartmentGlyphBoundingBox->setHeight(speciesGlyphBoundingBox->height() + 2 * padding);
}

void updateCompartmentExtents(Model *model, Layout *layout, const double &padding) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        Compartment *compartment = findSpeciesGlyphCompartment(model, layout->getSpeciesGlyph(i));
        if (compartment && getCompartmentGlyph(layout, compartment)) {
            if (i == 0)
                initializeCompartmentGlyphExtents(getCompartmentGlyph(layout, compartment)->getBoundingBox(),
                                                  layout->getSpeciesGlyph(i)->getBoundingBox(), padding);
            updateCompartmentExtents(getCompartmentGlyph(layout, compartment)->getBoundingBox(),
                                     layout->getSpeciesGlyph(i)->getBoundingBox(), padding);
        }
    }
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        CompartmentGlyph* compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout ,layout->getReactionGlyph(i));
        if (compartmentGlyph)
            updateCompartmentExtents(compartmentGlyph->getBoundingBox(),
                                     layout->getReactionGlyph(i)->getCurve(), padding);
    }
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

void updateCompartmentExtents(BoundingBox *compartmentGlyphBoundingBox, Curve *reactionCurve, const double &padding) {
    double reactionCenterX = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->x() + reactionCurve->getCurveSegment(0)->getEnd()->x());
    double reactionCenterY = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->y() + reactionCurve->getCurveSegment(0)->getEnd()->y());
    if (reactionCenterX - padding < compartmentGlyphBoundingBox->x()) {
        compartmentGlyphBoundingBox->setWidth(compartmentGlyphBoundingBox->width() +
                                              (compartmentGlyphBoundingBox->x() - (reactionCenterX - padding)));
        compartmentGlyphBoundingBox->setX(reactionCenterX - padding);
    }
    if (reactionCenterY - padding < compartmentGlyphBoundingBox->y()) {
        compartmentGlyphBoundingBox->setHeight(compartmentGlyphBoundingBox->height() +
                                              (compartmentGlyphBoundingBox->y() - (reactionCenterY - padding)));
        compartmentGlyphBoundingBox->setY(reactionCenterY - padding);
    }
    if (reactionCenterX + padding > compartmentGlyphBoundingBox->x() + compartmentGlyphBoundingBox->width()) {
        compartmentGlyphBoundingBox->setWidth(compartmentGlyphBoundingBox->width()
                                              + (reactionCenterX + padding) - (compartmentGlyphBoundingBox->x() + compartmentGlyphBoundingBox->width()));
    }
    if (reactionCenterY + padding > compartmentGlyphBoundingBox->y() + compartmentGlyphBoundingBox->height()) {
        compartmentGlyphBoundingBox->setHeight(compartmentGlyphBoundingBox->height()
                                              + (reactionCenterY + padding) - (compartmentGlyphBoundingBox->y() + compartmentGlyphBoundingBox->height()));
    }
}

void updateLayoutDimensions(Layout* layout, const double &padding) {
    if (!layoutContainsGlyphs(layout)) {
        layout->getDimensions()->setWidth(0);
        layout->getDimensions()->setHeight(0);
        return;
    }
    else {
        double minX;
        double minY;
        double maxX;
        double maxY;
        extractExtents(layout, minX, minY, maxX, maxY);
        layout->getDimensions()->setWidth(maxX - minX + 2 * padding);
        layout->getDimensions()->setHeight(maxY - minY + 2 * padding);
    }
}

void extractExtents(Layout* layout, double &minX, double &minY, double &maxX, double &maxY) {
    minX = INT_MAX;
    minY = INT_MAX;
    maxX = INT_MIN;
    maxY = INT_MIN;
    for (int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
        extractExtents(layout->getCompartmentGlyph(i)->getBoundingBox(), minX, minY, maxX, maxY);
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        extractExtents(layout->getSpeciesGlyph(i)->getBoundingBox(), minX, minY, maxX, maxY);
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++)
        extractExtents(layout->getReactionGlyph(i)->getCurve(), minX, minY, maxX, maxY);
}

void extractExtents(BoundingBox* boundingBox, double &minX, double &minY, double &maxX, double &maxY) {
    minX = std::min(minX, boundingBox->x());
    minY = std::min(minY, boundingBox->y());
    maxX = std::max(maxX, boundingBox->x() + boundingBox->width());
    maxY = std::max(maxY, boundingBox->y() + boundingBox->height());
}

void extractExtents(Curve* reactionCurve, double &minX, double &minY, double &maxX, double &maxY) {
    double reactionCenterX = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->x() + reactionCurve->getCurveSegment(0)->getEnd()->x());
    double reactionCenterY = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->y() + reactionCurve->getCurveSegment(0)->getEnd()->y());
    minX = std::min(minX, reactionCenterX);
    minY = std::min(minY, reactionCenterY);
    maxX = std::max(maxX, reactionCenterX);
    maxY = std::max(maxY, reactionCenterY);
}

}
