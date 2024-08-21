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
            renderInformationBase->addColorDefinition(createColorDefinition(renderPkgNamespaces, toLowerCase(colorId), colorValue));
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
    if (stringCompare(styleName, "default"))
        return getDefaultPredefinedStyleFeatures();
    else if (stringCompare(styleName, "blue ombre"))
        return getBlueOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "green ombre"))
        return getGreenOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "gray ombre") || stringCompare(styleName, "grey ombre"))
        return getGrayOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "red ombre"))
        return getRedOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "orange ombre"))
        return getOrangeOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "brown ombre"))
        return getBrownOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "purple ombre"))
        return getPurpleOmbrePredefinedStyleFeatures();
    else if (stringCompare(styleName, "purple ombre 2"))
        return getPurpleOmbre2PredefinedStyleFeatures();
    else if (stringCompare(styleName, "black and white"))
        return getBlackAndWhitePredefinedStyleFeatures();
    else if (stringCompare(styleName, "orange and blue"))
        return getOrangeAndBluePredefinedStyleFeatures();
    else if (stringCompare(styleName, "purple and yellow"))
        return getPurpleAndYellowPredefinedStyleFeatures();
    else if (stringCompare(styleName, "green and red"))
        return getGreenAndRedPredefinedStyleFeatures();
    else if (stringCompare(styleName, "power"))
        return getPowerPredefinedStyleFeatures();
    else if (stringCompare(styleName, "calm"))
        return getCalmPredefinedStyleFeatures();
    else if (stringCompare(styleName, "sunset"))
        return getSunsetPredefinedStyleFeatures();
    else if (stringCompare(styleName, "electric"))
        return getElectricPredefinedStyleFeatures();
    else if (stringCompare(styleName, "midnight"))
        return getMidnightPredefinedStyleFeatures();
    else if (stringCompare(styleName, "vibrance"))
        return getVibrancePredefinedStyleFeatures();
    else if (stringCompare(styleName, "ocean"))
        return getOceanPredefinedStyleFeatures();
    else if (stringCompare(styleName, "forest"))
        return getForestPredefinedStyleFeatures();
    else if (stringCompare(styleName, "warm tone"))
        return getWarmTonePredefinedStyleFeatures();
    else if (stringCompare(styleName, "cool tone"))
        return getCoolTonePredefinedStyleFeatures();
    else if (stringCompare(styleName, "escher"))
        return getEscherPredefinedStyleFeatures();

    return std::map<std::string, std::string>();
}

std::map<std::string, std::string> getDefaultPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "default";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "darkcyan";
    styleFeatures["compartment-border-width"] = "2";
    styleFeatures["compartment-fill-color"] = "lightgray";
    styleFeatures["compartment-font-color"] = "darkcyan";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["compartment-font-style"] = "normal";
    styleFeatures["compartment-font-weight"] = "normal";
    styleFeatures["compartment-border-radius-x"] = "25";
    styleFeatures["compartment-border-radius-y"] = "25";
    styleFeatures["compartment-text-horizontal-alignment"] = "middle";
    styleFeatures["compartment-text-vertical-alignment"] = "bottom";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-border-color"] = "black";
    styleFeatures["species-border-width"] = "2";
    styleFeatures["species-fill-color"] = "white";
    styleFeatures["species-font-color"] = "black";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["species-font-style"] = "normal";
    styleFeatures["species-font-weight"] = "normal";
    styleFeatures["species-border-radius-x"] = "6";
    styleFeatures["species-border-radius-y"] = "3.6";
    styleFeatures["reaction-geometric-shape"] = "rectangle";
    styleFeatures["reaction-line-color"] = "black";
    styleFeatures["reaction-line-width"] = "2";
    styleFeatures["reaction-font-color"] = "darkslategray";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["reaction-font-style"] = "normal";
    styleFeatures["reaction-font-weight"] = "normal";
    styleFeatures["line-ending-border-color"] = "black";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "black";
    return styleFeatures;
}

