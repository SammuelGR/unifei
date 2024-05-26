#define SIZE 8

#include <stdio.h>

typedef struct Car {
	char brand[30];
	float price;
	int year;
} Car;

int main() {
	Car cars[SIZE];
	int i;
	float P;

	for (i = 0; i < SIZE; i++) {
		scanf(" %[^\n]", cars[i].brand);
		scanf(" %f", &cars[i].price);
		scanf(" %d", &cars[i].year);
	}


	do {
		scanf("%f", &P);

		if (P > 0.0) {
			printf("Carros mais baratos que %.2f:\n", P);

			for (i = 0; i < SIZE; i++) {
				if (cars[i].price < P) {
					printf("%s %.2f %d\n", cars[i].brand, cars[i].price, cars[i].year);
				}
			}
			printf("\n");
		}
	} while (P > 0.0);

	return 0;
}
