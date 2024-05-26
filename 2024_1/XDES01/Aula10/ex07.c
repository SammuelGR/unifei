#define SIZE 8

#include <stdio.h>
#include <string.h>

typedef struct Book {
	char title[50];
	char author[30];
	int year;
} Book;

int main() {
	Book books[SIZE];
	int i;
	char search[30];

	for (i = 0; i < SIZE; i++) {
		scanf(" %[^\n]", books[i].title);
		scanf(" %[^\n]", books[i].author);
		scanf(" %d", &books[i].year);
	}

	do {
		scanf(" %[^\n]", search);

		if (strcmp(search, "sair") != 0) {
			printf("Livros de %s:\n", search);

			for (i = 0; i < SIZE; i++) {
				if (strcmp(search, books[i].author) == 0) {
					printf("%s (%d)\n", books[i].title, books[i].year);
				}
			}

			printf("\n");
		}
	} while (strcmp(search, "sair") != 0);

	return 0;
}
