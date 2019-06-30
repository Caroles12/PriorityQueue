#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"

struct heap {
    int tamanho;
    int* heapers;
};

heap_t* cria_heap(int tam) {
    heap_t* h = NULL;

    h = (heap_t*) malloc(sizeof(heap_t));
    if (h == NULL)
    {
        perror("cria_heap:\n");
        exit(EXIT_FAILURE);
    }

    h->heapers = (int*) malloc(tam * sizeof(int));
    if (h->heapers == NULL)
    {
        perror("cria_heap: heapers");
        exit(EXIT_FAILURE);
    }

    h->tamanho = 0;
    return h;
}

void monta_heap(heap_t* h, int vetor[], int tam) {
    int i;
    h->tamanho = tam;

    for(i = 0; i < h->tamanho; i++)
    {
        h->heapers[i] = vetor[i];
    }

    for(i = (h->tamanho/2 -1); i>=0; i--)
        heap_max_heapify(h, i);
}

int pai(int i) {
    return (i - 1)/2;
}

int esquerda(int i) {
    return (2*i + 1);
}


int direita (int i) {
    return (2*i + 2);
}

void heap_max_heapify(heap_t* heap, int init) {
    int e = esquerda(init);
    int d = direita(init);
    int maior;
    int temp = 0;
    if(e < heap->tamanho && heap->heapers[e] > heap->heapers[init])
        maior = e;
    else
        maior = init;
    if(d < heap->tamanho && heap->heapers[d] > heap->heapers[maior])
        maior = d;

    if(maior != init) {
        temp = heap->heapers[init];
        heap->heapers[init] = heap->heapers[maior];
        heap->heapers[maior] = temp;
        heap_max_heapify(heap, maior);
    }
}

void heapsort(int vetor[], int tam) {
    heap_t* h = cria_heap(tam);
    int i, temp;
    monta_heap(h, vetor, tam);
    for(i = tam - 1; i >= 0; i--) {
        temp = h->heapers[0];
        h->heapers[0] = h->heapers[i];
        h->heapers[i] = temp;

        h->tamanho -= 1;
        heap_max_heapify(h, 0);
    }

    for(i = 0; i< tam; i++) {
        printf("%d ", h->heapers[i]);
    }

    printf("\n");
}

