#include <stdio.h>

int main() {
    int userNumber = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &userNumber);

    if (userNumber % 11 == 0) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}