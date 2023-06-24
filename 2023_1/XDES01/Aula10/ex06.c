#define ARRAY_SIZE 8
#define STR_SIZE 31

#include <stdio.h>

typedef struct car {
	char brand[STR_SIZE];
	double price;
	int year;
} car;

int main() {
	car cars[ARRAY_SIZE];
	int i = 0;
	double P = 0.0;

	for (i = 0; i < ARRAY_SIZE; i++) {
		scanf(" %30[^\n]", cars[i].brand);
		scanf("%lf", &cars[i].price);
		scanf("%d", &cars[i].year);
	}

	do {
		scanf("%lf", &P);

		if (P > 0) {
			printf("Carros mais baratos que %.2lf:\n", P);

			for (i = 0; i < ARRAY_SIZE; i++) {
				if (cars[i].price < P) {
					printf("%s %.2lf %d\n", cars[i].brand, cars[i].price, cars[i].year);
				}
			}

			printf("\n");
		}
	} while (P > 0);

	return 0;
}
