#include "../src/blist.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *a = "hello";
    char *b = "world";
    t_node *lst;

    lst = NULL;
    push(&lst,init_node(a));
    push(&lst,init_node(b));
    push(&lst,init_node(b));

    show_list_str(lst);

    printf("length %d\n", len(&lst));
    t_node *elem;
    elem = pop(&lst);
    while (elem != NULL)
    {
        printf("%p\n", elem->data);
        elem = pop(&lst);
    }
    return (0);
}