#include <stdio.h>

int quadrados(int n);

int main() {
	int N = 5;

	printf("%d\n", quadrados(N));

	return 0;
}

int quadrados(int n) {
	int i, sum = 0;

	for (i = 1; i <= n; i++) {
		sum += i * i;
	}

	return sum;
}
