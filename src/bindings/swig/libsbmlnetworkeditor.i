%module libsbmlnetworkeditor
%{
#include <libsbml_ne_common.h>
#include <libsbml_ne_layout.h>
#include <libsbml_ne_render.h>
#include <libsbml_ne_util.h>
%}

%include "std_string.i"
%include "std_vector.i"

namespace std {
    %template(CompartmentGlyphVector) vector<CompartmentGlyph*>;
    %template(SpeciesGlyphVector) vector<SpeciesGlyph*>;
    %template(ReactionGlyphVector) vector<ReactionGlyph*>;
}



%include "libsbml_ne_common.h"
%include "libsbml_ne_layout.h"
%include "libsbml_ne_render.h"
%include "libsbml_ne_util.h"