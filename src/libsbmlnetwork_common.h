#ifndef __LIBSBMLNETWORK_COMMON_H_
#define __LIBSBMLNETWORK_COMMON_H_

# if defined (_WIN32)
    #if(LIBSBMLNETWORK_EXPORTS)
        #define LIBSBMLNETWORK_EXTERN __declspec(dllexport)
    #else
        #define LIBSBMLNETWORK_EXTERN __declspec(dllimport)
    #endif
# else
#define LIBSBMLNETWORK_EXTERN
#endif

#include <iostream>
#include <vector>
#include <set>

 const std::string getLibraryVersion();

const std::string getLibraryDirectory();

bool compareChar(const char& c1, const char& c2);

bool stringCompare(const std::string& str1, const std::string& str2);

std::string toLowerCase(const std::string& str);

bool isValueValid(const std::string& value, const std::vector<std::string>& validValues);

const double roundToTwoDecimalPlaces(const double& value);

#endif

