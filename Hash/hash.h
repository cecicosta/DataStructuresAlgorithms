#ifndef HASH_H
#define HASH_H

#include "list.h"
#define SIZE_HASH 20000

typedef struct no_hash {
    int value;
} no_hash;

typedef struct Hash {
    list lst[SIZE_HASH];   
} Hash;

void hash_add(Hash* h, int value);

no_hash *hash_get(Hash* h,int value);

int hash_exists(Hash* h, int value);

void hash_free(Hash* h);

#endif
