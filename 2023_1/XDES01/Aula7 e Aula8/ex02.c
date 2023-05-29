#include <stdio.h>

#define SIZE 10

int main() {
	int numbers[SIZE] = { 0 }, squaredNumbers[SIZE] = { 0 };
	int i = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		squaredNumbers[i] = numbers[i] * numbers[i];
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d ", numbers[i]);
	}

	printf("\n");

	for (i = 0; i < SIZE; i++) {
		printf("%d ", squaredNumbers[i]);
	}

	printf("\n");

	return 0;
}
