#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char text[100];
	int size, i, counter = 0;

	scanf("%[^\n]", text);

	size = strlen(text);

	for (i = 0; i < size; i++) {
		switch (tolower(text[i])) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				counter++;
				break;
			default:
				break;
		}
	}

	printf("%d\n", counter);

	return 0;
}
