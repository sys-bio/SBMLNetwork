#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts) {
if (listOfLayouts)
    return listOfLayouts->size();

return 0;
}

Layout* getLayout(ListOfLayouts* listOfLayouts, unsigned int layoutIndex) {
    if (listOfLayouts)
        return listOfLayouts->get(layoutIndex);

    return NULL;
}

Dimensions* getDimensions(Layout* layout) {
    if (layout)
        return layout->getDimensions();

    return NULL;
}

double getDimensionWidth(Layout* layout) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions)
        return dimensions->width();

    return 0.0;
}

int setDimensionWidth(Layout* layout, const double& width) {
    if (isValidLayoutDimensionWidthValue(width)) {
        Dimensions* dimensions = getDimensions(layout);
        if (dimensions) {
            dimensions->setWidth(width);
            return 0;
        }
    }

    return -1;
}

double getDimensionHeight(Layout* layout) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions)
        return dimensions->height();

    return 0.0;
}

int setDimensionHeight(Layout* layout, const double& height) {
    if (isValidLayoutDimensionHeightValue(height)) {
        Dimensions* dimensions = getDimensions(layout);
        if (dimensions) {
            dimensions->setHeight(height);
            return 0;
        }
    }

    return -1;
}

const unsigned int getNumGraphicalObjects(Layout* layout) {
    if (layout)
        return getNumCompartmentGlyphs(layout) + getNumSpeciesGlyphs(layout) + getNumReactionGlyphs(layout) +
               getNumTextGlyphs(layout);

    return 0;
}

const unsigned int getNumGraphicalObjects(Layout* layout, const std::string& id) {
    return getGraphicalObjects(layout, id).size();
}

std::vector<GraphicalObject*> getGraphicalObjects(Layout* layout, const std::string& id) {
    std::vector<GraphicalObject*> graphicalObjects;
    if (layout) {
        std::vector<CompartmentGlyph*> compartmentGlyphs = getAssociatedCompartmentGlyphsWithCompartmentId(layout, id);
        graphicalObjects.insert(graphicalObjects.end(), compartmentGlyphs.begin(), compartmentGlyphs.end());
        std::vector<SpeciesGlyph*> speciesGlyphs = getAssociatedSpeciesGlyphsWithSpeciesId(layout, id);
        graphicalObjects.insert(graphicalObjects.end(), speciesGlyphs.begin(), speciesGlyphs.end());
        std::vector<ReactionGlyph*> reactionGlyphs = getAssociatedReactionGlyphsWithReactionId(layout, id);
        graphicalObjects.insert(graphicalObjects.end(), reactionGlyphs.begin(), reactionGlyphs.end());
    }

    return graphicalObjects;
}

GraphicalObject* getGraphicalObject(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex) {
    std::vector<GraphicalObject*> graphicalObjects = getGraphicalObjects(layout, id);
    if (graphicalObjectIndex < graphicalObjects.size())
        return graphicalObjects.at(graphicalObjectIndex);

    return NULL;
}

const unsigned int getNumCompartmentGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumCompartmentGlyphs();

    return 0;
}

const unsigned int getNumCompartmentGlyphs(Layout* layout, const std::string& id) {
    return getCompartmentGlyphs(layout, id).size();
}

std::vector<CompartmentGlyph*> getCompartmentGlyphs(Layout* layout, const std::string& id) {
    if (layout)
        return getAssociatedCompartmentGlyphsWithCompartmentId(layout, id);
    return std::vector<CompartmentGlyph*>();
}

CompartmentGlyph* getCompartmentGlyph(Layout* layout, const std::string& id, const unsigned int compartmentGlyphIndex) {
    std::vector<CompartmentGlyph*> compartmentGlyphs = getCompartmentGlyphs(layout, id);
    if (compartmentGlyphIndex < compartmentGlyphs.size())
        return compartmentGlyphs.at(compartmentGlyphIndex);

    return NULL;
}

CompartmentGlyph* getCompartmentGlyph(Layout* layout, const unsigned int compartmentGlyphIndex) {
    if (layout && compartmentGlyphIndex < getNumCompartmentGlyphs(layout))
        return layout->getCompartmentGlyph(compartmentGlyphIndex);

    return NULL;
}

