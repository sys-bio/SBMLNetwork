#include "libsbmlnetwork_error_log.h"
#include "../../libsbmlnetwork_layout_helpers.h"
#include "../../libsbmlnetwork_sbmldocument_helpers.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_sbmldocument_layout.h"
#include "../../libsbmlnetwork_render.h"
#include "../../libsbmlnetwork_render_helpers.h"
#include "../../libsbmlnetwork_sbmldocument_render.h"
#include "../../libsbmlnetwork_layout_render.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

const std::string el_getErrorLog(SBMLDocument* document) {
    std::string errorLog = "";
    if (document) {
        errorLog = el_prepareErrorMessage(getUserData(document, "error_log"), errorLog);
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        errorLog += el_prepareErrorMessage(el_getErrorLog(listOfLayouts), errorLog);
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++) {
            Layout* layout = getLayout(document, i);
            errorLog += el_prepareErrorMessage(el_getErrorLog(layout), errorLog);
            const int numLocalRenderInformation = getNumLocalRenderInformation(layout);
            for (int j = 0; j < numLocalRenderInformation; j++)
                errorLog += el_prepareErrorMessage(el_getErrorLog(getLocalRenderInformation(layout, j)), errorLog);

        }
        const int numGlobalRenderInformation = getNumGlobalRenderInformation(document);
        for (int i = 0; i < numGlobalRenderInformation; i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(getGlobalRenderInformation(document, i)), errorLog);
    }

    return errorLog;
}

void el_clearErrorLog(SBMLDocument* document) {
    if (document) {
        setUserData(document, "error_log", "");
        ListOfLayouts* listOfLayouts = getListOfLayouts(document);
        el_clearErrorLog(listOfLayouts);
        const int numLayouts = getNumLayouts(document);
        for (int i = 0; i < numLayouts; i++) {
            Layout* layout = getLayout(document, i);
            el_clearErrorLog(layout);
            const int numLocalRenderInformation = getNumLocalRenderInformation(layout);
            for (int j = 0; j < numLocalRenderInformation; j++)
                el_clearErrorLog(getLocalRenderInformation(layout, j));
        }
        const int numGlobalRenderInformation = getNumGlobalRenderInformation(document);
        for (int i = 0; i < numGlobalRenderInformation; i++)
            el_clearErrorLog(getGlobalRenderInformation(document, i));
    }
}

const std::string el_getErrorLog(Layout* layout) {
    std::string errorLog = "";
    if (layout) {
        errorLog += el_prepareErrorMessage(getUserData(layout, "error_log"), errorLog);
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(layout->getCompartmentGlyph(i)), errorLog);
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(layout->getSpeciesGlyph(i)), errorLog);
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            errorLog += el_prepareErrorMessage(el_getErrorLog(layout->getReactionGlyph(i)), errorLog);
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                errorLog += el_prepareErrorMessage(el_getErrorLog(layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j)), errorLog);
        }
        for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(layout->getTextGlyph(i)), errorLog);
    }

    return errorLog;
}

void el_clearErrorLog(Layout* layout) {
    if (layout) {
        setUserData(layout, "error_log", "");
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            el_clearErrorLog(layout->getCompartmentGlyph(i));
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            el_clearErrorLog(layout->getSpeciesGlyph(i));
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            el_clearErrorLog(layout->getReactionGlyph(i));
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                el_clearErrorLog(layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
        }
        for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++)
            el_clearErrorLog(layout->getTextGlyph(i));
    }
}

const std::string el_getErrorLog(GraphicalObject* graphicalObject) {
    std::string errorLog = "";
    if (graphicalObject)
        errorLog += el_prepareErrorMessage(getUserData(graphicalObject, "error_log"), errorLog);
    if (graphicalObject->getBoundingBox())
        errorLog += el_prepareErrorMessage(el_getErrorLog(graphicalObject->getBoundingBox()), errorLog);
    if (isSetCurve(graphicalObject))
        errorLog += el_prepareErrorMessage(el_getErrorLog(getCurve(graphicalObject)), errorLog);

    return errorLog;
}

