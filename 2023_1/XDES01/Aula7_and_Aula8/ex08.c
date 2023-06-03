#include <stdio.h>

#define SIZE 8

int main() {
	int X[SIZE] = { 0 }, Y[SIZE] = { 0 }, intersection[SIZE] = { 0 }, i = 0, j = 0, repeatedNumbersCounter = 0, matchesCounter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &X[i]);
	}

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &Y[i]);

		if (X[i] == Y[i]) intersection[i] = 1;
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d ", (X[i] + Y[i]));
	}
	printf("\n");

	for (i = 0; i < SIZE; i++) {
		printf("%d ", (X[i] * Y[i]));
	}
	printf("\n");


	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (X[i] == Y[j]) {
				intersection[repeatedNumbersCounter] = X[i];

				repeatedNumbersCounter++;

				printf("%d ", X[i]);
			}
		}
	}
	printf("\n");

	for (i = 0; i < SIZE; i++) {
		matchesCounter = 0;

		for (j = 0; j < repeatedNumbersCounter; j++) {
			if (X[i] == intersection[j]) {
				matchesCounter++;
			}
		}

		if (matchesCounter == 0) {
			printf("%d ", X[i]);
		}
	}
	printf("\n");

	return 0;
}
