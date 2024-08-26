#include "libsbmlnetwork_render_helpers.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_render.h"
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
            return getCompartmentGlyphStyleType();
        else if (isSpeciesGlyph(graphicalObject))
            return getSpeciesGlyphStyleType();
        else if (isReactionGlyph(graphicalObject))
            return getReactionGlyphStyleType();
        else if (isSpeciesReferenceGlyph(graphicalObject))
            return getSpeciesReferenceGlyphStyleType();
        else if (isTextGlyph(graphicalObject))
            return getTextGlyphStyleType();

        return getGraphicalObjectStyleType();
    }

    return "";
}

const std::string getCompartmentGlyphStyleType() {
    return "COMPARTMENTGLYPH";
}

const std::string getSpeciesGlyphStyleType() {
    return "SPECIESGLYPH";
}

const std::string getReactionGlyphStyleType() {
    return "REACTIONGLYPH";
}

const std::string getSpeciesReferenceGlyphStyleType() {
    return "SPECIESREFERENCEGLYPH";
}

const std::string getTextGlyphStyleType() {
    return "TEXTGLYPH";
}

const std::string getGraphicalObjectStyleType() {
    return "GRAPHICALOBJECT";
}

std::vector<std::pair<SpeciesReferenceRole_t, std::string>> getStyleRoles() {
    std::vector<std::pair<SpeciesReferenceRole_t, std::string>> roles;
    roles.push_back(std::make_pair(SPECIES_ROLE_SUBSTRATE, "substrate"));
    roles.push_back(std::make_pair(SPECIES_ROLE_SIDESUBSTRATE, "sidesubstrate"));
    roles.push_back(std::make_pair(SPECIES_ROLE_PRODUCT, "product"));
    roles.push_back(std::make_pair(SPECIES_ROLE_SIDEPRODUCT, "sideproduct"));
    roles.push_back(std::make_pair(SPECIES_ROLE_MODIFIER, "modifier"));
    roles.push_back(std::make_pair(SPECIES_ROLE_ACTIVATOR, "activator"));
    roles.push_back(std::make_pair(SPECIES_ROLE_INHIBITOR, "inhibitor"));
    return roles;
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
    if (isValidHexColorCode(color))
        return addColor(renderInformationBase, getColorIdFromHexColorCode(renderInformationBase, color), color);
    else
        return addColor(renderInformationBase, color, getHexColorCodeFromHtmlColorName(color));
}

const bool addColor(RenderInformationBase* renderInformationBase, const std::string &colorId, const std::string &colorValue) {
    if (!colorId.empty() && !colorValue.empty() && !renderInformationBase->getColorDefinition(colorId)) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(renderInformationBase->getLevel(), renderInformationBase->getVersion());
        renderInformationBase->addColorDefinition(createColorDefinition(renderPkgNamespaces, toLowerCase(colorId), colorValue));
        return true;
    }

    return false;
}

const std::string getColorIdFromHexColorCode(RenderInformationBase* renderInformationBase, const std::string &hexColorCode) {
    std::string colorId = getHtmlColorNameFromHexColorCode(hexColorCode);
    if (colorId.empty())
        colorId = getUniqueColorId(renderInformationBase);

    return colorId;
}

const std::string getUniqueColorId(RenderInformationBase* renderInformationBase) {
    std::string uniqueColorId = "color_0";
    unsigned int i = 0;
    while (renderInformationBase->getColorDefinition(uniqueColorId))
        uniqueColorId = "color_" + std::to_string(i++);

    return uniqueColorId;
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
    if (!findStyleByTypeList(globalRenderInformation, getCompartmentGlyphStyleType())) {
        GlobalStyle* globalStyle = createGlobalStyleByType(globalRenderInformation, getCompartmentGlyphStyleType());
        RenderGroup* renderGroup = globalStyle->createGroup();
        setCompartmentGlyphRenderGroupFeatures(renderGroup);
        setCompartmentTextGlyphRenderGroupFeatures(renderGroup);
    }
}

void addSpeciesGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation) {
    if (!findStyleByTypeList(globalRenderInformation, getSpeciesGlyphStyleType())) {
        GlobalStyle* globalStyle = createGlobalStyleByType(globalRenderInformation, getSpeciesGlyphStyleType());
        RenderGroup* renderGroup = globalStyle->createGroup();
        setSpeciesGlyphRenderGroupFeatures(renderGroup);
        setSpeciesTextGlyphRenderGroupFeatures(renderGroup);
    }
}

void addReactionGlyphGlobalStyle(GlobalRenderInformation* globalRenderInformation) {
    if (!findStyleByTypeList(globalRenderInformation, getReactionGlyphStyleType())) {
        GlobalStyle* globalStyle = createGlobalStyleByType(globalRenderInformation, getReactionGlyphStyleType());
        RenderGroup* renderGroup = globalStyle->createGroup();
        setReactionGlyphRenderGroupFeatures(renderGroup);
        setReactionTextGlyphRenderGroupFeatures(renderGroup);
    }
}