const std::string getCompartmentId(Layout* layout, const std::string& id, const unsigned int compartmentGlyphIndex) {
    return getCompartmentId(getCompartmentGlyph(layout, id, compartmentGlyphIndex));
}

const std::string getCompartmentId(GraphicalObject* compartmentGlyph) {
    if (isCompartmentGlyph(compartmentGlyph))
        return ((CompartmentGlyph*)compartmentGlyph)->getCompartmentId();

    return "";
}

bool isCompartmentGlyph(Layout* layout, const std::string& id, const unsigned int compartmentGlyphIndex) {
    return isCompartmentGlyph(getCompartmentGlyph(layout, id, compartmentGlyphIndex));
}

bool isCompartmentGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<CompartmentGlyph*>(graphicalObject))
        return true;

    return false;
}

std::vector<std::string> getSpeciesGlyphsIds(Layout* layout) {
    std::vector<std::string> speciesGlyphsIds;
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++)
            speciesGlyphsIds.push_back(layout->getSpeciesGlyph(i)->getId());
    }

    return speciesGlyphsIds;
}

const unsigned int getNumSpeciesGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumSpeciesGlyphs();

    return 0;
}

const unsigned int getNumSpeciesGlyphs(Layout* layout, const std::string& id) {
    return getSpeciesGlyphs(layout, id).size();
}

std::vector<SpeciesGlyph*> getSpeciesGlyphs(Layout* layout, const std::string& id) {
    if (layout)
        return getAssociatedSpeciesGlyphsWithSpeciesId(layout, id);

    return std::vector<SpeciesGlyph*>();
}

SpeciesGlyph* getSpeciesGlyph(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(layout, id);
    if (speciesGlyphIndex < speciesGlyphs.size())
        return speciesGlyphs.at(speciesGlyphIndex);

    return NULL;
}

SpeciesGlyph* getSpeciesGlyph(Layout* layout, const unsigned int speciesGlyphIndex) {
    if (layout && speciesGlyphIndex < getNumSpeciesGlyphs(layout))
        return layout->getSpeciesGlyph(speciesGlyphIndex);

    return NULL;
}

const std::string getSpeciesId(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex) {
    return getSpeciesId(getSpeciesGlyph(layout, id, speciesGlyphIndex));
}

const std::string getSpeciesId(GraphicalObject* speciesGlyph) {
    if (isSpeciesGlyph(speciesGlyph))
        return ((SpeciesGlyph*)speciesGlyph)->getSpeciesId();

    return "";
}

bool isSpeciesGlyph(Layout* layout, const std::string& id, const unsigned int speciesGlyphIndex) {
    return isSpeciesGlyph(getSpeciesGlyph(layout, id, speciesGlyphIndex));
}

bool isSpeciesGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<SpeciesGlyph*>(graphicalObject))
        return true;

    return false;
}

std::vector<std::string> getReactionGlyphsIds(Layout* layout) {
    std::vector<std::string> reactionGlyphsIds;
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++)
            reactionGlyphsIds.push_back(layout->getReactionGlyph(i)->getId());
    }

    return reactionGlyphsIds;
}

const unsigned int getNumReactionGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumReactionGlyphs();

    return 0;
}

const unsigned int getNumReactionGlyphs(Layout* layout, const std::string& id) {
    return getReactionGlyphs(layout, id).size();
}

std::vector<ReactionGlyph*> getReactionGlyphs(Layout* layout, const std::string& id) {
    if (layout)
        return getAssociatedReactionGlyphsWithReactionId(layout, id);

    return std::vector<ReactionGlyph*>();
}

ReactionGlyph* getReactionGlyph(Layout* layout, const std::string& id, const unsigned int reactionGlyphIndex) {
    std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(layout, id);
    if (reactionGlyphIndex < reactionGlyphs.size())
        return reactionGlyphs.at(reactionGlyphIndex);

    return NULL;
}

ReactionGlyph* getReactionGlyph(Layout* layout, const unsigned int reactionGlyphIndex) {
    if (layout && reactionGlyphIndex < getNumReactionGlyphs(layout))
        return layout->getReactionGlyph(reactionGlyphIndex);

    return NULL;
}

