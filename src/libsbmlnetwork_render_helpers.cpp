#include "libsbmlnetwork_render_helpers.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_render.h"
#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_layout_helpers.h"
#include "colors/libsbmlnetwork_colors.h"
#include "styles/libsbmlnetwork_styles.h"

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

const std::string getColorValue(RenderInformationBase* renderInformationBase, const std::string &colorId) {
    ColorDefinition* colorDefinition = renderInformationBase->getColorDefinition(colorId);
    if (colorDefinition)
        return colorDefinition->getValue();

    return "";
}

const std::string getColorId(RenderInformationBase* renderInformationBase, const std::string &colorValue) {
    for (unsigned int i = 0; i < renderInformationBase->getNumColorDefinitions(); i++) {
        ColorDefinition* colorDefinition = renderInformationBase->getColorDefinition(i);
        if (stringCompare(colorDefinition->getValue(), colorValue))
            return colorDefinition->getId();
    }

    return "";
}


const std::string addColor(SBMLDocument* document, Style* style, const std::string &color) {
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

    return "";
}

const std::string addColor(SBMLDocument* document, LineEnding* lineEnding, const std::string &color) {
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

    return "";
}

const std::string addColor(RenderInformationBase* renderInformationBase, const std::string &color) {
    if (isValidHexColorCode(color))
        return addColor(renderInformationBase, getColorIdFromHexColorCode(renderInformationBase, color), color);
    else
        return addColor(renderInformationBase, color, getHexColorCodeFromHtmlColorName(color));
}

const std::string addColor(RenderInformationBase* renderInformationBase, const std::string &colorId, const std::string &colorValue) {
    if (stringCompare(getColorValue(renderInformationBase, colorId), colorValue))
        return colorId;

    if (!colorId.empty() && !colorValue.empty()) {
        RenderPkgNamespaces renderPkgNamespaces(renderInformationBase->getLevel(), renderInformationBase->getVersion());
        ColorDefinition* cd = createColorDefinition(&renderPkgNamespaces, toLowerCase(colorId), colorValue);
        if (!renderInformationBase->addColorDefinition(cd)) {
            delete cd;
            return toLowerCase(colorId);
        }

    return "";
}

const std::string addGradient(SBMLDocument* document, Style* style, const std::string type, std::vector<std::pair<std::string, double>> stopsVector) {
    RenderInformationBase* renderInformation = NULL;
    if (style) {
        for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
            LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, i);
            for (unsigned int j = 0; j < localRenderInformation->getNumLocalStyles(); j++) {
                if (localRenderInformation->getLocalStyle(j) == style) {
                    renderInformation = localRenderInformation;
                    break;
                }
            }
        }
        for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
            GlobalRenderInformation* globalRenderInformation = getGlobalRenderInformation(document, i);
            for (unsigned int j = 0; j < globalRenderInformation->getNumGlobalStyles(); j++) {
                if (globalRenderInformation->getGlobalStyle(j) == style) {
                    renderInformation = globalRenderInformation;
                    break;
                }
            }
        }
    }

    if (renderInformation)
        return addGradient(renderInformation, type, stopsVector);

    return "";
}

const std::string addGradient(SBMLDocument* document, LineEnding* lineEnding, const std::string type, std::vector<std::pair<std::string, double>> stopsVector) {
    RenderInformationBase* renderInformation = NULL;
    if (lineEnding) {
        for (unsigned int i = 0; i < getNumLocalRenderInformation(document); i++) {
            LocalRenderInformation* localRenderInformation = getLocalRenderInformation(document, i);
            for (unsigned int j = 0; j < localRenderInformation->getNumLineEndings(); j++) {
                if (localRenderInformation->getLineEnding(j) == lineEnding) {
                    renderInformation = localRenderInformation;
                    break;
                }
            }
        }
        for (unsigned int i = 0; i < getNumGlobalRenderInformation(document); i++) {
            GlobalRenderInformation* globalRenderInformation = getGlobalRenderInformation(document, i);
            for (unsigned int j = 0; j < globalRenderInformation->getNumLineEndings(); j++) {
                if (globalRenderInformation->getLineEnding(j) == lineEnding) {
                    renderInformation = globalRenderInformation;
                    break;
                }
            }
        }
    }

    if (renderInformation)
        return addGradient(renderInformation, type, stopsVector);

    return "";
}