void addSpeciesReferenceGlyphGlobalStyles(GlobalRenderInformation* globalRenderInformation) {
    std::vector<std::pair<SpeciesReferenceRole_t, std::string>> roles = getStyleRoles();
    for (unsigned int i = 0; i < roles.size(); i++) {
        if (!findStyleByRoleList(globalRenderInformation, roles[i].second)) {
            GlobalStyle* globalStyle = createGlobalStyleByRole(globalRenderInformation, roles[i].second);
            setSpeciesReferenceGlyphRenderGroupFeatures(globalStyle->createGroup(), roles[i].first);
        }
    }
}

void addLocalStyles(Layout* layout, LocalRenderInformation* localRenderInformation) {
    addCompartmentGlyphsLocalStyles(layout, localRenderInformation);
    addSpeciesGlyphsLocalStyles(layout, localRenderInformation);
    addReactionGlyphsLocalStyles(layout, localRenderInformation);
}

Style* createLocalStyle(RenderInformationBase* localRenderInformation, Style* globalStyle, GraphicalObject* graphicalObject) {
    Style* localStyle = createLocalStyle(localRenderInformation, graphicalObject);
    if (localStyle && globalStyle)
        localStyle->setGroup(globalStyle->getGroup()->clone());

    return localStyle;
}

Style* createLocalStyle(RenderInformationBase* localRenderInformation, GraphicalObject* graphicalObject) {
    LocalStyle* localStyle = NULL;
    if (localRenderInformation && graphicalObject) {
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
    rectangle->setStroke(getDefaultPredefinedStyleFeatures()["compartment-border-color"]);
    rectangle->setStrokeWidth(std::stod(getDefaultPredefinedStyleFeatures()["compartment-border-width"]));
    rectangle->setFill(getDefaultPredefinedStyleFeatures()["compartment-fill-color"]);
    rectangle->setRX(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["compartment-border-radius-x"]), 0.0));
    rectangle->setRY(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["compartment-border-radius-y"]), 0.0));
}

void setCompartmentTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup);
    renderGroup->setStroke(getDefaultPredefinedStyleFeatures()["compartment-font-color"]);
    renderGroup->setFontSize(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["compartment-font-size"]), 0.0));
    renderGroup->setTextAnchor(getDefaultPredefinedStyleFeatures()["compartment-text-horizontal-alignment"]);
    renderGroup->setVTextAnchor(getDefaultPredefinedStyleFeatures()["compartment-text-vertical-alignment"]);
}

void setSpeciesGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    Rectangle* rectangle = renderGroup->createRectangle();
    setDefaultRectangleShapeFeatures(rectangle);
    rectangle->setRX(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["species-border-radius-x"]), 0.0));
    rectangle->setRY(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["species-border-radius-y"]), 0.0));
}


void setSpeciesTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup);
    renderGroup->setFontSize(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["species-font-size"]), 0.0));
}

void setReactionGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    Ellipse* ellipse = renderGroup->createEllipse();
    setDefaultEllipseShapeFeatures(ellipse);
}

void setReactionTextGlyphRenderGroupFeatures(RenderGroup* renderGroup) {
    setGeneralTextGlyphRenderGroupFeatures(renderGroup);
    renderGroup->setStroke(getDefaultPredefinedStyleFeatures()["reaction-font-color"]);
    renderGroup->setFontSize(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["reaction-font-size"]), 0.0));
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

