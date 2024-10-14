#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_layout_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

const unsigned int getNumLayouts(ListOfLayouts* listOfLayouts) {
    if (listOfLayouts)
        return listOfLayouts->size();

    return 0;
}

Layout* getLayout(ListOfLayouts* listOfLayouts, unsigned int layoutIndex) {
    if (listOfLayouts) {
        if (layoutIndex < getNumLayouts(listOfLayouts))
            return listOfLayouts->get(layoutIndex);

        std::cerr << "error: layoutIndex is out of bounds." << std::endl;
    }

    return NULL;
}

Dimensions* getDimensions(Layout* layout) {
    if (layout)
        return layout->getDimensions();

    return NULL;
}

const double getDimensionWidth(Layout* layout) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions)
        return roundToTwoDecimalPlaces(dimensions->width());

    return NAN;
}

int setDimensionWidth(Layout* layout, const double& width) {
    if (isValidLayoutDimensionWidthValue(width)) {
        Dimensions* dimensions = getDimensions(layout);
        if (dimensions) {
            dimensions->setWidth(width);
            setUserData(dimensions, "width", std::to_string(width));
            return 0;
        }
    }

    return -1;
}

const double getDimensionHeight(Layout* layout) {
    Dimensions* dimensions = getDimensions(layout);
    if (dimensions)
        return roundToTwoDecimalPlaces(dimensions->height());

    return NAN;
}

int setDimensionHeight(Layout* layout, const double& height) {
    if (isValidLayoutDimensionHeightValue(height)) {
        Dimensions* dimensions = getDimensions(layout);
        if (dimensions) {
            dimensions->setHeight(height);
            setUserData(dimensions, "height", std::to_string(height));
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
        std::vector<CompartmentGlyph*> compartmentGlyphs = getCompartmentGlyphs(layout, id);
        graphicalObjects.insert(graphicalObjects.end(), compartmentGlyphs.begin(), compartmentGlyphs.end());
        std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(layout, id);
        graphicalObjects.insert(graphicalObjects.end(), speciesGlyphs.begin(), speciesGlyphs.end());
        std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(layout, id);
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

const unsigned int getNumSpeciesReferences(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferences(getReactionGlyph(layout, id, reactionGlyphIndex));
}

const unsigned int getNumSpeciesReferences(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getNumSpeciesReferenceGlyphs();

    return 0;
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferences(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex) {
    return getSpeciesReferenceGlyphs(getReactionGlyph(layout, id, reactionGlyphIndex));
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferences(GraphicalObject* reactionGlyph) {
    if (isReactionGlyph(reactionGlyph))
        return getSpeciesReferenceGlyphs((ReactionGlyph*)reactionGlyph);

    return std::vector<SpeciesReferenceGlyph*>();
}

SpeciesReferenceGlyph* getSpeciesReference(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReference(getReactionGlyph(layout, id, reactionGlyphIndex), speciesReferenceIndex);
}

SpeciesReferenceGlyph* getSpeciesReference(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex) {
    if (reactionGlyph && speciesReferenceIndex < getNumSpeciesReferences(reactionGlyph))
        return ((ReactionGlyph*)reactionGlyph)->getSpeciesReferenceGlyph(speciesReferenceIndex);

    return NULL;
}

const std::string getSpeciesReferenceId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getSpeciesReference(layout, id, reactionGlyphIndex, speciesReferenceIndex));
}

const std::string getSpeciesReferenceId(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getSpeciesReference(reactionGlyph, speciesReferenceIndex));
}

const std::string getSpeciesReferenceId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesReferenceId();

    return "";
}

const std::string getSpeciesReferenceSpeciesId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    GraphicalObject* speciesGlyph = getGraphicalObjectUsingItsOwnId(layout, getSpeciesReferenceSpeciesGlyphId(getSpeciesReference(layout, id, reactionGlyphIndex, speciesReferenceIndex)));
    if (dynamic_cast<SpeciesGlyph*>(speciesGlyph))
        return ((SpeciesGlyph*)speciesGlyph)->getSpeciesId();

    return "";
}

