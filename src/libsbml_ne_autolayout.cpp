#include "libsbml_ne_autolayout.h"
#include "libsbml_ne_layout_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void locateGlyphs(Model* model, Layout* layout) {
    GVC_t* gvc = gvContext();
    Agraph_t* graph = createGraph();
    addGlyphsToGraph(model, layout, graph);
    applyAutoLayoutOnGraph(layout, gvc, graph);
    extractGlyphsFeaturesFromGraph(model, layout, graph);
    deleteGraph(gvc, graph);
}

Agraph_t* createGraph() {
    std::string value = "Graph";
    return agopen(&value[0], Agdirected, NULL);
}

void addGlyphsToGraph(Model* model, Layout* layout, Agraph_t* graph) {
    addCompartmentGlyphsToGraph(model, layout, graph);
    addReactionGlyphsToGraph(layout, graph);
}

void addCompartmentGlyphsToGraph(Model* model, Layout* layout, Agraph_t* graph) {
    CompartmentGlyph* compartmentGlyph = NULL;
    Agraph_t* subgraph = NULL;
    for (int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        compartmentGlyph = layout->getCompartmentGlyph(i);
        std::string value = "clusterGraph" + std::to_string(i);
        subgraph = agsubg(graph, &value[0], true);
        addSpeciesGlyphsToSubGraph(model, layout, compartmentGlyph, subgraph);
    }
}

void addSpeciesGlyphsToSubGraph(Model* model, Layout* layout, CompartmentGlyph* compartmentGlyph, Agraph_t* subgraph) {
    SpeciesGlyph* speciesGlyph = NULL;
    for (int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        speciesGlyph = layout->getSpeciesGlyph(i);
        Compartment* compartment = findSpeciesGlyphCompartment(model, speciesGlyph);
        if (compartment && compartmentGlyphBelongs(compartmentGlyph, compartment))
            addSpeciesGlyphToSubGraph(speciesGlyph, subgraph);
    }
}

void addSpeciesGlyphToSubGraph(SpeciesGlyph* speciesGlyph, Agraph_t* subgraph) {
    double maxSpeciesBoxWidth =  120.0;
    double minSpeciesBoxHeight = 36.0;
    int stringLength = speciesGlyph->getSpeciesId().length();
    std::string value = speciesGlyph->getSpeciesId();
    Agnode_t* node = agnode(subgraph, &value[0], true);
    std::string attribute = "width";
    value = std::to_string((std::max(std::min(14.5 * (stringLength + 2), maxSpeciesBoxWidth), minSpeciesBoxHeight)) / 72.0);
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    attribute = "height";
    value = std::to_string(minSpeciesBoxHeight / 72.0);
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    attribute = "fixedsize";
    value = "false";
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    attribute = "shape";
    value = "rectangle";
    agsafeset(node, &attribute[0], &value[0], &value[0]);
}

void addReactionGlyphsToGraph(Layout* layout, Agraph_t* graph) {
    ReactionGlyph* reactionGlyph = NULL;
    for (int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        reactionGlyph = layout->getReactionGlyph(i);
        addReactinGlyphToGraph(layout, reactionGlyph, graph);
    }
}

void addReactinGlyphToGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_t* graph) {
    double minReactionBoxHeight = 36.0;
    std::string value = reactionGlyph->getReactionId();
    Agnode_t* node = agnode(graph, &value[0], true);
    std::string attribute = "width";
    value = std::to_string(0.8 * minReactionBoxHeight / 72.0);
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    attribute = "height";
    value = std::to_string(0.8 * minReactionBoxHeight / 72.0);
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    attribute = "fixedsize";
    value = "true";
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    attribute = "shape";
    value = "ellipse";
    agsafeset(node, &attribute[0], &value[0], &value[0]);
    addSpeciesReferenceGlyphsToGraph(layout, reactionGlyph, graph, node);
}

void addSpeciesReferenceGlyphsToGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_t* graph, Agnode_t* reactionNode) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = NULL;
    for (int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
        speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(i);
        addSpeciesReferenceGlyphToGraph(layout, speciesReferenceGlyph, graph, reactionNode);
    }
}

void addSpeciesReferenceGlyphToGraph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph, Agraph_t* graph, Agnode_t* reactionNode) {
    SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(speciesReferenceGlyph->getSpeciesGlyphId());
    if (speciesGlyph) {
        std::string value = speciesGlyph->getSpeciesId();
        Agnode_t* speciesNode = agnode(graph, &value[0], true);
        value = speciesReferenceGlyph->getId();
        if (speciesReferenceGlyph->getRole() == SPECIES_ROLE_PRODUCT)
            agedge(graph, reactionNode, speciesNode, &value[0], true);
        else
            agedge(graph, speciesNode, reactionNode, &value[0], true);
    }
}

