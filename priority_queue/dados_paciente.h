#ifndef DADOS_PACIENTE_H_INCLUDED
#define DADOS_PACIENTE_H_INCLUDED

typedef struct dados_paciente dado_t;

dado_t* cria_dado_paciente(char *nome,int prioridade);

dado_t **ler_arquivo(char *nome_do_arquivo, int *tamanho);

void *obter_dado_nome (dado_t *dado);


#endif // DADOS_PACIENTE_H_INCLUDED
