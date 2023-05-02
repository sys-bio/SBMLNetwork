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

const unsigned int getNumLayouts(SBMLDocument* document) {
    return getNumLayouts(getListOfLayouts(document));
}

const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts) {
    if (listOfLayouts)
        return listOfLayouts->size();

    return 0;
}

Layout* getLayout(SBMLDocument* document, unsigned int n) {
    return getLayout(getListOfLayouts(document), n);
}

Layout* getLayout(ListOfLayouts* listOfLayouts, unsigned int n) {
    if (listOfLayouts)
        return listOfLayouts->get(n);

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

int removeAllLayouts(SBMLDocument* document) {
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

bool isSetId(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->isSetId();

    return false;
}

const std::string getId(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getId();

    return "";
}

int setId(GraphicalObject* graphicalObject, const std::string& sid) {
    if (graphicalObject) {
        graphicalObject->setId(sid);
        return 0;
    }

    return -1;
}

bool isSetName(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->isSetName();

    return false;
}

const std::string getName(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getName();

    return "";
}

int setName(GraphicalObject* graphicalObject, const std::string& name) {
    if (graphicalObject) {
        graphicalObject->setName(name);
        return 0;
    }

    return -1;
}

GraphicalObject* getGraphicalObject(Layout* layout, const std::string& id) {
    CompartmentGlyph* compartmentGlyph = getCompartmentGlyph(layout, id);
    if (compartmentGlyph)
        return compartmentGlyph;
    SpeciesGlyph* speciesGlyph = getSpeciesGlyph(layout, id);
    if (speciesGlyph)
        return speciesGlyph;
    ReactionGlyph* reactionGlyphGlyph = getReactionGlyph(layout, id);
    if (reactionGlyphGlyph)
        return reactionGlyphGlyph;

    return NULL;
}

const unsigned int getNumCompartmentGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumCompartmentGlyphs();

    return 0;
}

CompartmentGlyph* getCompartmentGlyph(Layout* layout, const std::string& id) {
    if (layout)
        return layout->getCompartmentGlyph(id);

    return NULL;
}

CompartmentGlyph* getCompartmentGlyph(Layout* layout, unsigned int index) {
    if (layout)
        return layout->getCompartmentGlyph(index);

    return NULL;
}

const std::string getCompartmentId(Layout* layout, const std::string& id) {
    return getCompartmentId(getCompartmentGlyph(layout, id));
}

const std::string getCompartmentId(GraphicalObject* compartmentGlyph) {
    if (isCompartmentGlyph(compartmentGlyph))
        return ((CompartmentGlyph*)compartmentGlyph)->getCompartmentId();

    return "";
}

bool isCompartmentGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<CompartmentGlyph*>(graphicalObject))
        return true;

    return false;
}

const unsigned int getNumSpeciesGlyphs(Layout* layout) {
        if (layout)
            return layout->getNumSpeciesGlyphs();

        return 0;
    }

SpeciesGlyph* getSpeciesGlyph(Layout* layout, const std::string& id) {
    if (layout)
        return layout->getSpeciesGlyph(id);

    return NULL;
}

SpeciesGlyph* getSpeciesGlyph(Layout* layout, unsigned int index) {
    if (layout)
        return layout->getSpeciesGlyph(index);

    return NULL;
}

const std::string getSpeciesId(Layout* layout, const std::string& id) {
    return getSpeciesId(getSpeciesGlyph(layout, id));
}

const std::string getSpeciesId(GraphicalObject* speciesGlyph) {
    if (isSpeciesGlyph(speciesGlyph))
        return ((SpeciesGlyph*)speciesGlyph)->getSpeciesId();

    return "";
}

bool isSpeciesGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<SpeciesGlyph*>(graphicalObject))
        return true;

    return false;
}

const unsigned int getNumReactionGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumReactionGlyphs();

    return 0;
}

ReactionGlyph* getReactionGlyph(Layout* layout, const std::string& id) {
    if (layout)
        return layout->getReactionGlyph(id);

    return NULL;
}

ReactionGlyph* getReactionGlyph(Layout* layout, unsigned int index) {
    if (layout)
        return layout->getReactionGlyph(index);

    return NULL;
}

const std::string getReactionId(Layout* layout, const std::string& id) {
    return getReactionId(getReactionGlyph(layout, id));
}

const std::string getReactionId(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getReactionId();

    return "";
}

const unsigned int getNumSpeciesReferenceGlyphs(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getNumSpeciesReferenceGlyphs();

    return 0;
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(GraphicalObject* reactionGlyph, unsigned int index) {
    if (isReactionGlyph(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getSpeciesReferenceGlyph(index);

    return NULL;
}

bool isReactionGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<ReactionGlyph*>(graphicalObject))
        return true;

    return false;
}

const std::string getSpeciesReferenceId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesReferenceId();

    return "";
}

const std::string getSpeciesGlyphId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesGlyphId();

    return "";
}

const std::string getRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getRoleString();

    return "";
}

