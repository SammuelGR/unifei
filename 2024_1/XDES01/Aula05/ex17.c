#include <stdio.h>

int main() {
	float diameter, width, height, length;

	scanf("%f %f %f %f", &diameter, &width, &height, &length);

	if (diameter < width && diameter < height && diameter < length) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}
