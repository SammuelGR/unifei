#include <stdio.h>

int main() {
	int sallary;
	float installment;

	scanf("%d %f", &sallary, &installment);


	if (installment / sallary >= 0.2) {
		printf("emprestimo nao concedido\n");
	} else {
		printf("emprestimo concedido\n");
	}

	return 0;
}
