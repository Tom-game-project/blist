#include "blist.h"
#include <stdlib.h>
#include <stdio.h>


/// @brief リストの要素をすべて開放するための関数です。
///        delは`data`を開放するための関数ポインタ。
/// @param l 
/// @param del 
/// @return 
int delete_all_fn(t_node **l,void (*del)(void *)){//
    t_node *tmp = pop(l);

    while (tmp != NULL){
        del(tmp->data);
        free(tmp);
        tmp = pop(l);
    }
    return 0;
}


/// @brief `t_node`内の`data`にmallocを使用している場合
///        この関数を使うとダングリングポインタを作ってしまいます。
/// @param l 
/// @return 
int delete_all(t_node **l){
    t_node *tmp = pop(l);

    while (tmp != NULL){
        free(tmp);
        tmp = pop(l);
    }
    return 0;
}
