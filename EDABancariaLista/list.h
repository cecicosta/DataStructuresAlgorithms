#ifndef LIST_H
#define LIST_H

#define nullptr NULL
#define CB 0
#define CP 1
#define CF 2

struct node{
    struct node* next;
    struct node* back;
    void* account;
    int type;
}typedef node;

struct list{
    node* first;
    node* last;
    int length;
} typedef list;

list * create_list();

void insert_list(list* l,  void* account, int type);

void print_list_account_and_balance(list* l);

void print_list(list* l);

void print_list_rec(list* l);

void print_list_rev(list* l);

int is_list_empty(list* l);

node* find_node(list* l, int number);

int find_node_pos(list* l, int number);

void remove_node(list* l, int number);

void remove_node_rec(list* l, int number);

void free_list(list* l);

#endif // LIST_H
