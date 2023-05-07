#include <stdio.h>

int main() {
    int totalClassHours = 0, absencesHours = 0;
    float absencesHoursPercentage = 0.0;

    scanf("%d", &totalClassHours);

    scanf("%d", &absencesHours);

    absencesHoursPercentage = (float)absencesHours / (float)totalClassHours * 100;

    printf("%d\n", (int) absencesHoursPercentage);

    return 0;
}