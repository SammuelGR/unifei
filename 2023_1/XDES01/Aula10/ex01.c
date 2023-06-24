#include <stdio.h>

#define SIZE 51

typedef struct person {
	char name[SIZE];
	int age;
	char addressStreet[SIZE];
	int addressNumber;
} person;

int main() {
	person inputPerson;

	scanf("%50[^\n]", inputPerson.name);
	scanf("%d", &inputPerson.age);
	scanf(" %50[^\n]", inputPerson.addressStreet);
	scanf("%d", &inputPerson.addressNumber);

	printf("Nome: %s\n", inputPerson.name);
	printf("Idade: %d\n", inputPerson.age);
	printf("Endereco: %s, %d", inputPerson.addressStreet, inputPerson.addressNumber);

	return 0;
}
