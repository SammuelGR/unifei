#include <stdio.h>
#include "fila.h"

int main(void) {
	int aux;

	fila f = criar_fila();

	insere_fila(f, 10);
	insere_fila(f, 20);

	aux = remover_fila(f);
	printf("%d\n", aux);

	insere_fila(f, 5);

	aux = remover_fila(f);
	printf("%d\n", aux);

	liberar_fila(f);

	return 0;
}