void applyAutoLayoutOnGraph(Layout* layout, GVC_t* gvc, Agraph_t* graph) {
    if (layout->getNumCompartmentGlyphs() == 1 && layout->getNumSpeciesGlyphs() < 20)
        gvLayout (gvc, graph, "circo");
    else
        gvLayout (gvc, graph, "twopi");
}

void extractGlyphsFeaturesFromGraph(Model* model, Layout* layout, Agraph_t* graph) {
    double minXLayout = INT_MAX;
    double minYLayout = INT_MAX;
    double maxXLayout = INT_MIN;
    double maxYLayout = INT_MIN;
    extractCompartmentGlyphsFromGraph(model, layout, graph, minXLayout, minYLayout, maxXLayout, maxYLayout);
    extractReactionGlyphsFromGraph(layout, graph, minXLayout, minYLayout, maxXLayout, maxYLayout);
    updateDimensions(layout, minXLayout, minYLayout, maxXLayout, maxYLayout);
}

void extractCompartmentGlyphsFromGraph(Model* model, Layout* layout, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout) {
    double minXCompartment;
    double minYCompartment;
    double maxXCompartment;
    double maxYCompartment;
    CompartmentGlyph* compartmentGlyph = NULL;
    for (int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        compartmentGlyph = layout->getCompartmentGlyph(i);
        minXCompartment = INT_MAX;
        minYCompartment = INT_MAX;
        maxXCompartment = INT_MIN;
        maxYCompartment = INT_MIN;
        SpeciesGlyph* speciesGlyph = NULL;
        Compartment* compartment = NULL;
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            speciesGlyph = layout->getSpeciesGlyph(i);
            compartment = findSpeciesGlyphCompartment(model, speciesGlyph);
            if (compartment && compartmentGlyphBelongs(compartmentGlyph, compartment))
                extractSpeciesGlyphFromGraph(speciesGlyph, graph, minXLayout, minYLayout, maxXLayout, maxYLayout, minXCompartment, minYCompartment, maxXCompartment, maxYCompartment);
        }

        if (containsSpecies(model, layout, compartmentGlyph))
            updateBoundingBox(compartmentGlyph->getBoundingBox(), minXCompartment, minYCompartment, maxXCompartment, maxYCompartment);
    }
}

void extractSpeciesGlyphFromGraph(SpeciesGlyph* speciesGlyph, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout, double& minXCompartment, double& minYCompartment, double& maxXCompartment, double& maxYCompartment) {
    std::string value = speciesGlyph->getSpeciesId();
    Agnode_t* node = agnode(graph, &value[0], false);
    if (node) {
        updateBoundingBox(speciesGlyph->getBoundingBox(), node);
        updateExtetns(minXLayout, minYLayout, maxXLayout, maxYLayout, speciesGlyph->getBoundingBox());
        updateExtetns(minXCompartment, minYCompartment, maxXCompartment, maxYCompartment, speciesGlyph->getBoundingBox());
    }
}

void extractReactionGlyphsFromGraph(Layout* layout, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout) {
    ReactionGlyph* reactionGlyph = NULL;
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        reactionGlyph = layout->getReactionGlyph(i);
        extractReactionGlyphFromGraph(layout, reactionGlyph, graph, minXLayout, minYLayout, maxXLayout, maxYLayout);
    }
}

void extractReactionGlyphFromGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_t* graph, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout) {
    std::string value = reactionGlyph->getReactionId();
    Agnode_t* node = agnode(graph, &value[0], false);
    if (node) {
        updateBoundingBox(reactionGlyph->getBoundingBox(), node);
        updateExtetns(minXLayout, minYLayout, maxXLayout, maxYLayout, reactionGlyph->getBoundingBox());
        extractSpeciesReferenceGlyphsFromGraph(layout, reactionGlyph, graph, node, minXLayout, minYLayout, maxXLayout, maxYLayout);
    }
}

void extractSpeciesReferenceGlyphsFromGraph(Layout* layout, ReactionGlyph* reactionGlyph, Agraph_t* graph, Agnode_t* reactionNode, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout) {
    SpeciesReferenceGlyph* speciesReferenceGlyph = NULL;
    for (unsigned int i = 0; i < reactionGlyph->getNumSpeciesReferenceGlyphs(); i++) {
        speciesReferenceGlyph = reactionGlyph->getSpeciesReferenceGlyph(i);
        extractSpeciesReferenceGlyphFromGraph(layout, speciesReferenceGlyph, graph, reactionNode, minXLayout, minYLayout, maxXLayout, maxYLayout);
    }
}