const std::string getSpeciesReferenceSpeciesGlyphId(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getSpeciesReference(layout, id, reactionGlyphIndex, speciesReferenceIndex));
}

const std::string getSpeciesReferenceSpeciesGlyphId(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getSpeciesReference(reactionGlyph, speciesReferenceIndex));
}

const std::string getSpeciesReferenceSpeciesGlyphId(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getSpeciesGlyphId();

    return "";
}

bool isSetRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getSpeciesReference(layout, id, reactionGlyphIndex, speciesReferenceIndex));
}

bool isSetRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex) {
    return isSetRole(getSpeciesReference(reactionGlyph, speciesReferenceIndex));
}

bool isSetRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->isSetRole();

    return false;
}

const std::string getRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getSpeciesReference(layout, id, reactionGlyphIndex, speciesReferenceIndex));
}

const std::string getRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex) {
    return getRole(getSpeciesReference(reactionGlyph, speciesReferenceIndex));
}

const std::string getRole(GraphicalObject* speciesReferenceGlyph) {
    if (isSpeciesReferenceGlyph(speciesReferenceGlyph))
        return ((SpeciesReferenceGlyph*)speciesReferenceGlyph)->getRoleString();

    return "";
}

int setRole(Layout* layout, const std::string& id, const std::string& role) {
    if (isValidRoleValue(role))
        return setRole(getSpeciesReference(layout, id), role);

    return -1;
}

int setRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, const std::string& role) {
    if (isValidRoleValue(role))
        return setRole(getSpeciesReference(layout, id, reactionGlyphIndex), role);

    return -1;
}

int setRole(Layout* layout, const std::string& id, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& role) {
    if (isValidRoleValue(role))
        return setRole(getSpeciesReference(layout, id, reactionGlyphIndex, speciesReferenceIndex), role);

    return -1;
}

int setRole(GraphicalObject* reactionGlyph, unsigned int speciesReferenceIndex, const std::string& role) {
    if (isValidRoleValue(role))
        return setRole(getSpeciesReference(reactionGlyph, speciesReferenceIndex), role);

    return -1;
}

