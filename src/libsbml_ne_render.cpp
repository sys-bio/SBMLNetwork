#include "libsbml_ne_render.h"
#include "libsbml_ne_layout_helpers.h"
#include "libsbml_ne_render_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

ListOfGlobalRenderInformation* getListOfGlobalRenderInformation(SBMLDocument* document) {
    if (document) {
        SBasePlugin* renderBase = getRenderPlugin(document);
        if (renderBase) {
            RenderListOfLayoutsPlugin* renderListOfLayoutsPlugin = getRenderListOfLayoutsPlugin(renderBase);
            if (renderListOfLayoutsPlugin)
                return renderListOfLayoutsPlugin->getListOfGlobalRenderInformation();
        }
    }
    
    return NULL;
}

ListOfLocalRenderInformation* getListOfLocalRenderInformation(Layout* layout) {
    if (layout) {
        SBasePlugin* renderBase = getRenderPlugin(layout);
        if (renderBase) {
            RenderLayoutPlugin* renderLayoutPlugin = getRenderLayoutPlugin(renderBase);
            if (renderLayoutPlugin)
                return renderLayoutPlugin->getListOfLocalRenderInformation();
        }
    }
    
    return NULL;
}

int addGlobalRender(SBMLDocument* document, GlobalRenderInformation* globalRednderInformation) {
    if (globalRednderInformation) {
        ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
        if (listOfGlobalRenderInformation) {
            listOfGlobalRenderInformation->addGlobalRenderInformation(globalRednderInformation);
            return 0;
        }
    }
    
    return -1;
}

int addLocalRender(Layout* layout, LocalRenderInformation* localRednderInformation) {
    if (localRednderInformation) {
        ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
        if (listOfLocalRenderInformation) {
            listOfLocalRenderInformation->addLocalRenderInformation(localRednderInformation);
            return 0;
        }
    }
    
    return -1;
}

GlobalRenderInformation* createGlobalRender(SBMLDocument* document) {
    ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
    if (listOfGlobalRenderInformation)
        return listOfGlobalRenderInformation->createGlobalRenderInformation();
    
    return NULL;
}

LocalRenderInformation* createLocalRender(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation)
        return listOfLocalRenderInformation->createLocalRenderInformation();
    
    return NULL;
}

int removeGlobalRenders(SBMLDocument* document) {
    ListOfGlobalRenderInformation* listOfGlobalRenderInformation = getListOfGlobalRenderInformation(document);
    if (listOfGlobalRenderInformation) {
        while(listOfGlobalRenderInformation->size())
            listOfGlobalRenderInformation->remove(0);
        return 0;
    }
        
    return -1;
}

int removeLocalRenders(Layout* layout) {
    ListOfLocalRenderInformation* listOfLocalRenderInformation = getListOfLocalRenderInformation(layout);
    if (listOfLocalRenderInformation) {
        while(listOfLocalRenderInformation->size())
            listOfLocalRenderInformation->remove(0);
        return 0;
    }
        
    return -1;
}

int setDefaultGlobalRenderFeatures(SBMLDocument* document, GlobalRenderInformation* globalRednderInformation) {
    if (document && globalRednderInformation) {
        LayoutPkgNamespaces* layoutPkgNamespaces = new LayoutPkgNamespaces(document->getLevel(), document->getVersion());
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(document->getLevel(), document->getVersion());
        globalRednderInformation->setId("libSBML_NetworkEditor_Global_Render");
        globalRednderInformation->setBackgroundColor("lightgray");
        addDefaultColors(globalRednderInformation, renderPkgNamespaces);
        addDefaultLineEndings(globalRednderInformation, layoutPkgNamespaces, renderPkgNamespaces);
        return 0;
    }
    
    return -1;
}

