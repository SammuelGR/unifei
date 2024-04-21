#include <stdio.h>

int main() {
	int a, b, i;
	int evenSum = 0, oddProduct = 1;

	scanf("%d %d", &a, &b);

	for (i = a; i <= b; i++) {
		if (i & 1) {
			oddProduct *= i;
		} else {
			evenSum += i;
		}
	}

	printf("%d %d\n", evenSum, oddProduct);

	return 0;
}
