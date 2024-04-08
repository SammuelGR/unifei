#include <stdio.h>

int main() {
	int totalHours, completedHours;
	int completedPercentage;

	scanf("%d %d", &totalHours, &completedHours);

	completedPercentage = ((1.0 * completedHours) / (1.0 * totalHours)) * 100;

	printf("%d\n", completedPercentage);

	return 0;
}
