#include "libsbml_ne_render.h"
#include "libsbml_ne_layout_helpers.h"
#include "libsbml_ne_render_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

ListOfGlobalRenderInformation* getListOfGlobalRenderInformation(SBMLDocument* document) {
    if (document) {
        SBasePlugin* renderBase = getRenderPlugin(document);
        if (renderBase) {
            RenderListOfLayoutsPlugin* renderListOfLayoutsPlugin = getRenderListOfLayoutsPlugin(renderBase);
            if (renderListOfLayoutsPlugin)
                return renderListOfLayoutsPlugin->getListOfGlobalRenderInformation();
        }
    }
    
    return NULL;
}

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

int addGlobalRender(SBMLDocument* document, GlobalRenderInformation* globalRednderInformation) {
    if (globalRednderInformation) {
        ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
        if (listOfGlobalRenderInformation) {
            listOfGlobalRenderInformation->addGlobalRenderInformation(globalRednderInformation);
            return 0;
        }
    }
    
    return -1;
}

int addLocalRender(Layout* layout, LocalRenderInformation* localRednderInformation) {
    if (localRednderInformation) {
        ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
        if (listOfLocalRenderInformation) {
            listOfLocalRenderInformation->addLocalRenderInformation(localRednderInformation);
            return 0;
        }
    }
    
    return -1;
}

GlobalRenderInformation* createGlobalRender(SBMLDocument* document) {
    ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->createGlobalRenderInformation();
    
    return NULL;
}

LocalRenderInformation* createLocalRender(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->createLocalRenderInformation();
    
    return NULL;
}

int removeGlobalRenders(SBMLDocument* document) {
    ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
    if (listOfGlobalRenderInformation) {
        while(listOfGlobalRenderInformation->size())
            listOfGlobalRenderInformation->remove(0);
        return 0;
    }
        
    return -1;
}

int removeLocalRenders(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation) {
        while(listOfLocalRenderInformation->size())
            listOfLocalRenderInformation->remove(0);
        return 0;
    }
        
    return -1;
}

int setDefaultGlobalRenderFeatures(SBMLDocument* document, GlobalRenderInformation* globalRednderInformation) {
    if (document && globalRednderInformation) {
        LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(document->getLevel(), document->getVersion());
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(document->getLevel(), document->getVersion());
        globalRednderInformation->setId("libSBML_NetworkEditor_Global_Render");
        globalRednderInformation->setBackgroundColor("lightgray");
        addDefaultColors(globalRednderInformation, renderPkgNamespaces);
        addDefaultLineEndings(globalRednderInformation, layoutPkgNamespaces, renderPkgNamespaces);
        return 0;
    }
    
    return -1;
}

int setDefaultLocalRenderFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRednderInformation) {
    if (document && localRednderInformation) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(document->getLevel(), document->getVersion());
        localRednderInformation->setId("libSBML_NetworkEditor_Local_Render");
        localRednderInformation->setReferenceRenderInformation("libSBML_NetworkEditor_Global_Render");
        if (layout) {
            addStyles(layout, localRednderInformation, renderPkgNamespaces);
            return 0;
        }
    }
    
    return -1;
}

bool isLinearGradient(GradientBase* gradientBase) {
    if (gradientBase)
        return gradientBase->isLinearGradient();

    return false;
}

bool isRadialGradient(GradientBase* gradientBase) {
    if (gradientBase)
        return gradientBase->isRadialGradient();

    return false;
}

bool isSetLinearGradientX1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetX1();

    return false;
}

const RelAbsVector getLinearGradientX1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getX1();

    return RelAbsVector();
}

int setLinearGradientX1(GradientBase* gradientBase, const RelAbsVector& x1) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient *) gradientBase)->setX1(x1);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientX2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetX2();

    return false;
}

const RelAbsVector getLinearGradientX2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getX2();

    return RelAbsVector();
}

int setLinearGradientX2(GradientBase* gradientBase, const RelAbsVector& x2) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient *) gradientBase)->setX2(x2);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientY1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetY1();

    return false;
}

const RelAbsVector getLinearGradientY1(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getY1();

    return RelAbsVector();
}

int setLinearGradientY1(GradientBase* gradientBase, const RelAbsVector& y1) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient*) gradientBase)->setY1(y1);
        return 0;
    }

    return -1;
}

bool isSetLinearGradientY2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->isSetY2();

    return false;
}

