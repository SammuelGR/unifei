#define SIZE 2

#include <stdio.h>

typedef struct complexNumber {
	float realNumber;
	float imaginaryNumber;
} complexNumber;

int main() {
	complexNumber complexNumbers[SIZE];

	float sum[2] = { 0 }, subtraction[2] = { 0 }, product[2] = { 0 };

	scanf("%f", &complexNumbers[0].realNumber);
	scanf("%f", &complexNumbers[0].imaginaryNumber);
	scanf("%f", &complexNumbers[1].realNumber);
	scanf("%f", &complexNumbers[1].imaginaryNumber);

	sum[0] = complexNumbers[0].realNumber + complexNumbers[1].realNumber;
	sum[1] = complexNumbers[0].imaginaryNumber + complexNumbers[1].imaginaryNumber;
	printf("Soma: %f + (%f)i\n", sum[0], sum[1]);

	subtraction[0] = complexNumbers[0].realNumber - complexNumbers[1].realNumber;
	subtraction[1] = complexNumbers[0].imaginaryNumber - complexNumbers[1].imaginaryNumber;
	printf("Subtracao: %f + (%f)i\n", subtraction[0], subtraction[1]);

	product[0] = (complexNumbers[0].realNumber * complexNumbers[1].realNumber)
		- (complexNumbers[0].imaginaryNumber * complexNumbers[1].imaginaryNumber);

	product[1] = (complexNumbers[0].realNumber * complexNumbers[1].imaginaryNumber)
		+ (complexNumbers[1].realNumber * complexNumbers[0].imaginaryNumber);

	printf("Produto: %f + (%f)i\n", product[0], product[1]);

	return 0;
}
