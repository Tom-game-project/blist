#include <stdlib.h>
#include "blist.h"

t_node *get_back(t_node *l) {
    t_node *inode;

    inode = l;
    if (inode == NULL)
        return (NULL);
    while (inode -> back_node != NULL) {
        inode = inode -> back_node;
    }
    return (inode);
}

int push(t_node **l, t_node *n) {
    t_node *tmp;

    tmp = get_back(*l);
    if (tmp == NULL) {
        *l = n;
        n->pre_node = NULL;
        return (0);
    }
    tmp -> back_node = n;
    n -> pre_node = tmp;
    n->back_node = NULL;
    return (0);
}

