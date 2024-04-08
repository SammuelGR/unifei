#include <stdio.h>

int main() {
	int num;
	float average;

	scanf("%d", &num);
	average = num;

	scanf("%d", &num);
	average += num;

	scanf("%d", &num);
	average += num;

	average /= 3.0;

	printf("%f\n", average);

	return 0;
}
