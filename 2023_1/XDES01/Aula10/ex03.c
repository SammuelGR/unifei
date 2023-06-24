#include <stdio.h>

#define STR_SIZE 51
#define GRADES_SIZE 3
#define STUDENTS_SIZE 5

typedef struct student {
	char name[STR_SIZE];
	long int registrationNumber;
	float testGrades[GRADES_SIZE];
	float gradesAverage;
} student;

int main() {
	student students[STUDENTS_SIZE];
	int i = 0, j = 0;
	int higherFirstGradeIdx = 0;
	float higherFirstGradeValue = 0.0;
	int higherAverageIdx = 0;
	float higherAverageValue = 0.0;

	for (i = 0; i < STUDENTS_SIZE; i++) {
		scanf("%ld", &students[i].registrationNumber);
		scanf(" %50[^\n]", students[i].name);


		for (j = 0; j < GRADES_SIZE; j++) {
			scanf("%f", &students[i].testGrades[j]);

			students[i].gradesAverage += students[i].testGrades[j];
		}
		students[i].gradesAverage /= 3.0;

		if (i == 0 || students[i].testGrades[0] > higherFirstGradeValue) {
			higherFirstGradeValue = students[i].testGrades[0];
			higherFirstGradeIdx = i;
		}

		if (i == 0 || students[i].gradesAverage > higherAverageValue) {
			higherAverageValue = students[i].gradesAverage;
			higherAverageIdx = i;
		}
	}

	printf("Maior nota na P1: %.2f\n", higherFirstGradeValue);
	printf("%s\n\n", students[higherFirstGradeIdx].name);

	printf("Maior media: %s\n", students[higherAverageIdx].name);
	printf("Valor: %.2f\n\n", higherAverageValue);

	for (i = 0; i < STUDENTS_SIZE; i++) {
		printf("%ld %s ", students[i].registrationNumber, students[i].name);

		if (students[i].gradesAverage < 6.0) {
			printf("Reprovado\n");
		} else {
			printf("Aprovado\n");
		}
	}

	return 0;
}
