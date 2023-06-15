#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0, lowerCount = 0, upperCount = 0;

	scanf("%99[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (isupper(input[i]) != 0) {
			upperCount++;
		} else if (islower(input[i]) != 0) {
			lowerCount++;
		}
	}

	printf("%d %d\n", lowerCount, upperCount);

	return 0;
}
