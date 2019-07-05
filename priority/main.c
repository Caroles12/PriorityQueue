#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados_paciente.h"
#include "heap.h"


int main()
{
    while (1){

    /* Variáveis */
    int tamanho;
    dado_t **dado;
    char nome[50];
    char prioridade[3];
    char nome1[50];
    char prioridade1[3];
    int count = 0;
    char c;
    char d;

    //printf("-1\n");

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

     FILE * originalFile = fopen("dados.txt", "r");
     FILE * newFile = fopen("dados_temp.txt", "w");


         while( (c = fgetc(originalFile)) != EOF )
            {
                fprintf(newFile, "%c", c);
            };

     /*Essa função tem um bug, ela precisa receber os dados 2 vezes para inserir*/
     printf("Digite o nome do paciente :");
     gets(nome);
     printf("Digite a idade do paciente:");
     gets(prioridade);
      printf("Confirme digitando o nome do paciente:");
     gets(nome1);
     printf("Confirme digitando novamente a idade :");
     gets(prioridade1);




     fprintf(newFile, "\n%s;%s", nome, prioridade);
     fprintf(newFile, "\n%s;%s", nome1, prioridade1);



     fclose(originalFile);
     fclose(newFile);

     remove("dados.txt");
     rename("dados_temp.txt", "dados.txt");

     system("cls");
    }


}




