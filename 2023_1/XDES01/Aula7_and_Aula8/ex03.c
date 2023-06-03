#include <stdio.h>

#define SIZE 8

int main() {
	int numbers[SIZE] = { 0 }, i = 0, X = 0, Y = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);
	}

	do {
		scanf("%d %d", &X, &Y);
	} while ((X >= SIZE || X < 0) || (Y >= SIZE || Y < 0));

	printf("%d\n", (numbers[X] + numbers[Y]));

	return 0;
}
