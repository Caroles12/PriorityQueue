#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "dados_paciente.h"

typedef struct heap heap_t;

typedef struct dados_paciente dado_t;

/**
  * @brief  Criar o vetor heap
  * @param	dados_paciente: Ponteiro para a base de dados
  * @param  tam: Tamanho do vetor heap
  * @retval heap_t: ponteiro para o heap
  */
heap_t* cria_heap(int tam);

/**
  * @brief  Colocar no vetor heap a estrutura de dados dos pacientes
  * @param	dados_paciente: Ponteiro para a base de dados
  * @param  tam: Tamanho do vetor heap
  * @param  h:ponteiro do vetor heap
  * @retval Nenhum
  */
void monta_heap(heap_t* h,dado_t** paciente_dados, int tam);

/**
  * @brief  Identificar o vértice pai
  * @param	i: Identificador numérico da posição
  * @retval Int: resultado do indentificador numérico de pai
  */
int pai(int i);

/**
  * @brief  Identificar do filho a esquerda
  * @param	i: Identificador numérico da posição
  * @retval Int: resultado do indentificador numérico de filho a esquerda
  */
int esquerda(int i);
/**
  * @brief  Identificar do filho a direita
  * @param	i: Identificador numérico da posição
  * @retval Int: resultado do indentificador numérico de filho a direita
  */
int direita (int i);

/**
  * @brief  "Desenha" a arvore do heap minimo
  * @param	heap: ponteiro pro vetor heap
  * @param  init: Dado inicial
  * @retval Nenhum
  */
void heap_min_heapify(heap_t* heap, int init);

/**
  * @brief  Ordena o vetor heap
  * @param	h: ponteiro pro vetor heap
  * @param  tam: Tamanho do vetor
  * @param  paciente_dados: Ponteiro duplo para o vetor de dados_paciente
  * @retval Nenhum
  */
void heapsort(heap_t *h,dado_t** paciente_dados, int tam);

/**
  * @brief  Imprimere o vetor heap
  * @param	h: ponteiro pro vetor heap
  * @param  tam: Tamanho do vetor heap
  * @retval Nenhum
  */
void imprime_heap(heap_t *h,int tam);

/**
  * @brief  Libera a memória
  * @param	heap: ponteiro pro vetor heap
  * @retval Nenhum
  */
void libera_heap(heap_t *heap);


#endif // HEAP_H_INCLUDED
