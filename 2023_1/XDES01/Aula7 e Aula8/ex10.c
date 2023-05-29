#include <stdio.h>

#define SIZE 4

int main() {
	int n[SIZE][SIZE] = { 0 }, i = 0, j = 0, counter = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &n[i][j]);

			if (n[i][j] > 10) counter++;
		}
	}

	printf("%d\n", counter);

	return 0;
}
