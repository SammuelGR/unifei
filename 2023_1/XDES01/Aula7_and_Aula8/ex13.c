#include <stdio.h>

int main() {
	int M = 0, N = 0, i = 0, j = 0, higherValue = 0, secondHigherValue = 0, row = 0, col = 0;

	scanf("%d %d", &M, &N);

	int n[M][N];

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &n[i][j]);

			if (i == 0 && j == 0) {
				higherValue = n[i][j];
				secondHigherValue = n[i][j];
				row = i;
				col = j;
			}
			else if (n[i][j] > higherValue) {
				higherValue = n[i][j];

			}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (n[i][j] != higherValue && n[i][j] > secondHigherValue) {
				secondHigherValue = n[i][j];
				row = i;
				col = j;
			}
		}
	}

	printf("%d %d %d\n", secondHigherValue, row, col);

	return 0;
}