void setDefaultSquareShapeFeatures(Rectangle* square) {
    setDefault2DShapeFeatures(square);
    square->setX(RelAbsVector(0.0, 0.0));
    square->setY(RelAbsVector(0.0, 0.0));
    square->setWidth(RelAbsVector(0.0, 100.0));
    square->setRatio(1.0);
    square->setRX(RelAbsVector(0.0, 0.0));
    square->setRY(RelAbsVector(0.0, 0.0));
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

void setDefaultCircleShapeFeatures(Ellipse* circle) {
    setDefault2DShapeFeatures(circle);
    circle->setCX(RelAbsVector(0.0, 50.0));
    circle->setCY(RelAbsVector(0.0, 50.0));
    circle->setRX(RelAbsVector(0.0, 50.0));
    circle->setRatio(1.0);
    circle->setStroke("black");
    circle->setStrokeWidth(2.0);
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

void unifyGeometricShapeMutualFeatures(RenderGroup* renderGroup) {
    if (renderGroup && getNumGeometricShapes(renderGroup) > 1) {
        std::string strokeColor = "black";
        bool foundStrokeColor = false;
        double strokeWidth = 2.0;
        bool foundStrokeWidth = false;
        std::string fillColor = "white";
        bool foundFillColor = false;
        for (unsigned int i = 0; i < getNumGeometricShapes(renderGroup); i++) {
            if (isSetStrokeColor(getGeometricShape(renderGroup, i)) && !foundStrokeColor) {
                strokeColor = getStrokeColor(getGeometricShape(renderGroup, i));
                foundStrokeColor = true;
            }
            if (isSetStrokeWidth(getGeometricShape(renderGroup, i)) && !foundStrokeWidth) {
                strokeWidth = getStrokeWidth(getGeometricShape(renderGroup, i));
                foundStrokeWidth = true;
            }
            if (isSetFillColor(getGeometricShape(renderGroup, i)) && !foundFillColor) {
                fillColor = getFillColor(getGeometricShape(renderGroup, i));
                foundFillColor = true;
            }
        }

        for (unsigned int i = 0; i < getNumGeometricShapes(renderGroup); i++) {
            setStrokeColor(getGeometricShape(renderGroup, i), strokeColor);
            setStrokeWidth(getGeometricShape(renderGroup, i), strokeWidth);
            setFillColor(getGeometricShape(renderGroup, i), fillColor);
        }
    }
}

const std::string getGlobalStyleUniqueId(GlobalRenderInformation* globalRenderInformation, const std::string& type) {
    unsigned int global_style_iterator = 0;
    while (globalRenderInformation->getGlobalStyle(type + "_style_" + std::to_string(global_style_iterator)))
        global_style_iterator++;
    return type + "_style_" + std::to_string(global_style_iterator);
}

std::vector<std::string> getPredefinedStyleNames() {
    std::vector<std::string> predefinedStyleNames;
    predefinedStyleNames.push_back("default");
    predefinedStyleNames.push_back("blue ombre");
    predefinedStyleNames.push_back("green ombre");
    predefinedStyleNames.push_back("gray ombre");
    predefinedStyleNames.push_back("red ombre");
    predefinedStyleNames.push_back("orange ombre");
    predefinedStyleNames.push_back("brown ombre");
    predefinedStyleNames.push_back("purple ombre");
    predefinedStyleNames.push_back("purple ombre 2");
    predefinedStyleNames.push_back("black and white");
    predefinedStyleNames.push_back("orange and blue");
    predefinedStyleNames.push_back("purple and yellow");
    predefinedStyleNames.push_back("green and red");
    predefinedStyleNames.push_back("power");
    predefinedStyleNames.push_back("calm");
    predefinedStyleNames.push_back("sunset");
    predefinedStyleNames.push_back("electric");
    predefinedStyleNames.push_back("midnight");
    predefinedStyleNames.push_back("vibrance");
    predefinedStyleNames.push_back("ocean");
    predefinedStyleNames.push_back("forest");
    predefinedStyleNames.push_back("warm tone");
    predefinedStyleNames.push_back("cool tone");
    predefinedStyleNames.push_back("escher");

    return predefinedStyleNames;
}

std::map<std::string, std::string> getPredefinedStyleFeatures(const std::string styleName) {
    std::map<std::string, std::string> styleFeatures;
    std::map<std::string, std::string> defaultStyleFeatures = getDefaultPredefinedStyleFeatures();
    if (stringCompare(styleName, "default"))
        styleFeatures = defaultStyleFeatures;
    else {
        if (stringCompare(styleName, "blue ombre"))
            styleFeatures = getBlueOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "green ombre"))
            styleFeatures = getGreenOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "gray ombre") || stringCompare(styleName, "grey ombre"))
            styleFeatures = getGrayOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "red ombre"))
            styleFeatures = getRedOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "orange ombre"))
            styleFeatures = getOrangeOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "brown ombre"))
            styleFeatures = getBrownOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "purple ombre"))
            styleFeatures = getPurpleOmbrePredefinedStyleFeatures();
        else if (stringCompare(styleName, "purple ombre 2"))
            styleFeatures = getPurpleOmbre2PredefinedStyleFeatures();
        else if (stringCompare(styleName, "black and white"))
            styleFeatures = getBlackAndWhitePredefinedStyleFeatures();
        else if (stringCompare(styleName, "orange and blue"))
            styleFeatures = getOrangeAndBluePredefinedStyleFeatures();
        else if (stringCompare(styleName, "purple and yellow"))
            styleFeatures = getPurpleAndYellowPredefinedStyleFeatures();
        else if (stringCompare(styleName, "green and red"))
            styleFeatures = getGreenAndRedPredefinedStyleFeatures();
        else if (stringCompare(styleName, "power"))
            styleFeatures = getPowerPredefinedStyleFeatures();
        else if (stringCompare(styleName, "calm"))
            styleFeatures = getCalmPredefinedStyleFeatures();
        else if (stringCompare(styleName, "sunset"))
            styleFeatures = getSunsetPredefinedStyleFeatures();
        else if (stringCompare(styleName, "electric"))
            styleFeatures = getElectricPredefinedStyleFeatures();
        else if (stringCompare(styleName, "midnight"))
            styleFeatures = getMidnightPredefinedStyleFeatures();
        else if (stringCompare(styleName, "vibrance"))
            styleFeatures = getVibrancePredefinedStyleFeatures();
        else if (stringCompare(styleName, "ocean"))
            styleFeatures = getOceanPredefinedStyleFeatures();
        else if (stringCompare(styleName, "forest"))
            styleFeatures = getForestPredefinedStyleFeatures();
        else if (stringCompare(styleName, "warm tone"))
            styleFeatures = getWarmTonePredefinedStyleFeatures();
        else if (stringCompare(styleName, "cool tone"))
            styleFeatures = getCoolTonePredefinedStyleFeatures();
        else if (stringCompare(styleName, "escher"))
            styleFeatures = getEscherPredefinedStyleFeatures();
        styleFeatures.insert(defaultStyleFeatures.begin(), defaultStyleFeatures.end());
    }

    return styleFeatures;
}

