
#include "blist.h"
#include <stdbool.h>
#include <stdlib.h>

// test

#include <stdio.h>

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



t_node *merge(t_node **l0, t_node**l1,int comp(void *,void *)){
    t_node *rl = NULL;
    t_node *tmp0 = pop(l0);
    t_node *tmp1 = pop(l1);

    while (!(tmp0 == NULL && tmp1 == NULL)){
        if (tmp0 == NULL)
        {
        }
        else if (tmp1 == NULL || comp(tmp0->data, tmp1->data))
        {
            push(&rl,tmp0);
            tmp0 = pop(l0);
            continue;
        }
        push(&rl,tmp1);
        tmp1 = pop(l1);
    }
    return rl;
}

/// @brief 返り値は真ん中から、、
/// @param l 
/// @param length 
/// @return 
t_node *half_slice(t_node **l,unsigned int length){
    unsigned int i = 0;
    unsigned int halfpoint = length / 2;
    t_node *tmp = *l;
    t_node *rtmp;

    while (i < halfpoint - 1){
        tmp = tmp->back_node;
        i += 1;
    }
    rtmp = tmp->back_node;
    tmp->back_node->pre_node = NULL;
    tmp->back_node = NULL;
    return rtmp;
}

t_node *merge_sort(t_node *l,int comp(void *,void *)){
    unsigned int lst_length = len(&l);
    t_node *tmp0;
    t_node *tmp1;

    if (lst_length == 0)
        return NULL;
    else if (lst_length == 1)
        return merge(&l,NULL,comp);
    else if (lst_length == 2){
        tmp0 = pop(&l);
        tmp1 = pop(&l);
        return merge(&tmp0, &tmp1, comp);
    }else{
        tmp0 = half_slice(&l,lst_length);
        show_list_int(l);
        show_list_int(tmp0);
        tmp0 = merge_sort(tmp0,comp);
        tmp1 = merge_sort(l,comp);
        return merge( &tmp0, &tmp1,comp);
    }
}

