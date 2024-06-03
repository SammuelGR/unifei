#define SIZE 10

#include <stdio.h>

int main() {
	int vector[SIZE], i, *p = NULL;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &vector[i]);
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", vector[i]);
	}

	p = vector;
	for (i = 0; i < SIZE; i++) {
		*(p + i) += 1;
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", vector[i]);
	}

	return 0;
}
