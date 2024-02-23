#include "libsbml_ne_render_helpers.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"

#include <cmath>

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

Style* findStyleByIdList(RenderInformationBase* renderInformationBase, const std::string& id) {
    if (renderInformationBase->isLocalRenderInformation())
        return findStyleByIdList((LocalRenderInformation*)renderInformationBase, id);

    return NULL;
}

Style* findStyleByIdList(LocalRenderInformation* localRenderInformation, const std::string& id) {
    for (unsigned int i = 0; i < localRenderInformation->getNumLocalStyles(); i++) {
        std::set<std::string> idList = localRenderInformation->getLocalStyle(i)->getIdList();
        if (idList.find(id) != idList.end())
            return localRenderInformation->getLocalStyle(i);
    }

    return NULL;
}

Style* findStyleByRoleList(RenderInformationBase* renderInformationBase, const std::string& role) {
    if (renderInformationBase->isLocalRenderInformation())
        return findStyleByRoleList((LocalRenderInformation*)renderInformationBase, role);
    else if (renderInformationBase->isGlobalRenderInformation())
        return findStyleByRoleList((GlobalRenderInformation*)renderInformationBase, role);

    return NULL;
}

Style* findStyleByRoleList(LocalRenderInformation* localRenderInformation, const std::string& role) {
    for (unsigned int i = 0; i < localRenderInformation->getNumLocalStyles(); i++) {
        std::set<std::string> roleList = localRenderInformation->getLocalStyle(i)->getRoleList();
        if (roleList.find(role) != roleList.end())
            return localRenderInformation->getLocalStyle(i);
    }

    return NULL;
}

Style* findStyleByRoleList(GlobalRenderInformation* globalRenderInformation, const std::string& role) {
    for (unsigned int i = 0; i < globalRenderInformation->getNumGlobalStyles(); i++) {
        std::set<std::string> roleList = globalRenderInformation->getGlobalStyle(i)->getRoleList();
        if (roleList.find(role) != roleList.end())
            return globalRenderInformation->getGlobalStyle(i);
    }

    return NULL;
}

Style* findStyleByTypeList(RenderInformationBase* renderInformationBase, const std::string& type) {
    if (renderInformationBase->isLocalRenderInformation())
        return findStyleByTypeList((LocalRenderInformation*)renderInformationBase, type);
    else if (renderInformationBase->isGlobalRenderInformation())
        return findStyleByTypeList((GlobalRenderInformation*)renderInformationBase, type);

    return NULL;
}

Style* findStyleByTypeList(LocalRenderInformation* localRenderInformation, const std::string& type) {
    for (unsigned int i = 0; i < localRenderInformation->getNumLocalStyles(); i++) {
        std::set<std::string> typeList = localRenderInformation->getLocalStyle(i)->getTypeList();
        if (typeList.find(type) != typeList.end())
            return localRenderInformation->getLocalStyle(i);
    }

    return NULL;
}

Style* findStyleByTypeList(GlobalRenderInformation* globalRenderInformation, const std::string& type) {
    for (unsigned int i = 0; i < globalRenderInformation->getNumGlobalStyles(); i++) {
        std::set<std::string> typeList = globalRenderInformation->getGlobalStyle(i)->getTypeList();
        if (typeList.find(type) != typeList.end())
            return globalRenderInformation->getGlobalStyle(i);
    }

    return NULL;
}

