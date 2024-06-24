#include "../src/blist.h"
#include <stdlib.h>
#include <stdio.h>

int lt(int *a,int *b){
    return (a < b);
}

int main(void)
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    t_node *lst1;
    t_node *lst2;

    lst1 = NULL;
    lst2 = NULL;
    push(&lst1, init_node(&a));
    push(&lst1, init_node(&b));
    push(&lst1, init_node(&c));
    push(&lst2, init_node(&d));
    push(&lst2, init_node(&e));
    push(&lst2, init_node(&f));

    printf("lst 1\n");
    show_list_int(lst1);
    printf("lst 2\n");
    show_list_int(lst2);
    //t_node *n_lst = minsort(lst1, lst2, lt);
    return (0);
}