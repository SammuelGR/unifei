#include <stdio.h>

int main() {
    int userNumber = 0, i = 0;

    scanf("%d", &userNumber);

    for (i = 0; i < userNumber; i++) {
        printf("%d ", userNumber - i);
    }
    
    printf("\n");

    return 0;
}
