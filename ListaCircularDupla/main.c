#include <stdio.h>
#include <stdlib.h>

#include "circle_list.h"
int main()
{

    list * l = NULL;
    while(1){
        int operation = 0;
        printf("Operations: \n create list (0) \n insert element (1) \n print values (2) \n print values rec (3) \n \n is empty? (4) \n remove value (5) \n remove value rec (6) \n find value (7) \n free list (8) \n\n");
        scanf("%d", &operation);

        int entry = 0;
        int entry_aux =0;

        if(operation != 0 && l == NULL){
            printf("list was not initialized.\n\n");
            continue;
        }

        switch(operation){
            case 0:
                l = create_list();
                continue;
            case 1:
                printf("value to insert: ");
                scanf("%d", &entry);
                insert_list(l, entry);
                continue;
            case 2:
                print_list(l);
                continue;
            case 3:
                print_list_rec(l);
                continue;
            case 4:
                if(is_list_empty(l))
                    printf("List empty\n");
                else
                    printf("List not empty\n");
                continue;
            case 5:
                printf("value to remove: ");
                scanf("%d", &entry);
                remove_node(l, entry);
                continue;
            case 6:
                printf("value to remove: ");
                scanf("%d", &entry);
                remove_node_rec(l, entry);
                continue;
            case 7:
                printf("value to find: ");
                scanf("%d", &entry);
                printf("Value found at position %d in list \n (-1 equals 'not found')\n", find_node_pos(l, entry));
                continue;
            case 8:
                prin
                return 0;

            default:
                continue;
        }
    }

    return 0;
}
