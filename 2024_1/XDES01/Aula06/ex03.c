#include <stdio.h>

int main() {
	int n, i;

	scanf("%d", &n);

	for (i = 1; i < 2 * n; i += 2) {
		printf("%d ", i);
	}

	printf("\n");

	return 0;
}
