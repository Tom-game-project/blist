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
        return (0);
    }
    tmp -> back_node = n;
    n -> pre_node = tmp;
    return (0);
}


#include <stdio.h>

/// @brief test function
/// @param l 
void show_list(t_node *l)
{
    t_node *inode;
    int counter;

    inode = l;
    counter = 0;
    while (1)
    {
        printf("%d %p\n", counter, inode->data);
        inode = inode->back_node;
        counter++;
        if (inode == NULL)
            break;
    }
        
}