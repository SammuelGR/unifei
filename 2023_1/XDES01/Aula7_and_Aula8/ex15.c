#include <stdio.h>

int main() {
	int N = 0, i = 0, j = 0, currentSum = 0, previousSum = 0, differentSumCounter = 0;
	int columnsSum = 0, rowsSum = 0, mainDiagonalSum = 0, secondaryDiagonalSum = 0;

	scanf("%d", &N);
	int matrix[N][N];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	// check rows sum
	for (i = 0; i < N; i++) {
		currentSum = 0;

		for (j = 0; j < N; j++) {
			currentSum += matrix[i][j];
		}

		if (i == 0) {
			previousSum = currentSum;
		}
		else {
			if (currentSum != previousSum) {
				differentSumCounter++;
				break;
			}
		}
	}

	rowsSum = currentSum;

	if (differentSumCounter > 0) {
		printf("nao\n");

		return 0;
	}

	// check columns sum
	for (i = 0; i < N; i++) {
		currentSum = 0;

		for (j = 0; j < N; j++) {
			currentSum += matrix[j][i];
		}

		if (i == 0) {
			previousSum = currentSum;
		}
		else {
			if (currentSum != previousSum) {
				differentSumCounter++;
				break;
			}
		}
	}

	columnsSum = currentSum;

	if (differentSumCounter > 0) {
		printf("nao\n");

		return 0;
	}

	// calculate main diagonal sum
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == j) {
				mainDiagonalSum += matrix[i][j];
			}
		}
	}

	// calculate secondary diagonal sum
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (j == (N - 1 - i)) {
				secondaryDiagonalSum += matrix[i][j];
			}
		}
	}

	if (differentSumCounter == 0 && rowsSum == columnsSum && columnsSum == mainDiagonalSum && mainDiagonalSum == secondaryDiagonalSum) {
		printf("sim\n");
	}
	else {
		printf("nao\n");
	}

	return 0;
}
