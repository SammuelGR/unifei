#include <stdio.h>

int main() {
    float productValue = 0.0, discountValue = 0.0;
    int percentageValue = 0;

    printf("Digite o valor do produto a vista: ");
    scanf("%f", &productValue);

    printf("Digite o valor da porcentagem de desconto: ");
    scanf("%d", &percentageValue);

    discountValue = ((1.0 * percentageValue) / 100) * productValue;

    printf("R$ %.2f R$ %.2f\n", (productValue - discountValue), discountValue);

    return 0;
}