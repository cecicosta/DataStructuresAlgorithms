#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

struct conta_poupanca {
    int numero;
    float saldo;
}typedef conta_poupanca;

conta_poupanca* conta_poupanca_criar_conta();

void conta_poupanca_credito(conta_poupanca*, float);

void conta_poupanca_debito(conta_poupanca*, float);

void conta_poupanca_juros(conta_poupanca*, float);

void conta_poupanca_saldo(conta_poupanca*);

#endif //CONTA_POUPANCA_H
