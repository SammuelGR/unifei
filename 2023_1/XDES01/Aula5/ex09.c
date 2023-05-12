#include <stdio.h>

int main() {
    int year = 0;

    scanf("%d", &year);

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}