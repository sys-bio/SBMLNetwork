#ifndef __LIBSBMLNETWORK_ALIGN_SPECIES_H
#define __LIBSBMLNETWORK_ALIGN_SPECIES_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    void align_elements_alignGraphicalObjects(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const std::string& alignment, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsToTop(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    const double align_elements_getTopAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsToVerticalCenter(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    const double align_elements_getVerticalCenterAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsToBottom(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    const double align_elements_getBottomAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsToLeft(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    const double align_elements_getLeftAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsToHorizontalCenter(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    const double align_elements_getHorizontalCenterAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsToRight(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    const double align_elements_getRightAlignmentPosition(std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_alignGraphicalObjectsCircularly(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const bool ignoreFixedPositionNodes);

    void align_elements_distributeGraphicalObjects(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const std::string& direction, const double& spacing);

    void align_elements_distributeGraphicalObjectsHorizontally(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& spacing);

    void align_elements_distributeEvenGraphicalObjectsHorizontally(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& minX, const double& maxX, const double& distance);

    void align_elements_distributeOddGraphicalObjectsHorizontally(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& minX, const double& maxX, const double& distance);

    void align_elements_distributeGraphicalObjectsVertically(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& spacing);

    void align_elements_distributeEvenGraphicalObjectsVertically(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& minY, const double& maxY, const double& distance);

    void align_elements_distributeOddGraphicalObjectsVertically(Layout* layout, std::vector<GraphicalObject*> graphicalObjects, const double& minY, const double& maxY, const double& distance);

    const double align_elements_findDistributionDistance(const double& minPosition, const double& maxPosition, const unsigned int& numGraphicalObjects, const double& spacing);

    const double align_elements_getMinPositionX(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMinPositionY(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMaxPositionX(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMaxPositionY(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMinCenterX(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMinCenterY(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMaxCenterX(std::vector<GraphicalObject*> graphicalObjects);

    const double align_elements_getMaxCenterY(std::vector<GraphicalObject*> graphicalObjects);

}

#endif
