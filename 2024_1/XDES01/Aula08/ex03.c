#define LIN 4
#define COL 5

#include <stdio.h>

int main(void) {
	int numbers[LIN][COL], i, j;
	int highestValue, highestLin, highestCol;

	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			scanf("%d", &numbers[i][j]);

			if (i == 0 || numbers[i][j] > highestValue) {
				highestValue = numbers[i][j];
				highestLin = i;
				highestCol = j;
			}
		}
	}

	printf("%d %d %d\n", highestValue, highestLin, highestCol);

	return 0;
}
