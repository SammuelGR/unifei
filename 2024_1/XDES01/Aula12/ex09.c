#include <stdio.h>

int somafat(int n);

int main() {
	int n = 4;

	printf("soma fat = %d\n", somafat(n));

	return 0;
}

int somafat(int n) {
	long long int fat = n;
	int rest, sum = 0;

	while (n--) {
		if (n > 0) {
			fat *= n;
		}
	}

	while (fat / 10 >= 1) {
		rest = fat % 10;
		sum += rest;
		fat /= 10;

	}

	sum += fat;

	return sum;
}
