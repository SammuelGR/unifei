#include <stdio.h>
#include <stdlib.h>

#define PIXEL_VALUES_SIZE 3

typedef struct Pixel {
	int values[PIXEL_VALUES_SIZE];
} Pixel;

Pixel **allocateMatrix(int size) {
	int i;
	Pixel **matrix = (Pixel **)malloc(size * sizeof(Pixel *));
	matrix[0] = (Pixel *)malloc(size * size * sizeof(Pixel));

	for (i = 1; i < size; i++) {
		matrix[i] = matrix[i - 1] + size;
	}

	return matrix;
}

void freeMatrix(Pixel **matrix) {

	free(matrix[0]);
	free(matrix);
}

void readMatrix(Pixel **matrix, int size) {
	int i, j, k;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < PIXEL_VALUES_SIZE; k++) {
				scanf("%d", &matrix[i][j].values[k]);
			}
		}
	}
}

void applyFilter(Pixel **image, Pixel **filter) {
	// TODO
	return;
}

int main(void) {
	int size, maxScale;
	int i, j, k;
	char codificationName[3];
	Pixel **image = NULL, **filter = NULL;

	scanf("%s", codificationName);
	scanf("%d %d", &size, &size);
	scanf("%d", &maxScale);

	image = allocateMatrix(size);
	readMatrix(image, size);

	filter = allocateMatrix(size);
	readMatrix(filter, size);

	applyFilter(image, filter);

	printf("%s\n%d %d\n%d\n", codificationName, size, size, maxScale);

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < PIXEL_VALUES_SIZE; k++) {
				printf("%d ", image[i][j].values[k]);
			}
		}

		printf("\n");
	}

	freeMatrix(image);
	freeMatrix(filter);

	return 0;
}
