#include <stdio.h>

int main() {
	int n, x, i = 1;

	scanf("%d %d", &n, &x);

	while (n--) {
		printf("%d ", x * i);

		i++;
	}

	printf("\n");

	return 0;
}
