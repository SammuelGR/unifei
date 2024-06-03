#include <stdio.h>

int main() {
	int intNum = 10, *pInt = NULL;
	float floatNum = 10.0, *pFloat = NULL;
	char character = 'S', *pChar = NULL;

	pInt = &intNum;
	pFloat = &floatNum;
	pChar = &character;

	printf("%d\n%f\n%c\n", intNum, floatNum, character);

	*pInt = 20;
	*pFloat = 20.0;
	*pChar = 'N';

	printf("%d\n%f\n%c\n", intNum, floatNum, character);

	return 0;
}