const std::string getReactionId(Layout* layout, const std::string& id, const unsigned int reactionGlyphIndex) {
    return getReactionId(getReactionGlyph(layout, id, reactionGlyphIndex));
}

const std::string getReactionId(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getReactionId();

    return "";
}

bool isReactionGlyph(Layout* layout, const std::string& id, const unsigned int reactionGlyphIndex) {
    return isReactionGlyph(getReactionGlyph(layout, id, reactionGlyphIndex));
}

bool isReactionGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<ReactionGlyph*>(graphicalObject))
        return true;

    return false;
}

const unsigned int getNumSpeciesReferenceGlyphs(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferenceGlyphs(getReactionGlyph(layout, id, reactionGlyphIndex));
}

const unsigned int getNumSpeciesReferenceGlyphs(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getNumSpeciesReferenceGlyphs();

    return 0;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(getReactionGlyph(layout, id, reactionGlyphIndex));
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferenceGlyphs(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return getAssociatedSpeciesReferenceGlyphsWithReactionGlyph((ReactionGlyph*)reactionGlyph);

    return std::vector<SpeciesReferenceGlyph*>();
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceGlyph(getReactionGlyph(layout, id, reactionGlyphIndex), speciesReferenceGlyphIndex);
}

SpeciesReferenceGlyph* getSpeciesReferenceGlyph(GraphicalObject* reactionGlyph, unsigned int speciesReferenceGlyphIndex) {
    if (reactionGlyph && speciesReferenceGlyphIndex < getNumSpeciesReferenceGlyphs(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getSpeciesReferenceGlyph(speciesReferenceGlyphIndex);

    return NULL;
}

const std::string getSpeciesReferenceId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceId(getSpeciesReferenceGlyph(layout, id, reactionGlyphIndex, speciesReferenceGlyphIndex));
}

const std::string getSpeciesReferenceId(GraphicalObject* reactionGlyph, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceId(getSpeciesReferenceGlyph(reactionGlyph, speciesReferenceGlyphIndex));
}

const std::string getSpeciesReferenceId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesReferenceId();

    return "";
}

const std::string getSpeciesReferenceSpeciesGlyphId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getSpeciesReferenceGlyph(layout, id, reactionGlyphIndex, speciesReferenceGlyphIndex));
}

const std::string getSpeciesReferenceSpeciesGlyphId(GraphicalObject* reactionGlyph, unsigned int speciesReferenceGlyphIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getSpeciesReferenceGlyph(reactionGlyph, speciesReferenceGlyphIndex));
}

const std::string getSpeciesReferenceSpeciesGlyphId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesGlyphId();

    return "";
}

bool isSetRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return isSetRole(getSpeciesReferenceGlyph(layout, id, speciesReferenceGlyphIndex));
}

bool isSetRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceGlyphIndex) {
    return isSetRole(getSpeciesReferenceGlyph(reactionGlyph, speciesReferenceGlyphIndex));
}

bool isSetRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->isSetRole();

    return false;
}

const std::string getRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex) {
    return getRole(getSpeciesReferenceGlyph(layout, id, reactionGlyphIndex, speciesReferenceGlyphIndex));
}

const std::string getRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceGlyphIndex) {
    return getRole(getSpeciesReferenceGlyph(reactionGlyph, speciesReferenceGlyphIndex));
}

const std::string getRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getRoleString();

    return "";
}

int setRole(Layout* layout, const std::string& id, const std::string& role) {
    if (isValidRoleValue(role))
        return setRole(getSpeciesReferenceGlyph(layout, id), role);

    return -1;
}

int setRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getSpeciesReferenceGlyph(layout, id, reactionGlyphIndex), role);
}

int setRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role) {
    return setRole(getSpeciesReferenceGlyph(layout, id, reactionGlyphIndex, speciesReferenceGlyphIndex), role);
}

int setRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceGlyphIndex, const std::string& role) {
    return setRole(getSpeciesReferenceGlyph(reactionGlyph, speciesReferenceGlyphIndex), role);
}