bool isSpeciesReferenceGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<SpeciesReferenceGlyph*>(graphicalObject))
        return true;

    return false;
}

const unsigned int getNumTextGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumTextGlyphs();

    return 0;
}

TextGlyph* getTextGlyph(Layout* layout, unsigned int index) {
    if (layout)
        return layout->getTextGlyph(index);

    return NULL;
}

bool isSetText(GraphicalObject* textGlyph) {
    if (isText(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetText();

    return false;
}

const std::string getText(GraphicalObject* textGlyph) {
    if (isText(textGlyph))
        return ((TextGlyph*)textGlyph)->getText();

    return "";
}

int setText(GraphicalObject* textGlyph, const std::string& text) {
    if (isText(textGlyph)) {
        ((TextGlyph*)textGlyph)->setText(text);
        return 0;
    }

    return -1;
}

bool isSetOriginOfTextId(GraphicalObject* textGlyph) {
    if (isText(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetOriginOfTextId();

    return false;
}

const std::string getOriginOfTextId(GraphicalObject* textGlyph) {
    if (isText(textGlyph))
        return ((TextGlyph*)textGlyph)->getOriginOfTextId();

    return "";
}

int setOriginOfTextId(GraphicalObject* textGlyph, const std::string& orig) {
    if (isText(textGlyph)) {
        ((TextGlyph*)textGlyph)->setOriginOfTextId(orig);
        return 0;
    }

    return -1;
}

bool isSetGraphicalObjectId(GraphicalObject* textGlyph) {
    if (isText(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetGraphicalObjectId();

    return false;
}

const std::string getGraphicalObjectId(GraphicalObject* textGlyph) {
    if (isText(textGlyph))
        return ((TextGlyph*)textGlyph)->getGraphicalObjectId();

    return "";
}

int setGraphicalObjectId(GraphicalObject* textGlyph, const std::string& orig) {
    if (isText(textGlyph)) {
        ((TextGlyph*)textGlyph)->setGraphicalObjectId(orig);
        return 0;
    }

    return -1;
}

bool isText(GraphicalObject* graphicalObject) {
    if (dynamic_cast<TextGlyph*>(graphicalObject))
        return true;

    return false;
}

BoundingBox* getBoundingBox(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getBoundingBox();

    return NULL;
}

const double getPositionX(GraphicalObject* graphicalObject) {
    return getPositionX(getBoundingBox(graphicalObject));
}

const double getPositionX(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->x();

    return 0.0;
}

int setPositionX(GraphicalObject* graphicalObject, const double& x) {
    return setPositionX(getBoundingBox(graphicalObject), x);
}

int setPositionX(BoundingBox* boundingBox, const double& x) {
    if (boundingBox) {
        boundingBox->setX(x);
        return 0;
    }

    return -1;
}

const double getPositionY(GraphicalObject* graphicalObject) {
    return getPositionY(getBoundingBox(graphicalObject));
}

const double getPositionY(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->y();

    return 0.0;
}

int setPositionY(GraphicalObject* graphicalObject, const double& y) {
    return setPositionY(getBoundingBox(graphicalObject), y);
}

int setPositionY(BoundingBox* boundingBox, const double& y) {
    if (boundingBox) {
        boundingBox->setY(y);
        return 0;
    }

    return -1;
}

const double getDimensionWidth(GraphicalObject* graphicalObject) {
    return getDimensionWidth(getBoundingBox(graphicalObject));
}

const double getDimensionWidth(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->width();

    return 0.0;
}

int setDimensionWidth(GraphicalObject* graphicalObject, const double& width) {
    return setDimensionWidth(getBoundingBox(graphicalObject), width);
}

int setDimensionWidth(BoundingBox* boundingBox, const double& width) {
    if (boundingBox) {
        boundingBox->setWidth(width);
        return 0;
    }

    return -1;
}

const double getDimensionHeight(GraphicalObject* graphicalObject) {
    return getDimensionHeight(getBoundingBox(graphicalObject));
}

const double getDimensionHeight(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->height();

    return 0.0;
}

int setDimensionHeight(GraphicalObject* graphicalObject, const double& height) {
    return setDimensionHeight(getBoundingBox(graphicalObject), height);
}

int setDimensionHeight(BoundingBox* boundingBox, const double& height) {
    if (boundingBox) {
        boundingBox->setHeight(height);
        return 0;
    }

    return -1;
}

bool isSetCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject))
        return ((ReactionGlyph*)graphicalObject)->isSetCurve();
    if (isSpeciesReferenceGlyph(graphicalObject))
        return ((SpeciesReferenceGlyph*)graphicalObject)->isSetCurve();

    return  false;
}

Curve* getCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject))
        return ((ReactionGlyph*)graphicalObject)->getCurve();
    if (isSpeciesReferenceGlyph(graphicalObject))
        return ((SpeciesReferenceGlyph*)graphicalObject)->getCurve();

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

LineSegment* createLineCurveSegment(GraphicalObject* graphicalObject) {
    return createLineCurveSegment(getCurve(graphicalObject));
}

LineSegment* createLineCurveSegment(Curve* curve) {
    if (curve)
        return curve->createLineSegment();

    return NULL;
}

CubicBezier* createCubicBezierCurveSegment(GraphicalObject* graphicalObject) {
    return createCubicBezierCurveSegment(getCurve(graphicalObject));
}

CubicBezier* createCubicBezierCurveSegment(Curve* curve) {
    if (curve)
        return curve->createCubicBezier();

    return NULL;
}

int removeCurveSegment(GraphicalObject* graphicalObject, unsigned int n) {
    return removeCurveSegment(getCurve(graphicalObject), n);
}

int removeCurveSegment(Curve* curve, unsigned int n) {
    if (curve) {
        ListOfLineSegments* listOfLineSegments = curve->getListOfCurveSegments();
        if (listOfLineSegments) {
            LineSegment* lineSegment = listOfLineSegments->remove(n);
            delete lineSegment;
            return 0;
        }
    }

    return -1;
}

bool isCubicBezier(GraphicalObject* graphicalObject, unsigned int n) {
    return isCubicBezier(getCurveSegment(graphicalObject, n));
}

bool isCubicBezier(Curve* curve, unsigned int n) {
    return isCubicBezier(getCurveSegment(curve, n));
}

bool isCubicBezier(LineSegment* lineSegment) {
    if (lineSegment) {
        CubicBezier* cubicBezier = dynamic_cast<CubicBezier*>(lineSegment);
        if (cubicBezier)
            return true;
    }

    return  false;
}

const double getCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentStartPointX(getCurve(graphicalObject), n);
}

