#include <stdio.h>

int main() {
    int N = 0, X = 0, i = 0, totalSum = 0, currentSum = 0;

    do {
        scanf("%d %d", &N, &X);

        for (i = 0; i < N; i++) {
            currentSum = X * i;
            
            if (currentSum < N) {
                totalSum+= currentSum;
            }
        }
    } while (N < 0 || X < 0);

    printf("%d\n", totalSum);

    return 0;
}