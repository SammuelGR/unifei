#include <stdio.h>

int primo(int n);

int main() {
	int N;

	do {
		scanf("%d", &N);

		if (N > 0) {
			printf("%d\n", primo(N));
		}

	} while (N > 0);

	return 0;
}

int primo(int n) {
	int i, counter = 0;

	for (i = 1; i <= n / 2; i++) {
		if (n % i == 0) counter++;
	}

	return counter == 1;
}
