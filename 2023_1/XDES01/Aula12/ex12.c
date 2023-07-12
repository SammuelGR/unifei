#include <stdio.h>
#include <string.h>

int afimb(char* a, char* b);

int main() {
	printf("%d", afimb("ra", "arara"));

	return 0;
}

int afimb(char* a, char* b) {
	int sizeA = strlen(a);
	int sizeB = strlen(b);

	if (sizeA > sizeB) return 0;
	if (strcmp(a, b) == 0) return 1;

	if (strncmp(a, b + (sizeB - sizeA), sizeA) == 0) {
		return 1;
	}

	return 0;
}
