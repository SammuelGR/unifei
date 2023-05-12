#include <stdio.h>

int main() {
    float height = 0.0;
    char gender;

    scanf("%f %c", &height, &gender);

    printf("%f\n", height);

    switch (gender) {
        case 'f':
        case 'F':
            if (height * 10 < 18) {
                printf("nao\n");
            } else {
                printf("sim\n");
            }

            break;
        case 'm':
        case 'M':
            if (height < 1.75) {
                printf("nao\n");
            } else {
                printf("sim\n");
            }
            
            break;
    }

    return 0;
}