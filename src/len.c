#include "blist.h"
#include <stdlib.h>

unsigned int len(t_node **l) {
    unsigned int i = 0;
    t_node *tmp = *l;

    while (tmp != NULL) {
        tmp = tmp->back_node;
        i += 1;
    }
    return i;
}
