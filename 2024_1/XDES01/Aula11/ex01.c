#include <stdio.h>

int main() {
	int A, B;

	printf("%p\n", &A > &B ? (void*)&A : (void*)&B);

	return 0;
}
