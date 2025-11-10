/*
 * exercicio4.c
 *
 * Created on: 10 de nov de 2025
 *
 * Authors:
 *
 * Le o arquivo binário gerado no exercicio 1 (EP07Dados.bin) e cria um arquivo
 * de texto com os dados dos alunos ordenados alfabeticamente por nome.
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define BIN_FILENAME "EP07Dados.bin"
#define OUT_FILENAME "EP07OrdenadoNome.txt"

typedef struct {
    int matricula;
    char nome[50];
    char flag;
    float prova1, prova2;
    float notas[8];
} Aluno;

bool comparaNome(const Aluno &a, const Aluno &b) {
    return strcmp(a.nome, b.nome) < 0;
}

int main(void) {
    FILE *dadosBin, *saida;

    dadosBin = fopen(BIN_FILENAME, "rb");
    if (dadosBin == NULL) exit(1);

    vector<Aluno> alunos;
    Aluno aluno;

    while (fread(&aluno, sizeof(Aluno), 1, dadosBin) == 1) {
        alunos.push_back(aluno);
    }

    fclose(dadosBin);

    sort(alunos.begin(), alunos.end(), comparaNome);

    saida = fopen(OUT_FILENAME, "w");
    if (saida == NULL) exit(1);

    for (int i = 0; i < (int)alunos.size(); i++) {
        fprintf(saida, "%d %s %.1f %.1f ",
            alunos[i].matricula,
            alunos[i].nome,
            alunos[i].prova1,
            alunos[i].prova2);

        for (int j = 0; j < 8; j++)
            fprintf(saida, "%.1f ", alunos[i].notas[j]);

        fprintf(saida, "\n");
    }

    fclose(saida);

    return 0;
}
