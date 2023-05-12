#include <stdio.h>

int main() {
    int userNumber = 0, i = 0;

    do {
    scanf("%d", &userNumber);

    if (userNumber >= 0) {
        for (i = 0; i <= userNumber; i++) {
            printf("%d ", i);
        }
    }
    } while (userNumber < 0);

    printf("\n");

    return 0;
}