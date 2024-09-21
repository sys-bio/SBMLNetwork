#include "libsbmlnetwork_layout_render.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_render.h"
#include "libsbmlnetwork_render_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE {

ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout) {
    if (layout) {
        SBasePlugin* renderBase = getRenderPlugin(layout);
        if (renderBase) {
            RenderLayoutPlugin* renderLayoutPlugin = getRenderLayoutPlugin(renderBase);
            if (renderLayoutPlugin)
                return renderLayoutPlugin->getListOfLocalRenderInformation();
        }
    }

    return NULL;
}

const unsigned int getNumLocalRenderInformation(Layout* layout) {
    return getNumLocalRenderInformation(getListOfLocalRenderInformation(layout));
}

LocalRenderInformation* getLocalRenderInformation(Layout* layout, unsigned int renderIndex) {
    return getLocalRenderInformation(getListOfLocalRenderInformation(layout), renderIndex);
}

int addLocalRenderInformation(Layout* layout, LocalRenderInformation* localRenderInformation) {
    if (localRenderInformation) {
        ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
        if (listOfLocalRenderInformation) {
            listOfLocalRenderInformation->addLocalRenderInformation(localRenderInformation);
            return 0;
        }
    }

    return -1;
}

LocalRenderInformation* createLocalRenderInformation(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->createLocalRenderInformation();

    return NULL;
}

int removeAllLocalRenderInformation(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation) {
        while(listOfLocalRenderInformation->size())
            listOfLocalRenderInformation->remove(0);
        return 0;
    }

    return -1;
}

int setDefaultLocalRenderInformationFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRenderInformation) {
    if (document && localRenderInformation) {
        localRenderInformation->setId("libSBMLNetwork_Local_Render");
        localRenderInformation->setReferenceRenderInformation("libSBMLNetwork_Global_Render");
        if (layout) {
            //addLocalStyles(layout, localRenderInformation);
            return 0;
        }
    }

    return -1;
}

int setCompartmentStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& stroke) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style* style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            addColor(localRenderInformation, stroke);
            if (setStrokeColor(style, stroke))
                return -1;
        }
    }

    return 0;
}

int setSpeciesStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& stroke) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            addColor(localRenderInformation, stroke);
            if (setStrokeColor(style, stroke))
                return -1;
        }
    }

    return 0;
}

int setReactionStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& stroke) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            addColor(localRenderInformation, stroke);
            if (setStrokeColor(style, stroke))
                return -1;
        }
    }

    return 0;
}

int setSpeciesReferenceStrokeColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& stroke) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++) {
            style = getStyleById(localRenderInformation, layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
            if (style) {
                addColor(localRenderInformation, stroke);
                if (setStrokeColor(style, stroke))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setStrokeWidth(style, width))
                return -1;
        }
    }

    return 0;
}

int setSpeciesStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setStrokeWidth(style, width))
                return -1;
        }
    }

    return 0;
}

int setReactionStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setStrokeWidth(style, width))
                return -1;
        }
    }

    return 0;
}

int setSpeciesReferenceStrokeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        for (unsigned int j = 0; j < layout->getReactionGlyph(i)->getNumSpeciesReferenceGlyphs(); j++) {
            style = getStyleById(localRenderInformation, layout->getReactionGlyph(i)->getSpeciesReferenceGlyph(j));
            if (style) {
                if (setStrokeWidth(style, width))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentFontColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontColor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontColor(style, fontColor))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesFontColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontColor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontColor(style, fontColor))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionFontColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontColor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontColor(style, fontColor))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentFontFamily(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontFamily) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontFamily(style, fontFamily))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesFontFamily(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontFamily) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontFamily(style, fontFamily))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionFontFamily(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontFamily) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontFamily(style, fontFamily))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontSize(style, fontSize))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentFontSizeAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& fontSize) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    RelAbsVector fontSizeVector;
    fontSizeVector.setAbsoluteValue(fontSize);
    return setCompartmentFontSize(layout, localRenderInformation, fontSizeVector);
}

int setSpeciesFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontSize(style, fontSize))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesFontSizeAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& fontSize) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    RelAbsVector fontSizeVector;
    fontSizeVector.setAbsoluteValue(fontSize);
    return setSpeciesFontSize(layout, localRenderInformation, fontSizeVector);
}

int setReactionFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontSize(style, fontSize))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionFontSizeAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& fontSize) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    RelAbsVector fontSizeVector;
    fontSizeVector.setAbsoluteValue(fontSize);
    return setReactionFontSize(layout, localRenderInformation, fontSizeVector);
}

int setCompartmentFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontWeight(style, fontWeight))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontWeight(style, fontWeight))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontWeight(style, fontWeight))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentFontStyle(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontStyle) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontStyle(style, fontStyle))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesFontStyle(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontStyle) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontStyle(style, fontStyle))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionFontStyle(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontStyle) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setFontStyle(style, fontStyle))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& textAnchor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setTextAnchor(style, textAnchor))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& textAnchor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setTextAnchor(style, textAnchor))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& textAnchor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setTextAnchor(style, textAnchor))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentVTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& vTextAnchor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getCompartmentGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setVTextAnchor(style, vTextAnchor))
                    return -1;
            }
        }
    }

    return 0;
}

int setSpeciesVTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& vTextAnchor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getSpeciesGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setVTextAnchor(style, vTextAnchor))
                    return -1;
            }
        }
    }

    return 0;
}

int setReactionVTextAnchor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& vTextAnchor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, layout->getReactionGlyph(i));
        for (unsigned int j = 0; j < textGlyphs.size(); j++) {
            style = getStyleById(localRenderInformation, textGlyphs.at(j));
            if (style) {
                if (setVTextAnchor(style, vTextAnchor))
                    return -1;
            }
        }
    }

    return 0;
}

int setCompartmentFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            addColor(localRenderInformation, fillColor);
            if (setFillColor(style, fillColor))
                return -1;
        }
    }

    return 0;
}

int setCompartmentFillColorAsGradient(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& gradientId) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setFillColorAsGradient(style, gradientId))
                return -1;
        }
    }

    return 0;
}

int setSpeciesFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            addColor(localRenderInformation, fillColor);
            if (setFillColor(style, fillColor))
                return -1;
        }
    }

    return 0;
}

int setSpeciesFillColorAsGradient(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& gradientId) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setFillColorAsGradient(style, gradientId))
                return -1;
        }
    }

    return 0;
}

int setReactionFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            addColor(localRenderInformation, fillColor);
            if (setFillColor(style, fillColor))
                return -1;
        }
    }

    return 0;
}

int setReactionFillColorAsGradient(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& gradientId) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setFillColorAsGradient(style, gradientId))
                return -1;
        }
    }

    return 0;
}

int setCompartmentFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setFillRule(style, fillRule))
                return -1;
        }
    }

    return 0;
}

int setSpeciesFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setFillRule(style, fillRule))
                return -1;
        }
    }

    return 0;
}

int setReactionFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setFillRule(style, fillRule))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeType(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& shape) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeType(style, shape))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeType(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& shape) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeType(style, shape))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeType(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& shape) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeType(style, shape))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeX(style, x))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& x) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    RelAbsVector xVector;
    xVector.setAbsoluteValue(x);
    return setCompartmentGeometricShapeX(layout, localRenderInformation, xVector);
}

int setSpeciesGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeX(style, x))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& x) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    RelAbsVector xVector;
    xVector.setAbsoluteValue(x);
    return setSpeciesGeometricShapeX(layout, localRenderInformation, xVector);
}

int setReactionGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeX(style, x))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& x) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    RelAbsVector xVector;
    xVector.setAbsoluteValue(x);
    return setReactionGeometricShapeX(layout, localRenderInformation, xVector);
}

int setCompartmentGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeY(style, y))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& y) {
    RelAbsVector yVector;
    yVector.setAbsoluteValue(y);
    return setCompartmentGeometricShapeY(layout, localRenderInformation, yVector);
}

int setSpeciesGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeY(style, y))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& y) {
    RelAbsVector yVector;
    yVector.setAbsoluteValue(y);
    return setSpeciesGeometricShapeY(layout, localRenderInformation, yVector);
}

int setReactionGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeY(style, y))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& y) {
    RelAbsVector yVector;
    yVector.setAbsoluteValue(y);
    return setReactionGeometricShapeY(layout, localRenderInformation, yVector);
}

int setCompartmentGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeWidth(style, width))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeWidthAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    RelAbsVector widthVector;
    widthVector.setAbsoluteValue(width);
    return setCompartmentGeometricShapeWidth(layout, localRenderInformation, widthVector);
}

int setSpeciesGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeWidth(style, width))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeWidthAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    RelAbsVector widthVector;
    widthVector.setAbsoluteValue(width);
    return setSpeciesGeometricShapeWidth(layout, localRenderInformation, widthVector);
}

int setReactionGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeWidth(style, width))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeWidthAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& width) {
    RelAbsVector widthVector;
    widthVector.setAbsoluteValue(width);
    return setReactionGeometricShapeWidth(layout, localRenderInformation, widthVector);
}

int setCompartmentGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeHeight(style, height))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeHeightAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& height) {
    RelAbsVector heightVector;
    heightVector.setAbsoluteValue(height);
    return setCompartmentGeometricShapeHeight(layout, localRenderInformation, heightVector);
}

int setSpeciesGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeHeight(style, height))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeHeightAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& height) {
    RelAbsVector heightVector;
    heightVector.setAbsoluteValue(height);
    return setSpeciesGeometricShapeHeight(layout, localRenderInformation, heightVector);
}

int setReactionGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeHeight(style, height))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeHeightAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& height) {
    RelAbsVector heightVector;
    heightVector.setAbsoluteValue(height);
    return setReactionGeometricShapeHeight(layout, localRenderInformation, heightVector);
}

int setCompartmentGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeRatio(style, ratio))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeRatio(style, ratio))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio) {
    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeRatio(style, ratio))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeCornerCurvatureRadiusX(style, radiusX))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX) {
    RelAbsVector radiusXVector;
    radiusXVector.setAbsoluteValue(radiusX);
    return setCompartmentGeometricShapeCornerCurvatureRadiusX(layout, localRenderInformation, radiusXVector);
}

int setSpeciesGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeCornerCurvatureRadiusX(style, radiusX))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX) {
    RelAbsVector radiusXVector;
    radiusXVector.setAbsoluteValue(radiusX);
    return setSpeciesGeometricShapeCornerCurvatureRadiusX(layout, localRenderInformation, radiusXVector);
}

int setReactionGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeCornerCurvatureRadiusX(style, radiusX))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX) {
    RelAbsVector radiusXVector;
    radiusXVector.setAbsoluteValue(radiusX);
    return setReactionGeometricShapeCornerCurvatureRadiusX(layout, localRenderInformation, radiusXVector);
}

int setCompartmentGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeCornerCurvatureRadiusY(style, radiusY))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY) {
    RelAbsVector radiusYVector;
    radiusYVector.setAbsoluteValue(radiusY);
    return setCompartmentGeometricShapeCornerCurvatureRadiusY(layout, localRenderInformation, radiusYVector);
}

int setSpeciesGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeCornerCurvatureRadiusY(style, radiusY))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY) {
    RelAbsVector radiusYVector;
    radiusYVector.setAbsoluteValue(radiusY);
    return setSpeciesGeometricShapeCornerCurvatureRadiusY(layout, localRenderInformation, radiusYVector);
}

int setReactionGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeCornerCurvatureRadiusY(style, radiusY))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY) {
    RelAbsVector radiusYVector;
    radiusYVector.setAbsoluteValue(radiusY);
    return setReactionGeometricShapeCornerCurvatureRadiusY(layout, localRenderInformation, radiusYVector);
}

int setCompartmentGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeCenterX(style, centerX))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeCenterXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerX) {
    RelAbsVector centerXVector;
    centerXVector.setAbsoluteValue(centerX);
    return setCompartmentGeometricShapeCenterX(layout, localRenderInformation, centerXVector);
}

int setSpeciesGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeCenterX(style, centerX))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeCenterXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerX) {
    RelAbsVector centerXVector;
    centerXVector.setAbsoluteValue(centerX);
    return setSpeciesGeometricShapeCenterX(layout, localRenderInformation, centerXVector);
}

int setReactionGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeCenterX(style, centerX))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeCenterXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerX) {
    RelAbsVector centerXVector;
    centerXVector.setAbsoluteValue(centerX);
    return setReactionGeometricShapeCenterX(layout, localRenderInformation, centerXVector);
}

int setCompartmentGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeCenterY(style, centerY))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeCenterYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerY) {
    RelAbsVector centerYVector;
    centerYVector.setAbsoluteValue(centerY);
    return setCompartmentGeometricShapeCenterY(layout, localRenderInformation, centerYVector);
}

int setSpeciesGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeCenterY(style, centerY))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeCenterYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerY) {
    RelAbsVector centerYVector;
    centerYVector.setAbsoluteValue(centerY);
    return setSpeciesGeometricShapeCenterY(layout, localRenderInformation, centerYVector);
}

int setReactionGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeCenterY(style, centerY))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeCenterYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& centerY) {
    RelAbsVector centerYVector;
    centerYVector.setAbsoluteValue(centerY);
    return setReactionGeometricShapeCenterY(layout, localRenderInformation, centerYVector);
}

int setCompartmentGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeRadiusX(style, radiusX))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX) {
    RelAbsVector radiusXVector;
    radiusXVector.setAbsoluteValue(radiusX);
    return setCompartmentGeometricShapeRadiusX(layout, localRenderInformation, radiusXVector);
}

int setSpeciesGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeRadiusX(style, radiusX))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX) {
    RelAbsVector radiusXVector;
    radiusXVector.setAbsoluteValue(radiusX);
    return setSpeciesGeometricShapeRadiusX(layout, localRenderInformation, radiusXVector);
}

int setReactionGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeRadiusX(style, radiusX))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeRadiusXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusX) {
    RelAbsVector radiusXVector;
    radiusXVector.setAbsoluteValue(radiusX);
    return setReactionGeometricShapeRadiusX(layout, localRenderInformation, radiusXVector);
}

int setCompartmentGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeRadiusY(style, radiusY))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY) {
    RelAbsVector radiusYVector;
    radiusYVector.setAbsoluteValue(radiusY);
    return setCompartmentGeometricShapeRadiusY(layout, localRenderInformation, radiusYVector);
}

int setSpeciesGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeRadiusY(style, radiusY))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY) {
    RelAbsVector radiusYVector;
    radiusYVector.setAbsoluteValue(radiusY);
    return setSpeciesGeometricShapeRadiusY(layout, localRenderInformation, radiusYVector);
}

int setReactionGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeRadiusY(style, radiusY))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeRadiusYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& radiusY) {
    RelAbsVector radiusYVector;
    radiusYVector.setAbsoluteValue(radiusY);
    return setReactionGeometricShapeRadiusY(layout, localRenderInformation, radiusYVector);
}

int setCompartmentGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeElementX(style, elementX))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeElementXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementX) {
    RelAbsVector elementXVector;
    elementXVector.setAbsoluteValue(elementX);
    return setCompartmentGeometricShapeElementX(layout, localRenderInformation, elementXVector);
}

int setSpeciesGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeElementX(style, elementX))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeElementXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementX) {
    RelAbsVector elementXVector;
    elementXVector.setAbsoluteValue(elementX);
    return setSpeciesGeometricShapeElementX(layout, localRenderInformation, elementXVector);
}

int setReactionGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeElementX(style, elementX))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeElementXAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementX) {
    RelAbsVector elementXVector;
    elementXVector.setAbsoluteValue(elementX);
    return setReactionGeometricShapeElementX(layout, localRenderInformation, elementXVector);
}

int setCompartmentGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeElementY(style, elementY))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeElementYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementY) {
    RelAbsVector elementYVector;
    elementYVector.setAbsoluteValue(elementY);
    return setCompartmentGeometricShapeElementY(layout, localRenderInformation, elementYVector);
}

int setSpeciesGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY) {
    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeElementY(style, elementY))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeElementYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementY) {
    RelAbsVector elementYVector;
    elementYVector.setAbsoluteValue(elementY);
    return setSpeciesGeometricShapeElementY(layout, localRenderInformation, elementYVector);
}

int setReactionGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeElementY(style, elementY))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeElementYAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& elementY) {
    RelAbsVector elementYVector;
    elementYVector.setAbsoluteValue(elementY);
    return setReactionGeometricShapeElementY(layout, localRenderInformation, elementYVector);
}

int setCompartmentGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint1X(style, basePoint1X))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeBasePoint1XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1X) {
    RelAbsVector basePoint1XVector;
    basePoint1XVector.setAbsoluteValue(basePoint1X);
    return setCompartmentGeometricShapeBasePoint1X(layout, localRenderInformation, basePoint1XVector);
}

int setSpeciesGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X) {
    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint1X(style, basePoint1X))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeBasePoint1XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1X) {
    RelAbsVector basePoint1XVector;
    basePoint1XVector.setAbsoluteValue(basePoint1X);
    return setSpeciesGeometricShapeBasePoint1X(layout, localRenderInformation, basePoint1XVector);
}

int setReactionGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint1X(style, basePoint1X))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeBasePoint1XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1X) {
    RelAbsVector basePoint1XVector;
    basePoint1XVector.setAbsoluteValue(basePoint1X);
    return setReactionGeometricShapeBasePoint1X(layout, localRenderInformation, basePoint1XVector);
}

int setCompartmentGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint1Y(style, basePoint1Y))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeBasePoint1YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1Y) {
    RelAbsVector basePoint1YVector;
    basePoint1YVector.setAbsoluteValue(basePoint1Y);
    return setCompartmentGeometricShapeBasePoint1Y(layout, localRenderInformation, basePoint1YVector);
}

int setSpeciesGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint1Y(style, basePoint1Y))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeBasePoint1YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1Y) {
    RelAbsVector basePoint1YVector;
    basePoint1YVector.setAbsoluteValue(basePoint1Y);
    return setSpeciesGeometricShapeBasePoint1Y(layout, localRenderInformation, basePoint1YVector);
}

int setReactionGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint1Y(style, basePoint1Y))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeBasePoint1YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint1Y) {
    RelAbsVector basePoint1YVector;
    basePoint1YVector.setAbsoluteValue(basePoint1Y);
    return setReactionGeometricShapeBasePoint1Y(layout, localRenderInformation, basePoint1YVector);
}

int setCompartmentGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint2X(style, basePoint2X))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeBasePoint2XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2X) {
    RelAbsVector basePoint2XVector;
    basePoint2XVector.setAbsoluteValue(basePoint2X);
    return setCompartmentGeometricShapeBasePoint2X(layout, localRenderInformation, basePoint2XVector);
}

int setSpeciesGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint2X(style, basePoint2X))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeBasePoint2XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2X) {
    RelAbsVector basePoint2XVector;
    basePoint2XVector.setAbsoluteValue(basePoint2X);
    return setSpeciesGeometricShapeBasePoint2X(layout, localRenderInformation, basePoint2XVector);
}

int setReactionGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint2X(style, basePoint2X))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeBasePoint2XAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2X) {
    RelAbsVector basePoint2XVector;
    basePoint2XVector.setAbsoluteValue(basePoint2X);
    return setReactionGeometricShapeBasePoint2X(layout, localRenderInformation, basePoint2XVector);
}

int setCompartmentGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint2Y(style, basePoint2Y))
                return -1;
        }
    }

    return 0;
}

int setCompartmentGeometricShapeBasePoint2YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2Y) {
    RelAbsVector basePoint2YVector;
    basePoint2YVector.setAbsoluteValue(basePoint2Y);
    return setCompartmentGeometricShapeBasePoint2Y(layout, localRenderInformation, basePoint2YVector);
}

int setSpeciesGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint2Y(style, basePoint2Y))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeBasePoint2YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2Y) {
    RelAbsVector basePoint2YVector;
    basePoint2YVector.setAbsoluteValue(basePoint2Y);
    return setSpeciesGeometricShapeBasePoint2Y(layout, localRenderInformation, basePoint2YVector);
}

int setReactionGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeBasePoint2Y(style, basePoint2Y))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeBasePoint2YAsDouble(Layout* layout, LocalRenderInformation* localRenderInformation, const double& basePoint2Y) {
    RelAbsVector basePoint2YVector;
    basePoint2YVector.setAbsoluteValue(basePoint2Y);
    return setReactionGeometricShapeBasePoint2Y(layout, localRenderInformation, basePoint2YVector);
}

int setCompartmentGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getCompartmentGlyph(i));
        if (style) {
            if (setGeometricShapeHref(style, href))
                return -1;
        }
    }

    return 0;
}

int setSpeciesGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href) {
    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getSpeciesGlyph(i));
        if (style) {
            if (setGeometricShapeHref(style, href))
                return -1;
        }
    }

    return 0;
}

int setReactionGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href) {
    if (layout == NULL || localRenderInformation == NULL)
        return -1;

    Style *style = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        style = getStyleById(localRenderInformation, layout->getReactionGlyph(i));
        if (style) {
            if (setGeometricShapeHref(style, href))
                return -1;
        }
    }

    return 0;
}

}