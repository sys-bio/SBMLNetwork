#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_layout_helpers.h"
#include "autolayout/libsbmlnetwork_autolayout.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

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

Layout* getLayout(SBMLDocument* document, unsigned int layoutIndex) {
    return getLayout(getListOfLayouts(document), layoutIndex);
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

int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout, const double stiffness, const double gravity, const int maxNumConnectedEdges,
                             bool useMagnetism, bool useBoundary, bool useGrid, bool useNameAsTextLabel,
                             bool resetLockedNodes, const std::vector<std::string> lockedNodeIds) {
    if (document && layout) {
        setDefaultLayoutId(layout);
        setDefaultLayoutDimensions(layout);
        Model* model = document->getModel();
        if (model) {
            std::vector<LockedNodeInfo> lockedNodesInfo = getLockedNodesInfo(layout, lockedNodeIds, resetLockedNodes);
            clearGraphicalObjects(layout);
            setCompartmentGlyphs(model, layout);
            setSpeciesGlyphs(model, layout);
            setReactionGlyphs(model, layout);
            setAliasSpeciesGlyphs(layout, maxNumConnectedEdges);
            locateGlyphs(model, layout, stiffness, gravity, useMagnetism, useBoundary, useGrid, useNameAsTextLabel, lockedNodesInfo);
            setTextGlyphs(layout);
            return 0;
        }
    }

    return -1;
}

int updateLayoutCurves(SBMLDocument* document, Layout* layout, std::vector<std::string> updatedGraphicalObjectIds) {
    if (document && layout) {
        Model* model = document->getModel();
        if (model) {
            std::vector<LockedNodeInfo> lockedNodesInfo = getLockedNodesInfo(layout, updatedGraphicalObjectIds, false);
            locateReactions(model, layout, 10.0, 15.0, false, true, false, false, lockedNodesInfo);
            return 0;
        }
    }

    return -1;
}

int updateLayoutCurves(SBMLDocument* document, unsigned int layoutIndex, std::vector<std::string> updatedGraphicalObjectIds) {
    return updateLayoutCurves(document, getLayout(document, layoutIndex), updatedGraphicalObjectIds);
}

int createDefaultLayout(SBMLDocument* document, const double stiffness, const double gravity, const int maxNumConnectedEdges,
                        bool useMagnetism, bool useBoundary, bool useGrid, bool useNameAsTextLabel,
                        bool resetLockedNodes, const std::vector<std::string> lockedNodeIds) {
    Layout* layout = getLayout(document);
    if (!layout)
        layout = createLayout(document);

    return setDefaultLayoutFeatures(document, layout, stiffness, gravity, maxNumConnectedEdges, useMagnetism, useBoundary, useGrid, useNameAsTextLabel, resetLockedNodes, lockedNodeIds);
}

Dimensions* getDimensions(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensions(getLayout(document, layoutIndex));
}

double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensionWidth(getLayout(document, layoutIndex));
}

int setDimensionWidth(SBMLDocument* document, const double& width) {
    return setDimensionWidth(getLayout(document), width);
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    return setDimensionWidth(getLayout(document, layoutIndex), width);
}

double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensionHeight(getLayout(document, layoutIndex));
}

int setDimensionHeight(SBMLDocument* document, const double& height) {
    return setDimensionHeight(getLayout(document), height);
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    return setDimensionHeight(getLayout(document, layoutIndex), height);
}

const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumGraphicalObjects(getLayout(document, layoutIndex));
}

const unsigned int getNumGraphicalObjects(SBMLDocument* document, const std::string& id) {
    return getNumGraphicalObjects(getLayout(document), id);
}

const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getNumGraphicalObjects(getLayout(document, layoutIndex), id);
}

std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, const std::string& id) {
    return getGraphicalObjects(getLayout(document), id);
}

std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getGraphicalObjects(getLayout(document, layoutIndex), id);
}

GraphicalObject* getGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getGraphicalObject(getLayout(document), id, graphicalObjectIndex);
}

