#ifndef __LIBSBMLNETWORK_UPDATE_CURVES_H
#define __LIBSBMLNETWORK_UPDATE_CURVES_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    int update_curves_updateLayoutCurves(SBMLDocument* document, Layout* layout);
}

#endif