int setDefaultLocalRenderFeatures(SBMLDocument* document, Layout* layout, LocalRenderInformation* localRednderInformation) {
    if (document && localRednderInformation) {
        RenderPkgNamespaces* renderPkgNamespaces = new RenderPkgNamespaces(document->getLevel(), document->getVersion());
        localRednderInformation->setId("libSBML_NetworkEditor_Local_Render");
        localRednderInformation->setReferenceRenderInformation("libSBML_NetworkEditor_Global_Render");
        if (layout) {
            addStyles(layout, localRednderInformation, renderPkgNamespaces);
            return 0;
        }
    }
    
    return -1;
}


Style* findStyle(LocalRenderInformation* localRednderInformation, GraphicalObject* graphicalObject) {
    Style * style = NULL;
    if (localRednderInformation && graphicalObject) {
        style = findStyle(localRednderInformation, graphicalObject->getId());
        if (!style) {
            std::string objectRole;
            RenderGraphicalObjectPlugin* renderGraphicalObjectPlugin = dynamic_cast<RenderGraphicalObjectPlugin*>(graphicalObject->getPlugin("render"));
            if (renderGraphicalObjectPlugin && renderGraphicalObjectPlugin->isSetObjectRole())
                objectRole = renderGraphicalObjectPlugin->getObjectRole();
            style = findStyle(localRednderInformation, objectRole);
        }
    }
    
    return style;
}

Style* findStyle(GlobalRenderInformation* globalRednderInformation, GraphicalObject* graphicalObject, const std::string& objectType) {
    Style * style = NULL;
    if (globalRednderInformation) {
        // by role
        if (graphicalObject) {
            RenderGraphicalObjectPlugin* renderGraphicalObjectPlugin = dynamic_cast<RenderGraphicalObjectPlugin*>(graphicalObject->getPlugin("render"));
            if (renderGraphicalObjectPlugin && renderGraphicalObjectPlugin->isSetObjectRole())
                style = findStyle(globalRednderInformation, renderGraphicalObjectPlugin->getObjectRole());
        }
        // by type
        if (!style)
            style = findStyle(globalRednderInformation, objectType);
    }
    
    return style;
}

const std::string getStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStroke();
    
    return "";
}

int setStrokeColor(GraphicalPrimitive1D* graphicalPrimitive1D, const std::string& stroke) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStroke(stroke);
        return 0;
    }
    
    return -1;
}

const std::string getStrokeColor(Style* style) {
    if (style)
        return getStrokeColor(style->getGroup());
    
    return "";
}

int setStrokeColor(Style* style, const std::string& stroke) {
    if (style) {
        setStrokeColor(style->getGroup(), stroke);
        return 0;
    }
    
    return -1;
}

const double getStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeWidth();
    
    return 0.0;
}

int setStrokeWidth(GraphicalPrimitive1D* graphicalPrimitive1D, const double& strokeWidth) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeWidth(strokeWidth);
        return 0;
    }
    
    return -1;
}

const double getStrokeWidth(Style* style) {
    if (style)
        return getStrokeWidth(style->getGroup());
    
    return 0.0;
}

int setStrokeWidth(Style* style, const double& strokeWidth) {
    if (style) {
        setStrokeWidth(style->getGroup(), strokeWidth);
        return 0;
    }
    
    return -1;
}

const std::vector<unsigned int> getStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D) {
    if (graphicalPrimitive1D)
        return graphicalPrimitive1D->getStrokeDashArray();
    
    return std::vector<unsigned int>();
}

int setStrokeDashArray(GraphicalPrimitive1D* graphicalPrimitive1D, const std::vector<unsigned int>& strokeDashArray) {
    if (graphicalPrimitive1D) {
        graphicalPrimitive1D->setStrokeDashArray(strokeDashArray);
        return 0;
    }
    
    return -1;
}

const std::vector<unsigned int> getStrokeDashArray(Style* style) {
    if (style)
        return getStrokeDashArray(style->getGroup());
    
    return std::vector<unsigned int>();
}

int setStrokeDashArray(Style* style, const std::vector<unsigned int>& strokeDashArray) {
    if (style) {
        setStrokeDashArray(style->getGroup(), strokeDashArray);
        return 0;
    }
    
    return -1;
}

}

