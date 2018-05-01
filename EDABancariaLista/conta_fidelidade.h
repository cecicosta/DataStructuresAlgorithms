#ifndef CONTA_FINDELIDADE_H
#define CONTA_FINDELIDADE_H

struct conta_fidelidade {
    int numero;
    float saldo;
    float bonus;
}typedef conta_fidelidade;

conta_fidelidade* conta_fidelidade_criar_conta();

void conta_fidelidade_credito(conta_fidelidade*, float);

void conta_fidelidade_debito(conta_fidelidade*, float);

void conta_fidelidade_render_bunus(conta_fidelidade*);

void conta_fidelidade_saldo(conta_fidelidade*);

#endif //CONTA_FINDELIDADE_H
