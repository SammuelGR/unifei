// Faça uma função que receba três notas de um aluno e uma letra. Se a letra for ‘A’, a função deve calcular
// a média aritmética das notas do aluno; se for ‘P’, deve calcular a média ponderada, com pesos 5, 3 e 2. No
// Moodle, insira seu programa completo (main + funções).

#define SIZE 3

#include <stdio.h>

float calculateAverage(float grades[3], char avgType);

int main() {
	int i;
	float grades[SIZE];
	char avgType;

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &grades[i]);
	}

	scanf(" %c", &avgType);

	printf("%.2f\n", calculateAverage(grades, avgType));

	return 0;
}

float calculateAverage(float grades[3], char avgType) {
	int i, weights[3] = { 5, 3, 2 };
	const int weightsSum = 10;

	float sum = 0.0;

	if (avgType == 'A') {
		for (i = 0; i < SIZE; i++) {
			sum += grades[i];
		}

		return sum / SIZE;
	}

	for (i = 0; i < SIZE; i++) {
		sum += grades[i] * weights[i];
	}

	return sum / weightsSum;
}
