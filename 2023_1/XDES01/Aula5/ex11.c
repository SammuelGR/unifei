#include <stdio.h>

int main() {
    int age = 0, workingYears = 0;

    printf("Digite a idade: ");
    scanf("%d", &age);

    printf("Digite o tempo de servico, em anos: ");
    scanf("%d", &workingYears);

    if (age >= 65 || workingYears >= 30 || (age >= 60 && workingYears >= 25)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}