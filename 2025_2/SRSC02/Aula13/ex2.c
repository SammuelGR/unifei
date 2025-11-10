/* Programa que copia arquivos. Verificação e relato de erros é mínimo.*/

#include <sys/types.h>        /* inclui os arquivos de cabeçalho necessários */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]);    /* protótipo ANS */

#define BUF_SIZE 4096               /* usa um tamanho de buffer de 4096 bytes */
#define OUTPUT_MODE 0700            /* bits de proteção para o arquivo de saída */

int main(int argc, char *argv[])
{
    int in_fd, out_fd, rd_count, wt_count;
    char buffer[BUF_SIZE];

    if (argc != 3) exit(1);         /* erro de sintaxe se argc não for 3 */

    /* Abre o arquivo de entrada e cria o arquivo de saída */
    in_fd = open(argv[1], O_RDONLY);            /* abre o arquivo de origem */
    if (in_fd < 0) exit(2);                     /* se não puder ser aberto, saia */
    out_fd = creat(argv[2], OUTPUT_MODE);       /* cria o arquivo de destino */
    if (out_fd < 0) exit(3);                    /* se não puder ser criado, saia */

    /* Laço de cópia */
    while (1) {
        rd_count = read(in_fd, buffer, BUF_SIZE);   /* lê um bloco de dados */
        if (rd_count <= 0) break;                   /* se fim de arquivo ou erro, sai do laço */
        wt_count = write(out_fd, buffer, rd_count); /* escreve dados */
        if (wt_count <= 0) exit(4);                 /* wt_count <= 0 é um erro */
    }

    /* Fecha os arquivos */
    close(in_fd);
    close(out_fd);
    if (rd_count == 0)
        exit(0);            /* nenhum erro na última leitura */
    else
        exit(5);            /* erro na última leitura */
}
