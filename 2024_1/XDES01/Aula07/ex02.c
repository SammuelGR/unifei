#define SIZE 10

#include <stdio.h>

int main(void) {
	int A[SIZE], B[SIZE], i;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &A[i]);

		B[i] = A[i] * A[i];
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d ", B[i]);
	}

	printf("\n");

	return 0;
}
