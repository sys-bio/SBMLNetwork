#include "libsbmlnetwork_autolayout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../libsbmlnetwork_common.h"
#include "libsbmlnetwork_fruchterman_reingold_algorithm.h"
#include "../error_log/libsbmlnetwork_error_log.h"
#include "../user_data/libsbmlnetwork_user_data.h"
#include "../defaults/libsbmlnetwork_defaults_layout.h"

#include <cstdlib>
#include <cmath>
#include <climits>

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void autolayout_locateGlyphs(Model *model, Layout *layout, const bool &useNameAsTextLabel) {
    double stiffness = autolayout_getStiffness(layout);
    double gravity = autolayout_getGravity(layout);
    bool useMagnetism = false;
    bool useGrid = false;
    std::srand(time(0));
    autolayout_randomizeGlyphsLocations(model, layout);
    FruchtermanReingoldAlgorithmBase *autoLayoutAlgorithm = new FruchtermanReingoldAutoLayoutAlgorithm();
    autoLayoutAlgorithm->setElements(model, layout, useNameAsTextLabel);
    autoLayoutAlgorithm->setStiffness(stiffness);
    autoLayoutAlgorithm->setGravity(gravity);
    autoLayoutAlgorithm->setUseMagnetism(useMagnetism);
    autoLayoutAlgorithm->setUseGrid(useGrid);
    autoLayoutAlgorithm->updateNodesFixedPositionStatus();
    autoLayoutAlgorithm->updateConnectionsFixedPositionStatus();
    autoLayoutAlgorithm->setWidth(layout);
    autoLayoutAlgorithm->setHeight(layout);
    autoLayoutAlgorithm->apply();
    autolayout_updateCompartmentsExtents(model, layout);
    autolayout_updateLayoutDimensions(layout);
    delete autoLayoutAlgorithm;
    if (!autolayout_adjustLayoutDimensions(layout)) {
        if (autolayout_autolayoutMayStillConverge(layout)) {
            autolayout_updateGravity(layout);
            autolayout_updateStiffness(layout);
            autolayout_locateGlyphs(model, layout, useNameAsTextLabel);
        }
        else
            error_log_addErrorToLog(layout, "Auto-layout fails to converge with the given layout dimensions. Please adjust layout width and height and try again.");
    }
}

void autolayout_locateReactions(Model *model, Layout *layout, const bool &useNameAsTextLabel) {
    double stiffness = autolayout_getStiffness(layout);
    double gravity = autolayout_getGravity(layout);
    bool useMagnetism = false;
    bool useGrid = false;
    FruchtermanReingoldAlgorithmBase* autoLayoutAlgorithm = new FruchtermanReingoldUpdateCurvesAlgorithm();
    autoLayoutAlgorithm->setElements(model, layout, useNameAsTextLabel);
    autoLayoutAlgorithm->setStiffness(stiffness);
    autoLayoutAlgorithm->setGravity(gravity);
    autoLayoutAlgorithm->setUseMagnetism(useMagnetism);
    autoLayoutAlgorithm->setUseGrid(useGrid);
    autoLayoutAlgorithm->updateNodesFixedPositionStatus();
    autoLayoutAlgorithm->setWidth(layout);
    autoLayoutAlgorithm->setHeight(layout);
    autoLayoutAlgorithm->apply();
    autolayout_updateCompartmentsExtents(model, layout);
    autolayout_updateLayoutDimensions(layout);
    delete autoLayoutAlgorithm;
}

const double autolayout_getStiffness(Layout *layout) {
    std::string stiffness = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout, "stiffness");
    if (stiffness.empty()) {
        autolayout_setStiffness(layout, 10.0);
        return 10.0;
    }

    return std::stod(stiffness);
}

void autolayout_setStiffness(Layout *layout, const double &stiffness) {
    LIBSBMLNETWORK_CPP_NAMESPACE::user_data_setUserData(layout, "stiffness", std::to_string(stiffness));
}

