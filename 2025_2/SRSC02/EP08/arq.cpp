/*
 * arq.cpp
 *
 * Created on: 17 de nov de 2025
 *
 * Authors:
 *
 * Lista os arquivos armazenados em Disco.dat
 *
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "estruturas.h"

using namespace std;

#define NUM_ENTRADAS 8

// imprime nome.ext
void imprimeNome(const arquivo &arq) {
    string nome(arq.nome, TAM_NOME);
    string ext(arq.extensao, TAM_EXT);

    cout << nome << "." << ext;
}

// imprime data dia/mes/ano hora:min:seg, tipo 0: criacao, 1: acesso
void imprimeData(const arquivo &arq, int tipo) {
    const  ::data *d = (tipo == 0 ? &arq.criacao : &arq.acesso);

    cout << d->dia << "/" << d->mes << "/" << d->ano << " ";
    cout << d->hora << ":" << d->min << ":" << d->seg << endl;
}

int main(int argc, char *argv[]) {
    int modo = 0; // 0 normal, 1 -a, 2 -s, 3 -w
    int count = 0; // controlar impressao por linha
    int i;

    FILE *disco = fopen(FILE_NAME, "rb");
    if (!disco) exit(1);

    arquivo dir[NUM_ENTRADAS];

    // Le o cluster 0 (diretorio)
    if (fread(dir, sizeof(arquivo), NUM_ENTRADAS, disco) != NUM_ENTRADAS) {
        cout << "Erro ao ler diretorio\n";
        fclose(disco);
        exit(2);
    }

    fclose(disco);

    if (argc == 1) modo = 0;

    else if (argc == 2) {
        if (strcmp(argv[1], "-a") == 0) modo = 1;
        else if (strcmp(argv[1], "-s") == 0) modo = 2;
        else if (strcmp(argv[1], "-w") == 0) modo = 3;
        else {
            cout << "Opcao invalida para arq" << endl;
            return 0;
        }
    } else {
        cout << "Opcao invalida para arq" << endl;
        return 0;
    }

    for (i = 0; i < NUM_ENTRADAS; i++) {
        // ignorar deletados
        if ((unsigned char)dir[i].nome[0] == 0xEB) continue;

        // modo normal (0), -a (1) e -w (3) excluem sistema e hidden
        if (modo == 0 || modo == 1 || modo == 3) {
            if (dir[i].sistema != 0) continue;
            if (dir[i].hidden  != 0) continue;
        }

        // impressão
        if (modo == 0) {
            // 5 por linha
            imprimeNome(dir[i]);
            count++;
            if (count == 5) {
                cout << "\n";
                count = 0;
            } else {
                cout << "\t";
            }
        }

        else if (modo == 1) {
            // -a imprime todos os campos, um por linha
            cout << "Arquivo " << i << ":\n";
            cout << "\tNome: " << string(dir[i].nome, TAM_NOME) << endl;
            cout << "\tExtensao: " << string(dir[i].extensao, TAM_EXT) << endl;
            cout << "\tSistema: " << dir[i].sistema << endl;
            cout << "\tHidden: " << dir[i].hidden << endl;
            cout << "\tArchieved: " << dir[i].archieved << endl;
            cout << "\tData criacao: ";
            imprimeData(dir[i], 0);
            cout << "\tData acesso: ";
            imprimeData(dir[i], 1);
            cout << "\tTamanho: " << dir[i].tamanho << endl;
            cout << "\tCluster inicial: " << dir[i].cluster << "\n\n";
        }

        else if (modo == 2) {
            // -s (como normal mas mostrando arquivos de sistema)
            if (dir[i].hidden  != 0) continue; // ignora hidden

            // 5 por linha
            imprimeNome(dir[i]);
            count++;
            if (count == 5) {
                cout << "\n";
                count = 0;
            } else {
                cout << "\t";
            }
        }

        else if (modo == 3) {
            // -w 4 por linha, formato nome.ext
            if (dir[i].sistema != 0) continue;
            if (dir[i].hidden  != 0) continue;
            if ((unsigned char)dir[i].nome[0] == 0xEB) continue;

            imprimeNome(dir[i]);
            count++;
            if (count == 4) {
                cout << "\n";
                count = 0;
            } else {
                cout << "\t";
            }
        }
    }

    cout << endl;
    return 0;
}
