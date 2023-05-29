#include <stdio.h>

#define SIZE 10

int main() {
	int numbers[SIZE] = { 0 }, higherIndex = 0, lowerIndex = 0, i = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		if (i == 0) {
			higherIndex = 0;
			lowerIndex = 0;
		}
		else {
			if (numbers[i] > numbers[higherIndex]) {
				higherIndex = i;
			}

			if (numbers[i] < numbers[lowerIndex]) {
				lowerIndex = i;
			}
		}
	}

	printf("%d %d\n", numbers[higherIndex], numbers[lowerIndex]);
	printf("%d %d\n", higherIndex, lowerIndex);

	return 0;
}
