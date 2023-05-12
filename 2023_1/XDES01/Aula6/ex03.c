#include <stdio.h>

int main() {
    int userNumber = 0, i = 0;

    scanf("%d", &userNumber);

    for (i = 0; i < (userNumber * 2); i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}