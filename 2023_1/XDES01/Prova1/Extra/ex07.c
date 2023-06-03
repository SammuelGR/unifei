#include <stdio.h>

int main() {
	int primeNumbers[5] = { 0 }, primeCounter = 0, divisorsCounter = 0, currentNumber = 0, i = 0;

	while (primeCounter < 5) {
		scanf("%d", &currentNumber);

		divisorsCounter = 0;

		for (i = 1; i <= currentNumber; i++) {
			if (currentNumber % i == 0) {
				divisorsCounter++;
			}
		}

		if (divisorsCounter == 2) {
			primeNumbers[primeCounter] = currentNumber;
			primeCounter++;
		}
	}

	for (i = 0; i < 5; i++) {
		printf("%d ", primeNumbers[i]);
	}

	printf("\n");

	return 0;
}