GraphicalObject* getGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getGraphicalObject(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumCompartmentGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    return getNumCompartmentGlyphs(getLayout(document), compartmentId);
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId) {
    return getNumCompartmentGlyphs(getLayout(document, layoutIndex), compartmentId);
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    return getCompartmentGlyphs(getLayout(document), compartmentId);
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId) {
    return getCompartmentGlyphs(getLayout(document, layoutIndex), compartmentId);
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int compartmentGlyphIndex) {
    return getCompartmentGlyph(getLayout(document), compartmentId, compartmentGlyphIndex);
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId, unsigned int compartmentGlyphIndex) {
    return getCompartmentGlyph(getLayout(document, layoutIndex), compartmentId, compartmentGlyphIndex);
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, unsigned int compartmentGlyphIndex) {
    return getCompartmentGlyph(getLayout(document, layoutIndex), compartmentGlyphIndex);
}

bool isCompartmentGlyph(SBMLDocument* document, const std::string& id) {
    return isCompartmentGlyph(getLayout(document), id);
}

bool isCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isCompartmentGlyph(getLayout(document, layoutIndex), id);
}

std::string getCompartmentId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCompartmentId(document, getGraphicalObject(document, id, graphicalObjectIndex));
}

std::string getCompartmentId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCompartmentId(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
}

std::string getCompartmentId(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Compartment* compartment = getAssociatedCompartment(document, graphicalObject);
    if (compartment)
        return compartment->getId();

    return "";
}

Compartment* getAssociatedCompartment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getAssociatedCompartment(document, getGraphicalObject(document, id, graphicalObjectIndex));
}

Compartment* getAssociatedCompartment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getAssociatedCompartment(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
}

Compartment* getAssociatedCompartment(SBMLDocument* document, GraphicalObject* graphicalObject) {
    if (document && document->isSetModel()) {
        if (isCompartmentGlyph(graphicalObject))
            return findCompartmentGlyphCompartment(document->getModel(), (CompartmentGlyph*)graphicalObject);
        else if (isSpeciesGlyph(graphicalObject))
            return findSpeciesGlyphCompartment(document->getModel(), (SpeciesGlyph*)graphicalObject);
        else if (isReactionGlyph(graphicalObject))
            return findReactionGlyphCompartment(document->getModel(), (ReactionGlyph*)graphicalObject);
    }

    return NULL;
}

std::vector<std::string> getSpeciesGlyphsIds(SBMLDocument* document, unsigned int layoutIndex) {
    return getSpeciesGlyphsIds(getLayout(document, layoutIndex));
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumSpeciesGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getNumSpeciesGlyphs(getLayout(document), speciesId);
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId) {
    return getNumSpeciesGlyphs(getLayout(document, layoutIndex), speciesId);
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getSpeciesGlyphs(getLayout(document), speciesId);
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId) {
    return getSpeciesGlyphs(getLayout(document, layoutIndex), speciesId);
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(getLayout(document), speciesId, speciesGlyphIndex);
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(getLayout(document, layoutIndex), speciesId, speciesGlyphIndex);
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(getLayout(document, layoutIndex), speciesGlyphIndex);
}

bool isSpeciesGlyph(SBMLDocument* document, const std::string& id) {
    return isSpeciesGlyph(getLayout(document), id);
}

bool isSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isSpeciesGlyph(getLayout(document, layoutIndex), id);
}

std::vector<std::string> getReactionGlyphsIds(SBMLDocument* document, unsigned int layoutIndex) {
    return getReactionGlyphsIds(getLayout(document, layoutIndex));
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumReactionGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getNumReactionGlyphs(getLayout(document), reactionId);
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return getNumReactionGlyphs(getLayout(document, layoutIndex), reactionId);
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getReactionGlyphs(getLayout(document), reactionId);
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return getReactionGlyphs(getLayout(document, layoutIndex), reactionId);
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getReactionGlyph(getLayout(document), reactionId, reactionGlyphIndex);
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getReactionGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, unsigned int reactionGlyphIndex) {
    return getReactionGlyph(getLayout(document, layoutIndex), reactionGlyphIndex);
}

bool isReactionGlyph(SBMLDocument* document, const std::string& id) {
    return isReactionGlyph(getLayout(document), id);
}

