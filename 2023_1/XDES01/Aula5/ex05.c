#include <stdio.h>

int main() {
    float gradeA = 0.0, gradeB = 0.0;

    scanf("%f %f", &gradeA, &gradeB);

    if (gradeA > 10 || gradeA < 0 || gradeB > 10 || gradeB < 0) {
        printf("notas incorretas\n");
    } else {
        printf("%f\n", (gradeA + gradeB) / 2.0);
    }

    return 0;
}