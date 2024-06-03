// Faça um programa que declare uma estrutura para o cadastro de N alunos, onde o usuário informa N.
// Armazene as seguintes informações sobre os alunos: matrícula, nome completo e data de nascimento.
// Usando aritmética de ponteiros, leia as informações de N alunos e, a seguir, mostre o nome do aluno mais
// velho e do aluno mais novo.

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	unsigned int registrationNumber;
	char fullName[50];
	int yearOfBirth; // ¯\_(ツ)_/¯
} Student;

int main() {
	int N, i;
	Student *students = NULL;

	scanf("%d", &N);

	students = (Student *)malloc(N * sizeof(Student));

	for (i = 0; i < N; i++) {

	}

	return 0;
}
