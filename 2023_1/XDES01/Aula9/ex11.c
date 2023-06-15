#include <stdio.h>

#define SIZE 100

int main() {
	char strA[SIZE], strB[SIZE], strC[SIZE], strD[SIZE];
	int numA = 0, numB = 0, numC = 0, numD = 0, sum;

	scanf("%s", strA);
	scanf("%s", strB);
	scanf("%s", strC);
	scanf("%s", strD);

	sscanf(strA, "%d", &numA);
	sscanf(strB, "%d", &numB);
	sscanf(strC, "%d", &numC);
	sscanf(strD, "%d", &numD);

	sum = numA + numB + numC + numD;

	printf("%d\n", sum);

	return 0;
}
