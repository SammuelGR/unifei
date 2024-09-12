#include <stdio.h>
#include <stdlib.h>

typedef struct celula celula;

struct celula {
	int valor;
	celula *prox; // next
};

void imprime_lista(celula *L) {
	if (L == NULL) return;

	printf("%d, ", L->valor);

	imprime_lista(L->prox);
}

celula *insere_lista(celula *L, int v) {
	celula *nova = (celula *)malloc(sizeof(celula));

	nova->valor = v;
	nova->prox = L;

	return nova;
}

celula *busca_antecessor(celula *L, int v) {
	if (L == NULL) return NULL;
	if (L->prox == NULL) return NULL;

	if (L->prox->valor == v) {
		return L;
	}

	return busca_antecessor(L->prox, v);
}

celula *busca(celula *L, int v) {
	if (L == NULL) return NULL;

	if (L->valor == v) return L;

	return busca(L->prox, v);
}

void insere_depois(celula *L, int v) {
	celula *nova = (celula *)malloc(sizeof(celula));
	nova->valor = v;

	nova->prox = L->prox;
	L->prox = nova;

	return;
}

// remove uma celula que esta em L->prox
void remove_prox(celula *L) {
	celula *del = L->prox;

	L->prox = L->prox->prox;

	free(del);
	return;
}

void libera_lista(celula *L) {
	if (L == NULL) return;

	libera_lista(L->prox);
	free(L);

	return;
}

int main(void) {
	celula *L = NULL;
	celula *B = NULL;

	L = insere_lista(L, 2);
	L = insere_lista(L, 5);
	L = insere_lista(L, 3);
	L = insere_lista(L, 8);
	L = insere_lista(L, 4);

	imprime_lista(L);

	printf("\n");

	B = busca(L, 7);
	if (B == NULL) {
		printf("Nao achou 7!\n");
	} else {
		printf("Achou %d!\n", B->valor);
	}

	B = busca(L, 4);
	if (B == NULL) {
		printf("Nao achou 4!\n");
	} else {
		printf("Achou %d!\n", B->valor);
	}

	B = busca(L, 2);
	if (B == NULL) {
		printf("Nao achou 2!\n");
	} else {
		printf("Achou %d!\n", B->valor);
	}

	printf("\n");
	imprime_lista(L);

	printf("\n");
	insere_depois(busca(L, 3), 30);
	imprime_lista(L);
	printf("\n");


	printf("\n");
	imprime_lista(L);
	remove_prox(L);
	printf("\n");
	imprime_lista(L);
	printf("\n");

	B = busca_antecessor(L, 30);
	remove_prox(B);


	imprime_lista(L);
	printf("\n");


	return 0;
}
