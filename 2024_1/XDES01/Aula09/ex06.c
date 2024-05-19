#define SIZE 100

#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE], textWithoutSpaces[SIZE];
	int i, counter = 0, textSize, textWithoutSpacesSize, halfSize;
	int isPalindrome = 1;

	scanf("%[^\n]", text);
	textSize = strlen(text);

	for (i = 0; i < textSize; i++) {
		if (text[i] != ' ') {
			textWithoutSpaces[counter] = text[i];
			counter++;
		}
	}

	textWithoutSpaces[counter] = '\0';
	textWithoutSpacesSize = strlen(textWithoutSpaces);
	halfSize = textWithoutSpacesSize / 2;


	for (i = 0; i < halfSize; i++) {
		if (textWithoutSpaces[i] != textWithoutSpaces[textWithoutSpacesSize - i - 1]) {
			isPalindrome = 0;
		}
	}

	if (isPalindrome) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}
