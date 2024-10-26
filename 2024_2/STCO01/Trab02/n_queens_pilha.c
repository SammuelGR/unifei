#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void print_table(pilha p, int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (desempilhar(p) == j)
				printf("R ");
			else printf("_ ");
		}

		printf("\n");
	}
}

pilha solve(pilha p, int n, int current) {

	if (n == current) {
		print_table(p, n);
		printf("\n");

		return;
	}

	return p;
}

int main(void) {
	pilha p = cria_pilha();

	int n;

	scanf("%d", &n);

	solve(p, n, 0);

	libera_pilha(p);

	return 0;
}
