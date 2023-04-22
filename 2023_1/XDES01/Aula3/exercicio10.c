#include <stdio.h>

int main() {
    float celsiusValue = 0, fahrenheitValue = 0;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &fahrenheitValue);

    celsiusValue = (fahrenheitValue - 32) / 1.8;

    printf("Temperatura em Celsius: %.2f\n", celsiusValue);

    return 0;
}