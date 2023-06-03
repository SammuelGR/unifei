#include <stdio.h>

int main() {
	int languagesQuantity = 0;
	char gender = '\0', educationLevel = '\0';

	scanf("%d %c %c", &languagesQuantity, &gender, &educationLevel);

	switch (educationLevel) {
	case 'M':
		if (gender == 'M') {
			printf(languagesQuantity >= 2 ? "sim" : "nao");
		}
		else {
			printf(languagesQuantity >= 3 ? "sim" : "nao");
		}
		break;
	case 'S':
		if (gender == 'M') {
			printf(languagesQuantity >= 1 ? "sim" : "nao");
		}
		else {
			printf(languagesQuantity >= 2 ? "sim" : "nao");
		}
		break;

	default:
		break;
	}

	printf("\n");

	return 0;
}
