#include <stdio.h>

int main() {
    int result = 0;
    float childWeight = 0.0;

    scanf("%f", &childWeight);

    result = (childWeight / 2) * 5;

    printf("%d\n", result);

    return 0;
}