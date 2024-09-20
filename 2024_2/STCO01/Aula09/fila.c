#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX_CAPACITY 2500

struct filaa {
	int ini;
	int fim;
	int *valores;
};

fila criar_fila(void) {
	fila f = (fila)malloc(sizeof(struct filaa));

	f->valores = (int *)malloc(sizeof(int) * MAX_CAPACITY);

	f->ini = 0;
	f->fim = 0;

	return f;
}

void insere_fila(fila f, int v) {
	if (f->fim == MAX_CAPACITY) {
		printf("Erro: fila cheia!\n");
		return;
	}

	f->valores[f->fim] = v;
	f->fim++;

	return;
}

int remover_fila(fila f) {
	if (f->ini == f->fim) {
		printf("Erro: fila vazia!\n");
		return -1;
	}

	int valor = f->valores[f->ini];

	f->ini++;

	return valor;
}
void liberar_fila(fila f) {
	free(f->valores);
	free(f);

	return;
}
