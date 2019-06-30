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


    dado = ler_arquivo("dados.txt", &tamanho);

   #ifdef DEBUG
printf("\n\n");
#endif // DEBUG
    heap_t *heap;
    heap = cria_heap(tamanho);



    monta_heap(heap, dado, tamanho);


    return 0;
}





