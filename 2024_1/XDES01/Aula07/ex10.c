#define SIZE 6

#include <stdio.h>

int main(void) {
	int numbers[SIZE], i, highestValue, secHighestValue;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		if (i == 0) {
			highestValue = numbers[i];
		} else if (numbers[i] > highestValue) {
			highestValue = numbers[i];
		}
	}

	i = 0;
	while (numbers[i] == highestValue) {
		i++;
	};
	if (i == SIZE) i--;

	secHighestValue = numbers[i];

	for (i = 0; i < SIZE; i++) {
		if (numbers[i] != highestValue && numbers[i] > secHighestValue) {
			secHighestValue = numbers[i];
		}
	}

	printf("%d %d\n", highestValue, secHighestValue);

	return 0;
}
