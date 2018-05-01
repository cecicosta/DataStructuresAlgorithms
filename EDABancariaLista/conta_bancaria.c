#include "conta_bancaria.h"


conta_bancaria* conta_bancaria_criar_conta(){
    conta_bancaria* cb = (conta_bancaria*)malloc(sizeof(conta_bancaria));
    cb->numero = rand()%2000;
    cb->saldo = 0;
    return cb;
}

void conta_bancaria_credito(conta_bancaria* cb, float valor){
    cb->saldo += valor;
}

void conta_bancaria_debito(conta_bancaria* cb, float valor){
    cb->saldo -= valor;
}

void conta_bancaria_saldo(conta_bancaria* cb){
    printf("Saldo atual da conta: %d\n", cb->saldo);
}
