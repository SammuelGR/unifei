#include <stdio.h>

int main() {
    float distance = 0.0, valueA = 0.0, valueB = 0.0;
    int days = 0;

    printf("Digite a distancia a ser percorrida: ");
    scanf("%f", &distance);

    printf("Digite a quantidade de dias: ");
    scanf("%d", &days);

    valueA = (days * 62) + (1.4 * distance); 
    valueB = (days * 80) + (1.2 * distance); 

    printf("R$ %.2f R$ %.2f\n", valueA, valueB);

    return 0;
}