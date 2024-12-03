#include "libsbmlnetwork_hide_elements.h"
#include "../../libsbmlnetwork_sbmldocument_layout.h"
#include "../../libsbmlnetwork_layout.h"
#include "../../libsbmlnetwork_sbmldocument_render.h"
#include "../../libsbmlnetwork_render.h"
#include "../../libsbmlnetwork_render_helpers.h"
#include "../../features/colors/libsbmlnetwork_colors.h"
#include "../../features/set_layout_features/libsbmlnetwork_set_layout_features.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

int hide_elements_makeVisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_makeCompartmentVisible(document, layoutIndex))
        return -1;
    if (hide_elements_makeSpeciesVisible(document, layoutIndex))
        return -1;
    if (hide_elements_makeReactionVisible(document, layoutIndex))
        return -1;

    return 0;
}

int hide_elements_makeInvisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_makeCompartmentInvisible(document, layoutIndex))
        return -1;
    if (hide_elements_makeSpeciesInvisible(document, layoutIndex))
        return -1;
    if (hide_elements_makeReactionInvisible(document, layoutIndex))
        return -1;

    return 0;
}

int hide_elements_makeCompartmentVisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_make2DGraphicalObjectVisible(document, getStyleByType(getGlobalRenderInformation(document), getCompartmentGlyphStyleType())) ||
        hide_elements_makeTextVisible(document, getStyleByType(getGlobalRenderInformation(document), getCompartmentGlyphTextGlyphStyleType())))
        return -1;

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            hide_elements_makeGraphicalObjectLocalStyleVisible(document, localRenderInformation, layout->getCompartmentGlyph(i));
    }

    return 0;
}

int hide_elements_makeCompartmentInvisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_make2DGraphicalObjectInvisible(document, getStyleByType(getGlobalRenderInformation(document), getCompartmentGlyphStyleType())) ||
        hide_elements_makeTextInvisible(document, getStyleByType(getGlobalRenderInformation(document), getCompartmentGlyphTextGlyphStyleType())))
        return -1;

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++)
            hide_elements_makeGraphicalObjectLocalStyleInvisible(document, localRenderInformation, layout->getCompartmentGlyph(i));
    }

    return 0;
}

int hide_elements_makeSpeciesVisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_make2DGraphicalObjectVisible(document, getStyleByType(getGlobalRenderInformation(document), getSpeciesGlyphStyleType())) ||
        hide_elements_makeTextVisible(document, getStyleByType(getGlobalRenderInformation(document), getSpeciesGlyphTextGlyphStyleType())))
        return -1;

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            hide_elements_makeGraphicalObjectLocalStyleVisible(document, localRenderInformation, layout->getSpeciesGlyph(i));
    }

    return 0;
}

int hide_elements_makeSpeciesInvisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_make2DGraphicalObjectInvisible(document, getStyleByType(getGlobalRenderInformation(document), getSpeciesGlyphStyleType())) ||
        hide_elements_makeTextInvisible(document, getStyleByType(getGlobalRenderInformation(document), getSpeciesGlyphTextGlyphStyleType())))
        return -1;

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            hide_elements_makeGraphicalObjectLocalStyleInvisible(document, localRenderInformation, layout->getSpeciesGlyph(i));
    }

    return 0;
}

int hide_elements_makeReactionVisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_make2DGraphicalObjectVisible(document, getStyleByType(getGlobalRenderInformation(document), getReactionGlyphStyleType())))
        return -1;
    hide_elements_makeTextVisible(document, getStyleByType(getGlobalRenderInformation(document), getReactionGlyphTextGlyphStyleType()));

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++)
            hide_elements_makeGraphicalObjectLocalStyleVisible(document, localRenderInformation, layout->getReactionGlyph(i));
    }

    return hide_elements_makeSpeciesReferenceVisible(document, layoutIndex);
}

