#define STR_SIZE 51
#define ARRAY_SIZE 8

#include <stdio.h>
#include <string.h>

typedef struct book {
	char title[STR_SIZE];
	char author[STR_SIZE];
	int year;
} book;

int main() {
	book books[ARRAY_SIZE];
	char searchText[STR_SIZE], exitText[5] = "sair";
	int i = 0;

	for (i = 0; i < ARRAY_SIZE; i++) {
		scanf(" %50[^\n]", books[i].title);
		scanf(" %50[^\n]", books[i].author);
		scanf("%d", &books[i].year);
	}

	do {
		scanf(" %50[^\n]", searchText);

		if (strcmp(searchText, exitText) != 0) {
			printf("Livros de %s:\n", searchText);

			for (i = 0; i < ARRAY_SIZE; i++) {
				if (strcmp(books[i].author, searchText) == 0) {
					printf("%s (%d)\n", books[i].title, books[i].year);
				}
			}

			printf("\n");
		}

	} while (strcmp(searchText, exitText) != 0);

	return 0;
}
