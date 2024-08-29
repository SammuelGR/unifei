#include <stdio.h>

long unsigned int fatorial(long unsigned n);

int main(void) {
	printf("!10 = %lu\n", fatorial(10));
	printf("!5 = %lu\n", fatorial(5));

	return 0;
}

long unsigned int fatorial(long unsigned n) {
	if (n == 0) return 1;

	return n * fatorial(n - 1);
}