const std::string getStyleType(GraphicalObject* graphicalObject) {
    if (graphicalObject) {
        if (isCompartmentGlyph(graphicalObject))
            return "COMPARTMENTGLYPH";
        else if (isSpeciesGlyph(graphicalObject))
            return "SPECIESGLYPH";
        else if (isReactionGlyph(graphicalObject))
            return "REACTIONGLYPH";
        else if (isSpeciesReferenceGlyph(graphicalObject))
            return "SPECIESREFERENCEGLYPH";
        else if (isTextGlyph(graphicalObject))
            return "TEXTGLYPH";

        return "GRAPHICALOBJECT";
    }

    return "";
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
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setStroke("darkcyan");
    rectangle->setStrokeWidth(2.0);
    rectangle->setFill("lightgray");
    rectangle->setRX(RelAbsVector(0.0, 5.0));
    rectangle->setRY(RelAbsVector(0.0, 5.0));
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
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setStroke("black");
    rectangle->setStrokeWidth(2.0);
    rectangle->setFill("white");
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
    Ellipse* ellipse = renderGroup->createEllipse();
    setDefaultEllipseShapeFeatures(ellipse);
    ellipse->setStroke("black");
    ellipse->setStrokeWidth(2.0);
    ellipse->setFill("white");
}

void addSpeciesReferenceGlyphsStyles(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
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

void addDefaultColors(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    addWhiteColor(globalRenderInformation, renderPkgNamespaces);
    addBlackColor(globalRenderInformation, renderPkgNamespaces);
    addLightGrayColor(globalRenderInformation, renderPkgNamespaces);
    addDarkCyanColor(globalRenderInformation, renderPkgNamespaces);
    addTealColor(globalRenderInformation, renderPkgNamespaces);
    addSilverColor(globalRenderInformation, renderPkgNamespaces);
}

void addWhiteColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getColorDefinition("white"))
        globalRenderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "white", 255, 255, 255));
}

void addBlackColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getColorDefinition("black"))
        globalRenderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "black", 0, 0, 0));
}

void addLightGrayColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getColorDefinition("lightgray"))
        globalRenderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "lightgray", 211, 211, 211));
}

void addDarkCyanColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getColorDefinition("darkcyan"))
        globalRenderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "darkcyan", 0, 139, 139));
}

void addTealColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getColorDefinition("teal"))
        globalRenderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "teal", 0, 128, 128));
}

void addSilverColor(GlobalRenderInformation* globalRenderInformation, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getColorDefinition("silver"))
        globalRenderInformation->addColorDefinition(createColorDefintion(renderPkgNamespaces, "silver", 192, 192, 192));
}

ColorDefinition* createColorDefintion(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    return new ColorDefinition(renderPkgNamespaces, id, r, g, b, a);
}

void addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    addProductHeadLineEnding(globalRenderInformation, layoutPkgNamespaces, renderPkgNamespaces);
    addModifierHeadLineEnding(globalRenderInformation, layoutPkgNamespaces, renderPkgNamespaces);
    addActivatorHeadLineEnding(globalRenderInformation, layoutPkgNamespaces, renderPkgNamespaces);
    addInhibitorHeadLineEnding(globalRenderInformation, layoutPkgNamespaces, renderPkgNamespaces);
}

void addProductHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getLineEnding("productHead"))
        globalRenderInformation->addLineEnding(createProductHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createProductHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "productHead");
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setProductHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setProductHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Polygon* triangle = renderGroup->createPolygon();
    setDefaultTriangleShapeFeatures(triangle);
    triangle->getElement(1)->setY(RelAbsVector(0.0, 50.0));
    triangle->getElement(2)->setX(RelAbsVector(0.0, 0.0));
    triangle->setStroke("black");
    triangle->setStrokeWidth(2.0);
    triangle->setFill("black");
}

void addModifierHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getLineEnding("modifierHead"))
        globalRenderInformation->addLineEnding(createModifierHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createModifierHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "modifierHead");
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setModifierHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setModifierHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Polygon* diamond = renderGroup->createPolygon();
    setDefaultDiamondShapeFeatures(diamond);
    diamond->setStroke("black");
    diamond->setStrokeWidth(2.0);
    diamond->setFill("white");
}

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getLineEnding("activatorHead"))
        globalRenderInformation->addLineEnding(createActivatorHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
}

LineEnding* createActivatorHeadLineEnding(LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "activatorHead");
    setLineEndingGeneralFeatures(lineEnding, layoutPkgNamespaces);
    setActivatorHeadLineEndingExcluseFeatures(lineEnding, renderPkgNamespaces);
    return lineEnding;
}

