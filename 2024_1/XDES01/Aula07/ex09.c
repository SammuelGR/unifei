#define SIZE 6

#include <stdio.h>

int main(void) {
	int numbers[SIZE], i, highestIdx = 0, lowestIdx = 0, highestValue, lowestValue;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		if (i == 0) {
			highestValue = numbers[i];
			lowestValue = numbers[i];
		} else {
			if (numbers[i] > highestValue) {
				highestValue = numbers[i];
				highestIdx = i;
			}

			if (numbers[i] < lowestValue) {
				lowestValue = numbers[i];
				lowestIdx = i;
			}
		}
	}

	printf("%d %d\n", highestIdx, lowestIdx);

	return 0;
}
