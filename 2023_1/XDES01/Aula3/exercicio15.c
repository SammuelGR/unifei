#include <stdio.h>

int main() {
    float distance = 0.0;
    int elapsedTime = 0;

    printf("Digite a distancia em km: ");
    scanf("%f", &distance);

    printf("Digite o tempo em horas: ");
    scanf("%d", &elapsedTime);

    printf("Velocidade media: %.1f km/h\n", distance / elapsedTime);

    return 0;
}