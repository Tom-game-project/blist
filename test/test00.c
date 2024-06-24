#include "../src/blist.h"
#include <stdlib.h>

int main(void)
{
    char *a = "hello";
    char *b = "world";
    t_node *list;

    list = NULL;
    push(&list,init_node(a));
    push(&list,init_node(b));
    push(&list,init_node(b));

    show_list(list);
    return (0);
}