/*
 * exercicio2.c
 *
 * Created on: 10 de nov de 2025
 *
 * Authors:
 *
 * Le o arquivo binário gerado no exercicio 1 (EP07Dados.bin) e cria um arquivo
 * de texto ordenado por nome com o indice de cada aluno.
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define BIN_FILENAME "EP07Dados.bin"
#define OUT_FILENAME "EP07IndiceNome.txt"

typedef struct {
    int matricula;
    char nome[50];
    char flag;
    float prova1, prova2;
    float notas[8];
} Aluno;

typedef struct {
    string nome;
    int indice;
} NomeIndice;

bool comparaNome(const NomeIndice &a, const NomeIndice &b) {
    return a.nome < b.nome;
}

int main(void) {
    FILE *dadosBin, *saida;

    dadosBin = fopen(BIN_FILENAME, "rb");

    vector<NomeIndice> indices;
    Aluno aluno;
    int i = 0;

    if (dadosBin == NULL) exit(1);

    while (fread(&aluno, sizeof(Aluno), 1, dadosBin) == 1) {
        NomeIndice n;
        n.nome = aluno.nome;
        n.indice = i;
        indices.push_back(n);
        i++;
    }

    fclose(dadosBin);

    sort(indices.begin(), indices.end(), comparaNome);

    saida = fopen(OUT_FILENAME, "w");

    if (saida == NULL) exit(1);

    for (int i = 0; i < (int)indices.size(); i++) {
        fprintf(saida, "%s %d\n", indices[i].nome.c_str(), indices[i].indice);
    }

    fclose(saida);

    return 0;
}
