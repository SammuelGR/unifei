#include <stdio.h>

int main() {
	float height;
	char gender;

	scanf("%f %c", &height, &gender);

	if (gender == 'm') {
		if (height >= 1.75) {
			printf("sim\n");
		} else {
			printf("nao\n");
		}
	} else {
		if (height >= 1.8) {
			printf("sim\n");
		} else {
			printf("nao\n");
		}
	}

	return 0;
}
