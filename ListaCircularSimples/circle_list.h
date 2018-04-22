
#ifndef LIST_H
#define LIST_H

struct node typedef node;
struct list typedef list;

list * create_list();

void insert_list(list* l, int value);

void print_list(list* l);

void print_list_rec(list* l);

int is_list_empty(list* l);

node* find_node(list* l, int value);

int find_node_pos(list* l, int value);

void remove_node(list* l, int value);

void remove_node_rec(list* l, int value);

void free_list(list* l);

#endif // LIST_H
