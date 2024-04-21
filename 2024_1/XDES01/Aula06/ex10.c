#include <stdio.h>

int main() {
	int n, i, sum = 0;

	do {
		scanf("%d", &n);
	} while (n < 0);

	sum += n;
	for (i = 1; i <= n / 2.0; i++) {
		if (n % i == 0) sum += i;
	}

	printf("%d\n", sum);

	return 0;
}
