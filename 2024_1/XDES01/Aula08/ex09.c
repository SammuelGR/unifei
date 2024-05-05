#define SIZE 3

#include <stdio.h>

int main(void) {
	int table[SIZE][SIZE], i, j, counter = 0, win = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	for (i = 0; i < SIZE; i++) {
		if (table[i][i] == 1) counter++;
	}

	if (counter == 3) {
		win = 1;
	} else {
		counter = 0;

		for (i = 0; i < SIZE; i++) {
			if (table[i][SIZE - 1 - i] == 1) counter++;
		}

		if (counter == 3) {
			win = 1;
		} else {


			for (i = 0; i < SIZE; i++) {
				counter = 0;
				for (j = 0; j < SIZE; j++) {
					if (table[i][j] == 1) counter++;
				}

				if (counter == 3) {
					win = 1;
				} else {
					counter = 0;

					for (j = 0; j < SIZE; j++) {
						if (table[j][i] == 1) counter++;
					}

					if (counter == 3) {
						win = 1;
					}

				}
			}
		}
	}

	if (win == 1) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}
