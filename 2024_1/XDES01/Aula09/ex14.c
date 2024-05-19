#define STR_SIZE 12

#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int num;
	char str[STR_SIZE], aux[2] = "0";
	int counter[10] = { 0 }, i, currentNumber;

	scanf("%lld", &num);
	sprintf(str, "%lld", num);

	for (i = 0; i < STR_SIZE - 1; i++) {
		aux[0] = str[i];
		currentNumber = atoi(aux);

		counter[currentNumber]++;
	}

	for (i = 0; i < 10; i++) {
		printf("%d = %d\n", i, counter[i]);
	}

	return 0;
}
