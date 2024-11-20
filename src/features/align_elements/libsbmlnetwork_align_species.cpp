#include "libsbmlnetwork_align_species.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../features/align_elements/libsbmlnetwork_align_element.h"
#include "../../features/error_log/libsbmlnetwork_error_log.h"
#include "../../features/fix_elements/libsbmlnetwork_fix_element_position.h"

#include <climits>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    void align_elements_alignGraphicalObjects(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const std::string& alignment, const bool ignoreFixedPositionNodes) {
        if (align_elements_isValidAlignment(alignment, layout)) {
            if (stringCompare(alignment, "top"))
                align_elements_alignGraphicalObjectsToTop(layout, graphicalObjects, ignoreFixedPositionNodes);
            else if (stringCompare(alignment, "vCenter"))
                align_elements_alignGraphicalObjectsToVerticalCenter(layout, graphicalObjects, ignoreFixedPositionNodes);
            else if (stringCompare(alignment, "bottom"))
                align_elements_alignGraphicalObjectsToBottom(layout, graphicalObjects, ignoreFixedPositionNodes);
            else if (stringCompare(alignment, "left"))
                align_elements_alignGraphicalObjectsToLeft(layout, graphicalObjects, ignoreFixedPositionNodes);
            else if (stringCompare(alignment, "hCenter"))
                align_elements_alignGraphicalObjectsToHorizontalCenter(layout, graphicalObjects, ignoreFixedPositionNodes);
            else if (stringCompare(alignment, "right"))
                align_elements_alignGraphicalObjectsToRight(layout, graphicalObjects, ignoreFixedPositionNodes);
            else if (stringCompare(alignment, "circular") || stringCompare(alignment, "circle"))
                align_elements_alignGraphicalObjectsCircularly(layout, graphicalObjects, ignoreFixedPositionNodes);
        }
    }

    void align_elements_alignGraphicalObjectsToTop(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        try {
            double minY = align_elements_getTopAlignmentPosition(graphicalObjects, ignoreFixedPositionNodes);
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                setPositionY(layout, graphicalObjects.at(i), minY);
        }
        catch (const std::invalid_argument& e) {
            error_log_addErrorToLog(layout, e.what());
        }
    }

    const double align_elements_getTopAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        if (ignoreFixedPositionNodes)
            return align_elements_getMinPositionY(graphicalObjects);
        std::vector<GraphicalObject*> fixedPositionGraphicalObjects = fix_elements_getFixedPositionGraphicalObjects(graphicalObjects);
        if (fixedPositionGraphicalObjects.size() == 0)
            return align_elements_getMinPositionY(graphicalObjects);
        else if (fixedPositionGraphicalObjects.size() == 1)
            return fixedPositionGraphicalObjects.at(0)->getBoundingBox()->y();
        else
            throw std::invalid_argument("error: Multiple graphical objects in your align list have fixed position, so the alignment cannot be applied. Use the ignoreFixedPositionNodes option to ignore fixed position nodes.\n");
    }

    void align_elements_alignGraphicalObjectsToHorizontalCenter(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        try {
            double centerX = align_elements_getHorizontalCenterAlignmentPosition(graphicalObjects, ignoreFixedPositionNodes);
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                setPositionX(layout, graphicalObjects.at(i), centerX);
        }
        catch (const std::invalid_argument& e) {
            error_log_addErrorToLog(layout, e.what());
        }
    }

    const double align_elements_getHorizontalCenterAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        if (ignoreFixedPositionNodes)
            return 0.5 * (align_elements_getMinPositionX(graphicalObjects) + align_elements_getMaxPositionX(graphicalObjects));
        std::vector<GraphicalObject*> fixedPositionGraphicalObjects = fix_elements_getFixedPositionGraphicalObjects(graphicalObjects);
        if (fixedPositionGraphicalObjects.size() == 0)
            return 0.5 * (align_elements_getMinPositionX(graphicalObjects) + align_elements_getMaxPositionX(graphicalObjects));
        else if (fixedPositionGraphicalObjects.size() == 1)
            return fixedPositionGraphicalObjects.at(0)->getBoundingBox()->x();
        else
            throw std::invalid_argument("error: Multiple graphical objects in your align list have fixed position, so the alignment cannot be applied. Use the ignoreFixedPositionNodes option to ignore fixed position nodes.\n");
    }

    void align_elements_alignGraphicalObjectsToBottom(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        try {
            double maxY = align_elements_getBottomAlignmentPosition(graphicalObjects, ignoreFixedPositionNodes);
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                setPositionY(layout, graphicalObjects.at(i), maxY);
        }
        catch (const std::invalid_argument& e) {
            error_log_addErrorToLog(layout, e.what());
        }
    }

    const double align_elements_getBottomAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        if (ignoreFixedPositionNodes)
            return align_elements_getMaxPositionY(graphicalObjects);
        std::vector<GraphicalObject*> fixedPositionGraphicalObjects = fix_elements_getFixedPositionGraphicalObjects(graphicalObjects);
        if (fixedPositionGraphicalObjects.size() == 0)
            return align_elements_getMaxPositionY(graphicalObjects);
        else if (fixedPositionGraphicalObjects.size() == 1)
            return fixedPositionGraphicalObjects.at(0)->getBoundingBox()->y();
        else
            throw std::invalid_argument("error: Multiple graphical objects in your align list have fixed position, so the alignment cannot be applied. Use the ignoreFixedPositionNodes option to ignore fixed position nodes.\n");
    }

    void align_elements_alignGraphicalObjectsToLeft(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        try {
            double minX = align_elements_getLeftAlignmentPosition(graphicalObjects, ignoreFixedPositionNodes);
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                setPositionX(layout, graphicalObjects.at(i), minX);
        }
        catch (const std::invalid_argument& e) {
            error_log_addErrorToLog(layout, e.what());
        }
    }

    const double align_elements_getLeftAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        if (ignoreFixedPositionNodes)
            return align_elements_getMinPositionX(graphicalObjects);
        std::vector<GraphicalObject*> fixedPositionGraphicalObjects = fix_elements_getFixedPositionGraphicalObjects(graphicalObjects);
        if (fixedPositionGraphicalObjects.size() == 0)
            return align_elements_getMinPositionX(graphicalObjects);
        else if (fixedPositionGraphicalObjects.size() == 1)
            return fixedPositionGraphicalObjects.at(0)->getBoundingBox()->x();
        else
            throw std::invalid_argument("error: Multiple graphical objects in your align list have fixed position, so the alignment cannot be applied. Use the ignoreFixedPositionNodes option to ignore fixed position nodes.\n");
    }

    void align_elements_alignGraphicalObjectsToVerticalCenter(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        try {
            double centerY = align_elements_getVerticalCenterAlignmentPosition(graphicalObjects, ignoreFixedPositionNodes);
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                setPositionY(layout, graphicalObjects.at(i), centerY);
        }
        catch (const std::invalid_argument& e) {
            error_log_addErrorToLog(layout, e.what());
        }
    }

    const double align_elements_getVerticalCenterAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        if (ignoreFixedPositionNodes)
            return 0.5 * (align_elements_getMinPositionY(graphicalObjects) + align_elements_getMaxPositionY(graphicalObjects));
        std::vector<GraphicalObject*> fixedPositionGraphicalObjects = fix_elements_getFixedPositionGraphicalObjects(graphicalObjects);
        if (fixedPositionGraphicalObjects.size() == 0)
            return 0.5 * (align_elements_getMinPositionY(graphicalObjects) + align_elements_getMaxPositionY(graphicalObjects));
        else if (fixedPositionGraphicalObjects.size() == 1)
            return fixedPositionGraphicalObjects.at(0)->getBoundingBox()->y();
        else
            throw std::invalid_argument("error: Multiple graphical objects in your align list have fixed position, so the alignment cannot be applied. Use the ignoreFixedPositionNodes option to ignore fixed position nodes.\n");
    }

    void align_elements_alignGraphicalObjectsToRight(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        try {
            double maxX = align_elements_getRightAlignmentPosition(graphicalObjects, ignoreFixedPositionNodes);
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                setPositionX(layout, graphicalObjects.at(i), maxX);
        }
        catch (const std::invalid_argument& e) {
            error_log_addErrorToLog(layout, e.what());
        }
    }

    const double align_elements_getRightAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        if (ignoreFixedPositionNodes)
            return align_elements_getMaxPositionX(graphicalObjects);
        std::vector<GraphicalObject*> fixedPositionGraphicalObjects = fix_elements_getFixedPositionGraphicalObjects(graphicalObjects);
        if (fixedPositionGraphicalObjects.size() == 0)
            return align_elements_getMaxPositionX(graphicalObjects);
        else if (fixedPositionGraphicalObjects.size() == 1)
            return fixedPositionGraphicalObjects.at(0)->getBoundingBox()->x();
        else
            throw std::invalid_argument("error: Multiple graphical objects in your align list have fixed position, so the alignment cannot be applied. Use the ignoreFixedPositionNodes option to ignore fixed position nodes.\n");
    }

    void align_elements_alignGraphicalObjectsCircularly(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes) {
        double radius = graphicalObjects.size() * 50.0;
        double angle = 2 * M_PI / graphicalObjects.size();
        double centerX = std::max(radius, 0.5 * (align_elements_getMinCenterX(graphicalObjects) + align_elements_getMaxCenterX(graphicalObjects)));
        double centerY = std::max(radius, 0.5 * (align_elements_getMinCenterY(graphicalObjects) + align_elements_getMaxCenterY(graphicalObjects)));
        for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
            setPositionX(layout, graphicalObjects.at(i), centerX + radius * cos(i * angle) - 0.5 * graphicalObjects.at(i)->getBoundingBox()->width());
            setPositionY(layout, graphicalObjects.at(i), centerY + radius * sin(i * angle) - 0.5 * graphicalObjects.at(i)->getBoundingBox()->height());
        }
    }

    void align_elements_distributeGraphicalObjects(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const std::string& direction, const double& spacing) {
        if (align_elements_isValidDistributionDirection(direction, layout)) {
            if (stringCompare(direction, "horizontal"))
                align_elements_distributeGraphicalObjectsHorizontally(layout, graphicalObjects, spacing);
            else if (stringCompare(direction, "vertical"))
                align_elements_distributeGraphicalObjectsVertically(layout, graphicalObjects, spacing);
        }
    }

    void align_elements_distributeGraphicalObjectsHorizontally(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& spacing) {
        if (graphicalObjects.size() < 2)
            return;
        double minX = align_elements_getMinPositionX(graphicalObjects);
        double maxX = align_elements_getMaxPositionX(graphicalObjects);
        double minY = align_elements_getMinPositionY(graphicalObjects);
        double maxY = align_elements_getMaxPositionY(graphicalObjects);
        double distance = align_elements_findDistributionDistance(minX, maxX, graphicalObjects.size(), spacing);
        if (graphicalObjects.size() % 2 == 0) {
            for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
                setPositionX(layout, graphicalObjects.at(i), minX + i * distance);
                setPositionY(layout, graphicalObjects.at(i), 0.5 * (minY + maxY));
            }
        }
        else {
            for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
                setPositionX(layout, graphicalObjects.at(i),
                             0.5 * (minX + maxX) + (i - 0.5 * (graphicalObjects.size() - 1)) * distance);
                setPositionY(layout, graphicalObjects.at(i), 0.5 * (minY + maxY));
            }
        }
    }

    void align_elements_distributeGraphicalObjectsVertically(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& spacing) {
        if (graphicalObjects.size() < 2)
            return;
        double minX = align_elements_getMinPositionX(graphicalObjects);
        double maxX = align_elements_getMaxPositionX(graphicalObjects);
        double minY = align_elements_getMinPositionY(graphicalObjects);
        double maxY = align_elements_getMaxPositionY(graphicalObjects);
        double distance = align_elements_findDistributionDistance(minY, maxY, graphicalObjects.size(), spacing);

        if (graphicalObjects.size() % 2 == 0) {
            for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
                setPositionX(layout, graphicalObjects.at(i), 0.5 * (minX + maxX));
                setPositionY(layout, graphicalObjects.at(i), minY + i * distance);
            }
        }
        else {
            for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
                setPositionX(layout, graphicalObjects.at(i), 0.5 * (minX + maxX));
                setPositionY(layout, graphicalObjects.at(i),
                             0.5 * (minY + maxY) + (i - 0.5 * (graphicalObjects.size() - 1)) * distance);
            }
        }
    }

    const double align_elements_findDistributionDistance(const double& minPosition, const double& maxPosition, const unsigned int& numGraphicalObjects, const double& spacing) {
        double distance = 0;
        if (spacing > 0)
            distance = spacing;
        else
            distance = (maxPosition - minPosition) / (numGraphicalObjects - 1);

        return distance;
    }

    const double align_elements_getMinPositionX(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double minX = INT_MAX;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->x() < minX)
                    minX = graphicalObjects.at(i)->getBoundingBox()->x();

            return minX;
        }

        return 0.0;
    }

    const double align_elements_getMinPositionY(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double minY = INT_MAX;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->y() < minY)
                    minY = graphicalObjects.at(i)->getBoundingBox()->y();

            return minY;
        }

        return 0.0;
    }

    const double align_elements_getMaxPositionX(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double maxX = INT_MIN;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->x() > maxX)
                    maxX = graphicalObjects.at(i)->getBoundingBox()->x();

            return maxX;
        }

        return 0.0;
    }

    const double align_elements_getMaxPositionY(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double maxY = INT_MIN;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->y() > maxY)
                    maxY = graphicalObjects.at(i)->getBoundingBox()->y();

            return maxY;
        }

        return 0.0;
    }

    const double align_elements_getMinCenterX(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double minX = INT_MAX;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width() < minX)
                    minX = graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width();

            return minX;
        }

        return 0.0;
    }

    const double align_elements_getMinCenterY(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double minY = INT_MAX;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height() < minY)
                    minY = graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height();

            return minY;
        }

        return 0.0;
    }

    const double align_elements_getMaxCenterX(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double maxX = INT_MIN;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width() > maxX)
                    maxX = graphicalObjects.at(i)->getBoundingBox()->x() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->width();

            return maxX;
        }

        return 0.0;
    }

    const double align_elements_getMaxCenterY(std::vector<GraphicalObject*> graphicalObjects) {
        if (graphicalObjects.size()) {
            double maxY = INT_MIN;
            for (unsigned int i = 0; i < graphicalObjects.size(); i++)
                if (graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height() > maxY)
                    maxY = graphicalObjects.at(i)->getBoundingBox()->y() + 0.5 * graphicalObjects.at(i)->getBoundingBox()->height();

            return maxY;
        }

        return 0.0;
    }

}