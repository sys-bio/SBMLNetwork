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


