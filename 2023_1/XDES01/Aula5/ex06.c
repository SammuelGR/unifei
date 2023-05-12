#include <stdio.h>

int main() {
    float salary = 0.0, installment = 0.0;

    printf("Digite o valor do salario: ");
    scanf("%f", &salary);

    printf("Digite o valor da parcela do emprestimo: ");
    scanf("%f", &installment);

    if ((installment / salary) * 100 > 20) {
        printf("emprestimo nao concedido\n");
    } else {
        printf("emprestimo concedido\n");
    }

    return 0;
}