#include "arvore.h"
#include <stdio.h>


int incluir(arvore **raiz, int val)
{

	int ret;
	if (*raiz == NULL)
	{
		arvore *novo;
		novo = (arvore*)malloc(sizeof(arvore));
		novo->val = val;
		novo->dir = NULL;
		novo->esq = NULL;
		*raiz = novo;
		return 1;
	}
	else
	{
		if ((*raiz)->val == val)
			return 0;
		if ((*raiz)->val<val)
			ret = incluir(&((*raiz)->dir), val);
		else
			ret = incluir(&((*raiz)->esq), val);
	}
	return ret;
}

void printa_arv(arvore *arv)
{
	if (arv != NULL)
	{
		printa_arv(arv->esq);
		printf("%d\n", arv->val);
		printa_arv(arv->dir);
	}

}

void  perc_pre_ord(arvore *arv)
{
	if (arv != NULL)
	{
		printf("%d\n", arv->val);
		perc_pre_ord(arv->esq);
		perc_pre_ord(arv->dir);

	}
}


void perc_pos_ord(arvore *arv)
{
	if (arv != NULL)
	{
		perc_pre_ord(arv->esq);
		perc_pre_ord(arv->dir);
		printf("%d\n", arv->val);
	}
}


int profundidade(arvore *arv, int nivel, int max)
{
	if (arv == NULL)
	{
		if (nivel>max)
			return nivel;
		else
			return max;
	}
	else
	{
		max = profundidade(arv->esq, nivel + 1, max);
		max = profundidade(arv->dir, nivel + 1, max);
	}
	return max;
}

void free_arv(arvore *arv)
{
	arvore *aux1, *aux2;
	if (arv != NULL)
	{
		aux1 = arv->esq;
		aux2 = arv->dir;
		free(arv);
		free_arv(aux1);
		free_arv(aux2);
	}
}

int buscar(arvore *arv, int val)
{
	int resp;
	if (arv == NULL)
		return 0;
	if (arv->val == val)
		return 1;
	else
	{
		if (arv->val>val)
			resp = buscar(arv->esq, val);
		else
			resp = buscar(arv->dir, val);
	}
	return resp;
}

arvore* menor_valor(arvore *raiz, arvore** parent) {
	arvore *aux;
	if (raiz == NULL)
		return raiz;
	if (raiz->esq != NULL) {
		*parent = raiz;
		aux = menor_valor(raiz->esq, parent);
	}

	return aux;
}

arvore* remover(arvore* arv, int val) {
	arvore* resp;
	if (arv == NULL)
		return NULL;

	if (arv->val == val) {
		if (arv->esq == NULL && arv->dir == NULL) {
			free(arv);
			return NULL;
		}
		else if (arv->esq == NULL) {
			free(arv);
			return arv->dir;
		}
		else if (arv->dir == NULL) {
			free(arv);
			return arv->esq;
		}
		else {
			arvore* parent = NULL;
			resp = menor_valor(arv->esq, &parent);
			arv->val = resp->val;
			free(resp);
			parent->esq = NULL;
		}

		return arv;
	} 
	
	if (arv->val > val) {
		resp = remover(arv->esq, val);
		arv->esq = resp;
	}
	else {
		resp = remover(arv->dir, val);
		arv->dir = resp;
	}

	return arv;
}

