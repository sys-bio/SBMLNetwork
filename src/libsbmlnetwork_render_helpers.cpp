#include "libsbmlnetwork_render_helpers.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_layout_helpers.h"

#include <cmath>

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

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
        std::cerr << "error: Unable to get global render information\n";
    }

    return renderListOfLayoutsPlugin;
}

RenderLayoutPlugin* getRenderLayoutPlugin(SBasePlugin* renderBase) {
    RenderLayoutPlugin* renderLayoutPlugin = NULL;
    try {
        renderLayoutPlugin = dynamic_cast<RenderLayoutPlugin*>(renderBase); }
    catch(std::bad_cast) {
        std::cerr << "error: Unable to get local render information\n";
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

void addDefaultColors(GlobalRenderInformation* globalRenderInformation) {
    addColor(globalRenderInformation, "white");
    addColor(globalRenderInformation, "black");
    addColor(globalRenderInformation, "lightgray");
    addColor(globalRenderInformation, "darkslategray");
    addColor(globalRenderInformation, "darkcyan");
    addColor(globalRenderInformation, "teal");
    addColor(globalRenderInformation, "silver");
}

void addColorsOfDefaultGeometricShapes(SBMLDocument* document, Style* style) {
    addColor(document, style, "white");
    addColor(document, style, "black");
}

void addColorsOfDefaultGeometricShapes(GlobalRenderInformation* globalRenderInformation) {
    addColor(globalRenderInformation, "white");
    addColor(globalRenderInformation, "black");
}

const bool addColor(SBMLDocument* document, Style* style, const std::string &color) {
    if (style) {
        for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
            LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, i);
            for (unsigned int j = 0; j < localRenderInformation->getNumLocalStyles(); j++) {
                if (localRenderInformation->getLocalStyle(j) == style)
                    return addColor(localRenderInformation, color);
            }
        }
        for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
            GlobalRenderInformation* globalRenderInformation = getGlobalRenderInformation(document, i);
            for (unsigned int j = 0; j < globalRenderInformation->getNumGlobalStyles(); j++) {
                if (globalRenderInformation->getGlobalStyle(j) == style)
                    return addColor(globalRenderInformation, color);
            }
        }
    }

    return false;
}

const bool addColor(SBMLDocument* document, LineEnding* lineEnding, const std::string &color) {
    if (lineEnding) {
        for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
            LocalRenderInformation *localRenderInformation = getLocalRenderInformation(document, i);
            for (unsigned int j = 0; j < localRenderInformation->getNumLineEndings(); j++) {
                if (localRenderInformation->getLineEnding(j) == lineEnding)
                    return addColor(localRenderInformation, color);
            }
        }
        for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
            GlobalRenderInformation *globalRenderInformation = getGlobalRenderInformation(document, i);
            for (unsigned int j = 0; j < globalRenderInformation->getNumLineEndings(); j++) {
                if (globalRenderInformation->getLineEnding(j) == lineEnding)
                    return addColor(globalRenderInformation, color);
            }
        }
    }

    return false;
}

const bool addColor(RenderInformationBase* renderInformationBase, const std::string &color) {
    if (!renderInformationBase->getColorDefinition(color) || !renderInformationBase->getColorDefinition(getHtmlColorNameFromHexColorCode(color))) {
        std::string colorId = color;
        std::string colorValue = getHexColorCodeFromHtmlColorName(color);
        if (colorValue.empty()) {
            colorId = getHtmlColorNameFromHexColorCode(color);
            if (!colorId.empty())
                colorValue = color;
        }
        if (!colorId.empty() && !colorValue.empty()) {
            RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(renderInformationBase->getLevel(), renderInformationBase->getVersion());
            renderInformationBase->addColorDefinition(createColorDefinition(renderPkgNamespaces, colorId, colorValue));
            return true;
        }
    }

    return false;
}

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    return new ColorDefinition(renderPkgNamespaces, id, r, g, b, a);
}

ColorDefinition* createColorDefinition(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, const std::string &value) {
    ColorDefinition* colorDefinition = new ColorDefinition(renderPkgNamespaces, id);
    colorDefinition->setValue(value);
    return colorDefinition;
}

void addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation) {
    addProductHeadLineEnding(globalRenderInformation);
    addModifierHeadLineEnding(globalRenderInformation);
    addActivatorHeadLineEnding(globalRenderInformation);
    addInhibitorHeadLineEnding(globalRenderInformation);
}

void addProductHeadLineEnding(GlobalRenderInformation* globalRenderInformation) {
    if (!globalRenderInformation->getLineEnding("productHead")) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        globalRenderInformation->addLineEnding(createProductHeadLineEnding(renderPkgNamespaces));
    }
}

LineEnding* createProductHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "productHead");
    setLineEndingGeneralFeatures(lineEnding);
    setProductHeadLineEndingExclusiveFeatures(lineEnding);
    return lineEnding;
}

void setProductHeadLineEndingExclusiveFeatures(LineEnding* lineEnding) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Polygon* triangle = renderGroup->createPolygon();
    setDefaultTriangleShapeFeatures(triangle);
    triangle->getElement(1)->setY(RelAbsVector(0.0, 50.0));
    triangle->getElement(2)->setX(RelAbsVector(0.0, 0.0));
    triangle->setFill("black");
}

void addModifierHeadLineEnding(GlobalRenderInformation* globalRenderInformation) {
    if (!globalRenderInformation->getLineEnding("modifierHead")) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        globalRenderInformation->addLineEnding(createModifierHeadLineEnding(renderPkgNamespaces));
    }
}

