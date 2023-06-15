#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0;

	scanf("%99[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (i == 0 || input[i - 1] == ' ') {
			input[i] = toupper(input[i]);
		}
	}

	printf("%s\n", input);

	return 0;
}
