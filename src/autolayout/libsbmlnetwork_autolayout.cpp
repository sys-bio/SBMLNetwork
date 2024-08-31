#include "libsbmlnetwork_autolayout.h"
#include "../libsbmlnetwork_layout_helpers.h"
#include "../libsbmlnetwork_common.h"
#include "libsbmlnetwork_fruchterman_reingold_algorithm.h"

#include <cstdlib>
#include <cmath>
#include <climits>

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void locateGlyphs(Model *model, Layout *layout, const bool &useNameAsTextLabel) {
    double stiffness = getStiffness(layout);
    double gravity = getGravity(layout);
    bool useMagnetism = false;
    bool useGrid = false;
    std::srand(time(0));
    randomizeGlyphsLocations(model, layout);
    FruchtermanReingoldAlgorithmBase *autoLayoutAlgorithm = new FruchtermanReingoldAutoLayoutAlgorithm();
    autoLayoutAlgorithm->setElements(model, layout, useNameAsTextLabel);
    autoLayoutAlgorithm->setStiffness(stiffness);
    autoLayoutAlgorithm->setGravity(gravity);
    autoLayoutAlgorithm->setUseMagnetism(useMagnetism);
    autoLayoutAlgorithm->setUseGrid(useGrid);
    autoLayoutAlgorithm->updateNodesLockedStatus();
    autoLayoutAlgorithm->setWidth(layout);
    autoLayoutAlgorithm->setHeight(layout);
    autoLayoutAlgorithm->apply();
    updateCompartmentExtents(model, layout);
    updateLayoutDimensions(layout);
    delete autoLayoutAlgorithm;
    if (!adjustLayoutDimensions(layout)) {
        if (autolayoutMayStillConverge(stiffness, gravity)) {
            setStiffness(layout, 1.2 * stiffness);
            setGravity(layout, 0.95 * gravity);
            locateGlyphs(model, layout, useNameAsTextLabel);
        }
        else
            std::cerr << "Auto-layout fails to converge with the given layout dimensions. Please adjust layout width and height and try again." << std::endl;
    }
}

void locateReactions(Model *model, Layout *layout, const bool &useNameAsTextLabel) {
    double stiffness = getStiffness(layout);
    double gravity = getGravity(layout);
    bool useMagnetism = false;
    bool useGrid = false;
    FruchtermanReingoldAlgorithmBase* autoLayoutAlgorithm = new FruchtermanReingoldUpdateCurvesAlgorithm();
    autoLayoutAlgorithm->setElements(model, layout, useNameAsTextLabel);
    autoLayoutAlgorithm->setStiffness(stiffness);
    autoLayoutAlgorithm->setGravity(gravity);
    autoLayoutAlgorithm->setUseMagnetism(useMagnetism);
    autoLayoutAlgorithm->setUseGrid(useGrid);
    autoLayoutAlgorithm->updateNodesLockedStatus();
    autoLayoutAlgorithm->setWidth(layout);
    autoLayoutAlgorithm->setHeight(layout);
    autoLayoutAlgorithm->apply();
    updateCompartmentExtents(model, layout);
    updateLayoutDimensions(layout);
    delete autoLayoutAlgorithm;
}

const double getStiffness(Layout *layout) {
    std::string stiffness = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout, "stiffness");
    if (stiffness.empty()) {
        setStiffness(layout, 10.0);
        return 10.0;
    }

    return std::stod(stiffness);
}

void setStiffness(Layout *layout, const double &stiffness) {
    LIBSBMLNETWORK_CPP_NAMESPACE::setUserData(layout, "stiffness", std::to_string(stiffness));
}

const double getGravity(Layout *layout) {
    std::string gravity = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout, "gravity");
    if (gravity.empty()) {
        setGravity(layout, 15.0);
        return 15.0;
    }

    return std::stod(gravity);
}

void setGravity(Layout *layout, const double &gravity) {
    LIBSBMLNETWORK_CPP_NAMESPACE::setUserData(layout, "gravity", std::to_string(gravity));
}

void randomizeGlyphsLocations(Model *model, Layout *layout) {
    double canvasWidth = layout->getDimensions()->width();
    double canvasHeight = layout->getDimensions()->height();
    randomizeSpeciesGlyphsLocations(model, layout, canvasWidth, canvasHeight);
    randomizeReactionGlyphsLocations(model, layout, canvasWidth, canvasHeight);
}

void
randomizeSpeciesGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth, const double &canvasHeight) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        randomizeBoundingBoxesPosition(layout->getSpeciesGlyph(i)->getBoundingBox(), canvasWidth, canvasHeight);
}

void randomizeReactionGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth, const double &canvasHeight) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++)
        randomizeCurveCenterPoint(layout->getReactionGlyph(i)->getCurve(), canvasWidth, canvasHeight);
}

