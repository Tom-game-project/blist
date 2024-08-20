#include <stdlib.h>
#include "../src/blist.h"
#include <stdio.h>


int lt(void *a,void *b) {
    int tmpa ;
    int tmpb ;

    tmpa = ((int *)a)[0];
    tmpb = ((int *)b)[0];
    return (tmpa < tmpb);
}

int main(){
    t_node *n = NULL;
    t_node *l0 = NULL;

    int a = 6;
    int b = 4;
    int c = 3;
    int d = 7;
    int e = 5;
    int f = 1;
    int g = 2;
    // int h = 7;
    // int i = 7;

    push(&l0, init_node(&a));
    push(&l0, init_node(&b));
    push(&l0, init_node(&c));
    push(&l0, init_node(&d));
    push(&l0, init_node(&e));
    push(&l0, init_node(&f));
    push(&l0, init_node(&g));

    n = merge_sort(l0, lt);
    show_list_int(n);
    // delete_all(&n);
    return 0;
}