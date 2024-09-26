#include <stdio.h>
#include "fila.h"

int main(void) {
	int aux;

	fila f = criar_fila();

	insere_fila(f, 10);
	insere_fila(f, 20);
	insere_fila(f, 30);
	insere_fila(f, 40);

	aux = remover_fila(f);
	printf("%d foi removido\n", aux);

	insere_fila(f, 5);
	insere_fila(f, 15);

	aux = remover_fila(f);
	printf("%d foi removido\n", aux);

	printf("A fila%s esta vazia!\n", fila_vazia(f) ? "" : " nao");

	liberar_fila(f);

	printf("A fila%s esta vazia!\n", fila_vazia(f) ? "" : " nao");

	return 0;
}
