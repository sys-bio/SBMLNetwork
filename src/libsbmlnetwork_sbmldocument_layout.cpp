#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_sbmldocument.h"
#include "libsbmlnetwork_layout.h"
#include "libsbmlnetwork_layout_helpers.h"
#include "features/set_layout_features/libsbmlnetwork_set_layout_features.h"
#include "features/update_curves/libsbmlnetwork_update_curves.h"
#include "features/autolayout/libsbmlnetwork_autolayout.h"
#include "features/user_data/libsbmlnetwork_user_data.h"
#include "features/defaults/libsbmlnetwork_defaults_layout.h"
#include "features/alias_elements/libsbmlnetwork_alias_species.h"
#include "features/alias_elements/libsbmlnetwork_alias_reaction.h"
#include "features/fix_elements/libsbmlnetwork_fix_element_position.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

ListOfLayouts* getListOfLayouts(SBMLDocument* document) {
    if (document) {
        LayoutModelPlugin* layoutModelPlugin = getLayoutModelPlugin(document);
        if (layoutModelPlugin)
            return layoutModelPlugin->getListOfLayouts();
    }

    return NULL;
}

const unsigned int getNumLayouts(const SBMLDocument* document) {
    return getNumLayouts(getListOfLayouts(const_cast<SBMLDocument*>(document)));
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

int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges) {
    return set_layout_features_setDefaultLayoutFeatures(document, layout, maxNumConnectedEdges);
}

int setDefaultLayoutLocations(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges, bool resetFixedPositionElements, const std::set<std::pair<std::string, int> > fixedPositionNodesSet) {
    return set_layout_features_setDefaultLayoutLocations(document, layout, maxNumConnectedEdges, resetFixedPositionElements, fixedPositionNodesSet);
}

int updateLayoutCurves(SBMLDocument* document, Layout* layout) {
    return update_curves_updateLayoutCurves(document, layout);
}

bool getUseNameAsTextLabel(SBMLDocument* document, unsigned int layoutIndex) {
    std::string useNameAsTextLabel = user_data_getUserData(getLayout(document, layoutIndex), "use_name_as_text_label");
    if (useNameAsTextLabel == "false")
        return false;

    return true;
}

int setUseNameAsTextLabel(SBMLDocument* document, unsigned int layoutIndex, bool useNameAsTextLabel) {
    return user_data_setUserData(getLayout(document, layoutIndex), "use_name_as_text_label", useNameAsTextLabel ? "true" : "false");
}

int createDefaultLayoutFeatures(SBMLDocument* document, const int maxNumConnectedEdges) {
    Layout* layout = getLayout(document);
    if (!layout)
        layout = createLayout(document);

    return setDefaultLayoutFeatures(document, layout, maxNumConnectedEdges);
}

int createDefaultLayoutLocations(SBMLDocument* document, const int maxNumConnectedEdges, bool resetFixedPositionElements, const std::set<std::pair<std::string, int> > fixedPositionNodesSet) {
    Layout* layout = getLayout(document);
    if (!layout)
        layout = createLayout(document);

    return setDefaultLayoutLocations(document, layout, maxNumConnectedEdges, resetFixedPositionElements, fixedPositionNodesSet);
}

int createAliasSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    if (!alias_element_createAliasSpeciesGlyph(getLayout(document), speciesId, getReactionGlyph(document, reactionId, reactionGlyphIndex)))
        return updateLayoutCurves(document, getLayout(document));

    return -1;
}

int createAliasSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    if (!alias_element_createAliasSpeciesGlyph(getLayout(document, layoutIndex), speciesId, getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex)))
        return updateLayoutCurves(document, getLayout(document, layoutIndex));

    return -1;
}

int createAliasReactionGlyph(SBMLDocument* document, const std::string& reactionId) {
    return alias_element_createAliasReactionGlyph(document, getLayout(document), getReactionGlyph(document, reactionId));
}

int createAliasReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId) {
    return alias_element_createAliasReactionGlyph(document, getLayout(document, layoutIndex), getReactionGlyph(document, layoutIndex, reactionId));
}

int setSpeciesGlyphIndexInReactionGlyph(SBMLDocument* document, const std::string& speciesId, const std::string& reactionId, const unsigned int index) {
    if (!setSpeciesGlyphIndexInReactionGlyph(getLayout(document), speciesId, getReactionGlyph(document, reactionId), index))
        return updateLayoutCurves(document, getLayout(document));

    return -1;
}

int setSpeciesGlyphIndexInReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, const std::string& reactionId, const unsigned int index) {
    if (!setSpeciesGlyphIndexInReactionGlyph(getLayout(document, layoutIndex), speciesId, getReactionGlyph(document, layoutIndex, reactionId), index))
        return updateLayoutCurves(document, getLayout(document, layoutIndex));

    return -1;
}

int setSpeciesGlyphIndexInReactionGlyph(SBMLDocument* document, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex, const unsigned int index) {
    if (!setSpeciesGlyphIndexInReactionGlyph(getLayout(document), speciesId, getReactionGlyph(document, reactionId, reactionGlyphIndex), index))
        return updateLayoutCurves(document, getLayout(document));

    return -1;
}

int setSpeciesGlyphIndexInReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex, const unsigned int index) {
    if (!setSpeciesGlyphIndexInReactionGlyph(getLayout(document, layoutIndex), speciesId, getReactionGlyph(document, layoutIndex, reactionId, reactionGlyphIndex), index))
        return updateLayoutCurves(document, getLayout(document, layoutIndex));

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
    return getGraphicalObject(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int removeGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return removeGraphicalObject(getLayout(document), id, graphicalObjectIndex);
}

int removeGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return removeGraphicalObject(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

bool isSetId(SBMLDocument* document, unsigned int layoutIndex,  const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetId(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const std::string getId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getId(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setId(getLayout(document, layoutIndex), id, graphicalObjectIndex, graphicalObjectId);
}

bool isSetMetaId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetMetaId(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const std::string getMetaId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getMetaId(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setMetaId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectMetaId) {
    return setMetaId(getLayout(document, layoutIndex), id, graphicalObjectIndex, graphicalObjectMetaId);
}

bool isSetName(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetName(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const std::string getName(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getName(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setName(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectName) {
    return setName(getLayout(document, layoutIndex), id, graphicalObjectIndex, graphicalObjectName);
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

CompartmentGlyph* getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, unsigned int compartmentGlyphIndex) {
    return getCompartmentGlyph(getLayout(document, layoutIndex), compartmentGlyphIndex);
}

bool isCompartmentGlyph(SBMLDocument* document, const std::string& id) {
    return isCompartmentGlyph(getLayout(document), id);
}

bool isCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isCompartmentGlyph(getLayout(document, layoutIndex), id);
}

std::string getGraphicalObjectCompartmentId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getGraphicalObjectCompartmentId(document, getGraphicalObject(document, id, graphicalObjectIndex));
}

std::string getGraphicalObjectCompartmentId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getGraphicalObjectCompartmentId(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
}

std::string getGraphicalObjectCompartmentId(SBMLDocument* document, GraphicalObject* graphicalObject) {
    Compartment* compartment = getAssociatedCompartment(document, graphicalObject);
    if (compartment)
        return compartment->getId();

    return "";
}

Compartment* getAssociatedCompartment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getAssociatedCompartment(document, getGraphicalObject(document, id, graphicalObjectIndex));
}

Compartment* getAssociatedCompartment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getAssociatedCompartment(document, getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex));
}

Compartment* getAssociatedCompartment(SBMLDocument* document, GraphicalObject* graphicalObject) {
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

std::vector<std::string> getSpeciesGlyphsIds(SBMLDocument* document, unsigned int layoutIndex) {
    return getSpeciesGlyphsIds(getLayout(document, layoutIndex));
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

SpeciesGlyph* getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, unsigned int speciesGlyphIndex) {
    return getSpeciesGlyph(getLayout(document, layoutIndex), speciesGlyphIndex);
}

const int getSpeciesGlyphIndex(SBMLDocument* document, const char* speciesId, const char* reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesGlyphIndex(getLayout(document), speciesId, reactionId, reactionGlyphIndex);
}

const int getSpeciesGlyphIndex(SBMLDocument* document, unsigned int layoutIndex, const char* speciesId, const char* reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesGlyphIndex(getLayout(document, layoutIndex), speciesId, reactionId, reactionGlyphIndex);
}

bool isSpeciesGlyph(SBMLDocument* document, const std::string& id) {
    return isSpeciesGlyph(getLayout(document), id);
}

bool isSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isSpeciesGlyph(getLayout(document, layoutIndex), id);
}

std::vector<std::string> getReactionGlyphsIds(SBMLDocument* document, unsigned int layoutIndex) {
    return getReactionGlyphsIds(getLayout(document, layoutIndex));
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

const unsigned int getNumSpeciesReferences(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferences(getLayout(document), reactionId, reactionGlyphIndex);
}

const unsigned int getNumSpeciesReferences(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferences(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferences(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferences(getLayout(document), reactionId, reactionGlyphIndex);
}

std::vector<SpeciesReferenceGlyph*> getSpeciesReferences(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getSpeciesReferences(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex);
}

SpeciesReferenceGlyph* getSpeciesReference(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

SpeciesReferenceGlyph* getSpeciesReference(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceSpeciesId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getSpeciesReferenceSpeciesGlyphId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetSpeciesReferenceEmptySpeciesGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetEmptySpeciesGlyph(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetSpeciesReferenceEmptySpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetEmptySpeciesGlyph(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceEmptySpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getEmptySpeciesGlyphId(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceEmptySpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getEmptySpeciesGlyphId(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

bool isSetSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

const std::string getSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex);
}

int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, const std::string& role) {
    return setRole(getLayout(document), reactionId, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getLayout(document), reactionId, reactionGlyphIndex, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& role) {
    return setRole(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex, role);
}

int setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& role) {
    return setRole(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex, role);
}

const int getNumSpeciesReferencesAssociatedWithSpecies(SBMLDocument* document, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferencesAssociatedWithSpecies(getLayout(document), speciesId, reactionId, reactionGlyphIndex);
}

const int getNumSpeciesReferencesAssociatedWithSpecies(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex) {
    return getNumSpeciesReferencesAssociatedWithSpecies(getLayout(document, layoutIndex), speciesId, reactionId, reactionGlyphIndex);
}

const int getSpeciesReferenceIndexAssociatedWithSpecies(SBMLDocument* document, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int n) {
    return getSpeciesReferenceIndexAssociatedWithSpecies(getLayout(document), speciesId, reactionId, reactionGlyphIndex, n);
}

const int getSpeciesReferenceIndexAssociatedWithSpecies(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int n) {
    return getSpeciesReferenceIndexAssociatedWithSpecies(getLayout(document, layoutIndex), speciesId, reactionId, reactionGlyphIndex, n);
}

bool isSetSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetCurve(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

bool isSetSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return isSetCurve(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

Curve* getSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getCurve(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

Curve* getSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getCurve(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

const unsigned int getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getNumCurveSegments(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

const unsigned int getNumSpeciesReferenceCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return getNumCurveSegments(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

LineSegment* getSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

LineSegment* getSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int addSpeciesReferenceLineCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return addLineCurveSegment(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

int addSpeciesReferenceLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return addLineCurveSegment(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

int addSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return addCubicBezierCurveSegment(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

int addSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex) {
    return addCubicBezierCurveSegment(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex));
}

int removeSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int removeSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

bool isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

bool isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

double getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

double getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

double getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

int setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, x);
}

double getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

double getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex);
}

int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getSpeciesReference(getLayout(document), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

int setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getSpeciesReference(getLayout(document, layoutIndex), reactionId, reactionGlyphIndex, speciesReferenceIndex), curveSegmentIndex, y);
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumTextGlyphs(getLayout(document, layoutIndex));
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumTextGlyphs(getLayout(document), getGraphicalObject(getLayout(document), id, graphicalObjectIndex));
}

const unsigned int getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumTextGlyphs(getLayout(document, layoutIndex), getGraphicalObject(getLayout(document, layoutIndex), id, graphicalObjectIndex));
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

TextGlyph* getTextGlyph(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document), graphicalObject, textGlyphIndex);
}

TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document, layoutIndex), id, textGlyphIndex);
}

TextGlyph* getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, GraphicalObject* graphicalObject, unsigned int textGlyphIndex) {
    return getTextGlyph(getLayout(document, layoutIndex), graphicalObject, textGlyphIndex);
}

bool isSetText(SBMLDocument* document, const std::string& id) {
    return isSetText(getLayout(document), id);
}

bool isSetText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    return isSetText(getLayout(document, layoutIndex), id);
}

const std::string getText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getText(document, 0, id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    std::string text = getText(getLayout(const_cast<SBMLDocument*>(document), layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
    if (!text.empty()) {
        return text;
    }
    SBase* sBase = getSBMLObject(const_cast<SBMLDocument*>(document), getOriginOfTextId(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex));
    if (sBase) {
        std::string useNameAsTextLabel = user_data_getUserData(getLayout(document, layoutIndex), "use_name_as_text_label");
        if (useNameAsTextLabel != "false") {
            text = sBase->getName();
            if (!text.empty())
                return text;
        }
        text = sBase->getId();
        if (!text.empty())
            return text;
    }
    text = getGraphicalObjectId(document, layoutIndex, id, graphicalObjectIndex, textGlyphIndex);
    if (!text.empty()) {
        return text;
    }

    return "";
}

int setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return setText(getLayout(document), id, graphicalObjectIndex, text);
}

int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return setText(getLayout(document, layoutIndex), id, graphicalObjectIndex, text);
}

int setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getLayout(document), id, graphicalObjectIndex, textGlyphIndex, text);
}

int setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text) {
    return setText(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex, text);
}

int addText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return addText(getLayout(document), id, graphicalObjectIndex, text);
}

int addText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text) {
    return addText(getLayout(document, layoutIndex), id, graphicalObjectIndex, text);
}

