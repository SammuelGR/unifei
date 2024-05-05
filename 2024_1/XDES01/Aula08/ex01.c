#define SIZE 4

#include <stdio.h>

int main(void) {
	int numbers[SIZE][SIZE];
	int i, j, counter = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &numbers[i][j]);

			if (numbers[i][j] >= 10) {
				counter++;
			}
		}
	}

	printf("%d\n", counter);

	return 0;
}
