%module libsbmlnetworkeditor
%{
#include <libsbml_ne_common.h>
#include <libsbml_ne_layout.h>
#include <libsbml_ne_render.h>
#include <libsbml_ne_util.h>
%}

%include "std_string.i"

%include "libsbml_ne_common.h"
%include "libsbml_ne_layout.h"
%include "libsbml_ne_render.h"
%include "libsbml_ne_util.h"