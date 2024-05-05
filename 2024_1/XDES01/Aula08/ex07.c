#define LIN 3
#define COL 5

#include <stdio.h>

int main(void) {
	int numbers[LIN][COL], i, j;
	int k, divisors = 0;

	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			scanf("%d", &numbers[i][j]);
		}
	}

	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			if (numbers[i][j] >= 2) {
				if (numbers[i][j] == 2) {
					printf("%d ", numbers[i][j]);
				} else {
					divisors = 0;

					for (k = 1; k <= numbers[i][j] / 2; k++) {
						if (numbers[i][j] % k == 0) {
							divisors++;
						}
					}

					if (divisors == 1) {
						printf("%d ", numbers[i][j]);
					}
				}
			}
		}
	}

	printf("\n");

	return 0;
}
