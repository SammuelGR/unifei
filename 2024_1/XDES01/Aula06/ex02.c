#include <stdio.h>

int main() {
	int n, i;

	do {
		scanf("%d", &n);
	} while (n < 0);

	for (i = 0; i < n; i++)
		printf("%d ", i);

	printf("%d\n", n);

	return 0;
}
