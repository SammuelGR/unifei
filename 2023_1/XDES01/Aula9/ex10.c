#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char A[SIZE], B[SIZE];
	int counter = 0, i = 0;

	scanf("%99[^\n]", A);
	scanf(" %99[^\n]", B);


	for (i = 0; i < strlen(B) - strlen(A) + 1; i++) {
		if (strncmp(A, B + i, strlen(A)) == 0) {
			counter++;
		}
	}

	printf("%d\n", counter);

	return 0;
}