const RelAbsVector getLinearGradientY2(GradientBase* gradientBase) {
    if (isLinearGradient(gradientBase))
        ((LinearGradient*)gradientBase)->getY2();

    return RelAbsVector();
}

int setLinearGradientY2(GradientBase* gradientBase, const RelAbsVector& y2) {
    if (isLinearGradient(gradientBase)) {
        ((LinearGradient*) gradientBase)->setY2(y2);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientCx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetCx();

    return false;
}

const RelAbsVector getRadialGradientCx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getCx();

    return RelAbsVector();
}

int setRadialGradientCx(GradientBase* gradientBase, const RelAbsVector& cx) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*) gradientBase)->setCx(cx);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientCy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetCy();

    return false;
}

const RelAbsVector getRadialGradientCy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getCy();

    return RelAbsVector();
}

int setRadialGradientCy(GradientBase* gradientBase, const RelAbsVector& cy) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setCy(cy);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientFx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetFx();

    return false;
}

const RelAbsVector getRadialGradientFx(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getFx();

    return RelAbsVector();
}

int setRadialGradientFx(GradientBase* gradientBase, const RelAbsVector& fx) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setFx(fx);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientFy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetFy();

    return false;
}

const RelAbsVector getRadialGradientFy(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getFy();

    return RelAbsVector();
}

int setRadialGradientFy(GradientBase* gradientBase, const RelAbsVector& fy) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setFy(fy);
        return 0;
    }

    return -1;
}

bool isSetRadialGradientR(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->isSetR();

    return false;
}

const RelAbsVector getRadialGradientR(GradientBase* gradientBase) {
    if (isRadialGradient(gradientBase))
        ((RadialGradient*)gradientBase)->getR();

    return RelAbsVector();
}

int setRadialGradientR(GradientBase* gradientBase, const RelAbsVector& r) {
    if (isLinearGradient(gradientBase)) {
        ((RadialGradient*)gradientBase)->setR(r);
        return 0;
    }

    return -1;
}

Style* findStyle(LocalRenderInformation* localRednderInformation, GraphicalObject* graphicalObject) {
    Style * style = NULL;
    if (localRednderInformation && graphicalObject) {
        style = findStyle(localRednderInformation, graphicalObject->getId());
        if (!style) {
            std::string objectRole;
            RenderGraphicalObjectPlugin* renderGraphicalObjectPlugin = dynamic_cast<RenderGraphicalObjectPlugin*>(graphicalObject->getPlugin("render"));
            if (renderGraphicalObjectPlugin && renderGraphicalObjectPlugin->isSetObjectRole())
                objectRole = renderGraphicalObjectPlugin->getObjectRole();
            style = findStyle(localRednderInformation, objectRole);
        }
    }
    
    return style;
}

Style* findStyle(GlobalRenderInformation* globalRednderInformation, GraphicalObject* graphicalObject, const std::string& objectType) {
    Style * style = NULL;
    if (globalRednderInformation) {
        // by role
        if (graphicalObject) {
            RenderGraphicalObjectPlugin* renderGraphicalObjectPlugin = dynamic_cast<RenderGraphicalObjectPlugin*>(graphicalObject->getPlugin("render"));
            if (renderGraphicalObjectPlugin && renderGraphicalObjectPlugin->isSetObjectRole())
                style = findStyle(globalRednderInformation, renderGraphicalObjectPlugin->getObjectRole());
        }
        // by type
        if (!style)
            style = findStyle(globalRednderInformation, objectType);
    }
    
    return style;
}

RenderGroup* getRenderGroup(Style* style) {
    if (style)
        return style->getGroup();

    return NULL;
}

bool isSetStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStroke();

    return false;
}

const std::string getStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStroke();
    
    return "";
}

int setStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& stroke) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStroke(stroke);
        return 0;
    }
    
    return -1;
}

bool isSetStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStrokeWidth();

    return false;
}

const double getStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeWidth();
    
    return 0.0;
}

int setStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D, const double& strokeWidth) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeWidth(strokeWidth);
        return 0;
    }
    
    return -1;
}

bool isSetStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->isSetStrokeDashArray();

    return false;
}

const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeDashArray();
    
    return std::vector<unsigned int>();
}

int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeDashArray(strokeDashArray);
        return 0;
    }
    
    return -1;
}

unsigned int getNumStrokeDashes(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return getStrokeDashArray(graphicalPrimitive1D).size();
}

unsigned int getDash(GraphicalPrimitive1D* graphicalPrimitive1D, unsigned  int n) {
    if (graphicalPrimitive1D)
        graphicalPrimitive1D->getDashByIndex(n);

    return 0;
}

