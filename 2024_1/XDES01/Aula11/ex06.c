#define SIZE 80

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	char phrase[SIZE + 1], *p = NULL;
	int size, i;

	p = phrase;

	scanf(" %[^\n]", p);
	size = strlen(p);

	for (i = size - 1; i >= 0; i--) {
		printf("%c", toupper(*(p + i)));
	}

	printf("\n");

	return 0;
}
