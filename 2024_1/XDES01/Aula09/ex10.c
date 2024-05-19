#define SIZE 100

#include <stdio.h>
#include <string.h>

int main() {
	char A[SIZE], B[SIZE];
	int sizeA, sizeB, i, j, isEqual = 1, counter = 0;

	scanf("%s %s", A, B);
	sizeA = strlen(A);
	sizeB = strlen(B);


	for (i = 0; i < sizeB - sizeA + 1; i++) {
		for (j = 0; j < sizeA; j++) {
			if (A[j] != B[i + j]) {
				isEqual = 0;
			}
		}

		if (isEqual) {
			counter++;
		} else {
			isEqual = 1;
		}
	}

	printf("%d\n", counter);

	return 0;
}
