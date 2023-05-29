#include <stdio.h>

#define SIZE 3

int main() {
	int chessboard[SIZE][SIZE] = { 0 }, i = 0, j = 0, result = 0, counter = 0;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			scanf("%d", &chessboard[i][j]);
		}
	}

	// check column sequences
	for (i = 0; i < SIZE; i++) {
		counter = 0;

		for (j = 0; j < SIZE; j++) {
			if (chessboard[i][j] == 1) counter++;
		}

		if (counter == 3) result++;
	}

	// check row sequences
	for (i = 0; i < SIZE; i++) {
		counter = 0;

		for (j = 0; j < SIZE; j++) {
			if (chessboard[j][i] == 1) counter++;
		}

		if (counter == 3) result++;
	}

	// check main diagonal sequences
	counter = 0;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (i == j && chessboard[i][j] == 1) counter++;
		}
	}
	if (counter == 3) result++;

	// check secondary diagonal sequences
	counter = 0;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if ((j == (SIZE - 1 - i)) && chessboard[i][j] == 1) counter++;
		}
	}
	if (counter == 3) result++;



	if (result >= 1) {
		printf("sim\n");
	}
	else {
		printf("nao\n");
	}

	return 0;
}
