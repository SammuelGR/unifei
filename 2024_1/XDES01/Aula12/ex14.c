#include <stdio.h>
#include <stdlib.h>

int *sumVectors(int n, int *v1, int *v2);

int main() {
	int N, *v1 = NULL, *v2 = NULL, *v3 = NULL, i;

	scanf("%d", &N);

	v1 = (int *)malloc(N * sizeof(int));
	v2 = (int *)malloc(N * sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", (v1 + i));
	}

	for (i = 0; i < N; i++) {
		scanf("%d", (v2 + i));
	}

	v3 = sumVectors(N, v1, v2);

	for (i = 0; i < N; i++) {
		printf("%d ", *(v3 + i));
	}

	printf("\n");

	free(v1);
	free(v2);
	free(v3);

	return 0;
}

int *sumVectors(int n, int *v1, int *v2) {
	int i;
	int *v3 = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		*(v3 + i) = *(v1 + i) + *(v2 + i);
	}

	return v3;
}
