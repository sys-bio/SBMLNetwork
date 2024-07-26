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

int setSpeciesFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize) {
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

int setReactionFontSize(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& fontSize) {
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

int setCompartmentFontWeight(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fontWeight) {
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

int setSpeciesFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor) {
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

int setReactionFillColor(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillColor) {
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

int setCompartmentFillRule(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& fillRule) {
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

int setSpeciesGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x) {
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

int setReactionGeometricShapeX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& x) {
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

int setCompartmentGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y) {
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

int setSpeciesGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y) {
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

int setReactionGeometricShapeY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& y) {
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

int setCompartmentGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width) {
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

int setSpeciesGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width) {
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

int setReactionGeometricShapeWidth(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& width) {
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

int setCompartmentGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height) {
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

int setSpeciesGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height) {
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

int setReactionGeometricShapeHeight(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& height) {
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

int setCompartmentGeometricShapeRatio(Layout* layout, LocalRenderInformation* localRenderInformation, const double& ratio) {
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


int setSpeciesGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
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

int setReactionGeometricShapeCornerCurvatureRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
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

int setCompartmentGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
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

int setSpeciesGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
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

int setReactionGeometricShapeCornerCurvatureRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
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

int setCompartmentGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX) {
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

int setSpeciesGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX) {
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

int setReactionGeometricShapeCenterX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerX) {
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

int setCompartmentGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY) {
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

int setSpeciesGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY) {
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

int setReactionGeometricShapeCenterY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& centerY) {
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

int setCompartmentGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
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

int setSpeciesGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
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

int setReactionGeometricShapeRadiusX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusX) {
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

int setCompartmentGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
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

int setSpeciesGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
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

int setReactionGeometricShapeRadiusY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& radiusY) {
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

int setCompartmentGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX) {
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

int setSpeciesGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX) {
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

int setReactionGeometricShapeElementX(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementX) {
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

int setCompartmentGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY) {
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

int setReactionGeometricShapeElementY(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& elementY) {
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

int setCompartmentGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X) {
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

int setReactionGeometricShapeBasePoint1X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1X) {
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

int setCompartmentGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y) {
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

int setSpeciesGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y) {
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

int setReactionGeometricShapeBasePoint1Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint1Y) {
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

int setCompartmentGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X) {
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

int setSpeciesGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X) {
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

int setReactionGeometricShapeBasePoint2X(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2X) {
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

int setCompartmentGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y) {
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

int setSpeciesGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y) {
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

int setReactionGeometricShapeBasePoint2Y(Layout* layout, LocalRenderInformation* localRenderInformation, const RelAbsVector& basePoint2Y) {
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

int setCompartmentGeometricShapeHref(Layout* layout, LocalRenderInformation* localRenderInformation, const std::string& href) {
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