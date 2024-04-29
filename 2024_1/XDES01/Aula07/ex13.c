#define SIZE 10

#include <stdio.h>

int main() {
	int numbers[SIZE], i, X;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);
	}

	scanf("%d", &X);

	for (i = 0; i < SIZE; i++) {

		if (numbers[i] % X == 0) {
			printf("%d ", numbers[i]);
		}
	}

	printf("\n");

	return 0;
}
