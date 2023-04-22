#include <stdio.h>

int main() {
    float productValue = 0;

    printf("Digite o valor do produto: ");
    scanf("%f", &productValue);

    printf("Valor final com desconto: R$ %.2f", productValue * 0.88);

    return 0;
}