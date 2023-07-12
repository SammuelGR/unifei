#include <stdio.h>
#include <stdlib.h>


int* calculateSum(int n, int* vetA, int* vetB);

int main() {
	int n = 0, i = 0;
	int* vetA = NULL, * vetB = NULL, * vetC = NULL;

	scanf("%d", &n);

	vetA = (int*)malloc(n * sizeof(int));
	vetB = (int*)malloc(n * sizeof(int));

	if (!vetA || !vetB) exit(1);

	for (i = 0; i < n; i++) {
		scanf("%d", vetA + i);
	}

	for (i = 0; i < n; i++) {
		scanf("%d", vetB + i);
	}

	vetC = calculateSum(n, vetA, vetB);

	for (i = 0; i < n; i++) {
		printf("%d ", *(vetC + i));
	}

	printf("\n");

	free(vetA);
	free(vetB);
	free(vetC);
	return 0;
}

int* calculateSum(int n, int* vetA, int* vetB) {
	int* sum = (int*)malloc(n * sizeof(int));
	int i = 0;

	if (!sum) exit(1);

	for (i = 0; i < n; i++) {
		*(sum + i) = *(vetA + i) + *(vetB + i);
	}

	return sum;
}
