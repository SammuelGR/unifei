#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 12

int main() {
	char cpfStr[SIZE], auxStr[2];
	long long int cpf = 0;
	int numbers[10] = { 0 }, i = 0;

	scanf("%lld", &cpf);

	sprintf(cpfStr, "%lld", cpf);

	for (i = 0; i < SIZE - 1; i++) {
		auxStr[0] = cpfStr[i];
		numbers[atoi(auxStr)]++;
	}

	for (i = 0; i < 10; i++) {
		printf("%d = %d\n", i, numbers[i]);
	}

	return 0;
}
