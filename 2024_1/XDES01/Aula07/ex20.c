#define SIZE 10

#include <math.h>
#include <stdio.h>

int main() {
	double sr = 0.0;
	int num, i, primesCounter = 0, primes[SIZE];

	do {
		scanf("%d", &num);

		sr = sqrt(num);
		if (floor(sr) == sr) {
			primes[primesCounter] = num;
			primesCounter++;
		}

	} while (primesCounter < SIZE);

	for (i = 0; i < SIZE; i++) {
		printf("%d ", primes[i]);
	}

	printf("\n");

	return 0;
}
