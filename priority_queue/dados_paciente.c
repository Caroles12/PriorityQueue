#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados_paciente.h"
/*PROBLEMA 1: BASE DE DADOS*/

struct dados_paciente{
    char *nome;
    int prioridade;
};

/**
  * @brief  Criar os dados do paciente
  * @param	Nome: Equivale ao nome do paciente, prioridade: A prioridade q ele vai ter na fila
  * @retval dado_t: ponteiro para o dado
  */

dado_t* cria_dado_paciente(char *nome,int prioridade){

    dado_t *p=(dado_t*)malloc(sizeof(dado_t));  //O primeiro passo � alocar toda a estrutura

    if(p==NULL){
        printf("Mem�ria insuficiente: Problema em aloca��o de p");
        exit(-1);
    }

    //Alocando o espa�o da string
    p->nome=(char*)malloc(strlen(nome)+1);

    if(p->nome==NULL){
        printf("Mem�ria insuficiente: Problema em aloca��o de p");
          exit(-1);
    }

    //O ponteiro p come�a a apontar para os outros dados
    p->prioridade = prioridade;

    //Ponteiro p recebendo o conteudo da string
    strncpy(p->nome,nome,strlen(nome)+1);

    return p;
}

