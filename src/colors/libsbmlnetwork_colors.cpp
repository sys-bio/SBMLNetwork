#include "libsbmlnetwork_colors.h"
#include "../libsbmlnetwork_common.h"


namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    const std::map<std::string, std::string>* colorData() {
        static std::map<std::string, std::string> colors = {
                {"aliceblue", "#F0F8FF"},
                {"antiquewhite", "#FAEBD7"},
                {"aqua", "#00FFFF"},
                {"aquamarine", "#7FFFD4"},
                {"apricot", "#EB9373"},
                {"arapawa", "#1A2421"},
                {"azure", "#F0FFFF"},
                {"azureradiance", "#007FFF"},
                {"aquaisland", "#A1DAD7"},
                {"bayofmany", "#273A3E"},
                {"beige", "#F5F5DC"},
                {"bisque", "#FFE4C4"},
                {"black", "#000000"},
                {"blanchedalmond", "#FFEBCD"},
                {"blue", "#0000FF"},
                {"blueribbon", "#0066FF"},
                {"blueviolet", "#8A2BE2"},
                {"brown", "#A52A2A"},
                {"burlywood", "#DEB887"},
                {"buttercup", "#F3AD16"},
                {"cadetblue", "#5F9EA0"},
                {"cannonpink", "#8E5164"},
                {"carnation", "#F95A61"},
                {"carrotorange", "#ED9121"},
                {"casal", "#2E2F30"},
                {"ceruleanblue", "#2A52BE"},
                {"chartreuse", "#7FFF00"},
                {"chino", "#D2B7AD"},
                {"chocolate", "#D2691E"},
                {"christine", "#E1634F"},
                {"coral", "#FF7F50"},
                {"cornflowerblue", "#6495ED"},
                {"cornsilk", "#FFF8DC"},
                {"creamcan", "#F5C71A"},
                {"crimson", "#DC143C"},
                {"cyan", "#00FFFF"},
                {"daisybush", "#4F2398"},
                {"darkblue", "#00008B"},
                {"darkcyan", "#008B8B"},
                {"darkfern", "#0A6906"},
                {"darkgoldenrod", "#B8860B"},
                {"darkgray", "#A9A9A9"},
                {"darkgrey", "#A9A9A9"},
                {"darkgreen", "#006400"},
                {"darkindigo", "#4B0082"},
                {"darkkhaki", "#BDB76B"},
                {"darkmagenta", "#8B008B"},
                {"darkolivegreen", "#556B2F"},
                {"darkorange", "#FF8C00"},
                {"darkorchid", "#9932CC"},
                {"darkred", "#8B0000"},
                {"darksalmon", "#E9967A"},
                {"darkseagreen", "#8FBC8F"},
                {"darkslateblue", "#483D8B"},
                {"darkslategray", "#2F4F4F"},
                {"darkslategrey", "#2F4F4F"},
                {"darkturquoise", "#00CED1"},
                {"darkviolet", "#9400D3"},
                {"deeppink", "#FF1493"},
                {"deepskyblue", "#00BFFF"},
                {"dimgray", "#696969"},
                {"dimgrey", "#696969"},
                {"diserria", "#DAA520"},
                {"dodgerblue", "#1E90FF"},
                {"domino", "#8A2008"},
                {"dulllavender", "#A899E6"},
                {"eastside", "#AC91CE"},
                {"elm", "#027877"},
                {"everglade", "#1A2421"},
                {"fern", "#4F7942"},
                {"firebrick", "#B22222"},
                {"fieryorange", "#A24510"},
                {"floralwhite", "#FFFAF0"},
                {"forestgreen", "#228B22"},
                {"frenchrose", "#F64A8A"},
                {"fruitsalad", "#4F9D5D"},
                {"fuchsia", "#FF00FF"},
                {"gainsboro", "#DCDCDC"},
                {"ghostwhite", "#F8F8FF"},
                {"gladegreen", "#4A6B4E"},
                {"gold", "#FFD700"},
                {"goldengrass", "#D9B612"},
                {"goldenrod", "#DAA520"},
                {"gondola", "#211916"},
                {"gray", "#808080"},
                {"grey", "#808080"},
                {"grannysmithapple", "#A8E4A0"},
                {"green", "#008000"},
                {"greenyellow", "#ADFF2F"},
                {"gunsmoke", "#828685"},
                {"hawaiiantan", "#9D5616"},
                {"hemlock", "#5E5D3B"},
                {"hibiscus", "#AE4560"},
                {"honeydew", "#F0FFF0"},
                {"hopbush", "#D5853E"},
                {"hotpink", "#FF69B4"},
                {"indianred", "#CD5C5C"},
                {"indigo", "#4B0082"},
                {"ivory", "#FFFFF0"},
                {"jaffa", "#EF8633"},
                {"java", "#32303D"},
                {"khaki", "#F0E68C"},
                {"lavender", "#E6E6FA"},
                {"lavenderblush", "#FFF0F5"},
                {"lawngreen", "#7CFC00"},
                {"lemonchiffon", "#FFFACD"},
                {"lightblue", "#ADD8E6"},
                {"lightcoral", "#F08080"},
                {"lightcyan", "#E0FFFF"},
                {"lightgoldenrodyellow", "#FAFAD2"},
                {"lightgray", "#D3D3D3"},
                {"lightgrey", "#D3D3D3"},
                {"lightgreen", "#90EE90"},
                {"lightorchid", "#E29CD2"},
                {"lightpink", "#FFB6C1"},
                {"lightsalmon", "#FFA07A"},
                {"lightseagreen", "#20B2AA"},
                {"lightskyblue", "#87CEFA"},
                {"lightslategray", "#778899"},
                {"lightslategrey", "#778899"},
                {"lightsteelblue", "#B0C4DE"},
                {"lightyellow", "#FFFFE0"},
                {"lime", "#00FF00"},
                {"limegreen", "#32CD32"},
                {"linen", "#FAF0E6"},
                {"lunargreen", "#3A7D02"},
                {"luckypoint", "#202078"},
                {"magenta", "#FF00FF"},
                {"mandy", "#D57C6B"},
                {"maroon", "#800000"},
                {"mediumaquamarine", "#66CDAA"},
                {"mediumblue", "#0000CD"},
                {"mediumorchid", "#BA55D3"},
                {"mediumpurple", "#9370DB"},
                {"mediumseagreen", "#3CB371"},
                {"mediumslateblue", "#7B68EE"},
                {"mediumspringgreen", "#00FA9A"},
                {"mediumturquoise", "#48D1CC"},
                {"mediumvioletred", "#C71585"},
                {"mexicanred", "#A72525"},
                {"midnightblue", "#191970"},
                {"mintcream", "#F5FFFA"},
                {"mineshaft", "#323232"},
                {"mistyrose", "#FFE4E1"},
                {"moccasin", "#FFE4B5"},
                {"mondo", "#4A3C30"},
                {"montecarlo", "#78A39C"},
                {"nandor", "#4B3D2A"},
                {"navajowhite", "#FFDEAD"},
                {"navy", "#000080"},
                {"ochre", "#C77434"},
                {"oldlace", "#FDF5E6"},
                {"olive", "#808000"},
                {"olivedrab", "#6B8E23"},
                {"orange", "#FFA500"},
                {"orangepeel", "#FFA500"},
                {"orangered", "#FF4500"},
                {"orchid", "#DA70D"},
                {"palegoldenrod", "#EEE8AA"},
                {"palegreen", "#98FB98"},
                {"paleturquoise", "#AFEEEE"},
                {"palevioletred", "#DB7093"},
                {"papayawhip", "#FFEFD5"},
                {"paradiso", "#35A793"},
                {"peachpuff", "#FFDAB9"},
                {"perano", "#7F7F7F"},
                {"peru", "#CD853F"},
                {"pewter", "#96A8A1"},
                {"pictonblue", "#45B1E8"},
                {"pink", "#FFC0CB"},
                {"plum", "#DDA0DD"},
                {"powderblue", "#B0E0E6"},
                {"puertorico", "#3B69D6"},
                {"pumice", "#C2CAC4"},
                {"purple", "#800080"},
                {"purpleheart", "#69359C"},
                {"rebeccapurple", "#663399"},
                {"red", "#FF0000"},
                {"reddamask", "#DA6A41"},
                {"riptide", "#8BE6D8"},
                {"riverbed", "#434A59"},
                {"rosybrown", "#BC8F8F"},
                {"royalblue", "#4169E1"},
                {"royalpurple", "#6B3FA0"},
                {"saddlebrown", "#8B4513"},
                {"sage", "#9EAD3D"},
                {"salmon", "#FA8072"},
                {"sandybrown", "#F4A460"},
                {"sanjuan", "#334E75"},
                {"seagreen", "#2E8B57"},
                {"seashell", "#FFF5EE"},
                {"seance", "#721757"},
                {"shiraz", "#B52D42"},
                {"sienna", "#A0522D"},
                {"silver", "#C0C0C0"},
                {"skyblue", "#87CEEB"},
                {"slateblue", "#6A5ACD"},
                {"slategray", "#708090"},
                {"slategrey", "#708090"},
                {"snow", "#FFFAFA"},
                {"springgreen", "#00FF7F"},
                {"steelblue", "#4682B4"},
                {"studio", "#714AB2"},
                {"sunglo", "#E16865"},
                {"tan", "#D2B48C"},
                {"teal", "#008080"},
                {"terracotta", "#E2725B"},
                {"thistle", "#D8BFD8"},
                {"thunderbird", "#C02B18"},
                {"tiamaria", "#C1440E"},
                {"tobaccobrown", "#715D47"},
                {"gladegreen", "#4A6B4E"},
                {"tomato", "#FF6347"},
                {"tomthumb", "#273E33"},
                {"totempole", "#991B07"},
                {"turquoise", "#40E0D0"},
                {"vesuvius", "#AD975A"},
                {"violet", "#EE82EE"},
                {"waikawagray", "#5D7291"},
                {"waikawagrey", "#5D7291"},
                {"wheat", "#F5DEB3"},
                {"white", "#FFFFFF"},
                {"whitesmoke", "#F5F5F5"},
                {"yuma", "#CFAB7A"},
                {"yellow", "#FFFF00"},
                {"yellowgreen", "#9ACD32"}};

        return &colors;
    }

    const std::string getHexColorCodeFromHtmlColorName(const std::string& htmlColorName) {
        const std::map<std::string, std::string>* colors = colorData();
        auto color = colors->find(htmlColorName.c_str());
        if (color == colors->end()) {
            return "";
        }
        return color->first;
    }

    const std::string getHtmlColorNameFromHexColorCode(const std::string& hexColorCode) {
        const std::map<std::string, std::string>* colors = colorData();
        for (auto color = colors->begin(); color != colors->end(); color++) {
            if (stringCompare(color->second, hexColorCode)) {
                return color->first;
            }
        }
        return "";
    }

    const bool isValidHexColorCode(const std::string& value) {
        if ((value.size() != 7 && value.size() != 9)  || value.at(0) != '#')
            return false;

        for (unsigned int i = 1; i < value.size(); i++) {
            if (!isxdigit(value.at(i)))
                return false;
        }

        return true;
    }

    const bool isxdigit(const char& c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
    }

    const bool isValidColorValue(const std::string& value) {
        const std::map<std::string, std::string>* colors = colorData();
        if (colors->find(value.c_str()) != colors->end()) {
            return true;
        }
        return isValidHexColorCode(value);
    }

}