#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados_paciente.h"
#define DEBUG



/**
  * @brief  Criar os dados do paciente
  * @param	Nome: Equivale ao nome do paciente, prioridade: A prioridade q ele vai ter na fila
  * @retval dado_t: ponteiro para o dado
  */

dado_t* cria_dado_paciente(char *nome, int prioridade)
{

    dado_t *p = malloc(sizeof(dado_t));  //O primeiro passo é alocar toda a estrutura

    if(p==NULL)
    {
        printf("Memória insuficiente: Problema em alocação de p");
        exit(-1);
    }

    //Alocando o espaço da string
    p->nome=(char*)malloc(strlen(nome)+1);

    if(p->nome==NULL)
    {
        printf("Memória insuficiente: Problema em alocação de p");
        exit(-1);
    }

    //O ponteiro p começa a apontar para os outros dados
    p->prioridade = prioridade;

    //Ponteiro p recebendo o conteudo da string
    strncpy(p->nome,nome,strlen(nome)+1);

    return p;
}

/**
  * @brief  Ler o arquivo da fila
  * @param	nome_do_arquivo:Base de dados de teste
  *
  * @retval fila_t: ponteiro para uma nova fila
  */

dado_t **ler_arquivo(char *nome_do_arquivo, int *tamanho)
{
    FILE *fp;
    char buffer[64],buffer_paciente[64];
    int prioridade, orgao;
    int linhas = 0;


    fp=fopen(nome_do_arquivo,"r");
    if(fp==NULL)
    {
        printf("Erro ao abrir o arquivo DADOSPACIENTES.CSV");
        exit(1);
    }

    while(fgets(buffer,64,fp)!= NULL)
    {
        linhas++;
    }
    linhas--;
    rewind(fp);

    dado_t **ptr_dados = malloc(sizeof(dado_t *) * linhas);

    if (!ptr_dados)
    {
        perror(__func__);
        exit(-1);
    }

    int i = 0;

    //Ler o tamanho total do arquivo pra pegar todos os dados
    while(fgets(buffer,64,fp)!= NULL)
    {
        //As funções só vão receber se tiver 2 dados lidos
        if((sscanf(buffer,"%64[^;];%i", buffer_paciente, &prioridade)))
        {
            //Depois de ler, mandar o dado pra ser criado na estrutura
            ptr_dados[i] = cria_dado_paciente(buffer_paciente,prioridade);
            i++;
        }

    }


#ifdef DEBUG
    for (int i=0; i < linhas; i++)
        //printf("%s; %d\n", ptr_dados[i]->nome, ptr_dados[i]->prioridade);


#endif // DEBUG

        fclose(fp);

    *tamanho = linhas;
    return ptr_dados;
}
/**
  * @brief  Obter a prioridade dos pacientes
  * @param	paciente1: elemento a ser comparado
  * @param	paciente1: elemento a ser comparado
  * @retval int: Retorno true or false
  */

int obtem_prioridade(dado_t* paciente1, dado_t* paciente2)
{
    //printf("%s =%d \n",paciente1->nome, paciente1->prioridade);
    if(paciente1->prioridade > paciente2->prioridade)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/**
  * @brief  Libera a memória dos dados
  * @param	vetor: Ponteiro para dado_t
  * @param	tamanho: Tamanho total dos dados
  * @retval nenhum
  */

void libera_dados(dado_t **vetor, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        free(vetor[i]->nome);
        free(&vetor[i]);
    }
    free(vetor);
}



