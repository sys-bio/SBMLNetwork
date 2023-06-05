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

ListOfGraphicalObjects getListOfAssociatedGraphicalObjects(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfAssociatedGraphicalObjects;
    mergeListsOfGraphicalObjects(listOfAssociatedGraphicalObjects, getListOfAssociatedCompartmentGlyphs(document, id));
    mergeListsOfGraphicalObjects(listOfAssociatedGraphicalObjects, getListOfAssociatedSpeciesGlyphs(document, id));
    mergeListsOfGraphicalObjects(listOfAssociatedGraphicalObjects, getListOfAssociatedReactionGlyphs(document, id));
    return listOfAssociatedGraphicalObjects;
}

ListOfGraphicalObjects getListOfAssociatedCompartmentGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfAssociatedCompartmentGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            if (layout->getCompartmentGlyph(i)->getCompartmentId() == id)
                listOfAssociatedCompartmentGlyphs.append(layout->getCompartmentGlyph(i));
        }
    }

    return listOfAssociatedCompartmentGlyphs;
}

ListOfGraphicalObjects getListOfAssociatedSpeciesGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfAssociatedSpeciesGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            if (layout->getSpeciesGlyph(i)->getSpeciesId() == id)
                listOfAssociatedSpeciesGlyphs.append(layout->getSpeciesGlyph(i));
        }
    }

    return listOfAssociatedSpeciesGlyphs;
}

ListOfGraphicalObjects getListOfAssociatedReactionGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfAssociatedReactionGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            if (layout->getReactionGlyph(i)->getReactionId() == id)
                listOfAssociatedReactionGlyphs.append(layout->getReactionGlyph(i));
        }
    }

    return listOfAssociatedReactionGlyphs;
}

GraphicalObject* getAssociatedGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfGraphicalObjects listOfAssociatedGraphicalObjects = getListOfAssociatedGraphicalObjects(document, id);
    if (index < listOfAssociatedGraphicalObjects.size())
        return listOfAssociatedGraphicalObjects.get(index);

    return NULL;
}

GraphicalObject* getAssociatedCompartmentGlyph(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfGraphicalObjects listOfAssociatedCompartmentGlyphs = getListOfAssociatedCompartmentGlyphs(document, id);
    if (index < listOfAssociatedCompartmentGlyphs.size())
        return listOfAssociatedCompartmentGlyphs.get(index);

    return NULL;
}

GraphicalObject* getAssociatedSpeciesGlyph(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfGraphicalObjects listOfAssociatedSpeciesGlyphs = getListOfAssociatedSpeciesGlyphs(document, id);
    if (index < listOfAssociatedSpeciesGlyphs.size())
        return listOfAssociatedSpeciesGlyphs.get(index);

    return NULL;
}

GraphicalObject* getAssociatedReactionGlyph(SBMLDocument* document, const std::string& id, unsigned int index) {
    ListOfGraphicalObjects listOfAssociatedReactionGlyphs = getListOfAssociatedReactionGlyphs(document, id);
    if (index < listOfAssociatedReactionGlyphs.size())
        return listOfAssociatedReactionGlyphs.get(index);

    return NULL;
}

}
