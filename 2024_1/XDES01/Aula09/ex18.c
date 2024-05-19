#define SIZE 30

#include <stdio.h>
#include <string.h>

int main() {
	char strA[SIZE], strB[SIZE], fullStr[SIZE * 2] = "";

	scanf(" %s", strA);
	scanf(" %s", strB);

	strcat(fullStr, strA);
	strcat(fullStr, " ");
	strcat(fullStr, strB);

	printf("%s\n", fullStr);

	return 0;
}
