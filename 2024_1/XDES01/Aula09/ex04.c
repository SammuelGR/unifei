#define SIZE 100

#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE];
	int size, i;

	scanf("%[^\n]", text);

	size = strlen(text);

	for (i = size - 1; i >= 0; i--) {
		printf("%c", text[i]);
	}

	printf("\n");

	return 0;
}
