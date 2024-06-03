#define SIZE 5

#include <stdio.h>

int main() {
	int vector[SIZE] = { 3, 4, 1, 5, 2 }, *p = NULL, i, j, aux;

	p = vector;

	for (i = 0; i < SIZE - 1; i++) {
		for (j = i + 1; j < SIZE; j++) {
			if (*(p + i) > *(p + j)) {
				aux = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = aux;
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", *(p + i));
	}

	return 0;
}
