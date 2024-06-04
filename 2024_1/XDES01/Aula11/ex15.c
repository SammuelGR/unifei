#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, columns, X, hasX = 0;
	int **p = NULL, i, j;

	scanf("%d %d", &rows, &columns);

	p = (int **)malloc(rows * sizeof(int *));
	p[0] = (int *)malloc(rows * columns * sizeof(int));

	for (i = 1; i < rows; i++) {
		p[i] = p[i - 1] + columns;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &p[i][j]);
		}
	}

	scanf("%d", &X);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			if (p[i][j] == X) {
				hasX = 1;
				j = columns;
				i = rows;
			}
		}
	}

	printf("%s\n", hasX == 1 ? "sim" : "nao");

	free(p[0]);
	free(p);

	return 0;
}