LineEnding* createModifierHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "modifierHead");
    setLineEndingGeneralFeatures(lineEnding);
    setModifierHeadLineEndingExclusiveFeatures(lineEnding);
    return lineEnding;
}

void setModifierHeadLineEndingExclusiveFeatures(LineEnding* lineEnding) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Ellipse* ellipse = renderGroup->createEllipse();
    setDefaultEllipseShapeFeatures(ellipse);
}

void addActivatorHeadLineEnding(GlobalRenderInformation* globalRenderInformation) {
    if (!globalRenderInformation->getLineEnding("activatorHead")) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        globalRenderInformation->addLineEnding(createActivatorHeadLineEnding(renderPkgNamespaces));
    }
}

LineEnding* createActivatorHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "activatorHead");
    setLineEndingGeneralFeatures(lineEnding);
    setActivatorHeadLineEndingExclusiveFeatures(lineEnding);
    return lineEnding;
}

void setActivatorHeadLineEndingExclusiveFeatures(LineEnding* lineEnding) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Polygon* diamond = renderGroup->createPolygon();
    setDefaultDiamondShapeFeatures(diamond);
}

void addInhibitorHeadLineEnding(GlobalRenderInformation* globalRenderInformation) {
    if (!globalRenderInformation->getLineEnding("inhibitorHead")) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        globalRenderInformation->addLineEnding(createInhibitorHeadLineEnding(renderPkgNamespaces));
    }
}

LineEnding* createInhibitorHeadLineEnding(RenderPkgNamespaces* renderPkgNamespaces) {
    LineEnding* lineEnding = new LineEnding(renderPkgNamespaces, "inhibitorHead");
    lineEnding->createGroup();
    setLineEndingGeneralFeatures(lineEnding);
    setInhibitorHeadLineEndingExclusiveFeatures(lineEnding);
    return lineEnding;
}

void setInhibitorHeadLineEndingExclusiveFeatures(LineEnding* lineEnding) {
    RenderGroup* renderGroup = lineEnding->getGroup();
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setX(RelAbsVector(0.0, 80.0));
    rectangle->setWidth(RelAbsVector(0.0, 20.0));
    rectangle->setRX(RelAbsVector(0.0, 0.0));
    rectangle->setRY(RelAbsVector(0.0, 0.0));
}

void setLineEndingGeneralFeatures(LineEnding* lineEnding) {
    lineEnding->setEnableRotationalMapping(true);
    LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(lineEnding->getLevel(), lineEnding->getVersion());
    lineEnding->setBoundingBox(new BoundingBox(layoutPkgNamespaces, lineEnding->getId() + "_bb", -12.0, -6.0, 12.0, 12.0));
}

void addGlobalStyles(GlobalRenderInformation* globalRenderInformation) {
    addCompartmentGlyphGlobalStyle(globalRenderInformation);
    addSpeciesGlyphGlobalStyle(globalRenderInformation);
    addReactionGlyphGlobalStyle(globalRenderInformation);
    addSpeciesReferenceGlyphGlobalStyles(globalRenderInformation);
}

GlobalStyle* createGlobalStyleByType(GlobalRenderInformation* globalRenderInformation, const std::string& type) {
        GlobalStyle* globalStyle = globalRenderInformation->createGlobalStyle();
        globalStyle->setId(getGlobalStyleUniqueId(globalRenderInformation, type));
        globalStyle->addType(type);
        return globalStyle;
}

GlobalStyle* createGlobalStyleByRole(GlobalRenderInformation* globalRenderInformation, const std::string& role) {
    GlobalStyle* globalStyle = globalRenderInformation->createGlobalStyle();
    globalStyle->setId(getGlobalStyleUniqueId(globalRenderInformation, role));
    globalStyle->addRole(role);
    return globalStyle;
}

void addCompartmentGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation) {
    if (!findStyleByTypeList(globalRenderInformation, "COMPARTMENTGLYPH")) {
        GlobalStyle* globalStyle = createGlobalStyleByType(globalRenderInformation, "COMPARTMENTGLYPH");
        RenderGroup* renderGroup = globalStyle->createGroup();
        setCompartmentGlyphRenderGroupFeatures(renderGroup);
        setCompartmentTextGlyphRenderGroupFeatures(renderGroup);
    }
}

void addSpeciesGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation) {
    if (!findStyleByTypeList(globalRenderInformation, "SPECIESGLYPH")) {
        GlobalStyle* globalStyle = createGlobalStyleByType(globalRenderInformation, "SPECIESGLYPH");
        RenderGroup* renderGroup = globalStyle->createGroup();
        setSpeciesGlyphRenderGroupFeatures(renderGroup);
        setSpeciesTextGlyphRenderGroupFeatures(renderGroup);
    }
}

void addReactionGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation) {
    if (!findStyleByTypeList(globalRenderInformation, "REACTIONGLYPH")) {
        GlobalStyle* globalStyle = createGlobalStyleByType(globalRenderInformation, "REACTIONGLYPH");
        RenderGroup* renderGroup = globalStyle->createGroup();
        setReactionGlyphRenderGroupFeatures(renderGroup);
        setReactionTextGlyphRenderGroupFeatures(renderGroup);
    }
}

