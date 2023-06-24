#include <stdio.h>

#define STR_SIZE 51
#define ARRAY_SIZE 5

typedef struct student {
	char name[STR_SIZE];
	long int registrationNumber;
	char curse[STR_SIZE];
} student;

int main() {
	student students[ARRAY_SIZE];
	int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++) {
		scanf(" %50[^\n]", students[i].name);
		scanf("%ld", &students[i].registrationNumber);
		scanf(" %50[^\n]", students[i].curse);
	}

	for (i = 0; i < ARRAY_SIZE; i++) {
		printf("Aluno %d:\n", i + 1);
		printf("Nome: %s\n", students[i].name);
		printf("Matricula: %ld\n", students[i].registrationNumber);
		printf("Curso: %s\n", students[i].curse);
		printf("\n");
	}

	return 0;
}