std::map<std::string, std::string> getDefaultPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "default"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "darkcyan"},
        {"compartment-border-width", "2"},
        {"compartment-fill-color", "lightgray"},
        {"compartment-font-color", "darkcyan"},
        {"compartment-font-size", "10"},
        {"compartment-font-style", "normal"},
        {"compartment-font-weight", "normal"},
        {"compartment-border-radius-x", "25"},
        {"compartment-border-radius-y", "25"},
        {"compartment-text-horizontal-alignment", "middle"},
        {"compartment-text-vertical-alignment", "bottom"},
        {"species-geometric-shape", "rectangle"},
        {"species-border-color", "black"},
        {"species-border-width", "2"},
        {"species-fill-color", "white"},
        {"species-font-color", "black"},
        {"species-font-size", "24"},
        {"species-font-style", "normal"},
        {"species-font-weight", "normal"},
        {"species-border-radius-x", "6"},
        {"species-border-radius-y", "3.6"},
        {"reaction-geometric-shape", "ellipse"},
        {"reaction-line-color", "black"},
        {"reaction-line-width", "2"},
        {"reaction-border-color", "black"},
        {"reaction-border-width", "2"},
        {"reaction-fill-color", "white"},
        {"reaction-font-color", "darkslategray"},
        {"reaction-font-size", "12"},
        {"reaction-font-style", "normal"},
        {"reaction-font-weight", "normal"},
        {"line-ending-border-color", "black"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "black"},
        {"display-reaction-text-label", "false"}
    };

    return styleFeatures;
}

std::map<std::string, std::string> getBlueOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "blue ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "arapawa"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "arapawa"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "perano"},
        {"species-border-color", "arapawa"},
        {"species-border-width", "3"},
        {"species-font-color", "arapawa"},
        {"species-font-size", "24"},
        {"reaction-line-color", "indigo"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "arapawa"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "indigo"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "indigo"},
    };

    return styleFeatures;
}

