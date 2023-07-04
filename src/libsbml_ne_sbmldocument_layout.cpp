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

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getLayout(document), reactionId, reactionGlyphIndex);
}

const unsigned int getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(getLayout(document), reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesGlyphId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesGlyphId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

int setRole(SBMLDocument* document, const std::string& reactionId, const std::string& role) {
    return setRole(getLayout(document), reactionId, role);
}

int setRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, role);
}

int setRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getLayout(document), reactionId, reactionGlyphIndex, role);
}

int setRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, role);
}

int setRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role) {
    return setRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
}

int setRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceGlyphIndex, role);
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumTextGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, const std::string& id) {
    return getNumTextGlyphs(getLayout(document), id);
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getNumTextGlyphs(getLayout(document, layoutIndex), id);
}

std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, const std::string& id) {
    return getTextGlyphs(getLayout(document), id);
}

std::vector<TextGlyph*> getTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return getTextGlyphs(getLayout(document, layoutIndex), id);
}

TextGlyph* getTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document), id, textGlyphIndex);
}

TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document, layoutIndex), id, textGlyphIndex);
}

bool isSetText(SBMLDocument* document, const std::string& id) {
    return isSetText(getLayout(document), id);
}

bool isSetText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isSetText(getLayout(document, layoutIndex), id);
}

const std::string getText(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return getText(getLayout(document), id, textGlyphIndex);
}

const std::string getText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return getText(getLayout(document, layoutIndex), id, textGlyphIndex);
}

int setText(SBMLDocument* document, const std::string& id, const std::string& text) {
    return setText(getLayout(document), id, text);
}

int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const std::string& text) {
    return setText(getLayout(document, layoutIndex), id, text);
}

int setText(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getLayout(document), id, textGlyphIndex, text);
}

int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getLayout(document, layoutIndex), id, textGlyphIndex, text);
}

bool isSetOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getLayout(document), id, textGlyphIndex);
}

bool isSetOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getLayout(document, layoutIndex), id, textGlyphIndex);
}

const std::string getOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getLayout(document), id, textGlyphIndex);
}

const std::string getOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getLayout(document, layoutIndex), id, textGlyphIndex);
}

int setOriginOfTextId(SBMLDocument* document, const std::string& id, const std::string& orig) {
    return setOriginOfTextId(getLayout(document), id, orig);
}

int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const std::string& orig) {
    return setOriginOfTextId(getLayout(document, layoutIndex), id, orig);
}

int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document), id, textGlyphIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document, layoutIndex), id, textGlyphIndex, orig);
}

bool isSetGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getLayout(document), id, textGlyphIndex);
}

bool isSetGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getLayout(document, layoutIndex), id, textGlyphIndex);
}

const std::string getGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getLayout(document), id, textGlyphIndex);
}

const std::string getGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getLayout(document, layoutIndex), id, textGlyphIndex);
}

int setGraphicalObjectId(SBMLDocument* document, const std::string& id, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document), id, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document), id, textGlyphIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document, layoutIndex), id, textGlyphIndex, graphicalObjectId);
}

bool isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getLayout(document), id, textGlyphIndex);
}

bool isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getLayout(document, layoutIndex), id, textGlyphIndex);
}

BoundingBox* getBoundingBox(SBMLDocument* document, const std::string& id, const unsigned int graphicalObjectIndex) {
    return getBoundingBox(getLayout(document), id, graphicalObjectIndex);
}

BoundingBox* getBoundingBox(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const unsigned int graphicalObjectIndex) {
    return getBoundingBox(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const double getPositionX(SBMLDocument* document, const std::string& id, const unsigned int graphicalObjectIndex) {
    return getPositionX(getLayout(document), id, graphicalObjectIndex);
}

const double getPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const unsigned int graphicalObjectIndex) {
    return getPositionX(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setPositionX(SBMLDocument* document, const std::string& id, const double& x) {
    return setPositionX(getLayout(document), id, x);
}

int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x) {
    return setPositionX(getLayout(document, layoutIndex), id, x);
}

int setPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setPositionX(getLayout(document), id, graphicalObjectIndex, x);
}

int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setPositionX(getLayout(document, layoutIndex), id, graphicalObjectIndex, x);
}

const double getPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getLayout(document), id, graphicalObjectIndex);
}

const double getPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setPositionY(SBMLDocument* document, const std::string& id, const double& y) {
    return setPositionY(getLayout(document), id, y);
}

int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y) {
    return setPositionY(getLayout(document, layoutIndex), id, y);
}

int setPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setPositionY(getLayout(document), id, graphicalObjectIndex, y);
}

int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setPositionY(getLayout(document, layoutIndex), id, graphicalObjectIndex, y);
}

const double getDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getLayout(document), id, graphicalObjectIndex);
}

const double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setDimensionWidth(SBMLDocument* document, const std::string& id, const double& width) {
    return setDimensionWidth(getLayout(document), id, width);
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width) {
    return setDimensionWidth(getLayout(document, layoutIndex), id, width);
}

int setDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setDimensionWidth(getLayout(document), id, graphicalObjectIndex, width);
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setDimensionWidth(getLayout(document, layoutIndex), id, graphicalObjectIndex, width);
}

const double getDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getLayout(document), id, graphicalObjectIndex);
}

const double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setDimensionHeight(SBMLDocument* document, const std::string& id, const double& height) {
    return setDimensionHeight(getLayout(document), id, height);
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height) {
    return setDimensionHeight(getLayout(document, layoutIndex), id, height);
}

int setDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setDimensionHeight(getLayout(document), id, graphicalObjectIndex, height);
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setDimensionHeight(getLayout(document, layoutIndex), id, graphicalObjectIndex, height);
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
