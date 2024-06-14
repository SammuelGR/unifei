#include <stdio.h>
#include <string.h>

int afimb(char *a, char *b);

int main() {
	printf("%d", afimb("ra", "arara"));

	return 0;
}

int afimb(char *a, char *b) {
	int sizeA = strlen(a), sizeB = strlen(b);
	int charsToSkip = sizeB - sizeA;

	if (sizeA > sizeB) return 0;

	if (strcmp(a, b + charsToSkip) == 0) {
		return 1;
	}

	return 0;
}