void setActivatorHeadLineEndingExcluseFeatures(LineEnding* lineEnding, RenderPkgNamespaces* renderPkgNamespaces) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Ellipse* ellipse = renderGroup->createEllipse();
    setDefaultEllipseShapeFeatures(ellipse);
    ellipse->setStroke("black");
    ellipse->setStrokeWidth(2.0);
    ellipse->setFill("white");
}

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRenderInformation, LayoutPkgNamespaces* layoutPkgNamespaces, RenderPkgNamespaces* renderPkgNamespaces) {
    if (!globalRenderInformation->getLineEnding("inhibitorHead"))
        globalRenderInformation->addLineEnding(createInhibitorHeadLineEnding(layoutPkgNamespaces, renderPkgNamespaces));
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
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setX(RelAbsVector(0.0, 80.0));
    rectangle->setWidth(RelAbsVector(0.0, 20.0));
    rectangle->setRX(RelAbsVector(0.0, 0.0));
    rectangle->setRY(RelAbsVector(0.0, 0.0));
    rectangle->setStroke("black");
    rectangle->setStrokeWidth(2.0);
    rectangle->setFill("black");
}

void setLineEndingGeneralFeatures(LineEnding* lineEnding, LayoutPkgNamespaces* layoutPkgNamespaces) {
    lineEnding->setEnableRotationalMapping(true);
    lineEnding->setBoundingBox(new BoundingBox(layoutPkgNamespaces, lineEnding->getId() + "_bb", -12.0, -6.0, 12.0, 12.0));
}

void setDefaultRectangleShapeFeatures(Rectangle* rectangle) {
    rectangle->setX(RelAbsVector(0.0, 0.0));
    rectangle->setY(RelAbsVector(0.0, 0.0));
    rectangle->setWidth(RelAbsVector(0.0, 100.0));
    rectangle->setHeight(RelAbsVector(0.0, 100.0));
    rectangle->setRX(RelAbsVector(0.0, 10.0));
    rectangle->setRY(RelAbsVector(0.0, 10.0));
}

void setDefaultEllipseShapeFeatures(Ellipse* ellipse) {
    ellipse->setCX(RelAbsVector(0.0, 50.0));
    ellipse->setCY(RelAbsVector(0.0, 50.0));
    ellipse->setRX(RelAbsVector(0.0, 50.0));
    ellipse->setRY(RelAbsVector(0.0, 50.0));
}

void setDefaultTriangleShapeFeatures(Polygon* triangle) {
    RenderPoint* point = NULL;
    point = triangle->createPoint();
    point->setX(RelAbsVector(0.0, 0.0));
    point->setY(RelAbsVector(0.0, 0.0));
    point = triangle->createPoint();
    point->setX(RelAbsVector(0.0, 100.0));
    point->setY(RelAbsVector(0.0, 0.0));
    point = triangle->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 100.0));
}

void setDefaultDiamondShapeFeatures(Polygon* diamond) {
    RenderPoint* point = NULL;
    point = diamond->createPoint();
    point->setX(RelAbsVector(0.0, 0.0));
    point->setY(RelAbsVector(0.0, 50.0));
    point = diamond->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 0.0));
    point = diamond->createPoint();
    point->setX(RelAbsVector(0.0, 100.0));
    point->setY(RelAbsVector(0.0, 50.0));
    point = diamond->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 100.0));
}

void setDefaultPentagonShapeFeatures(Polygon* pentagon) {
    const double pi = 3.14159265;
    RenderPoint* point = NULL;
    point = pentagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 - std::sin(0.4 * pi))));
    point->setY(RelAbsVector(0.0, 50. * (1 - std::cos(0.4 * pi))));
    point = pentagon->createPoint();
    point->setX(RelAbsVector(0.0, 50.));
    point->setY(RelAbsVector(0.0, 0.));
    point = pentagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 + std::sin(0.4 * pi))));
    point->setY(RelAbsVector(0.0, 50. * (1 - std::cos(0.4 * pi))));
    point = pentagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 + std::sin(0.2 * pi))));
    point->setY(RelAbsVector(0.0, 50. * (1 + std::cos(0.2 * pi))));
    point = pentagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 - std::sin(0.2 * pi))));
    point->setY(RelAbsVector(0.0, 50. * (1 + std::cos(0.2 * pi))));
}

