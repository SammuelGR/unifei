#include <stdio.h>

int main() {
    float celsiusValue = 0, fahrenheitValue = 0;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsiusValue);

    fahrenheitValue = (celsiusValue * 1.8) + 32;

    printf("Temperatura em Fahrenheit: %.2f\n", fahrenheitValue);

    return 0;
}