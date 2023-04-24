#include <stdio.h>

int main() {
    int piecesAmount = 0, hours = 0, minutes = 0, seconds = 0, totalSeconds = 0;

    printf("Digite a quantidade de pecas que serao produzidas: ");
    scanf("%d", &piecesAmount);

    totalSeconds = piecesAmount * 17;

    seconds = totalSeconds % 60;
    minutes = (totalSeconds / 60) % 60;
    hours = (totalSeconds / (60 * 60)) % 60;

    printf("%d %d %d\n", hours, minutes, seconds);

    return 0;
}