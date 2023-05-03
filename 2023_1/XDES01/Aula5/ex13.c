#include <stdio.h>

int main() {
    int age = 0;
    
    scanf("%d", &age);

    if (age >= 4 && age <=5) {
        printf("Fraldinha\n");
    } else if (age >= 6 && age <= 12) {
        printf("Infantil\n");
    } else if (age >= 13 && age <= 18) {
        printf("Juvenil\n");
    } else if (age > 18) {
        printf("Adulto\n");
    }

    return 0;
}