#ifndef __LIBSBMLNETWORK_DEFAULTS_H
#define __LIBSBMLNETWORK_DEFAULTS_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void defaults_setDefaultLayoutId(Layout* layout);

const std::string defaults_getDefaultLayoutId();

void defaults_setDefaultLayoutDimensions(Layout* layout);

CompartmentGlyph* defaults_getDefaultCompartmentGlyph(Layout* layout);

const double defaults_getSpeciesDefaultWidth();

const double defaults_getSpeciesDefaultHeight();

const double defaults_getEmptySpeciesDefaultRadius();

const double defaults_getReactionDefaultWidth();

const double defaults_getReactionDefaultHeight();

const double defaults_getDefaultAutoLayoutPadding();

const double defaults_getAliasSpeciesGlyphPadding();

const double defaults_getAliasReactionGlyphPadding();

}

#endif
