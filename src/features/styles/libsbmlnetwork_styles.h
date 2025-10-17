#ifndef __LIBSBMLNETWORK_STYLES_H
#define __LIBSBMLNETWORK_STYLES_H

#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "../../libsbmlnetwork_sbmldocument.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    std::vector<std::string> getPredefinedStyleNames();

    std::map<std::string, std::string> getPredefinedStyleFeatures(const std::string styleName);

    std::map<std::string, std::string> getDefaultPredefinedStyleFeatures();

    std::map<std::string, std::string> getBlueOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getGreenOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getGrayOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getRedOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getOrangeOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getBrownOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getPurpleOmbrePredefinedStyleFeatures();

    std::map<std::string, std::string> getPurpleOmbre2PredefinedStyleFeatures();

    std::map<std::string, std::string> getBlackAndWhitePredefinedStyleFeatures();

    std::map<std::string, std::string> getOrangeAndBluePredefinedStyleFeatures();

    std::map<std::string, std::string> getPurpleAndYellowPredefinedStyleFeatures();

    std::map<std::string, std::string> getGreenAndRedPredefinedStyleFeatures();

    std::map<std::string, std::string> getPowerPredefinedStyleFeatures();

    std::map<std::string, std::string> getCalmPredefinedStyleFeatures();

    std::map<std::string, std::string> getSunsetPredefinedStyleFeatures();

    std::map<std::string, std::string> getElectricPredefinedStyleFeatures();

    std::map<std::string, std::string> getMidnightPredefinedStyleFeatures();

    std::map<std::string, std::string> getVibrancePredefinedStyleFeatures();

    std::map<std::string, std::string> getOceanPredefinedStyleFeatures();

    std::map<std::string, std::string> getForestPredefinedStyleFeatures();

    std::map<std::string, std::string> getWarmTonePredefinedStyleFeatures();

    std::map<std::string, std::string> getCoolTonePredefinedStyleFeatures();

    std::map<std::string, std::string> getEscherPredefinedStyleFeatures();

    const bool isValidPredefinedStyleName(const std::string& predefinedStyleName);

    const std::string findStyle(const std::map<std::string, std::string> renderFeatures);

    void setEscherStyleCustomFeatures(SBMLDocument* document, int layoutIndex = 0);

    bool IsSubstrateRole(const std::string& role);

    bool IsProductRole(const std::string& role);

    void UpdateSpeciesFeatures(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned glyphIndex);

    std::pair<double, double> SpeciesCenter(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned glyphIndex);

    inline bool EndCloserThanStart(double sx, double sy, double ex, double ey, double cx, double cy);

    bool IsEndPointCloseToSpecies(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned speciesReferenceIndex, double speciesCenterX, double speciesCenterY);

    void UpdateCurveEndPoint(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned speciesReferenceIndex, double speciesCenterX, double speciesCenterY, double speciesGlyphW, double speciesGlyphH);

    void UpdateAllCurvesTouchingSpeciesGlyph(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned speciesGlyphIndex);

    void UpdateSpeciesLabelPosition(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned speciesGlyphIndex, unsigned textGlyphIndex);

    bool AreSubstratesDirectionsReversed(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex);

    void ShowReversibilityHeads(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, bool substratesAreReversed);

    void SetReactionCenterStyle(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex);

    void AddGeometricShapesToMultipleCurveSegments(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex);

    bool IsVerticalReaction(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex);

    bool IsHorizontalReaction(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex);

    void UpdateReactionLabelPosition(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned textGlyphIndex);

    void UpdateReactionLabel(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned textGlyphIndex);

    void ConfigureArrowHeadsForAllReactions(SBMLDocument* document, int layoutIndex, double bx, double by, double bw, double bh);
}

#endif