void extractSpeciesReferenceGlyphFromGraph(Layout* layout, SpeciesReferenceGlyph* speciesReferenceGlyph, Agraph_t* graph, Agnode_t* reactionNode, double& minXLayout, double& minYLayout, double& maxXLayout, double& maxYLayout) {
    SpeciesGlyph* speciesGlyph = layout->getSpeciesGlyph(speciesReferenceGlyph->getSpeciesGlyphId());
    if (speciesGlyph) {
        std::string value = speciesGlyph->getSpeciesId();
        Agnode_t* speciesNode = agnode(graph, &value[0], false);
        value = speciesReferenceGlyph->getId();
        Agedge_t* e = NULL;
        if (speciesReferenceGlyph->getRole() == SPECIES_ROLE_PRODUCT)
            e = agedge(graph, reactionNode, speciesNode, &value[0], true);
        else
            e = agedge(graph, speciesNode, reactionNode, &value[0], true);

        if (e) {
            updateLineSegment(speciesReferenceGlyph->getCurve()->getCurveSegment(0), e);
            updateExtetns(minXLayout, minYLayout, maxXLayout, maxYLayout, speciesReferenceGlyph->getCurve()->getCurveSegment(0));
        }
    }
}

void updateBoundingBox(BoundingBox* box, Agnode_t* node) {
    box->setX(ND_coord(node).x - 0.5 * ND_width(node) * 72.0);
    box->setY(ND_coord(node).y  - 0.5 * ND_height(node) * 72.0);
    box->setWidth(ND_width(node) * 72.0);
    box->setHeight(ND_height(node) * 72.0);
}

void updateBoundingBox(BoundingBox* box, const double minX, const double minY, const double maxX, const double maxY) {
    box->setX(minX - 0.1 * (maxX - minX));
    box->setY(minY - 0.1 * (maxY - minY));
    box->setWidth(1.2 * (maxX - minX));
    box->setHeight(1.2 * (maxY - minY));
}

void updateLineSegment(LineSegment* lineSegment, Agedge_t* edge) {
    for (unsigned int i = 3; i < ED_spl(edge)->list->size; i = i + 3) {
        lineSegment->getStart()->setX(ED_spl(edge)->list[0].list[i - 3].x);
        lineSegment->getStart()->setY(ED_spl(edge)->list[0].list[i - 3].y);
        if (dynamic_cast< const CubicBezier* >(lineSegment)) {
            ((CubicBezier*)lineSegment)->getBasePoint1()->setX(ED_spl(edge)->list[0].list[i - 2].x);
            ((CubicBezier*)lineSegment)->getBasePoint1()->setY(ED_spl(edge)->list[0].list[i - 2].y);
            ((CubicBezier*)lineSegment)->getBasePoint2()->setX(ED_spl(edge)->list[0].list[i - 1].x);
            ((CubicBezier*)lineSegment)->getBasePoint2()->setY(ED_spl(edge)->list[0].list[i - 1].y);
        }
        lineSegment->getEnd()->setX(ED_spl(edge)->list[0].list[i].x);
        lineSegment->getEnd()->setY(ED_spl(edge)->list[0].list[i].y);
    }
}

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, BoundingBox* box) {
    if (box->x() < minX)
        minX = box->x();
    if (box->y() < minY)
        minY = box->y();
    if (box->x() + box->width() > maxX)
        maxX = box->x() + box->width();
    if (box->y() + box->height() > maxY)
        maxY = box->y() + box->height();
}

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, LineSegment* lineSegment) {
    updateExtetns(minX, minY, maxX, maxY, lineSegment->getStart()->x(), lineSegment->getStart()->y());
    if (dynamic_cast< const CubicBezier* >(lineSegment)) {
        updateExtetns(minX, minY, maxX, maxY, ((CubicBezier*)lineSegment)->getBasePoint1()->x(), ((CubicBezier*)lineSegment)->getBasePoint1()->y());
        updateExtetns(minX, minY, maxX, maxY, ((CubicBezier*)lineSegment)->getBasePoint2()->x(), ((CubicBezier*)lineSegment)->getBasePoint2()->y());
    }
    updateExtetns(minX, minY, maxX, maxY, lineSegment->getEnd()->x(), lineSegment->getEnd()->y());
}

void updateExtetns(double& minX, double& minY, double& maxX, double& maxY, const double x, const double y) {
    if (x < minX)
        minX = x;
    if (y < minY)
        minY = y;
    if (x > maxX)
        maxX = x;
    if (y > maxY)
        maxY = y;
}

void updateDimensions(Layout* layout, const double minX, const double minY, const double maxX, const double maxY) {
    layout->getDimensions()->setWidth(maxX - minX);
    layout->getDimensions()->setHeight(maxY - minY);
}

void deleteGraph(GVC_t* gvc, Agraph_t* graph) {
    gvFreeLayout(gvc, graph);
    agclose(graph);
}

}
