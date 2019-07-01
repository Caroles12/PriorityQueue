#ifndef DADOS_PACIENTE_H_INCLUDED
#define DADOS_PACIENTE_H_INCLUDED

struct dados_paciente{
    char *nome;
    int prioridade;
};

typedef struct dados_paciente dado_t;

dado_t* cria_dado_paciente(char *nome,int prioridade);

dado_t **ler_arquivo(char *nome_do_arquivo, int *tamanho);

void *obter_dado_nome (dado_t *dado);

int obtem_prioridade(dado_t* paciente1, dado_t* paciente2);

void libera_dados(dado_t **vetor, int tamanho);

#endif // DADOS_PACIENTE_H_INCLUDED
