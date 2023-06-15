#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0, aCounter = 0, result = 0;

	scanf("%99s", input);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == 'a') aCounter++;
	}

	if (aCounter > (strlen(input) / 2)) {
		result = strlen(input);
	} else {
		result = aCounter - 1 + aCounter;
	}

	printf("%d\n", result);

	return 0;
}
