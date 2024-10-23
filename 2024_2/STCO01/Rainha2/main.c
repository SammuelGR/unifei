#include <stdio.h>
#include <stdlib.h>

void imprime_tabuleiro(int n, int *r) {
	int x, y;

	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++) {
			if (r[y] == x)
				printf("R ");
			else
				printf("_ ");
		}
		printf("\n");
	}
}

void solve(int n, int *r, int atual) {
	int x, j;

	if (n == atual) {
		imprime_tabuleiro(n, r);
		printf("\n");

		return;
	}

	for (x = 0; x < n; x++) {
		// verificar se as rainhas anteriores
		// não estão atacando em x
		int viavel = 1;

		for (j = 0; j < atual; j++) {
			int dist = atual - j;

			if (r[j] == x || r[j] - x == dist || x - r[j] == dist) {
				viavel = 0;
				break;
			}
		}

		if (viavel == 1) {
			r[atual] = x;
			solve(n, r, atual + 1);
		}
	}

	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int *r = (int *)malloc(n * sizeof(int));

	solve(n, r, 0);

	free(r);

	return 0;
}
