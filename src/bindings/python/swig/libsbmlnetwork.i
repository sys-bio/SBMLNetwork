%module libsbmlnetwork
%{
#include <libsbmlnetwork_common.h>
#include <libsbmlnetwork_sbmldocument.h>
#include <libsbmlnetwork_sbmldocument_layout.h>
#include <libsbmlnetwork_layout.h>
#include <libsbmlnetwork_sbmldocument_render.h>
#include <libsbmlnetwork_layout_render.h>
#include <libsbmlnetwork_render.h>
%}

%include "std_string.i"
%include "std_vector.i"

namespace std {
    %template(CompartmentGlyphVector) vector<CompartmentGlyph*>;
    %template(SpeciesGlyphVector) vector<SpeciesGlyph*>;
    %template(ReactionGlyphVector) vector<ReactionGlyph*>;
}


%include "libsbmlnetwork_common.h"
%include "libsbmlnetwork_sbmldocument.h"
%include "libsbmlnetwork_sbmldocument_layout.h"
%include "libsbmlnetwork_layout.h"
%include "libsbmlnetwork_sbmldocument_render.h"
%include "libsbmlnetwork_layout_render.h"
%include "libsbmlnetwork_render.h"