int setRole(GraphicalObject* speciesReferenceGlyph, const std::string& role) {
    if (isValidRoleValue(role)) {
        if (isSpeciesReferenceGlyph(speciesReferenceGlyph)) {
            ((SpeciesReferenceGlyph *) speciesReferenceGlyph)->setRole(role);
            return 0;
        }
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

int addText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return addText(layout, getGraphicalObject(layout, id, graphicalObjectIndex), text);
}

int addText(Layout* layout, GraphicalObject* graphicalObject, const std::string& text) {
    if (graphicalObject) {
        TextGlyph* textGlyph = layout->createTextGlyph();
        textGlyph->setId(getTextGlyphUniqueId(layout, graphicalObject));
        textGlyph->setText(text);
        textGlyph->setGraphicalObjectId(graphicalObject->getId());
        textGlyph->setOriginOfTextId(getEntityId(graphicalObject));
        setTextGlyphBoundingBox(textGlyph, graphicalObject);

        return 0;
    }

    return -1;
}

int removeText(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return removeText(layout, getTextGlyph(layout, getGraphicalObject(layout, id, graphicalObjectIndex), textGlyphIndex));
}

int removeText(Layout* layout, GraphicalObject* textGlyph) {
    if (isTextGlyph(textGlyph)) {
        layout->removeTextGlyph(textGlyph->getId());
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
    return getSBMLObjectId(getGraphicalObjectUsingItsOwnId(layout, graphicalObjectId));
}

const std::string getSBMLObjectId(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return getEntityId(graphicalObject);

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
    if (isSetCurve(graphicalObject))
        return getPositionX(getCurve(graphicalObject));
    else
        return getPositionX(getBoundingBox(graphicalObject));
}

const double getPositionX(BoundingBox* boundingBox) {
    if (boundingBox)
        return roundToTwoDecimalPlaces(boundingBox->x());

    return NAN;
}

const double getPositionX(Curve* curve) {
    if (curve)
        return roundToTwoDecimalPlaces(getCurveMiddlePositionX(curve));

    return NAN;
}

int setPositionX(Layout* layout, const std::string& id, const double& x) {
    return setPositionX(layout, getGraphicalObject(layout, id), x);
}

int setPositionX(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setPositionX(layout, getGraphicalObject(layout, id, graphicalObjectIndex), x);
}

int setPositionX(Layout* layout, GraphicalObject* graphicalObject, const double& x) {
    double moveDistance = x - getPositionX(graphicalObject);
    if ((isSetCurve(graphicalObject) && !setPositionX(getCurve(graphicalObject), x)) || !setPositionX(getBoundingBox(graphicalObject), x)) {
        updateAssociatedTextGlyphsPositionX(layout, graphicalObject, moveDistance);
        lockGraphicalObject(graphicalObject);
        return 0;
    }

    return -1;
}

int setPositionX(BoundingBox* boundingBox, const double& x) {
    if (boundingBox && isValidBoundingBoxXValue(x)) {
        boundingBox->setX(x);
        return 0;
    }

    return -1;
}

int setPositionX(Curve* curve, const double& x) {
    if (curve && isValidBoundingBoxXValue(x)) {
        setCurveMiddlePositionX(curve, x);
        return 0;
    }

    return -1;
}

const double getPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const double getPositionY(GraphicalObject* graphicalObject) {
    if (isSetCurve(graphicalObject))
        return getPositionY(getCurve(graphicalObject));
    else
        return getPositionY(getBoundingBox(graphicalObject));
}

const double getPositionY(BoundingBox* boundingBox) {
    if (boundingBox)
        return roundToTwoDecimalPlaces(boundingBox->y());

    return NAN;
}

const double getPositionY(Curve* curve) {
    if (curve)
        return roundToTwoDecimalPlaces(getCurveMiddlePositionY(curve));

    return NAN;
}

int setPositionY(Layout* layout, const std::string& id, const double& y) {
    return setPositionY(layout, getGraphicalObject(layout, id), y);
}

int setPositionY(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setPositionY(layout, getGraphicalObject(layout, id, graphicalObjectIndex), y);
}

int setPositionY(Layout* layout, GraphicalObject* graphicalObject, const double& y) {
    double moveDistance = y - getPositionY(graphicalObject);
    if ((isSetCurve(graphicalObject) && !setPositionY(getCurve(graphicalObject), y)) || !setPositionY(getBoundingBox(graphicalObject), y)) {
        updateAssociatedTextGlyphsPositionY(layout, graphicalObject, moveDistance);
        lockGraphicalObject(graphicalObject);
        return 0;
    }

    return -1;
}

int setPositionY(BoundingBox* boundingBox, const double& y) {
    if (boundingBox && isValidBoundingBoxYValue(y)) {
        boundingBox->setY(y);
        return 0;
    }

    return -1;
}

int setPositionY(Curve* curve, const double& y) {
    if (curve && isValidBoundingBoxYValue(y)) {
        setCurveMiddlePositionY(curve, y);
        return 0;
    }

    return -1;
}

int setPosition(Layout* layout, const std::string& id, const double& x, const double& y) {
    return setPosition(layout, getGraphicalObject(layout, id), x, y);
}

int setPosition(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    return setPosition(layout, getGraphicalObject(layout, id, graphicalObjectIndex), x, y);
}

int setPosition(Layout* layout, GraphicalObject* graphicalObject, const double& x, const double& y) {
    double moveDistanceX = x - getPositionX(graphicalObject);
    double moveDistanceY = y - getPositionY(graphicalObject);
    if ((isSetCurve(graphicalObject) && !setPosition(getCurve(graphicalObject), x, y)) || !setPosition(getBoundingBox(graphicalObject), x, y)) {
        updateAssociatedTextGlyphsPosition(layout, graphicalObject, moveDistanceX, moveDistanceY);
        return 0;
    }

    return -1;
}

int setPosition(BoundingBox* boundingBox, const double& x, const double& y) {
    if (boundingBox && isValidBoundingBoxXValue(x) && isValidBoundingBoxYValue(y)) {
        boundingBox->setX(x);
        boundingBox->setY(y);
        return 0;
    }

    return -1;
}

int setPosition(Curve* curve, const double& x, const double& y) {
    if (curve && isValidBoundingBoxXValue(x) && isValidBoundingBoxYValue(y)) {
        setCurveMiddlePositionX(curve, x);
        setCurveMiddlePositionY(curve, y);
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
        return roundToTwoDecimalPlaces(boundingBox->width());

    return NAN;
}

int setDimensionWidth(Layout* layout, const std::string& id, const double& width) {
    return setDimensionWidth(layout, getGraphicalObject(layout, id), width);
}

int setDimensionWidth(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setDimensionWidth(layout, getGraphicalObject(layout, id, graphicalObjectIndex), width);
}

int setDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, const double& width) {
    double changedWidth = width - getDimensionWidth(graphicalObject);
    if (!setDimensionWidth(getBoundingBox(graphicalObject), width)) {
        fixGraphicalObjectWidth(graphicalObject);
        updateAssociatedTextGlyphsDimensionWidth(layout, graphicalObject, changedWidth);
        return 0;
    }

    return -1;
}

int setDimensionWidth(BoundingBox* boundingBox, const double& width) {
    if (boundingBox && isValidBoundingBoxWidthValue(width)) {
        boundingBox->setWidth(width);
        return 0;
    }

    return -1;
}

int setCompartmentDimensionWidth(Layout* layout, const double& width) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        if (setDimensionWidth(layout, layout->getCompartmentGlyph(i), width))
            return -1;
    }

    return 0;
}

