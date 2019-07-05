#ifndef DADOS_PACIENTE_H_INCLUDED
#define DADOS_PACIENTE_H_INCLUDED

struct dados_paciente{
    char *nome;
    int prioridade;
   };

typedef struct dados_paciente dado_t;

/**
  * @brief  Criar os dados do paciente
  * @param	Nome: Equivale ao nome do paciente, prioridade: A prioridade q ele vai ter na fila
  * @retval dado_t: ponteiro para o dado
  */
dado_t* cria_dado_paciente(char *nome,int prioridade);

/**
  * @brief  Ler o arquivo da fila
  * @param	nome_do_arquivo:Base de dados de teste
  *
  * @retval fila_t: ponteiro para uma nova fila
  */

dado_t **ler_arquivo(char *nome_do_arquivo, int *tamanho);

/**
  * @brief  Obter a prioridade dos pacientes
  * @param	paciente1: elemento a ser comparado
  * @param	paciente1: elemento a ser comparado
  * @retval int: Retorno true or false
  */
int obtem_prioridade(dado_t* paciente1, dado_t* paciente2);

/**
  * @brief  Libera a memória dos dados
  * @param	vetor: Ponteiro para dado_t
  * @param	tamanho: Tamanho total dos dados
  * @retval nenhum
  */
void libera_dados(dado_t **vetor, int tamanho);

#endif // DADOS_PACIENTE_H_INCLUDED
