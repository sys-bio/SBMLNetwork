#include "libsbml_ne_sbmldocument.h"
#include "libsbml_ne_sbmldocument_layout.h"
#include "libsbml_ne_sbmldocument_render.h"

extern "C" {

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE {

    int autolayoutWithDefaultParameters(SBMLDocument* document) {
        if (!createDefaultLayout(document, 10.0, 15.0, false, false, false) && !createDefaultRenderInformation(document))
            return 0;

        return -1;
    }

    int autolayout(SBMLDocument* document, const double stiffness, const double gravity, const bool useMagnetism,
                   const bool useBoundary, const bool useGrid) {
        if (!createDefaultLayout(document, stiffness, gravity, useMagnetism, useBoundary, useGrid) && !createDefaultRenderInformation(document))
            return 0;

        return -1;
    }

    Compartment *getCompartment(SBMLDocument *document, const char* id) {
        if (document->isSetModel())
            return document->getModel()->getCompartment(id);

        return NULL;
    }

    Species *getSpecies(SBMLDocument *document, const char* id) {
        if (document->isSetModel())
            return document->getModel()->getSpecies(id);

        return NULL;
    }

    Reaction *getReaction(SBMLDocument *document, const char* id) {
        if (document->isSetModel())
            return document->getModel()->getReaction(id);

        return NULL;
    }

    SpeciesReference *
    getSpeciesReference(SBMLDocument *document, const char* reactionId, const char* speciesId) {
        if (document->isSetModel()) {
            Reaction *reaction = getReaction(document, reactionId);
            if (reaction) {
                if (reaction->getReactant(speciesId))
                    return reaction->getReactant(speciesId);
                else if (reaction->getProduct(speciesId))
                    return reaction->getProduct(speciesId);
            }
        }

        return NULL;
    }

    SpeciesReference *
    getReactantSpeciesReference(SBMLDocument *document, const char* reactionId, const char* speciesId) {
        if (document->isSetModel()) {
            Reaction *reaction = getReaction(document, reactionId);
            if (reaction)
                reaction->getReactant(speciesId);
        }

        return NULL;
    }

    ModifierSpeciesReference *
    getModifierSpeciesReference(SBMLDocument *document, const char* reactionId, const char* speciesId) {
        if (document->isSetModel()) {
            Reaction *reaction = getReaction(document, reactionId);
            if (reaction)
                reaction->getModifier(speciesId);
        }

        return NULL;
    }
}

}
