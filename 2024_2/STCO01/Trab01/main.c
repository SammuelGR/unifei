#include <stdio.h>
#include <stdlib.h>

#define PIXEL_COLORS_SIZE 3

typedef struct Pixel {
	int colors[PIXEL_COLORS_SIZE];
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
			for (k = 0; k < PIXEL_COLORS_SIZE; k++) {
				scanf("%d", &matrix[i][j].colors[k]);
			}
		}
	}
}

void applyFilter(Pixel **image, Pixel **filter, int size) {
	int i, j, k, l;
	Pixel temp;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < PIXEL_COLORS_SIZE; k++) {
				if (temp.colors[k])	temp.colors[k] = 0;
			}

			for (k = 0; k < size; k++) {
				for (l = 0; l < PIXEL_COLORS_SIZE; l++) {
					if (filter[k][j].colors[l] == 1) temp.colors[l] += image[i][k].colors[l];
				}
			}

			for (k = 0; k < PIXEL_COLORS_SIZE; k++) {
				printf("%d ", temp.colors[k]);
			}
		}
		printf("\n");
	}
}

int main(void) {
	int size, maxScale;
	char codificationName[3];
	Pixel **image = NULL, **filter = NULL;

	scanf("%s", codificationName);
	scanf("%d %d", &size, &size);
	scanf("%d", &maxScale);

	image = allocateMatrix(size);
	readMatrix(image, size);

	filter = allocateMatrix(size);
	readMatrix(filter, size);

	printf("%s\n%d %d\n%d\n", codificationName, size, size, maxScale);

	applyFilter(image, filter, size);

	freeMatrix(image);
	freeMatrix(filter);

	return 0;
}
