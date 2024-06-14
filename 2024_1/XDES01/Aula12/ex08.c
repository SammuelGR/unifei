#include <stdio.h>

int qtdprimos(int n);

int main() {
	int n = 10;

	printf("\nprimos = %d\n", qtdprimos(n));

	return 0;
}

int qtdprimos(int n) {
	int i, qtd = 0, div;

	while (n--) {
		div = 0;

		for (i = 1; i <= n / 2; i++) {
			if (n % i == 0) div++;
		}

		if (div == 1) qtd++;
	}

	return qtd;
}
