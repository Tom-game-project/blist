#include <stdlib.h>
#include "blist.h"

/// @brief 最も後ろの要素を取得します
/// @param l 
/// @return 
t_node *get_back(t_node *l) {
    t_node *inode;

    inode = l;
    if (inode == NULL)
        return (NULL);
    while (inode -> back_node != NULL) {
        inode = inode -> back_node;
    }
    return (inode);
}

/// @brief lstはリスト、nは追加したい要素
/// @param lst
/// @param n 
/// @return 
int push(t_node **lst, t_node *n) {
    t_node *tmp;

    tmp = get_back(*lst);
    if (tmp == NULL) {
        *lst = n;
        n->pre_node = NULL;
        return (0);
    }
    tmp -> back_node = n;
    n -> pre_node = tmp;
    n->back_node = NULL;
    return (0);
}

