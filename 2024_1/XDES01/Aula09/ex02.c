#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char text[100];
	int size, i, vowels[5] = { 0 };

	scanf("%[^\n]", text);

	size = strlen(text);

	for (i = 0; i < size; i++) {
		switch (tolower(text[i])) {
			case 'a':
				vowels[0]++;
				break;
			case 'e':
				vowels[1]++;
				break;
			case 'i':
				vowels[2]++;
				break;
			case 'o':
				vowels[3]++;
				break;
			case 'u':
				vowels[4]++;
				break;
			default:
				break;
		}
	}

	printf("A = %d\n", vowels[0]);
	printf("E = %d\n", vowels[1]);
	printf("I = %d\n", vowels[2]);
	printf("O = %d\n", vowels[3]);
	printf("U = %d\n", vowels[4]);

	return 0;
}
