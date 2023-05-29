#include <stdio.h>

#define SIZE 8

int main() {
	char input[SIZE];
	int i = 0;

	for (i = 0; i < SIZE; i++) {
		scanf(" %c", &input[i]);
	}

	for (i = SIZE - 1; i >= 0; i--) {
		printf("%c ", input[i]);
	}

	printf("\n");

	return 0;
}
