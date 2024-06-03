#define SIZE 10

#include <stdio.h>

int main() {
	int vector[SIZE], i, *p = NULL;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &vector[i]);
	}

	p = vector;

	for (i = 0; i < SIZE; i++) {
		if (*(p + i) % 2 == 0) {
			*(p + i) += 1;
		} else {
			*(p + i) *= 2;
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", *(p + i));
	}

	return 0;
}