int removeText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return removeText(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

int removeText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return removeText(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

bool isSetOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

bool isSetOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getOriginOfTextId(const SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getLayout(const_cast<SBMLDocument*>(document)), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getOriginOfTextId(const SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getOriginOfTextId(getLayout(const_cast<SBMLDocument*>(document), layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document), id, graphicalObjectIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex, orig);
}

int setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig) {
    return setOriginOfTextId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex, orig);
}

bool isSetGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex);
}

bool isSetGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return isSetGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getGraphicalObjectId(const SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getLayout(const_cast<SBMLDocument*>(document)), id, graphicalObjectIndex, textGlyphIndex);
}

const std::string getGraphicalObjectId(const SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getGraphicalObjectId(getLayout(const_cast<SBMLDocument*>(document), layoutIndex), id, graphicalObjectIndex, textGlyphIndex);
}

int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document), id, graphicalObjectIndex, textGlyphIndex, graphicalObjectId);
}

int setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId) {
    return setGraphicalObjectId(getLayout(document, layoutIndex), id, graphicalObjectIndex, textGlyphIndex, graphicalObjectId);
}

bool isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getLayout(document), id, textGlyphIndex);
}

bool isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex) {
    return isTextGlyph(getLayout(document, layoutIndex), id, textGlyphIndex);
}

const unsigned int getNumAdditionalGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex) {
    return getNumAdditionalGraphicalObjects(getLayout(document, layoutIndex));
}

GraphicalObject* getAdditionalGraphicalObject(SBMLDocument* document, unsigned int additionalGraphicalObjectIndex) {
    return getAdditionalGraphicalObject(getLayout(document), additionalGraphicalObjectIndex);
}

