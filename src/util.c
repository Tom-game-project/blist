#include <stdio.h>
#include "blist.h"

/// @brief test function
/// @param l 
void show_list_pointer(t_node *l)
{
    t_node *inode;
    int counter;

    if (l == NULL)
    {
        printf("(empty)\n");
        return ;
    }
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

void show_list_str(t_node *l) {
    t_node *inode;
    int counter;

    if (l == NULL)
    {
        printf("(empty)\n");
        return ;
    }
    inode = l;
    counter = 0;
    while (1)
    {
        printf("%d %s\n", counter, (char *) inode->data);
        inode = inode->back_node;
        counter++;
        if (inode == NULL)
            break;
    }
}

void show_list_int(t_node *l) {
    t_node *inode;
    int counter;
    int *int_tmp;

    if (l == NULL)
    {
        printf("(empty)\n");
        return ;
    }
    inode = l;
    counter = 0;
    while (1)
    {
        int_tmp = (int *) inode->data;
        printf("%d %d\n", counter, int_tmp[0]);
        inode = inode->back_node;
        counter++;
        if (inode == NULL)
            break;
    }
}
