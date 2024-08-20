#include <stdlib.h>
#include "blist.h"

/// @brief リストの先頭の要素を取得して削除します。`t_node`内のデータは自分で解放する必要があります。
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
