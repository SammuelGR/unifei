#include <stdio.h>

#define SIZE 8

int main() {
	int n[SIZE] = { 0 }, i = 0, j = 0, divisorsCounter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &n[i]);
	}

	for (i = 0; i < SIZE; i++) {
		divisorsCounter = 0;

		if (n[i] > 1) {
			for (j = 1; j <= n[i]; j++) {
				if (n[i] % j == 0) divisorsCounter++;
			}
		}


		if (divisorsCounter == 2) printf("%d ", n[i]);
	}

	printf("\n");

	return 0;
}
