#include "libsbml_ne_util.h"
#include "libsbml_ne_layout.h"
#include "libsbml_ne_render.h"
#include "libsbml_ne_util_helpers.h"

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

ListOfCompartmentGlyphs getListOfCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    ListOfCompartmentGlyphs listOfCompartmentGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            if (layout->getCompartmentGlyph(i)->getCompartmentId() == compartmentId)
                listOfCompartmentGlyphs.append(layout->getCompartmentGlyph(i));
        }
    }

    return listOfCompartmentGlyphs;
}

const unsigned int getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId) {
    return getListOfCompartmentGlyphs(document, compartmentId).size();
}

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int index) {
    ListOfCompartmentGlyphs listOfCompartmentGlyphs = getListOfCompartmentGlyphs(document, compartmentId);
    if (index < listOfCompartmentGlyphs.size())
        return listOfCompartmentGlyphs.get(index);

    return NULL;
}

ListOfSpeciesGlyphs getListOfSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    ListOfSpeciesGlyphs listOfSpeciesGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            if (layout->getSpeciesGlyph(i)->getSpeciesId() == speciesId)
                listOfSpeciesGlyphs.append(layout->getSpeciesGlyph(i));
        }
    }

    return listOfSpeciesGlyphs;
}

const unsigned int getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId) {
    return getListOfSpeciesGlyphs(document, speciesId).size();
}

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int index) {
    ListOfSpeciesGlyphs listOfSpeciesGlyphs = getListOfSpeciesGlyphs(document, speciesId);
    if (index < listOfSpeciesGlyphs.size())
        return listOfSpeciesGlyphs.get(index);

    return NULL;
}

ListOfReactionGlyphs getListOfReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    ListOfReactionGlyphs listOfReactionGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            if (layout->getReactionGlyph(i)->getReactionId() == reactionId)
                listOfReactionGlyphs.append(layout->getReactionGlyph(i));
        }
    }

    return listOfReactionGlyphs;
}

const unsigned int getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId) {
    return getListOfReactionGlyphs(document, reactionId).size();
}

ReactionGlyph* getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int index) {
    ListOfReactionGlyphs listOfReactionGlyphs = getListOfReactionGlyphs(document, reactionId);
    if (index < listOfReactionGlyphs.size())
        return listOfReactionGlyphs.get(index);

    return NULL;
}

}
