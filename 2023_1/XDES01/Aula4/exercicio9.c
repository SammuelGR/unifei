#include <stdio.h>

int main() {
    int totalClassHours = 0, absencesHours = 0;
    float absencesHoursPercentage = 0.0;

    printf("Digite a carga horaria total da disciplina: ");
    scanf("%d", &totalClassHours);

    printf("Digite as horas de faltas acumuladas: ");
    scanf("%d", &absencesHours);

    absencesHoursPercentage = (float)absencesHours / (float)totalClassHours * 100;

    printf("A porcentagem de faltas eh %.2f%%\n", absencesHoursPercentage);

    return 0;
}