void addSpeciesReferenceGlyphGlobalStyles(GlobalRenderInformation* globalRenderInformation) {
    if (!findStyleByRoleList(globalRenderInformation, "substrate")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "substrate");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_SUBSTRATE);
    }
    if (!findStyleByRoleList(globalRenderInformation, "sidesubstrate")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "sidesubstrate");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_SIDESUBSTRATE);
    }
    if (!findStyleByRoleList(globalRenderInformation, "product")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "product");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_PRODUCT);
    }
    if (!findStyleByRoleList(globalRenderInformation, "sideproduct")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "sideproduct");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_SIDEPRODUCT);
    }
    if (!findStyleByRoleList(globalRenderInformation, "modifier")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "modifier");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_MODIFIER);
    }
    if (!findStyleByRoleList(globalRenderInformation, "activator")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "activator");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_ACTIVATOR);
    }
    if (!findStyleByRoleList(globalRenderInformation, "inhibitor")) {
        GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, "inhibitor");
        setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), SPECIES_ROLE_INHIBITOR);
    }
}

void addLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation) {
    addCompartmentGlyphsLocalStyles(layout, localRenderInformation);
    addSpeciesGlyphsLocalStyles(layout, localRenderInformation);
    addReactionGlyphsLocalStyles(layout, localRenderInformation);
}

Style* createLocalStyle(RenderInformationBase* localRenderInformation, Style* globalStyle, GraphicalObject* graphicalObject) {
    Style* localStyle = createLocalStyle(localRenderInformation, graphicalObject);
    localStyle->setGroup(globalStyle->getGroup()->clone());
    return localStyle;
}

Style* createLocalStyle(RenderInformationBase* localRenderInformation, GraphicalObject* graphicalObject) {
    LocalStyle* localStyle = NULL;
    if (localRenderInformation->isLocalRenderInformation()) {
        localStyle = ((LocalRenderInformation*)localRenderInformation)->createLocalStyle();
        localStyle->addId(graphicalObject->getId());
        localStyle->setId(graphicalObject->getId() + "_style");
    }

    return localStyle;
}

void addCompartmentGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        addCompartmentGlyphLocalStyle(layout->getCompartmentGlyph(i), localRenderInformation);
        addCompartmentTextGlyphsLocalStyles(layout, localRenderInformation, layout->getCompartmentGlyph(i));
    }
}

void addCompartmentGlyphLocalStyle(CompartmentGlyph* compartmentGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, compartmentGlyph);
    setCompartmentGlyphRenderGroupFeatures(localStyle->createGroup());
}

void addCompartmentTextGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation, CompartmentGlyph* compartmentGlyph) {
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (layout->getTextGlyph(i)->getGraphicalObjectId() == compartmentGlyph->getId())
            addCompartmentTextGlyphLocalStyle(layout->getTextGlyph(i), localRenderInformation);
    }
}

void addCompartmentTextGlyphLocalStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, textGlyph);
    setCompartmentTextGlyphRenderGroupFeatures(localStyle->createGroup());
}

void addSpeciesGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        addSpeciesGlyphLocalStyle(layout->getSpeciesGlyph(i), localRenderInformation);
        addSpeciesTextGlyphsLocalStyles(layout, localRenderInformation, layout->getSpeciesGlyph(i));
    }
}

void addSpeciesGlyphLocalStyle(SpeciesGlyph* speciesGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, speciesGlyph);
    setSpeciesGlyphRenderGroupFeatures(localStyle->createGroup());
}

void addSpeciesTextGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation, SpeciesGlyph* speciesGlyph) {
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (layout->getTextGlyph(i)->getGraphicalObjectId() == speciesGlyph->getId())
            addSpeciesTextGlyphLocalStyle(layout->getTextGlyph(i), localRenderInformation);
    }
}

void addSpeciesTextGlyphLocalStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, textGlyph);
    setSpeciesTextGlyphRenderGroupFeatures(localStyle->createGroup());
}

void addReactionGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        addReactionGlyphLocalStyle(layout->getReactionGlyph(i), localRenderInformation);
        addReactionTextGlyphsLocalStyles(layout, localRenderInformation, layout->getReactionGlyph(i));
        addSpeciesReferenceGlyphsLocalStyles(layout->getReactionGlyph(i), localRenderInformation);
    }
}

void addReactionGlyphLocalStyle(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, reactionGlyph);
    setReactionGlyphRenderGroupFeatures(localStyle->createGroup());
}

void addReactionTextGlyphsLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation, ReactionGlyph* reactionGlyph) {
    for (unsigned int i = 0; i < layout->getNumTextGlyphs(); i++) {
        if (layout->getTextGlyph(i)->getGraphicalObjectId() == reactionGlyph->getId())
            addReactionTextGlyphLocalStyle(layout->getTextGlyph(i), localRenderInformation);
    }
}

void addReactionTextGlyphLocalStyle(TextGlyph* textGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, textGlyph);
    setReactionTextGlyphRenderGroupFeatures(localStyle->createGroup());
}

void addSpeciesReferenceGlyphsLocalStyles(ReactionGlyph* reactionGlyph, LocalRenderInformation* localRenderInformation) {
    for (int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++)
        addSpeciesReferenceGlyphLocalStyle(reactionGlyph->getSpeciesReferenceGlyph(i), localRenderInformation);
}

void addSpeciesReferenceGlyphLocalStyle(SpeciesReferenceGlyph* speciesReferenceGlyph, LocalRenderInformation* localRenderInformation) {
    Style* localStyle = createLocalStyle(localRenderInformation, speciesReferenceGlyph);
    setSpeciesReferenceGlyphRenderGroupFeatures(localStyle->createGroup(), speciesReferenceGlyph->getRole());
}

void setCompartmentGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setStroke("darkcyan");
    rectangle->setStrokeWidth(2.0);
    rectangle->setFill("lightgray");
    rectangle->setRX(RelAbsVector(0.0, 5.0));
    rectangle->setRY(RelAbsVector(0.0, 5.0));
}

void setCompartmentTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup);
    renderGroup->setStroke("darkcyan");
    renderGroup->setFontSize(RelAbsVector(10.0, 0.0));
    renderGroup->setTextAnchor("middle");
    renderGroup->setVTextAnchor("bottom");
}

void setSpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setRX(RelAbsVector(6, 0.0));
    rectangle->setRY(RelAbsVector(3.6, 0.0));
}


void setSpeciesTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup);
    renderGroup->setFontSize(RelAbsVector(24.0, 0.0));
}

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    Ellipse* ellipse = renderGroup->createEllipse();
    setDefaultEllipseShapeFeatures(ellipse);
}

void setReactionTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup);
    renderGroup->setStroke("darkslategray");
    renderGroup->setFontSize(RelAbsVector(12.0, 0.0));
}

void setSpeciesReferenceGlyphRenderGroupFeatures(RenderGroup* renderGroup, SpeciesReferenceRole_t role) {
    setDefault1DShapeFeatures(renderGroup);
    if (role == SPECIES_ROLE_PRODUCT || role == SPECIES_ROLE_SIDEPRODUCT)
        renderGroup->setEndHead("productHead");
    else if (role == SPECIES_ROLE_MODIFIER)
        renderGroup->setEndHead("modifierHead");
    else if (role == SPECIES_ROLE_ACTIVATOR)
        renderGroup->setEndHead("activatorHead");
    else if (role == SPECIES_ROLE_INHIBITOR)
        renderGroup->setEndHead("inhibitorHead");
}

void setGeneralTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    renderGroup->setStroke("black");
    renderGroup->setFontSize(RelAbsVector(24.0, 0.0));
    renderGroup->setFontFamily("sans-serif");
    renderGroup->setFontWeight("normal");
    renderGroup->setFontStyle("normal");
    renderGroup->setTextAnchor("middle");
    renderGroup->setVTextAnchor("middle");
}

void setDefault1DShapeFeatures(GraphicalPrimitive1D* graphicalPrimitive1D) {
    graphicalPrimitive1D->setStroke("black");
    graphicalPrimitive1D->setStrokeWidth(2.0);
}

void setDefault2DShapeFeatures(GraphicalPrimitive2D* graphicalPrimitive2D) {
    setDefault1DShapeFeatures(graphicalPrimitive2D);
    graphicalPrimitive2D->setFill("white");
}

void setDefaultRectangleShapeFeatures(Rectangle* rectangle) {
    setDefault2DShapeFeatures(rectangle);
    rectangle->setX(RelAbsVector(0.0, 0.0));
    rectangle->setY(RelAbsVector(0.0, 0.0));
    rectangle->setWidth(RelAbsVector(0.0, 100.0));
    rectangle->setHeight(RelAbsVector(0.0, 100.0));
    rectangle->setRX(RelAbsVector(0.0, 10.0));
    rectangle->setRY(RelAbsVector(0.0, 10.0));
}

void setDefaultEllipseShapeFeatures(Ellipse* ellipse) {
    setDefault2DShapeFeatures(ellipse);
    ellipse->setCX(RelAbsVector(0.0, 50.0));
    ellipse->setCY(RelAbsVector(0.0, 50.0));
    ellipse->setRX(RelAbsVector(0.0, 50.0));
    ellipse->setRY(RelAbsVector(0.0, 50.0));
    ellipse->setStroke("black");
    ellipse->setStrokeWidth(2.0);
}

