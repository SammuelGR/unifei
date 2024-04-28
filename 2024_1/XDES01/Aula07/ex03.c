#define SIZE 8

#include <stdio.h>

int main(void) {
	int numbers[SIZE], X, Y, i;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);
	}

	scanf("%d %d", &X, &Y);

	printf("%d\n", numbers[X] + numbers[Y]);

	return 0;
}