void setDefaultHexagonShapeFeatures(Polygon* hexagon) {
    RenderPoint* point = NULL;
    point = hexagon->createPoint();
    point->setX(RelAbsVector(0.0, 0.0));
    point->setY(RelAbsVector(0.0, 25.0));
    point = hexagon->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 0.0));
    point = hexagon->createPoint();
    point->setX(RelAbsVector(0.0, 100.0));
    point->setY(RelAbsVector(0.0, 25.0));
    point = hexagon->createPoint();
    point->setX(RelAbsVector(0.0, 100.0));
    point->setY(RelAbsVector(0.0, 75.0));
    point = hexagon->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 100.0));
    point = hexagon->createPoint();
    point->setX(RelAbsVector(0.0, 0.0));
    point->setY(RelAbsVector(0.0, 75.0));
}

void setDefaultOctagonShapeFeatures(Polygon* octagon) {
    const double pi = 3.14159265;
    RenderPoint* point = NULL;
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 0.0));
    point->setY(RelAbsVector(0.0, 50.0));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 - std::cos(pi / 4.0))));
    point->setY(RelAbsVector(0.0, 50. * (1 - std::sin(pi / 4.0))));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 0.0));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 + std::cos(pi / 4.0))));
    point->setY(RelAbsVector(0.0, 50. * (1 - std::sin(pi / 4.0))));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 100.0));
    point->setY(RelAbsVector(0.0, 50.0));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 + std::cos(pi / 4.0))));
    point->setY(RelAbsVector(0.0, 50. * (1 + std::sin(pi / 4.0))));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 50.0));
    point->setY(RelAbsVector(0.0, 100.0));
    point = octagon->createPoint();
    point->setX(RelAbsVector(0.0, 50. * (1 - std::cos(pi / 4.0))));
    point->setY(RelAbsVector(0.0, 50. * (1 + std::sin(pi / 4.0))));
}

void setDefaultRenderCurveShapeFeatures(RenderCurve* renderCurve) {
    RenderPoint* point = NULL;
    point = renderCurve->createPoint();
    point->setX(RelAbsVector(0.0, 0.0));
    point->setY(RelAbsVector(0.0, 50.0));
    point = renderCurve->createPoint();
    point->setX(RelAbsVector(0.0, 100.0));
    point->setY(RelAbsVector(0.0, 50.0));
}

void setDefaultImageShapeFeatures(Image* image) {
    image->setX(RelAbsVector(0.0, 0.0));
    image->setY(RelAbsVector(0.0, 0.0));
    image->setWidth(RelAbsVector(0.0, 100.0));
    image->setHeight(RelAbsVector(0.0, 100.0));
}

const bool isValidBackgroundColorValue(const std::string& backgroundColor) {
    return isValidColorValue(backgroundColor);
}

