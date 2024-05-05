#define SIZE 3

#include <stdio.h>

int main(void) {
	int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &B[i][j]);

			if (A[i][j] > B[i][j]) {
				C[i][j] = A[i][j];
			} else {
				C[i][j] = B[i][j];
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	return 0;
}
