#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_CONNECTION__H
#define __LIBSBMLNETWORK_AUTOLAYOUT_CONNECTION__H

#include "libsbmlnetwork_autolayout_object_base.h"

class AutoLayoutConnection : public AutoLayoutObjectBase {
public:

    AutoLayoutConnection(Model* model, Layout* layout, ReactionGlyph* reactionGlyph);

    ~AutoLayoutConnection();

    const std::string getId() override;

    void updateFixedPositionStatus();

    void setCentroidNode();

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