bool isReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isReactionGlyph(getLayout(document, layoutIndex), id);
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getLayout(document), reactionId, reactionGlyphIndex);
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(getLayout(document), reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceSpeciesId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, const std::string& role) {
    return setRole(getLayout(document), reactionId, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getLayout(document), reactionId, reactionGlyphIndex, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role) {
    return setRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
}

bool isSetSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetCurve(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

bool isSetSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetCurve(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

Curve* getSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getCurve(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

Curve* getSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getCurve(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

const unsigned int getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getNumCurveSegments(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

const unsigned int getNumSpeciesReferenceCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getNumCurveSegments(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

LineSegment* getSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

LineSegment* getSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

LineSegment* createSpeciesReferenceLineCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return createLineCurveSegment(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

LineSegment* createSpeciesReferenceLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return createLineCurveSegment(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

CubicBezier* createSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return createCubicBezierCurveSegment(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

CubicBezier* createSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return createCubicBezierCurveSegment(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

int removeSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int removeSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

bool isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

bool isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

double getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex),
                               curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex),
                               curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

double getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

double getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getSpeciesReferenceGlyph(getLayout(document), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumTextGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumTextGlyphs(getLayout(document), getGraphicalObject(getLayout(document), id, graphicalObjectIndex));
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumTextGlyphs(getLayout(document, layoutIndex), getGraphicalObject(getLayout(document, layoutIndex), id, graphicalObjectIndex));
}

std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, const std::string& id) {
    return getTextGlyphs(getLayout(document), id);
}

std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getTextGlyphs(getLayout(document, layoutIndex), id);
}

TextGlyph* getTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document), id, textGlyphIndex);
}

TextGlyph* getTextGlyph(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document), graphicalObject, textGlyphIndex);
}

TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document, layoutIndex), id, textGlyphIndex);
}

TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document, layoutIndex), graphicalObject, textGlyphIndex);
}

bool isSetText(SBMLDocument* document, const std::string& id) {
    return isSetText(getLayout(document), id);
}

bool isSetText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isSetText(getLayout(document, layoutIndex), id);
}

const std::string getText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getText(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getText(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

int setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return setText(getLayout(document), id, graphicalObjectIndex, text);
}

int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return setText(getLayout(document, layoutIndex), id, graphicalObjectIndex, text);
}

int setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getLayout(document), id, graphicalObjectIndex, textGlyphIndex, text);
}

int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex, text);
}

int addText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return addText(getLayout(document), id, graphicalObjectIndex, text);
}

int addText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return addText(getLayout(document, layoutIndex), id, graphicalObjectIndex, text);
}

int removeText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return removeText(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

int removeText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return removeText(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

bool isSetOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

bool isSetOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document), id, graphicalObjectIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex, orig);
}

bool isSetGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

bool isSetGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex, graphicalObjectId);
}

bool isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getLayout(document), id, textGlyphIndex);
}

bool isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getLayout(document, layoutIndex), id, textGlyphIndex);
}

BoundingBox* getBoundingBox(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getBoundingBox(getLayout(document), id, graphicalObjectIndex);
}

