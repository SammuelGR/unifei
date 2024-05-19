#define SIZE 100

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE];
	int i, size;

	scanf("%[^\n]", text);
	size = strlen(text);

	text[0] = toupper(text[0]);
	for (i = 0; i < size; i++) {
		if (text[i] == ' ') {
			text[i + 1] = toupper(text[i + 1]);
		}
	}

	printf("%s\n", text);

	return 0;
}
