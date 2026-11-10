/********************************************************
*  Para compilar gcc ProgramaBaseCifragem.c -o cifragem *
*  Para executar ./cifragem                             *
********************************************************/

#include <stdio.h>

#define TAM 9
#define SYMBOLS 256

typedef unsigned char byte;

void Cifra(byte *bloco, char *chave, int itens) {
  int i;

  for (i = 0; i < itens; i++) {
    if (i % 2 == 0)
      bloco[i] = (bloco[i] >> 1) + (chave[i] << 1);
    else
      bloco[i] = (bloco[i] << 1) + (chave[i] >> 1);
    // printf("[%d] %3d\n", i, bloco[i]);
  }
}

void Decifra(byte *bloco, char *chave, int itens) {
  int i;

  for (i = 0; i < itens; i++) {
    if (i % 2 == 0)
      bloco[i] = (bloco[i] - (chave[i] << 1)) << 1;

    else
      bloco[i] = (bloco[i] - (chave[i] >> 1)) >> 1;
    // printf("[%d] %3d\n", i, bloco[i]);
  }
}

int main(void) {
  char BlocoDados[TAM], ChaveCifragem[TAM];
  FILE *ArquivoEntrada, *ArquivoSaida;
  char NomeArquivoEntrada[30], NomeArquivoSaida[30];
  int Itens;
  int opcao;

  do {
    printf("\n\nDigite a opcao desejada:\n\n");
    printf("1: Cifrar\n2: Decifrar\n0: Sair\n");

    scanf("%d", &opcao);

    if (opcao == 1) {
      printf("Entre com o Nome do Arquivo Original = ");
      scanf("%s", NomeArquivoEntrada);
      printf("Entre com o Nome do Arquivo para Cifragem = ");
      scanf("%s", NomeArquivoSaida);
      printf("Entre com uma senha de 8 digitos = ");
      scanf("%s", ChaveCifragem);

      ArquivoEntrada = fopen(NomeArquivoEntrada, "rb");
      ArquivoSaida = fopen(NomeArquivoSaida, "wb");
      do {
        Itens = fread(BlocoDados, 1, TAM, ArquivoEntrada);

        if (Itens != 0) {
          Cifra((unsigned char *)BlocoDados, ChaveCifragem, Itens);
          fwrite(BlocoDados, Itens, 1, ArquivoSaida);
        }
      } while (!feof(ArquivoEntrada));

      fclose(ArquivoSaida);
      fclose(ArquivoEntrada);
    } else if (opcao == 2) {
      printf("Entre com o Nome do Arquivo Cifrado = ");
      scanf("%s", NomeArquivoEntrada);
      printf("Entre com o Nome do Arquivo para Decifragem = ");
      scanf("%s", NomeArquivoSaida);
      printf("Entre com uma senha de 8 digitos = ");
      scanf("%s", ChaveCifragem);

      ArquivoEntrada = fopen(NomeArquivoEntrada, "rb");
      ArquivoSaida = fopen(NomeArquivoSaida, "wb");
      do {
        Itens = fread(BlocoDados, 1, TAM, ArquivoEntrada);

        if (Itens != 0) {
          Decifra((unsigned char *)BlocoDados, ChaveCifragem, Itens);
          fwrite(BlocoDados, Itens, 1, ArquivoSaida);
        }
      } while (!feof(ArquivoEntrada));

      fclose(ArquivoSaida);
      fclose(ArquivoEntrada);
    }
  } while (opcao);

  return 0;
}