const bool isValidColorValue(const std::string& value) {
    std::vector<std::string> html_color_names;
    html_color_names = {"aliceblue", "antiquewhite", "aqua", "aquamarine", "azure",
                        "beige", "bisque", "black", "blanchedalmond", "blue",
                        "blueviolet", "brown", "burlywood", "cadetblue", "chartreuse",
                        "chocolate", "coral", "cornflowerblue", "cornsilk", "crimson",
                        "cyan", "darkblue", "darkcyan", "darkgoldenrod", "darkgray",
                        "darkgreen", "darkkhaki", "darkmagenta", "darkolivegreen",
                        "darkorange", "darkorchid", "darkred", "darksalmon", "darkseagreen",
                        "darkslateblue", "darkslategray", "darkturquoise", "darkviolet",
                        "deeppink", "deepskyblue", "dimgray", "dodgerblue", "firebrick",
                        "floralwhite", "forestgreen", "fuchsia", "gainsboro", "ghostwhite",
                        "gold", "goldenrod", "gray", "green", "greenyellow", "honeydew",
                        "hotpink", "indianred", "indigo", "ivory", "khaki", "lavender",
                        "lavenderblush", "lawngreen", "lemonchiffon", "lightblue", "lightcoral",
                        "lightcyan", "lightgoldenrodyellow", "lightgreen", "lightgrey",
                        "lightpink","lightsalmon", "lightseagreen", "lightskyblue",
                        "lightslategray", "lightsteelblue", "lightyellow", "lime", "limegreen",
                        "linen", "magenta", "maroon", "mediumaquamarine", "mediumblue",
                        "mediumorchid", "mediumpurple", "mediumseagreen", "mediumslateblue",
                        "mediumspringgreen", "mediumturquoise", "mediumvioletred", "midnightblue",
                        "mintcream", "mistyrose", "moccasin", "navajowhite", "navy", "oldlace",
                        "olive", "olivedrab", "orange", "orangered", "orchid", "palegoldenrod",
                        "palegreen", "paleturquoise", "palevioletred", "papayawhip", "peachpuff",
                        "peru", "pink", "plum", "powderblue", "purple", "red", "rosybrown",
                        "royalblue", "saddlebrown", "salmon", "sandybrown", "seagreen","seashell",
                        "sienna", "silver", "skyblue", "slateblue", "slategray", "snow","springgreen",
                        "steelblue", "tan", "teal", "thistle", "tomato", "turquoise", "violet",
                        "wheat", "white", "whitesmoke", "yellow", "yellowgreen"};
    for (unsigned int i = 0; i < html_color_names.size(); i++) {
        if (stringCompare(html_color_names.at(i), std::to_lower(value)))
            return true;
    }

    std::vector<std::string> hex_color_codes;
    hex_color_codes = {"#F0F8FF", "#FAEBD7", "#00FFFF", "#7FFFD4", "#F0FFFF", "#F5F5DC", "#FFE4C4",
                        "#000000", "#FFEBCD", "#0000FF", "#8A2BE2", "#A52A2A", "#DEB887", "#5F9EA0",
                        "#7FFF00", "#D2691E", "#FF7F50", "#6495ED", "#FFF8DC", "#DC143C", "#00FFFF",
                        "#00008B", "#008B8B", "#B8860B", "#A9A9A9", "#006400", "#BDB76B", "#8B008B",
                        "#556B2F", "#FF8C00", "#9932CC", "#8B0000", "#E9967A", "#8FBC8F", "#483D8B",
                        "#2F4F4F", "#00CED1", "#9400D3", "#FF1493", "#00BFFF", "#696969", "#1E90FF",
                        "#B22222", "#FFFAF0", "#228B22", "#FF00FF", "#DCDCDC", "#F8F8FF", "#FFD700",
                        "#DAA520", "#808080", "#008000", "#ADFF2F", "#F0FFF0", "#FF69B4", "#CD5C5C",
                        "#4B0082", "#FFFFF0", "#F0E68C", "#E6E6FA", "#FFF0F5", "#7CFC00", "#FFFACD",
                        "#ADD8E6", "#F08080", "#E0FFFF", "#FAFAD2", "#90EE90", "#D3D3D3", "#FFB6C1",
                        "#FFA07A", "#20B2AA", "#87CEFA", "#778899", "#B0C4DE", "#FFFFE0", "#00FF00",
                        "#32CD32", "#FAF0E6", "#FF00FF", "#800000", "#66CDAA", "#0000CD", "#BA55D3",
                        "#9370DB", "#3CB371", "#7B68EE", "#00FA9A", "#48D1CC", "#C71585", "#191970",
                        "#F5FFFA", "#FFE4E1", "#FFE4B5", "#FFDEAD", "#000080", "#FDF5E6", "#808000",
                        "#6B8E23", "#FFA500", "#FF4500", "#DA70D6", "#EEE8AA", "#98FB98", "#AFEEEE",
                        "#DB7093", "#FFEFD5", "#FFDAB9", "#CD853F", "#FFC0CB", "#DDA0DD", "#B0E0E6",
                        "#800080", "#FF0000", "#BC8F8F", "#4169E1", "#8B4513", "#FA8072", "#F4A460",
                        "#2E8B57", "#FFF5EE", "#A0522D", "#C0C0C0", "#87CEEB", "#6A5ACD", "#708090",
                        "#FFFAFA", "#00FF7F", "#4682B4", "#D2B48C", "#008080", "#D8BFD8", "#FF6347",
                        "#40E0D0", "#EE82EE", "#F5DEB3", "#FFFFFF", "#F5F5F5", "#FFFF00", "#9ACD32"};
    for (unsigned int i = 0; i < hex_color_codes.size(); i++) {
        if (stringCompare(hex_color_codes.at(i), value))
            return true;
    }

    return false;
}

