#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void printTable(pilha p, int n) {
	int i;
	pilha reversedStack = cria_pilha();
	pilha tempStack = cria_pilha();

	while (!pilha_vazia(p)) {
		int c = desempilhar(p);
		empilhar(tempStack, c);
		empilhar(reversedStack, c);
	}

	while (!pilha_vazia(tempStack)) {
		empilhar(p, desempilhar(tempStack));
	}

	while (!pilha_vazia(reversedStack)) {
		int c = desempilhar(reversedStack);

		for (i = 0; i < n; i++)
			if (c == i)
				printf("R ");
			else
				printf("_ ");

		printf("\n");
	}

	printf("\n");

	libera_pilha(reversedStack);
	libera_pilha(tempStack);
}

int canKill(int *currentBoard, int currentHeight, int x) {
	for (int j = 0; j < currentHeight; j++) {
		int dist = currentHeight - j;

		if (currentBoard[j] == x || currentBoard[j] - x == dist || x - currentBoard[j] == dist) {
			return 1;
		}
	}
	return 0;
}

void solve(pilha p, int n) {
	int *currentBoard = (int *)malloc(n * sizeof(int));
	int height = 0;
	int curPosition = 0;

	while (height >= 0) {
		if (curPosition >= n) {
			height--;

			if (height >= 0 && !pilha_vazia(p)) {
				curPosition = desempilhar(p) + 1;
			}
		} else if (!canKill(currentBoard, height, curPosition)) {
			currentBoard[height] = curPosition;

			empilhar(p, curPosition);

			height++;
			if (height == n) {
				printTable(p, n);

				height--;
				if (!pilha_vazia(p)) {
					curPosition = desempilhar(p) + 1;
				}
			} else {
				curPosition = 0;
			}
		} else {
			curPosition++;
		}
	}

	free(currentBoard);
}

int main(void) {
	pilha p = cria_pilha();

	int n;

	scanf("%d", &n);

	solve(p, n);

	libera_pilha(p);

	return 0;
}
