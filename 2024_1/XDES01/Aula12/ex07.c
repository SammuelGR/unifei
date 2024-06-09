#include <stdio.h>

int sumNumerals(int n);

int main() {
	int x;

	scanf("%d", &x);

	printf("%d\n", sumNumerals(x));

	return 0;
}

int sumNumerals(int n) {
	int rest, sum = 0;

	if (n < 10) {
		return n;
	}

	do {
		rest = n % 10;
		sum += n < 10 ? n : rest;

		n /= 10;
	} while (n > 0);

	return sum;

}
