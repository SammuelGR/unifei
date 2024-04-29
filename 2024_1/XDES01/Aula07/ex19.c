#define SIZE 10

#include <stdio.h>

int main() {
	int num, primes[SIZE], i, primesCounter = 0, divCounter;

	do {
		scanf("%d", &num);

		if (num > 1) {
			if (num == 2) {
				primes[primesCounter] = num;
				primesCounter++;
			} else {
				divCounter = 0;

				for (i = 1; i <= num / 2; i++) {
					if (num % i == 0) divCounter++;
				}

				if (divCounter == 1) {
					primes[primesCounter] = num;
					primesCounter++;
				}
			}
		}
	} while (primesCounter < SIZE);


	for (i = 0; i < SIZE; i++) {
		printf("%d ", primes[i]);
	}

	printf("\n");

	return 0;
}
