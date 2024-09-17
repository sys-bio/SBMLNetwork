#ifndef __LIBSBMLNETWORK_COLORS_H
#define __LIBSBMLNETWORK_COLORS_H

#include <cstdlib>
#include <string>
#include <vector>
#include <map>

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    const std::map<std::string, std::string>* colorData();

    const std::string getHexColorCodeFromHtmlColorName(const std::string& htmlColorName);

    const std::string getHtmlColorNameFromHexColorCode(const std::string& hexColorCode);

    const bool isValidHexColorCode(const std::string& value);

    const bool isxdigit(const char& c);

    const bool isValidColorValue(const std::string& value);
}

#endif
