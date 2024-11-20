#ifndef __LIBSBMLNETWORK_ALIAS_ELEMENT_H
#define __LIBSBMLNETWORK_ALIAS_ELEMENT_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    void alias_element_setAliasGraphicalObjectPosition(GraphicalObject* aliasGraphicalObject, GraphicalObject* graphicalObject, const double& padding = 0.0);

}

#endif
