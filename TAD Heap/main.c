#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main() {

    int max = 0;
    printf("How many elements to insert? \n");
    scanf("%d", &max);
    Heap *heap = create_heap(max);

    int method = 0;
    printf("Insert 1 to 100 random(1) / Insert Manual (2) \n");
    scanf("%d", &method);

    srand(time(NULL));

    int i;
    for(i=0; i<max; i++){
        if(method == 1){
            insert_value(heap, rand()%100);
        }else{
            int value = 0;
            scanf("%d", &value);
            insert_value(heap, value);
        }
    }

    while(1){
        int operation = 0;
        printf("Operations: print values (0) / remove value (1) / change value (2) / find value (3) / free heap and exit (4)\n");
        scanf("%d", &operation);

        int entry = 0;
        int entry_aux =0;

        switch(operation){
            case 0:
                print_heap(heap);
                continue;
            case 1:
                printf("value to remove: ");
                scanf("%d", &entry);
                remove_value(heap, entry);
                continue;
            case 2:
                printf("value to change from: ");
                scanf("%d", &entry);
                printf("value to change to: ");
                scanf("%d", &entry_aux);
                change_value(heap, find_value(heap, entry), entry_aux);
                continue;
            case 3:
                printf("value to find: ");
                scanf("%d", &entry);
                printf("Value found at: %d\n (-1 equals 'not found')\n", find_value(heap, entry));
                continue;
            case 4:
                free_heap(heap);
                return 0;
            default:
                continue;
        }
    }

    return 0;
}


