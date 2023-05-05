#include <stdio.h>

int main() {
    int userValue = 0, i = 0, sum = 0;


    do {
        scanf("%d", &userValue);

        for (i = 0; i < (userValue * 2); i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }

    } while (userValue < 0);

    printf("%d\n", sum);

    return 0;
}