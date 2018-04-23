#include "conta_poupanca.h"

conta_poupanca* conta_poupanca_criar_conta(){
    conta_poupanca* cp = (conta_poupanca*)malloc(sizeof(conta_poupanca));
    cp->numero = rand()%2000;
    cp->saldo = 0;
    return cp;
}

void conta_poupanca_credito(conta_poupanca* cp, float valor){
    cp->saldo += valor;
}

void conta_poupanca_debito(conta_poupanca* cp, float valor){
    cp->saldo -= valor;
}

void conta_poupanca_juros(conta_poupanca* cp, float taxa){
    cp->saldo += ((float)cp->saldo)*taxa;
}

void conta_poupanca_saldo(conta_poupanca* cp){
    printf("Saldo atual da conta: %d\n", cp->saldo);
}