const double getCurveSegmentStartPointX(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        return lineSegment->getStart()->x();

    return  0.0;
}

int setCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentStartPointX(getCurve(graphicalObject), n, x);
}

int setCurveSegmentStartPointX(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment) {
        lineSegment->getStart()->setX(x);
        return  0;
    }

    return  -1;
}

const double getCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentStartPointY(getCurve(graphicalObject), n);
}

const double getCurveSegmentStartPointY(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        return lineSegment->getStart()->y();

    return  0.0;
}

int setCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentStartPointY(getCurve(graphicalObject), n, y);
}

int setCurveSegmentStartPointY(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment) {
        lineSegment->getStart()->setY(y);
        return 0;
    }

    return -1;
}

const double getCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentEndPointX(getCurve(graphicalObject), n);
}

const double getCurveSegmentEndPointX(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        return lineSegment->getEnd()->x();

    return  0.0;
}

int setCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentEndPointX(getCurve(graphicalObject), n, x);
}

int setCurveSegmentEndPointX(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment) {
        lineSegment->getEnd()->setX(x);
        return 0;
    }

    return -1;
}

const double getCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentEndPointY(getCurve(graphicalObject), n);
}

const double getCurveSegmentEndPointY(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment)
        return lineSegment->getEnd()->y();

    return  0.0;
}

int setCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentEndPointY(getCurve(graphicalObject), n, y);
}

int setCurveSegmentEndPointY(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment) {
        lineSegment->getEnd()->setY(y);
        return 0;
    }

    return -1;
}

const double getCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint1X(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint1X(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint1()->x();

    return  0.0;
}

int setCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentBasePoint1X(getCurve(graphicalObject), n, x);
}

int setCurveSegmentBasePoint1X(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment)) {
        ((CubicBezier*)lineSegment)->getBasePoint1()->setX(x);
        return 0;
    }

    return  -1;
}

const double getCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint1Y(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint1Y(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint1()->y();

    return  0.0;
}

int setCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentBasePoint1Y(getCurve(graphicalObject), n, y);
}

int setCurveSegmentBasePoint1Y(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment)) {
        ((CubicBezier*)lineSegment)->getBasePoint1()->setY(y);
        return 0;
    }

    return  -1;
}

const double getCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint2X(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint2X(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint2()->x();

    return  0.0;
}

int setCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int n, const double& x) {
    return setCurveSegmentBasePoint2X(getCurve(graphicalObject), n, x);
}

int setCurveSegmentBasePoint2X(Curve* curve, unsigned int n, const double& x) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment)) {
        ((CubicBezier*)lineSegment)->getBasePoint2()->setX(x);
        return 0;
    }

    return  -1;
}

const double getCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n) {
    return getCurveSegmentBasePoint2Y(getCurve(graphicalObject), n);
}

const double getCurveSegmentBasePoint2Y(Curve* curve, unsigned int n) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint2()->y();

    return  0.0;
}

int setCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int n, const double& y) {
    return setCurveSegmentBasePoint2Y(getCurve(graphicalObject), n, y);
}

int setCurveSegmentBasePoint2Y(Curve* curve, unsigned int n, const double& y) {
    LineSegment* lineSegment = getCurveSegment(curve, n);
    if (lineSegment && isCubicBezier(lineSegment)) {
        ((CubicBezier*)lineSegment)->getBasePoint2()->setY(y);
        return 0;
    }

    return  -1;
}

}
