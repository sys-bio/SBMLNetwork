#include "libsbmlnetwork_c_api.h"
#include "../libsbmlnetwork_sbmldocument.h"
#include "../libsbmlnetwork_sbmldocument_layout.h"
#include "../libsbmlnetwork_sbmldocument_render.h"
#include "../libsbmlnetwork_layout_helpers.h"
#include "../libsbmlnetwork_render_helpers.h"
#include "../colors/libsbmlnetwork_colors.h"
#include "../styles/libsbmlnetwork_styles.h"

extern "C" {

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    const char* c_api_getVersion() {
        return strdup(getLibraryVersion().c_str());
    }

    const char* c_api_getCurrentDirectoryOfLibrary() {return strdup(getCurrentDirectoryOfLibrary().c_str());
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

    int c_api_autolayout(SBMLDocument *document, const int maxNumConnectedEdges, bool useNameAsTextLabel, bool resetLockedNodes, const char **lockedNodeIds, const int lockedNodesSize) {
        std::set<std::string> lockedNodeIdsSet = std::set<std::string>();
        if (lockedNodeIds) {
            for (int i = 0; i < lockedNodesSize; i++)
                lockedNodeIdsSet.insert(lockedNodeIds[i]);
        }

        return autolayout(document, maxNumConnectedEdges, useNameAsTextLabel, resetLockedNodes, lockedNodeIdsSet);
    }

    int c_api_autorender(SBMLDocument *document) {
        return autorender(document);
    }

    int c_api_align(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* alignment, bool ignoreLockedNodes) {
        std::set<std::string> nodeIdsSet = std::set<std::string>();
        if (nodeIds) {
            for (int i = 0; i < nodesSize; i++)
                nodeIdsSet.insert(nodeIds[i]);
        }
        return align(document, nodeIdsSet, alignment, ignoreLockedNodes);
    }

    int c_api_distribute(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* direction, const double spacing) {
        std::set<std::pair<std::string, unsigned int>> nodeIdsSet = std::set<std::pair<std::string, unsigned int>>();
        if (nodeIds) {
            for (int i = 0; i < nodesSize; i++)
                nodeIdsSet.insert(std::make_pair(nodeIds[i], i));
        }
        return distribute(document, nodeIdsSet, direction, spacing);
    }

    const int c_api_getNumLayouts(SBMLDocument* document) {
        return getNumLayouts(document);
    }

    int c_api_removeLayouts(SBMLDocument* document) {
        return removeAllLayouts(document);
    }

    int c_api_createDefaultLayoutFeatures(SBMLDocument* document, const int maxNumConnectedEdges) {
        return createDefaultLayoutFeatures(document, maxNumConnectedEdges);
    }

    int c_api_createDefaultLayoutLocations(SBMLDocument* document, const int maxNumConnectedEdges,
                                  bool useNameAsTextLabel, bool resetLockedNodes,
                                  const char **lockedNodeIds, const int lockedNodesSize) {
        std::set<std::string> lockedNodeIdsSet = std::set<std::string>();
        if (lockedNodeIds) {
            for (int i = 0; i < lockedNodesSize; i++)
                lockedNodeIdsSet.insert(lockedNodeIds[i]);
        }
        return createDefaultLayoutLocations(document, maxNumConnectedEdges, useNameAsTextLabel, resetLockedNodes, lockedNodeIdsSet);
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

    const char* c_api_getNthSpeciesReferenceGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        SpeciesReferenceGlyph* speciesReferenceGlyph = getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
        if (speciesReferenceGlyph)
            return strdup(speciesReferenceGlyph->getId().c_str());

        return "";
    }

    const char* c_api_getNthSpeciesReferenceGlyphMetaId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        SpeciesReferenceGlyph* speciesReferenceGlyph = getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
        if (speciesReferenceGlyph)
            return strdup(speciesReferenceGlyph->getMetaId().c_str());

        return "";
    }

    const char* c_api_getNthSpeciesReferenceGlyphSpeciesReferenceId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        SpeciesReferenceGlyph* speciesReferenceGlyph = getSpeciesReferenceGlyph(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
        if (speciesReferenceGlyph)
            return strdup(speciesReferenceGlyph->getSpeciesReferenceId().c_str());

        return "";
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

    int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, int layoutIndex) {
        return setPositionX(document, layoutIndex, id, graphicalObjectIndex, x);
    }

    const double c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getPositionY(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, int layoutIndex) {
        return setPositionY(document, layoutIndex, id, graphicalObjectIndex, y);
    }

    int c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex, int layoutIndex) {
        return setPosition(document, layoutIndex, id, graphicalObjectIndex, x, y);
    }

    const double c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getDimensionWidth(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, int layoutIndex) {
        return setDimensionWidth(document, layoutIndex, id, graphicalObjectIndex, width);
    }

    int c_api_setCompartmentsWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setCompartmentDimensionWidth(document, layoutIndex, width);
    }

    const double c_api_getSpeciesWidth() {
        return getSpeciesDimensionWidth();
    }

    int c_api_setSpeciesWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setSpeciesDimensionWidth(document, layoutIndex, width);
    }

    const double c_api_getReactionsWidth() {
        return getReactionDimensionWidth();
    }

    int c_api_setReactionsWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setReactionDimensionWidth(document, layoutIndex, width);
    }

    const double c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, int layoutIndex) {
        return getDimensionHeight(document, layoutIndex, id, graphicalObjectIndex);
    }

    int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, int layoutIndex) {
        return setDimensionHeight(document, layoutIndex, id, graphicalObjectIndex, height);
    }

    int c_api_setCompartmentsHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setCompartmentDimensionHeight(document, layoutIndex, height);
    }

    const double c_api_getSpeciesHeight() {
        return getSpeciesDimensionHeight();
    }

    int c_api_setSpeciesHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setSpeciesDimensionHeight(document, layoutIndex, height);
    }

    const double c_api_getReactionsHeight() {
        return getReactionDimensionHeight();
    }

    int c_api_setReactionsHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setReactionDimensionHeight(document, layoutIndex, height);
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
        return getTextDimensionWidth(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
    }

    int c_api_setTextWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setTextDimensionWidth(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex, width);
    }

    const double c_api_getTextHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return getTextDimensionHeight(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
    }

    int c_api_setTextHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex) {
        return setTextDimensionHeight(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex, height);
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
        return removeRenderInformation(document);
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
        return getOffsetAsDouble(document, renderIndex, id, gradientStopIndex);
    }

    int c_api_setOffset(SBMLDocument* document, const char* id, const double offset, int gradientStopIndex, int renderIndex) {
        return setOffset(document, renderIndex, id, gradientStopIndex, offset);
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

    bool c_api_isSetLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientX1(document, renderIndex, id);
    }

    const double c_api_getLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex) {
        return getLinearGradientX1AsDouble(document, renderIndex, id);
    }

    int c_api_setLinearGradientX1(SBMLDocument* document, const char* id, const double x1, int renderIndex) {
        return setLinearGradientX1(document, renderIndex, id, x1);
    }

    bool c_api_isSetLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientY1(document, renderIndex, id);
    }

    const double c_api_getLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex) {
        return getLinearGradientY1AsDouble(document, renderIndex, id);
    }

    int c_api_setLinearGradientY1(SBMLDocument* document, const char* id, const double y1, int renderIndex) {
        return setLinearGradientY1(document, renderIndex, id, y1);
    }

    bool c_api_isSetLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientX2(document, renderIndex, id);
    }

    const double c_api_getLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex) {
        return getLinearGradientX2AsDouble(document, renderIndex, id);
    }

    int c_api_setLinearGradientX2(SBMLDocument* document, const char* id, const double x2, int renderIndex) {
        return setLinearGradientX2(document, renderIndex, id, x2);
    }

    bool c_api_isSetLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetLinearGradientY2(document, renderIndex, id);
    }

    const double c_api_getLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex) {
        return getLinearGradientY2AsDouble(document, renderIndex, id);
    }

    int c_api_setLinearGradientY2(SBMLDocument* document, const char* id, const double y2, int renderIndex) {
        return setLinearGradientY2(document, renderIndex, id, y2);
    }

    bool c_api_isSetRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientCx(document, renderIndex, id);
    }

    const double c_api_getRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex) {
        return getRadialGradientCxAsDouble(document, renderIndex, id);
    }

    int c_api_setRadialGradientCenterX(SBMLDocument* document, const char* id, const double cx, int renderIndex) {
        return setRadialGradientCx(document, renderIndex, id, cx);
    }

    bool c_api_isSetRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientCy(document, renderIndex, id);
    }

    const double c_api_getRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex) {
        return getRadialGradientCyAsDouble(document, renderIndex, id);
    }

    int c_api_setRadialGradientCenterY(SBMLDocument* document, const char* id, const double cy, int renderIndex) {
        return setRadialGradientCy(document, renderIndex, id, cy);
    }

    bool c_api_isSetRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientR(document, renderIndex, id);
    }

    const double c_api_getRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex) {
        return getRadialGradientRAsDouble(document, renderIndex, id);
    }

    int c_api_setRadialGradientRadius(SBMLDocument* document, const char* id, const double r, int renderIndex) {
        return setRadialGradientR(document, renderIndex, id, r);
    }

    bool c_api_isSetRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientFx(document, renderIndex, id);
    }

    const double c_api_getRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex) {
        return getRadialGradientFxAsDouble(document, renderIndex, id);
    }

    int c_api_setRadialGradientFocalX(SBMLDocument* document, const char* id, const double fx, int renderIndex) {
        return setRadialGradientFx(document, renderIndex, id, fx);
    }

    bool c_api_isSetRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex) {
        return isSetRadialGradientFy(document, renderIndex, id);
    }

    const double c_api_getRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex) {
        return getRadialGradientFyAsDouble(document, renderIndex, id);
    }

    int c_api_setRadialGradientFocalY(SBMLDocument* document, const char* id, const double fy, int renderIndex) {
        return setRadialGradientFy(document, renderIndex, id, fy);
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

    const double c_api_getSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getSpeciesReferenceLineEndingBoundingBoxX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    int c_api_setSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingBoundingBoxX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, x);
    }

    const double c_api_getLineEndingBoundingBoxY(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxY(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxY(SBMLDocument* document, const char* id, const double y, int renderIndex) {
        return setLineEndingBoundingBoxY(document, renderIndex, id, y);
    }

    const double c_api_getSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getSpeciesReferenceLineEndingBoundingBoxY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    int c_api_setSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingBoundingBoxY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, y);
    }

    const double c_api_getLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxWidth(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, const double width, int renderIndex) {
        return setLineEndingBoundingBoxWidth(document, renderIndex, id, width);
    }

    const double c_api_getSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getSpeciesReferenceLineEndingBoundingBoxWidth(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    int c_api_setSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingBoundingBoxWidth(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, width);
    }

    const double c_api_getLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, int renderIndex) {
        return getLineEndingBoundingBoxHeight(document, renderIndex, id);
    }

    int c_api_setLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, const double height, int renderIndex) {
        return setLineEndingBoundingBoxHeight(document, renderIndex, id, height);
    }

    const double c_api_getSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getSpeciesReferenceLineEndingBoundingBoxHeight(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    int c_api_setSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingBoundingBoxHeight(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, height);
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

    bool c_api_isSetSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetSpeciesReferenceLineEndingStrokeColor(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const char* c_api_getSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getSpeciesReferenceLineEndingStrokeColor(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex).c_str());
    }

    int c_api_setSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingStrokeColor(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, borderColor);
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

    bool c_api_isSetSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetSpeciesReferenceLineEndingStrokeWidth(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getSpeciesReferenceLineEndingStrokeWidth(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    int c_api_setSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingStrokeWidth(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, borderWidth);
    }

    const int c_api_getNumLineEndingBorderDashes(SBMLDocument* document, const char* id, int renderIndex) {
        return getNumLineEndingStrokeDashes(document, renderIndex, id);
    }

    const int c_api_getLineEndingNthBorderDash(SBMLDocument* document, const char* id, int dashIndex, int renderIndex) {
        return getLineEndingStrokeDash(document, renderIndex, id, dashIndex);
    }

    int c_api_setLineEndingNthBorderDash(SBMLDocument* document, const char* id, const int dash, int dashIndex, int renderIndex) {
        return setLineEndingStrokeDash(document, renderIndex, id, dashIndex, dash);
    }

    const int c_api_getNumSpeciesReferenceLineEndingBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getNumSpeciesReferenceLineEndingStrokeDashes(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const int c_api_getSpeciesReferenceLineEndingNthBorderDash(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int dashIndex, int layoutIndex) {
        return getSpeciesReferenceLineEndingStrokeDash(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, dashIndex);
    }

    int c_api_setSpeciesReferenceLineEndingNthBorderDash(SBMLDocument* document, const char* reactionId, const int dash, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int dashIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingStrokeDash(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, dashIndex, dash);
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

    bool c_api_isSetSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetSpeciesReferenceLineEndingFillColor(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const char* c_api_getSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getSpeciesReferenceLineEndingFillColor(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex).c_str());
    }

    int c_api_setSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, const char* fillColor, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingFillColor(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, fillColor);
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

    bool c_api_isSetSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetSpeciesReferenceLineEndingFillRule(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const char* c_api_getSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getSpeciesReferenceLineEndingFillRule(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex).c_str());
    }

    int c_api_setSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, const char* fillRule, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return setSpeciesReferenceLineEndingFillRule(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, fillRule);
    }

    const int c_api_getNumLineEndingGeometricShapes(SBMLDocument* document, const char* id, int renderIndex) {
        return getNumLineEndingGeometricShapes(document, renderIndex, id);
    }

    const int c_api_getNumSpeciesReferenceLineEndingGeometricShapes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return getNumSpeciesReferenceLineEndingGeometricShapes(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    bool c_api_isLineEndingRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingRectangle(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingRectangle(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingRectangle(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isLineEndingEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingEllipse(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingEllipse(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingEllipse(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isLineEndingPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingPolygon(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingPolygon(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingPolygon(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isLineEndingImage(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingImage(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingImage(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingImage(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isLineEndingRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingRenderCurve(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingRenderCurve(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingRenderCurve(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isLineEndingText(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isLineEndingText(document, renderIndex, id, geometricShapeIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingText(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingText(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isSetLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeXAsDouble(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeXAsDouble(document, renderIndex, id, geometricShapeIndex, x);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, x);
    }

    bool c_api_isSetLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeYAsDouble(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeYAsDouble(document, renderIndex, id, geometricShapeIndex, y);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, y);
    }

    bool c_api_isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeWidth(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeWidthAsDouble(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeWidthAsDouble(document, renderIndex, id, geometricShapeIndex, width);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeWidth(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeWidthAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeWidthAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, width);
    }

    bool c_api_isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeHeight(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeHeightAsDouble(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeHeightAsDouble(document, renderIndex, id, geometricShapeIndex, height);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeHeight(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeHeightAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeHeightAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, height);
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

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeRatio(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeRatio(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, const double ratio, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeRatio(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, ratio);
    }

    bool c_api_isSetLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCornerCurvatureRadiusX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(document, renderIndex, id, geometricShapeIndex, borderRadiusX);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, const double borderRadiusX, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, borderRadiusX);
    }

    bool c_api_isSetLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCornerCurvatureRadiusY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(document, renderIndex, id, geometricShapeIndex, borderRadiusY);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, const double borderRadiusY, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, borderRadiusY);
    }

    bool c_api_isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCenterX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeCenterXAsDouble(document, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeCenterXAsDouble(document, id, geometricShapeIndex, centerX);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeCenterX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeCenterXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, const double centerX, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeCenterXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, centerX);
    }

    bool c_api_isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeCenterY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeCenterYAsDouble(document, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeCenterYAsDouble(document, id, geometricShapeIndex, centerY);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeCenterY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeCenterYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, const double centerY, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeCenterYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, centerY);
    }

    bool c_api_isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeRadiusX(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeRadiusXAsDouble(document, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeRadiusXAsDouble(document, id, geometricShapeIndex, radiusX);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeRadiusX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeRadiusXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, const double radiusX, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeRadiusXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, radiusX);
    }

    bool c_api_isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return isSetLineEndingGeometricShapeRadiusY(document, renderIndex, id, geometricShapeIndex);
    }

    const double c_api_getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeRadiusYAsDouble(document, id, geometricShapeIndex);
    }

    int c_api_setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeRadiusYAsDouble(document, id, geometricShapeIndex, radiusY);
    }

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeRadiusY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeRadiusYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, const double radiusY, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeRadiusYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, radiusY);
    }

    int c_api_getLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeNumElements(document, renderIndex, id, geometricShapeIndex);
    }

    int c_api_getSpeciesReferenceLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeNumElements(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    bool c_api_isLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return isLineEndingGeometricShapeElementCubicBezier(document, renderIndex, id, geometricShapeIndex, segmentIndex);
    }

    bool c_api_isSpeciesReferenceLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return isSpeciesReferenceLineEndingGeometricShapeElementCubicBezier(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    const double c_api_getLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeElementXAsDouble(document, id, geometricShapeIndex, segmentIndex);
    }

    int c_api_setLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeElementXAsDouble(document, id, geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeElementXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeElementXAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeElementYAsDouble(document, id, geometricShapeIndex, segmentIndex);
    }

    int c_api_setLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeElementYAsDouble(document, id, geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeElementYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeElementYAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeBasePoint1XAsDouble(document, id, geometricShapeIndex, segmentIndex);
    }

    int c_api_setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeBasePoint1XAsDouble(document, id, geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeBasePoint1XAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeBasePoint1XAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeBasePoint1YAsDouble(document, id, geometricShapeIndex, segmentIndex);
    }

    int c_api_setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeBasePoint1YAsDouble(document, id, geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeBasePoint1YAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeBasePoint1YAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeBasePoint2XAsDouble(document, id, geometricShapeIndex, segmentIndex);
    }

    int c_api_setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeBasePoint2XAsDouble(document, id, geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeBasePoint2XAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeBasePoint2XAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return getLineEndingGeometricShapeBasePoint2YAsDouble(document, id, geometricShapeIndex, segmentIndex);
    }

    int c_api_setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int renderIndex) {
        return setLineEndingGeometricShapeBasePoint2YAsDouble(document, id, geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return getSpeciesReferenceLineEndingGeometricShapeBasePoint2YAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex);
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int segmentIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeBasePoint2YAsDouble(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, segmentIndex, y);
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

    bool c_api_isSetSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return isSetSpeciesReferenceLineEndingGeometricShapeHref(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex);
    }

    const char* c_api_getSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return strdup(getSpeciesReferenceLineEndingGeometricShapeHref(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex).c_str());
    }

    int c_api_setSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, const char* href, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex, int geometricShapeIndex) {
        return setSpeciesReferenceLineEndingGeometricShapeHref(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, geometricShapeIndex, href);
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

    const char* c_api_getCompartmentsBorderColor(SBMLDocument* document) {
        return strdup(getCompartmentStrokeColor(document).c_str());
    }

    int c_api_setCompartmentsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setCompartmentStrokeColor(document, layoutIndex, borderColor);
    }

    const char* c_api_getSpeciesBorderColor(SBMLDocument* document) {
        return strdup(getSpeciesStrokeColor(document).c_str());
    }

    int c_api_setSpeciesBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setSpeciesStrokeColor(document, layoutIndex, borderColor);
    }

    const char* c_api_getReactionsBorderColor(SBMLDocument* document) {
        return strdup(getReactionStrokeColor(document).c_str());
    }

    int c_api_setReactionsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setReactionStrokeColor(document, layoutIndex, borderColor, false);
    }

    int c_api_setReactionsLineColor(SBMLDocument* document, const char* lineColor, int layoutIndex) {
        return setReactionStrokeColor(document, layoutIndex, lineColor);
    }

    int c_api_setLineEndingsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex) {
        return setLineEndingStrokeColor(document, layoutIndex, borderColor);
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

    const double c_api_getCompartmentsBorderWidth(SBMLDocument* document) {
        return getCompartmentStrokeWidth(document);
    }

    int c_api_setCompartmentsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setCompartmentStrokeWidth(document, layoutIndex, borderWidth);
    }

    const double c_api_getSpeciesBorderWidth(SBMLDocument* document) {
        return getSpeciesStrokeWidth(document);
    }

    int c_api_setSpeciesBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setSpeciesStrokeWidth(document, layoutIndex, borderWidth);
    }

    const double c_api_getReactionsBorderWidth(SBMLDocument* document) {
        return getReactionStrokeWidth(document);
    }

    int c_api_setReactionsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setReactionStrokeWidth(document, layoutIndex, borderWidth, false);
    }

    const double c_api_getReactionsLineWidth(SBMLDocument* document) {
        return getReactionStrokeWidth(document);
    }

    int c_api_setReactionsLineWidth(SBMLDocument* document, const double lineWidth, int layoutIndex) {
        return setReactionStrokeWidth(document, layoutIndex, lineWidth);
    }

    int c_api_setLineEndingsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex) {
        return setLineEndingStrokeWidth(document, layoutIndex, borderWidth);
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

    const char* c_api_getCompartmentsFillColor(SBMLDocument* document) {
        return strdup(getCompartmentFillColor(document).c_str());
    }

    int c_api_setCompartmentsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setCompartmentFillColor(document, layoutIndex, fillColor);
    }

    const char* c_api_getSpeciesFillColor(SBMLDocument* document) {
        return strdup(getSpeciesFillColor(document).c_str());
    }

    int c_api_setSpeciesFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setSpeciesFillColor(document, layoutIndex, fillColor);
    }

    const char* c_api_getReactionsFillColor(SBMLDocument* document) {
        return strdup(getReactionFillColor(document).c_str());
    }

    int c_api_setReactionsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setReactionFillColor(document, layoutIndex, fillColor);
    }

    int c_api_setLineEndingsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex) {
        return setLineEndingFillColor(document, layoutIndex, fillColor);
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

    const char* c_api_getCompartmentsFillRule(SBMLDocument* document) {
        return strdup(getCompartmentFillRule(document).c_str());
    }

    int c_api_setCompartmentsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex) {
        return setCompartmentFillRule(document, layoutIndex, fillRule);
    }

    const char* c_api_getSpeciesFillRule(SBMLDocument* document) {
        return strdup(getSpeciesFillRule(document).c_str());
    }

    int c_api_setSpeciesFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex) {
        return setSpeciesFillRule(document, layoutIndex, fillRule);
    }

    const char* c_api_getReactionsFillRule(SBMLDocument* document) {
        return strdup(getReactionFillRule(document).c_str());
    }

    int c_api_setReactionsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex) {
        return setReactionFillRule(document, layoutIndex, fillRule);
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

    const char* c_api_getCompartmentsFontColor(SBMLDocument* document) {
        return strdup(getCompartmentFontColor(document).c_str());
    }

    int c_api_setCompartmentsFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex) {
        return setCompartmentFontColor(document, layoutIndex, fontColor);
    }

    const char* c_api_getSpeciesFontColor(SBMLDocument* document) {
        return strdup(getSpeciesFontColor(document).c_str());
    }

    int c_api_setSpeciesFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex) {
        return setSpeciesFontColor(document, layoutIndex, fontColor);
    }

    const char* c_api_getReactionsFontColor(SBMLDocument* document) {
        return strdup(getReactionFontColor(document).c_str());
    }

    int c_api_setReactionsFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex) {
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

    const char* c_api_getCompartmentsFontFamily(SBMLDocument* document) {
        return strdup(getCompartmentFontFamily(document).c_str());
    }

    int c_api_setCompartmentsFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setCompartmentFontFamily(document, layoutIndex, fontFamily);
    }

    const char* c_api_getSpeciesFontFamily(SBMLDocument* document) {
        return strdup(getSpeciesFontFamily(document).c_str());
    }

    int c_api_setSpeciesFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setSpeciesFontFamily(document, layoutIndex, fontFamily);
    }

    const char* c_api_getReactionsFontFamily(SBMLDocument* document) {
        return strdup(getReactionFontFamily(document).c_str());
    }

    int c_api_setReactionsFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setReactionFontFamily(document, layoutIndex, fontFamily);
    }

    int c_api_setFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex) {
        return setFontFamily(document, layoutIndex, fontFamily);
    }

    bool c_api_isSetFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return isSetFontSize(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    const double c_api_getFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return getFontSizeAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
    }

    int c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize, int graphicalObjectIndex, int textGlyphIndex, int layoutIndex) {
        return setFontSizeAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, fontSize);
    }

    const double c_api_getCompartmentsFontSize(SBMLDocument* document) {
        return getCompartmentFontSizeAsDouble(document);
    }

    int c_api_setCompartmentsFontSize(SBMLDocument* document, const double fontSize, int layoutIndex) {
        return setCompartmentFontSizeAsDouble(document, layoutIndex, fontSize);
    }

    const double c_api_getSpeciesFontSize(SBMLDocument* document) {
        return getSpeciesFontSizeAsDouble(document);
    }

    int c_api_setSpeciesFontSize(SBMLDocument* document, const double fontSize, int layoutIndex) {
        return setSpeciesFontSizeAsDouble(document, layoutIndex, fontSize);
    }

    const double c_api_getReactionsFontSize(SBMLDocument* document) {
        return getReactionFontSizeAsDouble(document);
    }

    int c_api_setReactionsFontSize(SBMLDocument* document, const double fontSize, int layoutIndex) {
        return setReactionFontSizeAsDouble(document, layoutIndex, fontSize);
    }

    int c_api_setFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex) {
        return setFontSizeAsDouble(document, layoutIndex, fontSize);
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

    const char* c_api_getCompartmentsFontWeight(SBMLDocument* document) {
        return strdup(getCompartmentFontWeight(document).c_str());
    }

    int c_api_setCompartmentsFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
        return setCompartmentFontWeight(document, layoutIndex, fontWeight);
    }

    const char* c_api_getSpeciesFontWeight(SBMLDocument* document) {
        return strdup(getSpeciesFontWeight(document).c_str());
    }

    int c_api_setSpeciesFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
        return setSpeciesFontWeight(document, layoutIndex, fontWeight);
    }

    const char* c_api_getReactionsFontWeight(SBMLDocument* document) {
        return strdup(getReactionFontWeight(document).c_str());
    }

    int c_api_setReactionsFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex) {
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

    const char* c_api_getCompartmentsFontStyle(SBMLDocument* document) {
        return strdup(getCompartmentFontStyle(document).c_str());
    }

    int c_api_setCompartmentsFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
        return setCompartmentFontStyle(document, layoutIndex, fontStyle);
    }

    const char* c_api_getSpeciesFontStyle(SBMLDocument* document) {
        return strdup(getSpeciesFontStyle(document).c_str());
    }

    int c_api_setSpeciesFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
        return setSpeciesFontStyle(document, layoutIndex, fontStyle);
    }

    const char* c_api_getReactionsFontStyle(SBMLDocument* document) {
        return strdup(getReactionFontStyle(document).c_str());
    }

    int c_api_setReactionsFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex) {
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

    const char* c_api_getCompartmentsTextHorizontalAlignment(SBMLDocument* document) {
        return strdup(getCompartmentTextAnchor(document).c_str());
    }

    int c_api_setCompartmentsTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
        return setCompartmentTextAnchor(document, layoutIndex, textHorizontalAlignment);
    }

    const char* c_api_getSpeciesTextHorizontalAlignment(SBMLDocument* document) {
        return strdup(getSpeciesTextAnchor(document).c_str());
    }

    int c_api_setSpeciesTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
        return setSpeciesTextAnchor(document, layoutIndex, textHorizontalAlignment);
    }

    const char* c_api_getReactionsTextHorizontalAlignment(SBMLDocument* document) {
        return strdup(getReactionTextAnchor(document).c_str());
    }

    int c_api_setReactionsTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex) {
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

    const char* c_api_getCompartmentsTextVerticalAlignment(SBMLDocument* document) {
        return strdup(getCompartmentVTextAnchor(document).c_str());
    }

    int c_api_setCompartmentsTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
        return setCompartmentVTextAnchor(document, layoutIndex, textVerticalAlignment);
    }

    const char* c_api_getSpeciesTextVerticalAlignment(SBMLDocument* document) {
        return strdup(getSpeciesVTextAnchor(document).c_str());
    }

    int c_api_setSpeciesTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
        return setSpeciesVTextAnchor(document, layoutIndex, textVerticalAlignment);
    }

    const char* c_api_getReactionsTextVerticalAlignment(SBMLDocument* document) {
        return strdup(getReactionVTextAnchor(document).c_str());
    }

    int c_api_setReactionsTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex) {
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
        return removeGeometricShape(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const char* c_api_getGeometricShapeType(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getGeometricShapeType(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex).c_str());
    }

    int c_api_setGeometricShapeType(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeType(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), shape);
    }

    const char* c_api_getCompartmentsGeometricShapeType(SBMLDocument* document) {
        return strdup(getCompartmentGeometricShapeType(document).c_str());
    }

    int c_api_setCompartmentsGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setCompartmentGeometricShapeType(document, layoutIndex, shape);
    }

    const char* c_api_getSpeciesGeometricShapeType(SBMLDocument* document) {
        return strdup(getSpeciesGeometricShapeType(document).c_str());
    }

    int c_api_setSpeciesGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setSpeciesGeometricShapeType(document, layoutIndex, shape);
    }

    const char* c_api_getReactionsGeometricShapeType(SBMLDocument* document) {
        return strdup(getReactionGeometricShapeType(document).c_str());
    }

    int c_api_setReactionsGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setReactionGeometricShapeType(document, layoutIndex, shape);
    }

    int c_api_setGeometricShapesType(SBMLDocument* document, const char* shape, int layoutIndex) {
        return setGeometricShapeType(document, layoutIndex, shape);
    }

    bool c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isRectangle(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isSquare(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSquare(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isEllipse(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isCircle(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isCircle(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
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

    bool c_api_isSetGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const char* c_api_getGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getGeometricShapeStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex).c_str());
    }

    int c_api_setGeometricShapeBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeStrokeColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, borderColor);
    }

    bool c_api_isSetGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeStrokeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, borderWidth);
    }

    bool c_api_isSetGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeFillColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const char* c_api_getGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return strdup(getGeometricShapeFillColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex).c_str());
    }

    int c_api_setGeometricShapeFillColor(SBMLDocument* document, const char* id, const char* fillColor, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeFillColor(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, fillColor);
    }

    bool c_api_isSetGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, x);
    }

    const double c_api_getCompartmentsGeometricShapeX(SBMLDocument* document) {
        return getCompartmentGeometricShapeXAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex) {
        return setCompartmentGeometricShapeXAsDouble(document, layoutIndex, x);
    }

    const double c_api_getSpeciesGeometricShapeX(SBMLDocument* document) {
        return getSpeciesGeometricShapeXAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex) {
        return setSpeciesGeometricShapeXAsDouble(document, layoutIndex, x);
    }

    const double c_api_getReactionsGeometricShapeX(SBMLDocument* document) {
        return getReactionGeometricShapeXAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex) {
        return setReactionGeometricShapeXAsDouble(document, layoutIndex, x);
    }

    int c_api_setGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex) {
        return setGeometricShapeXAsDouble(document, layoutIndex, x);
    }

    bool c_api_isSetGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, y);
    }

    const double c_api_getCompartmentsGeometricShapeY(SBMLDocument* document) {
        return getCompartmentGeometricShapeYAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex) {
        return setCompartmentGeometricShapeYAsDouble(document, layoutIndex, y);
    }

    const double c_api_getSpeciesGeometricShapeY(SBMLDocument* document) {
        return getSpeciesGeometricShapeYAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex) {
        return setSpeciesGeometricShapeYAsDouble(document, layoutIndex, y);
    }

    const double c_api_getReactionsGeometricShapeY(SBMLDocument* document) {
        return getReactionGeometricShapeYAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex) {
        return setReactionGeometricShapeYAsDouble(document, layoutIndex, y);
    }

    int c_api_setGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex) {
        return setGeometricShapeYAsDouble(document, layoutIndex, y);
    }

    bool c_api_isSetGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeWidth(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeWidthAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeWidthAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, width);
    }

    const double c_api_getCompartmentsGeometricShapeWidth(SBMLDocument* document) {
        return getCompartmentGeometricShapeWidthAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setCompartmentGeometricShapeWidthAsDouble(document, layoutIndex, width);
    }

    const double c_api_getSpeciesGeometricShapeWidth(SBMLDocument* document) {
        return getSpeciesGeometricShapeWidthAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setSpeciesGeometricShapeWidthAsDouble(document, layoutIndex, width);
    }

    const double c_api_getReactionsGeometricShapeWidth(SBMLDocument* document) {
        return getReactionGeometricShapeWidthAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setReactionGeometricShapeWidthAsDouble(document, layoutIndex, width);
    }

    int c_api_setGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex) {
        return setGeometricShapeWidthAsDouble(document, layoutIndex, width);
    }

    bool c_api_isSetGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeHeight(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeHeightAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeHeightAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, height);
    }

    const double c_api_getCompartmentsGeometricShapeHeight(SBMLDocument* document) {
        return getCompartmentGeometricShapeHeightAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setCompartmentGeometricShapeHeightAsDouble(document, layoutIndex, height);
    }

    const double c_api_getSpeciesGeometricShapeHeight(SBMLDocument* document) {
        return getSpeciesGeometricShapeHeightAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setSpeciesGeometricShapeHeightAsDouble(document, layoutIndex, height);
    }

    const double c_api_getReactionsGeometricShapeHeight(SBMLDocument* document) {
        return getReactionGeometricShapeHeightAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setReactionGeometricShapeHeightAsDouble(document, layoutIndex, height);
    }

    int c_api_setGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex) {
        return setGeometricShapeHeightAsDouble(document, layoutIndex, height);
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

    const double c_api_getCompartmentsGeometricShapeRatio(SBMLDocument* document) {
        return getCompartmentGeometricShapeRatio(document);
    }

    int c_api_setCompartmentsGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setCompartmentGeometricShapeRatio(document, layoutIndex, ratio);
    }

    const double c_api_getSpeciesGeometricShapeRatio(SBMLDocument* document) {
        return getSpeciesGeometricShapeRatio(document);
    }

    int c_api_setSpeciesGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setSpeciesGeometricShapeRatio(document, layoutIndex, ratio);
    }

    const double c_api_getReactionsGeometricShapeRatio(SBMLDocument* document) {
        return getReactionGeometricShapeRatio(document);
    }

    int c_api_setReactionsGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setReactionGeometricShapeRatio(document, layoutIndex, ratio);
    }

    int c_api_setGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex) {
        return setGeometricShapeRatio(document, layoutIndex, ratio);
    }

    bool c_api_isSetGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCornerCurvatureRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeCornerCurvatureRadiusXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeCornerCurvatureRadiusXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, borderRadiusX);
    }

    const double c_api_getCompartmentsGeometricShapeBorderRadiusX(SBMLDocument* document) {
        return getCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        return setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, borderRadiusX);
    }

    const double c_api_getSpeciesGeometricShapeBorderRadiusX(SBMLDocument* document) {
        return getSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        return setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, borderRadiusX);
    }

    const double c_api_getReactionsGeometricShapeBorderRadiusX(SBMLDocument* document) {
        return getReactionGeometricShapeCornerCurvatureRadiusXAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        return setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, borderRadiusX);
    }

    int c_api_setGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex) {
        return setGeometricShapeCornerCurvatureRadiusXAsDouble(document, layoutIndex, borderRadiusX);
    }

    bool c_api_isSetGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCornerCurvatureRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeCornerCurvatureRadiusYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeCornerCurvatureRadiusYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, borderRadiusY);
    }

    const double c_api_getCompartmentsGeometricShapeBorderRadiusY(SBMLDocument* document) {
        return getCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        return setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, borderRadiusY);
    }

    const double c_api_getSpeciesGeometricShapeBorderRadiusY(SBMLDocument* document) {
        return getSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        return setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, borderRadiusY);
    }

    const double c_api_getReactionsGeometricShapeBorderRadiusY(SBMLDocument* document) {
        return getReactionGeometricShapeCornerCurvatureRadiusYAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        return setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, borderRadiusY);
    }

    int c_api_setGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex) {
        return setGeometricShapeCornerCurvatureRadiusYAsDouble(document, layoutIndex, borderRadiusY);
    }

    bool c_api_isSetGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCenterX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeCenterXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeCenterXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, centerX);
    }

    const double c_api_getCompartmentsGeometricShapeCenterX(SBMLDocument* document) {
        return getCompartmentGeometricShapeCenterXAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex) {
        return setCompartmentGeometricShapeCenterXAsDouble(document, layoutIndex, centerX);
    }

    const double c_api_getSpeciesGeometricShapeCenterX(SBMLDocument* document) {
        return getSpeciesGeometricShapeCenterXAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex) {
        return setSpeciesGeometricShapeCenterXAsDouble(document, layoutIndex, centerX);
    }

    const double c_api_getReactionsGeometricShapeCenterX(SBMLDocument* document) {
        return getReactionGeometricShapeCenterXAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex) {
        return setReactionGeometricShapeCenterXAsDouble(document, layoutIndex, centerX);
    }

    int c_api_setGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex) {
        return setGeometricShapeCenterXAsDouble(document, layoutIndex, centerX);
    }

    bool c_api_isSetGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeCenterY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeCenterYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeCenterYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, centerY);
    }

    const double c_api_getCompartmentsGeometricShapeCenterY(SBMLDocument* document) {
        return getCompartmentGeometricShapeCenterYAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex) {
        return setCompartmentGeometricShapeCenterYAsDouble(document, layoutIndex, centerY);
    }

    const double c_api_getSpeciesGeometricShapeCenterY(SBMLDocument* document) {
        return getSpeciesGeometricShapeCenterYAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex) {
        return setSpeciesGeometricShapeCenterYAsDouble(document, layoutIndex, centerY);
    }

    const double c_api_getReactionsGeometricShapeCenterY(SBMLDocument* document) {
        return getReactionGeometricShapeCenterYAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex) {
        return setReactionGeometricShapeCenterYAsDouble(document, layoutIndex, centerY);
    }

    int c_api_setGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex) {
        return setGeometricShapeCenterYAsDouble(document, layoutIndex, centerY);
    }

    bool c_api_isSetGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeRadiusXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, radiusX);
    }

    const double c_api_getCompartmentsGeometricShapeRadiusX(SBMLDocument* document) {
        return getCompartmentGeometricShapeRadiusXAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex) {
        return setCompartmentGeometricShapeRadiusX(document, layoutIndex, radiusX);
    }

    const double c_api_getSpeciesGeometricShapeRadiusX(SBMLDocument* document) {
        return getSpeciesGeometricShapeRadiusXAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex) {
        return setSpeciesGeometricShapeRadiusXAsDouble(document, layoutIndex, radiusX);
    }

    const double c_api_getReactionsGeometricShapeRadiusX(SBMLDocument* document) {
        return getReactionGeometricShapeRadiusXAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex) {
        return setReactionGeometricShapeRadiusXAsDouble(document, layoutIndex, radiusX);
    }

    int c_api_setGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex) {
        return setGeometricShapeRadiusXAsDouble(document, layoutIndex, radiusX);
    }

    bool c_api_isSetGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isSetGeometricShapeRadiusY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    const double c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeRadiusYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    int c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeRadiusYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, radiusY);
    }

    const double c_api_getCompartmentsGeometricShapeRadiusY(SBMLDocument* document) {
        return getCompartmentGeometricShapeRadiusYAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex) {
        return setCompartmentGeometricShapeRadiusYAsDouble(document, layoutIndex, radiusY);
    }

    const double c_api_getSpeciesGeometricShapeRadiusY(SBMLDocument* document) {
        return getSpeciesGeometricShapeRadiusYAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex) {
        return setSpeciesGeometricShapeRadiusYAsDouble(document, layoutIndex, radiusY);
    }

    const double c_api_getReactionsGeometricShapeRadiusY(SBMLDocument* document) {
        return getReactionGeometricShapeRadiusYAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex) {
        return setReactionGeometricShapeRadiusYAsDouble(document, layoutIndex, radiusY);
    }

    int c_api_setGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex) {
        return setGeometricShapeRadiusYAsDouble(document, layoutIndex, radiusY);
    }

    const int c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeNumElements(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex);
    }

    bool c_api_isGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return isGeometricShapeElementCubicBezier(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    const double c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeElementXAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    int c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeElementX(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getCompartmentsGeometricShapeSegmentX(SBMLDocument* document) {
        return getCompartmentGeometricShapeElementXAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setCompartmentGeometricShapeElementX(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getSpeciesGeometricShapeSegmentX(SBMLDocument* document) {
        return getSpeciesGeometricShapeElementXAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setSpeciesGeometricShapeElementX(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getReactionsGeometricShapeSegmentX(SBMLDocument* document) {
        return getReactionGeometricShapeElementXAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setReactionGeometricShapeElementX(document, layoutIndex, segmentIndex, x);
    }

    int c_api_setGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setGeometricShapeElementXAsDouble(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeElementYAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    int c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeElementY(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getCompartmentsGeometricShapeSegmentY(SBMLDocument* document) {
        return getCompartmentGeometricShapeElementYAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setCompartmentGeometricShapeElementY(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getSpeciesGeometricShapeSegmentY(SBMLDocument* document) {
        return getSpeciesGeometricShapeElementYAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setSpeciesGeometricShapeElementY(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getReactionsGeometricShapeSegmentY(SBMLDocument* document) {
        return getReactionGeometricShapeElementYAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setReactionGeometricShapeElementY(document, layoutIndex, segmentIndex, y);
    }

    int c_api_setGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setGeometricShapeElementYAsDouble(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeBasePoint1XAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    int c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeBasePoint1X(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getCompartmentsGeometricShapeSegmentBasePoint1X(SBMLDocument* document) {
        return getCompartmentGeometricShapeBasePoint1XAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setCompartmentGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getSpeciesGeometricShapeSegmentBasePoint1X(SBMLDocument* document) {
        return getSpeciesGeometricShapeBasePoint1XAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setSpeciesGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getReactionsGeometricShapeSegmentBasePoint1X(SBMLDocument* document) {
        return getReactionGeometricShapeBasePoint1XAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setReactionGeometricShapeBasePoint1X(document, layoutIndex, segmentIndex, x);
    }

    int c_api_setGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setGeometricShapeBasePoint1XAsDouble(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeBasePoint1YAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    int c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeBasePoint1Y(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getCompartmentsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document) {
        return getCompartmentGeometricShapeBasePoint1YAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setCompartmentGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getSpeciesGeometricShapeSegmentBasePoint1Y(SBMLDocument* document) {
        return getSpeciesGeometricShapeBasePoint1YAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setSpeciesGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getReactionsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document) {
        return getReactionGeometricShapeBasePoint1YAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setReactionGeometricShapeBasePoint1Y(document, layoutIndex, segmentIndex, y);
    }

    int c_api_setGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setGeometricShapeBasePoint1YAsDouble(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeBasePoint2XAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    int c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeBasePoint2X(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, x);
    }

    const double c_api_getCompartmentsGeometricShapeSegmentBasePoint2X(SBMLDocument* document) {
        return getCompartmentGeometricShapeBasePoint2XAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setCompartmentGeometricShapeBasePoint2X(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getSpeciesGeometricShapeSegmentBasePoint2X(SBMLDocument* document) {
        return getSpeciesGeometricShapeBasePoint2XAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setSpeciesGeometricShapeBasePoint2XAsDouble(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getReactionsGeometricShapeSegmentBasePoint2X(SBMLDocument* document) {
        return getReactionGeometricShapeBasePoint2XAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setReactionGeometricShapeBasePoint2XAsDouble(document, layoutIndex, segmentIndex, x);
    }

    int c_api_setGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex, int layoutIndex) {
        return setGeometricShapeBasePoint2XAsDouble(document, layoutIndex, segmentIndex, x);
    }

    const double c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return getGeometricShapeBasePoint2YAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex);
    }

    int c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex) {
        return setGeometricShapeBasePoint2YAsDouble(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), geometricShapeIndex, segmentIndex, y);
    }

    const double c_api_getCompartmentsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document) {
        return getCompartmentGeometricShapeBasePoint2YAsDouble(document);
    }

    int c_api_setCompartmentsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setCompartmentGeometricShapeBasePoint2YAsDouble(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getSpeciesGeometricShapeSegmentBasePoint2Y(SBMLDocument* document) {
        return getSpeciesGeometricShapeBasePoint2YAsDouble(document);
    }

    int c_api_setSpeciesGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setSpeciesGeometricShapeBasePoint2YAsDouble(document, layoutIndex, segmentIndex, y);
    }

    const double c_api_getReactionsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document) {
        return getReactionGeometricShapeBasePoint2YAsDouble(document);
    }

    int c_api_setReactionsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setReactionGeometricShapeBasePoint2YAsDouble(document, layoutIndex, segmentIndex, y);
    }

    int c_api_setGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex, int layoutIndex) {
        return setGeometricShapeBasePoint2YAsDouble(document, layoutIndex, segmentIndex, y);
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

    const char* c_api_getCompartmentsGeometricShapeHref(SBMLDocument* document) {
        return strdup(getCompartmentGeometricShapeHref(document).c_str());
    }

    int c_api_setCompartmentsGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex) {
        return setCompartmentGeometricShapeHref(document, layoutIndex, href);
    }

    const char* c_api_getSpeciesGeometricShapeHref(SBMLDocument* document) {
        return strdup(getSpeciesGeometricShapeHref(document).c_str());
    }

    int c_api_setSpeciesGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex) {
        return setSpeciesGeometricShapeHref(document, layoutIndex, href);
    }

    const char* c_api_getReactionsGeometricShapeHref(SBMLDocument* document) {
        return strdup(getReactionGeometricShapeHref(document).c_str());
    }

    int c_api_setReactionsGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex) {
        return setReactionGeometricShapeHref(document, layoutIndex, href);
    }

    int c_api_setGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex) {
        return setGeometricShapeHref(document, layoutIndex, href);
    }

    const char* c_api_getStyle(SBMLDocument* document, int renderIndex) {
        return strdup(getStyle(document, renderIndex).c_str());
    }

    int c_api_setStyle(SBMLDocument* document, const char* styleName, int renderIndex) {
        return setStyle(document, renderIndex, styleName);
    }

    bool c_api_whetherDisplayReactionTextLabel(const char* styleName) {
        return whetherDisplayReactionTextLabel(styleName);
    }

    int c_api_getNumPredefinedStyles() {
        return getPredefinedStyleNames().size();
    }

    const char* c_api_getNthPredefinedStyleName(int index) {
        if (index >= 0 && index < c_api_getNumPredefinedStyles())
            return strdup(getPredefinedStyleNames().at(index).c_str());

        return "";
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