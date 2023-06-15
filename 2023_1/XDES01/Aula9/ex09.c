#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char text[SIZE], C;
	int I = 0, i = 0, charIndex = -1;

	scanf("%99[^\n]", text);
	scanf(" %c %d", &C, &I);

	for (i = I; i < strlen(text); i++) {
		if (text[i] == C) {
			charIndex = i;
			break;
		}
	}

	printf("%d\n", charIndex);

	return 0;
}
