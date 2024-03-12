#include "libsbml_ne_sbmldocument.h"
#include "libsbml_ne_sbmldocument_layout.h"
#include "libsbml_ne_sbmldocument_render.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

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

    bool isSetModel(SBMLDocument* document) {
        if (document)
            return document->isSetModel();

        return false;
    }

    int autolayout(SBMLDocument* document, const double& stiffness, const double& gravity,
                   const bool& useMagnetism, const bool& useBoundary, const bool& useGrid,
                   std::vector <std::string> lockedNodeIds) {
        if (!createDefaultLayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid, lockedNodeIds) && !createDefaultRenderInformation(document))
            return 0;

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