std::map<std::string, std::string> getBlueOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "blue ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "arapawa";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "arapawa";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "perano";
    styleFeatures["species-border-color"] = "arapawa";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "arapawa";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "indigo";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "arapawa";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "indigo";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "indigo";
    return styleFeatures;
}

std::map<std::string, std::string> getGreenOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "green ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "darkfern";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "darkfern";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "grannysmithapple";
    styleFeatures["species-border-color"] = "darkfern";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "darkfern";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "fruitsalad";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "darkfern";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "fruitsalad";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "fruitsalad";
    return styleFeatures;
}

std::map<std::string, std::string> getGrayOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "gray ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "nandor";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "nandor";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "pumice";
    styleFeatures["species-border-color"] = "nandor";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "nandor";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "gunsmoke";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "nandor";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "gunsmoke";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "gunsmoke";
    return styleFeatures;
}

std::map<std::string, std::string> getRedOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "red ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "totempole";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "mexicanred";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "apricot";
    styleFeatures["species-border-color"] = "totempole";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "mexicanred";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "crimson";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "mexicanred";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "crimson";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "crimson";
    return styleFeatures;
}

std::map<std::string, std::string> getOrangeOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "orange ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "vesuvius";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "vesuvius";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "diserria";
    styleFeatures["species-border-color"] = "vesuvius";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "vesuvius";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "reddamask";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "vesuvius";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "reddamask";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "reddamask";
    return styleFeatures;
}

std::map<std::string, std::string> getBrownOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "brown ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "mondo";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "mondo";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "domino";
    styleFeatures["species-border-color"] = "mondo";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "mondo";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "hemlock";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "mondo";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "hemlock";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "hemlock";
    return styleFeatures;
}

std::map<std::string, std::string> getPurpleOmbrePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "purple ombre";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "rebeccapurple";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "purple";
    styleFeatures["compartment-font-color"] = "white";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "mediumpurple";
    styleFeatures["species-border-color"] = "purpleheart";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "white";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "white";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "white";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "white";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "white";
    return styleFeatures;
}

std::map<std::string, std::string> getPurpleOmbre2PredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "purple ombre 2";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "seance";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "seance";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "eastside";
    styleFeatures["species-border-color"] = "seance";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "seance";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "studio";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "seance";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "studio";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "studio";
    return styleFeatures;
}

std::map<std::string, std::string> getBlackAndWhitePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "black and white";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "white";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "black";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "white";
    styleFeatures["species-border-color"] = "black";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "black";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "black";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "black";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "black";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "black";
    return styleFeatures;
}

std::map<std::string, std::string> getOrangeAndBluePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "orange and blue";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "jaffa";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "ceruleanblue";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "picton blue";
    styleFeatures["species-border-color"] = "jaffa";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "ceruleanblue";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "jaffa";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "ceruleanblue";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "jaffa";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "jaffa";
    return styleFeatures;
}

std::map<std::string, std::string> getPurpleAndYellowPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "purple and yellow";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "daisybush";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "daisybush";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "khaki";
    styleFeatures["species-border-color"] = "daisybush";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "daisybush";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "royalpurple";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "daisybush";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "royalpurple";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "royalpurple";
    return styleFeatures;
}

std::map<std::string, std::string> getGreenAndRedPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "green and red";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "forestgreen";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "thunderbird";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "fern";
    styleFeatures["species-border-color"] = "everglade";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "thunderbird";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "thunderbird";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "thunderbird";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "thunderbird";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "thunderbird";
    return styleFeatures;
}

std::map<std::string, std::string> getPowerPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "power";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "mandy";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "pewter";
    styleFeatures["compartment-font-color"] = "gondola";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "carnation";
    styleFeatures["species-border-color"] = "gondola";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "gondola";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "gondola";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "gondola";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "gondola";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "gondola";
    return styleFeatures;
}

