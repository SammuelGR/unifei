#include <stdio.h>

int soma(int a, int b);

int main() {
	printf("%d\n", soma(5, 25));

	return 0;
}

int soma(int a, int b) {
	int i, sum = 0;

	for (i = a; i <= b; i++) sum += i;

	return sum;
}
