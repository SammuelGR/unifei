#include <stdio.h>

int main() {
    int state = 0;
    float price = 0.0, finalPrice = 0.0;

    scanf("%f", &price);
    scanf("%d", &state);

    switch (state) {
        case 1:
            finalPrice = price * 1.12;
            break;
        case 2:
            finalPrice = price * 1.07;
            break;
        case 3:
            finalPrice = price * 1.15;
            break;
        case 4:
            finalPrice = price * 1.08;
            break;
    }

    printf("%.2f\n", finalPrice);
    
    return 0;
}