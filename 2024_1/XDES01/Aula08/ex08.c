#define SIZE 4

#include <stdio.h>

int main(void) {
	int matrix[SIZE][SIZE], i, j;
	int highestValue, secHighestValue, lin = 0, col = 0, allEqual = 1;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &matrix[i][j]);

			if (i == 0 || matrix[i][j] > highestValue) {
				highestValue = matrix[i][j];
			}
		}
	}



	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] != highestValue) {
				secHighestValue = matrix[i][j];
				lin = i;
				col = j;
				i = SIZE;
				j = SIZE;
				allEqual = 0;
			}
		}
	}

	if (allEqual == 1) {
		secHighestValue = matrix[0][0];
		lin = 1;
		col = 1;
	} else {
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if (matrix[i][j] != highestValue && matrix[i][j] > secHighestValue) {
					secHighestValue = matrix[i][j];
					lin = i;
					col = j;
				}
			}
		}
	}

	printf("%d %d %d\n", secHighestValue, lin, col);

	return 0;
}