int setRole(GraphicalObject* speciesReferenceGlyph, const std::string& role) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph)) {
        ((SpeciesReferenceGlyph *) speciesReferenceGlyph)->setRole(role);
        return 0;
    }

    return -1;
}

bool isSpeciesReferenceGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<SpeciesReferenceGlyph*>(graphicalObject))
        return true;

    return false;
}

const unsigned int getNumTextGlyphs(Layout* layout) {
    if (layout)
        return layout->getNumTextGlyphs();

    return 0;
}

const unsigned int getNumTextGlyphs(Layout* layout, const std::string& id) {
    return getTextGlyphs(layout, id).size();
}

const unsigned int getNumTextGlyphs(Layout* layout, GraphicalObject* graphicalObject) {
    return getTextGlyphs(layout, graphicalObject).size();
}

std::vector<TextGlyph*> getTextGlyphs(Layout* layout, const std::string& id) {
    std::vector<TextGlyph*> textGlyphs;
    std::vector<TextGlyph*> associatedtextGlyphs;
    std::vector<GraphicalObject*> graphicalObjects = getGraphicalObjects(layout, id);
    for (unsigned int i = 0; i < graphicalObjects.size(); i++) {
        associatedtextGlyphs = getTextGlyphs(layout, graphicalObjects.at(i));
        textGlyphs.insert(textGlyphs.end(), associatedtextGlyphs.begin(), associatedtextGlyphs.end());
    }

    return textGlyphs;
}

std::vector<TextGlyph*> getTextGlyphs(Layout* layout, GraphicalObject* graphicalObject) {
    return getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
}

TextGlyph* getTextGlyph(Layout* layout, const std::string& id, unsigned int textGlyphIndex) {
    std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, id);
    if (textGlyphIndex < textGlyphs.size())
        return textGlyphs.at(textGlyphIndex);

    return NULL;
}

TextGlyph* getTextGlyph(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    std::vector<TextGlyph*> textGlyphs = getTextGlyphs(layout, graphicalObject);
    if (textGlyphIndex < textGlyphs.size())
        return textGlyphs.at(textGlyphIndex);

    return NULL;
}

bool isSetText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetText(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

bool isSetText(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetText();

    return false;
}

const std::string getText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getText(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

const std::string getText(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->getText();

    return "";
}

int setText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return setText(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex)), text);
}

int setText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex), text);
}

int setText(GraphicalObject* textGlyph, const std::string& text) {
    if (isTextGlyph(textGlyph)) {
        ((TextGlyph*)textGlyph)->setText(text);
        return 0;
    }

    return -1;
}

bool isSetOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

bool isSetOriginOfTextId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetOriginOfTextId();

    return false;
}

const std::string getOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

const std::string getOriginOfTextId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->getOriginOfTextId();

    return "";
}

int setOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig) {
    return setOriginOfTextId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex)), orig);
}

int setOriginOfTextId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex), orig);
}

int setOriginOfTextId(GraphicalObject* textGlyph, const std::string& orig) {
    if (isTextGlyph(textGlyph)) {
        ((TextGlyph*)textGlyph)->setOriginOfTextId(orig);
        return 0;
    }

    return -1;
}

bool isSetGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

bool isSetGraphicalObjectId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->isSetGraphicalObjectId();

    return false;
}

const std::string getGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

const std::string getGraphicalObjectId(GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph))
        return ((TextGlyph*)textGlyph)->getGraphicalObjectId();

    return "";
}

int setGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex)), graphicalObjectId);
}

int setGraphicalObjectId(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex), graphicalObjectId);
}

int setGraphicalObjectId(GraphicalObject* textGlyph, const std::string& graphicalObjectId) {
    if (isTextGlyph(textGlyph)) {
        ((TextGlyph*)textGlyph)->setGraphicalObjectId(graphicalObjectId);
        return 0;
    }

    return -1;
}

GraphicalObject* getGraphicalObject(Layout* layout, GraphicalObject* textGlyph) {
    return getGraphicalObjectUsingItsOwnId(layout, getGraphicalObjectId(textGlyph));
}