const std::string getAdditionalGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, unsigned int additionalGraphicalObjectIndex) {
    return getAdditionalGraphicalObjectId(getLayout(document, layoutIndex), additionalGraphicalObjectIndex);
}

int addAdditionalGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id) {
    if (set_layout_features_createAdditionalGraphicalObject(getLayout(document, layoutIndex), id))
        return 0;

    return -1;
}

int removeAdditionalGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, unsigned int additionalGraphicalObjectIndex) {
    return set_layout_features_removeAdditionalGraphicalObject(getLayout(document, layoutIndex), additionalGraphicalObjectIndex);
}

BoundingBox* getBoundingBox(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getBoundingBox(getLayout(document), id, graphicalObjectIndex);
}

BoundingBox* getBoundingBox(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getBoundingBox(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const double getPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionX(getLayout(document), id, graphicalObjectIndex);
}

const double getPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionX(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setPositionX(SBMLDocument* document, const std::string& id, const double& x, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setPositionX(layout, id, x)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionX(layout, id, x)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setPositionX(layout, id, graphicalObjectIndex, x)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionX(layout, id, graphicalObjectIndex, x)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getLayout(document), id, graphicalObjectIndex);
}

const double getPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getPositionY(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setPositionY(SBMLDocument* document, const std::string& id, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setPositionY(layout, id, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionY(layout, id, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setPositionY(layout, id, graphicalObjectIndex, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPositionY(layout, id, graphicalObjectIndex, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setPosition(layout, id, x, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPosition(layout, id, x, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setPosition(layout, id, graphicalObjectIndex, x, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setPosition(layout, id, graphicalObjectIndex, x, y)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getLayout(document), id, graphicalObjectIndex);
}

const double getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionWidth(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setDimensionWidth(SBMLDocument* document, const std::string& id, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setDimensionWidth(layout, id, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionWidth(layout, id, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setDimensionWidth(layout, id, graphicalObjectIndex, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionWidth(layout, id, graphicalObjectIndex, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setCompartmentDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setCompartmentDimensionWidth(layout, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getSpeciesDimensionWidth() {
    return defaults_getSpeciesDefaultWidth();
}


int setSpeciesDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setSpeciesDimensionWidth(layout, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getReactionDimensionWidth() {
    return defaults_getReactionDefaultWidth();
}

int setReactionDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setReactionDimensionWidth(layout, width)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getEmptySpeciesDefaultWidth() {
    return defaults_getEmptySpeciesDefaultWidth();
}

const double getDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getLayout(document), id, graphicalObjectIndex);
}

const double getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getDimensionHeight(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int setDimensionHeight(SBMLDocument* document, const std::string& id, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setDimensionHeight(layout, id, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionHeight(layout, id, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document);
    if (!setDimensionHeight(layout, id, graphicalObjectIndex, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setDimensionHeight(layout, id, graphicalObjectIndex, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

int setCompartmentDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setCompartmentDimensionHeight(layout, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getSpeciesDimensionHeight() {
    return defaults_getSpeciesDefaultHeight();
}

int setSpeciesDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setSpeciesDimensionHeight(layout, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getReactionDimensionHeight() {
    return defaults_getReactionDefaultHeight();
}

const double getEmptySpeciesDefaultHeight() {
    return defaults_getEmptySpeciesDefaultHeight();
}

int setReactionDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves) {
    Layout* layout = getLayout(document, layoutIndex);
    if (!setReactionDimensionHeight(layout, height)) {
        if (updateCurves)
            updateLayoutCurves(document, layout);
        return 0;
    }

    return -1;
}

const double getTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionX(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextPositionX(SBMLDocument* document, const std::string& id, const double& x) {
    return setTextPositionX(getLayout(document), getGraphicalObject(document, id), x);
}

int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x) {
    return setTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), x);
}

int setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setTextPositionX(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), x);
}

int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x) {
    return setTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), x);
}

int setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x) {
    return setTextPositionX(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, x);
}

int setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x) {
    return setTextPositionX(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, x);
}

const double getTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionY(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextPositionY(SBMLDocument* document, const std::string& id, const double& y) {
    return setTextPositionY(getLayout(document), getGraphicalObject(document, id), y);
}

int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y) {
    return setTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), y);
}

int setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setTextPositionY(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), y);
}

int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y) {
    return setTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), y);
}

int setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y) {
    return setTextPositionY(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, y);
}

int setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y) {
    return setTextPositionY(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, y);
}

int setTextPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y) {
    return setTextPosition(getLayout(document), getGraphicalObject(document, id), x, y);
}

int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y) {
    return setTextPosition(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), x, y);
}

int setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), x, y);
}

int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), x, y);
}

int setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, x, y);
}

int setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y) {
    return setTextPosition(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, x, y);
}

const double getTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionWidth(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextDimensionWidth(SBMLDocument* document, const std::string& id, const double& width) {
    return setTextDimensionWidth(getLayout(document), getGraphicalObject(document, id), width);
}

int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width) {
    return setTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), width);
}

int setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), width);
}

int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), width);
}

int setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, width);
}

int setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width) {
    return setTextDimensionWidth(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, width);
}

const double getTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionHeight(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex);
}

const double getTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex) {
    return getTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex);
}

int setTextDimensionHeight(SBMLDocument* document, const std::string& id, const double& height) {
    return setTextDimensionHeight(getLayout(document), getGraphicalObject(document, id), height);
}

int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height) {
    return setTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id), height);
}

int setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), height);
}

int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), height);
}

int setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document), getGraphicalObject(document, id, graphicalObjectIndex), textGlyphIndex, height);
}

int setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height) {
    return setTextDimensionHeight(getLayout(document, layoutIndex), getGraphicalObject(document, layoutIndex, id, graphicalObjectIndex), textGlyphIndex, height);
}

bool isSetCurve(const SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetCurve(getLayout(const_cast<SBMLDocument*>(document)), id, graphicalObjectIndex);
}

bool isSetCurve(const SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return isSetCurve(getLayout(const_cast<SBMLDocument*>(document), layoutIndex), id, graphicalObjectIndex);
}

Curve* getCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCurve(getLayout(document), id, graphicalObjectIndex);
}

Curve* getCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getCurve(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

const unsigned int getNumCurveSegments(const SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumCurveSegments(getLayout(const_cast<SBMLDocument*>(document)), id, graphicalObjectIndex);
}

const unsigned int getNumCurveSegments(const SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return getNumCurveSegments(getLayout(const_cast<SBMLDocument*>(document), layoutIndex), id, graphicalObjectIndex);
}

LineSegment* getCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

LineSegment* getCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int addLineCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return addLineCurveSegment(getLayout(document), id, graphicalObjectIndex);
}

int addLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return addLineCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int addCubicBezierCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex) {
    return addCubicBezierCurveSegment(getLayout(document), id, graphicalObjectIndex);
}

int addCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex) {
    return addCubicBezierCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex);
}

int removeCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

int removeCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return removeCurveSegment(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

bool isCubicBezier(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

bool isCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return isCubicBezier(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentStartPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentStartPointY(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentStartPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

const double getCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointX(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentEndPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentEndPointY(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentEndPointY(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

const double getCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint1Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint1Y(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint1Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

const double getCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document, layoutIndex), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2X(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, x);
}

const double getCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex);
}

const double getCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex) {
    return getCurveSegmentBasePoint2Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x) {
    return setCurveSegmentBasePoint2Y(getLayout(document), id, curveSegmentIndex, x);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getLayout(document, layoutIndex), id, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getLayout(document), id, graphicalObjectIndex, curveSegmentIndex, y);
}

int setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y) {
    return setCurveSegmentBasePoint2Y(getLayout(document, layoutIndex), id, graphicalObjectIndex, curveSegmentIndex, y);
}

}
