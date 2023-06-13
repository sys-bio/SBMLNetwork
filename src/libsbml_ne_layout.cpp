#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"
#include "libsbml_ne_autolayout.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts) {
    if (listOfLayouts)
        return listOfLayouts->size();

    return 0;
}

Layout* getLayout(ListOfLayouts* listOfLayouts, unsigned int n) {
    if (listOfLayouts)
        return listOfLayouts->get(n);

    return NULL;
}

Dimensions* getDimensions(Layout* layout) {
    if (layout)
        return layout->getDimensions();

    return NULL;
}

double getDimensionWidth(Layout* layout) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions)
        return dimensions->getWidth();

    return 0.0;
}

int setDimensionWidth(Layout* layout, const double& width) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions) {
        dimensions->setWidth(width);
        return 0;
    }

    return -1;
}

double getDimensionHeight(Layout* layout) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions)
        return dimensions->getHeight();

    return 0.0;
}

int setDimensionHeight(Layout* layout, const double& height) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions) {
        dimensions->setHeight(height);
        return 0;
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

const std::string getSBMLObjectId(Layout* layout, const std::string& graphicalObjectId) {
    return getSBMLObjectId(layout, getGraphicalObject(layout, graphicalObjectId));
}

const std::string getSBMLObjectId(Layout* layout, GraphicalObject* graphicalObject) {
    return getEntityId(layout, graphicalObject);
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

const std::string getCompartmentId(Layout* layout, unsigned int index) {
    return getCompartmentId(getCompartmentGlyph(layout, index));
}

const std::string getCompartmentId(GraphicalObject* compartmentGlyph) {
    if (isCompartmentGlyph(compartmentGlyph))
        return ((CompartmentGlyph*)compartmentGlyph)->getCompartmentId();

    return "";
}

bool isCompartmentGlyph(Layout* layout, const std::string& id) {
    return isCompartmentGlyph(getCompartmentGlyph(layout, id));
}

bool isCompartmentGlyph(Layout* layout, unsigned int index) {
    return isCompartmentGlyph(getCompartmentGlyph(layout, index));
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

const std::string getSpeciesId(Layout* layout, unsigned int index) {
    return getSpeciesId(getSpeciesGlyph(layout, index));
}

const std::string getSpeciesId(GraphicalObject* speciesGlyph) {
    if (isSpeciesGlyph(speciesGlyph))
        return ((SpeciesGlyph*)speciesGlyph)->getSpeciesId();

    return "";
}

bool isSpeciesGlyph(Layout* layout, const std::string& id) {
    return isSpeciesGlyph(getSpeciesGlyph(layout, id));
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

const std::string getReactionId(Layout* layout, unsigned int index) {
    return getReactionId(getReactionGlyph(layout, index));
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

bool isReactionGlyph(Layout* layout, const std::string& id) {
    return isReactionGlyph(getReactionGlyph(layout, id));
}

bool isReactionGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<ReactionGlyph*>(graphicalObject))
        return true;

    return false;
}

const std::string getSpeciesReferenceId(GraphicalObject* reactionGlyph, unsigned int index) {
    return getSpeciesReferenceId(getSpeciesReferenceGlyph(reactionGlyph, index));
}

const std::string getSpeciesReferenceId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesReferenceId();

    return "";
}

const std::string getSpeciesGlyphId(GraphicalObject* reactionGlyph, unsigned int index) {
    return getSpeciesGlyphId(getSpeciesReferenceGlyph(reactionGlyph, index));
}

const std::string getSpeciesGlyphId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesGlyphId();

    return "";
}

bool isSetRole(GraphicalObject* reactionGlyph, unsigned int index) {
    return isSetRole(getSpeciesReferenceGlyph(reactionGlyph, index));
}

bool isSetRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->isSetRole();

    return false;
}

const std::string getRole(GraphicalObject* reactionGlyph, unsigned int index) {
    return getRole(getSpeciesReferenceGlyph(reactionGlyph, index));
}

const std::string getRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getRoleString();

    return "";
}

