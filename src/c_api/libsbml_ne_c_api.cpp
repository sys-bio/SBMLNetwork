#include "libsbml_ne_c_api.h"

extern "C" {

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

    SBMLDocument* c_api_readSBML(const char* sbml) {
        return readSBML(sbml);
    }

    bool c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName) {
        return writeSBMLToFile(document, fileName);
    }

    const char* c_api_writeSBMLToString(SBMLDocument* document) {
        return writeSBMLToString(document);
    }

    int c_api_autolayout(SBMLDocument *document, const double stiffness, const double gravity, const bool useMagnetism,
                   const bool useBoundary, const bool useGrid, const char **lockedNodeIds) {
        std::vector <std::string> lockedNodeIdsVector = std::vector<std::string>();
        if (lockedNodeIds) {
            for (int i = 0; lockedNodeIds[i] != nullptr; i++)
                lockedNodeIdsVector.emplace_back(lockedNodeIds[i]);
        }

        return autolayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid, lockedNodeIdsVector);
    }

    const int c_api_getNumLayouts(SBMLDocument* document) {
        return getNumLayouts(document);
    }

    int c_api_removeLayouts(SBMLDocument* document) {
        return removeAllLayouts(document);
    }

    double c_api_getWidth(SBMLDocument* document, int layoutIndex) {
        return getDimensionWidth(document, layoutIndex);
    }

    int c_api_setWidth(SBMLDocument* document, const double width, int layoutIndex) {
        return setDimensionWidth(document, layoutIndex, width);
    }

    double c_api_getHeight(SBMLDocument* document, int layoutIndex) {
        return getDimensionHeight(document, layoutIndex);
    }

    int c_api_setHeight(SBMLDocument* document, const double height, int layoutIndex) {
        return setDimensionHeight(document, layoutIndex, height);
    }

    const int c_api_getNumAllGraphicalObjects(SBMLDocument* document, int layoutIndex) {
        return getNumGraphicalObjects(document, layoutIndex);
    }

    const int c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex) {
        return getNumGraphicalObjects(document, layoutIndex, id);
    }

    const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumCompartmentGlyphs(document, layoutIndex);
    }

    const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex) {
        return getNumCompartmentGlyphs(document, layoutIndex, compartmentId);
    }

    bool c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex) {
        return isCompartmentGlyph(document, layoutIndex, compartmentId);
    }

    const int c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumSpeciesGlyphs(document, layoutIndex);
    }

    const int c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex) {
        return getNumSpeciesGlyphs(document, layoutIndex, speciesId);
    }

    bool c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex) {
        return isSpeciesGlyph(document, layoutIndex, speciesId);
    }

    const int c_api_getNumAllReactionGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumReactionGlyphs(document, layoutIndex);
    }

    const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex) {
        return getNumReactionGlyphs(document, layoutIndex, reactionId);
    }

    bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex) {
        return isReactionGlyph(document, layoutIndex, reactionId);
    }

    const int c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex) {
        return getNumSpeciesReferenceGlyphs(document, layoutIndex, reactionId, reactionGlyphIndex);
    }

    bool c_api_isSetRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return isSetRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
    }

    const char* c_api_getRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int speciesReferenceGlyphIndex, int layoutIndex) {
        return strdup(getRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex).c_str());
    }

    int c_api_setRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex, int speciesReferenceGlyphIndex, unsigned int layoutIndex) {
        return setRole(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
    }

    const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex) {
        return getNumTextGlyphs(document, layoutIndex);
    }

    const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* graphicalObjectId, int layoutIndex) {
        return getNumTextGlyphs(document, layoutIndex, graphicalObjectId);
    }
}

}