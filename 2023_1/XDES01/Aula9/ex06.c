#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE], trimmedString[SIZE];
	int i = 0, j = 0, counter = 0;

	scanf("%99[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] != ' ') {
			trimmedString[j] = input[i];
			j++;
		}
	}

	trimmedString[j] = '\0';

	for (i = 0; i < strlen(trimmedString); i++) {
		if (trimmedString[i] != trimmedString[strlen(trimmedString) - 1 - i]) {
			counter++;
		}
	}

	if (counter == 0) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}

