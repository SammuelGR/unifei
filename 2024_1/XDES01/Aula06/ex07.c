#include <stdio.h>

int main() {
	int n, i;

	do {
		scanf("%d", &n);
	} while (n < 0);

	for (i = 1; i <= n / 2.0; i++) {
		if (n % i == 0) {
			printf("%d ", i);
		}
	}

	printf("%d\n", n);

	return 0;
}
