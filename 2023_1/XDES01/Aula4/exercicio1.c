#include <stdio.h>

int main() {
    float brlValue = 0.0, dollarRate = 0.0;

    printf("Digite um valor em reais: ");
    scanf("%f", &brlValue);

    printf("Digite a cotacao do dolar: ");
    scanf("%f", &dollarRate);

    printf("R$ %.2f = $ %.2f\n", brlValue, brlValue / dollarRate);

    return 0;
}