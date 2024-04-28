#define SIZE 10

#include <stdio.h>

int main(void) {
	double numbers[SIZE], positivesSum = 0;
	int i, negativesCounter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%lf", &numbers[i]);

		if (numbers[i] > 0) {
			positivesSum += numbers[i];
		} else {
			negativesCounter++;
		}
	}

	printf("%d %.2lf\n", negativesCounter, positivesSum);

	return 0;
}
