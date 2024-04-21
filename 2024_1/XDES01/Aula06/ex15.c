#include <stdio.h>

int main() {
	int n, i, symbol = 1, counter = 0;
	float sum = 0.0, numerator, denominator;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		numerator = (2.0 * i) + 1.0;
		denominator = i + 1.0;

		sum += (numerator / denominator) * symbol;
		counter++;

		if (counter == 2) {
			symbol = -symbol;
			counter = 0;
		}

	}

	printf("%.2f\n", sum);

	return 0;
}
