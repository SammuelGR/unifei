#define SIZE 5

#include <stdio.h>

typedef struct Student {
	char name[30];
	long int registrationNumber;
	char course[30];
} Student;

int main() {
	Student students[SIZE];
	int i;

	for (i = 0; i < SIZE; i++) {
		scanf(" %[^\n]", students[i].name);
		scanf("%ld", &students[i].registrationNumber);
		scanf(" %[^\n]", students[i].course);
	}

	for (i = 0; i < SIZE; i++) {
		printf("Aluno %d:\n", i + 1);
		printf("Nome: %s\n", students[i].name);
		printf("Matricula: %ld\n", students[i].registrationNumber);
		printf("Curso: %s\n", students[i].course);
		printf("\n");
	}

	return 0;
}
