#ifndef __LIBSBML_NE_AUTOLAYOUT_CURVE__H
#define __LIBSBML_NE_AUTOLAYOUT_CURVE__H

#include "libsbml_ne_autolayout_object_base.h"

class AutoLayoutCurve : public AutoLayoutObjectBase {
public:

    AutoLayoutCurve(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph);

    const std::string getId() override;

    const std::string getNodeId();

    const std::string getRole();

protected:

    SpeciesReferenceGlyph* _speciesReferenceGlyph;
};

#endif
