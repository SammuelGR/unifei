#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char stringWithNumbers[SIZE], aux[SIZE];
	int i = 0, lastSpaceIdx = -1, counter = 0;
	double numbers[4], sum;

	scanf("%[^\n]", stringWithNumbers);

	for (i = 0; i < strlen(stringWithNumbers); i++) {
		if (stringWithNumbers[i] == ' ' || i == strlen(stringWithNumbers) - 1) {
			strncpy(aux, stringWithNumbers + lastSpaceIdx + 1, i);

			sscanf(aux, "%lf", &numbers[counter]);

			lastSpaceIdx = i;
			counter++;
		}
	}

	for (i = 0; i < 4; i++) {
		sum += numbers[i];
	}

	printf("%lf\n", sum);

	return 0;
}
