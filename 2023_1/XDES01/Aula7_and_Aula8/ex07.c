#include <stdio.h>

#define SIZE 15

int main() {
	int chosenNumbers[SIZE] = { 0 }, drawnNumbers[SIZE] = { 0 }, i = 0, j = 0, counter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &chosenNumbers[i]);
	}

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &drawnNumbers[i]);
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (chosenNumbers[i] == drawnNumbers[j]) counter++;
		}
	}

	printf("%d\n", counter);

	return 0;
}