void el_clearErrorLog(GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        setUserData(graphicalObject, "error_log", "");
        if (graphicalObject->getBoundingBox())
            el_clearErrorLog(graphicalObject->getBoundingBox());
        if (isSetCurve(graphicalObject))
            el_clearErrorLog(getCurve(graphicalObject));
    }
}

const std::string el_getErrorLog(BoundingBox* boundingBox) {
    std::string errorLog = "";
    if (boundingBox)
        errorLog += el_prepareErrorMessage(getUserData(boundingBox, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(BoundingBox* boundingBox) {
    if (boundingBox)
        setUserData(boundingBox, "error_log", "");
}

const std::string el_getErrorLog(Curve* curve) {
    std::string errorLog = "";
    if (curve)
        errorLog += el_prepareErrorMessage(getUserData(curve, "error_log"), errorLog);
    for (unsigned int i = 0; i < getNumCurveSegments(curve); i++)
        errorLog += el_prepareErrorMessage(el_getErrorLog(getCurveSegment(curve, i)), errorLog);

    return errorLog;
}

void el_clearErrorLog(Curve* curve) {
    if (curve) {
        setUserData(curve, "error_log", "");
        for (unsigned int i = 0; i < getNumCurveSegments(curve); i++)
            el_clearErrorLog(getCurveSegment(curve, i));
    }
}

const std::string el_getErrorLog(LineSegment* lineSegment) {
    std::string errorLog = "";
    if (lineSegment)
        errorLog += el_prepareErrorMessage(getUserData(lineSegment, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(LineSegment* lineSegment) {
    if (lineSegment)
        setUserData(lineSegment, "error_log", "");
}

const std::string el_getErrorLog(RenderInformationBase* renderInformation) {
    std::string errorLog = "";
    if (renderInformation)
        errorLog += el_prepareErrorMessage(getUserData(renderInformation, "error_log"), errorLog);
    for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++)
        errorLog += el_prepareErrorMessage(el_getErrorLog(renderInformation->getColorDefinition(i)), errorLog);
    for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
        GradientBase* gradientBase = renderInformation->getGradientDefinition(i);
        errorLog += el_prepareErrorMessage(el_getErrorLog(gradientBase), errorLog);
        for (unsigned int j = 0; j < gradientBase->getNumGradientStops(); j++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(gradientBase->getGradientStop(j)), errorLog);
    }
    for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++)
        errorLog += el_prepareErrorMessage(el_getErrorLog(renderInformation->getLineEnding(i)), errorLog);
    if (renderInformation->isGlobalRenderInformation()) {
        for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(((GlobalRenderInformation *) renderInformation)->getGlobalStyle(i)), errorLog);
    }
    else if (renderInformation->isLocalRenderInformation()) {
        for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(((LocalRenderInformation *) renderInformation)->getLocalStyle(i)), errorLog);
    }

    return errorLog;
}

void el_clearErrorLog(RenderInformationBase* renderInformation) {
    if (renderInformation) {
        setUserData(renderInformation, "error_log", "");
        for (unsigned int i = 0; i < renderInformation->getNumColorDefinitions(); i++)
            el_clearErrorLog(renderInformation->getColorDefinition(i));
        for (unsigned int i = 0; i < renderInformation->getNumGradientDefinitions(); i++) {
            GradientBase* gradientBase = renderInformation->getGradientDefinition(i);
            el_clearErrorLog(gradientBase);
            for (unsigned int j = 0; j < gradientBase->getNumGradientStops(); j++)
                el_clearErrorLog(gradientBase->getGradientStop(j));
        }
        for (unsigned int i = 0; i < renderInformation->getNumLineEndings(); i++)
            el_clearErrorLog(renderInformation->getLineEnding(i));
        if (renderInformation->isGlobalRenderInformation()) {
            for (unsigned int i = 0; i < ((GlobalRenderInformation*)renderInformation)->getNumGlobalStyles(); i++)
                el_clearErrorLog(((GlobalRenderInformation*)renderInformation)->getGlobalStyle(i));
        }
        else if (renderInformation->isLocalRenderInformation()) {
            for (unsigned int i = 0; i < ((LocalRenderInformation*)renderInformation)->getNumLocalStyles(); i++)
                el_clearErrorLog(((LocalRenderInformation*)renderInformation)->getLocalStyle(i));
        }
    }
}

const std::string el_getErrorLog(ColorDefinition* colorDefinition) {
    std::string errorLog = "";
    if (colorDefinition)
        errorLog += el_prepareErrorMessage(getUserData(colorDefinition, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(ColorDefinition* colorDefinition) {
    if (colorDefinition)
        setUserData(colorDefinition, "error_log", "");
}

const std::string el_getErrorLog(GradientBase* gradientBase) {
    std::string errorLog = "";
    if (gradientBase)
        errorLog += el_prepareErrorMessage(getUserData(gradientBase, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(GradientBase* gradientBase) {
    if (gradientBase)
        setUserData(gradientBase, "error_log", "");
}

const std::string el_getErrorLog(GradientStop* gradientStop) {
    std::string errorLog = "";
    if (gradientStop)
        errorLog += el_prepareErrorMessage(getUserData(gradientStop, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(GradientStop* gradientStop) {
    if (gradientStop)
        setUserData(gradientStop, "error_log", "");
}

const std::string el_getErrorLog(LineEnding* lineEnding) {
    std::string errorLog = "";
    if (lineEnding)
        errorLog += el_prepareErrorMessage(getUserData(lineEnding, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(LineEnding* lineEnding) {
    if (lineEnding)
        setUserData(lineEnding, "error_log", "");
}

const std::string el_getErrorLog(Style* style) {
    std::string errorLog = "";
    if (style) {
        errorLog += el_prepareErrorMessage(getUserData(style, "error_log"), errorLog);
        errorLog += el_prepareErrorMessage(el_getErrorLog(style->getGroup()), errorLog);
    }

    return errorLog;
}

void el_clearErrorLog(Style* style) {
    if (style) {
        setUserData(style, "error_log", "");
        el_clearErrorLog( style->getGroup());
    }
}

const std::string el_getErrorLog(RenderGroup* renderGroup) {
    std::string errorLog = "";
    if (renderGroup) {
        errorLog += el_prepareErrorMessage(getUserData(renderGroup, "error_log"), errorLog);
        for (unsigned int i = 0; i < renderGroup->getNumElements(); i++)
            errorLog += el_prepareErrorMessage(el_getErrorLog(renderGroup->getElement(i)), errorLog);
    }

    return errorLog;
}

void el_clearErrorLog(RenderGroup* renderGroup) {
    if (renderGroup) {
        setUserData(renderGroup, "error_log", "");
        for (unsigned int j = 0; j < renderGroup->getNumElements(); j++)
            el_clearErrorLog(renderGroup->getElement(j));
    }
}

const std::string el_getErrorLog(Transformation2D* transformation2D) {
    std::string errorLog = "";
    if (transformation2D)
        errorLog += el_prepareErrorMessage(getUserData(transformation2D, "error_log"), errorLog);

    return errorLog;
}

void el_clearErrorLog(Transformation2D* transformation2D) {
    if (transformation2D)
        setUserData(transformation2D, "error_log", "");
}

const std::string el_getErrorLog(SBase* sBase) {
    std::string errorLog = "";
    if (sBase)
        errorLog = el_prepareErrorMessage(getUserData(sBase, "error_log"), errorLog);

    return errorLog;

}

void el_clearErrorLog(SBase* sBase) {
    if (sBase)
        setUserData(sBase, "error_log", "");
}

const std::string el_prepareErrorMessage(const std::string& errorMessage, const std::string& errorLog) {
    std::string preparedErrorMessage = "";
    if (!errorMessage.empty()) {
        if (!errorLog.empty())
            preparedErrorMessage += "\n";

        preparedErrorMessage += errorMessage;
    }

    return preparedErrorMessage;
}

void el_addErrorToLog(SBase* sBase, const std::string& errorMessage) {
    if (sBase && !errorMessage.empty()) {
        std::string errorLog = getUserData(sBase, "error_log");
        if (!errorLog.empty())
            errorLog += "\n";
        errorLog += errorMessage;
        setUserData(sBase, "error_log", errorLog);
    }
}

}
