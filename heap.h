#define MAX 100

typedef struct fila_prioridade FilaPrioridade;

FilaPrioridade* cria_FilaPrioridade();

void libera_FilaPrioridade(FilaPrioridade *fp);

int insere_FilaPrioridade(FilaPrioridade* fp, char* voo, int prioridade);

int remove_FilaPrioridade(FilaPrioridade* fp);

int consulta_FilaPrioridade (FilaPrioridade* fp, char* voo);

int tamanho_FilaPrioridade(FilaPrioridade* fp);

int verCheia_FilaPrioridade(FilaPrioridade* fp);

int verVazia_FilaPrioridade(FilaPrioridade* fp);




