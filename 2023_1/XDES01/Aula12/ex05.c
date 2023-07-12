#include <stdio.h>

int soma(int a, int b);

int main() {
	int A = 0, B = 0;

	scanf("%d %d", &A, &B);

	printf("%d\n", soma(A, B));

	return 0;
}

int soma(int a, int b) {
	int i = 0, sum = 0;

	for (i = a; i <= b; i++) sum += i;

	return sum;
}
