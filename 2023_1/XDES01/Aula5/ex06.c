#include <stdio.h>

int main() {
    float salary = 0.0, installment = 0.0;

    scanf("%f %f", &salary, &installment);


    if ((installment / salary) * 100 > 20) {
        printf("emprestimo nao concedido\n");
    } else {
        printf("emprestimo concedido\n");
    }

    return 0;
}