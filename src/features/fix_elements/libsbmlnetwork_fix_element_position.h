#ifndef __LIBSBMLNETWORK_FIX_ELEMENTS_POSITION_H
#define __LIBSBMLNETWORK_FIX_ELEMENTS_POSITION_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

#include <set>

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void fix_elements_fixGraphicalObjectsPosition(Layout* layout, std::set<std::pair<std::string, int> > fixedElementNodesSet, const bool resetFixedPositionElements);

void fix_elements_fixCompartmentGlyphsPosition(Layout* layout, const bool resetFixedPositionElements);

void fix_elements_fixSpeciesGlyphsPosition(Layout* layout, std::set<std::pair<std::string, int> > fixedElementNodesSet, const bool resetFixedPositionElements);

void fix_elements_fixReactionGlyphsPosition(Layout* layout, std::set<std::pair<std::string, int> > fixedElementNodesSet, const bool resetFixedPositionElements);

void fix_elements_fixGraphicalObjectPosition(GraphicalObject* graphicalObject);

void fix_elements_unfixGraphicalObjectPosition(GraphicalObject* graphicalObject);

std::vector<GraphicalObject*> fix_elements_getFixedPositionGraphicalObjects(std::vector<GraphicalObject*> graphicalObjects);

}

#endif
