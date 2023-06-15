#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char inputA[SIZE], inputB[SIZE], result[(SIZE * 2) + 1];

	scanf("%99s", inputA);
	strncat(result, inputA, strlen(inputA));

	result[strlen(inputA)] = ' ';

	scanf(" %99s", inputB);
	strncat(result, inputB, strlen(inputB));

	printf("%s\n", result);

	return 0;
}
