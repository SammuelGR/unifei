#include <stdio.h>

int main() {
	int age, workingYears;

	scanf("%d %d", &age, &workingYears);

	if (age >= 65 || workingYears >= 30 || (age >= 60 && workingYears >= 25)) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}
