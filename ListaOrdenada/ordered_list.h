#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

struct node typedef node;
struct list typedef list;

list * create_list();

void insert_list(list* l, int value);

void print_list(list* l);

void print_list_rec(list* l);

void print_list_rev(list* l);

int is_list_empty(list* l);

node* find_node(list* l, int value);

int find_node_pos(list* l, int value);

void remove_node(list* l, int value);

void remove_node_rec(list* l, int value);

void free_list(list* l);

int compare_lists(list* l1, list* l2);

#endif // ORDERED_LIST_H