bool isSetFontColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return isSetStrokeColor(graphicalPrimitive1D);
}

const std::string getFontColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    return getStrokeColor(graphicalPrimitive1D);
}

int setFontColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontColor) {
    return setStrokeColor(graphicalPrimitive1D, fontColor);
}

bool isSetFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetFontFamily();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetFontFamily();
    }

    return false;
}

const std::string getFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getFontFamily();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getFontFamily();
    }

    return "";
}

int setFontFamily(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontFamily) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setFontFamily(fontFamily);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setFontFamily(fontFamily);
            return 0;
        }
    }

    return -1;
}

bool isSetFontSize(GraphicalPrimitive1D* graphicalPrimitive1D) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup)
        return renderGroup->isSetFontSize();
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text)
        return text->isSetFontSize();

    return false;
}

const RelAbsVector getFontSize(GraphicalPrimitive1D* graphicalPrimitive1D) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup)
        return renderGroup->getFontSize();
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text)
        return text->getFontSize();

    return RelAbsVector();
}

int setFontSize(GraphicalPrimitive1D* graphicalPrimitive1D, const RelAbsVector& fontSize) {
    RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
    if (renderGroup) {
        renderGroup->setFontSize(fontSize);
        return 0;
    }
    Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
    if (text) {
        text->setFontSize(fontSize);
        return 0;
    }

    return -1;
}

bool isSetFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetFontWeight();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetFontWeight();
    }

    return false;
}

const std::string getFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getFontWeightAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getFontWeightAsString();
    }

    return "";
}

int setFontWeight(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontWeight) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setFontWeight(fontWeight);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setFontWeight(fontWeight);
            return 0;
        }
    }

    return -1;
}

bool isSetFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetFontStyle();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetFontStyle();
    }

    return false;
}

const std::string getFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getFontStyleAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getFontStyleAsString();
    }

    return "";
}

int setFontStyle(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& fontStyle) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setFontStyle(fontStyle);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setFontStyle(fontStyle);
            return 0;
        }
    }

    return -1;
}

bool isSetTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetTextAnchor();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetTextAnchor();
    }

    return false;
}

const std::string getTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getTextAnchorAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getTextAnchorAsString();
    }

    return "";
}

int setTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& textAnchor) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setTextAnchor(textAnchor);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setTextAnchor(textAnchor);
            return 0;
        }
    }

    return -1;
}

bool isSetVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->isSetVTextAnchor();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->isSetVTextAnchor();
    }

    return false;
}

const std::string getVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup)
            return renderGroup->getVTextAnchorAsString();
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text)
            return text->getVTextAnchorAsString();
    }

    return "";
}

int setVTextAnchor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& vtextAnchor) {
    if (graphicalPrimitive1D) {
        RenderGroup* renderGroup = dynamic_cast<RenderGroup*>(graphicalPrimitive1D);
        if (renderGroup) {
            renderGroup->setVTextAnchor(vtextAnchor);
            return 0;
        }
        Text* text = dynamic_cast<Text*>(graphicalPrimitive1D);
        if (text) {
            text->setVTextAnchor(vtextAnchor);
            return 0;
        }
    }

    return -1;
}

bool isSetFillColor(GraphicalPrimitive2D* graphicalPrimitive2D) {
    if (graphicalPrimitive2D)
        return graphicalPrimitive2D->isSetFill();

    return false;
}

const std::string getFillColor(GraphicalPrimitive2D* graphicalPrimitive2D) {
    if (graphicalPrimitive2D)
        return graphicalPrimitive2D->getFill();
    
    return "";
}

int setFillColor(GraphicalPrimitive2D* graphicalPrimitive2D, const std::string& fill) {
    if (graphicalPrimitive2D) {
        graphicalPrimitive2D->setFill(fill);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetX();
    
    return false;
}

const RelAbsVector getRectangleShapeX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getX();
    
    return RelAbsVector();
}

int setRectangleShapeX(Rectangle* rectangle, const RelAbsVector& x) {
    if (rectangle) {
        rectangle->setX(x);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetY();
    
    return false;
}

const RelAbsVector getRectangleShapeY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getY();
    
    return RelAbsVector();
}