const bool isValidSpreadMethodValue(const std::string& spreadMethod) {
    if (stringCompare(spreadMethod, "pad"))
        return true;
    else if (stringCompare(spreadMethod, "reflect"))
        return true;
    else if (stringCompare(spreadMethod, "repeat"))
        return true;

    return false;
}

const bool isValidOffsetValue(const RelAbsVector& offset) {
    return isValidRelAbsVectorPositiveValue(offset);
}

const bool isValidStopColorValue(const std::string& stopColor) {
    return isValidColorValue(stopColor);
}

const bool isValidGradientX1Value(const RelAbsVector& x1) {
    return isValidRelAbsVectorPositiveValue(x1);
}

const bool isValidGradientX2Value(const RelAbsVector& x2) {
    return isValidRelAbsVectorPositiveValue(x2);
}

const bool isValidGradientY1Value(const RelAbsVector& y1) {
    return isValidRelAbsVectorPositiveValue(y1);
}

const bool isValidGradientY2Value(const RelAbsVector& y2) {
    return isValidRelAbsVectorPositiveValue(y2);
}

const bool isValidGradientCxValue(const RelAbsVector& cx) {
    return isValidRelAbsVectorPositiveValue(cx);
}

const bool isValidGradientCyValue(const RelAbsVector& cy) {
    return isValidRelAbsVectorPositiveValue(cy);
}

const bool isValidGradientFxValue(const RelAbsVector& fx) {
    return isValidRelAbsVectorPositiveValue(fx);
}

const bool isValidGradientFyValue(const RelAbsVector& fy) {
    return isValidRelAbsVectorPositiveValue(fy);
}

const bool isValidGradientRValue(const RelAbsVector& r) {
    return isValidRelAbsVectorPositiveValue(r);
}

const bool isValidEnableRotationalMappingValue(const bool& enableRotationalMapping) {
    return true;
}

const bool isValidStrokeColorValue(const std::string& stroke) {
    return isValidColorValue(stroke);
}

const bool isValidStrokeWidthValue(const double& strokeWidth) {
    if (strokeWidth > 0.0001)
        return true;

    return false;
}

const bool isValidStrokeDashArrayValue(const std::vector<unsigned int>& strokeDashArray) {
    for (unsigned int i = 0; i < strokeDashArray.size(); i++) {
        if (!isValidStrokeDashValue(strokeDashArray.at(i)))
            return false;
    }

    return true;
}

const bool isValidStrokeDashValue(unsigned int dash) {
    if (dash > 0.000)
        return true;

    return false;
}

const bool isValidFontColorValue(const std::string& fontColor) {
    return isValidColorValue(fontColor);
}

const bool isValidFontFamilyValue(const std::string& fontFamily) {
    if (stringCompare(fontFamily, "serif"))
        return true;
    else if (stringCompare(fontFamily, "sans-serif"))
        return true;
    else if (stringCompare(fontFamily, "monospace"))
        return true;

    return false;
}

const bool isValidFontSizeValue(const RelAbsVector& fontSize) {
    return isValidRelAbsVectorPositiveValue(fontSize);
}

