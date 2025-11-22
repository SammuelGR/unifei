/*
 * exercicio1.c
 *
 * Created on: 10 de nov de 2025
 *
 * Authors:
 *
 * Le o texto do arquivo EP07Dados.txt e transforma em dados binarios,
 * armazenando o resultado em EP07Dados.bin
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define TXT_FILENAME "EP07Dados.txt"
#define BIN_FILENAME "EP07Dados.bin"
#define TXT_EOF "-1 FIM"
#define BUFFER_SIZE 256
#define NOTAS_SIZE 8
#define NOME_SIZE 50

typedef struct {
    int matricula;
    char nome[NOME_SIZE];
    char flag;
    float prova1, prova2;
    float notas[NOTAS_SIZE];
} Aluno;

int main(void) {
    FILE *dadosTxt, *dadosBin;
    char buffer[BUFFER_SIZE];
    string bufferText;
    int rdCount = 0; // par = matricula + nome, impar = notas
    int i;

    Aluno aluno;

    dadosTxt = fopen(TXT_FILENAME, "r");
    dadosBin = fopen(BIN_FILENAME, "wb");

    if (dadosTxt == NULL || dadosBin == NULL) exit(1);

    while (fgets(buffer, sizeof(buffer), dadosTxt)) {
        bufferText = buffer;

        if (bufferText == TXT_EOF || bufferText == TXT_EOF + string("\n"))
            break;

        aluno.flag = 'N';

        if (rdCount % 2 == 0) {
            int spaceIdx = bufferText.find(" ");
            string nome = bufferText.substr(spaceIdx + 1);

            if (!nome.empty() && nome.back() == '\n')
                nome.pop_back();

            memset(aluno.nome, 0, sizeof(aluno.nome));
            strncpy(aluno.nome, nome.c_str(), sizeof(aluno.nome) - 1);

            aluno.matricula = stoi(bufferText.substr(0, spaceIdx));
        } else {
            i = 0;
            int notaIdx = 0;
            char numStr[20];
            int j = 0;

            while (bufferText[i] != '\0') {
                if (bufferText[i] != ' ' && bufferText[i] != '\n') {
                    numStr[j++] = bufferText[i];
                } else if (j > 0) {
                    numStr[j] = '\0';
                    float nota = atof(numStr);

                    if (notaIdx == 0) aluno.prova1 = nota;
                    else if (notaIdx == 1) aluno.prova2 = nota;
                    else aluno.notas[notaIdx - 2] = nota;

                    notaIdx++;
                    j = 0;
                }
                i++;
            }

            fwrite(&aluno, sizeof(Aluno), 1, dadosBin); // salva dados do aluno
        }

        rdCount++;
    }

    fclose(dadosTxt);
    fclose(dadosBin);

    return 0;
}
