#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct heap heap_t;

heap_t* cria_heap(int tam);
void monta_heap(heap_t* h, int vetor[], int tam);
int pai(int i);
int esquerda(int i);
int direita(int i);
void heap_max_heapify(heap_t* heap, int init);
void heapsort(int vetor[], int tam);

#endif // HEAP_H_INCLUDED
