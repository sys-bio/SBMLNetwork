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

ListOfCompartmentGlyphs getListOfAssociatedCompartmentGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfCompartmentGlyphs listOfAssociatedCompartmentGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            if (layout->getCompartmentGlyph(i)->getCompartmentId() == id)
                listOfAssociatedCompartmentGlyphs.append(layout->getCompartmentGlyph(i));
        }
    }

    return listOfAssociatedCompartmentGlyphs;
}

const unsigned int getNumAssociatedCompartmentGlyphs(SBMLDocument* document, const std::string& id) {
    return getListOfAssociatedCompartmentGlyphs(document, id).size();
}

CompartmentGlyph* getAssociatedCompartmentGlyph(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfCompartmentGlyphs listOfAssociatedCompartmentGlyphs = getListOfAssociatedCompartmentGlyphs(document, id);
    if (index < listOfAssociatedCompartmentGlyphs.size())
        return listOfAssociatedCompartmentGlyphs.get(index);

    return NULL;
}

ListOfSpeciesGlyphs getListOfAssociatedSpeciesGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfSpeciesGlyphs listOfAssociatedSpeciesGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            if (layout->getSpeciesGlyph(i)->getSpeciesId() == id)
                listOfAssociatedSpeciesGlyphs.append(layout->getSpeciesGlyph(i));
        }
    }

    return listOfAssociatedSpeciesGlyphs;
}

const unsigned int getNumAssociatedSpeciesGlyphs(SBMLDocument* document, const std::string& id) {
    return getListOfAssociatedSpeciesGlyphs(document, id).size();
}

SpeciesGlyph* getAssociatedSpeciesGlyph(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfSpeciesGlyphs listOfAssociatedSpeciesGlyphs = getListOfAssociatedSpeciesGlyphs(document, id);
    if (index < listOfAssociatedSpeciesGlyphs.size())
        return listOfAssociatedSpeciesGlyphs.get(index);

    return NULL;
}

ListOfReactionGlyphs getListOfAssociatedReactionGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfReactionGlyphs listOfAssociatedReactionGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            if (layout->getReactionGlyph(i)->getReactionId() == id)
                listOfAssociatedReactionGlyphs.append(layout->getReactionGlyph(i));
        }
    }

    return listOfAssociatedReactionGlyphs;
}

const unsigned int getNumAssociatedReactionGlyphs(SBMLDocument* document, const std::string& id) {
    return getListOfAssociatedReactionGlyphs(document, id).size();
}

ReactionGlyph* getAssociatedReactionGlyph(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfReactionGlyphs listOfAssociatedReactionGlyphs = getListOfAssociatedReactionGlyphs(document, id);
    if (index < listOfAssociatedReactionGlyphs.size())
        return listOfAssociatedReactionGlyphs.get(index);

    return NULL;
}

}
