#include <stdio.h>

int main() {
	int n, x;
	int sum = 0, multiple, i = 1;

	do {
		scanf("%d %d", &n, &x);
	} while (n < 0 || x < 0);

	do {
		multiple = x * i;

		if (multiple < n) {
			sum += multiple;
			i++;
		}
	} while (multiple < n);

	printf("%d\n", sum);

	return 0;
}
