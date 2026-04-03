#include "libsbmlnetwork_styles.h"
#include "../../libsbmlnetwork_common.h"
#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_sbmldocument_layout.h"

#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
                {"compartment-border-color", "orangered"},
                {"compartment-border-width", "4"},
                {"compartment-fill-color", "white"},
                {"compartment-font-color", "darkslategray"},
                {"compartment-font-size", "10"},
                {"compartment-font-family", "sans-serif"},
                {"compartment-font-style", "normal"},
                {"compartment-font-weight", "bold"},
                {"compartment-text-horizontal-alignment", "middle"},
                {"compartment-text-vertical-alignment", "bottom"},
                {"compartment-border-radius-x", "25"},
                {"compartment-border-radius-y", "25"},
                {"species-geometric-shape", "rectangle"},
                {"species-border-color", "orangered"},
                {"species-border-width", "4"},
                {"species-fill-color", "orange"},
                {"species-font-color", "darkslategray"},
                {"species-font-size", "24"},
                {"species-font-family", "sans-serif"},
                {"species-font-style", "normal"},
                {"species-font-weight", "normal"},
                {"species-text-horizontal-alignment", "middle"},
                {"species-text-vertical-alignment", "middle"},
                {"species-border-radius-x", "6"},
                {"species-border-radius-y", "3.6"},
                {"reaction-geometric-shape", "rectangle"},
                {"reaction-line-color", "navy"},
                {"reaction-line-width", "6"},
                {"reaction-border-color", "navy"},
                {"reaction-border-width", "4"},
                {"reaction-fill-color", "white"},
                {"reaction-font-color", "darkslategray"},
                {"reaction-font-size", "8"},
                {"reaction-font-family", "sans-serif"},
                {"reaction-font-style", "normal"},
                {"reaction-font-weight", "normal"},
                {"reaction-text-horizontal-alignment", "middle"},
                {"reaction-text-vertical-alignment", "middle"},
                {"line-ending-border-color", "navy"},
                {"line-ending-border-width", "5"},
                {"line-ending-fill-color", "navy"},
                {"display-reaction-text-label", "true"}
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
                {"reaction-geometric-shape-center-x", "7.5"},
                {"reaction-geometric-shape-center-y", "7.5"},
                {"reaction-geometric-shape-radius-x", "3.75"},
                {"reaction-geometric-shape-radius-y", "3.75"},
                {"reaction-line-color", "sanjuan"},
                {"reaction-line-width", "9"},
                {"reaction-border-color", "mineshaft"},
                {"reaction-border-width", "4"},
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
        if (styleScores.at(0).second <= scoreThreshold)
            return "";

        return styleScores.at(0).first;
    }

    void setEscherStyleCustomFeatures(SBMLDocument* document, int layoutIndex) {
        setUseNameAsTextLabel(document, layoutIndex, false);

        // Compartments
        int numCompartments = 0;
        std::string defaultCompartmentId;
        for (unsigned c = 0; c < getNumCompartments(document); ++c) {
            std::string cid = getCompartmentId(document, c);
            defaultCompartmentId = cid;
            for (unsigned go = 0; go < getNumCompartmentGlyphs(document, layoutIndex, cid); ++go) {
                ++numCompartments;
            }
        }
        if (numCompartments == 1) {
            makeInvisible(document, getGraphicalObject(document, layoutIndex, defaultCompartmentId, 0), false);
        }

        // Species
        for (unsigned s = 0; s < getNumSpecies(document); ++s) {
            std::string sid = getSpeciesId(document, s);
            for (unsigned sg = 0; sg < getNumSpeciesGlyphs(document, layoutIndex, sid); ++sg) {
                UpdateSpeciesFeatures(document, layoutIndex, sid, sg);
                UpdateAllCurvesTouchingSpeciesGlyph(document, layoutIndex, sid, sg);

                for (unsigned tg = 0; tg < getNumTextGlyphs(document, layoutIndex, sid, sg); ++tg) {
//                    setFontSizeAsDouble(document, getGraphicalObject(document, layoutIndex, sid, sg), tg, 12);
//                    setFontColor(document,        getGraphicalObject(document, layoutIndex, sid, sg), tg, "black");
//                    setFontStyle(document,        getGraphicalObject(document, layoutIndex, sid, sg), tg, "italic");
//                    setFontWeight(document,       getGraphicalObject(document, layoutIndex, sid, sg), tg, "bold");
                    UpdateSpeciesLabelPosition(document, layoutIndex, sid, sg, tg);
                }
            }
        }

        // Reactions
        for (unsigned rIdx = 0; rIdx < getNumReactions(document); ++rIdx) {
            std::string rid = getReactionId(document, rIdx);
            for (unsigned rg = 0; rg < getNumReactionGlyphs(document, layoutIndex, rid); ++rg) {
                bool reversed = AreSubstratesDirectionsReversed(document, layoutIndex, rid, rg);
                ShowReversibilityHeads(document, layoutIndex, rid, rg, reversed);

                SetReactionCenterStyle(document, layoutIndex, rid, rg);
                AddGeometricShapesToMultipleCurveSegments(document, layoutIndex, rid, rg);

                for (unsigned tg = 0; tg < getNumTextGlyphs(document, layoutIndex, rid, rg); ++tg) {
                    UpdateReactionLabel(document, layoutIndex, rid, rg, tg);
                }
            }
        }

        // Arrow heads
        ConfigureArrowHeadsForAllReactions(document, layoutIndex, -2.0, -3.0, 4.0, 6.0);

        // Independent text glyphs
        for (unsigned it = 0; it < getNumIndependentTextGlyphs(document, layoutIndex); ++it) {
            std::string id = getIndependentTextGlyphId(document, layoutIndex, it);
            int go = 0, tg = 0;
            setFontSizeAsDouble(document, getGraphicalObject(document, layoutIndex, id, go), tg, 38);
            setFontColor(document,        getGraphicalObject(document, layoutIndex, id, go), tg, "black");
            setFontStyle(document,        getGraphicalObject(document, layoutIndex, id, go), tg, "italic");
            setFontWeight(document,       getGraphicalObject(document, layoutIndex, id, go), tg, "bold");
        }
    }

    bool IsSubstrateRole(const std::string& role) {
        return role == "substrate" || role == "sidesubstrate" || role == "side substrate"
               || role == "reactant"  || role == "sidereactant" || role == "side reactant";
    }

    bool IsProductRole(const std::string& role) {
        return role == "product" || role == "sideproduct" || role == "side product";
    }

    void UpdateSpeciesFeatures(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned glyphIndex) {
        double w = getDimensionWidth(document, layoutIndex, speciesId, glyphIndex);
        double h = getDimensionHeight(document, layoutIndex, speciesId, glyphIndex);
        if (w > 30.0 || h > 30.0) {
            setDimensionWidth(document, layoutIndex, speciesId, glyphIndex, 30.0, false);
            setDimensionHeight(document, layoutIndex, speciesId, glyphIndex, 30.0, false);
        }
    }

    std::pair<double,double> SpeciesCenter(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned glyphIndex) {
        double x = getPositionX(document, layoutIndex, speciesId, glyphIndex);
        double y = getPositionY(document, layoutIndex, speciesId, glyphIndex);
        double w = getDimensionWidth(document, layoutIndex, speciesId, glyphIndex);
        double h = getDimensionHeight(document, layoutIndex, speciesId, glyphIndex);
        return {x + w/2.0, y + h/2.0};
    }

    inline bool EndCloserThanStart(double sx, double sy, double ex, double ey, double cx, double cy) {
        double end_d2   = std::sqrt((ex - cx)*(ex - cx) + (ey - cy)*(ey - cy));
        double start_d2 = std::sqrt((sx - cx)*(sx - cx) + (sy - cy)*(sy - cy));
        return end_d2 < start_d2;
    }

    bool IsEndPointCloseToSpecies(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned speciesReferenceIndex, double speciesCenterX, double speciesCenterY) {
        int seg0 = 0;
        int segN = getNumSpeciesReferenceCurveSegments(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex);
        int last = segN - 1;

        double sx = getSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0);
        double sy = getSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0);
        double ex = getSpeciesReferenceCurveSegmentEndPointX  (document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last);
        double ey = getSpeciesReferenceCurveSegmentEndPointY  (document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last);

        return EndCloserThanStart(sx, sy, ex, ey, speciesCenterX, speciesCenterY);
    }
    
    void UpdateCurveEndPoint(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned speciesReferenceIndex, double speciesCenterX, double speciesCenterY, double speciesGlyphW, double speciesGlyphH) {
        int seg0 = 0;
        int segN = getNumSpeciesReferenceCurveSegments(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex);
        int last = segN - 1;

        double sX = getSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0);
        double sY = getSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0);
        double eX = getSpeciesReferenceCurveSegmentEndPointX  (document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last);
        double eY = getSpeciesReferenceCurveSegmentEndPointY  (document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last);

        double c1X = getSpeciesReferenceCurveSegmentBasePoint1X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0);
        double c1Y = getSpeciesReferenceCurveSegmentBasePoint1Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0);
        double c2X = getSpeciesReferenceCurveSegmentBasePoint2X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last);
        double c2Y = getSpeciesReferenceCurveSegmentBasePoint2Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last);

        bool endClose = EndCloserThanStart(sX, sY, eX, eY, speciesCenterX, speciesCenterY);

        double angle = 0.0;
        double offset = 20.0;

        if (endClose) {
            if (std::abs(eX - c2X) > 1e-6 || std::abs(eY - c2Y) > 1e-6) {
                angle = std::atan2(eY - c2Y, eX - c2X);
            } else {
                angle = std::atan2(eY - c1Y, eX - c1X);
            }
            angle += M_PI;

            double newEndX = speciesCenterX + (speciesGlyphW/2.0 + offset) * std::cos(angle);
            double newEndY = speciesCenterY + (speciesGlyphH/2.0 + offset) * std::sin(angle);

            setSpeciesReferenceCurveSegmentEndPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last, newEndX);
            setSpeciesReferenceCurveSegmentEndPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last, newEndY);

            if (getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex) == 2) {
                setSpeciesReferenceCurveSegmentBasePoint2X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last, newEndX);
                setSpeciesReferenceCurveSegmentBasePoint2Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, last, newEndY);
            }
        } else {
            if (std::abs(sX - c1X) > 1e-6 || std::abs(sY - c1Y) > 1e-6) {
                angle = std::atan2(sY - c1Y, sX - c1X);
            } else {
                angle = std::atan2(sY - c2Y, sX - c2X);
            }
            angle += M_PI;

            double newStartX = speciesCenterX + (speciesGlyphW/2.0 + offset) * std::cos(angle);
            double newStartY = speciesCenterY + (speciesGlyphH/2.0 + offset) * std::sin(angle);

            setSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0, newStartX);
            setSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0, newStartY);

            if (getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex) == 2) {
                setSpeciesReferenceCurveSegmentBasePoint1X(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0, newStartX);
                setSpeciesReferenceCurveSegmentBasePoint1Y(document, layoutIndex, reactionId, reactionGlyphIndex, speciesReferenceIndex, seg0, newStartY);
            }
        }
    }

    void UpdateAllCurvesTouchingSpeciesGlyph(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned speciesGlyphIndex) {
        std::string speciesGlyphId = getId(document, layoutIndex, speciesId, speciesGlyphIndex);
        double w = getDimensionWidth(document, layoutIndex, speciesId, speciesGlyphIndex);
        double h = getDimensionHeight(document, layoutIndex, speciesId, speciesGlyphIndex);
        auto center = SpeciesCenter(document, layoutIndex, speciesId, speciesGlyphIndex);
        double cx = center.first;
        double cy = center.second;

        for (unsigned rIdx = 0; rIdx < getNumReactions(document); ++rIdx) {
            std::string reactionId = getReactionId(document, rIdx);
            for (unsigned rg = 0; rg < getNumReactionGlyphs(document, layoutIndex, reactionId); ++rg) {
                for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, rg); ++sr) {
                    std::string connectedSpeciesGlyphId = getSpeciesReferenceSpeciesGlyphId(document, layoutIndex, reactionId, rg, sr);
                    if (stringCompare(connectedSpeciesGlyphId, speciesGlyphId)) {
                        UpdateCurveEndPoint(document, layoutIndex, reactionId, rg, sr, cx, cy, w, h);
                    }
                }
            }
        }
    }

    void UpdateSpeciesLabelPosition(SBMLDocument* document, int layoutIndex, const std::string& speciesId, unsigned speciesGlyphIndex, unsigned textGlyphIndex) {
        double speciesX = getPositionX(document, layoutIndex, speciesId, speciesGlyphIndex);
        double speciesY = getPositionY(document, layoutIndex, speciesId, speciesGlyphIndex);
        double w = getDimensionWidth(document, layoutIndex, speciesId, speciesGlyphIndex);
        double h = getDimensionHeight(document, layoutIndex, speciesId, speciesGlyphIndex);

        double speciesCX = speciesX + w / 2.0;
        double speciesCY = speciesY + h / 2.0;

        double reactionCX = -1.0, reactionCY = -1.0;
        std::string speciesGlyphId = getId(document, layoutIndex, speciesId, speciesGlyphIndex);
        for (unsigned rIdx = 0; rIdx < getNumReactions(document); ++rIdx) {
            std::string reactionId = getReactionId(document, rIdx);
            for (unsigned rg = 0; rg < getNumReactionGlyphs(document, layoutIndex, reactionId); ++rg) {
                for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, rg); ++sr) {
                    if (stringCompare(getSpeciesReferenceSpeciesGlyphId(document, layoutIndex, reactionId, rg, sr), speciesGlyphId)) {
                        double rx = getPositionX(document, layoutIndex, reactionId, rg);
                        double ry = getPositionY(document, layoutIndex, reactionId, rg);
                        reactionCX = rx + getDimensionWidth(document, layoutIndex, reactionId, rg) / 2.0;
                        reactionCY = ry + getDimensionHeight(document, layoutIndex, reactionId, rg) / 2.0;
                        goto foundReaction;
                    }
                }
            }
        }
        foundReaction:

        const double pad = 8.0;
        const double diagThreshold = 0.4;

        if (reactionCX < 0.0) {
            setTextPositionX(document, layoutIndex, speciesId, speciesGlyphIndex, textGlyphIndex, speciesX + w + pad * 3.0);
            setTextPositionY(document, layoutIndex, speciesId, speciesGlyphIndex, textGlyphIndex, speciesCY - 7.0);
            return;
        }

        double dx = speciesCX - reactionCX;
        double dy = speciesCY - reactionCY;
        double absDx = std::abs(dx);
        double absDy = std::abs(dy);
        double maxD  = std::max(absDx, absDy);
        bool isDiagonal = (absDx > diagThreshold * maxD) && (absDy > diagThreshold * maxD);

        double newTX, newTY;

        if (isDiagonal) {
            newTX = speciesX + w + pad * 3.0;
            newTY = (dy < 0) ? speciesY - 4.0 : speciesY + h + 2.0;

        } else if (absDx >= absDy) {
            if (dx >= 0) {
                newTX = speciesX + w + pad * 3.0;
                newTY = speciesCY - 7.0;
            } else {
                newTX = speciesCX - 20.0;
                newTY = speciesY + h + pad;
            }
        } else {
            newTX = speciesCX - 20.0;
            newTY = (dy < 0) ? speciesY - 20.0 : speciesY + h + pad;
        }

        setTextPositionX(document, layoutIndex, speciesId, speciesGlyphIndex, textGlyphIndex, newTX);
        setTextPositionY(document, layoutIndex, speciesId, speciesGlyphIndex, textGlyphIndex, newTY);
    }

    bool AreSubstratesDirectionsReversed(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex) {
        for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex); ++sr) {
            std::string speciesGlyphId = getSpeciesReferenceSpeciesGlyphId(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            double cx = getPositionX(document, layoutIndex, speciesGlyphId, 0) + getDimensionWidth(document, layoutIndex, speciesGlyphId, 0) / 2.0;
            double cy = getPositionY(document, layoutIndex, speciesGlyphId, 0) + getDimensionHeight(document, layoutIndex, speciesGlyphId, 0) / 2.0;

            bool endClose = IsEndPointCloseToSpecies(document, layoutIndex, reactionId, reactionGlyphIndex, sr, cx, cy);
            std::string role = getSpeciesReferenceRole(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            if (IsSubstrateRole(role) && !endClose) return true;
        }
        return false;
    }

    void ShowReversibilityHeads(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, bool substratesAreReversed) {
        if (!isReversible(document, reactionId)) return;

        std::string head;
        for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex); ++sr) {
            std::string role = getSpeciesReferenceRole(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            if (IsProductRole(role)) {
                head = getStartHead(document, getSpeciesReference(document, layoutIndex, reactionId, reactionGlyphIndex, sr));
                if (head.empty()) {
                    head = getEndHead(document, getSpeciesReference(document, layoutIndex, reactionId, reactionGlyphIndex, sr));
                }
                break;
            }
        }
        if (head.empty()) return;

        for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex); ++sr) {
            std::string role = getSpeciesReferenceRole(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            if (!IsSubstrateRole(role)) continue;
            if (substratesAreReversed) {
                setStartHead(document, getSpeciesReference(document, layoutIndex, reactionId, reactionGlyphIndex, sr), head);
            } else {
                setEndHead(document, getSpeciesReference(document, layoutIndex, reactionId, reactionGlyphIndex, sr), head);
            }
        }
    }

    void SetReactionCenterStyle(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex) {
        int numShapes = getNumGeometricShapes(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex));
        while (numShapes--) {
            removeGeometricShape(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), 0);
        }
        setGeometricShapeType(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), "ellipse");
        int idx = 0;
        setGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, 3.75);
        setGeometricShapeRadiusY(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, 3.75);
        setGeometricShapeStrokeWidth(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, 4.0);
        setGeometricShapeStrokeColor(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, "mineshaft");
        setGeometricShapeFillColor  (document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, "waikawagray");
    }

    void AddGeometricShapesToMultipleCurveSegments(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex) {
        std::vector<std::pair<double,double>> crossPoints;
        std::set<std::pair<double,double>> seen;

        for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex); ++sr) {
            int nSeg = getNumSpeciesReferenceCurveSegments(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            if (nSeg > 1) {
                int last = nSeg - 1;
                double sx = getSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, sr, last);
                double sy = getSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, sr, last);
                std::pair<double,double> p = {sx, sy};
                if (!seen.count(p)) { crossPoints.push_back(p); seen.insert(p); }
            }
        }

        double rx = getPositionX(document, layoutIndex, reactionId, reactionGlyphIndex);
        double ry = getPositionY(document, layoutIndex, reactionId, reactionGlyphIndex);
        double rX = getGeometricShapeRadiusXAsDouble(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), 0);
        double rY = getGeometricShapeRadiusXAsDouble(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), 0);
        double strokeWidth = getGeometricShapeStrokeWidth(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), 0);
        std::string strokeColor = getGeometricShapeStrokeColor(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), 0);
        std::string fillColor   = getGeometricShapeFillColor  (document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), 0);

        for (const auto& p : crossPoints) {
            addGeometricShape(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), "ellipse");
            int idx = getNumGeometricShapes(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex)) - 1;
            setGeometricShapeCenterXAsDouble(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, p.first  - rx);
            setGeometricShapeCenterYAsDouble(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, p.second - ry);
            setGeometricShapeRadiusX(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, rX);
            setGeometricShapeRadiusY(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, rY);
            setGeometricShapeStrokeWidth(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, strokeWidth);
            setGeometricShapeStrokeColor(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, strokeColor);
            setGeometricShapeFillColor  (document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), idx, fillColor);
        }
    }

    bool IsVerticalReaction(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex) {
        int count = 0, numSegments = 0;
        for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex); ++sr) {
            int nSeg = getNumSpeciesReferenceCurveSegments(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            for (int k = 0; k < nSeg; ++k) {
                ++numSegments;
                double sX = getSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);
                double sY = getSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);
                double eX = getSpeciesReferenceCurveSegmentEndPointX  (document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);
                double eY = getSpeciesReferenceCurveSegmentEndPointY  (document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);

                double dx = std::abs(eX - sX);
                double dy = std::abs(eY - sY);

                if (dx < 1e-6 && dy < 1e-6) {
                    --numSegments;
                    continue;
                }

                if (dy >= dx) {
                    ++count;
                }
            }
        }
        return (numSegments > 0) && (count >= 0.5 * numSegments);
    }

    bool IsHorizontalReaction(SBMLDocument* document, int layoutIndex,
                              const std::string& reactionId, unsigned reactionGlyphIndex) {
        int count = 0, numSegments = 0;
        for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, reactionGlyphIndex); ++sr) {
            int nSeg = getNumSpeciesReferenceCurveSegments(document, layoutIndex, reactionId, reactionGlyphIndex, sr);
            for (int k = 0; k < nSeg; ++k) {
                ++numSegments;
                double sX = getSpeciesReferenceCurveSegmentStartPointX(document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);
                double sY = getSpeciesReferenceCurveSegmentStartPointY(document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);
                double eX = getSpeciesReferenceCurveSegmentEndPointX  (document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);
                double eY = getSpeciesReferenceCurveSegmentEndPointY  (document, layoutIndex, reactionId, reactionGlyphIndex, sr, k);

                double dx = std::abs(eX - sX);
                double dy = std::abs(eY - sY);

                // Treat degenerate (zero-length) segments as neutral — skip them
                if (dx < 1e-6 && dy < 1e-6) {
                    --numSegments;
                    continue;
                }

                if (dx >= dy) {
                    ++count;
                }
            }
        }
        return (numSegments > 0) && (count >= 0.5 * numSegments);
    }

    void UpdateReactionLabelPosition(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned textGlyphIndex) {
        double rx = getPositionX(document, layoutIndex, reactionId, reactionGlyphIndex);
        double ry = getPositionY(document, layoutIndex, reactionId, reactionGlyphIndex);
        double rw = getDimensionWidth (document, layoutIndex, reactionId, reactionGlyphIndex);
        double rh = getDimensionHeight(document, layoutIndex, reactionId, reactionGlyphIndex);

        double tx = getTextPositionX(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex);
        double ty = getTextPositionY(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex);
        double tw = getTextDimensionWidth (document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex);
        double th = getTextDimensionHeight(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex);

        if (std::abs(rx - tx) < 5.0 && std::abs(ry - ty) < 5.0) {
            setTextPositionX(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, tx + rw);
            setTextPositionY(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, ty + rh);
            return;
        }

        if (IsVerticalReaction(document, layoutIndex, reactionId, reactionGlyphIndex)) {
            if (rx + 10.0 < tx) {
                setTextPositionX(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, rx + 20.0);
            } else if (tx < rx && tx + tw > rx) {
                setTextPositionX(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, rx - tw - 10.0);
            } else if (tx + tw + 10.0 < rx) {
                setTextPositionX(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, rx - tw - 10.0);
            }
        } else if (IsHorizontalReaction(document, layoutIndex, reactionId, reactionGlyphIndex)) {
            setTextPositionX(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, rx - tw/2.0);
            if (std::abs(ty - ry) < 20.0) {
                if (ry > ty) {
                    setTextPositionY(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, ry - th - 20.0);
                } else {
                    setTextPositionY(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex, ry + rh + 20.0);
                }
            }
        }
    }

    void UpdateReactionLabel(SBMLDocument* document, int layoutIndex, const std::string& reactionId, unsigned reactionGlyphIndex, unsigned textGlyphIndex) {
        setFontSizeAsDouble(document, getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), textGlyphIndex, 24);
        setFontColor(document,        getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), textGlyphIndex, "luckypoint");
        setFontStyle(document,        getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), textGlyphIndex, "italic");
        setFontWeight(document,       getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), textGlyphIndex, "bold");
        setFontFamily(document,       getGraphicalObject(document, layoutIndex, reactionId, reactionGlyphIndex), textGlyphIndex, "sans-serif");

        UpdateReactionLabelPosition(document, layoutIndex, reactionId, reactionGlyphIndex, textGlyphIndex);
    }

    void ConfigureArrowHeadsForAllReactions(SBMLDocument* document, int layoutIndex, double bx, double by, double bw, double bh) {
        for (unsigned rIdx = 0; rIdx < getNumReactions(document); ++rIdx) {
            std::string reactionId = getReactionId(document, rIdx);
            for (unsigned rg = 0; rg < getNumReactionGlyphs(document, layoutIndex, reactionId); ++rg) {
                for (unsigned sr = 0; sr < getNumSpeciesReferences(document, layoutIndex, reactionId, rg); ++sr) {
                    setSpeciesReferenceLineEndingBoundingBoxX     (document, layoutIndex, reactionId, rg, sr, bx);
                    setSpeciesReferenceLineEndingBoundingBoxY     (document, layoutIndex, reactionId, rg, sr, by);
                    setSpeciesReferenceLineEndingBoundingBoxWidth (document, layoutIndex, reactionId, rg, sr, bw);
                    setSpeciesReferenceLineEndingBoundingBoxHeight(document, layoutIndex, reactionId, rg, sr, bh);
                }
            }
        }
    }
}