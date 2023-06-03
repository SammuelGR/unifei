#include <stdio.h>

int main() {
	int aRowSize = 0, aColSize = 0, bRowSize = 0, bColSize = 0;
	int i = 0, j = 0;

	scanf("%d %d", &aRowSize, &aColSize);

	int aVec[aRowSize][aColSize];

	for (i = 0; i < aRowSize; i++) {
		for (j = 0; j < aColSize; j++) {
			scanf("%d", &aVec[i][j]);
		}
	}

	scanf("%d %d", &bRowSize, &bColSize);

	int bVec[bRowSize][bColSize];

	for (i = 0; i < bRowSize; i++) {
		for (j = 0; j < bColSize; j++) {
			scanf("%d", &bVec[i][j]);
		}
	}

	if (aRowSize != bRowSize || aColSize != bColSize) {
		printf("impossivel\n");
	}

	else {
		for (i = 0; i < aRowSize; i++) {
			for (j = 0; j < aColSize; j++) {
				printf("%d ", aVec[i][j] + bVec[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
