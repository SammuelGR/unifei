#include <stdio.h>

int main() {
    float brlValue = 0.0, dollarRate = 0.0;

    scanf("%f", &brlValue);

    scanf("%f", &dollarRate);

    printf("%.2f\n", brlValue / dollarRate);

    return 0;
}