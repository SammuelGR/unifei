#define TIME_TO_PRODUCE_IN_SECONDS 17

#include <stdio.h>

int main() {
	int quantity, totalSeconds;
	int hours, minutes, seconds;

	scanf("%d", &quantity);

	totalSeconds = quantity * TIME_TO_PRODUCE_IN_SECONDS;

	hours = totalSeconds / 3600;
	totalSeconds -= hours * 3600;

	minutes = totalSeconds / 60;
	totalSeconds -= minutes * 60;

	seconds = totalSeconds;

	printf("%d %d %d\n", hours, minutes, seconds);

	return 0;
}
