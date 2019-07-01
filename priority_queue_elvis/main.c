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

     heapsort(dado, tamanho);

    return 0;
}




