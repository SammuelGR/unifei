#include <stdio.h>

int main() {
	int X = 0, i = 0, squaredSum = 0, sumOfSquares = 0;

	scanf("%d", &X);

	for (i = 1; i <= X; i++) {
		squaredSum += i;
		sumOfSquares += i * i;
	}

	squaredSum *= squaredSum;

	printf("%d\n", squaredSum - sumOfSquares);


	return 0;
}
