#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados_paciente.h"
#include "heap.h"

struct heap {
    int tamanho;
    dado_t** dados_paciente;
};


/**
  * @brief  Criar o vetor heap
  * @param	dados_paciente: Ponteiro para a base de dados
  * @param  tam: Tamanho do vetor heap
  * @retval heap_t: ponteiro para o heap
  */
heap_t* cria_heap(int tam) {
    heap_t* h = NULL;

    //Criando o vetor heap
    h = (heap_t*) malloc(sizeof(heap_t));
    if (h == NULL)
    {
        perror("cria_heap:\n");
        exit(EXIT_FAILURE);
    }

    //Criando o vetor heap com estrutura igual ao dos pacientes
    h->dados_paciente = (dado_t**)malloc(tam * sizeof(dado_t));
    if (h->dados_paciente== NULL)
    {
        perror("cria_heap: dados_paciente");
        exit(EXIT_FAILURE);
    }

    h->tamanho = 0; //Aqui será correto falar q o tamanho do heap é 0?
    return h;
}

/**
  * @brief  Colocar no vetor heap a estrutura de dados dos pacientes
  * @param	dados_paciente: Ponteiro para a base de dados
  * @param  tam: Tamanho do vetor heap
  * @param  h:ponteiro do vetor heap
  * @retval Nenhum
  */
void monta_heap(heap_t* h,dado_t** paciente_dados, int tam) {
    int i;
    h->tamanho = tam;

    //heap recebendo os dados do paciente
    /*OBS: AQUI NAO ROLOU FAZER COM VETOR WHY?*/
    //memcpy(h->dados_paciente, paciente_dados, sizeof(dado_t*)*tam);
    memcpy(h->dados_paciente, paciente_dados, sizeof(dado_t)*tam);

    for(i = (h->tamanho/2 -1); i>=0; i--)
        heap_min_heapify(h, i);
}

/**
  * @brief  Identificar o vértice pai
  * @param	i: Identificador numérico da posição
  * @retval Int: resultado do indentificador numérico de pai
  */
int pai(int i) {
    return (i - 1)/2;
}

/**
  * @brief  Identificar do filho a esquerda
  * @param	i: Identificador numérico da posição
  * @retval Int: resultado do indentificador numérico de filho a esquerda
  */
int esquerda(int i) {
    return (2*i + 1);
}

/**
  * @brief  Identificar do filho a direita
  * @param	i: Identificador numérico da posição
  * @retval Int: resultado do indentificador numérico de filho a direita
  */
int direita (int i) {
    return (2*i + 2);
}

/**
  * @brief  Colocar no vetor heap a estrutura de dados dos pacientes
  * @param	dados_paciente: Ponteiro para a base de dados
  * @param  tam: Tamanho do vetor heap
  * @param  h:ponteiro do vetor heap
  * @retval Nenhum
  */
void heap_min_heapify(heap_t* heap, int init) {
    int e = esquerda(init);
    int d = direita(init);
    int maior = 0;
    dado_t* temp = 0;
    if(e < heap->tamanho && obtem_prioridade(heap->dados_paciente[e],heap->dados_paciente[init]))
        maior = e;
    else
        maior = init;
    if(d < heap->tamanho && obtem_prioridade(heap->dados_paciente[d],heap->dados_paciente[maior]))
        maior = d;
    printf("e= %d, d = %d, maior=%d\n",e, d, maior);
    if(maior != init) {
        temp = heap->dados_paciente[init];
        heap->dados_paciente[init] = heap->dados_paciente[maior];
        heap->dados_paciente[maior]= temp;
        heap_min_heapify(heap, maior);
    }
}

void heapsort(heap_t *h,dado_t** paciente_dados, int tam) {
    int i;
    dado_t *temp;
    monta_heap(h, paciente_dados, tam);
    for(i = tam - 1; i >= 0; i--) {
        temp = h->dados_paciente[0];
        //printf("sort-prioridade=%s\n",temp->nome);
        h->dados_paciente[0] = h->dados_paciente[i];
        h->dados_paciente[i] = temp;
        h->tamanho -= 1;
        heap_min_heapify(h, 0);
    }

}

void imprime_heap(heap_t *h,int tam){
     dado_t* temp;
    int i;
     for (i = 0; i < tam; i++) {
        temp = h->dados_paciente[i];
        printf("Nome=%s ; Prioridade: %d\n",temp->nome,temp->prioridade);
        //printf("sort-prioridade=%s\n",temp->prioridade);
    }


}

void libera_heap(heap_t *heap)
{
    free(heap->dados_paciente);
    free(heap);
}

