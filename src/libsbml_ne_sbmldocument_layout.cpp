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

int setDimensionWidth(SBMLDocument* document, const double& width) {
    return setDimensionWidth(getLayout(document), width);
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width) {
    return setDimensionWidth(getLayout(document, layoutIndex), width);
}

double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex) {
    return getDimensionHeight(getLayout(document, layoutIndex));
}

int setDimensionHeight(SBMLDocument* document, const double& height) {
    return setDimensionHeight(getLayout(document), height);
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height) {
    return setDimensionHeight(getLayout(document, layoutIndex), height);
}

const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumGraphicalObjects(getLayout(document, layoutIndex));
}

const unsigned int getNumGraphicalObjects(SBMLDocument* document, const std::string& id) {
    return getNumGraphicalObjects(getLayout(document), id);
}

const unsigned int getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getNumGraphicalObjects(getLayout(document, layoutIndex), id);
}

std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, const std::string& id) {
    return getGraphicalObjects(getLayout(document), id);
}

std::vector<GraphicalObject*> getGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getGraphicalObjects(getLayout(document, layoutIndex), id);
}

GraphicalObject* getGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getGraphicalObject(getLayout(document), id, graphicalObjectIndex);
}

GraphicalObject* getGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getGraphicalObject(getLayout(document, layoutIndex), id);
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumCompartmentGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    return getNumCompartmentGlyphs(getLayout(document), compartmentId);
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId) {
    return getNumCompartmentGlyphs(getLayout(document, layoutIndex), compartmentId);
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    return getCompartmentGlyphs(getLayout(document), compartmentId);
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId) {
    return getCompartmentGlyphs(getLayout(document, layoutIndex), compartmentId);
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int compartmentGlyphIndex) {
    return getCompartmentGlyph(getLayout(document), compartmentId, compartmentGlyphIndex);
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId, unsigned int compartmentGlyphIndex) {
    return getCompartmentGlyph(getLayout(document, layoutIndex), compartmentId, compartmentGlyphIndex);
}

bool isCompartmentGlyph(SBMLDocument* document, const std::string& id) {
    return isCompartmentGlyph(getLayout(document), id);
}

bool isCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isCompartmentGlyph(getLayout(document, layoutIndex), id);
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumSpeciesGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getNumSpeciesGlyphs(getLayout(document), speciesId);
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId) {
    return getNumSpeciesGlyphs(getLayout(document, layoutIndex), speciesId);
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getSpeciesGlyphs(getLayout(document), speciesId);
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId) {
    return getSpeciesGlyphs(getLayout(document, layoutIndex), speciesId);
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(getLayout(document), speciesId, speciesGlyphIndex);
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(getLayout(document, layoutIndex), speciesId, speciesGlyphIndex);
}

bool isSpeciesGlyph(SBMLDocument* document, const std::string& id) {
    return isSpeciesGlyph(getLayout(document), id);
}

bool isSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isSpeciesGlyph(getLayout(document, layoutIndex), id);
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumReactionGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getNumReactionGlyphs(getLayout(document), reactionId);
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return getNumReactionGlyphs(getLayout(document, layoutIndex), reactionId);
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getReactionGlyphs(getLayout(document), reactionId);
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return getReactionGlyphs(getLayout(document, layoutIndex), reactionId);
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getReactionGlyph(getLayout(document), reactionId, reactionGlyphIndex);
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getReactionGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

bool isReactionGlyph(SBMLDocument* document, const std::string& id) {
    return isReactionGlyph(getLayout(document), id);
}

bool isReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isReactionGlyph(getLayout(document, layoutIndex), id);
}



/*
const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumSpeciesGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getNumSpeciesGlyphs(document, 0, speciesId);
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, unsigned int n, const std::string& speciesId) {
    return getSpeciesGlyphs(document, n, speciesId).size();
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getSpeciesGlyphs(document, 0, speciesId);
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId) {
    std::vector<SpeciesGlyph*> speciesGlyphs;
    Layout* layout = getLayout(document, layoutIndex);
    if (layout)
        speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, speciesId);

    return speciesGlyphs;
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(document, 0, speciesId, speciesGlyphIndex);
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(document, layoutIndex, speciesId);
    if (speciesGlyphIndex < speciesGlyphs.size())
        return speciesGlyphs.at(speciesGlyphIndex);

    return NULL;
}

bool isSpeciesGlyph(SBMLDocument* document, const std::string& id) {
    return isSpeciesGlyph(getLayout(document), id);
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumReactionGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getNumReactionGlyphs(document, 0, reactionId);
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return getReactionGlyphs(document, layoutIndex, reactionId).size();
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getReactionGlyphs(document, 0, reactionId);
}

std::vector<ReactionGlyph*> getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    std::vector<ReactionGlyph*> reactionGlyphs;
    Layout* layout = getLayout(document, layoutIndex);
    if (layout)
        reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, reactionId);

    return reactionGlyphs;
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getReactionGlyph(document, 0, reactionId, reactionGlyphIndex);
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(document, layoutIndex, reactionId);
    if (reactionGlyphIndex < reactionGlyphs.size())
        return reactionGlyphs.at(reactionGlyphIndex);

    return NULL;
}

bool isReactionGlyph(SBMLDocument* document, const std::string& id) {
    return isSpeciesGlyph(getLayout(document), id);
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(document, 0, reactionId, reactionGlyphIndex);
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex));
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(document, 0, reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    std::vector<SpeciesReferenceGlyph*> speciesReferenceGlyphs;
    ReactionGlyph* reactionGlyph = getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex);
    for (unsigned int i = 0 ; i < getNumSpeciesReferenceGlyphs(reactionGlyph); i++)
        speciesReferenceGlyphs.push_back(getSpeciesReferenceGlyph(reactionGlyph, i));

    return speciesReferenceGlyphs;
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceGlyph(document, 0, reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceGlyph(getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex), speciesReferenceGlyphIndex);
}

bool isReactionGlyph(SBMLDocument* document, const std::string& id) {
    return isSpeciesGlyph(getLayout(document), id);
}

const unsigned int getNumTextGlyphs(SBMLDocument* document) {
    return getNumTextGlyphs(getLayout(document));
}

TextGlyph* getTextGlyph(SBMLDocument* document, const std::string& id) {
    return getTextGlyph(getLayout(document), id);
}

TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int index) {
    return getTextGlyph(getLayout(document), index);
}

bool isSetText(SBMLDocument* document, const std::string& id) {
    return isSetText(getLayout(document), id);
}

bool isSetText(SBMLDocument* document, unsigned int index) {
    return isSetText(getLayout(document), index);
}

int setText(SBMLDocument* document, const std::string& id, const std::string& text) {
    return setText(getLayout(document), id, text);
}

int setText(SBMLDocument* document, unsigned int index, const std::string& text) {
    return setText(getLayout(document), index, text);
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
 */

}
