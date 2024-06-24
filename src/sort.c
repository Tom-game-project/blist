
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
    bool    flag;

    lst_tmp1 = NULL;
    lst_tmp2 = NULL;
    while (true)
    {
        if (lst_tmp1 == NULL)
            lst_tmp1 = pop(lst1);
        if (lst_tmp2 == NULL)
            lst_tmp2 = pop(lst2);
        printf("lst 1 %p lst2 %p\n",lst_tmp1,lst_tmp2);
        if (lst_tmp1 == NULL && lst_tmp2 != NULL)
            flag = 0;
        else if (lst_tmp1 != NULL && lst_tmp2 == NULL)
            flag = 1;
        else if (lst_tmp1 == NULL && lst_tmp2 == NULL)
            break;
        else
            flag = lt(lst_tmp1->data, lst_tmp2->data);
        if (flag)
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
