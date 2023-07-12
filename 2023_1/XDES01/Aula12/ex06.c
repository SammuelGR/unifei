#include <stdio.h>

long long int fatorial(int x);
double serie(int n);

int main() {
	int N = 0;

	scanf("%d", &N);

	printf("%lf", serie(N));

	return 0;
}

long long int fatorial(int x) {
	int i = 0;
	long long int total = 1;

	for (i = 0; i < x; i++) {
		total *= x - i;
	}

	return total;
}

double serie(int n) {
	int i = 0;
	double sum = 0.0;

	if (n == 0) return 0.0;

	for (i = 1; i < n; i++) {
		sum += (double)i / fatorial(i * 2);
	}

	return sum;
}
