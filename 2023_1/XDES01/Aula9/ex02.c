#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0, vowelCounter[5] = { 0 };

	scanf("%[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == 'a' || input[i] == 'A') {
			vowelCounter[0]++;
		} else if (input[i] == 'e' || input[i] == 'E') {
			vowelCounter[1]++;
		} else if (input[i] == 'i' || input[i] == 'I') {
			vowelCounter[2]++;
		} else if (input[i] == 'o' || input[i] == 'O') {
			vowelCounter[3]++;
		} else if (input[i] == 'u' || input[i] == 'U') {
			vowelCounter[4]++;
		}

	}

	printf("A = %d\n", vowelCounter[0]);
	printf("E = %d\n", vowelCounter[1]);
	printf("I = %d\n", vowelCounter[2]);
	printf("O = %d\n", vowelCounter[3]);
	printf("U = %d\n", vowelCounter[4]);

	return 0;
}
