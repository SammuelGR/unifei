#define SIZE 100

#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
	char textA[SIZE], textB[SIZE];
	int sizeA, sizeB, diff;

	scanf("%[^\n]", textA);
	sizeA = strlen(textA);

	scanf(" %[^\n]", textB);
	sizeB = strlen(textB);

	diff = (int)fabs(sizeA - sizeB);

	printf("A frase 1 possui %d caracteres a %s que a frase 2.\n", diff, sizeA > sizeB ? "mais" : "menos");

	return 0;
}
