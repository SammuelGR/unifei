/*
 * exercicio11.c
 *
 * Created on: 22 de set de 2025
 *
 * Le h e m, repassa para uma thread que imprime a saudacao.
 *
 */

#include <stdio.h>
#include <pthread.h>

typedef struct { int h, m; } Hora;

void *OLA(void *argumentos) {
    Hora *p = (Hora *)argumentos;

    if (p->h >= 6 && p->h < 12) {
        printf("Bom dia\n");
    } else if (p->h >= 12 && p->h < 18) {
        printf("Boa tarde\n");
    } else {
        printf("Boa noite\n");
    }
    return NULL;
}

int main(void) {
    Hora hp;
    pthread_t t;

    scanf("%d %d", &hp.h, &hp.m);

    pthread_create(&t, NULL, OLA, &hp);
    pthread_join(t, NULL);

    return 0;
}
