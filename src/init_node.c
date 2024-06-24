#include <stdlib.h>
#include "blist.h"

/// @brief malloc and initialize s_node
/// @return t_node *
t_node *init_node(void *a)
{
    t_node *r;
    r = (t_node *)malloc(sizeof(t_node));
    if (r == NULL)
        return (NULL);
    r -> data = a;
    r -> pre_node = NULL;
    r -> back_node = NULL;
    return (r);
}