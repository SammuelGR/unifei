#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE], trimmedString[SIZE];
	int i = 0, j = 0;

	scanf("%[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] != ' ') {
			trimmedString[j] = input[i];
			j++;
		}
	}

	trimmedString[j] = '\0';

	printf("%s\n", trimmedString);

	return 0;
}