void setDefaultTriangleShapeFeatures(Polygon* triangle) {
    setDefault2DShapeFeatures(triangle);
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
    setDefault2DShapeFeatures(diamond);
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
    setDefault2DShapeFeatures(pentagon);
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
    setDefault2DShapeFeatures(hexagon);
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
    setDefault2DShapeFeatures(octagon);
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
    setDefault1DShapeFeatures(renderCurve);
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

const std::string getGlobalStyleUniqueId(GlobalRenderInformation* globalRenderInformation, const std::string& type) {
    unsigned int global_style_iterator = 0;
    while (globalRenderInformation->getGlobalStyle(type + "_style_" + std::to_string(global_style_iterator)))
        global_style_iterator++;
    return type + "_style_" + std::to_string(global_style_iterator);
}

const bool isValidBackgroundColorValue(const std::string& backgroundColor) {
    return isValidColorValue(backgroundColor);
}

const bool isValidSpreadMethodValue(const std::string& spreadMethod) {
    return isValueValid(spreadMethod, getValidSpreadMethodValues());
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

const bool isValidEnableRotationalMappingValue(bool enableRotationalMapping) {
    return true;
}

const bool isValidStrokeColorValue(const std::string& stroke) {
    return isValidColorValue(stroke);
}

const bool isValidStrokeWidthValue(const double& strokeWidth) {
    if (strokeWidth > 0.0001)
        return true;

    std::cerr << "error: stroke width must be greater than 0" << std::endl;
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

    std::cerr << "error: stroke dash value must be greater than 0" << std::endl;
    return false;
}

const bool isValidFontColorValue(const std::string& fontColor) {
    return isValidColorValue(fontColor);
}

const bool isValidFontFamilyValue(const std::string& fontFamily) {
    return true;
}

const bool isValidFontSizeValue(const RelAbsVector& fontSize) {
    return isValidRelAbsVectorPositiveValue(fontSize);
}

const bool isValidFontWeightValue(const std::string& fontWeight) {
    return isValueValid(fontWeight, getValidFontWeightValues());
}

const bool isValidFontStyleValue(const std::string& fontStyle) {
    return isValueValid(fontStyle, getValidFontStyleValues());
}

const bool isValidTextAnchorValue(const std::string& textAnchor) {
    return isValueValid(textAnchor, getValidTextAnchorValues());
}

const bool isValidVTextAnchorValue(const std::string& vtextAnchor) {
    return isValueValid(vtextAnchor, getValidVTextAnchorValues());
}

const bool isValidFillColorValue(const std::string& fillColor) {
    return isValidColorValue(fillColor);
}

const bool isValidFillRuleValue(const std::string& fillRule) {
    return isValueValid(fillRule, getValidFillRuleValues());
}

const bool isValidStartHeadValue(const std::string& startHead) {
    return true;
}

const bool isValidEndHeadValue(const std::string& endHead) {
    return true;
}

const bool isValidGeometricShapeName(const std::string& geometricShapeName) {
    return isValueValid(geometricShapeName, getValidGeometricShapeNameValues());
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

    std::cerr << "error: geometric shape ratio must be greater than 0" << std::endl;
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
    std::cerr << "error: the absolute value of the entered value must be greater than 0" << std::endl;
    return false;
}

const bool isValidColorValue(const std::string& value) {
    std::vector<std::string> htmlColorNames = getValidHtmlColorNames();
    for (unsigned int i = 0; i < htmlColorNames.size(); i++) {
        if (stringCompare(htmlColorNames.at(i), value))
            return true;
    }
    std::vector<std::string> hexColorCodes = getValidHexColorCodes();
    for (unsigned int i = 0; i < hexColorCodes.size(); i++) {
        if (stringCompare(hexColorCodes.at(i), value))
            return true;
    }
    std::cerr << "error: entered value (" << value << ") is not a valid color value" << std::endl;
    return false;
}

const std::string getHexColorCodeFromHtmlColorName(const std::string& htmlColorName) {
    std::vector <std::string> htmlColorNames = getValidHtmlColorNames();
    std::vector <std::string> hexColorCodes = getValidHexColorCodes();
    for (unsigned int i = 0; i < htmlColorNames.size(); i++) {
        if (stringCompare(htmlColorNames.at(i), htmlColorName))
            return hexColorCodes.at(i);
    }

    return "";
}

const std::string getHtmlColorNameFromHexColorCode(const std::string& hexColorCode) {
    std::vector <std::string> hexColorCodes = getValidHexColorCodes();
    std::vector <std::string> htmlColorNames = getValidHtmlColorNames();
    for (unsigned int i = 0; i < hexColorCodes.size(); i++) {
        if (stringCompare(hexColorCodes.at(i), hexColorCode))
            return htmlColorNames.at(i);
    }

    return "";
}

std::vector<std::pair<std::string, std::string>> colorData() {
    std::vector<std::pair<std::string, std::string>> colors;
    colors.push_back(std::make_pair("AliceBlue", "#F0F8FF"));
    colors.push_back(std::make_pair("AntiqueWhite", "#FAEBD7"));
    colors.push_back(std::make_pair("Aqua", "#00FFFF"));
    colors.push_back(std::make_pair("Aquamarine", "#7FFFD4"));
    colors.push_back(std::make_pair("Apricot", "#EB9373"));
    colors.push_back(std::make_pair("Arapawa", "#1A2421"));
    colors.push_back(std::make_pair("Azure", "#F0FFFF"));
    colors.push_back(std::make_pair("AzureRadiance", "#007FFF"));
    colors.push_back(std::make_pair("AquaIsland", "#A1DAD7"));
    colors.push_back(std::make_pair("BayOfMany", "#273A3E"));
    colors.push_back(std::make_pair("Beige", "#F5F5DC"));
    colors.push_back(std::make_pair("Bisque", "#FFE4C4"));
    colors.push_back(std::make_pair("Black", "#000000"));
    colors.push_back(std::make_pair("BlanchedAlmond", "#FFEBCD"));
    colors.push_back(std::make_pair("Blue", "#0000FF"));
    colors.push_back(std::make_pair("BlueRibbon", "#0066FF"));
    colors.push_back(std::make_pair("BlueViolet", "#8A2BE2"));
    colors.push_back(std::make_pair("Brown", "#A52A2A"));
    colors.push_back(std::make_pair("BurlyWood", "#DEB887"));
    colors.push_back(std::make_pair("Buttercup", "#F3AD16"));
    colors.push_back(std::make_pair("CadetBlue", "#5F9EA0"));
    colors.push_back(std::make_pair("CannonPink", "#8E5164"));
    colors.push_back(std::make_pair("Carnation", "#F95A61"));
    colors.push_back(std::make_pair("CarrotOrange", "#ED9121"));
    colors.push_back(std::make_pair("Casal", "#2E2F30"));
    colors.push_back(std::make_pair("CeruleanBlue", "#2A52BE"));
    colors.push_back(std::make_pair("Chartreuse", "#7FFF00"));
    colors.push_back(std::make_pair("Chino", "#D2B7AD"));
    colors.push_back(std::make_pair("Chocolate", "#D2691E"));
    colors.push_back(std::make_pair("Christine", "#E1634F"));
    colors.push_back(std::make_pair("Coral", "#FF7F50"));
    colors.push_back(std::make_pair("CornflowerBlue", "#6495ED"));
    colors.push_back(std::make_pair("Cornsilk", "#FFF8DC"));
    colors.push_back(std::make_pair("CreamCan", "#F5C71A"));
    colors.push_back(std::make_pair("Crimson", "#DC143C"));
    colors.push_back(std::make_pair("Cyan", "#00FFFF"));
    colors.push_back(std::make_pair("DaisyBush", "#4F2398"));
    colors.push_back(std::make_pair("DarkBlue", "#00008B"));
    colors.push_back(std::make_pair("DarkCyan", "#008B8B"));
    colors.push_back(std::make_pair("DarkFern", "#0A6906"));
    colors.push_back(std::make_pair("DarkGoldenRod", "#B8860B"));
    colors.push_back(std::make_pair("DarkGray", "#A9A9A9"));
    colors.push_back(std::make_pair("DarkGreen", "#006400"));
    colors.push_back(std::make_pair("DarkIndigo", "#4B0082"));
    colors.push_back(std::make_pair("DarkKhaki", "#BDB76B"));
    colors.push_back(std::make_pair("DarkMagenta", "#8B008B"));
    colors.push_back(std::make_pair("DarkOliveGreen", "#556B2F"));
    colors.push_back(std::make_pair("DarkOrange", "#FF8C00"));
    colors.push_back(std::make_pair("DarkOrchid", "#9932CC"));
    colors.push_back(std::make_pair("DarkRed", "#8B0000"));
    colors.push_back(std::make_pair("DarkSalmon", "#E9967A"));
    colors.push_back(std::make_pair("DarkSeaGreen", "#8FBC8F"));
    colors.push_back(std::make_pair("DarkSlateBlue", "#483D8B"));
    colors.push_back(std::make_pair("DarkSlateGray", "#2F4F4F"));
    colors.push_back(std::make_pair("DarkTurquoise", "#00CED1"));
    colors.push_back(std::make_pair("DarkViolet", "#9400D3"));
    colors.push_back(std::make_pair("DeepPink", "#FF1493"));
    colors.push_back(std::make_pair("DeepSkyBlue", "#00BFFF"));
    colors.push_back(std::make_pair("DimGray", "#696969"));
    colors.push_back(std::make_pair("DiSerria", "#DAA520"));
    colors.push_back(std::make_pair("DodgerBlue", "#1E90FF"));
    colors.push_back(std::make_pair("Domino", "#8A2008"));
    colors.push_back(std::make_pair("DullLavender", "#A899E6"));
    colors.push_back(std::make_pair("EastSide", "#AC91CE"));
    colors.push_back(std::make_pair("Elm", "#027877"));
    colors.push_back(std::make_pair("Everglade", "#1A2421"));
    colors.push_back(std::make_pair("Fern", "#4F7942"));
    colors.push_back(std::make_pair("FireBrick", "#B22222"));
    colors.push_back(std::make_pair("Fiery Orange", "#A24510"));
    colors.push_back(std::make_pair("FloralWhite", "#FFFAF0"));
    colors.push_back(std::make_pair("ForestGreen", "#228B22"));
    colors.push_back(std::make_pair("FrenchRose", "#F64A8A"));
    colors.push_back(std::make_pair("FruitSalad", "#4F9D5D"));
    colors.push_back(std::make_pair("Fuchsia", "#FF00FF"));
    colors.push_back(std::make_pair("Gainsboro", "#DCDCDC"));
    colors.push_back(std::make_pair("GhostWhite", "#F8F8FF"));
    colors.push_back(std::make_pair("Glade Green", "#4A6B4E"));
    colors.push_back(std::make_pair("Gold", "#FFD700"));
    colors.push_back(std::make_pair("GoldenGrass", "#D9B612"));
    colors.push_back(std::make_pair("GoldenRod", "#DAA520"));
    colors.push_back(std::make_pair("Gondola", "#211916"));
    colors.push_back(std::make_pair("Gray", "#808080"));
    colors.push_back(std::make_pair("GrannySmithApple", "#A8E4A0"));
    colors.push_back(std::make_pair("Green", "#008000"));
    colors.push_back(std::make_pair("GreenYellow", "#ADFF2F"));
    colors.push_back(std::make_pair("GunSmoke", "#828685"));
    colors.push_back(std::make_pair("HawaiianTan", "#9D5616"));
    colors.push_back(std::make_pair("Hemlock", "#5E5D3B"));
    colors.push_back(std::make_pair("Hibiscus", "#AE4560"));
    colors.push_back(std::make_pair("HoneyDew", "#F0FFF0"));
    colors.push_back(std::make_pair("Hopbush", "#D5853E"));
    colors.push_back(std::make_pair("HotPink", "#FF69B4"));
    colors.push_back(std::make_pair("IndianRed", "#CD5C5C"));
    colors.push_back(std::make_pair("Indigo", "#4B0082"));
    colors.push_back(std::make_pair("Ivory", "#FFFFF0"));
    colors.push_back(std::make_pair("Jaffa", "#EF8633"));
    colors.push_back(std::make_pair("Java", "#32303D"));
    colors.push_back(std::make_pair("Khaki", "#F0E68C"));
    colors.push_back(std::make_pair("Lavender", "#E6E6FA"));
    colors.push_back(std::make_pair("LavenderBlush", "#FFF0F5"));
    colors.push_back(std::make_pair("LawnGreen", "#7CFC00"));
    colors.push_back(std::make_pair("LemonChiffon", "#FFFACD"));
    colors.push_back(std::make_pair("LightBlue", "#ADD8E6"));
    colors.push_back(std::make_pair("LightCoral", "#F08080"));
    colors.push_back(std::make_pair("LightCyan", "#E0FFFF"));
    colors.push_back(std::make_pair("LightGoldenRodYellow", "#FAFAD2"));
    colors.push_back(std::make_pair("LightGray", "#D3D3D3"));
    colors.push_back(std::make_pair("LightGreen", "#90EE90"));
    colors.push_back(std::make_pair("LightOrchid", "#E29CD2"));
    colors.push_back(std::make_pair("LightPink", "#FFB6C1"));
    colors.push_back(std::make_pair("LightSalmon", "#FFA07A"));
    colors.push_back(std::make_pair("LightSeaGreen", "#20B2AA"));
    colors.push_back(std::make_pair("LightSkyBlue", "#87CEFA"));
    colors.push_back(std::make_pair("LightSlateGray", "#778899"));
    colors.push_back(std::make_pair("LightSteelBlue", "#B0C4DE"));
    colors.push_back(std::make_pair("LightYellow", "#FFFFE0"));
    colors.push_back(std::make_pair("Lime", "#00FF00"));
    colors.push_back(std::make_pair("LimeGreen", "#32CD32"));
    colors.push_back(std::make_pair("Linen", "#FAF0E6"));
    colors.push_back(std::make_pair("LunarGreen", "#3A7D02"));
    colors.push_back(std::make_pair("LuckyPoint", "#202078"));
    colors.push_back(std::make_pair("Magenta", "#FF00FF"));
    colors.push_back(std::make_pair("Mandy", "#D57C6B"));
    colors.push_back(std::make_pair("Maroon", "#800000"));
    colors.push_back(std::make_pair("MediumAquaMarine", "#66CDAA"));
    colors.push_back(std::make_pair("MediumBlue", "#0000CD"));
    colors.push_back(std::make_pair("MediumOrchid", "#BA55D3"));
    colors.push_back(std::make_pair("MediumPurple", "#9370DB"));
    colors.push_back(std::make_pair("MediumSeaGreen", "#3CB371"));
    colors.push_back(std::make_pair("MediumSlateBlue", "#7B68EE"));
    colors.push_back(std::make_pair("MediumSpringGreen", "#00FA9A"));
    colors.push_back(std::make_pair("MediumTurquoise", "#48D1CC"));
    colors.push_back(std::make_pair("MediumVioletRed", "#C71585"));
    colors.push_back(std::make_pair("MexicanRed", "#A72525"));
    colors.push_back(std::make_pair("MidnightBlue", "#191970"));
    colors.push_back(std::make_pair("MintCream", "#F5FFFA"));
    colors.push_back(std::make_pair("MineShaft", "#323232"));
    colors.push_back(std::make_pair("MistyRose", "#FFE4E1"));
    colors.push_back(std::make_pair("Moccasin", "#FFE4B5"));
    colors.push_back(std::make_pair("Mondo", "#4A3C30"));
    colors.push_back(std::make_pair("MonteCarlo", "#78A39C"));
    colors.push_back(std::make_pair("Nandor", "#4B3D2A"));
    colors.push_back(std::make_pair("NavajoWhite", "#FFDEAD"));
    colors.push_back(std::make_pair("Navy", "#000080"));
    colors.push_back(std::make_pair("Ochre", "#C77434"));
    colors.push_back(std::make_pair("OldLace", "#FDF5E6"));
    colors.push_back(std::make_pair("Olive", "#808000"));
    colors.push_back(std::make_pair("OliveDrab", "#6B8E23"));
    colors.push_back(std::make_pair("Orange", "#FFA500"));
    colors.push_back(std::make_pair("OrangePeel", "#FFA500"));
    colors.push_back(std::make_pair("OrangeRed", "#FF4500"));
    colors.push_back(std::make_pair("Orchid", "#DA70D6"));
    colors.push_back(std::make_pair("PaleGoldenRod", "#EEE8AA"));
    colors.push_back(std::make_pair("PaleGreen", "#98FB98"));
    colors.push_back(std::make_pair("PaleTurquoise", "#AFEEEE"));
    colors.push_back(std::make_pair("PaleVioletRed", "#DB7093"));
    colors.push_back(std::make_pair("PapayaWhip", "#FFEFD5"));
    colors.push_back(std::make_pair("Paradiso", "#35A793"));
    colors.push_back(std::make_pair("PeachPuff", "#FFDAB9"));
    colors.push_back(std::make_pair("Perano", "#7F7F7F"));
    colors.push_back(std::make_pair("Peru", "#CD853F"));
    colors.push_back(std::make_pair("Pewter", "#96A8A1"));
    colors.push_back(std::make_pair("PictonBlue", "#45B1E8"));
    colors.push_back(std::make_pair("Pink", "#FFC0CB"));
    colors.push_back(std::make_pair("Plum", "#DDA0DD"));
    colors.push_back(std::make_pair("PowderBlue", "#B0E0E6"));
    colors.push_back(std::make_pair("PuertoRico", "#3B69D6"));
    colors.push_back(std::make_pair("Pumice", "#C2CAC4"));
    colors.push_back(std::make_pair("Purple", "#800080"));
    colors.push_back(std::make_pair("PurpleHeart", "#69359C"));
    colors.push_back(std::make_pair("RebeccaPurple", "#663399"));
    colors.push_back(std::make_pair("Red", "#FF0000"));
    colors.push_back(std::make_pair("RedDamask", "#DA6A41"));
    colors.push_back(std::make_pair("Riptide", "#8BE6D8"));
    colors.push_back(std::make_pair("RiverBed", "#434A59"));
    colors.push_back(std::make_pair("RosyBrown", "#BC8F8F"));
    colors.push_back(std::make_pair("RoyalBlue", "#4169E1"));
    colors.push_back(std::make_pair("RoyalPurple", "#6B3FA0"));
    colors.push_back(std::make_pair("SaddleBrown", "#8B4513"));
    colors.push_back(std::make_pair("Sage", "#9EAD3D"));
    colors.push_back(std::make_pair("Salmon", "#FA8072"));
    colors.push_back(std::make_pair("SandyBrown", "#F4A460"));
    colors.push_back(std::make_pair("SanJuan", "#334E75"));
    colors.push_back(std::make_pair("SeaGreen", "#2E8B57"));
    colors.push_back(std::make_pair("SeaShell", "#FFF5EE"));
    colors.push_back(std::make_pair("Seance", "#721757"));
    colors.push_back(std::make_pair("Shiraz", "#B52D42"));
    colors.push_back(std::make_pair("Sienna", "#A0522D"));
    colors.push_back(std::make_pair("Silver", "#C0C0C0"));
    colors.push_back(std::make_pair("SkyBlue", "#87CEEB"));
    colors.push_back(std::make_pair("SlateBlue", "#6A5ACD"));
    colors.push_back(std::make_pair("SlateGray", "#708090"));
    colors.push_back(std::make_pair("Snow", "#FFFAFA"));
    colors.push_back(std::make_pair("SpringGreen", "#00FF7F"));
    colors.push_back(std::make_pair("SteelBlue", "#4682B4"));
    colors.push_back(std::make_pair("Studio", "#714AB2"));
    colors.push_back(std::make_pair("Sunglo", "#E16865"));
    colors.push_back(std::make_pair("Tan", "#D2B48C"));
    colors.push_back(std::make_pair("Teal", "#008080"));
    colors.push_back(std::make_pair("TerraCotta", "#E2725B"));
    colors.push_back(std::make_pair("Thistle", "#D8BFD8"));
    colors.push_back(std::make_pair("Thunderbird", "#C02B18"));
    colors.push_back(std::make_pair("TiaMaria", "#C1440E"));
    colors.push_back(std::make_pair("TobaccoBrown", "#715D47"));
    colors.push_back(std::make_pair("GladeGreen", "#4A6B4E"));
    colors.push_back(std::make_pair("Tomato", "#FF6347"));
    colors.push_back(std::make_pair("TomThumb", "#273E33"));
    colors.push_back(std::make_pair("TotemPole", "#991B07"));
    colors.push_back(std::make_pair("Turquoise", "#40E0D0"));
    colors.push_back(std::make_pair("Vesuvius", "#AD975A"));
    colors.push_back(std::make_pair("Violet", "#EE82EE"));
    colors.push_back(std::make_pair("WaikawaGray", "#5D7291"));
    colors.push_back(std::make_pair("Wheat", "#F5DEB3"));
    colors.push_back(std::make_pair("White", "#FFFFFF"));
    colors.push_back(std::make_pair("WhiteSmoke", "#F5F5F5"));
    colors.push_back(std::make_pair("Yuma", "#CFAB7A"));
    colors.push_back(std::make_pair("Yellow", "#FFFF00"));
    colors.push_back(std::make_pair("YellowGreen", "#9ACD32"));

    return colors;
}

std::vector<std::string> getValidHtmlColorNames() {
    std::vector<std::string> htmlColorNames;
    for (unsigned int i = 0; i < colorData().size(); i++) {
        htmlColorNames.push_back(colorData().at(i).first);
    }

    return htmlColorNames;
}

std::vector<std::string> getValidHexColorCodes() {
    std::vector<std::string> hexColorCodes;
    for (unsigned int i = 0; i < colorData().size(); i++) {
        hexColorCodes.push_back(colorData().at(i).second);
    }

    return hexColorCodes;
}

std::vector<std::string> getValidSpreadMethodValues() {
    std::vector <std::string> spreadMethods;
    spreadMethods.push_back("pad");
    spreadMethods.push_back("reflect");
    spreadMethods.push_back("repeat");
    return spreadMethods;
}

std::vector<std::string> getValidFontWeightValues() {
    std::vector <std::string> fontWeights;
    fontWeights.push_back("normal");
    fontWeights.push_back("bold");
    return fontWeights;
}

std::vector<std::string> getValidFontStyleValues() {
    std::vector <std::string> fontStyles;
    fontStyles.push_back("normal");
    fontStyles.push_back("italic");
    return fontStyles;
}

std::vector<std::string> getValidTextAnchorValues() {
    std::vector <std::string> textAnchors;
    textAnchors.push_back("start");
    textAnchors.push_back("middle");
    textAnchors.push_back("end");
    return textAnchors;
}

std::vector<std::string> getValidVTextAnchorValues() {
    std::vector <std::string> vTextAnchors;
    vTextAnchors.push_back("top");
    vTextAnchors.push_back("middle");
    vTextAnchors.push_back("bottom");
    vTextAnchors.push_back("baseline");
    return vTextAnchors;
}

std::vector<std::string> getValidFillRuleValues() {
    std::vector <std::string> fillRules;
    fillRules.push_back("nonzero");
    fillRules.push_back("evenodd");
    return fillRules;
}

std::vector<std::string> getValidGeometricShapeNameValues() {
    std::vector <std::string> geometricShapeNames;
    geometricShapeNames.push_back("rectangle");
    geometricShapeNames.push_back("ellipse");
    geometricShapeNames.push_back("triangle");
    geometricShapeNames.push_back("diamond");
    geometricShapeNames.push_back("pentagon");
    geometricShapeNames.push_back("hexagon");
    geometricShapeNames.push_back("octagon");
    return geometricShapeNames;
}

}
