#include "libsbml_ne_util_layout.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"
#include "libsbml_ne_autolayout.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

ListOfLayouts* getListOfLayouts(SBMLDocument* document) {
    if (document) {
        LayoutModelPlugin* layoutModelPlugin = getLayoutModelPlugin(document);
        if (layoutModelPlugin)
            return layoutModelPlugin->getListOfLayouts();
    }

    return NULL;
}

const unsigned int getNumLayouts(SBMLDocument* document) {
    return getNumLayouts(getListOfLayouts(document));
}

Layout* getLayout(SBMLDocument* document, unsigned int n) {
    return getLayout(getListOfLayouts(document), n);
}

int addLayout(SBMLDocument* document, Layout* layout) {
    if (document && layout) {
        LayoutModelPlugin* layoutModelPlugin = enableAndGetLayoutModelPlugin(document);
        if (layoutModelPlugin) {
            layoutModelPlugin->addLayout(layout);
            return 0;
        }
    }

    return -1;
}

Layout* createLayout(SBMLDocument* document) {
    if (document) {
        LayoutModelPlugin* layoutModelPlugin = enableAndGetLayoutModelPlugin(document);
        if (layoutModelPlugin)
            return layoutModelPlugin->createLayout();
    }

    return NULL;
}

int removeAllLayouts(SBMLDocument* document) {
    ListOfLayouts* listOfLayouts = getListOfLayouts(document);
    if (listOfLayouts) {
        while (listOfLayouts->size())
            listOfLayouts->remove(0);
        return 0;
    }

    return -1;
}

int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout) {
    if (document && layout) {
        LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(document->getLevel(), document->getVersion());
        layout->setId("libSBML_NetworkEditor_Layout");
        layout->setDimensions(new Dimensions(layoutPkgNamespaces, 1024.0, 1024.0));
        Model* model = document->getModel();
        if (model) {
            setCompartmentGlyphs(model, layout, layoutPkgNamespaces);
            setSpeciesGlyphs(model, layout, layoutPkgNamespaces);
            setReactionGlyphs(model, layout, layoutPkgNamespaces);
            locateGlyphs(model, layout);
            setCompartmentTextGlyphs(layout, layoutPkgNamespaces);
            setSpeciesTextGlyphs(layout, layoutPkgNamespaces);
            return 0;
        }
    }

    return -1;
}

int createDefaultLayout(SBMLDocument* document) {
    if (!getNumLayouts(document)) {
        Layout* layout = createLayout(document);
        return setDefaultLayoutFeatures(document, layout);
    }

    return -1;
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    return getCompartmentGlyphs(document, compartmentId).size();
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    std::vector<CompartmentGlyph*> compartmentGlyphs;
    Layout* layout = getLayout(document);
    if (layout)
        compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(layout, compartmentId);

    return compartmentGlyphs;
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int n) {
    std::vector<CompartmentGlyph*> compartmentGlyphs = getCompartmentGlyphs(document, compartmentId);
    if (n < compartmentGlyphs.size())
        return compartmentGlyphs.at(n);

    return NULL;
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getSpeciesGlyphs(document, speciesId).size();
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    std::vector<SpeciesGlyph*> speciesGlyphs;
    Layout* layout = getLayout(document);
    if (layout)
        speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);

    return speciesGlyphs;
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int n) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(document, speciesId);
    if (n < speciesGlyphs.size())
        return speciesGlyphs.at(n);

    return NULL;
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getReactionGlyphs(document, reactionId).size();
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    std::vector<ReactionGlyph*> reactionGlyphs;
    Layout* layout = getLayout(document);
    if (layout)
        reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, reactionId);

    return reactionGlyphs;
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int n) {
    std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(document, reactionId);
    if (n < reactionGlyphs.size())
        return reactionGlyphs.at(n);

    return NULL;
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceGlyph(getReactionGlyph(document, reactionId, reactionGlyphIndex), speciesReferenceGlyphIndex);
}

std::string getCompartmentId(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Compartment* compartment = getCompartment(document, graphicalObject);
    if (compartment)
        return compartment->getId();

    return "";
}

Compartment* getCompartment(SBMLDocument* document, GraphicalObject* graphicalObject) {
    if (document && document->isSetModel()) {
        if (isCompartmentGlyph(graphicalObject))
            return findCompartmentGlyphCompartment(document->getModel(), (CompartmentGlyph*)graphicalObject);
        else if (isSpeciesGlyph(graphicalObject))
            return findSpeciesGlyphCompartment(document->getModel(), (SpeciesGlyph*)graphicalObject);
        else if (isReactionGlyph(graphicalObject))
            return findReactionGlyphCompartment(document->getModel(), (ReactionGlyph*)graphicalObject);
    }

    return NULL;
}

}
