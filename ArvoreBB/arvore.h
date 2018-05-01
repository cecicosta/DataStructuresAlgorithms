#ifndef ARVOREBB_H
#define ARVOREBB_H


typedef struct arvore
{
	int val;
	struct arvore *dir;
	struct arvore *esq;
}arvore;

int incluir(arvore **raiz, int val);

void printa_arv(arvore *arv);

void  perc_pre_ord(arvore *arv);

void perc_pos_ord(arvore *arv);

int profundidade(arvore *arv, int nivel, int max);

void free_arv(arvore *arv);

int buscar(arvore *arv, int val);

arvore* menor_valor(arvore *raiz, arvore** parent);

arvore* remover(arvore* arv, int val);

#endif