BoundingBox* getBoundingBox(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getBoundingBox(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const double getPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionX(getLayout(document), id, graphicalObjectIndex);
}

const double getPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionX(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setPositionX(SBMLDocument* document, const std::string& id, const double& x) {
    Layout* layout = getLayout(document);
    if (!setPositionX(layout, id, x)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionX(layout, id, x)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    Layout* layout = getLayout(document);
    if (!setPositionX(layout, id, graphicalObjectIndex, x)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionX(layout, id, graphicalObjectIndex, x)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

const double getPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getLayout(document), id, graphicalObjectIndex);
}

const double getPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setPositionY(SBMLDocument* document, const std::string& id, const double& y) {
    Layout* layout = getLayout(document);
    if (!setPositionY(layout, id, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionY(layout, id, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    Layout* layout = getLayout(document);
    if (!setPositionY(layout, id, graphicalObjectIndex, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionY(layout, id, graphicalObjectIndex, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y) {
    Layout* layout = getLayout(document);
    if (!setPosition(layout, id, x, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPosition(layout, id, x, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    Layout* layout = getLayout(document);
    if (!setPosition(layout, id, graphicalObjectIndex, x, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPosition(layout, id, graphicalObjectIndex, x, y)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

const double getDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getLayout(document), id, graphicalObjectIndex);
}

const double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setDimensionWidth(SBMLDocument* document, const std::string& id, const double& width) {
    Layout* layout = getLayout(document);
    if (!setDimensionWidth(layout, id, width)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionWidth(layout, id, width)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    Layout* layout = getLayout(document);
    if (!setDimensionWidth(layout, id, graphicalObjectIndex, width)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionWidth(layout, id, graphicalObjectIndex, width)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

const double getDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getLayout(document), id, graphicalObjectIndex);
}

const double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setDimensionHeight(SBMLDocument* document, const std::string& id, const double& height) {
    Layout* layout = getLayout(document);
    if (!setDimensionHeight(layout, id, height)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionHeight(layout, id, height)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id)));
        return 0;
    }

    return -1;
}

int setDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    Layout* layout = getLayout(document);
    if (!setDimensionHeight(layout, id, graphicalObjectIndex, height)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionHeight(layout, id, graphicalObjectIndex, height)) {
        if (canUpdateLayoutCurves(layout))
            updateLayoutCurves(document, layout, getListOfGraphicalObjectIds(getGraphicalObject(layout, id, graphicalObjectIndex)));
        return 0;
    }

    return -1;
}

const double getTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionX(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextPositionX(SBMLDocument* document, const std::string& id, const double& x) {
    return setTextPositionX(getLayout(document), getGraphicalObject(document, id), x);
}

int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x) {
    return setTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), x);
}

int setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setTextPositionX(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), x);
}

int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), x);
}

int setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x) {
    return setTextPositionX(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, x);
}

int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x) {
    return setTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, x);
}

const double getTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionY(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextPositionY(SBMLDocument* document, const std::string& id, const double& y) {
    return setTextPositionY(getLayout(document), getGraphicalObject(document, id), y);
}

int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y) {
    return setTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), y);
}

int setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setTextPositionY(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), y);
}

int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), y);
}

int setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y) {
    return setTextPositionY(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, y);
}

int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y) {
    return setTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, y);
}

int setTextPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y) {
    return setTextPosition(getLayout(document), getGraphicalObject(document, id), x, y);
}

int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y) {
    return setTextPosition(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), x, y);
}

int setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), x, y);
}

int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), x, y);
}

int setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, x, y);
}

int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, x, y);
}

const double getTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionWidth(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextDimensionWidth(SBMLDocument* document, const std::string& id, const double& width) {
    return setTextDimensionWidth(getLayout(document), getGraphicalObject(document, id), width);
}

int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width) {
    return setTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), width);
}

int setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), width);
}

int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), width);
}

int setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, width);
}

int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, width);
}

const double getTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionHeight(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextDimensionHeight(SBMLDocument* document, const std::string& id, const double& height) {
    return setTextDimensionHeight(getLayout(document), getGraphicalObject(document, id), height);
}

int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height) {
    return setTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), height);
}

int setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), height);
}

int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), height);
}

int setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, height);
}

int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, height);
}

bool isSetCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetCurve(getLayout(document), id, graphicalObjectIndex);
}

bool isSetCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetCurve(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

Curve* getCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCurve(getLayout(document), id, graphicalObjectIndex);
}

Curve* getCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCurve(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const unsigned int getNumCurveSegments(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumCurveSegments(getLayout(document), id, graphicalObjectIndex);
}

const unsigned int getNumCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumCurveSegments(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

LineSegment* getCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

LineSegment* getCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

LineSegment* createLineCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return createLineCurveSegment(getLayout(document), id, graphicalObjectIndex);
}

LineSegment* createLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return createLineCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

CubicBezier* createCubicBezierCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return createCubicBezierCurveSegment(getLayout(document), id, graphicalObjectIndex);
}

CubicBezier* createCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return createCubicBezierCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int removeCurveSegment(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getLayout(document), id, curveSegmentIndex);
}

int removeCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getLayout(document, layoutIndex), id, curveSegmentIndex);
}

bool isCubicBezier(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

bool isCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointY(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

const double getCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointY(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

const double getCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1Y(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

const double getCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2Y(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

}
