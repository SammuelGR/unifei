#define SIZE 8

#include <stdio.h>

int main() {
	unsigned int registrations[SIZE];
	float heights[SIZE], tallestValue, shortestValue;
	int i, tallestIdx = 0, shortestIdx = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%u", &registrations[i]);
	}

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &heights[i]);

		if (i == 0) {
			tallestValue = heights[i];
			shortestValue = heights[i];
		} else {
			if (heights[i] > tallestValue) {
				tallestValue = heights[i];
				tallestIdx = i;
			}

			if (heights[i] < shortestValue) {
				shortestValue = heights[i];
				shortestIdx = i;
			}
		}
	}

	printf("%u %.2f\n", registrations[shortestIdx], shortestValue);
	printf("%u %.2f\n", registrations[tallestIdx], tallestValue);

	return 0;
}
