#ifndef __LIBSBML_NE_AUTOLAYOUT_CONNECTION__H
#define __LIBSBML_NE_AUTOLAYOUT_CONNECTION__H

#include "libsbml_ne_autolayout_object_base.h"

class AutoLayoutConnection : public AutoLayoutObjectBase {
public:

    AutoLayoutConnection(Layout* layout, ReactionGlyph* reactionGlyph);

    const std::string getId() override;

    const std::string getCentroidNodeId();

    void setCurves();

    std::vector<AutoLayoutObjectBase*> getCurves();

    const int getNumNonModifierCurves();

protected:

    ReactionGlyph* _reactionGlyph;
    std::vector<AutoLayoutObjectBase*> _curves;
};

#endif
