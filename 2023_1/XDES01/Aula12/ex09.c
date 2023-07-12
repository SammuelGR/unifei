#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int somafat(int n);

int main() {
	int n = 0;

	scanf("%d", &n);

	printf("%d", somafat(n));

	return 0;
}

int somafat(int n) {
	long long int fat = 1;
	int i = 0, length = 0, sum = 0;
	char fatStr[20], auxStr[2];

	for (i = 0; i < n; i++) {
		fat *= n - i;
	}

	length = sprintf(fatStr, "%lld", fat);
	fatStr[length] = '\0';

	auxStr[1] = '\0';
	for (i = 0; i < length; i++) {
		strncpy(auxStr, fatStr + i, 1);
		sum += atoi(auxStr);
	}

	return sum;
}
