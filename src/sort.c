
#include "src/blist.h"
#include <stdbool.h>
#include <stdlib.h>

// t_node **sorted(t_node **head,int (*lt)(void *,void *)) {
//     t_node *new_head;

// }

t_node *minsort(t_node **lst1,t_node **lst2,int (*lt)(void *,void *)) {
    t_node *lst_tmp1;
    t_node *lst_tmp2;
    t_node *rlst;

    lst_tmp1 = NULL;
    lst_tmp2 = NULL;
    while (!(*lst1 == NULL && *lst2 == NULL))
    {
        if (lst_tmp1 == NULL)
            lst_tmp1 = pop(lst1);
        if (lst_tmp2 == NULL)
            lst_tmp2 = pop(lst2);
        lst_tmp2 = pop(lst2);
        if (lt(lst_tmp1->data, lst_tmp2->data))
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