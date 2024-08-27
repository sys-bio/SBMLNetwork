#ifndef __LIBSBMLNETWORK_STYLES_H
#define __LIBSBMLNETWORK_STYLES_H

#include <cstdlib>
#include <string>
#include <vector>
#include <map>

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
}

#endif
