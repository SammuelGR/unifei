#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
	char input[SIZE];
	int i = 0, counter = 0;

	scanf("%[^\n]", input);

	for (i = 0; i < strlen(input); i++) {
		if (input[i] == 'a'
			|| input[i] == 'A'
			|| input[i] == 'e'
			|| input[i] == 'E'
			|| input[i] == 'i'
			|| input[i] == 'I'
			|| input[i] == 'o'
			|| input[i] == 'O'
			|| input[i] == 'u'
			|| input[i] == 'U'
			) {
			counter++;
		}
	}

	printf("%d\n", counter);

	return 0;
}
