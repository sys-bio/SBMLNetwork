#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"
#include "libsbml_ne_autolayout.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {


ListOfLayouts* getListOfLayouts(SBMLDocument* document) {
    if (document) {
        LayoutModelPlugin* layoutModelPlugin = getLayoutModelPlugin(document);
        if (layoutModelPlugin)
            return layoutModelPlugin->getListOfLayouts();
    }
    
    return NULL;
}

int addLayout(SBMLDocument* document, Layout* layout) {
    if (document && layout) {
        LayoutModelPlugin* layoutModelPlugin = enableAndGetLayoutModelPlugin(document);
        if (layoutModelPlugin) {
            layoutModelPlugin->addLayout(layout);
            return 0;
        }
    }
    
    return -1;
}

Layout* createLayout(SBMLDocument* document) {
    if (document) {
        LayoutModelPlugin* layoutModelPlugin = enableAndGetLayoutModelPlugin(document);
        if (layoutModelPlugin)
            return layoutModelPlugin->createLayout();
    }
    
    return NULL;
}

int removeLayouts(SBMLDocument* document) {
    ListOfLayouts* listOfLayouts = getListOfLayouts(document);
    if (listOfLayouts) {
        while (listOfLayouts->size())
            listOfLayouts->remove(0);
        return 0;
    }
        
    return -1;
}

int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout) {
    if (document && layout) {
        LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(document->getLevel(), document->getVersion());
        layout->setId("libSBML_NetworkEditor_Layout");
        layout->setDimensions(new Dimensions(layoutPkgNamespaces, 1024.0, 1024.0));
        Model* model = document->getModel();
        if (model) {
            setCompartmentGlyphs(model, layout, layoutPkgNamespaces);
            setSpeciesGlyphs(model, layout, layoutPkgNamespaces);
            setReactionGlyphs(model, layout, layoutPkgNamespaces);
            locateGlyphs(model, layout);
            setCompartmentTextGlyphs(layout, layoutPkgNamespaces);
            setSpeciesTextGlyphs(layout, layoutPkgNamespaces);
            return 0;
        }
    }
    
    return -1;
}

GraphicalObject* getGraphicalObject(Layout* layout, const std::string& graphicalObjectId) {
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            if (layout->getCompartmentGlyph(i)->getId() == graphicalObjectId)
                return layout->getCompartmentGlyph(i);
        }
        
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            if (layout->getSpeciesGlyph(i)->getId() == graphicalObjectId)
                return layout->getSpeciesGlyph(i);
        }
        
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            if (layout->getReactionGlyph(i)->getId() == graphicalObjectId)
                return layout->getReactionGlyph(i);
            
            ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
            for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
                if (reactionGlyph->getSpeciesReferenceGlyph(j)->getId() == graphicalObjectId)
                    return reactionGlyph->getSpeciesReferenceGlyph(i);
            }
        }
    }
    
    return NULL;
}

const double getPositionX(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return getPositionX(graphicalObject->getBoundingBox());
    
    return 0.0;
}

const double getPositionX(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->x();

    return 0.0;
}

int setPositionX(GraphicalObject* graphicalObject, const double& x) {
    if (graphicalObject)
        return setPositionX(graphicalObject->getBoundingBox(), x);
    
    return -1;
}

int setPositionX(BoundingBox* boundingBox, const double& x) {
    if (boundingBox) {
        boundingBox->setX(x);
        return 0;
    }

    return -1;
}

const double getPositionY(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return getPositionY(graphicalObject->getBoundingBox());
    
    return 0.0;
}

const double getPositionY(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->y();

    return 0.0;
}

int setPositionY(GraphicalObject* graphicalObject, const double& y) {
    if (graphicalObject)
        setPositionY(graphicalObject->getBoundingBox(), y);
    
    return -1;
}

int setPositionY(BoundingBox* boundingBox, const double& y) {
    if (boundingBox) {
        boundingBox->setY(y);
        return 0;
    }

    return -1;
}

const double getDimensionWidth(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return getDimensionWidth(graphicalObject->getBoundingBox());
    
    return 0.0;
}

const double getDimensionWidth(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->width();

    return 0.0;
}

int setDimensionWidth(GraphicalObject* graphicalObject, const double& width) {
    if (graphicalObject)
        setDimensionWidth(graphicalObject->getBoundingBox(), width);
    
    return -1;
}

int setDimensionWidth(BoundingBox* boundingBox, const double& width) {
    if (boundingBox) {
        boundingBox->setWidth(width);
        return 0;
    }

    return -1;
}

