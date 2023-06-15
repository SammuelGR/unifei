#include <stdio.h>
#include <string.h>

#define SIZE 100001

int main() {
	char input[SIZE], removedAInput[SIZE], S[SIZE], Si[SIZE], testT[SIZE];
	int inputLen = 0, aCounter = 0, i = 0, removedAIndex = 0, removedALen = 0;
	int diffCounter = 0, halfLen = 0, inputDiffCounter = 0;

	scanf("%100000s", input);
	inputLen = strlen(input);

	for (i = 0; i < inputLen; i++) {
		if (input[i] == 'a') {
			aCounter++;
		} else {
			removedAInput[removedAIndex] = input[i];
			removedAIndex++;
		}
	}
	removedAInput[i] = '\0';
	removedALen = strlen(removedAInput);

	if (inputLen == 1) {
		if (input[0] == 'a') {
			printf("%s\n", input);
		} else {
			printf("%d\n", -1);
		}
	} else if (aCounter == inputLen) {
		printf("%s\n", input);
	} else if (aCounter == 0) {
		if (inputLen % 2 != 0) {
			printf("%d\n", -1);
		} else {
			halfLen = inputLen / 2;

			for (i = 0; i < halfLen; i++) {
				if (input[i] != input[i + halfLen]) inputDiffCounter++;
			}

			if (diffCounter > 0) {
				printf("%d\n", -1);
			} else {
				for (i = 0; i < halfLen; i++) printf("%c", input[i]);
				printf("\n");
			}
		}
	} else if (removedALen % 2 != 0) {
		printf("%d\n", -1);
	} else {
		halfLen = removedALen / 2;
		for (i = 0; i < halfLen; i++) {
			if (removedAInput[i] != removedAInput[i + halfLen]) diffCounter++;
		}

		if (diffCounter > 0) {
			printf("%d\n", -1);
		} else {
			for (i = 0; i < (inputLen - halfLen); i++) {
				S[i] = input[i];
			}
			S[i] = '\0';

			for (i = 0; i < halfLen; i++) {
				Si[i] = removedAInput[i];
			}
			Si[i] = '\0';

			strcat(testT, S);
			strcat(testT, Si);
			testT[strlen(testT)] = '\0';

			if (strcmp(testT, input) == 0) {
				printf("%s\n", S);
			} else {
				printf("%d\n", -1);
			}
		}
	}

	return 0;
}
