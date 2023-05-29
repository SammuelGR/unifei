#include <stdio.h>

#define SIZE 4

int main() {
	int n[SIZE][SIZE] = { 0 }, i = 0, j = 0, evenCounter = 0, oddCounter = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &n[i][j]);

			if (n[i][j] % 2 == 0) {
				evenCounter++;
			}
			else {
				oddCounter++;
			}
		}
	}

	printf("%d %d\n", evenCounter, oddCounter);

	return 0;
}
