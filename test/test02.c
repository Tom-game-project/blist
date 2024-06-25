
#include <stdlib.h>
#include "../src/blist.h"
#include <stdio.h>

int main(void)
{
    t_node *lst;
    t_node *odd;
    t_node *even;

    lst = NULL;
    push(&lst, init_node("0"));
    push(&lst, init_node("1"));
    push(&lst, init_node("2"));
    push(&lst, init_node("3"));
    push(&lst, init_node("4"));
    push(&lst, init_node("5"));
    push(&lst, init_node("6"));

    show_list_str(lst);
    even = lst;
    odd = lst->back_node;
    __divi(&lst);
    printf("even\n");
    show_list_str(even);
    printf("odd\n");
    show_list_str(odd);
}