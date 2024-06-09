// Faça uma função que recebe um valor N e retorne o valor da soma dos N primeiros termos da série:
// S = 0 + 1/2! + 2/4! + 3/6! + 4/8! + ...

long long int fatorial(int x);
double serie(int n);

#include <stdio.h>

int main() {

	printf("%lf\n", serie(4));

	return 0;
}

long long int fatorial(int x) {
	int i;
	long long int product = 1;

	for (i = x; i > 0; i--) product *= i;

	return product;
}

double serie(int n) {
	double S = 0.0, i = 0.0, j = 0.0;

	while (n--) {
		S += (double)(i / fatorial(j));

		i++;
		j += 2;
	}

	return S;
}