bool isTextGlyph(Layout* layout, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getTextGlyph(layout, id, textGlyphIndex));
}

bool isTextGlyph(GraphicalObject* graphicalObject) {
    if (dynamic_cast<TextGlyph*>(graphicalObject))
        return true;

    return false;
}

const std::string getSBMLObjectId(Layout* layout, const std::string& graphicalObjectId) {
    return getSBMLObjectId(layout, getGraphicalObjectUsingItsOwnId(layout, graphicalObjectId));
}

const std::string getSBMLObjectId(Layout* layout, GraphicalObject* graphicalObject) {
    if (layout && graphicalObject)
        return getEntityId(layout, graphicalObject);

    return "";
}

BoundingBox* getBoundingBox(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex) {
    return getBoundingBox(getGraphicalObject(layout, id, graphicalObjectIndex));
}

BoundingBox* getBoundingBox(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getBoundingBox();

    return NULL;
}

const double getPositionX(Layout* layout, const std::string& id, const unsigned int graphicalObjectIndex) {
    return getPositionX(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const double getPositionX(GraphicalObject* graphicalObject) {
    return getPositionX(getBoundingBox(graphicalObject));
}

const double getPositionX(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->x();

    return 0.0;
}

int setPositionX(Layout* layout, const std::string& id, const double& x) {
    return setPositionX(getGraphicalObject(layout, id), x);
}

int setPositionX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setPositionX(getGraphicalObject(layout, id, graphicalObjectIndex), x);
}

int setPositionX(GraphicalObject* graphicalObject, const double& x) {
    return setPositionX(getBoundingBox(graphicalObject), x);
}

int setPositionX(BoundingBox* boundingBox, const double& x) {
    if (boundingBox && isValidBoundingBoxXValue(x)) {
        boundingBox->setX(x);
        return 0;
    }

    return -1;
}

const double getPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const double getPositionY(GraphicalObject* graphicalObject) {
    return getPositionY(getBoundingBox(graphicalObject));
}

const double getPositionY(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->y();

    return 0.0;
}

int setPositionY(Layout* layout, const std::string& id, const double& y) {
    return setPositionY(getGraphicalObject(layout, id), y);
}

int setPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setPositionY(getGraphicalObject(layout, id, graphicalObjectIndex), y);
}

int setPositionY(GraphicalObject* graphicalObject, const double& y) {
    return setPositionY(getBoundingBox(graphicalObject), y);
}

int setPositionY(BoundingBox* boundingBox, const double& y) {
    if (boundingBox && isValidBoundingBoxXValue(y)) {
        boundingBox->setY(y);
        return 0;
    }

    return -1;
}

const double getDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const double getDimensionWidth(GraphicalObject* graphicalObject) {
    return getDimensionWidth(getBoundingBox(graphicalObject));
}

const double getDimensionWidth(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->width();

    return 0.0;
}

int setDimensionWidth(Layout* layout, const std::string& id, const double& width) {
    return setDimensionWidth(getGraphicalObject(layout, id), width);
}

int setDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setDimensionWidth(getGraphicalObject(layout, id, graphicalObjectIndex), width);
}

int setDimensionWidth(GraphicalObject* graphicalObject, const double& width) {
    return setDimensionWidth(getBoundingBox(graphicalObject), width);
}

int setDimensionWidth(BoundingBox* boundingBox, const double& width) {
    if (boundingBox && isValidBoundingBoxWidthValue(width)) {
        boundingBox->setWidth(width);
        return 0;
    }

    return -1;
}

const double getDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const double getDimensionHeight(GraphicalObject* graphicalObject) {;
    return getDimensionHeight(getBoundingBox(graphicalObject));
}

const double getDimensionHeight(BoundingBox* boundingBox) {
    if (boundingBox)
        return boundingBox->height();

    return 0.0;
}

int setDimensionHeight(Layout* layout, const std::string& id, const double& height) {
    return setDimensionHeight(getGraphicalObject(layout, id), height);
}

int setDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setDimensionHeight(getGraphicalObject(layout, id, graphicalObjectIndex), height);
}

