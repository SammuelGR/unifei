#include <stdio.h>

int main() {
	float height, result;
	char gender;

	scanf("%f %c", &height, &gender);

	if (gender == 'm') {
		result = (height * 72.7) - 58;
	} else {
		result = (height * 62.1) - 44.7;
	}

	printf("%f\n", result);

	return 0;
}
