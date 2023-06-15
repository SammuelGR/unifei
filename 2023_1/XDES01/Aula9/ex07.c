#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char stringA[SIZE], stringB[SIZE];
	int sizeDifference = 0;

	scanf(" %99[^\n]", stringA);
	scanf(" %99[^\n]", stringB);

	sizeDifference = strlen(stringA) - strlen(stringB);

	if (sizeDifference >= 0) {
		printf("A frase 1 possui %d caracteres a mais que a frase 2.\n", sizeDifference);
	} else {
		printf("A frase 1 possui %d caracteres a menos que a frase 2.\n", (-1 * sizeDifference));
	}

	return 0;
}
