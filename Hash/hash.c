#include "hash.h"
#include <stdio.h>

int comparison_hash_node(no_hash* iterate, void* value) {
	if (iterate->value == *((int*)value))
		return 1;
	return 0;
}

int hash_func(int value) {
	return value%SIZE_HASH;
}

no_hash* create_node_hash(int value) {
	no_hash* node = (no_hash*)malloc(sizeof(no_hash));
	node->value = value;
	return node;
}

void hash_add(Hash *h, int value) {
    insert_list(&(h->lst[hash_func(value)]), create_node_hash(value));
}

no_hash* hash_get(Hash* h, int value) {
    int ind = hash_func(value);

	if (h->lst[ind].length == 0)
		return NULL;

    return find_node(&h->lst, &comparison_hash_node, &value);
}

int hash_exists(Hash* h, int value) {
    return hash_get(h, value) == NULL ? 0 : 1;
}

void hash_free(Hash* h) {
    for( int i=0; i<SIZE_HASH; i++ ) {
		for (int j = 0; i < h->lst->length; j++) {
			free(h->lst[i].first->item);
			remove_node(&(h->lst[i]), h->lst->first);
		}
    }
}