const std::string addGradient(RenderInformationBase* renderInformationBase, const std::string type, std::vector<std::pair<std::string, double>> stopsVector) {
    if (isValidGradientStopsVector(stopsVector)) {
        for (unsigned int i = 0; i < stopsVector.size(); i++)
            addColor(renderInformationBase, stopsVector[i].first);
        std::string gradientId = getUniqueGradientId(renderInformationBase);
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(renderInformationBase->getLevel(), renderInformationBase->getVersion());
        if (!renderInformationBase->addGradientDefinition(createGradient(renderPkgNamespaces, gradientId, type, stopsVector)))
            return gradientId;
    }

    return "";
}

const std::string getColorIdFromHexColorCode(RenderInformationBase* renderInformationBase, const std::string &hexColorCode) {
    std::string colorId = getColorId(renderInformationBase, hexColorCode);
    if (!colorId.empty())
        return colorId;
    colorId = getHtmlColorNameFromHexColorCode(hexColorCode);
    if (!colorId.empty())
        return colorId;

    return getUniqueColorId(renderInformationBase);
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

GradientBase* createGradient(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, const std::string type, std::vector<std::pair<std::string, double>> stopsVector) {
    if (type == "linear")
        return createLinearGradient(renderPkgNamespaces, id, stopsVector);
    else if (type == "radial")
        return createRadialGradient(renderPkgNamespaces, id, stopsVector);

    return NULL;
}

GradientBase* createLinearGradient(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, std::vector<std::pair<std::string, double>> stopsVector) {
    LinearGradient* linearGradient = new LinearGradient(renderPkgNamespaces, id);
    for (unsigned int i = 0; i < stopsVector.size(); i++)
        linearGradient->addGradientStop(createGradientStop(renderPkgNamespaces, stopsVector[i].first, RelAbsVector(0.0, stopsVector[i].second)));

    return linearGradient;
}

GradientBase* createRadialGradient(RenderPkgNamespaces* renderPkgNamespaces, const std::string &id, std::vector<std::pair<std::string, double>> stopsVector) {
    RadialGradient* radialGradient = new RadialGradient(renderPkgNamespaces, id);
    for (unsigned int i = 0; i < stopsVector.size(); i++)
        radialGradient->addGradientStop(createGradientStop(renderPkgNamespaces, stopsVector[i].first, stopsVector[i].second));

    return radialGradient;
}

GradientStop* createGradientStop(RenderPkgNamespaces* renderPkgNamespaces, const std::string &stopColor, const RelAbsVector& offset) {
    GradientStop* gradientStop = new GradientStop(renderPkgNamespaces);
    gradientStop->setStopColor(stopColor);
    gradientStop->setOffset(offset);
    return gradientStop;
}

const std::string getUniqueGradientId(RenderInformationBase* renderInformationBase) {
    std::string uniqueGradientId = "gradient_0";
    unsigned int i = 0;
    while (renderInformationBase->getGradientDefinition(uniqueGradientId))
        uniqueGradientId = "gradient_" + std::to_string(i++);

    return uniqueGradientId;
}

LineEnding* createLocalLineEnding(SBMLDocument* document, RenderInformationBase* localRenderInformation, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    LineEnding* localLineEnding = NULL;
    std::string localLineEndingId = getLocalLineEndingId(document, speciesReferenceGlyph);
    if (localRenderInformation && !localLineEndingId.empty()) {
        localLineEnding = ((LocalRenderInformation*)localRenderInformation)->createLineEnding();
        localLineEnding->setId(localLineEndingId);
        if (isSetStartHead(document, speciesReferenceGlyph))
            setStartHead(document, speciesReferenceGlyph, localLineEndingId);
        else if (isSetEndHead(document, speciesReferenceGlyph))
            setEndHead(document, speciesReferenceGlyph, localLineEndingId);
    }

    return localLineEnding;
}

const bool isLocal(SBMLDocument* document, LineEnding* lineEnding, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    if (!lineEnding || !speciesReferenceGlyph)
        return false;

    std::string localLineEndingId = getLocalLineEndingId(document, speciesReferenceGlyph);
    if (localLineEndingId.empty())
        return false;

    return lineEnding->getId() == localLineEndingId;
}

const std::string getLocalLineEndingId(SBMLDocument* document, SpeciesReferenceGlyph* speciesReferenceGlyph) {
    std::string globalLineEndingId = getStartHead(document, speciesReferenceGlyph);
    if (globalLineEndingId.empty())
        globalLineEndingId = getEndHead(document, speciesReferenceGlyph);
    if (!globalLineEndingId.empty()) {
        if (globalLineEndingId.find(speciesReferenceGlyph->getId()) != std::string::npos)
            return globalLineEndingId;

        return speciesReferenceGlyph->getId() + "_" + globalLineEndingId;
    }

    return "";
}

void addDefaultLineEndings(GlobalRenderInformation* globalRenderInformation) {
    addProductHeadLineEnding(globalRenderInformation);
    addModifierHeadLineEnding(globalRenderInformation);
    addActivatorHeadLineEnding(globalRenderInformation);
    addInhibitorHeadLineEnding(globalRenderInformation);
}

void addProductHeadLineEnding(GlobalRenderInformation* globalRenderInformation) {
    if (!globalRenderInformation->getLineEnding("productHead")) {
        RenderPkgNamespaces renderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        LineEnding* le = createProductHeadLineEnding(&renderPkgNamespaces);
        globalRenderInformation->addLineEnding(le);
        delete le;
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
        RenderPkgNamespaces renderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        LineEnding* le = createModifierHeadLineEnding(&renderPkgNamespaces);
        globalRenderInformation->addLineEnding(le);
        delete le;
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
        RenderPkgNamespaces renderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        LineEnding* le = createActivatorHeadLineEnding(&renderPkgNamespaces);
        globalRenderInformation->addLineEnding(le);
        delete le;
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
        RenderPkgNamespaces renderPkgNamespaces(globalRenderInformation->getLevel(), globalRenderInformation->getVersion());
        LineEnding* le = createInhibitorHeadLineEnding(&renderPkgNamespaces);
        globalRenderInformation->addLineEnding(le);
        delete le;
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
    LayoutPkgNamespaces layoutPkgNamespaces(lineEnding->getLevel(), lineEnding->getVersion());
    BoundingBox bb(&layoutPkgNamespaces, lineEnding->getId() + "_bb", -12.0, -6.0, 12.0, 12.0);
    lineEnding->setBoundingBox(&bb);
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
    renderGroup->setStroke(getDefaultPredefinedStyleFeatures()["species-font-color"]);
    renderGroup->setFontSize(RelAbsVector(std::stod(getDefaultPredefinedStyleFeatures()["species-font-size"]), 0.0));
    renderGroup->setFontFamily(getDefaultPredefinedStyleFeatures()["species-font-family"]);
    renderGroup->setFontWeight(getDefaultPredefinedStyleFeatures()["species-font-weight"]);
    renderGroup->setFontStyle(getDefaultPredefinedStyleFeatures()["species-font-style"]);
    renderGroup->setTextAnchor(getDefaultPredefinedStyleFeatures()["species-text-horizontal-alignment"]);
    renderGroup->setVTextAnchor(getDefaultPredefinedStyleFeatures()["species-text-vertical-alignment"]);
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

const bool canHaveStrokeColor(GraphicalObject* graphicalObject) {
    return true;
}

const bool canHaveStrokeWidth(GraphicalObject* graphicalObject) {
    return true;
}

const bool canHaveStrokeDashArray(GraphicalObject* graphicalObject) {
    return true;
}

const bool canHaveFillColor(GraphicalObject* graphicalObject) {
    if (isCompartmentGlyph(graphicalObject) || isSpeciesGlyph(graphicalObject) || isReactionGlyph(graphicalObject))
        return true;

    return false;
}

const bool canHaveFillRule(GraphicalObject* graphicalObject) {
    if (isCompartmentGlyph(graphicalObject) || isSpeciesGlyph(graphicalObject) || (isReactionGlyph(graphicalObject) && !getCurve(graphicalObject)))
        return true;

    return false;
}

const bool canHaveFontColor(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveFontFamily(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveFontSize(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveFontWeight(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveFontStyle(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveTextAnchor(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveVTextAnchor(TextGlyph* textGlyph) {
    if (textGlyph)
        return true;

    return false;
}

const bool canHaveStartHead(GraphicalObject* graphicalObject) {
    if (isSpeciesReferenceGlyph(graphicalObject))
        return true;

    return false;
}

const bool canHaveEndHead(GraphicalObject* graphicalObject) {
    if (isSpeciesReferenceGlyph(graphicalObject))
        return true;

    return false;
}

const bool canHaveGeometricShape(GraphicalObject* graphicalObject) {
    if (isCompartmentGlyph(graphicalObject) || isSpeciesGlyph(graphicalObject) || (isReactionGlyph(graphicalObject) && !getCurve(graphicalObject)))
        return true;

    return false;
}

const bool isValidBackgroundColorValue(const std::string& backgroundColor) {
    return isValidColorValue(backgroundColor);
}

const bool isValidSpreadMethodValue(const std::string& spreadMethod) {
    return isValueValid(spreadMethod, getValidSpreadMethodValues());
}

const bool isValidGradientStopsVector(std::vector<std::pair<std::string, double>> gradientStopsVector) {
    for (unsigned int i = 0; i < gradientStopsVector.size(); i++) {
        if (!isValidStopColorValue(gradientStopsVector.at(i).first) || !isValidOffsetValue(RelAbsVector(0.0, gradientStopsVector.at(i).second)))
            return false;
    }

    return true;
}

const bool isValidOffsetValue(const RelAbsVector& offset) {
    if (std::abs(offset.getAbsoluteValue()) > 0.0001)
        return false;

    return isValidRelAbsVectorRelativeValue(offset.getRelativeValue());
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
    if (isValidDoubleValue(strokeWidth) && strokeWidth > 0.0001)
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
    if (isValidDoubleValue(dash) && dash > 0.000)
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
    if (isValidDoubleValue(ratio) && ratio > 0.0001)
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
    if (isValidRelAbsVectorValue(relAbsVectorValue) && relAbsVectorValue.getAbsoluteValue() >= 0.000)
        return true;

    std::cerr << "error: the absolute value of the entered value must be equal or greater than 0" << std::endl;
    return false;
}

const bool isValidRelAbsVectorValue(const RelAbsVector& relAbsVectorValue) {
    if (isValidDoubleValue(relAbsVectorValue.getAbsoluteValue()) && isValidDoubleValue(relAbsVectorValue.getRelativeValue()))
        return true;

    std::cerr << "error: the values of the RelAbsVector must be valid double values" << std::endl;
    return false;
}

const bool isValidRelAbsVectorRelativeValue(const double& value) {
    if (isValidDoubleValue(value) && value >= 0.0 && value <= 100.0)
        return true;
    std::cerr << "error: the entered value must be between 0 and 100" << std::endl;
    return false;
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
