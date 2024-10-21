#include "libsbmlnetwork_autolayout.h"
#include "../libsbmlnetwork_layout_helpers.h"
#include "../libsbmlnetwork_sbmldocument_helpers.h"
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
    autoLayoutAlgorithm->updateConnectionsLockedStatus();
    autoLayoutAlgorithm->setWidth(layout);
    autoLayoutAlgorithm->setHeight(layout);
    autoLayoutAlgorithm->apply();
    updateCompartmentExtents(model, layout);
    updateLayoutDimensions(layout);
    delete autoLayoutAlgorithm;
    if (!adjustLayoutDimensions(layout)) {
        if (autolayoutMayStillConverge(layout)) {
            updateGravity(layout);
            updateStiffness(layout);
            locateGlyphs(model, layout, useNameAsTextLabel);
        }
        else
            addErrorToLog(layout, "Auto-layout fails to converge with the given layout dimensions. Please adjust layout width and height and try again.");
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

void updateStiffness(Layout *layout) {
    setStiffness(layout, getStiffnessAdjustmentFactor(layout) * getStiffness(layout));
}

double getStiffnessAdjustmentFactor(Layout *layout) {
    return std::max(std::min(getDesiredDimensionToCurrentDimensionRatio(layout), 1.1), 0.9);
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

void updateGravity(Layout *layout) {
    setGravity(layout, getGravityAdjustmentFactor(layout) * getGravity(layout));
}

double getGravityAdjustmentFactor(Layout *layout) {
    return std::max(std::min(getCurrentDimensionToDesiredDimensionRatio(layout), 1.05), 0.95);
}

double getCurrentDimensionToDesiredDimensionRatio(Layout *layout) {
    double desiredWidth = getLayoutDimensionsDesiredWidth(layout);
    double desiredHeight = getLayoutDimensionsDesiredHeight(layout);
    if (layout->getDimensions()->width() < desiredWidth || layout->getDimensions()->height() < desiredHeight) {
        double widthRatio = layout->getDimensions()->width() / desiredWidth;
        double heightRatio = layout->getDimensions()->height() / desiredHeight;
        return std::sqrt(widthRatio * widthRatio + heightRatio * heightRatio);
    }
    else if (layout->getDimensions()->width() > desiredWidth || layout->getDimensions()->height() > desiredHeight) {
        double widthRatio = layout->getDimensions()->width() / desiredWidth;
        double heightRatio = layout->getDimensions()->height() / desiredHeight;
        return std::sqrt(widthRatio * widthRatio + heightRatio * heightRatio);
    }

    return 1.0;
}

double getDesiredDimensionToCurrentDimensionRatio(Layout *layout) {
    double desiredWidth = getLayoutDimensionsDesiredWidth(layout);
    double desiredHeight = getLayoutDimensionsDesiredHeight(layout);
    if (layout->getDimensions()->width() < desiredWidth || layout->getDimensions()->height() < desiredHeight) {
        double widthRatio = desiredWidth / layout->getDimensions()->width();
        double heightRatio = desiredHeight / layout->getDimensions()->height();
        return std::sqrt(widthRatio * widthRatio + heightRatio * heightRatio);
    }
    else if (layout->getDimensions()->width() > desiredWidth || layout->getDimensions()->height() > desiredHeight) {
        double widthRatio = desiredWidth / layout->getDimensions()->width();
        double heightRatio = desiredHeight / layout->getDimensions()->height();
        return std::sqrt(widthRatio * widthRatio + heightRatio * heightRatio);
    }

    return 1.0;
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
    updateCompartmentExtentsUsingItsElementsExtents(model, layout);
    updateCompartmentExtentsUsingItsPresetAttributes(layout);
}

void updateCompartmentExtentsUsingItsElementsExtents(Model *model, Layout *layout) {
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
                updateCompartmentExtentsUsingItsElementsExtents(compartmentGlyph->getBoundingBox(),
                                         layout->getSpeciesGlyph(i)->getBoundingBox());
            }
        }
    }
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        CompartmentGlyph *compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout,
                                                                                layout->getReactionGlyph(i));
        if (compartmentGlyph)
            updateCompartmentExtentsUsingItsElementsExtents(compartmentGlyph->getBoundingBox(),
                                     layout->getReactionGlyph(i)->getCurve());
    }
}

void updateCompartmentExtentsUsingItsElementsExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox) {
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

void updateCompartmentExtentsUsingItsElementsExtents(BoundingBox *compartmentGlyphBoundingBox, Curve *reactionCurve) {
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

void updateCompartmentExtentsUsingItsPresetAttributes(Layout *layout) {
    for (int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        CompartmentGlyph *compartmentGlyph = layout->getCompartmentGlyph(i);
        if (LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "locked") == "true") {
            std::string x = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "x");
            if (!x.empty())
                compartmentGlyph->getBoundingBox()->setX(std::stod(x));
            std::string y = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "y");
            if (!y.empty())
                compartmentGlyph->getBoundingBox()->setY(std::stod(y));
        }
        if (LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "fixed_width") == "true") {
            std::string width = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "width");
            if (!width.empty())
                compartmentGlyph->getBoundingBox()->setWidth(std::stod(width));
        }
        if (LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "fixed_height") == "true") {
            std::string height = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(compartmentGlyph, "height");
            if (!height.empty())
                compartmentGlyph->getBoundingBox()->setHeight(std::stod(height));
        }
    }
}

void updateLayoutDimensions(Layout *layout) {
    const double padding = getDefaultAutoLayoutPadding();
    if (!layoutContainsGlyphs(layout)) {
        layout->getDimensions()->setWidth(0);
        layout->getDimensions()->setHeight(0);
        return;
    } else {
        double maxX;
        double maxY;
        extractExtents(layout, maxX, maxY);
        layout->getDimensions()->setWidth(maxX);
        layout->getDimensions()->setHeight(maxY);
    }
}

const bool adjustLayoutDimensions(Layout *layout) {
    double desiredWidth = getLayoutDimensionsDesiredWidth(layout);
    double widthGap = desiredWidth - layout->getDimensions()->width();
    double desiredHeight = getLayoutDimensionsDesiredHeight(layout);
    double heightGap = desiredHeight - layout->getDimensions()->height();
    if (widthGap < 0.1 * desiredWidth && heightGap < 0.1 * desiredHeight) {
        setLayoutDimensionsDesiredWidth(layout, layout->getDimensions()->width());
        setLayoutDimensionsDesiredHeight(layout, layout->getDimensions()->height());
        return true;
    }

    return false;
}

const double getLayoutDimensionsDesiredWidth(Layout *layout) {;
    std::string presetWidth = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout->getDimensions(), "width");
    if (!presetWidth.empty())
        return std::stod(presetWidth);

    return layout->getDimensions()->width();
}

void setLayoutDimensionsDesiredWidth(Layout *layout, const double &width) {
    if (!LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout->getDimensions(), "width").empty())
        LIBSBMLNETWORK_CPP_NAMESPACE::setUserData(layout->getDimensions(), "width", std::to_string(width));
}

const double getLayoutDimensionsDesiredHeight(Layout *layout) {
    std::string presetHeight = LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout->getDimensions(), "height");
    if (!presetHeight.empty())
        return std::stod(presetHeight);

    return layout->getDimensions()->height();
}

void setLayoutDimensionsDesiredHeight(Layout *layout, const double &height) {
    if (!LIBSBMLNETWORK_CPP_NAMESPACE::getUserData(layout->getDimensions(), "height").empty())
        LIBSBMLNETWORK_CPP_NAMESPACE::setUserData(layout->getDimensions(), "height", std::to_string(height));
}

const bool autolayoutMayStillConverge(Layout *layout) {
    if (getGravity(layout) > 1.0)
        return true;

    return false;
}

void extractExtents(Layout *layout, double &maxX, double &maxY) {
    double minX = INT_MAX;
    double minY = INT_MAX;
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