#ifndef __LIBSBMLNETWORK_ALIGN_ELEMENT_H
#define __LIBSBMLNETWORK_ALIGN_ELEMENT_H

#ifndef SWIG
#include "sbml/SBMLTypes.h"
#endif

using namespace libsbml;


namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    const bool align_elements_isValidAlignment(const std::string& alignment, SBase* sBase = NULL);

    const bool align_elements_isValidDistributionDirection(const std::string& direction, SBase* sBase = NULL);

    std::vector<std::string> align_elements_getValidAlignmentValues();

    std::vector<std::string> align_elements_getValidDistributionDirectionValues();
}

#endif
