#include <stdio.h>

int main() {
	int N, i, j, sumsIdx = 0, isEqual = 1, sumsSize = 0;

	scanf("%d", &N);

	sumsSize = (N * 2) + 2;

	int mat[N][N], sums[sumsSize];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (i = 0; i < sumsSize; i++) {
		sums[i] = 0;
	}

	// soma linhas
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			sums[sumsIdx] += mat[i][j];
		}

		sumsIdx++;
	}
	// soma colunas
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			sums[sumsIdx] += mat[j][i];
		}

		sumsIdx++;
	}

	//soma diagonal principal
	for (i = 0; i < N; i++) {
		sums[sumsIdx] += mat[i][i];
	}

	sumsIdx++;
	//soma diagonal secundaria
	for (i = 0; i < N; i++) {
		sums[sumsIdx] += mat[i][N - 1 - i];
	}

	for (i = 0; i < sumsSize - 1; i++) {
		if (sums[i] != sums[i + 1]) {
			isEqual = 0;
			i = sumsSize - 1;
		}
	}

	if (isEqual == 1) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}
