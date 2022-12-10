#include "libsbml_ne_render_helpers.h"
#include "libsbml_ne_layout_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

SBasePlugin* getRenderPlugin(SBMLDocument* document) {
    LayoutModelPlugin* layoutModelPlugin = getLayoutModelPlugin(document);
    if (layoutModelPlugin) {
        SBasePlugin* renderBase = getRenderPlugin(layoutModelPlugin);
        if (!renderBase) {
            enableRenderPlugin(document);
            return getRenderPlugin(layoutModelPlugin);
        }
        return renderBase;
    }
    
    return NULL;
}

SBasePlugin* getRenderPlugin(Layout* layout) {
    SBasePlugin* renderBase = layout->getPlugin("render");
    if (!renderBase) {
        enableRenderPlugin(layout);
        return getRenderPlugin(layout);
    }
    return renderBase;
}

SBasePlugin* getRenderPlugin(LayoutModelPlugin* layoutModelPlugin) {
    ListOfLayouts* listOfLayouts = layoutModelPlugin->getListOfLayouts();
    return listOfLayouts->getPlugin("render");
}

RenderListOfLayoutsPlugin* getRenderListOfLayoutsPlugin(SBasePlugin* renderBase) {
    RenderListOfLayoutsPlugin* renderListOfLayoutsPlugin = NULL;
    try {
        renderListOfLayoutsPlugin = dynamic_cast<RenderListOfLayoutsPlugin*>(renderBase); }
    catch(std::bad_cast) {
        std::cerr << "Unable to get global render information\n";
    }
    
    return renderListOfLayoutsPlugin;
}

RenderLayoutPlugin* getRenderLayoutPlugin(SBasePlugin* renderBase) {
    RenderLayoutPlugin* renderLayoutPlugin = NULL;
    try {
        renderLayoutPlugin = dynamic_cast<RenderLayoutPlugin*>(renderBase); }
    catch(std::bad_cast) {
        std::cerr << "Unable to get local render information\n";
    }
    
    return renderLayoutPlugin;
}

void enableRenderPlugin(SBMLDocument* document) {
    if (document->getLevel() == 2)
        document->enablePackage(RenderExtension::getXmlnsL2(), "render",  true);
    else if (document->getLevel() == 3)
        document->enablePackage(RenderExtension::getXmlnsL3V1V1(), "render", true);
    document->setPackageRequired("render", false);
}

void enableRenderPlugin(Layout* layout) {
    if (layout->getLevel() == 2)
        layout->enablePackage(RenderExtension::getXmlnsL2(), "render",  true);
    else if (layout->getLevel() == 3)
        layout->enablePackage(RenderExtension::getXmlnsL3V1V1(), "render", true);
}

void addStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    addCompartmentGlyphsStyles(layout, localRenderInformation, renderPkgNamespaces);
    addSpeciesGlyphsStyles(layout, localRenderInformation, renderPkgNamespaces);
    addReactionGlyphsStyles(layout, localRenderInformation, renderPkgNamespaces);
}

Style* findStyle(LocalRenderInformation* localRednderInformation, const std::string& graphicalObjectId) {
    if (localRednderInformation) {
        Style* style = NULL;
        for (unsigned int i = 0; i < localRednderInformation->getNumStyles(); i++) {
            std::set<std::string> idList = localRednderInformation->getStyle(i)->getIdList();
            if (idList.find(graphicalObjectId) != idList.end())
                return localRednderInformation->getStyle(i);
        }
    }
    
    return NULL;
}

void addCompartmentGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        addCompartmentGlyphStyle(layout->getCompartmentGlyph(i), localRenderInformation, renderPkgNamespaces);
        addCompartmentTextGlyphsStyles(layout, localRenderInformation, layout->getCompartmentGlyph(i), renderPkgNamespaces);
    }
}

void addCompartmentGlyphStyle(CompartmentGlyph* compartmentGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    LocalStyle* localStyle = createLocalStyle(localRenderInformation, compartmentGlyph);
    setCompartmentGlyphRenderGroupFeatures(localStyle->createGroup(), renderPkgNamespaces);
}

void setCompartmentGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces) {
    Transformation2D* shape = createRectangleShape();
    ((Rectangle*)shape)->setStroke("darkcyan");
    ((Rectangle*)shape)->setStrokeWidth(2.0);
    ((Rectangle*)shape)->setFill("lightgray");
    ((Rectangle*)shape)->setRX(RelAbsVector(0.0, 5.0));
    ((Rectangle*)shape)->setRY(RelAbsVector(0.0, 5.0));
    renderGroup->addElement(shape);
}

void addCompartmentTextGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, CompartmentGlyph* compartmentGlyph, RenderPkgNamespaces* renderPkgNamespaces) {
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (layout->getTextGlyph(i)->getGraphicalObjectId() == compartmentGlyph->getId())
            addCompartmentTextGlyphStyle(layout->getTextGlyph(i), localRenderInformation, renderPkgNamespaces);
    }
}

void addCompartmentTextGlyphStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    LocalStyle* localStyle = createLocalStyle(localRenderInformation, textGlyph);
    setCompartmentTextGlyphRenderGroupFeatures(localStyle->createGroup(), renderPkgNamespaces);
}

void setCompartmentTextGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup, renderPkgNamespaces);
    renderGroup->setStroke("darkcyan");
    renderGroup->setFontSize(RelAbsVector(8.0, 0.0));
    renderGroup->setTextAnchor("start");
    renderGroup->setVTextAnchor("bottom");
}

void addSpeciesGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        addSpeciesGlyphStyle(layout->getSpeciesGlyph(i), localRenderInformation, renderPkgNamespaces);
        addSpeciesTextGlyphsStyles(layout, localRenderInformation, layout->getSpeciesGlyph(i), renderPkgNamespaces);
    }
}

void addSpeciesGlyphStyle(SpeciesGlyph* speciesGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    LocalStyle* localStyle = createLocalStyle(localRenderInformation, speciesGlyph);
    setSpeciesGlyphRenderGroupFeatures(localStyle->createGroup(), renderPkgNamespaces);
}

void setSpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces) {
    Transformation2D* shape = createRectangleShape();
    ((Rectangle*)shape)->setStroke("black");
    ((Rectangle*)shape)->setStrokeWidth(2.0);
    ((Rectangle*)shape)->setFill("white");
    renderGroup->addElement(shape);
}

void addSpeciesTextGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, SpeciesGlyph* speciesGlyph, RenderPkgNamespaces* renderPkgNamespaces) {
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (layout->getTextGlyph(i)->getGraphicalObjectId() == speciesGlyph->getId())
            addSpeciesTextGlyphStyle(layout->getTextGlyph(i), localRenderInformation, renderPkgNamespaces);
    }
}

void addSpeciesTextGlyphStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    LocalStyle* localStyle = createLocalStyle(localRenderInformation, textGlyph);
    setSpeciesTextGlyphRenderGroupFeatures(localStyle->createGroup(), renderPkgNamespaces);
}

void setSpeciesTextGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup, renderPkgNamespaces);
    renderGroup->setFontSize(RelAbsVector(24.0, 0.0));
}

void addReactionGlyphsStyles(Layout* layout, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        addReactionGlyphStyle(layout->getReactionGlyph(i), localRenderInformation, renderPkgNamespaces);
        addSpeciesReferenceGlyphsStyles(layout->getReactionGlyph(i), localRenderInformation, renderPkgNamespaces);
    }
}

void addReactionGlyphStyle(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    LocalStyle* localStyle = createLocalStyle(localRenderInformation, reactionGlyph);
    setReactionGlyphRenderGroupFeatures(localStyle->createGroup(), renderPkgNamespaces);
}

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces) {
    Transformation2D* shape = createEllipseShape();
    ((Ellipse*)shape)->setStroke("black");
    ((Ellipse*)shape)->setStrokeWidth(2.0);
    ((Ellipse*)shape)->setFill("white");
    renderGroup->addElement(shape);
}

void addSpeciesReferenceGlyphsStyles(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    for (int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
        LocalStyle* localStyle = createLocalStyle(localRenderInformation, reactionGlyph->getSpeciesReferenceGlyph(i));
        setSpeciesReferenceGlyphRenderGroupFeatures(localStyle->createGroup(), reactionGlyph->getSpeciesReferenceGlyph(i)->getRole(), renderPkgNamespaces);
    }
}

void addSpeciesReferenceGlyphStyle(SpeciesReferenceGlyph* speciesReferenceGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    LocalStyle* localStyle = createLocalStyle(localRenderInformation, speciesReferenceGlyph);
    setSpeciesReferenceGlyphRenderGroupFeatures(localStyle->createGroup(), speciesReferenceGlyph->getRole(), renderPkgNamespaces);
}

