#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "dados_paciente.h"

typedef struct heap heap_t;

typedef struct dados_paciente dado_t;

heap_t* cria_heap(int tam);
void monta_heap(heap_t* h,dado_t** paciente_dados, int tam);
int pai(int i);
int esquerda(int i);
int direita (int i);
void heap_max_heapify(heap_t* heap, int init);
void heapsort(dado_t** paciente_dados, int tam);


#endif // HEAP_H_INCLUDED
