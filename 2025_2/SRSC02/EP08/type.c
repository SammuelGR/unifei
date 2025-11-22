/*
 * type.c
 *
 * Authors:
 *
 * Localiza e imprime o conteúdo de um arquivo (ex.: type Ext4.txt)
 * dentro de Disco.dat. Ao final, imprime:
 *  - sequência dos clusters lidos
 *  - quantidade de clusters
 *  - tamanho do arquivo
 *  - bytes desperdiçados no último cluster
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estruturas.h"

#define NUM_ENTRADAS 8

 /* Converte string para maiúsculas (in place) */
void str_maiuscula(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = toupper((unsigned char)s[i]);
        i++;
    }
}

/* Extrai nome (até 8 chars) do argv[1] */
void extrai_nome_ext(const char *arg, char *nome, char *ext) {
    int i = 0, j = 0;

    /* nome até o '.' ou fim da string, máx 8 chars */
    while (arg[i] != '\0' && arg[i] != '.' && j < 8) {
        nome[j] = arg[i];
        i++;
        j++;
    }
    nome[j] = '\0';

    /* se tiver '.', pula */
    if (arg[i] == '.')
        i++;

    /* extensão até fim, máx 3 chars */
    j = 0;
    while (arg[i] != '\0' && j < 3) {
        ext[j] = arg[i];
        i++;
        j++;
    }
    ext[j] = '\0';
}

/* Constrói string C (com '\0') a partir dos campos fixos do diretório */
void monta_nome_dir(const char origem[], int tam, char *dest) {
    int i = 0;
    while (i < tam && origem[i] != '\0') {
        dest[i] = origem[i];
        i++;
    }
    dest[i] = '\0';
}

int main(int argc, char *argv[]) {
    const int BYTES_POR_CLUSTER = 511 * sizeof(char);

    FILE *disco;
    arquivo dir[NUM_ENTRADAS];
    char nomeArg[9], extArg[4];
    int i;

    if (argc != 2) {
        printf("Uso: type nome.ext\n");
        return 1;
    }

    /* 1) Separar nome e extensão do parâmetro */
    extrai_nome_ext(argv[1], nomeArg, extArg);
    str_maiuscula(nomeArg);
    str_maiuscula(extArg);

    /* 2) Abrir Disco.dat */
    disco = fopen(FILE_NAME, "rb");
    if (disco == NULL) {
        printf("Erro ao abrir %s\n", FILE_NAME);
        return 2;
    }

    /* 3) Ler diretório (cluster 0 com 8 entradas) */
    if (fread(dir, sizeof(arquivo), NUM_ENTRADAS, disco) != NUM_ENTRADAS) {
        printf("Erro ao ler diretório\n");
        fclose(disco);
        return 3;
    }

    /* 4) Procurar o arquivo no diretório */
    int idx = -1;

    for (i = 0; i < NUM_ENTRADAS; i++) {
        unsigned char c0 = (unsigned char)dir[i].nome[0];

        /* pula arquivos deletados (0xEB) */
        if (c0 == 0xEB)
            continue;

        char nomeDir[9], extDir[4];

        monta_nome_dir(dir[i].nome, TAM_NOME, nomeDir);
        monta_nome_dir(dir[i].extensao, TAM_EXT, extDir);

        str_maiuscula(nomeDir);
        str_maiuscula(extDir);

        if (strcmp(nomeDir, nomeArg) == 0 && strcmp(extDir, extArg) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Arquivo nao encontrado.\n");
        fclose(disco);
        return 4;
    }

    /* 5) Percorrer os clusters do arquivo e imprimir conteúdo */
    unsigned long int tamanho = dir[idx].tamanho;
    unsigned long int totalLido = 0;
    unsigned long int clusterAtual = dir[idx].cluster;

    /* área de dados começa após o diretório (8 entradas) */
    long offsetDados = NUM_ENTRADAS * sizeof(arquivo) + 3;

    cluster c;
    unsigned long int seq[200];
    int qClusters = 0;

    while (totalLido < tamanho) {
        /* clusters de dados numerados a partir de 1 */
        long pos = offsetDados + (long)(clusterAtual - 1) * (long)sizeof(cluster);

        if (fseek(disco, pos, SEEK_SET) != 0) {
            printf("Erro em fseek\n");
            fclose(disco);
            return 5;
        }

        if (fread(&c, sizeof(cluster), 1, disco) != 1) {
            printf("Erro em fread do cluster\n");
            fclose(disco);
            return 6;
        }

        unsigned long int faltando = tamanho - totalLido;
        unsigned long int aLer = (faltando < BYTES_POR_CLUSTER) ? faltando : BYTES_POR_CLUSTER;

        fwrite(c.dados, 1, aLer, stdout);

        totalLido += aLer;

        seq[qClusters] = clusterAtual;
        qClusters++;

        clusterAtual = c.prox;
    }

    printf("\n\n");

    /* 6) Estatísticas finais */
    printf("Sequencia de clusters lidos: ");
    for (i = 0; i < qClusters; i++)
        printf("%lu ", seq[i]);
    printf("\n");

    printf("Quantidade de clusters: %d\n", qClusters);
    printf("Tamanho do arquivo: %lu bytes\n", tamanho);

    unsigned long int resto = tamanho % BYTES_POR_CLUSTER;
    unsigned long int desperdicado = (resto == 0) ? 0 : (BYTES_POR_CLUSTER - resto);

    printf("Bytes desperdicados no ultimo cluster: %lu\n", desperdicado);

    fclose(disco);
    return 0;
}
