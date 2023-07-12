#include <stdio.h>

int primo(int N);

int main() {
	int N = 0;

	scanf("%d", &N);

	printf("%d\n", primo(N));

	return 0;
}

int primo(int N) {
	int i = 0, counter = 0;

	if (N <= 1) return 0;
	if (N <= 3) return 1;

	for (i = 1; i <= N; i++) {
		if (N % i == 0) {
			counter++;
		}
	}

	return counter == 2;
}