const double getDimensionHeight(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return getDimensionHeight(graphicalObject->getBoundingBox());
    
    return 0.0;
}

const double getDimensionHeight(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->height();

    return 0.0;
}

int setDimensionHeight(GraphicalObject* graphicalObject, const double& height) {
    if (graphicalObject)
        return setDimensionHeight(graphicalObject->getBoundingBox(), height);

    return -1;
}

int setDimensionHeight(BoundingBox* boundingBox, const double& height) {
    if (boundingBox) {
        boundingBox->setHeight(height);
        return 0;
    }

    return -1;
}

Curve* getCurve(GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        ReactionGlyph* reactionGlyph = dynamic_cast<ReactionGlyph*>(graphicalObject);
        if (reactionGlyph)
            return  reactionGlyph->getCurve();
        SpeciesReferenceGlyph* speciesReferenceGlyph = dynamic_cast<SpeciesReferenceGlyph*>(graphicalObject);
        if (speciesReferenceGlyph)
            return speciesReferenceGlyph->getCurve();
    }

    return  NULL;
}

const unsigned int getNumCurveSegments(GraphicalObject* graphicalObject) {
    return getNumCurveSegments(getCurve(graphicalObject));
}

const unsigned int getNumCurveSegments(Curve* curve) {
    if (curve)
        return curve->getNumCurveSegments();

    return 0;
}

LineSegment* getCurveSegment(GraphicalObject* graphicalObject, unsigned int index) {
    if (index < getNumCurveSegments(graphicalObject))
        return getCurve(graphicalObject)->getCurveSegment(index);

    return  NULL;
}

LineSegment* getCurveSegment(Curve* curve, unsigned int index) {
    if (index < getNumCurveSegments(curve))
        return curve->getCurveSegment(index);

    return  NULL;
}

bool isCubicBezier(LineSegment* lineSegment) {
    if (lineSegment) {
        CubicBezier* cubicBezier = dynamic_cast<CubicBezier*>(cubicBezier);
        if (cubicBezier)
            return  true;
    }

    return  false;
}

const double getCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentStartPointX(getCurve(graphicalObject), n);
}

const double getCurveSegmentStartPointX(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getStart()->x();

    return  0.0;
}

int setCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentStartPointX(getCurve(graphicalObject), n, x);
}

int setCurveSegmentStartPointX(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getStart()->setX(x);

    return  0.0;
}

const double getCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentStartPointY(getCurve(graphicalObject), n);
}

const double getCurveSegmentStartPointY(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getStart()->y();

    return  0.0;
}

int setCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentStartPointY(getCurve(graphicalObject), n, y);
}

int setCurveSegmentStartPointY(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getStart()->setY(y);

    return  0.0;
}

const double getCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentEndPointX(getCurve(graphicalObject), n);
}

const double getCurveSegmentEndPointX(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getEnd()->x();

    return  0.0;
}

int setCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentEndPointX(getCurve(graphicalObject), n, x);
}

int setCurveSegmentEndPointX(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getEnd()->setX(x);

    return  0.0;
}

const double getCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentEndPointY(getCurve(graphicalObject), n);
}

const double getCurveSegmentEndPointY(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getEnd()->y();

    return  0.0;
}

int setCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentEndPointY(getCurve(graphicalObject), n, y);
}

int setCurveSegmentEndPointY(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        lineSegment->getEnd()->setY(y);

    return  0.0;
}

const double getCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint1X(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint1X(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint1()->x();

    return  0.0;
}

int setCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentBasePoint1X(getCurve(graphicalObject), n, x);
}

int setCurveSegmentBasePoint1X(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint1()->setX(x);

    return  0.0;
}

const double getCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint1Y(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint1Y(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint1()->y();

    return  0.0;
}

int setCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentBasePoint1Y(getCurve(graphicalObject), n, y);
}

int setCurveSegmentBasePoint1Y(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint1()->setY(y);

    return  0.0;
}

const double getCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint2X(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint2X(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint2()->x();

    return  0.0;
}

int setCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentBasePoint2X(getCurve(graphicalObject), n, x);
}

int setCurveSegmentBasePoint2X(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint2()->setX(x);

    return  0.0;
}

const double getCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint2Y(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint2Y(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint2()->y();

    return  0.0;
}

int setCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentBasePoint2Y(getCurve(graphicalObject), n, y);
}

int setCurveSegmentBasePoint2Y(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        ((CubicBezier*)lineSegment)->getBasePoint2()->setY(y);

    return  0.0;
}

}
