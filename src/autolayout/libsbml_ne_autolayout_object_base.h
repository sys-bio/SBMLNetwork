#ifndef __LIBSBML_NE_AUTOLAYOUT_OBJECT_BASE__H
#define __LIBSBML_NE_AUTOLAYOUT_OBJECT_BASE__H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

class AutoLayoutObjectBase {
public:

    AutoLayoutObjectBase(Layout* layout);

    virtual const std::string getId() = 0;

protected:

    Layout* _layout;
};

#endif