void setSpeciesReferenceGlyphRenderGroupFeatures(RenderGroup* renderGroup, SpeciesReferenceRole_t role, RenderPkgNamespaces* renderPkgNamespaces) {
    renderGroup->setStroke("black");
    renderGroup->setStrokeWidth(2.0);
    
    if (role == SPECIES_ROLE_PRODUCT || role == SPECIES_ROLE_SIDEPRODUCT)
        renderGroup->setEndHead("productHead");
    else if (role == SPECIES_ROLE_MODIFIER)
        renderGroup->setEndHead("modifierHead");
    else if (role == SPECIES_ROLE_ACTIVATOR)
        renderGroup->setEndHead("activatorHead");
    else if (role == SPECIES_ROLE_INHIBITOR)
        renderGroup->setEndHead("inhibitorHead");
}

LocalStyle* createLocalStyle(LocalRenderInformation* localRenderInformation, GraphicalObject* graphicalObject) {
    LocalStyle* localStyle = localRenderInformation->createLocalStyle();
    localStyle->setId(graphicalObject->getId() + "_style");
    localStyle->addId(graphicalObject->getId());
    return localStyle;
}

void setGeneralTextGlyphRenderGroupFeatures(RenderGroup* renderGroup, RenderPkgNamespaces* renderPkgNamespaces) {
    renderGroup->setStroke("black");
    renderGroup->setFontSize(RelAbsVector(24.0, 0.0));
    renderGroup->setFontFamily("monospace");
    renderGroup->setFontWeight("normal");
    renderGroup->setFontStyle("normal");
    renderGroup->setTextAnchor("middle");
    renderGroup->setVTextAnchor("middle");
}

void addDefaultColors(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    addWhiteColor(globalRednderInformation, renderPkgNamespaces);
    addBlackColor(globalRednderInformation, renderPkgNamespaces);
    addLightGrayColor(globalRednderInformation, renderPkgNamespaces);
    addDarkCyanColor(globalRednderInformation, renderPkgNamespaces);
    addTealColor(globalRednderInformation, renderPkgNamespaces);
    addSilverColor(globalRednderInformation, renderPkgNamespaces);
}

void addWhiteColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getColorDefinition("white"))
        globalRednderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "white", 255, 255, 255));
}

void addBlackColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getColorDefinition("black"))
        globalRednderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "black", 0, 0, 0));
}

void addLightGrayColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getColorDefinition("lightgray"))
        globalRednderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "lightgray", 211, 211, 211));
}

void addDarkCyanColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getColorDefinition("darkcyan"))
        globalRednderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "darkcyan", 0, 139, 139));
}

void addTealColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getColorDefinition("teal"))
        globalRednderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "teal", 0, 128, 128));
}

void addSilverColor(GlobalRenderInformation* globalRednderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getColorDefinition("silver"))
        globalRednderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "silver", 192, 192, 192));
}

ColorDefinition* createColorDefintion(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    return new ColorDefinition(renderPkgNamespaces, id, r, g, b, a);
}

void addDefaultLineEndings(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    addProductHeadLineEnding(globalRednderInformation, layoutPkgNamespaces, renderPkgNamespaces);
    addModifierHeadLineEnding(globalRednderInformation, layoutPkgNamespaces, renderPkgNamespaces);
    addActivatorHeadLineEnding(globalRednderInformation, layoutPkgNamespaces, renderPkgNamespaces);
    addInhibitorHeadLineEnding(globalRednderInformation, layoutPkgNamespaces, renderPkgNamespaces);
}

void addProductHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getLineEnding("productHead"))
        globalRednderInformation->addLineEnding(createProductHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createProductHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "productHead");
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setProductHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setProductHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Transformation2D* shape = createTriangleShape(renderPkgNamespaces);
    ((Polygon*)shape)->getElement(1)->setY(RelAbsVector(0.0, 50.0));
    ((Polygon*)shape)->getElement(2)->setX(RelAbsVector(0.0, 0.0));
    ((Polygon*)shape)->setStroke("black");
    ((Polygon*)shape)->setStrokeWidth(2.0);
    ((Polygon*)shape)->setFill("black");
    renderGroup->addElement(shape);
}

void addModifierHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getLineEnding("modifierHead"))
        globalRednderInformation->addLineEnding(createModifierHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createModifierHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "modifierHead");
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setModifierHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setModifierHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Transformation2D* shape = createDiamondShape(renderPkgNamespaces);
    ((Polygon*)shape)->setStroke("black");
    ((Polygon*)shape)->setStrokeWidth(2.0);
    ((Polygon*)shape)->setFill("white");
    renderGroup->addElement(shape);
}

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getLineEnding("activatorHead"))
        globalRednderInformation->addLineEnding(createActivatorHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createActivatorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "activatorHead");
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setActivatorHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setActivatorHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Transformation2D* shape = createEllipseShape();
    ((Ellipse*)shape)->setStroke("black");
    ((Ellipse*)shape)->setStrokeWidth(2.0);
    ((Ellipse*)shape)->setFill("white");
    renderGroup->addElement(shape);
}

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRednderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRednderInformation->getLineEnding("inhibitorHead"))
        globalRednderInformation->addLineEnding(createInhibitorHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createInhibitorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "inhibitorHead");
    lineEnding->createGroup();
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setInhibitorHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setInhibitorHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Transformation2D* shape = createRectangleShape();
    ((Rectangle*)shape)->setX(RelAbsVector(0.0, 80.0));
    ((Rectangle*)shape)->setWidth(RelAbsVector(0.0, 20.0));
    ((Rectangle*)shape)->setRX(RelAbsVector(0.0, 0.0));
    ((Rectangle*)shape)->setRY(RelAbsVector(0.0, 0.0));
    ((Rectangle*)shape)->setStroke("black");
    ((Rectangle*)shape)->setStrokeWidth(2.0);
    ((Rectangle*)shape)->setFill("black");
    renderGroup->addElement(shape);
}

void setLineEndingGeneralFeatures(LineEnding* lineEnding, LayoutPkgNamespaces* layoutPkgNamespaces) {
    lineEnding->setEnableRotationalMapping(true);
    lineEnding->setBoundingBox(new BoundingBox(layoutPkgNamespaces, lineEnding->getId() + "_bb", -12.0, -6.0, 12.0, 12.0));
}

Transformation2D* createRectangleShape() {
    Transformation2D* rectangle = new Rectangle();
    ((Rectangle*)rectangle)->setX(RelAbsVector(0.0, 0.0));
    ((Rectangle*)rectangle)->setY(RelAbsVector(0.0, 0.0));
    ((Rectangle*)rectangle)->setWidth(RelAbsVector(0.0, 100.0));
    ((Rectangle*)rectangle)->setHeight(RelAbsVector(0.0, 100.0));
    ((Rectangle*)rectangle)->setRX(RelAbsVector(0.0, 10.0));
    ((Rectangle*)rectangle)->setRY(RelAbsVector(0.0, 10.0));
    return rectangle;
}

Transformation2D* createEllipseShape() {
    Transformation2D* ellipse = new Ellipse();
    ((Ellipse*)ellipse)->setCX(RelAbsVector(0.0, 50.0));
    ((Ellipse*)ellipse)->setCY(RelAbsVector(0.0, 50.0));
    ((Ellipse*)ellipse)->setRX(RelAbsVector(0.0, 50.0));
    ((Ellipse*)ellipse)->setRY(RelAbsVector(0.0, 50.0));
    return ellipse;
}

Transformation2D* createTriangleShape(RenderPkgNamespaces* renderPkgNamespaces) {
    Transformation2D* triangle = new Polygon();
    ((Polygon*)triangle)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 0.0), RelAbsVector(0.0, 0.0)));
    ((Polygon*)triangle)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 100.0), RelAbsVector(0.0, 0.0)));
    ((Polygon*)triangle)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 50.0), RelAbsVector(0.0, 100.0)));
    return triangle;
}

Transformation2D* createDiamondShape(RenderPkgNamespaces* renderPkgNamespaces) {
    Transformation2D* diamond = new Polygon();
    ((Polygon*)diamond)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 0.0), RelAbsVector(0.0, 50.0)));
    ((Polygon*)diamond)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 50.0), RelAbsVector(0.0, 0.0)));
    ((Polygon*)diamond)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 100.0), RelAbsVector(0.0, 50.0)));
    ((Polygon*)diamond)->addElement(new RenderPoint(renderPkgNamespaces, RelAbsVector(0.0, 50.0), RelAbsVector(0.0, 100.0)));
    return diamond;
}

}
