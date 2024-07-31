
#include "blist.h"
#include <stdbool.h>
#include <stdlib.h>

// test

#include <stdio.h>

// t_node **sorted(t_node **head,int (*lt)(void *,void *)) {
//     t_node *new_head;
// }

t_node *minsort(t_node **lst1,t_node **lst2,int (*lt)(void *,void *)) {
    t_node *lst_tmp1;
    t_node *lst_tmp2;
    t_node *rlst;

    lst_tmp1 = NULL;
    lst_tmp2 = NULL;
    while (true)
    {
        if (lst_tmp1 == NULL)
            lst_tmp1 = pop(lst1);
        if (lst_tmp2 == NULL)
            lst_tmp2 = pop(lst2);
        if (lst_tmp1 == NULL && lst_tmp2 == NULL)
            break;
        if ((!((lst_tmp1 != NULL) ^ (lst_tmp2 != NULL)) && lt(lst_tmp1->data, lst_tmp2->data)))
        {
            push(&rlst,lst_tmp1);
            lst_tmp1 = NULL;
        } else {
            push(&rlst,lst_tmp2);
            lst_tmp2 = NULL;
        }
    }
    return (rlst);
}

/// unsafe function
void __divi(t_node **lst) {
    t_node *pre_tmp;
    t_node *back_tmp;
    t_node *c_tmp;    // current

    c_tmp = *lst;
    pre_tmp = NULL;
    while (c_tmp != NULL) {
        back_tmp = c_tmp->back_node;
        if (back_tmp!=NULL)
            c_tmp->back_node = back_tmp -> back_node;
        c_tmp->pre_node = pre_tmp;
        c_tmp = back_tmp;
        if (c_tmp != NULL)
            pre_tmp = c_tmp->pre_node->pre_node;
    }
}

