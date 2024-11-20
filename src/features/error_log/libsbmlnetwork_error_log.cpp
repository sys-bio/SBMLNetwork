#include "libsbmlnetwork_error_log.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_sbmldocument_layout.h"
#include "../../libsbmlnetwork_render.h"
#include "../../libsbmlnetwork_render_helpers.h"
#include "../../libsbmlnetwork_sbmldocument_render.h"
#include "../../libsbmlnetwork_layout_render.h"
#include "../../features/user_data/libsbmlnetwork_user_data.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

const std::string error_log_getErrorLog(SBMLDocument* document) {
    std::string errorLog = "";
    if (document) {
        errorLog = error_log_prepareErrorMessage(ud_getUserData(document, "error_log"), errorLog);
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(listOfLayouts), errorLog);
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++) {
            Layout* layout = getLayout(document, i);
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(layout), errorLog);
            const int numLocalRenderInformation = getNumLocalRenderInformation(layout);
            for (int j = 0; j < numLocalRenderInformation; j++)
                errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(getLocalRenderInformation(layout, j)), errorLog);

        }
        const int numGlobalRenderInformation = getNumGlobalRenderInformation(document);
        for (int i = 0; i < numGlobalRenderInformation; i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(getGlobalRenderInformation(document, i)), errorLog);
    }

    return errorLog;
}

void error_log_clearErrorLog(SBMLDocument* document) {
    if (document) {
        ud_setUserData(document, "error_log", "");
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        error_log_clearErrorLog(listOfLayouts);
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++) {
            Layout* layout = getLayout(document, i);
            error_log_clearErrorLog(layout);
            const int numLocalRenderInformation = getNumLocalRenderInformation(layout);
            for (int j = 0; j < numLocalRenderInformation; j++)
                error_log_clearErrorLog(getLocalRenderInformation(layout, j));
        }
        const int numGlobalRenderInformation = getNumGlobalRenderInformation(document);
        for (int i = 0; i < numGlobalRenderInformation; i++)
            error_log_clearErrorLog(getGlobalRenderInformation(document, i));
    }
}

const std::string error_log_getErrorLog(Layout* layout) {
    std::string errorLog = "";
    if (layout) {
        errorLog += error_log_prepareErrorMessage(ud_getUserData(layout, "error_log"), errorLog);
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(layout->getCompartmentGlyph(i)), errorLog);
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(layout->getSpeciesGlyph(i)), errorLog);
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(layout->getReactionGlyph(i)), errorLog);
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j)), errorLog);
        }
        for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(layout->getTextGlyph(i)), errorLog);
    }

    return errorLog;
}

void error_log_clearErrorLog(Layout* layout) {
    if (layout) {
        ud_setUserData(layout, "error_log", "");
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            error_log_clearErrorLog(layout->getCompartmentGlyph(i));
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            error_log_clearErrorLog(layout->getSpeciesGlyph(i));
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            error_log_clearErrorLog(layout->getReactionGlyph(i));
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                error_log_clearErrorLog(layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
        }
        for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++)
            error_log_clearErrorLog(layout->getTextGlyph(i));
    }
}

const std::string error_log_getErrorLog(GraphicalObject* graphicalObject) {
    std::string errorLog = "";
    if (graphicalObject)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(graphicalObject, "error_log"), errorLog);
    if (graphicalObject->getBoundingBox())
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(graphicalObject->getBoundingBox()), errorLog);
    if (isSetCurve(graphicalObject))
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(getCurve(graphicalObject)), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        ud_setUserData(graphicalObject, "error_log", "");
        if (graphicalObject->getBoundingBox())
            error_log_clearErrorLog(graphicalObject->getBoundingBox());
        if (isSetCurve(graphicalObject))
            error_log_clearErrorLog(getCurve(graphicalObject));
    }
}

const std::string error_log_getErrorLog(BoundingBox* boundingBox) {
    std::string errorLog = "";
    if (boundingBox)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(boundingBox, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(BoundingBox* boundingBox) {
    if (boundingBox)
        ud_setUserData(boundingBox, "error_log", "");
}

const std::string error_log_getErrorLog(Curve* curve) {
    std::string errorLog = "";
    if (curve)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(curve, "error_log"), errorLog);
    for (unsigned int i = 0; i < getNumCurveSegments(curve); i++)
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(getCurveSegment(curve, i)), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(Curve* curve) {
    if (curve) {
        ud_setUserData(curve, "error_log", "");
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++)
            error_log_clearErrorLog(getCurveSegment(curve, i));
    }
}

const std::string error_log_getErrorLog(LineSegment* lineSegment) {
    std::string errorLog = "";
    if (lineSegment)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(lineSegment, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(LineSegment* lineSegment) {
    if (lineSegment)
        ud_setUserData(lineSegment, "error_log", "");
}

const std::string error_log_getErrorLog(RenderInformationBase* renderInformation) {
    std::string errorLog = "";
    if (renderInformation)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(renderInformation, "error_log"), errorLog);
    for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++)
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(renderInformation->getColorDefinition(i)), errorLog);
    for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
        GradientBase* gradientBase = renderInformation->getGradientDefinition(i);
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(gradientBase), errorLog);
        for (unsigned int j = 0; j < gradientBase->getNumGradientStops(); j++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(gradientBase->getGradientStop(j)), errorLog);
    }
    for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++)
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(renderInformation->getLineEnding(i)), errorLog);
    if (renderInformation->isGlobalRenderInformation()) {
        for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(((GlobalRenderInformation *) renderInformation)->getGlobalStyle(i)), errorLog);
    }
    else if (renderInformation->isLocalRenderInformation()) {
        for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(((LocalRenderInformation *) renderInformation)->getLocalStyle(i)), errorLog);
    }

    return errorLog;
}

