#ifndef LIST_H
#define LIST_H

typedef struct node{
    struct node* next;
    struct node* back;
    void* item;
}node;

typedef struct list{
    node* first;
    node* last;
    int length;
}list;

typedef int func(void* value, void* compare_to);

list * create_list();

void insert_list(list* l, void* item);

void print_list(list* l);

void print_list_rec(list* l);

void print_list_rev(list* l);

int is_list_empty(list* l);

node* find_node(list* l, func* comparison, void* compare_to);

int find_node_pos(list* l, func* comparison, void* compare_to);

void remove_node(list* l, node* n);

void free_list(list* l);

#endif // LIST_H