std::map<std::string, std::string> getCalmPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "calm";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "paradiso";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "montecarlo";
    styleFeatures["compartment-font-color"] = "totempole";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "jaffa";
    styleFeatures["species-border-color"] = "goldengrass";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "totempole";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "paradiso";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "totempole";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "paradiso";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "paradiso";
    return styleFeatures;
}

std::map<std::string, std::string> getSunsetPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "sunset";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "hibiscus";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "orangepeel";
    styleFeatures["compartment-font-color"] = "purpleheart";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "hibiscus";
    styleFeatures["species-border-color"] = "purpleheart";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "purpleheart";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "frenchrose";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "purpleheart";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "frenchrose";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "frenchrose";
    return styleFeatures;
}

std::map<std::string, std::string> getElectricPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "electric";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "java";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "riptide";
    styleFeatures["compartment-font-color"] = "cerise";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "lightorchid";
    styleFeatures["species-border-color"] = "java";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "cerise";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "hopbush";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "cerise";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "hopbush";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "hopbush";
    return styleFeatures;
}

std::map<std::string, std::string> getMidnightPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "midnight";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "thunderbird";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "dulllavender";
    styleFeatures["compartment-font-color"] = "thunderbird";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "sunglo";
    styleFeatures["species-border-color"] = "bayofmany";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "thunderbird";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "thunderbird";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "thunderbird";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "thunderbird";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "thunderbird";
    return styleFeatures;
}

std::map<std::string, std::string> getVibrancePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "vibrance";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "casal";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "carrotorange";
    styleFeatures["compartment-font-color"] = "shiraz";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "shiraz";
    styleFeatures["species-border-color"] = "cannonpink";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "shiraz";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "buttercup";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "shiraz";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "buttercup";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "buttercup";
    return styleFeatures;
}

std::map<std::string, std::string> getOceanPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "ocean";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "elm";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "yuma";
    styleFeatures["compartment-font-color"] = "riverbed";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "aquaisland";
    styleFeatures["species-border-color"] = "elm";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "riverbed";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "chino";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "riverbed";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "chino";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "chino";
    return styleFeatures;
}

std::map<std::string, std::string> getForestPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "forest";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "lunargreen";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "tobaccobrown";
    styleFeatures["compartment-font-color"] = "gladegreen";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "sage";
    styleFeatures["species-border-color"] = "tomthumb";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "gladegreen";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "tobaccobrown";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "gladegreen";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "tobaccobrown";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "tobaccobrown";
    return styleFeatures;
}

std::map<std::string, std::string> getWarmTonePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "warm tone";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "mondo";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "tiamaria";
    styleFeatures["compartment-font-color"] = "ochre";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "creamcan";
    styleFeatures["species-border-color"] = "tiamaria";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "ochre";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "christine";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "ochre";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "christine";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "christine";
    return styleFeatures;
}

std::map<std::string, std::string> getCoolTonePredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "cool tone";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "blueribbon";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "purpleheart";
    styleFeatures["compartment-font-color"] = "blueribbon";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["species-geometric-shape"] = "rectangle";
    styleFeatures["species-fill-color"] = "purpleheart";
    styleFeatures["species-border-color"] = "azureradiance";
    styleFeatures["species-border-width"] = "3";
    styleFeatures["species-font-color"] = "blueribbon";
    styleFeatures["species-font-size"] = "24";
    styleFeatures["reaction-line-color"] = "puertorico";
    styleFeatures["reaction-line-width"] = "3";
    styleFeatures["reaction-font-color"] = "blueribbon";
    styleFeatures["reaction-font-size"] = "12";
    styleFeatures["line-ending-border-color"] = "puertorico";
    styleFeatures["line-ending-border-width"] = "3";
    styleFeatures["line-ending-fill-color"] = "puertorico";
    return styleFeatures;
}

