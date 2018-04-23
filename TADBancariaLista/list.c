#include "list.h"
#include <stdio.h>

#include "conta_bancaria.h"
#include "conta_fidelidade.h"
#include "conta_poupanca.h"


list * create_list(){
    list* l = (list*) malloc(sizeof(list));
    l->first = nullptr;
    l->last = nullptr;
    l->length = 0;
    return l;
}

int get_account_number(node* n){
    switch(n->type){
    case CB:
        return ((struct conta_bancaria*)n->account)->numero;
    case CP:
        return ((struct conta_poupanca*)n->account)->numero;
    case CF:
        return ((struct conta_fidelidade*)n->account)->numero;
    }
}

float get_account_saldo(node* n){
    float value = -999999;
    switch(n->type){
    case CB:
        value = ((struct conta_bancaria*)n->account)->saldo;
    case CP:
        value = ((struct conta_poupanca*)n->account)->saldo;
    case CF:
        value = ((struct conta_fidelidade*)n->account)->saldo;
    }
    return value;
}

void insert_list(list* l, void* account, int type){
    node *new_node = (node*) malloc(sizeof(node));
    new_node->account = account;
    new_node->type = type;

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


void print_list_account_and_balance(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        printf("Numero da conta: %d\n", get_account_number(iterator));
        printf("Saldo: %f\n\n", get_account_saldo(iterator));
        iterator = iterator->next;
    }
}

void print_list(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        printf( iterator == l->last ? "%d\n" : "%d->", get_account_number(iterator));
        iterator = iterator->next;
    }
}

void print_list_rec_intern(list* l, node* current){
    if(current == nullptr){
        return;
    }
    printf( current == l->last ? "%d\n" : "%d->", get_account_number(current));
    current = current->next;
    print_list_rec_intern(l, current);
}

void print_list_rec(list* l){
    print_list_rec_intern(l, l->first);
}

void print_list_rev(list* l){
    node* iterator = l->last;
    while(iterator != nullptr){
        printf( iterator == l->first ? "%d\n" : "%d->", get_account_number(iterator));
        iterator = iterator->back;
    }
}

int is_list_empty(list* l){
    return l->first == nullptr ? 1 : 0;
}

node* find_node(list* l, int number){
    node* iterator = l->first;
    while(iterator != nullptr){
        if(get_account_number(iterator) == number)
            return iterator;
        iterator = iterator->next;
    }
    return nullptr;
}

int find_node_pos(list* l, int number){
    node* iterator = l->first;
    int pos = 0;
    while(iterator != nullptr){
        if(get_account_number(iterator) == number)
            return pos;
        pos++;
        iterator = iterator->next;
    }
    return -1;
}

node* find_node_rec_intern(list* l, node* current, int number){
    if(current == nullptr){
        return;
    }
    if(get_account_number(current) == number)
        return current;

    current = current->next;
    return find_node_rec_intern(l, current, number);
}

node* find_node_rec(list* l, int number){
    return find_node_rec_intern(l, l->first, number);
}

void remove_node(list* l, int number){
    node* n = find_node(l, number);

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

void free_list(list* l){
    node* iterator = l->first;
    while(iterator != nullptr){
        node* aux = iterator;
        iterator = iterator->next;
        free(aux->account);
        free(aux);
    }
    free(l);
}