void autolayout_updateStiffness(Layout *layout) {
    autolayout_setStiffness(layout, autolayout_getStiffnessAdjustmentFactor(layout) * autolayout_getStiffness(layout));
}

double autolayout_getStiffnessAdjustmentFactor(Layout *layout) {
    return std::max(std::min(autolayout_getDesiredDimensionToCurrentDimensionRatio(layout), 1.1), 0.9);
}

const double autolayout_getGravity(Layout *layout) {
    std::string gravity = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout, "gravity");
    if (gravity.empty()) {
        autolayout_setGravity(layout, 15.0);
        return 15.0;
    }

    return std::stod(gravity);
}

void autolayout_setGravity(Layout *layout, const double &gravity) {
    LIBSBMLNETWORK_CPP_NAMESPACE::user_data_setUserData(layout, "gravity", std::to_string(gravity));
}

void autolayout_updateGravity(Layout *layout) {
    autolayout_setGravity(layout, autolayout_getGravityAdjustmentFactor(layout) * autolayout_getGravity(layout));
}

double autolayout_getGravityAdjustmentFactor(Layout *layout) {
    return std::max(std::min(autolayout_getCurrentDimensionToDesiredDimensionRatio(layout), 1.05), 0.95);
}

double autolayout_getCurrentDimensionToDesiredDimensionRatio(Layout *layout) {
    double desiredWidth = autolayout_getLayoutDimensionsDesiredWidth(layout);
    double desiredHeight = autolayout_getLayoutDimensionsDesiredHeight(layout);
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

double autolayout_getDesiredDimensionToCurrentDimensionRatio(Layout *layout) {
    double desiredWidth = autolayout_getLayoutDimensionsDesiredWidth(layout);
    double desiredHeight = autolayout_getLayoutDimensionsDesiredHeight(layout);
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

void autolayout_randomizeGlyphsLocations(Model *model, Layout *layout) {
    double canvasWidth = layout->getDimensions()->width();
    double canvasHeight = layout->getDimensions()->height();
    autolayout_randomizeSpeciesGlyphsLocations(model, layout, canvasWidth, canvasHeight);
    autolayout_randomizeReactionGlyphsLocations(model, layout, canvasWidth, canvasHeight);
}

void autolayout_randomizeSpeciesGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth, const double &canvasHeight) {
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        autolayout_randomizeBoundingBoxesPosition(layout->getSpeciesGlyph(i)->getBoundingBox(), canvasWidth, canvasHeight);
}

void autolayout_randomizeReactionGlyphsLocations(Model *model, Layout *layout, const double &canvasWidth, const double &canvasHeight) {
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (layout->getReactionGlyph(i)->isSetCurve())
            autolayout_randomizeCurveCenterPoint(layout->getReactionGlyph(i)->getCurve(), canvasWidth, canvasHeight);
        else
            autolayout_randomizeBoundingBoxesPosition(layout->getReactionGlyph(i)->getBoundingBox(), canvasWidth, canvasHeight);
    }
}

void autolayout_randomizeBoundingBoxesPosition(BoundingBox *boundingBox, const double &canvasWidth, const double &canvasHeight) {
    double offset = 30.0;
    boundingBox->setX(offset + (std::rand() % int(canvasWidth - offset)));
    boundingBox->setY(offset + (std::rand() % int(canvasHeight - offset)));
}

void autolayout_randomizeCurveCenterPoint(Curve *curve, const double &canvasWidth, const double &canvasHeight) {
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

void autolayout_initializeCompartmentGlyphExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox) {
    const double padding = defaults_getDefaultAutoLayoutPadding();
    compartmentGlyphBoundingBox->setX(speciesGlyphBoundingBox->x() - padding);
    compartmentGlyphBoundingBox->setY(speciesGlyphBoundingBox->y() - padding);
    compartmentGlyphBoundingBox->setWidth(speciesGlyphBoundingBox->width() + 2 * padding);
    compartmentGlyphBoundingBox->setHeight(speciesGlyphBoundingBox->height() + 2 * padding);
}

