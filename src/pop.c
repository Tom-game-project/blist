#include <stdlib.h>
#include "blist.h"

/// @brief lstはリスト、リストの先頭の要素を取得して削除します
/// @param lst 
/// @return 
t_node *pop(t_node **lst)
{
    t_node *r_elem;

    if (*lst == NULL)
        return (NULL);
    r_elem = *lst;
    if (r_elem -> back_node != NULL){
        r_elem -> back_node -> pre_node = NULL;
        *lst = r_elem -> back_node;
    }
    else
        *lst = NULL;
    r_elem -> back_node = NULL;
    return (r_elem);
}
