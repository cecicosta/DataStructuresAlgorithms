#include "list.h"
#include <stdio.h>

#define nullptr NULL

list * create_list(){
    list* l = (list*) malloc(sizeof(list));
    l->first = nullptr;
    l->last = nullptr;
    l->length = 0;
    return l;
}

void insert_list(list* l, void* item){
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = item;
    new_node->back = nullptr;
    new_node->next = nullptr;

    if(l->last == nullptr)
        l->last = new_node;

    node* aux = l->first;
    l->first = new_node;
    new_node->next = aux;

    if(aux != nullptr)
        aux->back = new_node;

    l->length++;
}

int is_list_empty(list* l){
    return l->first == nullptr ? 1 : 0;
}

node* find_node(list* l, func* comparison, void* compare_to){
    node* iterator = l->first;
    while(iterator != nullptr){
        if(comparison(iterator, compare_to) == 1)
            return iterator;
        iterator = iterator->next;
    }
    return nullptr;
}

int find_node_pos(list* l, func* comparison, void* compare_to){
    node* iterator = l->first;
    int pos = 0;
    while(iterator != nullptr){
        if(comparison(iterator, compare_to) == 1)
            return pos;
        pos++;
        iterator = iterator->next;
    }
    return -1;
}


void remove_node(list* l, node* n){
    int removed = 0;

    if(n->next == nullptr){
        l->last = n->back;
        l->last->next = nullptr;
        removed = 1;
    }
    if(n->back == nullptr){
        l->first = n->next;
        l->first->back = nullptr;
        removed = 1;
    }
    if(n->next != nullptr && n->back != nullptr){
        node* aux_back = n->back;
        node* aux_next = n->next;
        aux_back->next = aux_next;
        aux_next->back = aux_back;
        removed = 1;
    }

    if(removed == 1){
        l->length--;
        free(n);
    }
}

void free_list(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        node* aux = iterator;
        iterator = iterator->next;
        free(aux);
    }
    free(l);
}
