#ifndef __LIBSBMLNETWORK_AUTOLAYOUT_NODE__H
#define __LIBSBMLNETWORK_AUTOLAYOUT_NODE__H

#include "libsbmlnetwork_autolayout_object_base.h"
#include "libsbmlnetwork_autolayout_point.h"

class AutoLayoutNodeBase : public AutoLayoutObjectBase {
public:

    AutoLayoutNodeBase(Model* model, Layout* layout, const bool& useNameAsTextLabel);

    virtual GraphicalObject* getGraphicalObject() = 0;

    virtual const double getX() = 0;

    virtual void setX(const double& x) = 0;

    virtual const double getY() = 0;

    virtual void setY(const double& y) = 0;

    virtual const double getWidth() = 0;

    virtual void setWidth(const double& width) = 0;

    virtual const double getHeight() = 0;

    virtual void setHeight(const double& height) = 0;

    void updateDimensions();

    virtual const double calculateWidth() = 0;

    virtual const double calculateHeight() = 0;

    void setPosition(const AutoLayoutPoint position);

    const AutoLayoutPoint getPosition();

    const double getDisplacementX();

    void setDisplacementX(const double& dx);

    const double getDisplacementY();

    void setDisplacementY(const double& dy);

    void setDisplacement(const AutoLayoutPoint displacement);

    const AutoLayoutPoint getDisplacement();

    const int getDegree();

    void incrementDegree();

    void setLocked(const bool& locked);

    const bool isLocked();

protected:

    double _displacementX;
    double _displacementY;
    int _degree;
    bool _locked;
    bool _useNameAsTextLabel;
};

class AutoLayoutNode : public AutoLayoutNodeBase {
public:

    AutoLayoutNode(Model* model, Layout* layout, SpeciesGlyph* speciesGlyph, const bool& useNameAsTextLabel);

    const std::string getId() override;

    GraphicalObject* getGraphicalObject() override;

    const double getX() override;

    void setX(const double& x) override;

    const double getY() override;

    void setY(const double& y) override;

    const double getWidth() override;

    void setWidth(const double& width) override;

    const double getHeight() override;

    void setHeight(const double& height) override;

    const double calculateWidth() override;

    const double calculateHeight() override;

protected:

    SpeciesGlyph* _speciesGlyph;
};

class AutoLayoutCentroidNode : public AutoLayoutNodeBase {
public:

    AutoLayoutCentroidNode(Model* model, Layout* layout, ReactionGlyph* reactionGlyph, const bool& useNameAsTextLabel);

    const std::string getId() override;

    GraphicalObject* getGraphicalObject() override;

    const double getX() override;

    void setX(const double& x) override;

    const double getY() override;

    void setY(const double& y) override;

    const double getWidth() override;

    void setWidth(const double& width) override;

    const double getHeight() override;

    void setHeight(const double& height) override;

    const double calculateWidth() override;

    const double calculateHeight() override;

protected:

    ReactionGlyph* _reactionGlyph;
};

const double calculateSpeciesGlyphDefaultWidth(Model *model, SpeciesGlyph *speciesGlyph);

const double calculateSpeciesGlyphDefaultHeight(SpeciesGlyph *speciesGlyph, const double &speciesWidth);

#endif
