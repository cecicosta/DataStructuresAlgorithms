#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

struct conta_bancaria {
    int numero;
    float saldo;
}typedef conta_bancaria;

conta_bancaria* conta_bancaria_criar_conta();

void conta_bancaria_credito(conta_bancaria*, float);

void conta_bancaria_debito(conta_bancaria*, float);

void conta_bancaria_saldo(conta_bancaria*);

#endif //CONTA_BANCARIA_H
