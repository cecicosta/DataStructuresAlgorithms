#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arvore.h"

int main()
{
    int valor, cont=0;
    arvore *arv;
    arv=NULL;

	int menu=1;
	while(menu != 7)
    {
		system("cls");
        printf("ARVORE BINARIA DE BUSCA\n\n\n0)Inserir\n1)Ordem\n2)Pre ordem\n3)Pos ordem\n4)Profundidade\n5)buscar\n6)remover\n7)Sair\n");
        scanf("%d",&menu);
        getchar();
		system("cls");
        switch(menu)
        {
			case 0:
				printf("Entre com o valor a ser inserir: ");
				scanf("%d", &valor);
				getchar();
				incluir(&arv, valor);
				continue;
            case 1:printa_arv(arv);getchar(); continue;
            case 2:perc_pre_ord(arv);getchar(); continue;
            case 3:perc_pos_ord(arv);getchar(); continue;
            case 4:
                printf("Altura da arvore: %d\n", profundidade(arv,0,0));
                getchar();
				continue;
            case 5:
                printf("Entre com o valor a ser buscado: ");
                scanf("%d", &valor);
                if(buscar(arv,valor))
                    printf("O valor existe na arvore!\n");
                else
                    printf("Valor nao encontrado\n");
				system("pause");
				continue;
			case 6:
				remover(arv, valor);
				continue;
        }

    }

    free_arv(arv);
	return 1;
}
