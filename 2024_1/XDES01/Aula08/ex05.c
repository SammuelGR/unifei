#include <stdio.h>

int main(void) {
	int A[2][4], B[4][3], i, j, k, l;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				for (l = 0; l < 3; l++) {
					if (A[i][j] == B[k][l]) {
						printf("%d ", A[i][j]);
					}
				}
			}
		}
	}

	printf("\n");

	return 0;
}
