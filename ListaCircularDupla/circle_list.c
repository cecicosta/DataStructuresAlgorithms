#include "circle_list.h"
#include <stdio.h>

#define nullptr NULL

struct node{
    node* next;
    node* back;
    int value;
};

struct list{
    node* first;
    node* last;
    int length;
};

list * create_list(){
    list* l = (list*) malloc(sizeof(list));
    l->first = nullptr;
    l->last = nullptr;
    l->length = 0;
    return l;
}

void insert_list(list* l, int value){
    node *new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    new_node->next = nullptr;
    new_node->back = nullptr;

    if(l->last == nullptr){
        l->first = new_node;
        l->last = new_node;
    }

    new_node->back = l->last;
    l->last->next = new_node;
    l->last = new_node;

    new_node->next = l->first;
    l->first->back = new_node;

    l->length++;
}

void print_list(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        printf( iterator == l->last ? "%d\n" : "%d->", iterator->value );
        iterator = iterator->next == l->first? nullptr : iterator->next;
    }
}

void print_list_rec_intern(list* l, node* current){
    if(current == nullptr){
        return;
    }

    printf( current == l->last ? "%d\n" : "%d->", current->value );
    current = current->next == l->first ? nullptr : current->next;
    print_list_rec_intern(l, current);
}

void print_list_rec(list* l){
    print_list_rec_intern(l, l->first);
}

int is_list_empty(list* l){
    return l->first == nullptr ? 1 : 0;
}

node* find_node(list* l, int value){
    node* iterator = l->first;
    while(iterator != nullptr){
        if(iterator->value == value)
            return iterator;
        iterator = iterator->next == l->first? nullptr : iterator->next;
    }
    return nullptr;
}

int find_node_pos(list* l, int value){
    node* iterator = l->first;
    int pos = 0;
    while(iterator != nullptr){
        if(iterator->value == value)
            return pos;
        pos++;
        iterator = iterator->next == l->first? nullptr : iterator->next;
    }
    return -1;
}

int find_node_rec_intern(list* l, int value, node** current, node** previous){
    if(*current == nullptr){
        return 0;
    }
    if((*current)->value == value){
        return 1;
    }

    *previous = *current;
    *current = (*current)->next == l->first ? nullptr : (*current)->next;
    return find_node_rec_intern(l, value, current, previous);
}

int find_node_rec(list* l, int value, node** current, node** previous){
    *current = l->first;
    return find_node_rec_intern(l, value, current, previous);
}

void remove_node(list* l, int value){
    node* current = l->first;
    node* previous = nullptr;
    while(current != nullptr){
        if(current->value == value)
            break;
        previous = current;
        current = current->next == l->first? nullptr : current->next;
    }
    if(current == nullptr)
        return;

    if(l->first == l->last){
        l->first = l->last = nullptr;
    }else if(current == l->first){
        l->first = current->next;
        l->last->next = l->first;
        l->first->back = l->last;
    }else if(current == l->last){
        l->last = previous;
        l->last->next = l->first;
        l->first->back = l->last;
    }else {
        previous->next = current->next;
        current->next->back = previous;
    }

    l->length--;
    free(current);
}

void remove_node_rec(list* l, int value){
    node* current = nullptr;
    node* previous = nullptr;

    if(find_node_rec(l, value, &current, &previous) == 0)
        return;

    if(l->first == l->last){
        l->first = l->last = nullptr;
    }else if(current == l->first){
        l->first = current->next;
        l->last->next = l->first;
        l->first->back = l->last;
    }else if(current == l->last){
        l->last = previous;
        l->last->next = l->first;
        l->first->back = l->last;
    }else {
        previous->next = current->next;
        current->next->back = previous;
    }

    l->length--;
    free(current);
}

void free_list(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        node* aux = iterator;
        iterator = iterator->next == l->first? nullptr : iterator->next;
        free(aux);
    }
    free(l);
}
