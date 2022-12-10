#ifndef __LIBSBML_NE_COMMON_H_
#define __LIBSBML_NE_COMMON_H_

#define LIBSBML_NETWORKEDITOR_EXTERN
# if defined (_WIN32)
    #if(LIBSBML_NETWORKEDITOR_EXPORTS)
        #define LIBSBML_NETWORKEDITOR_EXTERN __declspec(dllexport)
    #else
        #define LIBSBML_NETWORKEDITOR_EXTERN __declspec(dllimport)
    #endif
#endif

#endif

