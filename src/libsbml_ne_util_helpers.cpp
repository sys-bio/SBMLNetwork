#include "libsbml_ne_util_helpers.h"

namespace LIBSBML_NETWORKEDITOR_CPP_NAMESPACE  {

void mergeListsOfGraphicalObjects(ListOfGraphicalObjects list1, ListOfGraphicalObjects list2) {
    for (unsigned int i = 0; i < list2.size(); i++)
        list1.append(list2.get(i));
}

}