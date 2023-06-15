#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0;

	scanf("%[^\n]", input);

	for (i = strlen(input) - 1; i >= 0; i--) {
		printf("%c", input[i]);
	}

	printf("\n");

	return 0;
}
