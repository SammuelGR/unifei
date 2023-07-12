#define SIZE 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDate(char date[]);

int main() {
	char date[SIZE];

	scanf("%s", date);

	printDate(date);

	return 0;
}

void printDate(char date[]) {
	char dayStr[3], monthStr[3], yearStr[5];
	char months[12][10] = {
		"janeiro",
		"fevereiro",
		"marco",
		"abril",
		"maio",
		"junho",
		"julho",
		"agosto",
		"setembro",
		"outubro",
		"novembro",
		"dezembro"
	};

	int day = 0, month = 0;

	strncpy(dayStr, date, 2);
	day = atoi(dayStr);

	strncpy(monthStr, date + 3, 2);
	month = atoi(monthStr);

	strncpy(yearStr, date + 6, 4);
	yearStr[5] = '\0';

	printf("%d de %s de %s\n", day, months[month - 1], yearStr);
}
