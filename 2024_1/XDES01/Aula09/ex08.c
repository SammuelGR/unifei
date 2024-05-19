#define SIZE 100

#include <stdio.h>

int main() {
	char text[SIZE];
	int i, j;

	scanf("%[^\n]", text);
	scanf("%d %d", &i, &j);

	for (i = i; i <= j; i++) {
		printf("%c", text[i]);
	}

	printf("\n");

	return 0;
}
