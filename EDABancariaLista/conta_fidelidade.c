#include "conta_fidelidade.h"

conta_fidelidade* conta_fidelidade_criar_conta(){
    conta_fidelidade* cf = (conta_fidelidade*)malloc(sizeof(conta_fidelidade));
    cf->numero = rand()%2000;
    cf->saldo = 0;
    cf->bonus = 0;
    return cf;
}

void conta_fidelidade_credito(conta_fidelidade* cf, float valor){
    cf->saldo += valor;
    cf->bonus += valor * 0.01;
}

void conta_fidelidade_debito(conta_fidelidade* cf, float valor){
    cf->saldo -= valor;
}

void conta_fidelidade_render_bunus(conta_fidelidade* cf){
    cf->saldo += cf->bonus;
    cf->bonus = 0;
}

void conta_fidelidade_saldo(conta_fidelidade* cf){
    printf("Saldo atual da conta: %d\n", cf->saldo);
}

