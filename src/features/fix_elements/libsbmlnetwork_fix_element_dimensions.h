#ifndef __LIBSBMLNETWORK_FIX_ELEMENT_DIMENSIONS_H
#define __LIBSBMLNETWORK_FIX_ELEMENT_DIMENSIONS_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

void fix_elements_fixGraphicalObjectWidth(GraphicalObject* graphicalObject);

void fix_elements_unfixGraphicalObjectWidth(GraphicalObject* graphicalObject);

void fix_elements_fixGraphicalObjectHeight(GraphicalObject* graphicalObject);

void fix_elements_unfixGraphicalObjectHeight(GraphicalObject* graphicalObject);

}

#endif