void
randomizeBoundingBoxesPosition(BoundingBox *boundingBox, const double &canvasWidth, const double &canvasHeight) {
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

void
initializeCompartmentGlyphExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox) {
    const double padding = getDefaultAutoLayoutPadding();
    compartmentGlyphBoundingBox->setX(speciesGlyphBoundingBox->x() - padding);
    compartmentGlyphBoundingBox->setY(speciesGlyphBoundingBox->y() - padding);
    compartmentGlyphBoundingBox->setWidth(speciesGlyphBoundingBox->width() + 2 * padding);
    compartmentGlyphBoundingBox->setHeight(speciesGlyphBoundingBox->height() + 2 * padding);
}

void updateCompartmentExtents(Model *model, Layout *layout) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        Compartment *compartment = findSpeciesGlyphCompartment(model, layout->getSpeciesGlyph(i));
        if (compartment) {
            std::vector < CompartmentGlyph * > compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(
                    layout, compartment->getId());
            for (int j = 0; j < compartmentGlyphs.size(); j++) {
                CompartmentGlyph *compartmentGlyph = compartmentGlyphs.at(j);
                if (i == 0)
                    initializeCompartmentGlyphExtents(compartmentGlyph->getBoundingBox(),
                                                      layout->getSpeciesGlyph(i)->getBoundingBox());
                updateCompartmentExtents(compartmentGlyph->getBoundingBox(),
                                         layout->getSpeciesGlyph(i)->getBoundingBox());
            }
        }
    }
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        CompartmentGlyph *compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout,
                                                                                layout->getReactionGlyph(i));
        if (compartmentGlyph)
            updateCompartmentExtents(compartmentGlyph->getBoundingBox(),
                                     layout->getReactionGlyph(i)->getCurve());
    }
}

void updateCompartmentExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox) {
    const double padding = getDefaultAutoLayoutPadding();
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
updateCompartmentExtents(BoundingBox *compartmentGlyphBoundingBox, Curve *reactionCurve) {
    const double padding = getDefaultAutoLayoutPadding();
    double reactionCenterX = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->x() +
                                    reactionCurve->getCurveSegment(0)->getEnd()->x());
    double reactionCenterY = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->y() +
                                    reactionCurve->getCurveSegment(0)->getEnd()->y());
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
                                              + (reactionCenterX + padding) - (compartmentGlyphBoundingBox->x() +
                                                                               compartmentGlyphBoundingBox->width()));
    }
    if (reactionCenterY + padding > compartmentGlyphBoundingBox->y() + compartmentGlyphBoundingBox->height()) {
        compartmentGlyphBoundingBox->setHeight(compartmentGlyphBoundingBox->height()
                                               + (reactionCenterY + padding) - (compartmentGlyphBoundingBox->y() +
                                                                                compartmentGlyphBoundingBox->height()));
    }
}

void updateLayoutDimensions(Layout *layout) {
    const double padding = getDefaultAutoLayoutPadding();
    if (!layoutContainsGlyphs(layout)) {
        layout->getDimensions()->setWidth(0);
        layout->getDimensions()->setHeight(0);
        return;
    } else {
        double minX;
        double minY;
        double maxX;
        double maxY;
        extractExtents(layout, minX, minY, maxX, maxY);
        layout->getDimensions()->setWidth(roundToTwoDecimalPlaces(maxX - minX));
        layout->getDimensions()->setHeight(roundToTwoDecimalPlaces(maxY - minY));
    }
}

const bool adjustLayoutDimensions(Layout *layout) {
    std::string width = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout->getDimensions(), "width");
    if (!width.empty()) {
        double presetWidth = std::stod(width);
        if (std::abs(presetWidth - layout->getDimensions()->width()) < 2 * getDefaultAutoLayoutPadding())
            layout->getDimensions()->setWidth(presetWidth);
        else
            return false;
    }
    std::string height = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout->getDimensions(), "height");
    if (!height.empty()) {
        double presetHeight = std::stod(height);
        if (std::abs(presetHeight - layout->getDimensions()->height()) < 2 * getDefaultAutoLayoutPadding())
            layout->getDimensions()->setHeight(presetHeight);
        else
            return false;
    }

    return true;
}

const bool autolayoutMayStillConverge(const double &stiffness, const double &gravity) {
    if (gravity > 1.0)
        return true;

    return false;
}

void extractExtents(Layout *layout, double &minX, double &minY, double &maxX, double &maxY) {
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

void extractExtents(BoundingBox *boundingBox, double &minX, double &minY, double &maxX, double &maxY) {
    minX = std::min(minX, boundingBox->x());
    minY = std::min(minY, boundingBox->y());
    maxX = std::max(maxX, boundingBox->x() + boundingBox->width());
    maxY = std::max(maxY, boundingBox->y() + boundingBox->height());
}

void extractExtents(Curve *reactionCurve, double &minX, double &minY, double &maxX, double &maxY) {
    double reactionCenterX = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->x() +
                                    reactionCurve->getCurveSegment(0)->getEnd()->x());
    double reactionCenterY = 0.5 * (reactionCurve->getCurveSegment(0)->getStart()->y() +
                                    reactionCurve->getCurveSegment(0)->getEnd()->y());
    minX = std::min(minX, reactionCenterX);
    minY = std::min(minY, reactionCenterY);
    maxX = std::max(maxX, reactionCenterX);
    maxY = std::max(maxY, reactionCenterY);
}

}