#include <stdio.h>
#include "particao.h"
#include "list.h"

#define nullptr NULL

particao_node* particao_make_set(int item){
    particao_node* node = (particao_node*) malloc(sizeof(particao_node));
    node->parent = nullptr;
    node->item = item;
    node->rank = 0;
    return node;
}

particao_node* particao_union(particao_node* first, particao_node* second){
    if(first->rank > second->rank){
        second->parent = first;
		first->rank++;
		return first;
    }else if( second->rank > first->rank ){
        first->parent = second;
    }else{
        first->parent = second;
        first->rank++;
    }
    return second;
}

particao_node* particao_find(particao_node* node){
    particao_node* iterator = node;
    particao_node* previous = nullptr;
    while(iterator != nullptr){
        previous = iterator;
        iterator = iterator->parent;
    }

    return previous;
}

int same_particao(particao_node* one, particao_node* two){
    particao_node* represent_one = particao_find(one);
    particao_node* represent_two = particao_find(two);

    return represent_one == represent_two ? 1 : 0;
}

void particao_free(list* set){
    node* iterator = set->first;
    while(iterator != nullptr){
        free(iterator->item);
        iterator = iterator->next;
    }
}
