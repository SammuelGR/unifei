#include <stdio.h>
#include <math.h>

int main() {
    int userNumber = 0;
    float result = 0.0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &userNumber);

    if (userNumber > 0) {
        printf("A raiz quadrada de %d eh %f\n", userNumber, sqrt(userNumber));
    } else {
        printf("O numero %d ao quadrado eh %d\n", userNumber, (userNumber * userNumber));
    }
}