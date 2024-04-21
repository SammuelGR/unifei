#include <stdio.h>

int main() {
	int n, i, soma = 0;

	do {
		scanf("%d", &n);
	} while (n < 0);

	for (i = 1; i < 2 * n; i += 2) {
		soma += i;
	}

	printf("%d\n", soma);

	return 0;
}
