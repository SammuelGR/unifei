#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, columns, i, j;
	int **mat = NULL, **transposedMat = NULL;

	scanf("%d %d", &rows, &columns);

	mat = (int **)malloc(rows * sizeof(int *));
	mat[0] = (int *)malloc(rows * columns * sizeof(int));

	for (i = 1; i < rows; i++) {
		mat[i] = mat[i - 1] + columns;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	transposedMat = (int **)malloc(columns * sizeof(int *));
	transposedMat[0] = (int *)malloc(columns * rows * sizeof(int));

	for (i = 1; i < columns; i++) {
		transposedMat[i] = transposedMat[i - 1] + rows;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			transposedMat[j][i] = mat[i][j];
		}
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			printf("%d ", mat[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++) {
			printf("%d ", transposedMat[i][j]);
		}

		printf("\n");
	}

	free(mat[0]);
	free(mat);

	free(transposedMat[0]);
	free(transposedMat);

	return 0;
}
