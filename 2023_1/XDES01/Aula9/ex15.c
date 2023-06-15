#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0, counter = 0;

	scanf("%99[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == ' ') counter++;
	}

	printf("%d\n", counter + 1);

	return 0;
}
