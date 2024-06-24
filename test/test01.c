#include "../src/blist.h"
#include <stdlib.h>
#include <stdio.h>

int lt(void *a,void *b) {
    int tmpa ;
    int tmpb ;

    tmpa = ((int *)a)[0];
    tmpb = ((int *)b)[0];
    return (tmpa < tmpb);
}

int main(void)
{
    int a = 4;
    int b = 6;
    int c = 3;
    int d = 7;
    // int e = 5;
    // int f = 6;
    t_node *lst1;
    t_node *lst2;

    lst1 = NULL;
    lst2 = NULL;
    push(&lst1, init_node(&a));
    push(&lst1, init_node(&b));
    push(&lst2, init_node(&c));
    push(&lst2, init_node(&d));

    printf("lst 1\n");
    show_list_int(lst1);
    printf("lst 2\n");
    show_list_int(lst2);
    t_node *n_lst = minsort(&lst1, &lst2, lt);
    printf("n_lst\n");
    show_list_int(n_lst);
    printf("*lst1 %p\n", lst1);
    printf("*lst2 %p\n", lst2);
    return (0);
}