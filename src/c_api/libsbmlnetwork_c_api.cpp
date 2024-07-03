#include "libsbmlnetwork_c_api.h"
#include "../libsbmlnetwork_common.h"
#include "../libsbmlnetwork_layout.h"
#include "../libsbmlnetwork_layout_helpers.h"
#include "../libsbmlnetwork_render_helpers.h"

extern "C" {

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    const char* c_api_getVersion() {
        return strdup(getLibraryVersion().c_str());
    }

    SBMLDocument* c_api_readSBML(const char* sbml) {
        return readSBML(sbml);
    }

    bool c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName) {
        return writeSBMLToFile(document, fileName);
    }

    const char* c_api_writeSBMLToString(SBMLDocument* document) {
        return writeSBMLToString(document);
    }

    int c_api_getSBMLLevel(SBMLDocument* document) {
        return getSBMLLevel(document);
    }

    int c_api_getSBMLVersion(SBMLDocument* document) {
        return getSBMLVersion(document);
    }

    bool c_api_freeSBMLDocument(SBMLDocument* document) {
        return freeSBMLDocument(document);
    }

    bool c_api_isSetModel(SBMLDocument* document) {
        return isSetModel(document);
    }

    int c_api_autolayout(SBMLDocument *document, const double stiffness, const double gravity, bool useMagnetism, bool useBoundary, bool useGrid, bool useNameAsTextLabel, const char **lockedNodeIds, const int lockedNodesSize) {
        std::vector <std::string> lockedNodeIdsVector = std::vector<std::string>();
        if (lockedNodeIds) {
            for (int i = 0; i < lockedNodesSize; i++)
                lockedNodeIdsVector.emplace_back(lockedNodeIds[i]);
        }

        return autolayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid, useNameAsTextLabel, lockedNodeIdsVector);
    }

    int c_api_align(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* alignment, bool isLayoutAdded) {
        if (isLayoutAdded) {
            std::vector <std::string> nodeIdsVector = std::vector<std::string>();
            if (nodeIds) {
                for (int i = 0; i < nodesSize; i++)
                    nodeIdsVector.emplace_back(nodeIds[i]);
            }
            return align(document, nodeIdsVector, alignment);
        }
        else
            std::cerr << "Align function does not apply as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    int c_api_distribute(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* direction, const double spacing, bool isLayoutAdded) {
        if (isLayoutAdded) {
            std::vector <std::string> nodeIdsVector = std::vector<std::string>();
            if (nodeIds) {
                for (int i = 0; i < nodesSize; i++)
                    nodeIdsVector.emplace_back(nodeIds[i]);
            }
            return distribute(document, nodeIdsVector, direction, spacing);
        }
        else
            std::cerr << "Distribute function does not apply as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    const int c_api_getNumLayouts(SBMLDocument* document) {
        return getNumLayouts(document);
    }

    int c_api_removeLayouts(SBMLDocument* document) {
        return removeAllLayouts(document);
    }

    int c_api_createDefaultLayout(SBMLDocument* document, const double stiffness, const double gravity, bool useMagnetism,
                                  bool useBoundary, bool useGrid, bool useNameAsTextLabel,
                                  const char **lockedNodeIds, const int lockedNodesSize) {
        std::vector <std::string> lockedNodeIdsVector = std::vector<std::string>();
        if (lockedNodeIds) {
            for (int i = 0; i < lockedNodesSize; i++)
                lockedNodeIdsVector.emplace_back(lockedNodeIds[i]);
        }
        return createDefaultLayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid, useNameAsTextLabel, lockedNodeIdsVector);
    }

    double c_api_getCanvasWidth(SBMLDocument* document, int layoutIndex) {
        return getDimensionWidth(document, layoutIndex);
    }

    int c_api_setCanvasWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setDimensionWidth(document, layoutIndex, width);
    }

    double c_api_getCanvasHeight(SBMLDocument* document, int layoutIndex) {
        return getDimensionHeight(document, layoutIndex);
    }

    int c_api_setCanvasHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setDimensionHeight(document, layoutIndex, height);
    }

    const int c_api_getNumAllGraphicalObjects(SBMLDocument* document, int layoutIndex) {
        return getNumGraphicalObjects(document, layoutIndex);
    }

    const int c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex) {
        return getNumGraphicalObjects(document, layoutIndex, id);
    }

    const char* c_api_getNthGraphicalObjectId(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex) {
        GraphicalObject* graphicalObject = getGraphicalObject(document, layoutIndex, entityId, graphicalObjectIndex);
        if (graphicalObject)
            return strdup(graphicalObject->getId().c_str());

        return "";
    }

    const char* c_api_getNthGraphicalObjectMetaId(SBMLDocument* document, const char* entityId, int graphicalObjectIndex, int layoutIndex) {
        GraphicalObject* graphicalObject = getGraphicalObject(document, layoutIndex, entityId, graphicalObjectIndex);
        if (graphicalObject)
            return strdup(graphicalObject->getMetaId().c_str());

        return "";
    }

    const int c_api_getNumCompartments(SBMLDocument* document) {
        return getNumCompartments(document);
    }

    const char* c_api_getNthCompartmentId(SBMLDocument* document, int compartmentIndex) {
        return strdup(getNthCompartmentId(document, compartmentIndex).c_str());
    }

    const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumCompartmentGlyphs(document, layoutIndex);
    }

    const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex) {
        return getNumCompartmentGlyphs(document, layoutIndex, compartmentId);
    }

    const char* c_api_getNthCompartmentGlyphId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex) {
        CompartmentGlyph* compartmentGlyph = getCompartmentGlyph(document, layoutIndex, compartmentId, compartmentGlyphIndex);
        if (compartmentGlyph)
            return strdup(compartmentGlyph->getId().c_str());

        return "";
    }

    const char* c_api_getNthCompartmentGlyphMetaId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex) {
        CompartmentGlyph* compartmentGlyph = getCompartmentGlyph(document, layoutIndex, compartmentId, compartmentGlyphIndex);
        if (compartmentGlyph)
            return strdup(compartmentGlyph->getMetaId().c_str());

        return "";
    }

    bool c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex) {
        return isCompartmentGlyph(document, layoutIndex, compartmentId);
    }

    const char* c_api_getCompartmentId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getCompartmentId(document, layoutIndex, id, graphicalObjectIndex).c_str());
    }

    const int c_api_getNumSpecies(SBMLDocument* document) {
        return getNumSpecies(document);
    }

    const char* c_api_getNthSpeciesId(SBMLDocument* document, int speciesIndex) {
        return strdup(getNthSpeciesId(document, speciesIndex).c_str());
    }

    const int c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumSpeciesGlyphs(document, layoutIndex);
    }

    const int c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex) {
        return getNumSpeciesGlyphs(document, layoutIndex, speciesId);
    }

    const char* c_api_getNthSpeciesGlyphId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex) {
        SpeciesGlyph* speciesGlyph = getSpeciesGlyph(document, layoutIndex, speciesId, speciesGlyphIndex);
        if (speciesGlyph)
            return strdup(speciesGlyph->getId().c_str());

        return "";
    }

    const char* c_api_getNthSpeciesGlyphMetaId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex) {
        SpeciesGlyph* speciesGlyph = getSpeciesGlyph(document, layoutIndex, speciesId, speciesGlyphIndex);
        if (speciesGlyph)
            return strdup(speciesGlyph->getMetaId().c_str());

        return "";
    }

    bool c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex) {
        return isSpeciesGlyph(document, layoutIndex, speciesId);
    }

    const int c_api_getNumReactions(SBMLDocument* document) {
        return getNumReactions(document);
    }

    const char* c_api_getNthReactionId(SBMLDocument* document, int reactionIndex) {
        return strdup(getNthReactionId(document, reactionIndex).c_str());
    }

    const int c_api_getNumAllReactionGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumReactionGlyphs(document, layoutIndex);
    }

    const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex) {
        return getNumReactionGlyphs(document, layoutIndex, reactionId);
    }

    const char* c_api_getNthReactionGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex) {
        ReactionGlyph* reactionGlyph = getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex);
        if (reactionGlyph)
            return strdup(reactionGlyph->getId().c_str());

        return "";
    }

    const char* c_api_getNthReactionGlyphMetaId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex) {
        ReactionGlyph* reactionGlyph = getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex);
        if (reactionGlyph)
            return strdup(reactionGlyph->getMetaId().c_str());

        return "";
    }

    bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex) {
        return isReactionGlyph(document, layoutIndex, reactionId);
    }

    const int c_api_getNumSpeciesReferences(SBMLDocument* document, const char* reactionId) {
        return getNumSpeciesReferences(document, reactionId);
    }

    const int c_api_getNumReactants(SBMLDocument* document, const char* reactionId) {
        return getNumReactants(document, reactionId);
    }

    const int c_api_getNumProducts(SBMLDocument* document, const char* reactionId) {
        return getNumProducts(document, reactionId);
    }

    const int c_api_getNumModifiers(SBMLDocument* document, const char* reactionId) {
        return getNumModifiers(document, reactionId);
    }

    const char* c_api_getNthReactantId(SBMLDocument* document, const char* reactionId, int reactantIndex) {
        return strdup(getNthReactantId(document, reactionId, reactantIndex).c_str());
    }

    const char* c_api_getNthProductId(SBMLDocument* document, const char* reactionId, int productIndex) {
        return strdup(getNthProductId(document, reactionId, productIndex).c_str());
    }

    const char* c_api_getNthModifierId(SBMLDocument* document, const char* reactionId, int modifierIndex) {
        return strdup(getNthModifierId(document, reactionId, modifierIndex).c_str());
    }

    const int c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex) {
        return getNumSpeciesReferenceGlyphs(document, layoutIndex, reactionId, reactionGlyphIndex);
    }

    const char* c_api_getSpeciesReferenceSpeciesId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int layoutIndex) {
        return strdup(getSpeciesReferenceSpeciesId(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex).c_str());
    }

    const char* c_api_getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int layoutIndex) {
        return strdup(getSpeciesReferenceSpeciesGlyphId(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex).c_str());
    }

    bool c_api_isSetSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetSpeciesReferenceRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const char* c_api_getSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getSpeciesReferenceRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex).c_str());
    }

    int c_api_setSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
    }

    const int c_api_getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int layoutIndex) {
        return getNumSpeciesReferenceCurveSegments(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex);
    }

    bool c_api_isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return isSpeciesReferenceCurveSegmentCubicBezier(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    const double c_api_getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, x);
    }

    const double c_api_getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, y);
    }

    const double c_api_getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentEndPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentEndPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, x);
    }

    const double c_api_getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentEndPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentEndPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, y);
    }

    const double c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentBasePoint1X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentBasePoint1X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, x);
    }

    const double c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentBasePoint1Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentBasePoint1Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, y);
    }

    const double c_api_getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentBasePoint2X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentBasePoint2X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, x);
    }

    const double c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return getSpeciesReferenceCurveSegmentBasePoint2Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex);
    }

    int c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceIndex, int curveSegmentIndex, int layoutIndex) {
        return setSpeciesReferenceCurveSegmentBasePoint2Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, curveSegmentIndex, y);
    }

    bool c_api_isSetSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetStrokeColor(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex));
    }

    const char* c_api_getSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getStrokeColor(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex)).c_str());
    }

    int c_api_setSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setStrokeColor(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex), borderColor);
    }

    bool c_api_isSetSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetStrokeWidth(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex));
    }

    const double c_api_getSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getStrokeWidth(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex));
    }

    int c_api_setSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setStrokeWidth(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex), borderWidth);
    }

    int c_api_getNumSpeciesReferenceBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getNumStrokeDashes(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex));
    }

    const int c_api_getSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int dashIndex, int layoutIndex) {
        return getStrokeDash(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex), dashIndex);
    }

    int c_api_setSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, const int dash, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int dashIndex, int layoutIndex) {
        return setStrokeDash(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex), dashIndex, dash);
    }

    bool c_api_isSetSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetStartHead(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex));
    }

    const char* c_api_getSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getStartHead(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex)).c_str());
    }

    int c_api_setSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, const char* startHead, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setStartHead(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex), startHead);
    }

    bool c_api_isSetSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetEndHead(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex));
    }

    const char* c_api_getSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getEndHead(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex)).c_str());
    }

    int c_api_setSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, const char* endHead, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setEndHead(document, getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex), endHead);
    }

    const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumTextGlyphs(document, layoutIndex);
    }

    const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return getNumTextGlyphs(document, layoutIndex, id, graphicalObjectIndex);
    }

    const char* c_api_getText(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex, bool useNameAsTextLabel) {
        std::string text = getText(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
        if (!text.empty()) {
            return strdup(text.c_str());
        }
        if (useNameAsTextLabel) {
            text = getName(getSBMLObject(document, getOriginOfTextId(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex)));
            if (!text.empty()) {
                return strdup(text.c_str());
            }
        }
        text = getId(getSBMLObject(document, getOriginOfTextId(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex)));
        if (!text.empty()) {
            return strdup(text.c_str());
        }
        text = getGraphicalObjectId(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
        if (!text.empty()) {
            return strdup(text.c_str());
        }

        return "";
    }

    int c_api_setText(SBMLDocument* document, const char* id, const char* text, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setText(document, layoutIndex, id, textGlyphIndex, text);
    }

    int c_api_addText(SBMLDocument* document, const char* id, const char* text, int graphicalObjectIndex, int layoutIndex) {
        return addText(document, layoutIndex, id, graphicalObjectIndex, text);
    }

    int c_api_removeText(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return removeText(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
    }

    const double c_api_getX(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getPositionX(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, int layoutIndex, bool isLayoutAdded) {
        if (isLayoutAdded) {
            if (!setPositionX(document, layoutIndex, id, graphicalObjectIndex, x) && updateLayoutCurves(document,
                                                                                                        getGraphicalObject(
                                                                                                                document,
                                                                                                                layoutIndex,
                                                                                                                id,
                                                                                                                graphicalObjectIndex)))
                return 0;
        }
        else
            std::cerr << "X cannot be set as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    const double c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getPositionY(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, int layoutIndex, bool isLayoutAdded) {
        if (isLayoutAdded) {
            if (!setPositionY(document, layoutIndex, id, graphicalObjectIndex, y) && updateLayoutCurves(document,
                                                                                                        getGraphicalObject(
                                                                                                                document,
                                                                                                                layoutIndex,
                                                                                                                id,
                                                                                                                graphicalObjectIndex)))
                return 0;
        }
        else
            std::cerr << "Y cannot be set as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    int c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex, int layoutIndex, bool isLayoutAdded) {
        if (isLayoutAdded) {
            if (!setPosition(document, layoutIndex, id, graphicalObjectIndex, x, y) && updateLayoutCurves(document,
                                                                                                        getGraphicalObject(
                                                                                                                document,
                                                                                                                layoutIndex,
                                                                                                                id,
                                                                                                                graphicalObjectIndex)))
                return 0;
        }
        else
            std::cerr << "Position cannot be set as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    const double c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getDimensionWidth(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, int layoutIndex, bool isLayoutAdded) {
        if (isLayoutAdded) {
            if (!setDimensionWidth(document, layoutIndex, id, graphicalObjectIndex, width) && updateLayoutCurves(document,
                                                                                                        getGraphicalObject(
                                                                                                                document,
                                                                                                                layoutIndex,
                                                                                                                id,
                                                                                                                graphicalObjectIndex)))
                return 0;
        }
        else
            std::cerr << "Width cannot be set as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    const double c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getDimensionHeight(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, int layoutIndex, bool isLayoutAdded) {
        if (isLayoutAdded) {
            if (!setDimensionHeight(document, layoutIndex, id, graphicalObjectIndex, height) && updateLayoutCurves(document,
                                                                                                        getGraphicalObject(
                                                                                                                document,
                                                                                                                layoutIndex,
                                                                                                                id,
                                                                                                                graphicalObjectIndex)))
                return 0;
        }
        else
            std::cerr << "Height cannot be set as the layout is not set by the autolayout algorithm." << std::endl;

        return -1;
    }

    const double c_api_getTextX(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return getTextPositionX(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
    }

    int c_api_setTextX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setTextPositionX(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex, x);
    }

    const double c_api_getTextY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return getTextPositionY(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
    }

    int c_api_setTextY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setTextPositionY(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex, y);
    }

    int c_api_setTextPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setTextPosition(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex, x, y);
    }

    const double c_api_getTextWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return getDimensionWidth(getAssociatedTextGlyphsWithGraphicalObject(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).at(textGlyphIndex));
    }

    int c_api_setTextWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setDimensionWidth(getAssociatedTextGlyphsWithGraphicalObject(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).at(textGlyphIndex), width);
    }

    const double c_api_getTextHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return getDimensionHeight(getAssociatedTextGlyphsWithGraphicalObject(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).at(textGlyphIndex));
    }

    int c_api_setTextHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setDimensionHeight(getAssociatedTextGlyphsWithGraphicalObject(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).at(textGlyphIndex), height);
    }

    bool c_api_isSetCurve(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetCurve(document, layoutIndex, id, graphicalObjectIndex);
    }

    const int c_api_getNumCurveSegments(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return getNumCurveSegments(document, layoutIndex, id, graphicalObjectIndex);
    }

    bool c_api_isCurveSegmentCubicBezier(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return isCubicBezier(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }

    const double c_api_getCurveSegmentStartPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentStartPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }

    int c_api_setCurveSegmentStartPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentStartPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveSegmentStartPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentStartPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentStartPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentStartPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
    
    const double c_api_getCurveSegmentEndPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentEndPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentEndPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentEndPointX(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveSegmentEndPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentEndPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentEndPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentEndPointY(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
    
    const double c_api_getCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint1X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint1X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint1Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint1Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }
    
    const double c_api_getCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint2X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint2X(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, x);
    }
    
    const double c_api_getCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return getCurveSegmentBasePoint2Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex);
    }
    
    int c_api_setCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex, int curveSegmentIndex, int layoutIndex) {
        return setCurveSegmentBasePoint2Y(document, layoutIndex, id, graphicalObjectIndex, curveSegmentIndex, y);
    }

    const int c_api_getNumGlobalRenderInformation(SBMLDocument* document) {
        return getNumGlobalRenderInformation(document);
    }

    const int c_api_getNumLocalRenderInformation(SBMLDocument* document, int layoutIndex) {
        return getNumLocalRenderInformation(document, layoutIndex);
    }

    int c_api_removeRenderInformation(SBMLDocument* document) {
        if (removeAllGlobalRenderInformation(document), removeAllLocalRenderInformation(document))
        return 0;

        return 0;
    }

    int c_api_removeGlobalRenderInformation(SBMLDocument* document) {
        return removeAllGlobalRenderInformation(document);
    }

    int c_api_removeLocalRenderInformation(SBMLDocument* document, int layoutIndex) {
        return removeAllLocalRenderInformation(document, layoutIndex);
    }

    int c_api_createDefaultGlobalRenderInformation(SBMLDocument* document) {
        return createDefaultGlobalRenderInformation(document);
    }

    int c_api_createDefaultLocalRenderInformation(SBMLDocument* document) {
        return createDefaultLocalRenderInformation(document);
    }

    bool c_api_isSetBackgroundColor(SBMLDocument* document, int renderIndex) {
        return isSetBackgroundColor(document, renderIndex);
    }

    const char* c_api_getBackgroundColor(SBMLDocument* document, int renderIndex) {
        return strdup(getBackgroundColor(document, renderIndex).c_str());
    }

    int c_api_setBackgroundColor(SBMLDocument* document, const char* backgroundColor, int renderIndex) {
        return setBackgroundColor(document, renderIndex, backgroundColor);
    }

    const int c_api_getNumColors(SBMLDocument* document, int renderIndex) {
        return getNumGlobalColorDefinitions(document, renderIndex) + getNumLocalColorDefinitions(document, renderIndex);
    }

    const int c_api_getNumGlobalColors(SBMLDocument* document, int renderIndex) {
        return getNumGlobalColorDefinitions(document, renderIndex);
    }

    const int c_api_getNumLocalColors(SBMLDocument* document, int renderIndex) {
        return getNumLocalColorDefinitions(document, renderIndex);
    }

    const char* c_api_getNthGlobalColorId(SBMLDocument* document, int colorIndex, int renderIndex) {
        return strdup(getNthGlobalColorDefinitionId(document, renderIndex, colorIndex).c_str());
    }

    const char* c_api_getNthLocalColorId(SBMLDocument* document, int colorIndex, int renderIndex) {
        return strdup(getNthLocalColorDefinitionId(document, renderIndex, colorIndex).c_str());
    }

    bool c_api_isSetColorValue(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetValue(document, renderIndex, id);
    }

    const char* c_api_getColorValue(SBMLDocument* document, const char* id, int renderIndex) {
        return strdup(getValue(document, renderIndex, id).c_str());
    }

    int c_api_setColorValue(SBMLDocument* document, const char* id, const char* value, int renderIndex) {
        return setValue(document, renderIndex, id, value);
    }

    const int c_api_getNumGradients(SBMLDocument* document, int renderIndex) {
        return getNumGlobalGradientDefinitions(document, renderIndex) + getNumLocalGradientDefinitions(document, renderIndex);
    }

    const int c_api_getNumGlobalGradients(SBMLDocument* document, int renderIndex) {
        return getNumGlobalGradientDefinitions(document, renderIndex);
    }

    const int c_api_getNumLocalGradients(SBMLDocument* document, int renderIndex) {
        return getNumLocalGradientDefinitions(document, renderIndex);
    }

    const char* c_api_getNthGlobalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex) {
        return strdup(getNthGlobalGradientDefinitionId(document, renderIndex, gradientIndex).c_str());
    }

    const char* c_api_getNthLocalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex) {
        return strdup(getNthLocalGradientDefinitionId(document, renderIndex, gradientIndex).c_str());
    }

    bool c_api_isLinearGradient(SBMLDocument* document, const char* id, int renderIndex) {
        return isLinearGradient(document, renderIndex, id);
    }

    bool c_api_isRadialGradient(SBMLDocument* document, const char* id, int renderIndex) {
        return isRadialGradient(document, renderIndex, id);
    }

    bool c_api_isSetSpreadMethod(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetSpreadMethod(document, renderIndex, id);
    }

    const char* c_api_getSpreadMethod(SBMLDocument* document, const char* id, int renderIndex) {
        return strdup(getSpreadMethod(document, renderIndex, id).c_str());
    }

    int c_api_setSpreadMethod(SBMLDocument* document, const char* id, const char* spreadMethod, int renderIndex) {
        return setSpreadMethod(document, renderIndex, id, spreadMethod);
    }

    int c_api_getNumGradientStops(SBMLDocument* document, const char* id, int renderIndex) {
        return getNumGradientStops(document, renderIndex, id);
    }

    bool c_api_isSetOffset(SBMLDocument* document, const char* id, int gradientStopIndex, int renderIndex) {
        return isSetOffset(document, renderIndex, id, gradientStopIndex);
    }

    const double c_api_getOffset(SBMLDocument* document, const char* id, int gradientStopIndex, int renderIndex) {
        RelAbsVector offsetVector =  getOffset(document, renderIndex, id, gradientStopIndex);
        return offsetVector.getRelativeValue();
    }

    int c_api_setOffset(SBMLDocument* document, const char* id, const double offset, int gradientStopIndex, int renderIndex) {
        RelAbsVector offsetVector;
        offsetVector.setRelativeValue(offset);
        return setOffset(document, renderIndex, id, gradientStopIndex, offsetVector);
    }

    bool c_api_isSetStopColor(SBMLDocument* document, const char* id, int gradientStopIndex, int renderIndex) {
        return isSetStopColor(document, renderIndex, id, gradientStopIndex);
    }

    const char* c_api_getStopColor(SBMLDocument* document, const char* id, int gradientStopIndex, int renderIndex) {
        return strdup(getStopColor(document, renderIndex, id, gradientStopIndex).c_str());
    }

    int c_api_setStopColor(SBMLDocument* document, const char* id, const char* stopColor, int gradientStopIndex, int renderIndex) {
        return setStopColor(document, renderIndex, id, gradientStopIndex, stopColor);
    }

    int c_isSetLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientX1(document, renderIndex, id);
    }

    const double c_api_getLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector x1Vector = getLinearGradientX1(document, renderIndex, id);
        return  x1Vector.getRelativeValue();
    }

    int c_api_setLinearGradientX1(SBMLDocument* document, const char* id, const double x1, int renderIndex) {
        RelAbsVector x1Vector;
        x1Vector.setRelativeValue(x1);
        return setLinearGradientX1(document, renderIndex, id, x1Vector);
    }

    bool c_api_isSetLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientY1(document, renderIndex, id);
    }

    const double c_api_getLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector y1Vector = getLinearGradientY1(document, renderIndex, id);
        return  y1Vector.getRelativeValue();
    }

    int c_api_setLinearGradientY1(SBMLDocument* document, const char* id, const double y1, int renderIndex) {
        RelAbsVector y1Vector;
        y1Vector.setRelativeValue(y1);
        return setLinearGradientY1(document, renderIndex, id, y1Vector);
    }

    bool c_api_isSetLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientX2(document, renderIndex, id);
    }

    const double c_api_getLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector x2Vector = getLinearGradientX2(document, renderIndex, id);
        return  x2Vector.getRelativeValue();
    }

    int c_api_setLinearGradientX2(SBMLDocument* document, const char* id, const double x2, int renderIndex) {
        RelAbsVector x2Vector;
        x2Vector.setRelativeValue(x2);
        return setLinearGradientX2(document, renderIndex, id, x2Vector);
    }

    bool c_api_isSetLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientY2(document, renderIndex, id);
    }

    const double c_api_getLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector y2Vector = getLinearGradientY2(document, renderIndex, id);
        return  y2Vector.getRelativeValue();
    }

    int c_api_setLinearGradientY2(SBMLDocument* document, const char* id, const double y2, int renderIndex) {
        RelAbsVector y2Vector;
        y2Vector.setRelativeValue(y2);
        return setLinearGradientY2(document, renderIndex, id, y2Vector);
    }

    bool c_api_isSetRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientCx(document, renderIndex, id);
    }

    const double c_api_getRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector cxVector = getRadialGradientCx(document, renderIndex, id);
        return  cxVector.getRelativeValue();
    }

    int c_api_setRadialGradientCenterX(SBMLDocument* document, const char* id, const double cx, int renderIndex) {
        RelAbsVector cxVector;
        cxVector.setRelativeValue(cx);
        return setRadialGradientCx(document, renderIndex, id, cxVector);
    }

    bool c_api_isSetRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientCy(document, renderIndex, id);
    }

    const double c_api_getRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector cyVector = getRadialGradientCy(document, renderIndex, id);
        return  cyVector.getRelativeValue();
    }

    int c_api_setRadialGradientCenterY(SBMLDocument* document, const char* id, const double cy, int renderIndex) {
        RelAbsVector cyVector;
        cyVector.setRelativeValue(cy);
        return setRadialGradientCy(document, renderIndex, id, cyVector);
    }

    bool c_api_isSetRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientR(document, renderIndex, id);
    }

    const double c_api_getRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector rVector = getRadialGradientR(document, renderIndex, id);
        return  rVector.getRelativeValue();
    }

    int c_api_setRadialGradientRadius(SBMLDocument* document, const char* id, const double r, int renderIndex) {
        RelAbsVector rVector;
        rVector.setRelativeValue(r);
        return setRadialGradientR(document, renderIndex, id, rVector);
    }

    bool c_api_isSetRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientFx(document, renderIndex, id);
    }

    const double c_api_getRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector fxVector = getRadialGradientFx(document, renderIndex, id);
        return  fxVector.getRelativeValue();
    }

    int c_api_setRadialGradientFocalX(SBMLDocument* document, const char* id, const double fx, int renderIndex) {
        RelAbsVector fxVector;
        fxVector.setRelativeValue(fx);
        return setRadialGradientFx(document, renderIndex, id, fxVector);
    }

    bool c_api_isSetRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientFy(document, renderIndex, id);
    }

    const double c_api_getRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex) {
        RelAbsVector fyVector = getRadialGradientFy(document, renderIndex, id);
        return  fyVector.getRelativeValue();
    }

    int c_api_setRadialGradientFocalY(SBMLDocument* document, const char* id, const double fy, int renderIndex) {
        RelAbsVector fyVector;
        fyVector.setRelativeValue(fy);
        return setRadialGradientFy(document, renderIndex, id, fyVector);
    }

    const int c_api_getNumLineEndings(SBMLDocument* document, int renderIndex) {
        return getNumGlobalLineEndings(document, renderIndex) + getNumLocalLineEndings(document, renderIndex);
    }

    const int c_api_getNumGlobalLineEndings(SBMLDocument* document, int renderIndex) {
        return getNumGlobalLineEndings(document, renderIndex);
    }

    const int c_api_getNumLocalLineEndings(SBMLDocument* document, int renderIndex) {
        return getNumLocalLineEndings(document, renderIndex);
    }

    const char* c_api_getNthGlobalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex) {
        return strdup(getNthGlobalLineEndingId(document, renderIndex, lineEndingIndex).c_str());
    }

    const char* c_api_getNthLocalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex) {
        return strdup(getNthLocalLineEndingId(document, renderIndex, lineEndingIndex).c_str());
    }

    const double c_api_getLineEndingBoundingBoxX(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxX(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxX(SBMLDocument* document, const char* id, const double x, int renderIndex) {
        return setLineEndingBoundingBoxX(document, renderIndex, id, x);
    }

    const double c_api_getLineEndingBoundingBoxY(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxY(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxY(SBMLDocument* document, const char* id, const double y, int renderIndex) {
        return setLineEndingBoundingBoxY(document, renderIndex, id, y);
    }

    const double c_api_getLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxWidth(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, const double width, int renderIndex) {
        return setLineEndingBoundingBoxWidth(document, renderIndex, id, width);
    }

    const double c_api_getLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxHeight(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, const double height, int renderIndex) {
        return setLineEndingBoundingBoxHeight(document, renderIndex, id, height);
    }

    bool c_api_isSetLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLineEndingStrokeColor(document, renderIndex, id);
    }

    const char* c_api_getLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex) {
        return strdup(getLineEndingStrokeColor(document, renderIndex, id).c_str());
    }

    int c_api_setLineEndingBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int renderIndex) {
        return setLineEndingStrokeColor(document, renderIndex, id, borderColor);
    }

    bool c_api_isSetLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLineEndingStrokeWidth(document, renderIndex, id);
    }

    const double c_api_getLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingStrokeWidth(document, renderIndex, id);
    }

    int c_api_setLineEndingBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int renderIndex) {
        return setLineEndingStrokeWidth(document, renderIndex, id, borderWidth);
    }

    int c_api_getNumLineEndingBorderDashes(SBMLDocument* document, const char* id, int renderIndex) {
        return getNumLineEndingStrokeDashes(document, renderIndex, id);
    }

    const int c_api_getLineEndingNthBorderDash(SBMLDocument* document, const char* id, int dashIndex, int renderIndex) {
        return getLineEndingStrokeDash(document, renderIndex, id, dashIndex);
    }

    int c_api_setLineEndingNthBorderDash(SBMLDocument* document, const char* id, const int dash, int dashIndex, int renderIndex) {
        return setLineEndingStrokeDash(document, renderIndex, id, dashIndex, dash);
    }

    bool c_api_isSetLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLineEndingFillColor(document, renderIndex, id);
    }

    const char* c_api_getLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex) {
        return strdup(getLineEndingFillColor(document, renderIndex, id).c_str());
    }

    int c_api_setLineEndingFillColor(SBMLDocument* document, const char* id, const char* fillColor, int renderIndex) {
        return setLineEndingFillColor(document, renderIndex, id, fillColor);
    }

    bool c_api_isSetLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLineEndingFillRule(document, renderIndex, id);
    }

    const char* c_api_getLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex) {
        return strdup(getLineEndingFillRule(document, renderIndex, id).c_str());
    }

    int c_api_setLineEndingFillRule(SBMLDocument* document, const char* id, const char* fillRule, int renderIndex) {
        return setLineEndingFillRule(document, renderIndex, id, fillRule);
    }

    const int c_api_getNumLineEndingGeometricShapes(SBMLDocument* document, const char* id, int renderIndex) {
        return getNumLineEndingGeometricShapes(document, renderIndex, id);
    }

    bool c_api_isLineEndingRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingRectangle(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isLineEndingEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingEllipse(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isLineEndingPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingPolygon(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isLineEndingImage(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingImage(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isLineEndingRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingRenderCurve(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isLineEndingText(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingText(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSetLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector xVector = getLineEndingGeometricShapeX(document, id, geometricShapeIndex);
        return xVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * xVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex, int renderIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setLineEndingGeometricShapeX(document, id, geometricShapeIndex, xVector);
    }

    bool c_api_isSetLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector yVector = getLineEndingGeometricShapeY(document, id, geometricShapeIndex);
        return yVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * yVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex, int renderIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setLineEndingGeometricShapeY(document, id, geometricShapeIndex, yVector);
    }

    bool c_api_isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeWidth(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector widthVector = getLineEndingGeometricShapeWidth(document, id, geometricShapeIndex);
        return widthVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * widthVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex, int renderIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setLineEndingGeometricShapeWidth(document, id, geometricShapeIndex, widthVector);
    }

    bool c_api_isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeHeight(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector heightVector = getLineEndingGeometricShapeHeight(document, id, geometricShapeIndex);
        return heightVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * heightVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex, int renderIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setLineEndingGeometricShapeHeight(document, id, geometricShapeIndex, heightVector);
    }

    bool c_api_isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeRatio(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeRatio(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeRatio(document, renderIndex, id, geometricShapeIndex, ratio);
    }

    bool c_api_isSetLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCornerCurvatureRadiusX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector borderRadiusXVector = getLineEndingGeometricShapeCornerCurvatureRadiusX(document, id, geometricShapeIndex);
        return borderRadiusXVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * borderRadiusXVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex, int renderIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setLineEndingGeometricShapeCornerCurvatureRadiusX(document, id, geometricShapeIndex, borderRadiusXVector);
    }

    bool c_api_isSetLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCornerCurvatureRadiusY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector borderRadiusYVector = getLineEndingGeometricShapeCornerCurvatureRadiusY(document, id, geometricShapeIndex);
        return borderRadiusYVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * borderRadiusYVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex, int renderIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setLineEndingGeometricShapeCornerCurvatureRadiusY(document, id, geometricShapeIndex, borderRadiusYVector);
    }

    bool c_api_isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCenterX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector centerXVector = getLineEndingGeometricShapeCenterX(document, id, geometricShapeIndex);
        return centerXVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * centerXVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex, int renderIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setLineEndingGeometricShapeCenterX(document, id, geometricShapeIndex, centerXVector);
    }

    bool c_api_isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCenterY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector centerYVector = getLineEndingGeometricShapeCenterY(document, id, geometricShapeIndex);
        return centerYVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * centerYVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex, int renderIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setLineEndingGeometricShapeCenterY(document, id, geometricShapeIndex, centerYVector);
    }

    bool c_api_isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeRadiusX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector radiusXVector = getLineEndingGeometricShapeRadiusX(document, id, geometricShapeIndex);
        return radiusXVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * radiusXVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex, int renderIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setLineEndingGeometricShapeRadiusX(document, id, geometricShapeIndex, radiusXVector);
    }

    bool c_api_isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeRadiusY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        RelAbsVector radiusYVector = getLineEndingGeometricShapeRadiusY(document, id, geometricShapeIndex);
        return radiusYVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * radiusYVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex, int renderIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setLineEndingGeometricShapeRadiusY(document, id, geometricShapeIndex, radiusYVector);
    }

    int c_api_getLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeNumElements(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return isLineEndingGeometricShapeElementCubicBezier(document, renderIndex, id, geometricShapeIndex, segmentIndex);
    }

    const double c_api_getLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector xVector = getLineEndingGeometricShapeElementX(document, id, geometricShapeIndex, segmentIndex);
        return xVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * xVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setLineEndingGeometricShapeElementX(document, id, geometricShapeIndex, segmentIndex, xVector);
    }

    const double c_api_getLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector yVector = getLineEndingGeometricShapeElementY(document, id, geometricShapeIndex, segmentIndex);
        return yVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * yVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setLineEndingGeometricShapeElementY(document, id, geometricShapeIndex, segmentIndex, yVector);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint1XVector = getLineEndingGeometricShapeBasePoint1X(document, id, geometricShapeIndex, segmentIndex);
        return basePoint1XVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * basePoint1XVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint1XVector;
        basePoint1XVector.setAbsoluteValue(x);
        return setLineEndingGeometricShapeBasePoint1X(document, id, geometricShapeIndex, segmentIndex, basePoint1XVector);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint1YVector = getLineEndingGeometricShapeBasePoint1Y(document, id, geometricShapeIndex, segmentIndex);
        return basePoint1YVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * basePoint1YVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint1YVector;
        basePoint1YVector.setAbsoluteValue(y);
        return setLineEndingGeometricShapeBasePoint1Y(document, id, geometricShapeIndex, segmentIndex, basePoint1YVector);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint2XVector = getLineEndingGeometricShapeBasePoint2X(document, id, geometricShapeIndex, segmentIndex);
        return basePoint2XVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxWidth(document, id) * basePoint2XVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint2XVector;
        basePoint2XVector.setAbsoluteValue(x);
        return setLineEndingGeometricShapeBasePoint2X(document, id, geometricShapeIndex, segmentIndex, basePoint2XVector);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint2YVector = getLineEndingGeometricShapeBasePoint2Y(document, id, geometricShapeIndex, segmentIndex);
        return basePoint2YVector.getAbsoluteValue() + 0.01 * c_api_getLineEndingBoundingBoxHeight(document, id) * basePoint2YVector.getRelativeValue();
    }

    int c_api_setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        RelAbsVector basePoint2YVector;
        basePoint2YVector.setAbsoluteValue(y);
        return setLineEndingGeometricShapeBasePoint2Y(document, id, geometricShapeIndex, segmentIndex, basePoint2YVector);
    }

    bool c_api_isSetLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeHref(document, renderIndex, id, geometricShapeIndex);
    }

    const char* c_api_getLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return strdup(getLineEndingGeometricShapeHref(document, renderIndex, id, geometricShapeIndex).c_str());
    }

    int c_api_setLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeHref(document, renderIndex, id, geometricShapeIndex, href);
    }

    bool c_api_isSetBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    bool c_api_isSetLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id))
            return isSetStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));

        return false;
    }

    const char* c_api_getBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).c_str());
    }

    const char* c_api_getLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id))
            return strdup(getStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).c_str());

        return "";
    }

    int c_api_setBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int graphicalObjectIndex, int layoutIndex) {
        return setStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), borderColor);
    }

    int c_api_setLineColor(SBMLDocument* document, const char* id, const char* borderColor, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id)) {
            for (unsigned int i = 0; i < getNumSpeciesReferences(document, id); i++)
                setStrokeColor(document, getSpeciesReferenceGlyph(document, layoutIndex, id, graphicalObjectIndex, i), borderColor);

            return setStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), borderColor);
        }

        return -1;
    }

    int c_api_setCompartmentsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setCompartmentStrokeColor(document, layoutIndex, borderColor);
    }

    int c_api_setSpeciesBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setSpeciesStrokeColor(document, layoutIndex, borderColor);
    }

    int c_api_setReactionsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setReactionStrokeColor(document, layoutIndex, borderColor, false);
    }

    int c_api_setReactionsLineColors(SBMLDocument* document, const char* lineColor, int layoutIndex) {
        return setReactionStrokeColor(document, layoutIndex, lineColor);
    }

    int c_api_setLineEndingsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setLineEndingsStrokeColor(document, layoutIndex, borderColor);
    }

    int c_api_setBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setStrokeColor(document, layoutIndex, borderColor);
    }

    bool c_api_isSetBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    bool c_api_isSetLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id))
            return isSetStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));

        return false;
    }

    const double c_api_getBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return getStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    const double c_api_getLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id))
            return getStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));

        return -1;
    }

    int c_api_setBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int graphicalObjectIndex, int layoutIndex) {
        return setStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), borderWidth);
    }

    int c_api_setLineWidth(SBMLDocument* document, const char* id, const double lineWidth, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id)) {
            for (unsigned int i = 0; i < getNumSpeciesReferences(document, id); i++)
                setStrokeWidth(document, getSpeciesReferenceGlyph(document, layoutIndex, id, graphicalObjectIndex, i), lineWidth);

            return setStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), lineWidth);
        }

        return -1;
    }

    int c_api_setCompartmentsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setCompartmentStrokeWidth(document, layoutIndex, borderWidth);
    }

    int c_api_setSpeciesBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setSpeciesStrokeWidth(document, layoutIndex, borderWidth);
    }

    int c_api_setReactionsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setReactionStrokeWidth(document, layoutIndex, borderWidth, false);
    }

    int c_api_setReactionsLineWidths(SBMLDocument* document, const double lineWidth, int layoutIndex) {
        return setReactionStrokeWidth(document, layoutIndex, lineWidth);
    }

    int c_api_setLineEndingsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setLineEndingsStrokeWidth(document, layoutIndex, borderWidth);
    }

    int c_api_setBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setStrokeWidth(document, layoutIndex, borderWidth);
    }

    int c_api_getNumBorderDashes(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return getNumStrokeDashes(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    const int c_api_getNthBorderDash(SBMLDocument* document, const char* id, int dashIndex, int graphicalObjectIndex, int layoutIndex) {
        return getStrokeDash(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), dashIndex);
    }

    int c_api_setNthBorderDash(SBMLDocument* document, const char* id, const int dash, int dashIndex, int graphicalObjectIndex, int layoutIndex) {
        if (isReactionGlyph(document, layoutIndex, id)) {
            for (unsigned int i = 0; i < getNumSpeciesReferences(document, id); i++)
                setStrokeDash(document, getSpeciesReferenceGlyph(document, layoutIndex, id, graphicalObjectIndex, i), dash);
        }
        return setStrokeDash(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), dashIndex, dash);
    }

    bool c_api_isSetFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetFillColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    const char* c_api_getFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getFillColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).c_str());
    }

    int c_api_setFillColor(SBMLDocument* document, const char* id, const char* fillColor, int graphicalObjectIndex, int layoutIndex) {
        return setFillColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), fillColor);
    }

    int c_api_setCompartmentsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setCompartmentFillColor(document, layoutIndex, fillColor);
    }

    int c_api_setSpeciesFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setSpeciesFillColor(document, layoutIndex, fillColor);
    }

    int c_api_setReactionsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setReactionFillColor(document, layoutIndex, fillColor);
    }

    int c_api_setLineEndingsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setLineEndingsFillColor(document, layoutIndex, fillColor);
    }

    int c_api_setFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setFillColor(document, layoutIndex, fillColor);
    }

    bool c_api_isSetFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetFillRule(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    const char* c_api_getFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getFillRule(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).c_str());
    }

    int c_api_setFillRule(SBMLDocument* document, const char* id, const char* fillRule, int graphicalObjectIndex, int layoutIndex) {
        return setFillRule(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), fillRule);
    }

    int c_api_setCompartmentsFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex) {
        return setCompartmentFillRule(document, layoutIndex, fillRule);
    }

    int c_api_setSpeciesFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex) {
        return setSpeciesFillRule(document, layoutIndex, fillRule);
    }

    int c_api_setFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex) {
        return setFillRule(document, layoutIndex, fillRule);
    }

    bool c_api_isSetFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetFontColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const char* c_api_getFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return strdup(getFontColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex).c_str());
    }

    int c_api_setFontColor(SBMLDocument* document, const char* id, const char* fontColor, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setFontColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, fontColor);
    }

    int c_api_setCompartmentsFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex) {
        return setCompartmentFontColor(document, layoutIndex, fontColor);
    }

    int c_api_setSpeciesFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex) {
        return setSpeciesFontColor(document, layoutIndex, fontColor);
    }

    int c_api_setReactionsFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex) {
        return setReactionFontColor(document, layoutIndex, fontColor);
    }

    int c_api_setFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex) {
        return setFontColor(document, layoutIndex, fontColor);
    }

    bool c_api_isSetFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetFontFamily(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const char* c_api_getFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return strdup(getFontFamily(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex).c_str());
    }

    int c_api_setFontFamily(SBMLDocument* document, const char* id, const char* fontFamily, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setFontFamily(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, fontFamily);
    }

    int c_api_setCompartmentsFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setCompartmentFontFamily(document, layoutIndex, fontFamily);
    }

    int c_api_setSpeciesFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setSpeciesFontFamily(document, layoutIndex, fontFamily);
    }

    int c_api_setReactionsFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setReactionFontFamily(document, layoutIndex, fontFamily);
    }

    int c_api_setFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setFontFamily(document, layoutIndex, fontFamily);
    }

    bool c_api_isSetFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetFontSize(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const double c_api_getFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        RelAbsVector fontSizeVector = getFontSize(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
        return fontSizeVector.getAbsoluteValue() + 0.5 * (getTextDimensionWidth(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex) +
                getTextDimensionHeight(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex)) * fontSizeVector.getRelativeValue();
    }

    int c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        RelAbsVector fontSizeVector;
        fontSizeVector.setAbsoluteValue(fontSize);
        return setFontSize(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, fontSizeVector);
    }

    int c_api_setCompartmentsFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex) {
        RelAbsVector fontSizeVector;
        fontSizeVector.setAbsoluteValue(fontSize);
        return setCompartmentFontSize(document, layoutIndex, fontSizeVector);
    }

    int c_api_setSpeciesFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex) {
        RelAbsVector fontSizeVector;
        fontSizeVector.setAbsoluteValue(fontSize);
        return setSpeciesFontSize(document, layoutIndex, fontSizeVector);
    }

    int c_api_setReactionsFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex) {
        RelAbsVector fontSizeVector;
        fontSizeVector.setAbsoluteValue(fontSize);
        return setReactionFontSize(document, layoutIndex, fontSizeVector);
    }

    int c_api_setFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex) {
        RelAbsVector fontSizeVector;
        fontSizeVector.setAbsoluteValue(fontSize);
        return setFontSize(document, layoutIndex, fontSizeVector);
    }

    bool c_api_isSetFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetFontWeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const char* c_api_getFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return strdup(getFontWeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex).c_str());
    }

    int c_api_setFontWeight(SBMLDocument* document, const char* id, const char* fontWeight, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setFontWeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, fontWeight);
    }

    int c_api_setCompartmentsFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
        return setCompartmentFontWeight(document, layoutIndex, fontWeight);
    }

    int c_api_setSpeciesFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
        return setSpeciesFontWeight(document, layoutIndex, fontWeight);
    }

    int c_api_setReactionsFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
        return setReactionFontWeight(document, layoutIndex, fontWeight);
    }

    int c_api_setFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
        return setFontWeight(document, layoutIndex, fontWeight);
    }

    bool c_api_isSetFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetFontStyle(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const char* c_api_getFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return strdup(getFontStyle(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex).c_str());
    }

    int c_api_setFontStyle(SBMLDocument* document, const char* id, const char* fontStyle, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setFontStyle(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, fontStyle);
    }

    int c_api_setCompartmentsFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
        return setCompartmentFontStyle(document, layoutIndex, fontStyle);
    }

    int c_api_setSpeciesFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
        return setSpeciesFontStyle(document, layoutIndex, fontStyle);
    }

    int c_api_setReactionsFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
        return setReactionFontStyle(document, layoutIndex, fontStyle);
    }

    int c_api_setFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
        return setFontStyle(document, layoutIndex, fontStyle);
    }

    bool c_api_isSetTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetTextAnchor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const char* c_api_getTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return strdup(getTextAnchor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex).c_str());
    }

    int c_api_setTextHorizontalAlignment(SBMLDocument* document, const char* id, const char* textHorizontalAlignment, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setTextAnchor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, textHorizontalAlignment);
    }

    int c_api_setCompartmentsTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
        return setCompartmentTextAnchor(document, layoutIndex, textHorizontalAlignment);
    }

    int c_api_setSpeciesTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
        return setSpeciesTextAnchor(document, layoutIndex, textHorizontalAlignment);
    }

    int c_api_setReactionsTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
        return setReactionTextAnchor(document, layoutIndex, textHorizontalAlignment);
    }

    int c_api_setTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
        return setTextAnchor(document, layoutIndex, textHorizontalAlignment);
    }

    bool c_api_isSetTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetVTextAnchor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const char* c_api_getTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return strdup(getVTextAnchor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex).c_str());
    }

    int c_api_setTextVerticalAlignment(SBMLDocument* document, const char* id, const char* textVerticalAlignment, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setVTextAnchor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, textVerticalAlignment);
    }

    int c_api_setCompartmentsTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
        return setCompartmentVTextAnchor(document, layoutIndex, textVerticalAlignment);
    }

    int c_api_setSpeciesTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
        return setSpeciesVTextAnchor(document, layoutIndex, textVerticalAlignment);
    }

    int c_api_setReactionsTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
        return setReactionVTextAnchor(document, layoutIndex, textVerticalAlignment);
    }

    int c_api_setTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
        return setVTextAnchor(document, layoutIndex, textVerticalAlignment);
    }

    bool c_api_isSetStartHead(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetStartHead(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    const char* c_api_getStartHead(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getStartHead(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).c_str());
    }

    int c_api_setStartHead(SBMLDocument* document, const char* id, const char* startHead, int graphicalObjectIndex, int layoutIndex) {
        return setStartHead(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), startHead);
    }

    bool c_api_isSetEndHead(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return isSetEndHead(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    const char* c_api_getEndHead(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getEndHead(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex)).c_str());
    }

    int c_api_setEndHead(SBMLDocument* document, const char* id, const char* endHead, int graphicalObjectIndex, int layoutIndex) {
        return setEndHead(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), endHead);
    }

    int c_api_getNumGeometricShapes(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex) {
        return getNumGeometricShapes(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
    }

    int c_api_addGeometricShape(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex, int layoutIndex) {
        return addGeometricShape(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), shape);
    }

    int c_api_removeGeometricShape(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        if (removeGeometricShape(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex))
            return 0;

        return -1;
    }

    int c_api_setGeometricShape(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShape(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), shape);
    }

    int c_api_setCompartmentsGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setCompartmentGeometricShape(document, layoutIndex, shape);
    }

    int c_api_setSpeciesGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setSpeciesGeometricShape(document, layoutIndex, shape);
    }

    int c_api_setReactionsGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setReactionGeometricShape(document, layoutIndex, shape);
    }

    int c_api_setGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setGeometricShape(document, layoutIndex, shape);
    }

    bool c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isRectangle(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isEllipse(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isPolygon(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isImage(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isImage(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isRenderCurve(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isText(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isText(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isSetGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector xVector = getGeometricShapeX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return xVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * xVector.getRelativeValue();
    }

    int c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setGeometricShapeX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, xVector);
    }

    int c_api_setCompartmentsGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setCompartmentGeometricShapeX(document, layoutIndex, xVector);
    }

    int c_api_setSpeciesGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setSpeciesGeometricShapeX(document, layoutIndex, xVector);
    }

    int c_api_setReactionsGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setReactionGeometricShapeX(document, layoutIndex, xVector);
    }

    int c_api_setGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex) {
        RelAbsVector xVector;
        xVector.setAbsoluteValue(x);
        return setGeometricShapeX(document, layoutIndex, xVector);
    }

    bool c_api_isSetGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector yVector = getGeometricShapeY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return yVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * yVector.getRelativeValue();
    }

    int c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setGeometricShapeY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, yVector);
    }

    int c_api_setCompartmentsGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setCompartmentGeometricShapeY(document, layoutIndex, yVector);
    }

    int c_api_setSpeciesGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setSpeciesGeometricShapeY(document, layoutIndex, yVector);
    }

    int c_api_setReactionsGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setReactionGeometricShapeY(document, layoutIndex, yVector);
    }

    int c_api_setGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex) {
        RelAbsVector yVector;
        yVector.setAbsoluteValue(y);
        return setGeometricShapeY(document, layoutIndex, yVector);
    }

    bool c_api_isSetGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector widthVector = getGeometricShapeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return widthVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * widthVector.getRelativeValue();
    }

    int c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setGeometricShapeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, widthVector);
    }

    int c_api_setCompartmentsGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setCompartmentGeometricShapeWidth(document, layoutIndex, widthVector);
    }

    int c_api_setSpeciesGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setSpeciesGeometricShapeWidth(document, layoutIndex, widthVector);
    }

    int c_api_setReactionsGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setReactionGeometricShapeWidth(document, layoutIndex, widthVector);
    }

    int c_api_setGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex) {
        RelAbsVector widthVector;
        widthVector.setAbsoluteValue(width);
        return setGeometricShapeWidth(document, layoutIndex, widthVector);
    }

    bool c_api_isSetGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeHeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector heightVector = getGeometricShapeHeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return heightVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * heightVector.getRelativeValue();
    }

    int c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setGeometricShapeHeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, heightVector);
    }

    int c_api_setCompartmentsGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setCompartmentGeometricShapeHeight(document, layoutIndex, heightVector);
    }

    int c_api_setSpeciesGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setSpeciesGeometricShapeHeight(document, layoutIndex, heightVector);
    }

    int c_api_setReactionsGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setReactionGeometricShapeHeight(document, layoutIndex, heightVector);
    }

    int c_api_setGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex) {
        RelAbsVector heightVector;
        heightVector.setAbsoluteValue(height);
        return setGeometricShapeHeight(document, layoutIndex, heightVector);
    }

    bool c_api_isSetGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeRatio(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeRatio(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeRatio(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, ratio);
    }

    int c_api_setCompartmentsGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setCompartmentGeometricShapeRatio(document, layoutIndex, ratio);
    }

    int c_api_setSpeciesGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setSpeciesGeometricShapeRatio(document, layoutIndex, ratio);
    }

    int c_api_setReactionsGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setReactionGeometricShapeRatio(document, layoutIndex, ratio);
    }

    int c_api_setGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setGeometricShapeRatio(document, layoutIndex, ratio);
    }

    bool c_api_isSetGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCornerCurvatureRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector borderRadiusXVector = getGeometricShapeCornerCurvatureRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return borderRadiusXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * borderRadiusXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setGeometricShapeCornerCurvatureRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, borderRadiusXVector);
    }

    int c_api_setCompartmentsGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setCompartmentGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, borderRadiusXVector);
    }

    int c_api_setSpeciesGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setSpeciesGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, borderRadiusXVector);
    }

    int c_api_setReactionsGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setReactionGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, borderRadiusXVector);
    }

    int c_api_setGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        RelAbsVector borderRadiusXVector;
        borderRadiusXVector.setAbsoluteValue(borderRadiusX);
        return setGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, borderRadiusXVector);
    }

    bool c_api_isSetGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCornerCurvatureRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector borderRadiusYVector = getGeometricShapeCornerCurvatureRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return borderRadiusYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * borderRadiusYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setGeometricShapeCornerCurvatureRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, borderRadiusYVector);
    }

    int c_api_setCompartmentsGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setCompartmentGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, borderRadiusYVector);
    }

    int c_api_setSpeciesGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setSpeciesGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, borderRadiusYVector);
    }

    int c_api_setReactionsGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setReactionGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, borderRadiusYVector);
    }

    int c_api_setGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        RelAbsVector borderRadiusYVector;
        borderRadiusYVector.setAbsoluteValue(borderRadiusY);
        return setGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, borderRadiusYVector);
    }

    bool c_api_isSetGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCenterX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector centerXVector = getGeometricShapeCenterX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return centerXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * centerXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setGeometricShapeCenterX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, centerXVector);
    }

    int c_api_setCompartmentsGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setCompartmentGeometricShapeCenterX(document, layoutIndex, centerXVector);
    }

    int c_api_setSpeciesGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setSpeciesGeometricShapeCenterX(document, layoutIndex, centerXVector);
    }

    int c_api_setReactionsGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setReactionGeometricShapeCenterX(document, layoutIndex, centerXVector);
    }

    int c_api_setGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex) {
        RelAbsVector centerXVector;
        centerXVector.setAbsoluteValue(centerX);
        return setGeometricShapeCenterX(document, layoutIndex, centerXVector);
    }

    bool c_api_isSetGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCenterY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector centerYVector = getGeometricShapeCenterY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return centerYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * centerYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setGeometricShapeCenterY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, centerYVector);
    }

    int c_api_setCompartmentsGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setCompartmentGeometricShapeCenterY(document, layoutIndex, centerYVector);
    }

    int c_api_setSpeciesGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setSpeciesGeometricShapeCenterY(document, layoutIndex, centerYVector);
    }

    int c_api_setReactionsGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setReactionGeometricShapeCenterY(document, layoutIndex, centerYVector);
    }

    int c_api_setGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex) {
        RelAbsVector centerYVector;
        centerYVector.setAbsoluteValue(centerY);
        return setGeometricShapeCenterY(document, layoutIndex, centerYVector);
    }

    bool c_api_isSetGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector radiusXVector = getGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return radiusXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * radiusXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, radiusXVector);
    }

    int c_api_setCompartmentsGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setCompartmentGeometricShapeRadiusX(document, layoutIndex, radiusXVector);
    }

    int c_api_setSpeciesGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setSpeciesGeometricShapeRadiusX(document, layoutIndex, radiusXVector);
    }

    int c_api_setReactionsGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setReactionGeometricShapeRadiusX(document, layoutIndex, radiusXVector);
    }

    int c_api_setGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex) {
        RelAbsVector radiusXVector;
        radiusXVector.setAbsoluteValue(radiusX);
        return setGeometricShapeRadiusX(document, layoutIndex, radiusXVector);
    }

    bool c_api_isSetGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector radiusYVector = getGeometricShapeRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
        return radiusYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * radiusYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setGeometricShapeRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, radiusYVector);
    }

    int c_api_setCompartmentsGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setCompartmentGeometricShapeRadiusY(document, layoutIndex, radiusYVector);
    }

    int c_api_setSpeciesGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setSpeciesGeometricShapeRadiusY(document, layoutIndex, radiusYVector);
    }

    int c_api_setReactionsGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setReactionGeometricShapeRadiusY(document, layoutIndex, radiusYVector);
    }

    int c_api_setGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex) {
        RelAbsVector radiusYVector;
        radiusYVector.setAbsoluteValue(radiusY);
        return setGeometricShapeRadiusY(document, layoutIndex, radiusYVector);
    }

    const int c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeNumElements(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isGeometricShapeElementCubicBezier(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    const double c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentXVector = getGeometricShapeElementX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
        return segmentXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * segmentXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentXVector;
        segmentXVector.setAbsoluteValue(x);
        return setGeometricShapeElementX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, segmentXVector);
    }

    int c_api_setCompartmentsGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentXVector;
        segmentXVector.setAbsoluteValue(x);
        return setCompartmentGeometricShapeElementX(document, layoutIndex, segmentIndex, segmentXVector);
    }

    int c_api_setSpeciesGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentXVector;
        segmentXVector.setAbsoluteValue(x);
        return setSpeciesGeometricShapeElementX(document, layoutIndex, segmentIndex, segmentXVector);
    }

    int c_api_setReactionsGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentXVector;
        segmentXVector.setAbsoluteValue(x);
        return setReactionGeometricShapeElementX(document, layoutIndex, segmentIndex, segmentXVector);
    }

    int c_api_setGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentXVector;
        segmentXVector.setAbsoluteValue(x);
        return setGeometricShapeElementX(document, layoutIndex, segmentIndex, segmentXVector);
    }

    const double c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentYVector = getGeometricShapeElementY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
        return segmentYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * segmentYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentYVector;
        segmentYVector.setAbsoluteValue(y);
        return setGeometricShapeElementY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, segmentYVector);
    }

    int c_api_setCompartmentsGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentYVector;
        segmentYVector.setAbsoluteValue(y);
        return setCompartmentGeometricShapeElementY(document, layoutIndex, segmentIndex, segmentYVector);
    }

    int c_api_setSpeciesGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentYVector;
        segmentYVector.setAbsoluteValue(y);
        return setSpeciesGeometricShapeElementY(document, layoutIndex, segmentIndex, segmentYVector);
    }

    int c_api_setReactionsGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentYVector;
        segmentYVector.setAbsoluteValue(y);
        return setReactionGeometricShapeElementY(document, layoutIndex, segmentIndex, segmentYVector);
    }

    int c_api_setGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentYVector;
        segmentYVector.setAbsoluteValue(y);
        return setGeometricShapeElementY(document, layoutIndex, segmentIndex, segmentYVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentStartXVector = getGeometricShapeBasePoint1X(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
        return segmentStartXVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * segmentStartXVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentStartXVector;
        segmentStartXVector.setAbsoluteValue(x);
        return setGeometricShapeBasePoint1X(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, segmentStartXVector);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartXVector;
        segmentStartXVector.setAbsoluteValue(x);
        return setCompartmentGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, segmentStartXVector);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartXVector;
        segmentStartXVector.setAbsoluteValue(x);
        return setSpeciesGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, segmentStartXVector);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartXVector;
        segmentStartXVector.setAbsoluteValue(x);
        return setReactionGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, segmentStartXVector);
    }

    int c_api_setGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartXVector;
        segmentStartXVector.setAbsoluteValue(x);
        return setGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, segmentStartXVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentStartYVector = getGeometricShapeBasePoint1Y(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
        return segmentStartYVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * segmentStartYVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentStartYVector;
        segmentStartYVector.setAbsoluteValue(y);
        return setGeometricShapeBasePoint1Y(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, segmentStartYVector);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartYVector;
        segmentStartYVector.setAbsoluteValue(y);
        return setCompartmentGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, segmentStartYVector);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartYVector;
        segmentStartYVector.setAbsoluteValue(y);
        return setSpeciesGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, segmentStartYVector);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartYVector;
        segmentStartYVector.setAbsoluteValue(y);
        return setReactionGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, segmentStartYVector);
    }

    int c_api_setGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentStartYVector;
        segmentStartYVector.setAbsoluteValue(y);
        return setGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, segmentStartYVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2XVector = getGeometricShapeBasePoint2X(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
        return segmentBasePoint2XVector.getAbsoluteValue() + 0.01 * c_api_getWidth(document, id) * segmentBasePoint2XVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2XVector;
        segmentBasePoint2XVector.setAbsoluteValue(x);
        return setGeometricShapeBasePoint2X(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, segmentBasePoint2XVector);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2XVector;
        segmentBasePoint2XVector.setAbsoluteValue(x);
        return setCompartmentGeometricShapeBasePoint2X(document, layoutIndex, segmentIndex, segmentBasePoint2XVector);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2XVector;
        segmentBasePoint2XVector.setAbsoluteValue(x);
        return setSpeciesGeometricShapeBasePoint2X(document, layoutIndex, segmentIndex, segmentBasePoint2XVector);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2XVector;
        segmentBasePoint2XVector.setAbsoluteValue(x);
        return setReactionGeometricShapeBasePoint2X(document, layoutIndex, segmentIndex, segmentBasePoint2XVector);
    }

    int c_api_setGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2XVector;
        segmentBasePoint2XVector.setAbsoluteValue(x);
        return setGeometricShapeBasePoint2X(document, layoutIndex, segmentIndex, segmentBasePoint2XVector);
    }

    const double c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2YVector = getGeometricShapeBasePoint2Y(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
        return segmentBasePoint2YVector.getAbsoluteValue() + 0.01 * c_api_getHeight(document, id) * segmentBasePoint2YVector.getRelativeValue();
    }

    int c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        RelAbsVector segmentBasePoint2YVector;
        segmentBasePoint2YVector.setAbsoluteValue(y);
        return setGeometricShapeBasePoint2Y(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, segmentBasePoint2YVector);
    }

    bool c_api_isSetGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeHref(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const char* c_api_getGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getGeometricShapeHref(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex).c_str());
    }

    int c_api_setGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeHref(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, href);
    }

    int c_api_setCompartmentsGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex) {
        return setCompartmentGeometricShapeHref(document, layoutIndex, href);
    }

    int c_api_setSpeciesGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex) {
        return setSpeciesGeometricShapeHref(document, layoutIndex, href);
    }

    int c_api_setReactionsGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex) {
        return setReactionGeometricShapeHref(document, layoutIndex, href);
    }

    int c_api_setGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex) {
        return setGeometricShapeHref(document, layoutIndex, href);
    }

    int c_api_getNumValidRoleValues() {
        return getValidRoleValues().size();
    }

    const char* c_api_getNthValidRoleValue(int index) {
        if (index >= 0 && index < c_api_getNumValidRoleValues())
            return strdup(getValidRoleValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidAlignmentValues() {
        return getValidAlignmentValues().size();
    }

    const char* c_api_getNthValidAlignmentValue(int index) {
        if (index >= 0 && index < c_api_getNumValidAlignmentValues())
            return strdup(getValidAlignmentValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidDistributionDirectionValues() {
        return getValidDistributionDirectionValues().size();
    }

    const char* c_api_getNthValidDistributionDirectionValue(int index) {
        if (index >= 0 && index < c_api_getNumValidDistributionDirectionValues())
            return strdup(getValidDistributionDirectionValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidColorNameValues() {
        return getValidHtmlColorNames().size();
    }

    const char* c_api_getNthValidColorNameValue(int index) {
        if (index >= 0 && index < c_api_getNumValidColorNameValues())
            return strdup(getValidHtmlColorNames().at(index).c_str());

        return "";
    }

    int c_api_getNumValidHexColorCodeValues() {
        return getValidHexColorCodes().size();
    }

    const char* c_api_getNthValidHexColorCodeValue(int index) {
        if (index >= 0 && index < c_api_getNumValidHexColorCodeValues())
            return strdup(getValidHexColorCodes().at(index).c_str());

        return "";
    }

    int c_api_getNumValidSpreadMethodValues() {
        return getValidSpreadMethodValues().size();
    }

    const char* c_api_getNthValidSpreadMethodValue(int index) {
        if (index >= 0 && index < c_api_getNumValidSpreadMethodValues())
            return strdup(getValidSpreadMethodValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidFontWeightValues() {
        return getValidFontWeightValues().size();
    }

    const char* c_api_getNthValidFontWeightValue(int index) {
        if (index >= 0 && index < c_api_getNumValidFontWeightValues())
            return strdup(getValidFontWeightValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidFontStyleValues() {
        return getValidFontStyleValues().size();
    }

    const char* c_api_getNthValidFontStyleValue(int index) {
        if (index >= 0 && index < c_api_getNumValidFontStyleValues())
            return strdup(getValidFontStyleValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidHorizontalTextAlignmentValues() {
        return getValidTextAnchorValues().size();
    }

    const char* c_api_getNthValidHorizontalTextAlignmentValue(int index) {
        if (index >= 0 && index < c_api_getNumValidHorizontalTextAlignmentValues())
            return strdup(getValidTextAnchorValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidVerticalTextAlignmentValues() {
        return getValidVTextAnchorValues().size();
    }

    const char* c_api_getNthValidVerticalTextAlignmentValue(int index) {
        if (index >= 0 && index < c_api_getNumValidVerticalTextAlignmentValues())
            return strdup(getValidVTextAnchorValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidFillRuleValues() {
        return getValidFillRuleValues().size();
    }

    const char* c_api_getNthValidFillRuleValue(int index) {
        if (index >= 0 && index < c_api_getNumValidFillRuleValues())
            return strdup(getValidFillRuleValues().at(index).c_str());

        return "";
    }

    int c_api_getNumValidGeometricShapeValues() {
        return getValidGeometricShapeNameValues().size();
    }

    const char* c_api_getNthValidGeometricShapeValue(int index) {
        if (index >= 0 && index < c_api_getNumValidGeometricShapeValues())
            return strdup(getValidGeometricShapeNameValues().at(index).c_str());

        return "";
    }
}

}