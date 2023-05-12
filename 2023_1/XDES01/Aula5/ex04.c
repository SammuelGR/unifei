#include <stdio.h>

int main() {
    int userNumber = 0;

    scanf("%d", &userNumber);

    if (userNumber % 2 == 0) {
        printf("par\n");
    } else {
        printf("impar\n");
    }

    return 0;
}