std::map<std::string, std::string> getEscherPredefinedStyleFeatures() {
    std::map<std::string, std::string> styleFeatures;
    styleFeatures["name"] = "escher";
    styleFeatures["background-color"] = "white";
    styleFeatures["compartment-geometric-shape"] = "rectangle";
    styleFeatures["compartment-border-color"] = "black";
    styleFeatures["compartment-border-width"] = "3";
    styleFeatures["compartment-fill-color"] = "white";
    styleFeatures["compartment-font-color"] = "black";
    styleFeatures["compartment-font-size"] = "10";
    styleFeatures["compartment-font-style"] = "italic";
    styleFeatures["compartment-font-weight"] = "bold";
    styleFeatures["species-geometric-shape"] = "ellipse";
    styleFeatures["species-geometric-shape-ratio"] = "1";
    styleFeatures["species-border-color"] = "hawaiiantan";
    styleFeatures["species-border-width"] = "5";
    styleFeatures["species-fill-color"] = "terracotta";
    styleFeatures["species-font-color"] = "black";
    styleFeatures["species-font-size"] = "12";
    styleFeatures["species-font-style"] = "italic";
    styleFeatures["species-font-weight"] = "bold";
    styleFeatures["reaction-geometric-shape"] = "ellipse";
    styleFeatures["reaction-geometric-shape-center-x"] = "0.0";
    styleFeatures["reaction-geometric-shape-center-y"] = "0.0";
    styleFeatures["reaction-geometric-shape-radius-x"] = "4";
    styleFeatures["reaction-geometric-shape-radius-y"] = "4";
    styleFeatures["reaction-line-color"] = "sanjuan";
    styleFeatures["reaction-line-width"] = "9";
    styleFeatures["reaction-border-color"] = "mineshaft";
    styleFeatures["reaction-border-width"] = "3";
    styleFeatures["reaction-fill-color"] = "waikawagray";
    styleFeatures["reaction-font-color"] = "luckypoint";
    styleFeatures["reaction-font-size"] = "24";
    styleFeatures["reaction-font-style"] = "italic";
    styleFeatures["reaction-font-weight"] = "bold";
    styleFeatures["line-ending-border-color"] = "sanjuan";
    styleFeatures["line-ending-border-width"] = "6";
    styleFeatures["line-ending-fill-color"] = "sanjuan";
    styleFeatures["display-reaction-text-label"] = "true";
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
    colors.push_back(std::make_pair("aliceblue", "#F0F8FF"));
    colors.push_back(std::make_pair("antiquewhite", "#FAEBD7"));
    colors.push_back(std::make_pair("aqua", "#00FFFF"));
    colors.push_back(std::make_pair("aquamarine", "#7FFFD4"));
    colors.push_back(std::make_pair("apricot", "#EB9373"));
    colors.push_back(std::make_pair("arapawa", "#1A2421"));
    colors.push_back(std::make_pair("azure", "#F0FFFF"));
    colors.push_back(std::make_pair("azureradiance", "#007FFF"));
    colors.push_back(std::make_pair("aquaisland", "#A1DAD7"));
    colors.push_back(std::make_pair("bayofmany", "#273A3E"));
    colors.push_back(std::make_pair("beige", "#F5F5DC"));
    colors.push_back(std::make_pair("bisque", "#FFE4C4"));
    colors.push_back(std::make_pair("black", "#000000"));
    colors.push_back(std::make_pair("blanchedalmond", "#FFEBCD"));
    colors.push_back(std::make_pair("blue", "#0000FF"));
    colors.push_back(std::make_pair("blueribbon", "#0066FF"));
    colors.push_back(std::make_pair("blueviolet", "#8A2BE2"));
    colors.push_back(std::make_pair("brown", "#A52A2A"));
    colors.push_back(std::make_pair("burlywood", "#DEB887"));
    colors.push_back(std::make_pair("buttercup", "#F3AD16"));
    colors.push_back(std::make_pair("cadetblue", "#5F9EA0"));
    colors.push_back(std::make_pair("cannonpink", "#8E5164"));
    colors.push_back(std::make_pair("carnation", "#F95A61"));
    colors.push_back(std::make_pair("carrotorange", "#ED9121"));
    colors.push_back(std::make_pair("casal", "#2E2F30"));
    colors.push_back(std::make_pair("ceruleanblue", "#2A52BE"));
    colors.push_back(std::make_pair("chartreuse", "#7FFF00"));
    colors.push_back(std::make_pair("chino", "#D2B7AD"));
    colors.push_back(std::make_pair("chocolate", "#D2691E"));
    colors.push_back(std::make_pair("christine", "#E1634F"));
    colors.push_back(std::make_pair("coral", "#FF7F50"));
    colors.push_back(std::make_pair("cornflowerblue", "#6495ED"));
    colors.push_back(std::make_pair("cornsilk", "#FFF8DC"));
    colors.push_back(std::make_pair("creamcan", "#F5C71A"));
    colors.push_back(std::make_pair("crimson", "#DC143C"));
    colors.push_back(std::make_pair("cyan", "#00FFFF"));
    colors.push_back(std::make_pair("daisybush", "#4F2398"));
    colors.push_back(std::make_pair("darkblue", "#00008B"));
    colors.push_back(std::make_pair("darkcyan", "#008B8B"));
    colors.push_back(std::make_pair("darkfern", "#0A6906"));
    colors.push_back(std::make_pair("darkgoldenrod", "#B8860B"));
    colors.push_back(std::make_pair("darkgray", "#A9A9A9"));
    colors.push_back(std::make_pair("darkgrey", "#A9A9A9"));
    colors.push_back(std::make_pair("darkgreen", "#006400"));
    colors.push_back(std::make_pair("darkindigo", "#4B0082"));
    colors.push_back(std::make_pair("darkkhaki", "#BDB76B"));
    colors.push_back(std::make_pair("darkmagenta", "#8B008B"));
    colors.push_back(std::make_pair("darkolivegreen", "#556B2F"));
    colors.push_back(std::make_pair("darkorange", "#FF8C00"));
    colors.push_back(std::make_pair("darkorchid", "#9932CC"));
    colors.push_back(std::make_pair("darkred", "#8B0000"));
    colors.push_back(std::make_pair("darksalmon", "#E9967A"));
    colors.push_back(std::make_pair("darkseagreen", "#8FBC8F"));
    colors.push_back(std::make_pair("darkslateblue", "#483D8B"));
    colors.push_back(std::make_pair("darkslategray", "#2F4F4F"));
    colors.push_back(std::make_pair("darkslategrey", "#2F4F4F"));
    colors.push_back(std::make_pair("darkturquoise", "#00CED1"));
    colors.push_back(std::make_pair("darkviolet", "#9400D3"));
    colors.push_back(std::make_pair("deeppink", "#FF1493"));
    colors.push_back(std::make_pair("deepskyblue", "#00BFFF"));
    colors.push_back(std::make_pair("dimgray", "#696969"));
    colors.push_back(std::make_pair("dimgrey", "#696969"));
    colors.push_back(std::make_pair("diserria", "#DAA520"));
    colors.push_back(std::make_pair("dodgerblue", "#1E90FF"));
    colors.push_back(std::make_pair("domino", "#8A2008"));
    colors.push_back(std::make_pair("dulllavender", "#A899E6"));
    colors.push_back(std::make_pair("eastside", "#AC91CE"));
    colors.push_back(std::make_pair("elm", "#027877"));
    colors.push_back(std::make_pair("everglade", "#1A2421"));
    colors.push_back(std::make_pair("fern", "#4F7942"));
    colors.push_back(std::make_pair("firebrick", "#B22222"));
    colors.push_back(std::make_pair("fiery orange", "#A24510"));
    colors.push_back(std::make_pair("floralwhite", "#FFFAF0"));
    colors.push_back(std::make_pair("forestgreen", "#228B22"));
    colors.push_back(std::make_pair("frenchrose", "#F64A8A"));
    colors.push_back(std::make_pair("fruitsalad", "#4F9D5D"));
    colors.push_back(std::make_pair("fuchsia", "#FF00FF"));
    colors.push_back(std::make_pair("gainsboro", "#DCDCDC"));
    colors.push_back(std::make_pair("ghostwhite", "#F8F8FF"));
    colors.push_back(std::make_pair("glade green", "#4A6B4E"));
    colors.push_back(std::make_pair("gold", "#FFD700"));
    colors.push_back(std::make_pair("goldengrass", "#D9B612"));
    colors.push_back(std::make_pair("goldenrod", "#DAA520"));
    colors.push_back(std::make_pair("gondola", "#211916"));
    colors.push_back(std::make_pair("gray", "#808080"));
    colors.push_back(std::make_pair("grey", "#808080"));
    colors.push_back(std::make_pair("grannysmithapple", "#A8E4A0"));
    colors.push_back(std::make_pair("green", "#008000"));
    colors.push_back(std::make_pair("greenyellow", "#ADFF2F"));
    colors.push_back(std::make_pair("gunsmoke", "#828685"));
    colors.push_back(std::make_pair("hawaiiantan", "#9D5616"));
    colors.push_back(std::make_pair("hemlock", "#5E5D3B"));
    colors.push_back(std::make_pair("hibiscus", "#AE4560"));
    colors.push_back(std::make_pair("honeydew", "#F0FFF0"));
    colors.push_back(std::make_pair("hopbush", "#D5853E"));
    colors.push_back(std::make_pair("hotpink", "#FF69B4"));
    colors.push_back(std::make_pair("indianred", "#CD5C5C"));
    colors.push_back(std::make_pair("indigo", "#4B0082"));
    colors.push_back(std::make_pair("ivory", "#FFFFF0"));
    colors.push_back(std::make_pair("jaffa", "#EF8633"));
    colors.push_back(std::make_pair("java", "#32303D"));
    colors.push_back(std::make_pair("khaki", "#F0E68C"));
    colors.push_back(std::make_pair("lavender", "#E6E6FA"));
    colors.push_back(std::make_pair("lavenderblush", "#FFF0F5"));
    colors.push_back(std::make_pair("lawngreen", "#7CFC00"));
    colors.push_back(std::make_pair("lemonchiffon", "#FFFACD"));
    colors.push_back(std::make_pair("lightblue", "#ADD8E6"));
    colors.push_back(std::make_pair("lightcoral", "#F08080"));
    colors.push_back(std::make_pair("lightcyan", "#E0FFFF"));
    colors.push_back(std::make_pair("lightgoldenrodyellow", "#FAFAD2"));
    colors.push_back(std::make_pair("lightgray", "#D3D3D3"));
    colors.push_back(std::make_pair("lightgrey", "#D3D3D3"));
    colors.push_back(std::make_pair("lightgreen", "#90EE90"));
    colors.push_back(std::make_pair("lightorchid", "#E29CD2"));
    colors.push_back(std::make_pair("lightpink", "#FFB6C1"));
    colors.push_back(std::make_pair("lightsalmon", "#FFA07A"));
    colors.push_back(std::make_pair("lightseagreen", "#20B2AA"));
    colors.push_back(std::make_pair("lightskyblue", "#87CEFA"));
    colors.push_back(std::make_pair("lightslategray", "#778899"));
    colors.push_back(std::make_pair("lightslategrey", "#778899"));
    colors.push_back(std::make_pair("lightsteelblue", "#B0C4DE"));
    colors.push_back(std::make_pair("lightyellow", "#FFFFE0"));
    colors.push_back(std::make_pair("lime", "#00FF00"));
    colors.push_back(std::make_pair("limegreen", "#32CD32"));
    colors.push_back(std::make_pair("linen", "#FAF0E6"));
    colors.push_back(std::make_pair("lunargreen", "#3A7D02"));
    colors.push_back(std::make_pair("luckypoint", "#202078"));
    colors.push_back(std::make_pair("magenta", "#FF00FF"));
    colors.push_back(std::make_pair("mandy", "#D57C6B"));
    colors.push_back(std::make_pair("maroon", "#800000"));
    colors.push_back(std::make_pair("mediumaquamarine", "#66CDAA"));
    colors.push_back(std::make_pair("mediumblue", "#0000CD"));
    colors.push_back(std::make_pair("mediumorchid", "#BA55D3"));
    colors.push_back(std::make_pair("mediumpurple", "#9370DB"));
    colors.push_back(std::make_pair("mediumseagreen", "#3CB371"));
    colors.push_back(std::make_pair("mediumslateblue", "#7B68EE"));
    colors.push_back(std::make_pair("mediumspringgreen", "#00FA9A"));
    colors.push_back(std::make_pair("mediumturquoise", "#48D1CC"));
    colors.push_back(std::make_pair("mediumvioletred", "#C71585"));
    colors.push_back(std::make_pair("mexicanred", "#A72525"));
    colors.push_back(std::make_pair("midnightblue", "#191970"));
    colors.push_back(std::make_pair("mintcream", "#F5FFFA"));
    colors.push_back(std::make_pair("mineshaft", "#323232"));
    colors.push_back(std::make_pair("mistyrose", "#FFE4E1"));
    colors.push_back(std::make_pair("moccasin", "#FFE4B5"));
    colors.push_back(std::make_pair("mondo", "#4A3C30"));
    colors.push_back(std::make_pair("montecarlo", "#78A39C"));
    colors.push_back(std::make_pair("nandor", "#4B3D2A"));
    colors.push_back(std::make_pair("navajowhite", "#FFDEAD"));
    colors.push_back(std::make_pair("navy", "#000080"));
    colors.push_back(std::make_pair("ochre", "#C77434"));
    colors.push_back(std::make_pair("oldlace", "#FDF5E6"));
    colors.push_back(std::make_pair("olive", "#808000"));
    colors.push_back(std::make_pair("olivedrab", "#6B8E23"));
    colors.push_back(std::make_pair("orange", "#FFA500"));
    colors.push_back(std::make_pair("orangepeel", "#FFA500"));
    colors.push_back(std::make_pair("orangered", "#FF4500"));
    colors.push_back(std::make_pair("orchid", "#DA70D6"));
    colors.push_back(std::make_pair("palegoldenrod", "#EEE8AA"));
    colors.push_back(std::make_pair("palegreen", "#98FB98"));
    colors.push_back(std::make_pair("paleturquoise", "#AFEEEE"));
    colors.push_back(std::make_pair("palevioletred", "#DB7093"));
    colors.push_back(std::make_pair("papayawhip", "#FFEFD5"));
    colors.push_back(std::make_pair("paradiso", "#35A793"));
    colors.push_back(std::make_pair("peachpuff", "#FFDAB9"));
    colors.push_back(std::make_pair("perano", "#7F7F7F"));
    colors.push_back(std::make_pair("peru", "#CD853F"));
    colors.push_back(std::make_pair("pewter", "#96A8A1"));
    colors.push_back(std::make_pair("pictonblue", "#45B1E8"));
    colors.push_back(std::make_pair("pink", "#FFC0CB"));
    colors.push_back(std::make_pair("plum", "#DDA0DD"));
    colors.push_back(std::make_pair("powderblue", "#B0E0E6"));
    colors.push_back(std::make_pair("puertorico", "#3B69D6"));
    colors.push_back(std::make_pair("pumice", "#C2CAC4"));
    colors.push_back(std::make_pair("purple", "#800080"));
    colors.push_back(std::make_pair("purpleheart", "#69359C"));
    colors.push_back(std::make_pair("rebeccapurple", "#663399"));
    colors.push_back(std::make_pair("red", "#FF0000"));
    colors.push_back(std::make_pair("reddamask", "#DA6A41"));
    colors.push_back(std::make_pair("riptide", "#8BE6D8"));
    colors.push_back(std::make_pair("riverbed", "#434A59"));
    colors.push_back(std::make_pair("rosybrown", "#BC8F8F"));
    colors.push_back(std::make_pair("royalblue", "#4169E1"));
    colors.push_back(std::make_pair("royalpurple", "#6B3FA0"));
    colors.push_back(std::make_pair("saddlebrown", "#8B4513"));
    colors.push_back(std::make_pair("sage", "#9EAD3D"));
    colors.push_back(std::make_pair("salmon", "#FA8072"));
    colors.push_back(std::make_pair("sandybrown", "#F4A460"));
    colors.push_back(std::make_pair("sanjuan", "#334E75"));
    colors.push_back(std::make_pair("seagreen", "#2E8B57"));
    colors.push_back(std::make_pair("seashell", "#FFF5EE"));
    colors.push_back(std::make_pair("seance", "#721757"));
    colors.push_back(std::make_pair("shiraz", "#B52D42"));
    colors.push_back(std::make_pair("sienna", "#A0522D"));
    colors.push_back(std::make_pair("silver", "#C0C0C0"));
    colors.push_back(std::make_pair("skyblue", "#87CEEB"));
    colors.push_back(std::make_pair("slateblue", "#6A5ACD"));
    colors.push_back(std::make_pair("slategray", "#708090"));
    colors.push_back(std::make_pair("slategrey", "#708090"));
    colors.push_back(std::make_pair("snow", "#FFFAFA"));
    colors.push_back(std::make_pair("springgreen", "#00FF7F"));
    colors.push_back(std::make_pair("steelblue", "#4682B4"));
    colors.push_back(std::make_pair("studio", "#714AB2"));
    colors.push_back(std::make_pair("sunglo", "#E16865"));
    colors.push_back(std::make_pair("tan", "#D2B48C"));
    colors.push_back(std::make_pair("teal", "#008080"));
    colors.push_back(std::make_pair("terracotta", "#E2725B"));
    colors.push_back(std::make_pair("thistle", "#D8BFD8"));
    colors.push_back(std::make_pair("thunderbird", "#C02B18"));
    colors.push_back(std::make_pair("tiamaria", "#C1440E"));
    colors.push_back(std::make_pair("tobaccobrown", "#715D47"));
    colors.push_back(std::make_pair("gladegreen", "#4A6B4E"));
    colors.push_back(std::make_pair("tomato", "#FF6347"));
    colors.push_back(std::make_pair("tomthumb", "#273E33"));
    colors.push_back(std::make_pair("totempole", "#991B07"));
    colors.push_back(std::make_pair("turquoise", "#40E0D0"));
    colors.push_back(std::make_pair("vesuvius", "#AD975A"));
    colors.push_back(std::make_pair("violet", "#EE82EE"));
    colors.push_back(std::make_pair("waikawagray", "#5D7291"));
    colors.push_back(std::make_pair("waikawagrey", "#5D7291"));
    colors.push_back(std::make_pair("wheat", "#F5DEB3"));
    colors.push_back(std::make_pair("white", "#FFFFFF"));
    colors.push_back(std::make_pair("whitesmoke", "#F5F5F5"));
    colors.push_back(std::make_pair("yuma", "#CFAB7A"));
    colors.push_back(std::make_pair("yellow", "#FFFF00"));
    colors.push_back(std::make_pair("yellowgreen", "#9ACD32"));

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
