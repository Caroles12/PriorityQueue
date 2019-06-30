#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaprioridade.h"
#define MAX 1000
/*PROBLEMA 1: BASE DE DADOS*/

/*ERRO 1: ESSA VARIAVEL PRECISA SER UM VETOR DE STRUCT, OU SEJA, ELA PRECISA CONTER TODAS AS STRUCTS POSSIVEIS*/

struct filaprioridades{
  int tamanho;
  dado_t *dados_paciente;  /*POSSIVEL PROBLEMA: O TAMANHO DESSA STRUCT PRECISA SER O RETORNO DO MALLOC P do arquivo de dados*/
};


/**
  * @brief  Cria uma nova fila de números inteiros
  * @param
  *
  * @retval fila_t: ponteiro para uma nova fila
  */

fila_t* criar_fila_prioridade()
{

    fila_t *p = NULL;

    //aloca memória
    p = (fila_t*)malloc(sizeof(fila_t));

    //Verifica se a fila foi criada
    if(p != NULL)
        p->tamanho = 0;
    return p;

}

int enqueue(fila_t *fila,dado_t **p){
       if(fila == NULL)
        return 0;
    if(fila->tamanho== MAX)//fila cheia
        return 0;
    //Inserir na primeira posição livre da fila

//    printf("%s",obter_dado_nome(fila->dados_paciente[fila->tamanho]));
  //strcpy(fila->dados_paciente[fila->qtd].nome,obter_dado_nome(p));

    //fila->paciente_dados[fila->qtd].prioridade = fp->prioridade;

    //Chama heap

    }
