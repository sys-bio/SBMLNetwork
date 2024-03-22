#include "libsbml_ne_common.h"

#ifndef LIBSBML_NETWORK_EDITOR_VERSION
#define LIBSBML_NETWORK_EDITOR_VERSION @LIBSBML_NETWORK_EDITOR_VERSION@
#endif

const std::string getLibraryVersion() {
    return LIBSBML_NETWORK_EDITOR_VERSION;
}

bool compareChar(const char& c1, const char& c2) {
        if (c1 == c2)
            return true;
        else if (std::toupper(c1) == std::toupper(c2))
            return true;
        return false;
}

bool stringCompare(const std::string& str1, const std::string& str2) {
        return ((str1.size() == str2.size()) && std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar));
}

const bool isValueValid(const std::string& value, const std::vector<std::string>& validValues) {
    for (unsigned int i = 0; i < validValues.size(); i++) {
        if (stringCompare(value, validValues[i]))
            return true;
    }

    std::cerr << createErrorMessage(value, validValues) << std::endl;
    return false;
}

std::string createErrorMessage(const std::string& value, std::vector<std::string> validValues) {
    std::string errorMessage = "error: " + value + " is not a valid value. It must be one of the following: ";
    for (unsigned int i = 0; i < validValues.size(); i++) {
        if (i != validValues.size() - 1) {
            errorMessage += validValues[i];
            errorMessage += ", ";
        } else {
            errorMessage += "or ";
            errorMessage += validValues[i];
        }
    }

    return errorMessage;
}