int setRole(GraphicalObject* reactionGlyph, unsigned int index, const std::string& role) {
    return setRole(getSpeciesReferenceGlyph(reactionGlyph, index), role);
}

int setRole(GraphicalObject* speciesReferenceGlyph, const std::string& role) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph)) {
        ((SpeciesReferenceGlyph *) speciesReferenceGlyph)->setRole(role);
        return 0;
    }

    return -1;
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

TextGlyph* getTextGlyph(Layout* layout, const std::string& id) {
    if (layout)
        return layout->getTextGlyph(id);

    return NULL;
}

TextGlyph* getTextGlyph(Layout* layout, unsigned int index) {
    if (layout)
        return layout->getTextGlyph(index);

    return NULL;
}

bool isSetText(Layout* layout, const std::string& id) {
    return isSetText(getTextGlyph(layout, id));
}

bool isSetText(Layout* layout, unsigned int index) {
    return isSetText(getTextGlyph(layout, index));
}

bool isSetText(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetText();

    return false;
}

const std::string getText(Layout* layout, const std::string& id) {
    return getText(getTextGlyph(layout, id));
}

const std::string getText(Layout* layout, unsigned int index) {
    return getText(getTextGlyph(layout, index));
}

const std::string getText(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->getText();

    return "";
}

int setText(Layout* layout, const std::string& id, const std::string& text) {
    return setText(getTextGlyph(layout, id), text);
}

int setText(Layout* layout, unsigned int index, const std::string& text) {
    return setText(getTextGlyph(layout, index), text);
}

int setText(GraphicalObject* textGlyph, const std::string& text) {
    if (isTextGlyph(textGlyph)) {
        ((TextGlyph*)textGlyph)->setText(text);
        return 0;
    }

    return -1;
}

bool isSetOriginOfTextId(Layout* layout, const std::string& id) {
    return isSetOriginOfTextId(getTextGlyph(layout, id));
}

bool isSetOriginOfTextId(Layout* layout, unsigned int index) {
    return isSetOriginOfTextId(getTextGlyph(layout, index));
}

bool isSetOriginOfTextId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetOriginOfTextId();

    return false;
}

const std::string getOriginOfTextId(Layout* layout, const std::string& id) {
    return getOriginOfTextId(getTextGlyph(layout, id));
}

const std::string getOriginOfTextId(Layout* layout, unsigned int index) {
    return getOriginOfTextId(getTextGlyph(layout, index));
}

const std::string getOriginOfTextId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->getOriginOfTextId();

    return "";
}

int setOriginOfTextId(Layout* layout, const std::string& id, const std::string& orig) {
    return setOriginOfTextId(getTextGlyph(layout, id), orig);
}

int setOriginOfTextId(Layout* layout, unsigned int index, const std::string& orig) {
    return setOriginOfTextId(getTextGlyph(layout, index), orig);
}

int setOriginOfTextId(GraphicalObject* textGlyph, const std::string& orig) {
    if (isTextGlyph(textGlyph)) {
        ((TextGlyph*)textGlyph)->setOriginOfTextId(orig);
        return 0;
    }

    return -1;
}

bool isSetGraphicalObjectId(Layout* layout, const std::string& id) {
    return isSetGraphicalObjectId(getTextGlyph(layout, id));
}

bool isSetGraphicalObjectId(Layout* layout, unsigned int index) {
    return isSetGraphicalObjectId(getTextGlyph(layout, index));
}

bool isSetGraphicalObjectId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetGraphicalObjectId();

    return false;
}

const std::string getGraphicalObjectId(Layout* layout, const std::string& id) {
    return getGraphicalObjectId(getTextGlyph(layout, id));
}

const std::string getGraphicalObjectId(Layout* layout, unsigned int index) {
    return getGraphicalObjectId(getTextGlyph(layout, index));
}

const std::string getGraphicalObjectId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->getGraphicalObjectId();

    return "";
}

int setGraphicalObjectId(Layout* layout, const std::string& id, const std::string& orig) {
    return setGraphicalObjectId(getTextGlyph(layout, id), orig);
}

int setGraphicalObjectId(Layout* layout, unsigned int index, const std::string& orig) {
    return setGraphicalObjectId(getTextGlyph(layout, index), orig);
}

