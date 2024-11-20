#include "libsbmlnetwork_align_element.h"
#include "../../libsbmlnetwork_common.h"
#include "../../features/error_log/libsbmlnetwork_error_log.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

    const bool align_elements_isValidAlignment(const std::string& alignment, SBase* sBase) {
        if (isValueValid(alignment, align_elements_getValidAlignmentValues()))
            return true;

        error_log_addErrorToLog(sBase, error_log_createErrorMessage(alignment, align_elements_getValidAlignmentValues()));
        return false;
    }

    const bool align_elements_isValidDistributionDirection(const std::string& direction, SBase* sBase) {
        if (isValueValid(direction, align_elements_getValidDistributionDirectionValues()))
            return true;

        error_log_addErrorToLog(sBase, error_log_createErrorMessage(direction, align_elements_getValidDistributionDirectionValues()));
        return false;
    }

    std::vector<std::string> align_elements_getValidAlignmentValues() {
        std::vector <std::string> alignmentValues;
        alignmentValues.push_back("top");
        alignmentValues.push_back("vCenter");
        alignmentValues.push_back("bottom");
        alignmentValues.push_back("left");
        alignmentValues.push_back("hCenter");
        alignmentValues.push_back("right");
        alignmentValues.push_back("circular");

        return alignmentValues;
    }

    std::vector<std::string> align_elements_getValidDistributionDirectionValues() {
        std::vector <std::string> distributionDirectionValues;
        distributionDirectionValues.push_back("horizontal");
        distributionDirectionValues.push_back("vertical");

        return distributionDirectionValues;
    }

}
