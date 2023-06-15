#include <stdio.h>

#define SIZE 100

int main() {
	char strA[SIZE], strB[SIZE], strC[SIZE], strD[SIZE], strSum[SIZE];
	int numA = 0, numB = 0, numC = 0, numD = 0, numSum = 0;

	scanf("%99s", strA);
	scanf("%99s", strB);
	scanf("%99s", strC);
	scanf("%99s", strD);

	sscanf(strA, "%d", &numA);
	sscanf(strB, "%d", &numB);
	sscanf(strC, "%d", &numC);
	sscanf(strD, "%d", &numD);

	numSum = numA + numB + numC + numD;

	sprintf(strSum, "%d", numSum);
	printf("%s\n", strSum);

	return 0;
}
