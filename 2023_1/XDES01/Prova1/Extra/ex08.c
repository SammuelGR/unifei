#include <stdio.h>

int main() {
	int M = 0, N = 0, P = 0, i = 0, j = 0, k = 0;

	scanf("%d %d", &M, &N);
	int matrix[M][N];

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	scanf("%d", &P);
	int vector[P];

	for (i = 0; i < P; i++) {
		scanf("%d", &vector[i]);
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < P; k++) {
				if (vector[k] % 2 != 0 && vector[k] == matrix[i][j]) {
					printf("%d ", vector[k]);
				}
			}
		}
	}

	printf("\n");

	return 0;
}
