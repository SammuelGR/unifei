#include <stdio.h>

typedef struct Person {
	char name[30];
	int age;
	char addressStreet[50];
	int addressNumber;
} Person;

int main() {
	Person person;

	scanf(" %[^\n]", person.name);
	scanf("%d", &person.age);
	scanf(" %[^\n]", person.addressStreet);
	scanf("%d", &person.addressNumber);

	printf("Nome: %s\n", person.name);
	printf("Idade: %d\n", person.age);
	printf("Endereco: %s, %d\n", person.addressStreet, person.addressNumber);

	return 0;
}
