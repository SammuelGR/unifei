/*
 * exercicio3.c
 *
 * Created on: 03 de nov de 2025
 *
 * Authors:
 *
 * Simular atendimento bancário com duas filas (preferencial e normal) e dois
 * caixas usando threads, mutexes e semaforos.
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define NUM_CLIENTES 20
#define NUM_CAIXAS 2

typedef enum { PREFERENCIAL, NORMAL } TipoCliente;

typedef struct Cliente {
    int id;
    TipoCliente tipo;
    sem_t atendido;
    struct Cliente *prox;
} Cliente;

// Filas compartilhadas
Cliente *filaP = NULL;
Cliente *filaN = NULL;
pthread_mutex_t mutexFila = PTHREAD_MUTEX_INITIALIZER;
sem_t semFilaP, semFilaN;

int clientes_atendidos = 0;
pthread_mutex_t mutexContador = PTHREAD_MUTEX_INITIALIZER;

// Adiciona cliente à fila
void entrar_na_fila(Cliente *cliente) {
    pthread_mutex_lock(&mutexFila);
    if (cliente->tipo == PREFERENCIAL) {
        cliente->prox = filaP;
        filaP = cliente;
        printf("Cliente %d (PREFERENCIAL) entrou na fila P.\n", cliente->id);
        sem_post(&semFilaP);
    } else {
        cliente->prox = filaN;
        filaN = cliente;
        printf("Cliente %d (NORMAL) entrou na fila N.\n", cliente->id);
        sem_post(&semFilaN);
    }
    pthread_mutex_unlock(&mutexFila);
}

// Remove cliente da fila (FIFO)
Cliente *retirar_da_fila(TipoCliente tipo) {
    pthread_mutex_lock(&mutexFila);
    Cliente **fila = (tipo == PREFERENCIAL) ? &filaP : &filaN;
    Cliente *anterior = NULL, *atual = *fila;
    if (!atual) {
        pthread_mutex_unlock(&mutexFila);
        return NULL;
    }
    // Percorre até o último (FIFO)
    while (atual->prox) {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior)
        anterior->prox = NULL;
    else
        *fila = NULL;
    pthread_mutex_unlock(&mutexFila);
    return atual;
}

void *thread_cliente(void *arg) {
    Cliente *cliente = (Cliente *)arg;
    entrar_na_fila(cliente);
    // Espera ser atendido
    sem_wait(&cliente->atendido);
    // Após atendimento
    printf("Cliente %d foi atendido e está saindo do banco.\n", cliente->id);
    sem_destroy(&cliente->atendido);
    free(cliente);
    return NULL;
}

void *thread_caixa(void *arg) {
    int id_caixa = *(int *)arg;
    while (1) {
        // Verifica se já atendeu todos os clientes
        pthread_mutex_lock(&mutexContador);
        if (clientes_atendidos >= NUM_CLIENTES) {
            pthread_mutex_unlock(&mutexContador);
            break;
        }
        pthread_mutex_unlock(&mutexContador);

        Cliente *cliente = NULL;
        // Tenta atender preferencial
        if (sem_trywait(&semFilaP) == 0) {
            cliente = retirar_da_fila(PREFERENCIAL);
            if (cliente)
                printf("CAIXA %d está atendendo cliente %d da fila P.\n", id_caixa, cliente->id);
        } else if (sem_trywait(&semFilaN) == 0) {
            cliente = retirar_da_fila(NORMAL);
            if (cliente)
                printf("CAIXA %d está atendendo cliente %d da fila N.\n", id_caixa, cliente->id);
        } else {
            // Nenhum cliente, aguarda
            usleep(100000); // 0.1s
            continue;
        }

        if (cliente) {
            // Simula tempo de atendimento
            int tempo = 1 + rand() % 3;
            sleep(tempo);
            printf("CAIXA %d terminou atendimento do cliente %d.\n", id_caixa, cliente->id);
            sem_post(&cliente->atendido);
            pthread_mutex_lock(&mutexContador);
            clientes_atendidos++;
            pthread_mutex_unlock(&mutexContador);
        }
    }
    printf("CAIXA %d encerrou o expediente.\n", id_caixa);
    return NULL;
}

int main() {
    srand(time(NULL));
    sem_init(&semFilaP, 0, 0);
    sem_init(&semFilaN, 0, 0);

    pthread_t caixas[NUM_CAIXAS];
    int ids_caixa[NUM_CAIXAS];
    for (int i = 0; i < NUM_CAIXAS; i++) {
        ids_caixa[i] = i + 1;
        pthread_create(&caixas[i], NULL, thread_caixa, &ids_caixa[i]);
    }

    pthread_t clientes[NUM_CLIENTES];
    for (int i = 0; i < NUM_CLIENTES; i++) {
        Cliente *cliente = malloc(sizeof(Cliente));
        cliente->id = i + 1;
        cliente->tipo = (rand() % 2 == 0) ? PREFERENCIAL : NORMAL;
        cliente->prox = NULL;
        sem_init(&cliente->atendido, 0, 0);
        pthread_create(&clientes[i], NULL, thread_cliente, cliente);
        // Simula chegada aleatória
        usleep(100000 + rand() % 200000); // 0.1s a 0.3s
    }

    for (int i = 0; i < NUM_CLIENTES; i++) {
        pthread_join(clientes[i], NULL);
    }
    for (int i = 0; i < NUM_CAIXAS; i++) {
        pthread_join(caixas[i], NULL);
    }

    sem_destroy(&semFilaP);
    sem_destroy(&semFilaN);
    pthread_mutex_destroy(&mutexFila);
    pthread_mutex_destroy(&mutexContador);

    printf("Simulação encerrada. %d clientes atendidos.\n", clientes_atendidos);
    return 0;
}
