#include <stdio.h>

int main() {
    int yearOfBirth = 0, currentYear = 0, age = 0;

    printf("Digite o ano de nascimento da pessoa: ");
    scanf("%d", &yearOfBirth);

    printf("Digite o ano em que estamos: ");
    scanf("%d", &currentYear);

    age = currentYear - yearOfBirth;

    printf("Idade em anos: %d anos\n", age);
    printf("Idade em meses: %d meses\n", age * 12);
    printf("Idade em dias: %d dias\n", age * 365);

    return 0;
}
