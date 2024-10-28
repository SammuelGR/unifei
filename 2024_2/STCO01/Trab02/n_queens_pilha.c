#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void print_table(pilha p, int n) {
	int i, j = n;

	while (j--) {
		int c = desempilhar(p);

		for (i = 0; i < n; i++)
			if (c == i)
				printf("R ");
			else
				printf("_ ");

		printf("\n");
	}

	printf("\n");
}

void solveStack(pilha p, int n) {
	int i, j;

	pilha copy = cria_pilha();

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int c = pilha_vazia(p) ? 0 : desempilhar(p);
			empilhar(copy, c);

			int canKill = c == j && !pilha_vazia(p);

			if (!canKill) {
				while (!pilha_vazia(copy)) empilhar(p, desempilhar(copy));

				empilhar(p, c);
				empilhar(p, j);
				break;
			}
		}
	}

	print_table(p, n);
}

int main(void) {
	pilha p = cria_pilha();

	int n;

	scanf("%d", &n);

	solveStack(p, n);

	libera_pilha(p);

	return 0;
}
