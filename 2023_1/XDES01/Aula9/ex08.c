#include <stdio.h>

#define SIZE 100

int main() {
	char text[SIZE];
	int initialIndex = 0, finalIndex = 0, i = 0;

	scanf("%99[^\n]", text);
	scanf("%d %d", &initialIndex, &finalIndex);

	for (i = initialIndex; i <= finalIndex; i++) {
		printf("%c", text[i]);
	}

	printf("\n");

	return 0;
}
