#include <stdio.h>

int main() {
	int angles[3] = { 0 }, i = 0, highestAngle = 0;

	for (i = 0; i < 3; i++) {
		scanf("%d", &angles[i]);

		if (i == 0 || angles[i] > highestAngle)
			highestAngle = angles[i];
	}

	if (highestAngle < 90) {
		printf("acutangulo\n");
	}
	else if (highestAngle == 90) {
		printf("retangulo\n");
	}
	else {
		printf("obtusangulo\n");
	}

	return 0;
}
