#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaprioridade.h"
#include "dados_paciente.h"
/*PROBLEMA 1: BASE DE DADOS*/


struct filaprioridades{
    int qtd;
    dado_t *paciente_dados;
};

/**
  * @brief  Cria uma nova fila de números inteiros
  * @param
  *
  * @retval fila_t: ponteiro para uma nova fila
  */

fila_t* criar_fila_prioridade(){

    fila_t *p = NULL;

    //aloca memória
    p = (fila_t*)malloc(sizeof(fila_t));

    //Verifica se a fila foi criada
    if(p != NULL)
        p->qtd = 0;
    return p;

}

/**
  * @brief  Ler o arquivo da fila
  * @param	nome_do_arquivo:Base de dados de teste
  *
  * @retval fila_t: ponteiro para uma nova fila
  */

fila_t *ler_arquivo(char *nome_do_arquivo){
    FILE *fp;
    char buffer[64],buffer_paciente[64];
    int prioridade;
    float data;

    fp=fopen(nome_do_arquivo,"r");
    if(fp==NULL){
        printf("Erro ao abrir o arquivo DADOSPACIENTES.CSV");
        exit(1);
    }


    //Criar a fila
     fila_t *fila = criar_fila_prioridade();

    //Ler o tamanho total do arquivo pra pegar todos os dados
    while(fgets(buffer,64,fp)!= NULL){


         //As funções só vão receber se tiver 2 dados lidos
         if((sscanf(buffer,"%64[^;];%d",buffer_paciente, &prioridade) == 2)){

           //Depois de ler, mandar o dado pra ser criado na estrutura
           dado_t *fp=cria_dado_paciente(buffer_paciente,prioridade);

        /*A ORDEM AQUI PODE SER VAI PRO HEAP E DEPOIS PRA FILA DE PRIORIDADE?, AI JA INSERE BONITINHO*/

          //Adicionar na cabeça, pq eu to tratando da pilha
            //enqueue(fila,p);

        }

    }


    fclose(fp);
    return fila;
}

