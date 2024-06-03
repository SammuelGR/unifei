#include <stdio.h>
#include <stdlib.h>

int main() {
	int M, N, i, j, count;
	int *vetM = NULL, *vetN = NULL;

	scanf("%d %d", &M, &N);

	vetM = (int *)malloc(M * sizeof(int));
	vetN = (int *)malloc(N * sizeof(int));

	for (i = 0; i < M; i++) {
		scanf("%d", vetM + i);
	}

	for (i = 0; i < N; i++) {
		scanf("%d", vetN + i);
	}

	// union
	for (i = 0; i < M; i++) {
		printf("%d ", *(vetM + i));
	}
	for (i = 0; i < N; i++) {
		count = 0;

		for (j = 0; j < M; j++) {
			if (*(vetN + i) == *(vetM + j)) count++;
		}

		if (count == 0) printf("%d ", *(vetN + i));
	}
	printf("\n");

	// intersection
	for (i = 0; i < M; i++) {
		count = 0;

		for (j = 0; j < N; j++) {
			if (*(vetM + i) == *(vetN + j)) count++;
		}

		if (count > 0) printf("%d ", *(vetM + i));
	}
	printf("\n");

	// M - N
	for (i = 0; i < M; i++) {
		count = 0;
		for (j = 0; j < N; j++) {
			if (*(vetM + i) == *(vetN + j)) count++;
		}

		if (count == 0) printf("%d ", *(vetM + i));
	}
	printf("\n");

	free(vetM);
	free(vetN);

	return 0;
}
