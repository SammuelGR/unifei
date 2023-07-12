#include <stdio.h>

int qtdprimos(int n);

int main() {
	int N = 0;

	scanf("%d", &N);

	printf("%d", qtdprimos(N));

	return 0;
}

int qtdprimos(int n) {
	int i = 0, primeCounter = 0;
	int j = 0, divisorsCounter = 0;

	if (n <= 1) return 0;
	if (n == 2) return 1;

	for (i = 2; i < n; i++) {
		divisorsCounter = 0;

		for (j = 1; j <= i; j++) {
			if (i % j == 0) divisorsCounter++;
		}

		if (divisorsCounter == 2) primeCounter++;
	}

	return primeCounter;
}