int setGraphicalObjectId(GraphicalObject* textGlyph, const std::string& orig) {
    if (isTextGlyph(textGlyph)) {
        ((TextGlyph*)textGlyph)->setGraphicalObjectId(orig);
        return 0;
    }

    return -1;
}

const unsigned int getNumTextGlyphs(Layout* layout, const std::string& id) {
    return getNumTextGlyphs(layout, getGraphicalObject(layout, id));
}

const unsigned int getNumTextGlyphs(Layout* layout, GraphicalObject* graphicalObject) {
    return getTextGlyphs(layout, graphicalObject).size();
}

std::vector<TextGlyph*> getTextGlyphs(Layout* layout, const std::string& id) {
    return getTextGlyphs(layout, getGraphicalObject(layout, id));
}

std::vector<TextGlyph*> getTextGlyphs(Layout* layout, GraphicalObject* graphicalObject) {
    std::vector<TextGlyph*> textGlyphs;
    if (layout)
        textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);

    return textGlyphs;
}

TextGlyph* getTextGlyph(Layout* layout, const std::string& id, unsigned int index) {
    return getTextGlyph(layout, getGraphicalObject(layout, id), index);
}

TextGlyph* getTextGlyph(Layout* layout, GraphicalObject* graphicalObject, unsigned int index) {
    std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, graphicalObject);
    if (index < textGlyphs.size())
        return textGlyphs.at(index);

    return NULL;
}

bool isTextGlyph(Layout* layout, const std::string& id) {
    return isTextGlyph(getTextGlyph(layout, id));
}

bool isTextGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<TextGlyph*>(graphicalObject))
        return true;

    return false;
}

BoundingBox* getBoundingBox(Layout* layout, const std::string& id) {
    return getBoundingBox(getGraphicalObject(layout, id));
}

BoundingBox* getBoundingBox(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getBoundingBox();

    return NULL;
}

const double getPositionX(Layout* layout, const std::string& id) {
    return getPositionX(getGraphicalObject(layout, id));
}

const double getPositionX(GraphicalObject* graphicalObject) {
    return getPositionX(getBoundingBox(graphicalObject));
}

const double getPositionX(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->x();

    return 0.0;
}

int setPositionX(Layout* layout, const std::string& id, const double& x) {
    return setPositionX(getGraphicalObject(layout, id), x);
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

const double getPositionY(Layout* layout, const std::string& id) {
    return getPositionY(getGraphicalObject(layout, id));
}

const double getPositionY(GraphicalObject* graphicalObject) {
    return getPositionY(getBoundingBox(graphicalObject));
}

const double getPositionY(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->y();

    return 0.0;
}

int setPositionY(Layout* layout, const std::string& id, const double& y) {
    return setPositionY(getGraphicalObject(layout, id), y);
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

const double getDimensionWidth(Layout* layout, const std::string& id) {
    return getDimensionWidth(getGraphicalObject(layout, id));
}

const double getDimensionWidth(GraphicalObject* graphicalObject) {
    return getDimensionWidth(getBoundingBox(graphicalObject));
}

const double getDimensionWidth(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->width();

    return 0.0;
}

int setDimensionWidth(Layout* layout, const std::string& id, const double& width) {
    return setDimensionWidth(getGraphicalObject(layout, id), width);
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

const double getDimensionHeight(Layout* layout, const std::string& id) {
    return getDimensionHeight(getGraphicalObject(layout, id));
}

const double getDimensionHeight(GraphicalObject* graphicalObject) {
    return getDimensionHeight(getBoundingBox(graphicalObject));
}

const double getDimensionHeight(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->height();

    return 0.0;
}

int setDimensionHeight(Layout* layout, const std::string& id, const double& height) {
    return setDimensionHeight(getGraphicalObject(layout, id), height);
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

bool isSetCurve(Layout* layout, const std::string& id) {
    return isSetCurve(getGraphicalObject(layout, id));
}

bool isSetCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject))
        return ((ReactionGlyph*)graphicalObject)->isSetCurve();
    if (isSpeciesReferenceGlyph(graphicalObject))
        return ((SpeciesReferenceGlyph*)graphicalObject)->isSetCurve();

    return  false;
}

Curve* getCurve(Layout* layout, const std::string& id) {
    return getCurve(layout, id);
}

Curve* getCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject))
        return ((ReactionGlyph*)graphicalObject)->getCurve();
    if (isSpeciesReferenceGlyph(graphicalObject))
        return ((SpeciesReferenceGlyph*)graphicalObject)->getCurve();

    return  NULL;
}

