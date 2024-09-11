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

int main(void) {
	celula *L = NULL;

	L = insere_lista(L, 2);
	L = insere_lista(L, 5);
	L = insere_lista(L, 3);
	L = insere_lista(L, 2);
	L = insere_lista(L, 4);

	imprime_lista(L);

	printf("\n");

	free(L);

	return 0;
}