int setRectangleShapeY(Rectangle* rectangle, const RelAbsVector& y) {
    if (rectangle) {
        rectangle->setX(y);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeWidth(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetWidth();
    
    return false;
}

const RelAbsVector getRectangleShapeWidth(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getWidth();
    
    return RelAbsVector();
}

int setRectangleShapeWidth(Rectangle* rectangle, const RelAbsVector& width) {
    if (rectangle) {
        rectangle->setWidth(width);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeHeight(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetHeight();
    
    return false;
}

const RelAbsVector getRectangleShapeHeight(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getHeight();
    
    return RelAbsVector();
}

int setRectangleShapeHeight(Rectangle* rectangle, const RelAbsVector& height) {
    if (rectangle) {
        rectangle->setHeight(height);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeRatio(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetRatio();
    
    return false;
}

const double getRectangleShapeRatio(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getRatio();
    
    return 0.0;
}

int setRectangleShapeRatio(Rectangle* rectangle, const double& ratio) {
    if (rectangle) {
        rectangle->setRatio(ratio);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeRX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetRX();
    
    return false;
}

const RelAbsVector getRectangleShapeRX(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getRX();
    
    return RelAbsVector();
}

int setRectangleShapeRX(Rectangle* rectangle, const RelAbsVector& rx) {
    if (rectangle) {
        rectangle->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetRectangleShapeRY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->isSetRY();
    
    return false;
}

const RelAbsVector getRectangleShapeRY(Rectangle* rectangle) {
    if (rectangle)
        return rectangle->getRY();
    
    return RelAbsVector();
}

int setRectangleShapeRY(Rectangle* rectangle, const RelAbsVector& ry) {
    if (rectangle) {
        rectangle->setRY(ry);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeCX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetCX();
    
    return false;
}

const RelAbsVector getEllipseShapeCX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getCX();
    
    return RelAbsVector();
}

int setEllipseShapeCX(Ellipse* ellipse, const RelAbsVector& cx) {
    if (ellipse) {
        ellipse->setCX(cx);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeCY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetCY();
    
    return false;
}

const RelAbsVector getEllipseShapeCY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getCY();
    
    return RelAbsVector();
}

int setEllipseShapeCY(Ellipse* ellipse, const RelAbsVector& cy) {
    if (ellipse) {
        ellipse->setCY(cy);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeRX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetRX();
    
    return false;
}

const RelAbsVector getEllipseShapeRX(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getRX();
    
    return RelAbsVector();
}

int setEllipseShapeRX(Ellipse* ellipse, const RelAbsVector& rx) {
    if (ellipse) {
        ellipse->setRX(rx);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeRY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetRY();
    
    return false;
}

const RelAbsVector getEllipseShapeRY(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getRY();
    
    return RelAbsVector();
}

int setEllipseShapeRY(Ellipse* ellipse, const RelAbsVector& ry) {
    if (ellipse) {
        ellipse->setRY(ry);
        return 0;
    }
    
    return -1;
}

bool isSetEllipseShapeRatio(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->isSetRatio();
    
    return false;
}

const double getEllipseShapeRatio(Ellipse* ellipse) {
    if (ellipse)
        return ellipse->getRatio();
    
    return 0.0;
}

int setEllipseShapeRatio(Ellipse* ellipse, const double& ratio) {
    if (ellipse) {
        ellipse->setRatio(ratio);
        return 0;
    }
    
    return -1;
}

const unsigned int getPolygonShapeNumElements(Polygon* polygon) {
    if (polygon)
        return polygon->getNumElements();

    return 0;
}

const RelAbsVector getPolygonShapeElementX(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element)
            return element->getX();
    }

    return RelAbsVector();
}

int setPolygonShapeElementX(Polygon* polygon, unsigned  int n, const RelAbsVector& x) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element) {
            element->setX(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeElementY(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element)
            return element->getY();
    }

    return RelAbsVector();
}

int setPolygonShapeElementY(Polygon* polygon, unsigned  int n, const RelAbsVector& y) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element) {
            element->setY(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_x();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint1X(Polygon* polygon, unsigned  int n, const RelAbsVector& x) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_y();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint1Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_y(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_x();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint2X(Polygon* polygon, unsigned  int n, const RelAbsVector& x) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_y();
    }

    return RelAbsVector();
}

int setPolygonShapeBasePoint2Y(Polygon* polygon, unsigned  int n, const RelAbsVector& y) {
    if (polygon) {
        RenderPoint* element = polygon->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_y(y);
            return 0;
        }
    }

    return -1;
}

const unsigned int getRenderCurveShapeNumElements(RenderCurve* renderCurve) {
    if (renderCurve)
        return  renderCurve->getNumElements();

    return 0;
}

bool isRenderCubicBezier(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve)
        return isRenderCubicBezier(renderCurve->getElement(n));

    return false;
}

bool isRenderCubicBezier(RenderPoint* renderPoint) {
    if (renderPoint)
        return renderPoint->isRenderCubicBezier();

    return false;
}

const RelAbsVector getRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element)
            return element->getX();
    }

    return RelAbsVector();
}

int setRenderCurveShapeElementX(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element) {
            element->setX(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element)
            return element->getY();
    }

    return RelAbsVector();
}

int setRenderCurveShapeElementY(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element) {
            element->setY(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_x();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint1X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint1_y();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint1Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint1_y(y);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_x();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint2X(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& x) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_x(x);
            return 0;
        }
    }

    return -1;
}

