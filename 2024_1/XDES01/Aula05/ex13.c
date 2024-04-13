#include <stdio.h>

int main() {
	int age;

	scanf("%d", &age);

	if (age >= 4 && age <= 5) {
		printf("Fraldinha\n");
	} else if (age <= 12) {
		printf("Infantil\n");
	} else if (age <= 18) {
		printf("Juvenil\n");
	} else {
		printf("Adulto\n");
	}

	return 0;
}
