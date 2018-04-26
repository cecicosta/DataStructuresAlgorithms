#include <stdio.h>

#include "particao.h"


void print_list(list* l){
    node* iterator = l->first;
    while(iterator != NULL){
        printf("{%d}->", ((particao_node*)iterator->item)->item);
        printf( iterator == l->last ? "R{%d}\n" : "R{%d},", particao_find(((particao_node*)iterator->item))->item);
        iterator = iterator->next;
    }
}

int compare_sets(node* candidate, void* reference){
    if(((particao_node*)candidate->item)->item == *((int*)reference)){
        return 1;
    }
    return 0;
}

int main(){
    //CREATE SET
    srand(time(NULL));
    int amount = rand()%15;

    list* set = create_list();
    int i = 0;
    for(i=0; i<amount; i++){
        insert_list(set, particao_make_set(rand()%100));
    }

    printf("Data Structure for the Sets alread created!\n");
    print_list(set);
    printf("\n\n");

    //APP FUNCTIONS
    while(1){
        int operation = 0;
        printf("Operations:\n");
        printf(" Make Union (0)\n Find (1)\n Print Set (2)\n");
        printf(" Same Set? (3)\n Free (4)\n\n");
        scanf("%d", &operation);

        int entry = 0;
        node* first;
        node* second;
        switch(operation){
        case 0:
            printf("Select first set representative: ");
            scanf("%d", &entry);
            first = find_node(set, &compare_sets, &entry);
            particao_node* first_set = particao_find(first->item);

            printf("Select second set representative: ");
            scanf("%d", &entry);
            second = find_node(set, &compare_sets, &entry);
            particao_node* second_set = particao_find(second->item);

            particao_union(first_set, second_set);
            print_list(set);
            continue;
        case 1:
            printf("Value to find the set representative: ");
            scanf("%d", &entry);
            first = find_node(set, &compare_sets, &entry);
            particao_node* representative = particao_find(first->item);
            printf("Set representative: %d\n", representative->item);
            continue;
        case 2:
           print_list(set);
           continue;
        case 3:
            printf("Select first item: ");
            scanf("%d", &entry);
            node* first = find_node(set, &compare_sets, &entry);

            printf("Select second item: ");
            scanf("%d", &entry);
            node* second = find_node(set, &compare_sets, &entry);

            if(same_particao(first->item, second->item) == 1)
            printf("the selected itens are from the same set\n");
            else
            printf("the selected itens are NOT from the same set\n");
            continue;
        case 4:
            particao_free(set);
            return 0;
        default:
            continue;
        }
    }

    return 0;
}
