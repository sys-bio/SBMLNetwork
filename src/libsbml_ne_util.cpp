#include "libsbml_ne_util.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_render.h"
#include "libsbml_ne_util_helpers.h"
#include "libsbml_ne_layout_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

SBMLDocument* readSBML(const std::string& sbml) {
    SBMLDocument* document = readSBMLFromFile(sbml.c_str());
    if (document)
        return document;
    document = readSBMLFromString(sbml.c_str());
    if (document)
        return document;

    return NULL;
}

bool writeSBML(SBMLDocument* document, const std::string &fileName) {
    return writeSBMLToFile(document, fileName.c_str());
}

const std::string writeSBML(SBMLDocument* document) {
    return writeSBMLToString(document);
}

int createDefaultLayout(SBMLDocument* document) {
    if (!getNumLayouts(document)) {
        Layout* layout = createLayout(document);
        return setDefaultLayoutFeatures(document, layout);
    }

    return -1;
}

int createDefaultRenderInformation(SBMLDocument* document) {
    if (!createDefaultLocalRenderInformation(document) && !createDefaultGlobalRenderInformation(document))
        return 0;

    return -1;
}

int createDefaultGlobalRenderInformation(SBMLDocument* document) {
    if (!getNumGlobalRenderInformation(document)) {
        GlobalRenderInformation* globalRenderInformation = createGlobalRenderInformation(document);
        return setDefaultGlobalRenderInformationFeatures(document, globalRenderInformation);
    }

    return -1;
}

int createDefaultLocalRenderInformation(SBMLDocument* document) {
    Layout* layout = getLayout(document);
    if (!getNumLocalRenderInformation(layout)) {
        LocalRenderInformation* localRenderInformation = createLocalRenderInformation(layout);
        return setDefaultLocalRenderInformationFeatures(document,layout, localRenderInformation);
    }

    return -1;
}

bool isSetId(SBase* object) {
    if (object)
        return object->isSetId();

    return false;
}

const std::string getId(SBase* object) {
    if (object)
        return object->getId();

    return "";
}

int setId(SBase* object, const std::string& sid) {
    if (object) {
        object->setId(sid);
        return 0;
    }

    return -1;
}

bool isSetName(SBase* object) {
    if (object)
        object->isSetName();

    return false;
}

const std::string getName(SBase* object) {
    if (object)
        return object->getName();

    return "";
}

int setName(SBase* object, const std::string& name) {
    if (object) {
        object->setName(name);
        return 0;
    }

    return -1;
}

bool isSetMetaId(SBase* object) {
    if (object)
        return object->isSetMetaId();

    return false;
}

const std::string getMetaId(SBase* object) {
    if (object)
        return object->getMetaId();

    return "";
}

int setMetaId(SBase* object, const std::string& metaid) {
    if (object) {
        object->setMetaId(metaid);
        return 0;
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

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int index) {
    std::vector<CompartmentGlyph*> compartmentGlyphs = getCompartmentGlyphs(document, compartmentId);
    if (index < compartmentGlyphs.size())
        return compartmentGlyphs.at(index);

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

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int index) {
    std::vector<SpeciesGlyph*> speciesGlyphs = getSpeciesGlyphs(document, speciesId);
    if (index < speciesGlyphs.size())
        return speciesGlyphs.at(index);

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

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int index) {
    std::vector<ReactionGlyph*> reactionGlyphs = getReactionGlyphs(document, reactionId);
    if (index < reactionGlyphs.size())
        return reactionGlyphs.at(index);

    return NULL;
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
