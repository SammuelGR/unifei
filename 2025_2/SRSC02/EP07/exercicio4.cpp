/*
 * exercicio4.c
 *
 * Created on: 10 de nov de 2025
 *
 * Authors:
 *
 * Manipula os dados do arquivo binário (EP07Dados.bin) com as opções:
 * 1) Incluir aluno
 * 2) Alterar aluno
 * 3) Imprimir todos (por matrícula ou nome)
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define BIN_FILENAME "EP07Dados.bin"
#define IDX_NOME_FILENAME "EP07IndiceNome.txt"
#define IDX_MAT_FILENAME "EP07IndiceMatricula.txt"

typedef struct {
    int matricula;
    char nome[50];
    char flag; // 'N', 'D' ou 'T'
    float prova1, prova2;
    float notas[8];
} Aluno;


void incluirAluno() {
    FILE *f = fopen(BIN_FILENAME, "ab");
    if (f == NULL) exit(1);

    Aluno a;
    memset(&a, 0, sizeof(Aluno));

    cout << "Matricula: ";
    cin >> a.matricula;
    cin.ignore();
    cout << "Nome: ";
    fgets(a.nome, 50, stdin);
    a.nome[strcspn(a.nome, "\n")] = 0;

    a.flag = 'N';
    a.prova1 = 0;
    a.prova2 = 0;
    for (int i = 0; i < 8; i++) a.notas[i] = 0;

    fwrite(&a, sizeof(Aluno), 1, f);
    fclose(f);

    system("./exercicio2.exe");
    system("./exercicio3.exe");

    cout << "Aluno incluido com sucesso!\n";
}

void alterarAluno() {
    FILE *f = fopen(BIN_FILENAME, "r+b");
    if (f == NULL) exit(1);

    vector<Aluno> alunos;
    Aluno a;
    while (fread(&a, sizeof(Aluno), 1, f) == 1) alunos.push_back(a);

    int opcao;
    int idx = -1;

    cout << "Buscar por: 1-Matricula | 2-Nome: ";
    cin >> opcao;
    cin.ignore();

    if (opcao == 1) {
        int mat;
        cout << "Matricula: ";
        cin >> mat;
        for (int i = 0; i < (int)alunos.size(); i++)
            if (alunos[i].matricula == mat) idx = i;
    } else {
        char nome[50];
        cout << "Nome: ";
        cin.getline(nome, sizeof(nome));
        for (int i = 0; i < (int)alunos.size(); i++)
            if (strcmp(alunos[i].nome, nome) == 0) idx = i;
    }

    if (idx == -1) {
        cout << "Aluno nao encontrado.\n";
        fclose(f);
        return;
    }

    cout << "Alterando dados de " << alunos[idx].nome << endl;
    cout << "1 - Prova 1\n2 - Prova 2\n3 - Flag (N/D/T)\n";
    int op;
    cin >> op;

    if (op == 1) cin >> alunos[idx].prova1;
    else if (op == 2) cin >> alunos[idx].prova2;
    else if (op == 3) cin >> alunos[idx].flag;

    fseek(f, idx * sizeof(Aluno), SEEK_SET);
    fwrite(&alunos[idx], sizeof(Aluno), 1, f);
    fclose(f);

    system("./exercicio2.exe");
    system("./exercicio3.exe");

    cout << "Dados atualizados.\n";
}

bool cmpNome(const Aluno &a, const Aluno &b) {
    return strcmp(a.nome, b.nome) < 0;
}

bool cmpMat(const Aluno &a, const Aluno &b) {
    return a.matricula < b.matricula;
}

void imprimir() {
    FILE *f = fopen(BIN_FILENAME, "rb");
    if (f == NULL) exit(1);

    vector<Aluno> alunos;
    Aluno a;
    while (fread(&a, sizeof(Aluno), 1, f) == 1) alunos.push_back(a);
    fclose(f);

    int op;
    cout << "Imprimir em ordem: 1-Nome | 2-Matrícula: ";
    cin >> op;

    if (op == 1) sort(alunos.begin(), alunos.end(), cmpNome);
    else sort(alunos.begin(), alunos.end(), cmpMat);

    cout << "\n--- LISTA DE ALUNOS ---\n";
    for (auto &x : alunos) {
        cout << x.matricula << " - " << x.nome
            << " | P1: " << x.prova1
            << " | P2: " << x.prova2
            << " | Flag: " << x.flag << "\n";
    }
}

int main(void) {
    int op;
    do {
        cout << "\n1 - Incluir aluno\n2 - Alterar aluno\n3 - Imprimir alunos\n0 - Sair\nOpcao: ";
        cin >> op;
        cin.ignore();

        if (op == 1) incluirAluno();
        else if (op == 2) alterarAluno();
        else if (op == 3) imprimir();

    } while (op != 0);

    return 0;
}
