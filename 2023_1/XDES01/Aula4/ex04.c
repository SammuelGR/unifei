#include <stdio.h>

int main() {
    float distance = 0.0, valueA = 0.0, valueB = 0.0;
    int days = 0;

    scanf("%f", &distance);
    scanf("%d", &days);

    valueA = (days * 62) + (1.4 * distance); 
    valueB = (days * 80) + (1.2 * distance); 

    printf("%.2f %.2f\n", valueA, valueB);

    return 0;
}