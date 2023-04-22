#include <stdio.h>

int main() {
    float salaryValue = 0;

    printf("Digite o salario do funcionario: ");
    scanf("%f", &salaryValue);

    printf("Novo salario: R$ %.2f\n", salaryValue * 1.2);

    return 0;
}