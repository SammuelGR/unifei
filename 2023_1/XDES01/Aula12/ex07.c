#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumDigits(int n);

int main() {
	int N = 0;

	scanf("%d", &N);

	printf("%d\n", sumDigits(N));

	return 0;
}

int sumDigits(int n) {
	char numbersString[11], auxStr[2];
	int i = 0, length = 0, sum = 0;

	length = sprintf(numbersString, "%d", n);

	for (i = 0; i < length; i++) {
		strncpy(auxStr, numbersString + i, 1);

		sum += atoi(auxStr);
	}

	return sum;
}
