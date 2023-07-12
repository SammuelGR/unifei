#include <stdio.h>

int quadrados(int n);

int main() {
	int N = 0;

	scanf("%d", &N);

	printf("%d\n", quadrados(N));

	return 0;
}

int quadrados(int n) {
	int i = 0, sum = 0;

	for (i = 0; i <= n; i++) {
		sum += i * i;
	}

	return sum;
}
