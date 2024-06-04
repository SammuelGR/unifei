#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	unsigned int registrationNumber;
	char fullName[50];
	char birthDate[11]; // DD/MM/YYYY
	int bDay;
	int bMonth;
	int bYear;
} Student;

int main() {
	Student *students = NULL;
	int N, i;
	int youngestIdx = 0, eldestIdx = 0;
	char auxDay[3], auxMonth[3], auxYear[5];

	scanf("%d", &N);

	students = (Student *)malloc(N * sizeof(Student));

	for (i = 0; i < N; i++) {
		scanf("%u", &(students + i)->registrationNumber);
		scanf(" %[^\n]", (students + i)->fullName);
		scanf(" %[^\n]", (students + i)->birthDate);

		strncpy(auxDay, (students + i)->birthDate, 2); // *DD*/MM/YYYY
		strncpy(auxMonth, (students + i)->birthDate + 3, 2); // DD/*MM*/YYYY
		strncpy(auxYear, (students + i)->birthDate + 6, 4); // DD/MM/*YYYY*

		auxDay[2] = '\0';
		auxMonth[2] = '\0';
		auxYear[4] = '\0';

		sscanf(auxDay, "%d", &(students + i)->bDay);
		sscanf(auxMonth, "%d", &(students + i)->bMonth);
		sscanf(auxYear, "%d", &(students + i)->bYear);
	}


	for (i = 1; i < N; i++) {
		if ((students + i)->bYear < (students + eldestIdx)->bYear) {
			eldestIdx = i;
		} else if ((students + i)->bYear == (students + eldestIdx)->bYear) {
			if ((students + i)->bMonth < (students + eldestIdx)->bMonth) {
				eldestIdx = i;
			} else if ((students + i)->bMonth == (students + eldestIdx)->bMonth) {
				if ((students + i)->bDay < (students + eldestIdx)->bDay) {
					eldestIdx = i;
				}
			}
		}

		if ((students + i)->bYear > (students + youngestIdx)->bYear) {
			youngestIdx = i;
		} else if ((students + i)->bYear == (students + youngestIdx)->bYear) {
			if ((students + i)->bMonth > (students + youngestIdx)->bMonth) {
				youngestIdx = i;
			} else if ((students + i)->bMonth == (students + youngestIdx)->bMonth) {
				if ((students + i)->bDay > (students + youngestIdx)->bDay) {
					youngestIdx = i;
				}
			}
		}
	}

	printf("%s\n", (students + eldestIdx)->fullName);
	printf("%s\n", (students + youngestIdx)->fullName);

	free(students);

	return 0;
}


// INPUT EXAMPLE:
// 4
// 123
// Aleatorio Da Silva
// 01/02/2000
// 321
// Mais Novo
// 01/01/2001
// 333
// Mais Velho
// 31/12/1999
// 8421
// Outro Aleatorio
// 02/02/2000
