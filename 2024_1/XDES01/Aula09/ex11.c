#define SIZE 15
#include <stdio.h>

int main() {
	char A[SIZE], B[SIZE], C[SIZE], D[SIZE];
	int iA, iB, iC, iD, sum = 0;

	scanf("%s %s %s %s", A, B, C, D);
	sscanf(A, "%d", &iA);
	sscanf(B, "%d", &iB);
	sscanf(C, "%d", &iC);
	sscanf(D, "%d", &iD);

	sum = iA + iB + iC + iD;

	printf("%d\n", sum);

	return 0;
}
