#define DATE_SIZE 11
#define MONTHS_SIZE 12
#define MONTHS_MAX_LENGTH 10

#include <stdio.h>
#include <string.h>

void printDate(char dateStr[]);

int main() {
	char dateStr[DATE_SIZE];

	scanf("%s", dateStr);

	printDate(dateStr);

	return 0;
}

void printDate(char dateStr[]) {
	char months[MONTHS_SIZE][MONTHS_MAX_LENGTH] = {
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

	char dayStr[3], monthStr[3], yearStr[5];
	int day, month, year;

	strncpy(dayStr, dateStr, 2);
	dayStr[2] = '\0';
	sscanf(dayStr, "%d", &day);

	strncpy(monthStr, dateStr + 3, 2);
	monthStr[2] = '\0';
	sscanf(monthStr, "%d", &month);

	strncpy(yearStr, dateStr + 6, 4);
	yearStr[4] = '\0';
	sscanf(yearStr, "%d", &year);

	printf("%d de %s de %d", day, months[month - 1], year);
}
