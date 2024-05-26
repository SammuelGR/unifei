#define STUDENTS_SIZE 5
#define GRADES_SIZE 3

#include <stdio.h>

typedef struct Student {
	long int registrationNumber;
	char name[30];
	float grades[3];
	float gradesAverage;
} Student;

int main() {
	Student students[STUDENTS_SIZE];
	int i, j;
	int higherP1GradeIdx = 0, higherGradesAvgIdx = 0;
	float higherP1Grade, gradesAverage, higherGradesAvg;

	for (i = 0; i < STUDENTS_SIZE; i++) {
		scanf("%ld", &students[i].registrationNumber);
		scanf(" %[^\n]", students[i].name);

		gradesAverage = 0.0;
		for (j = 0; j < GRADES_SIZE; j++) {
			scanf("%f", &students[i].grades[j]);
			gradesAverage += students[i].grades[j];
		}

		gradesAverage /= 3.0;
		students[i].gradesAverage = gradesAverage;
	}

	higherP1Grade = students[0].grades[0];
	higherGradesAvg = students[0].gradesAverage;
	for (i = 1; i < STUDENTS_SIZE; i++) {
		if (students[i].grades[0] > higherP1Grade) {
			higherP1GradeIdx = i;
			higherP1Grade = students[i].grades[0];
		}

		if (students[i].gradesAverage > higherGradesAvg) {
			higherGradesAvg = students[i].gradesAverage;
			higherGradesAvgIdx = i;
		}
	}

	printf("Maior nota na P1: %.2f\n", higherP1Grade);
	printf("%s\n\n", students[higherP1GradeIdx].name);

	printf("Maior media: %s\n", students[higherGradesAvgIdx].name);
	printf("Valor: %.2f\n\n", students[higherP1GradeIdx].gradesAverage);

	for (i = 0; i < STUDENTS_SIZE; i++) {
		printf("%ld %s %s\n",
			students[i].registrationNumber,
			students[i].name,
			students[i].gradesAverage >= 6.0 ? "Aprovado" : "Reprovado");
	}

	return 0;
}
