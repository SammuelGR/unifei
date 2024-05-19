#define SIZE 100

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE];
	int i, size, upperCounter = 0, lowerCounter = 0;

	scanf("%[^\n]", text);
	size = strlen(text);

	for (i = 0; i < size; i++) {
		if (isupper(text[i])) {
			upperCounter++;
		} else if (islower(text[i])) {
			lowerCounter++;
		}
	}

	printf("%d %d", lowerCounter, upperCounter);

	return 0;
}
