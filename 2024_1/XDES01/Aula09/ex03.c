#define SIZE 100

#include <stdio.h>
#include <string.h>

int main() {
	char text[SIZE];
	int i = 0, size, counter = 0;

	scanf("%[^\n]", text);

	size = strlen(text);

	for (i = 0; i < size; i++) {
		if (text[i] == ' ') {
			counter++;
		}
	}

	printf("%d\n", counter);

	return 0;
}
