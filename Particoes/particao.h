#ifndef PARTICAO_H
#define PARTICAO_H

#include "list.h"

typedef struct particao_node{
    int item;
    int rank;
    struct particao_node* parent;
} particao_node;

particao_node* particao_make_set(int item);

particao_node* particao_union(particao_node* first, particao_node* second);

particao_node* particao_find(particao_node* node);

int same_particao(particao_node* one, particao_node* two);

void particao_free(list* set);

#endif //PARTICAO_H
