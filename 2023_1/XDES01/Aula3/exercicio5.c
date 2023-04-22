#include <stdio.h>

int main() {
    float userValue = 0;

    printf("Digite um numero real: ");
    scanf("%f", &userValue);

    printf("Resposta: %f\n", userValue/5);
    
    return 0;
}