#define STR_SIZE 50
#define NUMS_SIZE 4

#include <stdio.h>

int main() {
	char str[STR_SIZE];
	double nums[NUMS_SIZE], sum = 0.0;
	int i;

	scanf("%[^\n]", str);

	sscanf(str, "%lf %lf %lf %lf", &nums[0], &nums[1], &nums[2], &nums[3]);

	for (i = 0; i < NUMS_SIZE; i++) {
		sum += nums[i];
	}

	printf("%lf\n", sum);

	return 0;
}
