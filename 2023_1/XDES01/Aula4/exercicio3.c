#include <stdio.h>

int main() {
    int childWeight = 0, result = 0;

    printf("Digite o peso da crianca: ");
    scanf("%d", &childWeight);

    result = (childWeight / 2) * 5;

    printf("Sirva %d gotas.\n", result);

    return 0;
}