#include <stdio.h>

int main() {
	int x, i;
	long int sum = 0, squaredSum = 0, result = 0;

	scanf("%d", &x);

	for (i = 0; i <= x; i++) {
		sum += i;
		squaredSum += (i * i);
	}

	result = (sum * sum) - squaredSum;

	printf("%ld\n", result);

	return 0;
}
