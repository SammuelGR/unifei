#define SIZE 6

#include <stdio.h>

int main() {
	int A[SIZE], B[SIZE], i, j, counter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &A[i]);
	}

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &B[i]);
	}

	for (i = 0; i < SIZE; i++) {
		counter = 0;
		for (j = 0; j < SIZE; j++) {
			if (A[i] == B[j]) counter++;
		}

		if (counter == 0) {
			printf("%d ", A[i]);
		}
	}

	printf("\n");

	return 0;
}
