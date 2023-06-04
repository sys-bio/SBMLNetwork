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

ListOfGraphicalObjects getListOfGraphicalObjects(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfGraphicalObjects;
    mergeListsOfGraphicalObjects(listOfGraphicalObjects, getListOfCompartmentGlyphs(document, id));
    mergeListsOfGraphicalObjects(listOfGraphicalObjects, getListOfSpeciesGlyphs(document, id));
    mergeListsOfGraphicalObjects(listOfGraphicalObjects, getListOfReactionGlyphs(document, id));
    return listOfGraphicalObjects;
}

ListOfGraphicalObjects getListOfCompartmentGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfCompartmentGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            if (layout->getCompartmentGlyph(i)->getCompartmentId() == id)
                listOfCompartmentGlyphs.append(layout->getCompartmentGlyph(i));
        }
    }

    return listOfCompartmentGlyphs;
}

ListOfGraphicalObjects getListOfSpeciesGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfSpeciesGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            if (layout->getSpeciesGlyph(i)->getSpeciesId() == id)
                listOfSpeciesGlyphs.append(layout->getSpeciesGlyph(i));
        }
    }

    return listOfSpeciesGlyphs;
}

ListOfGraphicalObjects getListOfReactionGlyphs(SBMLDocument* document, const std::string& id) {
    ListOfGraphicalObjects listOfReactionGlyphs;
    Layout* layout = getLayout(document);
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            if (layout->getReactionGlyph(i)->getReactionId() == id)
                listOfReactionGlyphs.append(layout->getReactionGlyph(i));
        }
    }

    return listOfReactionGlyphs;
}

}
