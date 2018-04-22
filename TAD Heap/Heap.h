#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

//Implementação de um TAD Heap

struct _heap {
    int max; /* tamanho maximo do heap */
    int pos; /* proxima posicao disponivel no vetor */
    int * priority; /* vetor das prioridades */
};

typedef struct _heap Heap;

Heap * create_heap(int max);

void insert_value(Heap *heap, int priority);

int remove_top(Heap *heap);

int remove_value(Heap *heap, int value);

int find_value(Heap *heap, int value);

void print_heap(Heap *heap);

void change_value(Heap *heap, int pos, int value);

Heap* free_heap(Heap *heap);

#endif // HEAP_H_INCLUDED