int setSpeciesDimensionWidth(Layout* layout, const double& width) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        if (setDimensionWidth(layout, layout->getSpeciesGlyph(i), width))
            return -1;
    }

    return 0;
}

int setReactionDimensionWidth(Layout* layout, const double& width) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (setDimensionWidth(layout, layout->getReactionGlyph(i), width))
            return -1;
    }

    return 0;
}

const double getDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getGraphicalObject(layout, id, graphicalObjectIndex));
}

const double getDimensionHeight(GraphicalObject* graphicalObject) {;
    return getDimensionHeight(getBoundingBox(graphicalObject));
}

const double getDimensionHeight(BoundingBox* boundingBox) {
    if (boundingBox)
        return roundToTwoDecimalPlaces(boundingBox->height());

    return NAN;
}

int setDimensionHeight(Layout* layout, const std::string& id, const double& height) {
    return setDimensionHeight(layout, getGraphicalObject(layout, id), height);
}

int setDimensionHeight(Layout* layout, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setDimensionHeight(layout, getGraphicalObject(layout, id, graphicalObjectIndex), height);
}

int setDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, const double& height) {
    double changedHeight = height - getDimensionHeight(graphicalObject);
    if (!setDimensionHeight(getBoundingBox(graphicalObject), height)) {
        fixGraphicalObjectHeight(graphicalObject);
        updateAssociatedTextGlyphsDimensionHeight(layout, graphicalObject, changedHeight);
        return 0;
    }

    return -1;
}

int setDimensionHeight(BoundingBox* boundingBox, const double& height) {
    if (boundingBox && isValidBoundingBoxHeightValue(height)) {
        boundingBox->setHeight(height);
        return 0;
    }

    return -1;
}

int setCompartmentDimensionHeight(Layout* layout, const double& height) {
    for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
        if (setDimensionHeight(layout, layout->getCompartmentGlyph(i), height))
            return -1;
    }

    return 0;
}

int setSpeciesDimensionHeight(Layout* layout, const double& height) {
    for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
        if (setDimensionHeight(layout, layout->getSpeciesGlyph(i), height))
            return -1;
    }

    return 0;
}

