#define SIZE 10

#include <stdio.h>

int main() {
	int vector[SIZE], i, *p = NULL;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &vector[i]);
	}

	p = vector;

	for (i = 0; i < SIZE; i++) {
		printf("%p\t%d\n", (void *)p, *(p + i));
	}

	return 0;
}
