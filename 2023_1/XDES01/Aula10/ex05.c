#define ARRAY_SIZE 5

#include <stdio.h>
#include <string.h>

typedef struct person {
	char name[31];
	char phoneNumber[16];
} person;

int main() {
	person people[5], aux;
	int i = 0, j = 0;

	for (i = 0; i < ARRAY_SIZE; i++) {
		scanf(" %30[^\n]", people[i].name);
		scanf(" %15[^\n]", people[i].phoneNumber);
	}

	for (i = 0; i < (ARRAY_SIZE - 1); i++) {
		for (j = i + 1; j < ARRAY_SIZE; j++) {
			if (strcmp(people[i].name, people[j].name) > 0) {
				aux = people[i];
				people[i] = people[j];
				people[j] = aux;
			}
		}
	}

	for (i = 0; i < ARRAY_SIZE; i++) {
		printf("%s %s\n", people[i].name, people[i].phoneNumber);
	}

	return 0;
}
