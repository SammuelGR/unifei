#define FILE_NAME "Disco.dat"
#define TAM_NOME 8
#define TAM_EXT 3

typedef struct {
unsigned short dia;
unsigned short mes;
unsigned short ano;
unsigned short hora;
unsigned short min;
unsigned short seg;
} data;

typedef struct {
char nome [TAM_NOME]; // nome do arquivo, se iniciado com o hexadecimal 0EBh sao arquivos deletados
char extensao [TAM_EXT]; // extensao do arquivo (ex: TXT , C, CPP. DOC , etc)

// Protecao
unsigned short sistema; // arquivo do sistema operacional
unsigned short hidden; // arquivo oculto
unsigned short archieved; // arquivo arquivado ou backuped

// Datas do arquivo
data criacao; // Data e hora da criacao
data acesso; // Data do ultimo acesso

// Tamanho do arquivo em bytes
unsigned long int tamanho;

// Cluster inicial
unsigned long int cluster;
} arquivo;

typedef struct {
char dados [512];
unsigned long int prox;
} cluster;