int hide_elements_makeReactionInvisible(SBMLDocument* document, unsigned int layoutIndex) {
    if (hide_elements_make2DGraphicalObjectInvisible(document, getStyleByType(getGlobalRenderInformation(document), getReactionGlyphStyleType())))
        return -1;
    hide_elements_makeTextInvisible(document, getStyleByType(getGlobalRenderInformation(document), getReactionGlyphTextGlyphStyleType()));

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++)
            hide_elements_makeGraphicalObjectLocalStyleInvisible(document, localRenderInformation, layout->getReactionGlyph(i));
    }

    return hide_elements_makeSpeciesReferenceInvisible(document, layoutIndex);
}

int hide_elements_makeSpeciesReferenceVisible(SBMLDocument* document, unsigned int layoutIndex) {
    hide_elements_make1DGraphicalObjectVisible(document, getStyleByType(getGlobalRenderInformation(document), getSpeciesReferenceGlyphStyleType()));
    std::vector<std::pair<SpeciesReferenceRole_t, std::string>> styleRoles = getStyleRoles();
    for (std::vector<std::pair<SpeciesReferenceRole_t, std::string>>::const_iterator styleRoleIt = styleRoles.cbegin(); styleRoleIt != styleRoles.cend(); styleRoleIt++)
        hide_elements_make1DGraphicalObjectVisible(document, getStyleByRole(getGlobalRenderInformation(document), styleRoleIt->second));

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                hide_elements_makeGraphicalObjectLocalStyleVisible(document, localRenderInformation, layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
        }
    }

    return hide_elements_makeLineEndingVisible(document, layoutIndex);
}

int hide_elements_makeSpeciesReferenceInvisible(SBMLDocument* document, unsigned int layoutIndex) {
    hide_elements_make1DGraphicalObjectInvisible(document, getStyleByType(getGlobalRenderInformation(document), getSpeciesReferenceGlyphStyleType()));
    std::vector<std::pair<SpeciesReferenceRole_t, std::string>> styleRoles = getStyleRoles();
    for (std::vector<std::pair<SpeciesReferenceRole_t, std::string>>::const_iterator styleRoleIt = styleRoles.cbegin(); styleRoleIt != styleRoles.cend(); styleRoleIt++)
        hide_elements_make1DGraphicalObjectInvisible(document, getStyleByRole(getGlobalRenderInformation(document),
                                                                              styleRoleIt->second));

    Layout* layout = getLayout(document, layoutIndex);
    LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, layoutIndex);
    if (layout && localRenderInformation) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++)
                hide_elements_makeGraphicalObjectLocalStyleInvisible(document, localRenderInformation, layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
        }
    }

    return hide_elements_makeLineEndingInvisible(document, layoutIndex);
}

int hide_elements_makeLineEndingVisible(SBMLDocument* document, unsigned int layoutIndex) {
    for (unsigned int renderIndex = 0; renderIndex < getNumLocalRenderInformation(document, layoutIndex); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getLocalRenderInformation(document, lineEndingIndex, renderIndex)); lineEndingIndex++) {
            if (hide_elements_makeLineEndingVisible(document, getLineEnding(getLocalRenderInformation(document, lineEndingIndex, renderIndex), lineEndingIndex)))
                return -1;
        }
    }
    for (unsigned int renderIndex = 0; renderIndex < getNumGlobalRenderInformation(document); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getGlobalRenderInformation(document, renderIndex)); lineEndingIndex++) {
            if (hide_elements_makeLineEndingVisible(document, getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex)))
                return -1;
        }
    }

    return 0;
}

int hide_elements_makeLineEndingInvisible(SBMLDocument* document, unsigned int layoutIndex) {
    for (unsigned int renderIndex = 0; renderIndex < getNumLocalRenderInformation(document, layoutIndex); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getLocalRenderInformation(document, lineEndingIndex, renderIndex)); lineEndingIndex++) {
            if (hide_elements_makeLineEndingInvisible(document, getLineEnding(getLocalRenderInformation(document, lineEndingIndex, renderIndex), lineEndingIndex)))
                return -1;
        }
    }
    for (unsigned int renderIndex = 0; renderIndex < getNumGlobalRenderInformation(document); renderIndex++) {
        for (unsigned int lineEndingIndex = 0; lineEndingIndex < getNumLineEndings(getGlobalRenderInformation(document, renderIndex)); lineEndingIndex++) {
            if (hide_elements_makeLineEndingInvisible(document, getLineEnding(getGlobalRenderInformation(document, renderIndex), lineEndingIndex)))
                return -1;
        }
    }

    return 0;
}