const RelAbsVector getRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier())
            return ((RenderCubicBezier*)element)->getBasePoint2_y();
    }

    return RelAbsVector();
}

int setRenderCurveShapeBasePoint2Y(RenderCurve* renderCurve, unsigned  int n, const RelAbsVector& y) {
    if (renderCurve) {
        RenderPoint* element = renderCurve->getElement(n);
        if (element && element->isRenderCubicBezier()) {
            ((RenderCubicBezier*)element)->setBasePoint2_y(y);
            return 0;
        }
    }

    return -1;
}

bool isSetImageShapeX(Image* image) {
    if (image)
        return image->isSetX();

    return false;
}

const RelAbsVector getImageShapeX(Image* image) {
    if (image)
        return image->getX();

    return RelAbsVector();
}

int setImageShapeX(Image* image, const RelAbsVector& x) {
    if (image) {
        image->setX(x);
        return 0;
    }

    return -1;
}

bool isSetImageShapeY(Image* image) {
    if (image)
        return image->isSetY();

    return false;
}

const RelAbsVector getImageShapeY(Image* image) {
    if (image)
        return image->getY();

    return RelAbsVector();
}

int setImageShapeY(Image* image, const RelAbsVector& y) {
    if (image) {
        image->setY(y);
        return 0;
    }

    return -1;
}

bool isSetImageShapeWidth(Image* image) {
    if (image)
        return image->isSetWidth();

    return false;
}

const RelAbsVector getImageShapeWidth(Image* image) {
    if (image)
        return image->getWidth();

    return RelAbsVector();
}

int setImageShapeWidth(Image* image, const RelAbsVector& width) {
    if (image) {
        image->setWidth(width);
        return 0;
    }

    return -1;
}

bool isSetImageShapeHeight(Image* image) {
    if (image)
        return image->isSetHeight();

    return false;
}

const RelAbsVector getImageShapeHeight(Image* image) {
    if (image)
        return image->getHeight();

    return RelAbsVector();
}

int setImageShapeHeight(Image* image, const RelAbsVector& height) {
    if (image) {
        image->setHeight(height);
        return 0;
    }

    return -1;
}

bool isSetImageShapeHref(Image* image) {
    if (image)
        return image->isSetHref();

    return false;
}

const std::string getImageShapeHref(Image* image) {
    if (image)
        return image->getHref();

    return "";
}

int setImageShapeHref(Image* image, const std::string& href) {
    if (image) {
        image->setHref(href);
        return 0;
    }

    return -1;
}

bool isSetTextShapeX(Text* text) {
    if (text)
        return text->isSetX();

    return false;
}

const RelAbsVector getTextShapeX(Text* text) {
    if (text)
        return text->getX();

    return RelAbsVector();
}

int setTextShapeX(Text* text, const RelAbsVector& x) {
    if (text) {
        text->setX(x);
        return 0;
    }

    return -1;
}

bool isSetTextShapeY(Text* text) {
    if (text)
        return text->isSetY();

    return false;
}

const RelAbsVector getTextShapeY(Text* text) {
    if (text)
        return text->getY();

    return RelAbsVector();
}

int setTextShapeY(Text* text, const RelAbsVector& y) {
    if (text) {
        text->setY(y);
        return 0;
    }

    return -1;
}

