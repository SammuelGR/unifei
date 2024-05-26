#define SIZE 5

#include <stdio.h>
#include <string.h>

typedef struct Person {
	char name[30];
	char telNumber[16];
} Person;

int main() {
	Person people[SIZE], aux;
	int i, j;

	for (i = 0; i < SIZE; i++) {
		scanf(" %[^\n]", people[i].name);
		scanf(" %[^\n]", people[i].telNumber);
	}

	for (i = 0; i < SIZE - 1; i++) {
		for (j = i; j < SIZE; j++) {
			if (strcmp(people[i].name, people[j].name) > 0) {
				strcpy(aux.name, people[i].name);
				strcpy(aux.telNumber, people[i].telNumber);

				strcpy(people[i].name, people[j].name);
				strcpy(people[i].telNumber, people[j].telNumber);

				strcpy(people[j].name, aux.name);
				strcpy(people[j].telNumber, aux.telNumber);
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("%s %s\n", people[i].name, people[i].telNumber);
	}

	return 0;
}