const unsigned int getNumCurveSegments(Layout* layout, const std::string& id) {
    return getNumCurveSegments(getGraphicalObject(layout, id));
}

const unsigned int getNumCurveSegments(GraphicalObject* graphicalObject) {
    return getNumCurveSegments(getCurve(graphicalObject));
}

const unsigned int getNumCurveSegments(Curve* curve) {
    if (curve)
        return curve->getNumCurveSegments();

    return 0;
}

LineSegment* getCurveSegment(Layout* layout, const std::string& id, unsigned int index) {
    return getCurveSegment(getGraphicalObject(layout, id), index);
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

LineSegment* createLineCurveSegment(Layout* layout, const std::string& id) {
    return createLineCurveSegment(getGraphicalObject(layout, id));
}

LineSegment* createLineCurveSegment(GraphicalObject* graphicalObject) {
    return createLineCurveSegment(getCurve(graphicalObject));
}

LineSegment* createLineCurveSegment(Curve* curve) {
    if (curve)
        return curve->createLineSegment();

    return NULL;
}

CubicBezier* createCubicBezierCurveSegment(Layout* layout, const std::string& id) {
    return createCubicBezierCurveSegment(getGraphicalObject(layout, id));
}

CubicBezier* createCubicBezierCurveSegment(GraphicalObject* graphicalObject) {
    return createCubicBezierCurveSegment(getCurve(graphicalObject));
}

CubicBezier* createCubicBezierCurveSegment(Curve* curve) {
    if (curve)
        return curve->createCubicBezier();

    return NULL;
}

int removeCurveSegment(Layout* layout, const std::string& id, unsigned int n) {
    return removeCurveSegment(getGraphicalObject(layout, id), n);
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

bool isCubicBezier(Layout* layout, const std::string& id, unsigned int n) {
    return isCubicBezier(getGraphicalObject(layout, id), n);
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

const double getCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentStartPointX(getGraphicalObject(layout, id), n);
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

int setCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int n, const double& x) {
    return setCurveSegmentStartPointX(getGraphicalObject(layout, id), n, x);
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

const double getCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentStartPointY(getGraphicalObject(layout, id), n);
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

int setCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int n, const double& y) {
    return setCurveSegmentStartPointY(getGraphicalObject(layout, id), n, y);
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

const double getCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentEndPointX(getGraphicalObject(layout, id), n);
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

int setCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int n, const double& x) {
    return setCurveSegmentEndPointX(getGraphicalObject(layout, id), n, x);
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

const double getCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentEndPointY(getGraphicalObject(layout, id), n);
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

int setCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int n, const double& y) {
    return setCurveSegmentEndPointY(getGraphicalObject(layout, id), n, y);
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

const double getCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentBasePoint1X(getGraphicalObject(layout, id), n);
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

int setCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int n, const double& x) {
    return setCurveSegmentBasePoint1X(getGraphicalObject(layout, id), n, x);
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

const double getCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentBasePoint1Y(getGraphicalObject(layout, id), n);
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

int setCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int n, const double& y) {
    return setCurveSegmentBasePoint1Y(getGraphicalObject(layout, id), n, y);
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

const double getCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentBasePoint2X(getGraphicalObject(layout, id), n);
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

int setCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int n, const double& x) {
    return setCurveSegmentBasePoint2X(getGraphicalObject(layout, id), n, x);
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

const double getCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int n) {
    return getCurveSegmentBasePoint2Y(getGraphicalObject(layout, id), n);
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

int setCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int n, const double& y) {
    return setCurveSegmentBasePoint2Y(getGraphicalObject(layout, id), n, y);
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
