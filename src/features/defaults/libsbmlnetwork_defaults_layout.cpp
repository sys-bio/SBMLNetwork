#include "libsbmlnetwork_defaults_layout.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

void defaults_setDefaultLayoutId(Layout* layout) {
    if (!layout->isSetId())
        layout->setId(defaults_getDefaultLayoutId());
}

const std::string defaults_getDefaultLayoutId() {
    return  "libSBMLNetwork_Layout";
}

void defaults_setDefaultLayoutDimensions(Layout* layout) {
    Dimensions* dimensions = layout->getDimensions();
    if (!dimensions) {
        dimensions = new Dimensions(layout->getLevel(), layout->getVersion(), layout->getPackageVersion());
        layout->setDimensions(dimensions);
    }
    if (dimensions->getWidth() < 0.0001)
        dimensions->setWidth(1024.0);
    if (dimensions->getHeight() < 0.0001)
        dimensions->setHeight(1024.0);
}

CompartmentGlyph* defaults_getDefaultCompartmentGlyph(Layout* layout) {
    if (layout->getNumCompartmentGlyphs() == 1 && layout->getCompartmentGlyph(0)->getCompartmentId() == "default_compartment")
        return layout->getCompartmentGlyph(0);

    return NULL;
}

const double defaults_getSpeciesDefaultWidth() {
    return 60.0;
}

const double defaults_getSpeciesDefaultHeight() {
    return 36.0;
}

const double defaults_getEmptySpeciesDefaultWidth() {
    return 30.0;
}

const double defaults_getEmptySpeciesDefaultHeight() {
    return 30.0;
}

const double defaults_getReactionDefaultWidth() {
    return 20.0;
}

const double defaults_getReactionDefaultHeight() {
    return 20.0;
}

const double defaults_getDefaultAutoLayoutPadding() {
    return 30.0;
}

const double defaults_getAliasSpeciesGlyphPadding() {
    return 30.0;
}

const double defaults_getAliasReactionGlyphPadding() {
    return 30.0;
}

}
