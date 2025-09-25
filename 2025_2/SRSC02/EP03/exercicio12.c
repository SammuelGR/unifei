/*
 * exercicio12.c
 *
 * Created on: 22 de set de 2025
 *
 * Utiliza duas threads para trabalhar o intervalo [a, b]
 * Uma thread computa a soma dos valores pares, a outra computa o produto dos
 * termos impares
 *
 */

#include <stdio.h>
#include <pthread.h>

typedef struct { int a, b; long long r; } Intervalo;

void *soma_pares(void *arg) {
    Intervalo *intervalo = (Intervalo *)arg;
    long long soma = 0;
    int i;

    for (i = intervalo->a; i <= intervalo->b; i++) {
        if (i % 2 == 0) soma += i;
    }
    intervalo->r = soma;

    return NULL;
}

void *prod_impares(void *arg) {
    Intervalo *intervalo = (Intervalo *)arg;
    long long produto = 1;
    int i;

    int temImpares = 0;

    for (i = intervalo->a; i <= intervalo->b; i++) {
        if (i % 2 != 0) {
            produto *= i;
            temImpares = 1;
        }
    }

    intervalo->r = temImpares ? produto : 0;   // se não houver ímpares no intervalo, retorna 0
    return NULL;
}

int main(void) {
    int a, b;
    pthread_t t1, t2;
    Intervalo I1, I2;

    scanf("%d %d", &a, &b);
    I1.a = I2.a = a;
    I1.b = I2.b = b;

    /* cria threads */
    pthread_create(&t1, NULL, soma_pares, &I1);
    pthread_create(&t2, NULL, prod_impares, &I2);

    /* aguarda terminar */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /* imprime respostas */
    printf("Soma dos pares: %lld\n", I1.r);
    printf("Produto dos impares: %lld\n", I2.r);

    return 0;
}
