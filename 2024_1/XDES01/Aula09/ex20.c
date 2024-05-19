#define SIZE 100001

#include <stdio.h>
#include <string.h>

int main() {
	char T[SIZE], S[SIZE], Si[SIZE], Ti[SIZE];
	int sizeT, sizeSi, i, idx = 0, isEqual = 1;

	scanf(" %s", T);
	sizeT = strlen(T);

	for (i = 0; i < sizeT; i++) {
		if (T[i] != 'a') {
			Si[idx] = T[i];
			idx++;
		}
	}

	Si[idx] = '\0';
	sizeSi = strlen(Si);

	if (sizeSi % 2 != 0) {
		printf("%d\n", -1);
	} else {
		for (i = 0; i < sizeSi / 2; i++) {
			if (Si[i] != Si[i + sizeSi / 2]) isEqual = 0;
		}

		if (isEqual == 0) {
			printf("%d\n", -1);
		} else {
			Si[idx / 2] = '\0';
			sizeSi = strlen(Si);

			for (i = 0; i < sizeT - sizeSi; i++) {
				S[i] = T[i];
			}

			strcat(Ti, S);
			strcat(Ti, Si);

			if (strcmp(Ti, T) != 0) {
				printf("%d\n", -1);
			} else {
				for (i = 0; i < sizeT - sizeSi; i++) {
					printf("%c", T[i]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
