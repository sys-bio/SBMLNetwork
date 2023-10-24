#include "libsbml_ne_autolayout_curve.h"
#include "libsbml_ne_autolayout_node.h"
#include "../libsbml_ne_layout_helpers.h"

AutoLayoutCurve::AutoLayoutCurve(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph) : AutoLayoutObjectBase(layout) {
    _speciesReferenceGlyph = speciesReferenceGlyph;
}

const std::string AutoLayoutCurve::getId() {
    return _speciesReferenceGlyph->getId();
}

const std::string AutoLayoutCurve::getNodeId() {
    return _speciesReferenceGlyph->getSpeciesGlyphId();
}

const std::string AutoLayoutCurve::getRole() {
    return _speciesReferenceGlyph->getRoleString();
}
