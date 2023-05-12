#include <stdio.h>

int main() {
    int state = 0;
    float price = 0.0, finalPrice = 0.0;

    printf("Digite o preco do produto: ");
    scanf("%f", &price);

    printf("Digite o estado, de acordo com a tabela:\n");
    printf("1 = MG\n");
    printf("2 = SP\n");
    printf("3 = RJ\n");
    printf("4 = ES\n");
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

    printf("Valor final: R$ %.2f\n", finalPrice);
    
    return 0;
}