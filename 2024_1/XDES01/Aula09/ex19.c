#define SIZE 50

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE];
	int i, aCounter = 0, size;

	scanf(" %s", text);
	size = strlen(text);

	for (i = 0; i < size; i++) {
		if (tolower(text[i]) == 'a') {
			aCounter++;
		}
	}

	if (aCounter > size / 2) {
		printf("%d\n", size);
	} else {
		printf("%d\n", (aCounter * 2) - 1);
	}

	return 0;
}
