#define SIZE 15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int userNumbers[SIZE], winningNumbers[SIZE], *userCorrectNumbers = NULL;
	int i, j, correctNumbersCount = 0, count = 0;

	srand(time(NULL));

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &userNumbers[i]);
	}


	for (i = 0; i < SIZE; i++) {
		winningNumbers[i] = rand() % 25 + 1;
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (userNumbers[i] == winningNumbers[j]) correctNumbersCount++;
		}
	}

	if (correctNumbersCount > 0) {
		userCorrectNumbers = (int *)malloc(correctNumbersCount * sizeof(int));

		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if (userNumbers[i] == winningNumbers[j]) {
					*(userCorrectNumbers + count) = winningNumbers[j];
					count++;
				}
			}
		}


		for (i = 0; i < correctNumbersCount; i++) {
			printf("%d ", *(userCorrectNumbers + i));
		}
		printf("\n");
	}

	free(userCorrectNumbers);

	return 0;
}