std::map<std::string, std::string> getGreenOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "green ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "darkfern"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "darkfern"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "grannysmithapple"},
        {"species-border-color", "darkfern"},
        {"species-border-width", "3"},
        {"species-font-color", "darkfern"},
        {"species-font-size", "24"},
        {"reaction-line-color", "fruitsalad"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "darkfern"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "fruitsalad"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "fruitsalad"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getGrayOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "gray ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "nandor"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "nandor"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "pumice"},
        {"species-border-color", "nandor"},
        {"species-border-width", "3"},
        {"species-font-color", "nandor"},
        {"species-font-size", "24"},
        {"reaction-line-color", "gunsmoke"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "nandor"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "gunsmoke"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "gunsmoke"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getRedOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "red ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "totempole"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "mexicanred"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "apricot"},
        {"species-border-color", "totempole"},
        {"species-border-width", "3"},
        {"species-font-color", "mexicanred"},
        {"species-font-size", "24"},
        {"reaction-line-color", "crimson"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "mexicanred"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "crimson"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "crimson"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getOrangeOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "orange ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "vesuvius"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "vesuvius"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "diserria"},
        {"species-border-color", "vesuvius"},
        {"species-border-width", "3"},
        {"species-font-color", "vesuvius"},
        {"species-font-size", "24"},
        {"reaction-line-color", "reddamask"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "vesuvius"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "reddamask"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "reddamask"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getBrownOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "brown ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "mondo"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "mondo"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "domino"},
        {"species-border-color", "mondo"},
        {"species-border-width", "3"},
        {"species-font-color", "mondo"},
        {"species-font-size", "24"},
        {"reaction-line-color", "hemlock"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "mondo"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "hemlock"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "hemlock"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getPurpleOmbrePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "purple ombre"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "rebeccapurple"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "purple"},
        {"compartment-font-color", "white"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "mediumpurple"},
        {"species-border-color", "purpleheart"},
        {"species-border-width", "3"},
        {"species-font-color", "white"},
        {"species-font-size", "24"},
        {"reaction-line-color", "white"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "white"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "white"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "white"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getPurpleOmbre2PredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "purple ombre 2"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "seance"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "seance"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "eastside"},
        {"species-border-color", "seance"},
        {"species-border-width", "3"},
        {"species-font-color", "seance"},
        {"species-font-size", "24"},
        {"reaction-line-color", "studio"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "seance"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "studio"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "studio"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getBlackAndWhitePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "black and white"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "white"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "black"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "white"},
        {"species-border-color", "black"},
        {"species-border-width", "3"},
        {"species-font-color", "black"},
        {"species-font-size", "24"},
        {"reaction-line-color", "black"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "black"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "black"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "black"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getOrangeAndBluePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "orange and blue"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "jaffa"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "ceruleanblue"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "picton blue"},
        {"species-border-color", "jaffa"},
        {"species-border-width", "3"},
        {"species-font-color", "ceruleanblue"},
        {"species-font-size", "24"},
        {"reaction-line-color", "jaffa"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "ceruleanblue"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "jaffa"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "jaffa"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getPurpleAndYellowPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "purple and yellow"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "daisybush"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "daisybush"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "khaki"},
        {"species-border-color", "daisybush"},
        {"species-border-width", "3"},
        {"species-font-color", "daisybush"},
        {"species-font-size", "24"},
        {"reaction-line-color", "royalpurple"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "daisybush"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "royalpurple"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "royalpurple"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getGreenAndRedPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "green and red"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "forestgreen"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "thunderbird"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "fern"},
        {"species-border-color", "everglade"},
        {"species-border-width", "3"},
        {"species-font-color", "thunderbird"},
        {"species-font-size", "24"},
        {"reaction-line-color", "thunderbird"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "thunderbird"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "thunderbird"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "thunderbird"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getPowerPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "power"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "mandy"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "pewter"},
        {"compartment-font-color", "gondola"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "carnation"},
        {"species-border-color", "gondola"},
        {"species-border-width", "3"},
        {"species-font-color", "gondola"},
        {"species-font-size", "24"},
        {"reaction-line-color", "gondola"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "gondola"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "gondola"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "gondola"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getCalmPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "calm"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "paradiso"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "montecarlo"},
        {"compartment-font-color", "totempole"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "jaffa"},
        {"species-border-color", "goldengrass"},
        {"species-border-width", "3"},
        {"species-font-color", "totempole"},
        {"species-font-size", "24"},
        {"reaction-line-color", "paradiso"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "totempole"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "paradiso"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "paradiso"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getSunsetPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "sunset"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "hibiscus"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "orangepeel"},
        {"compartment-font-color", "purpleheart"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "hibiscus"},
        {"species-border-color", "purpleheart"},
        {"species-border-width", "3"},
        {"species-font-color", "purpleheart"},
        {"species-font-size", "24"},
        {"reaction-line-color", "frenchrose"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "purpleheart"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "frenchrose"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "frenchrose"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getElectricPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "electric"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "java"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "riptide"},
        {"compartment-font-color", "cerise"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "lightorchid"},
        {"species-border-color", "java"},
        {"species-border-width", "3"},
        {"species-font-color", "cerise"},
        {"species-font-size", "24"},
        {"reaction-line-color", "hopbush"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "cerise"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "hopbush"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "hopbush"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getMidnightPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "midnight"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "thunderbird"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "dulllavender"},
        {"compartment-font-color", "thunderbird"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "sunglo"},
        {"species-border-color", "bayofmany"},
        {"species-border-width", "3"},
        {"species-font-color", "thunderbird"},
        {"species-font-size", "24"},
        {"reaction-line-color", "thunderbird"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "thunderbird"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "thunderbird"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "thunderbird"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getVibrancePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "vibrance"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "casal"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "carrotorange"},
        {"compartment-font-color", "shiraz"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "shiraz"},
        {"species-border-color", "cannonpink"},
        {"species-border-width", "3"},
        {"species-font-color", "shiraz"},
        {"species-font-size", "24"},
        {"reaction-line-color", "buttercup"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "shiraz"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "buttercup"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "buttercup"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getOceanPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "ocean"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "elm"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "yuma"},
        {"compartment-font-color", "riverbed"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "aquaisland"},
        {"species-border-color", "elm"},
        {"species-border-width", "3"},
        {"species-font-color", "riverbed"},
        {"species-font-size", "24"},
        {"reaction-line-color", "chino"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "riverbed"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "chino"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "chino"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getForestPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "forest"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "lunargreen"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "tobaccobrown"},
        {"compartment-font-color", "gladegreen"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "sage"},
        {"species-border-color", "tomthumb"},
        {"species-border-width", "3"},
        {"species-font-color", "gladegreen"},
        {"species-font-size", "24"},
        {"reaction-line-color", "tobaccobrown"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "gladegreen"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "tobaccobrown"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "tobaccobrown"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getWarmTonePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "warm tone"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "mondo"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "tiamaria"},
        {"compartment-font-color", "ochre"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "creamcan"},
        {"species-border-color", "tiamaria"},
        {"species-border-width", "3"},
        {"species-font-color", "ochre"},
        {"species-font-size", "24"},
        {"reaction-line-color", "christine"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "ochre"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "christine"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "christine"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getCoolTonePredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "cool tone"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "blueribbon"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "purpleheart"},
        {"compartment-font-color", "blueribbon"},
        {"compartment-font-size", "10"},
        {"species-geometric-shape", "rectangle"},
        {"species-fill-color", "purpleheart"},
        {"species-border-color", "azureradiance"},
        {"species-border-width", "3"},
        {"species-font-color", "blueribbon"},
        {"species-font-size", "24"},
        {"reaction-line-color", "puertorico"},
        {"reaction-line-width", "3"},
        {"reaction-font-color", "blueribbon"},
        {"reaction-font-size", "12"},
        {"line-ending-border-color", "puertorico"},
        {"line-ending-border-width", "3"},
        {"line-ending-fill-color", "puertorico"}
    };
    return styleFeatures;
}

std::map<std::string, std::string> getEscherPredefinedStyleFeatures() {
    static std::map<std::string, std::string> styleFeatures = {
        {"name", "escher"},
        {"background-color", "white"},
        {"compartment-geometric-shape", "rectangle"},
        {"compartment-border-color", "black"},
        {"compartment-border-width", "3"},
        {"compartment-fill-color", "white"},
        {"compartment-font-color", "black"},
        {"compartment-font-size", "10"},
        {"compartment-font-style", "italic"},
        {"compartment-font-weight", "bold"},
        {"species-geometric-shape", "ellipse"},
        {"species-geometric-shape-ratio", "1"},
        {"species-border-color", "hawaiiantan"},
        {"species-border-width", "5"},
        {"species-fill-color", "terracotta"},
        {"species-font-color", "black"},
        {"species-font-size", "12"},
        {"species-font-style", "italic"},
        {"species-font-weight", "bold"},
        {"reaction-geometric-shape", "ellipse"},
        {"reaction-geometric-shape-center-x", "0.0"},
        {"reaction-geometric-shape-center-y", "0.0"},
        {"reaction-geometric-shape-radius-x", "4"},
        {"reaction-geometric-shape-radius-y", "4"},
        {"reaction-line-color", "sanjuan"},
        {"reaction-line-width", "9"},
        {"reaction-border-color", "mineshaft"},
        {"reaction-border-width", "3"},
        {"reaction-fill-color", "waikawagray"},
        {"reaction-font-color", "luckypoint"},
        {"reaction-font-size", "24"},
        {"reaction-font-style", "italic"},
        {"reaction-font-weight", "bold"},
        {"line-ending-border-color", "sanjuan"},
        {"line-ending-border-width", "6"},
        {"line-ending-fill-color", "sanjuan"},
        {"display-reaction-text-label", "true"}
    };
    return styleFeatures;
}

const bool isValidPredefinedStyleName(const std::string& predefinedStyleName) {
    std::vector<std::string> predefinedStyleNames = getPredefinedStyleNames();
    for (unsigned int i = 0; i < predefinedStyleNames.size(); i++) {
        if (stringCompare(predefinedStyleNames.at(i), predefinedStyleName))
            return true;
    }

    std::cerr << "error: predefined style name is not valid" << std::endl;
    return false;
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

const bool isValidOffsetValue(const double& offset) {
    return isValidRelAbsVectorRelativeValue(offset);
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

const bool isValidRelAbsVectorRelativeValue(const double& value) {
    if (value >= 0.0 && value <= 100.0)
        return true;
    std::cerr << "error: the entered value must be between 0 and 100" << std::endl;
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

    return isValidHexColorCode(value);
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

const bool isValidHexColorCode(const std::string& value) {
    if (value.size() != 7 || value.at(0) != '#')
        return false;

    for (unsigned int i = 1; i < value.size(); i++) {
        if (!isxdigit(value.at(i)))
            return false;
    }

    return true;
}

const bool isxdigit(const char& c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

std::vector<std::pair<std::string, std::string>> colorData() {
    static std::vector<std::pair<std::string, std::string>> colors = {
    {"aliceblue", "#F0F8FF"},
    {"antiquewhite", "#FAEBD7"},
    {"aqua", "#00FFFF"},
    {"aquamarine", "#7FFFD4"},
    {"apricot", "#EB9373"},
    {"arapawa", "#1A2421"},
    {"azure", "#F0FFFF"},
    {"azureradiance", "#007FFF"},
    {"aquaisland", "#A1DAD7"},
    {"bayofmany", "#273A3E"},
    {"beige", "#F5F5DC"},
    {"bisque", "#FFE4C4"},
    {"black", "#000000"},
    {"blanchedalmond", "#FFEBCD"},
    {"blue", "#0000FF"},
    {"blueribbon", "#0066FF"},
    {"blueviolet", "#8A2BE2"},
    {"brown", "#A52A2A"},
    {"burlywood", "#DEB887"},
    {"buttercup", "#F3AD16"},
    {"cadetblue", "#5F9EA0"},
    {"cannonpink", "#8E5164"},
    {"carnation", "#F95A61"},
    {"carrotorange", "#ED9121"},
    {"casal", "#2E2F30"},
    {"ceruleanblue", "#2A52BE"},
    {"chartreuse", "#7FFF00"},
    {"chino", "#D2B7AD"},
    {"chocolate", "#D2691E"},
    {"christine", "#E1634F"},
    {"coral", "#FF7F50"},
    {"cornflowerblue", "#6495ED"},
    {"cornsilk", "#FFF8DC"},
    {"creamcan", "#F5C71A"},
    {"crimson", "#DC143C"},
    {"cyan", "#00FFFF"},
    {"daisybush", "#4F2398"},
    {"darkblue", "#00008B"},
    {"darkcyan", "#008B8B"},
    {"darkfern", "#0A6906"},
    {"darkgoldenrod", "#B8860B"},
    {"darkgray", "#A9A9A9"},
    {"darkgrey", "#A9A9A9"},
    {"darkgreen", "#006400"},
    {"darkindigo", "#4B0082"},
    {"darkkhaki", "#BDB76B"},
    {"darkmagenta", "#8B008B"},
    {"darkolivegreen", "#556B2F"},
    {"darkorange", "#FF8C00"},
    {"darkorchid", "#9932CC"},
    {"darkred", "#8B0000"},
    {"darksalmon", "#E9967A"},
    {"darkseagreen", "#8FBC8F"},
    {"darkslateblue", "#483D8B"},
    {"darkslategray", "#2F4F4F"},
    {"darkslategrey", "#2F4F4F"},
    {"darkturquoise", "#00CED1"},
    {"darkviolet", "#9400D3"},
    {"deeppink", "#FF1493"},
    {"deepskyblue", "#00BFFF"},
    {"dimgray", "#696969"},
    {"dimgrey", "#696969"},
    {"diserria", "#DAA520"},
    {"dodgerblue", "#1E90FF"},
    {"domino", "#8A2008"},
    {"dulllavender", "#A899E6"},
    {"eastside", "#AC91CE"},
    {"elm", "#027877"},
    {"everglade", "#1A2421"},
    {"fern", "#4F7942"},
    {"firebrick", "#B22222"},
    {"fieryorange", "#A24510"},
    {"floralwhite", "#FFFAF0"},
    {"forestgreen", "#228B22"},
    {"frenchrose", "#F64A8A"},
    {"fruitsalad", "#4F9D5D"},
    {"fuchsia", "#FF00FF"},
    {"gainsboro", "#DCDCDC"},
    {"ghostwhite", "#F8F8FF"},
    {"gladegreen", "#4A6B4E"},
    {"gold", "#FFD700"},
    {"goldengrass", "#D9B612"},
    {"goldenrod", "#DAA520"},
    {"gondola", "#211916"},
    {"gray", "#808080"},
    {"grey", "#808080"},
    {"grannysmithapple", "#A8E4A0"},
    {"green", "#008000"},
    {"greenyellow", "#ADFF2F"},
    {"gunsmoke", "#828685"},
    {"hawaiiantan", "#9D5616"},
    {"hemlock", "#5E5D3B"},
    {"hibiscus", "#AE4560"},
    {"honeydew", "#F0FFF0"},
    {"hopbush", "#D5853E"},
    {"hotpink", "#FF69B4"},
    {"indianred", "#CD5C5C"},
    {"indigo", "#4B0082"},
    {"ivory", "#FFFFF0"},
    {"jaffa", "#EF8633"},
    {"java", "#32303D"},
    {"khaki", "#F0E68C"},
    {"lavender", "#E6E6FA"},
    {"lavenderblush", "#FFF0F5"},
    {"lawngreen", "#7CFC00"},
    {"lemonchiffon", "#FFFACD"},
    {"lightblue", "#ADD8E6"},
    {"lightcoral", "#F08080"},
    {"lightcyan", "#E0FFFF"},
    {"lightgoldenrodyellow", "#FAFAD2"},
    {"lightgray", "#D3D3D3"},
    {"lightgrey", "#D3D3D3"},
    {"lightgreen", "#90EE90"},
    {"lightorchid", "#E29CD2"},
    {"lightpink", "#FFB6C1"},
    {"lightsalmon", "#FFA07A"},
    {"lightseagreen", "#20B2AA"},
    {"lightskyblue", "#87CEFA"},
    {"lightslategray", "#778899"},
    {"lightslategrey", "#778899"},
    {"lightsteelblue", "#B0C4DE"},
    {"lightyellow", "#FFFFE0"},
    {"lime", "#00FF00"},
    {"limegreen", "#32CD32"},
    {"linen", "#FAF0E6"},
    {"lunargreen", "#3A7D02"},
    {"luckypoint", "#202078"},
    {"magenta", "#FF00FF"},
    {"mandy", "#D57C6B"},
    {"maroon", "#800000"},
    {"mediumaquamarine", "#66CDAA"},
    {"mediumblue", "#0000CD"},
    {"mediumorchid", "#BA55D3"},
    {"mediumpurple", "#9370DB"},
    {"mediumseagreen", "#3CB371"},
    {"mediumslateblue", "#7B68EE"},
    {"mediumspringgreen", "#00FA9A"},
    {"mediumturquoise", "#48D1CC"},
    {"mediumvioletred", "#C71585"},
    {"mexicanred", "#A72525"},
    {"midnightblue", "#191970"},
    {"mintcream", "#F5FFFA"},
    {"mineshaft", "#323232"},
    {"mistyrose", "#FFE4E1"},
    {"moccasin", "#FFE4B5"},
    {"mondo", "#4A3C30"},
    {"montecarlo", "#78A39C"},
    {"nandor", "#4B3D2A"},
    {"navajowhite", "#FFDEAD"},
    {"navy", "#000080"},
    {"ochre", "#C77434"},
    {"oldlace", "#FDF5E6"},
    {"olive", "#808000"},
    {"olivedrab", "#6B8E23"},
    {"orange", "#FFA500"},
    {"orangepeel", "#FFA500"},
    {"orangered", "#FF4500"},
    {"orchid", "#DA70D"},
    {"palegoldenrod", "#EEE8AA"},
    {"palegreen", "#98FB98"},
    {"paleturquoise", "#AFEEEE"},
    {"palevioletred", "#DB7093"},
    {"papayawhip", "#FFEFD5"},
    {"paradiso", "#35A793"},
    {"peachpuff", "#FFDAB9"},
    {"perano", "#7F7F7F"},
    {"peru", "#CD853F"},
    {"pewter", "#96A8A1"},
    {"pictonblue", "#45B1E8"},
    {"pink", "#FFC0CB"},
    {"plum", "#DDA0DD"},
    {"powderblue", "#B0E0E6"},
    {"puertorico", "#3B69D6"},
    {"pumice", "#C2CAC4"},
    {"purple", "#800080"},
    {"purpleheart", "#69359C"},
    {"rebeccapurple", "#663399"},
    {"red", "#FF0000"},
    {"reddamask", "#DA6A41"},
    {"riptide", "#8BE6D8"},
    {"riverbed", "#434A59"},
    {"rosybrown", "#BC8F8F"},
    {"royalblue", "#4169E1"},
    {"royalpurple", "#6B3FA0"},
    {"saddlebrown", "#8B4513"},
    {"sage", "#9EAD3D"},
    {"salmon", "#FA8072"},
    {"sandybrown", "#F4A460"},
    {"sanjuan", "#334E75"},
    {"seagreen", "#2E8B57"},
    {"seashell", "#FFF5EE"},
    {"seance", "#721757"},
    {"shiraz", "#B52D42"},
    {"sienna", "#A0522D"},
    {"silver", "#C0C0C0"},
    {"skyblue", "#87CEEB"},
    {"slateblue", "#6A5ACD"},
    {"slategray", "#708090"},
    {"slategrey", "#708090"},
    {"snow", "#FFFAFA"},
    {"springgreen", "#00FF7F"},
    {"steelblue", "#4682B4"},
    {"studio", "#714AB2"},
    {"sunglo", "#E16865"},
    {"tan", "#D2B48C"},
    {"teal", "#008080"},
    {"terracotta", "#E2725B"},
    {"thistle", "#D8BFD8"},
    {"thunderbird", "#C02B18"},
    {"tiamaria", "#C1440E"},
    {"tobaccobrown", "#715D47"},
    {"gladegreen", "#4A6B4E"},
    {"tomato", "#FF6347"},
    {"tomthumb", "#273E33"},
    {"totempole", "#991B07"},
    {"turquoise", "#40E0D0"},
    {"vesuvius", "#AD975A"},
    {"violet", "#EE82EE"},
    {"waikawagray", "#5D7291"},
    {"waikawagrey", "#5D7291"},
    {"wheat", "#F5DEB3"},
    {"white", "#FFFFFF"},
    {"whitesmoke", "#F5F5F5"},
    {"yuma", "#CFAB7A"},
    {"yellow", "#FFFF00"},
    {"yellowgreen", "#9ACD32"}};

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
    geometricShapeNames.push_back("square");
    geometricShapeNames.push_back("ellipse");
    geometricShapeNames.push_back("circle");
    geometricShapeNames.push_back("triangle");
    geometricShapeNames.push_back("diamond");
    geometricShapeNames.push_back("pentagon");
    geometricShapeNames.push_back("hexagon");
    geometricShapeNames.push_back("octagon");
    return geometricShapeNames;
}

}
