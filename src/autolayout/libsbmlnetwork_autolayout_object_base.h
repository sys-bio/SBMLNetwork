#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_OBJECT_BASE__H
#define __LIBSBMLNETWORK_AUTOLAYOUT_OBJECT_BASE__H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#include "sbml/packages/layout/common/LayoutExtensionTypes.h"
#endif

using namespace libsbml;

class AutoLayoutObjectBase {
public:

    AutoLayoutObjectBase(Model* model, Layout* layout);

    virtual ~AutoLayoutObjectBase();

    virtual const std::string getId() = 0;

protected:

    Model* _model;
    Layout* _layout;
};

#endif
