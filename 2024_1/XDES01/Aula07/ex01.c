#define SIZE 6

#include <stdio.h>

int main(void) {
	int numbers[SIZE], i;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d ", numbers[i]);
	}

	printf("\n");

	return 0;
}
