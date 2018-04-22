#include "Heap.h"
#include <stdio.h>

Heap * create_heap(int max) {
    Heap * heap = (Heap * ) malloc(sizeof(Heap));
    heap->max = max;
    heap->pos = 0;
    heap->priority = (int * ) malloc(max * sizeof(int));

    return heap;
}

void insert_value(Heap * heap, int priority) {
    if(priority < 0)
        return;

    if (heap->pos <= heap->max - 1) {
        heap->priority[heap->pos] = priority;
        fix_above(heap, heap->pos);
        heap->pos++;
    } else
        printf("Failed to insert. Heap is full\n");
}

void swap(int a, int b, int * v) {
    int f = v[a];
    v[a] = v[b];
    v[b] = f;
}

void fix_above(Heap * heap, int pos) {
    while (pos > 0) {
        //Calculate the parent index
        int parent = (pos - 1) / 2;
        //We implemented a max heap.
        if (heap->priority[parent] < heap->priority[pos])
            swap(pos, parent, heap->priority);
        else
            break;
        pos = parent;
    }
}

int remove_top(Heap * heap) {
    if (heap->pos > 0) {
        int root = heap->priority[0];
        heap->priority[0] = heap->priority[heap->pos - 1];
        heap->pos--;
        fix_below(heap, 0);

        return root;
    } else {
        printf("Cannot remove element. Heap is empty");
        return -1;
    }
}

int remove_value(Heap * heap, int value) {
    int at = find_value(heap, value);

    if (heap->pos > at) {
        int root = heap->priority[at];
        heap->priority[at] = heap->priority[heap->pos - 1];
        heap->pos--;
        fix_below(heap, at);

        return root;
    } else {
        printf("Cannot remove element. Heap is empty");
        return -1;
    }
}

void fix_below(Heap * heap, int parent) {

    while (2 * parent + 1 < heap->pos) {
        //Calculate the children indexes
        int child_left = 2 * parent + 1;
        int child_right = 2 * parent + 2;

        int child;
        //In case there is no child right
        if (child_right >= heap->pos)
            child_right = child_left;

        if (heap->priority[child_left] > heap->priority[child_right]){
            child = child_left;
        } else
            child = child_right;

        if (heap->priority[parent] < heap->priority[child]){
            //It is a max heap.
            swap(parent, child, heap->priority);
        } else
            break;

        parent = child;
    }
}

int _find_value(Heap *heap, int value, int pos){
    if(heap->pos <= pos)
        return -1;

    if(heap->priority[pos] < value)
        return -1;

    if(heap->priority[pos] == value)
        return pos;

    if(_find_value(heap, value, 2 * pos + 1) != -1)
        return 2 * pos + 1;
    else if(_find_value(heap, value, 2 * pos + 2) != -1)
        return 2 * pos + 2;

    return -1;
}

int find_value(Heap *heap, int value){
    return _find_value(heap, value, 0);
}

void _print_heap(Heap *heap, int pos, int level){
    if(heap->pos <= pos)
        return;

    printf("Level: %d\n", level);
    printf("%d\n", heap->priority[pos]);
    _print_heap(heap, 2 * pos + 1,level+1);
    _print_heap(heap, 2 * pos + 2,level+1);
}

void print_heap(Heap *heap){
    _print_heap(heap, 0, 0);
}


void change_value(Heap *heap, int pos, int value){
    if(heap->pos <= pos)
        return;
    if(value < 0)
        return;

    if(heap->priority[pos] < value){
        heap->priority[pos] = value;
        fix_above(heap, pos);
    }else if(heap->priority[pos] > value){
        heap->priority[pos] = value;
        fix_below(heap, pos);
    }
}

Heap* free_heap(Heap *heap){
    if(heap == NULL)
        return;

    if(heap->priority == NULL)
        return;
    free(heap->priority);
    heap->priority = NULL;
    free(heap);
}
