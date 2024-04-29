#define SIZE 5

#include <stdio.h>

int main() {
	int A[SIZE], B[SIZE], C[SIZE];
	int i;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &A[i]);
	}

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &B[i]);
	}

	for (i = 0; i < SIZE; i++) {
		C[i] = A[i] - B[i];
	}


	for (i = 0; i < SIZE; i++) {
		printf("%d ", C[i]);
	}

	printf("\n");

	return 0;
}
