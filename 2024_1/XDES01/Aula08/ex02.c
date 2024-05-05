#define LIN 3
#define COL 5

#include <stdio.h>

int main(void) {
	int numbers[LIN][COL], i, j;
	int even = 0, odd = 0;

	for (i = 0; i < LIN; i++) {
		for (j = 0; j < COL; j++) {
			scanf("%d", &numbers[i][j]);

			if (numbers[i][j] & 1) {
				odd++;
			} else {
				even++;
			}
		}
	}

	printf("%d %d\n", even, odd);

	return 0;
}
