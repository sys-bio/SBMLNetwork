#include "libsbml_ne_sbmldocument_layout.h"
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

Layout* getLayout(SBMLDocument* document, unsigned int layoutIndex) {
    return getLayout(getListOfLayouts(document), layoutIndex);
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

Dimensions* getDimensions(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensions(getLayout(document, layoutIndex));
}

double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensionWidth(getLayout(document, layoutIndex));
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    return setDimensionWidth(getLayout(document, layoutIndex), width);
}

int setDimensionWidth(SBMLDocument* document, const double& width) {

    for (unsigned int i = 0; i < getNumLayouts(document); i++) {
        if (setDimensionWidth(document, i, width))
            return -1;
    }

    return 0;
}

double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensionHeight(getLayout(document, layoutIndex));
}

int setDimensionHeight(SBMLDocument* document, const double& height) {

    for (unsigned int i = 0; i < getNumLayouts(document); i++) {
        if (setDimensionHeight(document, i, height))
            return -1;
    }

    return 0;
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    return setDimensionHeight(getLayout(document, layoutIndex), height);
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document) {
    unsigned int numCompartmentGlyphs = 0;
    for (unsigned int i = 0; i < getNumLayouts(document); i++)
        numCompartmentGlyphs += getNumCompartmentGlyphs(getLayout(document, i));

    return numCompartmentGlyphs;
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumCompartmentGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    unsigned int numCompartmentGlyphs = 0;
    for (unsigned int i = 0; i < getNumLayouts(document); i++)
        numCompartmentGlyphs += getCompartmentGlyphs(document, i, compartmentId).size();

    return numCompartmentGlyphs;
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int n, const std::string& compartmentId) {
    return getCompartmentGlyphs(document, n, compartmentId).size();
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    std::vector<CompartmentGlyph*> compartmentGlyphs;
    std::vector<CompartmentGlyph*> thisLayoutCompartmentGlyphs;
    for (unsigned int i = 0; i < getNumLayouts(document); i++) {
        thisLayoutCompartmentGlyphs = getCompartmentGlyphs(document, i, compartmentId);
        compartmentGlyphs.insert(std::end(compartmentGlyphs), std::begin(thisLayoutCompartmentGlyphs), std::end(thisLayoutCompartmentGlyphs));
    }

    return compartmentGlyphs;
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId) {
    std::vector<CompartmentGlyph*> compartmentGlyphs;
    Layout* layout = getLayout(document, layoutIndex);
    if (layout)
        compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(layout, compartmentId);

    return compartmentGlyphs;
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int compartmentGlyphIndex) {
    std::vector<CompartmentGlyph*> compartmentGlyphs = getCompartmentGlyphs(document, compartmentId);
    if (compartmentGlyphIndex < compartmentGlyphs.size())
        return compartmentGlyphs.at(compartmentGlyphIndex);

    return NULL;
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId, unsigned int compartmentGlyphIndex) {
    std::vector<CompartmentGlyph*> compartmentGlyphs = getCompartmentGlyphs(document, layoutIndex, compartmentId);
    if (compartmentGlyphIndex < compartmentGlyphs.size())
        return compartmentGlyphs.at(compartmentGlyphIndex);

    return NULL;
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document) {
    unsigned int numSpeciesGlyphs = 0;
    for (unsigned int i = 0; i < getNumLayouts(document); i++)
        numSpeciesGlyphs += getNumSpeciesGlyphs(getLayout(document, i));

    return numSpeciesGlyphs;
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumSpeciesGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    unsigned int numSpeciesGlyphs = 0;
    for (unsigned int i = 0; i < getNumLayouts(document); i++)
        numSpeciesGlyphs += getSpeciesGlyphs(document, i, speciesId).size();

    return numSpeciesGlyphs;
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int n, const std::string& speciesId) {
    return getSpeciesGlyphs(document, n, speciesId).size();
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    std::vector<SpeciesGlyph*> speciesGlyphs;
    std::vector<SpeciesGlyph*> thisLayoutSpeciesGlyphs;
    for (unsigned int i = 0; i < getNumLayouts(document); i++) {
        thisLayoutSpeciesGlyphs = getSpeciesGlyphs(document, i, speciesId);
        speciesGlyphs.insert(std::end(speciesGlyphs), std::begin(thisLayoutSpeciesGlyphs), std::end(thisLayoutSpeciesGlyphs));
    }

    return speciesGlyphs;
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId) {
    std::vector<SpeciesGlyph*> speciesGlyphs;
    Layout* layout = getLayout(document, layoutIndex);
    if (layout)
        speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);

    return speciesGlyphs;
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(document, speciesId);
    if (speciesGlyphIndex < speciesGlyphs.size())
        return speciesGlyphs.at(speciesGlyphIndex);

    return NULL;
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(document, layoutIndex, speciesId);
    if (speciesGlyphIndex < speciesGlyphs.size())
        return speciesGlyphs.at(speciesGlyphIndex);

    return NULL;
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document) {
    unsigned int numReactionGlyphs = 0;
    for (unsigned int i = 0; i < getNumLayouts(document); i++)
        numReactionGlyphs += getNumReactionGlyphs(getLayout(document, i));

    return numReactionGlyphs;
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumReactionGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    unsigned int numReactionGlyphs = 0;
    for (unsigned int i = 0; i < getNumLayouts(document); i++)
        numReactionGlyphs += getReactionGlyphs(document, i, reactionId).size();

    return numReactionGlyphs;
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return getReactionGlyphs(document, layoutIndex, reactionId).size();
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    std::vector<ReactionGlyph*> reactionGlyphs;
    std::vector<ReactionGlyph*> thisLayoutReactionGlyphs;
    for (unsigned int i = 0; i < getNumLayouts(document); i++) {
        thisLayoutReactionGlyphs = getReactionGlyphs(document, i, reactionId);
        reactionGlyphs.insert(std::end(reactionGlyphs), std::begin(thisLayoutReactionGlyphs), std::end(thisLayoutReactionGlyphs));
    }

    return reactionGlyphs;
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    std::vector<ReactionGlyph*> reactionGlyphs;
    Layout* layout = getLayout(document, layoutIndex);
    if (layout)
        reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, reactionId);

    return reactionGlyphs;
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(document, reactionId);
    if (reactionGlyphIndex < reactionGlyphs.size())
        return reactionGlyphs.at(reactionGlyphIndex);

    return NULL;
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(document, layoutIndex, reactionId);
    if (reactionGlyphIndex < reactionGlyphs.size())
        return reactionGlyphs.at(reactionGlyphIndex);

    return NULL;
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getReactionGlyph(document, reactionId, reactionGlyphIndex));
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex));
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs;
    ReactionGlyph* reactionGlyph = getReactionGlyph(document, reactionId, reactionGlyphIndex);
    for (unsigned int i = 0 ; i < getNumSpeciesReferenceGlyphs(reactionGlyph); i++)
        speciesReferenceGlyphs.push_back(getSpeciesReferenceGlyph(reactionGlyph, i));

    return speciesReferenceGlyphs;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs;
    ReactionGlyph* reactionGlyph = getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex);
    for (unsigned int i = 0 ; i < getNumSpeciesReferenceGlyphs(reactionGlyph); i++)
        speciesReferenceGlyphs.push_back(getSpeciesReferenceGlyph(reactionGlyph, i));

    return speciesReferenceGlyphs;
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceGlyph(getReactionGlyph(document, reactionId, reactionGlyphIndex), speciesReferenceGlyphIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceGlyph(getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex), speciesReferenceGlyphIndex);
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
