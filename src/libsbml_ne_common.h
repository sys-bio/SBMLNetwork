#ifndef __LIBSBML_NE_COMMON_H_
#define __LIBSBML_NE_COMMON_H_

# if defined (_WIN32)
    #if(LIBSBML_NETWORKEDITOR_EXPORTS)
        #define LIBSBML_NETWORKEDITOR_EXTERN __declspec(dllexport)
    #else
        #define LIBSBML_NETWORKEDITOR_EXTERN __declspec(dllimport)
    #endif
# else
#define LIBSBML_NETWORKEDITOR_EXTERN
#endif

#include <iostream>

LIBSBML_NETWORKEDITOR_EXTERN const std::string getLibraryVersion();

bool compareChar(const char& c1, const char& c2);

bool stringCompare(const std::string& str1, const std::string& str2);

#endif