void autolayout_updateCompartmentsExtents(Model *model, Layout *layout) {
    autolayout_updateCompartmentsExtentsUsingTheirElementsExtents(model, layout);
    autolayout_updateCompartmentsExtentsUsingTheirPresetAttributes(layout);
}

void autolayout_updateCompartmentsExtentsUsingTheirElementsExtents(Model *model, Layout *layout) {
    std::vector<std::string> extentsInitializedCompartmentGlyphIds;
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        Compartment *compartment = findSpeciesGlyphCompartment(model, layout->getSpeciesGlyph(i));
        if (compartment) {
            std::vector < CompartmentGlyph * > compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(
                    layout, compartment->getId());
            for (int j = 0; j < compartmentGlyphs.size(); j++) {
                CompartmentGlyph *compartmentGlyph = compartmentGlyphs.at(j);
                if (std::find(extentsInitializedCompartmentGlyphIds.begin(),
                              extentsInitializedCompartmentGlyphIds.end(), compartmentGlyph->getId()) ==
                    extentsInitializedCompartmentGlyphIds.end()) {
                    autolayout_initializeCompartmentGlyphExtents(compartmentGlyph->getBoundingBox(),
                                                      layout->getSpeciesGlyph(i)->getBoundingBox());
                    extentsInitializedCompartmentGlyphIds.push_back(compartmentGlyph->getId());
                }
                autolayout_updateCompartmentExtentsUsingItsElementsExtents(compartmentGlyph->getBoundingBox(),
                                         layout->getSpeciesGlyph(i)->getBoundingBox());
            }
        }
    }
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        CompartmentGlyph *compartmentGlyph = getCompartmentGlyphOfReactionGlyph(model, layout,
                                                                                layout->getReactionGlyph(i));
        if (compartmentGlyph) {
            if (layout->getReactionGlyph(i)->isSetCurve())
                autolayout_updateCompartmentExtentsUsingItsElementsExtents(compartmentGlyph->getBoundingBox(),
                                                                layout->getReactionGlyph(i)->getCurve());
            else
                autolayout_updateCompartmentExtentsUsingItsElementsExtents(compartmentGlyph->getBoundingBox(),
                                                  layout->getReactionGlyph(i)->getBoundingBox());
        }
    }
}

void autolayout_updateCompartmentExtentsUsingItsElementsExtents(BoundingBox *compartmentGlyphBoundingBox, BoundingBox *speciesGlyphBoundingBox) {
    const double padding = defaults_getDefaultAutoLayoutPadding();
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

void autolayout_updateCompartmentExtentsUsingItsElementsExtents(BoundingBox *compartmentGlyphBoundingBox, Curve *reactionCurve) {
    const double padding = defaults_getDefaultAutoLayoutPadding();
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

void autolayout_updateCompartmentsExtentsUsingTheirPresetAttributes(Layout *layout) {
    for (int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        CompartmentGlyph *compartmentGlyph = layout->getCompartmentGlyph(i);
        if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "fixed_position") == "true") {
            std::string x = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "x");
            if (!x.empty())
                compartmentGlyph->getBoundingBox()->setX(std::stod(x));
            std::string y = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "y");
            if (!y.empty())
                compartmentGlyph->getBoundingBox()->setY(std::stod(y));
        }
        if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "fixed_width") == "true") {
            std::string width = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "width");
            if (!width.empty())
                compartmentGlyph->getBoundingBox()->setWidth(std::stod(width));
        }
        if (LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "fixed_height") == "true") {
            std::string height = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(compartmentGlyph, "height");
            if (!height.empty())
                compartmentGlyph->getBoundingBox()->setHeight(std::stod(height));
        }
    }
}

