#include "libsbml_ne_autolayout_connection.h"
#include "libsbml_ne_autolayout_node.h"
#include "libsbml_ne_autolayout_curve.h"

AutoLayoutConnection::AutoLayoutConnection(Layout* layout, ReactionGlyph* reactionGlyph) : AutoLayoutObjectBase(layout) {
    _reactionGlyph = reactionGlyph;
    setCentroidNode();
    setCurves();
}

const std::string AutoLayoutConnection::getId() {
    return _reactionGlyph->getId();
}

void AutoLayoutConnection::setCentroidNode() {
    _centroidNode = new AutoLayoutCentroidNode(_layout, _reactionGlyph);
}

AutoLayoutObjectBase* AutoLayoutConnection::getCentroidNode() {
    return _centroidNode;
}

void AutoLayoutConnection::setCurves() {
    for (int i = 0; i < _reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
        _curves.push_back(new AutoLayoutCurve(_layout, _reactionGlyph->getSpeciesReferenceGlyph(i)));
}

std::vector<AutoLayoutObjectBase*> AutoLayoutConnection::getCurves() {
    return _curves;
}

const int AutoLayoutConnection::getNumNonModifierCurves() {
    int numNonModifierCurves = 0;
    for (int curveIndex = 0; curveIndex < _curves.size(); curveIndex++) {
        if (((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_PRODUCT ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_SIDEPRODUCT ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_SUBSTRATE ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_SIDESUBSTRATE ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_UNDEFINED)
            numNonModifierCurves++;
    }

    return numNonModifierCurves;
}

std::vector<std::string> AutoLayoutConnection::getNodeIds() {
    std::vector<std::string> nodeIds;
    for (int curveIndex = 0; curveIndex < _curves.size(); curveIndex++) {
        if (std::find(nodeIds.begin(), nodeIds.end(), ((AutoLayoutCurve*)_curves.at(curveIndex))->getNodeId()) == nodeIds.end())
            nodeIds.push_back(((AutoLayoutCurve*)_curves.at(curveIndex))->getNodeId());
    }

    return nodeIds;
}

std::vector<std::string> AutoLayoutConnection::getNonModifierNodeIds() {
    std::vector<std::string> nodeIds;
    for (int curveIndex = 0; curveIndex < _curves.size(); curveIndex++) {
        if (((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_PRODUCT ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_SIDEPRODUCT ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_SUBSTRATE ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_SIDESUBSTRATE ||
            ((AutoLayoutCurve*)_curves.at(curveIndex))->getRole() == SPECIES_ROLE_UNDEFINED) {
            if (std::find(nodeIds.begin(), nodeIds.end(), ((AutoLayoutCurve*)_curves.at(curveIndex))->getNodeId()) == nodeIds.end())
                nodeIds.push_back(((AutoLayoutCurve*)_curves.at(curveIndex))->getNodeId());
        }
    }

    return nodeIds;
}

