#include <stdio.h>

int main() {
    float productValue = 0.0, discountValue = 0.0;
    int percentageValue = 0;

    scanf("%f", &productValue);

    scanf("%d", &percentageValue);

    discountValue = ((1.0 * percentageValue) / 100) * productValue;

    printf("%.2f %.2f\n", (productValue - discountValue), discountValue);

    return 0;
}