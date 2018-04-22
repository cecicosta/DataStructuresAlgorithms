
#include "ordered_list.h"
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
    new_node->back = nullptr;
    new_node->next = nullptr;

    //Add the first element
    if(l->first == nullptr){
        l->first = l->last = new_node;
        return;
    }

    //Add to the beginning
    if(l->first->value > value){
        new_node->next = l->first;
        l->first->back = new_node;
        l->first = new_node;
        return;
    }

    node* current = l->first;
    while(current != nullptr){
        if(value < current->value){
            node* previous = current->back;
            new_node->next = current;
            new_node->back = previous;

            current->back = new_node;
            previous->next = new_node;
            return;
        }
        current = current->next;
    }

    //Add to the end
    new_node->back = l->last;
    l->last->next = new_node;
    l->last = new_node;
}

void print_list(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        printf( iterator == l->last ? "%d\n" : "%d->", iterator->value );
        iterator = iterator->next;
    }
}

void print_list_rec_intern(list* l, node* current){
    if(current == nullptr){
        return;
    }
    printf( current == l->last ? "%d\n" : "%d->", current->value );
    current = current->next;
    print_list_rec_intern(l, current);
}

void print_list_rec(list* l){
    print_list_rec_intern(l, l->first);
}

void print_list_rev(list* l){
    node* iterator = l->last;
    while(iterator != nullptr){
        printf( iterator == l->first ? "%d\n" : "%d->", iterator->value );
        iterator = iterator->back;
    }
}

int is_list_empty(list* l){
    return l->first == nullptr ? 1 : 0;
}

node* find_node(list* l, int value){
    node* iterator = l->first;
    while(iterator != nullptr){
        if(iterator->value == value)
            return iterator;
        iterator = iterator->next;
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
        iterator = iterator->next;
    }
    return -1;
}

node* find_node_rec_intern(list* l, node* current, int value){
    if(current == nullptr){
        return;
    }
    if(current->value == value)
        return current;

    current = current->next;
    return find_node_rec_intern(l, current, value);
}

node* find_node_rec(list* l, int value){
    return find_node_rec_intern(l, l->first, value);
}

void remove_node(list* l, int value){
    node* n = find_node(l, value);

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

void remove_node_rec(list* l, int value){
    node* n = find_node_rec(l, value);

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

int compare_lists(list* l1, list* l2){
    node* iterator1 = l1->first;
    node* iterator2 = l2->first;

    while(iterator1 != nullptr && iterator2 != nullptr){
        if(iterator1->value != iterator2->value)
            return 0;
        iterator1 = iterator1->next;
        iterator2 = iterator2->next;
        if(iterator1 == nullptr && iterator2 != nullptr)
        if(iterator1->value != iterator2->value)
            return 0;
        if(iterator1 != nullptr && iterator2 == nullptr)
        if(iterator1->value != iterator2->value)
            return 0;
    }
    return 1;
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
