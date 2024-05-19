#define SIZE 100

#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE], textWithoutSpaces[SIZE];
	int i, counter = 0, textSize;

	scanf("%[^\n]", text);

	textSize = strlen(text);

	for (i = 0; i < textSize; i++) {
		if (text[i] != ' ') {
			textWithoutSpaces[counter] = text[i];
			counter++;
		}
	}

	textWithoutSpaces[counter] = '\0';

	printf("%s\n", textWithoutSpaces);

	return 0;
}