void error_log_clearErrorLog(RenderInformationBase* renderInformation) {
    if (renderInformation) {
        ud_setUserData(renderInformation, "error_log", "");
        for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++)
            error_log_clearErrorLog(renderInformation->getColorDefinition(i));
        for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
            GradientBase* gradientBase = renderInformation->getGradientDefinition(i);
            error_log_clearErrorLog(gradientBase);
            for (unsigned int j = 0; j < gradientBase->getNumGradientStops(); j++)
                error_log_clearErrorLog(gradientBase->getGradientStop(j));
        }
        for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++)
            error_log_clearErrorLog(renderInformation->getLineEnding(i));
        if (renderInformation->isGlobalRenderInformation()) {
            for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++)
                error_log_clearErrorLog(((GlobalRenderInformation*)renderInformation)->getGlobalStyle(i));
        }
        else if (renderInformation->isLocalRenderInformation()) {
            for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++)
                error_log_clearErrorLog(((LocalRenderInformation*)renderInformation)->getLocalStyle(i));
        }
    }
}

const std::string error_log_getErrorLog(ColorDefinition* colorDefinition) {
    std::string errorLog = "";
    if (colorDefinition)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(colorDefinition, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(ColorDefinition* colorDefinition) {
    if (colorDefinition)
        ud_setUserData(colorDefinition, "error_log", "");
}

const std::string error_log_getErrorLog(GradientBase* gradientBase) {
    std::string errorLog = "";
    if (gradientBase)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(gradientBase, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(GradientBase* gradientBase) {
    if (gradientBase)
        ud_setUserData(gradientBase, "error_log", "");
}

const std::string error_log_getErrorLog(GradientStop* gradientStop) {
    std::string errorLog = "";
    if (gradientStop)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(gradientStop, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(GradientStop* gradientStop) {
    if (gradientStop)
        ud_setUserData(gradientStop, "error_log", "");
}

const std::string error_log_getErrorLog(LineEnding* lineEnding) {
    std::string errorLog = "";
    if (lineEnding)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(lineEnding, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(LineEnding* lineEnding) {
    if (lineEnding)
        ud_setUserData(lineEnding, "error_log", "");
}

const std::string error_log_getErrorLog(Style* style) {
    std::string errorLog = "";
    if (style) {
        errorLog += error_log_prepareErrorMessage(ud_getUserData(style, "error_log"), errorLog);
        errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(style->getGroup()), errorLog);
    }

    return errorLog;
}

void error_log_clearErrorLog(Style* style) {
    if (style) {
        ud_setUserData(style, "error_log", "");
        error_log_clearErrorLog( style->getGroup());
    }
}

const std::string error_log_getErrorLog(RenderGroup* renderGroup) {
    std::string errorLog = "";
    if (renderGroup) {
        errorLog += error_log_prepareErrorMessage(ud_getUserData(renderGroup, "error_log"), errorLog);
        for (unsigned int i = 0; i < renderGroup->getNumElements(); i++)
            errorLog += error_log_prepareErrorMessage(error_log_getErrorLog(renderGroup->getElement(i)), errorLog);
    }

    return errorLog;
}

void error_log_clearErrorLog(RenderGroup* renderGroup) {
    if (renderGroup) {
        ud_setUserData(renderGroup, "error_log", "");
        for (unsigned int j = 0; j < renderGroup->getNumElements(); j++)
            error_log_clearErrorLog(renderGroup->getElement(j));
    }
}

const std::string error_log_getErrorLog(Transformation2D* transformation2D) {
    std::string errorLog = "";
    if (transformation2D)
        errorLog += error_log_prepareErrorMessage(ud_getUserData(transformation2D, "error_log"), errorLog);

    return errorLog;
}

void error_log_clearErrorLog(Transformation2D* transformation2D) {
    if (transformation2D)
        ud_setUserData(transformation2D, "error_log", "");
}

const std::string error_log_getErrorLog(SBase* sBase) {
    std::string errorLog = "";
    if (sBase)
        errorLog = error_log_prepareErrorMessage(ud_getUserData(sBase, "error_log"), errorLog);

    return errorLog;

}

void error_log_clearErrorLog(SBase* sBase) {
    if (sBase)
        ud_setUserData(sBase, "error_log", "");
}

const std::string error_log_prepareErrorMessage(const std::string& errorMessage, const std::string& errorLog) {
    std::string preparedErrorMessage = "";
    if (!errorMessage.empty()) {
        if (!errorLog.empty())
            preparedErrorMessage += "\n";

        preparedErrorMessage += errorMessage;
    }

    return preparedErrorMessage;
}

void error_log_addErrorToLog(SBase* sBase, const std::string& errorMessage) {
    if (sBase && !errorMessage.empty()) {
        std::string errorLog = ud_getUserData(sBase, "error_log");
        if (!errorLog.empty())
            errorLog += "\n";
        errorLog += errorMessage;
        ud_setUserData(sBase, "error_log", errorLog);
    }
}

}
