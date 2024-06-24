#ifndef BLIST
#define BLIST

typedef struct s_node{
    void *data;
    struct s_node *pre_node;
    struct s_node *back_node;
} t_node;


t_node *init_node(void * a);
t_node *get_back(t_node *l);
int     push(t_node **l, t_node *n);
void    show_list(t_node *l);
t_node *pop(t_node **lst);

#endif