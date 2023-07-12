#include <stdio.h>
#include <string.h>

float calculateAverage(float grades[], char averageType);

int main() {
	float grades[3] = { 0.0 };
	char averageType;

	scanf("%f %f %f", &grades[0], &grades[1], &grades[2]);
	scanf(" %c", &averageType);

	printf("%.2f\n", calculateAverage(grades, averageType));

	return 0;
}

float calculateAverage(float grades[], char averageType) {
	float averageSum = 0.0;
	int i = 0;

	if (averageType == 'A') {
		for (i = 0; i < 3; i++) {
			averageSum += grades[i];
		}

		averageSum /= 3.0;

	} else if (averageType == 'P') {
		averageSum += grades[0] * 5.0;
		averageSum += grades[1] * 3.0;
		averageSum += grades[2] * 2.0;

		averageSum /= 10.0;
	}

	return averageSum;
}