int setReactionDimensionHeight(Layout* layout, const double& height) {
    for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
        if (setDimensionHeight(layout, layout->getReactionGlyph(i), height))
            return -1;
    }

    return 0;
}

const double getTextPositionX(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return getPositionX(textGlyphs.at(textGlyphIndex));

    return NAN;
}

int setTextPositionX(Layout* layout, GraphicalObject* graphicalObject, const double& x) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphs.size())
        return setPositionX(layout, textGlyphs.at(0), x);

    return -1;
}

int setTextPositionX(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& x) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return setPositionX(layout, textGlyphs.at(textGlyphIndex), x);

    return -1;
}

const double getTextPositionY(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return getPositionY(textGlyphs.at(textGlyphIndex));

    return NAN;
}

int setTextPositionY(Layout* layout, GraphicalObject* graphicalObject, const double& y) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphs.size())
        return setPositionY(layout, textGlyphs.at(0), y);

    return -1;
}

int setTextPositionY(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& y) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return setPositionY(layout, textGlyphs.at(textGlyphIndex), y);

    return -1;
}

int setTextPosition(Layout* layout, GraphicalObject* graphicalObject, const double& x, const double& y) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphs.size()) {
        setPositionX(layout, textGlyphs.at(0), x);
        setPositionY(layout, textGlyphs.at(0), y);
        return 0;
    }

    return -1;
}

int setTextPosition(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& x, const double& y) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size()) {
        setPositionX(layout, textGlyphs.at(textGlyphIndex), x);
        setPositionY(layout, textGlyphs.at(textGlyphIndex), y);
        return 0;
    }

    return -1;
}

const double getTextDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return getDimensionWidth(textGlyphs.at(textGlyphIndex));

    return NAN;
}

int setTextDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, const double& width) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphs.size())
        return setDimensionWidth(layout, textGlyphs.at(0), width);

    return -1;
}

int setTextDimensionWidth(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& width) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return setDimensionWidth(layout, textGlyphs.at(textGlyphIndex), width);

    return -1;
}

const double getTextDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return getDimensionHeight(textGlyphs.at(textGlyphIndex));

    return NAN;
}

int setTextDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, const double& height) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphs.size())
        return setDimensionHeight(layout, textGlyphs.at(0), height);

    return -1;
}

int setTextDimensionHeight(Layout* layout, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& height) {
    std::vector<TextGlyph*> textGlyphs = getAssociatedTextGlyphsWithGraphicalObject(layout, graphicalObject);
    if (textGlyphIndex >= 0 && textGlyphIndex < textGlyphs.size())
        return setDimensionHeight(layout, textGlyphs.at(textGlyphIndex), height);

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

int removeCurve(GraphicalObject* graphicalObject) {
    if (isReactionGlyph(graphicalObject)) {
        removeReactionGlyphCurve((ReactionGlyph *) graphicalObject);
        return 0;
    }

    return -1;
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
        return roundToTwoDecimalPlaces(lineSegment->getStart()->x());

    return  0.00;
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
        return roundToTwoDecimalPlaces(lineSegment->getStart()->y());

    return  0.00;
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
        return roundToTwoDecimalPlaces(lineSegment->getEnd()->x());

    return  0.00;
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
        return roundToTwoDecimalPlaces(lineSegment->getEnd()->y());

    return  0.00;
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
        return roundToTwoDecimalPlaces(((CubicBezier*)lineSegment)->getBasePoint1()->x());

    return  0.00;
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
        return roundToTwoDecimalPlaces(((CubicBezier*)lineSegment)->getBasePoint1()->y());

    return  0.00;
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
        return roundToTwoDecimalPlaces(((CubicBezier*)lineSegment)->getBasePoint2()->x());

    return  0.00;
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
        return roundToTwoDecimalPlaces(((CubicBezier*)lineSegment)->getBasePoint2()->y());

    return  0.00;
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
