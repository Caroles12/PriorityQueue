#include <stdio.h>
#include <stdlib.h>
#include "filaprioridade.h"
#include "dados_paciente.h"
#include "heap.h"


int main()
{
    /* Variáveis */
    int tamanho;
    dado_t **dado;

    printf("-1\n");

    dado = ler_arquivo("dados.txt", &tamanho);

#ifdef DEBUG
    printf("\n\n");
#endif // DEBUG
    //monta_heap(h, *dado, tamanho);
     heap_t *h;
     h = cria_heap(tamanho);

     heapsort(h, dado, tamanho);

     imprime_heap(h,tamanho);

     libera_dados(dado,tamanho);

     libera_heap(h);

    return 0;
}