int hide_elements_makeGraphicalObjectLocalStyleVisible(SBMLDocument* document, LocalRenderInformation* localRenderInformation, GraphicalObject* graphicalObject) {
    Style* style = getStyleById(localRenderInformation, graphicalObject);
    if (style) {
        if (isSpeciesReferenceGlyph(graphicalObject)) {
            if (hide_elements_make1DGraphicalObjectVisible(document, style))
                return -1;
        }
        else {
            if (hide_elements_make2DGraphicalObjectVisible(document, style))
                return -1;
        }
    }
    std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), graphicalObject);
    for (unsigned int j = 0; j < textGlyphs.size(); j++) {
        style = getStyleById(localRenderInformation, textGlyphs.at(j));
        if (style) {
            if (hide_elements_makeTextVisible(document, style))
                return -1;
        }
    }

    return 0;
}

int hide_elements_makeGraphicalObjectLocalStyleInvisible(SBMLDocument* document, LocalRenderInformation* localRenderInformation, GraphicalObject* graphicalObject) {
    Style* style = getStyleById(localRenderInformation, graphicalObject);
    if (style) {
        if (isSpeciesReferenceGlyph(graphicalObject)) {
            if (hide_elements_make1DGraphicalObjectInvisible(document, style))
                return -1;
        }
        else {
            if (hide_elements_make2DGraphicalObjectInvisible(document, style))
                return -1;
        }
    }
    std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), graphicalObject);
    for (unsigned int j = 0; j < textGlyphs.size(); j++) {
        style = getStyleById(localRenderInformation, textGlyphs.at(j));
        if (style) {
            if (hide_elements_makeTextInvisible(document, style))
                return -1;
        }
    }

    return 0;
}

int hide_elements_makeVisible(SBMLDocument* document, GraphicalObject* graphicalObject, const bool& applyToConnectedElements) {
    if (isCompartmentGlyph(graphicalObject))
        return hide_elements_makeCompartmentGlyphVisible(document, (CompartmentGlyph*)graphicalObject);
    else if (isSpeciesGlyph(graphicalObject))
        return hide_elements_makeSpeciesGlyphVisible(document, (SpeciesGlyph*)graphicalObject, applyToConnectedElements);
    else if (isReactionGlyph(graphicalObject))
        return hide_elements_makeReactionGlyphVisible(document, (ReactionGlyph*)graphicalObject, applyToConnectedElements);

    return -1;
}

int hide_elements_makeInvisible(SBMLDocument* document, GraphicalObject* graphicalObject, const bool& applyToConnectedElements) {
    if (isCompartmentGlyph(graphicalObject))
        return hide_elements_makeCompartmentGlyphInvisible(document, (CompartmentGlyph*)graphicalObject);
    else if (isSpeciesGlyph(graphicalObject))
        return hide_elements_makeSpeciesGlyphInvisible(document, (SpeciesGlyph*)graphicalObject, applyToConnectedElements);
    else if (isReactionGlyph(graphicalObject))
        return hide_elements_makeReactionGlyphInvisible(document, (ReactionGlyph*)graphicalObject, applyToConnectedElements);

    return -1;
}

int hide_elements_makeCompartmentGlyphVisible(SBMLDocument* document, CompartmentGlyph* compartmentGlyph) {
    if (compartmentGlyph) {
        Style* style = getLocalStyle(document, compartmentGlyph);
        if (!style)
            style = createLocalStyle(document, compartmentGlyph);
        hide_elements_make2DGraphicalObjectVisible(document, style);
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), compartmentGlyph);
        for (std::vector<TextGlyph*>::const_iterator textGlyphIt = textGlyphs.cbegin(); textGlyphIt != textGlyphs.cend(); textGlyphIt++)
            hide_elements_makeTextGlyphVisible(document, *textGlyphIt, compartmentGlyph);
        return 0;
    }

    return -1;
}

