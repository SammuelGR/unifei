#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, columns;
	int **mat = NULL, i, j;
	int lowestRIdx = 0, lowestCIdx = 0, highestRIdx = 0, highestCIdx = 0;

	scanf("%d %d", &rows, &columns);

	mat = (int **)malloc(rows * sizeof(int *));
	mat[0] = (int *)malloc(rows * columns * sizeof(int));

	for (i = 1; i < rows; i++) {
		mat[i] = mat[i - 1] + columns;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &mat[i][j]);

			if (mat[i][j] < mat[lowestRIdx][lowestCIdx]) {
				lowestRIdx = i;
				lowestCIdx = j;
			}

			if (mat[i][j] > mat[highestRIdx][highestCIdx]) {
				highestRIdx = i;
				highestCIdx = j;
			}
		}
	}

	printf("%d %d %d\n", mat[lowestRIdx][lowestCIdx], lowestRIdx, lowestCIdx);
	printf("%d %d %d\n", mat[highestRIdx][highestCIdx], highestRIdx, highestCIdx);


	free(mat[0]);
	free(mat);

	return 0;
}
