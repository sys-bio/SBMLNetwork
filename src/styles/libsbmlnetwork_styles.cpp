#include "libsbmlnetwork_styles.h"
#include "../libsbmlnetwork_common.h"

#include <algorithm>

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    std::vector<std::string> getPredefinedStyleNames() {
        std::vector<std::string> predefinedStyleNames;
        predefinedStyleNames.push_back("default");
        predefinedStyleNames.push_back("blue ombre");
        predefinedStyleNames.push_back("green ombre");
        predefinedStyleNames.push_back("gray ombre");
        predefinedStyleNames.push_back("red ombre");
        predefinedStyleNames.push_back("orange ombre");
        predefinedStyleNames.push_back("brown ombre");
        predefinedStyleNames.push_back("purple ombre");
        predefinedStyleNames.push_back("purple ombre 2");
        predefinedStyleNames.push_back("black and white");
        predefinedStyleNames.push_back("orange and blue");
        predefinedStyleNames.push_back("purple and yellow");
        predefinedStyleNames.push_back("green and red");
        predefinedStyleNames.push_back("power");
        predefinedStyleNames.push_back("calm");
        predefinedStyleNames.push_back("sunset");
        predefinedStyleNames.push_back("electric");
        predefinedStyleNames.push_back("midnight");
        predefinedStyleNames.push_back("vibrance");
        predefinedStyleNames.push_back("ocean");
        predefinedStyleNames.push_back("forest");
        predefinedStyleNames.push_back("warm tone");
        predefinedStyleNames.push_back("cool tone");
        predefinedStyleNames.push_back("escher");

        return predefinedStyleNames;
    }

    std::map<std::string, std::string> getPredefinedStyleFeatures(const std::string styleName) {
        std::map<std::string, std::string> styleFeatures;
        std::map<std::string, std::string> defaultStyleFeatures = getDefaultPredefinedStyleFeatures();
        if (stringCompare(styleName, "default"))
            styleFeatures = defaultStyleFeatures;
        else {
            if (stringCompare(styleName, "blue ombre"))
                styleFeatures = getBlueOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "green ombre"))
                styleFeatures = getGreenOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "gray ombre") || stringCompare(styleName, "grey ombre"))
                styleFeatures = getGrayOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "red ombre"))
                styleFeatures = getRedOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "orange ombre"))
                styleFeatures = getOrangeOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "brown ombre"))
                styleFeatures = getBrownOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "purple ombre"))
                styleFeatures = getPurpleOmbrePredefinedStyleFeatures();
            else if (stringCompare(styleName, "purple ombre 2"))
                styleFeatures = getPurpleOmbre2PredefinedStyleFeatures();
            else if (stringCompare(styleName, "black and white"))
                styleFeatures = getBlackAndWhitePredefinedStyleFeatures();
            else if (stringCompare(styleName, "orange and blue"))
                styleFeatures = getOrangeAndBluePredefinedStyleFeatures();
            else if (stringCompare(styleName, "purple and yellow"))
                styleFeatures = getPurpleAndYellowPredefinedStyleFeatures();
            else if (stringCompare(styleName, "green and red"))
                styleFeatures = getGreenAndRedPredefinedStyleFeatures();
            else if (stringCompare(styleName, "power"))
                styleFeatures = getPowerPredefinedStyleFeatures();
            else if (stringCompare(styleName, "calm"))
                styleFeatures = getCalmPredefinedStyleFeatures();
            else if (stringCompare(styleName, "sunset"))
                styleFeatures = getSunsetPredefinedStyleFeatures();
            else if (stringCompare(styleName, "electric"))
                styleFeatures = getElectricPredefinedStyleFeatures();
            else if (stringCompare(styleName, "midnight"))
                styleFeatures = getMidnightPredefinedStyleFeatures();
            else if (stringCompare(styleName, "vibrance"))
                styleFeatures = getVibrancePredefinedStyleFeatures();
            else if (stringCompare(styleName, "ocean"))
                styleFeatures = getOceanPredefinedStyleFeatures();
            else if (stringCompare(styleName, "forest"))
                styleFeatures = getForestPredefinedStyleFeatures();
            else if (stringCompare(styleName, "warm tone"))
                styleFeatures = getWarmTonePredefinedStyleFeatures();
            else if (stringCompare(styleName, "cool tone"))
                styleFeatures = getCoolTonePredefinedStyleFeatures();
            else if (stringCompare(styleName, "escher"))
                styleFeatures = getEscherPredefinedStyleFeatures();
            styleFeatures.insert(defaultStyleFeatures.begin(), defaultStyleFeatures.end());
        }

        return styleFeatures;
    }

    std::map<std::string, std::string> getDefaultPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "default"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "darkcyan"},
                {"compartment-border-width", "2"},
                {"compartment-fill-color", "lightgray"},
                {"compartment-font-color", "darkcyan"},
                {"compartment-font-size", "10"},
                {"compartment-font-family", "sans-serif"},
                {"compartment-font-style", "normal"},
                {"compartment-font-weight", "normal"},
                {"compartment-text-horizontal-alignment", "middle"},
                {"compartment-text-vertical-alignment", "bottom"},
                {"compartment-border-radius-x", "25"},
                {"compartment-border-radius-y", "25"},
                {"species-geometric-shape", "rectangle"},
                {"species-border-color", "black"},
                {"species-border-width", "2"},
                {"species-fill-color", "white"},
                {"species-font-color", "black"},
                {"species-font-size", "24"},
                {"species-font-family", "sans-serif"},
                {"species-font-style", "normal"},
                {"species-font-weight", "normal"},
                {"species-text-horizontal-alignment", "middle"},
                {"species-text-vertical-alignment", "middle"},
                {"species-border-radius-x", "6"},
                {"species-border-radius-y", "3.6"},
                {"reaction-geometric-shape", "ellipse"},
                {"reaction-line-color", "black"},
                {"reaction-line-width", "2"},
                {"reaction-border-color", "black"},
                {"reaction-border-width", "2"},
                {"reaction-fill-color", "white"},
                {"reaction-font-color", "darkslategray"},
                {"reaction-font-size", "12"},
                {"reaction-font-family", "sans-serif"},
                {"reaction-font-style", "normal"},
                {"reaction-font-weight", "normal"},
                {"reaction-text-horizontal-alignment", "middle"},
                {"reaction-text-vertical-alignment", "middle"},
                {"line-ending-border-color", "black"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "black"},
                {"display-reaction-text-label", "false"}
        };

        return styleFeatures;
    }

    std::map<std::string, std::string> getBlueOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "blue ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "arapawa"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "arapawa"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "perano"},
                {"species-border-color", "arapawa"},
                {"species-border-width", "3"},
                {"species-font-color", "arapawa"},
                {"species-font-size", "24"},
                {"reaction-line-color", "indigo"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "arapawa"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "indigo"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "indigo"},
        };

        return styleFeatures;
    }

    std::map<std::string, std::string> getGreenOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "green ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "darkfern"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "darkfern"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "grannysmithapple"},
                {"species-border-color", "darkfern"},
                {"species-border-width", "3"},
                {"species-font-color", "darkfern"},
                {"species-font-size", "24"},
                {"reaction-line-color", "fruitsalad"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "darkfern"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "fruitsalad"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "fruitsalad"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getGrayOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "gray ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "nandor"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "nandor"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "pumice"},
                {"species-border-color", "nandor"},
                {"species-border-width", "3"},
                {"species-font-color", "nandor"},
                {"species-font-size", "24"},
                {"reaction-line-color", "gunsmoke"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "nandor"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "gunsmoke"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "gunsmoke"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getRedOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "red ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "totempole"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "mexicanred"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "apricot"},
                {"species-border-color", "totempole"},
                {"species-border-width", "3"},
                {"species-font-color", "mexicanred"},
                {"species-font-size", "24"},
                {"reaction-line-color", "crimson"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "mexicanred"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "crimson"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "crimson"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getOrangeOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "orange ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "vesuvius"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "vesuvius"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "diserria"},
                {"species-border-color", "vesuvius"},
                {"species-border-width", "3"},
                {"species-font-color", "vesuvius"},
                {"species-font-size", "24"},
                {"reaction-line-color", "reddamask"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "vesuvius"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "reddamask"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "reddamask"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getBrownOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "brown ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "mondo"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "mondo"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "domino"},
                {"species-border-color", "mondo"},
                {"species-border-width", "3"},
                {"species-font-color", "mondo"},
                {"species-font-size", "24"},
                {"reaction-line-color", "hemlock"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "mondo"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "hemlock"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "hemlock"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getPurpleOmbrePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "purple ombre"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "rebeccapurple"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "purple"},
                {"compartment-font-color", "white"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "mediumpurple"},
                {"species-border-color", "purpleheart"},
                {"species-border-width", "3"},
                {"species-font-color", "white"},
                {"species-font-size", "24"},
                {"reaction-line-color", "white"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "white"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "white"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "white"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getPurpleOmbre2PredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "purple ombre 2"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "seance"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "seance"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "eastside"},
                {"species-border-color", "seance"},
                {"species-border-width", "3"},
                {"species-font-color", "seance"},
                {"species-font-size", "24"},
                {"reaction-line-color", "studio"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "seance"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "studio"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "studio"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getBlackAndWhitePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "black and white"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "white"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "black"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "white"},
                {"species-border-color", "black"},
                {"species-border-width", "3"},
                {"species-font-color", "black"},
                {"species-font-size", "24"},
                {"reaction-line-color", "black"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "black"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "black"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "black"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getOrangeAndBluePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "orange and blue"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "jaffa"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "ceruleanblue"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "picton blue"},
                {"species-border-color", "jaffa"},
                {"species-border-width", "3"},
                {"species-font-color", "ceruleanblue"},
                {"species-font-size", "24"},
                {"reaction-line-color", "jaffa"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "ceruleanblue"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "jaffa"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "jaffa"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getPurpleAndYellowPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "purple and yellow"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "daisybush"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "daisybush"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "khaki"},
                {"species-border-color", "daisybush"},
                {"species-border-width", "3"},
                {"species-font-color", "daisybush"},
                {"species-font-size", "24"},
                {"reaction-line-color", "royalpurple"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "daisybush"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "royalpurple"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "royalpurple"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getGreenAndRedPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "green and red"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "forestgreen"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "thunderbird"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "fern"},
                {"species-border-color", "everglade"},
                {"species-border-width", "3"},
                {"species-font-color", "thunderbird"},
                {"species-font-size", "24"},
                {"reaction-line-color", "thunderbird"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "thunderbird"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "thunderbird"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "thunderbird"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getPowerPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "power"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "mandy"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "pewter"},
                {"compartment-font-color", "gondola"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "carnation"},
                {"species-border-color", "gondola"},
                {"species-border-width", "3"},
                {"species-font-color", "gondola"},
                {"species-font-size", "24"},
                {"reaction-line-color", "gondola"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "gondola"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "gondola"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "gondola"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getCalmPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "calm"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "paradiso"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "montecarlo"},
                {"compartment-font-color", "totempole"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "jaffa"},
                {"species-border-color", "goldengrass"},
                {"species-border-width", "3"},
                {"species-font-color", "totempole"},
                {"species-font-size", "24"},
                {"reaction-line-color", "paradiso"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "totempole"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "paradiso"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "paradiso"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getSunsetPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "sunset"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "hibiscus"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "orangepeel"},
                {"compartment-font-color", "purpleheart"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "hibiscus"},
                {"species-border-color", "purpleheart"},
                {"species-border-width", "3"},
                {"species-font-color", "purpleheart"},
                {"species-font-size", "24"},
                {"reaction-line-color", "frenchrose"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "purpleheart"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "frenchrose"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "frenchrose"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getElectricPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "electric"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "java"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "riptide"},
                {"compartment-font-color", "cerise"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "lightorchid"},
                {"species-border-color", "java"},
                {"species-border-width", "3"},
                {"species-font-color", "cerise"},
                {"species-font-size", "24"},
                {"reaction-line-color", "hopbush"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "cerise"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "hopbush"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "hopbush"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getMidnightPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "midnight"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "thunderbird"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "dulllavender"},
                {"compartment-font-color", "thunderbird"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "sunglo"},
                {"species-border-color", "bayofmany"},
                {"species-border-width", "3"},
                {"species-font-color", "thunderbird"},
                {"species-font-size", "24"},
                {"reaction-line-color", "thunderbird"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "thunderbird"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "thunderbird"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "thunderbird"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getVibrancePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "vibrance"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "casal"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "carrotorange"},
                {"compartment-font-color", "shiraz"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "shiraz"},
                {"species-border-color", "cannonpink"},
                {"species-border-width", "3"},
                {"species-font-color", "shiraz"},
                {"species-font-size", "24"},
                {"reaction-line-color", "buttercup"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "shiraz"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "buttercup"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "buttercup"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getOceanPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "ocean"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "elm"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "yuma"},
                {"compartment-font-color", "riverbed"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "aquaisland"},
                {"species-border-color", "elm"},
                {"species-border-width", "3"},
                {"species-font-color", "riverbed"},
                {"species-font-size", "24"},
                {"reaction-line-color", "chino"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "riverbed"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "chino"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "chino"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getForestPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "forest"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "lunargreen"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "tobaccobrown"},
                {"compartment-font-color", "gladegreen"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "sage"},
                {"species-border-color", "tomthumb"},
                {"species-border-width", "3"},
                {"species-font-color", "gladegreen"},
                {"species-font-size", "24"},
                {"reaction-line-color", "tobaccobrown"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "gladegreen"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "tobaccobrown"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "tobaccobrown"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getWarmTonePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "warm tone"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "mondo"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "tiamaria"},
                {"compartment-font-color", "ochre"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "creamcan"},
                {"species-border-color", "tiamaria"},
                {"species-border-width", "3"},
                {"species-font-color", "ochre"},
                {"species-font-size", "24"},
                {"reaction-line-color", "christine"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "ochre"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "christine"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "christine"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getCoolTonePredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "cool tone"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "blueribbon"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "purpleheart"},
                {"compartment-font-color", "blueribbon"},
                {"compartment-font-size", "10"},
                {"species-geometric-shape", "rectangle"},
                {"species-fill-color", "purpleheart"},
                {"species-border-color", "azureradiance"},
                {"species-border-width", "3"},
                {"species-font-color", "blueribbon"},
                {"species-font-size", "24"},
                {"reaction-line-color", "puertorico"},
                {"reaction-line-width", "3"},
                {"reaction-font-color", "blueribbon"},
                {"reaction-font-size", "12"},
                {"line-ending-border-color", "puertorico"},
                {"line-ending-border-width", "3"},
                {"line-ending-fill-color", "puertorico"}
        };
        return styleFeatures;
    }

    std::map<std::string, std::string> getEscherPredefinedStyleFeatures() {
        static std::map<std::string, std::string> styleFeatures = {
                {"name", "escher"},
                {"background-color", "white"},
                {"compartment-geometric-shape", "rectangle"},
                {"compartment-border-color", "black"},
                {"compartment-border-width", "3"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "black"},
                {"compartment-font-size", "10"},
                {"compartment-font-style", "italic"},
                {"compartment-font-weight", "bold"},
                {"species-geometric-shape", "ellipse"},
                {"species-geometric-shape-ratio", "1"},
                {"species-border-color", "hawaiiantan"},
                {"species-border-width", "5"},
                {"species-fill-color", "terracotta"},
                {"species-font-color", "black"},
                {"species-font-size", "12"},
                {"species-font-style", "italic"},
                {"species-font-weight", "bold"},
                {"reaction-geometric-shape", "ellipse"},
                {"reaction-geometric-shape-center-x", "0.0"},
                {"reaction-geometric-shape-center-y", "0.0"},
                {"reaction-geometric-shape-radius-x", "4"},
                {"reaction-geometric-shape-radius-y", "4"},
                {"reaction-line-color", "sanjuan"},
                {"reaction-line-width", "9"},
                {"reaction-border-color", "mineshaft"},
                {"reaction-border-width", "3"},
                {"reaction-fill-color", "waikawagray"},
                {"reaction-font-color", "luckypoint"},
                {"reaction-font-size", "24"},
                {"reaction-font-style", "italic"},
                {"reaction-font-weight", "bold"},
                {"line-ending-border-color", "sanjuan"},
                {"line-ending-border-width", "6"},
                {"line-ending-fill-color", "sanjuan"},
                {"display-reaction-text-label", "true"}
        };
        return styleFeatures;
    }

    const bool isValidPredefinedStyleName(const std::string& predefinedStyleName) {
        std::vector<std::string> predefinedStyleNames = getPredefinedStyleNames();
        for (unsigned int i = 0; i < predefinedStyleNames.size(); i++) {
            if (stringCompare(predefinedStyleNames.at(i), predefinedStyleName))
                return true;
        }

        std::cerr << "error: predefined style name is not valid" << std::endl;
        return false;
    }

    const std::string findStyle(const std::map<std::string, std::string> renderFeatures) {
        std::vector<std::string> predefinedStyleNames = getPredefinedStyleNames();
        std::vector<std::pair<std::string, int>> styleScores;
        for (unsigned int i = 0; i < predefinedStyleNames.size(); i++) {
            std::map<std::string, std::string> predefinedStyleFeatures = getPredefinedStyleFeatures(predefinedStyleNames.at(i));
            int score = 0;
            for (std::map<std::string, std::string>::iterator it = predefinedStyleFeatures.begin(); it != predefinedStyleFeatures.end(); it++) {
                if (renderFeatures.find(it->first) != renderFeatures.end() && stringCompare(renderFeatures.at(it->first), it->second))
                    score++;
            }
            styleScores.push_back(std::make_pair(predefinedStyleNames.at(i), score));
        }

        std::sort(styleScores.begin(), styleScores.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });

        const int scoreThreshold = 15;
        if (styleScores.at(0).second <= scoreThreshold) {
            std::cerr << "error: no predefined style found" << std::endl;
            return "";
        }

        return styleScores.at(0).first;
    }
}