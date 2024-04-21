#include <stdio.h>

int main() {
	int n, i;

	scanf("%d", &n);

	for (i = n; i > 1; i--) {
		printf("%d ", i);
	}

	printf("%d\n", 1);

	return 0;
}
