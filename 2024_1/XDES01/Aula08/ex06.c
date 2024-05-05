#include <stdio.h>

int main(void) {
	int A[3][3], B[4][5], i, j, k, l, counter = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &B[i][j]);
		}
	}



	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			counter = 0;

			for (k = 0; k < 4; k++) {
				for (l = 0; l < 5; l++) {
					if (B[k][l] == A[i][j]) {
						counter++;
					}
				}
			}

			if (counter == 0) {
				printf("%d ", A[i][j]);
			}
		}
	}

	printf("\n");

	return 0;
}
