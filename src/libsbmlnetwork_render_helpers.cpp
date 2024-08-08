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

std::vector<std::map<std::string, std::string>> getPredefinedStyles() {
    std::vector<std::map<std::string, std::string>> predefinedStyles;
    // default style
    std::map<std::string, std::string> defaultStyle;
    defaultStyle["name"] = "default";
    defaultStyle["background-color"] = "White";
    defaultStyle["compartment-geometric-shape"] = "Rectangle";
    defaultStyle["compartment-border-color"] = "DarkCyan";
    defaultStyle["compartment-border-width"] = "3";
    defaultStyle["compartment-fill-color"] = "Lightgray";
    defaultStyle["compartment-font-color"] = "DarkCyan";
    defaultStyle["compartment-font-size"] = "10";
    defaultStyle["species-geometric-shape"] = "Rectangle";
    defaultStyle["species-border-color"] = "Black";
    defaultStyle["species-border-width"] = "3";
    defaultStyle["species-fill-color"] = "White";
    defaultStyle["species-font-color"] = "Black";
    defaultStyle["species-font-size"] = "24";
    defaultStyle["reaction-geometric-shape"] = "Rectangle";
    defaultStyle["reaction-line-color"] = "Black";
    defaultStyle["reaction-line-width"] = "3";
    defaultStyle["reaction-font-color"] = "DarkSlateGray";
    defaultStyle["reaction-font-size"] = "12";
    defaultStyle["line-ending-border-color"] = "Black";
    defaultStyle["line-ending-border-width"] = "3";
    defaultStyle["line-ending-fill-color"] = "Black";
    predefinedStyles.push_back(defaultStyle);
    // blue ombre style
    std::map<std::string, std::string> blueOmbreStyle;
    blueOmbreStyle["name"] = "blue ombre";
    blueOmbreStyle["background-color"] = "White";
    blueOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    blueOmbreStyle["compartment-border-color"] = "Arapawa";
    blueOmbreStyle["compartment-border-width"] = "3";
    blueOmbreStyle["compartment-fill-color"] = "White";
    blueOmbreStyle["compartment-font-color"] = "Arapawa";
    blueOmbreStyle["compartment-font-size"] = "10";
    blueOmbreStyle["species-geometric-shape"] = "Rectangle";
    blueOmbreStyle["species-fill-color"] = "Perano";
    blueOmbreStyle["species-border-color"] = "Arapawa";
    blueOmbreStyle["species-border-width"] = "3";
    blueOmbreStyle["species-font-color"] = "Arapawa";
    blueOmbreStyle["species-font-size"] = "24";
    blueOmbreStyle["reaction-line-color"] = "Indigo";
    blueOmbreStyle["reaction-line-width"] = "3";
    blueOmbreStyle["reaction-font-color"] = "Arapawa";
    blueOmbreStyle["reaction-font-size"] = "12";
    blueOmbreStyle["line-ending-border-color"] = "Indigo";
    blueOmbreStyle["line-ending-border-width"] = "3";
    blueOmbreStyle["line-ending-fill-color"] = "Indigo";
    predefinedStyles.push_back(blueOmbreStyle);
    // green ombre style
    std::map<std::string, std::string> greenOmbreStyle;
    greenOmbreStyle["name"] = "green ombre";
    greenOmbreStyle["background-color"] = "White";
    greenOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    greenOmbreStyle["compartment-border-color"] = "DarkFern";
    greenOmbreStyle["compartment-border-width"] = "3";
    greenOmbreStyle["compartment-fill-color"] = "White";
    greenOmbreStyle["compartment-font-color"] = "DarkFern";
    greenOmbreStyle["compartment-font-size"] = "10";
    greenOmbreStyle["species-geometric-shape"] = "Rectangle";
    greenOmbreStyle["species-fill-color"] = "GrannySmithApple";
    greenOmbreStyle["species-border-color"] = "DarkFern";
    greenOmbreStyle["species-border-width"] = "3";
    greenOmbreStyle["species-font-color"] = "DarkFern";
    greenOmbreStyle["species-font-size"] = "24";
    greenOmbreStyle["reaction-line-color"] = "FruitSalad";
    greenOmbreStyle["reaction-line-width"] = "3";
    greenOmbreStyle["reaction-font-color"] = "DarkFern";
    greenOmbreStyle["reaction-font-size"] = "12";
    greenOmbreStyle["line-ending-border-color"] = "FruitSalad";
    greenOmbreStyle["line-ending-border-width"] = "3";
    greenOmbreStyle["line-ending-fill-color"] = "FruitSalad";
    predefinedStyles.push_back(greenOmbreStyle);
    // gray ombre style
    std::map<std::string, std::string> grayOmbreStyle;
    grayOmbreStyle["name"] = "gray ombre";
    grayOmbreStyle["background-color"] = "White";
    grayOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    grayOmbreStyle["compartment-border-color"] = "Nandor";
    grayOmbreStyle["compartment-border-width"] = "3";
    grayOmbreStyle["compartment-fill-color"] = "White";
    grayOmbreStyle["compartment-font-color"] = "Nandor";
    grayOmbreStyle["compartment-font-size"] = "10";
    grayOmbreStyle["species-geometric-shape"] = "Rectangle";
    grayOmbreStyle["species-fill-color"] = "Pumice";
    grayOmbreStyle["species-border-color"] = "Nandor";
    grayOmbreStyle["species-border-width"] = "3";
    grayOmbreStyle["species-font-color"] = "Nandor";
    grayOmbreStyle["species-font-size"] = "24";
    grayOmbreStyle["reaction-line-color"] = "Gunsmoke";
    grayOmbreStyle["reaction-line-width"] = "3";
    grayOmbreStyle["reaction-font-color"] = "Nandor";
    grayOmbreStyle["reaction-font-size"] = "12";
    grayOmbreStyle["line-ending-border-color"] = "Gunsmoke";
    grayOmbreStyle["line-ending-border-width"] = "3";
    grayOmbreStyle["line-ending-fill-color"] = "Gunsmoke";
    predefinedStyles.push_back(grayOmbreStyle);
    // grey ombre style
    std::map<std::string, std::string> greyOmbreStyle;
    greyOmbreStyle["name"] = "grey ombre";
    greyOmbreStyle["background-color"] = "White";
    greyOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    greyOmbreStyle["compartment-border-color"] = "Nandor";
    greyOmbreStyle["compartment-border-width"] = "3";
    greyOmbreStyle["compartment-fill-color"] = "White";
    greyOmbreStyle["compartment-font-color"] = "Nandor";
    greyOmbreStyle["compartment-font-size"] = "10";
    greyOmbreStyle["species-geometric-shape"] = "Rectangle";
    greyOmbreStyle["species-fill-color"] = "Pumice";
    greyOmbreStyle["species-border-color"] = "Nandor";
    greyOmbreStyle["species-border-width"] = "3";
    greyOmbreStyle["species-font-color"] = "Nandor";
    greyOmbreStyle["species-font-size"] = "24";
    greyOmbreStyle["reaction-line-color"] = "Gunsmoke";
    greyOmbreStyle["reaction-line-width"] = "3";
    greyOmbreStyle["reaction-font-color"] = "Nandor";
    greyOmbreStyle["reaction-font-size"] = "12";
    greyOmbreStyle["line-ending-border-color"] = "Gunsmoke";
    greyOmbreStyle["line-ending-border-width"] = "3";
    greyOmbreStyle["line-ending-fill-color"] = "Gunsmoke";
    predefinedStyles.push_back(greyOmbreStyle);
    // red ombre
    std::map<std::string, std::string> redOmbreStyle;
    redOmbreStyle["name"] = "red ombre";
    redOmbreStyle["background-color"] = "White";
    redOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    redOmbreStyle["compartment-border-color"] = "TotemPole";
    redOmbreStyle["compartment-border-width"] = "3";
    redOmbreStyle["compartment-fill-color"] = "White";
    redOmbreStyle["compartment-font-color"] = "MexicanRed";
    redOmbreStyle["compartment-font-size"] = "10";
    redOmbreStyle["species-geometric-shape"] = "Rectangle";
    redOmbreStyle["species-fill-color"] = "Apricot";
    redOmbreStyle["species-border-color"] = "TotemPole";
    redOmbreStyle["species-border-width"] = "3";
    redOmbreStyle["species-font-color"] = "MexicanRed";
    redOmbreStyle["species-font-size"] = "24";
    redOmbreStyle["reaction-line-color"] = "Crimson";
    redOmbreStyle["reaction-line-width"] = "3";
    redOmbreStyle["reaction-font-color"] = "MexicanRed";
    redOmbreStyle["reaction-font-size"] = "12";
    redOmbreStyle["line-ending-border-color"] = "Crimson";
    redOmbreStyle["line-ending-border-width"] = "3";
    redOmbreStyle["line-ending-fill-color"] = "Crimson";
    predefinedStyles.push_back(redOmbreStyle);
    // orange ombre style
    std::map<std::string, std::string> orangeOmbreStyle;
    orangeOmbreStyle["name"] = "orange ombre";
    orangeOmbreStyle["background-color"] = "White";
    orangeOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    orangeOmbreStyle["compartment-border-color"] = "Vesuvius";
    orangeOmbreStyle["compartment-border-width"] = "3";
    orangeOmbreStyle["compartment-fill-color"] = "White";
    orangeOmbreStyle["compartment-font-color"] = "Vesuvius";
    orangeOmbreStyle["compartment-font-size"] = "10";
    orangeOmbreStyle["species-geometric-shape"] = "Rectangle";
    orangeOmbreStyle["species-fill-color"] = "DiSerria";
    orangeOmbreStyle["species-border-color"] = "Vesuvius";
    orangeOmbreStyle["species-border-width"] = "3";
    orangeOmbreStyle["species-font-color"] = "Vesuvius";
    orangeOmbreStyle["species-font-size"] = "24";
    orangeOmbreStyle["reaction-line-color"] = "RedDamask";
    orangeOmbreStyle["reaction-line-width"] = "3";
    orangeOmbreStyle["reaction-font-color"] = "Vesuvius";
    orangeOmbreStyle["reaction-font-size"] = "12";
    orangeOmbreStyle["line-ending-border-color"] = "RedDamask";
    orangeOmbreStyle["line-ending-border-width"] = "3";
    orangeOmbreStyle["line-ending-fill-color"] = "RedDamask";
    predefinedStyles.push_back(orangeOmbreStyle);
    // brown ombre style
    std::map<std::string, std::string> brownOmbreStyle;
    brownOmbreStyle["name"] = "brown ombre";
    brownOmbreStyle["background-color"] = "White";
    brownOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    brownOmbreStyle["compartment-border-color"] = "Mondo";
    brownOmbreStyle["compartment-border-width"] = "3";
    brownOmbreStyle["compartment-fill-color"] = "White";
    brownOmbreStyle["compartment-font-color"] = "Mondo";
    brownOmbreStyle["compartment-font-size"] = "10";
    brownOmbreStyle["species-geometric-shape"] = "Rectangle";
    brownOmbreStyle["species-fill-color"] = "Domino";
    brownOmbreStyle["species-border-color"] = "Mondo";
    brownOmbreStyle["species-border-width"] = "3";
    brownOmbreStyle["species-font-color"] = "Mondo";
    brownOmbreStyle["species-font-size"] = "24";
    brownOmbreStyle["reaction-line-color"] = "Hemlock";
    brownOmbreStyle["reaction-line-width"] = "3";
    brownOmbreStyle["reaction-font-color"] = "Mondo";
    brownOmbreStyle["reaction-font-size"] = "12";
    brownOmbreStyle["line-ending-border-color"] = "Hemlock";
    brownOmbreStyle["line-ending-border-width"] = "3";
    brownOmbreStyle["line-ending-fill-color"] = "Hemlock";
    predefinedStyles.push_back(brownOmbreStyle);
    // purple ombre style
    std::map<std::string, std::string> purpleOmbreStyle;
    purpleOmbreStyle["name"] = "purple ombre";
    purpleOmbreStyle["background-color"] = "White";
    purpleOmbreStyle["compartment-geometric-shape"] = "Rectangle";
    purpleOmbreStyle["compartment-border-color"] = "RebeccaPurple";
    purpleOmbreStyle["compartment-border-width"] = "3";
    purpleOmbreStyle["compartment-fill-color"] = "Purple";
    purpleOmbreStyle["compartment-font-color"] = "White";
    purpleOmbreStyle["compartment-font-size"] = "10";
    purpleOmbreStyle["species-geometric-shape"] = "Rectangle";
    purpleOmbreStyle["species-fill-color"] = "MediumPurple";
    purpleOmbreStyle["species-border-color"] = "PurpleHeart";
    purpleOmbreStyle["species-border-width"] = "3";
    purpleOmbreStyle["species-font-color"] = "White";
    purpleOmbreStyle["species-font-size"] = "24";
    purpleOmbreStyle["reaction-line-color"] = "White";
    purpleOmbreStyle["reaction-line-width"] = "3";
    purpleOmbreStyle["reaction-font-color"] = "White";
    purpleOmbreStyle["reaction-font-size"] = "12";
    purpleOmbreStyle["line-ending-border-color"] = "White";
    purpleOmbreStyle["line-ending-border-width"] = "3";
    purpleOmbreStyle["line-ending-fill-color"] = "White";
    predefinedStyles.push_back(purpleOmbreStyle);
    // purple ombre 2 style
    std::map<std::string, std::string> purpleOmbre2Style;
    purpleOmbre2Style["name"] = "purple ombre 2";
    purpleOmbre2Style["background-color"] = "White";
    purpleOmbre2Style["compartment-geometric-shape"] = "Rectangle";
    purpleOmbre2Style["compartment-border-color"] = "Seance";
    purpleOmbre2Style["compartment-border-width"] = "3";
    purpleOmbre2Style["compartment-fill-color"] = "White";
    purpleOmbre2Style["compartment-font-color"] = "Seance";
    purpleOmbre2Style["compartment-font-size"] = "10";
    purpleOmbre2Style["species-geometric-shape"] = "Rectangle";
    purpleOmbre2Style["species-fill-color"] = "EastSide";
    purpleOmbre2Style["species-border-color"] = "Seance";
    purpleOmbre2Style["species-border-width"] = "3";
    purpleOmbre2Style["species-font-color"] = "Seance";
    purpleOmbre2Style["species-font-size"] = "24";
    purpleOmbre2Style["reaction-line-color"] = "Studio";
    purpleOmbre2Style["reaction-line-width"] = "3";
    purpleOmbre2Style["reaction-font-color"] = "Seance";
    purpleOmbre2Style["reaction-font-size"] = "12";
    purpleOmbre2Style["line-ending-border-color"] = "Studio";
    purpleOmbre2Style["line-ending-border-width"] = "3";
    purpleOmbre2Style["line-ending-fill-color"] = "Studio";
    predefinedStyles.push_back(purpleOmbre2Style);
    // black and white style
    std::map<std::string, std::string> blackAndWhiteStyle;
    blackAndWhiteStyle["name"] = "black and white";
    blackAndWhiteStyle["background-color"] = "White";
    blackAndWhiteStyle["compartment-geometric-shape"] = "Rectangle";
    blackAndWhiteStyle["compartment-border-color"] = "White";
    blackAndWhiteStyle["compartment-border-width"] = "3";
    blackAndWhiteStyle["compartment-fill-color"] = "White";
    blackAndWhiteStyle["compartment-font-color"] = "Black";
    blackAndWhiteStyle["compartment-font-size"] = "10";
    blackAndWhiteStyle["species-geometric-shape"] = "Rectangle";
    blackAndWhiteStyle["species-fill-color"] = "White";
    blackAndWhiteStyle["species-border-color"] = "Black";
    blackAndWhiteStyle["species-border-width"] = "3";
    blackAndWhiteStyle["species-font-color"] = "Black";
    blackAndWhiteStyle["species-font-size"] = "24";
    blackAndWhiteStyle["reaction-line-color"] = "Black";
    blackAndWhiteStyle["reaction-line-width"] = "3";
    blackAndWhiteStyle["reaction-font-color"] = "Black";
    blackAndWhiteStyle["reaction-font-size"] = "12";
    blackAndWhiteStyle["line-ending-border-color"] = "Black";
    blackAndWhiteStyle["line-ending-border-width"] = "3";
    blackAndWhiteStyle["line-ending-fill-color"] = "Black";
    predefinedStyles.push_back(blackAndWhiteStyle);
    // orange blue
    std::map<std::string, std::string> orangeBlueStyle;
    orangeBlueStyle["name"] = "orange blue";
    orangeBlueStyle["background-color"] = "White";
    orangeBlueStyle["compartment-geometric-shape"] = "Rectangle";
    orangeBlueStyle["compartment-border-color"] = "Jaffa";
    orangeBlueStyle["compartment-border-width"] = "3";
    orangeBlueStyle["compartment-fill-color"] = "White";
    orangeBlueStyle["compartment-font-color"] = "CeruleanBlue";
    orangeBlueStyle["compartment-font-size"] = "10";
    orangeBlueStyle["species-geometric-shape"] = "Rectangle";
    orangeBlueStyle["species-fill-color"] = "Picton Blue";
    orangeBlueStyle["species-border-color"] = "Jaffa";
    orangeBlueStyle["species-border-width"] = "3";
    orangeBlueStyle["species-font-color"] = "CeruleanBlue";
    orangeBlueStyle["species-font-size"] = "24";
    orangeBlueStyle["reaction-line-color"] = "Jaffa";
    orangeBlueStyle["reaction-line-width"] = "3";
    orangeBlueStyle["reaction-font-color"] = "CeruleanBlue";
    orangeBlueStyle["reaction-font-size"] = "12";
    orangeBlueStyle["line-ending-border-color"] = "Jaffa";
    orangeBlueStyle["line-ending-border-width"] = "3";
    orangeBlueStyle["line-ending-fill-color"] = "Jaffa";
    predefinedStyles.push_back(orangeBlueStyle);
    // purple yellow
    std::map<std::string, std::string> purpleYellowStyle;
    purpleYellowStyle["name"] = "purple yellow";
    purpleYellowStyle["background-color"] = "White";
    purpleYellowStyle["compartment-geometric-shape"] = "Rectangle";
    purpleYellowStyle["compartment-border-color"] = "DaisyBush";
    purpleYellowStyle["compartment-border-width"] = "3";
    purpleYellowStyle["compartment-fill-color"] = "White";
    purpleYellowStyle["compartment-font-color"] = "DaisyBush";
    purpleYellowStyle["compartment-font-size"] = "10";
    purpleYellowStyle["species-geometric-shape"] = "Rectangle";
    purpleYellowStyle["species-fill-color"] = "Khaki";
    purpleYellowStyle["species-border-color"] = "DaisyBush";
    purpleYellowStyle["species-border-width"] = "3";
    purpleYellowStyle["species-font-color"] = "DaisyBush";
    purpleYellowStyle["species-font-size"] = "24";
    purpleYellowStyle["reaction-line-color"] = "RoyalPurple";
    purpleYellowStyle["reaction-line-width"] = "3";
    purpleYellowStyle["reaction-font-color"] = "DaisyBush";
    purpleYellowStyle["reaction-font-size"] = "12";
    purpleYellowStyle["line-ending-border-color"] = "RoyalPurple";
    purpleYellowStyle["line-ending-border-width"] = "3";
    purpleYellowStyle["line-ending-fill-color"] = "RoyalPurple";
    predefinedStyles.push_back(purpleYellowStyle);
    // green red style
    std::map<std::string, std::string> greenRedStyle;
    greenRedStyle["name"] = "green red";
    greenRedStyle["background-color"] = "White";
    greenRedStyle["compartment-geometric-shape"] = "Rectangle";
    greenRedStyle["compartment-border-color"] = "ForestGreen";
    greenRedStyle["compartment-border-width"] = "3";
    greenRedStyle["compartment-fill-color"] = "White";
    greenRedStyle["compartment-font-color"] = "Thunderbird";
    greenRedStyle["compartment-font-size"] = "10";
    greenRedStyle["species-geometric-shape"] = "Rectangle";
    greenRedStyle["species-fill-color"] = "Fern";
    greenRedStyle["species-border-color"] = "Everglade";
    greenRedStyle["species-border-width"] = "3";
    greenRedStyle["species-font-color"] = "Thunderbird";
    greenRedStyle["species-font-size"] = "24";
    greenRedStyle["reaction-line-color"] = "Thunderbird";
    greenRedStyle["reaction-line-width"] = "3";
    greenRedStyle["reaction-font-color"] = "Thunderbird";
    greenRedStyle["reaction-font-size"] = "12";
    greenRedStyle["line-ending-border-color"] = "Thunderbird";
    greenRedStyle["line-ending-border-width"] = "3";
    greenRedStyle["line-ending-fill-color"] = "Thunderbird";
    predefinedStyles.push_back(greenRedStyle);
    // power style
    std::map<std::string, std::string> powerStyle;
    powerStyle["name"] = "power";
    powerStyle["background-color"] = "White";
    powerStyle["compartment-geometric-shape"] = "Rectangle";
    powerStyle["compartment-border-color"] = "Mandy";
    powerStyle["compartment-border-width"] = "3";
    powerStyle["compartment-fill-color"] = "Pewter";
    powerStyle["compartment-font-color"] = "Gondola";
    powerStyle["compartment-font-size"] = "10";
    powerStyle["species-geometric-shape"] = "Rectangle";
    powerStyle["species-fill-color"] = "Carnation";
    powerStyle["species-border-color"] = "Gondola";
    powerStyle["species-border-width"] = "3";
    powerStyle["species-font-color"] = "Gondola";
    powerStyle["species-font-size"] = "24";
    powerStyle["reaction-line-color"] = "Gondola";
    powerStyle["reaction-line-width"] = "3";
    powerStyle["reaction-font-color"] = "Gondola";
    powerStyle["reaction-font-size"] = "12";
    powerStyle["line-ending-border-color"] = "Gondola";
    powerStyle["line-ending-border-width"] = "3";
    powerStyle["line-ending-fill-color"] = "Gondola";
    predefinedStyles.push_back(powerStyle);
    // calm style
    std::map<std::string, std::string> calmStyle;
    calmStyle["name"] = "calm";
    calmStyle["background-color"] = "White";
    calmStyle["compartment-geometric-shape"] = "Rectangle";
    calmStyle["compartment-border-color"] = "Paradiso";
    calmStyle["compartment-border-width"] = "3";
    calmStyle["compartment-fill-color"] = "MonteCarlo";
    calmStyle["compartment-font-color"] = "TotemPole";
    calmStyle["compartment-font-size"] = "10";
    calmStyle["species-geometric-shape"] = "Rectangle";
    calmStyle["species-fill-color"] = "Jaffa";
    calmStyle["species-border-color"] = "GoldenGrass";
    calmStyle["species-border-width"] = "3";
    calmStyle["species-font-color"] = "TotemPole";
    calmStyle["species-font-size"] = "24";
    calmStyle["reaction-line-color"] = "Paradiso";
    calmStyle["reaction-line-width"] = "3";
    calmStyle["reaction-font-color"] = "TotemPole";
    calmStyle["reaction-font-size"] = "12";
    calmStyle["line-ending-border-color"] = "Paradiso";
    calmStyle["line-ending-border-width"] = "3";
    calmStyle["line-ending-fill-color"] = "Paradiso";
    predefinedStyles.push_back(calmStyle);
    // sunset style
    std::map<std::string, std::string> sunsetStyle;
    sunsetStyle["name"] = "sunset";
    sunsetStyle["background-color"] = "White";
    sunsetStyle["compartment-geometric-shape"] = "Rectangle";
    sunsetStyle["compartment-border-color"] = "Hibiscus";
    sunsetStyle["compartment-border-width"] = "3";
    sunsetStyle["compartment-fill-color"] = "OrangePeel";
    sunsetStyle["compartment-font-color"] = "PurpleHeart";
    sunsetStyle["compartment-font-size"] = "10";
    sunsetStyle["species-geometric-shape"] = "Rectangle";
    sunsetStyle["species-fill-color"] = "Hibiscus";
    sunsetStyle["species-border-color"] = "PurpleHeart";
    sunsetStyle["species-border-width"] = "3";
    sunsetStyle["species-font-color"] = "PurpleHeart";
    sunsetStyle["species-font-size"] = "24";
    sunsetStyle["reaction-line-color"] = "FrenchRose";
    sunsetStyle["reaction-line-width"] = "3";
    sunsetStyle["reaction-font-color"] = "PurpleHeart";
    sunsetStyle["reaction-font-size"] = "12";
    sunsetStyle["line-ending-border-color"] = "FrenchRose";
    sunsetStyle["line-ending-border-width"] = "3";
    sunsetStyle["line-ending-fill-color"] = "FrenchRose";
    predefinedStyles.push_back(sunsetStyle);
    // electric style
    std::map<std::string, std::string> electricStyle;
    electricStyle["name"] = "electric";
    electricStyle["background-color"] = "White";
    electricStyle["compartment-geometric-shape"] = "Rectangle";
    electricStyle["compartment-border-color"] = "Java";
    electricStyle["compartment-border-width"] = "3";
    electricStyle["compartment-fill-color"] = "Riptide";
    electricStyle["compartment-font-color"] = "Cerise";
    electricStyle["compartment-font-size"] = "10";
    electricStyle["species-geometric-shape"] = "Rectangle";
    electricStyle["species-fill-color"] = "LightOrchid";
    electricStyle["species-border-color"] = "Java";
    electricStyle["species-border-width"] = "3";
    electricStyle["species-font-color"] = "Cerise";
    electricStyle["species-font-size"] = "24";
    electricStyle["reaction-line-color"] = "Hopbush";
    electricStyle["reaction-line-width"] = "3";
    electricStyle["reaction-font-color"] = "Cerise";
    electricStyle["reaction-font-size"] = "12";
    electricStyle["line-ending-border-color"] = "Hopbush";
    electricStyle["line-ending-border-width"] = "3";
    electricStyle["line-ending-fill-color"] = "Hopbush";
    predefinedStyles.push_back(electricStyle);
    // midnight style
    std::map<std::string, std::string> midnightStyle;
    midnightStyle["name"] = "midnight";
    midnightStyle["background-color"] = "White";
    midnightStyle["compartment-geometric-shape"] = "Rectangle";
    midnightStyle["compartment-border-color"] = "Thunderbird";
    midnightStyle["compartment-border-width"] = "3";
    midnightStyle["compartment-fill-color"] = "DullLavender";
    midnightStyle["compartment-font-color"] = "Thunderbird";
    midnightStyle["compartment-font-size"] = "10";
    midnightStyle["species-geometric-shape"] = "Rectangle";
    midnightStyle["species-fill-color"] = "Sunglo";
    midnightStyle["species-border-color"] = "BayOfMany";
    midnightStyle["species-border-width"] = "3";
    midnightStyle["species-font-color"] = "Thunderbird";
    midnightStyle["species-font-size"] = "24";
    midnightStyle["reaction-line-color"] = "Thunderbird";
    midnightStyle["reaction-line-width"] = "3";
    midnightStyle["reaction-font-color"] = "Thunderbird";
    midnightStyle["reaction-font-size"] = "12";
    midnightStyle["line-ending-border-color"] = "Thunderbird";
    // vibrance style
    std::map<std::string, std::string> vibranceStyle;
    vibranceStyle["name"] = "vibrance";
    vibranceStyle["background-color"] = "White";
    vibranceStyle["compartment-geometric-shape"] = "Rectangle";
    vibranceStyle["compartment-border-color"] = "Casal";
    vibranceStyle["compartment-border-width"] = "3";
    vibranceStyle["compartment-fill-color"] = "CarrotOrange";
    vibranceStyle["compartment-font-color"] = "Shiraz";
    vibranceStyle["compartment-font-size"] = "10";
    vibranceStyle["species-geometric-shape"] = "Rectangle";
    vibranceStyle["species-fill-color"] = "Shiraz";
    vibranceStyle["species-border-color"] = "CannonPink";
    vibranceStyle["species-border-width"] = "3";
    vibranceStyle["species-font-color"] = "Shiraz";
    vibranceStyle["species-font-size"] = "24";
    vibranceStyle["reaction-line-color"] = "Buttercup";
    vibranceStyle["reaction-line-width"] = "3";
    vibranceStyle["reaction-font-color"] = "Shiraz";
    vibranceStyle["reaction-font-size"] = "12";
    vibranceStyle["line-ending-border-color"] = "Buttercup";
    vibranceStyle["line-ending-border-width"] = "3";
    vibranceStyle["line-ending-fill-color"] = "Buttercup";
    predefinedStyles.push_back(vibranceStyle);
    // ocean style
    std::map<std::string, std::string> oceanStyle;
    oceanStyle["name"] = "ocean";
    oceanStyle["background-color"] = "White";
    oceanStyle["compartment-geometric-shape"] = "Rectangle";
    oceanStyle["compartment-border-color"] = "Elm";
    oceanStyle["compartment-border-width"] = "3";
    oceanStyle["compartment-fill-color"] = "Yuma";
    oceanStyle["compartment-font-color"] = "RiverBed";
    oceanStyle["compartment-font-size"] = "10";
    oceanStyle["species-geometric-shape"] = "Rectangle";
    oceanStyle["species-fill-color"] = "AquaIsland";
    oceanStyle["species-border-color"] = "Elm";
    oceanStyle["species-border-width"] = "3";
    oceanStyle["species-font-color"] = "RiverBed";
    oceanStyle["species-font-size"] = "24";
    oceanStyle["reaction-line-color"] = "Chino";
    oceanStyle["reaction-line-width"] = "3";
    oceanStyle["reaction-font-color"] = "RiverBed";
    oceanStyle["reaction-font-size"] = "12";
    oceanStyle["line-ending-border-color"] = "Chino";
    oceanStyle["line-ending-border-width"] = "3";
    oceanStyle["line-ending-fill-color"] = "Chino";
    predefinedStyles.push_back(oceanStyle);
    // forest style
    std::map<std::string, std::string> forestStyle;
    forestStyle["name"] = "forest";
    forestStyle["background-color"] = "White";
    forestStyle["compartment-geometric-shape"] = "Rectangle";
    forestStyle["compartment-border-color"] = "LunarGreen";
    forestStyle["compartment-border-width"] = "3";
    forestStyle["compartment-fill-color"] = "TobaccoBrown";
    forestStyle["compartment-font-color"] = "GladeGreen";
    forestStyle["compartment-font-size"] = "10";
    forestStyle["species-geometric-shape"] = "Rectangle";
    forestStyle["species-fill-color"] = "Sage";
    forestStyle["species-border-color"] = "TomThumb";
    forestStyle["species-border-width"] = "3";
    forestStyle["species-font-color"] = "GladeGreen";
    forestStyle["species-font-size"] = "24";
    forestStyle["reaction-line-color"] = "TobaccoBrown";
    forestStyle["reaction-line-width"] = "3";
    forestStyle["reaction-font-color"] = "GladeGreen";
    forestStyle["reaction-font-size"] = "12";
    forestStyle["line-ending-border-color"] = "TobaccoBrown";
    forestStyle["line-ending-border-width"] = "3";
    forestStyle["line-ending-fill-color"] = "TobaccoBrown";
    predefinedStyles.push_back(forestStyle);
    // warm tone style
    std::map<std::string, std::string> warmToneStyle;
    warmToneStyle["name"] = "warm tone";
    warmToneStyle["background-color"] = "White";
    warmToneStyle["compartment-geometric-shape"] = "Rectangle";
    warmToneStyle["compartment-border-color"] = "Mondo";
    warmToneStyle["compartment-border-width"] = "3";
    warmToneStyle["compartment-fill-color"] = "TiaMaria";
    warmToneStyle["compartment-font-color"] = "Ochre";
    warmToneStyle["compartment-font-size"] = "10";
    warmToneStyle["species-geometric-shape"] = "Rectangle";
    warmToneStyle["species-fill-color"] = "CreamCan";
    warmToneStyle["species-border-color"] = "TiaMaria";
    warmToneStyle["species-border-width"] = "3";
    warmToneStyle["species-font-color"] = "Ochre";
    warmToneStyle["species-font-size"] = "24";
    warmToneStyle["reaction-line-color"] = "Christine";
    warmToneStyle["reaction-line-width"] = "3";
    warmToneStyle["reaction-font-color"] = "Ochre";
    warmToneStyle["reaction-font-size"] = "12";
    warmToneStyle["line-ending-border-color"] = "Christine";
    warmToneStyle["line-ending-border-width"] = "3";
    warmToneStyle["line-ending-fill-color"] = "Christine";
    predefinedStyles.push_back(warmToneStyle);
    // cool tone style
    std::map<std::string, std::string> coolToneStyle;
    coolToneStyle["name"] = "cool tone";
    coolToneStyle["background-color"] = "White";
    coolToneStyle["compartment-geometric-shape"] = "Rectangle";
    coolToneStyle["compartment-border-color"] = "BlueRibbon";
    coolToneStyle["compartment-border-width"] = "3";
    coolToneStyle["compartment-fill-color"] = "PurpleHeart";
    coolToneStyle["compartment-font-color"] = "BlueRibbon";
    coolToneStyle["compartment-font-size"] = "10";
    coolToneStyle["species-geometric-shape"] = "Rectangle";
    coolToneStyle["species-fill-color"] = "PurpleHeart";
    coolToneStyle["species-border-color"] = "AzureRadiance";
    coolToneStyle["species-border-width"] = "3";
    coolToneStyle["species-font-color"] = "BlueRibbon";
    coolToneStyle["species-font-size"] = "24";
    coolToneStyle["reaction-line-color"] = "PuertoRico";
    coolToneStyle["reaction-line-width"] = "3";
    coolToneStyle["reaction-font-color"] = "BlueRibbon";
    coolToneStyle["reaction-font-size"] = "12";
    coolToneStyle["line-ending-border-color"] = "PuertoRico";
    coolToneStyle["line-ending-border-width"] = "3";
    coolToneStyle["line-ending-fill-color"] = "PuertoRico";
    predefinedStyles.push_back(coolToneStyle);
    // escher style
    std::map<std::string, std::string> escherStyle;
    escherStyle["name"] = "escher";
    escherStyle["background-color"] = "White";
    escherStyle["compartment-geometric-shape"] = "Rectangle";
    escherStyle["compartment-border-color"] = "Black";
    escherStyle["compartment-border-width"] = "3";
    escherStyle["compartment-fill-color"] = "White";
    escherStyle["compartment-font-color"] = "Black";
    escherStyle["compartment-font-size"] = "10";
    escherStyle["compartment-font-style"] = "italic";
    escherStyle["compartment-font-weight"] = "bold";
    escherStyle["species-geometric-shape"] = "Ellipse";
    escherStyle["species-geometric-shape-ratio"] = "1";
    escherStyle["species-border-color"] = "HawaiianTan";
    escherStyle["species-border-width"] = "5";
    escherStyle["species-fill-color"] = "Terracotta";
    escherStyle["species-font-color"] = "Black";
    escherStyle["species-font-size"] = "12";
    escherStyle["species-font-style"] = "italic";
    escherStyle["species-font-weight"] = "bold";
    escherStyle["reaction-geometric-shape"] = "Ellipse";
    escherStyle["reaction-geometric-shape-center-x"] = "0.0";
    escherStyle["reaction-geometric-shape-center-y"] = "0.0";
    escherStyle["reaction-geometric-shape-radius-x"] = "4";
    escherStyle["reaction-geometric-shape-radius-y"] = "4";
    escherStyle["reaction-line-color"] = "SanJuan";
    escherStyle["reaction-line-width"] = "9";
    escherStyle["reaction-border-color"] = "MineShaft";
    escherStyle["reaction-border-width"] = "3";
    escherStyle["reaction-fill-color"] = "WaikawaGray";
    escherStyle["reaction-font-color"] = "LuckyPoint";
    escherStyle["reaction-font-size"] = "24";
    escherStyle["reaction-font-style"] = "italic";
    escherStyle["reaction-font-weight"] = "bold";
    escherStyle["line-ending-border-color"] = "SanJuan";
    escherStyle["line-ending-border-width"] = "6";
    escherStyle["line-ending-fill-color"] = "SanJuan";
    escherStyle["display-reaction-text-label"] = "true";
    predefinedStyles.push_back(escherStyle);

    return predefinedStyles;
}

std::vector<std::string> getPredefinedStyleNames() {
    std::vector<std::string> predefinedStyleNames;
    std::vector<std::map<std::string, std::string>> predefinedStyles = getPredefinedStyles();
    for (const auto& predefinedStyle : predefinedStyles) {
        if (predefinedStyle.find("name") != predefinedStyle.end())
            predefinedStyleNames.push_back(predefinedStyle.find("name")->second);
    }
    return predefinedStyleNames;
}

const bool isValidPredefinedStyleName(const std::string& predefinedStyleName) {
    std::vector<std::string> predefinedStyleNames = getPredefinedStyleNames();
    if (std::find(predefinedStyleNames.begin(), predefinedStyleNames.end(), predefinedStyleName) != predefinedStyleNames.end())
        return true;

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
