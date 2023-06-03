#include <stdio.h>

#define SIZE 8

int main() {
	float athletesElapsedTimes[SIZE] = { 0.0 }, currentMinValue = 0.0;
	float aValue = 0.0, bValue = 0.0, cValue = 0.0;
	int aIndex = 0, bIndex = 0, cIndex = 0;
	int i = 0, currentMinIndex = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &athletesElapsedTimes[i]);

		if (i == 0 || athletesElapsedTimes[i] < currentMinValue) {
			currentMinValue = athletesElapsedTimes[i];
			currentMinIndex = i;
		}
	}

	aValue = currentMinValue;
	aIndex = currentMinIndex;

	if (currentMinIndex == 0) {
		currentMinValue = athletesElapsedTimes[1];
		currentMinIndex = 1;
	}
	else {
		currentMinValue = athletesElapsedTimes[0];
		currentMinIndex = 0;
	}

	for (i = 0; i < SIZE; i++) {
		if (athletesElapsedTimes[i] != aValue && athletesElapsedTimes[i] < currentMinValue) {
			currentMinValue = athletesElapsedTimes[i];
			currentMinIndex = i;
		}
	}

	bValue = currentMinValue;
	bIndex = currentMinIndex;

	if (currentMinIndex == 0 || currentMinIndex == 1) {
		currentMinValue = athletesElapsedTimes[2];
		currentMinIndex = 2;
	}
	else {
		currentMinValue = athletesElapsedTimes[0];
		currentMinIndex = 0;
	}

	for (i = 0; i < SIZE; i++) {
		if (athletesElapsedTimes[i] != aValue && athletesElapsedTimes[i] != bValue && athletesElapsedTimes[i] < currentMinValue) {
			currentMinValue = athletesElapsedTimes[i];
			currentMinIndex = i;
		}
	}

	cValue = currentMinValue;
	cIndex = currentMinIndex;

	printf("%f %d\n", aValue, aIndex);
	printf("%f %d\n", bValue, bIndex);
	printf("%f %d\n", cValue, cIndex);

	return 0;
}