int hide_elements_makeCompartmentGlyphInvisible(SBMLDocument* document, CompartmentGlyph* compartmentGlyph) {
    if (compartmentGlyph) {
        Style* style = getLocalStyle(document, compartmentGlyph);
        if (!style)
            style = createLocalStyle(document, compartmentGlyph);
        hide_elements_make2DGraphicalObjectInvisible(document, style);
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), compartmentGlyph);
        for (std::vector<TextGlyph*>::const_iterator textGlyphIt = textGlyphs.cbegin(); textGlyphIt != textGlyphs.cend(); textGlyphIt++)
            hide_elements_makeTextGlyphInvisible(document, *textGlyphIt, compartmentGlyph);
        return 0;
    }

    return -1;
}

int hide_elements_makeSpeciesGlyphVisible(SBMLDocument* document, SpeciesGlyph* speciesGlyph, const bool applyToConnectedElements) {
    if (speciesGlyph) {
        Style* style = getLocalStyle(document, speciesGlyph);
        if (!style)
            style = createLocalStyle(document, speciesGlyph);
        hide_elements_make2DGraphicalObjectVisible(document, style);
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), speciesGlyph);
        for (std::vector<TextGlyph*>::const_iterator textGlyphIt = textGlyphs.cbegin(); textGlyphIt != textGlyphs.cend(); textGlyphIt++)
            hide_elements_makeTextGlyphVisible(document, *textGlyphIt, speciesGlyph);
        if (applyToConnectedElements) {
            std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = set_layout_features_getConnectedSpeciesGlyphReferences(getLayout(document), speciesGlyph);
            for (std::vector<SpeciesReferenceGlyph*>::const_iterator speciesReferenceGlyphIt = speciesReferenceGlyphs.cbegin(); speciesReferenceGlyphIt != speciesReferenceGlyphs.cend(); speciesReferenceGlyphIt++) {
                if (hide_elements_makeSpeciesReferenceGlyphVisible(document, *speciesReferenceGlyphIt))
                    return -1;
            }
        }

        return 0;
    }

    return -1;
}

int hide_elements_makeSpeciesGlyphInvisible(SBMLDocument* document, SpeciesGlyph* speciesGlyph, const bool applyToConnectedElements) {
    if (speciesGlyph) {
        Style* style = getLocalStyle(document, speciesGlyph);
        if (!style)
            style = createLocalStyle(document, speciesGlyph);
        hide_elements_make2DGraphicalObjectInvisible(document, style);
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), speciesGlyph);
        for (std::vector<TextGlyph*>::const_iterator textGlyphIt = textGlyphs.cbegin(); textGlyphIt != textGlyphs.cend(); textGlyphIt++)
            hide_elements_makeTextGlyphInvisible(document, *textGlyphIt, speciesGlyph);
        if (applyToConnectedElements) {
            std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs = set_layout_features_getConnectedSpeciesGlyphReferences(getLayout(document), speciesGlyph);
            for (std::vector<SpeciesReferenceGlyph*>::const_iterator speciesReferenceGlyphIt = speciesReferenceGlyphs.cbegin(); speciesReferenceGlyphIt != speciesReferenceGlyphs.cend(); speciesReferenceGlyphIt++) {
                if (hide_elements_makeSpeciesReferenceGlyphInvisible(document, *speciesReferenceGlyphIt))
                    return -1;
            }
        }

        return 0;
    }

    return -1;
}

