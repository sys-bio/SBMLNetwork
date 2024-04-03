#ifndef __LIBSBML_NE_AUTOLAYOUT_CONNECTION__H
#define __LIBSBML_NE_AUTOLAYOUT_CONNECTION__H

#include "libsbml_ne_autolayout_object_base.h"

class AutoLayoutConnection : public AutoLayoutObjectBase {
public:

    AutoLayoutConnection(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const bool& useNameAsTextLabel);

    const std::string getId() override;

    void setCentroidNode(const bool& useNameAsTextLabel);

    AutoLayoutObjectBase* getCentroidNode();

    void setCurves();

    std::vector<AutoLayoutObjectBase*> getCurves();

    const int getNumNonModifierCurves();

    std::vector<std::string> getNodeIds();

    std::vector<std::string> getNonModifierNodeIds();

protected:

    ReactionGlyph* _reactionGlyph;
    AutoLayoutObjectBase* _centroidNode;
    std::vector<AutoLayoutObjectBase*> _curves;
};

#endif