int addGeometricShape(RenderGroup* renderGroup, const std::string& shape) {
    if (renderGroup) {
        if (stringCompare(shape, "rectangle")) {
            Rectangle* rectangle = renderGroup->createRectangle();
            setDefaultRectangleShapeFeatures(rectangle);
            return 0;
        }
        else if (stringCompare(shape, "ellipse")) {
            Ellipse* ellipse = renderGroup->createEllipse();
            setDefaultEllipseShapeFeatures(ellipse);
            return 0;
        }
        else if (stringCompare(shape, "triangle")) {
            Polygon* triangle = renderGroup->createPolygon();
            setDefaultTriangleShapeFeatures(triangle);
            return 0;
        }
        else if (stringCompare(shape, "diamond")) {
            Polygon* diamond = renderGroup->createPolygon();
            setDefaultDiamondShapeFeatures(diamond);
            return 0;
        }
        else if (stringCompare(shape, "pentagon")) {
            Polygon* pentagon = renderGroup->createPolygon();
            setDefaultPentagonShapeFeatures(pentagon);
            return 0;
        }
        else if (stringCompare(shape, "hexagon")) {
            Polygon* hexagon = renderGroup->createPolygon();
            setDefaultHexagonShapeFeatures(hexagon);
            return 0;
        }
        else if (stringCompare(shape, "octagon")) {
            Polygon* octagon = renderGroup->createPolygon();
            setDefaultOctagonShapeFeatures(octagon);
            return 0;
        }
        else if (stringCompare(shape, "rendercurve")) {
            RenderCurve* renderCurve = renderGroup->createCurve();
            setDefaultRenderCurveShapeFeatures(renderCurve);
            return 0;
        }
        else if (stringCompare(shape, "image")) {
            Image* image = renderGroup->createImage();
            setDefaultImageShapeFeatures(image);
            return 0;
        }
    }

    return -1;
}

Transformation2D * removeGeometricShape(RenderGroup* renderGroup, unsigned int n) {
    if (renderGroup)
        return renderGroup->removeElement(n);

    return NULL;
}

int addRenderPointToShape(Transformation2D* shape) {
    if (shape) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(shape->getLevel(), shape->getVersion());
        if (shape->isPolygon())
            return ((Polygon*)shape)->addElement(new RenderPoint(renderPkgNamespaces));
        else if (shape->isRenderCurve())
            return ((RenderCurve*)shape)->addElement(new RenderPoint(renderPkgNamespaces));
    }

    return -1;
}

int addRenderCubicBezierToShape(Transformation2D* shape) {
    if (shape) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(shape->getLevel(), shape->getVersion());
        if (shape->isPolygon())
            return ((Polygon*)shape)->addElement(new RenderCubicBezier(renderPkgNamespaces));
        else if (shape->isRenderCurve())
            return ((RenderCurve*)shape)->addElement(new RenderCubicBezier(renderPkgNamespaces));
    }

    return -1;
}

RenderPoint * removeElementFromShape(Transformation2D* shape, unsigned int n) {
    if (shape) {
        if (shape->isPolygon())
            return ((Polygon*)shape)->removeElement(n);
        else if (shape->isRenderCurve())
            return ((RenderCurve*)shape)->removeElement(n);
    }

    return NULL;
}

bool isSetStartHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->isSetStartHead();

    return false;
}

const std::string getStartHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getStartHead();

    return "";
}

int setStartHead(RenderGroup* renderGroup, const std::string startHead) {
    if (renderGroup) {
        renderGroup->setStartHead(startHead);
        return 0;
    }

    return -1;
}

bool isSetEndHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->isSetEndHead();

    return false;
}

const std::string getEndHead(RenderGroup* renderGroup) {
    if (renderGroup)
        return renderGroup->getEndHead();

    return "";
}

int setEndHead(RenderGroup* renderGroup, const std::string endHead) {
    if (renderGroup) {
        renderGroup->setEndHead(endHead);
        return 0;
    }

    return -1;
}

bool isSetEnableRotationalMapping(LineEnding* lineEnding) {
    if (lineEnding) {
        lineEnding->isSetEnableRotationalMapping();
    }

    return false;
}

bool getEnableRotationalMapping(LineEnding* lineEnding) {
    if (lineEnding) {
        lineEnding->getEnableRotationalMapping();
    }

    return false;
}

int setEnableRotationalMapping(LineEnding* lineEnding, bool enableRotationalMapping) {
    if (lineEnding) {
        lineEnding->setEnableRotationalMapping(enableRotationalMapping);
    }

    return false;
}

BoundingBox* getBoundingBox(LineEnding* lineEnding) {
    if (lineEnding)
        return lineEnding->getBoundingBox();

    return NULL;
}

RenderGroup* getRenderGroup(LineEnding* lineEnding) {
    if (lineEnding)
        return lineEnding->getGroup();

    return NULL;
}

}

