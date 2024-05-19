#define STR_SIZE 50
#define NUMS_SIZE 4

#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[STR_SIZE];
	int nums[NUMS_SIZE], sum = 0;
	int i;

	for (i = 0; i < NUMS_SIZE; i++) {
		scanf(" %s", str);
		nums[i] = atoi(str);
	}

	for (i = 0; i < NUMS_SIZE; i++) {
		sum += nums[i];
	}

	printf("%d\n", sum);

	return 0;
}