int hide_elements_makeReactionGlyphVisible(SBMLDocument* document, ReactionGlyph* reactionGlyph, const bool applyToConnectedElements) {
    if (reactionGlyph) {
        Style* style = getLocalStyle(document, reactionGlyph);
        if (!style)
            style = createLocalStyle(document, reactionGlyph);
        hide_elements_make2DGraphicalObjectVisible(document, style);
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), reactionGlyph);
        for (std::vector<TextGlyph*>::const_iterator textGlyphIt = textGlyphs.cbegin(); textGlyphIt != textGlyphs.cend(); textGlyphIt++)
            hide_elements_makeTextGlyphVisible(document, *textGlyphIt, reactionGlyph);
        if (applyToConnectedElements) {
            for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
                if (hide_elements_makeSpeciesReferenceGlyphVisible(document, reactionGlyph->getSpeciesReferenceGlyph(i)))
                    return -1;
        }

        return 0;
    }

    return -1;
}

int hide_elements_makeReactionGlyphInvisible(SBMLDocument* document, ReactionGlyph* reactionGlyph, const bool applyToConnectedElements) {
    if (reactionGlyph) {
        Style* style = getLocalStyle(document, reactionGlyph);
        if (!style)
            style = createLocalStyle(document, reactionGlyph);
        hide_elements_make2DGraphicalObjectInvisible(document, style);
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(getLayout(document), reactionGlyph);
        for (std::vector<TextGlyph*>::const_iterator textGlyphIt = textGlyphs.cbegin(); textGlyphIt != textGlyphs.cend(); textGlyphIt++)
            hide_elements_makeTextGlyphInvisible(document, *textGlyphIt, reactionGlyph);
        if (applyToConnectedElements) {
            for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
                if (hide_elements_makeSpeciesReferenceGlyphInvisible(document, reactionGlyph->getSpeciesReferenceGlyph(i)))
                    return -1;
        }

        return 0;
    }

    return -1;
}

int hide_elements_makeSpeciesReferenceGlyphVisible(SBMLDocument* document, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Style* style = getLocalStyle(document, speciesReferenceGlyph);
        if (!style)
            style = createLocalStyle(document, speciesReferenceGlyph);
        hide_elements_make1DGraphicalObjectVisible(document, style);
        hide_elements_makeLineEndingVisible(document, getSpeciesReferenceLocalLineEnding(document, speciesReferenceGlyph));
        return 0;
    }

    return -1;
}

int hide_elements_makeSpeciesReferenceGlyphInvisible(SBMLDocument* document, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (speciesReferenceGlyph) {
        Style* style = getLocalStyle(document, speciesReferenceGlyph);
        if (!style)
            style = createLocalStyle(document, speciesReferenceGlyph);
        hide_elements_make1DGraphicalObjectInvisible(document, style);
        hide_elements_makeLineEndingInvisible(document, getSpeciesReferenceLocalLineEnding(document, speciesReferenceGlyph));
        return 0;
    }

    return -1;
}

int hide_elements_makeTextGlyphVisible(SBMLDocument* document, TextGlyph* textGlyph, GraphicalObject* graphicalObject) {
    if (textGlyph) {
        Style* style = getLocalStyle(document, textGlyph);
        if (!style)
            style = createLocalStyle(document, textGlyph, graphicalObject);
        hide_elements_makeTextVisible(document, style);
        return 0;
    }

    return -1;
}

int hide_elements_makeTextGlyphInvisible(SBMLDocument* document, TextGlyph* textGlyph, GraphicalObject* graphicalObject) {
    if (textGlyph) {
        Style* style = getLocalStyle(document, textGlyph);
        if (!style)
            style = createLocalStyle(document, textGlyph, graphicalObject);
        hide_elements_makeTextInvisible(document, style);
        return 0;
    }

    return -1;
}

int hide_elements_makeLineEndingVisible(SBMLDocument* document, LineEnding* lineEnding) {
    if (lineEnding) {
        hide_elements_make2DGraphicalObjectVisible(document, lineEnding);
        return 0;
    }

    return -1;
}

int hide_elements_makeLineEndingInvisible(SBMLDocument* document, LineEnding* lineEnding) {
    if (lineEnding) {
        hide_elements_make2DGraphicalObjectInvisible(document, lineEnding);
        return 0;
    }

    return -1;
}

