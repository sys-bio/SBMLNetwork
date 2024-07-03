#include "libsbmlnetwork_sbmldocument.h"
#include "libsbmlnetwork_sbmldocument_layout.h"
#include "libsbmlnetwork_sbmldocument_render.h"
#include "libsbmlnetwork_layout_helpers.h"

namespace LIBSBMLNETWORK_CPP_NAMESPACE  {

    SBMLDocument* readSBML(const std::string& sbml) {
        SBMLDocument* document = readSBMLFromFile(sbml.c_str());
        if (document && document->isSetModel())
            return document;
        document = readSBMLFromString(sbml.c_str());
        if (document && document->isSetModel())
            return document;

        return NULL;
    }

    bool writeSBML(SBMLDocument* document, const std::string &fileName) {
        return writeSBMLToFile(document, fileName.c_str());
    }

    const std::string writeSBML(SBMLDocument* document) {
        return writeSBMLToString(document);
    }

    const unsigned int getSBMLLevel(SBMLDocument* document) {
        if (document)
            return document->getLevel();

        return 0;
    }

    const unsigned int getSBMLVersion(SBMLDocument* document) {
        if (document)
            return document->getVersion();

        return 0;
    }

    bool freeSBMLDocument(SBMLDocument* document) {
        if (document) {
            delete document;
            return true;
        }

        return false;
    }

    bool isSetModel(SBMLDocument* document) {
        if (document)
            return document->isSetModel();

        return false;
    }

    int autolayout(SBMLDocument* document, const double& stiffness, const double& gravity,
                   bool useMagnetism, bool useBoundary, bool useGrid,
                   bool useNameAsTextLabel, std::vector <std::string> lockedNodeIds) {
        const bool layoutIsAdded = !createDefaultLayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid, useNameAsTextLabel, lockedNodeIds);
        const bool renderIsAdded = !createDefaultRenderInformation(document);
        if (layoutIsAdded || renderIsAdded)
            return 0;

        return -1;
    }

    int updateLayoutCurves(SBMLDocument* document, GraphicalObject* updatedGraphicalObject) {
        return autolayout(document, 10, 15, false, false, false, true, getGraphicalObjectsIdsWhosePositionIsNotDependentOnGraphicalObject(getLayout(document),  updatedGraphicalObject));
    }

    int updateLayoutCurves(SBMLDocument* document, std::vector<GraphicalObject*> updatedGraphicalObjects) {
        return autolayout(document, 10, 15, false, false, false, true, getGraphicalObjectsIdsWhosePositionIsNotDependentOnGraphicalObject(getLayout(document), updatedGraphicalObjects));
    }

    int align(SBMLDocument* document, std::vector <std::string> nodeIds, const std::string& alignment) {
        if (nodeIds.size() > 1) {
            std::vector<GraphicalObject*> allGraphicalObjects;
            for (unsigned int i = 0; i < nodeIds.size(); i++) {
                std::vector<GraphicalObject*> graphicalObjects = getGraphicalObjects(document, nodeIds[i]);
                allGraphicalObjects.insert(allGraphicalObjects.end(), graphicalObjects.begin(), graphicalObjects.end());
            }
            alignGraphicalObjects(allGraphicalObjects, alignment);
            return updateLayoutCurves(document, allGraphicalObjects);
        }

        return -1;
    }

    int distribute(SBMLDocument* document, std::vector <std::string> nodeIds, const std::string& direction, const double& spacing) {
        if (nodeIds.size() > 1) {
            std::vector<GraphicalObject*> allGraphicalObjects;
            for (unsigned int i = 0; i < nodeIds.size(); i++) {
                std::vector<GraphicalObject*> graphicalObjects = getGraphicalObjects(document, nodeIds[i]);
                allGraphicalObjects.insert(allGraphicalObjects.end(), graphicalObjects.begin(), graphicalObjects.end());
            }
            distributeGraphicalObjects(allGraphicalObjects, direction, spacing);
            return updateLayoutCurves(document, allGraphicalObjects);
        }

        return -1;
    }

    SBase* getSBMLObject(SBMLDocument* document, const std::string& id) {
        if (document && document->isSetModel())
            return document->getModel()->getElementBySId(id);

        return NULL;
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

    const unsigned int getNumCompartments(SBMLDocument* document) {
        if (document && document->isSetModel())
            return document->getModel()->getNumCompartments();

        return 0;
    }

    const std::string getNthCompartmentId(SBMLDocument* document, const unsigned int& index) {
        if (document && document->isSetModel())
            return document->getModel()->getCompartment(index)->getId();

        return "";
    }

    Compartment* getCompartment(SBMLDocument* document, const std::string& id) {
        if (document && document->isSetModel())
            return document->getModel()->getCompartment(id);

        return NULL;
    }

    const unsigned int getNumSpecies(SBMLDocument* document) {
        if (document && document->isSetModel())
            return document->getModel()->getNumSpecies();

        return 0;
    }

    const std::string getNthSpeciesId(SBMLDocument* document, const unsigned int& index) {
        if (document && document->isSetModel())
            return document->getModel()->getSpecies(index)->getId();

        return "";
    }

    Species* getSpecies(SBMLDocument* document, const std::string& id) {
        if (document && document->isSetModel())
            return document->getModel()->getSpecies(id);

        return NULL;
    }

    const unsigned int getNumReactions(SBMLDocument* document) {
        if (document && document->isSetModel())
            return document->getModel()->getNumReactions();

        return 0;
    }

    const std::string getNthReactionId(SBMLDocument* document, const unsigned int& index) {
        if (document && document->isSetModel())
            return document->getModel()->getReaction(index)->getId();

        return "";
    }

    Reaction* getReaction(SBMLDocument* document, const std::string& id) {
        if (document && document->isSetModel())
            return document->getModel()->getReaction(id);

        return NULL;
    }

    const unsigned int getNumSpeciesReferences(SBMLDocument* document, const std::string& reactionId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getNumReactants() + reaction->getNumProducts() + reaction->getNumModifiers();
        }

        return 0;
    }

    const unsigned int getNumReactants(SBMLDocument* document, const std::string& reactionId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getNumReactants();
        }

        return 0;
    }

    const unsigned int getNumProducts(SBMLDocument* document, const std::string& reactionId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getNumProducts();
        }

        return 0;
    }

    const unsigned int getNumModifiers(SBMLDocument* document, const std::string& reactionId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getNumModifiers();
        }

        return 0;
    }

    const std::string getNthReactantId(SBMLDocument* document, const std::string& reactionId, const unsigned int& index) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getReactant(index)->getId();
        }

        return "";
    }

    const std::string getNthProductId(SBMLDocument* document, const std::string& reactionId, const unsigned int& index) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getProduct(index)->getId();
        }

        return "";
    }

    const std::string getNthModifierId(SBMLDocument* document, const std::string& reactionId, const unsigned int& index) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                return reaction->getModifier(index)->getId();
        }

        return "";
    }

    SpeciesReference* getSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction) {
                if (reaction->getReactant(speciesId))
                    return reaction->getReactant(speciesId);
                else if (reaction->getProduct(speciesId))
                    return reaction->getProduct(speciesId);
            }
        }

        return NULL;
    }

    SpeciesReference* getReactantSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                reaction->getReactant(speciesId);
        }

        return NULL;
    }

    ModifierSpeciesReference* getModifierSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId) {
        if (document && document->isSetModel()) {
            Reaction* reaction = getReaction(document, reactionId);
            if (reaction)
                reaction->getModifier(speciesId);
        }

        return NULL;
    }
}