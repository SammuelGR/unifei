#include <stdio.h>

int main() {
    int userNumber = 0;

    scanf("%d", &userNumber);

    if (userNumber % 11 == 0) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}