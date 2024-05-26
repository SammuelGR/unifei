#include <stdio.h>

typedef struct ComplexNumber {
	float real;
	float imaginary;
} ComplexNumber;

int main() {
	ComplexNumber A, B;

	scanf("%f %f", &A.real, &A.imaginary);
	scanf("%f %f", &B.real, &B.imaginary);

	printf("Soma: %f + (%f)i\n", A.real + B.real, A.imaginary + B.imaginary);
	printf("Subtracao: %f + (%f)i\n", A.real - B.real, A.imaginary - B.imaginary);
	printf("Produto: %f + (%f)i\n",
		(A.real * B.real) - (A.imaginary * B.imaginary),
		(A.real * B.imaginary) + (A.imaginary * B.real)
	);

	return 0;
}