int setDimensionHeight(GraphicalObject* graphicalObject, const double& height) {
    return setDimensionHeight(getBoundingBox(graphicalObject), height);
}

int setDimensionHeight(BoundingBox* boundingBox, const double& height) {
    if (boundingBox && isValidBoundingBoxHeightValue(height)) {
        boundingBox->setHeight(height);
        return 0;
    }

    return -1;
}

bool isSetCurve(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetCurve(getGraphicalObject(layout, id, graphicalObjectIndex));
}

bool isSetCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject))
        return ((ReactionGlyph*)graphicalObject)->isSetCurve();
    if (isSpeciesReferenceGlyph(graphicalObject))
        return ((SpeciesReferenceGlyph*)graphicalObject)->isSetCurve();

    return  false;
}

Curve* getCurve(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCurve(getGraphicalObject(layout, id, graphicalObjectIndex));
}

Curve* getCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject))
        return ((ReactionGlyph*)graphicalObject)->getCurve();
    if (isSpeciesReferenceGlyph(graphicalObject))
        return ((SpeciesReferenceGlyph*)graphicalObject)->getCurve();

    return  NULL;
}

const unsigned int getNumCurveSegments(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumCurveSegments(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const unsigned int getNumCurveSegments(GraphicalObject* graphicalObject) {
    return getNumCurveSegments(getCurve(graphicalObject));
}

const unsigned int getNumCurveSegments(Curve* curve) {
    if (curve)
        return curve->getNumCurveSegments();

    return 0;
}

LineSegment* getCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

LineSegment* getCurveSegment(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegment(getCurve(graphicalObject), curveSegmentIndex);
}

LineSegment* getCurveSegment(Curve* curve, unsigned int curveSegmentIndex) {
    if (curveSegmentIndex < getNumCurveSegments(curve))
        return curve->getCurveSegment(curveSegmentIndex);

    return  NULL;
}

LineSegment* createLineCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return createLineCurveSegment(getGraphicalObject(layout, id, graphicalObjectIndex));
}

LineSegment* createLineCurveSegment(GraphicalObject* graphicalObject) {
    return createLineCurveSegment(getCurve(graphicalObject));
}

LineSegment* createLineCurveSegment(Curve* curve) {
    if (curve)
        return curve->createLineSegment();

    return NULL;
}

CubicBezier* createCubicBezierCurveSegment(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return createCubicBezierCurveSegment(getGraphicalObject(layout, id, graphicalObjectIndex));
}

CubicBezier* createCubicBezierCurveSegment(GraphicalObject* graphicalObject) {
    return createCubicBezierCurveSegment(getCurve(graphicalObject));
}

CubicBezier* createCubicBezierCurveSegment(Curve* curve) {
    if (curve)
        return curve->createCubicBezier();

    return NULL;
}

int removeCurveSegment(Layout* layout, const std::string& id, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getGraphicalObject(layout, id), curveSegmentIndex);
}

int removeCurveSegment(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getCurve(graphicalObject), curveSegmentIndex);
}

int removeCurveSegment(Curve* curve, unsigned int curveSegmentIndex) {
    if (curve) {
        ListOfLineSegments* listOfLineSegments = curve->getListOfCurveSegments();
        if (listOfLineSegments) {
            LineSegment* lineSegment = listOfLineSegments->remove(curveSegmentIndex);
            delete lineSegment;
            return 0;
        }
    }

    return -1;
}

bool isCubicBezier(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

bool isCubicBezier(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return isCubicBezier(getCurve(graphicalObject), curveSegmentIndex);
}

bool isCubicBezier(Curve* curve, unsigned int curveSegmentIndex) {
    return isCubicBezier(getCurveSegment(curve, curveSegmentIndex));
}

bool isCubicBezier(LineSegment* lineSegment) {
    if (lineSegment) {
        CubicBezier* cubicBezier = dynamic_cast<CubicBezier*>(lineSegment);
        if (cubicBezier)
            return true;
    }

    return  false;
}

const double getCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentStartPointX(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment)
        return lineSegment->getStart()->x();

    return  0.0;
}

int setCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getGraphicalObject(layout, id), curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getCurve(graphicalObject), curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(Curve* curve, unsigned int curveSegmentIndex, const double& x) {
    if (isValidCurveSegmentStartPointXValue(x)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment) {
            lineSegment->getStart()->setX(x);
            return  0;
        }
    }

    return  -1;
}

const double getCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentStartPointY(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment)
        return lineSegment->getStart()->y();

    return  0.0;
}

int setCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getGraphicalObject(layout, id), curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getCurve(graphicalObject), curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(Curve* curve, unsigned int curveSegmentIndex, const double& y) {
    if (isValidCurveSegmentStartPointYValue(y)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment) {
            lineSegment->getStart()->setY(y);
            return 0;
        }
    }

    return -1;
}

const double getCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentEndPointX(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment)
        return lineSegment->getEnd()->x();

    return  0.0;
}

int setCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getGraphicalObject(layout, id), curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getCurve(graphicalObject), curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(Curve* curve, unsigned int curveSegmentIndex, const double& x) {
    if (isValidCurveSegmentEndPointXValue(x)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment) {
            lineSegment->getEnd()->setX(x);
            return  0;
        }
    }

    return  -1;
}

const double getCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentEndPointY(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment)
        return lineSegment->getEnd()->y();

    return  0.0;
}

int setCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getGraphicalObject(layout, id), curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getCurve(graphicalObject), curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(Curve* curve, unsigned int curveSegmentIndex, const double& y) {
    if (isValidCurveSegmentEndPointYValue(y)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment) {
            lineSegment->getEnd()->setY(y);
            return 0;
        }
    }

    return -1;
}

const double getCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentBasePoint1X(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint1()->x();

    return  0.0;
}

int setCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getGraphicalObject(layout, id), curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getCurve(graphicalObject), curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(Curve* curve, unsigned int curveSegmentIndex, const double& x) {
    if (isValidCurveSegmentBasePoint1XValue(x)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment && isCubicBezier(lineSegment)) {
            ((CubicBezier*)lineSegment)->getBasePoint1()->setX(x);
            return 0;
        }
    }

    return  -1;
}

const double getCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentBasePoint1Y(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint1()->y();

    return  0.0;
}

int setCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getGraphicalObject(layout, id), curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getCurve(graphicalObject), curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(Curve* curve, unsigned int curveSegmentIndex, const double& y) {
    if (isValidCurveSegmentBasePoint1YValue(y)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment && isCubicBezier(lineSegment)) {
            ((CubicBezier*)lineSegment)->getBasePoint1()->setY(y);
            return 0;
        }
    }

    return  -1;
}

const double getCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentBasePoint2X(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint2()->x();

    return  0.0;
}

int setCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getGraphicalObject(layout, id), curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getCurve(graphicalObject), curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(Curve* curve, unsigned int curveSegmentIndex, const double& x) {
    if (isValidCurveSegmentBasePoint2XValue(x)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment && isCubicBezier(lineSegment)) {
            ((CubicBezier*)lineSegment)->getBasePoint2()->setX(x);
            return 0;
        }
    }

    return  -1;
}

const double getCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex);
}

const double getCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getCurve(graphicalObject), curveSegmentIndex);
}

const double getCurveSegmentBasePoint2Y(Curve* curve, unsigned int curveSegmentIndex) {
    LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
    if (lineSegment && isCubicBezier(lineSegment))
        return ((CubicBezier*)lineSegment)->getBasePoint2()->y();

    return  0.0;
}

int setCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getGraphicalObject(layout, id), curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getGraphicalObject(layout, id, graphicalObjectIndex), curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(GraphicalObject* graphicalObject, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getCurve(graphicalObject), curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(Curve* curve, unsigned int curveSegmentIndex, const double& y) {
    if (isValidCurveSegmentBasePoint2YValue(y)) {
        LineSegment* lineSegment = getCurveSegment(curve, curveSegmentIndex);
        if (lineSegment && isCubicBezier(lineSegment)) {
            ((CubicBezier*)lineSegment)->getBasePoint2()->setY(y);
            return 0;
        }
    }

    return  -1;
}

}
