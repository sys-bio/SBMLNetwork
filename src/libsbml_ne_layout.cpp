#include "libsbml_ne_layout.h"
#include "libsbml_ne_layout_helpers.h"
#include "libsbml_ne_autolayout.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {


ListOfLayouts* getListOfLayouts(SBMLDocument* document) {
    if (document) {
        LayoutModelPlugin* layoutModelPlugin = getLayoutModelPlugin(document);
        if (layoutModelPlugin)
            return layoutModelPlugin->getListOfLayouts();
    }
    
    return NULL;
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

int removeLayouts(SBMLDocument* document) {
    ListOfLayouts* listOfLayouts = getListOfLayouts(document);
    if (listOfLayouts) {
        while (listOfLayouts->size())
            listOfLayouts->remove(0);
        return 0;
    }
        
    return -1;
}

int setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout) {
    if (document && layout) {
        LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(document->getLevel(), document->getVersion());
        layout->setId("libSBML_NetworkEditor_Layout");
        layout->setDimensions(new Dimensions(layoutPkgNamespaces, 1024.0, 1024.0));
        Model* model = document->getModel();
        if (model) {
            setCompartmentGlyphs(model, layout, layoutPkgNamespaces);
            setSpeciesGlyphs(model, layout, layoutPkgNamespaces);
            setReactionGlyphs(model, layout, layoutPkgNamespaces);
            locateGlyphs(model, layout);
            setCompartmentTextGlyphs(layout, layoutPkgNamespaces);
            setSpeciesTextGlyphs(layout, layoutPkgNamespaces);
            return 0;
        }
    }
    
    return -1;
}

GraphicalObject* getGraphicalObject(Layout* layout, const std::string& graphicalObjectId) {
    if (layout) {
        for (unsigned int i = 0; i < layout->getNumCompartmentGlyphs(); i++) {
            if (layout->getCompartmentGlyph(i)->getId() == graphicalObjectId)
                return layout->getCompartmentGlyph(i);
        }
        
        for (unsigned int i = 0; i < layout->getNumSpeciesGlyphs(); i++) {
            if (layout->getSpeciesGlyph(i)->getId() == graphicalObjectId)
                return layout->getSpeciesGlyph(i);
        }
        
        for (unsigned int i = 0; i < layout->getNumReactionGlyphs(); i++) {
            if (layout->getReactionGlyph(i)->getId() == graphicalObjectId)
                return layout->getReactionGlyph(i);
            
            ReactionGlyph* reactionGlyph = layout->getReactionGlyph(i);
            for (unsigned int j = 0; j < reactionGlyph->getNumSpeciesReferenceGlyphs(); j++) {
                if (reactionGlyph->getSpeciesReferenceGlyph(j)->getId() == graphicalObjectId)
                    return reactionGlyph->getSpeciesReferenceGlyph(i);
            }
        }
    }
    
    return NULL;
}

const double getPositionX(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getBoundingBox()->x();
    
    return 0.0;
}

int setPositionX(GraphicalObject* graphicalObject, const double& x) {
    if (graphicalObject) {
        graphicalObject->getBoundingBox()->setX(x);
        return 0;
    }
    
    return -1;
}

const double getPositionY(GraphicalObject* graphicalObject) {
    if (graphicalObject)
        return graphicalObject->getBoundingBox()->y();
    
    return 0.0;
}

int setPositionY(GraphicalObject* graphicalObject, const double& y) {
    if (graphicalObject) {
        graphicalObject->getBoundingBox()->setY(y);
        return 0;
    }
    
    return -1;
}

}
