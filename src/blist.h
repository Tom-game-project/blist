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
t_node *pop(t_node **lst);
t_node *minsort(t_node **lst1,t_node **lst2,int (*lt)(void *,void *));

// util functions
void    show_list_pointer(t_node *l);
void    show_list_str(t_node *l);
void    show_list_int(t_node *l);

void __divi(t_node **lst);

#endif