#ifndef __LIBSBML_NE_UTIL_HELPERS_H_
#define __LIBSBML_NE_UTIL_HELPERS_H_

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#include "sbml/packages/render/common/RenderExtensionTypes.h"
#endif

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void mergeListsOfGraphicalObjects(ListOfGraphicalObjects list1, ListOfGraphicalObjects list2);

}

#endif