int hide_elements_make2DGraphicalObjectVisible(SBMLDocument* document, Style* style) {
    hide_elements_make1DGraphicalObjectVisible(document, style);
    std::string colorWithoutTransparency = removeTransparencyFromColorName(getFillColor(style));
    if (getGradientDefinition(document, colorWithoutTransparency)) {
        return setFillColorAsGradient(style, colorWithoutTransparency);
    }
    std::string fillColorId = addColor(document, style, colorWithoutTransparency);
    return setFillColor(style, fillColorId, getValue(document, fillColorId));
}

int hide_elements_make2DGraphicalObjectInvisible(SBMLDocument* document, Style* style) {
    hide_elements_make1DGraphicalObjectInvisible(document, style);
    std::string fillColorId = addColor(document, style, addTransparencyToColorName(getFillColor(style)));
    return setFillColor(style, fillColorId, getValue(document, fillColorId));
}

int hide_elements_make2DGraphicalObjectVisible(SBMLDocument* document, LineEnding* lineEnding) {
    hide_elements_make1DGraphicalObjectVisible(document, lineEnding);
    std::string colorWithoutTransparency = removeTransparencyFromColorName(getFillColor(getRenderGroup(lineEnding)));
    if (getGradientDefinition(document, colorWithoutTransparency))
        return setFillColorAsGradient(getRenderGroup(lineEnding), colorWithoutTransparency);
    std::string fillColorId = addColor(document, lineEnding, colorWithoutTransparency);
    return setFillColor(getRenderGroup(lineEnding), fillColorId, getValue(document, fillColorId));
}

int hide_elements_make2DGraphicalObjectInvisible(SBMLDocument* document, LineEnding* lineEnding) {
    hide_elements_make1DGraphicalObjectInvisible(document, lineEnding);
    std::string fillColorId = addColor(document, lineEnding, addTransparencyToColorName(getFillColor(getRenderGroup(lineEnding))));
    return setFillColor(getRenderGroup(lineEnding), fillColorId, getValue(document, fillColorId));
}

int hide_elements_make1DGraphicalObjectVisible(SBMLDocument* document, Style* style) {
    std::string strokeColorId = addColor(document, style, removeTransparencyFromColorName(getStrokeColor(style)));
    return setStrokeColor(style, strokeColorId, getValue(document, strokeColorId));
}

int hide_elements_make1DGraphicalObjectInvisible(SBMLDocument* document, Style* style) {
    std::string strokeColorId = addColor(document, style, addTransparencyToColorName(getStrokeColor(style)));
    return setStrokeColor(style, strokeColorId, getValue(document, strokeColorId));
}

int hide_elements_make1DGraphicalObjectVisible(SBMLDocument* document, LineEnding* lineEnding) {
    std::string strokeColorId = addColor(document, lineEnding, removeTransparencyFromColorName(getStrokeColor(getRenderGroup(lineEnding))));
    return setStrokeColor(getRenderGroup(lineEnding), strokeColorId, getValue(document, strokeColorId));
}

int hide_elements_make1DGraphicalObjectInvisible(SBMLDocument* document, LineEnding* lineEnding) {
    std::string strokeColorId = addColor(document, lineEnding, addTransparencyToColorName(getStrokeColor(getRenderGroup(lineEnding))));
    return setStrokeColor(getRenderGroup(lineEnding), strokeColorId, getValue(document, strokeColorId));
}

int hide_elements_makeTextVisible(SBMLDocument* document, Style* style) {
    std::string fontColorId = addColor(document, style, removeTransparencyFromColorName(getFontColor(style)));
    return setFontColor(style, fontColorId, getValue(document, fontColorId));
}

int hide_elements_makeTextInvisible(SBMLDocument* document, Style* style) {
    std::string fontColorId = addColor(document, style, addTransparencyToColorName(getFontColor(style)));
    return setFontColor(style, fontColorId, getValue(document, fontColorId));
}

}