void autolayout_updateLayoutDimensions(Layout *layout) {
    if (!layoutContainsGlyphs(layout)) {
        layout->getDimensions()->setWidth(0);
        layout->getDimensions()->setHeight(0);
        return;
    } else {
        double maxX;
        double maxY;
        autolayout_extractExtents(layout, maxX, maxY);
        layout->getDimensions()->setWidth(maxX);
        layout->getDimensions()->setHeight(maxY);
    }
}

const bool autolayout_adjustLayoutDimensions(Layout *layout) {
    double desiredWidth = autolayout_getLayoutDimensionsDesiredWidth(layout);
    double widthGap = desiredWidth - layout->getDimensions()->width();
    double desiredHeight = autolayout_getLayoutDimensionsDesiredHeight(layout);
    double heightGap = desiredHeight - layout->getDimensions()->height();
    if (widthGap <= 0.1 * desiredWidth && heightGap <= 0.1 * desiredHeight) {
        autolayout_setLayoutDimensionsDesiredWidth(layout, layout->getDimensions()->width());
        autolayout_setLayoutDimensionsDesiredHeight(layout, layout->getDimensions()->height());
        return true;
    }

    return false;
}

const double autolayout_getLayoutDimensionsDesiredWidth(Layout *layout) {;
    std::string presetWidth = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout->getDimensions(), "width");
    if (!presetWidth.empty())
        return std::stod(presetWidth);

    return layout->getDimensions()->width();
}

void autolayout_setLayoutDimensionsDesiredWidth(Layout *layout, const double &width) {
    if (!LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout->getDimensions(), "width").empty())
        LIBSBMLNETWORK_CPP_NAMESPACE::user_data_setUserData(layout->getDimensions(), "width", std::to_string(width));
}

const double autolayout_getLayoutDimensionsDesiredHeight(Layout *layout) {
    std::string presetHeight = LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout->getDimensions(), "height");
    if (!presetHeight.empty())
        return std::stod(presetHeight);

    return layout->getDimensions()->height();
}

void autolayout_setLayoutDimensionsDesiredHeight(Layout *layout, const double &height) {
    if (!LIBSBMLNETWORK_CPP_NAMESPACE::user_data_getUserData(layout->getDimensions(), "height").empty())
        LIBSBMLNETWORK_CPP_NAMESPACE::user_data_setUserData(layout->getDimensions(), "height", std::to_string(height));
}

const bool autolayout_autolayoutMayStillConverge(Layout *layout) {
    if (autolayout_getGravity(layout) > 1.0)
        return true;

    return false;
}

void autolayout_extractExtents(Layout *layout, double &maxX, double &maxY) {
    double minX = INT_MAX;
    double minY = INT_MAX;
    maxX = INT_MIN;
    maxY = INT_MIN;
    for (int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
        autolayout_extractExtents(layout->getCompartmentGlyph(i)->getBoundingBox(), minX, minY, maxX, maxY);
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
        autolayout_extractExtents(layout->getSpeciesGlyph(i)->getBoundingBox(), minX, minY, maxX, maxY);
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (layout->getReactionGlyph(i)->isSetCurve())
            autolayout_extractExtents(layout->getReactionGlyph(i)->getCurve(), minX, minY, maxX, maxY);
        else
            autolayout_extractExtents(layout->getReactionGlyph(i)->getBoundingBox(), minX, minY, maxX, maxY);
    }
}

void autolayout_extractExtents(BoundingBox *boundingBox, double &minX, double &minY, double &maxX, double &maxY) {
    minX = std::min(minX, boundingBox->x());
    minY = std::min(minY, boundingBox->y());
    maxX = std::max(maxX, boundingBox->x() + boundingBox->width());
    maxY = std::max(maxY, boundingBox->y() + boundingBox->height());
}

void autolayout_extractExtents(Curve *reactionCurve, double &minX, double &minY, double &maxX, double &maxY) {
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