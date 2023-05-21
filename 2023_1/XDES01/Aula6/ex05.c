#include <stdio.h>

int main() {
    int N = 0, X = 0, i = 0;

    scanf("%d %d", &N, &X);

    for (i = 1; i <= N; i++) {
        printf("%d ", X * i);
    }

    printf("\n");

    return 0;
}