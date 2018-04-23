#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "conta_bancaria.h"
#include "conta_poupanca.h"
#include "conta_fidelidade.h"

float saldo_conta(node* n){
    float value = -999999;
    switch(n->type){
    case CB:
        value = ((struct conta_bancaria*)n->account)->saldo;
        break;
    case CP:
        value = ((struct conta_poupanca*)n->account)->saldo;
        break;
    case CF:
        value = ((struct conta_fidelidade*)n->account)->saldo;
        break;
    }
    return value;
}

void creditar_conta(node* n, float value){
    switch(n->type){
    case CB:
        conta_bancaria_credito((struct conta_bancaria*)n->account, value);
        break;
    case CP:
        conta_poupanca_credito((struct conta_poupanca*)n->account, value);
        break;
    case CF:
        conta_fidelidade_credito((struct conta_fidelidade*)n->account, value);
        break;
    }
}

void debitar_conta(node* n, float value){
    switch(n->type){
    case CB:
        conta_bancaria_debito((struct conta_bancaria*)n->account, value);
        break;
    case CP:
        conta_poupanca_debito((struct conta_poupanca*)n->account, value);
        break;
    case CF:
        conta_fidelidade_debito((struct conta_fidelidade*)n->account, value);
        break;
    }
}

int main()
{
    srand(time(nullptr));
    list * l = NULL;
    l = create_list();
    conta_bancaria* cb;
    conta_poupanca* cp;
    conta_fidelidade* cf;
    node* n;
    while(1){
        int operation = 0;
        printf("Operations: \n Inserir conta bancária (0) \n Inserir conta poupança (1) \n Inserir conta fidelidade (2) \n Credito em conta (3) \n");
        printf(" Debito em conta (4) \n Saldo da conta (5)  \n Bonus de conta fidelidade (6) \n");
        printf(" Transferência entre contas (7) \n Render juros na poupança (8) \n Render bonus na conta fidelidade (9) \n");
        printf(" Remover conta (10) \n Ver numero e saldo de todas as contas (11)\n\n");
        scanf("%d", &operation);

        int entry = 0;
        int entry_aux =0;
        float value = 0;

        if(operation != 0 && l == NULL){
            printf("list was not initialized.\n\n");
            continue;
        }

        switch(operation){
            case 0:
                cb = conta_bancaria_criar_conta();
                insert_list(l, cb, CB);
                printf("Conta criada bancaria com numero: %d\n", cb->numero);
                continue;
            case 1:
                cp = conta_poupanca_criar_conta();
                insert_list(l, cp, CP);
                printf("Conta criada poupança com numero: %d\n", cp->numero);
                continue;
            case 2:
                cf = conta_fidelidade_criar_conta();
                insert_list(l, cf, CF);
                printf("Conta criada fidelidade com numero: %d\n", cf->numero);
                continue;
            case 3:
                printf("Numero da conta a ser creditada: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr){
                    printf("Conta inexistente\n");
                    continue;
                }
                printf("Valor a ser creditado: ");
                scanf("%f", &value);
                creditar_conta(n, value);
                printf("Valor creditado em conta.\n");
                continue;
            case 4:
                printf("Numero da conta a ser debitada: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr){
                    printf("Conta inexistente\n");
                    continue;
                }
                printf("Valor a ser debitado: ");
                scanf("%f", &value);
                debitar_conta(n, value);
                printf("Valor debitado da conta.\n");
                continue;
            case 5:
                printf("Numero da conta: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr){
                    printf("Conta inexistente\n");
                    continue;
                }
                printf("Numero: %d \n", get_account_number(n));
                printf("Saldo: %.2f \n\n", saldo_conta(n));
                continue;
            case 6:
                printf("Numero da conta: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr || n->type != CF){
                    printf("Conta inexistente\n");
                    continue;
                }
                cf = (conta_fidelidade*)n->account;
                printf("Bonus em conta fidelidade: %f\n", cf->bonus);
                continue;
            case 7:
                printf("Numero da conta de origem: ");
                scanf("%d", &entry);
                node* ori = find_node(l, entry);
                if(n == nullptr){
                    printf("Conta inexistente\n");
                    continue;
                }

                printf("Numero da conta de destino: ");
                scanf("%d", &entry);
                node* des = find_node(l, entry);
                if(n == nullptr){
                    printf("Conta inexistente\n");
                    continue;
                }

                printf("Valor a ser transferido: ");
                scanf("%f", &value);
                if(get_account_saldo(ori) < value){
                    printf("Saldo insuficiente em conta\n");
                    continue;
                }

                debitar_conta(ori, value);
                creditar_conta(des, value);
                continue;
            case 8:
                printf("Numero da conta: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr || n->type != CP){
                    printf("Conta inexistente\n");
                    continue;
                }
                cp = (conta_poupanca*)n->account;
                conta_poupanca_juros(cp, 0.01f);
                continue;
            case 9:
                printf("Numero da conta: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr || n->type != CF){
                    printf("Conta inexistente\n");
                    continue;
                }
                cf = (conta_poupanca*)n->account;
                conta_fidelidade_render_bunus(cf);
                continue;
            case 10:
                printf("Numero da conta: ");
                scanf("%d", &entry);
                n = find_node(l, entry);
                if(n == nullptr){
                    printf("Conta inexistente\n");
                    continue;
                }
                remove_node(l, entry);
                continue;
            case 11:
                print_list_account_and_balance(l);
                continue;
            default:
                continue;
        }
    }
    return 0;
}