const bool isValidFontWeightValue(const std::string& fontWeight) {
    if (stringCompare(fontWeight, "bold"))
        return true;
    else if (stringCompare(fontWeight, "normal"))
        return true;

    return false;
}

const bool isValidFontStyleValue(const std::string& fontStyle) {
    if (stringCompare(fontStyle, "italic"))
        return true;
    else if (stringCompare(fontStyle, "normal"))
        return true;

    return false;
}

const bool isValidTextAnchorValue(const std::string& textAnchor) {
    if (stringCompare(textAnchor, "start"))
        return true;
    else if (stringCompare(textAnchor, "middle"))
        return true;
    else if (stringCompare(textAnchor, "end"))
        return true;

    return false;
}

const bool isValidVTextAnchorValue(const std::string& vtextAnchor) {
    if (stringCompare(vtextAnchor, "top"))
        return true;
    else if (stringCompare(vtextAnchor, "middle"))
        return true;
    else if (stringCompare(vtextAnchor, "bottom"))
        return true;
    else if (stringCompare(vtextAnchor, "baseline"))
        return true;

    return false;
}

const bool isValidFillColorValue(const std::string& fillColor) {
    return isValidColorValue(fillColor);
}

const bool isValidFillRuleValue(const std::string& fillRule) {
    if (stringCompare(fillRule, "nonzero"))
        return true;
    else if (stringCompare(fillRule, "evenodd"))
        return true;

    return false;
}

const bool isValidStartHeadValue(const std::string& startHead) {
    return true;
}

const bool isValidEndHeadValue(const std::string& endHead) {
    return true;
}

const bool isValidGeometricShapeXValue(const RelAbsVector& x) {
    return true;
}

const bool isValidGeometricShapeYValue(const RelAbsVector& y) {
    return true;
}

const bool isValidGeometricShapeWidthValue(const RelAbsVector& width) {
    return isValidRelAbsVectorPositiveValue(width);
}

const bool isValidGeometricShapeHeightValue(const RelAbsVector& height) {
    return isValidRelAbsVectorPositiveValue(height);
}

const bool isValidGeometricShapeRatioValue(const double& ratio) {
    if (ratio > 0.0001)
        return true;

    return false;
}

const bool isValidGeometricShapeCornerCurvatureRadiusX(const RelAbsVector& rx) {
    return isValidRelAbsVectorPositiveValue(rx);
}

const bool isValidGeometricShapeCornerCurvatureRadiusY(const RelAbsVector& ry) {
    return isValidRelAbsVectorPositiveValue(ry);
}

const bool isValidGeometricShapeCenterX(const RelAbsVector& cx) {
    return true;
}

const bool isValidGeometricShapeCenterY(const RelAbsVector& cy) {
    return true;
}

const bool isValidGeometricShapeRadiusX(const RelAbsVector& rx) {
    return isValidRelAbsVectorPositiveValue(rx);
}

const bool isValidGeometricShapeRadiusY(const RelAbsVector& ry) {
    return isValidRelAbsVectorPositiveValue(ry);
}

const bool isValidGeometricShapeElementX(const RelAbsVector& x) {
    return true;
}

const bool isValidGeometricShapeElementY(const RelAbsVector& y) {
    return true;
}

const bool isValidGeometricShapeBasePoint1X(const RelAbsVector& x) {
    return true;
}

const bool isValidGeometricShapeBasePoint1Y(const RelAbsVector& y) {
    return true;
}

const bool isValidGeometricShapeBasePoint2X(const RelAbsVector& y) {
    return true;
}

const bool isValidGeometricShapeBasePoint2Y(const RelAbsVector& y) {
    return true;
}

const bool isValidGeometricShapeHref(const std::string& href) {
    return true;
}

const bool isValidRelAbsVectorPositiveValue(const RelAbsVector& relAbsVectorValue) {
    if (relAbsVectorValue.getAbsoluteValue() > 0.000)
        return true;

    return false;
}

}
