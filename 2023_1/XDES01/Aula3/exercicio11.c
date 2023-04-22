#include <stdio.h>
#include <math.h>

int main() {
    float degreesValue = 0, radiansValue = 0;

    printf("Digite o valor do angulo em graus: ");
    scanf("%f", &degreesValue);

    radiansValue = degreesValue * (M_PI / 180);

    printf("Angulo em radianos: %f\n", radiansValue);

    return 0;
}